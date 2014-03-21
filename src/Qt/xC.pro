#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T10:33:46
#
#-------------------------------------------------

QT       -= gui

TARGET = xC
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    comm/xhttp.c

HEADERS += \
    system/http/httpengine.h \
    ../xvarargs.h \
    ../xtimer.h \
    ../xtime.h \
    ../xthread.h \
    ../xtapi.h \
    ../xrand.h \
    ../xpointer.h \
    ../xopengl.h \
    ../xmemory.h \
    ../xlongjmp.h \
    ../xinteger.h \
    ../ximage.h \
    ../xhttp.h \
    ../xgl.h \
    ../xfont.h \
    ../xfloat.h \
    ../xfile.h \
    ../xdebug.h \
    ../xcharacter.h \
    ../xboolean.h \
    include/sys_xhttp.h \
    system/include/sys_xhttpdef.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
