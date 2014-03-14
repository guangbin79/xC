/**
 * xC
 * @file xdebug.h
 * @brief �������
 * @author yangxq <yangxq@tiros.com.cn>
 * @date 2014/03/13
 * @par �޸ļ�¼
 */

#ifndef _XDEBUG_H_
#define _XDEBUG_H_

#include "./xboolean.h"

#ifdef NDEBUG

#define XASSERT(exp)
#define XDBGPRINTF(format, ...)

#else

#define XASSERT(exp) xdebug_assert(exp)
#define XDBGPRINTF(format,...) xdebug_printf(format,...)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ���Ե�ʵ��
 * @param[in] exp - ����
 * @return - ��
 */
void xdbg_assert(xbool_t exp);

/**
 * @brief ������Ϣ�����ʵ��,����ú궨��dbgprintf,��Ҫֱ�ӵ���tr_dbgprintf
 * @param[in] format - ������Ϣ�����ʽ
 * @param[in] ... - �ɱ������
 * @return - ��
 */
void xdbg_printf(const char * format, ...);

#ifdef __cplusplus
}
#endif

#endif /* NDEBUG */

#endif /* _XDEBUG_H_ */

