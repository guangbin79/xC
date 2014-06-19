/*
 * sys_free.c
 *
 *  Created on: 2011-10-14
 *      Author: shizy
 */
#include <malloc.h>


void sys_xfree(void * ptr){
	if(ptr){
		free(ptr);
	}
}
