/****************************************************************************
** Meta object code from reading C++ file 'logondialog.h'
**
** Created: Tue 2. Sep 16:22:05 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogonDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogonDialog[] = {
    "LogonDialog\0\0on_LogonButton_released()\0"
    "on_BeendenButton_released()\0"
};

const QMetaObject LogonDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogonDialog,
      qt_meta_data_LogonDialog, 0 }
};

const QMetaObject *LogonDialog::metaObject() const
{
    return &staticMetaObject;
}

void *LogonDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogonDialog))
	return static_cast<void*>(const_cast< LogonDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LogonDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_LogonButton_released(); break;
        case 1: on_BeendenButton_released(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
