#ifndef _TR_SYS_DEBUG_H_
#define _TR_SYS_DEBUG_H_
//#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif

void xsys_xdebug_assert(unsigned char exp);
void xsys_xdebug_dbgPrintf(const char * format, void *  ap);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_DEBUG_H_ */
