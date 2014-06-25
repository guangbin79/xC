#ifndef _XGL_SURFACE_H_
#define _XGL_SURFACE_H_

#include <jni.h>

struct _xgl_surface {
    	jobject glsurfaceObject;
	void * display;
	void * draw;
	void * read;
	void * contest;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif // _XGL_SURFACE_X_
