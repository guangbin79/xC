//
//  ThreadEngine.m
//  system_api
//
//  Created by Harry on 13-11-4.
//
//

#import "ThreadEngine.h"

@implementation ThreadEngine{
    BOOL _busy;
}

-(id)init
{
    if (self = [super init])
	{
        _pThreadHandle = nil;
        _pThreadProcFunc = NULL;
        _pvUser = NULL;
        _busy = NO;
       
    }
    return self;
}

-(void)dealloc
{
    
    if (_pThreadHandle)
    {
        [_pThreadHandle release];
        _pThreadHandle = nil;
    }
    _pThreadProcFunc = NULL;
    _pvUser = NULL;
    _busy = NO;
    [super dealloc];
    
}

-(void)willDestroy{
    if (_pThreadHandle)
    {
        [_pThreadHandle release];
        _pThreadHandle = nil;
    }
}

-(void)initAttr:(SYS_ThreadProcFunc) proc WithNotify:(SYS_ThreadNotifyFunc) notify AndUser:(void*) user
{
    _pThreadProcFunc = proc;
    _pvUser = user;
}

-(void)Start
{
    if (_pThreadHandle && [_pThreadHandle isExecuting])
    {
    }
    else
    {
        [_pThreadHandle release];
       
        _busy = YES;
        _pThreadHandle = [[NSThread alloc]initWithTarget:self selector:@selector(Run) object:nil];
        [_pThreadHandle start];
    }
}

-(void)Cancel
{
    if (_pThreadHandle && [_pThreadHandle isExecuting])
    {
        _busy = NO;
        [_pThreadHandle cancel];
        _pThreadHandle = nil;
    }
}

-(BOOL)isExecuting
{
    return _busy;
//    if (_pThreadHandle)
//    {
//        return [_pThreadHandle isExecuting];
//    }
//    return NO;
}

-(void)NotifyToMainThread
{
    if (_pThreadHandle == nil) {
        return;
    }
    [_pThreadHandle release];
    _pThreadHandle = nil;
}

-(void)Run
{
    @autoreleasepool
    {
        
        if (_pThreadProcFunc != NULL)
        {
            (*_pThreadProcFunc)(_pvUser);
        }
        
        _busy = NO;
        
        if (![[NSThread currentThread] isCancelled])
        {
            [self performSelectorOnMainThread:@selector(NotifyToMainThread) withObject:nil waitUntilDone:YES];
        }
    }
    
}

-(BOOL)isBusy{
    return _busy;
}




@end
