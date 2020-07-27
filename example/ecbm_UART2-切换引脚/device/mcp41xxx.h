#ifndef _MCP41XXX_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _MCP41XXX_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>MCP41XXX初始状态设置
//<i>由于DDS是输出形态更改比较频繁的器件，所以这里的设置值只作用于初始化函数。
//<o>初始幅度值
//<i>从0到255。
//<0-255>
#define MCP41XXX_INIT_AMP 150
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 cs;	//片选脚
	u8 sck;	//时钟脚
	u8 dat;	//数据脚
}mcp41xxx_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：mcp41xxx_init
描  述：MCP41XXX系列的初始化函数。
输  入：dev   -  需要初始化的器件。
		cs   -   该器件的片选脚。
		sck  -   该器件的时钟脚。
		dat  -   该器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-01
修改记录：
-------------------------------------------------------*/
extern void mcp41xxx_init(mcp41xxx_def *dev,u8 cs,u8 sck,u8 dat);
/*-------------------------------------------------------
函数名：mcp41xxx_set_amp
描  述：MCP41XXX系列的设置幅值函数，可以设置0~255。
输  入：dev   -  需要初始化的器件。
		amp  -  需要设置的幅值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-01
修改记录：
-------------------------------------------------------*/
extern void mcp41xxx_set_amp(mcp41xxx_def *dev,u8 amp);
#endif
