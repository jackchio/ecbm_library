#ifndef _AD9833_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _AD9833_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//这里就填写当前库的各项设置。
//<o>AD9833的主时钟
//<i>填写AD9833使用的主时钟频率，单位为Hz。根据板子的实际时钟来填写。
#define AD9833_MCLK 25000000
//<h>AD9833初始状态设置
//<i>由于DDS是输出形态更改比较频繁的器件，所以这里的设置值只作用于初始化函数。
//<o.0..7>输出波形选择
//<0x00=>正弦波
//<0x02=>三角波
//<0x68=>矩形波
//<0xE8=>不输出

#define AD9833_REG 0x2000
//<o>初始频率
//<i>如果在上面的设置中选择了波形输出，那么就要在这里设置波形的频率。单位Hz。
#define AD9833_FREQ 10000000
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define AD9833_OFF_WAVE	0x00//用户专用，关闭输出。
#define AD9833_TRI_WAVE	0x01//用户专用，输出三角波。
#define AD9833_SIN_WAVE	0x02//用户专用，输出正弦波。
#define AD9833_SQU_WAVE	0x03//用户专用，输出矩形波。


#define AD9833_REG_OFF_WAVE 0xE8//设置寄存器专用，关闭波形输出。
#define AD9833_REG_TRI_WAVE 0x02//设置寄存器专用，设置三角波参数。
#define AD9833_REG_SIN_WAVE 0x00//设置寄存器专用，设置正弦波参数。
#define AD9833_REG_SQU_WAVE 0x68//设置寄存器专用，设置矩形波参数。

#define AD9833_CONFIG_REG_MASK 0x0000	//控制字的地址掩码。
#define AD9833_FREQ0_REG_MASK  0x4000	//频率0寄存器掩码。
#define AD9833_FREQ1_REG_MASK  0x8000	//频率1寄存器掩码。
#define AD9833_PHASE0_REG_MASK 0xC000	//相位0寄存器掩码。
#define AD9833_PHASE1_REG_MASK 0xE000	//相位1寄存器掩码。

/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 fsync;	//ad9833的片选脚。
	u8 sclk;	//ad9833的时钟脚。
	u8 sdata;	//ad9833的数据脚。
	u8 config;	//ad9833的简明配置。
//|D7  D6  D5  D4 |   D3   |   D2   |   D1  D0  |
//|     预留      |当前频率|当前相位|输出波形类型|
}ad9833_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：ad9833_write
描  述：ad9833的写函数，用于向ad9833发送一串16位数据。
输  入：dev     -  需要发送的器件。
		txdata  -  需要发送的16位数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-25
修改记录：
-------------------------------------------------------*/
extern void ad9833_write(ad9833_def * dev,u16 txdata);
/*-------------------------------------------------------
函数名：ad9833_set_freq
描  述：AD9833设置频率函数，可以设置AD9833的输出波形频率。
输  入：dev  -  需要修改频率的器件。
		freq -  需要修改的目标频率。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-25
修改记录：
-------------------------------------------------------*/
extern void ad9833_set_freq(ad9833_def * dev,double freq);
/*-------------------------------------------------------
函数名：ad9833_set_wave
描  述：AD9833设置波形函数，可以设置AD9833的输出波形。
输  入：dev  -  需要修改频率的器件。
		freq -  需要修改的目标波形。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-25
修改记录：
-------------------------------------------------------*/
extern void ad9833_set_wave(ad9833_def * dev,u8 wave);
/*-------------------------------------------------------
函数名：ad9833_init
描  述：ad9833的初始化函数，初始化引脚的定义。
输  入：dev  -  需要初始化的器件。
		fsync-  ad9833的片选脚。
		sclk -  ad9833的时钟脚。
		sdata-  ad9833的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-25
修改记录：
-------------------------------------------------------*/
extern void ad9833_init(ad9833_def * dev,u8 fsync,u8 sclk,u8 sdata);

#endif
