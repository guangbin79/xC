/*
 * sys_malloc.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <malloc.h>


void * sys_xmalloc(unsigned int size){
	return malloc(size);
}
