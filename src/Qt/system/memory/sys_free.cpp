#include "../../include/sys_xmemory.h"
#include <QtCore>

void sys_xfree(void * ptr)
{
    free(ptr);
}
