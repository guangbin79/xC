/*
 * @file jni_xgl.h
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#ifndef _JNI_XGL_H_
#define _JNI_XGL_H_

typedef struct _sys_xglsurface
{
	jobject glsurfaceObject;
	void * display;
	void * draw;
	void * read;
	void * contest;
}sys_xglsurface;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIME_H_ */
