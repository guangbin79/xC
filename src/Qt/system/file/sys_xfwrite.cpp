#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fWrite(xsys_file_t * pf, const void * pvBuf, unsigned int bufSize)
{
    qint64 writeLen = (unsigned int)pf->qfile.write((char *)pvBuf, bufSize);

    if (-1 == writeLen)
    {
        return 0;
    }
    else
    {
        return (unsigned int)writeLen;
    }
}
