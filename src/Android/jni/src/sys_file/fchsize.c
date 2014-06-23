/*
 * @file fchsize.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */


#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned int xsys_xfile_fChSize(xsys_file_t * pf, unsigned int size){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fchsize", "(I)I");
		jint  filesize = (*g_env)->CallIntMethod(g_env, pf->fileObject, mid, size);
		(*g_env)->DeleteLocalRef(g_env, cls);
		return (unsigned int)filesize;
	}

	return (unsigned int)0;
}
