#include "../xC-TestUnit.h"
#include "../xC-TestCase.h"

#include "../../xmemory.h"

DEFINE_XC_TEST_UNIT_BEGIN(xMemory)

    XC_TEST_CASE {
        void * p = xmemory_alloc(10);

        TEST_CASE_ASSERT(p != 0)
    }

DEFINE_XC_TEST_UNIT_END
