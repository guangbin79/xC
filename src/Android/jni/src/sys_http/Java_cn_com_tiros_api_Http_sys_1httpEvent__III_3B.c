/*
 * @file Java_cn_com_tiros_api_Http_sys_1httpEvent__III_3B.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */


#include "cn_com_tiros_api_Http.h"
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

/*
 * Class:     cn_com_tiros_api_Http
 * Method:    sys_httpEvent
 * Signature: (III[B)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_Http_sys_1httpEvent__III_3B
  (JNIEnv * env, jclass cls, jint http, jint event, jint param1, jbyteArray param2){

	if(event == SYS_EVT_HTTP_BODY) {
             	char * data = (char *)malloc(param1 + 1);

		(*env)->GetByteArrayRegion(env, param2, 0, param1, data);

		data[param1] = '\0';
		sys_httpEvent((void *)http, event, param1, (unsigned int)data);


		free(data);
	} else {
              sys_httpEvent((void *)http, event, param1, 0);
	}


}

/*
 * Class:     cn_com_tiros_api_Http
 * Method:    sys_httpEvent
 * Signature: (IIILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_Http_sys_1httpEvent__IIILjava_lang_String_2
  (JNIEnv * env, jclass cls, jint http, jint event, jint param1, jstring param2){

  	if(event == SYS_EVT_HTTP_RESPONSE) {
             
              char * chars = jstringTochar(env, param2);

              sys_httpEvent((void *)http, event, param1, (unsigned int)chars);

              if(chars){
			free(chars);
	      }
        }

}
