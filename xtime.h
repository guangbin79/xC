/**
 * xC
 * @file xtime.h
 * @brief 日期\时间
 * @author guangbin <baigb@tiros.com.cn>
 * @date 2014/03/12
 * @par 修改记录
 *
 */

#ifndef _XTIME_H_
#define _XTIME_H_

#include "./xinteger.h"


/**
 * @brief 日期时间结构体
 */
typedef struct _xdate_time_t {
    xint16_t year;   ///< 年
    xint8_t month;   ///< 月
    xint8_t day;     ///< 日
    xint8_t hour;    ///< 时
    xint8_t minute;  ///< 分
    xint8_t second;  ///< 秒
} xdate_time_t;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 获取系统时钟
 * @param - 无
 * @return - 返回时钟时间,精度为毫秒
 */
xuint32_t xtime_clock();

/**
 * @brief 从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数
 * @param[in] pdt - 格林尼治时间,如果为空则为当前格林尼治时间
 * @return - 从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数
 */
xuint32_t xtime_mkTime(const xdate_time_t * pdt);

/**
 * @brief 转换格林尼治时间
 * @param[in] t - 需要转换的时间(从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数)
 * @param[out] pdt - 格林尼治时间
 * @return - 无
 */
void xtime_gmTime(xuint32_t t, xdate_time_t * pdt);

/**
 * @brief 转换本地时间
 * @param[in] t - 需要转换的时间(从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数)
 * @param[out] pdt - 本地时间
 * @return - 无
 */
void xtime_localTime(xuint32_t t, xdate_time_t * pdt);

#ifdef __cplusplus
}
#endif

#endif /* _XTIME_H_ */

