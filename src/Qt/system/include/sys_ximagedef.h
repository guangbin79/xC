#ifndef _SYS_IMAGEDEF_H_
#define _SYS_IMAGEDEF_H_

#include <QImage>

typedef struct _SYS_Image
{
    QImage * qimage;
    float sx;
    float sy;
    float angle;
    float px;
    float py;
} SYS_Image;


#ifdef __cplusplus
extern "C" {
#endif

void ReleaseScreenImage();
SYS_Image* getScreenImage();


#ifdef __cplusplus
}
#endif

#endif // _SYS_IMAGEDEF_H_
