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

HEADERS += \
    include/sys_xtime.h \
    include/sys_xfile.h \
    include/sys_xdebug.h \
    system/include/sys_xfiledef.h \
    system/thread/ThreadEngine.h \
    system/thread/MyThread.h \
    system/thread/LockEngine.h \
    system/include/sys_threaddef.h \
    include/sys_xtimer.h \
    include/sys_xmemory.h \
    include/sys_ximage.h \
    system/include/sys_xtimerdef.h \
    system/include/sys_ximagedef.h \
    include/sys_thread.h \
    include/sys_http.h \
    system/include/sys_httpdef.h \
    system/include/sys_xtapidef.h \
    include/sys_xtapi.h \
    system/include/sys_xgldef.h \
    ../../xboolean.h \
    ../../xvarargs.h \
    ../../xtimer.h \
    ../../xtime.h \
    ../../xthread.h \
    ../../xtapi.h \
    ../../xrand.h \
    ../../xpointer.h \
    ../../xopengl.h \
    ../../xmemory.h \
    ../../xlongjmp.h \
    ../../xinteger.h \
    ../../ximage.h \
    ../../xhttp.h \
    ../../xgl.h \
    ../../xfont.h \
    ../../xfloat.h \
    ../../xfile.h \
    ../../xdebug.h \
    ../../xcharacter.h \
    ../../Qt/xgl_def.h
    
SOURCES += \
    system/thread/ThreadEngine.cpp \
    system/thread/sys_thread.cpp \
    system/thread/MyThread.cpp \
    system/thread/LockEngine.cpp \
    system/http/sys_http.cpp \
    comm/xthread.cpp \
    comm/xhttp.cpp \
    comm/xlongjmp.c \
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
    comm/xtimer.c \
    comm/xmemory.c \
    comm/ximage.c \
    system/image/sys_image.cpp \
    system/memory/sys_realloc.cpp \
    system/memory/sys_memset.cpp \
    system/memory/sys_memmove.cpp \
    system/memory/sys_memcpy.cpp \
    system/memory/sys_memcmp.cpp \
    system/memory/sys_memchr.cpp \
    system/memory/sys_malloc.cpp \
    system/memory/sys_free.cpp \
    system/memory/sys_calloc.cpp \
    system/timer/sys_tmrstart.cpp \
    system/timer/sys_tmrisbusy.cpp \
    system/timer/sys_tmrdestroy.cpp \
    system/timer/sys_tmrcreate.cpp \
    system/timer/sys_tmrcancel.cpp \
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
    comm/xgl.cpp \
    comm/xfont.cpp \
    comm/xtapi.c \
    system/tapi/sys_tapigetnettype.cpp \
    system/tapi/sys_tapigetmobileid.cpp \
    system/tapi/sys_tapigetimsi.cpp \
    system/tapi/sys_tapigetdeviceinfo.cpp \
    system/tapi/sys_tapigetconnwifiinfo.cpp \
    system/tapi/sys_tapigetbscount.cpp \
    system/tapi/sys_tapigetbsbyindex.cpp \
    system/tapi/sys_tapidestroy.cpp \
    system/tapi/sys_tapicreate.cpp \
    comm/xrand.cpp \
    comm/xopengl.cpp

