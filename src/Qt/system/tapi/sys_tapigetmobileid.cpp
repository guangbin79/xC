#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../../../xfile.h"
#include "../../../xmemory.h"
#include "../../include/sys_xtapi.h"
#include<stdlib.h>
#include<string.h>

#define KTIROS_LOCAL_MOBILE_ID_LEN 128

const xchar_t * sys_tapigetmobileid(xsys_tapi_t* )
{
    static xchar_t id[KTIROS_LOCAL_MOBILE_ID_LEN] = {'\0'};
    if (id[0] != '\0')
    {
        return id;
    }
    else
    {
        xbool_t needCallAPI = true;
        const xchar_t * fileName = (const xchar_t *)"fs0:/config/api/mobileid";
        xbool_t fileExist = xfile_exist(fileName);
        if (fileExist)
        {
            xfile_t * fileHandler = xfile_open((const xchar_t *)"fs0:/config/api/mobileid", XOFM_READ);
            if (fileHandler != NULL)
            {
                xuint32_t size =  xfile_read(fileHandler,
                                          (void*)id,
                                          KTIROS_LOCAL_MOBILE_ID_LEN);
                if (size != 0)
                {
                    id[size] = '\0';
                    needCallAPI = false;
                }
                xfile_close(fileHandler);
                fileHandler = NULL;
            }
        }
        if (needCallAPI)
        {
            const xchar_t * temp = (const xchar_t *)"123456789012345";
            if (temp != NULL)
            {
                xuint32_t size = strlen((char *)temp);
                memcpy(id, temp, size + 1);
                xfile_t * fileHandler = xfile_open((const xchar_t *)"fs0:/config/api/mobileid",
                                             XOFM_CREATE);
                if (fileHandler != NULL)
                {
                    xuint32_t realSize = xfile_write(fileHandler, temp, size);
                    xfile_close(fileHandler);
                    fileHandler = NULL;
                    if (size != realSize)
                    {
                        xfile_remove((const xchar_t *)"fs0:/config/api/mobileid");
                    }
                }
            }
        }
    }

    return id;
}
