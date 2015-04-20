/**
 * xC
 * @file xhttprequest.h
 * @brief 通用xhttprequest相关接口
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/18
 * @par 修改记录
 *
 */


#ifndef _XHTTPREQUEST_H_
#define _XHTTPREQUEST_H_

#include "./xinteger.h"
#include "./xboolean.h"
#include "./xcharacter.h"

/**
 * @brief xhttprequest对象结构体
 */
typedef struct _xhttp_request xhttp_request_t;

/**
 * @brief xhttprequest错误类型枚举
 */
typedef enum _xhttp_error {
    XHE_NO_ERROR,        //没有错误
    XHE_CANCELED,        //取消请求
    XHE_NET_USELESS,     //网络未连接
    XHE_SERVER_USELESS,  //服务器故障
    XHE_CONNECT_TIMEOUT, //连接服务器超时
    XHE_RESPONSE_TIMEOUT //服务应答超时
} xhttp_error_t;

/**
 * @brief xhttprequest回调函数类型枚举
 */
typedef enum _xhttp_callback {
    XHCB_REQUEST,       //请求回调
    XHCB_RESPONSE,      //应答回调
    XHCB_HEADER,        //http头回调
    XHCB_BODY,          //数据体回调
    XHCB_FINISHED       //完成回调
} xhttp_callback_t;

/**
* @brief xhttprequest回调函数类型声明
* @return - 无
*/
typedef void (*xfn_http_request_t)(void * pvUser, const xchar_t * pszURL);
typedef void (*xfn_http_response_t)(void * pvUser, xuint16_t dwStatusCode);
typedef void (*xfn_http_header_t)(void * pvUser, const xchar_t * pszHeaderName, const xchar_t * pszHeaderValue);
typedef void (*xfn_http_body_t)(void * pvUser, const void * pvData, xuint32_t dwSize);
typedef void (*xfn_http_finished)(void * pvUser, xhttp_error_t error);

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief 创建xhttprequest对象
* @param[in] dwConnectTimeout - 连接超时时间,等于0则采用系统默认值
* @param[in] dwResponseTimeout - 应答超时时间,等于0则采用系统默认值
* @return - xhttprequest对象结构体指针
*/
xhttp_request_t * xhttprequest_create(xuint32_t dwConnectTimeout, xuint32_t dwResponseTimeout);

/**
* @brief 销毁xhttprequest对象
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @return - 无
*/
void xhttprequest_destroy(xhttp_request_t * pHttpRequest);

/**
* @brief 注册xhttprequest回调函数
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @param[in] type - 回调函数类型
* @param[in] pfn - 回调函数指针
* @param[in] pvUser - 回调函数对象指针
* @return - 无
*/
void xhttprequest_registerCallback(xhttp_request_t * pHttpRequest, xhttp_callback_t type, void * pfnCallback, void * pvUser);

/**
* @brief 添加header
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @param[in] pszHeader - header的字段名称
* @param[in] pszValue - header的该字段对应的值域
* @return - 如果已存在相同的header则返回XFALSE,否则返回XTRUE
*/
xbool_t xhttprequest_addHeader(xhttp_request_t * pHttpRequest, const xchar_t * pszHeader, const xchar_t * pszValue);

/**
* @brief 移除header
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @param[in] pszHeader - 要移除的header的字段名称
* @return - 无
*/
void xhttprequest_removeHeader(xhttp_request_t * pHttpRequest, const xchar_t * pszHeader);

/**
* @brief 是否正在请求
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @return - 如果正在发送请求：XTRUE,否则返回XFALSE
*/
xbool_t xhttprequest_isRunning(xhttp_request_t * pHttpRequest);

/**
* @brief Get请求
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @param[in] pszUrl - get请求的url地址
* @return - 是否成功发送请求,xhttprequest_isBusy()的返回值取反
*/
xbool_t xhttprequest_get(xhttp_request_t * pHttpRequest, const xchar_t * pszUrl);

/**
* @brief Post请求
* @param[in] pHttpRequest - xhttprequeset对象结构体指针
* @param[in] pContentType - post请求的提交内容类型
* @param[in] pszUrl - post请求的url地址
* @param[in] pvData - 要提交内容缓冲区地址
* @param[in] dwSize - 要提交的内容缓冲区字节数
* @return - 是否成功发送请求,xhttprequest_isBusy()的返回值取反
*/
xbool_t xhttprequest_post(xhttp_request_t * pHttpRequest, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize);

/**
* @brief 取消已经请求的操作
* @param[in] pHttpRequest - xhttprequest对象结构体指针
* @return - 无
*/
void xhttprequest_cancel(xhttp_request_t * pHttpRequest);

#ifdef __cplusplus
}
#endif

#endif /* _XHTTPREQUEST_H_ */

