/*
 * @file calloc.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <malloc.h>


void * sys_xcalloc(unsigned int nmemb, unsigned int size){
	return calloc(nmemb, size);
}
