/****************************************************************************
** Meta object code from reading C++ file 'rfidThread.h'
**
** Created: Tue 2. Sep 16:21:52 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RFID_Reader/rfidThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfidThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RFID_Thread[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_RFID_Thread[] = {
    "RFID_Thread\0\0checkRFID()\0"
};

const QMetaObject RFID_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RFID_Thread,
      qt_meta_data_RFID_Thread, 0 }
};

const QMetaObject *RFID_Thread::metaObject() const
{
    return &staticMetaObject;
}

void *RFID_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RFID_Thread))
	return static_cast<void*>(const_cast< RFID_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int RFID_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: checkRFID(); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RFID_Thread::checkRFID()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
