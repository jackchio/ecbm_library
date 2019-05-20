#ifndef _ECBM_HX7XX_H_
#define _ECBM_HX7XX_H_
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
版本出现BUG时，请联系作者解决。联系方式：进群778916610
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM主库连接使能
//<i>此选项打勾，意味着HX7XX库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。并且支持多器件下的代码复用。
//<i>此选项不打勾，意味着HX7XX库能单独使用，不会再依赖其他ECBM库函数。需要移植基本的构造函数。但此时若再加载ECBM库会有重定义报错的可能，请注意。
#define ECBM_HX7XX_LINK_EN 1 //和ECBM库连接的使能，如果想脱离主库单独使用HX7XX外设，请设为0。
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
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#define HX710A_CHA      0
#define HX710A_TEMP     1
#define HX710A_CHA_40HZ 2

#define HX710B_CHA      0
#define HX710B_VDD      1
#define HX710B_CHA_40HZ 2

#define HX710C_CHA      0

#define HX711_CHA       0
#define HX711_CHB       1
#define HX711_CHA_64    2

#define HX720_CHA       0

#if ECBM_HX7XX_LINK_EN
#include "ecbm.h"
typedef struct{
	u8 sck_port;
	u8 sck_pin;
	u8 sda_port;
	u8 sda_pin;
	s32 dat;
}hx7xx_def;

void hx7xx_init(hx7xx_def * dev,u8 sck,u8 sda){
	dev->sck_port=sck>>4;
	dev->sck_pin=0x01<<(sck&0x0f);
	dev->sda_port=sda>>4;
	dev->sda_pin=0x01<<(sda&0x0f);
	dev->dat=0;
	gpio_mode(sda,GPIO_IN);
	gpio_mode(sck,GPIO_IN);
	gpio_out(sda,1);
	gpio_out(sck,1);
}
void hx7xx_run(hx7xx_def * dev,u8 next){
	signed long Count;
	unsigned char i;
	unsigned int time=5000;
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);//使能AD（PD_SCK 置低）
	Count=0;
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	while((gpio_in_fast(dev->sda_port,dev->sda_pin))&&(time--))delay_ms(1);//AD转换未结束则等待，否则开始读取
	for (i=0;i<24;i++){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1); //PD_SCK 置高（发送脉冲）
		delay_us(_10us);
		Count=Count<<1; //下降沿来时变量Count左移一位，右侧补零
		gpio_out_fast(dev->sck_port,dev->sck_pin,0); //PD_SCK 置低
		delay_us(_10us);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)) Count++;
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第25个脉冲下降沿来时，转换数据
	delay_us(_10us);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	if(next>0){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第26个脉冲下降沿来时，转换数据
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(next==2){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第27个脉冲下降沿来时，转换数据
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(time==0)
		dev->dat=0;
	else{
		if(Count&(0x800000))Count|=0xFF000000;
		dev->dat=Count;
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);
}
#else
#include "stc.h"
#include "intrins.h"
sbit hx7xx_sck=P3^3;
sbit hx7xx_sda=P3^4;
void hx7xx_init(){
	hx7xx_sck=1;
	hx7xx_sda=1;
}
void Delay1ms()		//@24.000MHz
{
	unsigned char i, j;

	_nop_();
	i = 32;
	j = 40;
	do
	{
		while (--j);
	} while (--i);
}
void Delay10us()		//@24.000MHz
{
	unsigned char i;

	i = 78;
	while (--i);
}
signed long hx7xx_run(unsigned char next){
	signed long Count;
	unsigned char i;
	unsigned int time=5000;
	hx7xx_sck=0;//使能AD（PD_SCK 置低）
	Count=0;
	hx7xx_sda=1;
	while((hx7xx_sda)&&(time--))Delay1ms();//AD转换未结束则等待，否则开始读取
	for (i=0;i<24;i++){
		hx7xx_sck=1; //PD_SCK 置高（发送脉冲）
		Delay10us();
		Count=Count<<1; //下降沿来时变量Count左移一位，右侧补零
		hx7xx_sck=0; //PD_SCK 置低
		Delay10us();
		if(hx7xx_sda) Count++;
	}
	hx7xx_sck=1;//第25个脉冲下降沿来时，转换数据
	Delay10us();
	hx7xx_sck=0;
	if(next>0){
		hx7xx_sck=1;//第26个脉冲下降沿来时，转换数据
		Delay10us();
		hx7xx_sck=0;
	}
	if(next==2){
		hx7xx_sck=1;//第27个脉冲下降沿来时，转换数据
		Delay10us();
		hx7xx_sck=0;
	}
	hx7xx_sck=1;
	if(time==0)
		return 0;
	else{
		if(Count&(0x800000))Count|=0xFF000000;
		return Count;
	}
}
#endif
#endif
