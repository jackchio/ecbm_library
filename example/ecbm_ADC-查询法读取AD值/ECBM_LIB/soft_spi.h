#ifndef _ECBM_SOFT_SPI_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_SOFT_SPI_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>软件SPI模式设置
//<q.7>MOSI脚使能
//<q.6>MISO脚使能
//<e.5>CS脚使能
//<o.4>CS脚的控制权
//<0=>用户控制 <1=>库函数控制
//</e>
//<o.2>数据收发顺序
//<1=>先收/发数据的高位（MSB） <0=>先收/发数据的低位（LSB）
//<o.1>SPI时钟极性控制
//<i>请根据目标器件的协议选择。
//<0=>SCLK空闲时为低电平 <1=>SCLK空闲时为高电平
//<o.0>SPI时钟相位控制
//<i>请根据目标器件的协议选择。
//<1=>在时钟变化的第一个边沿 <0=>在时钟变化的第二个边沿
#define ECBM_SOFT_SPI_MODE 0x94
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
//|  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
//|MOSIEN|MISOEN| CSEN |CS_CON|  --  |M/LSB | CPOL | CPHA |
#define SOFT_SPI_MOSI_EN_MASK 0x80 //MOSI脚使能
#define SOFT_SPI_MOSI_ENABLE  0x80 //开放MOSI脚
#define SOFT_SPI_MOSI_DISABLE 0x7F //关闭MOSI脚

#define SOFT_SPI_MISO_EN_MASK 0x40 //MISO脚使能
#define SOFT_SPI_MISO_ENABLE  0x40 //开放MISO脚
#define SOFT_SPI_MISO_DISABLE 0xBF //关闭MISO脚

#define SOFT_SPI_CS_EN_MASK   0x20 //CS脚使能
#define SOFT_SPI_CS_ENABLE    0x20 //开放CS脚
#define SOFT_SPI_CS_DISABLE   0xDF //关闭CS脚

#define SOFT_SPI_CS_CON_MASK  0x10 //CS脚控制权限
#define SOFT_SPI_CS_SYSTEM    0x10 //CS由库函数控制
#define SOFT_SPI_CS_USER      0xEF //CS由用户自己控制

#define SOFT_SPI_MSB_LSB_MASK 0x04 //高/位选择
#define SOFT_SPI_MSB          0x04 //先发高位
#define SOFT_SPI_LSB          0xFB //先发低位

#define SOFT_SPI_CPOL_MASK    0x02 //时钟空闲电平
#define SOFT_SPI_CPOL_1       0x02 //空闲高电平
#define SOFT_SPI_CPOL_0       0xFD //空闲低电平

#define SOFT_SPI_CPHA_MASK    0x01 //时钟相位
#define SOFT_SPI_CPHA_1       0x01 //在第一个时钟沿采样
#define SOFT_SPI_CPHA_0       0xFE //在第二个时钟沿采样
/*--------------------------------------变量定义-----------------------------------*/
extern u8 xdata soft_spi_def_clk_port;
extern u8 xdata soft_spi_def_clk_pin;
extern u8 xdata soft_spi_def_mosi_port;
extern u8 xdata soft_spi_def_mosi_pin;
extern u8 xdata soft_spi_def_miso_port;
extern u8 xdata soft_spi_def_miso_pin;
extern u8 xdata soft_spi_def_cs_port;
extern u8 xdata soft_spi_def_cs_pin;
extern u8 xdata soft_spi_mode;
extern u8 xdata soft_spi_index;
extern u8 xdata soft_spi_max;
typedef struct{
	u8 clk_pin; //SPI里的时钟脚。
	u8 mosi_pin;//SPI里的数据输出脚。
	u8 miso_pin;//SPI里的数据输入脚。
	u8 cs_pin;  //SPI里的片选脚。
	u8 mode;    //SPI的运行模式。
	u8 dev_id;  //软件SPI的唯一ID。作为切换的凭证。
}soft_spi_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：soft_spi_set_pin
描  述：软件SPI引脚切换函数。
输  入：软件SPI的信息包。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-24
修改记录：
-------------------------------------------------------*/
extern void soft_spi_set_pin(soft_spi_def * dev);
/*-------------------------------------------------------
函数名：soft_spi_init。
描  述：软件SPI初始化函数。
输  入：	
		dev  -  软件SPI的信息包。
		clk  -  软件SPI的时钟脚。
		mosi -  软件SPI的数据输出脚。
		miso -  软件SPI的数据输入脚。
		cs   -  软件SPI的片选脚。
		mode -  软件SPI的工作模式。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-24
修改记录：
-------------------------------------------------------*/
extern void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
函数名：soft_spi_set_pin_linkage
描  述：软件SPI引脚切换函数（内联版）。主要用于其他库的调用，若不清楚原理请调用soft_spi_set_pin函数。
输  入：id   -  初始化软件SPI时分配的id号。
		clk  -  软件SPI的时钟脚。
		mosi -  软件SPI的数据输出脚。
		miso -  软件SPI的数据输入脚。
		cs   -  软件SPI的片选脚。
		mode -  软件SPI的工作模式。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-22
修改记录：
-------------------------------------------------------*/
extern void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
函数名：soft_spi_init_linkage
描  述：软件SPI初始化函数（内联版）。主要用于其他库的调用，若不清楚原理请调用soft_spi_init函数。
输  入：	clk  -  软件SPI的时钟脚。
		mosi -  软件SPI的数据输出脚。
		miso -  软件SPI的数据输入脚。
		cs   -  软件SPI的片选脚。
		mode -  软件SPI的工作模式。
输  出：无
返回值：初始化软件SPI时分配的id号。
创建者：奈特
调用例程：无
创建日期：2019-10-22
修改记录：
-------------------------------------------------------*/
extern u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
函数名：soft_spi_send
描  述：软件SPI发送/接收函数。
输  入：要发送的数据。
输  出：无
返回值：接收到的数据。
创建者：奈特
调用例程：
		soft_spi_send(0x55);    //发送某个数据。
		val=soft_spi_send(0xff);//读取某个数据，通常发送内容随意的话就填0xff。
创建日期：2019-10-22
修改记录：
-------------------------------------------------------*/
extern u8 soft_spi_send(u8 dat);
#endif
