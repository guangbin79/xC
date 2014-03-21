#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fRead(xsys_file_t * pf, void * pvBuf, unsigned int bufSize)
{
    qint64 readLen = (unsigned int)pf->qfile.read((char *)pvBuf, bufSize);

    if (-1 == readLen)
    {
        return 0;
    }
    else
    {
        return (unsigned int)readLen;
    }
}

