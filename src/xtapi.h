/**
 * xC
 * @file xtapi.h
 * @brief TAPI
 * @author guangbin <baigb@tiros.com.cn>
 * @date 2014/03/14
 * @par 修改记录
 *
 */

#ifndef _XTAPI_H_
#define _XTAPI_H_

#include "./xinteger.h"
#include "./xfloat.h"
#include "./xboolean.h"
#include "./xcharacter.h"


typedef struct _xtapi_t xtapi_t;

/**
 * @brief 基站信息结构体
 */
typedef struct _xbase_station_info_t {
    xuint32_t lac;                             //lac
    xuint32_t cell_id;                         //cellid
    xuint32_t mcc;                             //mobile_country_code
    xuint32_t mnc;                             //mobile_network_code
    xint16_t  signal_strength;                 //实际基站信号强度dbm
    xuint8_t  type;                            //基站信息类别： 0:普通基站信息， 1:C网基站信息...
    xdouble_t lat;                             //当前基站可获取的经度，若获取不到则为0
    xdouble_t lon;                             //当前基站可获取的纬度，若获取不到则为0
} xbase_station_info_t;

/**
 * @brief wifi信息结构体
 */
typedef struct _xwifi_info_t {
    xchar_t * name;                            //wifi名称
    xchar_t * mac;                             //mac地址，12位+1位,mac地址格式没有连接字符,比如mac地址为12:34:56:78:9a:bc,对应为123456789abc
    xchar_t * ip;                              //连接后实际分配的ip地址
    xint16_t  signal_strength;                 //wifi信号强度
} xwifi_info_t;

/**
  * @brief DeviceInfo信息结构体
  */
typedef struct _xdevice_info_t {
    xchar_t * manufacturer;                    //厂商名称
    xchar_t * device_model;                    //设备型号
    xchar_t * os_version;                      //操作系统版本
} xdevice_info_t;

/**
  * @brief 移动网络类型
  */
typedef enum _xnet_type_t {
    XNET_TYPE_WIFI,
    XNET_TYPE_GSM,
    XNET_TYPE_CDMA,
    XNET_TYPE_TDCDMA,
    XNET_TYPE_CDMA2000,
    XNET_TYPE_WCDMA
} xnet_type_t;

#ifdef __cplusplus
extern "C"
{
#endif	

/**
 * @brief 创建xtapi对象句柄
 * @return - 成功返回xtapi对象,失败返回XNULL
 */
xtapi_t * xtapi_create();

/**
 * @brief 销毁xtapi对象
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 无
 */
void xtapi_destroy(xtapi_t * pxtapi);

/**
 * @brief 获取可搜寻到的基站个数
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 返回实际获取到的基站个数，失败返回0
 */
xuint8_t xtapi_getBsCount(xtapi_t * pxtapi);

/**
 * @brief 根据索引获取指定基站信息，其中0为主基站索引，其它按信号强度排序
 * @param[in] pxtapi - xtapi对象句柄
 * @param[in] aIndex - 索引值(0~tr_tapigetbscount()之间)
 * @return - 根据指定索引值返回基站信息结构体（若索引值不在有效范围内，则返回XNULL）
 */
const xbase_station_info_t * xtapi_getBsByIndex(xtapi_t * pxtapi, const xuint8_t index);

/**
 * @brief 获取当前已连接的wifi信息
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 返回实际已连接的wifi信息结构体对象,失败返回XNULL
 */
const xwifi_info_t * xtapi_getConnWifiInfo(xtapi_t * pxtapi);

/**
 * @brief 获取MobileID
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 实际获取的MobileID
 */
const xchar_t * xtapi_getMobileId(xtapi_t * pxtapi);

/**
 * @brief 获取设备卡的IMSI
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 实际获取的IMSI
 */
const xchar_t * xtapi_getImsi(xtapi_t * pxtapi);

/**
 * @brief 获取当前网络的联网类别
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 网络类型
 */
xnet_type_t xtapi_getNetType(xtapi_t * pxtapi);

/**
 * @brief 获取设备信息
 * @param[in] pxtapi - xtapi对象句柄
 * @return - 返回设备信息结构体
 */
const xdevice_info_t * xtapi_getDeviceInfo(xtapi_t * pxtapi);

#ifdef __cplusplus
}
#endif

#endif /* _Xxtapi_H_ */

