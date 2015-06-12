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

#if defined __x86_64__
// todo: arm_64, e.g.:iphone_5s
typedef xuint64_t           xsize_t;
typedef xint64_t            xptrdiff_t;
typedef xint64_t            xintptr_t;
typedef xuint64_t           xuintptr_t;
#else
typedef xuint32_t           xsize_t;
typedef xint32_t            xptrdiff_t;
typedef xint32_t            xintptr_t;
typedef xuint32_t           xuintptr_t;
#endif


#define XINT8_MIN   -128
#define XINT16_MIN  -32768
#define XINT32_MIN  ~0x7fffffffL

#if defined _MSC_VER && _MSC_VER == 1200
#define XINT64_MIN  ~0x7fffffffffffffff
#else
#define XINT64_MIN  ~0x7fffffffffffffffLL
#endif

#define XINT8_MAX   127
#define XINT16_MAX  32767
#define XINT32_MAX  0x7fffffffL

#if defined _MSC_VER && _MSC_VER == 1200
#define XINT64_MAX  0x7fffffffffffffff
#else
#define XINT64_MAX  0x7fffffffffffffffLL
#endif

#define XUINT8_MAX  255
#define XUINT16_MAX 65535
#define XUINT32_MAX 0xffffffffUL

#if defined _MSC_VER && _MSC_VER == 1200
#define XUINT64_MAX 0xffffffffffffffff
#else
#define XUINT64_MAX 0xffffffffffffffffULL
#endif

#endif /* _XINTEGER_H_ */

