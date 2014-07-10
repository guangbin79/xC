/*
 * @file tapigetconnwifiinfo.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const xwifi_info_t * sys_tapigetconnwifiinfo(xsys_tapi_t * ptapi){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(ptapi && ptapi->tapiObject){

		jclass cls_Tapi =(*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jclass cls_wifiInfo = (*g_env)->FindClass(g_env, "xc/api/WIFIInfo");

		jmethodID mid = (*g_env)->GetMethodID(g_env, cls_Tapi, "sys_tapigetconnwifiinfo", "()Lxc/api/WIFIInfo;");
		jfieldID fid_name = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mName", "Ljava/lang/String;");
		jfieldID fid_mac = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mMac", "Ljava/lang/String;");
		jfieldID fid_ip = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mIp", "Ljava/lang/String;");
		jfieldID fid_signalstrength = (*g_env)->GetFieldID(g_env, cls_wifiInfo, "mSignalstrength", "S");

		jobject obj_wifiInfo = (*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid);
		if(!obj_wifiInfo){
			(*g_env)->DeleteLocalRef(g_env, obj_wifiInfo);
			(*g_env)->DeleteLocalRef(g_env, cls_Tapi);
			(*g_env)->DeleteLocalRef(g_env, cls_wifiInfo);
			return 0;
		}
		if(!ptapi->wifiInfo){
			ptapi->wifiInfo = (xwifi_info_t * )malloc(sizeof(xwifi_info_t));
		}
		jstring str_name = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_name));
		jstring str_mac = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_mac));
		jstring str_ip = (jstring)((*g_env)->GetObjectField(g_env, obj_wifiInfo, fid_ip));
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
		return ptapi->wifiInfo;
	}
	return 0;
}
