/**
 * xC
 * @file xlongjmp.h
 * @brief 非本地跳转
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/14
 * @par 修改记录
 *
 */

#ifndef _XLONGJMP_H_
#define _XLONGJMP_H_

#include "./xinteger.h"


/**
 * @brief 用于保存恢复调用环境所需的信息
 */
typedef struct _xjmp_buf {
    int buf[66]; // 66 : 用于兼容各个系统的 jmp_buf 大小
} xjmp_buf_t[1];


/**
 * @brief 建立本地的xjmp_buf缓冲区并且初始化，用于将来跳转回此处
 * @param[in] env - 保存的程序调用环境
 * @return - 如果是从xlongjmp_set直接调用返回，xlongjmp_set返回值为0;如果val传递给xlongjmp_jump零值，xlongjmp_set的返回值为1；否则，xlongjmp_set的返回值为val
 */
xint32_t xlongjmp_set(xjmp_buf_t env);

/**
 * @brief 恢复env所指的缓冲区中的程序调用环境上下文，env所指缓冲区的内容是由xlongjump_set子程序调用所保存
 * @param[in] env - 恢复的程序的调用环境
 * @parma[in] val - xlongjmp_set返回值
 * @return - 无
 */
void xlongjmp_jump(xjmp_buf_t env, xint32_t val);

#endif /* _XLONGJMP_H_ */

