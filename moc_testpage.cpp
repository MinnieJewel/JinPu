/****************************************************************************
** Meta object code from reading C++ file 'testpage.h'
**
** Created: Thu May 24 10:37:07 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      65,    9,    9,    9, 0x08,
      87,    9,    9,    9, 0x08,
     114,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestPage[] = {
    "TestPage\0\0on_btn_speedTest_clicked()\0"
    "on_btn_driverTest_clicked()\0"
    "on_btn_back_clicked()\0on_btn_breakTest_clicked()\0"
    "on_btn_tractionTest_clicked()\0"
};

const QMetaObject TestPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_TestPage,
      qt_meta_data_TestPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestPage))
        return static_cast<void*>(const_cast< TestPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int TestPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_speedTest_clicked(); break;
        case 1: on_btn_driverTest_clicked(); break;
        case 2: on_btn_back_clicked(); break;
        case 3: on_btn_breakTest_clicked(); break;
        case 4: on_btn_tractionTest_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
