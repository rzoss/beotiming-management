/****************************************************************************
** Meta object code from reading C++ file 'hardwarekonfiguration.h'
**
** Created: Tue 2. Sep 15:50:38 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hardwarekonfiguration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardwarekonfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HardwareKonfiguration[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      46,   22,   22,   22, 0x08,
      87,   70,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HardwareKonfiguration[] = {
    "HardwareKonfiguration\0\0on_okButton_released()\0"
    "on_canButton_released()\0current,previous\0"
    "on_streckenTreeWidget_currentItemChanged(QTreeWidgetItem*,QTreeWidgetI"
    "tem*)\0"
};

const QMetaObject HardwareKonfiguration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HardwareKonfiguration,
      qt_meta_data_HardwareKonfiguration, 0 }
};

const QMetaObject *HardwareKonfiguration::metaObject() const
{
    return &staticMetaObject;
}

void *HardwareKonfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HardwareKonfiguration))
	return static_cast<void*>(const_cast< HardwareKonfiguration*>(this));
    return QDialog::qt_metacast(_clname);
}

int HardwareKonfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_okButton_released(); break;
        case 1: on_canButton_released(); break;
        case 2: on_streckenTreeWidget_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
