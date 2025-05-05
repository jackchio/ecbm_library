#ifndef _ECBM_BEEP_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_BEEP_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2025 奈特

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
//<o>蜂鸣器响的电平
//<i>由于外部电路是完全自由的（比如NPN电路是高电平响，PNP电路是低电平响。），所以得先设置蜂鸣器响起来的电平。
//<0=>低电平
//<1=>高电平
#define ECBM_BEEP_IO_WORK (0)
//<o>蜂鸣器驱动脚对应的port
//<0x80=>P0
//<0x90=>P1
//<0xA0=>P2
//<0xB0=>P3
//<0xC0=>P4
//<0xC8=>P5
//<0xE8=>P6
//<0xF8=>P7
#define ECBM_BEEP_IO_PORT (0xB0)
//<o>蜂鸣器驱动脚对应的pin
//<0x00=>0
//<0x01=>1
//<0x02=>2
//<0x03=>3
//<0x04=>4
//<0x05=>5
//<0x06=>6
//<0x07=>7
#define ECBM_BEEP_IO_PIN  (0x03)
//<o>响的时长
//<i>定义默认状态下蜂鸣器响的时间长度，后续也可以用beep_set_class函数修改。
//<i>该值为10mS的倍数，比如输入5，就是响5*10=50mS。
#define ECBM_BEEP_ON_TIME_MAX  (8)
//<o>间隔的时长
//<i>定义默认状态下两次蜂鸣器响的间隔时间长度，后续也可以用beep_set_class函数修改。通常是连续响多次的时候才会用到这个值。
//<i>该值为10mS的倍数，比如输入5，就是响5*10=50mS。
#define ECBM_BEEP_OFF_TIME_MAX  (12)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：beep_set_class
描  述：蜂鸣器修改样式函数，可以设置蜂鸣器响的时长和间隔时长。
输  入：
    on_time     响的时长。
    off_time    间隔的时长。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-03-05
修改记录：
-------------------------------------------------------*/
extern void beep_set_class(u8 on_time,u8 off_time);
/*-------------------------------------------------------
函数名：beep_start
描  述：蜂鸣器响函数。
输  入：
    count     响的次数。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-03-05
修改记录：
-------------------------------------------------------*/
extern void beep_start(u8 count);
/*-------------------------------------------------------
函数名：beep_idle
描  述：蜂鸣器空闲函数，断开库对IO的控制，实现自定义的蜂鸣器控制。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-03-05
修改记录：
-------------------------------------------------------*/
extern void beep_idle(void);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。