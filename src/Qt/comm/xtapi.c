#include "../../xtapi.h"
#include "../include/sys_xtapi.h"

xtapi_t * xtapi_create()
{
    return (xtapi_t *)sys_tapicreate();
}

void xtapi_destroy(xtapi_t * pxtapi)
{
    sys_tapidestroy((xsys_tapi_t *)pxtapi);
}

xuint8_t xtapi_getBsCount(xtapi_t * pxtapi)
{
    return sys_tapigetbscount((xsys_tapi_t *)pxtapi);
}

const xbase_station_info_t * xtapi_getBsByIndex(xtapi_t * pxtapi, const xuint8_t index)
{
    return (const xbase_station_info_t *)sys_tapigetbsbyindex((xsys_tapi_t *)pxtapi, index);
}

const xwifi_info_t * xtapi_getConnWifiInfo(xtapi_t * pxtapi)
{
    return (const xwifi_info_t *)sys_tapigetconnwifiinfo((xsys_tapi_t *)pxtapi);
}

const xchar_t * xtapi_getMobileId(xtapi_t * pxtapi)
{
    return sys_tapigetmobileid((xsys_tapi_t *) pxtapi);
}

const xchar_t * xtapi_getImsi(xtapi_t * pxtapi)
{
    return (xchar_t *)sys_tapigetimsi( (xsys_tapi_t *) pxtapi);
}

xnet_type_t xtapi_getNetType(xtapi_t * pxtapi)
{
    return (xnet_type_t)sys_tapigetnettype( (xsys_tapi_t *) pxtapi);
}

const xdevice_info_t * xtapi_getDeviceInfo(xtapi_t * pxtapi)
{
    return (const xdevice_info_t *)sys_tapigetdeviceinfo( (xsys_tapi_t *) pxtapi);
}
