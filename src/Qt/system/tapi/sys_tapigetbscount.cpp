#include "../../include/sys_xtapi.h"
#include "../../system/include/sys_xtapidef.h"
xuint8_t sys_tapigetbscount(xsys_tapi_t * ptapi)
{
    if (ptapi)
        return (xuint8_t)ptapi->_iBaseStationCount;
    return 0;
}
