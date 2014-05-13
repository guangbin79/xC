#include "../../../xgl.h"
#include "../system/include/sys_xgldef.h"

xbool_t xgl_makeCurrentContext(xgl_surface_t * surface)
{
    surface->widget->makeCurrent();

    return true;
}

void xgl_swapBuffers()
{
    const QGLContext * context = QGLContext::currentContext();

    if (context)
        context->swapBuffers();
}
