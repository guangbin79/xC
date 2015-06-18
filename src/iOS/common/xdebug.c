#include "../../../xdebug.h"
#include "../include/sys_debug.h"
#include "../../../xvarargs.h"

void xdebug_assert(xbool_t exp)
{
    sys_assert(exp);
}

void xdebug_printf(const xchar_t * format, ...)
{
    xva_list_t ap;

    XVA_START(ap, format);
    sys_dbgprintf(format, (void *)ap);
    XVA_END (ap);
}

