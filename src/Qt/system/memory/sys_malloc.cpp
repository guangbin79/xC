#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xmalloc(unsigned int size)
{
    return malloc(size);
}
