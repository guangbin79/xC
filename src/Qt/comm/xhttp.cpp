#include "../../../xhttp.h"
#include "../include/sys_http.h"

xhttp_t * xhttp_create(xuint32_t dwConnectTimeout, xuint32_t dwResponseTimeout) {
    return (xhttp_t *)sys_HttpCreate(dwConnectTimeout, dwResponseTimeout);
}

void xhttp_destroy(xhttp_t * pHttp) {
    sys_HttpDestroy((SYS_Http *)pHttp);
}

void xhttp_registerCallback(xhttp_t * pHttp, xhttp_callback_t type, void * pfnCallback, void * pvUser) {
    sys_HttpRegisterCallback((SYS_Http *)pHttp, (SYS_Http_Callback)type, pfnCallback, pvUser);
}

xbool_t xhttp_addHeader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue) {
    return sys_HttpAddHeader((SYS_Http *)pHttp, (const char *)pszHeader, (const char *)pszValue);
}

void xhttp_removeHeader(xhttp_t * pHttp, const xchar_t * pszHeader) {
    sys_HttpRemoveHeader((SYS_Http *)pHttp, (const char *)pszHeader);
}

xbool_t xhttp_isRunning(xhttp_t *pHttp) {
    return sys_HttpIsRunning((SYS_Http *)pHttp);
}

xbool_t xhttp_get(xhttp_t * pHttp, const xchar_t * pszUrl) {
    return sys_HttpGet((SYS_Http *)pHttp, (const char *)pszUrl);
}

xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize) {
    return sys_HttpPost((SYS_Http *)pHttp, (const char *)pContentType, (const char *)pszUrl, pvData, dwSize);
}

void xhttp_cancel(xhttp_t * pHttp) {
    sys_HttpCancel((SYS_Http *)pHttp);
}
