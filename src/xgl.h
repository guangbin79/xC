/**
 * xC
 * @file xgl.h
 * @brief xgl API
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par 修改xgl_makeCurrentContext接口声明
 * 
 */

#ifndef _XGL_H_
#define _XGL_H_

#include "xboolean.h"

typedef struct _xgl_surface_t xgl_surface_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 准备绘图上下文
 * @return void
 */
void xgl_drawScreenBegin();
    
/**
 * @brief 结束绘图上下文
 * @return void
 */
void xgl_drawScreenEnd();

/**
 * @brief 准备绘图上下文
 * @param[in] surface - 绑定surface，不可以传NULL
 * @return 是否成功设置
 */
xbool_t xgl_makeCurrentContext(xgl_surface_t * surface);

#ifdef __cplusplus
}
#endif

#endif /* _XGL_H_ */



