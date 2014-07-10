/*
 * @file assert.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xdebug.h"

void xsys_xdebug_assert(unsigned char exp){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env , "xc/api/Xdebug");
	jmethodID mid= (*g_env)->GetStaticMethodID(g_env, cls, "sys_assert", "(Z)V");
	(*g_env)->CallStaticVoidMethod(g_env, cls, mid, exp);
	(*g_env)->DeleteLocalRef(g_env, cls);
}
