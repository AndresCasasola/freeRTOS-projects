/****************************************************************************
** Meta object code from reading C++ file 'mainusergui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtApplication/mainusergui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainusergui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainUserGUI_t {
    QByteArrayData data[41];
    char stringdata0[726];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainUserGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainUserGUI_t qt_meta_stringdata_MainUserGUI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MainUserGUI"
QT_MOC_LITERAL(1, 12, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 41), // "on_serialPortComboBox_current..."
QT_MOC_LITERAL(4, 76, 4), // "arg1"
QT_MOC_LITERAL(5, 81, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 103, 26), // "on_colorWheel_colorChanged"
QT_MOC_LITERAL(7, 130, 10), // "cambiaLEDs"
QT_MOC_LITERAL(8, 141, 17), // "tivaStatusChanged"
QT_MOC_LITERAL(9, 159, 6), // "status"
QT_MOC_LITERAL(10, 166, 7), // "message"
QT_MOC_LITERAL(11, 174, 20), // "pingResponseReceived"
QT_MOC_LITERAL(12, 195, 15), // "CommandRejected"
QT_MOC_LITERAL(13, 211, 7), // "int16_t"
QT_MOC_LITERAL(14, 219, 4), // "code"
QT_MOC_LITERAL(15, 224, 16), // "LEDPwmBrightness"
QT_MOC_LITERAL(16, 241, 5), // "value"
QT_MOC_LITERAL(17, 247, 24), // "on_pwmGpio_Check_toggled"
QT_MOC_LITERAL(18, 272, 7), // "checked"
QT_MOC_LITERAL(19, 280, 19), // "changeSwitchesState"
QT_MOC_LITERAL(20, 300, 6), // "state1"
QT_MOC_LITERAL(21, 307, 6), // "state2"
QT_MOC_LITERAL(22, 314, 14), // "ADC8SampleShow"
QT_MOC_LITERAL(23, 329, 22), // "PARAMETERS_ADC8_PACKET"
QT_MOC_LITERAL(24, 352, 9), // "parametro"
QT_MOC_LITERAL(25, 362, 15), // "ADC12SampleShow"
QT_MOC_LITERAL(26, 378, 23), // "PARAMETERS_ADC12_PACKET"
QT_MOC_LITERAL(27, 402, 28), // "on_ADCFrequency_valueChanged"
QT_MOC_LITERAL(28, 431, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(29, 451, 23), // "on_sensor_lumin_clicked"
QT_MOC_LITERAL(30, 475, 14), // "SensorDataShow"
QT_MOC_LITERAL(31, 490, 22), // "PARAMETERS_SENSOR_READ"
QT_MOC_LITERAL(32, 513, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(33, 535, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(34, 567, 8), // "position"
QT_MOC_LITERAL(35, 576, 23), // "ProximitySensorDataShow"
QT_MOC_LITERAL(36, 600, 27), // "PARAMETERS_PROXIMITY_SENSOR"
QT_MOC_LITERAL(37, 628, 21), // "GestureSensorDataShow"
QT_MOC_LITERAL(38, 650, 25), // "PARAMETERS_GESTURE_SENSOR"
QT_MOC_LITERAL(39, 676, 22), // "GestureSensorDataShow2"
QT_MOC_LITERAL(40, 699, 26) // "PARAMETERS_GESTURE_SENSOR2"

    },
    "MainUserGUI\0on_runButton_clicked\0\0"
    "on_serialPortComboBox_currentIndexChanged\0"
    "arg1\0on_pushButton_clicked\0"
    "on_colorWheel_colorChanged\0cambiaLEDs\0"
    "tivaStatusChanged\0status\0message\0"
    "pingResponseReceived\0CommandRejected\0"
    "int16_t\0code\0LEDPwmBrightness\0value\0"
    "on_pwmGpio_Check_toggled\0checked\0"
    "changeSwitchesState\0state1\0state2\0"
    "ADC8SampleShow\0PARAMETERS_ADC8_PACKET\0"
    "parametro\0ADC12SampleShow\0"
    "PARAMETERS_ADC12_PACKET\0"
    "on_ADCFrequency_valueChanged\0"
    "on_checkBox_clicked\0on_sensor_lumin_clicked\0"
    "SensorDataShow\0PARAMETERS_SENSOR_READ\0"
    "on_checkBox_2_clicked\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0ProximitySensorDataShow\0"
    "PARAMETERS_PROXIMITY_SENSOR\0"
    "GestureSensorDataShow\0PARAMETERS_GESTURE_SENSOR\0"
    "GestureSensorDataShow2\0"
    "PARAMETERS_GESTURE_SENSOR2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainUserGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x08 /* Private */,
       3,    1,  125,    2, 0x08 /* Private */,
       5,    0,  128,    2, 0x08 /* Private */,
       6,    1,  129,    2, 0x08 /* Private */,
       7,    0,  132,    2, 0x08 /* Private */,
       8,    2,  133,    2, 0x08 /* Private */,
      11,    0,  138,    2, 0x08 /* Private */,
      12,    1,  139,    2, 0x08 /* Private */,
      15,    1,  142,    2, 0x08 /* Private */,
      17,    1,  145,    2, 0x08 /* Private */,
      19,    2,  148,    2, 0x08 /* Private */,
      22,    1,  153,    2, 0x08 /* Private */,
      25,    1,  156,    2, 0x08 /* Private */,
      27,    1,  159,    2, 0x08 /* Private */,
      28,    1,  162,    2, 0x08 /* Private */,
      29,    0,  165,    2, 0x08 /* Private */,
      30,    1,  166,    2, 0x08 /* Private */,
      32,    1,  169,    2, 0x08 /* Private */,
      33,    1,  172,    2, 0x08 /* Private */,
      35,    1,  175,    2, 0x08 /* Private */,
      37,    1,  178,    2, 0x08 /* Private */,
      39,    1,  181,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26,   24,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   24,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, 0x80000000 | 36,   24,
    QMetaType::Void, 0x80000000 | 38,   24,
    QMetaType::Void, 0x80000000 | 40,   24,

       0        // eod
};

void MainUserGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainUserGUI *_t = static_cast<MainUserGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_runButton_clicked(); break;
        case 1: _t->on_serialPortComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_colorWheel_colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->cambiaLEDs(); break;
        case 5: _t->tivaStatusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->pingResponseReceived(); break;
        case 7: _t->CommandRejected((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 8: _t->LEDPwmBrightness((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_pwmGpio_Check_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->changeSwitchesState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->ADC8SampleShow((*reinterpret_cast< PARAMETERS_ADC8_PACKET(*)>(_a[1]))); break;
        case 12: _t->ADC12SampleShow((*reinterpret_cast< PARAMETERS_ADC12_PACKET(*)>(_a[1]))); break;
        case 13: _t->on_ADCFrequency_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_sensor_lumin_clicked(); break;
        case 16: _t->SensorDataShow((*reinterpret_cast< PARAMETERS_SENSOR_READ(*)>(_a[1]))); break;
        case 17: _t->on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->ProximitySensorDataShow((*reinterpret_cast< PARAMETERS_PROXIMITY_SENSOR(*)>(_a[1]))); break;
        case 20: _t->GestureSensorDataShow((*reinterpret_cast< PARAMETERS_GESTURE_SENSOR(*)>(_a[1]))); break;
        case 21: _t->GestureSensorDataShow2((*reinterpret_cast< PARAMETERS_GESTURE_SENSOR2(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainUserGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainUserGUI.data,
      qt_meta_data_MainUserGUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainUserGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainUserGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainUserGUI.stringdata0))
        return static_cast<void*>(const_cast< MainUserGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainUserGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
