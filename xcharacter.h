/**
 * xC
 * @file xcharacter.h
 * @brief 字符类型
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/06
 * @par 修改记录
 *
 */

#ifndef _XCHARACTER_H_
#define _XCHARACTER_H_

#include "./xinteger.h"


typedef char       xchar_t;
typedef xint16_t   xwchar_t;


static const xuint8_t  XCHAR_MIN  = 0;
static const xuint16_t XWCHAR_MIN = 0;
static const xuint8_t  XCHAR_MAX  = 255;
static const xuint16_t XWCHAR_MAX = 65535;

#endif /* _XCHARACTER_H_ */

