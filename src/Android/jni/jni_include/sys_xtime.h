/*
 * @file sys_xtime.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#ifndef _TR_SYS_TIME_H_
#define _TR_SYS_TIME_H_


#ifdef __cplusplus
extern "C" {
#endif


unsigned int  sys_xclock();
unsigned int  sys_xmkTime(const xdate_time_t * pdt);
void  sys_time(xdate_time_t * pdt);

void sys_xgmTime(xuint32_t t, xdate_time_t * pdt);
void sys_xlocalTime(xuint32_t t, xdate_time_t * pdt);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIME_H_ */
