#ifndef _SYS_XTAPIDEF_H_
#define _SYS_XTAPIDEF_H_

#include "../../include/sys_xtapi.h"

typedef struct _xsys_tapi_t
{
	int	_iBaseStationCount;
    xsys_base_station_info_t * _pBaseStationInfo;
    xsys_wifi_info_t *	_pWifiInfo;
    xsys_device_info_t * _pDeviceInfo;
} xsys_tapi_t;

#endif // _SYS_XTAPIDEF_H_
