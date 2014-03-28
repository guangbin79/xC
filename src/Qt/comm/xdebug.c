#include "../../xdebug.h"
#include "../include/sys_xdebug.h"
#include "../../xvarargs.h"

void xdebug_assert(xbool_t exp)
{
    xsys_xdebug_assert(exp);
}

void xdebug_printf(const xchar_t * format, ...)
{
    xva_list_t ap;

    XVA_START(ap, format);
    xsys_xdebug_dbgPrintf((const char *)format, (void *)ap);
    XVA_END(ap);
}

