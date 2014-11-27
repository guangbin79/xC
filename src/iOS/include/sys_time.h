#ifndef _TR_SYS_TIME_H_
#define _TR_SYS_TIME_H_

typedef struct _SYS_tm
{
    short int year;
    char month;
    char day;
    char hour;
    char minute;
    char second;
} SYS_tm;

#ifdef __cplusplus
extern "C" {
#endif
    
    unsigned int sys_clock();
    void sys_time(SYS_tm * ptm);
    void sys_gmtime(SYS_tm * ptm, int t);
    void sys_localtime(SYS_tm * ptm, int t);
    
#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIME_H_ */
