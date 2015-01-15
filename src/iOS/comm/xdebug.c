#include "../../../xdebug.h"
#include "../include/sys_debug.h"
#include "../../../xvarargs.h"
#include <stdarg.h>

void xdebug_assert(xbool_t exp)
{
    sys_assert(exp);
}

void xdebug_printf(const xchar_t * format, ...)
{
    va_list ap;
    
    va_start(ap, format);
    sys_dbgprintf((const char *)format, (void *)ap);
    va_end (ap);
}

