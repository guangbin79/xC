#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T10:33:46
#
#-------------------------------------------------

QT       += network
QT       += opengl

TARGET = xC
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    system/thread/ThreadEngine.cpp \
    system/thread/sys_thread.cpp \
    system/thread/MyThread.cpp \
    system/thread/LockEngine.cpp \
    system/http/sys_http.cpp \
    comm/xthread.cpp \
    comm/xhttp.cpp \
    comm/xlongjmp.cpp

HEADERS += \
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
    system/thread/ThreadEngine.h \
    system/thread/MyThread.h \
    system/thread/LockEngine.h \
    system/include/sys_threaddef.h \
    include/sys_thread.h \
    include/sys_http.h \
    system/include/sys_httpdef.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
