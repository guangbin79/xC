#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned char xsys_xfile_fRename(const char * pszFilename1, const char * pszFilename2)
{
    return QFile::rename(sys_fpathchange(pszFilename1), sys_fpathchange(pszFilename2));
}
