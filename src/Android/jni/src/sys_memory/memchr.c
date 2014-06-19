/*
 * sys_memchr.c
 *
 *  Created on: 2011-11-23
 *      Author: shizy
 */
#include <string.h>


const void * sys_xmemchr(const void * ptr, char c, unsigned int count){
	return memchr(ptr, c, count);
}
