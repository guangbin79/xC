#include "../../../xmemory.h"
#include "../include/sys_memory.h"
#include "../../../xdebug.h"

void * xmemory_alloc(xsize_t size)
{
    return sys_malloc(size);
}

void * xmemory_calloc(xsize_t nmemb, xsize_t size)
{
    return sys_calloc(nmemb, size);
}

void * xmemory_realloc(void * ptr, xsize_t size)
{
    return sys_realloc(ptr, size);
}

void xmemory_free(void * ptr)
{
    return sys_free(ptr);
}

void * xmemory_copy(void * dptr, const void * sptr, xsize_t size)
{
    return sys_memcpy(dptr, sptr, size);
}

void * xmemory_move(void * dptr, const void * sptr, xsize_t size)
{
    return sys_memmove(dptr, sptr, size);
}

void * xmemory_set(void * ptr, xint32_t c, xuint32_t count)
{
    return sys_memset(ptr, c, count);
}

xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count)
{
    return sys_memcmp(buf1, buf2, count);
}

const void * xmemory_find(const void * ptr, xchar_t c, xuint32_t count)
{
    return sys_find(ptr, c, count);
}
