/*
 * @file fmkdir.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_system.h"

unsigned char xsys_xfile_fMkDir(const char * pszDir){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
	jmethodID  mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fmkdir", "(Ljava/lang/String;)I");

	jstring dir = 0;

	if(pszDir){
		dir = (*g_env)->NewStringUTF(g_env, pszDir);
	}

	jint result = (*g_env)->CallStaticIntMethod(g_env, cls, mid, dir);

	(*g_env)->DeleteLocalRef(g_env,dir);
	(*g_env)->DeleteLocalRef(g_env,cls);

	return (unsigned char)result;
}
