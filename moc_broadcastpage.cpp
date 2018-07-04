/****************************************************************************
** Meta object code from reading C++ file 'broadcastpage.h'
**
** Created: Thu Jan 12 11:29:37 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "broadcastpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'broadcastpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BroadCastPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_BroadCastPage[] = {
    "BroadCastPage\0"
};

const QMetaObject BroadCastPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_BroadCastPage,
      qt_meta_data_BroadCastPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BroadCastPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BroadCastPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BroadCastPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BroadCastPage))
        return static_cast<void*>(const_cast< BroadCastPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int BroadCastPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
