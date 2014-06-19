/*
 * sys_tmrcreate.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include "../../jni_include/sys_xtimer.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/jni_timer.h"
#include "../../jni_include/jni_system.h"

xsys_timer_t * sys_tmrcreate(){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xsys_timer_t * timer = (xsys_timer_t *)sys_xmalloc(sizeof(xsys_timer_t));

	if(!timer){
		return 0;
	}

	jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xtimerr");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");

	jobject obj = (*g_env)->NewObject(g_env, cls, mid);

	timer->timerObject = (*g_env)->NewGlobalRef(g_env, obj);

	mid = (*g_env)->GetMethodID(g_env, cls, "sys_tmrcreate", "(I)V");
	(*g_env)->CallVoidMethod(g_env, timer->timerObject, mid, (jint) timer);

	timer->pfn = 0;
	timer->pvUser = 0;

	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);

	return timer;

}
