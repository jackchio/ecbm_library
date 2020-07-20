#ifndef _DS18B20_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _DS18B20_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
	u8 port;	//由于18b20的通讯对时序要求高，所以将IO口拆分。
	u8 pin;		
	float temp;	//存放温度值
}ds18b20_def;
//DS18B20的管脚排列是：当平面朝着自己的时候，引脚向下，从左到右分别是GND、DQ、VCC
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：ds18b20_init
描  述：DS18B20的初始化函数。
输  入：dev  -  需要初始化的器件。
		pin  -  该器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-04
修改记录：
-------------------------------------------------------*/
extern void ds18b20_init(ds18b20_def * dev,u8 pin);
/*-------------------------------------------------------
函数名：ds18b20_write
描  述：DS18B20的写函数，用于向DS18B20写入一个字节的数据。
输  入：dev  -  要操作的器件。
		dat  -  要发送的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-04
修改记录：
-------------------------------------------------------*/
extern void ds18b20_write(ds18b20_def * dev,u8 dat);
/*-------------------------------------------------------
函数名：ds18b20_read
描  述：DS18B20的读函数，用于向DS18B20读取一个字节的数据。
输  入：dev  -  要操作的器件。
输  出：无
返回值：读取到的数据。
创建者：奈特
调用例程：无
创建日期：2020-02-04
修改记录：
-------------------------------------------------------*/
extern u8 ds18b20_read(ds18b20_def * dev);
/*-------------------------------------------------------
函数名：ds18b20_check
描  述：DS18B20的检测函数，用于检测DS18B20是否存在，并复位。
输  入：dev  -  目标器件。
输  出：无
返回值：1代表器件存在、0代表器件不存在。
创建者：奈特
调用例程：无
创建日期：2020-02-04
修改记录：
-------------------------------------------------------*/
extern u8 ds18b20_check(ds18b20_def * dev);
/*-------------------------------------------------------
函数名：ds18b20_run
描  述：DS18B20的运行函数，运行之后可以获取温度值。
输  入：dev      -  目标器件。
输  出：dev.temp - 测量到的温度。
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-04
修改记录：
-------------------------------------------------------*/
extern u8 ds18b20_run(ds18b20_def * dev);
#endif

