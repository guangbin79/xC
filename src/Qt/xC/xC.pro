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

SOURCES += \
    ../xdebug/xdebug.cpp \
    ../xmemory/xmemory.cpp

HEADERS += \
    ../../../xboolean.h \
    ../../../xcharacter.h \
    ../../../xdebug.h \
    ../../../xfile.h \
    ../../../xfloat.h \
    ../../../xglcontext.h \
    ../../../xhttprequest.h \
    ../../../xinteger.h \
    ../../../xlongjmp.h \
    ../../../xmemory.h \
    ../../../xopengl.h \
    ../../../xpointer.h \
    ../../../xrand.h \
    ../../../xthread.h \
    ../../../xtime.h \
    ../../../xtimer.h \
    ../../../xvarargs.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
