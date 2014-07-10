/*
 * @file memcmp.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <string.h>


int sys_xmemcmp(const void * buf1, const void * buf2, unsigned int count){
	return memcmp(buf1, buf2, count);
}
