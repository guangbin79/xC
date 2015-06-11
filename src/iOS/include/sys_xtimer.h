#ifndef _TR_SYS_TIMER_H_
#define _TR_SYS_TIMER_H_

typedef struct _SYS_Timer SYS_Timer;

typedef void (*SYS_PFNTIMEREVENT)(void * pvUser);

#ifdef __cplusplus
extern "C" {
#endif

SYS_Timer * sys_xtmrcreate();
void sys_xtmrdestroy(SYS_Timer * ptmr);
void sys_xtmrstart(SYS_Timer * ptmr, unsigned int dwMSecs, SYS_PFNTIMEREVENT pfn, void * pvUser);
unsigned char sys_xtmrisbusy(SYS_Timer * ptmr);
void sys_xtmrcancel(SYS_Timer * ptmr);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIMER_H_ */
