#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"
#include <QDir>

unsigned char xsys_xfile_fRmDir(const char * pszDir)
{
    return QDir().rmpath(sys_fpathchange(pszDir));
}
