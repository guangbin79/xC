#include "../../../xlongjmp.h"
#include <setjmp.h>
#include <qglobal.h>

xint32_t xlongjmp_set(xjmp_buf_t env) {
#ifdef Q_OS_MAC
    return (xint32_t)setjmp(env->buf);
#else
    return (xint32_t)setjmp((void *)env);
#endif
}

void xlongjmp_jump(xjmp_buf_t env, xint32_t val) {
#ifdef Q_OS_MAC
    longjmp(env->buf, (int)val);
#else
    longjmp((void *)env, (int)val);
#endif
}

