/*
 *  sys_time.mm
 *  System_api
 *
 *  Created by feifei on 11-9-26.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "../../include/sys_time.h"
#include <time.h>
#include <mach/mach_time.h>

unsigned int sys_clock()
{
    mach_timebase_info_data_t info;
    mach_timebase_info(&info);
    uint64_t time1 = mach_absolute_time();
    uint64_t time2 = time1 * info.numer / info.denom / 1000000LL;
    return time2;
}

void sys_time(SYS_tm * ptm)
{
	CFAbsoluteTime now = CFAbsoluteTimeGetCurrent();
	CFGregorianDate cfdate = CFAbsoluteTimeGetGregorianDate(now,CFTimeZoneCopySystem());
    
	ptm->year = (short int)cfdate.year;
    ptm->month = (char)cfdate.month;
    ptm->day = (char)cfdate.day;
    ptm->hour = (char)cfdate.hour;
    ptm->minute = (char)cfdate.minute;
    ptm->second = (char)cfdate.second;
}

void sys_gmtime(SYS_tm * ptm, int t)
{
    NSDate * time = [NSDate dateWithTimeIntervalSince1970:(NSTimeInterval)t];
    NSCalendar * calendar = [NSCalendar currentCalendar];
    NSDateComponents * comps;
    
    comps =[calendar components:(NSYearCalendarUnit | NSMonthCalendarUnit |NSDayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit) fromDate:time];
    
    
    ptm->year = (short int)[comps year];
    ptm->month = (char)[comps month];
    ptm->day = (char)[comps day];
    ptm->hour = (char)[comps hour];
    ptm->minute = (char)[comps minute];
    ptm->second = (char)[comps second];
}

void sys_localtime(SYS_tm * ptm, int t)
{
    if(t == 0)
    {
        return sys_time(ptm);
    }
    else
    {
        NSDate * date = [NSDate date];
        
        NSTimeZone * zone = [NSTimeZone systemTimeZone];
        
        NSInteger interval = [zone secondsFromGMTForDate: date];
        
        NSDate * localeDate = [date dateByAddingTimeInterval: interval];
        
        NSDate * time = [localeDate dateByAddingTimeInterval:(NSTimeInterval)t];
        NSCalendar * calendar = [NSCalendar currentCalendar];
        NSDateComponents * comps;
        
        comps =[calendar components:(NSYearCalendarUnit | NSMonthCalendarUnit |NSDayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit) fromDate:time];
        
        
        ptm->year = (short int)[comps year];
        ptm->month = (char)[comps month];
        ptm->day = (char)[comps day];
        ptm->hour = (char)[comps hour];
        ptm->minute = (char)[comps minute];
        ptm->second = (char)[comps second];
    }
}



