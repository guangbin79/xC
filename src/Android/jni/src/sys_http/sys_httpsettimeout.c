/*
 * @file sys_httpsettimeout.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

void sys_httpsettimeout(SYS_Http * pHttp, unsigned int dwMSecs1, unsigned int dwMSecs2){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpsettimeout", "(II)V");

		(*g_env)->CallVoidMethod(g_env, pHttp->httpObject, mid, dwMSecs1, dwMSecs2);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}
}
