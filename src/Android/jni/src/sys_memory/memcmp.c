/*
 * sys_memcmp.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <string.h>


int sys_xmemcmp(const void * buf1, const void * buf2, unsigned int count){
	return memcmp(buf1, buf2, count);
}
