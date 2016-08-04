#include "../../../xmemory.h"
#include "../include/sys_memory.h"
#include "../../../xdebug.h"

void * xmemory_alloc(xsize_t size)
{
//    assert(size != 0);

    return sys_malloc(size);
}

void * xmemory_calloc(xsize_t nmemb, xsize_t size)
{
//    assert(nmemb != 0 && size != 0);

    return sys_calloc(nmemb, size);
}

void * xmemory_realloc(void * ptr, xsize_t size)
{
    //assert(ptr != NULL && size != 0);

    return sys_realloc(ptr, size);
}

void xmemory_free(void * ptr)
{
//    assert(ptr != NULL);

    return sys_free(ptr);
}

void * xmemory_copy(void * dptr, const void * sptr, xsize_t size)
{
//    assert(dptr != NULL && sptr != NULL && size != 0);

    return sys_memcpy(dptr, sptr, size);
}

void * xmemory_move(void * dptr, const void * sptr, xsize_t size)
{
//    assert(dptr != NULL && sptr != NULL && size != 0);

    return sys_memmove(dptr, sptr, size);
}

void * xmemory_set(void * ptr, xuint8_t c, xuint32_t size)
{
//    assert(ptr != NULL && size != 0);

    return sys_memset(ptr, c, size);
}

xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count)
{
//    assert(buf1 != NULL && buf2 != NULL && count > 0);

    return sys_memcmp(buf1, buf2, count);
}

//const void* tr_memchr(const void* ptr, char c, xsize_t count)
//{
//    return sys_memchr(ptr, c, count);
//}
