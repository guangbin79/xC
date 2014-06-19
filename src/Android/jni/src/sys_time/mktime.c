#include "../../../xtime.h"
#include "../../../xpointer.h"
#include "../../../xdebug.h"
#include "../../jni_include/sys_xtime.h"

unsigned int  sys_xmkTime(const xdate_time_t * pdt)
{
	 xdate_time_t end;
	    xuint32_t days = 0;
	    xuint8_t nptm1monthday = 0;
	    const xdate_time_t * pdtChange = XNULL;
	    xdate_time_t stdtCur;

	    if(XNULL == pdt)
	    {
	        //计算当前时间
	    	sys_time((xdate_time_t *)(&stdtCur));
	        pdtChange = &stdtCur;
	    }
	    else
	    {
	        pdtChange = pdt;
	    }

	    end.year = 1970;
	    end.month = 1;
	    end.day = 1;
	    end.hour = 0;
	    end.minute = 0;
	    end.second = 0;

	    xdebug_assert(pdtChange->year > end.year ||
	                  (pdtChange->year == end.year && pdtChange->month > end.month) ||
	                  (pdtChange->year == end.year && pdtChange->month == end.month && pdtChange->day > end.day) ||
	                  (pdtChange->year == end.year && pdtChange->month == end.month && pdtChange->day == end.day && pdtChange->hour > end.hour) ||
	                  (pdtChange->year == end.year && pdtChange->month == end.month && pdtChange->day == end.day && pdtChange->hour == end.hour && pdtChange->minute > end.minute) ||
	                  (pdtChange->year == end.year && pdtChange->month == end.month && pdtChange->day == end.day && pdtChange->hour == end.hour && pdtChange->minute == end.minute && pdtChange->second >= end.second));

	    if (pdtChange->year > end.year)
	    {
	        xuint8_t n;
	        xuint16_t year = pdtChange->year;

	        while (--year > end.year)
	        {
	            //计算整年天数
	            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	            {
	                days += 366;
	            }
	            else
	            {
	                days += 365;
	            }
	        }

	        for (n = 12; n >= end.month; --n)
	        {
	            //计算开始时间月数
	            switch (n)
	            {
	            case 1:
	            case 3:
	            case 5:
	            case 7:
	            case 8:
	            case 10:
	            case 12:
	                if (n == end.month)
	                {
	                    nptm1monthday = 31;
	                }
	                else
	                {
	                    days += 31;
	                }
	                break;

	            case 4:
	            case 6:
	            case 9:
	            case 11:
	                if (n == end.month)
	                {
	                    nptm1monthday = 30;
	                }
	                else
	                {
	                    days += 30;
	                }
	                break;

	            case 2:
	                if ((end.year % 4 == 0 && end.year % 100 != 0) || end.year % 400 == 0)
	                {
	                    if (n == end.month)
	                    {
	                        nptm1monthday = 29;
	                    }
	                    else
	                    {
	                        days += 29;
	                    }
	                }
	                else
	                {
	                    if (n == end.month)
	                    {
	                        nptm1monthday = 28;
	                    }
	                    else
	                    {
	                        days += 28;
	                    }
	                }
	                break;
	            }
	        }

	        for (n = 1; n < pdtChange->month; ++n)
	        {
	            //计算结束时间月数
	            switch (n)
	            {
	            case 1:
	            case 3:
	            case 5:
	            case 7:
	            case 8:
	            case 10:
	            case 12:
	                days += 31;
	                break;

	            case 4:
	            case 6:
	            case 9:
	            case 11:
	                days += 30;
	                break;

	            case 2:
	                if ((pdtChange->year % 4 == 0 && pdtChange->year % 100 != 0) || pdtChange->year % 400 == 0)
	                {
	                    days += 29;
	                }
	                else
	                {
	                    days += 28;
	                }
	                break;
	            }
	        }

	        days += nptm1monthday - end.day;//累加开始时间天数
	        days += pdtChange->day - 1;//累加结束时间天数

	        return days * 24 * 3600 +
	                (24 - end.hour - 1) * 3600 + (60 - end.minute - 1) * 60 + 60 - end.second +
	                pdtChange->hour * 3600 + pdtChange->minute * 60 + pdtChange->second;

	    }
	    else
	    {
	        xuint8_t n;

	        //开始时间和结束时间是同一年
	        for (n = end.month; n < pdtChange->month; ++n)
	        {
	            //计算开始和结束月份
	            switch (n)
	            {
	            case 1:
	            case 3:
	            case 5:
	            case 7:
	            case 8:
	            case 10:
	            case 12:
	                if (n == end.month)
	                {
	                    nptm1monthday = 31;
	                }
	                else
	                {
	                    days += 31;
	                }
	                break;

	            case 4:
	            case 6:
	            case 9:
	            case 11:
	                if (n == end.month)
	                {
	                    nptm1monthday = 30;
	                }
	                else
	                {
	                    days += 30;
	                }
	                break;

	            case 2:
	                if ((end.year % 4 == 0 && end.year % 100 != 0) || end.year % 400 == 0)
	                {
	                    if (n == end.month)
	                    {
	                        nptm1monthday = 29;
	                    }
	                    else
	                    {
	                        days += 29;
	                    }
	                }
	                else
	                {
	                    if (n == end.month)
	                    {
	                        nptm1monthday = 28;
	                    }
	                    else
	                    {
	                        days += 28;
	                    }
	                }
	                break;
	            }
	        }

	        if (end.month != pdtChange->month)
	        {
	            //如果开始时间和结束时间不是同一月
	            days += nptm1monthday - end.day;//累加开始时间天数
	            days += pdtChange->day;//累加结束时间天数
	        }
	        else
	        {
	            //同年同月中
	            days += pdtChange->day - end.day;
	        }

	        return days * 24 * 3600 +
	                pdtChange->hour - end.hour * 3600 +
	                pdtChange->minute - end.minute * 60 +
	                pdtChange->second - end.second;
	    }
}
