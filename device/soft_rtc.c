#include "soft_rtc.h"   //����ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
u16 soft_rtc_year;   //��
u8  soft_rtc_month;  //��
u8  soft_rtc_day;    //��
u8  soft_rtc_week;   //����
u8  soft_rtc_hour;   //ʱ
u8  soft_rtc_minute; //��
u8  soft_rtc_second; //��
#if (SOFT_RTC_UPDATE_EN)
u8  soft_rtc_cmd_sta; //����ʱ��У׼��״̬��������
u8  soft_rtc_cmd_count;
u8 code soft_rtc_string[]=SOFT_RTC_UPDATE_STRING;
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��ȡ�������ֵ������
-------------------------------------------------------*/
#if ((SOFT_RTC_SET_EN)||(SOFT_RTC_RUN_EN))
u8 soft_rtc_get_day_max(u16 year,u8 month){
    u8 code soft_rtc_year_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2){//2�·ݱȽ����⡣
        if(((year%4==0)&&(year%100!=0))||(year%400==0)){//���жϵ�ǰ��ƽ�껹�����ꡣ
            return 29;//����һ����29�졣
        }else{
            return 28;//ƽ��һ����28�졣
        }
    }else{
        return soft_rtc_year_month[month-1];//�·ݴ�1��ʼ�������±��0��ʼ������Ҫ��һ��
    }
}
#endif
/*-------------------------------------------------------
���к�����
-------------------------------------------------------*/
#if (SOFT_RTC_RUN_EN)
void soft_rtc_run(void){
    u8 day_max;
    soft_rtc_second++;      //��+1��
    if(soft_rtc_second>=60){//����60�룬
        soft_rtc_second=0;  //�����㡣
        soft_rtc_minute++;  //��+1��
        if(soft_rtc_minute>=60){//����60�֡�
            soft_rtc_minute=0;//�����㡣
            soft_rtc_hour++;    //ʱ+1��
            if(soft_rtc_hour>=24){//����24ʱ��
                soft_rtc_hour=0;//ʱ���㡣
                soft_rtc_day++;//��+1��
                soft_rtc_week++;//����+1��
                if(soft_rtc_week>7){//������������գ�
                    soft_rtc_week=1;//�ͱ������һ��
                }
                day_max=soft_rtc_get_day_max(soft_rtc_year,soft_rtc_month);//��ȡ���굱�µ����������
                if(soft_rtc_day>day_max){//��������һ�����������ʱ��
                    soft_rtc_day=1;//��ָ���
                    soft_rtc_month++;//�·�+1��
                    if(soft_rtc_month>12){//����12���µĻ���
                        soft_rtc_month=1;//�»ָ�
                        soft_rtc_year++;//���+1��
                    }
                }
            }
        }
    }
}
#endif
/*-------------------------------------------------------
�������ں�����
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
    day_max=soft_rtc_get_day_max(soft_rtc_year,soft_rtc_month);//��ȡ���굱�µ����������
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
����ʱ�亯����
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
����ʱ�亯����
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