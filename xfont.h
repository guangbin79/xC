/**
 * @file xfont.h
 * @brief 字体
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par 修改记录
 */

#ifndef _XFONT_H_
#define _XFONT_H_

#include "./xboolean.h"
#include "./xinteger.h"
#include "./xcharacter.h"

/**
 * @brief 字体结构体
 */
typedef struct _xfont xfont_t;

/**
 * @brief 字体风格结构体
 */
typedef enum _xfont_style {
    XFS_MAP_1,                              ///<  标准字体大小:地图最大字体36
    XFS_MAP_2,                              ///<  标准字体大小:
    XFS_MAP_3,                              ///<  标准字体大小:
    XFS_MAP_4,                              ///<  标准字体大小:
    XFS_MAP_5,                              ///<  标准字体大小:
    XFS_MAP_6,                              ///<  标准字体大小:
    XFS_MAP_7,                              ///<  标准字体大小:
    XFS_MAP_8,                              ///<  标准字体大小:
    XFS_MAP_9,                              ///<  标准字体大小:
    XFS_MAP_10                              ///<  标准字体大小:
} xfont_style_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 创建字体
 * @param - 无
 * @return - 字体结构体
 */
xfont_t * xfont_create();

/**
 * @brief 销毁字体
 * @param[in] font - 字体结构体
 * @return - 无
 */
void xfont_destroy(xfont_t * font);

/**
 * @brief 设置字体风格
 * @param[in] font - 字体结构体
 * @param[in] fontStyle - 字体风格
 * @return - 无
 */
void xfont_setStyle(xfont_t * font, xfont_style_t fontStyle);

/**
 * @brief 获取字体大小
 * @param[in] pft - 字体结构体
 * @return - 字体大小
 */
xuint16_t xfont_getFontSize(xfont_t * font);

/**
 * @brief 获取字体高度
 * @param[in] font - 字体结构体
 * @return - 字体高度
 */
xuint16_t xfont_getHeight(xfont_t * font);

/**
 * @brief 获取字符串宽度
 * @param[in] font - 字体结构体
 * @param[in] text - 目标字符串
 * @param[in] nChars - 目标字符串字串字符个数,如果为0或常超出字符串长度的数据,表示返回目标字符串全长
 * @param[in] nMaxWidth - 最大可用宽度(像素),如果为0,则表示宽度没有限制
 * @param[out] pnFits - 给定可用宽度的屏幕中可以容纳的字符数,该参数可以为空,空值表示不需要传出该值
 * @return - 可用空间中可以容纳的文本字符串总宽度(以像素为单位)
 */
xuint16_t xfont_measureText(xfont_t * font, const xwchar_t * text, xuint32_t nChars, xuint16_t nMaxWidth, xuint32_t * pnFits);

/**
 * @brief 准备绘图上下文
 * @param[in] font - 字体结构体
 * @param[in] image - 目标图片结构体
 * @return 无
*/
void xfont_drawBegin(xfont_t * font, void * pixels_argb, xuint16_t width, xuint16_t height);

/**
 * @brief 开始绘制文字
 * @param[in] font - 字体结构体
 * @param[in] x - 目标位置，左上角x坐标
 * @param[in] y - 目标位置，左上角y坐标
 * @param[in] text - 绘制字符串
 * @param[in] r,g,b - 绘制字体颜色
 * @return 无
*/
void xfont_drawText(xfont_t * font, xint16_t x, xint16_t y, const xwchar_t * text, xuint8_t r, xuint8_t g, xuint8_t b);

/**
 * @brief 释放绘图上下文
 * @param[in] font - 字体结构体
 * @return 无
*/
void xfont_drawEnd(xfont_t * font);

#ifdef __cplusplus
}
#endif

#endif /* _XFONT_H_ */

