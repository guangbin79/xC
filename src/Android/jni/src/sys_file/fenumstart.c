/*
 * @file fenumstart.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

xsys_file_enum_t * xsys_xfile_fEnumStart(const char * pszDir, unsigned char bDirs){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xsys_file_enum_t * fileEnum = (xsys_file_enum_t *)malloc(sizeof(xsys_file_enum_t));
	if(!fileEnum){
		return 0;
	}
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/XenumFile");
	jmethodID mid;
	mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
	jobject obj = (*g_env)->NewObject(g_env, cls, mid);
	fileEnum->fileObject = (*g_env)->NewGlobalRef(g_env, obj);
	mid = (*g_env)->GetMethodID(g_env, cls, "sys_fenumstart","(Ljava/lang/String;Z)V");
	jstring dir = 0;

	if(pszDir){
		dir = (*g_env)->NewStringUTF(g_env, pszDir);
	}

	(*g_env)->CallVoidMethod(g_env, fileEnum->fileObject, mid, dir, bDirs);

	(*g_env)->DeleteLocalRef(g_env, dir);
	(*g_env)->DeleteLocalRef(g_env, cls);
	(*g_env)->DeleteLocalRef(g_env, obj);

	fileEnum->cstr = 0;

	return fileEnum;
}
