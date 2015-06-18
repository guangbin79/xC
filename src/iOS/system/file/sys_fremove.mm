//
//  sys_fremove.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdio.h"
#include "stdlib.h"


unsigned char sys_fremove(const char * pszFilename)
{
	char* pPath = fpathchange(pszFilename);
	if(pPath == NULL)
	{
		return false;
	}	
	BOOL success = 0;
	NSFileManager * fileManager = [NSFileManager defaultManager];
	NSError *error;
	if([fileManager fileExistsAtPath:[NSString stringWithFormat:@"%s",pPath]])
	{
		success = [fileManager removeItemAtPath:[NSString stringWithFormat:@"%s",pPath] error:&error];
	}
	else
	{
		free(pPath);
		return true;
	}

	free(pPath);
	if(success )
		return true;
	else
		return false;
}
