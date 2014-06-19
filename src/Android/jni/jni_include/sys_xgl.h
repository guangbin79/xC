#ifndef _SYS_XGL_H_
#define _SYS_xgl_H_

#include "jni_xgl.h"


#ifdef __cplusplus
extern "C" {
#endif


unsigned char sys_gl_makeCurrent(xsys_xglsurface * surface);

void sys_gl_swapBuffers();

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIME_H_ */
