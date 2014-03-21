#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

void xsys_xfile_fClose(xsys_file_t * pf)
{
    pf->qfile.close();
    delete pf;
}
