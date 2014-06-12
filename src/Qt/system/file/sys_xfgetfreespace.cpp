#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fGetFreeSpace(const char * )
{
    return 500 * 1024 * 1024; // 默认可使用空间500M
}
