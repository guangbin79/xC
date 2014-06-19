#ifndef _SYS_HTTP_H_
#define _SYS_HTTP_H_

typedef struct _SYS_Http SYS_Http;

typedef void (*SYS_PFNHTTPEVENT)(void * pvUser, unsigned int dwEvent, unsigned int dwParam1, unsigned int dwParam2);

typedef enum _SYS_HTTPErrCode
{
    SYS_NO_ERROR,        //没有错误
    SYS_CANCELED,        //取消请求
    SYS_NET_USELESS,     //网络未连接
    SYS_SERVER_USELESS,  //服务器故障
    SYS_CONNECT_TIMEOUT, //连接服务器超时
    SYS_RESPONSE_TIMEOUT //服务应答超时
} SYS_HTTPErrCode;


typedef enum _SYS_HttpEvent
{
	SYS_EVT_HTTP_REQUEST,       //请求回调
	SYS_EVT_HTTP_RESPONSE,      //应答回调
	SYS_EVT_HTTP_HEADER,        //http头回调
	SYS_EVT_HTTP_BODY,          //数据体回调
	SYS_EVT_HTTP_FINISHED       //完成回调
} SYS_HttpEvent;

#ifdef __cplusplus
extern "C" {
#endif

SYS_Http * sys_httpcreate();
void sys_httpdestroy(SYS_Http * pHttp);
void sys_httpregisternotify(SYS_Http * pHttp, SYS_HttpEvent type,SYS_PFNHTTPEVENT pfnNotify, void * pvUser);
unsigned char  sys_httpaddheader(SYS_Http * pHttp, const char * pszHeader, const char * pszValue);
void sys_httpremoveheader(SYS_Http * pHttp, const char * pszHeader);
unsigned char sys_httpget(SYS_Http * pHttp, const char * pszUrl);
unsigned char sys_httppost(SYS_Http * pHttp, const char * pContentType, const char * pszUrl, const void * pvData, unsigned int dwSize);
void sys_httpcancel(SYS_Http * pHttp);
unsigned char sys_httpisRunning(SYS_Http * pHttp);
#ifdef __cplusplus
}
#endif


#endif // _SYS_HTTP_H_
