#ifndef _TR_SYS_IMAGE_H_
#define _TR_SYS_IMAGE_H_

typedef struct _SYS_Image SYS_Image;

#ifdef __cplusplus
extern "C" {
#endif

SYS_Image * sys_ximgload(const void * pimgdata, unsigned int size);
SYS_Image * sys_ximgcreate(unsigned short int width, unsigned short int height);
void sys_ximgdestroy(SYS_Image * pimg);
unsigned short int sys_ximggetwidth(const SYS_Image * pimg);
unsigned short int sys_ximggetheight(const SYS_Image * pimg);
void * sys_ximglock(SYS_Image * pimg);
void sys_ximgunlock(SYS_Image * pimg, void * pvData);
void sys_ximgclearcolor(SYS_Image *pimg,unsigned char r, unsigned char g, unsigned char b, unsigned char a);
#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_IMAGE_H_ */

