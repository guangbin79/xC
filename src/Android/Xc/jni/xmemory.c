#include "../../../../xmemory.h"
#include <stdlib.h>

void * xmemory_alloc(xsize_t size) {
    return malloc(size);
}

void * xmemory_calloc(xsize_t nmemb, xsize_t size) {
    return calloc(nmemb, size);
    
}
 
void * xmemory_realloc(void * ptr, xsize_t size) {
    if (ptr)
        return realloc(ptr, size);
    return malloc(size);
}

void xmemory_free(void * ptr) {
    free(ptr);
}

void * xmemory_copy(void * dptr, const void * sptr, xsize_t size) {
    return memcpy(dptr, sptr, size);
}

void * xmemory_move(void * dptr, const void * sptr, xsize_t size) {
    return memmove(dptr, sptr, size);
}

void * xmemory_set(void * ptr, xuint8_t c, xuint32_t count) {
    return memset(ptr, c, count);
}

xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count) {
    return memcmp(buf1, buf2, count);
}

const void * xmemory_find(const void * ptr, xchar_t c, xuint32_t count) {
    return memchr(ptr, c, count);
}

