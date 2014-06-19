/*
 * sys_tpicreate.c
 *
 *  Created on: 2011-11-9
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

xsys_tapi_t * sys_tapicreate(){
	JNIEnv * g_env;
	if(jvm == 0)
	{
		mylog("jvm = NULL");
	}
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xsys_tapi_t * tapi = (xsys_tapi_t *)sys_xmalloc(sizeof(xsys_tapi_t));

	sys_xmemset(tapi, 0, sizeof(xsys_tapi_t));

	if(!tapi){
		return 0;
	}

	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");

	jobject obj = (*g_env)->NewObject(g_env, cls, mid);
	tapi->tapiObject = (*g_env)->NewGlobalRef(g_env, obj);;

	mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapicreate", "()V");

	(*g_env)->CallVoidMethod(g_env, tapi->tapiObject, mid);
	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);

	return tapi;
}
