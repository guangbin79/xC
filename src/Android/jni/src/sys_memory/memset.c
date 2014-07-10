/*
 * @file memset.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <string.h>

void * sys_xmemset(void * ptr, int c, unsigned int size){
	return memset(ptr, c, size);
}
