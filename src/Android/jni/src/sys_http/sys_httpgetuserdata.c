/*
 * sys_httpgetuserdata.c
 *
 *  Created on: 2011-11-23
 *      Author: shizy
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
