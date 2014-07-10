/*
 * @file memcpy.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <string.h>

void * sys_xmemcpy(void * dptr, const void * sptr, unsigned int size){
	return memcpy(dptr, sptr, size);
}
