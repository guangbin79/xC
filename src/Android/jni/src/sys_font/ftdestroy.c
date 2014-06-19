/*
 * sys_ftdestroy.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */
#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

void sys_xftdestroy(xfont_t * pft){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft && pft->fontObject){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftdestroy", "()V");

		(*g_env)->CallVoidMethod(g_env, pft->fontObject, mid);
		(*g_env)->DeleteGlobalRef(g_env, pft->fontObject);
		(*g_env)->DeleteLocalRef(g_env, cls);

		sys_xfree(pft);
	}

}
