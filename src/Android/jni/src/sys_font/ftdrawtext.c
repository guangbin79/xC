/*
 * sys_ftdrawtext2.c
 *
 *  Created on: 2012-2-17
 *      Author: shizy
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfont.h"

void sys_xftdrawtext(xfont_t * pft, short int x, short int y, const unsigned short int * pwszText, unsigned char r, unsigned char g, unsigned char b){

	mylog("1111");
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft){
		mylog("2222");
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftdrawtext2","(IILjava/lang/String;III)V");

		mylog("33333");
		unsigned int wlen = jni_wcslen(pwszText);

		jstring text = "1111";

		mylog("44444");
//		if(pwszText){
//			text = (*g_env)->NewString(g_env, pwszText, wlen);
//		}
		mylog("555");
		(*g_env)->CallVoidMethod(g_env, pft->fontObject, mid, x, y, text, r, g, b);
		mylog("6666");
		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, text);
	}
}
