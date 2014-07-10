/*
 * @file sys_xgl.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xgl.h"

unsigned char sys_gl_makeCurrent(sys_xglsurface * surface)
{
	if(surface && surface->glsurfaceObject)
	{
		JNIEnv * g_env;
		(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
			jclass cls = (*g_env)->FindClass(g_env, "javax/microedition/khronos/egl/EGL20");
			jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "EGLWindowSurfaceMakeCurrent","(javax/microedition/khronos/egl/EGLDisplay;javax.microedition.khronos.egl.EGLSurface;javax.microedition.khronos.egl.EGLSurface;javax.microedition.khronos.egl.EGLContext;)B");
			unsigned char flag = (*g_env)->CallBooleanMethod(g_env, surface->glsurfaceObject, mid, surface->display, surface, surface,surface);
			(*g_env)->DeleteGlobalRef(g_env, cls);
			return flag;
	}
}

void sys_gl_swapBuffers(sys_xglsurface * surface)
{
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls = (*g_env)->FindClass(g_env, "javax/microedition/khronos/egl/EGL20");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "EGLSwapBuffers", "(javax/microedition/khronos/egl/EGLDisplay;javax.microedition.khronos.egl.EGLSurface;javax.microedition.khronos.egl.EGLSurface;)V");
	(*g_env)->CallStaticVoidMethod(g_env, cls, mid);
	(*g_env)->DeleteLocalRef(g_env, cls);

}
