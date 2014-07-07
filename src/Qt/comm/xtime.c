#include "../../../xtime.h"
#include "../include/sys_xtime.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"

xuint32_t xtime_clock()
{
    return xsys_xtime_clock();
}

void xtime_gmTime(xuint32_t t, xdate_time_t * pdt)
{
    xuint16_t nYear = 1970;
    xuint8_t nMonth = 1;
    xuint8_t nDay = 1;
    xuint8_t nHour = 0;
    xuint8_t nMinute = 0;
    xuint8_t nSecond = 0;
    if(t > 0)
    {
        xuint32_t nSurSeconds = t;//剩余秒数
        while(nSurSeconds > 0)
        {
            //确定当前年天数
            xuint16_t nCurYearDay = 0;
            xuint32_t nSeconds = 0;
            if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
            {
                nCurYearDay = 366;
            }
            else
            {
                nCurYearDay = 365;
            }

            //确定秒数
            nSeconds = nCurYearDay * 24 * 60 * 60;

            if(nSurSeconds > nSeconds)
            {
                //大于一年
                nSurSeconds -= nSeconds;
                nYear += 1;
            }
            else
            {
                //剩余时间小于一年，循环结束
                xbool_t bFindDay = XFALSE;//判断是否确定天数
                //1.计算出剩余秒的天数
                xuint16_t nSurDay = nSurSeconds / (24 * 60 * 60);
                nSurSeconds -= nSurDay * 24 * 60 * 60;
                if(nSurSeconds > 0)
                {
                    //如果剩余秒数>0，则剩余天数+1
                    nSurDay += 1;
                }
                //确定月数和天数
                for (; nMonth <= 12; nMonth++)
                {
                    //计算开始时间月数
                    switch (nMonth)
                    {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                    {
                        if(nSurDay <= 31)
                        {
                            bFindDay = XTRUE;
                            nDay = nSurDay;
                        }
                        else
                        {
                            nSurDay -= 31;
                        }
                    }
                        break;

                    case 4:
                    case 6:
                    case 9:
                    case 11:
                    {
                        if(nSurDay <= 30)
                        {
                            bFindDay = XTRUE;
                            nDay = nSurDay;
                        }
                        else
                        {
                            nSurDay -= 30;
                        }
                    }
                        break;

                    case 2:
                    {
                        if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
                        {
                            if(nSurDay <= 29)
                            {
                                bFindDay = XTRUE;
                                nDay = nSurDay;
                            }
                            else
                            {
                                nSurDay -= 29;
                            }
                        }
                        else
                        {
                            if(nSurDay <= 28)
                            {
                                bFindDay = XTRUE;
                                nDay = nSurDay;
                            }
                            else
                            {
                                nSurDay -= 28;
                            }
                        }
                    }
                        break;
                    }

                    if(bFindDay != XFALSE)
                    {
                        break;
                    }
                }

                //确定时、分、秒
                nHour = nSurSeconds / (60 * 60);
                nMinute = (nSurSeconds % (60 * 60)) / 60;
                nSecond = (nSurSeconds % (60 * 60)) % 60;
                break;
            }
        }
    }

    if(pdt != XNULL)
    {
        pdt->year = nYear;
        pdt->month = nMonth;
        pdt->day = nDay;
        pdt->hour = nHour;
        pdt->minute = nMinute;
        pdt->second = nSecond;
    }
    return;
}

void xtime_localTime(xuint32_t t, xdate_time_t * pdt)
{
    if(t > 0)
    {
        //获取本地时间与UTC时间偏差
        t += xsys_xtime_utcToLocal();
        return xtime_gmTime(t, pdt);
    }
    else
    {
        if(pdt != XNULL)
        {
            pdt->year = 1970;
            pdt->month = 1;
            pdt->day = 1;
            pdt->hour = 0;
            pdt->minute = 0;
            pdt->second = 0;
        }
    }

    return;
}

xuint32_t xtime_mkTime(const xdate_time_t * pdt)
{
    xdate_time_t end;
    xuint32_t days = 0;
    xuint8_t nptm1monthday = 0;
    const xdate_time_t * pdtChange = XNULL;
    xdate_time_t stdtCur;

    if(XNULL == pdt)
    {
        //计算当前时间
        xsys_xtime_utcTime((xsys_tm_t *)(&stdtCur));
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


