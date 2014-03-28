#include "../../include/sys_xtime.h"
#include <QDateTime>

void xsys_xtime_time(xsys_tm_t * sys_time)
{
    QDateTime dt = QDateTime::currentDateTimeUtc();

    sys_time->year = dt.date().year();
    sys_time->month = dt.date().month();
    sys_time->day = dt.date().day();
    sys_time->hour = dt.time().hour();
    sys_time->minute = dt.time().minute();
    sys_time->second = dt.time().second();
}
