#ifndef _SYS_XHTTP_H_
#define _SYS_XHTTP_H_

#include <inttypes.h>

typedef struct _SYS_Http SYS_Http;

typedef enum _SYS_Http_Error {
    SHE_NO_ERROR,        //没有错误
    SHE_CANCELED,        //取消请求
    SHE_NET_USELESS,     //网络未连接
    SHE_SERVER_USELESS,  //服务器故障
    SHE_CONNECT_TIMEOUT, //连接服务器超时
    SHE_RESPONSE_TIMEOUT //服务应答超时
} SYS_Http_Error;

typedef enum _SYS_Http_Callback {
    SHCB_REQUEST,       //请求回调
    SHCB_RESPONSE,      //应答回调
    SHCB_HEADER,        //http头回调
    SHCB_BODY,          //数据体回调
    SHCB_FINISHED,      //完成回调
} SYS_Http_Callback;

typedef void (*SYS_HttpRequestFunc)(void * pvUser, const char * pszURL);
typedef void (*SYS_HttpResponseFunc)(void * pvUser, uint16_t dwStatusCode);
typedef void (*SYS_HttpHeaderFunc)(void * pvUser, const char * pszHeaderName, const char * pszHeaderValue);
typedef void (*SYS_HttpBodyFunc)(void * pvUser, const void * pvData, uint32_t dwSize);
typedef void (*SYS_HttpFinishedFunc)(void * pvUser, SYS_Http_Error error);

#ifdef __cplusplus
extern "C" {
#endif

SYS_Http* sys_HttpCreate(uint32_t dwConnectTimeout, uint32_t dwResponseTimeout);
void sys_HttpDestroy(SYS_Http* pHttp);
void sys_HttpRegisterCallback(SYS_Http* pHttp, SYS_Http_Callback type, void * pfnCallback, void * pvUser);
bool sys_HttpAddHeader(SYS_Http* pHttp, const char * pszHeader, const char * pszValue);
void sys_HttpRemoveHeader(SYS_Http* pHttp, const char * pszHeader);
bool sys_HttpIsRunning(SYS_Http* pHttp);
bool sys_HttpGet(SYS_Http* pHttp, const char * pszUrl);
bool sys_HttpPost(SYS_Http* pHttp, const char * pContentType, const char * pszUrl, const void * pvData, uint32_t dwSize);
void sys_HttpCancel(SYS_Http* pHttp);

#ifdef __cplusplus
}
#endif


#endif // _SYS_XHTTP_H_
