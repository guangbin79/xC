/**
 * xC
 * @file xglcontext.h
 * @brief xglcontext API
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/17
i*
 */

#ifndef _XGLCONTEXT_H_
#define _XGLCONTEXT_H_

#include "./xboolean.h"

typedef struct _xgl_context xgl_context_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 设定当前线程的绘图上下文
 * @param[in] context - 绘图上下文，传NULL则解除当前线程的绘图上下文
 * @return 是否成功设置
 */
xbool_t xglcontext_makeCurrent(xgl_context_t * context);

/**
 * @brief 交换缓冲区
 * @param - 无
 * @return - 无
 */
void xglcontext_swapBuffers(xgl_context_t * context);

#ifdef __cplusplus
}
#endif

#endif /* _XGLCONTEXT_H_ */



