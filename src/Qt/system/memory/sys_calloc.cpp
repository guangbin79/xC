#include "../../include/sys_xmemory.h"
#include <QtCore>

void * sys_xcalloc(unsigned int nmemb, unsigned int size)
{
    return calloc(nmemb, size);
}
