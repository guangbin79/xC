/*
 * sys_memmove.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <string.h>

void * sys_xmemmove(void * dptr, const void * sptr, unsigned int size){
	return memmove(dptr, sptr, size);
}
