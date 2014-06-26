/*
 * @file sys_xthread.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#ifndef __SYS_THREAD_H__
#define __SYS_THREAD_H__

#include <jni.h>
#include <pthread.h>
//#include "../../../../xboolean.h"

/////////////////////
//线程执行体函数原型
typedef void (*SYS_ThreadProcFunc)(void* pvuser);
//线程执行完后的回调函数原型
typedef void (*SYS_ThreadNotifyFunc)(void* pvuser);

typedef struct _xsys_thread_t{
	jobject threadObject;
	SYS_ThreadProcFunc pfn1;
	SYS_ThreadNotifyFunc pfn2;
	void * pvUser;
}xsys_thread_t;

typedef struct _SYS_Mutexstr{
	pthread_mutex_t mMutex;
}SYS_Mutex;

#ifdef __cplusplus
extern "C" {
#endif

void sys_ThreadProcFuncEvent(void * pvUser);

void sys_ThreadNotifyFuncEvent(void * pvUser);

xsys_thread_t* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser);

unsigned char sys_ThreadStart(xsys_thread_t* pthread);
    
unsigned char sys_ThreadIsExecuting(xsys_thread_t* pthread);
    
void sys_ThreadDestory(xsys_thread_t* pthread);
    
/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/
    
SYS_Mutex* sys_MutexCreate(unsigned char bRecursive);

void sys_MutexLock(SYS_Mutex* pmutex);

void sys_MutexUnlock(SYS_Mutex* pmutex);

void sys_MutexDestory(SYS_Mutex* pmutex);

/**************key*********************/

pthread_key_t * sys_keycreate();

void sys_keydestroy(pthread_key_t * pkey);

void * sys_keyget(pthread_key_t * pkey);

void sys_keyset(pthread_key_t * pkey, const void * value);

unsigned char sys_threadonce(pthread_once_t * once, void(*init)());


#ifdef __cplusplus
}
#endif

#endif /*__SYS_THREAD_H__*/
