/****************************************************************************
** Meta object code from reading C++ file 'brakeselfcheckpage.h'
**
** Created: Thu May 24 10:36:34 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "brakeselfcheckpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brakeselfcheckpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrakeSelfCheckPage[] = {

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
      20,   19,   19,   19, 0x08,
      43,   19,   19,   19, 0x08,
      66,   19,   19,   19, 0x08,
      91,   88,   19,   19, 0x08,
     114,   19,   19,   19, 0x08,
     130,   19,   19,   19, 0x08,
     156,  148,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BrakeSelfCheckPage[] = {
    "BrakeSelfCheckPage\0\0on_btn_cease_clicked()\0"
    "on_btn_start_clicked()\0on_btn_exit_clicked()\0"
    "id\0setSelectedButton(int)\0setDetectFlag()\0"
    "resetDetectFlag()\0checked\0"
    "setToggleButton(bool)\0"
};

const QMetaObject BrakeSelfCheckPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_BrakeSelfCheckPage,
      qt_meta_data_BrakeSelfCheckPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrakeSelfCheckPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrakeSelfCheckPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrakeSelfCheckPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrakeSelfCheckPage))
        return static_cast<void*>(const_cast< BrakeSelfCheckPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int BrakeSelfCheckPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_cease_clicked(); break;
        case 1: on_btn_start_clicked(); break;
        case 2: on_btn_exit_clicked(); break;
        case 3: setSelectedButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setDetectFlag(); break;
        case 5: resetDetectFlag(); break;
        case 6: setToggleButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
