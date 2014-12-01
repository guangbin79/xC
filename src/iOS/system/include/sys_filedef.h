#ifndef _SYS_FILEDEF_H_
#define _SYS_FILEDEF_H_
#include "dirent.h"
#include "stdio.h"

#define _MAX_FILENAME_LENGTH (256 * 3)
#define PRIVATE_PATH_LEN 60
#define IPHONE_DIR "/work/svn/data/"


typedef struct _SYS_File
{
	FILE *fs;
	char *fname;
} SYS_File;

typedef struct _SYS_FileEnum
{
    DIR* directory;
    char * pszDir;
    int pos;
    bool isdir;
    char name[_MAX_FILENAME_LENGTH];
} SYS_FileEnum;

#ifdef __cplusplus
extern "C" {
#endif
    
    char * fpathchange(const char * pszFilename);
    
#ifdef __cplusplus
}
#endif


#endif
