#include "../../jni_include/jni_system.h"

unsigned int  sys_xclock(){

	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/Xtime");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_clock", "()D");

	jint clock = (*g_env)->CallStaticDoubleMethod(g_env, cls, mid);
	return clock;

}
