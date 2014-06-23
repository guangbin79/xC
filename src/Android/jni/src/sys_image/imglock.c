/*
 * @file imglock.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"

void * sys_imglock(xsys_image_t * pimg){
	if(pimg && pimg->imgobject){
	        JNIEnv * g_env;
	        (*jvm)->AttachCurrentThread(jvm, &g_env, 0);
		jclass cls =(*g_env)->FindClass(g_env, "xc/api/Ximage");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "getBitmapObj","()Ljava/lang/Object;");
                jobject jbitmap = (*g_env)->CallObjectMethod(g_env, pimg->imgobject, mid);
                AndroidBitmap_lockPixels(g_env, jbitmap, &(pimg->buffer));

		(*g_env)->DeleteLocalRef(g_env, cls);

           return pimg->buffer;
        }
        return 0;
}

