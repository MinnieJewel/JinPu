/****************************************************************************
** Meta object code from reading C++ file 'chargerpage.h'
**
** Created: Thu May 24 10:37:14 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chargerpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chargerpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChargerPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      49,   12,   12,   12, 0x08,
      73,   12,   12,   12, 0x08,
      97,   12,   12,   12, 0x08,
     109,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChargerPage[] = {
    "ChargerPage\0\0on_btn_EmergencyBroadcast_clicked()\0"
    "on_btn_reset2_clicked()\0on_btn_reset1_clicked()\0"
    "resetFlag()\0setToggleButton1(bool)\0"
    "setToggleButton2(bool)\0"
};

const QMetaObject ChargerPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_ChargerPage,
      qt_meta_data_ChargerPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChargerPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChargerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChargerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChargerPage))
        return static_cast<void*>(const_cast< ChargerPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int ChargerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_EmergencyBroadcast_clicked(); break;
        case 1: on_btn_reset2_clicked(); break;
        case 2: on_btn_reset1_clicked(); break;
        case 3: resetFlag(); break;
        case 4: setToggleButton1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: setToggleButton2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
