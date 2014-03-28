#include "../../include/sys_xtimer.h"
#include "../include/sys_xtimerdef.h"
#include <QTimer>

void sys_xtmrcancel(SYS_Timer * ptmr)
{
    ptmr->qtimer.disconnect(SIGNAL(timeout()));
    ptmr->qtimer.stop();
}
