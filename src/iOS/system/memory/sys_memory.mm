/*
 *  sys_memory.mm
 *  My_System_api
 *
 *  Created by feifei on 11-9-26.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "../../include/sys_memory.h"

void * sys_malloc(unsigned int size)
{
    void* p = malloc(size);
	return p;
}

void * sys_calloc(unsigned int nmemb, unsigned int size)
{
	return calloc(nmemb,size);
}
void * sys_realloc(void * ptr, unsigned int size)
{
	return realloc(ptr, size);
}
void sys_free(void * ptr)
{
	if (ptr) {
		free(ptr);
	}
}

void * sys_memcpy(void * dptr, const void * sptr, size_t size)
{
	return memcpy(dptr,sptr,size);
}
void * sys_memmove(void * dptr, const void * sptr, size_t size)
{
	return memmove(dptr, sptr, size);
}
void * sys_memset(void * ptr, int c, size_t size)
{
	return memset(ptr, c, size);
}

int sys_memcmp(const void * buf1, const void * buf2, size_t count)
{
	return memcmp(buf1, buf2, count);
}
const void* sys_memchr(const void* ptr, char c, size_t count){
    return memchr(ptr,c,count);
}
