#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned char xsys_xfile_fExist(const char * pszFilename)
{
    QString path = sys_fpathchange(pszFilename, NULL);

    return QFile::exists(path);
}
