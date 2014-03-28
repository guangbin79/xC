#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"
#include <QDir>

unsigned char xsys_xfile_fMkDir(const char * pszDir)
{
     QString szdir = sys_fpathchange(pszDir);

     if (!szdir.endsWith('/'))
     {
         szdir.append('/');
     }

     return QDir().mkpath(szdir);
}
