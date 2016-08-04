//
//  sys_fseek.mm
//  api
//
//  Created by feifei on 11-09-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#include "../include/sys_filedef.h"
#include "../../include/sys_file.h"
#include "../../include/sys_debug.h"
#include <stdio.h>
#include <Foundation/NSFileHandle.h>
//定位文件读写位置
size_t sys_fseek(SYS_File * pf, SYS_FileSeekType seekType,size_t moveDistance)
{
	uint32_t err;
	fpos_t curPos;
	fgetpos(pf->fs, &curPos);
	switch ( seekType)
	{
		case SYS_FST_CURRENT_UP:
		{
			curPos -= moveDistance;
			if (curPos<0)
				curPos = 0;
			err = fseek(pf->fs,curPos,SEEK_SET);
		}break;
		case SYS_FST_CURRENT_DOWN:
		{//底层不做任何判断，因为调用频繁，为了增加效率
//			uint32_t nFilesz = sys_fgetsize(pf->fname);
			curPos += moveDistance;
//			if (curPos>nFilesz)
//				curPos = nFilesz;			
			err = fseek(pf->fs,curPos,SEEK_SET);
		}break;
		case SYS_FST_START:
		{
//			uint32_t nFilesz = sys_fgetsize(pf->fname);
			curPos = moveDistance;
//			if (curPos>nFilesz)
//				curPos = nFilesz;			
			err = fseek(pf->fs,curPos,SEEK_SET);
		}break;
		case SYS_FST_END:
		{
			err = fseek(pf->fs,0,SEEK_END);
		}break;
		default:
			break;
	}
	if (err==-1) {
        sys_assert(0);
    }
    fgetpos(pf->fs, &curPos);
	return curPos;
	
}