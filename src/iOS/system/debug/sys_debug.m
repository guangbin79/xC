/*
 *  sys_debug.mm
 *  sys_api
 *
 *  Created by caiyw on 14-12-2.
 *  Copyright 2014 navinfo. All rights reserved.
 */

#include <assert.h>
#include "../../include/sys_debug.h"

//@interface SysDebug : NSObject
//-(void)MyAssert:(unsigned char)exp;
//@end
//
//@implementation SysDebug
//-(void)MyAssert:(unsigned char)exp{
//    NSAssert(exp, @"");
//}
//@end

//断言
void sys_assert(unsigned char exp)
{
    assert(exp);
}

void sys_dbgprintf(const char * format, void * ap)
{
#ifdef SIMULATOR
    NSString *tmpFormat = [NSString stringWithUTF8String:format];
	NSLogv(tmpFormat,(va_list)ap);
#else
#endif
}



