#include "../../xgl.h"
#include "./system/include/sys_xgldef.h"

void xgl_drawScreenBegin()
{

}

void xgl_drawScreenEnd()
{
    const QGLContext* context = QGLContext::currentContext();
    if (context)
        context->swapBuffers();
}

xbool_t xgl_makeCurrentContext(xgl_surface_t * surface)
{
    surface->widget->makeCurrent();

    return true;
}
