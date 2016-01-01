/****************************************************************************
** Meta object code from reading C++ file 'receThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../receThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_receThread_t {
    QByteArrayData data[10];
    char stringdata[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_receThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_receThread_t qt_meta_stringdata_receThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "receThread"
QT_MOC_LITERAL(1, 11, 12), // "setVibration"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "response"
QT_MOC_LITERAL(4, 34, 1), // "s"
QT_MOC_LITERAL(5, 36, 9), // "setTemper"
QT_MOC_LITERAL(6, 46, 6), // "temper"
QT_MOC_LITERAL(7, 53, 11), // "setHumidity"
QT_MOC_LITERAL(8, 65, 8), // "setLight"
QT_MOC_LITERAL(9, 74, 11) // "setManacher"

    },
    "receThread\0setVibration\0\0response\0s\0"
    "setTemper\0temper\0setHumidity\0setLight\0"
    "setManacher"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_receThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,
       8,    1,   54,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void receThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        receThread *_t = static_cast<receThread *>(_o);
        switch (_id) {
        case 0: _t->setVibration(); break;
        case 1: _t->response((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setTemper((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->setHumidity((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->setLight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->setManacher((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (receThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::setVibration)) {
                *result = 0;
            }
        }
        {
            typedef void (receThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::response)) {
                *result = 1;
            }
        }
        {
            typedef void (receThread::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::setTemper)) {
                *result = 2;
            }
        }
        {
            typedef void (receThread::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::setHumidity)) {
                *result = 3;
            }
        }
        {
            typedef void (receThread::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::setLight)) {
                *result = 4;
            }
        }
        {
            typedef void (receThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receThread::setManacher)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject receThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_receThread.data,
      qt_meta_data_receThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *receThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *receThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_receThread.stringdata))
        return static_cast<void*>(const_cast< receThread*>(this));
    return QThread::qt_metacast(_clname);
}

int receThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void receThread::setVibration()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void receThread::response(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void receThread::setTemper(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void receThread::setHumidity(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void receThread::setLight(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void receThread::setManacher(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
