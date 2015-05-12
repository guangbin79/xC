#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T16:21:43
#
#-------------------------------------------------

QT       += opengl

QT       -= gui

TARGET = xC
TEMPLATE = lib
CONFIG += staticlib

CONFIG(release, debug|release): DEFINES += NDEBUG

SOURCES += \
    xdebug/xdebug.cpp \
    xmemory/xmemory.cpp

HEADERS += \
    ../../xbaseon.h \
    ../../xboolean.h \
    ../../xcharacter.h \
    ../../xdebug.h \
    ../../xfile.h \
    ../../xfloat.h \
    ../../xgles.h \
    ../../xinteger.h \
    ../../xlongjmp.h \
    ../../xmemory.h \
    ../../xpointer.h \
    ../../xrand.h \
    ../../xthread.h \
    ../../xtime.h \
    ../../xtimer.h \
    ../../xvarargs.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
