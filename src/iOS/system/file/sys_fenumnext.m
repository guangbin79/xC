//
//  fenumnext.mm
//  api
//
//  Created by xiehaiduo on 09-12-8.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "stdlib.h"
#include "dirent.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif
	int strcmp(const char *, const char *);
	
#ifdef __cplusplus
}
#endif

const char * sys_fenumnext(SYS_FileEnum * pfe)
{
	struct      dirent * dir_entry = NULL;
	if (pfe->directory == NULL) {
		return NULL;
	}
    //readdir 读取目录   
    //readdir相当于文件操作函数read，DIR结构体相当于文件操作里面的FILE结构体。
	while((dir_entry=readdir(pfe->directory)) != NULL)
	{
		if(dir_entry->d_name[0] == '.')
			continue;
		else 
		{
			if( (pfe->isdir==true) && (dir_entry->d_type==4) )	{
				break;
			}
			else if( (pfe->isdir==false) && (dir_entry->d_type!=4) ){
				break;
			}
			else{
				continue;
			}
		}
	}
	if(dir_entry != NULL)
		//sprintf(pfe->name,"%s%s",pfe->pszDir,dir_entry->d_name);
        sprintf(pfe->name,"%s",dir_entry->d_name);
	else {
		return NULL;
	}
	return pfe->name;
}
