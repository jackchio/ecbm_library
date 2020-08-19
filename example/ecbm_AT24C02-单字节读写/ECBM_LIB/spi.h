#ifndef _ECBM_SPI_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_SPI_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>SPI库内部设置
//<o.4>主/从机
//<0=>从机  <1=>主机
//<i>根据自己的需求设置。
//<o.7>SS引脚使能
//<i>SS就是片选端。
//<i>使能SS脚后，如果SS脚被外界拉低，那么无论之前是主机还是从机，都会强制被切换成从机。
//<i>使能SS脚后，如果SS脚被外界拉高，那么是主机还是从机就由上面的“主/从机”设置来决定。
//<i>通常要是一直都作为主机的话，就可以不使用SS引脚
//<o.5>数据收发顺序
//<0=>先收/发数据的高位（MSB） <1=>先收/发数据的低位（LSB）
//<i>根据目标器件选择。
//<o.0..1>SPI时钟
//<i>SYSCLK就是主频，在STC-ISP上设置的那个。
//<0=>SYSCLK/4 <1=>SYSCLK/8 <2=>SYSCLK/16 <3=>SYSCLK/32 
//<o.3>SPI时钟极性控制
//<i>请根据目标器件的协议选择。
//<0=>SCLK空闲时为低电平 <1=>SCLK空闲时为高电平
//<o.2>SPI时钟相位控制
//<i>请根据目标器件的协议选择。
//<0=>在时钟变化的第一个边沿 <1=>在时钟变化的第二个边沿
#define ECBM_SPI_REG 0x50
//<o.2..3>SPI输出管脚
//<i>定义SPI输出的管脚，共有4组可选。
//<0=>SS-P12|MOSI-P13|MISO-P14|SCLK-P15
//<1=>SS-P22|MOSI-P23|MISO-P24|SCLK-P25
//<2=>SS-P74|MOSI-P75|MISO-P76|SCLK-P77
//<3=>SS-P35|MOSI-P34|MISO-P33|SCLK-P32
#define ECBM_SPI_IO 0
//</h>
//<q>SPI中断
//<i>SPI传输完成一个字节就会触发中断。
#define ECBM_SPI_IT_EN 0
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define SPI_IT_ON  do{IE2|=0x02;}while(0)
#define SPI_IT_OFF do{IE2&=0xFD;}while(0)
#define SPI_IT_ID  interrupt 9
#define SPI_PIN_P1 0
#define SPI_PIN_P2 4
#define SPI_PIN_P7 8
#define SPI_PIN_P3 12
#if ECBM_SPI_IT_EN == 1
extern u8 xdata spi_busy;
#define SPI_IT_CLS do{SPSTAT = 0xc0;spi_busy=0;}while(0)
#endif
//void SPI_Isr() SPI_IT_ID
//{
//    SPI_IT_CLS;     //清中断标志
//    LED = !LED;     //测试端口
//}
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：spi_set_pin
描  述：SPI的引脚设置函数。SPI支持4个组，对应在P1、P2、P7、P3上。
输  入：group - 设置SPI输出的引脚。可以输入SPI_PIN_P1、SPI_PIN_P2、SPI_PIN_P7、SPI_PIN_P3。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-22
修改记录：
-------------------------------------------------------*/
extern void spi_set_pin(u8 group);
/*-------------------------------------------------------
函数名：spi_init
描  述：SPI初始化函数。参数可以在图形界面输入。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：spi_init();//初始化SPI
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
extern void spi_init(void);
/*-------------------------------------------------------
函数名：spi_send
描  述：SPI发送/接收函数。
输  入：要发送的数据。
输  出：无
返回值：接收到的数据。
创建者：奈特
调用例程：
		spi_send(0x55);    //发送某个数据。
		val=spi_send(0xff);//读取某个数据，通常发送内容随意的话就填0xff。
创建日期：2019-10-22
修改记录：
-------------------------------------------------------*/
extern u8 spi_send(u8 dat);
#endif
