
#include "../../include/sys_timer.h"
#include "../include/sys_timerdef.h"
#include "stdlib.h"

SYS_Timer * sys_tmrcreate()
{
	SYS_Timer *ptimer = (SYS_Timer*)malloc(sizeof(SYS_Timer));
	if( ptimer == NULL)
	{
		return NULL;
	}
	
	ptimer->timerengine = [[TimerEngine  alloc] init];
	
	if(ptimer->timerengine == NULL)
	{
		free(ptimer);
		return NULL;
	}
	
	return ptimer;
}


void sys_tmrstart(SYS_Timer * ptmr, unsigned int dwMSecs, SYS_PFNTIMEREVENT pfn, void * pvUser)
{
	if (sys_tmrisbusy(ptmr))
		return;
	
	if(ptmr != NULL && ptmr->timerengine != NULL)
	{
		[ptmr->timerengine startTimer:dwMSecs withTarget:pfn withUser:pvUser];
	}
}


unsigned char sys_tmrisbusy(SYS_Timer * ptmr)
{
	if(ptmr != NULL && ptmr->timerengine!= NULL)
		return [ptmr->timerengine isBusy];
	else
		return false;
}

void sys_tmrcancel(SYS_Timer * ptmr)
{
	if(ptmr != NULL &&
	   ptmr->timerengine != NULL &&
	   sys_tmrisbusy(ptmr))
	{
		[ptmr->timerengine cancelTimer];
	}
}

void sys_tmrdestroy(SYS_Timer * ptmr)
{
	if(ptmr != NULL && ptmr->timerengine != NULL)
	{
		[ptmr->timerengine destroytime];
		[ptmr->timerengine release];
		free(ptmr);
	}
}

