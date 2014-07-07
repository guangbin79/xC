#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned char xsys_xfile_fRemove(const char * pszFilename)
{
    bool bAsset;

    QString szdir = sys_fpathchange(pszFilename, &bAsset);

    if (bAsset) return false;

    return QFile::remove(szdir);
}
