/*
 * @file jni_system.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */

#ifndef JNI_SYSTEM_H_
#define JNI_SYSTEM_H_

#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern JavaVM * jvm;
extern jobject sensorobject;

extern JNIEnv * g_env;

#ifdef __cplusplus
extern "C" {
#endif

char * jstringTochar(JNIEnv *, jstring jstr);
unsigned short * jstringTowchar(JNIEnv *, jstring jstr);
unsigned int jni_wcslen(const unsigned short * str);
unsigned short * jni_wcsncpy(unsigned short * dst0, const unsigned short * src0, unsigned int count);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_JNI_H_ */
