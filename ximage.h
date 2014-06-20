/**
 * xC
 * @file ximage.h
 * @brief 图片
 * @author guangbin <baigb@tiros.com.cn>
 * @date 2014/03/14
 * @par 修改记录
 *
 */

#ifndef _XIMAGE_H_
#define _XIMAGE_H_

#include "./xinteger.h"
#include "./xboolean.h"

/**
 * @par ******** 注意 ******** <br>
 * 图片格式尽可能采用PNG <br>
 */

/**
 * @brief 图片结构体
 */
typedef struct _ximage ximage_t;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 通过指定数据生成图片
 * @param[in] pximgdata - 图片数据
 * @param[in] size - 图片数据大小
 * @return - 如果成功返回Image,否则返回XNULL
 */
ximage_t * ximage_load(const void * pximgdata, xuint32_t size);

/**
 * @brief 建立指定大小的图片
 * @param[in] width - 宽
 * @param[in] height - 高
 * @return - 如果成功返回Image,否则返回XNULL
 * @par 接口使用约定:
 *      1.生成的图片未初始化,直接显示结果不能确定 <br>
 */
ximage_t * ximage_create(xuint16_t width, xuint16_t height);

/**
 * @brief 销毁图片
 * @param[in] pximg - 图片结构体指针
 * @return - 无
 */
void ximage_destroy(ximage_t * pximg);

/**
 * @brief 获取图片的宽度
 * @param[in] pximg - 图片结构体指针
 * @return - 图片宽度
 */
xuint16_t ximage_getWidth(ximage_t * pximg);

/**
 * @brief 获取图片的高度
 * @param[in] pximg - 图片结构体指针
 * @return - 图片高度
 */
xuint16_t ximage_getHeight(ximage_t * pximg);

/**
 * @brief 获取实际图片像素区域颜色数据至指定数据地址
 * @param[in] pximg - 图片结构体指针
 * @return -获取成功:接收该图片数据地址,失败：XNULL
 */
void * ximage_lock(ximage_t * pximg);

/**
 * @brief设置像素区域颜色
 * @param[in] pximg      - 图片结构体指针
 * @param[in] pvData    - 图片像素数组地址
 * @return -无
 */
void ximage_unlock(ximage_t * pximg, void * pvData);

/**
 * @brief使用指定颜色清除图片像素区域
 * @param[in] pximg      - 图片结构体指针
 * @param[in] r,g,b,a   - 清除颜色值(0-255)
 * @return -无
 */
void ximage_clearColor(ximage_t * pximg, xuint8_t r, xuint8_t g, xuint8_t b, xuint8_t a);

#ifdef __cplusplus
}
#endif

#endif /* _XIMAGE_H_ */

