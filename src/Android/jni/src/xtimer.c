#include "../../../xtimer.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../jni_include/sys_xtimer.h"



xtimer_t * xtimer_create()
{
    return (xtimer_t *)sys_tmrcreate();
}

void xtimer_destroy(xtimer_t * ptmr)
{
	xdebug_assert(ptmr != XNULL);

    sys_tmrdestroy((xsys_timer_t *)ptmr);
}
void xtimer_start(xtimer_t * ptmr, xuint32_t dwMSecs, xfn_timer_event_t pfn, void * pvUser)
{
	xdebug_assert(ptmr != XNULL && dwMSecs != 0 && pfn != XNULL && !xtimer_isBusy((ptmr)));

    sys_tmrstart((xsys_timer_t *)ptmr, dwMSecs, pfn, pvUser);
}

xbool_t xtimer_isBusy(xtimer_t * ptmr)
{
	xdebug_assert(ptmr != XNULL);

    return sys_tmrisbusy((xsys_timer_t *)ptmr);
}

void xtimer_cancel(xtimer_t * ptmr)
{
	xdebug_assert(ptmr != XNULL);
    if(xtimer_isBusy(ptmr))
    {
    	sys_tmrcancel((xsys_timer_t *)ptmr);
    }

}

