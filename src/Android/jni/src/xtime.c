#include "../../../xtime.h"
#include "../../../xpointer.h"
#include "../../../xdebug.h"
#include "../jni_include/sys_xtime.h"


xuint32_t xtime_clock()
{
	return (xuint32_t)sys_xclock();
}


xuint32_t xtime_mkTime(const xdate_time_t * pdt)
{
	return  sys_xmkTime(pdt);
}



void xtime_gmTime(xuint32_t t, xdate_time_t * pdt)
{
	sys_xgmTime(t, pdt);
}


void xtime_localTime(xuint32_t t, xdate_time_t * pdt)
{
	sys_xlocalTime(t, pdt);
}


