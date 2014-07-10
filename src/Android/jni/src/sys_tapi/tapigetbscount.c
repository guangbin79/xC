/*
 * @file tapigetbscount.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

unsigned char sys_tapigetbscount(xsys_tapi_t * ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi){

		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetbscount","()I");

		jint result = (*g_env)->CallIntMethod(g_env, ptapi->tapiObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);

		return (unsigned short)result;
	}
	return (unsigned short)0;
}
