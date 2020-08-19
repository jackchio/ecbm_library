#ifndef _ECBM_TIMER_H_
#define _ECBM_TIMER_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 奈特

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
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<e>定时器0使能与设置
//<i>勾选该选项会使能定时器0，开放和定时器0相关的操作函数。若未使用定时器0，可以关掉优化空间。
#define ECBM_TIMER0_EN 0
//<o.3>定时器开关
//<0=>软件开关 <1=>软硬件开关。
//<i>当选择“软件开关”时，运行timer_start函数就能启动定时器0。
//<i>当选择“软硬件开关”时，除了运行timer_start函数外，INT0（P32）脚要为高电平才启动定时器0。通常会用在通过外部硬件来启动定时器的情况。
//<o.2>计数来源
//<0=>对系统时钟计数（定时器应用）
//<1=>对外部T0（P34）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.0..1>工作模式
//<i>16位自动重载模式：当计数寄存器溢出时，自动重载设定好的初值。
//<i>16位不自动重载模式：当计数寄存器溢出时，从0开始计数（如果不想从0开始，需要在定时器中断里给定时器赋予初值）。
//<i>8位自动重载模式：只使用TL0计数，当TL0溢出时，自动把TH0的值赋予TL0。
//<i>16位自动重载（不可屏蔽中断）模式：与上面的16位自动重载模式一样，但是会产生一个不可屏蔽的中断。
//<0=>16位自动重载模式
//<1=>16位不自动重载模式
//<2=>8位自动重载模式（不推荐、鸡肋）
//<3=>16位自动重载（不可屏蔽中断）模式 
#define ECBM_TIMER0_TMOD 0x04
//<o.7>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
#define ECBM_TIMER0_AUXR 0x80
//<o.0>对外输出时钟
//<i>勾选该选项后，每次定时器0发生溢出时，T0CLKO（P35）脚的电平自动发生翻转。
#define ECBM_TIMER0_INTCLKO 0x01
//<o>定时时间/计数数量
//<0-65535>
//<i>在这里填入脉冲数（在定时模式下，脉冲数=定时时间/时间基准。在计数模式下，就是你想计数的最大值）。
//<i>比如定时模式下，主频24MHz的时间基准是1/24000000秒，定时100us的脉冲数就是0.0001*(1/24000000)=2400。那么输入2400就行了。
//<i>时间基准计算比较麻烦，做定时器应用时可以直接调用timer_set_timer_mode函数。
//<i>如果是在计数模式下，希望统计到100个脉冲就触发中断，那么输入100就行了。
#define ECBM_TIMER0_COUNT 10
//<q>定时器0的中断使能
#define ECBM_TIMER0_IT_EN 0
//</e>
//<e>定时器1使能与设置
//<i>勾选该选项会使能定时器1，开放和定时器1相关的操作函数。若未使用定时器1，可以关掉优化空间。
#define ECBM_TIMER1_EN 0
//<o.7>定时器开关
//<0=>软件开关 <1=>软硬件开关。
//<i>当选择“软件开关”时，运行timer_start函数就能启动定时器1。
//<i>当选择“软硬件开关”时，除了运行timer_start函数外，INT1（P33）脚要为高电平才启动定时器1。通常会用在通过外部硬件来启动定时器的情况。
//<o.6>计数来源
//<0=>对系统时钟计数（定时器应用）
//<1=>对外部T1（P35）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.4..5>工作模式
//<i>16位自动重载模式：当计数寄存器溢出时，自动重载设定好的初值。
//<i>16位不自动重载模式：当计数寄存器溢出时，从0开始计数（如果不想从0开始，需要在定时器中断里给定时器赋予初值）。
//<i>8位自动重载模式：只使用TL1计数，当TL1溢出时，自动把TH1的值赋予TL1。
//<0=>16位自动重载模式
//<1=>16位不自动重载模式
//<2=>8位自动重载模式（不推荐、鸡肋）
#define ECBM_TIMER1_TMOD 0x00
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
#define ECBM_TIMER1_AUXR 0x40
//<o.1>对外输出时钟
//<i>勾选该选项后，每次定时器1发生溢出时，T1CLKO（P34）脚的电平自动发生翻转。
#define ECBM_TIMER1_INTCLKO 0x02
//<o>定时时间/计数数量
//<0-65535>
//<i>在这里填入脉冲数（在定时模式下，脉冲数=定时时间/时间基准。在计数模式下，就是你想计数的最大值）。
//<i>比如定时模式下，主频24MHz的时间基准是1/24000000秒，定时100us的脉冲数就是0.0001*(1/24000000)=2400。那么输入2400就行了。
//<i>时间基准计算比较麻烦，做定时器应用时可以直接调用timer_set_timer_mode函数。
//<i>如果是在计数模式下，希望统计到100个脉冲就触发中断，那么输入100就行了。
#define ECBM_TIMER1_COUNT 65535
//<q>定时器1的中断使能
#define ECBM_TIMER1_IT_EN 0
//</e>
//<e>定时器2使能与设置
//<i>勾选该选项会使能定时器2，开放和定时器2相关的操作函数。若未使用定时器2，可以关掉优化空间。
#define ECBM_TIMER2_EN 0
//<o.3>计数来源
//<0=>对系统时钟计数（定时器应用）
//<1=>对外部T2（P12）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.2>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
#define ECBM_TIMER2_AUXR 0x04
//<o.2>对外输出时钟
//<i>勾选该选项后，每次定时器2发生溢出时，T2CLKO（P13）脚的电平自动发生翻转。
#define ECBM_TIMER2_INTCLKO 0x04
//<o>定时时间/计数数量
//<0-65535>
//<i>在这里填入脉冲数（在定时模式下，脉冲数=定时时间/时间基准。在计数模式下，就是你想计数的最大值）。
//<i>比如定时模式下，主频24MHz的时间基准是1/24000000秒，定时100us的脉冲数就是0.0001*(1/24000000)=2400。那么输入2400就行了。
//<i>时间基准计算比较麻烦，做定时器应用时可以直接调用timer_set_timer_mode函数。
//<i>如果是在计数模式下，希望统计到100个脉冲就触发中断，那么输入100就行了。
#define ECBM_TIMER2_COUNT 500
//<q>定时器2的中断使能
//<i>注意：定时器2的中断函数里需要清除中断标志位。
#define ECBM_TIMER2_IT_EN 0
//</e>
//<e>定时器3使能与设置
//<i>勾选该选项会使能定时器3，开放和定时器3相关的操作函数。若未使用定时器3，可以关掉优化空间。
#define ECBM_TIMER3_EN 0
//<o.2>计数来源
//<0=>对系统时钟计数（定时器应用）
//<1=>对外部T3（P04）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.1>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.0>对外输出时钟
//<i>勾选该选项后，每次定时器3发生溢出时，T3CLKO（P05）脚的电平自动发生翻转。
#define ECBM_TIMER3_T4T3M 0x00
//<o>定时时间/计数数量
//<0-65535>
//<i>在这里填入脉冲数（在定时模式下，脉冲数=定时时间/时间基准。在计数模式下，就是你想计数的最大值）。
//<i>比如定时模式下，主频24MHz的时间基准是1/24000000秒，定时100us的脉冲数就是0.0001*(1/24000000)=2400。那么输入2400就行了。
//<i>时间基准计算比较麻烦，做定时器应用时可以直接调用timer_set_timer_mode函数。
//<i>如果是在计数模式下，希望统计到100个脉冲就触发中断，那么输入100就行了。
#define ECBM_TIMER3_COUNT 65535
//<q>定时器3的中断使能
//<i>注意：定时器3的中断函数里需要清除中断标志位。
#define ECBM_TIMER3_IT_EN 0
//</e>
//<e>定时器4使能与设置
//<i>勾选该选项会使能定时器4，开放和定时器4相关的操作函数。若未使用定时器4，可以关掉优化空间。
#define ECBM_TIMER4_EN 0
//<o.6>计数来源
//<0=>对系统时钟计数（定时器应用）
//<1=>对外部T4（P06）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.5>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.4>对外输出时钟
//<i>勾选该选项后，每次定时器4发生溢出时，T4CLKO（P07）脚的电平自动发生翻转。
#define ECBM_TIMER4_T4T3M 0x10
//<o>定时时间/计数数量
//<0-65535>
//<i>在这里填入脉冲数（在定时模式下，脉冲数=定时时间/时间基准。在计数模式下，就是你想计数的最大值）。
//<i>比如定时模式下，主频24MHz的时间基准是1/24000000秒，定时100us的脉冲数就是0.0001*(1/24000000)=2400。那么输入2400就行了。
//<i>时间基准计算比较麻烦，做定时器应用时可以直接调用timer_set_timer_mode函数。
//<i>如果是在计数模式下，希望统计到100个脉冲就触发中断，那么输入100就行了。
#define ECBM_TIMER4_COUNT 10000
//<q>定时器4的中断使能
//<i>注意：定时器4的中断函数里需要清除中断标志位。
#define ECBM_TIMER4_IT_EN 0
//</e>
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define TIMER0_ON     do{TF0=0;TR0=1;}while(0) //打开定时器0。
#define TIMER0_OFF    do{TR0=0;}while(0)       //关闭定时器0。
#define TIMER0_IT_ON  do{ET0=1;}while(0)       //打开定时器0中断。
#define TIMER0_IT_OFF do{ET0=0;}while(0)       //关闭定时器0中断。
#define TIMER0_1T     do{AUXR|=0x80;}while(0)  //设定定时器0为1T模式。
#define TIMER0_12T    do{AUXR&=0x7F;}while(0)  //设定定时器0为12T模式。
#define TIMER0_TIMER  do{TMOD&=0xFB;}while(0)  //设定定时器0为定时器。
#define TIMER0_COUNT  do{TMOD|=0x04;}while(0)  //设定定时器0为计数器。


#define TIMER1_ON     do{TF1=0;TR1=1;}while(0) //打开定时器1。
#define TIMER1_OFF    do{TR1=0;}while(0)       //关闭定时器1。
#define TIMER1_IT_ON  do{ET1=1;}while(0)       //打开定时器1中断。
#define TIMER1_IT_OFF do{ET1=0;}while(0)       //关闭定时器1中断。
#define TIMER1_1T     do{AUXR|=0x40;}while(0)  //设定定时器1为1T模式。
#define TIMER1_12T    do{AUXR&=0xBF;}while(0)  //设定定时器1为12T模式。
#define TIMER1_TIMER  do{TMOD&=0xBF;}while(0)  //设定定时器1为定时器。
#define TIMER1_COUNT  do{TMOD|=0x40;}while(0)  //设定定时器1为计数器。

#define TIMER2_ON     do{AUXR|=0x10;}while(0)  //打开定时器2。
#define TIMER2_OFF    do{AUXR&=0xEF;}while(0)  //关闭定时器2。
#define TIMER2_IT_ON  do{IE2 |=0x04;}while(0)  //打开定时器2中断。
#define TIMER2_IT_OFF do{IE2 &=0xFB;}while(0)  //关闭定时器2中断。
#define TIMER2_IT_CLS do{AUXINTIF&=0xFE;}while(0)//清定时器2中断标志
#define TIMER2_1T     do{AUXR|=0x04;}while(0)  //设定定时器2为1T模式。
#define TIMER2_12T    do{AUXR&=0xFB;}while(0)  //设定定时器2为12T模式。
#define TIMER2_TIMER  do{AUXR&=0xF7;}while(0)  //设定定时器2为定时器。
#define TIMER2_COUNT  do{AUXR|=0x08;}while(0)  //设定定时器2为计数器。

#define TIMER3_ON     do{T4T3M|=0x08;}while(0) //打开定时器3。
#define TIMER3_OFF    do{T4T3M&=0xF7;}while(0) //关闭定时器3。
#define TIMER3_IT_ON  do{IE2  |=0x20;}while(0) //打开定时器3中断。
#define TIMER3_IT_OFF do{IE2  &=0xDF;}while(0) //关闭定时器3中断。
#define TIMER3_IT_CLS do{AUXINTIF&=0xFD;}while(0)//清定时器3中断标志
#define TIMER3_1T     do{T4T3M|=0x02;}while(0) //设定定时器3为1T模式。
#define TIMER3_12T    do{T4T3M&=0xFD;}while(0) //设定定时器3为12T模式。
#define TIMER3_TIMER  do{T4T3M&=0xFB;}while(0) //设定定时器3为定时器。
#define TIMER3_COUNT  do{T4T3M|=0x04;}while(0) //设定定时器3为计数器。

#define TIMER4_ON     do{T4T3M|=0x80;}while(0) //打开定时器4。
#define TIMER4_OFF    do{T4T3M&=0x7F;}while(0) //关闭定时器4。
#define TIMER4_IT_ON  do{IE2  |=0x40;}while(0) //打开定时器4中断。
#define TIMER4_IT_OFF do{IE2  &=0xBF;}while(0) //关闭定时器4中断。
#define TIMER4_IT_CLS do{AUXINTIF&=0xFB;}while(0)//清定时器4中断标志
#define TIMER4_1T     do{T4T3M|=0x20;}while(0) //设定定时器4为1T模式。
#define TIMER4_12T    do{T4T3M&=0xDF;}while(0) //设定定时器4为12T模式。
#define TIMER4_TIMER  do{T4T3M&=0xBF;}while(0) //设定定时器4为定时器。
#define TIMER4_COUNT  do{T4T3M|=0x40;}while(0) //设定定时器4为计数器。


#define TIMER0_FUN interrupt 1 //定时器0的中断服务号。
#define TIMER1_FUN interrupt 3 //定时器1的中断服务号。
#define TIMER2_FUN interrupt 12//定时器2的中断服务号。
#define TIMER3_FUN interrupt 19//定时器3的中断服务号。
#define TIMER4_FUN interrupt 20//定时器4的中断服务号。



/*--------------------------------------变量定义-----------------------------------*/
//extern u8 value;//定义需要的变量。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：timer_start
描  述：定时器开始函数。用于打开一个定时器。
输  入：需要打开的定时器编号。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-16
修改记录：
-------------------------------------------------------*/
extern void timer_start(u8 id);
/*-------------------------------------------------------
函数名：timer_stop
描  述：定时器停止函数。用于关闭一个定时器。
输  入：需要关闭的定时器编号。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-16
修改记录：
-------------------------------------------------------*/
extern void timer_stop(u8 id);
/*-------------------------------------------------------
函数名：timer_init
描  述：定时器初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-17
修改记录：
-------------------------------------------------------*/
extern void timer_init(void);
/*-------------------------------------------------------
函数名：timer_set_timer_mode
描  述：定时器设定定时模式函数。可将指定的定时器设定成指定的时间中断。
输  入：id  -  要设定的定时器号。
		us  -  要设定的时间，单位us。太长的时间可以在中断里延长。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-01-07
修改记录：
2020-06-05:修复了定时器3和定时器4在使用时影响定时器1的问题。
-------------------------------------------------------*/
extern void timer_set_timer_mode(u8 id,u16 us);
/*-------------------------------------------------------
函数名：timer_set_value
描  述：定时器设定初值函数。可向指定的定时器装填定时初值，推荐先停止定时器再写。
输  入：id     -  要设定的定时器号。
		value  -  要设定的初值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-01-07
修改记录：
-------------------------------------------------------*/
extern void timer_set_value(u8 id,u16 value);
/*-------------------------------------------------------
函数名：timer_get_value
描  述：定时器计数值获取函数。可读出指定的定时器当前的计数值，推荐先停止定时器再读。
输  入：id  -  要设定的定时器号。
		us  -  要设定的时间，单位us。太长的时间可以在中断里延长。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-01-07
修改记录：
-------------------------------------------------------*/
extern u16 timer_get_value(u8 id);
#endif
