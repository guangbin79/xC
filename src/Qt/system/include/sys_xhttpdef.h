#ifndef _SYS_XHTTPDEF_H_
#define _SYS_XHTTPDEF_H_

#include <QHttp>
#include <QList>
#include "../../include/sys_xhttp.h"
#include "../http/httpengine.h"

typedef struct _HttpHeader {
    QString    sHeader;
    QString    sValue;
} HttpHeader;

struct _SYS_Http {
    HttpEngine *        pHttpEngine;
    sys_xfn_http_event  pNotify;
    void *              pvUser;
    bool                bIsBusy;
};

#endif /* _SYS_XHTTPDEF_H_ */
