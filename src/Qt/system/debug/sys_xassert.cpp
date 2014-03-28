#include "../../include/sys_xdebug.h"
#include <QDebug>

void xsys_xdebug_assert(xchar_t exp)
{
    Q_ASSERT(exp);
    exp += 1; //这句话的作用是去除编译警告:unused
}

