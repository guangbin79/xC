#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
#include<stdlib.h>
#include<string.h>

xsys_tapi_t * sys_tapicreate()
{
    xsys_tapi_t * pTApi = new xsys_tapi_t;
    if (pTApi)
    {
        pTApi->_iBaseStationCount = 0;
        pTApi->_pBaseStationInfo = new xsys_base_station_info_t;
        if (pTApi->_pBaseStationInfo)
        {
            pTApi->_pBaseStationInfo->cellid = 50927;
            pTApi->_pBaseStationInfo->lac = 4440;
            pTApi->_pBaseStationInfo->lat = 0;
            pTApi->_pBaseStationInfo->lon = 0;
            pTApi->_pBaseStationInfo->mcc = 460;
            pTApi->_pBaseStationInfo->mnc = 0;
            pTApi->_pBaseStationInfo->signalstrength = 100;
            pTApi->_pBaseStationInfo->type = 0;
            pTApi->_iBaseStationCount = 1;
        }
        pTApi->_pWifiInfo = new xsys_wifi_info_t;
        if (pTApi->_pWifiInfo)
        {
            pTApi->_pWifiInfo->ip = new xchar_t[32];
            strcpy((char *)pTApi->_pWifiInfo->ip, (const char *)"192,168.6.146");
            pTApi->_pWifiInfo->mac =new xchar_t[16];
            strcpy((char *)pTApi->_pWifiInfo->mac, (const char *)"00254b960bbb");
            pTApi->_pWifiInfo->name = new xchar_t[32];
            strcpy((char *)pTApi->_pWifiInfo->name, (const char *)"tiros608");
            pTApi->_pWifiInfo->signalstrength = 100;
        }
        pTApi->_pDeviceInfo = new xsys_device_info_t;
        if (pTApi->_pDeviceInfo)
        {
            pTApi->_pDeviceInfo->manufacturername = new xchar_t[32];
            strcpy((char *)pTApi->_pDeviceInfo->manufacturername, (const char *)"simulator");
            pTApi->_pDeviceInfo->devicemodel = new xchar_t[32];
            strcpy((char *)pTApi->_pDeviceInfo->devicemodel, (const char *)"qt");
            pTApi->_pDeviceInfo->osversion = new xchar_t[32];
            strcpy((char *)pTApi->_pDeviceInfo->osversion, (const char *)"1.0");
        }
    }
    return pTApi;
}
