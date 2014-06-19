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


void sys_imgdestroy(xsys_image_t * image)
{
	if(image && image->imgobject){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
		jclass cls = (*g_env)->FindClass(g_env, "xc/api/Ximage");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_imgdestroy", "()V");

		(*g_env)->CallVoidMethod(g_env, image->imgobject, mid);
		(*g_env)->DeleteGlobalRef(g_env, image->imgobject);
		(*g_env)->DeleteLocalRef(g_env, cls);

        free(image);
	}
}

