#ifndef _ECBM_ADC_H_
#define _ECBM_ADC_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 ����

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
//<i>ADC��Ϊ�����⣬����û�����������⡣��˼���ֱ�ӵ���ʹ�ã��ֿ�����ʹ�á�
//<i>���Դ�ѡ��򹴣�ֻ����ζ��ADC���ʹ��ECBM���ͷ�ļ�����ѡ��򹴣����ʹ�û�����stc8ͷ�ļ���
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����adc.h����ͬһ���ļ��С�
#define ECBM_ADC_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ���ⲿ�жϣ�����Ϊ0��
//<h>ͨ��ʹ������
//<i>ADC��ת����ʱ����ҪIO�Ǹ���ģʽ������������ʹ��֮�󣬻���adc_init�����а���Ӧ��IO�����óɸ���ģʽ��
//<i>��ǰ�Ĵ���ֻ�����STC8A8Kϵ�С������ͺ�δ���룬�����������Ӧ�����ã�����ͨ��8~14��ӦIO��һ�µ����⣩��
//<q>ͨ��0(P1.0)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.7��ͻ���벻Ҫ��P1.7��Ϊ����̬��
#define ADC_CH0 0
//<q>ͨ��1(P1.1)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.0��ͻ���벻Ҫ��P0.0��Ϊ����̬��
#define ADC_CH1 0
//<q>ͨ��2(P1.2)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.1��ͻ���벻Ҫ��P0.1��Ϊ����̬��
#define ADC_CH2 0
//<q>ͨ��3(P1.3)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.2��ͻ���벻Ҫ��P0.2��Ϊ����̬��
#define ADC_CH3 0
//<q>ͨ��4(P1.4)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.3��ͻ���벻Ҫ��P0.3��Ϊ����̬��
#define ADC_CH4 0
//<q>ͨ��5(P1.5)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.4��ͻ���벻Ҫ��P0.4��Ϊ����̬��
#define ADC_CH5 0
//<q>ͨ��6(P1.6)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.5��ͻ���벻Ҫ��P0.5��Ϊ����̬��
#define ADC_CH6 0
//<q>ͨ��7(P1.7)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P0.6��ͻ���벻Ҫ��P0.6��Ϊ����̬��
#define ADC_CH7 1
//<q>ͨ��8(P0.0)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.0��ͻ���벻Ҫ��P1.0��Ϊ����̬��
#define ADC_CH8 0
//<q>ͨ��9(P0.1)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.1��ͻ���벻Ҫ��P1.1��Ϊ����̬��
#define ADC_CH9 0
//<q>ͨ��10(P0.2)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.2��ͻ���벻Ҫ��P1.2��Ϊ����̬��
#define ADC_CH10 0
//<q>ͨ��11(P0.3)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.3��ͻ���벻Ҫ��P1.3��Ϊ����̬��
#define ADC_CH11 0
//<q>ͨ��12(P0.4)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.4��ͻ���벻Ҫ��P1.4��Ϊ����̬��
#define ADC_CH12 0
//<q>ͨ��13(P0.5)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.5��ͻ���벻Ҫ��P1.5��Ϊ����̬��
#define ADC_CH13 0
//<q>ͨ��14(P0.6)
//<i>��ͨ����Ӧ��IOֻ������STC8A8Kϵ�С�
//<i>����STC8A8Kϵ����˵����ͨ�����P1.6��ͻ���벻Ҫ��P1.6��Ϊ����̬��
#define ADC_CH14 0
//<q>ͨ��15(Vref)
//<i>����STC8A8Kϵ����˵����ͨ�����P1.7��ͻ���벻Ҫ��P1.7��Ϊ����̬��
#define ADC_CH15 0
//</h>
//<h>ADC�ڲ�����
//<o.0..3>ADC�ķ�Ƶϵ��
//<i>���������ADC��ת���ٶȡ���������0~15����Ӧ1��Ƶ��16��Ƶ��
//<i>ADC�Ĳ�����=SYSCLK/2/16/��Ƶϵ����
//<o.5>ADC�Ķ��뷽ʽ
//<0=>����� <1=>�Ҷ���
//<i>�����Ϊ�������Ҷ������֣����������ʵ����˵�����ֶ������;��
//<i>����룺ADC_RES�������ĸ�8λ��ADC_RESL�������ĵ�2λ������10λADC��˵����
//<i>�����Ĳ���Ϊ[D9 D8 D7 6 D5 D4 D3 D2][D1 D0 0 0 0 0 0 0]��ȡֵ��ΧΪ0~65472������ֵΪ64��ֱ�Ӱ������Ĵ���ƴ��һ���16λ���ݵĻ���ʹ���ϻ���Щ���㡣
//<i>���ǿ��ǵ�ADC��ת��ʱ�����ڵ�Դ���ȵ�ԭ����������ݵ�λ�����������Ŀ����Ҫ����̫��ȴҪ�������ȶ��Ļ�����������Բ�������˲���ֱ��������2λ���ɡ�
//<i>�Ҷ��룺ADC_RES�������ĸ�2λ������10λADC��˵����ADC_RESL�������ĵ�8λ��
//<i>�Ҷ���Ĳ���Ϊ[0 0 0 0 0 0 D9 D8][D7 D6 D5 D4 D3 D2 D1 D0]��ȡֵ��ΧΪ0~1023������ֵΪ1��
//<i>�������һ�ȽϾ�֪���Ҷ���ģʽ�¿���ֱ�Ӱ������Ĵ������ƴ��һ����Ϊһ��16λ������ʹ�á�
#define ADC_SPEED 39
//<q>������λ����
//<i>��������Ľ��⣬���ȷʵ��Ҫ������λ���ݣ����Ƚ����뷽ʽѡΪ������ٹ�ѡ��ѡ�
//<i>ѡ���ѡ��󣬶�ȡ����������u16 adc_read(u8 pin)���Ϊu8 adc_read(u8 pin)����ֻ���ADC_RES��ֵ��
//<i>��������Ҷ��������¹�ѡ��ѡ���ô��ֻ�������2λ������10λADC��˵����
#define ADC_8BIT 0
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
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
