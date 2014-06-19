#include "../../jni_include/jni_system.h"

unsigned char xsys_xfile_fDiskExist(const char * pszDisk){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env, "xc/api/XfileClass");
	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fdiskexist", "(Ljava/lang/String;)I");

	jstring dir = 0;
	if(pszDisk){
		dir = (*g_env)->NewStringUTF(g_env, pszDisk);
	}

	jint result = (*g_env)->CallStaticIntMethod(g_env, cls, mid, dir);

	(*g_env)->DeleteLocalRef(g_env,dir);
	(*g_env)->DeleteLocalRef(g_env,cls);

	return (unsigned char)result;
}
