/****************************************************************************
** Meta object code from reading C++ file 'rechteanpassen.h'
**
** Created: Tue 2. Sep 15:55:53 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rechteanpassen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rechteanpassen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RechteAnpassen[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x08,
      62,   15,   15,   15, 0x08,
      85,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RechteAnpassen[] = {
    "RechteAnpassen\0\0text\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_okButton_released()\0on_canButton_released()\0"
};

const QMetaObject RechteAnpassen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RechteAnpassen,
      qt_meta_data_RechteAnpassen, 0 }
};

const QMetaObject *RechteAnpassen::metaObject() const
{
    return &staticMetaObject;
}

void *RechteAnpassen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RechteAnpassen))
	return static_cast<void*>(const_cast< RechteAnpassen*>(this));
    return QDialog::qt_metacast(_clname);
}

int RechteAnpassen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: on_okButton_released(); break;
        case 2: on_canButton_released(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
