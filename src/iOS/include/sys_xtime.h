#ifndef _SYS_XTIME_H_
#define _SYS_XTIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../xinteger.h"
#include "../../../xcharacter.h"

typedef struct _xsys_tm
{
    xint16_t year;
    xchar_t month;
    xchar_t day;
    xchar_t hour;
    xchar_t minute;
    xchar_t second;
}xsys_tm_t;


xuint16_t xsys_xtime_clock();
void xsys_xtime_localTime(xsys_tm_t * ptm);
void xsys_xtime_utcTime(xsys_tm_t * ptm);
xint32_t xsys_xtime_utcToLocal();//获取UTC时间到本地时间的差，单位秒，如果本地时间大于UTC时间则为正值否则为负值。

#ifdef __cplusplus
}
#endif

#endif /* _SYS_XTIME_H_ */
