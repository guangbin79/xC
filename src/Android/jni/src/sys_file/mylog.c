/*
 * mylog.c
 *
 *  Created on: 2014-5-21
 *      Author: wangxt
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"

//此为自己写的测试用log
 void mylog(const char * chLog, int code){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls = (*g_env)->FindClass(g_env, "xc/api/testclass");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "printlnLog", "(Ljava/lang/String;I)V");

	jstring strLog = 0;
	if(chLog){
		strLog = (*g_env)->NewStringUTF(g_env, chLog);
	}

	jint result = (*g_env)->CallStaticIntMethod(g_env, cls, mid, strLog, code);

	(*g_env)->DeleteLocalRef(g_env,cls);
	(*g_env)->DeleteLocalRef(g_env,strLog);

}
