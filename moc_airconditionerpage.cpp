/****************************************************************************
** Meta object code from reading C++ file 'airconditionerpage.h'
**
** Created: Thu May 24 10:36:58 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "airconditionerpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'airconditionerpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AirConditionerPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      56,   19,   19,   19, 0x08,
      75,   19,   19,   19, 0x08,
      91,   19,   19,   19, 0x08,
     107,   19,   19,   19, 0x08,
     132,   19,   19,   19, 0x08,
     153,   19,   19,   19, 0x08,
     183,  177,   19,   19, 0x08,
     202,   19,   19,   19, 0x08,
     214,   19,   19,   19, 0x08,
     230,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AirConditionerPage[] = {
    "AirConditionerPage\0\0"
    "on_btn_EmergencyBroadcast_clicked()\0"
    "selectVehicle(int)\0selectMode(int)\0"
    "selectWind(int)\0on_btn_confirm_clicked()\0"
    "on_btn_add_clicked()\0on_btn_reduse_clicked()\0"
    "state\0setSpeedState(int)\0resetFlag()\0"
    "resetTempFlag()\0resetWindFlag()\0"
};

const QMetaObject AirConditionerPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_AirConditionerPage,
      qt_meta_data_AirConditionerPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AirConditionerPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AirConditionerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AirConditionerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AirConditionerPage))
        return static_cast<void*>(const_cast< AirConditionerPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int AirConditionerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_EmergencyBroadcast_clicked(); break;
        case 1: selectVehicle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: selectMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: selectWind((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_btn_confirm_clicked(); break;
        case 5: on_btn_add_clicked(); break;
        case 6: on_btn_reduse_clicked(); break;
        case 7: setSpeedState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: resetFlag(); break;
        case 9: resetTempFlag(); break;
        case 10: resetWindFlag(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
