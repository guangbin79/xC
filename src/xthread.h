/**
 * xC
 * @file xthread.h
 * @brief xthread API
 * @author map <map@tiros.com.cn>
 * @date 2014/03/14
 * @par
 *
 */
#ifndef __XTHREAD_H__
#define __XTHREAD_H__


#include "./xboolean.h"

typedef struct _ThreadStr XThread;
typedef struct _Mutexstr XMutex;

//线程执行体函数原型
typedef void (*XThreadProcFunc)(void* pvuser);
//线程执行完后的回调函数原型
typedef void (*XThreadNotifyFunc)(void* pvuser);

#ifdef __cplusplus
extern "C" {
#endif
    
/**
 * @brief 创建线程句柄
 * @param proc - 线程执行函数地址
 * @param pvuser - 传递给线程执行的参数
 * @param notify - 线程执行完毕之后通知主线程函数地址
 * @return - 创建成功的线程句柄，NULL为失败
 */
XThread* xthread_create(XThreadProcFunc proc, XThreadNotifyFunc notify, void * pvuser);

/**
 * @brief 启动线程
 * @param pthread - 线程句柄
 * @return - 成功true/失败false
 */
bool xthread_start(XThread* pthread);

/**
 * @brief 获取线程是否正在运行
 * @param pthread - 线程句柄
 * @return - true：正在执行/false：空闲或者完成
 */
bool xthread_isExecuting(XThread* pthread);

/**
 * @brief 销毁线程
 * @param pthread - 线程句柄
 * @return - void
 */
void xthread_destory(XThread* pthread);

/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

/**
 * @brief 创建线程互斥句柄
 * @return - 创建成功的线程互斥句柄，NULL为失败
 */
XMutex* xmutex_create();

/**
 * @brief 互斥加锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_lock(XMutex* pMutex);

/**
 * @brief 互斥解锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_unlock(XMutex* pMutex);

/**
 * @brief 销毁线程互斥句柄
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_destory(XMutex* pMutex);
    
    
#ifdef __cplusplus
}
#endif

#endif /*__XTHREAD_H__*/


