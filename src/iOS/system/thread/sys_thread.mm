//
//  sys_bitmap.mm
// System_api
//
//  Created by zjy on 12-6-27.
//  Copyright 2011 __MyCompanyName__. All rights reserved.

#import"sys_thread.h"
#import"sys_threaddef.h"



SYS_Thread* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser)
{
    SYS_Thread * pThread = (SYS_Thread*)malloc(sizeof(SYS_Thread));
    if (pThread)
    {
        pThread->_pThreadEngine = [[ThreadEngine alloc]init];
        [pThread->_pThreadEngine initAttr:proc WithNotify:NULL AndUser:pvuser];
    }
    return pThread;
}

unsigned char sys_ThreadStart(SYS_Thread* pthread)
{
    if (pthread)
    {
        [pthread->_pThreadEngine Start];
        return true;
    }
    return false;
}

unsigned char sys_ThreadIsExecuting(SYS_Thread* pthread)
{
    if (pthread)
    {
        return [pthread->_pThreadEngine isExecuting];
    }
    return false;
}

void sys_ThreadDestory(SYS_Thread* pthread)
{
    if (pthread)
    {
        while(true){
            if ([pthread->_pThreadEngine isBusy] == NO){
                break;
            }

            [NSThread sleepForTimeInterval:3];
        }
        [pthread->_pThreadEngine  willDestroy];
        [pthread->_pThreadEngine release];
        free(pthread);
        pthread = NULL;
    }
}

/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

SYS_Mutex* sys_MutexCreate()
{
    SYS_Mutex* pmutex= (SYS_Mutex*)malloc(sizeof(SYS_Mutex));
    pmutex->_pMutexEngine = [[MutexEngine alloc]init];
    return  pmutex;
}

void sys_MutexLock(SYS_Mutex* pmutex)
{
    if (pmutex) {
        [pmutex->_pMutexEngine lock];
    }
}

void sys_MutexUnlock(SYS_Mutex* pmutex)
{
    if (pmutex) {
        [pmutex->_pMutexEngine unlock];
    }
}

void sys_MutexDestory(SYS_Mutex* pmutex)
{
    if (pmutex) {
        [pmutex->_pMutexEngine release];
        free(pmutex);
        pmutex= NULL;
    }
}




