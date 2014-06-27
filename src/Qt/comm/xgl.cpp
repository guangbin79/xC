#include "../../../xgl.h"
#include "../system/include/sys_xgldef.h"

xbool_t xgl_makeCurrentContext(xgl_surface_t * surface)
{
    surface->widget->makeCurrent();

    return true;
}

void xgl_swapBuffers(xgl_surface_t * surface)
{
    const QGLContext * context = surface->widget->context();

    if (context)
        context->swapBuffers();
}
