#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T12:12:39
#
#-------------------------------------------------

QT       += core gui xml
include(InputMethodPkg/InputMethod.pri)
include(ZDaoPkg/ZDaoPkg.pri)
TARGET = TrainLineEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lineswin.cpp \
    detailinfowin.cpp \
    globalinfo.cpp \
    bean.cpp

HEADERS  += mainwindow.h \
    lineswin.h \
    detailinfowin.h \
    globalinfo.h \
    bean.h

FORMS    += mainwindow.ui \
    lineswin.ui \
    detailinfowin.ui \
    lineswin.ui
