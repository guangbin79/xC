//
//  sys_fchsize.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
// 改变后的文件的大小
unsigned int sys_fchsize(SYS_File * pf, unsigned int size)
{
    NSFileHandle *fh = [NSFileHandle fileHandleForWritingAtPath:[NSString stringWithFormat:@"%s",pf->fname]];
    [fh truncateFileAtOffset:size];
    [fh closeFile];
    uint32_t fsz = sys_fgetsize(pf->fname);
    
    return fsz;
}

