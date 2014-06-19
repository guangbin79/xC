/*
 * jni_http.h
 *
 *  Created on: 2011-10-28
 *      Author: shizy
 */

#ifndef JNI_HTTP_H_
#define JNI_HTTP_H_

#include <jni.h>
#include "sys_xhttp.h"

struct _SYS_Http{
	jobject httpObject;
	SYS_PFNHTTPEVENT pfn[5];
	void * pvUser[5];
};


#ifdef __cplusplus
extern "C" {
#endif

void sys_httpEvent(void * pvUser, unsigned int dwEvent, unsigned int dwParam1, unsigned int dwParam2);

#ifdef __cplusplus
}
#endif

#endif /* JNI_HTTP_H_ */
