/*
 * @file sys_httpregisternotify.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
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
