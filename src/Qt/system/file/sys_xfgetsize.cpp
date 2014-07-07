#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fGetSize(const char * pszFilename)
{
    return (unsigned int)QFile(sys_fpathchange(pszFilename, NULL)).size();
}
