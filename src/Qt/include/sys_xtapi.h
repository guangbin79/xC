#ifndef _SYS_XTAPI_H_
#define _SYS_XTAPI_H_

#include "../../xcharacter.h"
#include "../../xfloat.h"
#include "../../xinteger.h"

typedef struct  _xsys_tapi_t   xsys_tapi_t;

typedef struct _xsys_base_station_info_t {
    xuint32_t lac;                 //lac
    xuint32_t cellid;              //cellid
    xuint32_t mcc;                 //mobile_country_code
    xuint32_t mnc;                 //mobile_network_code
    xint16_t  signalstrength;      //实际基站信号强度dbm
    xuint8_t  type;                //基站信息类别： 0:普通基站信息， 1:C网基站信息...
    xdouble_t lat;                 //当前基站可获取的经度，若获取不到则为0
    xdouble_t lon;                 //当前基站可获取的纬度，若获取不到则为0
} xsys_base_station_info_t;

typedef struct _xsys_wifi_info_t {
    xchar_t * name;                  //name
    xchar_t * mac;                   //mac地址，12位+1位,mac地址格式没有连接字符,比如mac地址为12:34:56:78:9a:bc,对应为123456789abc
    xchar_t * ip;                    //连接后实际分配的ip地址
    xint16_t signalstrength;         //wifi信号强度
} xsys_wifi_info_t;

typedef struct _xsys_device_info_t {
    xchar_t * manufacturername;      //厂商名称
    xchar_t * devicemodel;           //设备型号
    xchar_t * osversion;             //操作系统版本
} xsys_device_info_t;

typedef enum _xsys_net_type_t {
    XSYS_NET_TYPE_WIFI,
    XSYS_NET_TYPE_GSM,
    XSYS_NET_TYPE_CDMA,
    XSYS_NET_TYPE_TDCDMA,
    XSYS_NET_TYPE_CDMA2000,
    XSYS_NET_TYPE_WCDMA
} xsys_net_type_t;
#ifdef __cplusplus
extern "C"
{
#endif

xsys_tapi_t * sys_tapicreate();
void sys_tapidestroy(xsys_tapi_t * ptapi);
xuint8_t sys_tapigetbscount(xsys_tapi_t * ptapi);
const xsys_base_station_info_t * sys_tapigetbsbyindex(xsys_tapi_t * ptapi, const xchar_t aIndex);
const xsys_wifi_info_t * sys_tapigetconnwifiinfo(xsys_tapi_t * ptapi);
const xchar_t * sys_tapigetmobileid(xsys_tapi_t * ptapi);
const char * sys_tapigetimsi(xsys_tapi_t * ptapi);
xsys_net_type_t sys_tapigetnettype(xsys_tapi_t * ptapi);
const xsys_device_info_t * sys_tapigetdeviceinfo(xsys_tapi_t * ptapi);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_XTAPI_H_ */
