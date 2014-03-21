#include "../../include/sys_xtime.h"
#include <QTime>

xuint16_t xsys_xtime_clock()
{
    QTime qtime = QTime::currentTime();
    xuint16_t qclock = 0;

    qclock = (((((qtime.hour() * 60) + qtime.minute()) * 60) + qtime.second()) * 1000) + qtime.msec();

    return qclock;
}
