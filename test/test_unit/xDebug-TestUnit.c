#include "../xC-TestUnit.h"
#include "../xC-TestCase.h"

#include "../../xdebug.h"

DEFINE_XC_TEST_UNIT_BEGIN(xDebug)

    XC_TEST_CASE {
        XC_TEST_CASE_FAIL("test")
    }

DEFINE_XC_TEST_UNIT_END
