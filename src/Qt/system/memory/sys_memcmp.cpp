#include "../../include/sys_xmemory.h"
#include <QtCore>

int sys_xmemcmp(const void * buf1, const void * buf2, unsigned int count)
{
    return memcmp(buf1, buf2, count);
}
