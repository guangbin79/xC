/*
 * sys_srand.c
 *
 *  Created on: 2011-11-9
 *      Author: shizy
 */
#include "../../jni_include/sys_xrand.h"
#include "../../jni_include/jni_system.h"

void sys_srand(unsigned int seed){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);

	jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xrand");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_srand", "(I)V");
	(*g_env)->CallStaticVoidMethod(g_env, cls, mid, seed);
	(*g_env)->DeleteLocalRef(g_env, cls);
}
