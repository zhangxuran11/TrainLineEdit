INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
QT += sql

OTHER_FILES += \
    TrainLineDaoPkg/TrainLineDB.sql

HEADERS += \
    ZDaoPkg/resultset.h \
    ZDaoPkg/dbservice.h

SOURCES += \
    ZDaoPkg/resultset.cpp \
    ZDaoPkg/dbservice.cpp


