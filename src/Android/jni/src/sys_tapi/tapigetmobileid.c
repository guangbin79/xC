/*
 * @file tapigetmobileid.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const char * sys_tapigetmobileid(xsys_tapi_t * ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi){

		if(ptapi->mobileid){
			return ptapi->mobileid;
		}

		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetmobileid","()Ljava/lang/String;");

		jstring str = (jstring)((*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid));

		char * mobileid = jstringTochar(g_env, str);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, str);

		ptapi->mobileid = mobileid;
		return mobileid;
	}
}
