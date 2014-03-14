/**
 * 通用平台系统API
 * Copyright (c) 2011 Tiros.
 * @file timer.h
 * @brief 定时器
 * @author caiyw <caiyw@tiros.com.cn>
 * @date 2011/06/15
 * @note 不要直接调用tr_函数,应该调用对应的宏定义
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
typedef struct _Timer xtimer_t;

/**
 * @brief 定时器回调函数类型声明
 * @param pvUser - 回调对象指针
 * @return - 无
 */
typedef void (*XFUNPOINTER_FNTIMEREVENT)(void * pvUser);
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 创建定时器
 * @param - 无
 * @return - 定时器结构体指针
 */
xtimer_t* xtimer_create();


/**
 * @brief 销毁定时器
 * @param[in] ptmr - 定时器结构体指针
 * @return - 无
 */
void xtimer_destroy( xtimer_t* ptmr );

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
void xtimer_start( xtimer_t* ptmr, xuint32_t dwMSecs, XFUNPOINTER_FNTIMEREVENT pfn, void* pvUser );

/**
 * @brief 判断定时器是否已经启动
 * @param[in] ptmr - 定时器结构体指针
 * @return - 已经开始定时:true,没有开始定时:false
 */
xbool_t xtimer_isbusy( xtimer_t* ptmr );


/**
 * @brief 取消已经启动的定时器
 * @param[in] ptmr - 定时器结构体指针
 * @return - 无
 */
void xtimer_cancel( xtimer_t* ptmr );

#ifdef __cplusplus
}
#endif

#endif /* _TIMER_H_ */

