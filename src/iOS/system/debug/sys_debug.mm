//
//  sys_debug.mm
//  My_System_api
//
//  Created by feifei on 11-9-26.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include <assert.h>
#include "../../include/sys_debug.h"

@interface SysDebug : NSObject
-(void)MyAssert:(unsigned char)exp;
@end

@implementation SysDebug
-(void)MyAssert:(unsigned char)exp{
    NSAssert(exp, @"zhangyang_AAAAAAAAAAAAAAAAAAAA");
}
@end

//断言
void sys_assert(unsigned char exp)
{
        assert(exp);
//    SysDebug* mudebug = [[SysDebug alloc] init];
//    [mudebug MyAssert:exp];
//    [mudebug release];
}

void sys_dbgprintf(const xchar_t * format, void * ap)
{
#ifdef SIMULATOR
	//NSString *tmpFormat = [[NSString alloc] initWithUTF8String:format];
    NSString *tmpFormat = [NSString stringWithUTF8String:format];
	NSLogv(tmpFormat,(va_list)ap);  
	//[tmpFormat release];
#else
#endif
}



