/*
 * sys_tapigetdeviceinfo.c
 *
 *  Created on: 2012-3-5
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const xdevice_info_t* sys_tapigetdeviceinfo(xsys_tapi_t* ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);

	if(ptapi && ptapi->tapiObject){

		if(!ptapi->deviceInfo){

			jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtapi");

			jmethodID mid_osversion = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetosversion", "()Ljava/lang/String;");
			jmethodID mid_devicemodel = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetdevicemodel", "()Ljava/lang/String;");
			jmethodID mid_manufacturername = (*g_env)->GetMethodID(g_env, cls, "sys_tapigetmanufacturername", "()Ljava/lang/String;");

			jstring str_osversion = (jstring)((*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid_osversion));
			jstring str_devicemodel = (jstring)((*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid_devicemodel));
			jstring str_manufacturername = (jstring)((*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid_manufacturername));

			ptapi->deviceInfo = (xdevice_info_t * )sys_xmalloc(sizeof(xdevice_info_t));
			sys_xmemset(ptapi->deviceInfo, 0, sizeof(xdevice_info_t));

			if(str_osversion){
				ptapi->deviceInfo->os_version = jstringTochar(g_env, str_osversion);
			}

			if(str_devicemodel){
				ptapi->deviceInfo->device_model = jstringTochar(g_env, str_devicemodel);
			}

			if(str_manufacturername){
				ptapi->deviceInfo->manufacturer = jstringTochar(g_env, str_manufacturername);
			}

			(*g_env)->DeleteLocalRef(g_env, str_osversion);
			(*g_env)->DeleteLocalRef(g_env, str_devicemodel);
			(*g_env)->DeleteLocalRef(g_env, str_manufacturername);

			(*g_env)->DeleteLocalRef(g_env, cls);

		}

		return ptapi->deviceInfo;
	}
	return 0;
}
