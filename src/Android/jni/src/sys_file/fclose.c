/*
 * sys_fclose.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

void xsys_xfile_fClose(xsys_file_t * pf){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/XfileClass");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fclose", "()V");

		(*g_env)->CallVoidMethod(g_env, pf->fileObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteGlobalRef(g_env, pf->fileObject);

		free(pf);
	}

}
