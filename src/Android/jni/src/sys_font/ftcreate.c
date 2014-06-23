/*
 * @file ftcreate.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

xfont_t * sys_xftcreate(){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xfont_t * font = (xfont_t *)malloc(sizeof(xfont_t));
	if(!font){
		return 0;
	}
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
	jobject obj = (*g_env)->NewObject(g_env, cls, mid);
	font->fontObject = (*g_env)->NewGlobalRef(g_env, obj);
	mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftcreate", "()V");
	(*g_env)->CallVoidMethod(g_env, font->fontObject, mid);
	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);
	mylog("create 15");

	return font;
}
