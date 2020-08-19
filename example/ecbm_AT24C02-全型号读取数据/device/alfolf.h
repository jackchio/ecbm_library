#ifndef _ALFOLF_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ALFOLF_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	float min;
	float max;
	float err;
	float value;
}alfolf_def;//限幅一阶线性滤波器。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：alfolf_init
描  述：限幅一阶线性滤波器的初始化函数。
输  入：dev   -   要初始化的滤波器。
		min   -   要限幅的最小值。
		max   -   要限幅的最大值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-29
修改记录：
-------------------------------------------------------*/
extern void alfolf_init(alfolf_def * dev,float min,float max);
/*-------------------------------------------------------
函数名：alfolf_in
描  述：限幅一阶线性滤波器的数据输入函数。
输  入：dev       -   要输入数据的滤波器。
		in        -   被滤波的数据。
输  出：dev.value  -  滤波后的数据
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-29
修改记录：
-------------------------------------------------------*/
extern void alfolf_in(alfolf_def * dev,float in);
#endif
