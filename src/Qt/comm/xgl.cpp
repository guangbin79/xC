#include "../../xgl.h"
#include <QGLContext>

struct _xgl_surface_t {
    QGLWidget * widget;
};

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
