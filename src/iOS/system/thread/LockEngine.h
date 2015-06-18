//
//  ThreadEngine.h
//  system_api
//
//  Created by Harry on 13-11-4.
//
//

#import <Foundation/Foundation.h>

/**************************************************/
/*                                                */
/*      线程互斥引擎API                             */
/*                                                */
/**************************************************/
@interface MutexEngine : NSObject{
    NSLock* _pLock;
}
-(id)init;
-(void)lock;
-(void)unlock;

@end


/**************************************************/
/*                                                */
/*      线程信号量引擎API                           */
/*                                                */
/**************************************************/

@interface SemaphoreEngine : NSObject{
    NSCondition* _pCondition;
}
-(id)init;
-(void)lock;
-(void)unlock;
-(void)wait;
-(void)signal;

@end






