#include "../../include/sys_xtimer.h"
#include "../include/sys_xtimerdef.h"
#include <QTimer>

void sys_xtmrstart(SYS_Timer * ptmr, unsigned int dwMSecs, SYS_PFNTIMEREVENT pfn, void * pvUser)
{
    ptmr->qtimer.pfn = pfn;
    ptmr->qtimer.pvUser = pvUser;
    ptmr->qtimer.setInterval(dwMSecs);
    ptmr->qtimer.setSingleShot(true);
    ptmr->qtimer.connect(&ptmr->qtimer, SIGNAL(timeout()), &ptmr->qtimer, SLOT(TimeOut()));
    ptmr->qtimer.start();
}

void QSYSTimer::TimeOut()
{
    disconnect(SIGNAL(timeout()));
    pfn(pvUser);
}
