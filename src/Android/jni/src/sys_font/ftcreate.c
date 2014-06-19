/*
 * sys_ftcreate.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

xfont_t * sys_xftcreate(){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xfont_t * font = (xfont_t *)sys_xmalloc(sizeof(xfont_t));

	if(!font){
		return 0;
	}
mylog("create 1");
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
	mylog("create 2");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
	mylog("create 12");
	jobject obj = (*g_env)->NewObject(g_env, cls, mid);

	font->fontObject = (*g_env)->NewGlobalRef(g_env, obj);
	mylog("create 13");
	mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftcreate", "()V");
	mylog("create 14");
	(*g_env)->CallVoidMethod(g_env, font->fontObject, mid);
	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);
	mylog("create 15");

	return font;
}
