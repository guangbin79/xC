/*
 * Java_cn_com_tiros_api_Timerr_sys_1timerEvent.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include "xc_api_Timerr.h"
#include "../../jni_include/jni_timer.h"
/*
 * Class:     cn_com_tiros_api_Timerr
 * Method:    sys_timerEvent
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_Timerr_sys_1timerEvent
  (JNIEnv * env, jclass cls, jint pTimer){
	sys_timerEvent((xsys_timer_t *)pTimer);
}
