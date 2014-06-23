/*
 * @file sys_ximage.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _TR_SYS_IMAGE_H_
#define _TR_SYS_IMAGE_H_
#include "../../../../ximage.h"
#include "jni_image.h"

#ifdef __cplusplus
extern "C" {
#endif

xsys_image_t * sys_imgload(const void * pimgdata, unsigned int size);
xsys_image_t * sys_imgcreate(unsigned short int width, unsigned short int height);
void sys_imgdestroy(xsys_image_t * pimg);
unsigned short int sys_imggetwidth(const xsys_image_t * pimg);
unsigned short int sys_imggetheight(const xsys_image_t * pimg);
void * sys_imglock(xsys_image_t * pimg);
void sys_imgunlock(xsys_image_t * pimg, void * pvData);
void sys_imgclearcolor(xsys_image_t *pimg,unsigned char r, unsigned char g, unsigned char b, unsigned char a);
#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_IMAGE_H_ */

