#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fGetSpace(const char * pszDisk)
{
    return 10 * 1024 * 1024 * 1024; // 默认空间10G
}

