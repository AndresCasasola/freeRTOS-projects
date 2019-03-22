/****************************************************************************
** Meta object code from reading C++ file 'qtivarpc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtApplication/qtivarpc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtivarpc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTivaRPC_t {
    QByteArrayData data[66];
    char stringdata0[949];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTivaRPC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTivaRPC_t qt_meta_stringdata_QTivaRPC = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QTivaRPC"
QT_MOC_LITERAL(1, 9, 13), // "statusChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "status"
QT_MOC_LITERAL(4, 31, 7), // "message"
QT_MOC_LITERAL(5, 39, 20), // "pingReceivedFromTiva"
QT_MOC_LITERAL(6, 60, 23), // "commandRejectedFromTiva"
QT_MOC_LITERAL(7, 84, 7), // "int16_t"
QT_MOC_LITERAL(8, 92, 4), // "code"
QT_MOC_LITERAL(9, 97, 20), // "receiveSwitchesState"
QT_MOC_LITERAL(10, 118, 6), // "state1"
QT_MOC_LITERAL(11, 125, 6), // "state2"
QT_MOC_LITERAL(12, 132, 18), // "ADC8SampleReceived"
QT_MOC_LITERAL(13, 151, 22), // "PARAMETERS_ADC8_PACKET"
QT_MOC_LITERAL(14, 174, 9), // "parametro"
QT_MOC_LITERAL(15, 184, 19), // "ADC12SampleReceived"
QT_MOC_LITERAL(16, 204, 23), // "PARAMETERS_ADC12_PACKET"
QT_MOC_LITERAL(17, 228, 19), // "IncommingSensorData"
QT_MOC_LITERAL(18, 248, 22), // "PARAMETERS_SENSOR_READ"
QT_MOC_LITERAL(19, 271, 28), // "IncommingProximitySensorData"
QT_MOC_LITERAL(20, 300, 27), // "PARAMETERS_PROXIMITY_SENSOR"
QT_MOC_LITERAL(21, 328, 26), // "IncommingGestureSensorData"
QT_MOC_LITERAL(22, 355, 25), // "PARAMETERS_GESTURE_SENSOR"
QT_MOC_LITERAL(23, 381, 27), // "IncommingGestureSensorData2"
QT_MOC_LITERAL(24, 409, 26), // "PARAMETERS_GESTURE_SENSOR2"
QT_MOC_LITERAL(25, 436, 14), // "startRPCClient"
QT_MOC_LITERAL(26, 451, 6), // "puerto"
QT_MOC_LITERAL(27, 458, 4), // "ping"
QT_MOC_LITERAL(28, 463, 7), // "LEDGpio"
QT_MOC_LITERAL(29, 471, 3), // "red"
QT_MOC_LITERAL(30, 475, 5), // "green"
QT_MOC_LITERAL(31, 481, 4), // "blue"
QT_MOC_LITERAL(32, 486, 16), // "LEDPwmBrightness"
QT_MOC_LITERAL(33, 503, 5), // "value"
QT_MOC_LITERAL(34, 509, 11), // "LEDPwmColor"
QT_MOC_LITERAL(35, 521, 5), // "color"
QT_MOC_LITERAL(36, 527, 10), // "switchMode"
QT_MOC_LITERAL(37, 538, 4), // "mode"
QT_MOC_LITERAL(38, 543, 13), // "switchesSound"
QT_MOC_LITERAL(39, 557, 23), // "switchesInterruptEnable"
QT_MOC_LITERAL(40, 581, 5), // "check"
QT_MOC_LITERAL(41, 587, 9), // "ADCSample"
QT_MOC_LITERAL(42, 597, 9), // "switchADC"
QT_MOC_LITERAL(43, 607, 6), // "active"
QT_MOC_LITERAL(44, 614, 16), // "ADCFrequencySend"
QT_MOC_LITERAL(45, 631, 4), // "freq"
QT_MOC_LITERAL(46, 636, 17), // "ADCResolutionSend"
QT_MOC_LITERAL(47, 654, 3), // "res"
QT_MOC_LITERAL(48, 658, 10), // "SensorRead"
QT_MOC_LITERAL(49, 669, 19), // "SensorProximitySend"
QT_MOC_LITERAL(50, 689, 26), // "ProximitySensorChangeState"
QT_MOC_LITERAL(51, 716, 5), // "state"
QT_MOC_LITERAL(52, 722, 26), // "processIncommingSerialData"
QT_MOC_LITERAL(53, 749, 10), // "TivaStatus"
QT_MOC_LITERAL(54, 760, 13), // "TivaConnected"
QT_MOC_LITERAL(55, 774, 16), // "TivaDisconnected"
QT_MOC_LITERAL(56, 791, 13), // "OpenPortError"
QT_MOC_LITERAL(57, 805, 13), // "BaudRateError"
QT_MOC_LITERAL(58, 819, 12), // "DataBitError"
QT_MOC_LITERAL(59, 832, 11), // "ParityError"
QT_MOC_LITERAL(60, 844, 9), // "StopError"
QT_MOC_LITERAL(61, 854, 16), // "FlowControlError"
QT_MOC_LITERAL(62, 871, 21), // "UnexpectedPacketError"
QT_MOC_LITERAL(63, 893, 21), // "FragmentedPacketError"
QT_MOC_LITERAL(64, 915, 15), // "CRCorStuffError"
QT_MOC_LITERAL(65, 931, 17) // "ReceivedDataError"

    },
    "QTivaRPC\0statusChanged\0\0status\0message\0"
    "pingReceivedFromTiva\0commandRejectedFromTiva\0"
    "int16_t\0code\0receiveSwitchesState\0"
    "state1\0state2\0ADC8SampleReceived\0"
    "PARAMETERS_ADC8_PACKET\0parametro\0"
    "ADC12SampleReceived\0PARAMETERS_ADC12_PACKET\0"
    "IncommingSensorData\0PARAMETERS_SENSOR_READ\0"
    "IncommingProximitySensorData\0"
    "PARAMETERS_PROXIMITY_SENSOR\0"
    "IncommingGestureSensorData\0"
    "PARAMETERS_GESTURE_SENSOR\0"
    "IncommingGestureSensorData2\0"
    "PARAMETERS_GESTURE_SENSOR2\0startRPCClient\0"
    "puerto\0ping\0LEDGpio\0red\0green\0blue\0"
    "LEDPwmBrightness\0value\0LEDPwmColor\0"
    "color\0switchMode\0mode\0switchesSound\0"
    "switchesInterruptEnable\0check\0ADCSample\0"
    "switchADC\0active\0ADCFrequencySend\0"
    "freq\0ADCResolutionSend\0res\0SensorRead\0"
    "SensorProximitySend\0ProximitySensorChangeState\0"
    "state\0processIncommingSerialData\0"
    "TivaStatus\0TivaConnected\0TivaDisconnected\0"
    "OpenPortError\0BaudRateError\0DataBitError\0"
    "ParityError\0StopError\0FlowControlError\0"
    "UnexpectedPacketError\0FragmentedPacketError\0"
    "CRCorStuffError\0ReceivedDataError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTivaRPC[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       1,  218, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  144,    2, 0x06 /* Public */,
       5,    0,  149,    2, 0x06 /* Public */,
       6,    1,  150,    2, 0x06 /* Public */,
       9,    2,  153,    2, 0x06 /* Public */,
      12,    1,  158,    2, 0x06 /* Public */,
      15,    1,  161,    2, 0x06 /* Public */,
      17,    1,  164,    2, 0x06 /* Public */,
      19,    1,  167,    2, 0x06 /* Public */,
      21,    1,  170,    2, 0x06 /* Public */,
      23,    1,  173,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,  176,    2, 0x0a /* Public */,
      27,    0,  179,    2, 0x0a /* Public */,
      28,    3,  180,    2, 0x0a /* Public */,
      32,    1,  187,    2, 0x0a /* Public */,
      34,    1,  190,    2, 0x0a /* Public */,
      36,    1,  193,    2, 0x0a /* Public */,
      38,    0,  196,    2, 0x0a /* Public */,
      39,    1,  197,    2, 0x0a /* Public */,
      41,    0,  200,    2, 0x0a /* Public */,
      42,    1,  201,    2, 0x0a /* Public */,
      44,    1,  204,    2, 0x0a /* Public */,
      46,    1,  207,    2, 0x0a /* Public */,
      48,    0,  210,    2, 0x0a /* Public */,
      49,    1,  211,    2, 0x0a /* Public */,
      50,    1,  214,    2, 0x0a /* Public */,
      52,    0,  217,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,
    QMetaType::Void, 0x80000000 | 18,   14,
    QMetaType::Void, 0x80000000 | 20,   14,
    QMetaType::Void, 0x80000000 | 22,   14,
    QMetaType::Void, 0x80000000 | 24,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   29,   30,   31,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void, QMetaType::QColor,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void, QMetaType::Double,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void,

 // enums: name, flags, count, data
      53, 0x0,   12,  222,

 // enum data: key, value
      54, uint(QTivaRPC::TivaConnected),
      55, uint(QTivaRPC::TivaDisconnected),
      56, uint(QTivaRPC::OpenPortError),
      57, uint(QTivaRPC::BaudRateError),
      58, uint(QTivaRPC::DataBitError),
      59, uint(QTivaRPC::ParityError),
      60, uint(QTivaRPC::StopError),
      61, uint(QTivaRPC::FlowControlError),
      62, uint(QTivaRPC::UnexpectedPacketError),
      63, uint(QTivaRPC::FragmentedPacketError),
      64, uint(QTivaRPC::CRCorStuffError),
      65, uint(QTivaRPC::ReceivedDataError),

       0        // eod
};

void QTivaRPC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTivaRPC *_t = static_cast<QTivaRPC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->pingReceivedFromTiva(); break;
        case 2: _t->commandRejectedFromTiva((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 3: _t->receiveSwitchesState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->ADC8SampleReceived((*reinterpret_cast< PARAMETERS_ADC8_PACKET(*)>(_a[1]))); break;
        case 5: _t->ADC12SampleReceived((*reinterpret_cast< PARAMETERS_ADC12_PACKET(*)>(_a[1]))); break;
        case 6: _t->IncommingSensorData((*reinterpret_cast< PARAMETERS_SENSOR_READ(*)>(_a[1]))); break;
        case 7: _t->IncommingProximitySensorData((*reinterpret_cast< PARAMETERS_PROXIMITY_SENSOR(*)>(_a[1]))); break;
        case 8: _t->IncommingGestureSensorData((*reinterpret_cast< PARAMETERS_GESTURE_SENSOR(*)>(_a[1]))); break;
        case 9: _t->IncommingGestureSensorData2((*reinterpret_cast< PARAMETERS_GESTURE_SENSOR2(*)>(_a[1]))); break;
        case 10: _t->startRPCClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->ping(); break;
        case 12: _t->LEDGpio((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->LEDPwmBrightness((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->LEDPwmColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 15: _t->switchMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->switchesSound(); break;
        case 17: _t->switchesInterruptEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->ADCSample(); break;
        case 19: _t->switchADC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->ADCFrequencySend((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->ADCResolutionSend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->SensorRead(); break;
        case 23: _t->SensorProximitySend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->ProximitySensorChangeState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->processIncommingSerialData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QTivaRPC::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::statusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::pingReceivedFromTiva)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(int16_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::commandRejectedFromTiva)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::receiveSwitchesState)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_ADC8_PACKET );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::ADC8SampleReceived)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_ADC12_PACKET );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::ADC12SampleReceived)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_SENSOR_READ );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::IncommingSensorData)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_PROXIMITY_SENSOR );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::IncommingProximitySensorData)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_GESTURE_SENSOR );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::IncommingGestureSensorData)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (QTivaRPC::*_t)(PARAMETERS_GESTURE_SENSOR2 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTivaRPC::IncommingGestureSensorData2)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject QTivaRPC::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QTivaRPC.data,
      qt_meta_data_QTivaRPC,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QTivaRPC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTivaRPC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTivaRPC.stringdata0))
        return static_cast<void*>(const_cast< QTivaRPC*>(this));
    return QObject::qt_metacast(_clname);
}

int QTivaRPC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void QTivaRPC::statusChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTivaRPC::pingReceivedFromTiva()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QTivaRPC::commandRejectedFromTiva(int16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QTivaRPC::receiveSwitchesState(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QTivaRPC::ADC8SampleReceived(PARAMETERS_ADC8_PACKET _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QTivaRPC::ADC12SampleReceived(PARAMETERS_ADC12_PACKET _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QTivaRPC::IncommingSensorData(PARAMETERS_SENSOR_READ _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QTivaRPC::IncommingProximitySensorData(PARAMETERS_PROXIMITY_SENSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QTivaRPC::IncommingGestureSensorData(PARAMETERS_GESTURE_SENSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QTivaRPC::IncommingGestureSensorData2(PARAMETERS_GESTURE_SENSOR2 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
