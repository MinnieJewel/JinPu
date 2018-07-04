/****************************************************************************
** Meta object code from reading C++ file 'debugpage.h'
**
** Created: Thu May 24 10:36:00 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "debugpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DebugPage[] = {

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
      11,   10,   10,   10, 0x08,
      40,   10,   10,   10, 0x08,
      69,   10,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,
     124,   10,   10,   10, 0x08,
     152,   10,   10,   10, 0x08,
     184,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DebugPage[] = {
    "DebugPage\0\0on_btn_DataMoniter_clicked()\0"
    "on_btn_versionInfo_clicked()\0"
    "on_btn_PublishSet_clicked()\0"
    "on_btn_RIOMDebug_clicked()\0"
    "on_btn_LifeSignal_clicked()\0"
    "on_btn_RIOMDetailInfo_clicked()\0"
    "on_btn_Back_clicked()\0"
};

const QMetaObject DebugPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_DebugPage,
      qt_meta_data_DebugPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DebugPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DebugPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DebugPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DebugPage))
        return static_cast<void*>(const_cast< DebugPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int DebugPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_DataMoniter_clicked(); break;
        case 1: on_btn_versionInfo_clicked(); break;
        case 2: on_btn_PublishSet_clicked(); break;
        case 3: on_btn_RIOMDebug_clicked(); break;
        case 4: on_btn_LifeSignal_clicked(); break;
        case 5: on_btn_RIOMDetailInfo_clicked(); break;
        case 6: on_btn_Back_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
