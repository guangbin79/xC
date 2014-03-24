#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xrealloc(void * ptr, unsigned int size)
{
    if (ptr)
        return realloc(ptr, size);
    return malloc(size);
}
