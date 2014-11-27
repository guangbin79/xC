#include "../../../xtime.h"
#include "../include/sys_time.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

/**
 * @brief 获取系统时钟
 * @param - 无
 * @return - 返回时钟时间,精度为毫秒
 */
xuint32_t xtime_clock()
{
    return sys_clock();
}

/**
 * @brief 转换格林尼治时间
 * @param[in] t - 需要转换的时间(从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数)
 * @param[out] pdt - 格林尼治时间
 * @return - 无
 */
void xtime_gmTime(xuint32_t t, xdate_time_t * pdt)
{
    return sys_gmtime(pdt, t);
}

/**
 * @brief 转换本地时间
 * @param[in] t - 需要转换的时间(从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数)
 * @param[out] pdt - 本地时间
 * @return - 无
 */
void xtime_localTime(xuint32_t t, xdate_time_t * pdt)
{
    return sys_localtime(pdt, t);
}

/**
 * @brief 从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数
 * @param[in] pdt - 格林尼治时间,如果为空则为当前格林尼治时间
 * @return - 从公元1970年1月1日0时0分0秒算起至指定的格林尼治时间所经过的秒数
 */
xuint32_t xtime_mkTime(const xdate_time_t * pdt)
{
    xdate_time_t end;
    xuint32_t days = 0;
    xuint8_t nptm1monthday = 0;
    
    xdebug_assert(pdt != XNULL);
    
    end.year = 1970;
    end.month = 1;
    end.day = 1;
    end.hour = 0;
    end.minute = 0;
    end.second = 0;
    
    xdebug_assert(pdt->year > end.year ||
                  (pdt->year == end.year && pdt->month > end.month) ||
                  (pdt->year == end.year && pdt->month == end.month && pdt->day > end.day) ||
                  (pdt->year == end.year && pdt->month == end.month && pdt->day == end.day && pdt->hour > end.hour) ||
                  (pdt->year == end.year && pdt->month == end.month && pdt->day == end.day && pdt->hour == end.hour && pdt->minute > end.minute) ||
                  (pdt->year == end.year && pdt->month == end.month && pdt->day == end.day && pdt->hour == end.hour && pdt->minute == end.minute && pdt->second >= end.second));
    
    if (pdt->year > end.year)
    {
        xuint8_t n;
        xuint16_t year = pdt->year;
        
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
        
        for (n = 1; n < pdt->month; ++n)
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
                    if ((pdt->year % 4 == 0 && pdt->year % 100 != 0) || pdt->year % 400 == 0)
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
        days += pdt->day - 1;//累加结束时间天数
        
        return days * 24 * 3600 +
        (24 - end.hour - 1) * 3600 + (60 - end.minute - 1) * 60 + 60 - end.second +
        pdt->hour * 3600 + pdt->minute * 60 + pdt->second;
        
    }
    else
    {
        xuint8_t n;
        
        //开始时间和结束时间是同一年
        for (n = end.month; n < pdt->month; ++n)
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
        
        if (end.month != pdt->month)
        {
            //如果开始时间和结束时间不是同一月
            days += nptm1monthday - end.day;//累加开始时间天数
            days += pdt->day;//累加结束时间天数
        }
        else
        {
            //同年同月中
            days += pdt->day - end.day;
        }
        
        return days * 24 * 3600 +
        pdt->hour - end.hour * 3600 +
        pdt->minute - end.minute * 60 +
        pdt->second - end.second;
    }
}


