/*
 * sys_httpremoveheader.c
 *
 *  Created on: 2011-10-28
 *      Author: shizy
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

void sys_httpremoveheader(SYS_Http * pHttp, const char * pszHeader){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpremoveheader", "(Ljava/lang/String;)V");

		jstring header = 0;

		if(pszHeader){
			header = (*g_env)->NewStringUTF(g_env, pszHeader);
		}

		(*g_env)->CallVoidMethod(g_env, pHttp->httpObject, mid, header);

		(*g_env)->DeleteLocalRef(g_env, header);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}

}
