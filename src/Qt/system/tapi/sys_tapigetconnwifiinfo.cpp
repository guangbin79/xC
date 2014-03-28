#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
const xsys_wifi_info_t * sys_tapigetconnwifiinfo(xsys_tapi_t * ptapi)
{
    if (ptapi)
        return ptapi->_pWifiInfo;
    return 0;
}
