#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T12:12:39
#
#-------------------------------------------------

QT       += core gui xml
include(InputMethodPkg/InputMethod.pri)
include(ZDaoPkg/ZDaoPkg.pri)

DEFINES += $$(ARCH)
contains( DEFINES, arm ) {
    DEFINES += ARM
}
!contains( DEFINES, arm ) {
    DEFINES += X86
}


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


OTHER_FILES += \
    qss/mainframe.qss


contains( DEFINES, ARM ) {
    mytarget.commands = scp ./${TARGET} root@192.168.1.11:/
}
contains( DEFINES, X86 ) {
    mytarget.commands = cp ./${TARGET} ../SystemController/
}
mytarget.target = all

mytarget.depends =



QMAKE_EXTRA_TARGETS += mytarget

