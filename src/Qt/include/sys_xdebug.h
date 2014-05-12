#ifndef _SYS_XDEBUG_H_
#define _SYS_XDEBUG_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../xcharacter.h"
#include "../../../xvarargs.h"

void xsys_xdebug_assert(xchar_t exp);
void xsys_xdebug_dbgPrintf(const char * format, va_list ap);

#ifdef __cplusplus
}
#endif

#endif /* SYS_XDEBUG_H_ */
