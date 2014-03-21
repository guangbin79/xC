#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fGetFreeSpace(const char * pszDisk)
{
    return 5 * 1024 * 1024 * 1024; // 默认可使用空间5G
}
