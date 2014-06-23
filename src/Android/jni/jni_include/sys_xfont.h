/*
 * @file sys_xfont.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_FONT_H_
#define _TR_SYS_FONT_H_

#include "../../../../xfont.h"


typedef enum _SYS_FontStyle
{
    SYS_FS_MAP_1 = 100,
    SYS_FS_MAP_2,
    SYS_FS_MAP_3,
    SYS_FS_MAP_4,
    SYS_FS_MAP_5,
    SYS_FS_MAP_6,
    SYS_FS_MAP_7,
    SYS_FS_MAP_8,
    SYS_FS_MAP_9,
    SYS_FS_MAP_10
} SYS_FontStyle;

#ifdef __cplusplus
extern "C" {
#endif

xfont_t * sys_xftcreate();
void sys_ftdestroy(xfont_t * pft);
void sys_ftsetstyle(xfont_t * pft, xfont_style_t fst);
unsigned short int sys_ftgetfontsize(xfont_t * pft);
unsigned short int sys_ftgetheight(xfont_t * pft);
unsigned short int sys_ftmeasuretext(xfont_t * pft, const unsigned short int * pwszText, unsigned int nChars, unsigned short int nMaxWidth, unsigned int * pnFits);
void sys_ftdrawbegin(xfont_t * pft, ximage_t* pimg);
void sys_ftdrawtext(xfont_t * pft, short int x, short int y, const unsigned short int * pwszText, unsigned char r, unsigned char g, unsigned char b);
void sys_ftdrawend(xfont_t* pft);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_FONT_H_ */

