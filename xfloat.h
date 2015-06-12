/**
 * xC
 * @file xfloat.h
 * @brief 浮点类型
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/06
 * @par 修改记录
 *
 */

#ifndef _XFLOAT_H_
#define _XFLOAT_H_

typedef float  xfloat_t;
typedef double xdouble_t;


    /* IEEE version: the following values are taken from the above ANSI draft.  */
    /* The ACORN FPE (v17) is known not to precisely implement IEEE arithmetic. */
#define XFLT_RADIX      2

    /* radix of exponent representation */
#define XFLT_ROUNDS     1
    /*
     * The rounding mode for floating-point addition is characterised by the
     * value of FLT_ROUNDS:
     *  -1 : indeterminable.
     *   0 : towards zero.
     *   1 : to nearest.
     *   2 : towards positive infinity.
     *   3 : towards negative infinity.
     *   ? : any other is implementation-defined.
     */


#define XFLT_MANT_DIG   24
#define XDBL_MANT_DIG   53
    /* number of base-FLT_RADIX digits in the floating point mantissa */

    /* The values that follow are not achieved under Acorn's FPE version 17  */
    /* but they should be correct in due course!                             */

#define XFLT_DIG        6
#define XDBL_DIG        15
    /* number of decimal digits of precision */

#define XFLT_MIN_EXP    -125
#define XDBL_MIN_EXP    -1021
    /* minimum negative integer such that FLT_RADIX raised to that power */
    /* minus 1 is a normalised floating-point number. */

#define XFLT_MIN_10_EXP -37
#define XDBL_MIN_10_EXP -307
    /* minimum negative integer such that 10 raised to that power is in the */
    /* range of normalised floating-point numbers. */

#define XFLT_MAX_EXP    128
#define XDBL_MAX_EXP    1024
    /* maximum integer such that FLT_RADIX raised to that power minus 1 is a */

#define XFLT_MAX_10_EXP 38
#define XDBL_MAX_10_EXP 308
    /* maximum integer such that 10 raised to that power is in the range of */
    /* representable finite floating-point numbers. */

#define XFLT_MAX        3.40282347e+38F
#define XDBL_MAX        1.79769313486231571e+308
    /* maximum representable finite floating-point number. */

#define XFLT_EPSILON    1.19209290e-7F
#define XDBL_EPSILON    2.2204460492503131e-16
    /* minimum positive floating point number x such that 1.0 + x != 1.0 */

#define XFLT_MIN        1.17549435e-38F
#define XDBL_MIN        2.22507385850720138e-308
    /* minimum normalised positive floating-point number. */

#define XHUGE_VAL       1.7976931348623157E+308

#endif /* _XFLOAT_H_ */

