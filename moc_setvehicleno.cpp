/****************************************************************************
** Meta object code from reading C++ file 'setvehicleno.h'
**
** Created: Thu May 24 10:37:24 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "setvehicleno.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setvehicleno.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetVehicleNo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   13,   13,   13, 0x08,
      61,   13,   13,   13, 0x08,
      85,   13,   13,   13, 0x08,
     112,   13,   13,   13, 0x08,
     136,   13,   13,   13, 0x08,
     154,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetVehicleNo[] = {
    "SetVehicleNo\0\0on_btn_back_clicked()\0"
    "on_btn_confirm_clicked()\0"
    "on_btn_lineNo_clicked()\0"
    "on_btn_vehicleNo_clicked()\0"
    "setSelectedButton(bool)\0setCurrentNo(int)\0"
    "resetHmiSetWheelDiaCommand()\0"
};

const QMetaObject SetVehicleNo::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_SetVehicleNo,
      qt_meta_data_SetVehicleNo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetVehicleNo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetVehicleNo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetVehicleNo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetVehicleNo))
        return static_cast<void*>(const_cast< SetVehicleNo*>(this));
    return MyBase::qt_metacast(_clname);
}

int SetVehicleNo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_back_clicked(); break;
        case 1: on_btn_confirm_clicked(); break;
        case 2: on_btn_lineNo_clicked(); break;
        case 3: on_btn_vehicleNo_clicked(); break;
        case 4: setSelectedButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: setCurrentNo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: resetHmiSetWheelDiaCommand(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
