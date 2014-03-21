#ifndef _SYS_XHTTP_H_
#define _SYS_XHTTP_H_

typedef struct _sys_xhttp_t sys_xhttp_t;

typedef void (*sys_xfn_http_event)(void * pvUser, xuint32_t dwEvent);

typedef enum _sys_xhttp_event_t {
    XEVT_HTTP_REQUEST = 0x0001,       // 请求
    XEVT_HTTP_RESPONSE = 0X0002,      // 应答
    XEVT_HTTP_BODY = 0x0003,          // 数据体
    XEVT_HTTP_COMPLETED = 0x0004,     // 完成
    XEVT_HTTP_ERROR = 0x0005          // 错误
} sys_xhttp_event_t;

#ifdef __cplusplus
extern "C" {
#endif

sys_xhttp_t * sys_xhttp_create();
void sys_xhttp_destroy(sys_xhttp_t * pHttp);
void sys_xhttp_registerNotify(sys_xhttp_t * pHttp, xfn_http_event pfnNotify, void * pvUser);
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

#ifdef __cplusplus
}
#endif


#endif // _SYS_XHTTP_H_
