/*
 * @file xfont.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xfont.h"
#include "../jni_include/sys_xfont.h"
#include "../jni_include/jni_font.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

xfont_t * xfont_create()
{
    return (xfont_t *)sys_xftcreate();
}

void xfont_destroy(xfont_t * pft)
{
	xdebug_assert(pft != XNULL);

    sys_xftdestroy((xfont_t *)pft);
}

void xfont_setStyle(xfont_t * pft, xfont_style_t fst)
{
	xdebug_assert(pft != XNULL);

    sys_xftsetstyle((xfont_t *)pft, (xfont_style_t)fst);
}

xuint16_t xfont_getHeight(xfont_t * pft)
{
	xdebug_assert(pft != XNULL);

    return sys_xftgetheight((xfont_t *)pft);
}
xuint16_t xfont_measureText(xfont_t * pft, const xwchar_t * pwszText,
							xuint32_t nChars, xuint16_t nMaxWidth,xuint32_t * pnFits)
{
	xdebug_assert(pft != XNULL && pwszText != XNULL);

    return sys_xftmeasuretext((xfont_t *)pft, pwszText, nChars, nMaxWidth, pnFits);
}

xuint16_t xfont_getFontSize(xfont_t * pft)
{
	xdebug_assert(pft != XNULL);

    return sys_xftgetfontsize((xfont_t *)pft);
}
void xfont_drawBegin(xfont_t * font, ximage_t * image)
{
	xdebug_assert(font != XNULL && image != XNULL);
    sys_xftdrawbegin((xfont_t *)font, (ximage_t*)image);
}

void xfont_drawText(xfont_t * font, xint16_t x, xint16_t y, const xwchar_t * text,
					xuint8_t r, xuint8_t g, xuint8_t b)
{
	xdebug_assert(font != XNULL && text != XNULL);
    sys_xftdrawtext((xfont_t *)font, x, y, text, r, g, b);
}

void xfont_drawEnd(xfont_t * pft)
{
	xdebug_assert(pft != XNULL);
    sys_xftdrawend((xfont_t *)pft);
}










