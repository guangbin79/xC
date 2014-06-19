#include "../../../xthread.h"
#include "../jni_include/sys_xthread.h"


xthread_t * xthread_create(xfn_thread_proc_t proc, void * pvUser)
{
    return (xthread_t *)sys_ThreadCreate((SYS_ThreadProcFunc)proc, pvUser);
}

xbool_t xthread_start(xthread_t * pxthread)
{
    return sys_ThreadStart((xsys_thread_t*) pxthread);
}

xbool_t xthread_isExecuting(xthread_t * pxthread)
{
    return sys_ThreadIsExecuting((xsys_thread_t*) pxthread);
}

void xthread_destory(xthread_t * pxthread)
{
    sys_ThreadDestory((xsys_thread_t*) pxthread);
}


/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

//Mutex* tr_MutexCreate()
xmutex_t * xmutex_create()
{
    return (xmutex_t*)sys_MutexCreate();
}

void xmutex_Lock(xmutex_t* pmutex)
{
    sys_MutexLock((SYS_Mutex*) pmutex);
}

void xmutex_Unlock(xmutex_t* pmutex)
{
    sys_MutexUnlock((SYS_Mutex*) pmutex);
}

void xmutex_Destory(xmutex_t* pmutex)
{
    sys_MutexDestory((SYS_Mutex*) pmutex);
}









