/**
 * xC 
 * @file xvarargs.h
 * @brief 可变参数
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/06
 * @par 修改记录
 *
 */

#ifndef _XVARARGS_H_
#define _XVARARGS_H_

#include "./xinteger.h"
#include "./xpointer.h"


/*
 适用环境: 参数列表从右向左入栈, 且堆栈地址从高到低分配.
 通常情况下默认的ARM过程调用标准(APCS)应该符合, 如果出现问题, 请查看相关编译器选项, 选择对应的APCS标准.

 XVA_INTSIZEOF: 求n的大小是int的多少倍
 */

typedef xuint8_t * xva_list_t;

#define XVA_INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define XVA_START(ap, v) (ap = (xva_list_t)&v + XVA_INTSIZEOF(v))
#define XVA_ARG(ap, t)   (*(t *)((ap += XVA_INTSIZEOF(t)) - XVA_INTSIZEOF(t)))
#define XVA_END(ap)      (ap = XNULL)

#endif /* _XVARARGS_H_ */

