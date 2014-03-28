#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

const char * xsys_xfile_fEnumNext(xsys_file_enum_t * pfe)
{
    if (pfe->pos == pfe->count)
    {
        return NULL;
    }

    while (pfe->pos != pfe->count)
    {
        QFileInfo qfileinfo = pfe->qFileInfoList.at(pfe->pos++);

        if (pfe->isdir && qfileinfo.isDir())
        {
            QString str = qfileinfo.filePath();
            int flag = str.lastIndexOf("/.");
            int size = str.size();

            if(flag != -1 && (flag == size - 2 || flag == size - 3))     ///< 不枚举 "/." 和 "/.."
            {
                continue;
            }

            return qfileinfo.fileName().toLatin1().data();
        }
        else if (!pfe->isdir && qfileinfo.isFile())
        {
            return qfileinfo.fileName().toLatin1().data();
        }
    }

    return NULL;
}
