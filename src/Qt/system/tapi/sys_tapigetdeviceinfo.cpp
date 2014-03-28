#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
const xsys_device_info_t * sys_tapigetdeviceinfo(xsys_tapi_t * ptapi)
{
    if (ptapi)
        return ptapi->_pDeviceInfo;
    return 0;
}
