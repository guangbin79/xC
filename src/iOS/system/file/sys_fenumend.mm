//
//  fenumend_core.mm
//  api
//
//  Created by xiehaiduo on 09-12-8.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//


#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdlib.h"

//枚举目录或文件结束
void sys_fenumend(SYS_FileEnum * pfe)
{
	if(pfe)
	{	
		if(pfe->directory)
			closedir(pfe->directory);
		
		if(pfe->pszDir)
			free(pfe->pszDir);
		free(pfe);
	}
}