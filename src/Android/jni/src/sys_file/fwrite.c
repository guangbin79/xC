/*
 * @file fwrite.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned int xsys_xfile_fWrite(xsys_file_t * pf, const void * pvBuf, unsigned int bufSize){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fwrite", "([BI)I");

		jbyteArray  barray =(*g_env)->NewByteArray(g_env, bufSize);

		(*g_env)->SetByteArrayRegion(g_env, barray, 0, bufSize, pvBuf);

		jint size = (*g_env)->CallIntMethod(g_env, pf->fileObject, mid, barray, bufSize);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, barray);

		return size;
	}

	return 0;
}
