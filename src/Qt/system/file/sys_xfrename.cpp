#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned char xsys_xfile_fRename(const char * pszFilename1, const char * pszFilename2)
{
    bool bAsset1, bAsset2;
    QString szdir1 = sys_fpathchange(pszFilename1, &bAsset1);
    QString szdir2 = sys_fpathchange(pszFilename2, &bAsset2);

    if (bAsset1 || bAsset2) return false;

    return QFile::rename(szdir1, szdir2);
}
