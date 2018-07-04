/****************************************************************************
** Meta object code from reading C++ file 'setpasswordpage.h'
**
** Created: Thu May 24 10:36:09 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "setpasswordpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setpasswordpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetPasswordPage[] = {

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
      17,   16,   16,   16, 0x08,
      39,   16,   16,   16, 0x08,
      64,   16,   16,   16, 0x08,
      84,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetPasswordPage[] = {
    "SetPasswordPage\0\0on_btn_back_clicked()\0"
    "on_btn_confirm_clicked()\0typeInPassword(int)\0"
    "selectInsert(int)\0"
};

const QMetaObject SetPasswordPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_SetPasswordPage,
      qt_meta_data_SetPasswordPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetPasswordPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetPasswordPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetPasswordPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetPasswordPage))
        return static_cast<void*>(const_cast< SetPasswordPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int SetPasswordPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_back_clicked(); break;
        case 1: on_btn_confirm_clicked(); break;
        case 2: typeInPassword((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: selectInsert((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
