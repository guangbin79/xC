#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fChSize(xsys_file_t * pf, unsigned int size)
{
    pf->qfile.resize(size);

    return (unsigned int)pf->qfile.size();
}
