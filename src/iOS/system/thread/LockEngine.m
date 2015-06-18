//
//  ThreadEngine.m
//  system_api
//
//  Created by Harry on 13-11-4.
//
//

#import "LockEngine.h"

@implementation MutexEngine


/**************************************************/
/*                                                */
/*      线程互斥引擎API                             */
/*                                                */
/**************************************************/

-(id)init
{
    if (self = [super init])
	{
        _pLock = [[NSLock alloc]init];
    }
    return self;
}

-(void)dealloc
{
    [_pLock release];
    [super dealloc];
}

-(void)lock
{
    [_pLock lock];
}

-(void)unlock
{
    [_pLock unlock];
}

@end


/**************************************************/
/*                                                */
/*      线程信号量引擎API                           */
/*                                                */
/**************************************************/

@implementation SemaphoreEngine;

-(id)init
{
    if (self = [super init]) {
        _pCondition = [[NSCondition alloc]init];
    }
    return self;
}

-(void)lock
{
    [_pCondition lock];
}

-(void)unlock
{
    [_pCondition unlock];
}

-(void)wait
{
    [_pCondition wait];
}

-(void)signal
{
    [_pCondition signal];
}


@end














