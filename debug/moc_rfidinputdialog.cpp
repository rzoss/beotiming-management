/****************************************************************************
** Meta object code from reading C++ file 'rfidinputdialog.h'
**
** Created: Tue 2. Sep 16:21:58 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RFID_Reader/rfidinputdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfidinputdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RFIDInputDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      40,   16,   16,   16, 0x08,
      64,   16,   16,   16, 0x08,
      83,   16,   16,   16, 0x08,
     112,   16,   16,   16, 0x08,
     144,   16,   16,   16, 0x08,
     176,   16,   16,   16, 0x08,
     204,   16,   16,   16, 0x08,
     232,   16,   16,   16, 0x08,
     265,   16,   16,   16, 0x08,
     296,   16,   16,   16, 0x08,
     326,   16,   16,   16, 0x08,
     355,   16,   16,   16, 0x08,
     402,   16,   16,   16, 0x08,
     436,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RFIDInputDialog[] = {
    "RFIDInputDialog\0\0on_okButton_released()\0"
    "on_canButton_released()\0checkSingularity()\0"
    "on_nameLineEdit_textEdited()\0"
    "on_vornameLineEdit_textEdited()\0"
    "on_adresseLineEdit_textEdited()\0"
    "on_plzLineEdit_textEdited()\0"
    "on_ortLineEdit_textEdited()\0"
    "on_telephonLineEdit_textEdited()\0"
    "on_mobileLineEdit_textEdited()\0"
    "on_emailLineEdit_textEdited()\0"
    "on_clubLineEdit_textEdited()\0"
    "on_nationalitaetComboBox_currentIndexChanged()\0"
    "on_jahrgangSpinBox_valueChanged()\0"
    "on_autoCheckBox_stateChanged()\0"
};

const QMetaObject RFIDInputDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RFIDInputDialog,
      qt_meta_data_RFIDInputDialog, 0 }
};

const QMetaObject *RFIDInputDialog::metaObject() const
{
    return &staticMetaObject;
}

void *RFIDInputDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RFIDInputDialog))
	return static_cast<void*>(const_cast< RFIDInputDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RFIDInputDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_okButton_released(); break;
        case 1: on_canButton_released(); break;
        case 2: checkSingularity(); break;
        case 3: on_nameLineEdit_textEdited(); break;
        case 4: on_vornameLineEdit_textEdited(); break;
        case 5: on_adresseLineEdit_textEdited(); break;
        case 6: on_plzLineEdit_textEdited(); break;
        case 7: on_ortLineEdit_textEdited(); break;
        case 8: on_telephonLineEdit_textEdited(); break;
        case 9: on_mobileLineEdit_textEdited(); break;
        case 10: on_emailLineEdit_textEdited(); break;
        case 11: on_clubLineEdit_textEdited(); break;
        case 12: on_nationalitaetComboBox_currentIndexChanged(); break;
        case 13: on_jahrgangSpinBox_valueChanged(); break;
        case 14: on_autoCheckBox_stateChanged(); break;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
