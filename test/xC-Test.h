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

#ifdef __cplusplus
extern "C" {
#endif

void xC_API_Test(xC_API_t api);

#ifdef __cplusplus
}
#endif

#endif /* _XC_TEST_H_ */
