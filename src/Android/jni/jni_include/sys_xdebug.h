/*
 * @file sys_xdebug.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_DEBUG_H_
#define _TR_SYS_DEBUG_H_
#ifdef __cplusplus
extern "C" {
#endif

void xsys_xdebug_assert(unsigned char exp);
void xsys_xdebug_dbgPrintf(const char * format, void *  ap);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_DEBUG_H_ */
