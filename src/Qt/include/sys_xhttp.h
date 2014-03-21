#ifndef _SYS_XHTTP_H_
#define _SYS_XHTTP_H_

#include "../../xinteger.h"
#include "../../xboolean.h"
#include "../../xcharacter.h"

typedef struct _sys_xhttp_t sys_xhttp_t;

typedef void (*sys_xfn_http_event)(void * pvUser, xuint32_t dwEvent);

typedef enum _sys_xhttp_event_t {
    XEVT_SYS_HTTP_REQUEST,       // 请求
    XEVT_SYS_HTTP_RESPONSE,      // 应答
    XEVT_SYS_HTTP_BODY,          // 数据体
    XEVT_SYS_HTTP_COMPLETED,     // 完成
    XEVT_SYS_HTTP_ERROR          // 错误
} sys_xhttp_event_t;

typedef enum _sys_xhttp_error_t {
    XERR_SYS_HTTP_NET_USELESS,     //网络未连接
    XERR_SYS_HTTP_CONNECT_TIMEOUT, //连接服务器超时
    XERR_SYS_HTTP_RESPONSE_TIMEOUT //服务应答超时
} sys_xhttp_error_t;

#ifdef __cplusplus
extern "C" {
#endif

sys_xhttp_t * sys_xhttp_create();
void sys_xhttp_destroy(sys_xhttp_t * pHttp);
void sys_xhttp_registerNotify(sys_xhttp_t * pHttp, sys_xfn_http_event pfnNotify, void * pvUser);
xbool_t sys_xhttp_addHeader(sys_xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue);
void sys_xhttp_removeHeader(sys_xhttp_t * pHttp, const xchar_t * pszHeader);
xbool_t sys_xhttp_get(sys_xhttp_t * pHttp, const xchar_t * pszUrl);
xbool_t sys_xhttp_post(sys_xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize);
void sys_xhttp_cancel(sys_xhttp_t * pHttp);
void sys_xhttp_setTimeOut(sys_xhttp_t * pHttp, xuint32_t dwMSecs1, xuint32_t dwMSecs2);
xuint32_t sys_xhttp_getStatusCode(sys_xhttp_t * pHttp);
xuint32_t sys_xhttp_getContentLength(sys_xhttp_t * pHttp);
xuint32_t sys_xhttp_getBodySize(sys_xhttp_t * pHttp);
void * sys_xhttp_getBodyData(sys_xhttp_t * pHttp);
sys_xhttp_error_t sys_xhttp_getError(sys_xhttp_t * pHttp);

#ifdef __cplusplus
}
#endif


#endif // _SYS_XHTTP_H_
