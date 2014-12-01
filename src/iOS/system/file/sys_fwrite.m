//
//  sys_fwrite.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdio.h"
//写文件
unsigned int sys_fwrite(SYS_File * pf, const void * pvBuf, unsigned int bufSize)
{
	uint32_t flen = 0;
	
	if(pf != NULL)
		flen = fwrite(pvBuf,1,(size_t)bufSize,pf->fs);
	
	return flen;
	
}