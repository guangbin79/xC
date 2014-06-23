/*
 * @file jni_font.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
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
