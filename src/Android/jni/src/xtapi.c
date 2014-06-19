#include "../../../xtapi.h"
#include "../jni_include/sys_xtapi.h"
#include "../jni_include/sys_xfile.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../../../xfile.h"
#include "../../../xmemory.h"
#include <string.h>
//#include "../../../../api/universal/string.h"

#define KTirosLocalMobileIdLen 128

xtapi_t* xtapi_create()
{
    return (xtapi_t*)sys_tapicreate();
}

void xtapi_destroy(xtapi_t* ptapi)
{
    sys_tapidestroy((xsys_tapi_t*)ptapi);
}

xuint8_t xtapi_getBsCount(xtapi_t* ptapi)
{
    return sys_tapigetbscount((xsys_tapi_t*)ptapi);
}

const xbase_station_info_t* xtapi_getBsByIndex(xtapi_t* ptapi, const xuint8_t aIndex)
{
    return (const xbase_station_info_t*)sys_tapigetbsbyindex((xsys_tapi_t*)ptapi, aIndex);
}

const xwifi_info_t* xtapi_getConnWifiInfo(xtapi_t* ptapi)
{
    return (const xwifi_info_t*)sys_tapigetconnwifiinfo((xsys_tapi_t*)ptapi);
}

const xchar_t * xtapi_getMobileId(xtapi_t * ptapi)
{
    static char id[KTirosLocalMobileIdLen] = {'\0'};
    if (id[0] != '\0')
    {
        return id;
    }
    else
    {
    	xbool_t needCallAPI = XTRUE;
        const char* fileName = "fs0:/config/api/mobileid";
        xbool_t fileExist = xsys_xfile_fExist(fileName);
        if (fileExist)
        {
        	xsys_file_t* fileHandler = xsys_xfile_fOpen("fs0:/config/api/mobileid", XSYS_OFM_READ);
            if (fileHandler != XNULL)
            {
                xuint32_t size =  xsys_xfile_fRead(fileHandler,
                                          (void*)id,
                                          KTirosLocalMobileIdLen);
                if (size != 0)
                {
                    id[size] = '\0';
                    needCallAPI = XFALSE;
                }
                xsys_xfile_fClose(fileHandler);
                fileHandler = XNULL;
            }
        }
        if (needCallAPI)
        {
            const char* temp = sys_tapigetmobileid( (xsys_tapi_t*) ptapi);
            if (temp != XNULL)
            {
                xuint32_t size = strlen(temp);
                memcpy(id, temp, size + 1);
                xsys_file_t* fileHandler = xsys_xfile_fOpen("fs0:/config/api/mobileid",
                		XSYS_OFM_CREATE);
                if (fileHandler != XNULL)
                {
                    xuint32_t realSize = xsys_xfile_fWrite(fileHandler, temp, size);
                    xsys_xfile_fClose(fileHandler);
                    fileHandler = NULL;
                    if (size != realSize)
                    {
                    	xsys_xfile_fRemove("fs0:/config/api/mobileid");
                    }
                }
            }
        }
    }
    
    return id;
}

const xchar_t* xtapi_getImsi(xtapi_t* ptapi)
{
    return sys_tapigetimsi( (xsys_tapi_t*) ptapi);
}

int xtapi_getNetTypes(xtapi_t* ptapi)
{
    return sys_tapigetnettype( (xsys_tapi_t*) ptapi);
}

const xdevice_info_t* xtapi_getDeviceInfo(xtapi_t* ptapi)
{
    return (const xdevice_info_t*)sys_tapigetdeviceinfo( (xsys_tapi_t*) ptapi);
}
