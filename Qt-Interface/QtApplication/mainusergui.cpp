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
    setWindowTitle(tr("Interfaz de Control TIVA")); // Título de la ventana

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
    ventanaPopUp.setText(tr("Status: RESPUESTA A PING RECIBIDA")); //Este es el texto que muestra la ventana
    ventanaPopUp.setStandardButtons(QMessageBox::Ok);
    ventanaPopUp.setWindowTitle(tr("Evento"));
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

    //SENSOR. ESPECIFICACION 3
    connect(&tiva,SIGNAL(IncommingSensorData(PARAMETERS_SENSOR_READ)),this,SLOT(SensorDataShow(PARAMETERS_SENSOR_READ)));
    connect(&tiva,SIGNAL(IncommingProximitySensorData(PARAMETERS_PROXIMITY_SENSOR)),this,SLOT(ProximitySensorDataShow(PARAMETERS_PROXIMITY_SENSOR)));
    connect(&tiva,SIGNAL(IncommingGestureSensorData(PARAMETERS_GESTURE_SENSOR)),this,SLOT(GestureSensorDataShow(PARAMETERS_GESTURE_SENSOR)));
    connect(&tiva,SIGNAL(IncommingGestureSensorData2(PARAMETERS_GESTURE_SENSOR2)),this,SLOT(GestureSensorDataShow2(PARAMETERS_GESTURE_SENSOR2)));

    //Semana 2. Inicializacion GRAFICA
    ui->Grafica->setTitle("Osciloscopio"); // Titulo de la grafica
    ui->Grafica->setAxisTitle(QwtPlot::xBottom, "Muestras"); // Etiqueta eje X de coordenadas
    ui->Grafica->setAxisTitle(QwtPlot::yLeft, "Tension");    // Etiqueta eje Y de coordenadas
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

    //Inicializacion GRAFICA de GESTOS
    ui->Grafica_2->setTitle("Gestos"); // Titulo de la grafica
    ui->Grafica_2->setAxisTitle(QwtPlot::xBottom, "Tiempo"); // Etiqueta eje X de coordenadas
    ui->Grafica_2->setAxisTitle(QwtPlot::yLeft, "Valor");    // Etiqueta eje Y de coordenadas
    //ui->Grafica->axisAutoScale(true); // Con Autoescala
    ui->Grafica_2->setAxisScale(QwtPlot::yLeft, 0, 256); // Escala fija
    ui->Grafica_2->setAxisScale(QwtPlot::xBottom,0,32);

    // Formateo de la curva
    for(int i=0;i<4;i++){
    Channels2[i] = new QwtPlotCurve();
    Channels2[i]->attach(ui->Grafica_2);
    }

    //Inicializacion de los valores básicos
    for(int i=0;i<32;i++){
        xVal2[i]=i;
        yVal2[0][i]=0;
        yVal2[1][i]=0;
        yVal2[2][i]=0;
        yVal2[3][i]=0;
    }
    Channels2[0]->setRawSamples(xVal2,yVal2[0],32);
    Channels2[1]->setRawSamples(xVal2,yVal2[1],32);
    Channels2[2]->setRawSamples(xVal2,yVal2[2],32);
    Channels2[3]->setRawSamples(xVal2,yVal2[3],32);

    Channels2[0]->setPen(QPen(Qt::red)); // Color de la curva
    Channels2[1]->setPen(QPen(Qt::cyan));
    Channels2[2]->setPen(QPen(Qt::yellow));
    Channels2[3]->setPen(QPen(Qt::green));
    m_Grid2 = new QwtPlotGrid();     // Rejilla de puntos
    m_Grid2->attach(ui->Grafica_2);    // que se asocia al objeto QwtPl
    ui->Grafica_2->setAutoReplot(false); //Desactiva el autoreplot (mejora la eficiencia)
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
    switch (status)
    {
        case QTivaRPC::TivaConnected:

            //Caso conectado..
            // Deshabilito el boton de conectar
            ui->runButton->setEnabled(false);

            // Se indica que se ha realizado la conexión en la etiqueta 'statusLabel'
            ui->statusLabel->setText(tr("Ejecucion, conectado al puerto %1.")
                             .arg(ui->serialPortComboBox->currentText()));

            //    // Y se habilitan los controles deshabilitados
            ui->pingButton->setEnabled(true);

        break;

        case QTivaRPC::TivaDisconnected:
            //Caso desconectado..
            // Rehabilito el boton de conectar
            ui->runButton->setEnabled(false);
        break;
        case QTivaRPC::UnexpectedPacketError:
        case QTivaRPC::FragmentedPacketError:
        case QTivaRPC::CRCorStuffError:
            //Errores detectados en la recepcion de paquetes
            ui->statusLabel->setText(message);
        break;
        default:
            //Otros errores (por ejemplo, abriendo el puerto)
            processError(tiva.getLastErrorMessage());
    }
}


// SLOT asociada a pulsación del botón RUN
void MainUserGUI::on_runButton_clicked()
{
    //Intenta arrancar la comunicacion con la TIVA
    tiva.startRPCClient( ui->serialPortComboBox->currentText());
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

void MainUserGUI::on_sensor_lumin_clicked()
{
    tiva.SensorRead();
}

void MainUserGUI::SensorDataShow(PARAMETERS_SENSOR_READ parametro){

    QColor col;
    int total = parametro.b + parametro.r + parametro.g+1;
    col.setBlue(parametro.b*255/total);
    col.setGreen(parametro.g*255/total);
    col.setRed(parametro.r*255/total);

    ui->intensidad->display(parametro.c);
    ui->color->setColor(col);

}

void MainUserGUI::on_horizontalSlider_sliderMoved(int position)
{
    ui->distance->display(position);
    tiva.SensorProximitySend(position);
}

void MainUserGUI::on_checkBox_2_clicked(bool checked)
{
    tiva.ProximitySensorChangeState(checked);
}

void MainUserGUI::ProximitySensorDataShow(PARAMETERS_PROXIMITY_SENSOR parametro){

    ui->distance_2->display(parametro.value);
    ui->color_2->setChecked(parametro.state);
}

void MainUserGUI::GestureSensorDataShow(PARAMETERS_GESTURE_SENSOR parametro){

    ui->up->setChecked(0);
    ui->down->setChecked(0);
    ui->left->setChecked(0);
    ui->right->setChecked(0);
    ui->near->setChecked(0);
    ui->far->setChecked(0);

    switch(parametro.mode){

        case 1: ui->left->setChecked(1);
                break;
        case 2: ui->right->setChecked(1);
            break;
        case 3: ui->up->setChecked(1);
            break;
        case 4: ui->down->setChecked(1);
            break;
        case 5: ui->near->setChecked(1);
            break;
        case 6: ui->far->setChecked(1);
            break;
        case 7:
                ui->left->setChecked(1);
                ui->right->setChecked(1);
                ui->up->setChecked(1);
                ui->down->setChecked(1);
                ui->near->setChecked(1);
                ui->far->setChecked(1);
            break;
        default:
            break;
    }

}

void MainUserGUI::GestureSensorDataShow2(PARAMETERS_GESTURE_SENSOR2 parametro){

    for(int i=0;i<(parametro.bytes_read/4);i++){
        yVal2[0][i]=parametro.fifo[4*i];
        yVal2[1][i]=parametro.fifo[(4*i)+1];
        yVal2[2][i]=parametro.fifo[(4*i)+2];
        yVal2[3][i]=parametro.fifo[(4*i)+3];
    }

//    for(int i=0;i<(parametro.bytes_read/4);i++){
//        yVal2[0][(1000-parametro.bytes_read/4)+i]=((double)parametro.fifo[4*i]);
//        yVal2[1][(1000-parametro.bytes_read/4)+i]=((double)parametro.fifo[(4*i)+1]);
//        yVal2[2][(1000-parametro.bytes_read/4)+i]=((double)parametro.fifo[(4*i)+2]);
//        yVal2[3][(1000-parametro.bytes_read/4)+i]=((double)parametro.fifo[(4*i)+3]);
//    }

    ui->Grafica_2->replot();
}