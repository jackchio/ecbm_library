#ifndef _MDU16_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _MDU16_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
函数名：div32
描  述：32位除16位除法函数。
输  入：num1  -  无符号32位被除数。
		num2  -  无符号16位除数。
输  出：num1  -  无符号32位商。
		num2  -  无符号16位余数。
返回值：溢出位。
创建者：奈特
调用例程：无
创建日期：2020-03-27
修改记录：
-------------------------------------------------------*/
extern u8 div32(u32 * num1,u16 * num2);
/*-------------------------------------------------------
函数名：div16
描  述：16位除16位除法函数。
输  入：num1  -  无符号16位被除数。
		num2  -  无符号16位除数。
输  出：num1  -  无符号16位商。
		num2  -  无符号16位余数。
返回值：溢出位。
创建者：奈特
调用例程：无
创建日期：2020-03-27
修改记录：
-------------------------------------------------------*/
extern u8 div16(u16 * num1,u16 * num2);
/*-------------------------------------------------------
函数名：mul16
描  述：16位乘16位乘法函数。
输  入：num1  -  无符号16位被乘数。
		num2  -  无符号16位乘数。
输  出：num3  -  无符号32位积。
返回值：溢出位。
创建者：奈特
调用例程：无
创建日期：2020-03-27
修改记录：
-------------------------------------------------------*/
extern u8 mul16(u16 num1,u16 num2,u32 * num3);
#endif
