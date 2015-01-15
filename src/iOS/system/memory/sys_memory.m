/*
 *  sys_memory.mm
 *  sys_api
 *
 *  Created by caiyw on 14-12-2.
 *  Copyright 2014 navinfo. All rights reserved.
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

void * sys_memcpy(void * dptr, const void * sptr, unsigned int size)
{
	return memcpy(dptr,sptr,size);
}
void * sys_memmove(void * dptr, const void * sptr, unsigned int size)
{
	return memmove(dptr, sptr, size);
}
void * sys_memset(void * ptr, int c, unsigned int size)
{
	return memset(ptr, c, size);
}

int sys_memcmp(const void * buf1, const void * buf2, unsigned int count)
{
	return memcmp(buf1, buf2, count);
}
const void * sys_find(const void* ptr, char c, unsigned int count){
    return memchr(ptr, c, count);
}
