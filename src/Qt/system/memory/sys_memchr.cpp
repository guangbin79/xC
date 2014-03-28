#include "../../include/sys_xmemory.h"
#include <QtCore>

const void* sys_xmemchr(const void* ptr, char c, unsigned int count)
{
    return memchr(ptr, c, count);
}
