/*
 * sys_tapigetconnwifiinfo.c
 *
 *  Created on: 2011-11-9
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const xwifi_info_t * sys_tapigetconnwifiinfo(xsys_tapi_t * ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
mylog("wifi--111111111");
	if(ptapi && ptapi->tapiObject){

		jclass cls_Tapi =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jclass cls_wifiInfo = (*g_env)->FindClass(g_env, "xc/api/WIFIInfo");
		mylog("wifi--222222222222");

		jmethodID mid = (*g_env)->GetMethodID(g_env, cls_Tapi, "sys_tapigetconnwifiinfo", "()Lxc/api/WIFIInfo;");
		mylog("wifi--33333333333333");
		jfieldID fid_name = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mName", "Ljava/lang/String;");
		jfieldID fid_mac = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mMac", "Ljava/lang/String;");
		jfieldID fid_ip = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mIp", "Ljava/lang/String;");
		jfieldID fid_signalstrength = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mSignalstrength", "S");
		mylog("wifi--444444444444");

		jobject obj_wifiInfo = (*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid);
		mylog("wifi--5555555555");
		if(!obj_wifiInfo){
			(*g_env)->DeleteLocalRef(g_env, obj_wifiInfo);
			(*g_env)->DeleteLocalRef(g_env, cls_Tapi);
			(*g_env)->DeleteLocalRef(g_env, cls_wifiInfo);
			return 0;
		}
		mylog("wifi--666666666666666666");
		if(!ptapi->wifiInfo){
			ptapi->wifiInfo = (xwifi_info_t * )sys_xmalloc(sizeof(xwifi_info_t));
		}
		mylog("wifi--7777777777777777");
		jstring str_name = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_name));
		jstring str_mac = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_mac));
		jstring str_ip = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_ip));
		mylog("wifi--888888888888888");
		if(str_name){
			ptapi->wifiInfo->name = jstringTochar(g_env, str_name);
		}

		if(str_mac){
			ptapi->wifiInfo->mac = jstringTochar(g_env, str_mac);
		}
		if(str_ip){
			ptapi->wifiInfo->ip = jstringTochar(g_env, str_ip);
		}
		ptapi->wifiInfo->signal_strength = (*g_env)->GetShortField(g_env, obj_wifiInfo, fid_signalstrength);

		if(str_name){
			(*g_env)->DeleteLocalRef(g_env, str_name);
		}
		if(str_mac){
			(*g_env)->DeleteLocalRef(g_env, str_mac);
		}
		if(str_ip){
			(*g_env)->DeleteLocalRef(g_env, str_ip);
		}
		(*g_env)->DeleteLocalRef(g_env, obj_wifiInfo);
		(*g_env)->DeleteLocalRef(g_env, cls_Tapi);
		(*g_env)->DeleteLocalRef(g_env, cls_wifiInfo);
		mylog("wifi--999999999999");
		return ptapi->wifiInfo;
	}
	return 0;
}
