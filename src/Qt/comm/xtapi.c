#include "../../include/sys_tapi.h"
#include "../../../../universal/string.h"
#include"../include/sys_tapidef.h"

xtapi_t * xtapi_create()
{
    SYS_TAPI* pTApi = new SYS_TAPI;
    if ( pTApi )
    {
        pTApi->_iBaseStationCount = 0;
        pTApi->_pBaseStationInfo = new SYS_BaseStationInfo;
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
        pTApi->_pWifiInfo = new SYS_WifiInfo;
        if ( pTApi->_pWifiInfo )
        {
            pTApi->_pWifiInfo->ip = new char[32];
            strcpy(pTApi->_pWifiInfo->ip,  "192,168.6.146");
            pTApi->_pWifiInfo->mac =new char[16];
            strcpy(pTApi->_pWifiInfo->mac,  "00254b960bbb");
            pTApi->_pWifiInfo->name = new char[32];
            strcpy(pTApi->_pWifiInfo->name, "tiros608");
            pTApi->_pWifiInfo->signalstrength = 100;
        }
        pTApi->_pDeviceInfo = new SYS_DeviceInfo;
        if ( pTApi->_pDeviceInfo )
        {
            pTApi->_pDeviceInfo->manufacturername = new char[32];
            strcpy(pTApi->_pDeviceInfo->manufacturername,  "simulator");
            pTApi->_pDeviceInfo->devicemodel = new char[32];
            strcpy(pTApi->_pDeviceInfo->devicemodel,  "qt");
            pTApi->_pDeviceInfo->osversion = new char[32];
            strcpy(pTApi->_pDeviceInfo->osversion,  "1.0");
        }
    }
    return pTApi;
}

void xtapi_destroy(xtapi_t * pxtapi)
{
    if ( ptapi )
    {
        if (ptapi->_pBaseStationInfo)
            delete ptapi->_pBaseStationInfo;
        if (ptapi->_pWifiInfo)
        {
            if ( ptapi->_pWifiInfo->ip )
                delete ptapi->_pWifiInfo->ip;
            if ( ptapi->_pWifiInfo->mac )
                delete ptapi->_pWifiInfo->mac;
            if ( ptapi->_pWifiInfo->name )
                delete ptapi->_pWifiInfo->name;
            delete ptapi->_pWifiInfo;
        }
        if ( ptapi->_pDeviceInfo )
        {
            if ( ptapi->_pDeviceInfo->manufacturername )
                delete ptapi->_pDeviceInfo->manufacturername;
            if ( ptapi->_pDeviceInfo->devicemodel )
                delete ptapi->_pDeviceInfo->devicemodel;
            if ( ptapi->_pDeviceInfo->osversion )
                delete ptapi->_pDeviceInfo->osversion;
            delete ptapi->_pDeviceInfo;
        }
        delete ptapi;
    }
}


xuint8_t xtapi_getBsCount(xtapi_t * pxtapi)
{
    if ( ptapi )
        return ptapi->_iBaseStationCount;
    return 0;
}

const xbase_station_info_t * xtapi_getBsByIndex(xtapi_t * pxtapi, const xuint8_t index)
{
    if ( !ptapi || aIndex >= ptapi->_iBaseStationCount )
        return 0;
    return ptapi->_pBaseStationInfo;
}

const xwifi_info_t * xtapi_getConnWifiInfo(xtapi_t * pxtapi)
{
    if ( ptapi )
        return ptapi->_pWifiInfo;
    return 0;
}

const xchar_t * xtapi_getMobileId(xtapi_t * pxtapi)
{
    return "123456789012345";
}

const xchar_t * xtapi_getImsi(xtapi_t * pxtapi)
{
    return "000000000000000";
}

xdevice_info_t xtapi_getNetType(xtapi * pxtapi)
{
    return 0;
}

const xdevice_info_t * xtapi_getDeviceInfo(xtapi_t * pxtapi)
{
    if ( ptapi )
        return ptapi->_pDeviceInfo;
    return 0;
}
