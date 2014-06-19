#include "../../../../xgl.h"
#include "../jni_include/jni_system.h"
#include "../jni_include/sys_xgl.h"


xbool_t xgl_makeCurrentContext(xgl_surface_t * surface)
{
	return sys_gl_makeCurrent((xsys_xglsurface*) surface);
}

void xgl_swapBuffers(xgl_surface_t * surface)
{
	sys_gl_swapBuffers(
			surface);
}
