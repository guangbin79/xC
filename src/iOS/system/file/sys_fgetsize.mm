//
//  fgetsize_core.mm
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
	
    size_t strlen(const char *);
	
#ifdef __cplusplus
}
#endif
//得到文件的大小
unsigned int sys_fgetsize(const char * pszFilename)
{	
	uint32_t size=0;
	char* pPath = fpathchange(pszFilename);
	if(pPath)
	{
		NSFileManager * fileManager = [NSFileManager defaultManager];
        //attributesOfItemAtPath 返回在给定的路径的项目的属性（文件，目录，符号链接，等）
		NSDictionary *dictionary = [fileManager attributesOfItemAtPath:[NSString stringWithFormat:@"%s",pPath]
																 error:nil];
		NSNumber *fileSystemSizeInBytes = [dictionary objectForKey: NSFileSize];
		size = [fileSystemSizeInBytes unsignedIntValue];
		free(pPath);
	}
	return size;
}
