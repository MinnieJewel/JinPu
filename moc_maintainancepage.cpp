/****************************************************************************
** Meta object code from reading C++ file 'maintainancepage.h'
**
** Created: Thu May 24 10:37:00 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "maintainancepage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maintainancepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaintainancePage[] = {

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
      18,   17,   17,   17, 0x08,
      49,   17,   17,   17, 0x08,
      80,   17,   17,   17, 0x08,
     107,   17,   17,   17, 0x08,
     143,   17,   17,   17, 0x08,
     165,   17,   17,   17, 0x08,
     190,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaintainancePage[] = {
    "MaintainancePage\0\0on_btn_historyRecord_clicked()\0"
    "on_btn_RunningRecord_clicked()\0"
    "on_btn_setRecord_clicked()\0"
    "on_btn_RunningRecordClear_clicked()\0"
    "on_btn_test_clicked()\0on_btn_paraSet_clicked()\0"
    "on_btn_mainpage_clicked()\0"
};

const QMetaObject MaintainancePage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_MaintainancePage,
      qt_meta_data_MaintainancePage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaintainancePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaintainancePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaintainancePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaintainancePage))
        return static_cast<void*>(const_cast< MaintainancePage*>(this));
    return MyBase::qt_metacast(_clname);
}

int MaintainancePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_historyRecord_clicked(); break;
        case 1: on_btn_RunningRecord_clicked(); break;
        case 2: on_btn_setRecord_clicked(); break;
        case 3: on_btn_RunningRecordClear_clicked(); break;
        case 4: on_btn_test_clicked(); break;
        case 5: on_btn_paraSet_clicked(); break;
        case 6: on_btn_mainpage_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
