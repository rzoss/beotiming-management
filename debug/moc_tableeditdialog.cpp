/****************************************************************************
** Meta object code from reading C++ file 'tableeditdialog.h'
**
** Created: Tue 2. Sep 16:22:11 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableeditdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableeditdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TableEditDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      49,   16,   16,   16, 0x08,
      79,   16,   16,   16, 0x08,
     128,  108,   16,   16, 0x08,
     177,  108,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TableEditDialog[] = {
    "TableEditDialog\0\0on_BestaetigenButton_released()\0"
    "on_VerwerfenButton_released()\0"
    "on_loeschenButton_released()\0"
    "topLeft,bottomRight\0"
    "on_kontakte_dataChanged(QModelIndex,QModelIndex)\0"
    "on_resultate_dataChanged(QModelIndex,QModelIndex)\0"
};

const QMetaObject TableEditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TableEditDialog,
      qt_meta_data_TableEditDialog, 0 }
};

const QMetaObject *TableEditDialog::metaObject() const
{
    return &staticMetaObject;
}

void *TableEditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TableEditDialog))
	return static_cast<void*>(const_cast< TableEditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TableEditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_BestaetigenButton_released(); break;
        case 1: on_VerwerfenButton_released(); break;
        case 2: on_loeschenButton_released(); break;
        case 3: on_kontakte_dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: on_resultate_dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
