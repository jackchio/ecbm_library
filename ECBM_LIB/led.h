#ifndef _ECBM_LED_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_LED_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 奈特

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
//<h>COM使能
//<q.0>COM0
//<q.1>COM1
//<q.2>COM2
//<q.3>COM3
//<q.4>COM4
//<q.5>COM5
//<q.6>COM6
//<q.7>COM7
#define ECBM_LED_COM_EN (0x00)
//</h>
//<h>SEG使能
//<q.0>SEG0
//<q.1>SEG1
//<q.2>SEG2
//<q.3>SEG3
//<q.4>SEG4
//<q.5>SEG5
//<q.6>SEG6
//<q.7>SEG7
#define ECBM_LED_SEGL_EN (0x00)
//<q.0>SEG8
//<q.1>SEG9
//<q.2>SEG10
//<q.3>SEG11
//<q.4>SEG12
//<q.5>SEG13
//<q.6>SEG14
//<q.7>SEG15
#define ECBM_LED_SEGH_EN (0x00)
//</h>
//<o.4..5>LED工作模式
//<0=>共阴模式
//<1=>共阳模式
//<2=>共阴/共阳模式
//<o.0..2>LED亮度调节
//<0=>100%
//<1=>87.5%
//<2=>75%
//<3=>62.5%
//<4=>50%
//<5=>37.5%
//<6=>25%
//<7=>12.5%
#define ECBM_LED_CTRL (0x00)
//<o>LED时钟分屏
//<0-255>
#define ECBM_LED_CLK_DIV (1)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define LED_MODE_DC     (0x00)
#define LED_MODE_DA     (0x10)
#define LED_MODE_DCA    (0x20)

#define LED_DUTY_8_8    (0x00)
#define LED_DUTY_7_8    (0x01)
#define LED_DUTY_6_8    (0x02)
#define LED_DUTY_5_8    (0x03)
#define LED_DUTY_4_8    (0x04)
#define LED_DUTY_3_8    (0x05)
#define LED_DUTY_2_8    (0x06)
#define LED_DUTY_1_8    (0x07)
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：led_init
描  述：LED外设初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_init(void);
/*-------------------------------------------------------
函数名：led_start
描  述：LED开始工作函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_start(void);
/*-------------------------------------------------------
函数名：led_stop
描  述：LED停止工作函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_stop(void);
/*-------------------------------------------------------
函数名：led_set_mode
描  述：LED工作设置函数。
输  入：
    mode    有3种工作模式，其宏定义为：
                LED_MODE_DC     共阴模式
                LED_MODE_DA     共阳模式
                LED_MODE_DCA    共阴/共阳模式
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_set_mode(u8 mode);
/*-------------------------------------------------------
函数名：led_set_duty
描  述：LED亮度设置函数。
输  入：
    duty    有8种亮度，其宏定义为：
                LED_DUTY_8_8    100%亮度
                LED_DUTY_7_8    87.5%亮度
                LED_DUTY_6_8    75%亮度
                LED_DUTY_5_8    62.5%亮度
                LED_DUTY_4_8    50%亮度
                LED_DUTY_3_8    37.5%亮度
                LED_DUTY_2_8    25%亮度
                LED_DUTY_1_8    12.5%亮度
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_set_duty(u8 duty);
/*-------------------------------------------------------
函数名：led_set_freq
描  述：LED驱动频率函数。
输  入：
    freq    可输入10~255。单位为Hz。推荐在75Hz以上。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-11
修改记录：
-------------------------------------------------------*/
extern void led_set_freq(u8 freq);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。