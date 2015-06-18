//
//  sys_thread.h
//  Thread API
//
//  Created by xCPI
//  Copyright (c) 2015年  All rights reserved.

#ifndef __SYS_THREAD_H__
#define __SYS_THREAD_H__


typedef struct _SYS_ThreadStr SYS_Thread;
typedef struct _SYS_Mutexstr SYS_Mutex;

//线程执行体函数原型
typedef void (*SYS_ThreadProcFunc)(void* pvuser);
//线程执行完后的回调函数原型
typedef void (*SYS_ThreadNotifyFunc)(void* pvuser);

#ifdef __cplusplus
extern "C" {
#endif
    
    SYS_Thread* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser);
    
    unsigned char sys_ThreadStart(SYS_Thread* pthread);
    
    unsigned char sys_ThreadIsExecuting(SYS_Thread* pthread);
    
    void sys_ThreadDestory(SYS_Thread* pthread);
    
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


