#include "../../../xfile.h"
#include "../include/sys_file.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

xfile_t * xfile_open(const xchar_t * pszFilename, xopen_file_mode_t mode)
{
    XASSERT(pszFilename != XNULL);

    return (xfile_t *)sys_fopen(pszFilename, mode);
}

void xfile_close(xfile_t * pf)
{
    XASSERT(pf != XNULL);

    sys_fclose((SYS_File *)pf);
}

xuint32_t xfile_write(xfile_t * pf, const void * pvBuf, xuint32_t bufSize)
{
    XASSERT(pf != XNULL && pvBuf != XNULL && bufSize != 0);

    return sys_fwrite((SYS_File *)pf, pvBuf, bufSize);
}

xuint32_t xfile_read(xfile_t * pf, void * pvBuf, xuint32_t bufSize)
{
    XASSERT(pf != XNULL && pvBuf != XNULL && bufSize != 0);

    return sys_fread((SYS_File *)pf, pvBuf, bufSize);
}

xuint32_t xfile_seek(xfile_t * pf, xfile_seek_type_t seekType, xuint32_t moveDistance)
{
    XASSERT(pf != XNULL);

    return sys_fseek((SYS_File *)pf, seekType, moveDistance);
}

xuint32_t xfile_changeSize(xfile_t * pf, xuint32_t size)
{
    XASSERT(pf != XNULL);

    return sys_fchsize((SYS_File *)pf, size);
}

xbool_t xfile_rename(const xchar_t * pszFilename1, const xchar_t * pszFilename2)
{
    XASSERT(pszFilename1 != XNULL && pszFilename2 != XNULL);

    return sys_frename(pszFilename1, pszFilename2);
}

xbool_t xfile_remove(const xchar_t * pszFilename)
{
    XASSERT(pszFilename != XNULL);

    return sys_fremove(pszFilename);
}

xbool_t xfile_exist(const xchar_t * pszFilename)
{
    XASSERT(pszFilename != XNULL);

    return sys_fexist(pszFilename);
}

xbool_t xfile_mkDir(const xchar_t * pszDir)
{
    XASSERT(pszDir != XNULL);

    return sys_fmkdir(pszDir);
}

xbool_t xfile_removeDir(const xchar_t * pszDir)
{
    XASSERT(pszDir != XNULL);

    return sys_frmdir(pszDir);
}

xuint32_t xfile_getSize(const xchar_t * pszFilename)
{
    XASSERT(pszFilename != XNULL);

    return sys_fgetsize(pszFilename);
}

xuint32_t xfile_getSpace(const xchar_t * pszDisk)
{
    XASSERT(pszDisk != XNULL);

    return sys_fgetspace(pszDisk);
}

xuint32_t xfile_getFreeSpace(const xchar_t * pszDisk)
{
    XASSERT(pszDisk != XNULL);

    return sys_fgetfreespace(pszDisk);
}

xfile_enum_t * xfile_enumStart(const xchar_t * pszDir, xbool_t bDirs)
{
    XASSERT(pszDir != XNULL);

    return (xfile_enum_t *)sys_fenumstart(pszDir, bDirs);
}

const xchar_t * xfile_enumNext(xfile_enum_t * pfe)
{
    XASSERT(pfe != XNULL);

    return sys_fenumnext((SYS_FileEnum *)pfe);
}

void xfile_enumEnd(xfile_enum_t * pfe)
{
    XASSERT(pfe != XNULL);

    return sys_fenumend((SYS_FileEnum *)pfe);
}

//xbool_t xfile_exist(const xchar_t * pszDisk)
//{
//    XASSERT(pszDisk != XNULL);
//    
//    return sys_fdiskexist(pszDisk);
//}

//bool tr_freadline(char* str, size_t size, File  * pf)
//{
//    XASSERT(pf != NULL && str != NULL);
//    
//    return sys_freadline(str,size,(SYS_File *)pf);
//}

