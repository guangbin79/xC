//
//  fenumstart.mm
//  api
//
//  Created by xiehaiduo on 09-12-8.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif
size_t	 strlen(const char *);
char * strcat(char *, const char *);
char * strcpy(char *, const char *);
	
#ifdef __cplusplus
}
#endif

SYS_FileEnum * sys_fenumstart(const char * pszDir, unsigned char bDirs)
{
	SYS_FileEnum *filelist =(SYS_FileEnum *)malloc(sizeof(SYS_FileEnum));
	if(filelist == NULL)
		return NULL;
	
	char* pPath = fpathchange(pszDir);//--/var/.abc/
	if(pPath == NULL)
	{
		free(filelist);
		return NULL;
	}	
	
	
	if(pPath[strlen(pPath) - 1] != '/')
	{
		strcat(pPath,"/");
	}
	
	
	filelist->pos = 0;
	filelist->isdir = bDirs;
	
	size_t i = strlen(pPath);
	filelist->pszDir = (char *)malloc(i + 1);
	memset(filelist->pszDir, 0, i+1);
	
	
	if(NULL == filelist->pszDir)
	{
		free(filelist);
		free(pPath);
		return NULL;
	} 
	
	strcpy(filelist->pszDir, pPath);

	
	filelist->pszDir[i] = '\0';
	free(pPath);
	//opendir 打开目录
	filelist->directory = opendir(filelist->pszDir);
	
	return filelist;
}