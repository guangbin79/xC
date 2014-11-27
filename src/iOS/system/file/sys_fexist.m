//
//  sys_fexist.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//


#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdio.h"
#include "stdlib.h"
//判断文件是否存在
unsigned char sys_fexist(const char * pszFilename)
{
	 char* pPath = fpathchange(pszFilename);
	 if(pPath == NULL)
	 {
		 return false;
	 }	
	NSFileManager * fileManager = [NSFileManager defaultManager];
	BOOL isExist = [fileManager fileExistsAtPath:[NSString stringWithFormat:@"%s",pPath]];
	free(pPath);
    return isExist;
}