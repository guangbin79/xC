/**
 * xC
 * @file xrand.h
 * @brief 通用随机数相关接口
 * @author Harry <computerwjun@126.com>
 * @date 2014/03/13
 * @par 修改记录
 * 
 */

#ifndef _XRAND_H_
#define _XRAND_H_

#include "./xinteger.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 设置随机数种子
 */
void xsrand(xuint32_t seed);

/**
 * @brief 获取随机数
 */
xint32_t xrand();

#ifdef __cplusplus
}
#endif

#endif /* _XRAND_H_ */

