/*
 * @file fgetsize.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned int xsys_xfile_fGetSize(const char * pszFilename){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fgetsize", "(Ljava/lang/String;)I");

	jstring name = 0;

	if(pszFilename){
		name = (*g_env)->NewStringUTF(g_env, pszFilename);
	}

	jint size = (*g_env)->CallStaticIntMethod(g_env, cls, mid, name);

	(*g_env)->DeleteLocalRef(g_env,cls);
	(*g_env)->DeleteLocalRef(g_env,name);

	return size;
}
