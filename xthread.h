/**
 * xC
 * @file xthread.h
 * @brief 线程
 * @author guangbin <guangbin79@gmail.com>
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
typedef struct _xthread xthread_t;

/**
 * @brief 线程执行函数类型声明
 * @param pvUser - 数据对象指针
 * @return - 无
 */
typedef void (*xfn_thread_proc_t)(void * pvUser);

/**
 * @brief 互斥结构体
 */
typedef struct _xthread_mutex xthread_mutex_t;

/**
 * @brief TLS key
 */
typedef struct _xthread_key xthread_key_t;

/**
 * @brief 线程一次性初始化控制标志
 */
typedef xint8_t xthread_once_t;

/**
 * @brief 线程一次性初始化控制常量
 */
#define XTHREAD_ONCE_INIT 1


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
 * @brief 销毁线程
 * @param[in] pxthread - 线程句柄
 * @return - 无
 */
void xthread_destroy(xthread_t * pxthread);

/**
 * @brief 挂起当前线程
 * @param[in] dwMSecs - 挂起时间,单位:毫秒
 * @return - 无
 */
void xthread_sleep(xuint32_t dwMSecs);

/**
 * @brief 创建线程互斥句柄
 * @return - 创建成功的线程互斥句柄，XNULL为失败
 */
xthread_mutex_t * xthread_mutex_create(xbool_t bRecursive);

/**
 * @brief 互斥加锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xthread_mutex_lock(xthread_mutex_t * pmutex);

/**
 * @brief 互斥解锁
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xthread_mutex_unlock(xthread_mutex_t * pmutex);

/**
 * @brief 销毁线程互斥句柄
 * @param pmutex - 线程互斥句柄
 * @return - 无
 */
void xthread_mutex_destroy(xthread_mutex_t * pmutex);

/**
 * @brief 创建 TLS 的 key
 * @return - 创建成功的key，XNLL为失败
 */
xthread_key_t * xthread_key_create();

/**
 * @brief 销毁 TLS 的 key
 * @param pkey - TLS 对应的 key
 * @return - 无
 */
void xthread_key_destroy(xthread_key_t * pkey);

/**
 * @brief 获取 TLS 对应 key 的数据
 * @param pkey - TLS 对应的 key
 * @return - 返回 TLS 对应 key 的数据指针
 */
void * xthread_key_get(xthread_key_t * pkey);

/**
 * @brief 设置 TLS 对应 key 的数据
 * @param pkey - TLS 对应的 key
 * @param value - TLS 对应 key 的数据指针
 * @return - 无
 */
void xthread_key_set(xthread_key_t * pkey, const void * value);

/**
 * @brief 线程一次性初始化
 * @param once - 一次性初始化标志位
 * @param init - 一次性初始化函数
 * @return - 调用一次性初始化函数则返回XTRUE, 否则返回XFALSE
 */
xbool_t xthread_once(xthread_once_t * once, void(*init)());

#ifdef __cplusplus
}
#endif

#endif /*_XTHREAD_H_*/
