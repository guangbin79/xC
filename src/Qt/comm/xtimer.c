#include "../../xtimer.h"
#include "../include/sys_xtimer.h"
#include "../../xdebug.h"
#include "../../xpointer.h"

xtimer_t * xtimer_create()
{
    return (xtimer_t *)sys_xtmrcreate();
}

void xtimer_destroy(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);

    sys_xtmrdestroy((SYS_Timer *)ptmr);
}

void xtimer_start(xtimer_t * ptmr, xuint32_t dwMSecs, xfn_timer_event_t pfn, void * pvUser)
{
    xdebug_assert(ptmr != XNULL && dwMSecs != 0 && pfn != XNULL && !xtimer_isBusy((ptmr)));

    sys_xtmrstart((SYS_Timer *)ptmr, dwMSecs, pfn, pvUser);
}

xbool_t xtimer_isBusy(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);

    return sys_xtmrisbusy((SYS_Timer *)ptmr);
}
void xtimer_cancel(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);
    if (sys_xtmrisbusy((SYS_Timer*)ptmr))
        sys_xtmrcancel((SYS_Timer *)ptmr);
}

