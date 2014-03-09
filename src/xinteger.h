/**
 * xC
 * @file xinteger.h
 * @brief 整数类型
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/06
 * @par 修改记录
 * 
 */

#ifndef _XINTEGER_H_
#define _XINTEGER_H_

typedef signed char         xint8_t;
typedef signed short int    xint16_t;
typedef signed int          xint32_t;

#if defined _MSC_VER && _MSC_VER == 1200 
typedef signed __int64      xint64_t;
#else
typedef signed long long    xint64_t;
#endif

typedef unsigned char       xuint8_t;
typedef unsigned short int  xuint16_t;
typedef unsigned int        xuint32_t;

#if defined _MSC_VER && _MSC_VER == 1200 
typedef unsigned __int64    xuint64_t;
#else
typedef unsigned long long  xuint64_t;
#endif


static const xint8_t   XINT8_MIN   = -128;
static const xint16_t  XINT16_MIN  = -32768;
static const xint32_t  XINT32_MIN  = ~0x7fffffffL;

#if defined _MSC_VER && _MSC_VER == 1200 
static const xint64_t  XINT64_MIN  = ~0x7fffffffffffffff;
#else
static const xint64_t  XINT64_MIN  = ~0x7fffffffffffffffLL;
#endif

static const xint8_t   XINT8_MAX   = 127;
static const xint16_t  XINT16_MAX  = 32767;
static const xint32_t  XINT32_MAX  = 0x7fffffffL;

#if defined _MSC_VER && _MSC_VER == 1200 
static const xint64_t  XINT64_MAX  = 0x7fffffffffffffff;
#else
static const xint64_t  XINT64_MAX  = 0x7fffffffffffffffLL;
#endif

static const uxint8_t  XUINT8_MAX  = 255;
static const uxint16_t XUINT16_MAX = 65535;
static const uxint32_t XUINT32_MAX = 0xffffffffUL;

#if defined _MSC_VER && _MSC_VER == 1200 
static const uxint64_t XUINT64_MAX = 0xffffffffffffffff;
#else
static const uxint64_t XUINT64_MAX = 0xffffffffffffffffULL;
#endif

#endif /* _XINTEGER_H_ */

