/*
 * @file ximage.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../ximage.h"
#include "../jni_include/sys_ximage.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

ximage_t * ximg_load(const void * pimgdata, uint32_t size)
{
	xdebug_assert(pimgdata != NULL && size != 0);

    return (ximage_t *)sys_imgload(pimgdata, size);
}

ximage_t * ximg_create(uint16_t width, uint16_t height)
{
    return (ximage_t *)sys_imgcreate(width, height);
}

void ximg_destroy(ximage_t * pimg)
{
	xdebug_assert(pimg != NULL);

    return sys_imgdestroy((xsys_image_t *)pimg);
}

uint16_t ximg_getwidth(ximage_t * pimg)
{
	xdebug_assert(pimg != NULL);

    return (uint16_t)sys_imggetwidth((xsys_image_t *)pimg);
}

uint16_t  ximg_getheight(ximage_t * pimg)
{
	xdebug_assert(pimg != NULL);

    return (uint16_t)sys_imggetheight((xsys_image_t *)pimg);
}

void * ximg_lock(ximage_t * pimg)
{
	xdebug_assert(pimg != NULL);

    return sys_imglock((xsys_image_t *)pimg);
}

void ximg_unlock(ximage_t * pimg, void * pvData)
{
	xdebug_assert(pimg != NULL && pvData != NULL);
    sys_imgunlock((xsys_image_t *)pimg, pvData);
}

void ximg_clearcolor(ximage_t *pimg,uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	xdebug_assert(pimg != NULL);
    sys_imgclearcolor((xsys_image_t *)pimg, r, g, b, a);
}
