//
//  sys_fmkdir.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdlib.h"
#include <sys/stat.h>


#ifdef __cplusplus
extern "C" {
#endif
	
	size_t strlen(const char *);
	char * strcat(char *, const char *);
	
#ifdef __cplusplus
}
#endif
unsigned char sys_fmkdir(const char * pszDir)
{
	char* pPath = fpathchange(pszDir);
	if(pPath == NULL)
	{
		return false;
	}	
//    BOOL isDir;
    NSFileManager * fileManager = [NSFileManager defaultManager];
//    if(NO==[fileManager fileExistsAtPath:[NSString stringWithFormat:@"%s",pPath] isDirectory:&isDir] ) {

        [fileManager createDirectoryAtPath:[NSString stringWithFormat:@"%s",pPath]withIntermediateDirectories:YES attributes:nil error:0];
        free(pPath);
        return 1;
//    }
//    free(pPath);
//    return true;
    
//    char s[255];
//    char* dir2 = pPath;
//    if(pPath[strlen(pPath) - 1] != '/')
//    {
//        strcat(pPath,"/");
//    }
//    if (dir2[0] == '/')
//        dir2++;
//    const char* sdir = strchr(dir2, '/');
//    while (sdir) {
//        strncpy(s, pPath, sdir - pPath);
//        s[sdir - pPath] = '\0';
//        //        printf(s);
//        //        printf("\r\n");
//        mkdir(s, 0777);
//        sdir++;
//        sdir = strchr(sdir, '/');
//    }
//    free(pPath);
//	return true;
    
}