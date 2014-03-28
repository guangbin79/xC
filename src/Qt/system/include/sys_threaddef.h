#ifndef _SYS_THREADDEF_H_
#define _SYS_THREADDEF_H_

#include "../thread/ThreadEngine.h"
#include "../thread/LockEngine.h"
#include "../../include/sys_thread.h"

struct _SYS_ThreadStr
{
    CThreadEngine* _pThreadEngine;
    SYS_ThreadProcFunc _pThreadProcFunc;
    void* _pvUser;
};

struct _SYS_Mutexstr
{
    CMutexEngine* _pMutexEngine;
};

#endif /*_SYS_THREADDEF_H_*/
