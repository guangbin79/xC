/*
 * @file sys_httpisRunning.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

unsigned char sys_httpisRunning(SYS_Http * pHttp){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpisRunning", "()I");

		jboolean result = (*g_env)->CallIntMethod(g_env, pHttp->httpObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);

		if(result){
			return (unsigned char)1;
		}
	}
	return (unsigned char)0;
}
