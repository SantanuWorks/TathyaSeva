QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createuser.cpp \
    main.cpp \
    loginwnd.cpp \
    repl.cpp

HEADERS += \
    Automata.h \
    Error.h \
    FileHandler.h \
    LanguageUtil.h \
    QueryExecuter.h \
    QueryUtil.h \
    createuser.h \
    loginwnd.h \
    repl.h

FORMS += \
    createuser.ui \
    loginwnd.ui \
    repl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BargraphInfo.json \
    DS.json \
    DatastoreInfo.json \
    Language.json \
    LinegraphInfo.json \
    PiechartInfo.json \
    ProjectDoc.txt \
    ProjectTimeline.txt \
    QueryFormat.json \
    TableInfo.json
