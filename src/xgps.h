/**
 * xC
 * @file xgps.h
 * @brief 通用gps相关接口
 * @author Harry <computerwjun@126.com>
 * @date 2014/03/13
 * @par 修改记录
 * 
 */

#ifndef _XGPS_H_
#define _XGPS_H_

#include "./xinteger.h"
#include "./xboolean.h"
#include "./xfloat.h"


/**
 * @brief GPS信息结构体
 */
typedef struct _GPSInfo
{
    xdouble_t  lon;                ///< 经度
    xdouble_t  lat;                ///< 纬度
    xdouble_t  speed;              ///< 速度 单位:米/秒
    xdouble_t  course;             ///< 方向 真北方向为0度,顺时针向东增加角度
} xGPSInfo_t;

/**
 * @brief GPS回调函数类型声明
 * @param[in] pvUser - 回调对象指针
 * @param[in] pInfo - 回调GPS信息结构体指针
 * @return - 无
 * @par 注:GPS设备禁用时,以pInfo为空进行回调,表示无法使用GPS设备,并停止定位<br>
 */
typedef void (*XPFNGPSINFO)(void * pvUser, const xGPSInfo_t * pInfo);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 启动GPS定位
 * @param[in] pfn - GPS信息回调函数指针
 * @param[in] pvUser - 回调函数对象指针
 * @return - 无
 */
void xgps_start(XPFNGPSINFO pfn, void * pvUser);

/**
 * @brief 停止GPS定位
 * @param - 无
 * @return - 无
 */
void xgps_stop();

/**
 * @brief 判断GPS是否已经开始定位
 * @param - 无
 * @return - GPS定位已经启动则返回true,否则返回false
 */
xbool_t xgps_isbusy();

#ifdef __cplusplus
}
#endif

#endif /* _XGPS_H_ */

