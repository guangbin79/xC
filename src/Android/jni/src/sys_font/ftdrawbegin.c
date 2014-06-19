/*
 * sys_ftdrawbegin.c
 *
 *  Created on: 2012-2-17
 *      Author: shizy
 *      Modify: by caoyp 2012-07-04.
 */
#include "../../jni_include/jni_image.h"
#include "../../jni_include/jni_font.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/sys_xfont.h"

void sys_xftdrawbegin(xfont_t * pft, xsys_image_t* pimg){
 
	if(pft && pft->fontObject){
	        JNIEnv * g_env;
	        (*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	        jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xfont");
                jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ftdrawbegin","(Lcn/com/tiros/api/Image;)V");
                (*g_env)->CallVoidMethod(g_env, pft->fontObject, mid, pimg->imgobject);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}

}
