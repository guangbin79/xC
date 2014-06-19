/*
 * jni_font.h
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 *  Modify caoyp on: 2012-5-28
 */

#ifndef JNI_FONT_H_
#define JNI_FONT_H_

#include <jni.h>
#include <time.h>
#include <android/log.h>
#include <string.h>
#include "../../../../xfont.h"

struct _xfont_t
{
	jobject  fontObject;
	xfont_style_t style;
	void * pcolors;
    void * ptr; //保存像素数组地址
	unsigned short int width;
	unsigned short int height;
};

#endif /* JNI_FONT_H_ */
