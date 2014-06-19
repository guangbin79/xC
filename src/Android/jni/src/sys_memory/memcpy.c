/*
 * sys_memcpy.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <string.h>

void * sys_xmemcpy(void * dptr, const void * sptr, unsigned int size){
	return memcpy(dptr, sptr, size);
}
