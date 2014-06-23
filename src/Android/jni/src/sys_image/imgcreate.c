/*
 * @file imgcreate.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"

xsys_image_t * sys_imgcreate(unsigned short int width, unsigned short int height)
{

	xsys_image_t * image = (xsys_image_t *)malloc(sizeof(xsys_image_t));

    if (!image)
    {
        return NULL;
    }

    image->width = width;
    image->height = height;
				
    JNIEnv * g_env;
    (*jvm)->AttachCurrentThread(jvm, &g_env, 0);

    jclass cls =(*g_env)->FindClass(g_env, "xc/api/Ximage");
    jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
    jobject obj = (*g_env)->NewObject(g_env, cls, mid);
    image->imgobject = (*g_env)->NewGlobalRef(g_env, obj);

    mid = (*g_env)->GetMethodID(g_env, cls, "sys_imgcreate", "(II)V");	 
    (*g_env)->CallVoidMethod(g_env, image->imgobject, mid, width, height);

    (*g_env)->DeleteLocalRef(g_env, obj);
    (*g_env)->DeleteLocalRef(g_env, cls);
    
    return image;
}





