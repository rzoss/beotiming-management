/****************************************************************************
** Meta object code from reading C++ file 'passwordchangedialog.h'
**
** Created: Tue 2. Sep 15:55:47 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../passwordchangedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passwordchangedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PasswordChangeDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      28,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   21,   21,   21, 0x08,
      72,   21,   21,   21, 0x08,
     101,   96,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PasswordChangeDialog[] = {
    "PasswordChangeDialog\0\0value\0"
    "valueCalculated(int)\0on_okButton_released()\0"
    "on_canButton_released()\0text\0"
    "on_newLineEdit_textChanged(QString)\0"
};

const QMetaObject PasswordChangeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PasswordChangeDialog,
      qt_meta_data_PasswordChangeDialog, 0 }
};

const QMetaObject *PasswordChangeDialog::metaObject() const
{
    return &staticMetaObject;
}

void *PasswordChangeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PasswordChangeDialog))
	return static_cast<void*>(const_cast< PasswordChangeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PasswordChangeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueCalculated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_okButton_released(); break;
        case 2: on_canButton_released(); break;
        case 3: on_newLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PasswordChangeDialog::valueCalculated(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
