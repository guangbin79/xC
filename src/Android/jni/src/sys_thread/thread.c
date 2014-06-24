/*
 * @file thread.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xthread.h"
#include "cn_com_tiros_api_MThread.h"


/*
 * Class:     cn_com_tiros_api_MThread
 * Method:    SYS_ThreadProcFunc
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_MThread_SYS_1ThreadProcFunc
  (JNIEnv * env , jclass cls, jint pvuser){
	sys_ThreadProcFuncEvent((void *)pvuser);
 }

/*
 * Class:     cn_com_tiros_api_MThread
 * Method:    SYS_ThreadNotifyFunc
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_com_tiros_api_MThread_SYS_1ThreadNotifyFunc
  (JNIEnv * env , jclass cls, jint pvuser){
	sys_ThreadNotifyFuncEvent((void *) pvuser);
 }


xsys_thread_t* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser){

	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	xsys_thread_t * thread = (xsys_thread_t *)malloc(sizeof(xsys_thread_t));

	jint hasnotify  = 0;

	if(!thread){
		return 0;
	}

	jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/MThread");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");

	jobject obj = (*g_env)->NewObject(g_env, cls, mid);

	thread->threadObject = (*g_env)->NewGlobalRef(g_env, obj);

	mid = (*g_env)->GetMethodID(g_env, cls, "sys_ThreadCreate", "(II)V");

	thread->pfn1 = proc;
//	if(notify){
//		hasnotify = 1;
//		thread->pfn2 = notify;
//	}else{
		hasnotify = 0;
	//}
	thread->pvUser = pvuser;

	(*g_env)->CallVoidMethod(g_env, thread->threadObject, mid, (jint) thread, hasnotify);

	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);

	return thread;
}


unsigned char sys_ThreadStart(xsys_thread_t* pthread){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pthread && pthread->threadObject){
		jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/MThread");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ThreadStart", "()I");
		jint ret = (*g_env)->CallIntMethod(g_env, pthread->threadObject, mid);
		(*g_env)->DeleteLocalRef(g_env, cls);
		return ret;
	}
	return 0;
}

unsigned char sys_ThreadIsExecuting(xsys_thread_t* pthread){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pthread && pthread->threadObject){
		jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/MThread");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ThreadIsExecuting", "()I");
		jint ret = (*g_env)->CallIntMethod(g_env, pthread->threadObject, mid);
		(*g_env)->DeleteLocalRef(g_env, cls);
		return ret;
	}
	return 0;
}

void sys_ThreadDestory(xsys_thread_t* pthread){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pthread && pthread->threadObject){

		jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/MThread");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "sys_ThreadDestory", "()V");

		(*g_env)->CallVoidMethod(g_env, pthread->threadObject, mid);

		(*g_env)->DeleteGlobalRef(g_env, pthread->threadObject);
		(*g_env)->DeleteLocalRef(g_env, cls);

		pthread->pfn1 = 0;
		pthread->pfn2 = 0;
		pthread->pvUser = 0;

		free(pthread);
	}
}



void sys_ThreadProcFuncEvent(void * pvUser){
	xsys_thread_t * pthread = (xsys_thread_t*)pvUser;

	if (!pthread || !pthread->pfn1){
		return;
	}

 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_ThreadProcFuncEvent ");

	(*(pthread->pfn1))(pthread->pvUser);

}
void sys_ThreadNotifyFuncEvent(void * pvUser){

	xsys_thread_t * pthread = (xsys_thread_t*)pvUser;

	if (!pthread || !pthread->pfn2){
		return;
	}

 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_ThreadNotifyFuncEvent ");

	(*(pthread->pfn2))(pthread->pvUser);
}


SYS_Mutex* sys_MutexCreate(){


 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_MutexCreate ");

	SYS_Mutex * mutex = (SYS_Mutex *)malloc(sizeof(SYS_Mutex));

	if(!mutex){
		return 0;
	}

        pthread_mutex_init(&mutex->mMutex, 0);

	/**
	jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/Mutex");
	jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "<init>", "()V");

	jobject obj = (*g_env)->NewObject(g_env, cls, mid);

	mutex->mutexObject = (*g_env)->NewGlobalRef(g_env, obj);

	(*g_env)->DeleteLocalRef(g_env, obj);
	(*g_env)->DeleteLocalRef(g_env, cls);

	*/

	return mutex;

}

void sys_MutexLock(SYS_Mutex* pmutex){

 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_MutexLock ");

	if(pmutex){
		pthread_mutex_lock(&pmutex->mMutex);
	}

	/**
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pmutex && pmutex->mutexObject){
		jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/Mutex");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "lock", "()V");
		(*g_env)->CallVoidMethod(g_env, pmutex->mutexObject, mid);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}
	*/
}

void sys_MutexUnlock(SYS_Mutex* pmutex){

 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_MutexUnlock ");

	if(pmutex){
		pthread_mutex_unlock(&pmutex->mMutex);
	}
	
	/**
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	if(pmutex && pmutex->mutexObject){
		jclass cls = (*g_env)->FindClass(g_env, "cn/com/tiros/api/Mutex");
		jmethodID mid = (*g_env)->GetMethodID(g_env, cls, "unlock", "()V");
		(*g_env)->CallVoidMethod(g_env, pmutex->mutexObject, mid);
		(*g_env)->DeleteLocalRef(g_env, cls);
	}
	*/
}

void sys_MutexDestory(SYS_Mutex* pmutex){

 __android_log_print(ANDROID_LOG_INFO,"jni--","sys_MutexDestory ");

	if(pmutex){
		pthread_mutex_destroy(&pmutex->mMutex);
		free(pmutex);
	}
}









