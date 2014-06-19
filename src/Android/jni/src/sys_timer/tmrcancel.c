/*
 * sys_tmrcancel.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include "../../jni_include/sys_xtimer.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/jni_timer.h"
#include "../../jni_include/jni_system.h"

void sys_tmrcancel(xsys_timer_t * ptmr){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptmr){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xtimerr");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tmrcancel", "()V");

		(*g_env)->CallVoidMethod(g_env, ptmr->timerObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);
	}

}
