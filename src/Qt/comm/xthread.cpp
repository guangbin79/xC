#include "../../../xthread.h"
#include "../include/sys_thread.h"

static xthread_mutex_t * _once_mutex = 0;

xthread_t * xthread_create(xfn_thread_proc_t proc, void* pvuser)
{
    if (0 == _once_mutex) {
        _once_mutex = xthread_mutex_create(XFALSE);
    }

    return (xthread_t *)sys_ThreadCreate((SYS_ThreadProcFunc)proc, pvuser);
}

xbool_t xthread_start(xthread_t * pthread)
{
    return sys_ThreadStart((SYS_Thread*) pthread);
}

void xthread_destroy(xthread_t * pthread)
{
    sys_ThreadDestory((SYS_Thread*) pthread);
}

void xthread_sleep(xuint32_t dwMSecs)
{
    sys_ThreadSleep(dwMSecs);
}

xthread_mutex_t * xthread_mutex_create(xbool_t bRecursive)
{
    return (xthread_mutex_t *)sys_MutexCreate(bRecursive);
}

void xthread_mutex_lock(xthread_mutex_t * pmutex)
{
    sys_MutexLock((SYS_Mutex*) pmutex);
}

void xthread_mutex_unlock(xthread_mutex_t * pmutex)
{
    sys_MutexUnlock((SYS_Mutex*) pmutex);
}

void xthread_mutex_destroy(xthread_mutex_t * pmutex)
{
    sys_MutexDestory((SYS_Mutex*) pmutex);
}

xthread_key_t * xthread_key_create()
{
    return (xthread_key_t *)sys_TlsAlloc();
}

void xthread_key_destroy(xthread_key_t * pkey)
{
    sys_TlsFree((void *)pkey);
}

void * xthread_key_get(xthread_key_t * pkey)
{
    return sys_TlsGet((void *)pkey);
}

void xthread_key_set(xthread_key_t * pkey, const void * value)
{
    sys_TlsSet((void *)pkey, value);
}

xbool_t xthread_once(xthread_once_t * once, void(*init)())
{
    if (0 == _once_mutex) {
        _once_mutex = xthread_mutex_create(XFALSE);
    }

    xthread_mutex_lock(_once_mutex);

    if (XTHREAD_ONCE_INIT == *once) {
       *once = ~XTHREAD_ONCE_INIT;
       (*init)();

       xthread_mutex_unlock(_once_mutex);

       return XTRUE;
    }

    xthread_mutex_unlock(_once_mutex);

    return XFALSE;
}

