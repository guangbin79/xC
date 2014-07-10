/*
 * @file jni_image.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */


#ifndef JNI_IMAGE_H_
#define JNI_IMAGE_H_

#include <jni.h>

#include <string.h>
#include <android/log.h>
#include <android/bitmap.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define GL_PIXEL_SIZE 4

typedef struct _xsys_image_t
{
    jobject imgobject;
    void * buffer;
    uint16_t width, height;
}xsys_image_t;

#ifdef __cplusplus
extern "C" {
#endif
  
#ifdef __cplusplus
}

#endif
#endif /* JNI_IMAGE_H_ */
