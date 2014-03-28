#include "../../include/sys_xtimer.h"
#include "../include/sys_xtimerdef.h"

SYS_Timer * sys_xtmrcreate()
{
    return new SYS_Timer;
}

