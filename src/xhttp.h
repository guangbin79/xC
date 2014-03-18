/**
 * xC
 * @file xhttp.h
 * @brief 通用http相关接口
 * @author Harry <computerwjun@126.com>
 * @date 2014/03/13
 * @par 修改记录
 * 
 */


#ifndef _XHTTP_H_
#define _XHTTP_H_

#include "./xinteger.h"
#include "./xboolean.h"
#include "./xcharacter.h"

/**
 * @brief http对象结构体
 */
typedef struct _Http xhttp_t;

/**
* @brief Http回调函数类型声明
* @param pvUser - 回调对象指针
* @param dwEvent - 回调事件类型
* @param dwParam1 - 回调事件传递参数1
* @param dwParam2 - 回调事件传递参数2
* @return - 无
*/ 
typedef void (*XPFNHTTPEVENT)(void * pvUser, xuint32_t dwEvent, xuint32_t dwParam1, xuint32_t dwParam2);

/**
 * @brief Http错误码枚举
 */
typedef enum _HTTPErrCode
{
	XHTTPERR_DISCONNECT = 600,               //网络未连接
	XHTTPERR_CLIENTERR = 601,                //http客户端错误
    XHTTPERR_SERVERERR = 602,                //http服务器非正常应答
    XHTTPERR_TIMEOUT_RESPONSE = 700,         //HTTP应答超时错误
    XHTTPERR_TIMEOUT_DATA = 701		//HTTP接收数据超时
} xHTTPErrCode_t;

/**
 * @brief Http错误类型枚举
 */
typedef enum _HttpErrorType
{
	XHTTPERRTYPE_UNAVAILABLE = 0x01,	//网络不可用（自定义错误码600系列）
	XHTTPERRTYPE_RESPONSE,		//http应答错误（标准http应答错误码）
	XHTTPERRTYPE_TIMEOUT		//超时（自定义错误码700系列）
}xHttpErrorType_t;

/**
 * @brief Http回调事件类型枚举
 */
typedef enum _HttpEvent
{
	XEVT_HTTP_REQUEST = 0x0001,       /* 请求 */
    XEVT_HTTP_RESPONSE = 0X0002,	 	 /* 应答   | dwParam1:状态码 dwParam2:当状态码为200系列时，该值为完整数据体长度，当状态码为300系列时，为跳转url地址*/
	XEVT_HTTP_BODY = 0x0003,          /* 数据体 | dwParam1 : http body size (uint32)  dwParam2 : http body (void *) */
	XEVT_HTTP_COMPLETED = 0x0004,     /* 完成 */
	XEVT_HTTP_ERROR = 0x0005          /* 错误   | dwParam1 : 错误类型 dwParam2: 错误码, 600之后为自定义错误*/
}xHttpEvent_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief 创建http对象
* @return - http对象结构体指针
*/ 
xhttp_t * xhttp_create();

/**
* @brief 销毁http对象
* @param[in] pHttp - http对象结构体指针
* @return - 无
*/ 
void xhttp_destroy(xhttp_t * pHttp);

/**
* @brief 注册http回调函数
* @param[in] pHttp - http对象结构体指针
* @param[in] pfnNotify - http事件回调函数指针
* @param[in] pvUser - http事件回调对象指针
* @return - 无
*/ 
void xhttp_registernotify(xhttp_t * pHttp, XPFNHTTPEVENT pfnNotify, void * pvUser);

/**
* @brief 添加http的临时header头,仅限于本次http请求时有效
* @param[in] pHttp - http对象结构体指针
* @param[in] pszHeader - header的字段名称
* @param[in] pszValue - header的该字段对应的值域
* @return - 添加成功：true 添加失败：false
*/ 
xbool_t xhttp_addheader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue);

/**
* @brief 移除http的header头
* @param[in] pHttp - http对象结构体指针
* @param[in] pszHeader - 要移除的header的字段名称
* @return - 无
*/ 
void xhttp_removeheader(xhttp_t * pHttp, const xchar_t * pszHeader);

/**
* @brief http的Get请求
* @param[in] pHttp - http对象结构体指针
* @param[in] pszUrl - get请求的url地址
* @return - 添加请求成功：true 添加请求失败：false
*/ 
xbool_t xhttpget(xhttp_t * pHttp, const xchar_t * pszUrl);

/**
* @brief http的post请求
* @param[in] pHttp - http对象结构体指针
* @param[in] pContentType - post请求的提交内容类型
* @param[in] pszUrl - post请求的url地址
* @param[in] pvData - 要提交内容缓冲区地址
* @param[in] dwSize - 要提交的内容缓冲区字节数
* @return - 添加请求成功：true 添加请求失败：false
*/
xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize);

/**
* @brief 取消已经请求的http操作
* @param[in] pHttp - http对象结构体指针
* @return - 无
*/
void xhttp_cancel(xhttp_t * pHttp);

/**
* @brief 设置http传输超时，如果不设置或者设置为0则使用默认时间,默认等待连接时间为30s,接收数据片段间隔时间为20s
* @param[in] pHttp - http对象结构体指针
* @param[in] dwMSecs1 - http发送请求到收到服务器响应的等待连接超时时间
* @param[in] dwMSecs2 - http接收数据片段间隔超时时间
* @return - 无
*/ 
void xhttp_settimeout(xhttp_t * pHttp, xuint32_t dwMSecs1, xuint32_t dwMSecs2);
	
#ifdef __cplusplus
}
#endif

#endif /*	_XHTTP_H_	*/
