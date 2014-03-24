#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xmemmove(void * dptr, const void * sptr, unsigned int size)
{
    return memmove(dptr, sptr, size);
}
