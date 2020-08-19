#ifndef _MCP4725_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _MCP4725_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 scl_pin;	//时钟脚。
	u8 sda_pin;	//数据脚。
	u8 id;		//软件IIC的ID号
	u8 config;  //芯片的配置。
//  D7  |  D6  D5  D4  D3  D2  D1  D0 
//软硬件|预留
//	
	u8 addr;	//芯片的地址。
}mcp4725_def;
/*--------------------------------------程序定义-----------------------------------*/
/*---------------------------------------宏定义------------------------------------*/
#define MCP4725_IIC_MASK	0x80//IIC的配置掩码。
#define MCP4725_SOFT_IIC	0x00//使用软件的IIC。
#define MCP4725_HARD_IIC	0x80//使用硬件的IIC。
/*-------------------------------------------------------
函数名：mcp4725_soft_init
描  述：MCP4725的初始化函数，使用软件IIC。
输  入：dev  -  要初始化的器件。
		scl  -  该器件的时钟脚。
		sda  -  该器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-03-01
修改记录：
-------------------------------------------------------*/
void mcp4725_soft_init(mcp4725_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：mcp4725_hard_init
描  述：MCP4725的初始化函数，使用硬件IIC。
输  入：dev  -  要初始化的器件。
		scl  -  该器件的时钟脚。
		sda  -  该器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-03-02
修改记录：
-------------------------------------------------------*/
void mcp4725_hard_init(mcp4725_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：mcp4725_set_addr
描  述：MCP4725的设置地址函数，可以修改器件地址。
输  入：dev  -  要修改的器件。
		addr -  该器件的IIC地址。可输入0~7。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-03-01
修改记录：
-------------------------------------------------------*/
void mcp4725_set_addr(mcp4725_def * dev,u8 addr);
/*-------------------------------------------------------
函数名：mcp4725_run
描  述：MCP4725的运行函数。用于输出一个模拟量。
输  入：dev  -  要操作的器件。
		dat  -  要转化成模拟量的数字量。可输入0~4095，对应芯片的0~VCC-1LSB。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-03-01
修改记录：
-------------------------------------------------------*/
void mcp4725_run(mcp4725_def * dev,u16 dat);
/*-------------------------------------------------------
函数名：mcp4725_out
描  述：MCP4725的输出函数。和运行函数差不多，但是支持模拟值。
输  入：dev  -  要操作的器件。
		vcc  -  器件的VCC,但是需要注意的是该芯片有满偏误差，所以这里输入的值要比实际VCC要小一点。
		out  -  要器件输出的电压值，要小于参数的VCC值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-03-01
修改记录：
-------------------------------------------------------*/
void mcp4725_out(mcp4725_def * dev,float vcc,float out);
#endif
