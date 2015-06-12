#include "xC-Test.h"
#include "xC-TestUnit.h"

DECLEAR_XC_TEST_UNIT_BEGIN

    XC_TEST_UNIT(xInteger)
    XC_TEST_UNIT(xFloat)
    XC_TEST_UNIT(xBoolean)
    XC_TEST_UNIT(xCharacter)
    XC_TEST_UNIT(xPointer)
    XC_TEST_UNIT(xVarArgs)

    XC_TEST_UNIT(xDebug)
    XC_TEST_UNIT(xMemory)
    XC_TEST_UNIT(xRand)
    XC_TEST_UNIT(xThread)
    XC_TEST_UNIT(xTime)
    XC_TEST_UNIT(xTimer)
    XC_TEST_UNIT(xLongJmp)
    XC_TEST_UNIT(xFile)

    XC_TEST_UNIT(xHttpRequest)
    XC_TEST_UNIT(xGLContext)
    XC_TEST_UNIT(xOpenGL)

DECLEAR_XC_TEST_UNIT_END
