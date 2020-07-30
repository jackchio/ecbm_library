#ifndef _MAX6675_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _MAX6675_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>结构体优化
//<q>热电偶断路检测功能
//<i>开启本功能后，访问结构体的flag就能知道热电偶是否连接到MAX6675上。
//<i>连接时，flag=1；断开时，flag=0。
#define MAX6675_FLAG_EN 1 
//<o>温度数据类型
//<0=>u16型(原始数据) <1=>float型(温度值)
//<i>由于这个芯片测温度的分辨率也不算很高，只有0.25度。所以用float型的优点也不是太大。换成u16型可以节约一些空间（省2字节）。
//<i>MAX6675的测量范围是0~1023.75度,在选择u16型(原始数据)的时候对应0~4095。
#define MAX6675_TEMP_TYPE 1
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	#if MAX6675_TEMP_TYPE == 0 	//如果选择了原始数据，
	u16 temp;					//就定义成u16型。
	#else						//如果选择了温度值，
	float temp;					//就定义成float型。
	#endif
	u8 sck;						//时钟脚。
	u8 cs;						//片选脚。
	u8 so;						//数据脚。
	#if MAX6675_FLAG_EN			//如果使能了热电偶检测，
	u8 flag;					//就定义一个变量来存热电偶连接状态。
	#endif
}max6675_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：max6675_init
描  述：MAX6675的初始化函数。
输  入：dev  -  需要初始化的器件。
		sck  -  器件的时钟脚。
		cs   -  器件的片选脚。
		so   -  器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-02
修改记录：
-------------------------------------------------------*/
extern void max6675_init(max6675_def * dev,u8 sck,u8 cs,u8 so);
/*-------------------------------------------------------
函数名：max6675_run
描  述：MAX6675的运行函数，运行此函数能得到温度值。
输  入：dev      -  需要读取温度的器件。
输  出：dev.temp -  温度值。
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-02
修改记录：
-------------------------------------------------------*/
extern void max6675_run(max6675_def * dev);
#endif
