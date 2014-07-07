#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"
#include <QDir>

unsigned char xsys_xfile_fMkDir(const char * pszDir)
{
     bool bAsset;

     QString szdir = sys_fpathchange(pszDir, &bAsset);

     if (bAsset) return false;

     if (!szdir.endsWith('/'))
     {
         szdir.append('/');
     }

     return QDir().mkpath(szdir);
}
