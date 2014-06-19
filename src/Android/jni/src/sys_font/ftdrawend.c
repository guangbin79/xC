/*
 * sys_ftdrawend.c
 *
 *  Created on: 2012-2-17
 *      Author: shizy
 *  Modify  by caoyp on: 2012-5-28
 *  Modify  by caoyp on: 2012-7-04
 */
#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

void sys_xftdrawend(xfont_t* pft){
    unsigned int starttime = clock() / 1000;

	if(pft && pft->fontObject){
	        JNIEnv * g_env;
	        (*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	        jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftdrawend","()Ljava/lang/Object;");
		jobject jbitmap = (*g_env)->CallObjectMethod(g_env, pft->fontObject, mid);
                AndroidBitmap_lockPixels(g_env, jbitmap, &(pft->ptr));            
                memcpy(pft->pcolors, pft->ptr, pft->width * pft->height * GL_PIXEL_SIZE);
                AndroidBitmap_unlockPixels(g_env, jbitmap);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}
}

