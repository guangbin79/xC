#include "../../../xdebug.h"
#include "../../../xvarargs.h"
#include <QDebug>
#include <QString>

void xdebug_assert(xbool_t exp) {
    Q_ASSERT(exp);
}

void xdebug_printf(const char * format, va_list ap) {
    QTextStream out(stdout);

    out << QString().vsprintf(format, ap);
}

