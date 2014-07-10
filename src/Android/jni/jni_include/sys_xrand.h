/*
 * @file sys_xrand.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_RAND_H_
#define _TR_SYS_RAND_H_

#ifdef __cplusplus
extern "C" {
#endif

void sys_srand(unsigned int seed);
int sys_rand();

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_RAND_H_ */

