#include "../../../xtime.h"
#include "../../../xpointer.h"
#include "../../../xdebug.h"
#include "../../jni_include/sys_xtime.h"

void sys_xgmTime(xuint32_t t, xdate_time_t * pdt)
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
