#ifndef _XC_TESTUNIT_H_
#define _XC_TESTUNIT_H_

#include "xC-Test.h"
#include "../xdebug.h"

typedef void (*xfn_xCTestUnit_t)();

#define DECLEAR_XC_TEST_UNIT_BEGIN          void xC_API_Test(xC_API_t api) { \
                                                xfn_xCTestUnit_t _testUnitEntry[xC_API_End - xC_API_Begin + 1] = {0};

#define XC_TEST_UNIT(API)                       void API##_TestUnit(); \
                                                _testUnitEntry[API] = API##_TestUnit;

#define DECLEAR_XC_TEST_UNIT_END                if (_testUnitEntry[api] != 0) { \
                                                    _testUnitEntry[api](); \
                                                } \
                                                else { \
                                                    xdebug_printf("??? %u haven't test unit.", api); \
                                                } \
                                                return; \
                                            }

#define DEFINE_XC_TEST_UNIT_BEGIN(API)      void API##_TestUnit() { \
                                                char _testCaseStatus = 'o'; // 'i'-->in case，'o'-->out case
#define DEFINE_XC_TEST_UNIT_END                 if (_testCaseStatus != 'o') { \
                                                    xdebug_printf("!!! %s: %d, Before a test case is wrong.", __FILE__, __LINE__); \
                                                } \
                                                return; \
                                            }

#endif /* _XC_TESTUNIT_H_ */
