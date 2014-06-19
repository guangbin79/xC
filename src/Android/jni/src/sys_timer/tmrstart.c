/*
 * sys_tmrstart.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include "../../jni_include/sys_xtimer.h"
#include "../../jni_include/jni_timer.h"
#include "../../jni_include/jni_system.h"

void sys_tmrstart(xsys_timer_t * ptmr, unsigned int dwMSecs, xfn_timer_event_t pfn, void * pvUser){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptmr){

		ptmr->pfn = pfn;
		ptmr->pvUser = pvUser;

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xtimerr");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tmrstart", "(I)V");

		(*g_env)->CallVoidMethod(g_env, ptmr->timerObject, mid, dwMSecs);

		(*g_env)->DeleteLocalRef(g_env, cls);
	}

}
