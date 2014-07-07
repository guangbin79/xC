#include <QFont>
#include <QPainter>
#include <QImage>
#include "../include/sys_ximage.h"
#include "../system/include/sys_ximagedef.h"
#include "../../../xfont.h"

struct _xfont {
    QFont qfont;
    SYS_Image * image;
    void * argb;
    uint16_t width, height;
    QImage* qimage;
    QPainter qpainter;
};

xfont_t * xfont_create()
{
    xfont_t * pFont = new xfont_t;
    pFont->qimage = 0;
    return pFont;
}

void xfont_destroy(xfont_t * font)
{
    delete font;
}

void xfont_setStyle(xfont_t * font, xfont_style_t fontStyle)
{
    switch (fontStyle)
    {
    case XFS_MAP_1:
        font->qfont.setPixelSize(30);
        break;
    case XFS_MAP_2:
        font->qfont.setPixelSize(20);
        break;
    case XFS_MAP_3:
        font->qfont.setPixelSize(18);
        break;
    case XFS_MAP_4:
        font->qfont.setPixelSize(16);
        break;
    case XFS_MAP_5:
        font->qfont.setPixelSize(15);
        break;
    case XFS_MAP_6:
        font->qfont.setPixelSize(14);
        break;
    case XFS_MAP_7:
        font->qfont.setPixelSize(13);
        break;
    case XFS_MAP_8:
        font->qfont.setPixelSize(12);
        break;
    case XFS_MAP_9:
        font->qfont.setPixelSize(11);
        break;
    case XFS_MAP_10:
        font->qfont.setPixelSize(10);
        break;
    default:
        font->qfont.setPixelSize(14);
    }
}

xuint16_t xfont_getFontSize(xfont_t * font)
{
    return (unsigned short int)font->qfont.pixelSize();
}

xuint16_t xfont_getHeight(xfont_t * font)
{
    QFontMetrics qMetrics(font->qfont);

    return (unsigned short int)qMetrics.height();
}

xuint16_t xfont_measureText(xfont_t * font, const xwchar_t * text, xuint32_t nChars, xuint16_t nMaxWidth, xuint32_t * pnFits)
{
    QFontMetrics qMetrics(font->qfont);
    QString str;

    if ((unsigned int)str.size() > nChars && 0 != nChars)
    {
        str = QString::fromUtf16((const ushort *)text).left(nChars);
    }
    else
    {
         str = QString::fromUtf16((const ushort *)text);
    }

    if (0 == nMaxWidth)
    {
        if (pnFits)
               *pnFits = str.length();
        return (unsigned short int)qMetrics.width(str);
    }

    int i = 0;
    unsigned short int width, sum = 0;

    while (i < str.length())
    {
        width = (unsigned short int)qMetrics.width(str[i++]);

        if (nMaxWidth >= width)
        {
            nMaxWidth -= width;
            sum += width;
        }
        else
        {
            break;
        }
    }
    if (pnFits != NULL)
    {
        *pnFits = i;
    }

    return sum;
}

void xfont_drawBegin(xfont_t * font, void * pixels_argb, xuint16_t width, xuint16_t height)
{
    font->argb = pixels_argb;
    font->width = width;
    font->height = height;

    font->image = sys_ximgcreate(width, height);

    void * pdata = sys_ximglock(font->image);
    memcpy(pdata, font->argb, 4 * font->width * font->height);
    sys_ximgunlock(font->image, pdata);

    font->qpainter.begin(((SYS_Image *)font->image)->qimage);
}

void xfont_drawText(xfont_t * font, xint16_t x, xint16_t y, const xwchar_t * text, xuint8_t r, xuint8_t g, xuint8_t b)
{
    QString str;
    font->qpainter.setFont(font->qfont);
    font->qpainter.setPen(QColor(r, g, b, 255));
    str = QString::fromUtf16((const ushort *)text);
    font->qpainter.drawText(x, y + font->qpainter.fontMetrics().ascent(), str);
}

void xfont_drawEnd(xfont_t * font)
{
    font->qpainter.end();

    void * pdata = sys_ximglock(font->image);
    memcpy(font->argb, pdata, 4 * font->width * font->height);
    sys_ximgunlock(font->image, pdata);

    sys_ximgdestroy(font->image);
}
