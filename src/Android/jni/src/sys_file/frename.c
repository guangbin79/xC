/*
 * @file frename.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_system.h"

unsigned char xsys_xfile_fRename(const char * pszFilename1, const char * pszFilename2){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_frename", "(Ljava/lang/String;Ljava/lang/String;)I");

	jstring name1 = 0;
	jstring name2 = 0;

	if(pszFilename1){
		name1 =  (*g_env)->NewStringUTF(g_env, pszFilename1);
	}

	if(pszFilename2){
		name2 =  (*g_env)->NewStringUTF(g_env, pszFilename2);
	}

	jint result = (*g_env)->CallStaticIntMethod(g_env, cls, mid, name1, name2);

	(*g_env)->DeleteLocalRef(g_env,cls);
	(*g_env)->DeleteLocalRef(g_env,name1);
	(*g_env)->DeleteLocalRef(g_env,name2);

	return (unsigned char)result;
}
