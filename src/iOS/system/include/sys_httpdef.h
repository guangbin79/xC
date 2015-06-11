#ifndef _SYS_XHTTPDEF_H_
#define _SYS_XHTTPDEF_H_

#include <QHttp>
#include <QList>
#include <QTimer>
#include "../../include/sys_http.h"

typedef struct _HttpHeader {
    QString    sHeader;
    QString    sValue;
} HttpHeader;

#define HTTP_CALLBACK_COUNT 5

struct _SYS_Http {
    QHttp * pQHttp;
    QList<QPair<QString, QString> > * pHeaderList;
    QTimer * pTimer;
    bool isRunning, isConnecting;
    uint32_t connectTimeout, responseTimeout;

    void * pfn[HTTP_CALLBACK_COUNT];
    void * pv[HTTP_CALLBACK_COUNT];
};

#endif /* _SYS_XHTTPDEF_H_ */
