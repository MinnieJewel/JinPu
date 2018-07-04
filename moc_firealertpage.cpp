/****************************************************************************
** Meta object code from reading C++ file 'firealertpage.h'
**
** Created: Thu May 24 10:36:32 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "firealertpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firealertpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FireAlertPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      51,   14,   14,   14, 0x08,
      74,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FireAlertPage[] = {
    "FireAlertPage\0\0on_btn_EmergencyBroadcast_clicked()\0"
    "on_btn_reset_clicked()\0on_btn_quiet_clicked()\0"
    "resetFlag()\0"
};

const QMetaObject FireAlertPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_FireAlertPage,
      qt_meta_data_FireAlertPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FireAlertPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FireAlertPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FireAlertPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FireAlertPage))
        return static_cast<void*>(const_cast< FireAlertPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int FireAlertPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_EmergencyBroadcast_clicked(); break;
        case 1: on_btn_reset_clicked(); break;
        case 2: on_btn_quiet_clicked(); break;
        case 3: resetFlag(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
