/*
 * @file realloc.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <malloc.h>


void * sys_xrealloc(void * ptr, unsigned int size){
	return realloc(ptr, size);
}
