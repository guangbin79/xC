//
//  TimerEngine.h
//  api_core
//
//  Created by xiehaiduo on 09-12-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "sys_timer.h"


@interface TimerEngine : NSObject {
    
	NSTimer *timercontrol;  //iphone定时器
	void *pUser;
	SYS_PFNTIMEREVENT pFn;
	
}

- (void)startTimer:(uint32_t)dwMSecs withTarget:(SYS_PFNTIMEREVENT)pfn withUser:(void *)pvUser;
- (void)cancelTimer;
- (bool)isBusy;
- (void)destroytime;

@end
