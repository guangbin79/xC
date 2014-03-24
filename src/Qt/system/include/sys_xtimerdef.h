#ifndef _SYS_TIMERDEF_H_
#define _SYS_TIMERDEF_H_

#include "../../include/sys_xtimer.h"
#include <QTimer>

class QSYSTimer : public QTimer
{
    Q_OBJECT
public:
    SYS_PFNTIMEREVENT pfn;
    void * pvUser;
private slots:
    void TimeOut();
};

typedef struct _SYS_Timer
{
    QSYSTimer qtimer;
} SYS_Timer;

#endif /* SYS_TIMERDEF_H */
