/*
 * sys_httpcreate.c
 *
 *  Created on: 2011-10-28
 *      Author: shizy
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

SYS_Http * sys_httpcreate(){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	SYS_Http * http = (SYS_Http *)malloc(sizeof(SYS_Http));

	if(!http){
		return 0;
	}

	jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");

	jobject obj = (*g_env)->NewObject(g_env, cls, mid);

	http->httpObject = (*g_env)->NewGlobalRef(g_env, obj);

	mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpcreate", "(III)V");
	(*g_env)->CallVoidMethod(g_env, http->httpObject, mid, (jint) http);

	int i = 0;
	for(i = 0; i < 5; i++)
	{
		http->pfn[i] = 0;
		http->pvUser[i] = 0;
	}


	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);

	return http;

}
