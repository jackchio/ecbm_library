#include "soft_rtc.h"   //加载头文件。
/*--------------------------------------变量定义-----------------------------------*/
u16 soft_rtc_year;   //年
u8  soft_rtc_month;  //月
u8  soft_rtc_day;    //日
u8  soft_rtc_week;   //星期
u8  soft_rtc_hour;   //时
u8  soft_rtc_minute; //分
u8  soft_rtc_second; //秒
#if (SOFT_RTC_UPDATE_EN)
u8  soft_rtc_cmd_sta; //接收时间校准的状态机变量。
u8  soft_rtc_cmd_count;
u8 code soft_rtc_string[]=SOFT_RTC_UPDATE_STRING;
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
获取天数最大值函数。
-------------------------------------------------------*/
#if ((SOFT_RTC_SET_EN)||(SOFT_RTC_RUN_EN))
u8 soft_rtc_get_day_max(u16 year,u8 month){
    u8 code soft_rtc_year_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2){//2月份比较特殊。
        if(((year%4==0)&&(year%100!=0))||(year%400==0)){//先判断当前是平年还是闰年。
            return 29;//闰年一个月29天。
        }else{
            return 28;//平年一个月28天。
        }
    }else{
        return soft_rtc_year_month[month-1];//月份从1开始，数组下标从0开始，所以要减一。
    }
}
#endif
/*-------------------------------------------------------
运行函数。
-------------------------------------------------------*/
#if (SOFT_RTC_RUN_EN)
void soft_rtc_run(void){
    u8 day_max;
    soft_rtc_second++;      //秒+1。
    if(soft_rtc_second>=60){//到了60秒，
        soft_rtc_second=0;  //秒清零。
        soft_rtc_minute++;  //分+1。
        if(soft_rtc_minute>=60){//到了60分。
            soft_rtc_minute=0;//分清零。
            soft_rtc_hour++;    //时+1。
            if(soft_rtc_hour>=24){//到了24时。
                soft_rtc_hour=0;//时清零。
                soft_rtc_day++;//天+1。
                soft_rtc_week++;//星期+1。
                if(soft_rtc_week>7){//如果大于星期日，
                    soft_rtc_week=1;//就变成星期一。
                }
                day_max=soft_rtc_get_day_max(soft_rtc_year,soft_rtc_month);//获取当年当月的最大天数。
                if(soft_rtc_day>day_max){//天数大于一个月最大天数时，
                    soft_rtc_day=1;//天恢复。
                    soft_rtc_month++;//月份+1。
                    if(soft_rtc_month>12){//超过12个月的话，
                        soft_rtc_month=1;//月恢复
                        soft_rtc_year++;//年份+1。
                    }
                }
            }
        }
    }
}
#endif
/*-------------------------------------------------------
设置日期函数。
-------------------------------------------------------*/
#if (SOFT_RTC_SET_EN)
u8 soft_rtc_set_date(u16 year,u8 month,u8 day,u8 week){
    u8 day_max;
    soft_rtc_year=year;
    if((month>=1)&&(month<=12)){
        soft_rtc_month=month;
    }else{
        return SOFTRTC_MON_ERR;
    }
    day_max=soft_rtc_get_day_max(soft_rtc_year,soft_rtc_month);//获取当年当月的最大天数。
    if((day>=1)&&(day<=day_max)){
        soft_rtc_day=day;
    }else{
        return SOFTRTC_DAY_ERR;
    }
    if((week>=1)&&(week<=7)){
        soft_rtc_week=week;
    }else{
        return SOFTRTC_WEEK_ERR;
    }
    return SOFTRTC_OK;
}
#endif
/*-------------------------------------------------------
设置时间函数。
-------------------------------------------------------*/
#if (SOFT_RTC_SET_EN)
u8 soft_rtc_set_time(u8 hour,u8 minute,u8 second){
    if(hour  <24){soft_rtc_hour  =hour;  }else{return SOFTRTC_HOUR_ERR;}
    if(minute<60){soft_rtc_minute=minute;}else{return SOFTRTC_MIN_ERR; }
    if(second<60){soft_rtc_second=second;}else{return SOFTRTC_SEC_ERR; }
    return SOFTRTC_OK;
}
#endif
/*-------------------------------------------------------
更新时间函数。
-------------------------------------------------------*/
#if (SOFT_RTC_UPDATE_EN)
u8 soft_rtc_update(u8 dat){
    u8 res;
    res=0;
    switch(soft_rtc_cmd_sta){
        case 0:break;
        case 1:{
            if(dat==soft_rtc_string[soft_rtc_cmd_count]){
                soft_rtc_cmd_count++;
                if(soft_rtc_cmd_count>=(sizeof(SOFT_RTC_UPDATE_STRING)-1)){
                    soft_rtc_cmd_sta=2;
                }
            }else{
                soft_rtc_cmd_count=0;
                soft_rtc_cmd_sta=0;
            }
        }break;
        case 2:{soft_rtc_year   =(u16)(dat)*100;soft_rtc_cmd_sta=3;}break;
        case 3:{soft_rtc_year  +=(u16)(dat);    soft_rtc_cmd_sta=4;}break;
        case 4:{soft_rtc_month =dat;            soft_rtc_cmd_sta=5;}break;
        case 5:{soft_rtc_day   =dat;            soft_rtc_cmd_sta=6;}break;
        case 6:{soft_rtc_week  =dat;            soft_rtc_cmd_sta=7;}break;
        case 7:{soft_rtc_hour  =dat;            soft_rtc_cmd_sta=8;}break;
        case 8:{soft_rtc_minute=dat;            soft_rtc_cmd_sta=9;}break;
        case 9:{soft_rtc_second=dat;res=1;      soft_rtc_cmd_sta=0;}break;  
    }
    if(dat==soft_rtc_string[0]){
        soft_rtc_cmd_sta=1;
        soft_rtc_cmd_count=1;
    }
    return res;
}
#endif