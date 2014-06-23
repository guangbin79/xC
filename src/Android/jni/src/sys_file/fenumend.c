/*
 * @file fenumend.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

void xsys_xfile_fEnumEnd(xsys_file_enum_t * pfe){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pfe){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/XenumFile");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fenumend", "()V");

		(*g_env)->CallVoidMethod(g_env, pfe->fileObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteGlobalRef(g_env, pfe->fileObject);

		if(pfe->cstr){
			free(pfe->cstr);
			pfe->cstr = 0;
		}
		free(pfe);
	}

}
