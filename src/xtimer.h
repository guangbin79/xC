/**
 * xC
 * @file xtimer.h
 * @brief 定时器
 * @author guangbin <baigb@tiros.com.cn>
 * @date 2014/03/14
 * @par 修改记录
 *
 */

#ifndef _XTIMER_H_
#define _XTIMER_H_

#include "./xboolean.h"
#include "./xinteger.h"


/**
 * @brief 定时器结构体
 */
typedef struct _xtimer_t xtimer_t;

/**
 * @brief 定时器回调函数类型声明
 * @param pvUser - 回调对象指针
 * @return - 无
 */
typedef void (*xfn_timer_event)(void * pvUser);


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 创建定时器
 * @param - 无
 * @return - 定时器结构体指针
 */
xtimer_t * xtimer_create();

/**
 * @brief 销毁定时器
 * @param[in] ptmr - 定时器结构体指针
 * @return - 无
 */
void xtimer_destroy(xtimer_t * ptmr);

/**
 * @brief 启动定时器
 * @param[in] ptmr - 定时器结构体指针
 * @param[in] dwMSecs - 定时器定时时间,单位:毫秒
 * @param[in] pfn - 定时器到期后回调函数指针
 * @param[in] pvUser - 定时器到期后回调对象指针
 * @return - 无
 * @par 接口使用约定
 *      1.dwMSecs必须大于0<br>
 */
void xtimer_start(xtimer_t * ptmr, xuint32_t dwMSecs, xfn_timer_event pfn, void * pvUser);

/**
 * @brief 判断定时器是否已经启动
 * @param[in] ptmr - 定时器结构体指针
 * @return - 已经开始定时:true,没有开始定时:false
 */
xbool_t xtimer_isBusy(xtimer_t * ptmr);

/**
 * @brief 取消已经启动的定时器
 * @param[in] ptmr - 定时器结构体指针
 * @return - 无
 */
void xtimer_cancel(xtimer_t * ptmr);

#ifdef __cplusplus
}
#endif

#endif /* _XTIMER_H_ */

