#include "../../xlongjmp.h"
#include <setjmp.h>

struct _xjmp_buf_t {
    jmp_buf buf;
};

xint32_t xlongjmp_set(xjmp_buf_t env) {
    return (xint32_t)setjmp(env.buf);
}

void xlongjmp_jump(xjmp_buf_t env, xint32_t val) {
    longjmp(env.buf, (int)val);
}
