#include "../../xmemory.h"
#include "../include/sys_xmemory.h"
#include "../../xdebug.h"

void * xmemory_alloc(xsize_t size)
{
//    assert(size != 0);

    return sys_xmalloc(size);
}

void * xmemory_calloc(xsize_t nmemb, xsize_t size)
{
//    assert(nmemb != 0 && size != 0);

    return sys_xcalloc(nmemb, size);
}

void * xmemory_realloc(void * ptr, xsize_t size)
{
    //assert(ptr != NULL && size != 0);

    return sys_xrealloc(ptr, size);
}

void xmemory_free(void * ptr)
{
//    assert(ptr != NULL);

    return sys_xfree(ptr);
}

void * xmemory_copy(void * dptr, const void * sptr, xsize_t size)
{
//    assert(dptr != NULL && sptr != NULL && size != 0);

    return sys_xmemcpy(dptr, sptr, size);
}

void * xmemory_move(void * dptr, const void * sptr, xsize_t size)
{
//    assert(dptr != NULL && sptr != NULL && size != 0);

    return sys_xmemmove(dptr, sptr, size);
}

void * xmemory_set(void * ptr, int c, xsize_t size)
{
//    assert(ptr != NULL && size != 0);

    return sys_xmemset(ptr, c, size);
}

xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count)
{
//    assert(buf1 != NULL && buf2 != NULL && count > 0);

    return sys_xmemcmp(buf1, buf2, count);
}

const void* xmemory_find(const void* ptr, xchar_t c, xuint32_t count)
{
    return sys_xmemchr(ptr, c, count);
}
