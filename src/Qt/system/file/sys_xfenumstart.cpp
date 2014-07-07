#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

xsys_file_enum_t * xsys_xfile_fEnumStart(const char * pszDir, unsigned char bDirs)
{
    xsys_file_enum_t * pfileEnum = new xsys_file_enum_t;

    if (NULL == pfileEnum)
    {
        return NULL;
    }

    pfileEnum->qdir.setPath(sys_fpathchange(pszDir, NULL));
    pfileEnum->qFileInfoList = pfileEnum->qdir.entryInfoList();
    pfileEnum->isdir = bDirs;
    pfileEnum->pos = 0;
    pfileEnum->count = pfileEnum->qFileInfoList.count();

    return pfileEnum;
}
