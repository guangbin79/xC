/*
 * @file localTime.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xtime.h"
#include "../../../xpointer.h"
#include "../../../xdebug.h"
#include "../../jni_include/sys_xtime.h"

void sys_xlocalTime(xuint32_t t, xdate_time_t * pdt)
{
	t += 3600 * 8;
	sys_xgmTime(t, pdt);
}
