#include "../../../xlongjmp.h"
#include <setjmp.h>

xint32_t xlongjmp_set(xjmp_buf_t env) {
    return (xint32_t)setjmp(env);
}

void xlongjmp_jump(xjmp_buf_t env, xint32_t val) {
    longjmp(env, (int)val);
}
