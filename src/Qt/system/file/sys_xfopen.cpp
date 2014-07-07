#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"
#include <QString>

static unsigned char createfile(xsys_file_t * pfile, const char * pszFilename);

xsys_file_t * xsys_xfile_fOpen(const char * pszFilename, xsys_open_file_mode_t mode)
{
    xsys_file_t * pfile = new xsys_file_t;
    bool bAsset;

    if (NULL == pfile)
    {
        return NULL;
    }

    pfile->qfile.setFileName(sys_fpathchange(pszFilename, &bAsset));

    switch (mode)
    {
    case XSYS_OFM_READ:
        if(xsys_xfile_fExist(pszFilename) && pfile->qfile.open(QIODevice::ReadOnly))
        {
            return pfile;
        }
        break;
    case XSYS_OFM_READWRITE:
        if (bAsset) return NULL;

        if(xsys_xfile_fExist(pszFilename) && pfile->qfile.open(QIODevice::ReadWrite))
        {
            return pfile;
        }
        break;
    case XSYS_OFM_APPEND:
        if (bAsset) return NULL;

        if (xsys_xfile_fExist(pszFilename) && pfile->qfile.open(QIODevice::ReadWrite) && pfile->qfile.seek(pfile->qfile.size()))
        {
            return pfile;
        }
        break;
    case XSYS_OFM_CREATE:
        if (bAsset) return NULL;

        if(!xsys_xfile_fExist(pszFilename) && createfile(pfile, pszFilename))
        {
            return pfile;
        }
        break;
    }

    delete pfile;

    return NULL;
}

static unsigned char createfile(xsys_file_t * pfile, const char * pszFilename)
{
    QString path = sys_fpathchange(pszFilename, NULL);

    // 创建目录
    int flag = path.lastIndexOf('/');

    if (-1 != flag)
    {
        if (!QDir().mkpath(path.left(flag)))
        {
            return 0;
        }
    }

    // 创建文件
    pfile->qfile.open(QIODevice::ReadWrite);

    return 1;
}
