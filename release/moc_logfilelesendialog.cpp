/****************************************************************************
** Meta object code from reading C++ file 'logfilelesendialog.h'
**
** Created: Tue 2. Sep 15:50:43 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logfilelesendialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logfilelesendialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogfileLesenDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      43,   19,   19,   19, 0x08,
      73,   67,   19,   19, 0x08,
     106,   67,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogfileLesenDialog[] = {
    "LogfileLesenDialog\0\0on_okButton_released()\0"
    "on_canButton_released()\0state\0"
    "on_neuCheckBox_stateChanged(int)\0"
    "on_delCheckBox_stateChanged(int)\0"
};

const QMetaObject LogfileLesenDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogfileLesenDialog,
      qt_meta_data_LogfileLesenDialog, 0 }
};

const QMetaObject *LogfileLesenDialog::metaObject() const
{
    return &staticMetaObject;
}

void *LogfileLesenDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogfileLesenDialog))
	return static_cast<void*>(const_cast< LogfileLesenDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LogfileLesenDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_okButton_released(); break;
        case 1: on_canButton_released(); break;
        case 2: on_neuCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_delCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
