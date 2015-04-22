#ifndef _XC_TESTCASE_H_
#define _XC_TESTCASE_H_

#include "xC-TestUnit.h"
#include "../xdebug.h"


#define XC_TEST_CASE             { \
                                     if (_testCaseStatus == 'o') { \
                                         _testCaseStatus = 'i'; \
                                     } \
                                     else { \
                                         xdebug_printf("!!! %s: %d, Before a test case is wrong.", __FILE__, __LINE__); \
                                         return; \
                                     } \
                                 } \
                                 while (1)

#define TEST_CASE_ASSERT(B)      { \
                                     _testCaseStatus = 'o'; \
                                     if (!B) { \
                                         xdebug_printf("### %s: %d, The test case is failed.", __FILE__, __LINE__); \
                                         break; \
                                     } \
                                 }


#endif /* _XC_TEST_CASE_H_ */
