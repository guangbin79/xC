/*
 * @file tapigetimsi.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const char* sys_tapigetimsi(xsys_tapi_t* ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi){

		if(ptapi->imsi){
			return ptapi->imsi;
		}

		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetimsi","()Ljava/lang/String;");

		jstring str = (jstring)((*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid));

		char * imsi = jstringTochar(g_env, str);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, str);

		ptapi->mobileid = imsi;
		return imsi;
	}
	return 0;
}
