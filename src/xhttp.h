/**
 * xC
 * @file xhttp.h
 * @brief 通用xhttp相关接口
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/18
 * @par 修改记录
 *
 */


#ifndef _XHTTP_H_
#define _XHTTP_H_

#include "./xinteger.h"
#include "./xboolean.h"
#include "./xcharacter.h"

/**
 * @brief xhttp对象结构体
 */
typedef struct _xhttp_t xhttp_t;

/**
* @brief xhttp回调函数类型声明
* @param pvUser - 回调对象指针
* @param dwEvent - 回调事件类型
* @return - 无
*/
typedef void (*xfn_http_event_t)(void * pvUser, xuint32_t dwEvent);

/**
 * @brief xhttp回调事件类型枚举
 */
typedef enum _xhttp_event_t {
    XEVT_HTTP_REQUEST,       //请求
    XEVT_HTTP_RESPONSE,      //应答
    XEVT_HTTP_BODY,          //数据体
    XEVT_HTTP_COMPLETED,     //完成
    XEVT_HTTP_ERROR          //错误
} xhttp_event_t;

/**
 * @brief xhttp错误类型枚举
 */
typedef enum _xhttp_error_t {
    XERR_HTTP_NET_USELESS,     //网络未连接
    XERR_HTTP_CONNECT_TIMEOUT, //连接服务器超时
    XERR_HTTP_RESPONSE_TIMEOUT //服务应答超时
} xhttp_error_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief 创建xhttp对象
* @return - xhttp对象结构体指针
*/
xhttp_t * xhttp_create();

/**
* @brief 销毁xhttp对象
* @param[in] pHttp - xhttp对象结构体指针
* @return - 无
*/
void xhttp_destroy(xhttp_t * pHttp);

/**
* @brief 注册xhttp回调函数
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] pfnNotify - xhttp事件回调函数指针
* @param[in] pvUser - xhttp事件回调对象指针
* @return - 无
*/
void xhttp_registerNotify(xhttp_t * pHttp, xfn_http_event_t pfnNotify, void * pvUser);

/**
* @brief 添加xhttp的临时header头,仅限于本次xhttp请求时有效
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] pszHeader - header的字段名称
* @param[in] pszValue - header的该字段对应的值域
* @return - 添加成功：XTRUE 添加失败：XFALSE
*/
xbool_t xhttp_addHeader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue);

/**
* @brief 移除xhttp的header头
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] pszHeader - 要移除的header的字段名称
* @return - 无
*/
void xhttp_removeHeader(xhttp_t * pHttp, const xchar_t * pszHeader);

/**
* @brief xhttp的Get请求
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] pszUrl - get请求的url地址
* @return - 添加请求成功：XTRUE 添加请求失败：XFALSE
*/
xbool_t xhttp_get(xhttp_t * pHttp, const xchar_t * pszUrl);

/**
* @brief xhttp的post请求
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] pContentType - post请求的提交内容类型
* @param[in] pszUrl - post请求的url地址
* @param[in] pvData - 要提交内容缓冲区地址
* @param[in] dwSize - 要提交的内容缓冲区字节数
* @return - 添加请求成功：XTRUE 添加请求失败：XFALSE
*/
xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize);

/**
* @brief 取消已经请求的xhttp操作
* @param[in] pHttp - xhttp对象结构体指针
* @return - 无
*/
void xhttp_cancel(xhttp_t * pHttp);

/**
* @brief 设置xhttp传输超时，如果不设置或者设置为0则使用默认时间,默认等待连接时间为30s,接收数据片段间隔时间为20s
* @param[in] pHttp - xhttp对象结构体指针
* @param[in] dwMSecs1 - xhttp发送请求到收到服务器响应的等待连接超时时间
* @param[in] dwMSecs2 - xhttp接收数据片段间隔超时时间
* @return - 无
*/
void xhttp_setTimeOut(xhttp_t * pHttp, xuint32_t dwMSecs1, xuint32_t dwMSecs2);

/**
 * @brief 获取xhttp响应状态码
 * @param[in] pHttp - xhttp对象结构体指针
 * @return - xhttp 响应状态码
 */
xuint32_t xhttp_getStatusCode(xhttp_t * pHttp);

/**
 * @brief 获取xhttp响应数据总长度
 * @param[in] pHttp - xhttp对象结构体指针
 * @return - xhttp 数据总长度.
 */
xuint32_t xhttp_getContentLength(xhttp_t * pHttp);

/**
 * @brief 获取xhttp数据体长度
 * @param[in] pHttp - xhttp对象结构体指针
 * @return - xhttp 数据体长度
 */
xuint32_t xhttp_getBodySize(xhttp_t * pHttp);

/**
 * @brief 获取xhttp响应数据体
 * @param[in] pHttp - xhttp对象结构体指针
 * @return - xhttp 数据体对象
 */
void * xhttp_getBodyData(xhttp_t * pHttp);

/**
 * @brief 获取xhttp错误类型
 * @param[in] pHttp - xhttp对象结构体指针
 * @return - xhttp 错误类型
 */
xhttp_error_t xhttp_getError(xhttp_t * pHttp);

#ifdef __cplusplus
}
#endif

#endif /* _XHTTP_H_ */

