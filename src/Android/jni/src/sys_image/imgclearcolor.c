/*
 * @file imgclearcolor.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"


void sys_imgclearcolor(xsys_image_t *pimg,unsigned char r, unsigned char g, unsigned char b, unsigned char a){
	if(pimg && pimg->imgobject){
       	        JNIEnv * g_env;
	        (*jvm)->AttachCurrentThread(jvm, &g_env, 0);
		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Ximage");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_imgclearcolor","(IIII)V");
                (*g_env)->CallVoidMethod(g_env, pimg->imgobject, mid, r, g, b, a);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}
}




