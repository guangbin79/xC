#include "../../xfile.h"
#include "../include/sys_xfile.h"
#include "../../xdebug.h"
#include "../../xpointer.h"

xfile_t * xfile_open(const xchar_t * filename, xopen_file_mode_t mode)
{
    xdebug_assert(filename != XNULL);

    return (xfile_t *)xsys_xfile_fOpen((const char *)filename, (xsys_open_file_mode_t)mode);
}

void xfile_close(xfile_t * pf)
{
    xdebug_assert(pf != XNULL);

    xsys_xfile_fClose((xsys_file_t *)pf);
}

xuint32_t xfile_write(xfile_t * pf, const void * pvBuf, xuint32_t bufSize)
{
    xdebug_assert(pf != XNULL && pvBuf != XNULL && bufSize != 0);

    return xsys_xfile_fWrite((xsys_file_t *)pf, pvBuf, bufSize);
}

xuint32_t xfile_read(xfile_t * pf, void * pvBuf, xuint32_t bufSize)
{
    xdebug_assert(pf != XNULL && pvBuf != XNULL && bufSize != 0);

    return xsys_xfile_fRead((xsys_file_t *)pf, pvBuf, bufSize);
}

xuint32_t xfile_seek(xfile_t * pf, xfile_seek_type_t seekType, xuint32_t moveDistance)
{
    xdebug_assert(pf != XNULL);

    return xsys_xfile_fSeek((xsys_file_t *)pf, (xsys_file_seek_type_t)seekType, moveDistance);
}

xuint32_t xfile_changeSize(xfile_t * pf, xuint32_t size)
{
    xdebug_assert(pf != XNULL);

    return xsys_xfile_fChSize((xsys_file_t *)pf, size);
}

xbool_t xfile_rename(const xchar_t * pszFilename1, const xchar_t * pszFilename2)
{
    xdebug_assert(pszFilename1 != XNULL && pszFilename2 != XNULL);

    return xsys_xfile_fRename((const char *)pszFilename1, (const char *)pszFilename2);
}

xbool_t xfile_remove(const xchar_t * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);

    return xsys_xfile_fRemove((const char *)pszFilename);
}

xbool_t xfile_exist(const xchar_t * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);

    return xsys_xfile_fExist((const char *)pszFilename);
}

xbool_t xfile_mkDir(const xchar_t * pszDir)
{
    xdebug_assert(pszDir != XNULL);

    return xsys_xfile_fMkDir((const char *)pszDir);
}

xbool_t xfile_removeDir(const xchar_t * pszDir)
{
    xdebug_assert(pszDir != XNULL);

    return xsys_xfile_fRmDir((const char *)pszDir);
}

xuint32_t xfile_getSize(const xchar_t * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);

    return xsys_xfile_fGetSize((const char *)pszFilename);
}

xuint32_t xfile_getSpace(const xchar_t * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);

    return xsys_xfile_fGetSpace((const char *)pszDisk);
}

xuint32_t xfile_getFreeSpace(const xchar_t * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);

    return xsys_xfile_fGetFreeSpace((const char *)pszDisk);
}

xfile_enum_t * xfile_enumStart(const xchar_t * pszDir, xbool_t bDirs)
{
    xdebug_assert(pszDir != XNULL);

    return (xfile_enum_t *)xsys_xfile_fEnumStart((const char *)pszDir, bDirs);
}

const xchar_t * xfile_enumNext(xfile_enum_t * pfe)
{
    xdebug_assert(pfe != XNULL);

    return (const xchar_t *)(xsys_xfile_fEnumNext((xsys_file_enum_t *)pfe));
}

void xfile_enumEnd(xfile_enum_t * pfe)
{
    xdebug_assert(pfe != XNULL);

    return xsys_xfile_fEnumEnd((xsys_file_enum_t *)pfe);
}

xbool_t xfile_diskExist(const xchar_t * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);
    return xsys_xfile_fDiskExist((const char *)pszDisk);
}

