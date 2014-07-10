/*
 * @file ftgetheight.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

unsigned short int sys_xftgetheight(xfont_t * pft){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftgetheight","()I");
		jint result = (*g_env)->CallIntMethod(g_env, pft->fontObject, mid);
		(*g_env)->DeleteLocalRef(g_env, cls);
		return (unsigned short)result;
	}

	return (unsigned short)0;

}
