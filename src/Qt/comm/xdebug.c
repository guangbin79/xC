#include "../../xdebug.h"
#include "../include/sys_xdebug.h"
#include "../../xvarargs.h"
#include <stdarg.h>

void xdebug_assert(xbool_t exp)
{
    xsys_xdebug_assert(exp);
}

void xdebug_printf(const xchar_t * format, ...)
{
    va_list ap;

    va_start(ap, format);
    xsys_xdebug_dbgPrintf((const char *)format, ap);
    va_end(ap);
}

