/*
 * @file memmove.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <string.h>

void * sys_xmemmove(void * dptr, const void * sptr, unsigned int size){
	return memmove(dptr, sptr, size);
}
