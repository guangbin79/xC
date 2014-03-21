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
	comm/xtime.c \
    comm/xfile.c \
    comm/xdebug.c \
    system/debug/sys_xassert.cpp \
    system/debug/sys_xdbgprintf.cpp \
    system/time/sys_xclock.cpp \
    system/time/sys_xtime.cpp \
    system/file/sys_xfchsize.cpp \
    system/file/sys_xfclose.cpp \
    system/file/sys_xfdiskexist.cpp \
    system/file/sys_xfenumend.cpp \
    system/file/sys_xfenumnext.cpp \
    system/file/sys_xfenumstart.cpp \
    system/file/sys_xfexist.cpp \
    system/file/sys_xfgetfreespace.cpp \
    system/file/sys_xfgetsize.cpp \
    system/file/sys_xfgetspace.cpp \
    system/file/sys_xfmkdir.cpp \
    system/file/sys_xfopen.cpp \
    system/file/sys_xfread.cpp \
    system/file/sys_xfpathchange.cpp \
    system/file/sys_xfremove.cpp \
    system/file/sys_xfrename.cpp \
    system/file/sys_xfrmdir.cpp \
    system/file/sys_xfseek.cpp \
    system/file/sys_xfwrite.cpp \

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
	include/sys_xtime.h \
    include/sys_xfile.h \
    include/sys_xdebug.h \
    system/include/sys_xfiledef.h \
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
