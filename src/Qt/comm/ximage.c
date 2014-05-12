#include "../../../ximage.h"
#include "../include/sys_ximage.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

ximage_t * ximage_load(const void * pximgdata, xuint32_t size)
{
    xdebug_assert(pximgdata != XNULL && size != 0);

    return (ximage_t *)sys_ximgload(pximgdata, size);
}


ximage_t * ximage_create(xuint16_t width, xuint16_t height)
{
    return (ximage_t *)sys_ximgcreate(width, height);
}

void ximage_destroy(ximage_t * pximg)
{
    xdebug_assert(pximg != XNULL);

    return sys_ximgdestroy((SYS_Image *)pximg);
}

xuint16_t ximage_getWidth(ximage_t * pximg)
{
    xdebug_assert(pximg != XNULL);

    return (xuint16_t)sys_ximggetwidth((SYS_Image *)pximg);
}


xuint16_t ximage_getHeight(ximage_t * pximg)
{
    xdebug_assert(pximg != XNULL);

    return (xuint16_t)sys_ximggetheight((SYS_Image *)pximg);
}

void * ximage_lock(ximage_t * pximg)
{
    xdebug_assert(pximg != XNULL);
    return  sys_ximglock((SYS_Image *) pximg);
}


void ximage_unlock(ximage_t * pximg, void * pvData)
{
    xdebug_assert(pximg != XNULL && pvData != XNULL);
    sys_ximgunlock((SYS_Image *)pximg, pvData);
}

void ximage_clearColor(ximage_t * pximg, xuint8_t r, xuint8_t g, xuint8_t b, xuint8_t a)
{
    xdebug_assert(pximg != XNULL);
    sys_ximgclearcolor((SYS_Image *)pximg, r, g, b, a);
}
