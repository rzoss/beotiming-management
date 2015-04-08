TEMPLATE = app
TARGET = BEO_Timing
QT += core \
    gui \
    sql \
    widgets
HEADERS += Database.h \
    RFID_Reader/MasterRD.h \
    RFID_Reader/RFID_CR500.h \
    RFID_Reader/rfidThread.h \
    RFID_Reader/rfidinputdialog.h \
    User.h \
    dbThread.h \
    delegates/KontaktDelegate.h \
    delegates/ResultateDelegate.h \
    hardwarekonfiguration.h \
    logfilelesendialog.h \
    logondialog.h \
    md5/md5.h \
    md5/md5_loc.h \
    neueruserdialog.h \
    neuesrennendialog.h \
    passwordchangedialog.h \
    rechteanpassen.h \
    tableeditdialog.h \
    beo_timing.h
SOURCES += Database.cpp \
    RFID_Reader/RFID_CR500.cpp \
    RFID_Reader/rfidThread.cpp \
    RFID_Reader/rfidinputdialog.cpp \
    User.cpp \
    dbThread.cpp \
    delegates/KontaktDelegate.cpp \
    delegates/ResultateDelegate.cpp \
    hardwarekonfiguration.cpp \
    logfilelesendialog.cpp \
    logondialog.cpp \
    md5/md5.cpp \
    neueruserdialog.cpp \
    neuesrennendialog.cpp \
    passwordchangedialog.cpp \
    rechteanpassen.cpp \
    tableeditdialog.cpp \
    main.cpp \
    beo_timing.cpp
FORMS += RFID_Reader/rfidinputdialog.ui \
    hardwarekonfiguration.ui \
    logfilelesendialog.ui \
    logondialog.ui \
    neueruserdialog.ui \
    neuesrennendialog.ui \
    passwordchangedialog.ui \
    rechteanpassen.ui \
    tableeditdialog.ui \
    beo_timing.ui
RESOURCES += beo_timing.qrc
INCLUDEPATH += c:\MinGW\include \
    app \
    md5 \
    RFID_Reader
RC_FILE += myapp.rc
