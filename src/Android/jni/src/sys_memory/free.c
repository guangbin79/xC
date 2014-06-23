/*
 * @file free.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <malloc.h>


void sys_xfree(void * ptr){
	if(ptr){
		free(ptr);
	}
}
