#ifndef MAINUSERGUI_H
#define MAINUSERGUI_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <QWidget>
#include <QtSerialPort/qserialport.h>
#include <QMessageBox>
#include "qtivarpc.h"
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include "rpc_commands.h"

#define MAX_SAMPLES_PER_CHANNEL 8

namespace Ui {
class MainUserGUI;
}

class MainUserGUI : public QWidget
{
    Q_OBJECT
    
public: 
    explicit MainUserGUI(QWidget *parent = 0);
    ~MainUserGUI();
    
private slots:
    //Slots asociados por nombre
    void on_runButton_clicked();    
    void on_serialPortComboBox_currentIndexChanged(const QString &arg1);
    void on_pushButton_clicked();    
    void on_colorWheel_colorChanged(const QColor &arg1);


    //Otros slots
    void cambiaLEDs();
    void tivaStatusChanged(int status,QString message);
    void pingResponseReceived(void);
    void CommandRejected(int16_t code);    
    void LEDPwmBrightness(double value);
    void on_pwmGpio_Check_toggled(bool checked);
    void changeSwitchesState(bool state1, bool state2);
    void ADC8SampleShow(PARAMETERS_ADC8_PACKET parametro);
    void ADC12SampleShow(PARAMETERS_ADC12_PACKET parametro);
    void on_ADCFrequency_valueChanged(double value);
    void on_checkBox_clicked(bool checked);
    void on_stopButton_clicked();
    void on_FrequencySlider_valueChanged(int value);

    void on_StartCapButton_clicked();

    void on_EndCapButton_clicked();

private:
    // funciones privadas
    void processError(const QString &s);
    void activateRunButton();

private:
    //Componentes privados
    Ui::MainUserGUI *ui;
    int transactionCount;
    QMessageBox ventanaPopUp;
    QTivaRPC tiva; //Objeto para gestionar la ejecucion acciones en el microcontrolador y/o recibir eventos desde él

    // Graphics
    double xVal[1000]; //valores eje X
    double yVal[4][1000]; //valores ejes Y
    QwtPlotCurve *Channels[4]; //Curvas
    QwtPlotGrid  *m_Grid; //Cuadricula

    // ADC capture
    FILE *file = NULL;
    char *filename = "/home/andres/Desktop/datafile";
    int bytes_writen=0;
};

#endif // GUIPANEL_H
