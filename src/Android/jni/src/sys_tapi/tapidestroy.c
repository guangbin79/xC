/*
 * sys_tapidestroy.c
 *
 *  Created on: 2011-11-9
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

void sys_tapidestroy(xsys_tapi_t * ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi && ptapi->tapiObject){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_tapidestroy", "()V");

		(*g_env)->CallVoidMethod(g_env, ptapi->tapiObject, mid);
		(*g_env)->DeleteGlobalRef(g_env, ptapi->tapiObject);
		(*g_env)->DeleteLocalRef(g_env, cls);

		if(ptapi->mobileid){
			sys_xfree(ptapi->mobileid);
		}

		if(ptapi->imsi){
			sys_xfree(ptapi->imsi);
		}

		if(ptapi->stationInfo){
			sys_xfree(ptapi->stationInfo);
		}
		if(ptapi->wifiInfo){
			if(ptapi->wifiInfo->name){
				sys_xfree(ptapi->wifiInfo->name);
			}
			if(ptapi->wifiInfo->mac){
				sys_xfree(ptapi->wifiInfo->mac);
			}
			if(ptapi->wifiInfo->ip){
				sys_xfree(ptapi->wifiInfo->ip);
			}
			sys_xfree(ptapi->wifiInfo);
		}

		if(ptapi->deviceInfo){
			if(ptapi->deviceInfo->os_version){
				sys_xfree(ptapi->deviceInfo->os_version);
			}
			if(ptapi->deviceInfo->device_model){
				(ptapi->deviceInfo->device_model);
			}
			if(ptapi->deviceInfo->manufacturer){
				sys_xfree(ptapi->deviceInfo->manufacturer);
			}
			sys_xfree(ptapi->deviceInfo);
		}

		sys_xfree(ptapi);
	}
}
