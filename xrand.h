/**
 * xC
 * @file xrand.h
 * @brief 通用随机数相关接口
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/18
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
void xrand_srand(xuint32_t seed);

/**
 * @brief 获取随机数
 */
xint32_t xrand_rand();

#ifdef __cplusplus
}
#endif

#endif /* _XRAND_H_ */

