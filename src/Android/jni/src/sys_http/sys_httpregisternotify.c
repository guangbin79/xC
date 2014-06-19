/*
 * sys_httpregisternotify.c
 *
 *  Created on: 2011-10-28
 *      Author: shizy
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"
void sys_httpregisternotify(SYS_Http * pHttp, SYS_HttpEvent type,SYS_PFNHTTPEVENT pfnNotify, void * pvUser)
{
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pHttp){
		pHttp->pfn[type] = pfnNotify;
		pHttp->pvUser[type] = pvUser;
	}
}
