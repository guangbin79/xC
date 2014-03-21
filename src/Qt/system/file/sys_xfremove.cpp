#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned char xsys_xfile_fRemove(const char * pszFilename)
{
    return QFile::remove(sys_fpathchange(pszFilename));
}
