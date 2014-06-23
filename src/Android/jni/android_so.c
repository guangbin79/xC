/*
 * @file android_so.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "./jni_include/jni_system.h"

JavaVM * jvm;
extern jobject sensorobject;
//APPGlobalInfo * globalInfo;

jint JNI_OnLoad(JavaVM * vm, void * reserved) {
	jvm = vm;
	JNIEnv * g_env;
	(*vm)->AttachCurrentThread(vm, &g_env, 0);
	return (*g_env)->GetVersion(g_env);

}
