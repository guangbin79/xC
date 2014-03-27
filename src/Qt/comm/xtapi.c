#include "../../xtapi.h"
#include "../include/sys_xtapi.h"
#include "../../xdebug.h"
#include "../../xpointer.h"
#include "../../xfile.h"
#include "../../xmemory.h"
#define KTirosLocalMobileIdLen 128

xtapi_t * xtapi_create()
{
    return (TAPI*)sys_tapicreate();
}

void xtapi_destroy(xtapi_t * pxtapi)
{
    sys_tapidestroy((SYS_TAPI*)ptapi);
}

xuint8_t xtapi_getBsCount(xtapi_t * pxtapi)
{
    return sys_tapigetbscount((SYS_TAPI*)ptapi);
}

const xbase_station_info_t * xtapi_getBsByIndex(xtapi_t * pxtapi, const xuint8_t index)
{
    return (const BaseStationInfo*)sys_tapigetbsbyindex((SYS_TAPI*)ptapi, aIndex);
}

const xwifi_info_t * xtapi_getConnWifiInfo(xtapi_t * pxtapi)
{
    return (const WifiInfo*)sys_tapigetconnwifiinfo((SYS_TAPI*)ptapi);
}

const xchar_t * xtapi_getMobileId(xtapi_t * pxtapi)
{
    static char id[KTirosLocalMobileIdLen] = {'\0'};
    if (id[0] != '\0')
    {
        return id;
    }
    else
    {
        bool needCallAPI = true;
        const char* fileName = "fs0:/config/api/mobileid";
        bool fileExist = tr_fexist(fileName);
        if (fileExist)
        {
            File* fileHandler = tr_fopen("fs0:/config/api/mobileid", OFM_READ);
            if (fileHandler != NULL)
            {
                uint32_t size =  tr_fread(fileHandler,
                                          (void*)id,
                                          KTirosLocalMobileIdLen);
                if (size != 0)
                {
                    id[size] = '\0';
                    needCallAPI = false;
                }
                tr_fclose(fileHandler);
                fileHandler = NULL;
            }
        }
        if (needCallAPI)
        {
            const char* temp = sys_tapigetmobileid( (SYS_TAPI*) ptapi);
            if (temp != NULL)
            {
                uint32_t size = strlen(temp);
                memcpy(id, temp, size + 1);
                File* fileHandler = tr_fopen("fs0:/config/api/mobileid",
                                             OFM_CREATE);
                if (fileHandler != NULL)
                {
                    uint32_t realSize = tr_fwrite(fileHandler, temp, size);
                    tr_fclose(fileHandler);
                    fileHandler = NULL;
                    if (size != realSize)
                    {
                        tr_fremove("fs0:/config/api/mobileid");
                    }
                }
            }
        }
    }

    return id;
}

const xchar_t * xtapi_getImsi(xtapi_t * pxtapi)
{
    return sys_tapigetimsi( (SYS_TAPI*) ptapi);
}

xdevice_info_t xtapi_getNetType(xtapi * pxtapi)
{
    return sys_tapigetnettype( (SYS_TAPI*) ptapi);
}

const xdevice_info_t * xtapi_getDeviceInfo(xtapi_t * pxtapi)
{
    return (const DeviceInfo*)sys_tapigetdeviceinfo( (SYS_TAPI*) ptapi);
}
