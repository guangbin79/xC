#include "../../include/sys_xtimer.h"
#include "../include/sys_xtimerdef.h"

void sys_xtmrdestroy(SYS_Timer * ptmr)
{
    delete ptmr;
}
