/*
 * @file jni_timer.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */


#ifndef JNI_TIMER_H_
#define JNI_TIMER_H_

#include <jni.h>
#include "sys_xtimer.h"

struct _xsys_timer_t{
	jobject timerObject;
	xfn_timer_event_t pfn;
	void * pvUser;
};

#ifdef __cplusplus
extern "C" {
#endif

void sys_timerEvent(xsys_timer_t * pTimer);

#ifdef __cplusplus
}
#endif

#endif /* JNI_TIMER_H_ */
