/********************************************************************************
** Form generated from reading UI file 'mainusergui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUSERGUI_H
#define UI_MAINUSERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "analogwidgets/led.h"
#include "color_wheel.hpp"
#include "qwt_knob.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainUserGUI
{
public:
    QPushButton *runButton;
    QPushButton *pingButton;
    QSplitter *splitter;
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QSplitter *splitter_3;
    QCheckBox *pwmGpio_Check;
    Led *led_1;
    Led *led_2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *BotonesCheckBox;
    QPushButton *Botones;
    color_widgets::ColorWheel *colorWheel;
    QwtKnob *Knob;
    QSplitter *splitter_2;
    QCheckBox *rojo;
    QCheckBox *verde;
    QCheckBox *azul;
    QPushButton *pushButton;
    QLabel *statusLabel;
    QLabel *label_3;
    QWidget *tab_2;
    QwtPlot *Grafica;
    QCheckBox *ADCCheck;
    QwtKnob *ADCFrequency;
    QLineEdit *FreqNumber;
    QLabel *label_5;
    QLabel *label_4;
    QCheckBox *checkBox;
    QCheckBox *Canal1Check;
    QLabel *label_11;
    QCheckBox *Canal2Check;
    QCheckBox *Canal3Check;
    QCheckBox *Canal4Check;
    QCheckBox *CanalTodosCheck;
    QWidget *tab_3;
    QPushButton *sensor_lumin;
    Led *color;
    QLCDNumber *intensidad;
    Led *color_2;
    QLabel *label_13;
    QSlider *horizontalSlider;
    QLCDNumber *distance;
    QCheckBox *checkBox_2;
    QLCDNumber *distance_2;
    QLabel *label_14;
    Led *left;
    Led *up;
    Led *right;
    Led *down;
    Led *near;
    Led *far;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *tab_4;
    QwtPlot *Grafica_2;
    QLabel *label_12;

    void setupUi(QWidget *MainUserGUI)
    {
        if (MainUserGUI->objectName().isEmpty())
            MainUserGUI->setObjectName(QStringLiteral("MainUserGUI"));
        MainUserGUI->resize(782, 540);
        runButton = new QPushButton(MainUserGUI);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(260, 10, 98, 27));
        pingButton = new QPushButton(MainUserGUI);
        pingButton->setObjectName(QStringLiteral("pingButton"));
        pingButton->setGeometry(QRect(280, 50, 61, 27));
        splitter = new QSplitter(MainUserGUI);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 10, 221, 27));
        splitter->setOrientation(Qt::Horizontal);
        serialPortLabel = new QLabel(splitter);
        serialPortLabel->setObjectName(QStringLiteral("serialPortLabel"));
        splitter->addWidget(serialPortLabel);
        serialPortComboBox = new QComboBox(splitter);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        splitter->addWidget(serialPortComboBox);
        tabWidget = new QTabWidget(MainUserGUI);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 80, 801, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        splitter_3 = new QSplitter(tab);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(360, 220, 97, 66));
        splitter_3->setOrientation(Qt::Vertical);
        pwmGpio_Check = new QCheckBox(splitter_3);
        pwmGpio_Check->setObjectName(QStringLiteral("pwmGpio_Check"));
        splitter_3->addWidget(pwmGpio_Check);
        led_1 = new Led(tab);
        led_1->setObjectName(QStringLiteral("led_1"));
        led_1->setEnabled(true);
        led_1->setGeometry(QRect(40, 210, 31, 31));
        led_1->setChecked(false);
        led_1->setColor(QColor(115, 210, 22));
        led_2 = new Led(tab);
        led_2->setObjectName(QStringLiteral("led_2"));
        led_2->setEnabled(true);
        led_2->setGeometry(QRect(100, 210, 31, 31));
        led_2->setChecked(false);
        led_2->setColor(QColor(115, 210, 22));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 250, 31, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 250, 41, 20));
        BotonesCheckBox = new QCheckBox(tab);
        BotonesCheckBox->setObjectName(QStringLiteral("BotonesCheckBox"));
        BotonesCheckBox->setGeometry(QRect(160, 230, 141, 21));
        Botones = new QPushButton(tab);
        Botones->setObjectName(QStringLiteral("Botones"));
        Botones->setGeometry(QRect(150, 270, 111, 27));
        colorWheel = new color_widgets::ColorWheel(tab);
        colorWheel->setObjectName(QStringLiteral("colorWheel"));
        colorWheel->setGeometry(QRect(550, 130, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorWheel->sizePolicy().hasHeightForWidth());
        colorWheel->setSizePolicy(sizePolicy);
        Knob = new QwtKnob(tab);
        Knob->setObjectName(QStringLiteral("Knob"));
        Knob->setGeometry(QRect(340, 100, 129, 134));
        Knob->setUpperBound(1);
        Knob->setValue(0.5);
        Knob->setSingleSteps(0u);
        Knob->setPageSteps(10u);
        splitter_2 = new QSplitter(tab);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(60, 70, 97, 66));
        splitter_2->setOrientation(Qt::Vertical);
        rojo = new QCheckBox(splitter_2);
        rojo->setObjectName(QStringLiteral("rojo"));
        splitter_2->addWidget(rojo);
        verde = new QCheckBox(splitter_2);
        verde->setObjectName(QStringLiteral("verde"));
        splitter_2->addWidget(verde);
        azul = new QCheckBox(splitter_2);
        azul->setObjectName(QStringLiteral("azul"));
        splitter_2->addWidget(azul);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 350, 64, 27));
        statusLabel = new QLabel(tab);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(410, 340, 341, 51));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 80, 91, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Grafica = new QwtPlot(tab_2);
        Grafica->setObjectName(QStringLiteral("Grafica"));
        Grafica->setGeometry(QRect(30, 20, 651, 251));
        QBrush brush(QColor(46, 52, 54, 255));
        brush.setStyle(Qt::SolidPattern);
        Grafica->setCanvasBackground(brush);
        ADCCheck = new QCheckBox(tab_2);
        ADCCheck->setObjectName(QStringLiteral("ADCCheck"));
        ADCCheck->setGeometry(QRect(210, 320, 101, 26));
        ADCFrequency = new QwtKnob(tab_2);
        ADCFrequency->setObjectName(QStringLiteral("ADCFrequency"));
        ADCFrequency->setEnabled(true);
        ADCFrequency->setGeometry(QRect(480, 253, 171, 181));
        ADCFrequency->setLowerBound(1);
        ADCFrequency->setUpperBound(5000);
        ADCFrequency->setScaleMaxMajor(5);
        ADCFrequency->setScaleMaxMinor(4);
        ADCFrequency->setScaleStepSize(1000);
        FreqNumber = new QLineEdit(tab_2);
        FreqNumber->setObjectName(QStringLiteral("FreqNumber"));
        FreqNumber->setGeometry(QRect(390, 323, 71, 28));
        FreqNumber->setReadOnly(true);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 293, 81, 20));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 363, 91, 20));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(210, 350, 161, 26));
        Canal1Check = new QCheckBox(tab_2);
        Canal1Check->setObjectName(QStringLiteral("Canal1Check"));
        Canal1Check->setGeometry(QRect(60, 286, 91, 26));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 266, 81, 20));
        Canal2Check = new QCheckBox(tab_2);
        Canal2Check->setObjectName(QStringLiteral("Canal2Check"));
        Canal2Check->setGeometry(QRect(60, 306, 91, 26));
        Canal3Check = new QCheckBox(tab_2);
        Canal3Check->setObjectName(QStringLiteral("Canal3Check"));
        Canal3Check->setGeometry(QRect(60, 326, 91, 26));
        Canal4Check = new QCheckBox(tab_2);
        Canal4Check->setObjectName(QStringLiteral("Canal4Check"));
        Canal4Check->setGeometry(QRect(60, 346, 91, 26));
        CanalTodosCheck = new QCheckBox(tab_2);
        CanalTodosCheck->setObjectName(QStringLiteral("CanalTodosCheck"));
        CanalTodosCheck->setGeometry(QRect(60, 366, 121, 26));
        CanalTodosCheck->setChecked(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        sensor_lumin = new QPushButton(tab_3);
        sensor_lumin->setObjectName(QStringLiteral("sensor_lumin"));
        sensor_lumin->setGeometry(QRect(40, 20, 111, 27));
        color = new Led(tab_3);
        color->setObjectName(QStringLiteral("color"));
        color->setGeometry(QRect(70, 60, 51, 51));
        color->setColor(QColor(46, 52, 54));
        intensidad = new QLCDNumber(tab_3);
        intensidad->setObjectName(QStringLiteral("intensidad"));
        intensidad->setGeometry(QRect(50, 120, 91, 41));
        intensidad->setAutoFillBackground(false);
        color_2 = new Led(tab_3);
        color_2->setObjectName(QStringLiteral("color_2"));
        color_2->setGeometry(QRect(270, 80, 51, 51));
        color_2->setChecked(false);
        color_2->setColor(QColor(239, 41, 41));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(240, 20, 121, 20));
        horizontalSlider = new QSlider(tab_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(220, 200, 160, 16));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        distance = new QLCDNumber(tab_3);
        distance->setObjectName(QStringLiteral("distance"));
        distance->setGeometry(QRect(250, 140, 91, 41));
        distance->setAutoFillBackground(false);
        checkBox_2 = new QCheckBox(tab_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(262, 47, 141, 26));
        distance_2 = new QLCDNumber(tab_3);
        distance_2->setObjectName(QStringLiteral("distance_2"));
        distance_2->setGeometry(QRect(250, 290, 91, 41));
        distance_2->setAutoFillBackground(false);
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(240, 260, 121, 20));
        left = new Led(tab_3);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(450, 110, 51, 51));
        left->setChecked(false);
        left->setColor(QColor(115, 210, 22));
        up = new Led(tab_3);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(520, 50, 51, 51));
        up->setChecked(false);
        up->setColor(QColor(115, 210, 22));
        right = new Led(tab_3);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(590, 110, 51, 51));
        right->setChecked(false);
        right->setColor(QColor(115, 210, 22));
        down = new Led(tab_3);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(520, 170, 51, 51));
        down->setChecked(false);
        down->setColor(QColor(115, 210, 22));
        near = new Led(tab_3);
        near->setObjectName(QStringLiteral("near"));
        near->setGeometry(QRect(429, 286, 51, 51));
        near->setChecked(false);
        near->setColor(QColor(115, 210, 22));
        far = new Led(tab_3);
        far->setObjectName(QStringLiteral("far"));
        far->setGeometry(QRect(429, 220, 51, 51));
        far->setChecked(false);
        far->setColor(QColor(115, 210, 22));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(526, 64, 41, 20));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(447, 124, 61, 20));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(588, 125, 61, 20));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(527, 185, 41, 20));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(437, 235, 41, 20));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(430, 300, 51, 20));
        tabWidget->addTab(tab_3, QString());
        near->raise();
        far->raise();
        sensor_lumin->raise();
        color->raise();
        intensidad->raise();
        color_2->raise();
        label_13->raise();
        horizontalSlider->raise();
        distance->raise();
        checkBox_2->raise();
        distance_2->raise();
        label_14->raise();
        left->raise();
        up->raise();
        right->raise();
        down->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        Grafica_2 = new QwtPlot(tab_4);
        Grafica_2->setObjectName(QStringLiteral("Grafica_2"));
        Grafica_2->setGeometry(QRect(20, 30, 651, 251));
        Grafica_2->setCanvasBackground(brush);
        tabWidget->addTab(tab_4, QString());
        label_12 = new QLabel(MainUserGUI);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setEnabled(true);
        label_12->setGeometry(QRect(600, 10, 121, 91));
        label_12->setFrameShape(QFrame::NoFrame);
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/new/images/logo.png")));
        label_12->setScaledContents(true);
        label_12->setOpenExternalLinks(true);
        QWidget::setTabOrder(serialPortComboBox, pingButton);
        QWidget::setTabOrder(pingButton, runButton);

        retranslateUi(MainUserGUI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainUserGUI);
    } // setupUi

    void retranslateUi(QWidget *MainUserGUI)
    {
        MainUserGUI->setWindowTitle(QApplication::translate("MainUserGUI", "GUIPanel", Q_NULLPTR));
        runButton->setText(QApplication::translate("MainUserGUI", "Inicio", Q_NULLPTR));
        pingButton->setText(QApplication::translate("MainUserGUI", "Ping", Q_NULLPTR));
        serialPortLabel->setText(QApplication::translate("MainUserGUI", "Puerto Serie:", Q_NULLPTR));
        pwmGpio_Check->setText(QApplication::translate("MainUserGUI", "Pwm / Gpio", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        led_1->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        led_1->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        led_2->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        led_2->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainUserGUI", "SW1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainUserGUI", "SW2", Q_NULLPTR));
        BotonesCheckBox->setText(QApplication::translate("MainUserGUI", "Botones ON/OFF", Q_NULLPTR));
        Botones->setText(QApplication::translate("MainUserGUI", "Estado Botones", Q_NULLPTR));
        rojo->setText(QApplication::translate("MainUserGUI", "Rojo", Q_NULLPTR));
        verde->setText(QApplication::translate("MainUserGUI", "Verde", Q_NULLPTR));
        azul->setText(QApplication::translate("MainUserGUI", "Azul", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainUserGUI", "Estado:", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MainUserGUI", "Detenido", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainUserGUI", "Intensidad", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainUserGUI", "Tab 1", Q_NULLPTR));
        ADCCheck->setText(QApplication::translate("MainUserGUI", "Activar ADC", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainUserGUI", "Frecuencia:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainUserGUI", "1 Hz - 5KHz", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainUserGUI", "Resolucion: 8/12 bits", Q_NULLPTR));
        Canal1Check->setText(QApplication::translate("MainUserGUI", "Canal 1", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainUserGUI", "Mostrar:", Q_NULLPTR));
        Canal2Check->setText(QApplication::translate("MainUserGUI", "Canal 2", Q_NULLPTR));
        Canal3Check->setText(QApplication::translate("MainUserGUI", "Canal 3", Q_NULLPTR));
        Canal4Check->setText(QApplication::translate("MainUserGUI", "Canal 4", Q_NULLPTR));
        CanalTodosCheck->setText(QApplication::translate("MainUserGUI", "Mostrar todos", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainUserGUI", "Tab 2", Q_NULLPTR));
        sensor_lumin->setText(QApplication::translate("MainUserGUI", "Brillo y Color", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        color->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        color->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        color_2->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        color_2->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QApplication::translate("MainUserGUI", "Sensor Proximidad", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainUserGUI", "Modo 1 / Modo 2", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainUserGUI", "Distancia medida", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        left->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        left->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        up->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        up->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        right->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        right->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        down->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        down->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        near->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        near->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        far->setToolTip(QApplication::translate("MainUserGUI", "Color Led component", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        far->setWhatsThis(QApplication::translate("MainUserGUI", "Led indicator", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_15->setText(QApplication::translate("MainUserGUI", "Arriba", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainUserGUI", "Izquierda", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainUserGUI", "Derecha", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainUserGUI", "Abajo", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainUserGUI", "Alejar", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainUserGUI", "Acercar", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainUserGUI", "Tab 3", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainUserGUI", "Tab 4", Q_NULLPTR));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainUserGUI: public Ui_MainUserGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUSERGUI_H
