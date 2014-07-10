/*
 * @file memchr.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include <string.h>


const void * sys_xmemchr(const void * ptr, char c, unsigned int count){
	return memchr(ptr, c, count);
}
