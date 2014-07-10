/*
 * @file sys_xtimer.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_TIMER_H_
#define _TR_SYS_TIMER_H_

#include "../../../xtimer.h"

typedef struct _xsys_timer_t xsys_timer_t;


#ifdef __cplusplus
extern "C" {
#endif

xsys_timer_t * sys_tmrcreate();
void sys_tmrdestroy(xsys_timer_t * ptmr);
void sys_tmrstart(xsys_timer_t * ptmr, unsigned int dwMSecs, xfn_timer_event_t pfn, void * pvUser);
unsigned char sys_tmrisbusy(xsys_timer_t * ptmr);
void sys_tmrcancel(xsys_timer_t * ptmr);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIMER_H_ */
