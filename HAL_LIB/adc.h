#ifndef _ECBM_ADC_H_
#define _ECBM_ADC_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 奈特

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
版本出现BUG时，请联系作者解决。联系方式：进群778916610
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM主库连接使能
//<i>ADC库为基础库，几乎没有依赖其他库。因此即可直接单独使用，又可联合使用。
//<i>所以此选项打勾，只是意味着ADC库会使用ECBM库的头文件。此选项不打勾，则会使用基本的stc8头文件。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和adc.h置于同一个文件夹。
#define ECBM_ADC_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用外部中断，请设为0。
//<h>通道使能设置
//<i>ADC在转换的时候需要IO是高阻模式，在这里设置使能之后，会在adc_init函数中把相应的IO口设置成高阻模式。
//<i>当前的代码只针对于STC8A8K系列。其他型号未加入，请酌情调整相应的设置（比如通道8~14对应IO不一致的问题）。
//<q>通道0(P1.0)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.7冲突，请不要将P1.7设为高阻态。
#define ADC_CH0 0
//<q>通道1(P1.1)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.0冲突，请不要将P0.0设为高阻态。
#define ADC_CH1 0
//<q>通道2(P1.2)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.1冲突，请不要将P0.1设为高阻态。
#define ADC_CH2 0
//<q>通道3(P1.3)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.2冲突，请不要将P0.2设为高阻态。
#define ADC_CH3 0
//<q>通道4(P1.4)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.3冲突，请不要将P0.3设为高阻态。
#define ADC_CH4 0
//<q>通道5(P1.5)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.4冲突，请不要将P0.4设为高阻态。
#define ADC_CH5 0
//<q>通道6(P1.6)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.5冲突，请不要将P0.5设为高阻态。
#define ADC_CH6 0
//<q>通道7(P1.7)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P0.6冲突，请不要将P0.6设为高阻态。
#define ADC_CH7 1
//<q>通道8(P0.0)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.0冲突，请不要将P1.0设为高阻态。
#define ADC_CH8 0
//<q>通道9(P0.1)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.1冲突，请不要将P1.1设为高阻态。
#define ADC_CH9 0
//<q>通道10(P0.2)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.2冲突，请不要将P1.2设为高阻态。
#define ADC_CH10 0
//<q>通道11(P0.3)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.3冲突，请不要将P1.3设为高阻态。
#define ADC_CH11 0
//<q>通道12(P0.4)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.4冲突，请不要将P1.4设为高阻态。
#define ADC_CH12 0
//<q>通道13(P0.5)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.5冲突，请不要将P1.5设为高阻态。
#define ADC_CH13 0
//<q>通道14(P0.6)
//<i>该通道对应的IO只适用于STC8A8K系列。
//<i>对于STC8A8K系列来说，该通道会和P1.6冲突，请不要将P1.6设为高阻态。
#define ADC_CH14 0
//<q>通道15(Vref)
//<i>对于STC8A8K系列来说，该通道会和P1.7冲突，请不要将P1.7设为高阻态。
#define ADC_CH15 0
//</h>
//<h>ADC内部设置
//<o.0..3>ADC的分频系数
//<i>该项决定了ADC的转换速度。可以输入0~15，对应1分频到16分频。
//<i>ADC的采样率=SYSCLK/2/16/分频系数。
//<o.5>ADC的对齐方式
//<0=>左对齐 <1=>右对齐
//<i>对齐分为左对齐和右对齐两种，下面从两个实例上说明两种对齐的用途。
//<i>左对齐：ADC_RES保存结果的高8位，ADC_RESL保存结果的低2位（对于10位ADC来说）。
//<i>左对齐的布局为[D9 D8 D7 6 D5 D4 D3 D2][D1 D0 0 0 0 0 0 0]，取值范围为0~65472，步进值为64。直接把两个寄存器拼在一起成16位数据的话，使用上会有些不便。
//<i>但是考虑到ADC在转换时，由于电源不稳等原因会引起数据低位波动。如果项目精度要求不是太高却要求数据稳定的话，视情况可以不做软件滤波，直接舍弃低2位即可。
//<i>右对齐：ADC_RES保存结果的高2位（对于10位ADC来说），ADC_RESL保存结果的低8位。
//<i>右对齐的布局为[0 0 0 0 0 0 D9 D8][D7 D6 D5 D4 D3 D2 D1 D0]，取值范围为0~1023，步进值为1。
//<i>和左对齐一比较就知道右对齐模式下可以直接把两个寄存器结果拼在一起作为一个16位数据来使用。
#define ADC_SPEED 39
//<q>舍弃低位数据
//<i>根据上面的讲解，如果确实需要舍弃低位数据，请先将对齐方式选为左对齐再勾选此选项。
//<i>选择此选项后，读取函数定义由u16 adc_read(u8 pin)变更为u8 adc_read(u8 pin)。且只输出ADC_RES的值。
//<i>如果是在右对齐的情况下勾选此选项，那么就只能输出高2位（对于10位ADC来说）。
#define ADC_8BIT 0
//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#include "ecbm.h"
void adc_init(){
	ADCCFG=ADC_SPEED;
#if ADC_CH0
	gpio_mode(A00,GPIO_HZ);
#endif
#if ADC_CH1
	gpio_mode(A01,GPIO_HZ);
#endif
#if ADC_CH2
	gpio_mode(A02,GPIO_HZ);
#endif
#if ADC_CH3
	gpio_mode(A03,GPIO_HZ);
#endif
#if ADC_CH4
	gpio_mode(A04,GPIO_HZ);
#endif
#if ADC_CH5
	gpio_mode(A05,GPIO_HZ);
#endif
#if ADC_CH6
	gpio_mode(A06,GPIO_HZ);
#endif
#if ADC_CH7
	gpio_mode(A07,GPIO_HZ);
#endif
#if ADC_CH8
	gpio_mode(A08,GPIO_HZ);
#endif
#if ADC_CH9
	gpio_mode(A09,GPIO_HZ);
#endif
#if ADC_CH10
	gpio_mode(A10,GPIO_HZ);
#endif
#if ADC_CH11
	gpio_mode(A11,GPIO_HZ);
#endif
#if ADC_CH12
	gpio_mode(A12,GPIO_HZ);
#endif
#if ADC_CH13
	gpio_mode(A13,GPIO_HZ);
#endif
#if ADC_CH14
	gpio_mode(A14,GPIO_HZ);
#endif
}
#if ADC_8BIT
unsigned char adc_read(unsigned char pin){
	ADC_CONTR=0x80|0x40|pin;
	_nop_();
	_nop_();
	while((ADC_CONTR&0x20)==0);
	ADC_CONTR&=~0x20;
	return ADC_RES;
}
#else 
unsigned int adc_read(unsigned char pin){
	ADC_CONTR=0x80|0x40|pin;
	_nop_();
	_nop_();
	while((ADC_CONTR&0x20)==0);
	ADC_CONTR&=~0x20;
	return (ADC_RES<<8|ADC_RESL);
}
#endif
float adc_voltage(unsigned char pin,float vref){
	u16 jg;
	jg=(u16)adc_read(pin);
	#if ADC_8BIT
	return (float)jg*vref/255.0f;
	#else
	return (float)jg*vref/4095.0f;
	#endif
}
#endif
