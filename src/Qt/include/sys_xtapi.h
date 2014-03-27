#ifndef _TR_SYS_XTAPI_H_
#define _TR_SYS_XTAPI_H_

typedef struct  _xsys_tapi_t   xsys_tapi_t;

typedef struct _xsys_base_station_info_t
{
    unsigned int        lac;                           //lac
    unsigned int        cellid;                        //cellid
    unsigned int        mcc;                           //mobile_country_code
    unsigned int        mnc;                           //mobile_network_code
    signed short int   signalstrength;                  //实际基站信号强度dbm
    unsigned char      type;                            //基站信息类别： 0:普通基站信息， 1:C网基站信息...
    double              lat;                      //当前基站可获取的经度，若获取不到则为0
    double              lon;                      //当前基站可获取的纬度，若获取不到则为0
}xsys_base_station_info_t;

typedef struct _xsys_wifi_info_t
{
    char*                       name;                  //name
    char*                       mac;                   //mac地址，12位+1位,mac地址格式没有连接字符,比如mac地址为12:34:56:78:9a:bc,对应为123456789abc
    char*                       ip;                    //连接后实际分配的ip地址
    signed short int    signalstrength;                //wifi信号强度
}xsys_wifi_info_t;

typedef struct _xsys_device_info_t
{
    char* manufacturername;                          //厂商名称
    char* devicemodel;                               //设备型号
    char* osversion;                                 //操作系统版本
}xsys_device_info_t;

#ifdef __cplusplus
extern "C"
{
#endif

xsys_tapi_t *   sys_tapicreate();
void sys_tapidestroy(xsys_tapi_t * ptapi);
unsigned char sys_tapigetbscount(xsys_tapi_t * ptapi);
const xsys_base_station_info_t * sys_tapigetbsbyindex(xsys_tapi_t * ptapi, const unsigned char aIndex);
const xsys_wifi_info_t * sys_tapigetconnwifiinfo(xsys_tapi_t * ptapi);
const char * sys_tapigetmobileid(xsys_tapi_t * ptapi);
const char * sys_tapigetimsi(xsys_tapi_t * ptapi);
int sys_tapigetnettype(xsys_tapi_t * ptapi);
const xsys_device_info_t * sys_tapigetdeviceinfo(xsys_tapi_t * ptapi);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_XTAPI_H_ */
