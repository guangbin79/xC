/**
 * xC
 * @file xthread.h
 * @brief 线程
 * @author guangbin <baigb@tiros.com.cn>
 * @date 2014/03/17
 * @par 修改记录
 *
 */
#ifndef _XTHREAD_H_
#define _XTHREAD_H_

#include "./xboolean.h"


/**
 * @brief 线程结构体
 */
typedef struct _xthread_t xthread_t;

/**
 * @brief 互斥结构体
 */
typedef struct _xmutex_t xmutex_t;

/**
 * @brief 线程执行函数类型声明
 * @param pvUser - 数据对象指针
 * @return - 无
 */
typedef void (*xfn_thread_proc_t)(void * pvUser);


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 创建线程句柄
 * @param[in] proc - 线程执行函数地址
 * @param[in] pvUser - 传递给线程执行的参数
 * @return - 创建成功的线程句柄，XNULL为失败
 */
xthread_t * xthread_create(xfn_thread_proc_t proc, void * pvUser);

/**
 * @brief 启动线程
 * @param[in] pxthread - 线程句柄
 * @return - 成功XTRUE/失败XFALSE
 */
xbool_t xthread_start(xthread_t * pxthread);

/**
 * @brief 获取线程是否正在运行
 * @param[in] pxthread - 线程句柄
 * @return - XTRUE：正在执行/XFALSE：空闲或者完成
 */
xbool_t xthread_isExecuting(xthread_t * pxthread);

/**
 * @brief 销毁线程
 * @param[in] pxthread - 线程句柄
 * @return - 无
 */
void xthread_destory(xthread_t * pxthread);

/**
 * @brief 创建线程互斥句柄
 * @return - 创建成功的线程互斥句柄，XNULL为失败
 */
xmutex_t * xmutex_create();

/**
 * @brief 互斥加锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_lock(xmutex_t * pmutex);

/**
 * @brief 互斥解锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_unlock(xmutex_t * pmutex);

/**
 * @brief 销毁线程互斥句柄
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xmutex_destory(xmutex_t * pmutex);

#ifdef __cplusplus
}
#endif

#endif /*_XTHREAD_H_*/

