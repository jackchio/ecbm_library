#ifndef _ECBM_POWER_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_POWER_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>优化和功能使能
//<i>在这里开始所需要的功能，优化不需要的功能。
//<e>看门狗
//<i>该选项只是让编译器编译看门狗的代码，并不会打开看门狗（为了防止看门狗打开得太早，初始化外设时不能喂狗导致单片机一直重启）。
//<i>开启看门狗使用wdt_start();
#define ECBM_POWER_WDOG_EN (0)
//<q.3>IDLE模式时继续计数？
//<i>在IDLE模式下，如果继续计数的话，单片机会因为没有喂狗而重启。
//<o.0..2>看门狗定时器分频系数
//<i>看门狗溢出时间=（12*32768*分频系数）/SYS_CLK。
//<i>在溢出之前调用wdt_feed();喂狗函数就行。
//<0=>2 
//<1=>4 
//<2=>8 
//<3=>16 
//<4=>32 
//<5=>64 
//<6=>128 
//<7=>256  
#define ECBM_POWER_WDT_MODE (0x05)
//</e>
//<q>单片机重启函数
//<i>建立函数只是为了方便在函数内添加其他代码，其实真正有用的就一句话，直接用宏定义指令也能重启单片机。
#define ECBM_POWER_RESET_EN (0)
//<q>单片机电源控制函数
//<i>建立函数只是为了方便在函数内添加其他代码，其实直接用宏定义指令也能控制单片机电源。
#define ECBM_POWER_CONTROL_EN (0)
//<e.15>掉电唤醒定时器使能
//<i>开启唤醒定时器使能后，定时器会在单片机进入掉电模式的时候开始计数。当到达设定值时，会唤醒单片机。
//<o.0..14>定时时间
//<0-32767:1>
//<i>公式：掉电唤醒定时器定时时间=(10^6*16*计数次数)/Fwt,单位微秒。Fwt在32KHz左右，具体值在F8H和F9H可获取。
#define ECBM_POWER_WKTC_CONFIG (4095)
//</e>
//</h>
//<e>复位配置寄存器
//<i>这里的功能和STC-ISP上设置的功能一样，如果没有特殊要求，推荐在STC-ISP上设置，优化掉这个功能来省点空间。
//<i>使能之后会在system_init里自动调用power_rstcfg_init函数。
#define ECBM_POWER_RST_CFG_EN (0)
//<q.6>低压复位
//<i>不勾选，当系统检测到低压事件时，会产生低压中断。
//<i>勾选，当系统检测到低压事件时，会自动复位。
//<o.4>RST脚功能
//<0=>普通IO口(P54) 
//<1=>复位脚
//<o.0..1>低压检测门槛电压设置
//<0=>2.2V 
//<1=>2.4V 
//<2=>2.7V 
//<3=>3.0V
#define ECBM_POWER_RST_CFG_MODE (0x00)
//</e>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：power_reset_code
描  述：复位函数，复位之后从main函数开始运行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    power_reset_code();//复位。
    ...//其他无关的代码。
创建日期：2019-10-11
修改记录：
-------------------------------------------------------*/
extern void power_reset_code(void);
/*-------------------------------------------------------
函数名：power_reset_isp
描  述：复位函数，复位之后从系统BootLoader开始运行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    power_reset_isp();//复位。
    ...//其他无关的代码。
创建日期：2019-10-11
修改记录：
-------------------------------------------------------*/
extern void power_reset_isp(void);
/*-------------------------------------------------------
函数名：power_powerdown
描  述：掉电函数，运行本函数会使单片机进入掉电状态，CPU和外设的电源都会被关掉。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    power_powerdown();//掉电。
    ...//其他无关的代码。
创建日期：2019-10-11
修改记录：
2019-12-05：新增了唤醒定时器，现在支持自动唤醒。
-------------------------------------------------------*/
extern void power_powerdown(void);
/*-------------------------------------------------------
函数名：power_cpu_idle
描  述：CPU空闲函数，运行本函数会只关闭单片机CPU的电源，外设依然正常运行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    power_cpu_idle();//复位。
    ...//其他无关的代码。
创建日期：2019-10-11
修改记录：
-------------------------------------------------------*/
extern void power_cpu_idle(void);
/*-------------------------------------------------------
函数名：wdt_start
描  述：看门狗开启函数。用于打开看门狗。看门狗的参数在图形界面中设置。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    wdt_start();//打开看门狗。
创建日期：2019-10-8
修改记录：
2019-10-11：从ecbm_core.h移动到power.h文件。
-------------------------------------------------------*/
extern void wdt_start(void);
/*-------------------------------------------------------
函数名：wdt_feed
描  述：喂狗函数，如果超过喂狗时间没有执行本函数，单片机就会重启。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    wdt_feed();//喂狗。
    ...//其他无关的代码。
创建日期：2019-10-8
修改记录：
2019-10-11：从ecbm_core.h移动到power.h文件。
-------------------------------------------------------*/
extern void wdt_feed(void);
/*-------------------------------------------------------
函数名：power_rstcfg_init
描  述：复位寄存器初始化函数，初始化的值来自于图形界面的设置。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    ...//其他无关的代码。
    power_rstcfg_init();//设置复位寄存器。
    ...//其他无关的代码。
创建日期：2019-10-11
修改记录：
2019-12-10：添加进了system_init函数里运行。
-------------------------------------------------------*/
extern void power_rstcfg_init(void);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。