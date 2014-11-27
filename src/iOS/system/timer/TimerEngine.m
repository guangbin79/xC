//
//  TimerEngine.mm
//  api_core
//
//  Created by xiehaiduo on 09-12-23.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "TimerEngine.h"


@implementation TimerEngine

- (id)init{
    if (self = [super init]) {
    }
	return self;
}


- (void)startTimer:(uint32_t)dwMSecs withTarget:(SYS_PFNTIMEREVENT)pfn withUser:(void *)pvUser{
    
	pFn = pfn;
	pUser = pvUser;
    if (timercontrol && [timercontrol isValid]==YES) {
        [timercontrol invalidate];
    }
    [timercontrol release];
    timercontrol = nil;
	timercontrol = [[NSTimer timerWithTimeInterval:(dwMSecs*0.001) target:self selector:@selector(timerFired:) userInfo:nil repeats:NO] retain];
	[[NSRunLoop currentRunLoop] addTimer:timercontrol forMode:NSDefaultRunLoopMode];
}

- (void) dealloc {
    
    if (timercontrol && [timercontrol isValid]==YES) {
        [timercontrol invalidate];
    }
    [timercontrol release];
    timercontrol = nil;
    
    [super dealloc];
}

// Timer callback method
- (void)timerFired:(NSTimer *)timer//(id)sender
{
    [self cancelTimer];
	if (pFn != NULL) {
		(*pFn)(pUser);
	}
}


- (void)cancelTimer {
    if (timercontrol && [timercontrol isValid]==YES) {
        [timercontrol invalidate];
        [timercontrol release];
        timercontrol = nil;
    }
}

- (bool)isBusy {
	if ([timercontrol isValid]==YES) {
		return true;
	}
	return false;
}

// Included for form's sake; our ImageClient object will be around for as long as the app is running
- (void)destroytime {
    if (timercontrol && [timercontrol isValid]==YES) {
        [timercontrol invalidate];
        [timercontrol release];
        timercontrol = nil;
    }
}


@end
