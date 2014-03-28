#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
const xsys_base_station_info_t* sys_tapigetbsbyindex(xsys_tapi_t * ptapi, const unsigned char aIndex)
{
    if ( !ptapi || aIndex >= ptapi->_iBaseStationCount )
        return 0;
    return ptapi->_pBaseStationInfo;
}
