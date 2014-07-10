/*
 * @file sys_httppost.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

unsigned char sys_httppost(SYS_Http * pHttp, const char * pContentType, const char * pszUrl, const void * pvData, unsigned int dwSize){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp && pHttp->httpObject){

		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Xhttp");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_httppost", "(Ljava/lang/String;Ljava/lang/String;[B)Z");

		jbyteArray bytes = (*g_env)->NewByteArray(g_env, dwSize);
		(*g_env)->SetByteArrayRegion(g_env, bytes, 0, dwSize, (jbyte *)pvData);

		jstring type = 0;

		if(pContentType) {
			type = (*g_env)->NewStringUTF(g_env, pContentType);
		}

		jstring url = 0;

		if(pszUrl){
			url = (*g_env)->NewStringUTF(g_env, pszUrl);
		}

		jboolean result = (*g_env)->CallBooleanMethod(g_env, pHttp->httpObject, mid, type, url, bytes);

		(*g_env)->DeleteLocalRef(g_env, type);
		(*g_env)->DeleteLocalRef(g_env, url);
		(*g_env)->DeleteLocalRef(g_env, bytes);
		(*g_env)->DeleteLocalRef(g_env, cls);

		bytes = 0;
		if(result){
			return (unsigned char)1;
		}
	}
	return (unsigned char)0;
}
