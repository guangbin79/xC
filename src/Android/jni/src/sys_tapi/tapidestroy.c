/*
 * @file tapidestroy.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
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
			free(ptapi->mobileid);
		}

		if(ptapi->imsi){
			free(ptapi->imsi);
		}

		if(ptapi->stationInfo){
			free(ptapi->stationInfo);
		}
		if(ptapi->wifiInfo){
			if(ptapi->wifiInfo->name){
				free(ptapi->wifiInfo->name);
			}
			if(ptapi->wifiInfo->mac){
				free(ptapi->wifiInfo->mac);
			}
			if(ptapi->wifiInfo->ip){
				free(ptapi->wifiInfo->ip);
			}
			free(ptapi->wifiInfo);
		}

		if(ptapi->deviceInfo){
			if(ptapi->deviceInfo->os_version){
				free(ptapi->deviceInfo->os_version);
			}
			if(ptapi->deviceInfo->device_model){
				(ptapi->deviceInfo->device_model);
			}
			if(ptapi->deviceInfo->manufacturer){
				free(ptapi->deviceInfo->manufacturer);
			}
			free(ptapi->deviceInfo);
		}

		free(ptapi);
	}
}
