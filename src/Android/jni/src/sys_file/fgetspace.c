/*
 * @file fgetspace.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */


#include "../../jni_include/jni_system.h"

unsigned int xsys_xfile_fGetSpace(const char * pszDisk){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env , "xc/api/Xfile");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fgetspace", "(Ljava/lang/String;)D");

	jstring dir = 0;
	if(pszDisk){
		dir = (*g_env)->NewStringUTF(g_env, pszDisk);
	}

	jdouble result = (*g_env)->CallStaticDoubleMethod(g_env, cls, mid, dir);

	(*g_env)->DeleteLocalRef(g_env,cls);
	(*g_env)->DeleteLocalRef(g_env,dir);

	return result;
}
