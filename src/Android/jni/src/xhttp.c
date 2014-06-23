/*
 * @file xhttp.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xhttp.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../../../xmemory.h"
#include "../../../xboolean.h"
#include "../jni_include/sys_xhttp.h"
#include "../jni_include/jni_http.h"
//#include "./netManager/http_def.h"
//#include "./netManager/comm_netManager.h"
//#include "../../../universal/string.h"
//#include "../../BasePlugin.h"


xhttp_t * xhttp_create(xuint32_t dwConnectTimeout, xuint32_t dwResponseTimeout)
{
    return (xhttp_t*)sys_httpcreate(dwConnectTimeout,dwResponseTimeout);
}

void xhttp_destroy(xhttp_t * pHttp)
{
    sys_httpdestroy((SYS_Http*)pHttp);
}


void xhttp_registerCallback(xhttp_t * pHttp, xhttp_callback_t type, void * pfnCallback, void * pvUser)
{
	sys_httpregisternotify((SYS_Http*)pHttp, (SYS_HttpEvent)type, (SYS_PFNHTTPEVENT)pfnCallback, pvUser);
}

xbool_t xhttp_addHeader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue)
{
	return  sys_httpaddheader((SYS_Http*)pHttp, pszHeader, pszValue);
}

void xhttp_removeHeader(xhttp_t * pHttp, const xchar_t * pszHeader)
{
	xsys_xdebug_assert(pHttp != XNULL && pszHeader != XNULL);
    sys_httpremoveheader((SYS_Http*) pHttp, pszHeader);
}

xbool_t xhttp_get(xhttp_t * pHttp, const xchar_t * pszUrl)
{
	xsys_xdebug_assert(pHttp != XNULL && pszUrl != XNULL);
	return sys_httpget((SYS_Http*)pHttp, pszUrl);
}


xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize)
{
	xsys_xdebug_assert(pHttp != XNULL && pContentType != XNULL && pszUrl != XNULL && pvData != XNULL);
	return sys_httppost((SYS_Http*) pHttp, pContentType, pszUrl, pvData, dwSize);
}

void xhttp_cancel(xhttp_t * pHttp)
{
	xsys_xdebug_assert(pHttp != XNULL);
	sys_httpcancel((SYS_Http*) pHttp);

}

xbool_t xhttp_isRunning(xhttp_t * pHttp)
{
	return sys_httpisRunning((SYS_Http*) pHttp);
}

