/****************************************************************************
** Meta object code from reading C++ file 'timesetpage.h'
**
** Created: Thu May 24 10:37:03 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timesetpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timesetpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimeSetPage[] = {

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
      13,   12,   12,   12, 0x0a,
      37,   31,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TimeSetPage[] = {
    "TimeSetPage\0\0mykeyPressEvent()\0index\0"
    "setSelectedButton(int)\0resetHmiSetTimeCommand()\0"
    "setHmiSetTimeCommand()\0setTimeCommand()\0"
};

const QMetaObject TimeSetPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_TimeSetPage,
      qt_meta_data_TimeSetPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeSetPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeSetPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeSetPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeSetPage))
        return static_cast<void*>(const_cast< TimeSetPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int TimeSetPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mykeyPressEvent(); break;
        case 1: setSelectedButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: resetHmiSetTimeCommand(); break;
        case 3: setHmiSetTimeCommand(); break;
        case 4: setTimeCommand(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
