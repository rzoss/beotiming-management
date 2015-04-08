/****************************************************************************
** Meta object code from reading C++ file 'dbThread.h'
**
** Created: Tue 2. Sep 15:55:20 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dbThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DB_Thread[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DB_Thread[] = {
    "DB_Thread\0\0checkDB()\0"
};

const QMetaObject DB_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DB_Thread,
      qt_meta_data_DB_Thread, 0 }
};

const QMetaObject *DB_Thread::metaObject() const
{
    return &staticMetaObject;
}

void *DB_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DB_Thread))
	return static_cast<void*>(const_cast< DB_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int DB_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: checkDB(); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DB_Thread::checkDB()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
