/*
 * sys_realloc.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <malloc.h>


void * sys_xrealloc(void * ptr, unsigned int size){
	return realloc(ptr, size);
}
