/****************************************************************************
** Meta object code from reading C++ file 'beo_timing.h'
**
** Created: Tue 2. Sep 19:12:36 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../beo_timing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'beo_timing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BEO_Timing[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      53,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     179,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     269,   11,   11,   11, 0x08,
     299,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BEO_Timing[] = {
    "BEO_Timing\0\0Tree_Build()\0Tree_Changed()\0"
    "Table_Edit()\0checkRFID()\0checkDB()\0"
    "NeuesRennen()\0exportToCsv()\0changePwd()\0"
    "neuerUser()\0buildConfiguration()\0"
    "readLogFile()\0rechteAnpassen()\0about()\0"
    "rfidConnection(bool)\0mysqlConnection(bool)\0"
    "purge()\0optimieren()\0CR500_verbinden()\0"
    "tag_initialisieren_pers(bool)\0"
    "tag_clear_pers(bool)\0"
    "tag_initialisieren_unpers(bool)\0"
    "tag_clear_unpers(bool)\0"
};

const QMetaObject BEO_Timing::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BEO_Timing,
      qt_meta_data_BEO_Timing, 0 }
};

const QMetaObject *BEO_Timing::metaObject() const
{
    return &staticMetaObject;
}

void *BEO_Timing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BEO_Timing))
	return static_cast<void*>(const_cast< BEO_Timing*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BEO_Timing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Tree_Build(); break;
        case 1: Tree_Changed(); break;
        case 2: Table_Edit(); break;
        case 3: checkRFID(); break;
        case 4: checkDB(); break;
        case 5: NeuesRennen(); break;
        case 6: exportToCsv(); break;
        case 7: changePwd(); break;
        case 8: neuerUser(); break;
        case 9: buildConfiguration(); break;
        case 10: readLogFile(); break;
        case 11: rechteAnpassen(); break;
        case 12: about(); break;
        case 13: rfidConnection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: mysqlConnection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: purge(); break;
        case 16: optimieren(); break;
        case 17: CR500_verbinden(); break;
        case 18: tag_initialisieren_pers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: tag_clear_pers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: tag_initialisieren_unpers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: tag_clear_unpers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
