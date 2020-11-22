#ifndef _ECBM_GPIO_H_
#define _ECBM_GPIO_H_
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
//<h>普通优化设置
//<i>在这里选择将要使用IO口。这样用不到的Px口就不会编译，节约flash空间。
//<i>并且把没用到的Px口屏蔽掉还能加快函数的操作时间。
//<i>比如8脚的STC8F1K08只有P3和P5，那么为了压缩空间和加速，只使能P3和P5即可。
//<q>P0口使能
#define ECBM_GPIO0_EN 1
//<q>P1口使能
#define ECBM_GPIO1_EN 1
//<q>P2口使能
#define ECBM_GPIO2_EN 1
//<q>P3口使能
#define ECBM_GPIO3_EN 1
//<q>P4口使能
#define ECBM_GPIO4_EN 1
//<q>P5口使能
#define ECBM_GPIO5_EN 1
//<q>P6口使能
#define ECBM_GPIO6_EN 1
//<q>P7口使能
#define ECBM_GPIO7_EN 1
//</h>
//<h>深度优化
//<i>深度优化就是具体优化到函数，剔除不需要的函数达到尽可能减小占用空间的目的。
//<i>但是会影响到其他库的使用，建议只在简单应用+小容量单片机的情况下设置这些选项。
//<q>gpio_write
#define ECBM_GPIO_WRITE_EN 1
//<q>gpio_read
#define ECBM_GPIO_READ_EN 1
//<q>gpio_uppull
#define ECBM_GPIO_UPPULL_EN 1
//<q>gpio_mode
#define ECBM_GPIO_MODE_EN 1
//<q>gpio_speed
#define ECBM_GPIO_SPEED_EN 1
//<q>gpio_current
#define ECBM_GPIO_CURRENT_EN 1
//<q>gpio_out
#define ECBM_GPIO_OUT_EN 1
//<q>gpio_in
#define ECBM_GPIO_IN_EN 1
//<q>gpio_toggle
#define ECBM_GPIO_TOGGLE_EN 1
//<q>gpio_toggle_fast
#define ECBM_GPIO_TOGGLE_FAST_EN 1
//<q>gpio_out_fast
#define ECBM_GPIO_OUT_FAST_EN 1
//<q>gpio_in_fast
#define ECBM_GPIO_IN_FAST_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#if 1  //点击左侧-号能快速折叠宏定义项。
/*
在24MHz的频率下，STC8F2K32S2直接操作寄存器的IO翻转速度为3MHz。
而使用gpio_toggle达到375KHz，使用gpio_toggle_fast达到666KHz。
请根据需求来选择直接操作寄存器还是使用库函数。
*/
#define GPIO_PU  0       //设置IO为弱上拉。
#define GPIO_HZ  1       //设置IO为高阻态。
#define GPIO_OD  2       //设置IO为开漏。
#define GPIO_PP  3       //设置IO为推挽。
#define GPIO_IN  GPIO_PU //输入模式设定为弱上拉。
#define GPIO_OUT GPIO_PP //输出模式设定为推挽。

#define	GPIO_FAST 	0
#define	GPIO_SLOW	1

#define	GPIO_STR	0
#define	GPIO_GEN 	1


#define GPIO_PIN_0   0x01//操作IO引脚Px.0。
#define GPIO_PIN_1   0x02//操作IO引脚Px.1。
#define GPIO_PIN_2   0x04//操作IO引脚Px.2。
#define GPIO_PIN_3   0x08//操作IO引脚Px.3。
#define GPIO_PIN_4   0x10//操作IO引脚Px.4。
#define GPIO_PIN_5   0x20//操作IO引脚Px.5。
#define GPIO_PIN_6   0x40//操作IO引脚Px.6。
#define GPIO_PIN_7   0x80//操作IO引脚Px.7。
#define GPIO_PIN_All 0xFF//操作IO所有引脚。

#define GPIO_P0  0//操作P0口。
#define GPIO_P1  1//操作P1口。
#define GPIO_P2  2//操作P2口。
#define GPIO_P3  3//操作P3口。
#define GPIO_P4  4//操作P4口。
#define GPIO_P5  5//操作P5口。
#define GPIO_P6  6//操作P6口。
#define GPIO_P7  7//操作P7口。

#define D00 0x00//对应的是P00。
#define D01 0x01//对应的是P01。
#define D02 0x02//对应的是P02。
#define D03 0x03//对应的是P03。
#define D04 0x04//对应的是P04。
#define D05 0x05//对应的是P05。
#define D06 0x06//对应的是P06。
#define D07 0x07//对应的是P07。

#define D10 0x10//对应的是P10。
#define D11 0x11//对应的是P11。
#define D12 0x12//对应的是P12。
#define D13 0x13//对应的是P13。
#define D14 0x14//对应的是P14。
#define D15 0x15//对应的是P15。
#define D16 0x16//对应的是P16。
#define D17 0x17//对应的是P17。

#define D20 0x20//对应的是P20。
#define D21 0x21//对应的是P21。
#define D22 0x22//对应的是P22。
#define D23 0x23//对应的是P23。
#define D24 0x24//对应的是P24。
#define D25 0x25//对应的是P25。
#define D26 0x26//对应的是P26。
#define D27 0x27//对应的是P27。

#define D30 0x30//对应的是P30。
#define D31 0x31//对应的是P31。
#define D32 0x32//对应的是P32。
#define D33 0x33//对应的是P33。
#define D34 0x34//对应的是P34。
#define D35 0x35//对应的是P35。
#define D36 0x36//对应的是P36。
#define D37 0x37//对应的是P37。

#define D40 0x40//对应的是P40。
#define D41 0x41//对应的是P41。
#define D42 0x42//对应的是P42。
#define D43 0x43//对应的是P43。
#define D44 0x44//对应的是P44。
#define D45 0x45//对应的是P45。
#define D46 0x46//对应的是P46。
#define D47 0x47//对应的是P47。

#define D50 0x50//对应的是P50。
#define D51 0x51//对应的是P51。
#define D52 0x52//对应的是P52。
#define D53 0x53//对应的是P53。
#define D54 0x54//对应的是P54。
#define D55 0x55//对应的是P55。
#define D56 0x56//对应的是P56。
#define D57 0x57//对应的是P57。

#define D60 0x60//对应的是P60。
#define D61 0x61//对应的是P61。
#define D62 0x62//对应的是P62。
#define D63 0x63//对应的是P63。
#define D64 0x64//对应的是P64。
#define D65 0x65//对应的是P65。
#define D66 0x66//对应的是P66。
#define D67 0x67//对应的是P67。

#define D70 0x70//对应的是P70。
#define D71 0x71//对应的是P71。
#define D72 0x72//对应的是P72。
#define D73 0x73//对应的是P73。
#define D74 0x74//对应的是P74。
#define D75 0x75//对应的是P75。
#define D76 0x76//对应的是P76。
#define D77 0x77//对应的是P77。

#define Dxx 0x88//因为STC8系列没有这个脚，所以把它作为空闲脚。
#define GPIO_Px 8//因为STC8系列没有这个P口，所以把它作为空闲脚。
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用************************IO设置模块******************************/#if 1
/*-------------------------------------------------------
函数名：gpio_uppull
描  述：IO口上拉电阻配置函数，可设定打开或关闭某个IO口的内置上拉电阻。
输  入：
       pin - IO口的编号，即DXX。比如P1.0脚就是D10。
       en  - 使能开关，1代表打开上拉电阻；0代表关闭上拉电阻。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_uppull(D10,1);//P1.0口打开内部的上拉电阻。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-05-25：优化存储空间和速度。
2020-10-12：bit参数换成u8。
-------------------------------------------------------*/
extern void gpio_uppull(u8 pin,u8 en);
/*-------------------------------------------------------
函数名：gpio_mode
描  述：设置IO口工作模式函数，有弱上拉、高阻态、开漏和推挽这四种模式。四种模式的代号参见上面的宏定义。
输  入：
       pin - IO口的编号，即DXX。比如P1.0脚就是D10。
       mode- 需要设置的模式，比如高阻态就是GPIO_HZ。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_mode(D10,GPIO_HZ);//P1.0口设置为高阻态模式。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
-------------------------------------------------------*/
extern void gpio_mode(u8 pin,u8 mode);
/*-------------------------------------------------------
函数名：gpio_speed
描  述：设置IO口工作速度函数,仅限stc8g和stc8h。
输  入：
       pin  - IO口的编号，即DXX。比如P1.0脚就是D10。
       speed- 需要设置的速度，参考宏定义。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_speed(D10,GPIO_FAST);//P1.0口设置为快速模式。
创建日期：2020-11-9
修改记录：
-------------------------------------------------------*/
extern void gpio_speed(u8 pin,u8 speed);
/*-------------------------------------------------------
函数名：gpio_current
描  述：设置IO口驱动电流函数,仅限stc8g和stc8h。
输  入：
       pin    - IO口的编号，即DXX。比如P1.0脚就是D10。
       current- 需要设置的驱动电流，参考宏定义。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_current(D10,GPIO_STR);//P1.0口设置为大电流模式。
创建日期：2020-11-9
修改记录：
-------------------------------------------------------*/
extern void gpio_current(u8 pin,u8 current);
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用**********************普通IO操作模块****************************/#if 1
/*-------------------------------------------------------
函数名：gpio_write
描  述：P口写入函数，直接写入8位数据到某个P口上。
输  入： 
        port - 要写入数据的P口编号，如“GPIO_P0”。
        dat  - 要写入的数据，如“0x06”。  
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_write(GPIO_P0,0x06);//P0口发送0x06，即P0的高低电平为0000 0110。 
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。性能无下降。
2019-10-9：加入空闲引脚。性能下降程度和多使能一个P口一样。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
-------------------------------------------------------*/
extern void gpio_write(u8 port,u8 dat);
/*-------------------------------------------------------
函数名：gpio_read
描  述：P口读出函数，将整个P口的值一次性读出(并口)。
输  入：想读出数据的P口编号，如“GPIO_P0”。
输  出：无
返回值：该P口上的值。
创建者：奈特
调用例程：val=gpio_read(GPIO_P0);//将P0的电平状态赋予变量val。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。性能无下降。
2019-10-9：加入空闲引脚。性能下降程度和多使能一个P口一样。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
-------------------------------------------------------*/
extern u8 gpio_read(u8 port);
/*-------------------------------------------------------
函数名：gpio_out
描  述：IO口输出函数，用于输出高低电平。
输  入：
       pin   - 需要输出电平的IO口编号，比如D10。
       value - 具体的高低电平。1代表高电平；0代表低电平。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_out(D10,1);//P1.0口输出高电平。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。性能从300KHz降至200KHz@24MHz
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
2020-10-12：bit参数换成u8。
-------------------------------------------------------*/
extern void gpio_out(u8 pin,u8 value);
/*-------------------------------------------------------
函数名：gpio_in
描  述：IO口输入函数，用于读取某个IO口的电平状态。
输  入：需要读取电平状态的IO口编号，比如D10。
输  出：无
返回值：该IO口的电平状态。
创建者：奈特
调用例程：flag=gpio_in(D10);//把P1.0口的电平状态赋予变量flag。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。性能从279KHz降至171KHz@24MHz
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
2020-10-12：bit参数换成u8。
-------------------------------------------------------*/
extern u8 gpio_in(u8 pin);
/*-------------------------------------------------------
函数名：gpio_toggle
描  述：IO口电平翻转函数。用于翻转某个IO口，速度比用库函数先读后写的方式要快。
输  入：需要翻转电平的IO口。比如D10。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_toggle(D10);//翻转P1.0口的电平状态。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。性能从353KHz降至222KHz@24MHz
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-05-25:优化存储空间和速度。
-------------------------------------------------------*/
extern void gpio_toggle(u8 pin);
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用**********************快速IO操作模块****************************/#if 1
/*-------------------------------------------------------
函数名：gpio_toggle_fast
描  述：IO口电平快速翻转函数。和上面的翻转函数的差别在于需要提供P口编号。翻转速度更快。
输  入：
       port - 需要翻转的IO口所在的P口编号。比如要翻转P1.0就填“GPIO_P1”。
       pin  - 需要翻转的IO口编号，比如要翻转P1.0就填“GPIO_PIN_0”。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_toggle_fast(GPIO_P1,GPIO_PIN_0);//P1.0口的电平翻转。
创建日期：2019-7-15
修改记录：
2019-8-14:备注--由于加入报错功能降低函数性能，所以该函数没有报错功能。
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
-------------------------------------------------------*/
extern void gpio_toggle_fast(u8 port,u8 pin);
/*-------------------------------------------------------
函数名：gpio_out_fast
描  述：IO口电平快速输出函数。和上面的输出函数的差别在于需要提供P口编号。执行速度更快。
输  入：
       port - 需要输出电平的IO口所在的P口编号。比如P1.0就填“GPIO_P1”。
       pin  - 需要输出电平的IO口编号，比如P1.0就填“GPIO_PIN_0”。
       val  - 需要输出的具体电平状态值。
输  出：无
返回值：无
创建者：奈特
调用例程：gpio_out_fast(GPIO_P1,GPIO_PIN_0,1);//P1.0口输出高电平。
创建日期：2019-7-15
修改记录：
2019-8-14:备注--由于加入报错功能降低函数性能，所以该函数没有报错功能。
2019-10-9：加入空闲引脚。
2019-10-11：引入深度优化。
2020-10-12：bit参数换成u8。
-------------------------------------------------------*/
extern void gpio_out_fast(u8 port,u8 pin,u8 val);
/*-------------------------------------------------------
函数名：gpio_in_fast
描  述：IO口电平快速输入函数。和上面的输入函数的差别在于需要提供P口编号。执行速度更快。
输  入：
       port - 需要读取电平状态的IO口所在的P口编号。比如P1.0就填“GPIO_P1”。
       pin  - 需要读取电平状态的IO口编号，比如P1.0就填“GPIO_PIN_0”。
输  出：无
返回值：该IO口的电平状态。
创建者：奈特
调用例程：flag=gpio_in_fast(GPIO_P1,GPIO_PIN_0);//把P1.0的电平状态值赋予变量flag。
创建日期：2019-7-15
修改记录：
2019-8-14:备注--由于加入报错功能降低函数性能，所以该函数没有报错功能。
2019-10-9：加入空闲引脚。性能下降程度和多使能一个P口一样。
2019-10-11：引入深度优化。
2020-10-12：bit参数换成u8。
-------------------------------------------------------*/
extern u8 gpio_in_fast(u8 port,u8 pin);
/*程序区折叠专用**************************************************************/#endif
#endif
