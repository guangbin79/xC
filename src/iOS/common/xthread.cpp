#include "../../../xthread.h"
#include "../../../xmemory.h"
#include "../include/sys_thread.h"
#include <pthread.h>

xthread_t * xthread_create(xfn_thread_proc_t proc, void* pvuser)
{
    return (xthread_t *)sys_ThreadCreate((SYS_ThreadProcFunc)proc, pvuser);
}

xbool_t xthread_start(xthread_t * pthread)
{
    return sys_ThreadStart((SYS_Thread*) pthread);
}

xbool_t xthread_isExecuting(xthread_t * pthread)
{
    return sys_ThreadIsExecuting((SYS_Thread*) pthread);
}

void xthread_destory(xthread_t * pthread)
{
    sys_ThreadDestory((SYS_Thread*) pthread);
}

void xthread_sleep(xuint32_t dwMSecs)
{
}

/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

xthread_mutex_t * xmutex_create()
{
    return (xthread_mutex_t *)sys_MutexCreate();
}

void xmutex_lock(xthread_mutex_t * pmutex)
{
    sys_MutexLock((SYS_Mutex*) pmutex);
}

void xmutex_unlock(xthread_mutex_t * pmutex)
{
    sys_MutexUnlock((SYS_Mutex*) pmutex);
}

void xmutex_destory(xthread_mutex_t * pmutex)
{
    sys_MutexDestory((SYS_Mutex*) pmutex);
}

xthread_key_t * xthread_key_create()
{
    pthread_key_t * key = (pthread_key_t *)xmemory_alloc(sizeof(pthread_key_t));
    if (0 == key)
    {
        return 0;
    }
    
    pthread_key_create(key, 0);
    
    return (xthread_key_t *)key;
}

void xthread_key_destroy(xthread_key_t * pkey)
{
    pthread_key_delete(*(pthread_key_t *)pkey);
}

void * xthread_key_get(xthread_key_t * pkey)
{
    return pthread_getspecific(*(pthread_key_t *)pkey);
}

void xthread_key_set(xthread_key_t * pkey, const void * value)
{
    pthread_setspecific(*(pthread_key_t *)pkey , value);
}

xbool_t xthread_once(xthread_once_t * once, void(*init)())
{
    return pthread_once((pthread_once_t *)once, init);
}
