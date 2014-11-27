#include "../../../xtimer.h"
#include "../include/sys_timer.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

xtimer_t * xtimer_create()
{
    return (xtimer_t *)sys_tmrcreate();
}

void xtimer_destroy(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);
    
    sys_tmrdestroy((SYS_Timer *)ptmr);
}

void xtimer_start(xtimer_t * ptmr, xuint32_t dwMSecs, SYS_PFNTIMEREVENT pfn, void * pvUser)
{
    xdebug_assert(ptmr != XNULL && dwMSecs != 0 && pfn != XNULL && !xtimer_isBusy((ptmr)));
    
    sys_tmrstart((SYS_Timer *)ptmr, dwMSecs, pfn, pvUser);
}

xbool_t xtimer_isBusy(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);
    
    return sys_tmrisbusy((SYS_Timer *)ptmr);
}

void xtimer_cancel(xtimer_t * ptmr)
{
    xdebug_assert(ptmr != XNULL);
    if (xtimer_isBusy(ptmr))
        sys_tmrcancel((SYS_Timer *)ptmr);
}

