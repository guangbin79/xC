//
//  sys_fread.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//


#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdio.h"
//读文件
size_t sys_fread(SYS_File * pf, void * pvBuf, size_t bufSize)
{
	size_t flen = 0;
	
	if(pf != NULL)
		flen = fread(pvBuf,1,(size_t)bufSize,pf->fs);
	
	return flen;
}