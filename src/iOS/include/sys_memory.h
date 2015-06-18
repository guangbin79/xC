#ifndef _TR_SYS_MEMORY_H_
#define _TR_SYS_MEMORY_H_

#include "../../../xinteger.h"

#ifdef __cplusplus
extern "C" {
#endif

void * sys_malloc(unsigned int size);
void * sys_calloc(unsigned int nmemb, unsigned int size);
void * sys_realloc(void * ptr, unsigned int size);
void sys_free(void * ptr);

void * sys_memcpy(void * dptr, const void * sptr, xsize_t size);
void * sys_memmove(void * dptr, const void * sptr, xsize_t size);
void * sys_memset(void * ptr, int c, xsize_t size);
int sys_memcmp(const void * buf1, const void * buf2, xsize_t count);
const void* sys_memchr(const void* ptr, char c, xsize_t count);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_MEMORY_H_ */
