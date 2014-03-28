#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"

void sys_tapidestroy(xsys_tapi_t * ptapi)
{
    if (ptapi)
    {
        if (ptapi->_pBaseStationInfo)
            delete ptapi->_pBaseStationInfo;
        if (ptapi->_pWifiInfo)
        {
            if (ptapi->_pWifiInfo->ip)
                delete ptapi->_pWifiInfo->ip;
            if (ptapi->_pWifiInfo->mac)
                delete ptapi->_pWifiInfo->mac;
            if (ptapi->_pWifiInfo->name)
                delete ptapi->_pWifiInfo->name;
            delete ptapi->_pWifiInfo;
        }
        if (ptapi->_pDeviceInfo)
        {
            if (ptapi->_pDeviceInfo->manufacturername)
                delete ptapi->_pDeviceInfo->manufacturername;
            if (ptapi->_pDeviceInfo->devicemodel)
                delete ptapi->_pDeviceInfo->devicemodel;
            if (ptapi->_pDeviceInfo->osversion)
                delete ptapi->_pDeviceInfo->osversion;
            delete ptapi->_pDeviceInfo;
        }
        delete ptapi;
    }
}
