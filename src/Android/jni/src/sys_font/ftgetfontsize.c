/*
 * sys_ftgetfontsize.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */

#include "../../jni_include/jni_font.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"
#include "../../jni_include/jni_system.h"

unsigned short int sys_xftgetfontsize(xfont_t * pft){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftgetfontsize","()I");

		jint result = (*g_env)->CallIntMethod(g_env, pft->fontObject, mid);

		(*g_env)->DeleteLocalRef(g_env, cls);

		return (unsigned short)result;
	}

	return (unsigned short)0;

}
