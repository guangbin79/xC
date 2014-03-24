#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xmemcpy(void * dptr, const void * sptr, unsigned int size)
{
    return memcpy(dptr, sptr, size);
}
