#ifndef _SYS_XHTTPDEF_H_
#define _SYS_XHTTPDEF_H_

#include <QHttp>
#include <QList>
#include "../../include/sys_http.h"
#include "../http/httpengine.h"

typedef struct _HttpHeader
{
    QString    sHeader;
    QString    sValue;
}HttpHeader;

struct _SYS_Http
{
    HttpEngine*         pHttpEngine;
    SYS_PFNHTTPEVENT    pNotify;
    void*               pvUser;
    bool               bIsBusy;
};

#endif /* _SYS_XHTTPDEF_H_ */
