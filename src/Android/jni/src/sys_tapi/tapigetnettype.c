/*
 * sys_tapigetnettype.c
 *
 *  Created on: 2012-3-5
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

int sys_tapigetnettype(xsys_tapi_t* ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetnettype","()I");

		jint result = (*g_env)->CallIntMethod(g_env, ptapi->tapiObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);

		return result;
	}

	return 0;
}
