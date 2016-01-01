/****************************************************************************
** Meta object code from reading C++ file 'comport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../comport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_comPort_t {
    QByteArrayData data[19];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_comPort_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_comPort_t qt_meta_stringdata_comPort = {
    {
QT_MOC_LITERAL(0, 0, 7), // "comPort"
QT_MOC_LITERAL(1, 8, 8), // "slotSend"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 16), // "slotSendTextArea"
QT_MOC_LITERAL(4, 35, 1), // "s"
QT_MOC_LITERAL(5, 37, 15), // "slotSetManacher"
QT_MOC_LITERAL(6, 53, 17), // "slotSetSendButton"
QT_MOC_LITERAL(7, 71, 19), // "soltReceStartButton"
QT_MOC_LITERAL(8, 91, 18), // "soltReceStopButton"
QT_MOC_LITERAL(9, 110, 16), // "slotReceTextArea"
QT_MOC_LITERAL(10, 127, 18), // "slotSetTemperature"
QT_MOC_LITERAL(11, 146, 6), // "temper"
QT_MOC_LITERAL(12, 153, 15), // "slotSetHumidity"
QT_MOC_LITERAL(13, 169, 12), // "slotSetLight"
QT_MOC_LITERAL(14, 182, 16), // "slotSetVibration"
QT_MOC_LITERAL(15, 199, 8), // "slotExit"
QT_MOC_LITERAL(16, 208, 17), // "slotChangeToType0"
QT_MOC_LITERAL(17, 226, 17), // "slotChangeToType1"
QT_MOC_LITERAL(18, 244, 17) // "slotChangeToType2"

    },
    "comPort\0slotSend\0\0slotSendTextArea\0s\0"
    "slotSetManacher\0slotSetSendButton\0"
    "soltReceStartButton\0soltReceStopButton\0"
    "slotReceTextArea\0slotSetTemperature\0"
    "temper\0slotSetHumidity\0slotSetLight\0"
    "slotSetVibration\0slotExit\0slotChangeToType0\0"
    "slotChangeToType1\0slotChangeToType2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_comPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    1,   90,    2, 0x0a /* Public */,
       5,    1,   93,    2, 0x0a /* Public */,
       6,    0,   96,    2, 0x0a /* Public */,
       7,    0,   97,    2, 0x0a /* Public */,
       8,    0,   98,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x0a /* Public */,
      12,    1,  105,    2, 0x0a /* Public */,
      13,    1,  108,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    0,  112,    2, 0x0a /* Public */,
      16,    0,  113,    2, 0x0a /* Public */,
      17,    0,  114,    2, 0x0a /* Public */,
      18,    0,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void comPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        comPort *_t = static_cast<comPort *>(_o);
        switch (_id) {
        case 0: _t->slotSend(); break;
        case 1: _t->slotSendTextArea((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slotSetManacher((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slotSetSendButton(); break;
        case 4: _t->soltReceStartButton(); break;
        case 5: _t->soltReceStopButton(); break;
        case 6: _t->slotReceTextArea((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slotSetTemperature((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: _t->slotSetHumidity((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->slotSetLight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->slotSetVibration(); break;
        case 11: _t->slotExit(); break;
        case 12: _t->slotChangeToType0(); break;
        case 13: _t->slotChangeToType1(); break;
        case 14: _t->slotChangeToType2(); break;
        default: ;
        }
    }
}

const QMetaObject comPort::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_comPort.data,
      qt_meta_data_comPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *comPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *comPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_comPort.stringdata))
        return static_cast<void*>(const_cast< comPort*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int comPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
