#ifndef _VISUALSCOPE_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _VISUALSCOPE_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：vs_send
描  述：虚拟示波器发送函数。
输  入：id	-	发送数据的串口号。本函数直接调用串口发送函数，因此要使用的串口需要提前初始化。
		ch	-	发送的虚拟示波器通道数，可输入1~4。
		dat	-	发送的数据缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：
例1：
	s16 adc_buf;//定义缓存变量。
	...//无关代码。
	adc_buf=(s16)adc_read(0);//读取adc的通道0的ad值存到变量里,注意变量类型转换。
	vs_send(1,1,&adc_buf);//通过串口1，发送ad值到虚拟串口，只用了一个虚拟示波器通道。
	...//无关代码。
例2：
	s16 rocker[2];//定义摇杆缓存数组，2个元素分别对应X轴和Y轴。
	...//无关代码。
	rocker[0]=(s16)adc_read(0);//读取摇杆X轴偏移量。
	rocker[1]=(s16)adc_read(1);//读取摇杆Y轴偏移量。
	vs_send(1,2,rocker);////通过串口1，发送摇杆偏移量到虚拟串口，用了两个虚拟示波器通道。
	...//无关代码。
创建日期：2020-05-08
修改记录：
-------------------------------------------------------*/
extern void vs_send(u8 id,u8 ch,s16 * dat);
#endif
