/**
 * xC 
 * @file xpointer.h
 * @brief 指针类型
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/06
 * @par 修改记录
 * 
 */

#ifndef _XPOINTER_H_
#define _XPOINTER_H_

#include "./xinteger.h"


#define XNULL 0
#define XOFFSETOF(type, member) ((size_xt)((uint8_xt *)&(((type *)0)->member) - (uint8_xt *)0))

#endif /* _XPOINTER_H_ */

