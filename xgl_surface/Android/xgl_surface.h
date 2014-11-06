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

#endif // _XGL_SURFACE_X_


