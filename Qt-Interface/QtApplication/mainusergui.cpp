#include "mainusergui.h"
#include "ui_mainusergui.h"
#include <QSerialPort>      // Comunicacion por el puerto serie
#include <QSerialPortInfo>  // Comunicacion por el puerto serie
#include <QMessageBox>      // Se deben incluir cabeceras a los componentes que se vayan a crear en la clase
#include "rpc_commands.h"
// y que no estén incluidos en el interfaz gráfico. En este caso, la ventana de PopUp <QMessageBox>
// que se muestra al recibir un PING de respuesta

#include<stdint.h>      // Cabecera para usar tipos de enteros con tamaño
#include<stdbool.h>     // Cabecera para usar booleanos

MainUserGUI::MainUserGUI(QWidget *parent) :  // Constructor de la clase
    QWidget(parent),
    ui(new Ui::MainUserGUI)               // Indica que guipanel.ui es el interfaz grafico de la clase
  , transactionCount(0)
{
    ui->setupUi(this);                // Conecta la clase con su interfaz gráfico.
    setWindowTitle(tr("Tivaia")); // Título de la ventana

    // Inicializa la lista de puertos serie
    ui->serialPortComboBox->clear(); // Vacía de componentes la comboBox
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        // La descripción realiza un FILTRADO que  nos permite que SOLO aparezcan los interfaces tipo USB serial con el identificador de fabricante
        // y producto de la TIVA
        // NOTA!!: SI QUIERES REUTILIZAR ESTE CODIGO PARA OTRO CONVERSOR USB-Serie, cambia los valores VENDOR y PRODUCT por los correspondientes
        // o cambia la condicion por "if (true) para listar todos los puertos serie"
        if ((info.vendorIdentifier()==0x1CBE) && (info.productIdentifier()==0x0002))
        {
            ui->serialPortComboBox->addItem(info.portName());
        }
    }

    //Inicializa algunos controles
    ui->serialPortComboBox->setFocus();   // Componente del GUI seleccionado de inicio
    ui->pingButton->setEnabled(false);    // Se deshabilita el botón de ping del interfaz gráfico, hasta que

    //Inicializa la ventana de PopUp que se muestra cuando llega la respuesta al PING
    ventanaPopUp.setIcon(QMessageBox::Information);
    ventanaPopUp.setText(tr("Ping response received!")); //Este es el texto que muestra la ventana
    ventanaPopUp.setStandardButtons(QMessageBox::Ok);
    ventanaPopUp.setWindowTitle(tr("Event"));
    ventanaPopUp.setParent(this,Qt::Popup);

    //Conexion de signals de los widgets del interfaz con slots propios de este objeto
    connect(ui->rojo,SIGNAL(toggled(bool)),this,SLOT(cambiaLEDs()));
    connect(ui->verde,SIGNAL(toggled(bool)),this,SLOT(cambiaLEDs()));
    connect(ui->azul,SIGNAL(toggled(bool)),this,SLOT(cambiaLEDs()));


    //Conectamos Slots del objeto "Tiva" con Slots de nuestra aplicacion (o con widgets)
    connect(&tiva,SIGNAL(statusChanged(int,QString)),this,SLOT(tivaStatusChanged(int,QString)));
    connect(ui->pingButton,SIGNAL(clicked(bool)),&tiva,SLOT(ping()));
    connect(ui->Knob,SIGNAL(valueChanged(double)),&tiva,SLOT(LEDPwmBrightness(double)));
    connect(&tiva,SIGNAL(pingReceivedFromTiva()),this,SLOT(pingResponseReceived()));
    connect(&tiva,SIGNAL(commandRejectedFromTiva(int16_t)),this,SLOT(CommandRejected(int16_t)));
    connect(ui->Botones,SIGNAL(clicked(bool)),&tiva,SLOT(switchesSound()));
    connect(&tiva,SIGNAL(receiveSwitchesState(bool,bool)),this,SLOT(changeSwitchesState(bool,bool)));
    connect(ui->BotonesCheckBox,SIGNAL(toggled(bool)),&tiva,SLOT(switchesInterruptEnable(bool)));
    connect(&tiva,SIGNAL(receiveSwitchesState(bool,bool)),this,SLOT(changeSwitchesState(bool,bool)));

    //ADC. ESPECIFICACION 2.
    connect(&tiva,SIGNAL(ADC8SampleReceived(PARAMETERS_ADC8_PACKET)),this,SLOT(ADC8SampleShow(PARAMETERS_ADC8_PACKET)));
    connect(&tiva,SIGNAL(ADC12SampleReceived(PARAMETERS_ADC12_PACKET)),this,SLOT(ADC12SampleShow(PARAMETERS_ADC12_PACKET)));
    connect(ui->ADCCheck,SIGNAL(toggled(bool)),&tiva,SLOT(switchADC(bool)));

    //Semana 2. Inicializacion GRAFICA
    ui->Grafica->setTitle("Oscilloscope"); // Titulo de la grafica
    ui->Grafica->setAxisTitle(QwtPlot::xBottom, "Samples"); // Etiqueta eje X de coordenadas
    ui->Grafica->setAxisTitle(QwtPlot::yLeft, "Voltage");    // Etiqueta eje Y de coordenadas
    //ui->Grafica->axisAutoScale(true); // Con Autoescala
    ui->Grafica->setAxisScale(QwtPlot::yLeft, 0, 3.3); // Escala fija
    ui->Grafica->setAxisScale(QwtPlot::xBottom,0,999);

    // Formateo de la curva
    for(int i=0;i<4;i++){
    Channels[i] = new QwtPlotCurve();
    Channels[i]->attach(ui->Grafica);
    }

    //Inicializacion de los valores básicos
    for(int i=0;i<1000;i++){
        xVal[i]=i;
        yVal[0][i]=0;
        yVal[1][i]=0;
        yVal[2][i]=0;
        yVal[3][i]=0;
    }
    Channels[0]->setRawSamples(xVal,yVal[0],1000);
    Channels[1]->setRawSamples(xVal,yVal[1],1000);
    Channels[2]->setRawSamples(xVal,yVal[2],1000);
    Channels[3]->setRawSamples(xVal,yVal[3],1000);

    Channels[0]->setPen(QPen(Qt::red)); // Color de la curva
    Channels[1]->setPen(QPen(Qt::cyan));
    Channels[2]->setPen(QPen(Qt::yellow));
    Channels[3]->setPen(QPen(Qt::green));
    m_Grid = new QwtPlotGrid();     // Rejilla de puntos
    m_Grid->attach(ui->Grafica);    // que se asocia al objeto QwtPl
    ui->Grafica->setAutoReplot(false); //Desactiva el autoreplot (mejora la eficiencia)
    //Semana 2. FIN Inicializacion GRAFICA

}

MainUserGUI::~MainUserGUI() // Destructor de la clase
{
    delete ui;   // Borra el interfaz gráfico asociado a la clase
}

void MainUserGUI::on_serialPortComboBox_currentIndexChanged(const QString &arg1)
{
    activateRunButton();
}

// Funcion auxiliar de procesamiento de errores de comunicación
void MainUserGUI::processError(const QString &s)
{
    activateRunButton(); // Activa el botón RUN
    // Muestra en la etiqueta de estado la razón del error (notese la forma de pasar argumentos a la cadena de texto)
    ui->statusLabel->setText(tr("Status: Not running, %1.").arg(s));
}

// Funcion de habilitacion del boton de inicio/conexion
void MainUserGUI::activateRunButton()
{
    ui->runButton->setEnabled(true);
}

//Este Slot lo hemos conectado con la señal statusChange de la TIVA, que se activa cuando
//El puerto se conecta o se desconecta y cuando se producen determinados errores.
//Esta función lo que hace es procesar dichos eventos
void MainUserGUI::tivaStatusChanged(int status,QString message)
{
    ui->statusLabel->setText(message);
    switch (status)
    {
        case QTivaRPC::TivaConnected:
            ui->runButton->setEnabled(false);
            ui->stopButton->setEnabled(true);
            ui->pingButton->setEnabled(true);
            ui->statusLabel->setText(tr("Running, connected to %1")
                             .arg(ui->serialPortComboBox->currentText()));
        break;
        case QTivaRPC::TivaDisconnected:
            ui->runButton->setEnabled(true);
            ui->stopButton->setEnabled(false);
            ui->pingButton->setEnabled(false);
            ui->statusLabel->setText(tr("Sleeping"));
        break;
        case QTivaRPC::OpenPortError:
            ui->statusLabel->setText(tr("Not running, can not open %1")
                         .arg(ui->serialPortComboBox->currentText()));
        break;
        case QTivaRPC::UnexpectedPacketError:
        case QTivaRPC::FragmentedPacketError:
        case QTivaRPC::CRCorStuffError:
            ui->statusLabel->setText(message);
        break;
        default:
            ui->statusLabel->setText(tr("Not running, error not handled"));
            processError(tiva.getLastErrorMessage());
        break;
    }
}


// SLOT asociada a pulsación del botón RUN
void MainUserGUI::on_runButton_clicked()
{
    ui->statusLabel->setText(tr("Connecting..."));
    ui->statusLabel->repaint();
    usleep(500*1000);
    tiva.startRPCClient( ui->serialPortComboBox->currentText());
}

void MainUserGUI::on_stopButton_clicked()
{
    ui->statusLabel->setText(tr("Stopping..."));
    ui->statusLabel->repaint();
    usleep(500*1000);
    tiva.stopRPCClient();
}

void MainUserGUI::cambiaLEDs(void)
{
    //Invoca al metodo LEDGPio para enviar la orden a la TIVA
    tiva.LEDGpio(ui->rojo->isChecked(),ui->verde->isChecked(),ui->azul->isChecked());
}

//Slots Asociado al boton que limpia los mensajes del interfaz
void MainUserGUI::on_pushButton_clicked()
{
    ui->statusLabel->setText(tr(""));
}

//**** Slots asociados a la recepción de mensajes desde la TIVA ********/
//Están conectados a señales generadas por el objeto TIVA de clase QTivaRPC (se conectan en el constructor de la ventana, más arriba en este fichero))
//Se pueden añadir los que se quieran para completar la aplicación

//Este se ejecuta cuando se recibe una respuesta de PING
void MainUserGUI::pingResponseReceived()
{
    // Muestra una ventana popUP para el caso de comando PING; no te deja definirla en un "caso"
    ventanaPopUp.setStyleSheet("background-color: lightgrey");
    ventanaPopUp.setModal(true); //CAMBIO: Se sustituye la llamada a exec(...) por estas dos.
    ventanaPopUp.show();
}

//Este se ejecuta cuando se recibe un mensaje de comando rechazado
void MainUserGUI::CommandRejected(int16_t code)
{
    ui->statusLabel->setText(tr("Status: Comando rechazado,%1").arg(code));
}


void MainUserGUI::on_colorWheel_colorChanged(const QColor &arg1)
{
    tiva.LEDPwmColor(arg1);
}

void MainUserGUI::on_pwmGpio_Check_toggled(bool checked)
{
    tiva.switchMode(checked);
}

void MainUserGUI::LEDPwmBrightness(double value)
{
    tiva.LEDPwmBrightness(value);
}

void MainUserGUI::changeSwitchesState(bool state1, bool state2){

    ui->led_1->setChecked(state1);
    ui->led_2->setChecked(state2);
}

//ESPECIFICACION 2. Mostrar los valores ADC
void MainUserGUI::ADC12SampleShow(PARAMETERS_ADC12_PACKET parametro){

    for(int i=0;i<(1000-8);i++){
        yVal[0][i]=yVal[0][i+8];
        yVal[1][i]=yVal[1][i+8];
        yVal[2][i]=yVal[2][i+8];
        yVal[3][i]=yVal[3][i+8];
    }

    for(int i=0;i<8;i++){
        yVal[0][(1000-8)+i]=((double)parametro.chan1[i])*3.3/4096.0;
        yVal[1][(1000-8)+i]=((double)parametro.chan2[i])*3.3/4096.0;
        yVal[2][(1000-8)+i]=((double)parametro.chan3[i])*3.3/4096.0;
        yVal[3][(1000-8)+i]=((double)parametro.chan4[i])*3.3/4096.0;
    }

    if(ui->CanalTodosCheck->isChecked()){
        Channels[0]->attach(ui->Grafica);
        Channels[1]->attach(ui->Grafica);
        Channels[2]->attach(ui->Grafica);
        Channels[3]->attach(ui->Grafica);
    }else{
        if(ui->Canal1Check->isChecked())
            Channels[0]->attach(ui->Grafica);
        else
            Channels[0]->detach();

        if(ui->Canal2Check->isChecked())
            Channels[1]->attach(ui->Grafica);
        else
            Channels[1]->detach();

        if(ui->Canal3Check->isChecked())
            Channels[2]->attach(ui->Grafica);
        else
            Channels[2]->detach();

        if(ui->Canal4Check->isChecked())
            Channels[3]->attach(ui->Grafica);
        else
            Channels[3]->detach();
    }

    ui->Grafica->replot();
}

//ESPECIFICACION 2. Mostrar los valores ADC
void MainUserGUI::ADC8SampleShow(PARAMETERS_ADC8_PACKET parametro){

    // Write value on file
    if (file != NULL){
        ui->statusLabelCap->setText(tr("Capturing 8bits samples"));
        uint8_t *data;
        data = parametro.chan3;
        for(int i=0; i<8; i++)
        {
            bytes_writen = fprintf(file, "%d\n", (uint32_t)parametro.chan3[i]);
            if(bytes_writen < 0)
            {
                printf("write");
                fflush(stdout);
                ui->statusLabelCap->setText(tr("Writing error"));
            }
        }
    }

    for(int i=0;i<(1000-8);i++){
        yVal[0][i]=yVal[0][i+8];
        yVal[1][i]=yVal[1][i+8];
        yVal[2][i]=yVal[2][i+8];
        yVal[3][i]=yVal[3][i+8];
    }

    for(int i=0;i<8;i++){
        yVal[0][(1000-8)+i]=((double)parametro.chan1[i])*3.3/256.0;
        yVal[1][(1000-8)+i]=((double)parametro.chan2[i])*3.3/256.0;
        yVal[2][(1000-8)+i]=((double)parametro.chan3[i])*3.3/256.0;
        yVal[3][(1000-8)+i]=((double)parametro.chan4[i])*3.3/256.0;
    }

    if(ui->CanalTodosCheck->isChecked()){
        Channels[0]->attach(ui->Grafica);
        Channels[1]->attach(ui->Grafica);
        Channels[2]->attach(ui->Grafica);
        Channels[3]->attach(ui->Grafica);
    }else{
        if(ui->Canal1Check->isChecked())
            Channels[0]->attach(ui->Grafica);
        else
            Channels[0]->detach();

        if(ui->Canal2Check->isChecked())
            Channels[1]->attach(ui->Grafica);
        else
            Channels[1]->detach();

        if(ui->Canal3Check->isChecked())
            Channels[2]->attach(ui->Grafica);
        else
            Channels[2]->detach();

        if(ui->Canal4Check->isChecked())
            Channels[3]->attach(ui->Grafica);
        else
            Channels[3]->detach();
    }

    ui->Grafica->replot();
}

void MainUserGUI::on_ADCFrequency_valueChanged(double value)
{
      QString num;
      num.setNum((int) value, 10);
      ui->FreqNumber->setText(num);
      tiva.ADCFrequencySend(value);
}

void MainUserGUI::on_checkBox_clicked(bool checked)
{
   tiva.ADCResolutionSend(checked);
}


void MainUserGUI::on_FrequencySlider_valueChanged(int value)
{
    QString num;
    num.setNum(value, 10);
    ui->FreqNumber->setText(num);
    tiva.ADCFrequencySend((double)value);
}

void MainUserGUI::on_StartCapButton_clicked()
{
    file = fopen(filename, "w+");
    if(file == NULL){
        perror("open output file");
        fflush(stdout);
    }else{
        ui->statusLabelCap->setText(tr("Ready"));
    }
}

void MainUserGUI::on_EndCapButton_clicked()
{
    fclose(file);
    file = NULL;
    ui->statusLabelCap->setText(tr("Closed"));
}
