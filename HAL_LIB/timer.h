#ifndef _ECBM_TIMER_H_
#define _ECBM_TIMER_H_
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
//<i>GPIO��Ϊ�����⣬����û�����������⡣��˼���ֱ�ӵ���ʹ�ã��ֿ�����ʹ�á�
//<i>���Դ�ѡ��򹴣�ֻ����ζ��GPIO���ʹ��ECBM���ͷ�ļ�����ѡ��򹴣����ʹ�û�����stc8ͷ�ļ���
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����gpio.h����ͬһ���ļ��С�
#define ECBM_TIMER_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ���ⲿ�жϣ�����Ϊ0��
//<e>��ʱ��0ʹ��������
//<i>��ѡ��ѡ���ʹ�ܶ�ʱ��0�����źͶ�ʱ��0��صĲ�����������δʹ�ö�ʱ��0�����Թص��Ż��ռ䡣
#define ECBM_TIMER0_EN 1
//<o.4>��ʱ������
//<0=>������� <1=>��Ӳ�����ء�
//<i>��ѡ��������ء�ʱ������tim_start��������������ʱ��0��
//<i>��ѡ����Ӳ�����ء�ʱ����������tim_start�����⣬INT0��P32����ҪΪ�ߵ�ƽ��������ʱ��0��ͨ��������ͨ���ⲿӲ����������ʱ���������
//<o.5>������Դ
//<0=>��ϵͳʱ�Ӽ�������ʱ��Ӧ�ã�  <1=>���ⲿT0��P34���ŵ������źż�����������Ӧ�ã�
//<i>timer�ı��ʾ��Ǽ���������ϵͳʱ�Ӽ���ʱ������ʱ�ӵ�����T�̶�������ֵn���ԴӼĴ�����������ô����ͨ��t=nT���ʱ�䡣��������������ʱ����
//<i>�������ⲿ�����ź�Ҳ�й̶���������ڣ���ôҲ�������ⲿ�����ź�������ʱ��������һ���ⲿ�źŶ�������ģ�û�й̶����ڣ�����ֻ��֪������ֵn�����Ծͳ��˼�������
//<o.2..3>����ģʽ
//<i>16λ�Զ�����ģʽ���������Ĵ������ʱ���Զ������趨�õĳ�ֵ��
//<i>16λ���Զ�����ģʽ���������Ĵ������ʱ����0��ʼ��������������0��ʼ����Ҫ�ڶ�ʱ���ж������ʱ�������ֵ����
//<i>8λ�Զ�����ģʽ��ֻʹ��TL0��������TL0���ʱ���Զ���TH0��ֵ����TL0��
//<i>16λ�Զ����أ����������жϣ�ģʽ���������16λ�Զ�����ģʽһ�������ǻ����һ���������ε��жϡ�
//<0=>16λ�Զ�����ģʽ <1=>16λ���Զ�����ģʽ <2=>8λ�Զ�����ģʽ <3=>16λ�Զ����أ����������жϣ�ģʽ 
//<o.6>ʱ�ӷ�Ƶ
//<i>���൱��STC-ISP�������12Tģʽ��1Tģʽ��
//<0=>ϵͳʱ��12��Ƶ��Fosc/12�� <1=>ϵͳʱ�Ӳ���Ƶ
//<o.7>�������ʱ��
//<i>��ѡ��ѡ���ÿ�ζ�ʱ��0�������ʱ��T0CLKO��P35���ŵĵ�ƽ�Զ�������ת��
#define ECBM_TIMER0_MODE 0x40
//</e>
//<e>��ʱ��1ʹ��������
//<i>������������˶�ʱ��1�������ڵĲ����ʷ����������Ը����õ����ȼ�Ϊ������ʹ��>�����Զ�����ʹ��>��ʱ��1ʹ�ܡ�
//<i>��������ж��Ƿ�ʱ�����Ƿ��������⡣��������ˣ����ж��Զ�����ʹ�ܡ����û�����ӣ����ж϶�ʱ��1ʹ�ܡ�
#define ECBM_TIMER1_EN 0
//<o.4>��ʱ������
//<0=>������� <1=>��Ӳ�����ء�
//<i>��ѡ��������ء�ʱ������tim_start��������������ʱ��1��
//<i>��ѡ����Ӳ�����ء�ʱ����������tim_start�����⣬INT1��P33����ҪΪ�ߵ�ƽ��������ʱ��1��ͨ��������ͨ���ⲿӲ����������ʱ���������
//<o.5>������Դ
//<0=>��ϵͳʱ�Ӽ�������ʱ��Ӧ�ã�  <1=>���ⲿT1��P35���ŵ������źż�����������Ӧ�ã�
//<i>timer�ı��ʾ��Ǽ���������ϵͳʱ�Ӽ���ʱ������ʱ�ӵ�����T�̶�������ֵn���ԴӼĴ�����������ô����ͨ��t=nT���ʱ�䡣��������������ʱ����
//<i>�������ⲿ�����ź�Ҳ�й̶���������ڣ���ôҲ�������ⲿ�����ź�������ʱ��������һ���ⲿ�źŶ�������ģ�û�й̶����ڣ�����ֻ��֪������ֵn�����Ծͳ��˼�������
//<o.2..3>����ģʽ
//<i>16λ�Զ�����ģʽ���������Ĵ������ʱ���Զ������趨�õĳ�ֵ��
//<i>16λ���Զ�����ģʽ���������Ĵ������ʱ����0��ʼ��������������0��ʼ����Ҫ�ڶ�ʱ���ж������ʱ�������ֵ����
//<i>8λ�Զ�����ģʽ��ֻʹ��TL1��������TL1���ʱ���Զ���TH1��ֵ����TL1��
//<0=>16λ�Զ�����ģʽ <1=>16λ���Զ�����ģʽ <2=>8λ�Զ�����ģʽ 
//<o.6>ʱ�ӷ�Ƶ
//<i>���൱��STC-ISP�������12Tģʽ��1Tģʽ��
//<0=>ϵͳʱ��12��Ƶ��Fosc/12�� <1=>ϵͳʱ�Ӳ���Ƶ
//<o.7>�������ʱ��
//<i>��ѡ��ѡ���ÿ�ζ�ʱ��1�������ʱ��T1CLKO��P34���ŵĵ�ƽ�Զ�������ת��
#define ECBM_TIMER1_MODE 0x00
//</e>
//<e>��ʱ��2ʹ��������
//<i>��ѡ��ѡ���ʹ�ܶ�ʱ��2�����źͶ�ʱ��2��صĲ�����������δʹ�ö�ʱ��2�����Թص��Ż��ռ䡣
//<i>��ʱ��2�̶�Ϊ16λ�Զ�����ģʽ��
#define ECBM_TIMER2_EN 0
//<o.5>������Դ
//<0=>��ϵͳʱ�Ӽ�������ʱ��Ӧ�ã�  <1=>���ⲿT2��P12���ŵ������źż�����������Ӧ�ã�
//<i>timer�ı��ʾ��Ǽ���������ϵͳʱ�Ӽ���ʱ������ʱ�ӵ�����T�̶�������ֵn���ԴӼĴ�����������ô����ͨ��t=nT���ʱ�䡣��������������ʱ����
//<i>�������ⲿ�����ź�Ҳ�й̶���������ڣ���ôҲ�������ⲿ�����ź�������ʱ��������һ���ⲿ�źŶ�������ģ�û�й̶����ڣ�����ֻ��֪������ֵn�����Ծͳ��˼�������
//<o.6>ʱ�ӷ�Ƶ
//<i>���൱��STC-ISP�������12Tģʽ��1Tģʽ��
//<0=>ϵͳʱ��12��Ƶ��Fosc/12�� <1=>ϵͳʱ�Ӳ���Ƶ
//<o.7>�������ʱ��
//<i>��ѡ��ѡ���ÿ�ζ�ʱ��2�������ʱ��T2CLKO��P13���ŵĵ�ƽ�Զ�������ת��
#define ECBM_TIMER2_MODE 0x40
//</e>
//<e>��ʱ��3ʹ��������
//<i>��ѡ��ѡ���ʹ�ܶ�ʱ��3�����źͶ�ʱ��3��صĲ�����������δʹ�ö�ʱ��3�����Թص��Ż��ռ䡣
//<i>��ʱ��3�̶�Ϊ16λ�Զ�����ģʽ��
#define ECBM_TIMER3_EN 0
//<o.5>������Դ
//<0=>��ϵͳʱ�Ӽ�������ʱ��Ӧ�ã�  <1=>���ⲿT3��P04���ŵ������źż�����������Ӧ�ã�
//<i>timer�ı��ʾ��Ǽ���������ϵͳʱ�Ӽ���ʱ������ʱ�ӵ�����T�̶�������ֵn���ԴӼĴ�����������ô����ͨ��t=nT���ʱ�䡣��������������ʱ����
//<i>�������ⲿ�����ź�Ҳ�й̶���������ڣ���ôҲ�������ⲿ�����ź�������ʱ��������һ���ⲿ�źŶ�������ģ�û�й̶����ڣ�����ֻ��֪������ֵn�����Ծͳ��˼�������
//<o.6>ʱ�ӷ�Ƶ
//<i>���൱��STC-ISP�������12Tģʽ��1Tģʽ��
//<0=>ϵͳʱ��12��Ƶ��Fosc/12�� <1=>ϵͳʱ�Ӳ���Ƶ
//<o.7>�������ʱ��
//<i>��ѡ��ѡ���ÿ�ζ�ʱ��3�������ʱ��T3CLKO��P05���ŵĵ�ƽ�Զ�������ת��
#define ECBM_TIMER3_MODE 0x40
//</e>
//<e>��ʱ��4ʹ��������
//<i>��ѡ��ѡ���ʹ�ܶ�ʱ��4�����źͶ�ʱ��4��صĲ�����������δʹ�ö�ʱ��4�����Թص��Ż��ռ䡣
//<i>��ʱ��4�̶�Ϊ16λ�Զ�����ģʽ��
#define ECBM_TIMER4_EN 0
//<o.5>������Դ
//<0=>��ϵͳʱ�Ӽ�������ʱ��Ӧ�ã�  <1=>���ⲿT4��P06���ŵ������źż�����������Ӧ�ã�
//<i>timer�ı��ʾ��Ǽ���������ϵͳʱ�Ӽ���ʱ������ʱ�ӵ�����T�̶�������ֵn���ԴӼĴ�����������ô����ͨ��t=nT���ʱ�䡣��������������ʱ����
//<i>�������ⲿ�����ź�Ҳ�й̶���������ڣ���ôҲ�������ⲿ�����ź�������ʱ��������һ���ⲿ�źŶ�������ģ�û�й̶����ڣ�����ֻ��֪������ֵn�����Ծͳ��˼�������
//<o.6>ʱ�ӷ�Ƶ
//<i>���൱��STC-ISP�������12Tģʽ��1Tģʽ��
//<0=>ϵͳʱ��12��Ƶ��Fosc/12�� <1=>ϵͳʱ�Ӳ���Ƶ
//<o.7>�������ʱ��
//<i>��ѡ��ѡ���ÿ�ζ�ʱ��4�������ʱ��T4CLKO��P07���ŵĵ�ƽ�Զ�������ת��
#define ECBM_TIMER4_MODE 0x40
//</e>
//<e.15>���绽�Ѷ�ʱ��
//<i>���ڵ��绽�ѵĶ�ʱ����ͨ�����õ�32KHzʱ�������������ʼ���������Ƶ����õ���ֵʱ���ѵ�Ƭ����
//<o.0..14>��������
//<0-32767:1>
//<i>��ʽΪ����ʱʱ��=��16000000*����������+1����/Fwt����λΪ΢�룬����FwtΪʵ���ϵ�ʱ��Ƶ�ʣ���Ϊ�������ϴ���Ҫ��RAM����F8H��F9H��ȡ��ʵʱ��Ƶ�ʡ�
//<i>��Χ��0~32767��
//<i>�����㷨Ϊ����ʱʱ��=0.5ms*����������+1����
#define ECBM_WKT 32767
//</e>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_TIMER_LINK_EN
#include "ecbm.h"//ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
#else            //���Ҫ�����������У�ҲӦ���ṩSTC8��ͷ�ļ���ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ�
#include "stc.h" //��STC-ISP��������ʱ������ΪSTC.h��
#define u8 unsigned char
#endif
typedef union{
	struct{
	u8 id    :2;//0..1
	u8 mode  :2;//2..3
	u8 sw    :1;//4
	u8 source:1;//5
	u8 div   :1;//6
	u8 out   :1;//7
	}init;
	u8 buf;
}tim_def;
#if ECBM_TIMER0_EN
tim_def tim0;
#endif
#if ECBM_TIMER1_EN&&(SUART_EN==0)
tim_def tim1;
#endif
#if ECBM_TIMER2_EN
tim_def tim2;
#endif
#if ECBM_TIMER3_EN
tim_def tim3;
#endif
#if ECBM_TIMER4_EN
tim_def tim4;
#endif
#define tim0_start()    TF0=0;TR0=1
#define tim0_stop()     TR0=0
#define tim0_start_it() ET0=1;tim0_start() 
#define tim0_stop_it()  ET0=0;tim0_stop()
#define TIM0_FUN        interrupt 1
void (* tim0_it_fun) (void);
void tim0_itfun() TIM0_FUN
{
	tim0_it_fun();
}


#define tim1_start()    TF1=0;TR1=1
#define tim1_stop()     TR1=0
#define tim1_start_it() ET1=1;tim1_start()
#define tim1_stop_it()  ET1=0;tim1_stop()
#define TIM1_FUN        interrupt 3
void (* tim1_it_fun) (void);
void tim1_itfun() TIM1_FUN
{
	tim1_it_fun();
}


#define tim2_start()    AUXR|=0x10
#define tim2_stop()     AUXR&=0xEF
#define tim2_start_it() IE2|=0x04;tim2_start()
#define tim2_stop_it()  IE2&=0xFB;tim2_stop()
#define TIM2_FUN        interrupt 12
#define tim2_cls()      AUXINTIF &= ~T2IF //���жϱ�־
void (* tim2_it_fun) (void);
void tim2_itfun() TIM2_FUN
{
	tim2_cls();
	tim2_it_fun();
}

#define tim3_start()    T4T3M|=0x08
#define tim3_stop()     T4T3M&=0xF7
#define tim3_start_it() IE2|=0x20;tim3_start()
#define tim3_stop_it()  IE2&=0xDF;tim3_stop()
#define TIM3_FUN        interrupt 19
#define tim3_cls()      AUXINTIF &= ~T3IF //���жϱ�־
void (* tim3_it_fun) (void);
void tim3_itfun() TIM3_FUN
{
	tim3_cls();
	tim3_it_fun();
}

#define tim4_start()    T4T3M|=0x80
#define tim4_stop()     T4T3M&=0x7F
#define tim4_start_it() IE2|=0x40;tim4_start()
#define tim4_stop_it()  IE2&=0xBF;tim4_stop() 
#define TIM4_FUN        interrupt 20
#define tim4_cls()      AUXINTIF&=~T4IF //���жϱ�־
void (* tim4_it_fun) (void);
void tim4_itfun() TIM4_FUN
{
	tim4_cls();
	tim4_it_fun();
}
void tim_null(){
	
}

void tim_config(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//��ʱ��0�����÷�ʽ
			TMOD&=0xFC;
			TMOD|=tim->init.mode;
			if(tim->init.sw==1){
				TMOD|=0x08;
			}else{
				TMOD&=0xF7;
			}
			if(tim->init.source==1){
				TMOD|=0x04;
			}else{
				TMOD&=0xFB;
			}
			if(tim->init.div==1){
				AUXR|=0x80;
			}else{
				AUXR&=0x7F;
			}
			if(tim->init.out==1){
				INTCLKO|=0x01;
			}else{
				INTCLKO&=0xFE;
			}
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//��ʱ��1�����÷�ʽ
			TMOD&=0xCF;
			TMOD|=(tim->init.mode<<4);
			if(tim->init.sw==1){
				TMOD|=0x80;
			}else{
				TMOD&=0x7F;
			}
			if(tim->init.source==1){
				TMOD|=0x40;
			}else{
				TMOD&=0xBF;
			}
			if(tim->init.div==1){
				AUXR|=0x40;
			}else{
				AUXR&=0xBF;
			}
			if(tim->init.out==1){
				INTCLKO|=0x02;
			}else{
				INTCLKO&=0xFD;
			}			
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//��ʱ��2��4�����÷�ʽ
			if(tim->init.mode==1){//tim4
				if(tim->init.source==1){
					T4T3M|=0x40;
				}else{
					T4T3M&=0xBF;
				}
				if(tim->init.div==1){
					T4T3M|=0x20;
				}else{
					T4T3M&=0xDF;
				}
				if(tim->init.out==1){
					T4T3M|=0x10;
				}else{
					T4T3M&=0xEF;
				}
			}else{//tim2
				if(tim->init.source==1){
					AUXR|=0x08;
				}else{
					AUXR&=0xF7;
				}
				if(tim->init.div==1){
					AUXR|=0x04;
				}else{
					AUXR&=0xFB;
				}
				if(tim->init.out==1){
					INTCLKO|=0x04;
				}else{
					INTCLKO&=0xFB;
				}
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//��ʱ��3�����÷�ʽ
			if(tim->init.source==1){
				T4T3M|=0x04;
			}else{
				T4T3M&=0xFB;
			}
			if(tim->init.div==1){
				T4T3M|=0x02;
			}else{
				T4T3M&=0xFD;
			}
			if(tim->init.out==1){
				T4T3M|=0x01;
			}else{
				T4T3M&=0xFE;
			}			
		}break;
		#endif
	}
}
void tim_init(){
	#if ECBM_TIMER0_EN
	tim0.buf=ECBM_TIMER0_MODE;
	tim0.init.id=0;
	tim0_it_fun=tim_null;
	tim_config(&tim0);
	#endif
	#if ECBM_TIMER1_EN&&(SUART_EN==0)
	tim1.buf=ECBM_TIMER1_MODE;
	tim1.init.id=1;
	tim1_it_fun=tim_null;
	tim_config(&tim1);
	#endif
	#if ECBM_TIMER2_EN
	tim2.buf=ECBM_TIMER2_MODE;
	tim2.init.id=2;
	tim2.init.mode=0;
	tim2_it_fun=tim_null;
	tim_config(&tim2);
	#endif
	#if ECBM_TIMER3_EN
	tim3.buf=ECBM_TIMER3_MODE;
	tim3.init.id=3;
	tim3_it_fun=tim_null;
	tim_config(&tim3);
	#endif
	#if ECBM_TIMER4_EN
	tim4.buf=ECBM_TIMER4_MODE;
	tim4.init.id=2;
	tim4.init.mode=1;
	tim4_it_fun=tim_null;
	tim_config(&tim4);
	#endif
}

void tim_start(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//��ʱ��0�����÷�ʽ
			tim0_start();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//��ʱ��1�����÷�ʽ
			tim1_start();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//��ʱ��2��4�����÷�ʽ
			if(tim->init.mode==1){//tim4
				tim4_start();
			}else{//tim2
				tim2_start();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//��ʱ��3�����÷�ʽ
			tim3_start();
		}break;
		#endif
	}
}

void tim_stop(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//��ʱ��0�����÷�ʽ
			tim0_stop();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//��ʱ��1�����÷�ʽ
			tim1_stop();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//��ʱ��2��4�����÷�ʽ
			if(tim->init.mode==1){//tim4
				tim4_stop();
			}else{//tim2
				tim2_stop();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//��ʱ��3�����÷�ʽ
			tim3_stop() ;
		}break;
		#endif
	}
}
void tim_wait(){
	
}
void tim_start_it(tim_def * tim,void (*it_fun)(void)){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//��ʱ��0�����÷�ʽ
			tim0_it_fun=it_fun;
			tim0_start_it();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//��ʱ��1�����÷�ʽ
			tim1_it_fun=it_fun;
			tim1_start_it();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//��ʱ��2��4�����÷�ʽ
			if(tim->init.mode==1){//tim4
				tim4_it_fun=it_fun;
				tim4_start_it();
			}else{//tim2
				tim2_it_fun=it_fun;
				tim2_start_it();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//��ʱ��3�����÷�ʽ
			tim3_it_fun=it_fun;
			tim3_start_it();
		}break;
		#endif
	}
}
void tim_stop_it(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//��ʱ��0�����÷�ʽ
			tim0_stop_it();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//��ʱ��1�����÷�ʽ
			tim1_stop_it();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//��ʱ��2��4�����÷�ʽ
			if(tim->init.mode==1){//tim4
				tim4_stop_it();
			}else{//tim2
				tim2_stop_it();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//��ʱ��3�����÷�ʽ
			tim3_stop_it();
		}break;
		#endif
	}
}
#endif
