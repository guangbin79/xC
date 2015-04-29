/**
 * xC
 * @file xdebug.h
 * @brief 代码调试
 * @author guangbin <guangbin79@gmail.com>
 * @date 2015/01/30
 * @par 修改记录
 *
 */

#ifndef _XDEBUG_H_
#define _XDEBUG_H_

#include "./xboolean.h"
#include "./xcharacter.h"

#ifdef NDEBUG

#define XASSERT(exp)
#define XDBGPRINTF(str)

#else

#define XASSERT(exp)      xdebug_assert(exp)
#define XDBGPRINTF(str)   xdebug_printf(str)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 断言的实现
 * @param[in] exp - 断言
 * @return - 无
 */
void xdebug_assert(xbool_t exp);

/**
 * @brief 调试信息输出的实现
 * @param[in] str - 输出的调试信息
 * @return - 无
 */
void xdebug_printf(const xchar_t * str);

#ifdef __cplusplus
}
#endif

#endif /* NDEBUG */

#endif /* _XDEBUG_H_ */

