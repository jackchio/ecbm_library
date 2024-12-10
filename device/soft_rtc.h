#ifndef _ECBM_SOFT_RTC_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_SOFT_RTC_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2024 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
    本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。
                            ***************************
                            * 联系方式 ：进群778916610 *
                            * 若1群满人：进群927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>SOFT-RTC运行函数使能
//<i>对于定时器资源紧张或者有外置RTC的项目而言，可以关掉软RTC的运行函数，只使用设置函数。
//<i>如果使能了运行函数，需要在一个每隔1秒执行一次的函数（不一定是中断函数，只要执行间隔满足1秒就行）内调用soft_rtc_run函数。
//<i>如果不使能运行函数，则需要自行决定应该使用什么器件来跑时间。
#define SOFT_RTC_RUN_EN  (1)
//<e>SOFT-RTC时间更新函数使能
//<i>不同的项目会有不同的更新时间的方式，比如按键手动调整和串口输入调整。
//<i>这里提到的时间更新函数就是基于STC-ISP上位机的时间校准功能做的串口接收处理函数。
//<i>因此如果你不需要串口更新时间功能，就可以关闭这个函数来节约空间。
#define SOFT_RTC_UPDATE_EN  (1)
//<s>命令头
//<i>在STC-ISP中，可以设置在发送校时数据之前先发送一串自定义的命令头，可以是HEX也可以是字符串。
//<i>这是为了让程序更好的识别，防止一些误触发。在本库中，主要是使用字符串来做命令头。
#define SOFT_RTC_UPDATE_STRING  "SOFT-RTC"
//</e>
//<q>SOFT-RTC时间设置函数使能
//<i>不同的项目会有不同的更新时间的方式，比如按键手动调整和串口输入调整。
//<i>这里提到的设置函数是可供用户调用的两个函数soft_rtc_set_date和soft_rtc_set_time。
//<i>这两个函数也没有什么特别的，就是在数值上做了约束，比如限制月份在1~12之间等。
//<i>如果输入的时间确定是100%正确，比如用上位机更新的时间，那么就可以不用这两个函数。
#define SOFT_RTC_SET_EN  (1)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define SOFTRTC_OK       (0)//操作OK
#define SOFTRTC_MON_ERR  (1)//月设置错误
#define SOFTRTC_DAY_ERR  (2)//日设置错误
#define SOFTRTC_WEEK_ERR (3)//星期设置错误
#define SOFTRTC_HOUR_ERR (4)//小时设置错误
#define SOFTRTC_MIN_ERR  (5)//分钟设置错误
#define SOFTRTC_SEC_ERR  (6)//秒钟设置错误
/*--------------------------------------变量定义-----------------------------------*/
extern u16 soft_rtc_year;   //年
extern u8  soft_rtc_month;  //月
extern u8  soft_rtc_day;    //日
extern u8  soft_rtc_week;   //星期
extern u8  soft_rtc_hour;   //时
extern u8  soft_rtc_minute; //分
extern u8  soft_rtc_second; //秒
/*--------------------------------------函数定义-----------------------------------*/
/*-------------------------------------------------------
函数名：soft_rtc_get_day_max
描  述：获取天数最大值函数。
输  入：无
输  出：无
返回值：
    当前年份和当前月份的最大天数值。
创建者：奈特
调用例程：无
创建日期：2021-8-31
修改记录：
-------------------------------------------------------*/
extern u8 soft_rtc_get_day_max(u16 year,u8 month);
/*-------------------------------------------------------
函数名：soft_rtc_run
描  述：运行函数。每一秒运行一次即可。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-8-31
修改记录：
-------------------------------------------------------*/
extern void soft_rtc_run(void);
/*-------------------------------------------------------
函数名：soft_rtc_set_date
描  述：设置日期函数。
输  入：
    year    年份
    month   月份
    day     日期
输  出：无
返回值：
    SOFTRTC_OK          设置正确
    SOFTRTC_MON_ERR     月份设置错误
    SOFTRTC_DAY_ERR     日期设置错误
    SOFTRTC_WEEK_ERR    星期设置错误
创建者：奈特
调用例程：无
创建日期：2021-8-31
修改记录：
-------------------------------------------------------*/
extern u8 soft_rtc_set_date(u16 year,u8 month,u8 day,u8 week);
/*-------------------------------------------------------
函数名：soft_rtc_set_time
描  述：设置时间函数。
输  入：
    hour    时
    minute  分
    second  秒
输  出：无
返回值：
    SOFTRTC_OK          设置正确
    SOFTRTC_HOUR_ERR    时设置错误
    SOFTRTC_MIN_ERR     分设置错误
    SOFTRTC_SEC_ERR     秒设置错误
创建者：奈特
调用例程：无
创建日期：2021-8-31
修改记录：
-------------------------------------------------------*/
extern u8 soft_rtc_set_time(u8 hour,u8 minute,u8 second);
/*-------------------------------------------------------
函数名：soft_rtc_update
描  述：更新时间函数，将本函数放入串口中断回调中。
输  入：
    dat     串口接收到的数据。
输  出：无
返回值：
    0   没有更新数据。
    1   有更新数据。
创建者：奈特
调用例程：无
创建日期：2024-09-13
修改记录：
-------------------------------------------------------*/
extern u8 soft_rtc_update(u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。