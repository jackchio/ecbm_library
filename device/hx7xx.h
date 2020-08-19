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
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>器件支持
//<q>HX710A
//<i>该芯片的通道A能以128倍的增益测量差分信号，通道B能测量片内温度。
#define HX7XX_HX710A_EN 1
//<q>HX710B
//<i>该芯片的通道A能以128倍的增益测量差分信号，通道B能测量DVDD-AVDD的电压差。
#define HX7XX_HX710B_EN 1
//<q>HX710C
//<i>该芯片的通道A能以128倍的增益测量差分信号，具有传感器电源开关。
#define HX7XX_HX710C_EN 1
//<q>HX711
//<i>该芯片的通道A能以128倍或64倍的增益测量差分信号，通道B能以32倍的增益测量差分信号。
#define HX7XX_HX711_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define HX710A_CHA      0//下次测量测量A通道，适用于HX710A
#define HX710A_TEMP     1//下次测量测量温度通道，适用于HX710A
#define HX710A_CHA_40HZ 2//下次测量测量A通道，测量频率切换成40Hz，适用于HX710A

#define HX710B_CHA      0//下次测量测量A通道，适用于HX710B
#define HX710B_VDD      1//下次测量测量VDD，适用于HX710B
#define HX710B_CHA_40HZ 2//下次测量测量A通道，测量频率切换成40Hz，适用于HX710B

#define HX710C_CHA      0//下次测量测量A通道，适用于HX710C

#define HX711_CHA       0//下次测量测量A通道，适用于HX711
#define HX711_CHB       1//下次测量测量B通道，适用于HX711
#define HX711_CHA_64    2//下次测量测量A通道，放大倍数改为64，适用于HX711

#define HX720_CHA       0//下次测量测量A通道，适用于HX720
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 sck_port;//时钟脚。
	u8 sck_pin;
	u8 sda_port;//数据脚。
	u8 sda_pin;
	s32 dat;	//测量得到数据。
}hx7xx_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：hx7xx_init
描  述：hx7xx系列的初始化函数。
输  入：dev   -  需要初始化的器件。
		sck   -  器件的时钟脚。
		sda   -  器件的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
void hx7xx_init(hx7xx_def * dev,u8 sck,u8 sda);
/*-------------------------------------------------------
函数名：hx7xx_run
描  述：hx7xx系列的运行函数，用于的到ADC的测量值。
输  入：dev  -  要操作的器件。
		next - 下次测量的通道/功能。
输  出：dev.dat - 测量的结果。
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
void hx7xx_run(hx7xx_def * dev,u8 next);
#endif
