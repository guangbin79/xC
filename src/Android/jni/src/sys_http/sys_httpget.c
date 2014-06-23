/*
 * @file sys_httpget.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

unsigned char sys_httpget(SYS_Http * pHttp, const char * pszUrl){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpget", "(Ljava/lang/String;)Z");

		jstring url = 0;

		if (pszUrl != 0) {
			url = (*g_env)->NewStringUTF(g_env, pszUrl);
		}

		jboolean result = (*g_env)->CallBooleanMethod(g_env, pHttp->httpObject, mid, url);

		(*g_env)->DeleteLocalRef(g_env, url);
		(*g_env)->DeleteLocalRef(g_env, cls);

		if(result){
			return (unsigned char)1;
		}
	}
	return (unsigned char)0;
}
