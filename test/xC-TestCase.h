#ifndef _XC_TESTCASE_H_
#define _XC_TESTCASE_H_

#include "xC-TestUnit.h"

#define XC_TEST_CASE             { \
                                     if (_testCaseStatus == 'o') { \
                                         _testCaseStatus = 'i'; \
                                     } \
                                     else { \
                                         _result_cb(__FILE__, __LINE__, "!!! Before a test case is wrong."); \
                                         return; \
                                     } \
                                 } \
                                 while (1)

#define XC_TEST_CASE_PASS()      { \
                                     if (_testCaseStatus == 'i') { \
                                         _testCaseStatus = 'o'; \
                                     } \
                                     else { \
                                         _result_cb(__FILE__, __LINE__, "!!! The test case is wrong."); \
                                         return; \
                                     } \
                                 }

#define XC_TEST_CASE_FAIL(T)     { \
                                     if (_testCaseStatus == 'i') { \
                                         _testCaseStatus = 'o'; \
                                         _result_cb(__FILE__, __LINE__, T); \
                                     } \
                                     else { \
                                         _result_cb(__FILE__, __LINE__, "!!! The test case is wrong."); \
                                         return; \
                                     } \
                                 }

#endif /* _XC_TEST_CASE_H_ */
