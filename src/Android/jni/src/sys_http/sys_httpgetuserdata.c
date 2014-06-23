/*
 * @file sys_httpgetuserdata.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

void * sys_httpgetuserdata(SYS_Http* pHttp){
	if(pHttp){
		return pHttp->pvUser;
	}
	return 0;
}
