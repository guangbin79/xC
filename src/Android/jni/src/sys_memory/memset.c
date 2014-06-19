/*
 * sys_memset.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <string.h>

void * sys_xmemset(void * ptr, int c, unsigned int size){
	return memset(ptr, c, size);
}
