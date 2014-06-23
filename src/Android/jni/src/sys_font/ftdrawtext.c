/*
 * @file ftdrawtext.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfont.h"

void sys_xftdrawtext(xfont_t * pft, short int x, short int y, const unsigned short int * pwszText, unsigned char r, unsigned char g, unsigned char b){


	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft){

		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftdrawtext2","(IILjava/lang/String;III)V");
		unsigned int wlen = jni_wcslen(pwszText);

		jstring text = 0;
		if(pwszText){
			text = (*g_env)->NewString(g_env, pwszText, wlen);
		}

		(*g_env)->CallVoidMethod(g_env, pft->fontObject, mid, x, y, text, r, g, b);

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, text);
	}
}
