#ifndef _SYS_XTIME_H_
#define _SYS_XTIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../xinteger.h"
#include "../../xcharacter.h"

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
void xsys_xtime_time(xsys_tm_t * ptm);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_XTIME_H_ */
