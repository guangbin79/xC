#include "../../xhttp.h"
#include "../include/sys_xhttp.h"

xhttp_t * xhttp_create() {
    return (xhttp_t *)sys_xhttp_create();
}

void xhttp_destroy(xhttp_t * pHttp) {
    sys_xhttp_destroy((sys_xhttp_t *)pHttp);
}

void xhttp_registerNotify(xhttp_t * pHttp, xfn_http_event pfnNotify, void * pvUser) {
    sys_xhttp_registerNotify((sys_xhttp_t *)pHttp, (sys_xfn_http_event)pfnNotify, pvUser);
}

xbool_t xhttp_addHeader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue) {
    return sys_xhttp_addHeader((sys_xhttp_t *)pHttp, pszHeader, pszValue);
}

void xhttp_removeHeader(xhttp_t * pHttp, const xchar_t * pszHeader) {
    sys_xhttp_removeHeader((sys_xhttp_t *)pHttp, pszHeader);
}

xbool_t xhttp_get(xhttp_t * pHttp, const xchar_t * pszUrl) {
    return sys_xhttp_get((sys_xhttp_t *)pHttp, pszUrl);
}

xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize) {
    return sys_xhttp_post((sys_xhttp_t *)pHttp, pContentType, pszUrl, pvData, dwSize);
}

void xhttp_cancel(xhttp_t * pHttp) {
    sys_xhttp_cancel((sys_xhttp_t *)pHttp);
}

void xhttp_setTimeOut(xhttp_t * pHttp, xuint32_t dwMSecs1, xuint32_t dwMSecs2) {
    sys_xhttp_setTimeOut((sys_xhttp_t *)pHttp, dwMSecs1, dwMSecs2);
}

xuint32_t xhttp_getStatusCode(xhttp_t * pHttp) {
    return sys_xhttp_getStatusCode((sys_xhttp_t *)pHttp);
}

xuint32_t xhttp_getContentLength(xhttp_t * pHttp) {
    return sys_xhttp_getContentLength((sys_xhttp_t *)pHttp);
}

xuint32_t xhttp_getBodySize(xhttp_t * pHttp) {
    return sys_xhttp_getBodySize((sys_xhttp_t *)pHttp);
}

void * xhttp_getBodyData(xhttp_t * pHttp) {
    return sys_xhttp_getBodyData((sys_xhttp_t *)pHttp);
}

xhttp_error_t xhttp_getError(xhttp_t * pHttp) {
    return (xhttp_error_t)sys_xhttp_getError((sys_xhttp_t *)pHttp);
}
