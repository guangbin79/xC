/*
 * @file fopen.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

xsys_file_t * xsys_xfile_fOpen(const char * pszFilename, xsys_open_file_mode_t mode){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);


	xsys_file_t * file = (xsys_file_t *)malloc(sizeof(xsys_file_t));

	if(!file){
		return 0;
	}

	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");

	jmethodID mid;
	mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
	jobject obj = (*g_env)->NewObject(g_env, cls, mid);
	file->fileObject = (*g_env)->NewGlobalRef(g_env, obj);

	mid = (*g_env)->GetMethodID(g_env, cls, "sys_fopen","(Ljava/lang/String;I)I");
	jstring fileName = 0;
	if(pszFilename){
		fileName = (*g_env)->NewStringUTF(g_env, pszFilename);
	}

	jint result = (*g_env)->CallIntMethod(g_env, file->fileObject, mid, fileName, mode);

	if(result == 0){
		file = 0;
	}

	(*g_env)->DeleteLocalRef(g_env, cls);
	(*g_env)->DeleteLocalRef(g_env, fileName);
	(*g_env)->DeleteLocalRef(g_env, obj);

	return file;
}
