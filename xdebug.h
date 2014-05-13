/**
 * @file xdebug.h
 * @brief 代码调试
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par 修改记录
 * 
 */

#ifndef _XDEBUG_H_
#define _XDEBUG_H_

#include "./xboolean.h"
#include "./xcharacter.h"

#ifdef NDEBUG

#define XASSERT(exp)
#define XDBGPRINTF(format, ...)

#else

#define XASSERT(exp) xdebug_assert(exp)
#define XDBGPRINTF(format,...) xdebug_printf(format, VA_ARGS)

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
 * @brief 调试信息输出的实现,请调用宏定义xdb_gprintf,不要直接调用xdbg_printf
 * @param[in] format - 调试信息输出格式
 * @param[in] ... - 可变参序列
 * @return - 无
 */
void xdebug_printf(const xchar_t * format, ...);

#ifdef __cplusplus
}
#endif

#endif /* NDEBUG */

#endif /* _XDEBUG_H_ */

