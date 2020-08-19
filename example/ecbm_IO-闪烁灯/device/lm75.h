#ifndef _LM75_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _LM75_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<o.0>工作状态
//<i>默认在初始化芯片的时候就写入一次配置，所以这里选关断的话，上电芯片就不工作，直到使能它正常工作。
//<0=>正常工作  <1=>关断
//<o.1>OS引脚工作模式
//<i>比较器模式就是当温度超报警值之后，OS引脚一直为有效电平，直到温度低于滞后值。
//<i>中断模式就是当温度超过报警值之后，OS引脚变为有效电平直到单片机读取读取温度就变为非有效电平。
//<0=>比较器模式  <1=>中断模式
//<o.2>OS引脚极性
//<0=>有效电平为低电平  <1=>有效电平为高电平
#define LM75_CONFIG 0x00
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define XXX_XXX_XXX do{XXX_XXX}while(0) //这样定义指令型的宏定义。
#define XXX_XXX		XXX_XX				//这样定义常量型宏定义。
/*--------------------------------------变量定义-----------------------------------*/
extern u8 value;//定义需要的变量。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：
描  述：
输  入：
输  出：
返回值：
创建者：
调用例程：
创建日期：
修改记录：
-------------------------------------------------------*/

#endif
