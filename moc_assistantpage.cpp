/****************************************************************************
** Meta object code from reading C++ file 'assistantpage.h'
**
** Created: Thu May 24 10:36:51 2018
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "assistantpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assistantpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AssistantPage[] = {

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
      15,   14,   14,   14, 0x08,
      51,   14,   14,   14, 0x08,
      75,   14,   14,   14, 0x08,
      87,   14,   14,   14, 0x08,
     111,   14,   14,   14, 0x08,
     135,   14,   14,   14, 0x08,
     158,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AssistantPage[] = {
    "AssistantPage\0\0on_btn_EmergencyBroadcast_clicked()\0"
    "on_pushButton_clicked()\0resetFlag()\0"
    "on_btn_reset1_clicked()\0on_btn_reset2_clicked()\0"
    "setToggleButton1(bool)\0setToggleButton2(bool)\0"
};

const QMetaObject AssistantPage::staticMetaObject = {
    { &MyBase::staticMetaObject, qt_meta_stringdata_AssistantPage,
      qt_meta_data_AssistantPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AssistantPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AssistantPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AssistantPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AssistantPage))
        return static_cast<void*>(const_cast< AssistantPage*>(this));
    return MyBase::qt_metacast(_clname);
}

int AssistantPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_EmergencyBroadcast_clicked(); break;
        case 1: on_pushButton_clicked(); break;
        case 2: resetFlag(); break;
        case 3: on_btn_reset1_clicked(); break;
        case 4: on_btn_reset2_clicked(); break;
        case 5: setToggleButton1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: setToggleButton2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
