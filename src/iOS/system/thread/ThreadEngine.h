//
//  ThreadEngine.h
//  system_api
//
//  Created by Harry on 13-11-4.
//
//

#import <Foundation/Foundation.h>
#import "sys_thread.h"

@interface ThreadEngine : NSObject{
    NSThread* _pThreadHandle;
    SYS_ThreadProcFunc _pThreadProcFunc;
    SYS_ThreadNotifyFunc _pThreadNotifyFunc;
    void* _pvUser;
}
-(id)init;
-(void)initAttr:(SYS_ThreadProcFunc) proc WithNotify:(SYS_ThreadNotifyFunc) notify AndUser:(void*) user;
-(void)Start;
-(void)Cancel;
-(BOOL)isExecuting;
-(BOOL)isBusy;
-(void)willDestroy;
@end
