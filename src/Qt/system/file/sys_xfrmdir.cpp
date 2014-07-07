#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"
#include <QDir>

unsigned char xsys_xfile_fRmDir(const char * pszDir)
{
    bool bAsset;
    QString szdir = sys_fpathchange(pszDir, &bAsset);

    if (bAsset) return false;

    return QDir().rmpath(szdir);
}
