#include "../../include/sys_xtimer.h"
#include "../include/sys_xtimerdef.h"

unsigned char sys_xtmrisbusy(SYS_Timer * ptmr)
{
    return ptmr->qtimer.isActive();
}

