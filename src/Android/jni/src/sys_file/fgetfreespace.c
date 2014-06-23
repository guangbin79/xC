/*
 * @file fgetfreespace.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_system.h"


unsigned int xsys_xfile_fGetFreeSpace(const char * pszDisk){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fgetfreespace", "(Ljava/lang/String;)D");

	jstring disk = 0;

	if(pszDisk){
		disk = (*g_env)->NewStringUTF(g_env, pszDisk);
	}

	jdouble result = (*g_env)->CallStaticDoubleMethod(g_env, cls, mid, disk);

	(*g_env)->DeleteLocalRef(g_env,cls);
	(*g_env)->DeleteLocalRef(g_env,disk);

	return result;
}
