/*
 * @file xthread.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../../xthread.h"
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

xthread_mutex_t * xthread_mutex_create(xbool_t bRecursive)
{
    return (xthread_mutex_t*)sys_MutexCreate(bRecursive);
}

void xthread_mutex_lock(xthread_mutex_t* pmutex)
{
    sys_MutexLock((SYS_Mutex*) pmutex);
}

void xthread_mutex_unlock(xthread_mutex_t * pmutex)
{
    sys_MutexUnlock((SYS_Mutex*) pmutex);
}

void xthread_mutex_destory(xthread_mutex_t * pmutex)
{
    sys_MutexDestory((SYS_Mutex*) pmutex);
}

xthread_key_t * xthread_key_create()
{
	return sys_keycreate();
}

void xthread_key_destroy(xthread_key_t * pkey)
{
	sys_keydestroy((pthread_key_t*)pkey);
}

void * xthread_key_get(xthread_key_t * pkey)
{
	return sys_keyget((pthread_key_t*)pkey);
}

void xthread_key_set(xthread_key_t * pkey, const void * value)
{
	sys_keyset((pthread_key_t*)pkey, value);
}

xbool_t xthread_once(xthread_once_t * once, void(*init)())
{
	return sys_threadonce((pthread_once_t*)once, init);
}
