/*
 *  sys_image.c
 *  My_System_api
 *
 *  Created by caoyp on 12-5-5.
 *  Modify by caoyp on 12-5-10.
 *  Modify by caoyp on 12-5-18.
 *  Modify by caoyp on 12-6-05.
 *  Modify by caoyp on 12-6-17.
 *  Modify by caoyp on 12-7-04.
 *  Copyright 2012 __MyCompanyName__TIROS. All rights reserved.
 *
 */

#include "../../jni_include/jni_image.h"
#include "../../jni_include/sys_ximage.h"
#include "../../jni_include/jni_system.h"
#include "../../../ximage.h"


unsigned short int sys_imggetheight(const xsys_image_t * image)
{
	return image->height;
}

