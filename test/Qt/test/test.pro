#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T18:47:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG(release, debug|release): DEFINES += NDEBUG

SOURCES += main.cpp \
    ../../xC-Test.c \
    ../../test_unit/xBaseOn-TestUnit.c \
    ../../test_unit/xBoolean-TestUnit.c \
    ../../test_unit/xCharacter-TestUnit.c \
    ../../test_unit/xDebug-TestUnit.c \
    ../../test_unit/xFile-TestUnit.c \
    ../../test_unit/xFloat-TestUnit.c \
    ../../test_unit/xGLES-TestUnit.c \
    ../../test_unit/xInteger-TestUnit.c \
    ../../test_unit/xLongJmp-TestUnit.c \
    ../../test_unit/xMemory-TestUnit.c \
    ../../test_unit/xPointer-TestUnit.c \
    ../../test_unit/xRand-TestUnit.c \
    ../../test_unit/xThread-TestUnit.c \
    ../../test_unit/xTime-TestUnit.c \
    ../../test_unit/xTimer-TestUnit.c \
    ../../test_unit/xVarArgs-TestUnit.c

HEADERS += \
    ../../xC-Test.h \
    ../../xC-TestCase.h \
    ../../xC-TestUnit.h
