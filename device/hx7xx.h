#ifndef _ECBM_HX7XX_H_
#define _ECBM_HX7XX_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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

����˵����
	���������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ�������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽������ϵ��ʽ����Ⱥ778916610
------------------------------------------------------------------------------------*/
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM��������ʹ��
//<i>��ѡ��򹴣���ζ��HX7XX���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣����֧�ֶ������µĴ��븴�á�
//<i>��ѡ��򹴣���ζ��HX7XX���ܵ���ʹ�ã���������������ECBM�⺯������Ҫ��ֲ�����Ĺ��캯��������ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
#define ECBM_HX7XX_LINK_EN 1 //��ECBM�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��HX7XX���裬����Ϊ0��
//<h>����֧��
//<q>HX710A
//<i>��оƬ��ͨ��A����128���������������źţ�ͨ��B�ܲ���Ƭ���¶ȡ�
#define HX7XX_HX710A_EN 1
//<q>HX710B
//<i>��оƬ��ͨ��A����128���������������źţ�ͨ��B�ܲ���DVDD-AVDD�ĵ�ѹ�
#define HX7XX_HX710B_EN 1
//<q>HX710C
//<i>��оƬ��ͨ��A����128���������������źţ����д�������Դ���ء�
#define HX7XX_HX710C_EN 1
//<q>HX711
//<i>��оƬ��ͨ��A����128����64���������������źţ�ͨ��B����32���������������źš�
#define HX7XX_HX711_EN 1
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
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
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);//ʹ��AD��PD_SCK �õͣ�
	Count=0;
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	while((gpio_in_fast(dev->sda_port,dev->sda_pin))&&(time--))delay_ms(1);//ADת��δ������ȴ�������ʼ��ȡ
	for (i=0;i<24;i++){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1); //PD_SCK �øߣ��������壩
		delay_us(_10us);
		Count=Count<<1; //�½�����ʱ����Count����һλ���Ҳಹ��
		gpio_out_fast(dev->sck_port,dev->sck_pin,0); //PD_SCK �õ�
		delay_us(_10us);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)) Count++;
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��25�������½�����ʱ��ת������
	delay_us(_10us);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	if(next>0){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��26�������½�����ʱ��ת������
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(next==2){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��27�������½�����ʱ��ת������
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
	hx7xx_sck=0;//ʹ��AD��PD_SCK �õͣ�
	Count=0;
	hx7xx_sda=1;
	while((hx7xx_sda)&&(time--))Delay1ms();//ADת��δ������ȴ�������ʼ��ȡ
	for (i=0;i<24;i++){
		hx7xx_sck=1; //PD_SCK �øߣ��������壩
		Delay10us();
		Count=Count<<1; //�½�����ʱ����Count����һλ���Ҳಹ��
		hx7xx_sck=0; //PD_SCK �õ�
		Delay10us();
		if(hx7xx_sda) Count++;
	}
	hx7xx_sck=1;//��25�������½�����ʱ��ת������
	Delay10us();
	hx7xx_sck=0;
	if(next>0){
		hx7xx_sck=1;//��26�������½�����ʱ��ת������
		Delay10us();
		hx7xx_sck=0;
	}
	if(next==2){
		hx7xx_sck=1;//��27�������½�����ʱ��ת������
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
