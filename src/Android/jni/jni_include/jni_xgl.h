#ifndef _JNI_XGL_H_
#define _JNI_XGL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _xsys_xglsurface
{
	jobject glsurfaceObject;
	void * display;
	void * draw;
	void * read;
	void * contest;
}xsys_xglsurface;


#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TIME_H_ */
