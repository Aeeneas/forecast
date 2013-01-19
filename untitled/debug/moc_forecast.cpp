/****************************************************************************
** Meta object code from reading C++ file 'forecast.h'
**
** Created: Sat 19. Jan 13:42:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../forecast.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'forecast.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_forecast[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      24,    9,    9,    9, 0x0a,
      53,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_forecast[] = {
    "forecast\0\0takeWeather()\0"
    "loadFinished(QNetworkReply*)\0drawSlot()\0"
};

void forecast::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        forecast *_t = static_cast<forecast *>(_o);
        switch (_id) {
        case 0: _t->takeWeather(); break;
        case 1: _t->loadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->drawSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData forecast::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject forecast::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_forecast,
      qt_meta_data_forecast, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &forecast::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *forecast::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *forecast::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_forecast))
        return static_cast<void*>(const_cast< forecast*>(this));
    return QWidget::qt_metacast(_clname);
}

int forecast::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
