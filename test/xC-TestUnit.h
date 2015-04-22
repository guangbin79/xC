#ifndef _XC_TESTUNIT_H_
#define _XC_TESTUNIT_H_

#include "xC-Test.h"

typedef void (*xfn_xCTestUnit_t)(xfn_test_result_t _result_cb);

#define DECLEAR_XC_TEST_UNIT_BEGIN          void xC_API_Test(xC_API_t _api_type, xfn_test_result_t _result_cb) { \
                                                xfn_xCTestUnit_t _testUnitEntry[xC_API_End - xC_API_Begin + 1] = {0};

#define XC_TEST_UNIT(API)                       void API##_TestUnit(xfn_test_result_t _result_cb); \
                                                _testUnitEntry[API] = API##_TestUnit;

#define DECLEAR_XC_TEST_UNIT_END                if (_testUnitEntry[_api_type] != 0) { \
                                                    _testUnitEntry[_api_type](_result_cb); \
                                                } \
                                                else { \
                                                    _result_cb(0, _api_type, "??? Haven't test unit."); \
                                                } \
                                                return; \
                                            }

#define DEFINE_XC_TEST_UNIT_BEGIN(API)      void API##_TestUnit(xfn_test_result_t _result_cb) { \
                                                char _testCaseStatus = 'o'; // 'i'-->in case，'o'-->out case
#define DEFINE_XC_TEST_UNIT_END                 if (_testCaseStatus != 'o') { \
                                                    _result_cb(__FILE__, __LINE__, "!!! Last a test case is wrong."); \
                                                } \
                                                return; \
                                            }

#endif /* _XC_TESTUNIT_H_ */
