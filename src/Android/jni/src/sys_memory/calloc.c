/*
 * sys_calloc.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <malloc.h>


void * sys_xcalloc(unsigned int nmemb, unsigned int size){
	return calloc(nmemb, size);
}
