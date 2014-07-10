/*
 * @file sys_httpaddheader.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

unsigned char sys_httpaddheader(SYS_Http * pHttp, const char * pszHeader, const char * pszValue){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httpaddheader", "(Ljava/lang/String;Ljava/lang/String;)Z");

		jstring header = 0;
		jstring value = 0;

		if(pszHeader){
			header = (*g_env)->NewStringUTF(g_env, pszHeader);
		}

		if(pszValue){
			value = (*g_env)->NewStringUTF(g_env, pszValue);
		}

		jboolean result = (*g_env)->CallBooleanMethod(g_env, pHttp->httpObject, mid, header, value);

		(*g_env)->DeleteLocalRef(g_env, header);
		(*g_env)->DeleteLocalRef(g_env, value);
		(*g_env)->DeleteLocalRef(g_env, cls);

		if(result){
			return (unsigned char)1;
		}
	}
	return (unsigned char)0;
}
