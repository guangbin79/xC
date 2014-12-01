//
//  sys_fopen.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "../../include/sys_file.h"
#include "../include/sys_filedef.h"
#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>


SYS_File * sys_fopen(const char * pszFilename, SYS_OpenFileMode mode)
{
	SYS_File* pSysFile = (SYS_File*)malloc(sizeof(SYS_File));
   
	if (pSysFile == NULL) {
		return NULL;
	}

	char *pPath = fpathchange(pszFilename);
	if(pPath == NULL)
	{
		free(pSysFile);
		return NULL;
	}
	BOOL isExist = [ [NSFileManager defaultManager] fileExistsAtPath:[NSString stringWithFormat:@"%s",pPath]];
//	BOOL bNULL = isExist?(mode == SYS_OFM_CREATE?YES:NO):(mode != SYS_OFM_CREATE?YES:NO);
//	if (bNULL)
//	{
//		free(pPath);
//		free(pSysFile);
//		return NULL;
//	}
    if (isExist) {
        if (mode == SYS_OFM_CREATE) {
            mode = SYS_OFM_READWRITE;
        }
    }
    else
    {
        if (mode != SYS_OFM_CREATE)
        {
            free(pPath);
            free(pSysFile);
            return NULL;
        }
    }
	switch(mode)
	{
		case SYS_OFM_READ:
			pSysFile->fs = fopen(pPath,"r");
			break;
		case SYS_OFM_READWRITE:
			pSysFile->fs = fopen(pPath,"r+");
			break;
		case SYS_OFM_APPEND:
			pSysFile->fs = fopen(pPath,"a+");
			break;
		case SYS_OFM_CREATE:
		{
//            NSString* tempPath = [NSString stringWithFormat:@"%s",pPath];
//            NSArray * array = [ tempPath componentsSeparatedByString:@"/"];
//            NSMutableString* dirStr = [[NSMutableString alloc] init];
//            for (int i =0; i<[array count]-1; i++) {
//                [dirStr appendString:[array objectAtIndex:i]];
//                [dirStr appendString:@"/"];
//            }
//            
//            NSFileManager * fileManager = [NSFileManager defaultManager];
//            NSError* err = nil;
//            BOOL isSuccess =  [fileManager createDirectoryAtPath:dirStr withIntermediateDirectories:YES attributes:nil error:&err];
//            [dirStr release];
//            isSuccess = [fileManager createFileAtPath:[NSString stringWithFormat:@"%s",pPath] contents:nil attributes:nil];
            char* s = strrchr(pPath, '/');
            if (s)
            {
                *s = '\0';
                sys_fmkdir(pPath);
                *s = '/';
            }
            pSysFile->fs = fopen(pPath,"wb+");
            
			break;
		}
		default:
			break;
	}
	
	if(pSysFile->fs == NULL)
	{
		free(pPath);
		free(pSysFile);
		return NULL;
	}
    
	pSysFile->fname = pPath;
	return pSysFile;
}


