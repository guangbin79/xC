/*
 * sys_fseek.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned int xsys_xfile_fSeek(xsys_file_t * pf, xsys_file_seek_type_t seekType, unsigned int moveDistance){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/XfileClass");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fseek", "(II)I");

		jint result = (*g_env)->CallIntMethod(g_env, pf->fileObject, mid, seekType, moveDistance);
		(*g_env)->DeleteLocalRef(g_env, cls);
		return result;
	}

	return 0;
}
