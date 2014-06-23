/*
 * @file xrand.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xrand.h"
#include "../jni_include/sys_xrand.h"

void xrand_srand(xuint32_t seed)
{
    sys_srand(seed);
}

xint32_t xrand_rand()
{
	return sys_rand();
}
