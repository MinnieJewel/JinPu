/****************************************************************************
** Meta object code from reading C++ file 'datamoniter.h'
**
** Created: Thu May 24 10:37:19 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datamoniter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamoniter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataMoniter[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      38,   35,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataMoniter[] = {
    "DataMoniter\0\0on_btn_back_clicked()\0"
    "id\0onBtnClicked(int)\0"
};

const QMetaObject DataMoniter::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_DataMoniter,
      qt_meta_data_DataMoniter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataMoniter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataMoniter))
        return static_cast<void*>(const_cast< DataMoniter*>(this));
    return MyBase::qt_metacast(_clname);
}

int DataMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_back_clicked(); break;
        case 1: onBtnClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
