/*
 * @file sys_xmemory.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_MEMORY_H_
#define _TR_SYS_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

void * sys_xmalloc(unsigned int size);
void * sys_xcalloc(unsigned int nmemb, unsigned int size);
void * sys_xrealloc(void * ptr, unsigned int size);
void sys_xfree(void * ptr);

void * sys_xmemcpy(void * dptr, const void * sptr, unsigned int size);
void * sys_xmemmove(void * dptr, const void * sptr, unsigned int size);
void * sys_xmemset(void * ptr, int c, unsigned int size);
int sys_xmemcmp(const void * buf1, const void * buf2, unsigned int count);
const void* sys_xmemchr(const void* ptr, char c, unsigned int count);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_MEMORY_H_ */
