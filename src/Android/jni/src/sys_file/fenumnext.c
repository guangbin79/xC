/*
 * @file fenumnext.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

const char * xsys_xfile_fEnumNext(xsys_file_enum_t * pfe){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pfe){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/XenumFile");

		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fenumnext", "()Ljava/lang/String;");

		jstring fileName = (*g_env)->CallObjectMethod(g_env, pfe->fileObject, mid);

		if(pfe->cstr){
			free(pfe->cstr);
			pfe->cstr = 0;
		}

		pfe->cstr = jstringTochar(g_env, fileName);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, fileName);

		return pfe->cstr;
	}

	return 0;
}
