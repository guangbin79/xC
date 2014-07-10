/*
 * @file imggetheight.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"


unsigned short int sys_imggetheight(const xsys_image_t * image)
{
	return image->height;
}

