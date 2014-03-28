#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xmemset(void * ptr, int c, unsigned int size)
{
    return memset(ptr, c, size);
}
