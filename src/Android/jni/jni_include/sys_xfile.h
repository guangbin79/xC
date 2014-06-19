#ifndef _SYS_XFILE_H_
#define _SYS_XFILE_H_

typedef struct _xsys_file_t      xsys_file_t;
typedef struct _xsys_file_enum_t  xsys_file_enum_t;

typedef enum _xsys_open_file_mode_t
{
    XSYS_OFM_READ,
    XSYS_OFM_READWRITE,
    XSYS_OFM_APPEND,
    XSYS_OFM_CREATE
} xsys_open_file_mode_t;

typedef enum _xsys_file_seek_type_t
{
    XSYS_FST_START,
    XSYS_FST_END,
    XSYS_FST_CURRENT_DOWN,
    XSYS_FST_CURRENT_UP
} xsys_file_seek_type_t;

#ifdef __cplusplus
extern "C" {
#endif

xsys_file_t * xsys_xfile_fOpen(const char * pszFilename, xsys_open_file_mode_t mode);
void xsys_xfile_fClose(xsys_file_t * pf);
unsigned int xsys_xfile_fWrite(xsys_file_t * pf, const void * pvBuf, unsigned int bufSize);
unsigned int xsys_xfile_fRead(xsys_file_t * pf, void * pvBuf, unsigned int bufSize);
unsigned int xsys_xfile_fSeek(xsys_file_t * pf, xsys_file_seek_type_t seekType, unsigned int moveDistance);
unsigned int xsys_xfile_fChSize(xsys_file_t * pf, unsigned int size);
unsigned char xsys_xfile_fRename(const char * pszFilename1, const char * pszFilename2);
unsigned char xsys_xfile_fRemove(const char * pszFilename);
unsigned char xsys_xfile_fExist(const char * pszFilename);
unsigned char xsys_xfile_fMkDir(const char * pszDir);
unsigned char xsys_xfile_fRmDir(const char * pszDir);
unsigned int xsys_xfile_fGetSize(const char * pszFilename);
unsigned int xsys_xfile_fGetSpace(const char * pszDisk);
unsigned int xsys_xfile_fGetFreeSpace(const char * pszDisk);
xsys_file_enum_t * xsys_xfile_fEnumStart(const char * pszDir, unsigned char bDirs);
const char * xsys_xfile_fEnumNext(xsys_file_enum_t * pfe);
void xsys_xfile_fEnumEnd(xsys_file_enum_t * pfe);
unsigned char xsys_xfile_fDiskExist(const char * pszDisk);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_XFILE_H_ */
