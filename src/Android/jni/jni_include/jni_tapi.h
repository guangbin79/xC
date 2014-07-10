/*
 * @file jni_tapi.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#ifndef JNI_TAPI_H_
#define JNI_TAPI_H_

#include <jni.h>
#include "../../../../xtapi.h"

typedef struct _xsys_tapi_t{
	jobject tapiObject;
	char * mobileid;
	char * imsi;
	xbase_station_info_t * stationInfo;
	xwifi_info_t * wifiInfo;
	xdevice_info_t * deviceInfo;
}xsys_tapi_t;


#endif /* JNI_TAPI_H_ */
