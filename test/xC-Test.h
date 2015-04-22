#ifndef _XC_TEST_H_
#define _XC_TEST_H_

typedef enum _xC_API {
    xC_API_Begin = 0,
    xBoolean = xC_API_Begin,
    xCharacter,
    xDebug,
    xFile,
    xFloat,
    xGLContext,
    xHttpRequest,
    xInteger,
    xLongJmp,
    xMemory,
    xOpenGL,
    xPointer,
    xRand,
    xThread,
    xTime,
    xTimer,
    xVarArgs,
    xC_API_End = xVarArgs
} xC_API_t;

typedef void (*xfn_test_result_t)(const char * file, int line, const char * description);

#ifdef __cplusplus
extern "C" {
#endif

void xC_API_Test(xC_API_t _api_type, xfn_test_result_t _result_cb);

#ifdef __cplusplus
}
#endif

#endif /* _XC_TEST_H_ */
