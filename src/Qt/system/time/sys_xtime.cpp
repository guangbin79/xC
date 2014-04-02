#include "../../include/sys_xtime.h"
#include <QDateTime>

void xsys_xtime_localTime(xsys_tm_t * sys_time)
{
    QDateTime dt = QDateTime::currentDateTime();

    sys_time->year = dt.date().year();
    sys_time->month = dt.date().month();
    sys_time->day = dt.date().day();
    sys_time->hour = dt.time().hour();
    sys_time->minute = dt.time().minute();
    sys_time->second = dt.time().second();
}

void xsys_xtime_utcTime(xsys_tm_t * sys_time)
{
    QDateTime dt = QDateTime::currentDateTimeUtc();

    sys_time->year = dt.date().year();
    sys_time->month = dt.date().month();
    sys_time->day = dt.date().day();
    sys_time->hour = dt.time().hour();
    sys_time->minute = dt.time().minute();
    sys_time->second = dt.time().second();
}

xint32_t xsys_xtime_utcToLocal()
{
    QDateTime dLocal = QDateTime::currentDateTime();
    QDateTime dUTC = QDateTime::currentDateTimeUtc();

    return dUTC.secsTo(dLocal);
}
