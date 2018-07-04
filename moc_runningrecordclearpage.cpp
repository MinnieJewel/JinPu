/****************************************************************************
** Meta object code from reading C++ file 'runningrecordclearpage.h'
**
** Created: Thu May 24 10:36:43 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "runningrecordclearpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runningrecordclearpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunningRecordClearPage[] = {

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
      31,   24,   23,   23, 0x0a,
      55,   23,   23,   23, 0x0a,
      74,   23,   23,   23, 0x0a,
      92,   23,   23,   23, 0x0a,
     110,   23,   23,   23, 0x0a,
     130,   23,   23,   23, 0x0a,
     145,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RunningRecordClearPage[] = {
    "RunningRecordClearPage\0\0button\0"
    "onClearButtonClick(int)\0resetServiceFlag()\0"
    "resetERMAP1Flag()\0resetERMAP2Flag()\0"
    "resetTractionFlag()\0resetAuxFlag()\0"
    "on_btn_back_clicked()\0"
};

const QMetaObject RunningRecordClearPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_RunningRecordClearPage,
      qt_meta_data_RunningRecordClearPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunningRecordClearPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunningRecordClearPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunningRecordClearPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunningRecordClearPage))
        return static_cast<void*>(const_cast< RunningRecordClearPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int RunningRecordClearPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onClearButtonClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: resetServiceFlag(); break;
        case 2: resetERMAP1Flag(); break;
        case 3: resetERMAP2Flag(); break;
        case 4: resetTractionFlag(); break;
        case 5: resetAuxFlag(); break;
        case 6: on_btn_back_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
