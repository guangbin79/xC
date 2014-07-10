/*
 * @file fread.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"


unsigned int xsys_xfile_fRead(xsys_file_t * pf, void * pvBuf, unsigned int bufSize){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfile");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fread", "([BI)I");
		jbyteArray barray =(*g_env)->NewByteArray(g_env, bufSize);
		jint size = (*g_env)->CallIntMethod(g_env, pf->fileObject, mid, barray, bufSize);

		if (size > 0)
		{
			(*g_env)->GetByteArrayRegion(g_env, barray, 0, bufSize, pvBuf);

		}
		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, barray);

		return size;
	}

	return 0;
}
