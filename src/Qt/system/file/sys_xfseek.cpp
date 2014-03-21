#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

unsigned int xsys_xfile_fSeek(xsys_file_t * pf, xsys_file_seek_type_t seekType, unsigned int moveDistance)
{
    switch (seekType)
    {
        case XSYS_FST_START:
            pf->qfile.seek(moveDistance);
            break;
        case XSYS_FST_END:
            pf->qfile.seek(pf->qfile.size());
            break;
        case XSYS_FST_CURRENT_DOWN:
            pf->qfile.seek(pf->qfile.pos() + moveDistance);
            break;
        case XSYS_FST_CURRENT_UP:
            pf->qfile.seek(pf->qfile.pos() - moveDistance);
            break;
    }

    return (unsigned int)pf->qfile.pos();
}
