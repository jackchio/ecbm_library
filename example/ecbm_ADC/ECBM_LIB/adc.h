#ifndef _ECBM_ADC_H_
#define _ECBM_ADC_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 奈特

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
//<h>STC8A8K系列设置
//<i>ADC在转换的时候需要IO是高阻模式，在这里设置使能之后，会在adc_init函数中把相应的IO口设置成高阻模式。
//<i>当前的设置针对于STC8A8K系列。
//<q>通道0(P1.0)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.7冲突，请不要将P1.7设为高阻态。
#define ECBM_T1_ADC_CH0 1
//<q>通道1(P1.1)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.0冲突，请不要将P0.0设为高阻态。
#define ECBM_T1_ADC_CH1 0
//<q>通道2(P1.2)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.1冲突，请不要将P0.1设为高阻态。
#define ECBM_T1_ADC_CH2 0
//<q>通道3(P1.3)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.2冲突，请不要将P0.2设为高阻态。
#define ECBM_T1_ADC_CH3 0
//<q>通道4(P1.4)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.3冲突，请不要将P0.3设为高阻态。
#define ECBM_T1_ADC_CH4 0
//<q>通道5(P1.5)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.4冲突，请不要将P0.4设为高阻态。
#define ECBM_T1_ADC_CH5 0
//<q>通道6(P1.6)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.5冲突，请不要将P0.5设为高阻态。
#define ECBM_T1_ADC_CH6 0
//<q>通道7(P1.7)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.6冲突，请不要将P0.6设为高阻态。
#define ECBM_T1_ADC_CH7 0
//<q>通道8(P0.0)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.0冲突，请不要将P1.0设为高阻态。
#define ECBM_T1_ADC_CH8 0
//<q>通道9(P0.1)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.1冲突，请不要将P1.1设为高阻态。
#define ECBM_T1_ADC_CH9 0
//<q>通道10(P0.2)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.2冲突，请不要将P1.2设为高阻态。
#define ECBM_T1_ADC_CH10 0
//<q>通道11(P0.3)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.3冲突，请不要将P1.3设为高阻态。
#define ECBM_T1_ADC_CH11 0
//<q>通道12(P0.4)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.4冲突，请不要将P1.4设为高阻态。
#define ECBM_T1_ADC_CH12 0
//<q>通道13(P0.5)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.5冲突，请不要将P1.5设为高阻态。
#define ECBM_T1_ADC_CH13 0
//<q>通道14(P0.6)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.6冲突，请不要将P1.6设为高阻态。
#define ECBM_T1_ADC_CH14 0
//<q>通道15(Vref)
//<i>对于STC8A8K系列来说，该通道会和P1.7冲突，请不要将P1.7设为高阻态。
#define ECBM_T1_ADC_CH15 0
//</h>
//<h>STC8G2K系列设置

//</h>
//<h>STC8G1K08A-8PIN系列设置
//<i>ADC在转换的时候需要IO是高阻模式，在这里设置使能之后，会在adc_init函数中把相应的IO口设置成高阻模式。
//<i>当前的设置针对于STC8G1K08A-8PIN系列。
//<q>通道0(P3.0)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH0 0
//<q>通道1(P3.1)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH1 0
//<q>通道2(P3.2)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH2 0
//<q>通道3(P3.3)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH3 0
//<q>通道4(P5.4)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH4 0
//<q>通道5(P5.5)
//<i>该通道对应的IO只适用于STC8G1K08A-8PIN系列。
#define ECBM_T3_ADC_CH5 0
//<q>通道15(Vref)
#define ECBM_T3_ADC_CH15 1
//</h>
//<h>ADC参数设置
//<o.0..3>ADC的分频系数
//<5-15>
//<i>该项决定了ADC的转换速度。可以输入0~15，对应1分频到16分频。
//<i>但是实测输入6以下的效果很差。所以限制只能输入6以上的。
//<i>ADC的采样率=SYSCLK/2/16/分频系数。
//<o.5>ADC的对齐方式
//<0=>左对齐 <1=>右对齐
//<i>对齐分为左对齐和右对齐两种，下面从两个实例上说明两种对齐的用途。
//<i>左对齐：ADC_RES保存结果的高8位，ADC_RESL保存结果的低4位（对于12位ADC来说）。
//<i>左对齐的布局为[D11 D10 D9 D8 D7 D6 D5 D4][D3 D2 D1 D0 0 0 0 0]，取值范围为0~65520，步进值为16。直接把两个寄存器拼在一起成16位数据的话，使用上会有些不便。
//<i>但是考虑到ADC在转换时，由于电源不稳等原因会引起数据低位波动。如果项目精度要求不是太高却要求数据稳定的话，视情况可以不做软件滤波，直接舍弃低4位即可。
//<i>右对齐：ADC_RES保存结果的高4位（对于12位ADC来说），ADC_RESL保存结果的低8位。
//<i>右对齐的布局为[0 0 0 0 D11 D10 D9 D8][D7 D6 D5 D4 D3 D2 D1 D0]，取值范围为0~4095，步进值为1。
//<i>和左对齐一比较就知道右对齐模式下可以直接把两个寄存器结果拼在一起作为一个16位数据来使用。
#define ECBM_ADC_SPEED 37
//<q>舍弃低位数据
//<i>根据上面的讲解，如果确实需要舍弃低位数据，请勾选此选项，之后adc_read函数就只输出ADC_RES的值，ADC_RESL的值会被舍去。
#define ECBM_ADC_8BIT 0
//<q>ADC中断
#define ECBM_ADC_IT_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define ADC_FUN    interrupt 5                    //中断号，放置于中断函数之后。中断函数由用户自定义。
#define ADC_CLS_IT do{ADC_CONTR&=0xDF;adc_busy=0;}while(0)//清中断标志

/*--------------------------------------变量定义-----------------------------------*/
extern u8 xdata adc_busy;
extern float xdata adc_ch15;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：adc_init
描  述：ADC初始化函数。用于设置ADC工作配置，将相应的IO设置成高阻。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：adc_init();//初始化ADC
创建日期：2019-7-31
修改记录：
2019-8-5：增加了中断使能和中断优先级设置。
-------------------------------------------------------*/
extern void adc_init(void);
/*-------------------------------------------------------
函数名：adc_read
描  述：查询法读取AD值函数。用于把某通道对应的IO口电压值转换成AD值。
输  入：要读取的通道号，可输入0~15。
输  出：无
返回值：该通道的AD值。可返回8位数据或者12位数据，看具体设置。
创建者：奈特
调用例程：val=adc_read(0);//读取通道0的AD值。
创建日期：2019-7-31
修改记录：
2020-07-28：只保留一个函数
-------------------------------------------------------*/
extern u16 adc_read(u8 pin);
/*-------------------------------------------------------
函数名：adc_read_start
描  述：ADC转换开始函数（中断法）。用于开启对某通道对应的IO口电压的转换。该函数只开始一次转换，并不会马上得到结果。
输  入：要读取的通道号，可输入0~15。
输  出：无
返回值：无
创建者：奈特
调用例程：adc_read_start(0);//准备读取通道0的AD值。在中断函数中读取ADC转换结果。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_read_start(u8 pin);
/*-------------------------------------------------------
函数名：adc_read_it
描  述：中断法读取AD值函数。在ADC中断中调用本函数，可得到ADC转换的结果。转换的通道用adc_read_start函数设置。
输  入：无
输  出：无
返回值：该通道的AD值。
创建者：奈特
调用例程：//本函数是放在中断函数中的。
	void adc_it_fun() ADC_FUN	//ADC中断函数
	{
		ADC_CLS_IT;				//清除对应的中断标志位。
		val=adc_read_it();		//读取转换后的AD值。
	}
创建日期：2019-8-5
修改记录：
2020-07-28：只保留一个函数
-------------------------------------------------------*/
extern u16 adc_read_it();
/*-------------------------------------------------------
函数名：adc_voltage
描  述：读取电压函数。用于读取某通道对应的IO口电压值。
输  入：
       pin  - 要读取的通道号，可输入0~15。
       vref - adc的vref电压，最好实测得到。
输  出：无
返回值：该通道的电压值。
创建者：奈特
调用例程：val=adc_voltage(0,3.299);//读取通道0的电压值，vref是3.299V。
创建日期：2019-7-31
修改记录：
-------------------------------------------------------*/
extern float adc_voltage(u8 pin,float vref);
/*-------------------------------------------------------
函数名：adc_it_start
描  述：开启ADC中断函数。用于打开ADC的中断。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：adc_it_start();//开启ADC的中断。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_it_start();
/*-------------------------------------------------------
函数名：adc_it_stop
描  述：关闭ADC中断函数。用于关闭ADC的中断。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：adc_it_stop();//关闭ADC的中断。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_it_stop();
/*-------------------------------------------------------
函数名：adc_read_vref
描  述：ADC读取Vref函数。
输  入：无
输  出：无
返回值：Vref的电压值，单位V。
创建者：奈特
调用例程：无
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern float adc_read_vref(void);
#endif
