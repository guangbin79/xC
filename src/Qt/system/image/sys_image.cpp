#include "../../include/sys_ximage.h"
#include "../include/sys_ximagedef.h"
#include <QtGui/QImage>

SYS_Image * sys_ximgcreate(unsigned short int width, unsigned short int height)
{
    SYS_Image * pimage = new SYS_Image;

    if (NULL == pimage)
    {
        return NULL;
    }

    pimage->qimage = new QImage(width, height, QImage::Format_ARGB32);
    //pimage->qimage = new QImage(width, height, QImage::Format_RGB16);

    if (NULL == pimage->qimage)
    {
        delete pimage;

        return NULL;
    }

    pimage->qimage->fill(0);
    pimage->angle = 0;
    pimage->px = 0;
    pimage->py = 0;
    pimage->sx = 1;
    pimage->sy = 1;

    return pimage;
}

SYS_Image * sys_ximgload(const void * pimgdata, unsigned int size)
{
    SYS_Image * pimage = new SYS_Image;
    QImage img;
    if (NULL == pimage)
    {
        return NULL;
    }
    if (!img.loadFromData((const uchar *)pimgdata, size))
    {
        delete pimage;
        return NULL;
    }
    pimage->qimage = new QImage(img.convertToFormat(QImage::Format_ARGB32_Premultiplied/*Format_RGB16*/));//(w,h,uch,argb);
//    pimage->qimage = new QImage(img.convertToFormat(QImage::Format_ARGB32));//(w,h,uch,argb);

    if (NULL == pimage->qimage)
    {
        delete pimage;

        return NULL;
    }
    return pimage;
}

void sys_ximgdestroy( SYS_Image * pimg)
{
    delete pimg->qimage;
    delete pimg;
}

unsigned short int sys_ximggetheight(const  SYS_Image * pimg)
{
    return (unsigned short int)pimg->qimage->height();
}

unsigned short int sys_ximggetwidth(const  SYS_Image * pimg)
{
    return (unsigned short int)pimg->qimage->width();
}

void * sys_ximglock(SYS_Image * pimg)
{
    return pimg->qimage->bits();
}

void sys_ximgunlock(SYS_Image * pimg, void * pvData)
{
    uchar* pBits = pimg->qimage->bits();
    memcpy(pBits, pvData, pimg->qimage->width() * pimg->qimage->height() * 4);
}

void sys_ximgclearcolor(SYS_Image *pimg,unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    if (pimg)
        {
            int w = pimg->qimage->width();
            int h = pimg->qimage->height();
            if (a == 0.0)
                r = g = b = 0;
            uchar* pBytes = 0;
            for (int i=0; i < h; i++)
            {
                pBytes = pimg->qimage->scanLine(i);
                for (int j = 0; j < w; j++)
                {
                    pBytes[j*4] = b*255;
                    pBytes[j*4+1] = g*255;
                    pBytes[j*4+2] = r*255;
                    pBytes[j*4+3] = a*255;
                }
            }
        }
}




