//
//  sys_frename.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../../include/sys_file.h"
#include "../include/sys_filedef.h"
#include "stdio.h"
#include "stdlib.h"

unsigned char sys_frename(const char * pszFilename1, const char * pszFilename2)
{
	char* opPath = fpathchange(pszFilename1);
	if(opPath == NULL)
	{
		return false;
	}	
	char* npPath = fpathchange(pszFilename2);
	if(npPath == NULL)
	{
		return false;
	}	
	//rename  执行成功则返回0，失败返回-1
	int err = rename(opPath,npPath);
	free(opPath);
	free(npPath);
	if(err == 0)
		return true;
	else
		return false;
}