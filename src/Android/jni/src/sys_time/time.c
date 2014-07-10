/*
 * @file time.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_system.h"
#include "../../../xtime.h"
#include <time.h>

void  sys_time(xdate_time_t * pdt){


	if(pdt){
		time_t t;
		struct tm * p;

		t = time(NULL);
		p = gmtime(&t);

		pdt->year = p->tm_year + 1900;
		pdt->month = p->tm_mon + 1;
		pdt->day = p->tm_mday;
		pdt->hour = p->tm_hour;
		pdt->minute = p->tm_min;
		pdt->second = p->tm_sec;
	}


}
