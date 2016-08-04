//
//  sys_fclose.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//


#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdlib.h"
#include "stdio.h"

//关闭文件
void sys_fclose(SYS_File * pf)
{
	if(pf != NULL)
	{
		if(pf->fname != NULL)
			free(pf->fname);
		if(pf->fs != NULL)
			fclose(pf->fs);
		
		free(pf);
	}
}
