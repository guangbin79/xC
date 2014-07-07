#include "../../../xfile.h"
#include "../include/sys_xfile.h"
#include "../../../xpointer.h"

xfile_t * xfile_open(const xchar_t * filename, xopen_file_mode_t mode)
{
    return (xfile_t *)xsys_xfile_fOpen((const char *)filename, (xsys_open_file_mode_t)mode);
}

void xfile_close(xfile_t * pf)
{
    xsys_xfile_fClose((xsys_file_t *)pf);
}

xuint32_t xfile_write(xfile_t * pf, const void * pvBuf, xuint32_t bufSize)
{
    return xsys_xfile_fWrite((xsys_file_t *)pf, pvBuf, bufSize);
}

xuint32_t xfile_read(xfile_t * pf, void * pvBuf, xuint32_t bufSize)
{
    return xsys_xfile_fRead((xsys_file_t *)pf, pvBuf, bufSize);
}

xuint32_t xfile_seek(xfile_t * pf, xfile_seek_type_t seekType, xuint32_t moveDistance)
{
    return xsys_xfile_fSeek((xsys_file_t *)pf, (xsys_file_seek_type_t)seekType, moveDistance);
}

xuint32_t xfile_changeSize(xfile_t * pf, xuint32_t size)
{
    return xsys_xfile_fChSize((xsys_file_t *)pf, size);
}

xbool_t xfile_rename(const xchar_t * pszFilename1, const xchar_t * pszFilename2)
{
    return xsys_xfile_fRename((const char *)pszFilename1, (const char *)pszFilename2);
}

xbool_t xfile_remove(const xchar_t * pszFilename)
{
    return xsys_xfile_fRemove((const char *)pszFilename);
}

xbool_t xfile_exist(const xchar_t * pszFilename)
{
    return xsys_xfile_fExist((const char *)pszFilename);
}

xbool_t xfile_mkDir(const xchar_t * pszDir)
{
    return xsys_xfile_fMkDir((const char *)pszDir);
}

xbool_t xfile_removeDir(const xchar_t * pszDir)
{
    return xsys_xfile_fRmDir((const char *)pszDir);
}

xuint32_t xfile_getSize(const xchar_t * pszFilename)
{
    return xsys_xfile_fGetSize((const char *)pszFilename);
}

xuint32_t xfile_getSpace(const xchar_t * dir)
{
    return xsys_xfile_fGetSpace((const char *)dir);
}

xuint32_t xfile_getFreeSpace(const xchar_t * xfs)
{
    return xsys_xfile_fGetFreeSpace((const char *)xfs);
}

xfile_enum_t * xfile_enumStart(const xchar_t * pszDir, xbool_t bDirs)
{
    return (xfile_enum_t *)xsys_xfile_fEnumStart((const char *)pszDir, bDirs);
}

const xchar_t * xfile_enumNext(xfile_enum_t * pfe)
{
    return (const xchar_t *)(xsys_xfile_fEnumNext((xsys_file_enum_t *)pfe));
}

void xfile_enumEnd(xfile_enum_t * pfe)
{
    return xsys_xfile_fEnumEnd((xsys_file_enum_t *)pfe);
}

