/*
 * sys_tapigetbsbyindex.c
 *
 *  Created on: 2011-11-9
 *      Author: shizy
 */
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/jni_tapi.h"
#include "../../jni_include/jni_system.h"

const xbase_station_info_t * sys_tapigetbsbyindex(xsys_tapi_t * ptapi, const unsigned char aIndex){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);

	if(ptapi && ptapi->tapiObject){

		jclass cls_Tapi = (*g_env)->FindClass(g_env, "xc/api/Xtapi");
		jclass cls_StationInfo = (*g_env)->FindClass(g_env, "xc/api/BaseStationInfo");

		jmethodID mid = (*g_env)->GetMethodID(g_env, cls_Tapi, "sys_tapigetbsbyindex", "(I)xc/api/BaseStationInfo;");

		jfieldID fid_lac = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mLac", "I");
		jfieldID fid_cellid = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mCellId", "I");
		jfieldID fid_mcc = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mMcc", "I");
		jfieldID fid_mnc = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mMnc", "I");
		jfieldID fid_signalstrength = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mSignalstrength", "S");
		jfieldID fid_type = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mType", "I");
		jfieldID fid_lat = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mLat", "D");
		jfieldID fid_lon = (*g_env)->GetFieldID(g_env, cls_StationInfo, "mLon", "D");

		jobject obj_stationInfo = (*g_env)->CallObjectMethod(g_env, ptapi->tapiObject, mid, aIndex);

		if(obj_stationInfo){
			if(!ptapi->stationInfo)
			{
				ptapi->stationInfo = (xbase_station_info_t * )sys_xmalloc(sizeof(xbase_station_info_t));
			}

			ptapi->stationInfo->lac = (*g_env)->GetIntField(g_env, obj_stationInfo, fid_lac);
			ptapi->stationInfo->cell_id = (*g_env)->GetIntField(g_env, obj_stationInfo, fid_cellid);
			ptapi->stationInfo->mcc = (*g_env)->GetIntField(g_env, obj_stationInfo, fid_mcc);
			ptapi->stationInfo->mnc = (*g_env)->GetIntField(g_env, obj_stationInfo, fid_mnc);
			ptapi->stationInfo->signal_strength = (*g_env)->GetShortField(g_env, obj_stationInfo, fid_signalstrength);
			ptapi->stationInfo->type = (*g_env)->GetIntField(g_env, obj_stationInfo, fid_type);
			ptapi->stationInfo->lat = (*g_env)->GetDoubleField(g_env, obj_stationInfo, fid_lat);
			ptapi->stationInfo->lon = (*g_env)->GetDoubleField(g_env, obj_stationInfo, fid_lon);
		}
		else{
			ptapi->stationInfo = 0;
		}

		(*g_env)->DeleteLocalRef(g_env, cls_Tapi);
		(*g_env)->DeleteLocalRef(g_env, cls_StationInfo);
		(*g_env)->DeleteLocalRef(g_env, obj_stationInfo);

		return ptapi->stationInfo;
	}
	return 0;
}
