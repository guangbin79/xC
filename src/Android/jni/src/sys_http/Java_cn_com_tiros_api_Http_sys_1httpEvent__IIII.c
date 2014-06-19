/*
 * Java_cn_com_tiros_api_Http_sys_1httpEvent__III_3B.c
 *
 *  Created on: 2012-07-24
 *      Author: caoyp
 */
#include "cn_com_tiros_api_Http.h"
#include "../../jni_include/jni_http.h"
/*
 * Class:     cn_com_tiros_api_Http
 * Method:    sys_httpEvent
 * Signature: (IIII)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_Http_sys_1httpEvent__IIII
  (JNIEnv *env, jclass cls, jint http, jint event, jint  param1, jint  param2){
	sys_httpEvent((void *)http, event, param1, param2);
}
