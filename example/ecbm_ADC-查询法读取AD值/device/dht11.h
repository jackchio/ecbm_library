#ifndef _XXXX_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _XXXX_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
	u8 port;        //DHT11硬件连接的P口
	u8 pin;         //P口上的编号
	u8 temp;		//DHT11测出来的温度值
	u8 humi;		//DHT11测出来的湿度值
}dht11_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：dht11_init
描  述：DHT11的初始化函数。
输  入：dev  -  需要初始化的器件。
		pin  -  该器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern void dht11_init(dht11_def * dev,u8 pin);
/*-------------------------------------------------------
函数名：dht11_run
描  述：DHT11的运行函数，运行就能得到温湿度值。
输  入：dev  -  需要测量的器件。
输  出：dev.temp - 测量得到的温度值。
		dev.humi - 测量得到的湿度值。
返回值：通信状态。0-正常。1-总线错误。2-访问超时
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern u8 dht11_run(dht11_def * dev);
#endif
