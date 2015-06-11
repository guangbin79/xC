#ifndef _SYS_THREADDEF_H_
#define _SYS_THREADDEF_H_

#import"ThreadEngine.h"
#import "LockEngine.h"

struct _SYS_ThreadStr
{
    ThreadEngine* _pThreadEngine;
};

struct _SYS_Mutexstr
{
    MutexEngine* _pMutexEngine;
};

struct _SYS_Semaphorestr
{
    SemaphoreEngine* _pSemaphoreEngine;
};


#endif /*_SYS_THREADDEF_H_*/
