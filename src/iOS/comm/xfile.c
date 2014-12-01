#include "../../../xfile.h"
#include "../include/sys_file.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

xfile_t * xfile_open(const xchar_t * filename, xopen_file_mode_t mode)
{
    xdebug_assert(filename != XNULL);
    
    return (xfile_t *)sys_fopen(filename, (SYS_OpenFileMode)mode);
}

void xfile_fclose(xfile_t * pf)
{
    xdebug_assert(pf != XNULL);
    
    sys_fclose((SYS_File *)pf);
}

xuint32_t xfile_fwrite(xfile_t * pf, const void * pvBuf, xuint32_t bufSize)
{
    xdebug_assert(pf != XNULL && pvBuf != XNULL && bufSize != 0);
    
    return sys_fwrite((SYS_File *)pf, pvBuf, bufSize);
}

xuint32_t xfile_fread(xfile_t * pf, void * pvBuf, xuint32_t bufSize)
{
    xdebug_assert(pf != XNULL && pvBuf != XNULL && bufSize != 0);
    
    return sys_fread((SYS_File *)pf, pvBuf, bufSize);
}

xuint32_t xfile_fseek(xfile_t * pf, SYS_FileSeekType seekType, xuint32_t moveDistance)
{
    xdebug_assert(pf != XNULL);
    
    return sys_fseek((SYS_File *)pf, seekType, moveDistance);
}

xuint32_t xfile_fchsize(xfile_t * pf, xuint32_t size)
{
    xdebug_assert(pf != XNULL);
    
    return sys_fchsize((SYS_File *)pf, size);
}

xbool_t xfile_frename(const char * pszFilename1, const char * pszFilename2)
{
    xdebug_assert(pszFilename1 != XNULL && pszFilename2 != XNULL);
    
    return sys_frename(pszFilename1, pszFilename2);
}

xbool_t xfile_fremove(const char * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);
    
    return sys_fremove(pszFilename);
}

xbool_t xfile_fexist(const char * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);
    
    return sys_fexist(pszFilename);
}

xbool_t xfile_fmkdir(const char * pszDir)
{
    xdebug_assert(pszDir != XNULL);
    
    return sys_fmkdir(pszDir);
}

xbool_t xfile_frmdir(const char * pszDir)
{
    xdebug_assert(pszDir != XNULL);
    
    return sys_frmdir(pszDir);
}

xuint32_t xfile_fgetsize(const char * pszFilename)
{
    xdebug_assert(pszFilename != XNULL);
    
    return sys_fgetsize(pszFilename);
}

xuint32_t xfile_fgetspace(const char * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);
    
    return sys_fgetspace(pszDisk);
}

xuint32_t xfile_fgetfreespace(const char * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);
    
    return sys_fgetfreespace(pszDisk);
}

xfile_enum_t * xfile_fenumstart(const char * pszDir, xbool_t bDirs)
{
    xdebug_assert(pszDir != XNULL);
    
    return (xfile_enum_t *)sys_fenumstart(pszDir, bDirs);
}

const char * xfile_fenumnext(xfile_enum_t * pfe)
{
    xdebug_assert(pfe != XNULL);
    
    return sys_fenumnext((SYS_FileEnum *)pfe);
}

void xfile_fenumend(xfile_enum_t * pfe)
{
    xdebug_assert(pfe != XNULL);
    
    return sys_fenumend((SYS_FileEnum *)pfe);
}

xbool_t xfile_fdiskexist(const char * pszDisk)
{
    xdebug_assert(pszDisk != XNULL);
    return sys_fdiskexist(pszDisk);
}

