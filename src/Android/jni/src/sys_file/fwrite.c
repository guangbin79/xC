/*
 * sys_fwrite.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */

#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned int xsys_xfile_fWrite(xsys_file_t * pf, const void * pvBuf, unsigned int bufSize){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pf){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/XfileClass");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_fwrite", "([BI)I");

		jbyteArray  barray =(*g_env)->NewByteArray(g_env, bufSize);

		(*g_env)->SetByteArrayRegion(g_env, barray, 0, bufSize, pvBuf);

		//jbyte * element=(*g_env)->GetByteArrayElements(g_env, barray, 0);
		//sys_memcpy(element, pvBuf, bufSize);
		//(*g_env)->ReleaseByteArrayElements(g_env, barray, element, 0);
		jint size = (*g_env)->CallIntMethod(g_env, pf->fileObject, mid, barray, bufSize);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, barray);

		return size;
	}

	return 0;
}
