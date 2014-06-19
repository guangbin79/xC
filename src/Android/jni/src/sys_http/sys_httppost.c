/*
 * sys_httppost.c
 *
 *  Created on: 2011-10-28
 *      Author: shizy
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

               //__android_log_print(ANDROID_LOG_INFO,"jni--","sys_httppost  0 dwSize ==  %d", dwSize);

		(*g_env)->SetByteArrayRegion(g_env, bytes, 0, dwSize, (jbyte *)pvData);

              // __android_log_print(ANDROID_LOG_INFO,"jni--","sys_httppost  1");

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

               //__android_log_print(ANDROID_LOG_INFO,"jni--","sys_httppost  2");

		if(result){
			return (unsigned char)1;
		}
	}
	return (unsigned char)0;
}
