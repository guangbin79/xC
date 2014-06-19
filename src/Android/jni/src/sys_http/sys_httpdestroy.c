/*
 * sys_httpdestroy.c
 *
 *  Created on: 2011-10-28
 *      Author: shizy
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

void sys_httpdestroy(SYS_Http * pHttp){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpdestroy", "()V");

		(*g_env)->CallVoidMethod(g_env, pHttp->httpObject, mid);

		(*g_env)->DeleteGlobalRef(g_env, pHttp->httpObject);
		(*g_env)->DeleteLocalRef(g_env, cls);

		free(pHttp);
	}
}
