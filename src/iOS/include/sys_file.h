#ifndef _TR_SYS_FILE_H_
#define _TR_SYS_FILE_H_

#include "../../../xinteger.h"
#include "../../../xcharacter.h"

typedef struct _SYS_File      SYS_File;
typedef struct _SYS_FileEnum  SYS_FileEnum;

typedef enum _SYS_OpenFileMode
{
    SYS_OFM_READ,
    SYS_OFM_READWRITE,
    SYS_OFM_APPEND,
    SYS_OFM_CREATE
} SYS_OpenFileMode;

typedef enum _SYS_FileSeekType
{
    SYS_FST_START,
    SYS_FST_END,
    SYS_FST_CURRENT_DOWN,
    SYS_FST_CURRENT_UP
} SYS_FileSeekType;

#ifdef __cplusplus
extern "C" {
#endif

SYS_File * sys_fopen(const xchar_t * pszFilename, SYS_OpenFileMode mode);
void sys_fclose(SYS_File * pf);
xsize_t sys_fwrite(SYS_File * pf, const void * pvBuf, xsize_t bufSize);
xsize_t sys_fread(SYS_File * pf, void * pvBuf, xsize_t bufSize);
xsize_t sys_fseek(SYS_File * pf, SYS_FileSeekType seekType, xsize_t moveDistance);
unsigned int sys_fchsize(SYS_File * pf, unsigned int size);
unsigned char sys_frename(const char * pszFilename1, const char * pszFilename2);
unsigned char sys_fremove(const char * pszFilename);
unsigned char sys_fexist(const char * pszFilename);
unsigned char sys_fmkdir(const char * pszDir);
unsigned char sys_frmdir(const char * pszDir);
unsigned int sys_fgetsize(const char * pszFilename);
unsigned int sys_fgetspace(const char * pszDisk);
unsigned int sys_fgetfreespace(const char * pszDisk);
SYS_FileEnum * sys_fenumstart(const char * pszDir, unsigned char bDirs);
const char * sys_fenumnext(SYS_FileEnum * pfe);
void sys_fenumend(SYS_FileEnum * pfe);
unsigned char sys_fdiskexist(const char * pszDisk);
//bool sys_freadline(char* str, xsize_t size, SYS_File * pf);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_FILE_H_ */
