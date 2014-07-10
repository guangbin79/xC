/*
 * @file ftmeasuretext.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"
unsigned short int sys_xftmeasuretext(xfont_t * pft, const unsigned short int * pwszText, unsigned int nChars, unsigned short int nMaxWidth, unsigned int * pnFits){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pft){
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftmeasuretext", "(Ljava/lang/String;II)I");

		unsigned int wlen = jni_wcslen(pwszText);
		if(nChars != 0 && nChars < wlen){
			wlen = nChars;
		}

		jstring text = 0;

		if(pwszText){
			text = (*g_env)->NewString(g_env, pwszText, wlen);
		}

		jint result = (*g_env)->CallIntMethod(g_env, pft->fontObject, mid, text, wlen, nMaxWidth);

		if(pnFits){
			mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftgetPnFits", "()I");
			(*pnFits) = (*g_env)->CallIntMethod(g_env, pft->fontObject, mid);
		}

		(*g_env)->DeleteLocalRef(g_env, cls);
		(*g_env)->DeleteLocalRef(g_env, text);

		return (unsigned short)result;
	}

	return (unsigned short)0;
}
