#ifndef _ECBM_PWM16_OUT_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_PWM16_OUT_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>PWMA组
//<h>引脚位置选择
//<i>PWMxP和PWMxN是成对出现的，基本一改就是同时改两个位置。
//<o.0..1>通道1的输出脚
//<0=>PWM1P[P1.0]PWM1N[P1.1]
//<1=>PWM1P[P2.0]PWM1N[P2.1]
//<2=>PWM1P[P6.0]PWM1N[P6.1]
//<o.2..3>通道2的输出脚
//<0=>PWM2P[P1.2/P5.4]PWM2N[P1.3]
//<1=>PWM2P[P2.2]PWM2N[P2.3]
//<2=>PWM2P[P6.2]PWM2N[P6.3]
//<o.4..5>通道3的输出脚
//<0=>PWM3P[P1.4]PWM3N[P1.5]
//<1=>PWM3P[P2.4]PWM3N[P2.5]
//<2=>PWM3P[P6.4]PWM3N[P6.5]
//<o.6..7>通道4的输出脚
//<0=>PWM4P[P1.6]PWM4N[P1.7]
//<1=>PWM4P[P2.6]PWM4N[P2.7]
//<2=>PWM4P[P6.6]PWM4N[P6.7]
//<3=>PWM4P[P3.4]PWM4N[P3.3]
#define ECBM_PWM16_OUT_GROUPA_PIN_SEL (192)
//<o.0..1>外部触发脚
//<0=>P3.2
//<1=>P4.1
//<2=>P7.3
//<o.2>刹车脚
//<0=>P3.5
//<1=>比较器输出
#define ECBM_PWM16_OUT_GROUPA_EXT_PIN_SEL (0)
//</h>
//<h>引脚输出使能
//<i>本设置会影响波形的对外输出，但是不会影响内部波形的产生。
//<i>可以认为本设置是PWM模块和GPIO模块之间的连接使能。
//<q.0>PWM1P输出使能
//<q.1>PWM1N输出使能
//<q.2>PWM2P输出使能
//<q.3>PWM2N输出使能
//<q.4>PWM3P输出使能
//<q.5>PWM3N输出使能
//<q.6>PWM4P输出使能
//<q.7>PWM4N输出使能
#define ECBM_PWM16_OUT_GROUPA_PIN_EN (3)
//</h>
//<h>信号极性选择
//<i>本设置会影响波形！请认真进行合理的设置。所谓“影响波形”目前有两个例子可以举。
//<i>第一种情况：当PWM1P和PWM1N都是输出时（无论正反），就会引入死区控制。
//<i>当然引入死区控制之后，也需要死区控制寄存器有正确的值才会出正常的波形。若不需要加入死区请确保死区寄存器为0。
//<i>而另一种情况，就是PWM1P为【正向输出】，PWM1N为【反向输出】的时候，由于PWM1N本来就是PWM1P的反向，就会负负得正，得到两个一样的波形。
//<o.0..1>PWM1P
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.2..3>PWM1N
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.4..5>PWM2P
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.6..7>PWM2N
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
#define ECBM_PWM16_OUT_GROUPA_PIN12_POL (13)
//<o.0..1>PWM3P
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.2..3>PWM3N
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.4..5>PWM4P
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.6..7>PWM4N
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
#define ECBM_PWM16_OUT_GROUPA_PIN34_POL (0)
//</h>
//<e.4>刹车功能使能
//<i>刹车功能就是当单片机收到刹车信号时，停止PWM波的输出。
//<q.6>自动输出使能
//<i>当PWM因为刹车而停下来的时候，可以手动判断启动，也可以自动启动。
//<i>自动启动的条件是触发一次事件，由于刹车只关了MOE没有关CEN，所以一般是在下一次计时溢出时自动启动。
//<i>因此启动的时间会随着溢出时间变化而变化。
//<o.5>刹车输入极性
//<i>可以设置为高电平或者低电平触发刹车。
//<0=>低电平
//<1=>高电平
#define ECBM_PWM16_OUT_GROUPA_BKR   (80)
//<h>刹车功能控制范围
//<i>倘若不是所有PWM通道都需要刹车，那么可以在这里选择刹车的范围。
//<q.0>PWM1P
//<q.1>PWM1N
//<q.2>PWM2P
//<q.3>PWM2N
//<q.4>PWM3P
//<q.5>PWM3N
//<q.6>PWM4P
//<q.7>PWM4N
#define ECBM_PWM16_OUT_GROUPA_IOAUX   (3)
//</h>
//</e>
//<h>死区时间设置
//<i>死区时间就是在一些应用下防止上下管MOS同时导通导致烧毁的，加入死区时间之后，PWM波形的占空比会受影响。
//<i>所以非必要就不要加入死区时间。
//<o.5..7>计算公式
//<0=> 1*( 0+(输入值))*PWM时钟
//<1=> 1*(32+(输入值))*PWM时钟
//<2=> 1*(64+(输入值))*PWM时钟
//<3=> 1*(96+(输入值))*PWM时钟
//<4=> 2*(64+(输入值))*PWM时钟
//<5=> 2*(96+(输入值))*PWM时钟
//<6=> 8*(32+(输入值))*PWM时钟
//<7=>16*(32+(输入值))*PWM时钟
//<o.0..4>输入值
#define ECBM_PWM16_OUT_GROUPA_DTR (0)
//</h>
//<h>空闲状态电平
//<i>手册用的就是OCn而不是PWMnP。原因应该是这些信号可以不输出到IO口。
//<o.0>OC1P
//<0=>低电平
//<1=>高电平
//<o.1>OC1N
//<0=>低电平
//<1=>高电平
//<o.2>OC2P
//<0=>低电平
//<1=>高电平
//<o.3>OC2N
//<0=>低电平
//<1=>高电平
//<o.4>OC3P
//<0=>低电平
//<1=>高电平
//<o.5>OC3N
//<0=>低电平
//<1=>高电平
//<o.6>OC4P
//<0=>低电平
//<1=>高电平
//<o.7>OC4N
//<0=>低电平
//<1=>高电平
#define ECBM_PWM16_OUT_GROUPA_PIN_OIS (0)
//</h>
//<h>频率和占空比
//<i>PWM输出频率=系统工作频率/((预分频器+1)*(自动重装值+1))
//<i>一般只在特殊调整时才会用到这些，大部分情况用pwm16_out_groupa_wave_start函数就能得到比较指定频率和占空比的波形了。
//<o.0..15>预分频器
#define ECBM_PWM16_OUT_GROUPA_FREQ (0)
//<o.0..15>自动重装值
#define ECBM_PWM16_OUT_GROUPA_ARR (11)
//<o.0..15>PWM1占空比
#define ECBM_PWM16_OUT_GROUPA_CH1_DUTY (5)
//<o.0..15>PWM2占空比
#define ECBM_PWM16_OUT_GROUPA_CH2_DUTY (0)
//<o.0..15>PWM3占空比
#define ECBM_PWM16_OUT_GROUPA_CH3_DUTY (0)
//<o.0..15>PWM4占空比
#define ECBM_PWM16_OUT_GROUPA_CH4_DUTY (0)
//</h>
//<q.7>自动预装载使能
//<o.4..6>对齐模式
//<i>一般应用而言，选向上或向下计数就够了。
//<i>其他对齐模式主要用在电机应用上，用来和ADC联动采集电流。
//<0=>向上计数
//<1=>向下计数
//<2=>中央对齐(中断只在向下计数触发)
//<4=>中央对齐(中断只在向上计数触发)
//<6=>中央对齐(中断在上下计数里都触发)
//<q.3>单脉冲模式
//<i>注意，当使用pwm16_out_groupa_wave_start函数之后，该设置无效。
#define ECBM_PWM16_OUT_GROUPA_CR1     (0)
//</h>

//<h>PWMB组
//<h>引脚位置选择
//<o.0..1>通道5的输出脚
//<0=>P2.0
//<1=>P1.7
//<2=>P0.0
//<3=>P7.4
//<o.2..3>通道6的输出脚
//<0=>P2.1
//<1=>P5.4
//<2=>P0.1
//<3=>P7.5
//<o.4..5>通道7的输出脚
//<0=>P2.2
//<1=>P3.3
//<2=>P0.2
//<3=>P7.6
//<o.6..7>通道8的输出脚
//<0=>P2.3
//<1=>P3.4
//<2=>P0.3
//<3=>P7.7
#define ECBM_PWM16_OUT_GROUPB_PIN_SEL (0)
//<o.0..1>外部触发脚
//<0=>P3.2
//<1=>P0.6
//<o.2>刹车脚
//<0=>P3.5
//<1=>比较器输出
#define ECBM_PWM16_OUT_GROUPB_EXT_PIN_SEL (0)
//</h>
//<h>引脚输出使能
//<i>本设置会影响波形的对外输出，但是不会影响内部波形的产生。
//<i>可以认为本设置是PWM模块和GPIO模块之间的连接使能。
//<q.0>PWM5输出使能
//<q.2>PWM6输出使能
//<q.4>PWM7输出使能
//<q.6>PWM8输出使能
#define ECBM_PWM16_OUT_GROUPB_PIN_EN (0)
//</h>
//<h>信号极性选择
//<i>本设置会影响波形！请认真进行合理的设置。所谓“影响波形”目前有两个例子可以举。
//<i>第一种情况：当PWM1P和PWM1N都是输出时（无论正反），就会引入死区控制。
//<i>当然引入死区控制之后，也需要死区控制寄存器有正确的值才会出正常的波形。若不需要加入死区请确保死区寄存器为0。
//<i>而另一种情况，就是PWM1P为【正向输出】，PWM1N为【反向输出】的时候，由于PWM1N本来就是PWM1P的反向，就会负负得正，得到两个一样的波形。
//<o.0..1>PWM5
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.4..5>PWM6
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
#define ECBM_PWM16_OUT_GROUPB_PIN56_POL (15)
//<o.0..1>PWM7
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
//<o.4..5>PWM8
//<0=>关闭信号
//<1=>正向输出
//<3=>反向输出
#define ECBM_PWM16_OUT_GROUPB_PIN78_POL (0)
//</h>
//<e.4>刹车功能使能
//<i>刹车功能就是当单片机收到刹车信号时，停止PWM波的输出。
//<q.6>自动输出使能
//<i>当PWM因为刹车而停下来的时候，可以手动判断启动，也可以自动启动。
//<i>自动启动的条件是触发一次事件，由于刹车只关了MOE没有关CEN，所以一般是在下一次计时溢出时自动启动。
//<i>因此启动的时间会随着溢出时间变化而变化。
//<o.5>刹车输入极性
//<i>可以设置为高电平或者低电平触发刹车。
//<0=>低电平
//<1=>高电平
#define ECBM_PWM16_OUT_GROUPB_BKR   (0)
//<h>刹车功能控制范围
//<i>倘若不是所有PWM通道都需要刹车，那么可以在这里选择刹车的范围。
//<q.0>PWM5
//<q.2>PWM6
//<q.4>PWM7
//<q.6>PWM8
#define ECBM_PWM16_OUT_GROUPB_IOAUX   (0)
//</h>
//</e>
//<h>死区时间设置
//<i>死区时间就是在一些应用下防止上下管MOS同时导通导致烧毁的，加入死区时间之后，PWM波形的占空比会受影响。
//<i>所以非必要就不要加入死区时间。
//<o.5..7>计算公式
//<0=> 1*( 0+(输入值))*PWM时钟
//<1=> 1*(32+(输入值))*PWM时钟
//<2=> 1*(64+(输入值))*PWM时钟
//<3=> 1*(96+(输入值))*PWM时钟
//<4=> 2*(64+(输入值))*PWM时钟
//<5=> 2*(96+(输入值))*PWM时钟
//<6=> 8*(32+(输入值))*PWM时钟
//<7=>16*(32+(输入值))*PWM时钟
//<o.0..4>输入值
#define ECBM_PWM16_OUT_GROUPB_DTR (0)
//</h>
//<h>空闲状态电平
//<i>手册用的就是OCn而不是PWMnP。原因应该是这些信号可以不输出到IO口。
//<o.0>OC5
//<0=>低电平
//<1=>高电平
//<o.2>OC6
//<0=>低电平
//<1=>高电平
//<o.4>OC7
//<0=>低电平
//<1=>高电平
//<o.6>OC8
//<0=>低电平
//<1=>高电平
#define ECBM_PWM16_OUT_GROUPB_PIN_OIS (0)
//</h>
//<h>频率和占空比
//<i>PWM输出频率=系统工作频率/((预分频器+1)*(自动重装值+1))
//<i>一般只在特殊调整时才会用到这些，大部分情况用pwm16_out_groupa_wave_start函数就能得到比较指定频率和占空比的波形了。
//<o.0..15>预分频器
#define ECBM_PWM16_OUT_GROUPB_FREQ (0)
//<o.0..15>自动重装值
#define ECBM_PWM16_OUT_GROUPB_ARR (0)
//<o.0..15>PWM5占空比
#define ECBM_PWM16_OUT_GROUPB_CH5_DUTY (0)
//<o.0..15>PWM6占空比
#define ECBM_PWM16_OUT_GROUPB_CH6_DUTY (0)
//<o.0..15>PWM7占空比
#define ECBM_PWM16_OUT_GROUPB_CH7_DUTY (0)
//<o.0..15>PWM8占空比
#define ECBM_PWM16_OUT_GROUPB_CH8_DUTY (0)
//</h>
//<q.7>自动预装载使能
//<o.4..6>对齐模式
//<i>一般应用而言，选向上或向下计数就够了。
//<i>其他对齐模式主要用在电机应用上，用来和ADC联动采集电流。
//<0=>向上计数
//<1=>向下计数
//<2=>中央对齐(中断只在向下计数触发)
//<4=>中央对齐(中断只在向上计数触发)
//<6=>中央对齐(中断在上下计数里都触发)
//<q.3>单脉冲模式
//<i>注意，当使用pwm16_out_groupa_wave_start函数之后，该设置无效。
#define ECBM_PWM16_OUT_GROUPB_CR1     (0)
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：pwm16_out_init
描  述：高级16位PWM的初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_init(void);
/*-------------------------------------------------------
函数名：pwm16_out_groupa_start
描  述：高级16位PWMA组和B组的启动函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_groupa_start(void);
extern void pwm16_out_groupb_start(void);
/*-------------------------------------------------------
函数名：pwm16_out_groupa_stop
描  述：高级16位PWMA组和B组的停止函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_groupa_stop(void);
extern void pwm16_out_groupb_stop(void);
/*-------------------------------------------------------
函数名：pwm16_out_set_freq
描  述：高级16位PWM的频率设置函数。
输  入：
    ch      通道号，范围1~8。若输入1~4，则会修改A组的频率值。若输入5~8，则会修改B组的频率值。
    freq    频率值，单位Hz。若输入0，则不会做任何修改。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_set_freq(u8 ch,u32 freq);
/*-------------------------------------------------------
函数名：pwm16_out_set_duty
描  述：高级16位PWM的占空比设置函数。
输  入：
    ch          通道号，范围1~8。
    ch_duty     该通道的占空比值，范围0~10000。对应0%~100.00%。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_set_duty(u8 ch,u16 ch_duty);
/*-------------------------------------------------------
函数名：pwm16_out_pulse_start
描  述：高级16位PWM的启动函数（以可数脉冲的模式启动）。
输  入：
    ch          通道号，范围1~8。
    ch_count    该通道要发送的脉冲数量，范围1~255。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_pulse_start(u8 ch,u8 ch_count);
/*-------------------------------------------------------
函数名：pwm16_out_wave_start
描  述：高级16位PWM的启动函数（以波形输出的模式启动）。
输  入：
    ch          通道号，范围1~8。
    ch_duty     该通道的占空比值，范围0~10000。对应0%~100.00%。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2025-01-11
修改记录：
-------------------------------------------------------*/
extern void pwm16_out_wave_start(u8 ch,u16 ch_duty);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。