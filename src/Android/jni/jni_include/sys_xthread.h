//
//  sys_thread.h
//  Thread API
//
//  Created by Harry on 13-10-31.
//  Copyright (c) 2013年 Harry. All rights reserved.

#ifndef __SYS_THREAD_H__
#define __SYS_THREAD_H__



#include <jni.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


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

//typedef struct _pthread_mutex_t{
//
//}pthread_mutex_t;


typedef struct _SYS_Mutexstr{
	pthread_mutex_t mMutex;
}SYS_Mutex;



void sys_ThreadProcFuncEvent(void * pvUser);
void sys_ThreadNotifyFuncEvent(void * pvUser);

///////////////////////


xsys_thread_t* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser);

unsigned char sys_ThreadStart(xsys_thread_t* pthread);
    
unsigned char sys_ThreadIsExecuting(xsys_thread_t* pthread);
    
void sys_ThreadDestory(xsys_thread_t* pthread);
    
/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/
    
SYS_Mutex* sys_MutexCreate();

void sys_MutexLock(SYS_Mutex* pmutex);

void sys_MutexUnlock(SYS_Mutex* pmutex);

void sys_MutexDestory(SYS_Mutex* pmutex);
    
    
#ifdef __cplusplus
}
#endif

#endif /*__SYS_THREAD_H__*/


