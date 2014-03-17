/**
 * xC
 * @file xgl.h
 * @brief xgl API
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par 修改记录
 * 
 */

#ifndef _XGL_H_
#define _XGL_H_

#include "xboolean.h"

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
 * @param[in] bBind - 是否将当前线程设置为渲染线程
 * @return 是否成功设置
 */
xbool_t xgl_makeCurrentContext(xbool_t bBind);

#ifdef __cplusplus
}
#endif

#endif /* _XGL_H_ */



