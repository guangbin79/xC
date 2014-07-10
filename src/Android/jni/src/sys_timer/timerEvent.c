/*
 * sys_timerEvent.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include "../../jni_include/jni_timer.h"

void sys_timerEvent(xsys_timer_t * pTimer){

	if(pTimer){
		if(pTimer->pfn){
			(*(pTimer->pfn))(pTimer->pvUser);
		}
	}

}
