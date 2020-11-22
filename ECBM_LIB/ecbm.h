#ifndef __ECBM_H_
#define __ECBM_H_
/*----------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 ����

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
�汾����BUGʱ������ϵ���߽����
                             **************************
                             * ��ϵ��ʽ����Ⱥ778916610 *
							 ************************** 
---------------------------------------------------------------------------------*/
//V2.2�汾
//������STC8F��STC8A��STC8G��STC8H�ļĴ�����
//������ͷ�ļ���,���������ٰ���"REG51.H"
/*--------------------------�ں����⹦�ܼĴ���--------------------------*/
sfr		ACC			=0xE0;  //�ۼ���
sfr		B			=0xF0;  //B�Ĵ���
sfr		PSW			=0xD0;  //����״̬�ּĴ���
sbit	CY			=PSW^7; //��λ��־λ
sbit	AC			=PSW^6; //������λ��־λ
sbit	F0			=PSW^5; //�����û��ı�־λ
sbit	RS1			=PSW^4; //�����Ĵ���ѡ��λ����λ��
sbit	RS0			=PSW^3; //�����Ĵ���ѡ��λ����λ��
sbit	OV			=PSW^2; //�����־λ
sbit	P			=PSW^0; //��żУ��λ
sfr		SP			=0x81;  //��ջָ��
sfr		DPL			=0x82;  //����ָ�루���ֽڣ�
sfr		DPH			=0x83;  //����ָ�루���ֽڣ�
sfr		TA			=0xAE;  //DPTRʱ����ƼĴ���
sfr		DPS			=0xE3;  //DPTRָ��ѡ����
sfr		DPL1		=0xE4;  //�ڶ�������ָ�루���ֽڣ�
sfr		DPH1		=0xE5;  //�ڶ�������ָ�루���ֽڣ�
#define IF_ODD(_OE_) ACC=_OE_;if(P)//�ж��ǲ�������   
/*-------------------------�ж����⹦�ܼĴ���----------------------------*/
sfr		IE			=0xa8;  //�ж�����Ĵ���
sbit	EA			=IE^7;  //���ж��������λ
sbit	ELVD		=IE^6;  //��ѹ����ж�����λ
sbit	EADC		=IE^5;  //A/Dת���ж�����λ
sbit	ES			=IE^4;  //����1�ж�����λ
sbit	ET1			=IE^3;  //��ʱ��1�ж�����λ
sbit	EX1			=IE^2;  //�ⲿ�ж�1����λ
sbit	ET0			=IE^1;  //��ʱ��0�ж�����λ
sbit	EX0			=IE^0;  //�ⲿ�ж�0����λ
#define	EA_ENABLE	do{EA=1;}while(0)//�����жϿ���
#define	EA_DISABLE	do{EA=0;}while(0)//�ر����жϿ���
sfr     IE2     =   0xaf;	//�ж�����Ĵ���2
#define ETKSUI      0x80	//���������ж�����λ
#define EUSB	    0x80	//USB�ж�����λ
#define ET4         0x40	//��ʱ��4�ж�����λ
#define ET3         0x20	//��ʱ��3�ж�����λ
#define ES4         0x10	//����4�ж�����λ
#define ES3         0x08	//����3�ж�����λ
#define ET2         0x04	//��ʱ��2�ж�����λ
#define ESPI        0x02	//SPI�ж�����λ
#define ES2         0x01	//����2�ж�����λ
sfr     INTCLKO =   0x8f;	//�ⲿ�ж���ʱ��������ƼĴ���
#define EX4         0x40	//�ⲿ�ж�4�ж�����λ
#define EX3         0x20	//�ⲿ�ж�3�ж�����λ
#define EX2         0x10	//�ⲿ�ж�2�ж�����λ
#define T2CLKO      0x04	//��ʱ��2ʱ���������
#define T1CLKO      0x02	//��ʱ��1ʱ���������
#define T0CLKO      0x01	//��ʱ��0ʱ���������
sfr     AUXINTIF=   0xef;	//��չ�жϱ�־λ�Ĵ���
#define INT4IF      0x40	//�ⲿ�ж�4���жϱ�־λ
#define INT3IF      0x20	//�ⲿ�ж�3���жϱ�־λ
#define INT2IF      0x10	//�ⲿ�ж�2���жϱ�־λ
#define T4IF        0x04	//��ʱ��4���жϱ�־λ
#define T3IF        0x02	//��ʱ��3���жϱ�־λ
#define T2IF        0x01	//��ʱ��2���жϱ�־λ
/*##############################�ⲿ�ж�0###############################*/
//-------------����ָ��------------//
#define	EXTI0_ENABLE				do{EX0=1;}while(0)//���ⲿ�ж�0
#define	EXTI0_DISABLE				do{EX0=0;}while(0)//�ر��ⲿ�ж�0

#define	EXTI0_SET_MODE_UP_DOWM		do{IT0=0;}while(0)//�ⲿ�ж�0ͨ�������غ��½��ش���
#define	EXTI0_SET_MODE_DOWM			do{IT0=1;}while(0)//�ⲿ�ж�0ͨ���½��ش���

#define EXTI0_SET_IO_HIGH			do{P32=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI0_GET_IO				(P32)             //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
//-------------���ܶ���------------//
#define	EXTI0_IT_NUM				interrupt 0//�ⲿ�ж�0�жϺ�
/*##############################�ⲿ�ж�1###############################*/
//-------------����ָ��------------//
#define	EXTI1_ENABLE				do{EX1=1;}while(0)//���ⲿ�ж�1
#define	EXTI1_DISABLE				do{EX1=0;}while(0)//�ر��ⲿ�ж�1

#define	EXTI1_SET_MODE_UP_DOWM		do{IT1=0;}while(0)//�ⲿ�ж�1ͨ�������غ��½��ش���
#define	EXTI1_SET_MODE_DOWM			do{IT1=1;}while(0)//�ⲿ�ж�1ͨ���½��ش���

#define EXTI1_SET_IO_HIGH			do{P33=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define	EXTI1_GET_IO				(P33)             //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
//-------------���ܶ���------------//
#define	EXTI1_IT_NUM				interrupt 2//�ⲿ�ж�1�жϺ�
/*##############################�ⲿ�ж�2###############################*/
//-------------����ָ��------------//
#define	EXTI2_ENABLE				do{INTCLKO|= EX2;}while(0)//���ⲿ�ж�2
#define	EXTI2_DISABLE				do{INTCLKO&=~EX2;}while(0)//�ر��ⲿ�ж�2

#define EXTI2_SET_IO_HIGH			do{P36=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define	EXTI2_GET_IO				(P36) 

#define EXTI2_IT_CLS				do{AUXINTIF&=~INT2IF;}while(0)//����ⲿ�ж�2���жϱ�־λ
//-------------���ܶ���------------//
#define	EXTI2_IT_NUM				interrupt 10//�ⲿ�ж�2�жϺ�
/*##############################�ⲿ�ж�3###############################*/
//-------------����ָ��------------//
#define	EXTI3_ENABLE				do{INTCLKO|= EX3;}while(0)//���ⲿ�ж�3
#define	EXTI3_DISABLE				do{INTCLKO&=~EX3;}while(0)//�ر��ⲿ�ж�3

#define EXTI3_SET_IO_HIGH			do{P37=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define	EXTI3_GET_IO				(P37) 

#define	EXTI3_IT_CLS				do{AUXINTIF&=~INT3IF;}while(0)//����ⲿ�ж�3���жϱ�־λ
//-------------���ܶ���------------//
#define EXTI3_IT_NUM				interrupt 11//�ⲿ�ж�3�жϺ�
/*##############################�ⲿ�ж�3###############################*/
//-------------����ָ��------------//
#define	EXTI4_ENABLE				do{INTCLKO|= EX4;}while(0)//���ⲿ�ж�4
#define	EXTI4_DISABLE				do{INTCLKO&=~EX4;}while(0)//�ر��ⲿ�ж�4

#define EXTI4_SET_IO_HIGH			do{P30=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI4_GET_IO				P30 

#define EXTI4_IT_CLS				do{AUXINTIF&=~INT4IF;}while(0)//����ⲿ�ж�4���жϱ�־λ
//-------------���ܶ���------------//
#define EXTI4_IT_NUM				interrupt 16//�ⲿ�ж�4�жϺ�
/*-------------------------I/O�����⹦�ܼĴ���--------------------------*/
sfr		P0			=0x80;  //P0�˿�
sbit	P00			=P0^0;  //P0.0��
sbit	P01			=P0^1;  //P0.1��
sbit	P02			=P0^2;  //P0.2��
sbit	P03			=P0^3;  //P0.3��
sbit	P04			=P0^4;  //P0.4��
sbit	P05			=P0^5;  //P0.5��
sbit	P06			=P0^6;  //P0.6��
sbit	P07			=P0^7;  //P0.7��
sfr		P0M0		=0x94;  //P0�����üĴ���0
sfr		P0M1		=0x93;  //P0�����üĴ���1
#define	P0PU		(*(unsigned char volatile xdata *)0xFE10)//P0������������ƼĴ���
#define	P0NCS		(*(unsigned char volatile xdata *)0xFE18)//P0��ʩ���ش������ƼĴ���
#define	P0SR		(*(unsigned char volatile xdata *)0xFE20)//P0�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P0DR        (*(unsigned char volatile xdata *)0xFE28)//P0�������������ƼĴ���
#define	P0IE        (*(unsigned char volatile xdata *)0xFE30)//P0�������ź�����ʹ�ܿ��ƼĴ���

sfr		P1			=0x90;  //P1�˿�
sbit	P10			=P1^0;  //P1.0��
sbit	P11			=P1^1;  //P1.1��
sbit	P12			=P1^2;  //P1.2��
sbit	P13			=P1^3;  //P1.3��
sbit	P14			=P1^4;  //P1.4��
sbit	P15			=P1^5;  //P1.5��
sbit	P16			=P1^6;  //P1.6��
sbit	P17			=P1^7;  //P1.7��
sfr		P1M0		=0x92;  //P1�����üĴ���0
sfr		P1M1		=0x91;  //P1�����üĴ���1
#define	P1PU		(*(unsigned char volatile xdata *)0xFE11)//P1������������ƼĴ���
#define	P1NCS		(*(unsigned char volatile xdata *)0xFE19)//P1��ʩ���ش������ƼĴ���
#define	P1SR		(*(unsigned char volatile xdata *)0xFE21)//P1�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P1DR        (*(unsigned char volatile xdata *)0xFE29)//P1�������������ƼĴ���
#define	P1IE        (*(unsigned char volatile xdata *)0xFE31)//P1�������ź�����ʹ�ܿ��ƼĴ���

sfr		P2			=0xa0;  //P2�˿�
sbit	P20			=P2^0;  //P2.0��
sbit	P21			=P2^1;  //P2.1��
sbit	P22			=P2^2;  //P2.2��
sbit	P23			=P2^3;  //P2.3��
sbit	P24			=P2^4;  //P2.4��
sbit	P25			=P2^5;  //P2.5��
sbit	P26			=P2^6;  //P2.6��
sbit	P27			=P2^7;  //P2.7��
sfr		P2M0		=0x96;  //P2�����üĴ���0
sfr		P2M1		=0x95;  //P2�����üĴ���1
#define	P2PU		(*(unsigned char volatile xdata *)0xFE12)//P2������������ƼĴ���
#define	P2NCS		(*(unsigned char volatile xdata *)0xFE1A)//P2��ʩ���ش������ƼĴ���
#define	P2SR		(*(unsigned char volatile xdata *)0xFE22)//P2�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P2DR        (*(unsigned char volatile xdata *)0xFE2A)//P2�������������ƼĴ���

sfr		P3			=0xb0;  //P3�˿�
sbit	P30			=P3^0;  //P3.0��
sbit	P31			=P3^1;  //P3.1��
sbit	P32			=P3^2;  //P3.2��
sbit	P33			=P3^3;  //P3.3��
sbit	P34			=P3^4;  //P3.4��
sbit	P35			=P3^5;  //P3.5��
sbit	P36			=P3^6;  //P3.6��
sbit	P37			=P3^7;  //P3.7��
sfr		P3M0		=0xB2;  //P3�����üĴ���0
sfr		P3M1		=0xB1;  //P3�����üĴ���1
#define	P3PU		(*(unsigned char volatile xdata *)0xFE13)//P3������������ƼĴ���
#define	P3NCS		(*(unsigned char volatile xdata *)0xFE1B)//P3��ʩ���ش������ƼĴ���
#define	P3SR		(*(unsigned char volatile xdata *)0xFE23)//P3�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P3DR        (*(unsigned char volatile xdata *)0xFE2B)//P3�������������ƼĴ���
#define	P3IE        (*(unsigned char volatile xdata *)0xFE33)//P3�������ź�����ʹ�ܿ��ƼĴ���

sfr		P4			=0xC0;  //P4�˿�
sbit	P40			=P4^0;  //P4.0��
sbit	P41			=P4^1;  //P4.1��
sbit	P42			=P4^2;  //P4.2��
sbit	P43			=P4^3;  //P4.3��
sbit	P44			=P4^4;  //P4.4��
sbit	P45			=P4^5;  //P4.5��
sbit	P46			=P4^6;  //P4.6��
sbit	P47			=P4^7;  //P4.7��
sfr		P4M0		=0xB4;  //P4�����üĴ���0
sfr		P4M1		=0xB3;  //P4�����üĴ���1
#define	P4PU		(*(unsigned char volatile xdata *)0xFE14)//P4������������ƼĴ���
#define	P4NCS		(*(unsigned char volatile xdata *)0xFE1C)//P4��ʩ���ش������ƼĴ���
#define	P4SR		(*(unsigned char volatile xdata *)0xFE24)//P4�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P4DR        (*(unsigned char volatile xdata *)0xFE2C)//P4�������������ƼĴ���

sfr		P5			=0xC8;  //P5�˿�
sbit	P50			=P5^0;  //P5.0��
sbit	P51			=P5^1;  //P5.1��
sbit	P52			=P5^2;  //P5.2��
sbit	P53			=P5^3;  //P5.3��
sbit	P54			=P5^4;  //P5.4��
sbit	P55			=P5^5;  //P5.5��
sbit	P56			=P5^6;  //P5.6��
sbit	P57			=P5^7;  //P5.7��
sfr		P5M0		=0xCA;  //P5�����üĴ���0
sfr		P5M1		=0xC9;  //P5�����üĴ���1
#define	P5PU		(*(unsigned char volatile xdata *)0xFE15)//P5������������ƼĴ���
#define	P5NCS		(*(unsigned char volatile xdata *)0xFE1D)//P5��ʩ���ش������ƼĴ���
#define	P5SR		(*(unsigned char volatile xdata *)0xFE25)//P5�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P5DR        (*(unsigned char volatile xdata *)0xFE2D)//P5�������������ƼĴ���

sfr		P6			=0xE8;  //P6�˿�
sbit	P60			=P6^0;  //P6.0��
sbit	P61			=P6^1;  //P6.1��
sbit	P62			=P6^2;  //P6.2��
sbit	P63			=P6^3;  //P6.3��
sbit	P64			=P6^4;  //P6.4��
sbit	P65			=P6^5;  //P6.5��
sbit	P66			=P6^6;  //P6.6��
sbit	P67			=P6^7;  //P6.7��
sfr		P6M0		=0xCC;  //P6�����üĴ���0
sfr		P6M1		=0xCB;  //P6�����üĴ���1
#define	P6PU		(*(unsigned char volatile xdata *)0xFE16)//P6������������ƼĴ���
#define	P6NCS		(*(unsigned char volatile xdata *)0xFE1E)//P6��ʩ���ش������ƼĴ���
#define	P6SR		(*(unsigned char volatile xdata *)0xFE26)//P6�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P6DR        (*(unsigned char volatile xdata *)0xFE2E)//P6�������������ƼĴ���

sfr		P7			=0xF8;  //P7�˿�
sbit	P70			=P7^0;  //P7.0��
sbit	P71			=P7^1;  //P7.1��
sbit	P72			=P7^2;  //P7.2��
sbit	P73			=P7^3;  //P7.3��
sbit	P74			=P7^4;  //P7.4��
sbit	P75			=P7^5;  //P7.5��
sbit	P76			=P7^6;  //P7.6��
sbit	P77			=P7^7;  //P7.7��
sfr		P7M0		=0xE2;  //P7�����üĴ���0
sfr		P7M1		=0xE1;  //P7�����üĴ���7
#define	P7PU		(*(unsigned char volatile xdata *)0xFE17)//P7������������ƼĴ���
#define	P7NCS		(*(unsigned char volatile xdata *)0xFE1F)//P7��ʩ���ش������ƼĴ���
#define	P7SR		(*(unsigned char volatile xdata *)0xFE27)//P7�ڵ�ƽת���ٶȿ��ƼĴ���
#define	P7DR        (*(unsigned char volatile xdata *)0xFE2F)//P7�������������ƼĴ���
/*------------------------���Ź����⹦�ܼĴ���---------------------------*/
sfr		WDT_CONTR					=0xC1;  //���Ź����ƼĴ���
#define	WDT_FLAG					0x80   //���Ź������־λ
#define	EN_WDT						0x20   //���Ź�ʹ��λ
#define	CLR_WDT						0x10   //���Ź���ʱ������
#define	IDL_WDT						0x08   //����ģʽ�¿��Ź�����λ
//-------------����ָ��------------//
#define	WDT_POWER_ON				do{WDT_CONTR|= EN_WDT;}while(0)//�򿪿��Ź�

#define	WDT_CLR						do{WDT_CONTR|=CLR_WDT;}while(0)//ι��

#define WDT_SET_IDLE_ENABLE			do{WDT_CONTR|= IDL_WDT;}while(0)//���Ź��ڿ���ģʽ�¼�������
#define WDT_SET_IDLE_DISABLE		do{WDT_CONTR&=~IDL_WDT;}while(0)//���Ź��ڿ���ģʽ��ֹͣ����

#define WDT_SET_SCALE(value)		do{WDT_CONTR=((WDT_CONTR&(~0x07))|((unsigned char)(value)&0x07));}while(0)//���ÿ��Ź���Ԥ��Ƶϵ��
//-------------�Ĵ�����ȡ----------//
#define WDT_SET_REG_CONTR(value)	do{WDT_CONTR=(unsigned char)value;}while(0)//����WDT_CONTR�Ĵ���
#define	WDT_GET_REG_CONTR			(WDT_CONTR)//��ȡWDT_CONTR�Ĵ�����ֵ
/*-------------------------ADC���⹦�ܼĴ���----------------------------*/
sfr		ADC_CONTR					=0xBC;	//ADC���ƼĴ���
#define	ADC_POWER					0x80	//ADC��Դ����λ
#define	ADC_START					0x40	//ADCת����������λ
#define	ADC_FLAG					0x20	//ADCת��������־λ
sfr		ADC_RES						=0xBD;	//ADCת������Ĵ������ߣ�
sfr		ADC_RESL					=0xBE;	//ADCת������Ĵ������ͣ�
sfr		ADC_CFG						=0xDE;	//ADC���üĴ���
#define	ADC_RESFMT					0x20	//ADCת�������ʽ����λ
#define	ADC_TIM						(*(unsigned char volatile xdata *)0xFEA8)//ADCʱ����ƼĴ���
//-------------����ָ��------------//
#define	ADC_POWER_ON				do{ADC_CONTR|= ADC_POWER;}while(0)//��ADC�ĵ�Դ
#define	ADC_POWER_OFF				do{ADC_CONTR&=~ADC_POWER;}while(0)//�ر�ADC�ĵ�Դ

#define	ADC_IT_ENABLE				do{EADC=1;}while(0)
#define	ADC_IT_DISABLE				do{EADC=0;}while(0)

#define	ADC_GET_IT_FLAG				(ADC_CONTR&ADC_FLAG)//��ȡADת��������־λ
#define	ADC_IT_CLS					do{ADC_CONTR&=~ADC_FLAG;}while(0)//���ADת��������־λ

#define	ADC_MEASURE_ON				do{ADC_CONTR|=ADC_START;}while(0)//��ʼADת��

#define	ADC_SET_CHANNELS(value)		do{ADC_CONTR=((ADC_CONTR&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//����ADC��ת��ͨ��

#define	ADC_SET_ALIGN_LEFT			do{ADC_CFG&=~ADC_RESFMT;}while(0)//����ADC�Ľ�����������
#define	ADC_SET_ALIGN_RIGHT			do{ADC_CFG|= ADC_RESFMT;}while(0)//����ADC�Ľ���Ҷ�������

#define	ADC_SET_SPEED(value)		do{ADC_CFG=((ADC_CFG&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//����ADC��ת���ٶ�
//-------------�Ĵ�����ȡ----------//
#define	ADC_SET_REG_CONTR(value)	do{ADC_CONTR=(unsigned char)value;}while(0)	//����ADC_CONTR�Ĵ���
#define	ADC_GET_REG_CONTR			(ADC_CONTR)	//��ȡADC_CONTR�Ĵ�����ֵ

#define	ADC_SET_REG_CFG(value)		do{ADC_CFG=(unsigned char)value;}while(0)	//����ADC_CFG�Ĵ���
#define	ADC_GET_REG_CFG				(ADC_CFG)	//��ȡADC_CFG�Ĵ�����ֵ

#define	ADC_SET_REG_TIM(value)		do{ADC_TIM=(unsigned char)value;}while(0)	//����ADC_TIM�Ĵ���
#define	ADC_GET_REG_TIM				(ADC_TIM)	//��ȡADC_TIM�Ĵ�����ֵ

#define ADC_GET_REG_RES_HL			((((unsigned int)ADC_RES)<<8)|(unsigned int)ADC_RESL)//��ȡADC����Ĵ�����ȫ��
#define ADC_GET_REG_RES_H8			(ADC_RES )	//��ȡADC����Ĵ����ĸ�8λ
#define ADC_GET_REG_RES_L8			(ADC_RESL)	//��ȡADC����Ĵ����ĵ�8λ
//-------------���ܶ���------------//
#define ADC_IT_NUM					interrupt 5//ADC���жϺ�
/*-----------------------ʱ�ӹ������⹦�ܼĴ���--------------------------*/
#define	CKSEL						(*(unsigned char volatile xdata *)0xFE00)//ʱ��ѡ��Ĵ���
#define	CLKDIV						(*(unsigned char volatile xdata *)0xFE01)//ʱ�ӷ�Ƶ�Ĵ���
#define	HIRCCR						(*(unsigned char volatile xdata *)0xFE02)//�ڲ������������ƼĴ���
#define	XOSCCR						(*(unsigned char volatile xdata *)0xFE03)//�ⲿ������ƼĴ���
#define	IRC32KCR					(*(unsigned char volatile xdata *)0xFE04)//�ڲ�32K�������ƼĴ���
#define	MCLKOCR						(*(unsigned char volatile xdata *)0xFE05)//��ʱ��������ƼĴ���
#define	IRCDB						(*(unsigned char volatile xdata *)0xFE06)//�ڲ���������ȥ�����ƼĴ���
#define	X32KCR						(*(unsigned char volatile xdata *)0xFE08)//�ⲿ32K�������ƼĴ���
sfr		IRTRIM						=0x9F;//�ڲ��߾���IRCƵ�ʵ����Ĵ���
sfr		LIRTRIM						=0x9E;//�ڲ��߾���IRCƵ��΢���Ĵ���
sfr		IRCBAND						=0x9D;//IRCƵ��ѡ��Ĵ���
//-------------����ָ��------------//
#define	CLK_SET_SOURCE_HSI			do{CKSEL=((CKSEL&(~0x03))|0x00);}while(0)//����ʱ��ԴΪ�ڲ�����IRC
#define	CLK_SET_SOURCE_HSE			do{CKSEL=((CKSEL&(~0x03))|0x01);}while(0)//����ʱ��ԴΪ�ⲿ���پ���
#define	CLK_SET_SOURCE_LSE			do{CKSEL=((CKSEL&(~0x03))|0x02);}while(0)//����ʱ��ԴΪ�ⲿ���پ���
#define	CLK_SET_SOURCE_LSI			do{CKSEL=((CKSEL&(~0x03))|0x03);}while(0)//����ʱ��ԴΪ�ڲ�����IRC

#define	CLK_HSI_POWER_ON			do{HIRCCR=((HIRCCR&(~0x81))|0x80);}while(!(HIRCCR&0x01))//����HSI��Դ
#define	CLK_HSI_POWER_OFF			do{HIRCCR=0x00;}while(0)//�ر�HSI��Դ

#define	CLK_HSE_A_POWER_ON			do{XOSCCR=((XOSCCR&(~0xC1))|0x80);}while(!(XOSCCR&0x01))//����HSE��Դ�������ó���Դ����
#define	CLK_HSE_P_POWER_ON			do{XOSCCR=((XOSCCR&(~0xC1))|0xC0);}while(!(XOSCCR&0x01))//����HSE��Դ�������ó���Դ����
#define	CLK_HSE_POWER_OFF			do{XOSCCR=0x00;}while(0)//�ر�HSE��Դ

#define	CLK_HSE_GAIN_ENABLE			do{XOSCCR|= 0x20;}while(0)//���ⲿ���پ�������
#define	CLK_HSE_GAIN_DISABLE		do{XOSCCR&=~0x20;}while(0)//�ر��ⲿ���پ�������

#define	CLK_LSE_POWER_ON			do{X32KCR=((X32KCR&(~0x81))|0x80);}while(!(X32KCR&0x01))//����LSE��Դ
#define	CLK_LSE_POWER_OFF			do{X32KCR=0x00;}while(0)//�ر�LSE��Դ

#define	CLK_LSE_GAIN_ENABLE			do{X32KCR|= 0x40;}while(0)//���ⲿ���پ�������
#define	CLK_LSE_GAIN_DISABLE		do{X32KCR&=~0x40;}while(0)//�ر��ⲿ���پ�������

#define	CLK_LSI_POWER_ON			do{IRC32KCR=((IRC32KCR&(~0x81))|0x80);}while(!(IRC32KCR&0x01))//����LSI��Դ
#define	CLK_LSI_POWER_OFF			do{IRC32KCR=0x00;}while(0)//�ر�LSI��Դ

#define	CLK_SET_OUT_TO_P54_FA		do{CKSEL&=~0x08;}while(0)//����ʱ�������ΪP5.4(������STC8F��STC8A)
#define	CLK_SET_OUT_TO_P16_FA		do{CKSEL|= 0x08;}while(0)//����ʱ�������ΪP1.6(������STC8F��STC8A)

#define	CLK_OUT_SET_DIV_FA(value)	do{CKSEL=((CKSEL&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//����ʱ�������Ƶ(������STC8F��STC8A)

#define	CLK_SET_OUT_TO_P54_GH		do{MCLKOCR&=~0x80;}while(0)//����ʱ�������ΪP5.4(������STC8G��STC8H)
#define	CLK_SET_OUT_TO_P16_GH		do{MCLKOCR|= 0x80;}while(0)//����ʱ�������ΪP1.6(������STC8G��STC8H)

#define	CLK_OUT_SET_DIV_GH(value)	do{MCLKOCR=((MCLKOCR&(~0x7F))|((unsigned char)(value)&0x7F));}while(0)//����ʱ�������Ƶ(������STC8G��STC8H)
//-------------�Ĵ�����ȡ----------//
#define	CLK_SET_REG_CLKDIV(value)	do{CLKDIV=(unsigned char)value;}while(0)//����CLKDIV�Ĵ���
#define	CLK_GET_REG_CLKDIV			(CLKDIV)//��ȡCLKDIV�Ĵ���
/*----------------------IAP/ISP���⹦�ܼĴ���---------------------------*/
sfr		IAP_DATA					=0xC2;  //IAP���ݼĴ���
sfr		IAP_ADDRH					=0xC3;  //IAP�ߵ�ַ�Ĵ���
sfr		IAP_ADDRL					=0xC4;  //IAP�͵�ַ�Ĵ���
sfr		IAP_CMD						=0xC5;  //IAP����Ĵ���
#define	IAP_IDL						0x00
#define	IAP_READ					0x01
#define	IAP_WRITE					0x02
#define	IAP_ERASE					0x03
sfr		IAP_TRIG					=0xC6;  //IAP�����Ĵ���
sfr		IAP_CONTR					=0xC7;  //IAP���ƼĴ���
sfr		IAP_TPS						=0xF5;  //EEPROM�����ȴ�ʱ����ƼĴ���
#define IAPEN						0x80   //EEPROM����ʹ�ܿ���λ
#define SWBS						0x40   //�����λѡ�����λ
#define SWRST						0x20   //�����λ����
#define CMD_FAIL					0x10   //EEPROM����ʧ��״̬λ
//-------------����ָ��------------//
#define	IAP_POWER_ON				do{IAP_CONTR|= IAPEN;}while(0)//��IAP����
#define	IAP_POWER_OFF				do{IAP_CONTR&=~IAPEN;}while(0)//�ر�IAP����

#define	IAP_CMD_NOP					do{IAP_CMD=IAP_IDL;}while(0)//�ղ���
#define	IAP_CMD_READ				do{IAP_CMD=IAP_READ;}while(0)//��һ���ֽ�
#define	IAP_CMD_WRITE				do{IAP_CMD=IAP_WRITE;}while(0)//дһ���ֽ�
#define	IAP_CMD_ERASE				do{IAP_CMD=IAP_ERASE;}while(0)//����һ������

#define	IAP_TRIG_ON					do{IAP_TRIG=0x5A;IAP_TRIG=0xA5;}while(0)//����һ��EEPROM����
#define	IAP_TRIG_CLS				do{IAP_TRIG=0;}while(0)//��մ����Ĵ���

#define	IAP_GET_FAIL				(IAP_CONTR&CMD_FAIL)
//-------------�Ĵ�����ȡ----------//
#define	IAP_SET_REG_DATA(value)		do{IAP_DATA=(unsigned char)value;}while(0)//дһ�����ݵ�IAP_DATA
#define	IAP_GET_REG_DATA			(IAP_DATA)//��IAP_DATA��һ������

#define	IAP_SET_REG_ADDR_HL(value)	do{IAP_ADDRL=(unsigned char)(value);IAP_ADDRH=(unsigned char)(value>>8);}while(0)//дһ����ַ��IAP_ADDRH��IAP_ADDRL��
#define	IAP_GET_REG_ADDR_HL			((((unsigned int)IAP_ADDRH)<<8)|(unsigned int)IAP_ADDRL)//��һ����ַIAP_ADDR

#define	IAP_SET_REG_ADDR_H8(value)	do{IAP_ADDRH=(unsigned char)(value);}while(0)//дһ����ַ��IAP_ADDRH��
#define	IAP_GET_REG_ADDR_H8			(IAP_ADDRH)//��IAP_ADDRH

#define	IAP_SET_REG_ADDR_L8(value)	do{IAP_ADDRL=(unsigned char)(value);}while(0)//дһ����ַ��IAP_ADDRL��
#define	IAP_GET_REG_ADDR_L8			(IAP_ADDRL)//��IAP_ADDRL

#define	IAP_SET_REG_CONTR(value)	do{IAP_CONTR=(unsigned char)(value);}while(0)//д��һ�����ݵ�IAP_CONTR�Ĵ���
#define	IAP_GET_REG_CONTR			(IAP_CONTR)//��ȡIAP_CONTR�Ĵ���

#define	IAP_SET_REG_TPS(value)			do{IAP_TPS=(unsigned char)(value);}while(0)//дһ�����ݵ�IAP_TPS�Ĵ���
#define	IAP_GET_REG_TPS					(IAP_TPS)//��IAP_TPS�Ĵ���
/*-------------------------SPI���⹦�ܼĴ���----------------------------*/
sfr		SPSTAT					=0xCD;//SPI״̬�Ĵ���
#define	SPIF					0x80   //SPI�жϱ�־λ
#define	WCOL					0x40   //SPIд��ͻ��־λ
sfr		SPCTL					=0xCE;//SPI���ƼĴ���
#define	SSIG					0x80   //SS���Ź��ܿ���λ
#define	SPEN					0x40   //SPIʹ�ܿ���λ
#define	DORD					0x20   //SPI����λ����/����˳��λ
#define	MSTR					0x10   //������/��ģʽѡ��λ
#define	CPOL					0x08   //SPIʱ�Ӽ��Կ���
#define	CPHA					0x04   //SPIʱ����λ����
sfr		SPDAT					=0xCF;//SPI���ݼĴ���
//-------------����ָ��------------//
#define	SPI_POWER_ON				do{SPCTL|= SPEN;}while(0)//��SPI
#define	SPI_POWER_OFF				do{SPCTL&=~SPEN;}while(0)//�ر�SPI

#define	SPI_SET_CS_ENABLE			do{SPCTL&=~SSIG;}while(0)//��CS�ŵ�ʹ��
#define	SPI_SET_CS_DISABLE			do{SPCTL|= SSIG;}while(0)//�ر�CS�ŵ�ʹ��

#define	SPI_SET_DATA_MSB			do{SPCTL&=~DORD;}while(0)//�����ȷ�/�����ݵĸ�λ
#define	SPI_SET_DATA_LSB			do{SPCTL|= DORD;}while(0)//�����ȷ�/�����ݵĵ�λ

#define	SPI_SET_MODE_MASTER			do{SPCTL|= MSTR;}while(0)//����SPIΪ����ģʽ
#define	SPI_SET_MODE_SLAVE			do{SPCTL&=~MSTR;}while(0)//����SPIΪ�ӻ�ģʽ

#define	SPI_SET_CPOL_1				do{SPCTL|= CPOL;}while(0)//����CPOLλΪ1
#define	SPI_SET_CPOL_0				do{SPCTL&=~CPOL;}while(0)//����CPOLλΪ0

#define	SPI_SET_CPHA_1				do{SPCTL|= CPHA;}while(0)//����CPHAλΪ1
#define	SPI_SET_CPHA_0				do{SPCTL&=~CPHA;}while(0)//����CPHAλΪ0

#define SPI_SET_PIN(value)			do{P_SW1=((P_SW1&(~0x0C))|((unsigned char)(value)&0x0C));}while(0)//���ô���1���������

#define	SPI_IT_CLS					do{SPSTAT|=(SPIF|WCOL);}while(0)//��SPI�жϱ�־λ
#define	SPI_WCOL_CLS				do{SPSTAT|=WCOL;}while(0)//��SPIд��ͻ��־λ
#define	SPI_GET_IT_FLAG				(SPSTAT&SPIF)

#define	SPI_IT_ENABLE				do{IE2|= ESPI;}while(0)//��SPI�ж�
#define	SPI_IT_DISABLE				do{IE2&=~ESPI;}while(0)//��SPI�ж�

#define	SPI_SET_SPR(value)			do{SPCTL=((SPCTL&(~0x03))|((unsigned char)(value)&0x03));}while(0)//����SPIʱ�ӷ�Ƶ
#define	SPI_GET_SPR					(SPCTL&0x03)			//��ȡSPIʱ�ӷ�Ƶ
//-------------�Ĵ�����ȡ----------//
#define	SPI_SET_REG_SPSTAT(value)	do{SPSTAT=(unsigned char)(value);}while(0)//дһ�����ݵ�SPCTL�Ĵ���
#define	SPI_GET_REG_SPSTAT			(SPSTAT)//��ȡSPCTL�Ĵ�����ֵ

#define	SPI_SET_REG_SPCTL(value)	do{SPCTL=(unsigned char)(value);}while(0)//дһ�����ݵ�SPCTL�Ĵ���
#define	SPI_GET_REG_SPCTL			(SPCTL)//��ȡSPCTL�Ĵ�����ֵ

#define	SPI_SET_REG_SPDAT(value)	do{SPDAT=(unsigned char)(value);}while(0)//дһ�����ݵ�SPDAT�Ĵ���
#define	SPI_GET_REG_SPDAT			(SPDAT)//��ȡSPDAT�Ĵ�����ֵ
//-------------���ܶ���------------//
#define SPI_IT_NUM				interrupt 9//SPI���жϺ�
/*-----------------------ϵͳ�������⹦�ܼĴ���--------------------------*/
sfr     PCON						=0x87;  //��Դ���ƼĴ���
#define SMOD						0x80   //����1�����ʿ���λ
#define SMOD0						0x40   //֡���������λ
#define LVDF						0x20   //��ѹ����ж������־
#define POF							0x10   //�ϵ��־λ
#define GF1							0x08   //�û�ר�ñ�־λ
#define GF0							0x04   //�û�ר�ñ�־λ
#define PD							0x02   //����ģʽ����λ
#define IDL							0x01   //����ģʽ����λ
sfr     AUXR2						=0x97;  //�����Ĵ���2
#define TXLNRX						0x10   
sfr BUS_SPEED						=0xA1;  //�����ٶȿ��ƼĴ���
sfr     P_SW1						=0xA2;  //����˿��л��Ĵ���1
sfr     P_SW2						=0xBA;  //����˿��л��Ĵ���2
#define EAXFR						0x80
sfr     VOCTRL						=0xBB;  //��ѹ���ƼĴ���
sfr     RSTCFG						=0xFF;  //��λ���üĴ���
//-------------����ָ��------------//
#define POWER_RESET					do{IAP_CONTR=(SWRST|SWBS);}while(0)	//�൱���ϵ�����(���ݻᶪʧ)
#define MCU_RESET					do{IAP_CONTR=(SWRST);}while(0)		//�൱�ڰ�����λ(���ݲ��ᶪʧ)
#define POWER_DOWN					do{PCON|=PD;}while(0)				//����ģʽ
#define POWER_IDLE					do{PCON|=IDL;}while(0)				//����ģʽ
#define EX_SFR_ENABLE				do{P_SW2|= EAXFR;}while(0)			//�򿪶���ļĴ�����ַ��
#define EX_SFR_DISABLE				do{P_SW2&=~EAXFR;}while(0)			//�رն���ļĴ�����ַ��
//-------------�Ĵ�����ȡ----------//
#define	SYS_SET_REG_RSTCFG(value)	do{RSTCFG=(unsigned char)(value);}while(0)//����RSTCFG�Ĵ���
#define	SYS_GET_REG_RSTCFG			(RSTCFG)//��ȡRSTCFG�Ĵ���
/*------------------------���綨ʱ�����ܼĴ���---------------------------*/
sfr		WKTCL						=0xAA;//���绽�Ѷ�ʱ������8λ��
sfr		WKTCH						=0xAB;//���绽�Ѷ�ʱ������8λ��
sfr16	WKTC						=0xAA;//���绽�Ѷ�ʱ����16λ��
#define	WKTEN						0x80	//���绽��ʹ��
//-------------����ָ��------------//
#define	WKT_ON						do{WKTCH|= WKTEN;}while(0)//�򿪵��綨ʱ��
#define	WKT_OFF						do{WKTCH&=~WKTEN;}while(0)//�رյ��綨ʱ��
//-------------�Ĵ�����ȡ----------//
#define	WKT_SET_REG_COUNT(value)	do{WKTC=(unsigned int)value}while(0)//���õ��綨ʱ��
#define	WKT_GET_REG_COUNT			(WKTC)//��ȡ���綨ʱ��
/*------------------------��ͨ��ʱ�����ܼĴ���---------------------------*/
/*###############################��ʱ��0################################*/
sfr		TCON						=0x88;  //��ʱ�����ƼĴ���
sbit	TF1							=TCON^7;//��ʱ��1����жϱ�־λ
sbit	TR1							=TCON^6;//��ʱ��1���п���λ
sbit	TF0							=TCON^5;//��ʱ��0����жϱ�־λ
sbit	TR0							=TCON^4;//��ʱ��0���п���λ
sbit	IE1							=TCON^3;//�ⲿ�ж�1�����־λ
sbit	IT1							=TCON^2;//�ⲿ�ж�1��������λ
sbit	IE0							=TCON^1;//�ⲿ�ж�0�����־λ
sbit	IT0							=TCON^0;//�ⲿ�ж�0��������λ
sfr		TMOD						=0x89;  //��ʱ��0/1ģʽ�Ĵ���
#define T1_GATE						0x80   //��ʱ��1�ſ�λ
#define T1_CT						0x40   //��ʱ��1��������λ
#define T1_M1						0x20   //��ʱ��1ģʽѡ��λ1
#define T1_M0						0x10   //��ʱ��1ģʽѡ��λ0
#define T0_GATE						0x08   //��ʱ��0�ſ�λ
#define T0_CT						0x04   //��ʱ��0��������λ
#define T0_M1						0x02   //��ʱ��0ģʽѡ��λ1
#define T0_M0						0x01   //��ʱ��0ģʽѡ��λ0
sfr		TL0							=0x8A;  //��ʱ��0�����Ĵ�������8λ��
sfr		TL1							=0x8B;  //��ʱ��1�����Ĵ�������8λ��
sfr		TH0							=0x8C;  //��ʱ��0�����Ĵ�������8λ��
sfr		TH1							=0x8D;  //��ʱ��1�����Ĵ�������8λ��
sfr		AUXR						=0x8E;  //�����Ĵ���1
#define	T0x12						0x80   //��ʱ��0�ٶȿ���λ 
#define	T1x12						0x40   //��ʱ��1�ٶȿ���λ
#define	UART_M0x6					0x20   //����1ģʽ0��ͨѶ�ٶȿ���λ
#define	T2R							0x10   //��ʱ��2���п���λ
#define	T2_CT						0x08   //��ʱ��2��������λ
#define	T2x12						0x04   //��ʱ��2�ٶȿ���λ
#define	EXTRAM						0x02   //��չRAM���ʿ���λ
#define	S1ST2						0x01   //����1�����ʷ�����ѡ��Ϊλ
sfr		T2H							=0xD6;  //��ʱ��2�����Ĵ�������8λ��
sfr		T2L							=0xD7;  //��ʱ��2�����Ĵ�������8λ��
//-------------����ָ��------------//
#define TIMER0_ON					do{TF0=0;TR0=1;}while(0)	//����ʱ��0
#define TIMER0_OFF					do{TR0=0;}while(0)			//�ض�ʱ��0

#define TIMER0_IT_ENABLE			do{ET0=1;}while(0)			//����ʱ��0�ж�ʹ��
#define TIMER0_IT_DISABLE			do{ET0=0;}while(0)			//�ض�ʱ��0�ж�ʹ��

#define TIMER0_GATE_ENABLE			do{TMOD|= T0_GATE;}while(0)	//����ʱ��0���ſ�λ
#define TIMER0_GATE_DISABLE			do{TMOD&=~T0_GATE;}while(0)	//�ض�ʱ��0���ſ�λ

#define	TIMER0_OUT_ON				do{INTCLKO|= T0CLKO;}while(0)//����ʱ��0��ʱ�����
#define	TIMER0_OUT_OFF				do{INTCLKO&=~T0CLKO;}while(0)//�ض�ʱ��0��ʱ�����

#define TIMER0_SET_MODE_COUNT		do{TMOD|= T0_CT;}while(0)	//�趨��ʱ��0Ϊ������
#define TIMER0_SET_MODE_TIMER		do{TMOD&=~T0_CT;}while(0)	//�趨��ʱ��0Ϊ��ʱ��

#define TIMER0_SET_MODE_AUTO16		do{TMOD=(TMOD&(~0x03));}while(0)		//��ʱ��0������16λģʽ
#define TIMER0_SET_MODE_16BIT		do{TMOD=(TMOD&(~0x03))|T0_M0;}while(0)	//��ʱ��0������16λģʽ
#define TIMER0_SET_MODE_8BIT		do{TMOD=(TMOD&(~0x03))|T0_M1;}while(0)	//��ʱ��0������8λ�Զ�����
#define TIMER0_SET_MODE_1T			do{AUXR|= T0x12;}while(0)	//�趨��ʱ��0Ϊ1Tģʽ
#define TIMER0_SET_MODE_12T			do{AUXR&=~T0x12;}while(0)	//�趨��ʱ��0Ϊ12Tģʽ

#define	TIMER0_GET_FLAG				(TF0)//��ʱ��0�������־λ
#define	TIMER0_FLAG_CLS				do{TF0=0;}while(0)//�嶨ʱ��0�������־λ
//-------------�Ĵ�����ȡ----------//
#define	TIMER0_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x80))|((unsigned char)(value)&0x80));}while(0)//����AUXR�Ĵ����Ķ�ʱ��0����
#define	TIMER0_GET_REG_AUXR			(AUXR&0x80)//��ȡAUXR�Ĵ����Ķ�ʱ��0����

#define TIMER0_SET_REG_TMOD(value)	do{TMOD=((TMOD&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)	//���ö�ʱ��0�Ĺ���ģʽ
#define TIMER0_GET_REG_TMOD			(TMOD&0x0F)								//��ȡ��ʱ��0�Ĺ���ģʽ

#define TIMER0_SET_REG_HL(value)	do{TL0=(unsigned char)(value);TH0=(unsigned char)(value>>8);}while(0)//���ö�ʱ��0�ļ���ֵ
#define TIMER0_GET_REG_HL			((((unsigned int)TH0)<<8)|(unsigned int)TL0)//��ȡ��ʱ��0�ļ���ֵ

#define TIMER0_SET_REG_H8(value)	do{TH0=(unsigned char)(value);}while(0)		//���ö�ʱ��0�ļ���ֵ�ĸ�8λ
#define TIMER0_GET_REG_H8			(TH0)										//��ȡ��ʱ��0�ļ���ֵ�ĸ�8λ

#define TIMER0_SET_REG_L8(value)	do{TL0=(unsigned char)(value);}while(0)		//���ö�ʱ��0�ļ���ֵ�ĵ�8λ
#define TIMER0_GET_REG_L8			(TL0)										//��ȡ��ʱ��0�ļ���ֵ�ĵ�8λ
//-------------���ܶ���------------//
#define TIMER0_IT_NUM				interrupt 1//��ʱ��0���жϺ�
/*###############################��ʱ��1################################*/
//-------------����ָ��------------//
#define TIMER1_ON					do{TF1=0;TR1=1;}while(0)	//����ʱ��1
#define TIMER1_OFF					do{TR1=0;}while(0)			//�ض�ʱ��1

#define TIMER1_IT_ENABLE			do{ET1=1;}while(0)			//����ʱ��1�ж�ʹ��
#define TIMER1_IT_DISABLE			do{ET1=0;}while(0)			//�ض�ʱ��1�ж�ʹ��

#define TIMER1_GATE_ENABLE			do{TMOD|= T1_GATE;}while(0)	//����ʱ��1���ſ�λ
#define TIMER1_GATE_DISABLE			do{TMOD&=~T1_GATE;}while(0)	//�ض�ʱ��1���ſ�λ

#define	TIMER1_OUT_ON				do{INTCLKO|= T1CLKO;}while(0)//����ʱ��1��ʱ�����
#define	TIMER1_OUT_OFF				do{INTCLKO&=~T1CLKO;}while(0)//�ض�ʱ��1��ʱ�����

#define TIMER1_SET_MODE_COUNT		do{TMOD|= T1_CT;}while(0)//�趨��ʱ��1Ϊ������
#define TIMER1_SET_MODE_TIMER		do{TMOD&=~T1_CT;}while(0)//�趨��ʱ��1Ϊ��ʱ��

#define TIMER1_SET_MODE_AUTO16		do{TMOD=(TMOD&(~0x30));}while(0)		//��ʱ��1������16λģʽ
#define TIMER1_SET_MODE_16BIT		do{TMOD=(TMOD&(~0x30))|T1_M0;}while(0)	//��ʱ��1������16λģʽ
#define TIMER1_SET_MODE_8BIT		do{TMOD=(TMOD&(~0x30))|T1_M1;}while(0)	//��ʱ��1������8λ�Զ�����

#define	TIMER1_SET_MODE_1T			do{AUXR|= T1x12;}while(0)//�趨��ʱ��1Ϊ1Tģʽ
#define	TIMER1_SET_MODE_12T			do{AUXR&=~T1x12;}while(0)//�趨��ʱ��1Ϊ12Tģʽ

#define	TIMER1_GET_FLAG				(TF1)//��ʱ��1�������־λ
#define	TIMER1_FLAG_CLS				do{TF1=0;}while(0)//�嶨ʱ��1�������־λ
//-------------�Ĵ�����ȡ----------//
#define	TIMER1_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x40))|((unsigned char)(value)&0x40));}while(0)//����AUXR�Ĵ����Ķ�ʱ��1����
#define	TIMER1_GET_REG_AUXR			(AUXR&0x40)//��ȡAUXR�Ĵ����Ķ�ʱ��1����

#define TIMER1_SET_REG_TMOD(value)	do{TMOD=((TMOD&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//���ö�ʱ��1�Ĺ���ģʽ
#define TIMER1_GET_REG_TMOD			(TMOD&0xF0)					//��ȡ��ʱ��1�Ĺ���ģʽ

#define TIMER1_SET_REG_HL(value)	do{TL1=(unsigned char)(value);TH1=(unsigned char)(value>>8);}while(0)//���ö�ʱ��1�ļ���ֵ
#define TIMER1_GET_REG_HL			((((unsigned int)TH1)<<8)|(unsigned int)TL1)//��ȡ��ʱ��1�ļ���ֵ

#define TIMER1_SET_REG_H8(value)	do{TH1=(unsigned char)(value);}while(0)		//���ö�ʱ��1�ļ���ֵ�ĸ�8λ
#define TIMER1_GET_REG_H8			(TH1)										//��ȡ��ʱ��1�ļ���ֵ�ĸ�8λ

#define TIMER1_SET_REG_L8(value)	do{TL1=(unsigned char)(value);}while(0)		//���ö�ʱ��1�ļ���ֵ�ĵ�8λ
#define TIMER1_GET_REG_L8			(TL1)										//��ȡ��ʱ��1�ļ���ֵ�ĵ�8λ
//-------------���ܶ���------------//
#define TIMER1_IT_NUM				interrupt 3//��ʱ��1���жϺ�
/*###############################��ʱ��2################################*/
//-------------����ָ��------------//
#define TIMER2_ON					do{AUXR|= T2R;}while(0)  //�򿪶�ʱ��2
#define TIMER2_OFF					do{AUXR&=~T2R;}while(0)  //�رն�ʱ��2

#define TIMER2_IT_ENABLE			do{IE2 |= ET2;}while(0)  //�򿪶�ʱ��2�ж�
#define TIMER2_IT_DISABLE			do{IE2 &=~ET2;}while(0)  //�رն�ʱ��2�ж�

#define	TIMER2_OUT_ON				do{INTCLKO|= T2CLKO;}while(0)//����ʱ��2��ʱ�����
#define	TIMER2_OUT_OFF				do{INTCLKO&=~T2CLKO;}while(0)//�ض�ʱ��2��ʱ�����

#define TIMER2_SET_MODE_COUNT		do{AUXR|= T2_CT;}while(0)  //�趨��ʱ��2Ϊ������
#define TIMER2_SET_MODE_TIMER		do{AUXR&=~T2_CT;}while(0)  //�趨��ʱ��2Ϊ��ʱ��

#define TIMER2_SET_MODE_1T			do{AUXR|= T2x12;}while(0)  //�趨��ʱ��2Ϊ1Tģʽ
#define TIMER2_SET_MODE_12T			do{AUXR&=~T2x12;}while(0)  //�趨��ʱ��2Ϊ12Tģʽ

#define	TIMER2_IT_CLS				do{AUXINTIF&=~T2IF;}while(0)//�嶨ʱ��2�жϱ�־
//-------------�Ĵ�����ȡ----------//
#define	TIMER2_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x0C))|((unsigned char)(value)&0x0C));}while(0)//����AUXR�Ĵ����Ķ�ʱ��2����
#define	TIMER2_GET_REG_AUXR			(AUXR&0x0C)//��ȡAUXR�Ĵ����Ķ�ʱ��2����

#define TIMER2_SET_REG_HL(value)	do{T2L=(unsigned char)(value);T2H=(unsigned char)(value>>8);}while(0)//���ö�ʱ��2�ļ���ֵ
#define TIMER2_GET_REG_HL			((((unsigned int)T2H)<<8)|(unsigned int)T2L)//��ȡ��ʱ��2�ļ���ֵ

#define TIMER2_SET_REG_H8(value)	do{T2H=(unsigned char)(value);}while(0)		//���ö�ʱ��2�ļ���ֵ�ĸ�8λ
#define TIMER2_GET_REG_H8			(T2H)										//��ȡ��ʱ��2�ļ���ֵ�ĸ�8λ

#define TIMER2_SET_REG_L8(value)	do{T2L=(unsigned char)(value);}while(0)		//���ö�ʱ��2�ļ���ֵ�ĵ�8λ
#define TIMER2_GET_REG_L8			(T2L)
//-------------���ܶ���------------//
#define TIMER2_IT_NUM				interrupt 12//��ʱ��2���жϷ����
/*###############################��ʱ��3################################*/
sfr		T4T3M						=0xD1;  //��ʱ��4/3���ƼĴ���
#define	T4R							0x80   //��ʱ��4�������λ
#define	T4_CT						0x40   //��ʱ��4��������λ
#define	T4x12						0x20   //��ʱ��4�ٶȿ���λ
#define	T4CLKO						0x10   //��ʱ��4ʱ���������
#define	T3R							0x08   //��ʱ��3�������λ
#define	T3_CT						0x04   //��ʱ��3��������λ
#define	T3x12						0x02   //��ʱ��3�ٶȿ���λ
#define	T3CLKO						0x01   //��ʱ��3ʱ���������
sfr		T4H							=0xD2;  //��ʱ��4�����Ĵ�������8λ��
sfr		T4L							=0xD3;  //��ʱ��4�����Ĵ�������8λ��
sfr		T3H							=0xD4;  //��ʱ��3�����Ĵ�������8λ��
sfr		T3L							=0xD5;  //��ʱ��3�����Ĵ�������8λ��
//-------------����ָ��------------//
#define TIMER3_ON					do{T4T3M|= T3R;}while(0) //�򿪶�ʱ��3
#define TIMER3_OFF					do{T4T3M&=~T3R;}while(0) //�رն�ʱ��3

#define TIMER3_IT_ENABLE			do{IE2  |= ET3;}while(0) //�򿪶�ʱ��3�ж�
#define TIMER3_IT_DISABLE			do{IE2  &=~ET3;}while(0) //�رն�ʱ��3�ж�

#define	TIMER3_OUT_ON				do{T4T3M|= T3CLKO;}while(0)//����ʱ��3��ʱ�����
#define	TIMER3_OUT_OFF				do{T4T3M&=~T3CLKO;}while(0)//�ض�ʱ��3��ʱ�����

#define TIMER3_SET_MODE_COUNT		do{T4T3M|= T3_CT;}while(0) //�趨��ʱ��3Ϊ������
#define TIMER3_SET_MODE_TIMER		do{T4T3M&=~T3_CT;}while(0) //�趨��ʱ��3Ϊ��ʱ��

#define TIMER3_SET_MODE_1T			do{T4T3M|= T3x12;}while(0) //�趨��ʱ��3Ϊ1Tģʽ
#define TIMER3_SET_MODE_12T			do{T4T3M&=~T3x12;}while(0) //�趨��ʱ��3Ϊ12Tģʽ

#define TIMER3_IT_CLS				do{AUXINTIF&=~T3IF;}while(0)//�嶨ʱ��3�жϱ�־
//-------------�Ĵ�����ȡ----------//
#define	TIMER3_SET_REG_T4T3M(value)	do{T4T3M=((T4T3M&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//����T4T3M�Ĵ����Ķ�ʱ��3����
#define	TIMER3_GET_REG_T4T3M		(T4T3M&0x0F)//��ȡT4T3M�Ĵ����Ķ�ʱ��3����

#define TIMER3_SET_REG_HL(value)	do{T3L=(unsigned char)(value);T3H=(unsigned char)(value>>8);}while(0)//���ö�ʱ��3�ļ���ֵ
#define TIMER3_GET_REG_HL			((((unsigned int)T3H)<<8)|(unsigned int)T3L)//��ȡ��ʱ��3�ļ���ֵ

#define TIMER3_SET_REG_H8(value)	do{T3H=(unsigned char)(value);}while(0)		//���ö�ʱ��3�ļ���ֵ�ĸ�8λ
#define TIMER3_GET_REG_H8			(T3H)										//��ȡ��ʱ��3�ļ���ֵ�ĸ�8λ

#define TIMER3_SET_REG_L8(value)	do{T3L=(unsigned char)(value);}while(0)		//���ö�ʱ��3�ļ���ֵ�ĵ�8λ
#define TIMER3_GET_REG_L8			(T3L)
//-------------���ܶ���------------//
#define TIMER3_IT_NUM			interrupt 19//��ʱ��3���жϷ����
/*###############################��ʱ��4################################*/
//-------------����ָ��------------//
#define TIMER4_ON					do{T4T3M|= T4R;}while(0) //�򿪶�ʱ��4
#define TIMER4_OFF					do{T4T3M&=~T4R;}while(0) //�رն�ʱ��4

#define TIMER4_IT_ENABLE			do{IE2  |= ET4;}while(0) //�򿪶�ʱ��4�ж�
#define TIMER4_IT_DISABLE			do{IE2  &=~ET4;}while(0) //�رն�ʱ��4�ж�

#define	TIMER4_OUT_ON				do{T4T3M|= T4CLKO;}while(0)//����ʱ��4��ʱ�����
#define	TIMER4_OUT_OFF				do{T4T3M&=~T4CLKO;}while(0)//�ض�ʱ��4��ʱ�����

#define TIMER4_SET_MODE_COUNT		do{T4T3M|= T4_CT;}while(0) //�趨��ʱ��4Ϊ������
#define TIMER4_SET_MODE_TIMER		do{T4T3M&=~T4_CT;}while(0) //�趨��ʱ��4Ϊ��ʱ��

#define TIMER4_SET_MODE_1T			do{T4T3M|= T4x12;}while(0) //�趨��ʱ��4Ϊ1Tģʽ
#define TIMER4_SET_MODE_12T			do{T4T3M&=~T4x12;}while(0) //�趨��ʱ��4Ϊ12Tģʽ

#define TIMER4_IT_CLS				do{AUXINTIF&=~T4IF;}while(0)//�嶨ʱ��4�жϱ�־
//-------------�Ĵ�����ȡ----------//
#define	TIMER4_SET_REG_T4T3M(value)	do{T4T3M=((T4T3M&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//����T4T3M�Ĵ����Ķ�ʱ��4����
#define	TIMER4_GET_REG_T4T3M		(T4T3M&0xF0)//��ȡT4T3M�Ĵ����Ķ�ʱ��4����

#define TIMER4_SET_REG_HL(value)	do{T4L=(unsigned char)(value);T4H=(unsigned char)(value>>8);}while(0)//���ö�ʱ��4�ļ���ֵ
#define TIMER4_GET_REG_HL			((((unsigned int)T4H)<<8)|(unsigned int)T4L)//��ȡ��ʱ��4�ļ���ֵ

#define TIMER4_SET_REG_H8(value)	do{T4H=(unsigned char)(value);}while(0)		//���ö�ʱ��4�ļ���ֵ�ĸ�8λ
#define TIMER4_GET_REG_H8			(T4H)										//��ȡ��ʱ��4�ļ���ֵ�ĸ�8λ

#define TIMER4_SET_REG_L8(value)	do{T4L=(unsigned char)(value);}while(0)		//���ö�ʱ��4�ļ���ֵ�ĵ�8λ
#define TIMER4_GET_REG_L8			(T4L)
//-------------���ܶ���------------//
#define TIMER4_IT_NUM				interrupt 20//��ʱ��4���жϷ����
/*-------------------------�������⹦�ܼĴ���----------------------------*/
/*################################����1#################################*/
sfr		SCON						=0x98;
sbit	SM0							=SCON^7;
sbit	SM1							=SCON^6;
sbit	SM2							=SCON^5;
sbit	REN							=SCON^4;
sbit	TB8							=SCON^3;
sbit	RB8							=SCON^2;
sbit	TI							=SCON^1;
sbit	RI							=SCON^0;
sfr		SBUF						=0x99;
sfr		SADDR						=0xA9;
sfr		SADEN						=0xB9;
//-------------����ָ��------------//
#define UART1_IT_ENABLE				do{ES=1;}while(0)	//�򿪴���1�ж�
#define UART1_IT_DISABLE			do{ES=0;}while(0)	//�رմ���1�ж�

#define UART1_TI_CLR				do{TI=0;}while(0)	//�������1�ķ��ͱ�־λ
#define UART1_GET_TI_FLAG			(TI)				//��ȡ����1�ķ��ͱ�־λ

#define UART1_RI_CLR				do{RI=0;}while(0)	//�������1�Ľ��ܱ�־λ
#define UART1_GET_RI_FLAG			(RI)				//��ȡ����1�Ľ��ܱ�־λ

#define UART1_SET_TXD_BYTE9_0		do{TB8=0;TB8=0;}while(0)	//���ô���1���͵ĵ�9λΪ0
#define UART1_SET_TXD_BYTE9_1		do{TB8=1;TB8=1;}while(0)	//���ô���1���͵ĵ�9λΪ1

#define UART1_GET_RXD_BYTE9			(RB8)						//��ȡ����1���յĵ�9λ 

#define UART1_SET_PIN(value)		do{P_SW1=((P_SW1&(~0xC0))|((unsigned char)(value)&0xC0));}while(0)//���ô���1���������

#define UART1_SET_BAUD_1			do{PCON&=~SMOD;}while(0)//���ò����ʲ�����
#define UART1_SET_BAUD_2			do{PCON|= SMOD;}while(0)//���ò����ʶ�����

#define	UART1_SET_CLK_TIMER1		do{AUXR&=~S1ST2;}while(0)//���ô���1��ʱ���ɶ�ʱ��1����
#define	UART1_SET_CLK_TIMER2		do{AUXR|= S1ST2;}while(0)//���ô���1��ʱ���ɶ�ʱ��2����

#define UART1_SET_RXD_ENABLE		do{REN=1;}while(0)	//����1�Ľ��ܹ��ܿ���
#define UART1_SET_RXD_DISABLE		do{REN=0;}while(0)	//����1�Ľ��ܹ��ܹر�

#define UART1_SET_MUX_ENABLE		do{SM2=1;}while(0)	//����1�Ķ��ͨ�ſ���
#define UART1_SET_MUX_DISABLE		do{SM2=0;}while(0)	//����1�Ķ��ͨ�Źر�

#define UART1_SET_MODE_S_8			do{SCON=(SCON&(~0xC0))|0x00;}while(0)//����1�Ĺ���ģʽΪͬ��ģʽ
#define UART1_SET_MODE_A_8_BAUD		do{SCON=(SCON&(~0xC0))|0x40;}while(0)//����1�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART1_SET_MODE_A_9			do{SCON=(SCON&(~0xC0))|0x80;}while(0)//����1�Ĺ���ģʽΪ�첽9λģʽ
#define UART1_SET_MODE_A_9_BAUD		do{SCON=(SCON&(~0xC0))|0xC0;}while(0)//����1�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
//-------------�Ĵ�����ȡ----------//
#define UART1_SET_REG_SADDR(value)	do{SADDR=((unsigned char)(value));}while(0)	//���ô���1�ĵ�ַ
#define UART1_GET_REG_SADDR			(SADDR)										//��ȡ����1�ĵ�ַ

#define UART1_SET_REG_SADEN(value)	do{SADEN=((unsigned char)(value));}while(0)	//���ô���1�ĵ�ַ����
#define UART1_GET_REG_SADEN			(SADEN)										//��ȡ����1�ĵ�ַ����

#define UART1_SET_REG_SBUF(value)	do{SBUF =((unsigned char)(value));}while(0)	//���ô���1Ҫ���͵�����
#define UART1_GET_REG_SBUF			(SBUF)										//��ȡ����1���յ�������

#define UART1_SET_REG_SCON(value)	do{SCON =((unsigned char)(value));}while(0)	//����SCON�Ĵ���
#define UART1_GET_REG_SCON			(SCON)										//��ȡSCON�Ĵ���

#define UART1_SET_REG_PCON(value)	do{PCON =((PCON &(~0xC0))|((unsigned char)(value)&0xC0));}while(0)//����PCON�Ĵ����Ĵ���1����
#define UART1_GET_REG_PCON			(PCON&0xC0)									//��ȡPCON�Ĵ����Ĵ���1����

#define UART1_SET_REG_AUXR(value)	do{AUXR =((AUXR &(~0x21))|((unsigned char)(value)&0x21));}while(0)//����AUXR�Ĵ����Ĵ���1����
#define UART1_GET_REG_AUXR			(AUXR&0x21)									//��ȡAUXR�Ĵ����Ĵ���1����
//-------------���ܶ���------------//
#define UART1_IT_NUM				interrupt 4//����1�жϺ�
/*################################����2#################################*/
sfr		S2CON						=0x9A;
#define	S2SM0						0x80
#define	S2ST2						0x40
#define	S2SM2						0x20
#define	S2REN						0x10
#define	S2TB8						0x08
#define	S2RB8						0x04
#define	S2TI						0x02
#define	S2RI						0x01
sfr		S2BUF						=0x9B;
//-------------����ָ��------------//
#define	UART2_IT_ENABLE				do{IE2|= ES2;}while(0)//�򿪴���2�ж�
#define	UART2_IT_DISABLE			do{IE2&=~ES2;}while(0)//�رմ���2�ж�

#define UART2_TI_CLR				do{S2CON&=~S2TI;}while(0)	//�������2�ķ��ͱ�־λ
#define UART2_GET_TI_FLAG			(S2CON&S2TI)				//��ȡ����2�ķ��ͱ�־λ

#define UART2_RI_CLR				do{S2CON&=~S2RI;}while(0)	//�������2�Ľ��ܱ�־λ
#define UART2_GET_RI_FLAG			(S2CON&S2RI)				//��ȡ����2�Ľ��ܱ�־λ

#define UART2_SET_TXD_BYTE9_0		do{S2CON&=~S2TB8;S2CON&=~S2TB8;}while(0)	//���ô���2���͵ĵ�9λΪ0
#define UART2_SET_TXD_BYTE9_1		do{S2CON|= S2TB8;S2CON|= S2TB8;}while(0)	//���ô���2���͵ĵ�9λΪ1

#define UART2_GET_RXD_BYTE9			(S2CON&S2RB8)								//��ȡ����2���յĵ�9λ 

#define UART2_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x01))|((unsigned char)(value)&0x01));}while(0)//���ô���2���������

#define UART2_SET_RXD_ENABLE		do{S2CON|= S2REN;}while(0)	//����2�Ľ��ܹ��ܿ���
#define UART2_SET_RXD_DISABLE		do{S2CON&=~S2REN;}while(0)	//����2�Ľ��ܹ��ܹر�

#define UART2_SET_MUX_ENABLE		do{S2CON|= S2SM2;}while(0)	//����2�Ķ��ͨ�ſ���
#define UART2_SET_MUX_DISABLE		do{S2CON&=~S2SM2;}while(0)	//����2�Ķ��ͨ�Źر�

#define UART2_SET_MODE_A_8_BAUD		do{S2CON&=~S2SM0;}while(0)//����2�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART2_SET_MODE_A_9_BAUD		do{S2CON|= S2SM0;}while(0)//����2�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
//-------------�Ĵ�����ȡ----------//
#define UART2_SET_REG_S2BUF(value)	do{S2BUF =((unsigned char)(value));}while(0)//���ô���2Ҫ���͵�����
#define UART2_GET_REG_S2BUF			(S2BUF)										//��ȡ����2���յ�������

#define UART2_SET_REG_S2CON(value)	do{S2CON =((unsigned char)(value));}while(0)//����S2CON�Ĵ���
#define UART2_GET_REG_S2CON			(S2CON)										//��ȡS2CON�Ĵ���
//-------------���ܶ���------------//
#define UART2_IT_NUM				interrupt 8//����2�жϺ�
/*################################����3#################################*/
sfr		S3CON						=0xAC;
#define	S3SM0						0x80
#define	S3ST3						0x40
#define	S3SM2						0x20
#define	S3REN						0x10
#define	S3TB8						0x08
#define	S3RB8						0x04
#define	S3TI						0x02
#define	S3RI						0x01
sfr		S3BUF						=0xAD;
//-------------����ָ��------------//
#define	UART3_IT_ENABLE				do{IE2|= ES3;}while(0)//�򿪴���3�ж�
#define	UART3_IT_DISABLE			do{IE2&=~ES3;}while(0)//�رմ���3�ж�

#define UART3_TI_CLR				do{S3CON&=~S3TI;}while(0)	//�������3�ķ��ͱ�־λ
#define UART3_GET_TI_FLAG			(S3CON&S3TI)				//��ȡ����3�ķ��ͱ�־λ

#define UART3_RI_CLR				do{S3CON&=~S3RI;}while(0)	//�������3�Ľ��ܱ�־λ
#define UART3_GET_RI_FLAG			(S3CON&S3RI)				//��ȡ����3�Ľ��ܱ�־λ

#define UART3_SET_TXD_BYTE9_0		do{S3CON&=~S3TB8;S3CON&=~S3TB8;}while(0)	//���ô���3���͵ĵ�9λΪ0
#define UART3_SET_TXD_BYTE9_1		do{S3CON|= S3TB8;S3CON|= S3TB8;}while(0)	//���ô���3���͵ĵ�9λΪ1

#define UART3_GET_RXD_BYTE9			(S3CON&S3RB8)								//��ȡ����3���յĵ�9λ 

#define UART3_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x02))|((unsigned char)(value)&0x02));}while(0)//���ô���3���������

#define	UART3_SET_CLK_TIMER2		do{S3CON&=~S3ST3;}while(0)//���ô���3��ʱ���ɶ�ʱ��2����
#define	UART3_SET_CLK_TIMER3		do{S3CON|= S3ST3;}while(0)//���ô���3��ʱ���ɶ�ʱ��3����

#define UART3_SET_RXD_ENABLE		do{S3CON|= S3REN;}while(0)	//����3�Ľ��ܹ��ܿ���
#define UART3_SET_RXD_DISABLE		do{S3CON&=~S3REN;}while(0)	//����3�Ľ��ܹ��ܹر�

#define UART3_SET_MUX_ENABLE		do{S3CON|= S3SM2;}while(0)	//����3�Ķ��ͨ�ſ���
#define UART3_SET_MUX_DISABLE		do{S3CON&=~S3SM2;}while(0)	//����3�Ķ��ͨ�Źر�

#define UART3_SET_MODE_A_8_BAUD		do{S3CON&=~S3SM0;}while(0)//����3�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART3_SET_MODE_A_9_BAUD		do{S3CON|= S3SM0;}while(0)//����3�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
//-------------�Ĵ�����ȡ----------//
#define UART3_SET_REG_S3BUF(value)	do{S3BUF =((unsigned char)(value));}while(0)//���ô���3Ҫ���͵�����
#define UART3_GET_REG_S3BUF			(S3BUF)										//��ȡ����3���յ�������

#define UART3_SET_REG_S3CON(value)	do{S3CON =((unsigned char)(value));}while(0)//����S3CON�Ĵ���
#define UART3_GET_REG_S3CON			(S3CON)										//��ȡS3CON�Ĵ���
//-------------���ܶ���------------//
#define UART3_IT_NUM				interrupt 17//����3�жϺ�
/*################################����4#################################*/
sfr		S4CON						=0x84;
#define	S4SM0						0x80
#define	S4ST4						0x40
#define	S4SM2						0x20
#define	S4REN						0x10
#define	S4TB8						0x08
#define	S4RB8						0x04
#define	S4TI						0x02
#define	S4RI						0x01
sfr		S4BUF						=0x85;
//-------------����ָ��------------//
#define	UART4_IT_ENABLE				do{IE2|= ES4;}while(0)//�򿪴���4�ж�
#define	UART4_IT_DISABLE			do{IE2&=~ES4;}while(0)//�رմ���4�ж�

#define UART4_TI_CLR				do{S4CON&=~S4TI;}while(0)	//�������4�ķ��ͱ�־λ
#define UART4_GET_TI_FLAG			(S4CON&S4TI)				//��ȡ����4�ķ��ͱ�־λ

#define UART4_RI_CLR				do{S4CON&=~S4RI;}while(0)	//�������4�Ľ��ܱ�־λ
#define UART4_GET_RI_FLAG			(S4CON&S4RI)				//��ȡ����4�Ľ��ܱ�־λ

#define UART4_SET_TXD_BYTE9_0		do{S4CON&=~S4TB8;S4CON&=~S4TB8;}while(0)	//���ô���4���͵ĵ�9λΪ0
#define UART4_SET_TXD_BYTE9_1		do{S4CON|= S4TB8;S4CON|= S4TB8;}while(0)	//���ô���4���͵ĵ�9λΪ1

#define UART4_GET_RXD_BYTE9			(S4CON&S4RB8)								//��ȡ����4���յĵ�9λ 

#define UART4_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x04))|((unsigned char)(value)&0x04));}while(0)//���ô���4���������

#define	UART4_SET_CLK_TIMER2		do{S4CON&=~S4ST4;}while(0)//���ô���4��ʱ���ɶ�ʱ��2����
#define	UART4_SET_CLK_TIMER4		do{S4CON|= S4ST4;}while(0)//���ô���4��ʱ���ɶ�ʱ��4����

#define UART4_SET_RXD_ENABLE		do{S4CON|= S4REN;}while(0)	//����4�Ľ��ܹ��ܿ���
#define UART4_SET_RXD_DISABLE		do{S4CON&=~S4REN;}while(0)	//����4�Ľ��ܹ��ܹر�

#define UART4_SET_MUX_ENABLE		do{S4CON|= S4SM2;}while(0)	//����4�Ķ��ͨ�ſ���
#define UART4_SET_MUX_DISABLE		do{S4CON&=~S4SM2;}while(0)	//����4�Ķ��ͨ�Źر�

#define UART4_SET_MODE_A_8_BAUD		do{S4CON&=~S4SM0;}while(0)//����4�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART4_SET_MODE_A_9_BAUD		do{S4CON|= S4SM0;}while(0)//����4�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
//-------------�Ĵ�����ȡ----------//
#define UART4_SET_REG_S4BUF(value)	do{S4BUF =((unsigned char)(value));}while(0)//���ô���4Ҫ���͵�����
#define UART4_GET_REG_S4BUF			(S4BUF)										//��ȡ����4���յ�������

#define UART4_SET_REG_S4CON(value)	do{S4CON =((unsigned char)(value));}while(0)//����S4CON�Ĵ���
#define UART4_GET_REG_S4CON			(S4CON)										//��ȡS4CON�Ĵ���
//-------------���ܶ���------------//
#define UART4_IT_NUM				interrupt 18//����4�жϺ�
/*------------------------�Ƚ������⹦�ܼĴ���---------------------------*/
sfr     CMPCR1						=0xE6;//�Ƚ������ƼĴ���1
#define CMPEN						0x80//�Ƚ���ʹ��λ
#define CMPIF						0x40//�Ƚ����жϱ�־λ
#define PIE							0x20//�Ƚ����������ж�ʹ��λ
#define NIE							0x10//�Ƚ����½����ж�ʹ��λ
#define PIS							0x08//�Ƚ�������ѡ��λ
#define NIS							0x04//�Ƚ�������ѡ��λ
#define CMPOE						0x02//�Ƚ�������������λ
#define CMPRES						0x01//�Ƚ������
sfr     CMPCR2						=0xE7;//�Ƚ������ƼĴ���2
#define INVCMPO						0x80//�Ƚ�������������
#define DISFLT						0x40//ģ���˲����ܿ���
//-------------����ָ��------------//
#define	CMP_POWER_ON				do{CMPCR1|= CMPEN;}while(0)//�����Ƚ���
#define	CMP_POWER_OFF				do{CMPCR1&=~CMPEN;}while(0)//�رձȽ���

#define	CMP_IT_CLS					do{CMPCR1&=~CMPIF;}while(0)//����Ƚ����жϱ�־λ

#define	CMP_IT_POSITIVE_ENABLE		do{CMPCR1|= PIE;}while(0)//�����������ж�
#define	CMP_IT_POSITIVE_DISABLE		do{CMPCR1&=~PIE;}while(0)//�ر��������ж�

#define	CMP_IT_NEGATIVE_ENABLE		do{CMPCR1|= NIE;}while(0)//�����������ж�
#define	CMP_IT_NEGATIVE_DISABLE		do{CMPCR1&=~NIE;}while(0)//�ر��������ж�

#define	CMP_SET_POSITIVE_ADC		do{CMPCR1|= PIS;}while(0)//�Ƚ�����+��ΪADC�����
#define	CMP_SET_POSITIVE_P37		do{CMPCR1&=~PIS;}while(0)//�Ƚ�����+��ΪP3.7��

#define	CMP_SET_NEGATIVE_P36		do{CMPCR1|= NIS;}while(0)//�Ƚ�����-��ΪP3.6��
#define	CMP_SET_NEGATIVE_BGV		do{CMPCR1&=~NIS;}while(0)//�Ƚ�����-��Ϊ�ڲ�1.9V��ѹ

#define	CMP_SET_OUT_ENABLE			do{CMPCR1|= CMPOE;}while(0)//�����Ƚ���������
#define	CMP_SET_OUT_DISABLE			do{CMPCR1&=~CMPOE;}while(0)//�رձȽ���������

#define	CMP_GET_RESULT				(CMPCR1&CMPRES)//��ȡ�Ƚ������

#define	CMP_SET_OUT_NEGATIVE		do{CMPCR2|= INVCMPO;}while(0)//�Ƚ�������������
#define	CMP_SET_OUT_POSITIVE		do{CMPCR2&=~INVCMPO;}while(0)//�Ƚ�������������

#define	CMP_SET_ANALOG_FILTER_ENABLE	do{CMPCR2|= DISFLT;}while(0)//�����Ƚ���ģ���˲�
#define	CMP_SET_ANALOG_FILTER_DISABLE	do{CMPCR2&=~DISFLT;}while(0)//�رձȽ���ģ���˲�

#define	CMP_SET_DIGITAL_FILTER(value)	do{CMPCR2=((CMPCR2&(~0x3F))|((unsigned char)(value)&0x3F));}while(0)//���ñȽ��������˲�

#define CMP_SET_PIN(value)			do{P_SW2=((P_SW2&(~0x08))|((unsigned char)(value)&0x08));}while(0)//���ñȽ������������
//-------------�Ĵ�����ȡ----------//
#define	CMP_SET_REG_CMPCR1(value)	do{CMPCR1=(unsigned char)(value);}while(0)//����CMPCR1�Ĵ���
#define	CMP_GET_REG_CMPCR1			(CMPCR1)//��ȡCMPCR1�Ĵ���

#define	CMP_SET_REG_CMPCR2(value)	do{CMPCR2=(unsigned char)(value);}while(0)//����CMPCR2�Ĵ���
#define	CMP_GET_REG_CMPCR2			(CMPCR2)//��ȡCMPCR1�Ĵ���
//-------------���ܶ���------------//
#define CMP_IT_NUM					interrupt 21//�Ƚ����жϺ�
/*-------------------------MDU16���⹦�ܼĴ���---------------------------*/
#define	MD5MD4						(*(unsigned int  volatile xdata *)0xfcf4)//һ��������ų�����������������
#define	MD3MD2MD1MD0				(*(unsigned long volatile xdata *)0xfcf0)//һ���������32λ��������32λ�̡�����
#define	MD1MD0						(*(unsigned int  volatile xdata *)0xfcf2)//һ���������16λ��������16λ�̡�16λ��������
#define	ARCON						(*(unsigned char volatile xdata *)0xfcf6)//MDUģʽ���ƼĴ���
#define	OPCON						(*(unsigned char volatile xdata *)0xfcf7)//MDU�������ƼĴ���
#define	MDOV						0x40
#define	MDRST						0x02
#define	ENOP						0x01
//-------------����ָ��------------//
#define	MDU16_RESET					do{OPCON=MDRST;}while(0)//��λ�˳���Ԫ
#define	MDU16_START					do{OPCON=ENOP;}while(0)	//��ʼ����
#define	MDU16_GET_END_FLAG			(OPCON&ENOP)			//��ȡ���������־λ
#define	MDU16_GET_MDOV_FLAG			(OPCON&MDOV)			//��ȡ���������λ

#define	MDU16_SET_16MUL				do{ARCON=0x80;}while(0)	//16λ�˷�
#define	MDU16_SET_16DIV				do{ARCON=0xa0;}while(0)	//16λ����
#define	MDU16_SET_32DIV				do{ARCON=0xc0;}while(0)	//32λ����
//-------------�Ĵ�����ȡ----------//
#define	MDU16_SET_REG_ARCON(value)	do{ARCON=(unsigned char)(value);}while(0)//����ARCON�Ĵ���
#define	MDU16_GET_REG_ARCON			(ARCON)//��ȡARCON�Ĵ���

#define	MDU16_SET_REG_OPCON(value)	do{OPCON=(unsigned char)(value);}while(0)//����OPCON�Ĵ���
#define	MDU16_GET_REG_OPCON			(OPCON)//��ȡOPCON�Ĵ���
/*-------------------------IIC���⹦�ܼĴ���-----------------------------*/
#define	I2CCFG						(*(unsigned char volatile xdata *)0xfe80)//IIC���üĴ���
#define ENI2C						0x80//IIC��Դʹ��
#define MSSL						0x40//IIC���ӻ�ѡ��
#define	I2CMSCR						(*(unsigned char volatile xdata *)0xfe81)//IIC�������ƼĴ���
#define EMSI    				    0x80
#define	I2CMSST						(*(unsigned char volatile xdata *)0xfe82)//IIC����״̬�Ĵ���
#define MSBUSY						0x80//����ģʽʱIIC������״̬λ
#define MSIF						0x40//����ģʽʱ���ж�����λ
#define MSACKI						0x02//����ģʽʱ�����յ���ACK
#define MSACKO						0x01//����ģʽʱ��Ҫ���͵�ACK
#define	I2CMSAUX					(*(unsigned char volatile xdata *)0xfe88)//IIC�����������ƼĴ���
#define	WDTA						0x01//�Զ�����ackλ
#define I2CSLCR						(*(unsigned char volatile xdata *)0xfe83)//IIC�ӻ����ƼĴ���
#define ESTAI						0x40//�ӻ�ģʽʱ����START�ź��ж�����λ
#define ERXI						0x20//�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define ETXI						0x10//�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define ESTOI						0x08//�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define SLRST						0x01//��λ�ӻ�ģʽ
#define I2CSLST						(*(unsigned char volatile xdata *)0xfe84)//IIC�ӻ�״̬�Ĵ���
#define SLBUSY						0x80//�ӻ�ģʽʱIIC������״̬λ
#define STAIF						0x40//�ӻ�ģʽʱ����START�ź��ж�����λ
#define RXIF						0x20//�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define TXIF						0x10//�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define STOIF						0x08//�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define TXING						0x04
#define SLACKI						0x02//�ӻ�ģʽʱ���յ���ACK
#define SLACKO						0x01//�ӻ�ģʽʱ����Ҫ���͵�ACK
#define I2CSLADR					(*(unsigned char volatile xdata *)0xfe85)//IIC�ӻ���ַ�Ĵ���
#define I2CTXD						(*(unsigned char volatile xdata *)0xfe86)//IIC�������ݼĴ���
#define I2CRXD						(*(unsigned char volatile xdata *)0xfe87)//IIC�������ݼĴ���
//-------------����ָ��------------//
#define	IIC_POWER_ON				do{I2CCFG|= ENI2C;}while(0)//��IIC��Դ
#define	IIC_POWER_OFF				do{I2CCFG&=~ENI2C;}while(0)//�ر�IIC��Դ

#define	IIC_SET_MODE_MASTER			do{I2CCFG|= MSSL;}while(0)//����IICΪ����ģʽ
#define	IIC_SET_MODE_SLAVE			do{I2CCFG&=~MSSL;}while(0)//����IICΪ�ӻ�ģʽ

#define	IIC_SET_AUTOACK_ENABLE		do{I2CMSAUX|= WDTA;}while(0)//�����Զ�����ACK
#define	IIC_SET_AUTOACK_DISABLE		do{I2CMSAUX&=~WDTA;}while(0)//ȡ���Զ�����ACK

#define IIC_SET_SPEED(value)		do{I2CCFG=((I2CCFG&(~0x3F))|((unsigned char)(value)&0x3F));}while(0)//����IIC������ٶ�

#define	IIC_GET_IT_FLAG				(I2CMSST&MSIF)//��ȡIIC�жϱ�־λ
#define	IIC_IT_CLS					do{I2CMSST&=~MSIF;}while(0)//���IIC�жϱ�־λ

#define IIC_SET_PIN(value)			do{P_SW2=((P_SW2&(~0x30))|((unsigned char)(value)&0x30));}while(0)//����IIC���������
//-------------�Ĵ�����ȡ----------//
#define	IIC_SET_REG_CFG(value)		do{I2CCFG=(unsigned char)value;}while(0)//����IICCFG�Ĵ���
#define	IIC_GET_REG_CFG				(I2CCFG)//��ȡIICCFG�Ĵ���

#define	IIC_SET_REG_MSCR(value)		do{I2CMSCR=(unsigned char)value;}while(0)//����IICMSCR�Ĵ���
#define	IIC_GET_REG_MSCR			(I2CMSCR)//��ȡIICMSCR�Ĵ���

#define	IIC_SET_REG_MSST(value)		do{I2CMSST=(unsigned char)value;}while(0)//����I2CMSST�Ĵ���
#define	IIC_GET_REG_MSST			(I2CMSST)//��ȡI2CMSST�Ĵ���

#define	IIC_SET_REG_MSAUX(value)	do{I2CMSAUX=(unsigned char)value;}while(0)//����I2CMSAUX�Ĵ���
#define	IIC_GET_REG_MSAUX			(I2CMSAUX)//��ȡI2CMSAUX�Ĵ���
//-------------���ܶ���------------//
#define IIC_IT_NUM					interrupt 24//IIC�жϺ�
/*-------------------------IIC���⹦�ܼĴ���-----------------------------*/
sfr     IP      =   0xb8;  //�ж����ȼ����ƼĴ���
sbit    PPCA    =   IP^7;  //PCA�ж����ȼ�����λ���ͣ�
sbit    PLVD    =   IP^6;  //��ѹ����ж����ȼ�����λ���ͣ�
sbit    PADC    =   IP^5;  //ADC�ж����ȼ�����λ���ͣ�
sbit    PS      =   IP^4;  //����1�ж����ȼ�����λ���ͣ�
sbit    PT1     =   IP^3;  //��ʱ��1�ж����ȼ�����λ���ͣ�
sbit    PX1     =   IP^2;  //�ⲿ�ж�1�ж����ȼ�����λ���ͣ�
sbit    PT0     =   IP^1;  //��ʱ��0�ж����ȼ�����λ���ͣ�
sbit    PX0     =   IP^0;  //�ⲿ�ж�0�ж����ȼ�����λ���ͣ�
sfr     IP2     =   0xb5;  //�ж����ȼ����ƼĴ���2
#define PI2C        0x40   //IIC�ж����ȼ�����λ���ͣ�
#define PCMP        0x20   //�Ƚ����ж����ȼ�����λ���ͣ�
#define PX4         0x10   //�ⲿ�ж�4�ж����ȼ�����λ���ͣ�
#define PPWMFD      0x08
#define PPWM        0x04
#define PSPI        0x02   //SPI�ж����ȼ�����λ���ͣ�
#define PS2         0x01   //����2�ж����ȼ�����λ���ͣ�
sfr     IPH     =   0xb7;  //���ж����ȼ����ƼĴ���
#define PPCAH       0x80   //PCA�ж����ȼ�����λ���ߣ�
#define PLVDH       0x40   //��ѹ����ж����ȼ�����λ���ߣ�
#define PADCH       0x20   //ADC�ж����ȼ�����λ���ߣ�
#define PSH         0x10   //����1�ж����ȼ�����λ���ߣ�
#define PT1H        0x08   //��ʱ��1�ж����ȼ�����λ���ߣ�
#define PX1H        0x04   //�ⲿ�ж�1�ж����ȼ�����λ���ߣ�
#define PT0H        0x02   //��ʱ��0�ж����ȼ�����λ���ߣ�
#define PX0H        0x01   //�ⲿ�ж�0�ж����ȼ�����λ���ߣ�
sfr     IP2H    =   0xb6;  //���ж����ȼ����ƼĴ���2
#define PI2CH       0x40   //IIC�ж����ȼ�����λ���ߣ�
#define PCMPH       0x20   //�Ƚ����ж����ȼ�����λ���ߣ�
#define PX4H        0x10   //�ⲿ�ж�4�ж����ȼ�����λ���ߣ�
#define PPWMFDH     0x08
#define PPWMH       0x04
#define PSPIH       0x02   //SPI�ж����ȼ�����λ���ߣ�
#define PS2H        0x01   //����2�ж����ȼ�����λ���ߣ�
sfr     IP3     =   0xDF;
sfr     IP3H    =   0xEE;
//-------------����ָ��------------//
#define	IT_SET_EXTI0_PRIORITY_0		do{IPH&=~PX0H;IP&=~PX0H;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ0		
#define	IT_SET_EXTI0_PRIORITY_1		do{IPH&=~PX0H;IP|= PX0H;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ1		
#define	IT_SET_EXTI0_PRIORITY_2		do{IPH|= PX0H;IP&=~PX0H;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ2		
#define	IT_SET_EXTI0_PRIORITY_3		do{IPH|= PX0H;IP|= PX0H;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ3		

#define	IT_SET_TIMER0_PRIORITY_0	do{IPH&=~PT0H;IP&=~PT0H;}while(0)//���ö�ʱ��0�����ȼ�Ϊ0		
#define	IT_SET_TIMER0_PRIORITY_1	do{IPH&=~PT0H;IP|= PT0H;}while(0)//���ö�ʱ��0�����ȼ�Ϊ1		
#define	IT_SET_TIMER0_PRIORITY_2	do{IPH|= PT0H;IP&=~PT0H;}while(0)//���ö�ʱ��0�����ȼ�Ϊ2		
#define	IT_SET_TIMER0_PRIORITY_3	do{IPH|= PT0H;IP|= PT0H;}while(0)//���ö�ʱ��0�����ȼ�Ϊ3		

#define	IT_SET_EXTI1_PRIORITY_0		do{IPH&=~PX1H;IP&=~PX1H;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ0		
#define	IT_SET_EXTI1_PRIORITY_1		do{IPH&=~PX1H;IP|= PX1H;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ1		
#define	IT_SET_EXTI1_PRIORITY_2		do{IPH|= PX1H;IP&=~PX1H;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ2		
#define	IT_SET_EXTI1_PRIORITY_3		do{IPH|= PX1H;IP|= PX1H;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ3		

#define	IT_SET_TIMER1_PRIORITY_0	do{IPH&=~PT1H;IP&=~PT1H;}while(0)//���ö�ʱ��1�����ȼ�Ϊ0		
#define	IT_SET_TIMER1_PRIORITY_1	do{IPH&=~PT1H;IP|= PT1H;}while(0)//���ö�ʱ��1�����ȼ�Ϊ1		
#define	IT_SET_TIMER1_PRIORITY_2	do{IPH|= PT1H;IP&=~PT1H;}while(0)//���ö�ʱ��1�����ȼ�Ϊ2		
#define	IT_SET_TIMER1_PRIORITY_3	do{IPH|= PT1H;IP|= PT1H;}while(0)//���ö�ʱ��1�����ȼ�Ϊ3		

#define	IT_SET_UART1_PRIORITY_0		do{IPH&=~PSH;IP&=~PSH;}while(0)//���ô���1�����ȼ�Ϊ0		
#define	IT_SET_UART1_PRIORITY_1		do{IPH&=~PSH;IP|= PSH;}while(0)//���ô���1�����ȼ�Ϊ1		
#define	IT_SET_UART1_PRIORITY_2		do{IPH|= PSH;IP&=~PSH;}while(0)//���ô���1�����ȼ�Ϊ2		
#define	IT_SET_UART1_PRIORITY_3		do{IPH|= PSH;IP|= PSH;}while(0)//���ô���1�����ȼ�Ϊ3		

#define	IT_SET_ADC_PRIORITY_0		do{IPH&=~PADCH;IP&=~PADCH;}while(0)//����ADC�����ȼ�Ϊ0		
#define	IT_SET_ADC_PRIORITY_1		do{IPH&=~PADCH;IP|= PADCH;}while(0)//����ADC�����ȼ�Ϊ1		
#define	IT_SET_ADC_PRIORITY_2		do{IPH|= PADCH;IP&=~PADCH;}while(0)//����ADC�����ȼ�Ϊ2		
#define	IT_SET_ADC_PRIORITY_3		do{IPH|= PADCH;IP|= PADCH;}while(0)//����ADC�����ȼ�Ϊ3		

#define	IT_SET_LVD_PRIORITY_0		do{IPH&=~PLVDH;IP&=~PLVDH;}while(0)//����LVD�����ȼ�Ϊ0		
#define	IT_SET_LVD_PRIORITY_1		do{IPH&=~PLVDH;IP|= PLVDH;}while(0)//����LVD�����ȼ�Ϊ1		
#define	IT_SET_LVD_PRIORITY_2		do{IPH|= PLVDH;IP&=~PLVDH;}while(0)//����LVD�����ȼ�Ϊ2		
#define	IT_SET_LVD_PRIORITY_3		do{IPH|= PLVDH;IP|= PLVDH;}while(0)//����LVD�����ȼ�Ϊ3		

#define	IT_SET_PCA_PRIORITY_0		do{IPH&=~PPCAH;IP&=~PPCAH;}while(0)//����PCA�����ȼ�Ϊ0		
#define	IT_SET_PCA_PRIORITY_1		do{IPH&=~PPCAH;IP|= PPCAH;}while(0)//����PCA�����ȼ�Ϊ1		
#define	IT_SET_PCA_PRIORITY_2		do{IPH|= PPCAH;IP&=~PPCAH;}while(0)//����PCA�����ȼ�Ϊ2		
#define	IT_SET_PCA_PRIORITY_3		do{IPH|= PPCAH;IP|= PPCAH;}while(0)//����PCA�����ȼ�Ϊ3		

#define	IT_SET_UART2_PRIORITY_0		do{IP2H&=~PS2H;IP2&=~PS2H;}while(0)//���ô���2�����ȼ�Ϊ0		
#define	IT_SET_UART2_PRIORITY_1		do{IP2H&=~PS2H;IP2|= PS2H;}while(0)//���ô���2�����ȼ�Ϊ1		
#define	IT_SET_UART2_PRIORITY_2		do{IP2H|= PS2H;IP2&=~PS2H;}while(0)//���ô���2�����ȼ�Ϊ2		
#define	IT_SET_UART2_PRIORITY_3		do{IP2H|= PS2H;IP2|= PS2H;}while(0)//���ô���2�����ȼ�Ϊ3		

#define	IT_SET_SPI_PRIORITY_0		do{IP2H&=~PSPIH;IP2&=~PSPIH;}while(0)//����SPI�����ȼ�Ϊ0		
#define	IT_SET_SPI_PRIORITY_1		do{IP2H&=~PSPIH;IP2|= PSPIH;}while(0)//����SPI�����ȼ�Ϊ1		
#define	IT_SET_SPI_PRIORITY_2		do{IP2H|= PSPIH;IP2&=~PSPIH;}while(0)//����SPI�����ȼ�Ϊ2		
#define	IT_SET_SPI_PRIORITY_3		do{IP2H|= PSPIH;IP2|= PSPIH;}while(0)//����SPI�����ȼ�Ϊ3		

#define	IT_SET_PWM_PRIORITY_0		do{IP2H&=~PPWMH;IP2&=~PPWMH;}while(0)//����PWM�����ȼ�Ϊ0		
#define	IT_SET_PWM_PRIORITY_1		do{IP2H&=~PPWMH;IP2|= PPWMH;}while(0)//����PWM�����ȼ�Ϊ1		
#define	IT_SET_PWM_PRIORITY_2		do{IP2H|= PPWMH;IP2&=~PPWMH;}while(0)//����PWM�����ȼ�Ϊ2		
#define	IT_SET_PWM_PRIORITY_3		do{IP2H|= PPWMH;IP2|= PPWMH;}while(0)//����PWM�����ȼ�Ϊ3		

#define	IT_SET_PWMFD_PRIORITY_0		do{IP2H&=~PPWMFDH;IP2&=~PPWMFDH;}while(0)//����PWMFD�����ȼ�Ϊ0		
#define	IT_SET_PWMFD_PRIORITY_1		do{IP2H&=~PPWMFDH;IP2|= PPWMFDH;}while(0)//����PWMFD�����ȼ�Ϊ1		
#define	IT_SET_PWMFD_PRIORITY_2		do{IP2H|= PPWMFDH;IP2&=~PPWMFDH;}while(0)//����PWMFD�����ȼ�Ϊ2		
#define	IT_SET_PWMFD_PRIORITY_3		do{IP2H|= PPWMFDH;IP2|= PPWMFDH;}while(0)//����PWMFD�����ȼ�Ϊ3		

#define	IT_SET_EXTI4_PRIORITY_0		do{IP2H&=~PX4H;IP2&=~PX4H;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ0		
#define	IT_SET_EXTI4_PRIORITY_1		do{IP2H&=~PX4H;IP2|= PX4H;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ1		
#define	IT_SET_EXTI4_PRIORITY_2		do{IP2H|= PX4H;IP2&=~PX4H;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ2		
#define	IT_SET_EXTI4_PRIORITY_3		do{IP2H|= PX4H;IP2|= PX4H;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ3		

#define	IT_SET_CMP_PRIORITY_0		do{IP2H&=~PCMPH;IP2&=~PCMPH;}while(0)//���ñȽ��������ȼ�Ϊ0		
#define	IT_SET_CMP_PRIORITY_1		do{IP2H&=~PCMPH;IP2|= PCMPH;}while(0)//���ñȽ��������ȼ�Ϊ1		
#define	IT_SET_CMP_PRIORITY_2		do{IP2H|= PCMPH;IP2&=~PCMPH;}while(0)//���ñȽ��������ȼ�Ϊ2		
#define	IT_SET_CMP_PRIORITY_3		do{IP2H|= PCMPH;IP2|= PCMPH;}while(0)//���ñȽ��������ȼ�Ϊ3		

#define	IT_SET_IIC_PRIORITY_0		do{IP2H&=~PI2CH;IP2&=~PI2CH;}while(0)//����IIC�����ȼ�Ϊ0		
#define	IT_SET_IIC_PRIORITY_1		do{IP2H&=~PI2CH;IP2|= PI2CH;}while(0)//����IIC�����ȼ�Ϊ1		
#define	IT_SET_IIC_PRIORITY_2		do{IP2H|= PI2CH;IP2&=~PI2CH;}while(0)//����IIC�����ȼ�Ϊ2		
#define	IT_SET_IIC_PRIORITY_3		do{IP2H|= PI2CH;IP2|= PI2CH;}while(0)//����IIC�����ȼ�Ϊ3		
/*-------------------------PCA/PWM���⹦�ܼĴ���-------------------------*/
sfr CCON        =   0xD8;	//PCA���ƼĴ���
sbit CF         =   CCON^7;	
sbit CR         =   CCON^6;
sbit CCF3       =   CCON^3;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xD9;	//PCAģʽ�Ĵ���
#define CIDL        0x80	//����ģʽ���Ƿ�ֹͣPCA����
#define ECF         0x01	//PCA����������ж�����λ
sfr CL          =   0xE9;	//PCA���������ֽ�
sfr CH          =   0xF9;	//PCA���������ֽ�
//-------------����ָ��------------//
#define	PCA_POWER_ON				do{CR=1;}while(0)//��PCAģ��
#define	PCA_POWER_OFF				do{CR=0;}while(0)//�ر�PCAģ��

#define	PCA_IT_ENABLE				do{CMOD|= ECF;}while(0)//��PCA������������ж�
#define	PCA_IT_DISABLE				do{CMOD&=~ECF;}while(0)//�ر�PCA������������ж�

#define	PCA_GET_IT_FLAG				(CF)//��ȡPCA����������жϱ�־λ
#define	PCA_IT_CLS					do{CF=0;}while(0)//���PCA����������жϱ�־λ

#define	PCA0_GET_IT_FLAG			(CCF0)//��ȡPCA0�����жϱ�־λ
#define	PCA0_IT_CLS					do{CCF0=0;}while(0)//���PCA0�����жϱ�־λ

#define	PCA1_GET_IT_FLAG			(CCF1)//��ȡPCA1�����жϱ�־λ
#define	PCA1_IT_CLS					do{CCF1=0;}while(0)//���PCA1�����жϱ�־λ

#define	PCA2_GET_IT_FLAG			(CCF2)//��ȡPCA2�����жϱ�־λ
#define	PCA2_IT_CLS					do{CCF2=0;}while(0)//���PCA2�����жϱ�־λ

#define	PCA3_GET_IT_FLAG			(CCF3)//��ȡPCA3�����жϱ�־λ
#define	PCA3_IT_CLS					do{CCF3=0;}while(0)//���PCA3�����жϱ�־λ

#define PCA_SET_IDLE_ENABLE			do{CMOD&=~CIDL;}while(0)//PCA�ڿ���ģʽ�¼�������
#define PCA_SET_IDLE_DISABLE		do{CMOD|= CIDL;}while(0)//PCA�ڿ���ģʽ��ֹͣ����

#define PCA_SET_CPS(value)			do{CMOD=((CMOD&(~0x0E))|((unsigned char)(value)&0x0E));}while(0)//����PCA����������Դ

#define PCA_SET_PIN(value)			do{P_SW1=((P_SW1&(~0x30))|((unsigned char)(value)&0x30));}while(0)//����PCA���������
//-------------�Ĵ�����ȡ----------//
#define	PCA_SET_REG_CCON(value)		do{CCON=(unsigned char)value;}while(0)//����CCON�Ĵ���
#define	PCA_GET_REG_CCON			(CCON)//��ȡCCON�Ĵ���

#define	PCA_SET_REG_CMOD(value)		do{CMOD=(unsigned char)value;}while(0)//����CMOD�Ĵ���
#define	PCA_GET_REG_CMOD			(CMOD)//��ȡCMOD�Ĵ���

#define	PCA_SET_REG_CL(value)		do{CL=(unsigned char)value;}while(0)//����CL�Ĵ���
#define	PCA_GET_REG_CL				(CL)//��ȡCL�Ĵ���

#define	PCA_SET_REG_CH(value)		do{CH=(unsigned char)value;}while(0)//����CH�Ĵ���
#define	PCA_GET_REG_CH				(CH)//��ȡCH�Ĵ���

#define PCA_SET_REG_CHL(value)		do{CL=(unsigned char)(value);CH=(unsigned char)(value>>8);}while(0)//����PCA�ļ���ֵ
#define PCA_GET_REG_CHL				((((unsigned int)CH)<<8)|(unsigned int)CL)//��ȡPCA�ļ���ֵ
//-------------���ܶ���------------//
#define PCA_IT_NUM					interrupt 7//PCA�жϺ�
/*################################PCA0#################################*/
sfr 	CCAPM0						=0xDA;	//PCAģ��0ģʽ���ƼĴ���
#define ECOM0						0x40	//����PCAģ��0�ıȽϹ���
#define CCAPP0						0x20	//����PCAģ��0���������ز���
#define CCAPN0						0x10	//����PCAģ��0�����½��ز���
#define MAT0						0x08	//����PCAģ��0��ƥ�书��
#define TOG0						0x04	//����PCAģ��0�ĸ��������������
#define PWM0						0x02	//����PCAģ��0����������������
#define ECCF0						0x01	//����PCAģ��0��ƥ��/�����ж�
sfr		CCAP0L						=0xEA;	//PCAģ��0���ֽ�
sfr		CCAP0H						=0xFA;	//PCAģ��0���ֽ�
sfr		PCA_PWM0					=0xF2;	//PCA0��PWMģʽ�Ĵ���
//-------------����ָ��------------//
#define	PCA0_SET_ECOM_ENABLE		do{CCAPM0|= ECOM0;}while(0)//��PCAģ��0�ıȽϹ���
#define	PCA0_SET_ECOM_DISABLE		do{CCAPM0&=~ECOM0;}while(0)//�ر�PCAģ��0�ıȽϹ���

#define	PCA0_SET_CCAPP_ENABLE		do{CCAPM0|= CCAPP0;}while(0)//��PCAģ��0�������ز�����
#define	PCA0_SET_CCAPP_DISABLE		do{CCAPM0&=~CCAPP0;}while(0)//�ر�PCAģ��0�������ز�����

#define	PCA0_SET_CCAPN_ENABLE		do{CCAPM0|= CCAPN0;}while(0)//��PCAģ��0���½��ز�����
#define	PCA0_SET_CCAPN_DISABLE		do{CCAPM0&=~CCAPN0;}while(0)//�ر�PCAģ��0���½��ز�����

#define	PCA0_SET_MAT_ENABLE			do{CCAPM0|= MAT0;}while(0)//��PCAģ��0��ƥ�书��
#define	PCA0_SET_MAT_DISABLE		do{CCAPM0&=~MAT0;}while(0)//�ر�PCAģ��0��ƥ�书��

#define	PCA0_SET_TOG_ENABLE			do{CCAPM0|= TOG0;}while(0)//��PCAģ��0�ĸ��������������
#define	PCA0_SET_TOG_DISABLE		do{CCAPM0&=~TOG0;}while(0)//�ر�PCAģ��0�ĸ��������������

#define	PCA0_SET_PWM_ENABLE			do{CCAPM0|= PWM0;}while(0)//��PCAģ��0����������������
#define	PCA0_SET_PWM_DISABLE		do{CCAPM0&=~PWM0;}while(0)//�ر�PCAģ��0����������������

#define	PCA0_SET_ECCF_ENABLE		do{CCAPM0|= ECCF0;}while(0)//��PCAģ��0��ƥ��/�����ж�
#define	PCA0_SET_ECCF_DISABLE		do{CCAPM0&=~ECCF0;}while(0)//�ر�PCAģ��0��ƥ��/�����ж�
//-------------�Ĵ�����ȡ----------//
#define	PCA_SET_REG_CCAPM0(value)	do{CCAPM0=(unsigned char)value;}while(0)//����CCAPM0�Ĵ���
#define	PCA_GET_REG_CCAPM0			(CCAPM0)//��ȡCCAPM0�Ĵ���

#define	PCA_SET_REG_CCAP0L(value)	do{CCAP0L=(unsigned char)value;}while(0)//����CCAP0L�Ĵ���
#define	PCA_GET_REG_CCAP0L			(CCAP0L)//��ȡCCAP0L�Ĵ���

#define	PCA_SET_REG_CCAP0H(value)	do{CCAP0H=(unsigned char)value;}while(0)//����CCAP0H�Ĵ���
#define	PCA_GET_REG_CCAP0H			(CCAP0H)//��ȡCCAP0H�Ĵ���

#define PCA_SET_REG_CCAP0HL(value)	do{CCAP0L=(unsigned char)(value);CCAP0H=(unsigned char)(value>>8);}while(0)//����PCA0�Ĳ���ֵ
#define PCA_GET_REG_CCAP0HL			((((unsigned int)CCAP0H)<<8)|(unsigned int)CCAP0L)//��ȡPCA0�Ĳ���ֵ

#define	PCA_SET_REG_PWM0(value)		do{PCA_PWM0=(unsigned char)value;}while(0)//����PCA_PWM0�Ĵ���
#define	PCA_GET_REG_PWM0			(PCA_PWM0)//��ȡPCA_PWM0�Ĵ���
/*################################PCA1#################################*/
sfr CCAPM1      =   0xdb;	//PCAģ��1ģʽ���ƼĴ���
#define ECOM1       0x40	//����PCAģ��1�ıȽϹ���
#define CCAPP1      0x20	//����PCAģ��1���������ز���
#define CCAPN1      0x10	//����PCAģ��1�����½��ز���
#define MAT1        0x08	//����PCAģ��1��ƥ�书��
#define TOG1        0x04	//����PCAģ��1�ĸ��������������
#define PWM1        0x02	//����PCAģ��1����������������
#define ECCF1       0x01	//����PCAģ��1��ƥ��/�����ж�
sfr CCAP1L      =   0xeb;	//PCAģ��1���ֽ�
sfr CCAP1H      =   0xfb;	//PCAģ��1���ֽ�
sfr PCA_PWM1    =   0xf3;	//PCA1��PWMģʽ�Ĵ���
//-------------����ָ��------------//
#define	PCA1_SET_ECOM_ENABLE		do{CCAPM1|= ECOM1;}while(0)//��PCAģ��1�ıȽϹ���
#define	PCA1_SET_ECOM_DISABLE		do{CCAPM1&=~ECOM1;}while(0)//�ر�PCAģ��1�ıȽϹ���

#define	PCA1_SET_CCAPP_ENABLE		do{CCAPM1|= CCAPP1;}while(0)//��PCAģ��1�������ز�����
#define	PCA1_SET_CCAPP_DISABLE		do{CCAPM1&=~CCAPP1;}while(0)//�ر�PCAģ��1�������ز�����

#define	PCA1_SET_CCAPN_ENABLE		do{CCAPM1|= CCAPN1;}while(0)//��PCAģ��1���½��ز�����
#define	PCA1_SET_CCAPN_DISABLE		do{CCAPM1&=~CCAPN1;}while(0)//�ر�PCAģ��1���½��ز�����

#define	PCA1_SET_MAT_ENABLE			do{CCAPM1|= MAT1;}while(0)//��PCAģ��1��ƥ�书��
#define	PCA1_SET_MAT_DISABLE		do{CCAPM1&=~MAT1;}while(0)//�ر�PCAģ��1��ƥ�书��

#define	PCA1_SET_TOG_ENABLE			do{CCAPM1|= TOG1;}while(0)//��PCAģ��1�ĸ��������������
#define	PCA1_SET_TOG_DISABLE		do{CCAPM1&=~TOG1;}while(0)//�ر�PCAģ��1�ĸ��������������

#define	PCA1_SET_PWM_ENABLE			do{CCAPM1|= PWM1;}while(0)//��PCAģ��1����������������
#define	PCA1_SET_PWM_DISABLE		do{CCAPM1&=~PWM1;}while(0)//�ر�PCAģ��1����������������

#define	PCA1_SET_ECCF_ENABLE		do{CCAPM1|= ECCF1;}while(0)//��PCAģ��1��ƥ��/�����ж�
#define	PCA1_SET_ECCF_DISABLE		do{CCAPM1&=~ECCF1;}while(0)//�ر�PCAģ��1��ƥ��/�����ж�
//-------------�Ĵ�����ȡ----------//
#define	PCA_SET_REG_CCAPM1(value)	do{CCAPM1=(unsigned char)value;}while(0)//����CCAPM1�Ĵ���
#define	PCA_GET_REG_CCAPM1			(CCAPM1)//��ȡCCAPM1�Ĵ���

#define	PCA_SET_REG_CCAP1L(value)	do{CCAP1L=(unsigned char)value;}while(0)//����CCAP1L�Ĵ���
#define	PCA_GET_REG_CCAP1L			(CCAP1L)//��ȡCCAP1L�Ĵ���

#define	PCA_SET_REG_CCAP1H(value)	do{CCAP1H=(unsigned char)value;}while(0)//����CCAP1H�Ĵ���
#define	PCA_GET_REG_CCAP1H			(CCAP1H)//��ȡCCAP1H�Ĵ���

#define PCA_SET_REG_CCAP1HL(value)	do{CCAP1L=(unsigned char)(value);CCAP1H=(unsigned char)(value>>8);}while(0)//����PCA1�Ĳ���ֵ
#define PCA_GET_REG_CCAP1HL			((((unsigned int)CCAP1H)<<8)|(unsigned int)CCAP1L)//��ȡPCA1�Ĳ���ֵ

#define	PCA_SET_REG_PWM1(value)		do{PCA_PWM1=(unsigned char)value;}while(0)//����PCA_PWM1�Ĵ���
#define	PCA_GET_REG_PWM1			(PCA_PWM1)//��ȡPCA_PWM1�Ĵ���
/*################################PCA2#################################*/
sfr CCAPM2      =   0xdc;	//PCAģ��2ģʽ���ƼĴ���
#define ECOM2       0x40	//����PCAģ��2�ıȽϹ���
#define CCAPP2      0x20	//����PCAģ��2���������ز���
#define CCAPN2      0x10	//����PCAģ��2�����½��ز���
#define MAT2        0x08	//����PCAģ��2��ƥ�书��
#define TOG2        0x04	//����PCAģ��2�ĸ��������������
#define PWM2        0x02	//����PCAģ��2����������������
#define ECCF2       0x01	//����PCAģ��2��ƥ��/�����ж�
sfr CCAP2L      =   0xec;	//PCAģ��2���ֽ�
sfr CCAP2H      =   0xfc;	//PCAģ��2���ֽ�
sfr PCA_PWM2    =   0xf4;	//PCA2��PWMģʽ�Ĵ���
//-------------����ָ��------------//
#define	PCA2_SET_ECOM_ENABLE		do{CCAPM2|= ECOM2;}while(0)//��PCAģ��2�ıȽϹ���
#define	PCA2_SET_ECOM_DISABLE		do{CCAPM2&=~ECOM2;}while(0)//�ر�PCAģ��2�ıȽϹ���

#define	PCA2_SET_CCAPP_ENABLE		do{CCAPM2|= CCAPP2;}while(0)//��PCAģ��2�������ز�����
#define	PCA2_SET_CCAPP_DISABLE		do{CCAPM2&=~CCAPP2;}while(0)//�ر�PCAģ��2�������ز�����

#define	PCA2_SET_CCAPN_ENABLE		do{CCAPM2|= CCAPN2;}while(0)//��PCAģ��2���½��ز�����
#define	PCA2_SET_CCAPN_DISABLE		do{CCAPM2&=~CCAPN2;}while(0)//�ر�PCAģ��2���½��ز�����

#define	PCA2_SET_MAT_ENABLE			do{CCAPM2|= MAT2;}while(0)//��PCAģ��2��ƥ�书��
#define	PCA2_SET_MAT_DISABLE		do{CCAPM2&=~MAT2;}while(0)//�ر�PCAģ��2��ƥ�书��

#define	PCA2_SET_TOG_ENABLE			do{CCAPM2|= TOG2;}while(0)//��PCAģ��2�ĸ��������������
#define	PCA2_SET_TOG_DISABLE		do{CCAPM2&=~TOG2;}while(0)//�ر�PCAģ��2�ĸ��������������

#define	PCA2_SET_PWM_ENABLE			do{CCAPM2|= PWM2;}while(0)//��PCAģ��2����������������
#define	PCA2_SET_PWM_DISABLE		do{CCAPM2&=~PWM2;}while(0)//�ر�PCAģ��2����������������

#define	PCA2_SET_ECCF_ENABLE		do{CCAPM2|= ECCF2;}while(0)//��PCAģ��2��ƥ��/�����ж�
#define	PCA2_SET_ECCF_DISABLE		do{CCAPM2&=~ECCF2;}while(0)//�ر�PCAģ��2��ƥ��/�����ж�
//-------------�Ĵ�����ȡ----------//
#define	PCA_SET_REG_CCAPM2(value)	do{CCAPM2=(unsigned char)value;}while(0)//����CCAPM2�Ĵ���
#define	PCA_GET_REG_CCAPM2			(CCAPM2)//��ȡCCAPM2�Ĵ���

#define	PCA_SET_REG_CCAP2L(value)	do{CCAP2L=(unsigned char)value;}while(0)//����CCAP2L�Ĵ���
#define	PCA_GET_REG_CCAP2L			(CCAP2L)//��ȡCCAP2L�Ĵ���

#define	PCA_SET_REG_CCAP2H(value)	do{CCAP2H=(unsigned char)value;}while(0)//����CCAP2H�Ĵ���
#define	PCA_GET_REG_CCAP2H			(CCAP2H)//��ȡCCAP2H�Ĵ���

#define PCA_SET_REG_CCAP2HL(value)	do{CCAP2L=(unsigned char)(value);CCAP2H=(unsigned char)(value>>8);}while(0)//����PCA2�Ĳ���ֵ
#define PCA_GET_REG_CCAP2HL			((((unsigned int)CCAP2H)<<8)|(unsigned int)CCAP2L)//��ȡPCA2�Ĳ���ֵ

#define	PCA_SET_REG_PWM2(value)		do{PCA_PWM2=(unsigned char)value;}while(0)//����PCA_PWM2�Ĵ���
#define	PCA_GET_REG_PWM2			(PCA_PWM2)//��ȡPCA_PWM2�Ĵ���
/*################################PCA3#################################*/
sfr CCAPM3      =   0xdd;	//PCAģ��3ģʽ���ƼĴ���
#define ECOM3       0x40	//����PCAģ��3�ıȽϹ���
#define CCAPP3      0x20	//����PCAģ��3���������ز���
#define CCAPN3      0x10	//����PCAģ��3�����½��ز���
#define MAT3        0x08	//����PCAģ��3��ƥ�书��
#define TOG3        0x04	//����PCAģ��3�ĸ��������������
#define PWM3        0x02	//����PCAģ��3����������������
#define ECCF3       0x01	//����PCAģ��3��ƥ��/�����ж�
sfr CCAP3L      =   0xed;	//PCAģ��3���ֽ�
sfr CCAP3H      =   0xfd;	//PCAģ��3���ֽ�
sfr PCA_PWM3    =   0xf5;	//PCA3��PWMģʽ�Ĵ���
//-------------����ָ��------------//
#define	PCA3_SET_ECOM_ENABLE		do{CCAPM3|= ECOM3;}while(0)//��PCAģ��3�ıȽϹ���
#define	PCA3_SET_ECOM_DISABLE		do{CCAPM3&=~ECOM3;}while(0)//�ر�PCAģ��3�ıȽϹ���

#define	PCA3_SET_CCAPP_ENABLE		do{CCAPM3|= CCAPP3;}while(0)//��PCAģ��3�������ز�����
#define	PCA3_SET_CCAPP_DISABLE		do{CCAPM3&=~CCAPP3;}while(0)//�ر�PCAģ��3�������ز�����

#define	PCA3_SET_CCAPN_ENABLE		do{CCAPM3|= CCAPN3;}while(0)//��PCAģ��3���½��ز�����
#define	PCA3_SET_CCAPN_DISABLE		do{CCAPM3&=~CCAPN3;}while(0)//�ر�PCAģ��3���½��ز�����

#define	PCA3_SET_MAT_ENABLE			do{CCAPM3|= MAT3;}while(0)//��PCAģ��3��ƥ�书��
#define	PCA3_SET_MAT_DISABLE		do{CCAPM3&=~MAT3;}while(0)//�ر�PCAģ��3��ƥ�书��

#define	PCA3_SET_TOG_ENABLE			do{CCAPM3|= TOG3;}while(0)//��PCAģ��3�ĸ��������������
#define	PCA3_SET_TOG_DISABLE		do{CCAPM3&=~TOG3;}while(0)//�ر�PCAģ��3�ĸ��������������

#define	PCA3_SET_PWM_ENABLE			do{CCAPM3|= PWM3;}while(0)//��PCAģ��3����������������
#define	PCA3_SET_PWM_DISABLE		do{CCAPM3&=~PWM3;}while(0)//�ر�PCAģ��3����������������

#define	PCA3_SET_ECCF_ENABLE		do{CCAPM3|= ECCF3;}while(0)//��PCAģ��3��ƥ��/�����ж�
#define	PCA3_SET_ECCF_DISABLE		do{CCAPM3&=~ECCF3;}while(0)//�ر�PCAģ��3��ƥ��/�����ж�
//-------------�Ĵ�����ȡ----------//
#define	PCA_SET_REG_CCAPM3(value)	do{CCAPM3=(unsigned char)value;}while(0)//����CCAPM3�Ĵ���
#define	PCA_GET_REG_CCAPM3			(CCAPM3)//��ȡCCAPM3�Ĵ���

#define	PCA_SET_REG_CCAP3L(value)	do{CCAP3L=(unsigned char)value;}while(0)//����CCAP3L�Ĵ���
#define	PCA_GET_REG_CCAP3L			(CCAP3L)//��ȡCCAP3L�Ĵ���

#define	PCA_SET_REG_CCAP3H(value)	do{CCAP3H=(unsigned char)value;}while(0)//����CCAP3H�Ĵ���
#define	PCA_GET_REG_CCAP3H			(CCAP3H)//��ȡCCAP3H�Ĵ���

#define PCA_SET_REG_CCAP3HL(value)	do{CCAP3L=(unsigned char)(value);CCAP3H=(unsigned char)(value>>8);}while(0)//����PCA3�Ĳ���ֵ
#define PCA_GET_REG_CCAP3HL			((((unsigned int)CCAP3H)<<8)|(unsigned int)CCAP3L)//��ȡPCA3�Ĳ���ֵ

#define	PCA_SET_REG_PWM3(value)		do{PCA_PWM3=(unsigned char)value;}while(0)//����PCA_PWM3�Ĵ���
#define	PCA_GET_REG_PWM3			(PCA_PWM3)//��ȡPCA_PWM3�Ĵ���















//do{}while(0)


#define	TOUCH_IT_ENABLE		do{IE2|= ETKSUI;}while(0)
#define	TOUCH_IT_DISABLE	do{IE2&=~ETKSUI;}while(0)
#define	USB_IT_ENABLE		do{IE2|= EUSB;}while(0)
#define	USB_IT_DISABLE		do{IE2&=~EUSB;}while(0)





#define	LVD_IT_ENABLE	do{ELVD=1;}while(0)
#define	LVD_IT_DISABLE	do{ELVD=0;}while(0)




#define     TM2PS       (*(unsigned char volatile xdata *)0xFEA2)
#define     TM3PS       (*(unsigned char volatile xdata *)0xFEA3)
#define     TM4PS       (*(unsigned char volatile xdata *)0xFEA4)



//��ͻ�Ĳ���
sfr         PWMSET      =           0xF1;
sfr         PWMCFG01    =           0xF6;
sfr         PWMCFG23    =           0xF7;
sfr         PWMCFG45    =           0xFE;



#define     PWM0C       (*(unsigned int  volatile xdata *)0xFF00)
#define     PWM0CH      (*(unsigned char volatile xdata *)0xFF00)
#define     PWM0CL      (*(unsigned char volatile xdata *)0xFF01)
#define     PWM0CKS     (*(unsigned char volatile xdata *)0xFF02)
#define     PWM0TADCH   (*(unsigned char volatile xdata *)0xFF03)
#define     PWM0TADCL   (*(unsigned char volatile xdata *)0xFF04)
#define     PWM0IF      (*(unsigned char volatile xdata *)0xFF05)
#define     PWM0FDCR    (*(unsigned char volatile xdata *)0xFF06)

#define     PWM00T1     (*(unsigned int  volatile xdata *)0xFF10)
#define     PWM00T1H    (*(unsigned char volatile xdata *)0xFF10)
#define     PWM00T1L    (*(unsigned char volatile xdata *)0xFF11)
#define     PWM00T2     (*(unsigned int  volatile xdata *)0xFF12)
#define     PWM00T2H    (*(unsigned char volatile xdata *)0xFF12)
#define     PWM00T2L    (*(unsigned char volatile xdata *)0xFF13)
#define     PWM00CR     (*(unsigned char volatile xdata *)0xFF14)
#define     PWM00HLD    (*(unsigned char volatile xdata *)0xFF15)

#define     PWM01T1     (*(unsigned int  volatile xdata *)0xFF18)
#define     PWM01T1H    (*(unsigned char volatile xdata *)0xFF18)
#define     PWM01T1L    (*(unsigned char volatile xdata *)0xFF19)
#define     PWM01T2     (*(unsigned int  volatile xdata *)0xFF1A)
#define     PWM01T2H    (*(unsigned char volatile xdata *)0xFF1A)
#define     PWM01T2L    (*(unsigned char volatile xdata *)0xFF1B)
#define     PWM01CR     (*(unsigned char volatile xdata *)0xFF1C)
#define     PWM01HLD    (*(unsigned char volatile xdata *)0xFF1D)

#define     PWM02T1     (*(unsigned int  volatile xdata *)0xFF20)
#define     PWM02T1H    (*(unsigned char volatile xdata *)0xFF20)
#define     PWM02T1L    (*(unsigned char volatile xdata *)0xFF21)
#define     PWM02T2     (*(unsigned int  volatile xdata *)0xFF22)
#define     PWM02T2H    (*(unsigned char volatile xdata *)0xFF22)
#define     PWM02T2L    (*(unsigned char volatile xdata *)0xFF23)
#define     PWM02CR     (*(unsigned char volatile xdata *)0xFF24)
#define     PWM02HLD    (*(unsigned char volatile xdata *)0xFF25)

#define     PWM03T1     (*(unsigned int  volatile xdata *)0xFF28)
#define     PWM03T1H    (*(unsigned char volatile xdata *)0xFF28)
#define     PWM03T1L    (*(unsigned char volatile xdata *)0xFF29)
#define     PWM03T2     (*(unsigned int  volatile xdata *)0xFF2A)
#define     PWM03T2H    (*(unsigned char volatile xdata *)0xFF2A)
#define     PWM03T2L    (*(unsigned char volatile xdata *)0xFF2B)
#define     PWM03CR     (*(unsigned char volatile xdata *)0xFF2C)
#define     PWM03HLD    (*(unsigned char volatile xdata *)0xFF2D)

#define     PWM04T1     (*(unsigned int  volatile xdata *)0xFF30)
#define     PWM04T1H    (*(unsigned char volatile xdata *)0xFF30)
#define     PWM04T1L    (*(unsigned char volatile xdata *)0xFF31)
#define     PWM04T2     (*(unsigned int  volatile xdata *)0xFF32)
#define     PWM04T2H    (*(unsigned char volatile xdata *)0xFF32)
#define     PWM04T2L    (*(unsigned char volatile xdata *)0xFF33)
#define     PWM04CR     (*(unsigned char volatile xdata *)0xFF34)
#define     PWM04HLD    (*(unsigned char volatile xdata *)0xFF35)

#define     PWM05T1     (*(unsigned int  volatile xdata *)0xFF38)
#define     PWM05T1H    (*(unsigned char volatile xdata *)0xFF38)
#define     PWM05T1L    (*(unsigned char volatile xdata *)0xFF39)
#define     PWM05T2     (*(unsigned int  volatile xdata *)0xFF3A)
#define     PWM05T2H    (*(unsigned char volatile xdata *)0xFF3A)
#define     PWM05T2L    (*(unsigned char volatile xdata *)0xFF3B)
#define     PWM05CR     (*(unsigned char volatile xdata *)0xFF3C)
#define     PWM05HLD    (*(unsigned char volatile xdata *)0xFF3D)

#define     PWM06T1     (*(unsigned int  volatile xdata *)0xFF40)
#define     PWM06T1H    (*(unsigned char volatile xdata *)0xFF40)
#define     PWM06T1L    (*(unsigned char volatile xdata *)0xFF41)
#define     PWM06T2     (*(unsigned int  volatile xdata *)0xFF42)
#define     PWM06T2H    (*(unsigned char volatile xdata *)0xFF42)
#define     PWM06T2L    (*(unsigned char volatile xdata *)0xFF43)
#define     PWM06CR     (*(unsigned char volatile xdata *)0xFF44)
#define     PWM06HLD    (*(unsigned char volatile xdata *)0xFF45)

#define     PWM07T1     (*(unsigned int  volatile xdata *)0xFF48)
#define     PWM07T1H    (*(unsigned char volatile xdata *)0xFF48)
#define     PWM07T1L    (*(unsigned char volatile xdata *)0xFF49)
#define     PWM07T2     (*(unsigned int  volatile xdata *)0xFF4A)
#define     PWM07T2H    (*(unsigned char volatile xdata *)0xFF4A)
#define     PWM07T2L    (*(unsigned char volatile xdata *)0xFF4B)
#define     PWM07CR     (*(unsigned char volatile xdata *)0xFF4C)
#define     PWM07HLD    (*(unsigned char volatile xdata *)0xFF4D)

#define     PWM1C       (*(unsigned int  volatile xdata *)0xFF50)
#define     PWM1CH      (*(unsigned char volatile xdata *)0xFF50)
#define     PWM1CL      (*(unsigned char volatile xdata *)0xFF51)
#define     PWM1CKS     (*(unsigned char volatile xdata *)0xFF52)
#define     PWM1IF      (*(unsigned char volatile xdata *)0xFF55)
#define     PWM1FDCR    (*(unsigned char volatile xdata *)0xFF56)

#define     PWM10T1     (*(unsigned int  volatile xdata *)0xFF60)
#define     PWM10T1H    (*(unsigned char volatile xdata *)0xFF60)
#define     PWM10T1L    (*(unsigned char volatile xdata *)0xFF61)
#define     PWM10T2     (*(unsigned int  volatile xdata *)0xFF62)
#define     PWM10T2H    (*(unsigned char volatile xdata *)0xFF62)
#define     PWM10T2L    (*(unsigned char volatile xdata *)0xFF63)
#define     PWM10CR     (*(unsigned char volatile xdata *)0xFF64)
#define     PWM10HLD    (*(unsigned char volatile xdata *)0xFF65)

#define     PWM11T1     (*(unsigned int  volatile xdata *)0xFF68)
#define     PWM11T1H    (*(unsigned char volatile xdata *)0xFF68)
#define     PWM11T1L    (*(unsigned char volatile xdata *)0xFF69)
#define     PWM11T2     (*(unsigned int  volatile xdata *)0xFF6A)
#define     PWM11T2H    (*(unsigned char volatile xdata *)0xFF6A)
#define     PWM11T2L    (*(unsigned char volatile xdata *)0xFF6B)
#define     PWM11CR     (*(unsigned char volatile xdata *)0xFF6C)
#define     PWM11HLD    (*(unsigned char volatile xdata *)0xFF6D)

#define     PWM12T1     (*(unsigned int  volatile xdata *)0xFF70)
#define     PWM12T1H    (*(unsigned char volatile xdata *)0xFF70)
#define     PWM12T1L    (*(unsigned char volatile xdata *)0xFF71)
#define     PWM12T2     (*(unsigned int  volatile xdata *)0xFF72)
#define     PWM12T2H    (*(unsigned char volatile xdata *)0xFF72)
#define     PWM12T2L    (*(unsigned char volatile xdata *)0xFF73)
#define     PWM12CR     (*(unsigned char volatile xdata *)0xFF74)
#define     PWM12HLD    (*(unsigned char volatile xdata *)0xFF75)

#define     PWM13T1     (*(unsigned int  volatile xdata *)0xFF78)
#define     PWM13T1H    (*(unsigned char volatile xdata *)0xFF78)
#define     PWM13T1L    (*(unsigned char volatile xdata *)0xFF79)
#define     PWM13T2     (*(unsigned int  volatile xdata *)0xFF7A)
#define     PWM13T2H    (*(unsigned char volatile xdata *)0xFF7A)
#define     PWM13T2L    (*(unsigned char volatile xdata *)0xFF7B)
#define     PWM13CR     (*(unsigned char volatile xdata *)0xFF7C)
#define     PWM13HLD    (*(unsigned char volatile xdata *)0xFF7D)

#define     PWM14T1     (*(unsigned int  volatile xdata *)0xFF80)
#define     PWM14T1H    (*(unsigned char volatile xdata *)0xFF80)
#define     PWM14T1L    (*(unsigned char volatile xdata *)0xFF81)
#define     PWM14T2     (*(unsigned int  volatile xdata *)0xFF82)
#define     PWM14T2H    (*(unsigned char volatile xdata *)0xFF82)
#define     PWM14T2L    (*(unsigned char volatile xdata *)0xFF83)
#define     PWM14CR     (*(unsigned char volatile xdata *)0xFF84)
#define     PWM14HLD    (*(unsigned char volatile xdata *)0xFF85)

#define     PWM15T1     (*(unsigned int  volatile xdata *)0xFF88)
#define     PWM15T1H    (*(unsigned char volatile xdata *)0xFF88)
#define     PWM15T1L    (*(unsigned char volatile xdata *)0xFF89)
#define     PWM15T2     (*(unsigned int  volatile xdata *)0xFF8A)
#define     PWM15T2H    (*(unsigned char volatile xdata *)0xFF8A)
#define     PWM15T2L    (*(unsigned char volatile xdata *)0xFF8B)
#define     PWM15CR     (*(unsigned char volatile xdata *)0xFF8C)
#define     PWM15HLD    (*(unsigned char volatile xdata *)0xFF8D)

#define     PWM16T1     (*(unsigned int  volatile xdata *)0xFF90)
#define     PWM16T1H    (*(unsigned char volatile xdata *)0xFF90)
#define     PWM16T1L    (*(unsigned char volatile xdata *)0xFF91)
#define     PWM16T2     (*(unsigned int  volatile xdata *)0xFF92)
#define     PWM16T2H    (*(unsigned char volatile xdata *)0xFF92)
#define     PWM16T2L    (*(unsigned char volatile xdata *)0xFF93)
#define     PWM16CR     (*(unsigned char volatile xdata *)0xFF94)
#define     PWM16HLD    (*(unsigned char volatile xdata *)0xFF95)

#define     PWM17T1     (*(unsigned int  volatile xdata *)0xFF98)
#define     PWM17T1H    (*(unsigned char volatile xdata *)0xFF98)
#define     PWM17T1L    (*(unsigned char volatile xdata *)0xFF99)
#define     PWM17T2     (*(unsigned int  volatile xdata *)0xFF9A)
#define     PWM17T2H    (*(unsigned char volatile xdata *)0xFF9A)
#define     PWM17T2L    (*(unsigned char volatile xdata *)0xFF9B)
#define     PWM17CR     (*(unsigned char volatile xdata *)0xFF9C)
#define     PWM17HLD    (*(unsigned char volatile xdata *)0xFF9D)

#define     PWM2C       (*(unsigned int  volatile xdata *)0xFFA0)
#define     PWM2CH      (*(unsigned char volatile xdata *)0xFFA0)
#define     PWM2CL      (*(unsigned char volatile xdata *)0xFFA1)
#define     PWM2CKS     (*(unsigned char volatile xdata *)0xFFA2)
#define     PWM2TADCH   (*(unsigned char volatile xdata *)0xFFA3)
#define     PWM2TADCL   (*(unsigned char volatile xdata *)0xFFA4)
#define     PWM2IF      (*(unsigned char volatile xdata *)0xFFA5)
#define     PWM2FDCR    (*(unsigned char volatile xdata *)0xFFA6)

#define     PWM20T1     (*(unsigned int  volatile xdata *)0xFFB0)
#define     PWM20T1H    (*(unsigned char volatile xdata *)0xFFB0)
#define     PWM20T1L    (*(unsigned char volatile xdata *)0xFFB1)
#define     PWM20T2     (*(unsigned int  volatile xdata *)0xFFB2)
#define     PWM20T2H    (*(unsigned char volatile xdata *)0xFFB2)
#define     PWM20T2L    (*(unsigned char volatile xdata *)0xFFB3)
#define     PWM20CR     (*(unsigned char volatile xdata *)0xFFB4)
#define     PWM20HLD    (*(unsigned char volatile xdata *)0xFFB5)

#define     PWM21T1     (*(unsigned int  volatile xdata *)0xFFB8)
#define     PWM21T1H    (*(unsigned char volatile xdata *)0xFFB8)
#define     PWM21T1L    (*(unsigned char volatile xdata *)0xFFB9)
#define     PWM21T2     (*(unsigned int  volatile xdata *)0xFFBA)
#define     PWM21T2H    (*(unsigned char volatile xdata *)0xFFBA)
#define     PWM21T2L    (*(unsigned char volatile xdata *)0xFFBB)
#define     PWM21CR     (*(unsigned char volatile xdata *)0xFFBC)
#define     PWM21HLD    (*(unsigned char volatile xdata *)0xFFBD)

#define     PWM22T1     (*(unsigned int  volatile xdata *)0xFFC0)
#define     PWM22T1H    (*(unsigned char volatile xdata *)0xFFC0)
#define     PWM22T1L    (*(unsigned char volatile xdata *)0xFFC1)
#define     PWM22T2     (*(unsigned int  volatile xdata *)0xFFC2)
#define     PWM22T2H    (*(unsigned char volatile xdata *)0xFFC2)
#define     PWM22T2L    (*(unsigned char volatile xdata *)0xFFC3)
#define     PWM22CR     (*(unsigned char volatile xdata *)0xFFC4)
#define     PWM22HLD    (*(unsigned char volatile xdata *)0xFFC5)

#define     PWM23T1     (*(unsigned int  volatile xdata *)0xFFC8)
#define     PWM23T1H    (*(unsigned char volatile xdata *)0xFFC8)
#define     PWM23T1L    (*(unsigned char volatile xdata *)0xFFC9)
#define     PWM23T2     (*(unsigned int  volatile xdata *)0xFFCA)
#define     PWM23T2H    (*(unsigned char volatile xdata *)0xFFCA)
#define     PWM23T2L    (*(unsigned char volatile xdata *)0xFFCB)
#define     PWM23CR     (*(unsigned char volatile xdata *)0xFFCC)
#define     PWM23HLD    (*(unsigned char volatile xdata *)0xFFCD)

#define     PWM24T1     (*(unsigned int  volatile xdata *)0xFFD0)
#define     PWM24T1H    (*(unsigned char volatile xdata *)0xFFD0)
#define     PWM24T1L    (*(unsigned char volatile xdata *)0xFFD1)
#define     PWM24T2     (*(unsigned int  volatile xdata *)0xFFD2)
#define     PWM24T2H    (*(unsigned char volatile xdata *)0xFFD2)
#define     PWM24T2L    (*(unsigned char volatile xdata *)0xFFD3)
#define     PWM24CR     (*(unsigned char volatile xdata *)0xFFD4)
#define     PWM24HLD    (*(unsigned char volatile xdata *)0xFFD5)

#define     PWM25T1     (*(unsigned int  volatile xdata *)0xFFD8)
#define     PWM25T1H    (*(unsigned char volatile xdata *)0xFFD8)
#define     PWM25T1L    (*(unsigned char volatile xdata *)0xFFD9)
#define     PWM25T2     (*(unsigned int  volatile xdata *)0xFFDA)
#define     PWM25T2H    (*(unsigned char volatile xdata *)0xFFDA)
#define     PWM25T2L    (*(unsigned char volatile xdata *)0xFFDB)
#define     PWM25CR     (*(unsigned char volatile xdata *)0xFFDC)
#define     PWM25HLD    (*(unsigned char volatile xdata *)0xFFDD)

#define     PWM26T1     (*(unsigned int  volatile xdata *)0xFFE0)
#define     PWM26T1H    (*(unsigned char volatile xdata *)0xFFE0)
#define     PWM26T1L    (*(unsigned char volatile xdata *)0xFFE1)
#define     PWM26T2     (*(unsigned int  volatile xdata *)0xFFE2)
#define     PWM26T2H    (*(unsigned char volatile xdata *)0xFFE2)
#define     PWM26T2L    (*(unsigned char volatile xdata *)0xFFE3)
#define     PWM26CR     (*(unsigned char volatile xdata *)0xFFE4)
#define     PWM26HLD    (*(unsigned char volatile xdata *)0xFFE5)

#define     PWM27T1     (*(unsigned int  volatile xdata *)0xFFE8)
#define     PWM27T1H    (*(unsigned char volatile xdata *)0xFFE8)
#define     PWM27T1L    (*(unsigned char volatile xdata *)0xFFE9)
#define     PWM27T2     (*(unsigned int  volatile xdata *)0xFFEA)
#define     PWM27T2H    (*(unsigned char volatile xdata *)0xFFEA)
#define     PWM27T2L    (*(unsigned char volatile xdata *)0xFFEB)
#define     PWM27CR     (*(unsigned char volatile xdata *)0xFFEC)
#define     PWM27HLD    (*(unsigned char volatile xdata *)0xFFED)

#define     PWM3C       (*(unsigned int  volatile xdata *)0xFC00)
#define     PWM3CH      (*(unsigned char volatile xdata *)0xFC00)
#define     PWM3CL      (*(unsigned char volatile xdata *)0xFC01)
#define     PWM3CKS     (*(unsigned char volatile xdata *)0xFC02)
#define     PWM3IF      (*(unsigned char volatile xdata *)0xFC05)
#define     PWM3FDCR    (*(unsigned char volatile xdata *)0xFC06)

#define     PWM30T1     (*(unsigned int  volatile xdata *)0xFC10)
#define     PWM30T1H    (*(unsigned char volatile xdata *)0xFC10)
#define     PWM30T1L    (*(unsigned char volatile xdata *)0xFC11)
#define     PWM30T2     (*(unsigned int  volatile xdata *)0xFC12)
#define     PWM30T2H    (*(unsigned char volatile xdata *)0xFC12)
#define     PWM30T2L    (*(unsigned char volatile xdata *)0xFC13)
#define     PWM30CR     (*(unsigned char volatile xdata *)0xFC14)
#define     PWM30HLD    (*(unsigned char volatile xdata *)0xFC15)

#define     PWM31T1     (*(unsigned int  volatile xdata *)0xFC18)
#define     PWM31T1H    (*(unsigned char volatile xdata *)0xFC18)
#define     PWM31T1L    (*(unsigned char volatile xdata *)0xFC19)
#define     PWM31T2     (*(unsigned int  volatile xdata *)0xFC1A)
#define     PWM31T2H    (*(unsigned char volatile xdata *)0xFC1A)
#define     PWM31T2L    (*(unsigned char volatile xdata *)0xFC1B)
#define     PWM31CR     (*(unsigned char volatile xdata *)0xFC1C)
#define     PWM31HLD    (*(unsigned char volatile xdata *)0xFC1D)

#define     PWM32T1     (*(unsigned int  volatile xdata *)0xFC20)
#define     PWM32T1H    (*(unsigned char volatile xdata *)0xFC20)
#define     PWM32T1L    (*(unsigned char volatile xdata *)0xFC21)
#define     PWM32T2     (*(unsigned int  volatile xdata *)0xFC22)
#define     PWM32T2H    (*(unsigned char volatile xdata *)0xFC22)
#define     PWM32T2L    (*(unsigned char volatile xdata *)0xFC23)
#define     PWM32CR     (*(unsigned char volatile xdata *)0xFC24)
#define     PWM32HLD    (*(unsigned char volatile xdata *)0xFC25)

#define     PWM33T1     (*(unsigned int  volatile xdata *)0xFC28)
#define     PWM33T1H    (*(unsigned char volatile xdata *)0xFC28)
#define     PWM33T1L    (*(unsigned char volatile xdata *)0xFC29)
#define     PWM33T2     (*(unsigned int  volatile xdata *)0xFC2A)
#define     PWM33T2H    (*(unsigned char volatile xdata *)0xFC2A)
#define     PWM33T2L    (*(unsigned char volatile xdata *)0xFC2B)
#define     PWM33CR     (*(unsigned char volatile xdata *)0xFC2C)
#define     PWM33HLD    (*(unsigned char volatile xdata *)0xFC2D)

#define     PWM34T1     (*(unsigned int  volatile xdata *)0xFC30)
#define     PWM34T1H    (*(unsigned char volatile xdata *)0xFC30)
#define     PWM34T1L    (*(unsigned char volatile xdata *)0xFC31)
#define     PWM34T2     (*(unsigned int  volatile xdata *)0xFC32)
#define     PWM34T2H    (*(unsigned char volatile xdata *)0xFC32)
#define     PWM34T2L    (*(unsigned char volatile xdata *)0xFC33)
#define     PWM34CR     (*(unsigned char volatile xdata *)0xFC34)
#define     PWM34HLD    (*(unsigned char volatile xdata *)0xFC35)

#define     PWM35T1     (*(unsigned int  volatile xdata *)0xFC38)
#define     PWM35T1H    (*(unsigned char volatile xdata *)0xFC38)
#define     PWM35T1L    (*(unsigned char volatile xdata *)0xFC39)
#define     PWM35T2     (*(unsigned int  volatile xdata *)0xFC3A)
#define     PWM35T2H    (*(unsigned char volatile xdata *)0xFC3A)
#define     PWM35T2L    (*(unsigned char volatile xdata *)0xFC3B)
#define     PWM35CR     (*(unsigned char volatile xdata *)0xFC3C)
#define     PWM35HLD    (*(unsigned char volatile xdata *)0xFC3D)

#define     PWM36T1     (*(unsigned int  volatile xdata *)0xFC40)
#define     PWM36T1H    (*(unsigned char volatile xdata *)0xFC40)
#define     PWM36T1L    (*(unsigned char volatile xdata *)0xFC41)
#define     PWM36T2     (*(unsigned int  volatile xdata *)0xFC42)
#define     PWM36T2H    (*(unsigned char volatile xdata *)0xFC42)
#define     PWM36T2L    (*(unsigned char volatile xdata *)0xFC43)
#define     PWM36CR     (*(unsigned char volatile xdata *)0xFC44)
#define     PWM36HLD    (*(unsigned char volatile xdata *)0xFC45)

#define     PWM37T1     (*(unsigned int  volatile xdata *)0xFC48)
#define     PWM37T1H    (*(unsigned char volatile xdata *)0xFC48)
#define     PWM37T1L    (*(unsigned char volatile xdata *)0xFC49)
#define     PWM37T2     (*(unsigned int  volatile xdata *)0xFC4A)
#define     PWM37T2H    (*(unsigned char volatile xdata *)0xFC4A)
#define     PWM37T2L    (*(unsigned char volatile xdata *)0xFC4B)
#define     PWM37CR     (*(unsigned char volatile xdata *)0xFC4C)
#define     PWM37HLD    (*(unsigned char volatile xdata *)0xFC4D)

#define     PWM4C       (*(unsigned int  volatile xdata *)0xFC50)
#define     PWM4CH      (*(unsigned char volatile xdata *)0xFC50)
#define     PWM4CL      (*(unsigned char volatile xdata *)0xFC51)
#define     PWM4CKS     (*(unsigned char volatile xdata *)0xFC52)
#define     PWM4TADCH   (*(unsigned char volatile xdata *)0xFC53)
#define     PWM4TADCL   (*(unsigned char volatile xdata *)0xFC54)
#define     PWM4IF      (*(unsigned char volatile xdata *)0xFC55)
#define     PWM4FDCR    (*(unsigned char volatile xdata *)0xFC56)

#define     PWM40T1     (*(unsigned int  volatile xdata *)0xFC60)
#define     PWM40T1H    (*(unsigned char volatile xdata *)0xFC60)
#define     PWM40T1L    (*(unsigned char volatile xdata *)0xFC61)
#define     PWM40T2     (*(unsigned int  volatile xdata *)0xFC62)
#define     PWM40T2H    (*(unsigned char volatile xdata *)0xFC62)
#define     PWM40T2L    (*(unsigned char volatile xdata *)0xFC63)
#define     PWM40CR     (*(unsigned char volatile xdata *)0xFC64)
#define     PWM40HLD    (*(unsigned char volatile xdata *)0xFC65)

#define     PWM41T1     (*(unsigned int  volatile xdata *)0xFC68)
#define     PWM41T1H    (*(unsigned char volatile xdata *)0xFC68)
#define     PWM41T1L    (*(unsigned char volatile xdata *)0xFC69)
#define     PWM41T2     (*(unsigned int  volatile xdata *)0xFC6A)
#define     PWM41T2H    (*(unsigned char volatile xdata *)0xFC6A)
#define     PWM41T2L    (*(unsigned char volatile xdata *)0xFC6B)
#define     PWM41CR     (*(unsigned char volatile xdata *)0xFC6C)
#define     PWM41HLD    (*(unsigned char volatile xdata *)0xFC6D)

#define     PWM42T1     (*(unsigned int  volatile xdata *)0xFC70)
#define     PWM42T1H    (*(unsigned char volatile xdata *)0xFC70)
#define     PWM42T1L    (*(unsigned char volatile xdata *)0xFC71)
#define     PWM42T2     (*(unsigned int  volatile xdata *)0xFC72)
#define     PWM42T2H    (*(unsigned char volatile xdata *)0xFC72)
#define     PWM42T2L    (*(unsigned char volatile xdata *)0xFC73)
#define     PWM42CR     (*(unsigned char volatile xdata *)0xFC74)
#define     PWM42HLD    (*(unsigned char volatile xdata *)0xFC75)

#define     PWM43T1     (*(unsigned int  volatile xdata *)0xFC78)
#define     PWM43T1H    (*(unsigned char volatile xdata *)0xFC78)
#define     PWM43T1L    (*(unsigned char volatile xdata *)0xFC79)
#define     PWM43T2     (*(unsigned int  volatile xdata *)0xFC7A)
#define     PWM43T2H    (*(unsigned char volatile xdata *)0xFC7A)
#define     PWM43T2L    (*(unsigned char volatile xdata *)0xFC7B)
#define     PWM43CR     (*(unsigned char volatile xdata *)0xFC7C)
#define     PWM43HLD    (*(unsigned char volatile xdata *)0xFC7D)

#define     PWM44T1     (*(unsigned int  volatile xdata *)0xFC80)
#define     PWM44T1H    (*(unsigned char volatile xdata *)0xFC80)
#define     PWM44T1L    (*(unsigned char volatile xdata *)0xFC81)
#define     PWM44T2     (*(unsigned int  volatile xdata *)0xFC82)
#define     PWM44T2H    (*(unsigned char volatile xdata *)0xFC82)
#define     PWM44T2L    (*(unsigned char volatile xdata *)0xFC83)
#define     PWM44CR     (*(unsigned char volatile xdata *)0xFC84)
#define     PWM44HLD    (*(unsigned char volatile xdata *)0xFC85)

#define     PWM45T1     (*(unsigned int  volatile xdata *)0xFC88)
#define     PWM45T1H    (*(unsigned char volatile xdata *)0xFC88)
#define     PWM45T1L    (*(unsigned char volatile xdata *)0xFC89)
#define     PWM45T2     (*(unsigned int  volatile xdata *)0xFC8A)
#define     PWM45T2H    (*(unsigned char volatile xdata *)0xFC8A)
#define     PWM45T2L    (*(unsigned char volatile xdata *)0xFC8B)
#define     PWM45CR     (*(unsigned char volatile xdata *)0xFC8C)
#define     PWM45HLD    (*(unsigned char volatile xdata *)0xFC8D)

#define     PWM46T1     (*(unsigned int  volatile xdata *)0xFC90)
#define     PWM46T1H    (*(unsigned char volatile xdata *)0xFC90)
#define     PWM46T1L    (*(unsigned char volatile xdata *)0xFC91)
#define     PWM46T2     (*(unsigned int  volatile xdata *)0xFC92)
#define     PWM46T2H    (*(unsigned char volatile xdata *)0xFC92)
#define     PWM46T2L    (*(unsigned char volatile xdata *)0xFC93)
#define     PWM46CR     (*(unsigned char volatile xdata *)0xFC94)
#define     PWM46HLD    (*(unsigned char volatile xdata *)0xFC95)

#define     PWM47T1     (*(unsigned int  volatile xdata *)0xFC98)
#define     PWM47T1H    (*(unsigned char volatile xdata *)0xFC98)
#define     PWM47T1L    (*(unsigned char volatile xdata *)0xFC99)
#define     PWM47T2     (*(unsigned int  volatile xdata *)0xFC9A)
#define     PWM47T2H    (*(unsigned char volatile xdata *)0xFC9A)
#define     PWM47T2L    (*(unsigned char volatile xdata *)0xFC9B)
#define     PWM47CR     (*(unsigned char volatile xdata *)0xFC9C)
#define     PWM47HLD    (*(unsigned char volatile xdata *)0xFC9D)

#define     PWM5C       (*(unsigned int  volatile xdata *)0xFCA0)
#define     PWM5CH      (*(unsigned char volatile xdata *)0xFCA0)
#define     PWM5CL      (*(unsigned char volatile xdata *)0xFCA1)
#define     PWM5CKS     (*(unsigned char volatile xdata *)0xFCA2)
#define     PWM5IF      (*(unsigned char volatile xdata *)0xFCA5)
#define     PWM5FDCR    (*(unsigned char volatile xdata *)0xFCA6)

#define     PWM50T1     (*(unsigned int  volatile xdata *)0xFCB0)
#define     PWM50T1H    (*(unsigned char volatile xdata *)0xFCB0)
#define     PWM50T1L    (*(unsigned char volatile xdata *)0xFCB1)
#define     PWM50T2     (*(unsigned int  volatile xdata *)0xFCB2)
#define     PWM50T2H    (*(unsigned char volatile xdata *)0xFCB2)
#define     PWM50T2L    (*(unsigned char volatile xdata *)0xFCB3)
#define     PWM50CR     (*(unsigned char volatile xdata *)0xFCB4)
#define     PWM50HLD    (*(unsigned char volatile xdata *)0xFCB5)

#define     PWM51T1     (*(unsigned int  volatile xdata *)0xFCB8)
#define     PWM51T1H    (*(unsigned char volatile xdata *)0xFCB8)
#define     PWM51T1L    (*(unsigned char volatile xdata *)0xFCB9)
#define     PWM51T2     (*(unsigned int  volatile xdata *)0xFCBA)
#define     PWM51T2H    (*(unsigned char volatile xdata *)0xFCBA)
#define     PWM51T2L    (*(unsigned char volatile xdata *)0xFCBB)
#define     PWM51CR     (*(unsigned char volatile xdata *)0xFCBC)
#define     PWM51HLD    (*(unsigned char volatile xdata *)0xFCBD)

#define     PWM52T1     (*(unsigned int  volatile xdata *)0xFCC0)
#define     PWM52T1H    (*(unsigned char volatile xdata *)0xFCC0)
#define     PWM52T1L    (*(unsigned char volatile xdata *)0xFCC1)
#define     PWM52T2     (*(unsigned int  volatile xdata *)0xFCC2)
#define     PWM52T2H    (*(unsigned char volatile xdata *)0xFCC2)
#define     PWM52T2L    (*(unsigned char volatile xdata *)0xFCC3)
#define     PWM52CR     (*(unsigned char volatile xdata *)0xFCC4)
#define     PWM52HLD    (*(unsigned char volatile xdata *)0xFCC5)

#define     PWM53T1     (*(unsigned int  volatile xdata *)0xFCC8)
#define     PWM53T1H    (*(unsigned char volatile xdata *)0xFCC8)
#define     PWM53T1L    (*(unsigned char volatile xdata *)0xFCC9)
#define     PWM53T2     (*(unsigned int  volatile xdata *)0xFCCA)
#define     PWM53T2H    (*(unsigned char volatile xdata *)0xFCCA)
#define     PWM53T2L    (*(unsigned char volatile xdata *)0xFCCB)
#define     PWM53CR     (*(unsigned char volatile xdata *)0xFCCC)
#define     PWM53HLD    (*(unsigned char volatile xdata *)0xFCCD)

#define     PWM54T1     (*(unsigned int  volatile xdata *)0xFCD0)
#define     PWM54T1H    (*(unsigned char volatile xdata *)0xFCD0)
#define     PWM54T1L    (*(unsigned char volatile xdata *)0xFCD1)
#define     PWM54T2     (*(unsigned int  volatile xdata *)0xFCD2)
#define     PWM54T2H    (*(unsigned char volatile xdata *)0xFCD2)
#define     PWM54T2L    (*(unsigned char volatile xdata *)0xFCD3)
#define     PWM54CR     (*(unsigned char volatile xdata *)0xFCD4)
#define     PWM54HLD    (*(unsigned char volatile xdata *)0xFCD5)

#define     PWM55T1     (*(unsigned int  volatile xdata *)0xFCD8)
#define     PWM55T1H    (*(unsigned char volatile xdata *)0xFCD8)
#define     PWM55T1L    (*(unsigned char volatile xdata *)0xFCD9)
#define     PWM55T2     (*(unsigned int  volatile xdata *)0xFCDA)
#define     PWM55T2H    (*(unsigned char volatile xdata *)0xFCDA)
#define     PWM55T2L    (*(unsigned char volatile xdata *)0xFCDB)
#define     PWM55CR     (*(unsigned char volatile xdata *)0xFCDC)
#define     PWM55HLD    (*(unsigned char volatile xdata *)0xFCDD)

#define     PWM56T1     (*(unsigned int  volatile xdata *)0xFCE0)
#define     PWM56T1H    (*(unsigned char volatile xdata *)0xFCE0)
#define     PWM56T1L    (*(unsigned char volatile xdata *)0xFCE1)
#define     PWM56T2     (*(unsigned int  volatile xdata *)0xFCE2)
#define     PWM56T2H    (*(unsigned char volatile xdata *)0xFCE2)
#define     PWM56T2L    (*(unsigned char volatile xdata *)0xFCE3)
#define     PWM56CR     (*(unsigned char volatile xdata *)0xFCE4)
#define     PWM56HLD    (*(unsigned char volatile xdata *)0xFCE5)

#define     PWM57T1     (*(unsigned int  volatile xdata *)0xFCE8)
#define     PWM57T1H    (*(unsigned char volatile xdata *)0xFCE8)
#define     PWM57T1L    (*(unsigned char volatile xdata *)0xFCE9)
#define     PWM57T2     (*(unsigned int  volatile xdata *)0xFCEA)
#define     PWM57T2H    (*(unsigned char volatile xdata *)0xFCEA)
#define     PWM57T2L    (*(unsigned char volatile xdata *)0xFCEB)
#define     PWM57CR     (*(unsigned char volatile xdata *)0xFCEC)
#define     PWM57HLD    (*(unsigned char volatile xdata *)0xFCED)











//��ǿ��PWM���η��������⹦�ܼĴ���
sfr PWMCFG      =   0xf1;

#define CBIF        0x80
#define ETADC       0x40
sfr PWMIF       =   0xf6;
#define C7IF        0x80
#define C6IF        0x40
#define C5IF        0x20
#define C4IF        0x10
#define C3IF        0x08
#define C2IF        0x04
#define C1IF        0x02
#define C0IF        0x01
sfr PWMFDCR     =   0xf7;
#define INVCMP      0x80
#define INVIO       0x40
#define ENFD        0x20
#define FLTFLIO     0x10
#define EFDI        0x08
#define FDCMP       0x04
#define FDIO        0x02
#define FDIF        0x01
sfr PWMCR       =   0xfe;
#define ENPWM       0x80
#define ECBI        0x40

//�������⹦�ܼĴ���λ����չRAM����
//������Щ�Ĵ���,���Ƚ�P_SW2��BIT7����Ϊ1,�ſ�������д
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define TADCP       (*(unsigned char volatile xdata *)0xfff3)
#define TADCPH      (*(unsigned char volatile xdata *)0xfff3)
#define TADCPL      (*(unsigned char volatile xdata *)0xfff4)


#define PWM0T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM0T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM0T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM0T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM0T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM0T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM0CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM0HLD     (*(unsigned char volatile xdata *)0xff05)

#define PWM1T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM1T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM1T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM1T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM1T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM1T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM1CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM1HLD     (*(unsigned char volatile xdata *)0xff15)

#define PWM2T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM2HLD     (*(unsigned char volatile xdata *)0xff25)

#define PWM3T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM3HLD     (*(unsigned char volatile xdata *)0xff35)

#define PWM4T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM4HLD     (*(unsigned char volatile xdata *)0xff45)

#define PWM5T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff50)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff54)
#define PWM5HLD     (*(unsigned char volatile xdata *)0xff55)

#define PWM6T1      (*(unsigned int  volatile xdata *)0xff60)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff60)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff61)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff62)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff62)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff63)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff64)
#define PWM6HLD     (*(unsigned char volatile xdata *)0xff65)

#define PWM7T1      (*(unsigned int  volatile xdata *)0xff70)
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff70)
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff71)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff72)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff72)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff73)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff74)
#define PWM7HLD     (*(unsigned char volatile xdata *)0xff75)




//stc8h


sfr         USBCLK      =           0xdc;
sfr         USBCON      =           0xf4;
sfr         USBADR      =           0xfc;
sfr         USBDAT      =           0xec;

#define     PWMA_ETRPS  (*(unsigned char volatile xdata *)0xFEB0)
#define     PWMA_ENO    (*(unsigned char volatile xdata *)0xFEB1)
#define     PWMA_PS     (*(unsigned char volatile xdata *)0xFEB2)
#define     PWMA_IOAUX  (*(unsigned char volatile xdata *)0xFEB3)


#define     PWMB_ETRPS  (*(unsigned char volatile xdata *)0xFEB4)
#define     PWMB_ENO    (*(unsigned char volatile xdata *)0xFEB5)
#define     PWMB_PS     (*(unsigned char volatile xdata *)0xFEB6)
#define     PWMB_IOAUX  (*(unsigned char volatile xdata *)0xFEB7)


#define     PWMA_CR1    (*(unsigned char volatile xdata *)0xFEC0)
#define     PWMA_CR2    (*(unsigned char volatile xdata *)0xFEC1)
#define     PWMA_SMCR   (*(unsigned char volatile xdata *)0xFEC2)
#define     PWMA_ETR    (*(unsigned char volatile xdata *)0xFEC3)
#define     PWMA_IER    (*(unsigned char volatile xdata *)0xFEC4)
#define     PWMA_SR1    (*(unsigned char volatile xdata *)0xFEC5)
#define     PWMA_SR2    (*(unsigned char volatile xdata *)0xFEC6)

#define     PWMA_EGR    (*(unsigned char volatile xdata *)0xFEC7)
#define     PWMA_CCMR1  (*(unsigned char volatile xdata *)0xFEC8)
#define     PWMA_CCMR2  (*(unsigned char volatile xdata *)0xFEC9)
#define     PWMA_CCMR3  (*(unsigned char volatile xdata *)0xFECa)
#define     PWMA_CCMR4  (*(unsigned char volatile xdata *)0xFECb)
#define     PWMA_CCER1  (*(unsigned char volatile xdata *)0xFECc)
#define     PWMA_CCER2  (*(unsigned char volatile xdata *)0xFECd)
#define     PWMA_CNTR   (*(unsigned int  volatile xdata *)0xFECe)
#define     PWMA_CNTRH  (*(unsigned char volatile xdata *)0xFECe)
#define     PWMA_CNTRL  (*(unsigned char volatile xdata *)0xFECf)
#define     PWMA_PSCR   (*(unsigned int  volatile xdata *)0xFED0)
#define     PWMA_PSCRH  (*(unsigned char volatile xdata *)0xFED0)
#define     PWMA_PSCRL  (*(unsigned char volatile xdata *)0xFED1)
#define     PWMA_ARR    (*(unsigned int  volatile xdata *)0xFED2)
#define     PWMA_ARRH   (*(unsigned char volatile xdata *)0xFED2)
#define     PWMA_ARRL   (*(unsigned char volatile xdata *)0xFED3)
#define     PWMA_RCR    (*(unsigned char volatile xdata *)0xFED4)
#define     PWMA_CCR1   (*(unsigned int  volatile xdata *)0xFED5)
#define     PWMA_CCR1H  (*(unsigned char volatile xdata *)0xFED5)
#define     PWMA_CCR1L  (*(unsigned char volatile xdata *)0xFED6)
#define     PWMA_CCR2   (*(unsigned int  volatile xdata *)0xFED7)
#define     PWMA_CCR2H  (*(unsigned char volatile xdata *)0xFED7)
#define     PWMA_CCR2L  (*(unsigned char volatile xdata *)0xFED8)
#define     PWMA_CCR3   (*(unsigned int  volatile xdata *)0xFED9)
#define     PWMA_CCR3H  (*(unsigned char volatile xdata *)0xFED9)
#define     PWMA_CCR3L  (*(unsigned char volatile xdata *)0xFEDA)
#define     PWMA_CCR4   (*(unsigned int  volatile xdata *)0xFEDB)
#define     PWMA_CCR4H  (*(unsigned char volatile xdata *)0xFEDB)
#define     PWMA_CCR4L  (*(unsigned char volatile xdata *)0xFEDC)
#define     PWMA_BKR    (*(unsigned char volatile xdata *)0xFEDD)
#define     PWMA_DTR    (*(unsigned char volatile xdata *)0xFEDE)
#define     PWMA_OISR   (*(unsigned char volatile xdata *)0xFEDF)



#define     PWMB_CR1    (*(unsigned char volatile xdata *)0xfee0)
#define     PWMB_CR2    (*(unsigned char volatile xdata *)0xfee1)
#define     PWMB_SMCR   (*(unsigned char volatile xdata *)0xfee2)
#define     PWMB_ETR    (*(unsigned char volatile xdata *)0xfee3)
#define     PWMB_IER    (*(unsigned char volatile xdata *)0xfee4)
#define     PWMB_SR1    (*(unsigned char volatile xdata *)0xfee5)
#define     PWMB_SR2    (*(unsigned char volatile xdata *)0xfee6)
#define     PWMB_EGR    (*(unsigned char volatile xdata *)0xfee7)
#define     PWMB_CCMR1  (*(unsigned char volatile xdata *)0xfee8)

#define     PWMB_CCMR2  (*(unsigned char volatile xdata *)0xfee9)
#define     PWMB_CCMR3  (*(unsigned char volatile xdata *)0xfeea)
#define     PWMB_CCMR4  (*(unsigned char volatile xdata *)0xfeeb)
#define     PWMB_CCER1  (*(unsigned char volatile xdata *)0xfeec)
#define     PWMB_CCER2  (*(unsigned char volatile xdata *)0xfeed)
#define     PWMB_CNTR   (*(unsigned int  volatile xdata *)0xfeee)
#define     PWMB_CNTRH  (*(unsigned char volatile xdata *)0xfeee)
#define     PWMB_CNTRL  (*(unsigned char volatile xdata *)0xfeef)
#define     PWMB_PSCR   (*(unsigned int  volatile xdata *)0xfef0)
#define     PWMB_PSCRH  (*(unsigned char volatile xdata *)0xfef0)
#define     PWMB_PSCRL  (*(unsigned char volatile xdata *)0xfef1)
#define     PWMB_ARR    (*(unsigned int  volatile xdata *)0xfef2)
#define     PWMB_ARRH   (*(unsigned char volatile xdata *)0xfef2)
#define     PWMB_ARRL   (*(unsigned char volatile xdata *)0xfef3)
#define     PWMB_RCR    (*(unsigned char volatile xdata *)0xfef4)
#define     PWMB_CCR1   (*(unsigned int  volatile xdata *)0xfef5)
#define     PWMB_CCR1H  (*(unsigned char volatile xdata *)0xfef5)
#define     PWMB_CCR1L  (*(unsigned char volatile xdata *)0xfef6)
#define     PWMB_CCR2   (*(unsigned int  volatile xdata *)0xfef7)
#define     PWMB_CCR2H  (*(unsigned char volatile xdata *)0xfef7)
#define     PWMB_CCR2L  (*(unsigned char volatile xdata *)0xfef8)
#define     PWMB_CCR3   (*(unsigned int  volatile xdata *)0xfef9)
#define     PWMB_CCR3H  (*(unsigned char volatile xdata *)0xfef9)
#define     PWMB_CCR3L  (*(unsigned char volatile xdata *)0xfefa)
#define     PWMB_CCR4   (*(unsigned int  volatile xdata *)0xfefb)
#define     PWMB_CCR4H  (*(unsigned char volatile xdata *)0xfefb)
#define     PWMB_CCR4L  (*(unsigned char volatile xdata *)0xfefc)
#define     PWMB_BKR    (*(unsigned char volatile xdata *)0xfefd)
#define     PWMB_DTR    (*(unsigned char volatile xdata *)0xfefe)
#define     PWMB_OISR   (*(unsigned char volatile xdata *)0xfeff)
#endif
