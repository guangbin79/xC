#include "../../../xdebug.h"
#include "../../../xvarargs.h"
#include <QDebug>
#include <QString>

void xdebug_assert(xbool_t exp) {
    Q_ASSERT(exp);
}

void xdebug_printf(const xchar_t * str) {
    QTextStream out(stdout);

    out << QString((const char *)str);
}

