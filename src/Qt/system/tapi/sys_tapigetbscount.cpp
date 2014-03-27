#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
unsigned char sys_tapigetbscount(xsys_tapi_t * ptapi)
{
    if ( ptapi )
        return ptapi->_iBaseStationCount;
    return 0;
}
