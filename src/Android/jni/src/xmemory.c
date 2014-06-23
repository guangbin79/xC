/*
 * @file xmemory.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xmemory.h"
#include "../../../xpointer.h"
#include "../../../xdebug.h"
#include "../jni_include/sys_xmemory.h"

void * xmemory_alloc(xsize_t size)
{
	xsys_xdebug_assert(size != 0);

    return sys_xmalloc(size);
}

void * xmemory_calloc(xsize_t nmemb, xsize_t size)
{
	xsys_xdebug_assert(nmemb != 0 && size != 0);

    return sys_xcalloc(nmemb, size);
}

void * xmemory_realloc(void * ptr, xsize_t size)
{
	xsys_xdebug_assert(ptr != XNULL && size != 0);

    return sys_xrealloc(ptr, size);
}

void xmemory_free(void * ptr)
{
	xsys_xdebug_assert(ptr != XNULL);

    return sys_xfree(ptr);
}

void * xmemory_copy(void * dptr, const void * sptr, xsize_t size)
{
	xsys_xdebug_assert(dptr != XNULL && sptr != XNULL && size != 0);

    return sys_xmemcpy(dptr, sptr, size);
}

void * xmemory_move(void * dptr, const void * sptr, xsize_t size)
{
	xsys_xdebug_assert(dptr != XNULL && sptr != XNULL && size != 0);

    return sys_xmemmove(dptr, sptr, size);
}

void * xmemory_set(void * ptr, int c, xsize_t size)
{
	xsys_xdebug_assert(ptr != XNULL && size != 0);

    return sys_xmemset(ptr, c, size);
}

xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count)
{
	xsys_xdebug_assert(buf1 != XNULL && buf2 != XNULL && count > 0);

    return sys_xmemcmp(buf1, buf2, count);
}

const void* xmemory_find(const void* ptr, xchar_t c, xuint32_t count)
{
    return sys_xmemchr(ptr, c, count);
}
