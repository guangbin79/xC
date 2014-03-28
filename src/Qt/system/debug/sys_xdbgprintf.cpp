#include "../../include/sys_xdebug.h"
#include <QDebug>
#include <QString>

void xsys_xdebug_dbgPrintf(const char * format, void * ap)
{
    QTextStream out(stdout);
  //  out<< QString().vsprintf(format, ap);
}

