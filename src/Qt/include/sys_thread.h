//
//  sys_thread.h
//  Thread API
//
//  Created by Harry on 13-10-31.
//  Copyright (c) 2013年 Harry. All rights reserved.

#ifndef _SYS_THREAD_H_
#define _SYS_THREAD_H_


typedef struct _SYS_ThreadStr SYS_Thread;
typedef struct _SYS_Mutexstr SYS_Mutex;

//线程执行体函数原型
typedef void (*SYS_ThreadProcFunc)(void* pvuser);

#ifdef __cplusplus
extern "C" {
#endif

SYS_Thread* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser);

unsigned char sys_ThreadStart(SYS_Thread* pthread);

unsigned char sys_ThreadIsExecuting(SYS_Thread* pthread);

void sys_ThreadDestory(SYS_Thread* pthread);

void sys_ThreadSleep(unsigned int dwMSecs);

void * sys_TlsAlloc();
void sys_TlsFree(void * tls_key);
void * sys_TlsGet(void * tls_key);
void sys_TlsSet(void * tls_key, const void * data);

/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

SYS_Mutex* sys_MutexCreate(bool bRecursive);

void sys_MutexLock(SYS_Mutex* pmutex);

void sys_MutexUnlock(SYS_Mutex* pmutex);

void sys_MutexDestory(SYS_Mutex* pmutex);


#ifdef __cplusplus
}
#endif

#endif /*_SYS_THREAD_H_*/


