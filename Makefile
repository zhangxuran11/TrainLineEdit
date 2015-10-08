#############################################################################
# Makefile for building: TrainLineEdit
# Generated by qmake (2.01a) (Qt 4.8.1) on: ?? 10? 8 18:34:21 2015
# Project:  TrainLineEdit.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile TrainLineEdit.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtSql -I/usr/include/qt4 -IInputMethodPkg -IZDaoPkg -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtSql -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = InputMethodPkg/soft_keyboard_symbol.cpp \
		InputMethodPkg/soft_keyboard_numbers.cpp \
		InputMethodPkg/soft_keyboard_lowercase_letter.cpp \
		InputMethodPkg/soft_keyboard_complete.cpp \
		InputMethodPkg/soft_keyboard_capital_letter.cpp \
		InputMethodPkg/soft_keyboard.cpp \
		InputMethodPkg/klineedit.cpp \
		InputMethodPkg/ktextedit.cpp \
		ZDaoPkg/resultset.cpp \
		ZDaoPkg/dbservice.cpp \
		main.cpp \
		mainwindow.cpp \
		lineswin.cpp \
		detailinfowin.cpp \
		globalinfo.cpp \
		bean.cpp moc_soft_keyboard_symbol.cpp \
		moc_soft_keyboard_numbers.cpp \
		moc_soft_keyboard_lowercase_letter.cpp \
		moc_soft_keyboard_complete.cpp \
		moc_soft_keyboard_capital_letter.cpp \
		moc_soft_keyboard.cpp \
		moc_klineedit.cpp \
		moc_ktextedit.cpp \
		moc_mainwindow.cpp \
		moc_lineswin.cpp \
		moc_detailinfowin.cpp
OBJECTS       = soft_keyboard_symbol.o \
		soft_keyboard_numbers.o \
		soft_keyboard_lowercase_letter.o \
		soft_keyboard_complete.o \
		soft_keyboard_capital_letter.o \
		soft_keyboard.o \
		klineedit.o \
		ktextedit.o \
		resultset.o \
		dbservice.o \
		main.o \
		mainwindow.o \
		lineswin.o \
		detailinfowin.o \
		globalinfo.o \
		bean.o \
		moc_soft_keyboard_symbol.o \
		moc_soft_keyboard_numbers.o \
		moc_soft_keyboard_lowercase_letter.o \
		moc_soft_keyboard_complete.o \
		moc_soft_keyboard_capital_letter.o \
		moc_soft_keyboard.o \
		moc_klineedit.o \
		moc_ktextedit.o \
		moc_mainwindow.o \
		moc_lineswin.o \
		moc_detailinfowin.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		InputMethodPkg/InputMethod.pri \
		ZDaoPkg/ZDaoPkg.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		TrainLineEdit.pro
QMAKE_TARGET  = TrainLineEdit
DESTDIR       = 
TARGET        = TrainLineEdit

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_lineswin.h ui_detailinfowin.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: TrainLineEdit.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		InputMethodPkg/InputMethod.pri \
		ZDaoPkg/ZDaoPkg.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtSql.prl \
		/usr/lib/i386-linux-gnu/libQtXml.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile TrainLineEdit.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
InputMethodPkg/InputMethod.pri:
ZDaoPkg/ZDaoPkg.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtSql.prl:
/usr/lib/i386-linux-gnu/libQtXml.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile TrainLineEdit.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/TrainLineEdit1.0.0 || $(MKDIR) .tmp/TrainLineEdit1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/TrainLineEdit1.0.0/ && $(COPY_FILE) --parents InputMethodPkg/soft_keyboard_symbol.h InputMethodPkg/soft_keyboard_numbers.h InputMethodPkg/soft_keyboard_lowercase_letter.h InputMethodPkg/soft_keyboard_complete.h InputMethodPkg/soft_keyboard_capital_letter.h InputMethodPkg/soft_keyboard.h InputMethodPkg/klineedit.h InputMethodPkg/ktextedit.h ZDaoPkg/resultset.h ZDaoPkg/dbservice.h mainwindow.h lineswin.h detailinfowin.h globalinfo.h bean.h .tmp/TrainLineEdit1.0.0/ && $(COPY_FILE) --parents InputMethodPkg/soft_keyboard_symbol.cpp InputMethodPkg/soft_keyboard_numbers.cpp InputMethodPkg/soft_keyboard_lowercase_letter.cpp InputMethodPkg/soft_keyboard_complete.cpp InputMethodPkg/soft_keyboard_capital_letter.cpp InputMethodPkg/soft_keyboard.cpp InputMethodPkg/klineedit.cpp InputMethodPkg/ktextedit.cpp ZDaoPkg/resultset.cpp ZDaoPkg/dbservice.cpp main.cpp mainwindow.cpp lineswin.cpp detailinfowin.cpp globalinfo.cpp bean.cpp .tmp/TrainLineEdit1.0.0/ && $(COPY_FILE) --parents mainwindow.ui lineswin.ui detailinfowin.ui lineswin.ui .tmp/TrainLineEdit1.0.0/ && (cd `dirname .tmp/TrainLineEdit1.0.0` && $(TAR) TrainLineEdit1.0.0.tar TrainLineEdit1.0.0 && $(COMPRESS) TrainLineEdit1.0.0.tar) && $(MOVE) `dirname .tmp/TrainLineEdit1.0.0`/TrainLineEdit1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/TrainLineEdit1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_soft_keyboard_symbol.cpp moc_soft_keyboard_numbers.cpp moc_soft_keyboard_lowercase_letter.cpp moc_soft_keyboard_complete.cpp moc_soft_keyboard_capital_letter.cpp moc_soft_keyboard.cpp moc_klineedit.cpp moc_ktextedit.cpp moc_mainwindow.cpp moc_lineswin.cpp moc_detailinfowin.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_soft_keyboard_symbol.cpp moc_soft_keyboard_numbers.cpp moc_soft_keyboard_lowercase_letter.cpp moc_soft_keyboard_complete.cpp moc_soft_keyboard_capital_letter.cpp moc_soft_keyboard.cpp moc_klineedit.cpp moc_ktextedit.cpp moc_mainwindow.cpp moc_lineswin.cpp moc_detailinfowin.cpp
moc_soft_keyboard_symbol.cpp: InputMethodPkg/soft_keyboard_symbol.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard_symbol.h -o moc_soft_keyboard_symbol.cpp

moc_soft_keyboard_numbers.cpp: InputMethodPkg/soft_keyboard_numbers.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard_numbers.h -o moc_soft_keyboard_numbers.cpp

moc_soft_keyboard_lowercase_letter.cpp: InputMethodPkg/soft_keyboard_lowercase_letter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard_lowercase_letter.h -o moc_soft_keyboard_lowercase_letter.cpp

moc_soft_keyboard_complete.cpp: InputMethodPkg/soft_keyboard_complete.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard_complete.h -o moc_soft_keyboard_complete.cpp

moc_soft_keyboard_capital_letter.cpp: InputMethodPkg/soft_keyboard_capital_letter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard_capital_letter.h -o moc_soft_keyboard_capital_letter.cpp

moc_soft_keyboard.cpp: InputMethodPkg/soft_keyboard_numbers.h \
		InputMethodPkg/soft_keyboard_complete.h \
		InputMethodPkg/soft_keyboard_capital_letter.h \
		InputMethodPkg/soft_keyboard_lowercase_letter.h \
		InputMethodPkg/soft_keyboard_symbol.h \
		InputMethodPkg/soft_keyboard.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/soft_keyboard.h -o moc_soft_keyboard.cpp

moc_klineedit.cpp: InputMethodPkg/klineedit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/klineedit.h -o moc_klineedit.cpp

moc_ktextedit.cpp: InputMethodPkg/ktextedit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) InputMethodPkg/ktextedit.h -o moc_ktextedit.cpp

moc_mainwindow.cpp: detailinfowin.h \
		lineswin.h \
		globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		ui_lineswin.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_lineswin.cpp: globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		ui_lineswin.h \
		lineswin.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lineswin.h -o moc_lineswin.cpp

moc_detailinfowin.cpp: detailinfowin.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) detailinfowin.h -o moc_detailinfowin.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_lineswin.h ui_detailinfowin.h ui_lineswin.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_lineswin.h ui_detailinfowin.h ui_lineswin.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_lineswin.h: lineswin.ui
	/usr/bin/uic-qt4 lineswin.ui -o ui_lineswin.h

ui_detailinfowin.h: detailinfowin.ui
	/usr/bin/uic-qt4 detailinfowin.ui -o ui_detailinfowin.h

ui_lineswin.h: lineswin.ui
	/usr/bin/uic-qt4 lineswin.ui -o ui_lineswin.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

soft_keyboard_symbol.o: InputMethodPkg/soft_keyboard_symbol.cpp InputMethodPkg/soft_keyboard_symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard_symbol.o InputMethodPkg/soft_keyboard_symbol.cpp

soft_keyboard_numbers.o: InputMethodPkg/soft_keyboard_numbers.cpp InputMethodPkg/soft_keyboard_numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard_numbers.o InputMethodPkg/soft_keyboard_numbers.cpp

soft_keyboard_lowercase_letter.o: InputMethodPkg/soft_keyboard_lowercase_letter.cpp InputMethodPkg/soft_keyboard_lowercase_letter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard_lowercase_letter.o InputMethodPkg/soft_keyboard_lowercase_letter.cpp

soft_keyboard_complete.o: InputMethodPkg/soft_keyboard_complete.cpp InputMethodPkg/soft_keyboard_complete.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard_complete.o InputMethodPkg/soft_keyboard_complete.cpp

soft_keyboard_capital_letter.o: InputMethodPkg/soft_keyboard_capital_letter.cpp InputMethodPkg/soft_keyboard_capital_letter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard_capital_letter.o InputMethodPkg/soft_keyboard_capital_letter.cpp

soft_keyboard.o: InputMethodPkg/soft_keyboard.cpp InputMethodPkg/soft_keyboard.h \
		InputMethodPkg/soft_keyboard_numbers.h \
		InputMethodPkg/soft_keyboard_complete.h \
		InputMethodPkg/soft_keyboard_capital_letter.h \
		InputMethodPkg/soft_keyboard_lowercase_letter.h \
		InputMethodPkg/soft_keyboard_symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soft_keyboard.o InputMethodPkg/soft_keyboard.cpp

klineedit.o: InputMethodPkg/klineedit.cpp InputMethodPkg/klineedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o klineedit.o InputMethodPkg/klineedit.cpp

ktextedit.o: InputMethodPkg/ktextedit.cpp InputMethodPkg/ktextedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ktextedit.o InputMethodPkg/ktextedit.cpp

resultset.o: ZDaoPkg/resultset.cpp ZDaoPkg/resultset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o resultset.o ZDaoPkg/resultset.cpp

dbservice.o: ZDaoPkg/dbservice.cpp ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dbservice.o ZDaoPkg/dbservice.cpp

main.o: main.cpp mainwindow.h \
		detailinfowin.h \
		lineswin.h \
		globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		ui_lineswin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		detailinfowin.h \
		lineswin.h \
		globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		ui_lineswin.h \
		ui_mainwindow.h \
		InputMethodPkg/soft_keyboard.h \
		InputMethodPkg/soft_keyboard_numbers.h \
		InputMethodPkg/soft_keyboard_complete.h \
		InputMethodPkg/soft_keyboard_capital_letter.h \
		InputMethodPkg/soft_keyboard_lowercase_letter.h \
		InputMethodPkg/soft_keyboard_symbol.h \
		ui_detailinfowin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

lineswin.o: lineswin.cpp lineswin.h \
		globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		ui_lineswin.h \
		detailinfowin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lineswin.o lineswin.cpp

detailinfowin.o: detailinfowin.cpp detailinfowin.h \
		ui_detailinfowin.h \
		globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		lineswin.h \
		ui_lineswin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o detailinfowin.o detailinfowin.cpp

globalinfo.o: globalinfo.cpp globalinfo.h \
		ZDaoPkg/dbservice.h \
		ZDaoPkg/resultset.h \
		bean.h \
		lineswin.h \
		ui_lineswin.h \
		detailinfowin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o globalinfo.o globalinfo.cpp

bean.o: bean.cpp bean.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bean.o bean.cpp

moc_soft_keyboard_symbol.o: moc_soft_keyboard_symbol.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard_symbol.o moc_soft_keyboard_symbol.cpp

moc_soft_keyboard_numbers.o: moc_soft_keyboard_numbers.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard_numbers.o moc_soft_keyboard_numbers.cpp

moc_soft_keyboard_lowercase_letter.o: moc_soft_keyboard_lowercase_letter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard_lowercase_letter.o moc_soft_keyboard_lowercase_letter.cpp

moc_soft_keyboard_complete.o: moc_soft_keyboard_complete.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard_complete.o moc_soft_keyboard_complete.cpp

moc_soft_keyboard_capital_letter.o: moc_soft_keyboard_capital_letter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard_capital_letter.o moc_soft_keyboard_capital_letter.cpp

moc_soft_keyboard.o: moc_soft_keyboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_soft_keyboard.o moc_soft_keyboard.cpp

moc_klineedit.o: moc_klineedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_klineedit.o moc_klineedit.cpp

moc_ktextedit.o: moc_ktextedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ktextedit.o moc_ktextedit.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_lineswin.o: moc_lineswin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lineswin.o moc_lineswin.cpp

moc_detailinfowin.o: moc_detailinfowin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_detailinfowin.o moc_detailinfowin.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

