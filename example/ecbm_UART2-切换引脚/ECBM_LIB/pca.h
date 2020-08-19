#ifndef _ECBM_PCA_H_
#define _ECBM_PCA_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 奈特

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
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>PCA主设置
//<q.7>空闲模式下是否停止PCA计数
//<i>勾选：空闲模式下PCA停止计数。
//<i>不勾选：空闲模式下PCA继续计数。
//<o.1..3>PCA计数脉冲源
//<2=>定时器0的溢出脉冲 <3=>ECI脚的外部输入时钟 <4=>SYSCLK    <1=>SYSCLK/2 
//<5=>SYSCLK/4         <6=>SYSCLK/6           <7=>SYSCLK/8  <0=>SYSCLK/12 
//<q.0>PCA计数器溢出中断使能
#define ECBM_PCA_CMOD 0x09
//<q>PCA计数器溢出回调函数
#define ECBM_PCA_CALLBACK_EN 1
//<o.4..5>PCA引脚
//<0=>ECI-P12|CCP0-P17|CCP1-P16|CCP2-P15|CCP3-P14
//<1=>ECI-P22|CCP0-P23|CCP1-P24|CCP2-P25|CCP3-P26
//<2=>ECI-P74|CCP0-P70|CCP1-P71|CCP2-P72|CCP3-P73
//<3=>ECI-P35|CCP0-P33|CCP1-P32|CCP2-P31|CCP3-P30
#define ECBM_PCA_IO 0x00
//</h>
//<e>PCA0
//<i>捕获通道0的使能
#define ECBM_PCA0_EN 1
//<o>工作模式
//<0=>无功能
//<1=>6位PWM模式
//<2=>7位PWM模式
//<3=>8位PWM模式
//<4=>10位PWM模式
//<5=>16位捕获模式
//<6=>16位软件定时器
//<7=>16位高速脉冲输出
#define ECBM_PCA0_MODE 5
//<q.5>上升沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的上升沿时中断。
//<q.4>下降沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的下降沿时中断。
#define ECBM_PCA0_UP_DOWN 0x20
//<q>自动重装定时值使能
//<i>在PCA工作在定时器模式或者高速脉冲输出模式时，使能该功能可以在中断中自动重装定时器。
//<i>但是因为每次的定时值都需要几us的时间去计算，如果定时的时间太短，中断就会卡住，然后单片机死机。
#define ECBM_PCA0_TIMER_AUTO_EN 0
//<q>PCA0模块中断回调函数
#define ECBM_PCA0_CALLBACK_EN 1
//</e>

//<e>PCA1
//<i>捕获通道1的使能
#define ECBM_PCA1_EN 1
//<o>工作模式
//<0=>无功能
//<1=>6位PWM模式
//<2=>7位PWM模式
//<3=>8位PWM模式
//<4=>10位PWM模式
//<5=>16位捕获模式
//<6=>16位软件定时器
//<7=>16位高速脉冲输出
#define ECBM_PCA1_MODE 7
//<q.5>上升沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的上升沿时中断。
//<q.4>下降沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的下降沿时中断。
#define ECBM_PCA1_UP_DOWN 0x00
//<q>自动重装定时值使能
//<i>在PCA工作在定时器模式或者高速脉冲输出模式时，使能该功能可以在中断中自动重装定时器。
//<i>但是因为每次的定时值都需要几us的时间去计算，如果定时的时间太短，中断就会卡住，然后单片机死机。
#define ECBM_PCA1_TIMER_AUTO_EN 1
//<q>PCA1模块中断回调函数
#define ECBM_PCA1_CALLBACK_EN 0
//</e>

//<e>PCA2
//<i>捕获通道2的使能
#define ECBM_PCA2_EN 0
//<o>工作模式
//<0=>无功能
//<1=>6位PWM模式
//<2=>7位PWM模式
//<3=>8位PWM模式
//<4=>10位PWM模式
//<5=>16位捕获模式
//<6=>16位软件定时器
//<7=>16位高速脉冲输出
#define ECBM_PCA2_MODE 7
//<q.5>上升沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的上升沿时中断。
//<q.4>下降沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的下降沿时中断。
#define ECBM_PCA2_UP_DOWN 0x00
//<q>自动重装定时值使能
//<i>在PCA工作在定时器模式或者高速脉冲输出模式时，使能该功能可以在中断中自动重装定时器。
//<i>但是因为每次的定时值都需要几us的时间去计算，如果定时的时间太短，中断就会卡住，然后单片机死机。
#define ECBM_PCA2_TIMER_AUTO_EN 0
//<q>PCA2模块中断回调函数
#define ECBM_PCA2_CALLBACK_EN 0
//</e>

//<e>PCA3
//<i>捕获通道3的使能
#define ECBM_PCA3_EN 0
//<o>工作模式
//<0=>无功能
//<1=>6位PWM模式
//<2=>7位PWM模式
//<3=>8位PWM模式
//<4=>10位PWM模式
//<5=>16位捕获模式
//<6=>16位软件定时器
//<7=>16位高速脉冲输出
#define ECBM_PCA3_MODE 7
//<q.5>上升沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的上升沿时中断。
//<q.4>下降沿中断/捕获
//<i>在捕获模式下，勾选此选项，可以在收到外部信号的下降沿时中断。
#define ECBM_PCA3_UP_DOWN 0x00
//<q>自动重装定时值使能
//<i>在PCA工作在定时器模式或者高速脉冲输出模式时，使能该功能可以在中断中自动重装定时器。
//<i>但是因为每次的定时值都需要几us的时间去计算，如果定时的时间太短，中断就会卡住，然后单片机死机。
#define ECBM_PCA3_TIMER_AUTO_EN 0
//<q>PCA3模块中断回调函数
#define ECBM_PCA3_CALLBACK_EN 0
//</e>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define PCA_ECOMn_1 0x40
#define PCA_ECOMn_0 0xBF

#define PCA_CAPPn_1 0x20
#define PCA_CAPPn_0 0xDF

#define PCA_CAPNn_1 0x10
#define PCA_CAPNn_0 0xEF

#define PCA_MATn_1  0x08
#define PCA_MATn_0  0xF7

#define PCA_TOGn_1  0x04
#define PCA_TOGn_0  0xFB

#define PCA_PWMn_1  0x02
#define PCA_PWMn_0  0xFD

#define PCA_ECCFn_1 0x01
#define PCA_ECCFn_0 0xFE

#define PCA_PIN_P1  0x00
#define PCA_PIN_P2  0x10
#define PCA_PIN_P7  0x20
#define PCA_PIN_P3  0x30
/*--------------------------------------变量定义-----------------------------------*/
extern u8  pca_mode_0;
extern u8  pca_mode_1;
extern u8  pca_mode_2;
extern u8  pca_mode_3;

extern u16 pca_timer_count_0;
extern u16 pca_timer_count_1;
extern u16 pca_timer_count_2;
extern u16 pca_timer_count_3;

extern u16 pca_timer_add_0;
extern u16 pca_timer_add_1;
extern u16 pca_timer_add_2;
extern u16 pca_timer_add_3;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：pca_init
描  述：PCA初始化置函数。需要在图形化界面设置好工作模式。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca_init(void);
/*-------------------------------------------------------
函数名：pca_set_io
描  述：PCA设置IO映射函数。对应的引脚在图形化界面可以看得到。
输  入：io  -  可以输入PCA_PIN_P1、PCA_PIN_P2、PCA_PIN_P7、PCA_PIN_P3。
		       对应关系在图形化界面可以看得到
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void pca_set_io(u8 io);
/*-------------------------------------------------------
函数名：pca_set_mode
描  述：PCA在PWM模式下的占空比设置函数。使用本函数前确认该通道的工作模式是PWM模式。
输  入：id   -  要设置占空比的通道号，可输入0~3，对应CCP0~CCP3。
		mode -  要设置的工作模式，可输入0~7。对应的功能见下表。
		<0>无功能
		<1>6位PWM模式
		<2>7位PWM模式
		<3>8位PWM模式
		<4>10位PWM模式
		<5>16位捕获模式
		<6>16位软件定时器
		<7>16位高速脉冲输出
输  出：无
返回值：无
创建者：奈特
调用例程：pca_set_mode(0,2);//设置CCP0输出7位PWM波。
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca_set_mode(u8 id,u8 mode);
/*-------------------------------------------------------
函数名：pca_set_timer
描  述：PCA在定时器模式或高速脉冲输出模式下的计数值设置函数。
		使用本函数前确认该通道的工作模式是定时器模式或高速脉冲输出模式。
输  入：id    -  要设置计数值的通道号，可输入0~3，对应CCP0~CCP3。
		count -  要设置的计数值，可根据PCA的时钟和目标定时时间来算出计数值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca_set_timer(u8 id,u16 count);
/*-------------------------------------------------------
函数名：pca_set_duty
描  述：PCA在PWM模式下的占空比设置函数。使用本函数前确认该通道的工作模式是PWM模式。
输  入：id   -  要设置占空比的通道号，可输入0~3，对应CCP0~CCP3。
		duty -  要设置的占空比，可输入0~1000。对应0%~100.0%，但是精度和PWM位数有关。
输  出：无
返回值：无
创建者：奈特
调用例程：pca_set_duty(0,543);//设置CCP0输出PWM波的占空比为54.3%。
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca_set_duty(u8 id,u16 duty);
/*-------------------------------------------------------
函数名：pca_timer_callback
描  述：PCA计数器溢出回调函数。是在计数器从65535溢出到0的时候触发的。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca_timer_callback(void);
/*-------------------------------------------------------
函数名：pca0_callback
描  述：PCA模块0中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca0_callback(void);
/*-------------------------------------------------------
函数名：pca1_callback
描  述：PCA模块1中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca1_callback(void);
/*-------------------------------------------------------
函数名：pca2_callback
描  述：PCA模块2中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca2_callback(void);
/*-------------------------------------------------------
函数名：pca3_callback
描  述：PCA模块3中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-13
修改记录：
-------------------------------------------------------*/
extern void pca3_callback(void);
#endif
