/*
 *  fpathchange.mm
 *  My_System_api
 *
 *  Created by feifei on 11-9-26.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#include "../include/sys_filedef.h"
#include <sys/xattr.h>

//更改路径
char * fpathchange(const char * pszFilename)
{
	//"fs1$navidog\map\basemap\5\65537\3473426"   创建一个目录搜索路径列表。
    NSArray *paths = nil;
#ifdef CopyFileToDoc
    paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
#else
    paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
#endif
    
	NSString *docDir = [paths objectAtIndex:0];
    NSString * sPath = nil;
    char* sFilePath = (char*)malloc(255);
    const char* tempFilename = pszFilename;
    memset(sFilePath, 0, 255);
    
    if (strstr(pszFilename, "asset:/")) {
        tempFilename += 5;
        sPath = [docDir stringByAppendingPathComponent:@"PrivateData"];
    }
    else if (strstr(pszFilename, "share:/")) {
        sPath = [docDir stringByAppendingPathComponent:@"share"];
        tempFilename += 5;
    }
    else if (strstr(pszFilename, ""))
    {
        
    }
    
    //创建文件夹并且设置不上传属性
    BOOL isDir;
    NSError *error;
    NSFileManager * fileManager = [NSFileManager defaultManager];
    if (NO == [fileManager fileExistsAtPath:sPath isDirectory:&isDir])
    {
        [fileManager createDirectoryAtPath:sPath withIntermediateDirectories:YES attributes:nil error:&error];
        if (strstr(pszFilename, "fs4:/") == NULL) {
            NSURL* tempulr = [NSURL URLWithString:sPath];
            const char* filePath = [[tempulr path] fileSystemRepresentation];
            const char* attrName = "com.apple.MobileBackup";
            u_int8_t attrValue = 1;
            int result = setxattr(filePath, attrName, &attrValue, sizeof(attrValue), 0, 0);
//            if ( result != 0) {
//                assert(0);
//            }
        }
    }
    
    strcpy(sFilePath, [sPath UTF8String]);
    strcat(sFilePath, "/");
    strcat(sFilePath, tempFilename);
    
    return sFilePath;
}