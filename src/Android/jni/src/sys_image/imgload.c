/*
 *  sys_image.c
 *  My_System_api
 *
 *  Created by caoyp on 12-5-5.
 *  Modify by caoyp on 12-5-10.
 *  Modify by caoyp on 12-5-18.
 *  Modify by caoyp on 12-6-05.
 *  Modify by caoyp on 12-6-17.
 *  Modify by caoyp on 12-7-04.
 *  Copyright 2012 __MyCompanyName__TIROS. All rights reserved.
 *
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"

xsys_image_t * sys_imgload(const void * pimgdata, unsigned int size){

	xsys_image_t * image = (xsys_image_t *)malloc(sizeof(xsys_image_t));

    if (!image)
    {
        return NULL;
    }

    JNIEnv * g_env;
    (*jvm)->AttachCurrentThread(jvm, &g_env, 0);

    jclass cls =(*g_env)->FindClass(g_env, "xc/api/Ximage");
    jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");
    jobject obj = (*g_env)->NewObject(g_env, cls, mid);
    image->imgobject = (*g_env)->NewGlobalRef(g_env, obj);

    mid = (*g_env)->GetMethodID(g_env, cls, "sys_imgload", "([BI)V");

    jbyteArray barray =(*g_env)->NewByteArray(g_env, size);
    (*g_env)->SetByteArrayRegion(g_env, barray, 0, size, pimgdata);
    (*g_env)->CallVoidMethod(g_env, image->imgobject, mid, barray, size);
    (*g_env)->DeleteLocalRef(g_env, barray);

    mid = (*g_env)->GetMethodID(g_env, cls, "imgload_getwidth", "()I");
    image->width =  (*g_env)->CallIntMethod(g_env, image->imgobject, mid); 
    mid = (*g_env)->GetMethodID(g_env, cls, "imgload_getheight", "()I");
    image->height =  (*g_env)->CallIntMethod(g_env, image->imgobject, mid);

    (*g_env)->DeleteLocalRef(g_env, obj);
    (*g_env)->DeleteLocalRef(g_env, cls);

    return image;
}


