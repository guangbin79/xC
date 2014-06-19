/*
 * sys_dbgprintf.c
 *
 *  Created on: 2011-10-11
 *      Author: shizy
 */
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xdebug.h"
#include "../../jni_include/sys_xmemory.h"
//#include <stdio.h>

void xsys_xdebug_dbgPrintf(const char * format, void * ap) {
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	int size;
	char * pstr;
	size = vsnprintf(0, 0, format, ap);
	pstr = (char *) sys_xmalloc(size + 1);
	vsnprintf(pstr, size + 1, format, ap);
	jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xdebug");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_dbgprintf", "(Ljava/lang/String;)V");
	jstring str = 0;

	if (pstr) {
		str = (*g_env)->NewStringUTF(g_env, pstr);
	}
	(*g_env)->CallStaticVoidMethod(g_env, cls, mid, str);
	sys_xfree(pstr);

	(*g_env)->DeleteLocalRef(g_env, str);
	(*g_env)->DeleteLocalRef(g_env, cls);
}
