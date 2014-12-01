//
//  sys_frmdir.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>


//删除目录
unsigned char sys_frmdir(const char * pszDir)
{
	char* pPath = fpathchange(pszDir);
	if(pPath == NULL)
	{
		return false;
	}	

	NSFileManager * fileManager = [NSFileManager defaultManager];
	NSError *error;
	BOOL success = 0;
	if([fileManager fileExistsAtPath:[NSString stringWithFormat:@"%s",pPath]])
	{
		success = [fileManager removeItemAtPath:[NSString stringWithFormat:@"%s",pPath] error:&error];
        free(pPath);
        return success;
	}
    
    free(pPath);
    return true;
}
