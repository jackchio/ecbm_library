#ifndef __ECBM_H_
#define __ECBM_H_
/*----------------------------------------------------------------------------------
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
---------------------------------------------------------------------------------*/
//V2.2版本
//集成了STC8F、STC8A、STC8G、STC8H的寄存器。
//包含本头文件后,不用另外再包含"REG51.H"
/*--------------------------内核特殊功能寄存器--------------------------*/
sfr		ACC			=0xE0;  //累加器
sfr		B			=0xF0;  //B寄存器
sfr		PSW			=0xD0;  //程序状态字寄存器
sbit	CY			=PSW^7; //进位标志位
sbit	AC			=PSW^6; //辅助进位标志位
sbit	F0			=PSW^5; //留给用户的标志位
sbit	RS1			=PSW^4; //工作寄存器选择位（高位）
sbit	RS0			=PSW^3; //工作寄存器选择位（低位）
sbit	OV			=PSW^2; //溢出标志位
sbit	P			=PSW^0; //奇偶校验位
sfr		SP			=0x81;  //堆栈指针
sfr		DPL			=0x82;  //数据指针（低字节）
sfr		DPH			=0x83;  //数据指针（高字节）
sfr		TA			=0xAE;  //DPTR时序控制寄存器
sfr		DPS			=0xE3;  //DPTR指针选择器
sfr		DPL1		=0xE4;  //第二组数据指针（低字节）
sfr		DPH1		=0xE5;  //第二组数据指针（高字节）
#define IF_ODD(_OE_) ACC=_OE_;if(P)//判断是不是奇数   
/*-------------------------中断特殊功能寄存器----------------------------*/
sfr		IE			=0xa8;  //中断允许寄存器
sbit	EA			=IE^7;  //总中断允许控制位
sbit	ELVD		=IE^6;  //低压检测中断允许位
sbit	EADC		=IE^5;  //A/D转换中断允许位
sbit	ES			=IE^4;  //串口1中断允许位
sbit	ET1			=IE^3;  //定时器1中断允许位
sbit	EX1			=IE^2;  //外部中断1允许位
sbit	ET0			=IE^1;  //定时器0中断允许位
sbit	EX0			=IE^0;  //外部中断0允许位
#define	EA_ENABLE	do{EA=1;}while(0)//打开总中断开关
#define	EA_DISABLE	do{EA=0;}while(0)//关闭总中断开关
sfr     IE2     =   0xaf;	//中断允许寄存器2
#define ETKSUI      0x80	//触摸按键中断允许位
#define EUSB	    0x80	//USB中断允许位
#define ET4         0x40	//定时器4中断允许位
#define ET3         0x20	//定时器3中断允许位
#define ES4         0x10	//串口4中断允许位
#define ES3         0x08	//串口3中断允许位
#define ET2         0x04	//定时器2中断允许位
#define ESPI        0x02	//SPI中断允许位
#define ES2         0x01	//串口2中断允许位
sfr     INTCLKO =   0x8f;	//外部中断与时钟输出控制寄存器
#define EX4         0x40	//外部中断4中断允许位
#define EX3         0x20	//外部中断3中断允许位
#define EX2         0x10	//外部中断2中断允许位
#define T2CLKO      0x04	//定时器2时钟输出控制
#define T1CLKO      0x02	//定时器1时钟输出控制
#define T0CLKO      0x01	//定时器0时钟输出控制
sfr     AUXINTIF=   0xef;	//扩展中断标志位寄存器
#define INT4IF      0x40	//外部中断4的中断标志位
#define INT3IF      0x20	//外部中断3的中断标志位
#define INT2IF      0x10	//外部中断2的中断标志位
#define T4IF        0x04	//定时器4的中断标志位
#define T3IF        0x02	//定时器3的中断标志位
#define T2IF        0x01	//定时器2的中断标志位
/*##############################外部中断0###############################*/
//-------------功能指令------------//
#define	EXTI0_ENABLE				do{EX0=1;}while(0)//打开外部中断0
#define	EXTI0_DISABLE				do{EX0=0;}while(0)//关闭外部中断0

#define	EXTI0_SET_MODE_UP_DOWM		do{IT0=0;}while(0)//外部中断0通过上升沿和下降沿触发
#define	EXTI0_SET_MODE_DOWM			do{IT0=1;}while(0)//外部中断0通过下降沿触发

#define EXTI0_SET_IO_HIGH			do{P32=1;}while(0)//设置IO的默认电平为高电平
#define EXTI0_GET_IO				(P32)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
//-------------功能定义------------//
#define	EXTI0_IT_NUM				interrupt 0//外部中断0中断号
/*##############################外部中断1###############################*/
//-------------功能指令------------//
#define	EXTI1_ENABLE				do{EX1=1;}while(0)//打开外部中断1
#define	EXTI1_DISABLE				do{EX1=0;}while(0)//关闭外部中断1

#define	EXTI1_SET_MODE_UP_DOWM		do{IT1=0;}while(0)//外部中断1通过上升沿和下降沿触发
#define	EXTI1_SET_MODE_DOWM			do{IT1=1;}while(0)//外部中断1通过下降沿触发

#define EXTI1_SET_IO_HIGH			do{P33=1;}while(0)//设置IO的默认电平为高电平
#define	EXTI1_GET_IO				(P33)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
//-------------功能定义------------//
#define	EXTI1_IT_NUM				interrupt 2//外部中断1中断号
/*##############################外部中断2###############################*/
//-------------功能指令------------//
#define	EXTI2_ENABLE				do{INTCLKO|= EX2;}while(0)//打开外部中断2
#define	EXTI2_DISABLE				do{INTCLKO&=~EX2;}while(0)//关闭外部中断2

#define EXTI2_SET_IO_HIGH			do{P36=1;}while(0)//设置IO的默认电平为高电平
#define	EXTI2_GET_IO				(P36) 

#define EXTI2_IT_CLS				do{AUXINTIF&=~INT2IF;}while(0)//清除外部中断2的中断标志位
//-------------功能定义------------//
#define	EXTI2_IT_NUM				interrupt 10//外部中断2中断号
/*##############################外部中断3###############################*/
//-------------功能指令------------//
#define	EXTI3_ENABLE				do{INTCLKO|= EX3;}while(0)//打开外部中断3
#define	EXTI3_DISABLE				do{INTCLKO&=~EX3;}while(0)//关闭外部中断3

#define EXTI3_SET_IO_HIGH			do{P37=1;}while(0)//设置IO的默认电平为高电平
#define	EXTI3_GET_IO				(P37) 

#define	EXTI3_IT_CLS				do{AUXINTIF&=~INT3IF;}while(0)//清除外部中断3的中断标志位
//-------------功能定义------------//
#define EXTI3_IT_NUM				interrupt 11//外部中断3中断号
/*##############################外部中断3###############################*/
//-------------功能指令------------//
#define	EXTI4_ENABLE				do{INTCLKO|= EX4;}while(0)//打开外部中断4
#define	EXTI4_DISABLE				do{INTCLKO&=~EX4;}while(0)//关闭外部中断4

#define EXTI4_SET_IO_HIGH			do{P30=1;}while(0)//设置IO的默认电平为高电平
#define EXTI4_GET_IO				P30 

#define EXTI4_IT_CLS				do{AUXINTIF&=~INT4IF;}while(0)//清除外部中断4的中断标志位
//-------------功能定义------------//
#define EXTI4_IT_NUM				interrupt 16//外部中断4中断号
/*-------------------------I/O口特殊功能寄存器--------------------------*/
sfr		P0			=0x80;  //P0端口
sbit	P00			=P0^0;  //P0.0口
sbit	P01			=P0^1;  //P0.1口
sbit	P02			=P0^2;  //P0.2口
sbit	P03			=P0^3;  //P0.3口
sbit	P04			=P0^4;  //P0.4口
sbit	P05			=P0^5;  //P0.5口
sbit	P06			=P0^6;  //P0.6口
sbit	P07			=P0^7;  //P0.7口
sfr		P0M0		=0x94;  //P0口配置寄存器0
sfr		P0M1		=0x93;  //P0口配置寄存器1
#define	P0PU		(*(unsigned char volatile xdata *)0xFE10)//P0口上拉电阻控制寄存器
#define	P0NCS		(*(unsigned char volatile xdata *)0xFE18)//P0口施密特触发控制寄存器
#define	P0SR		(*(unsigned char volatile xdata *)0xFE20)//P0口电平转换速度控制寄存器
#define	P0DR        (*(unsigned char volatile xdata *)0xFE28)//P0口驱动电流控制寄存器
#define	P0IE        (*(unsigned char volatile xdata *)0xFE30)//P0口数字信号输入使能控制寄存器

sfr		P1			=0x90;  //P1端口
sbit	P10			=P1^0;  //P1.0口
sbit	P11			=P1^1;  //P1.1口
sbit	P12			=P1^2;  //P1.2口
sbit	P13			=P1^3;  //P1.3口
sbit	P14			=P1^4;  //P1.4口
sbit	P15			=P1^5;  //P1.5口
sbit	P16			=P1^6;  //P1.6口
sbit	P17			=P1^7;  //P1.7口
sfr		P1M0		=0x92;  //P1口配置寄存器0
sfr		P1M1		=0x91;  //P1口配置寄存器1
#define	P1PU		(*(unsigned char volatile xdata *)0xFE11)//P1口上拉电阻控制寄存器
#define	P1NCS		(*(unsigned char volatile xdata *)0xFE19)//P1口施密特触发控制寄存器
#define	P1SR		(*(unsigned char volatile xdata *)0xFE21)//P1口电平转换速度控制寄存器
#define	P1DR        (*(unsigned char volatile xdata *)0xFE29)//P1口驱动电流控制寄存器
#define	P1IE        (*(unsigned char volatile xdata *)0xFE31)//P1口数字信号输入使能控制寄存器

sfr		P2			=0xa0;  //P2端口
sbit	P20			=P2^0;  //P2.0口
sbit	P21			=P2^1;  //P2.1口
sbit	P22			=P2^2;  //P2.2口
sbit	P23			=P2^3;  //P2.3口
sbit	P24			=P2^4;  //P2.4口
sbit	P25			=P2^5;  //P2.5口
sbit	P26			=P2^6;  //P2.6口
sbit	P27			=P2^7;  //P2.7口
sfr		P2M0		=0x96;  //P2口配置寄存器0
sfr		P2M1		=0x95;  //P2口配置寄存器1
#define	P2PU		(*(unsigned char volatile xdata *)0xFE12)//P2口上拉电阻控制寄存器
#define	P2NCS		(*(unsigned char volatile xdata *)0xFE1A)//P2口施密特触发控制寄存器
#define	P2SR		(*(unsigned char volatile xdata *)0xFE22)//P2口电平转换速度控制寄存器
#define	P2DR        (*(unsigned char volatile xdata *)0xFE2A)//P2口驱动电流控制寄存器

sfr		P3			=0xb0;  //P3端口
sbit	P30			=P3^0;  //P3.0口
sbit	P31			=P3^1;  //P3.1口
sbit	P32			=P3^2;  //P3.2口
sbit	P33			=P3^3;  //P3.3口
sbit	P34			=P3^4;  //P3.4口
sbit	P35			=P3^5;  //P3.5口
sbit	P36			=P3^6;  //P3.6口
sbit	P37			=P3^7;  //P3.7口
sfr		P3M0		=0xB2;  //P3口配置寄存器0
sfr		P3M1		=0xB1;  //P3口配置寄存器1
#define	P3PU		(*(unsigned char volatile xdata *)0xFE13)//P3口上拉电阻控制寄存器
#define	P3NCS		(*(unsigned char volatile xdata *)0xFE1B)//P3口施密特触发控制寄存器
#define	P3SR		(*(unsigned char volatile xdata *)0xFE23)//P3口电平转换速度控制寄存器
#define	P3DR        (*(unsigned char volatile xdata *)0xFE2B)//P3口驱动电流控制寄存器
#define	P3IE        (*(unsigned char volatile xdata *)0xFE33)//P3口数字信号输入使能控制寄存器

sfr		P4			=0xC0;  //P4端口
sbit	P40			=P4^0;  //P4.0口
sbit	P41			=P4^1;  //P4.1口
sbit	P42			=P4^2;  //P4.2口
sbit	P43			=P4^3;  //P4.3口
sbit	P44			=P4^4;  //P4.4口
sbit	P45			=P4^5;  //P4.5口
sbit	P46			=P4^6;  //P4.6口
sbit	P47			=P4^7;  //P4.7口
sfr		P4M0		=0xB4;  //P4口配置寄存器0
sfr		P4M1		=0xB3;  //P4口配置寄存器1
#define	P4PU		(*(unsigned char volatile xdata *)0xFE14)//P4口上拉电阻控制寄存器
#define	P4NCS		(*(unsigned char volatile xdata *)0xFE1C)//P4口施密特触发控制寄存器
#define	P4SR		(*(unsigned char volatile xdata *)0xFE24)//P4口电平转换速度控制寄存器
#define	P4DR        (*(unsigned char volatile xdata *)0xFE2C)//P4口驱动电流控制寄存器

sfr		P5			=0xC8;  //P5端口
sbit	P50			=P5^0;  //P5.0口
sbit	P51			=P5^1;  //P5.1口
sbit	P52			=P5^2;  //P5.2口
sbit	P53			=P5^3;  //P5.3口
sbit	P54			=P5^4;  //P5.4口
sbit	P55			=P5^5;  //P5.5口
sbit	P56			=P5^6;  //P5.6口
sbit	P57			=P5^7;  //P5.7口
sfr		P5M0		=0xCA;  //P5口配置寄存器0
sfr		P5M1		=0xC9;  //P5口配置寄存器1
#define	P5PU		(*(unsigned char volatile xdata *)0xFE15)//P5口上拉电阻控制寄存器
#define	P5NCS		(*(unsigned char volatile xdata *)0xFE1D)//P5口施密特触发控制寄存器
#define	P5SR		(*(unsigned char volatile xdata *)0xFE25)//P5口电平转换速度控制寄存器
#define	P5DR        (*(unsigned char volatile xdata *)0xFE2D)//P5口驱动电流控制寄存器

sfr		P6			=0xE8;  //P6端口
sbit	P60			=P6^0;  //P6.0口
sbit	P61			=P6^1;  //P6.1口
sbit	P62			=P6^2;  //P6.2口
sbit	P63			=P6^3;  //P6.3口
sbit	P64			=P6^4;  //P6.4口
sbit	P65			=P6^5;  //P6.5口
sbit	P66			=P6^6;  //P6.6口
sbit	P67			=P6^7;  //P6.7口
sfr		P6M0		=0xCC;  //P6口配置寄存器0
sfr		P6M1		=0xCB;  //P6口配置寄存器1
#define	P6PU		(*(unsigned char volatile xdata *)0xFE16)//P6口上拉电阻控制寄存器
#define	P6NCS		(*(unsigned char volatile xdata *)0xFE1E)//P6口施密特触发控制寄存器
#define	P6SR		(*(unsigned char volatile xdata *)0xFE26)//P6口电平转换速度控制寄存器
#define	P6DR        (*(unsigned char volatile xdata *)0xFE2E)//P6口驱动电流控制寄存器

sfr		P7			=0xF8;  //P7端口
sbit	P70			=P7^0;  //P7.0口
sbit	P71			=P7^1;  //P7.1口
sbit	P72			=P7^2;  //P7.2口
sbit	P73			=P7^3;  //P7.3口
sbit	P74			=P7^4;  //P7.4口
sbit	P75			=P7^5;  //P7.5口
sbit	P76			=P7^6;  //P7.6口
sbit	P77			=P7^7;  //P7.7口
sfr		P7M0		=0xE2;  //P7口配置寄存器0
sfr		P7M1		=0xE1;  //P7口配置寄存器7
#define	P7PU		(*(unsigned char volatile xdata *)0xFE17)//P7口上拉电阻控制寄存器
#define	P7NCS		(*(unsigned char volatile xdata *)0xFE1F)//P7口施密特触发控制寄存器
#define	P7SR		(*(unsigned char volatile xdata *)0xFE27)//P7口电平转换速度控制寄存器
#define	P7DR        (*(unsigned char volatile xdata *)0xFE2F)//P7口驱动电流控制寄存器
/*------------------------看门狗特殊功能寄存器---------------------------*/
sfr		WDT_CONTR					=0xC1;  //看门狗控制寄存器
#define	WDT_FLAG					0x80   //看门狗溢出标志位
#define	EN_WDT						0x20   //看门狗使能位
#define	CLR_WDT						0x10   //看门狗定时器清零
#define	IDL_WDT						0x08   //空闲模式下看门狗控制位
//-------------功能指令------------//
#define	WDT_POWER_ON				do{WDT_CONTR|= EN_WDT;}while(0)//打开看门狗

#define	WDT_CLR						do{WDT_CONTR|=CLR_WDT;}while(0)//喂狗

#define WDT_SET_IDLE_ENABLE			do{WDT_CONTR|= IDL_WDT;}while(0)//看门狗在空闲模式下继续计数
#define WDT_SET_IDLE_DISABLE		do{WDT_CONTR&=~IDL_WDT;}while(0)//看门狗在空闲模式下停止计数

#define WDT_SET_SCALE(value)		do{WDT_CONTR=((WDT_CONTR&(~0x07))|((unsigned char)(value)&0x07));}while(0)//设置看门狗的预分频系数
//-------------寄存器读取----------//
#define WDT_SET_REG_CONTR(value)	do{WDT_CONTR=(unsigned char)value;}while(0)//设置WDT_CONTR寄存器
#define	WDT_GET_REG_CONTR			(WDT_CONTR)//获取WDT_CONTR寄存器的值
/*-------------------------ADC特殊功能寄存器----------------------------*/
sfr		ADC_CONTR					=0xBC;	//ADC控制寄存器
#define	ADC_POWER					0x80	//ADC电源控制位
#define	ADC_START					0x40	//ADC转换启动控制位
#define	ADC_FLAG					0x20	//ADC转换结束标志位
sfr		ADC_RES						=0xBD;	//ADC转换结果寄存器（高）
sfr		ADC_RESL					=0xBE;	//ADC转换结果寄存器（低）
sfr		ADC_CFG						=0xDE;	//ADC配置寄存器
#define	ADC_RESFMT					0x20	//ADC转换结果格式控制位
#define	ADC_TIM						(*(unsigned char volatile xdata *)0xFEA8)//ADC时序控制寄存器
//-------------功能指令------------//
#define	ADC_POWER_ON				do{ADC_CONTR|= ADC_POWER;}while(0)//打开ADC的电源
#define	ADC_POWER_OFF				do{ADC_CONTR&=~ADC_POWER;}while(0)//关闭ADC的电源

#define	ADC_IT_ENABLE				do{EADC=1;}while(0)
#define	ADC_IT_DISABLE				do{EADC=0;}while(0)

#define	ADC_GET_IT_FLAG				(ADC_CONTR&ADC_FLAG)//获取AD转换结束标志位
#define	ADC_IT_CLS					do{ADC_CONTR&=~ADC_FLAG;}while(0)//清除AD转换结束标志位

#define	ADC_MEASURE_ON				do{ADC_CONTR|=ADC_START;}while(0)//开始AD转换

#define	ADC_SET_CHANNELS(value)		do{ADC_CONTR=((ADC_CONTR&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//设置ADC的转换通道

#define	ADC_SET_ALIGN_LEFT			do{ADC_CFG&=~ADC_RESFMT;}while(0)//设置ADC的结果左对齐排列
#define	ADC_SET_ALIGN_RIGHT			do{ADC_CFG|= ADC_RESFMT;}while(0)//设置ADC的结果右对齐排列

#define	ADC_SET_SPEED(value)		do{ADC_CFG=((ADC_CFG&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//设置ADC的转换速度
//-------------寄存器读取----------//
#define	ADC_SET_REG_CONTR(value)	do{ADC_CONTR=(unsigned char)value;}while(0)	//设置ADC_CONTR寄存器
#define	ADC_GET_REG_CONTR			(ADC_CONTR)	//获取ADC_CONTR寄存器的值

#define	ADC_SET_REG_CFG(value)		do{ADC_CFG=(unsigned char)value;}while(0)	//设置ADC_CFG寄存器
#define	ADC_GET_REG_CFG				(ADC_CFG)	//获取ADC_CFG寄存器的值

#define	ADC_SET_REG_TIM(value)		do{ADC_TIM=(unsigned char)value;}while(0)	//设置ADC_TIM寄存器
#define	ADC_GET_REG_TIM				(ADC_TIM)	//获取ADC_TIM寄存器的值

#define ADC_GET_REG_RES_HL			((((unsigned int)ADC_RES)<<8)|(unsigned int)ADC_RESL)//获取ADC结果寄存器的全部
#define ADC_GET_REG_RES_H8			(ADC_RES )	//获取ADC结果寄存器的高8位
#define ADC_GET_REG_RES_L8			(ADC_RESL)	//获取ADC结果寄存器的低8位
//-------------功能定义------------//
#define ADC_IT_NUM					interrupt 5//ADC的中断号
/*-----------------------时钟管理特殊功能寄存器--------------------------*/
#define	CKSEL						(*(unsigned char volatile xdata *)0xFE00)//时钟选择寄存器
#define	CLKDIV						(*(unsigned char volatile xdata *)0xFE01)//时钟分频寄存器
#define	HIRCCR						(*(unsigned char volatile xdata *)0xFE02)//内部高速振荡器控制寄存器
#define	XOSCCR						(*(unsigned char volatile xdata *)0xFE03)//外部晶振控制寄存器
#define	IRC32KCR					(*(unsigned char volatile xdata *)0xFE04)//内部32K振荡器控制寄存器
#define	MCLKOCR						(*(unsigned char volatile xdata *)0xFE05)//主时钟输出控制寄存器
#define	IRCDB						(*(unsigned char volatile xdata *)0xFE06)//内部高速振荡器去抖控制寄存器
#define	X32KCR						(*(unsigned char volatile xdata *)0xFE08)//外部32K振荡器控制寄存器
sfr		IRTRIM						=0x9F;//内部高精度IRC频率调整寄存器
sfr		LIRTRIM						=0x9E;//内部高精度IRC频率微调寄存器
sfr		IRCBAND						=0x9D;//IRC频段选择寄存器
//-------------功能指令------------//
#define	CLK_SET_SOURCE_HSI			do{CKSEL=((CKSEL&(~0x03))|0x00);}while(0)//设置时钟源为内部高速IRC
#define	CLK_SET_SOURCE_HSE			do{CKSEL=((CKSEL&(~0x03))|0x01);}while(0)//设置时钟源为外部高速晶振
#define	CLK_SET_SOURCE_LSE			do{CKSEL=((CKSEL&(~0x03))|0x02);}while(0)//设置时钟源为外部低速晶振
#define	CLK_SET_SOURCE_LSI			do{CKSEL=((CKSEL&(~0x03))|0x03);}while(0)//设置时钟源为内部低速IRC

#define	CLK_HSI_POWER_ON			do{HIRCCR=((HIRCCR&(~0x81))|0x80);}while(!(HIRCCR&0x01))//开启HSI电源
#define	CLK_HSI_POWER_OFF			do{HIRCCR=0x00;}while(0)//关闭HSI电源

#define	CLK_HSE_A_POWER_ON			do{XOSCCR=((XOSCCR&(~0xC1))|0x80);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成有源晶振
#define	CLK_HSE_P_POWER_ON			do{XOSCCR=((XOSCCR&(~0xC1))|0xC0);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成无源晶振
#define	CLK_HSE_POWER_OFF			do{XOSCCR=0x00;}while(0)//关闭HSE电源

#define	CLK_HSE_GAIN_ENABLE			do{XOSCCR|= 0x20;}while(0)//打开外部高速晶振增益
#define	CLK_HSE_GAIN_DISABLE		do{XOSCCR&=~0x20;}while(0)//关闭外部高速晶振增益

#define	CLK_LSE_POWER_ON			do{X32KCR=((X32KCR&(~0x81))|0x80);}while(!(X32KCR&0x01))//开启LSE电源
#define	CLK_LSE_POWER_OFF			do{X32KCR=0x00;}while(0)//关闭LSE电源

#define	CLK_LSE_GAIN_ENABLE			do{X32KCR|= 0x40;}while(0)//打开外部低速晶振增益
#define	CLK_LSE_GAIN_DISABLE		do{X32KCR&=~0x40;}while(0)//关闭外部低速晶振增益

#define	CLK_LSI_POWER_ON			do{IRC32KCR=((IRC32KCR&(~0x81))|0x80);}while(!(IRC32KCR&0x01))//开启LSI电源
#define	CLK_LSI_POWER_OFF			do{IRC32KCR=0x00;}while(0)//关闭LSI电源

#define	CLK_SET_OUT_TO_P54_FA		do{CKSEL&=~0x08;}while(0)//设置时钟输出脚为P5.4(适用于STC8F和STC8A)
#define	CLK_SET_OUT_TO_P16_FA		do{CKSEL|= 0x08;}while(0)//设置时钟输出脚为P1.6(适用于STC8F和STC8A)

#define	CLK_OUT_SET_DIV_FA(value)	do{CKSEL=((CKSEL&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//设置时钟输出分频(适用于STC8F和STC8A)

#define	CLK_SET_OUT_TO_P54_GH		do{MCLKOCR&=~0x80;}while(0)//设置时钟输出脚为P5.4(适用于STC8G和STC8H)
#define	CLK_SET_OUT_TO_P16_GH		do{MCLKOCR|= 0x80;}while(0)//设置时钟输出脚为P1.6(适用于STC8G和STC8H)

#define	CLK_OUT_SET_DIV_GH(value)	do{MCLKOCR=((MCLKOCR&(~0x7F))|((unsigned char)(value)&0x7F));}while(0)//设置时钟输出分频(适用于STC8G和STC8H)
//-------------寄存器读取----------//
#define	CLK_SET_REG_CLKDIV(value)	do{CLKDIV=(unsigned char)value;}while(0)//设置CLKDIV寄存器
#define	CLK_GET_REG_CLKDIV			(CLKDIV)//获取CLKDIV寄存器
/*----------------------IAP/ISP特殊功能寄存器---------------------------*/
sfr		IAP_DATA					=0xC2;  //IAP数据寄存器
sfr		IAP_ADDRH					=0xC3;  //IAP高地址寄存器
sfr		IAP_ADDRL					=0xC4;  //IAP低地址寄存器
sfr		IAP_CMD						=0xC5;  //IAP命令寄存器
#define	IAP_IDL						0x00
#define	IAP_READ					0x01
#define	IAP_WRITE					0x02
#define	IAP_ERASE					0x03
sfr		IAP_TRIG					=0xC6;  //IAP触发寄存器
sfr		IAP_CONTR					=0xC7;  //IAP控制寄存器
sfr		IAP_TPS						=0xF5;  //EEPROM擦除等待时间控制寄存器
#define IAPEN						0x80   //EEPROM操作使能控制位
#define SWBS						0x40   //软件复位选择控制位
#define SWRST						0x20   //软件复位操作
#define CMD_FAIL					0x10   //EEPROM操作失败状态位
//-------------功能指令------------//
#define	IAP_POWER_ON				do{IAP_CONTR|= IAPEN;}while(0)//打开IAP功能
#define	IAP_POWER_OFF				do{IAP_CONTR&=~IAPEN;}while(0)//关闭IAP功能

#define	IAP_CMD_NOP					do{IAP_CMD=IAP_IDL;}while(0)//空操作
#define	IAP_CMD_READ				do{IAP_CMD=IAP_READ;}while(0)//读一个字节
#define	IAP_CMD_WRITE				do{IAP_CMD=IAP_WRITE;}while(0)//写一个字节
#define	IAP_CMD_ERASE				do{IAP_CMD=IAP_ERASE;}while(0)//擦除一个扇区

#define	IAP_TRIG_ON					do{IAP_TRIG=0x5A;IAP_TRIG=0xA5;}while(0)//触发一次EEPROM操作
#define	IAP_TRIG_CLS				do{IAP_TRIG=0;}while(0)//清空触发寄存器

#define	IAP_GET_FAIL				(IAP_CONTR&CMD_FAIL)
//-------------寄存器读取----------//
#define	IAP_SET_REG_DATA(value)		do{IAP_DATA=(unsigned char)value;}while(0)//写一个数据到IAP_DATA
#define	IAP_GET_REG_DATA			(IAP_DATA)//从IAP_DATA读一个数据

#define	IAP_SET_REG_ADDR_HL(value)	do{IAP_ADDRL=(unsigned char)(value);IAP_ADDRH=(unsigned char)(value>>8);}while(0)//写一个地址到IAP_ADDRH和IAP_ADDRL中
#define	IAP_GET_REG_ADDR_HL			((((unsigned int)IAP_ADDRH)<<8)|(unsigned int)IAP_ADDRL)//读一个地址IAP_ADDR

#define	IAP_SET_REG_ADDR_H8(value)	do{IAP_ADDRH=(unsigned char)(value);}while(0)//写一个地址到IAP_ADDRH中
#define	IAP_GET_REG_ADDR_H8			(IAP_ADDRH)//读IAP_ADDRH

#define	IAP_SET_REG_ADDR_L8(value)	do{IAP_ADDRL=(unsigned char)(value);}while(0)//写一个地址到IAP_ADDRL中
#define	IAP_GET_REG_ADDR_L8			(IAP_ADDRL)//读IAP_ADDRL

#define	IAP_SET_REG_CONTR(value)	do{IAP_CONTR=(unsigned char)(value);}while(0)//写入一个数据到IAP_CONTR寄存器
#define	IAP_GET_REG_CONTR			(IAP_CONTR)//读取IAP_CONTR寄存器

#define	IAP_SET_REG_TPS(value)			do{IAP_TPS=(unsigned char)(value);}while(0)//写一个数据到IAP_TPS寄存器
#define	IAP_GET_REG_TPS					(IAP_TPS)//读IAP_TPS寄存器
/*-------------------------SPI特殊功能寄存器----------------------------*/
sfr		SPSTAT					=0xCD;//SPI状态寄存器
#define	SPIF					0x80   //SPI中断标志位
#define	WCOL					0x40   //SPI写冲突标志位
sfr		SPCTL					=0xCE;//SPI控制寄存器
#define	SSIG					0x80   //SS引脚功能控制位
#define	SPEN					0x40   //SPI使能控制位
#define	DORD					0x20   //SPI数据位发送/接收顺序位
#define	MSTR					0x10   //器件主/从模式选择位
#define	CPOL					0x08   //SPI时钟极性控制
#define	CPHA					0x04   //SPI时钟相位控制
sfr		SPDAT					=0xCF;//SPI数据寄存器
//-------------功能指令------------//
#define	SPI_POWER_ON				do{SPCTL|= SPEN;}while(0)//打开SPI
#define	SPI_POWER_OFF				do{SPCTL&=~SPEN;}while(0)//关闭SPI

#define	SPI_SET_CS_ENABLE			do{SPCTL&=~SSIG;}while(0)//打开CS脚的使能
#define	SPI_SET_CS_DISABLE			do{SPCTL|= SSIG;}while(0)//关闭CS脚的使能

#define	SPI_SET_DATA_MSB			do{SPCTL&=~DORD;}while(0)//设置先发/收数据的高位
#define	SPI_SET_DATA_LSB			do{SPCTL|= DORD;}while(0)//设置先发/收数据的低位

#define	SPI_SET_MODE_MASTER			do{SPCTL|= MSTR;}while(0)//设置SPI为主机模式
#define	SPI_SET_MODE_SLAVE			do{SPCTL&=~MSTR;}while(0)//设置SPI为从机模式

#define	SPI_SET_CPOL_1				do{SPCTL|= CPOL;}while(0)//设置CPOL位为1
#define	SPI_SET_CPOL_0				do{SPCTL&=~CPOL;}while(0)//设置CPOL位为0

#define	SPI_SET_CPHA_1				do{SPCTL|= CPHA;}while(0)//设置CPHA位为1
#define	SPI_SET_CPHA_0				do{SPCTL&=~CPHA;}while(0)//设置CPHA位为0

#define SPI_SET_PIN(value)			do{P_SW1=((P_SW1&(~0x0C))|((unsigned char)(value)&0x0C));}while(0)//设置串口1的输出引脚

#define	SPI_IT_CLS					do{SPSTAT|=(SPIF|WCOL);}while(0)//清SPI中断标志位
#define	SPI_WCOL_CLS				do{SPSTAT|=WCOL;}while(0)//清SPI写冲突标志位
#define	SPI_GET_IT_FLAG				(SPSTAT&SPIF)

#define	SPI_IT_ENABLE				do{IE2|= ESPI;}while(0)//开SPI中断
#define	SPI_IT_DISABLE				do{IE2&=~ESPI;}while(0)//关SPI中断

#define	SPI_SET_SPR(value)			do{SPCTL=((SPCTL&(~0x03))|((unsigned char)(value)&0x03));}while(0)//设置SPI时钟分频
#define	SPI_GET_SPR					(SPCTL&0x03)			//读取SPI时钟分频
//-------------寄存器读取----------//
#define	SPI_SET_REG_SPSTAT(value)	do{SPSTAT=(unsigned char)(value);}while(0)//写一个数据到SPCTL寄存器
#define	SPI_GET_REG_SPSTAT			(SPSTAT)//获取SPCTL寄存器的值

#define	SPI_SET_REG_SPCTL(value)	do{SPCTL=(unsigned char)(value);}while(0)//写一个数据到SPCTL寄存器
#define	SPI_GET_REG_SPCTL			(SPCTL)//获取SPCTL寄存器的值

#define	SPI_SET_REG_SPDAT(value)	do{SPDAT=(unsigned char)(value);}while(0)//写一个数据到SPDAT寄存器
#define	SPI_GET_REG_SPDAT			(SPDAT)//获取SPDAT寄存器的值
//-------------功能定义------------//
#define SPI_IT_NUM				interrupt 9//SPI的中断号
/*-----------------------系统管理特殊功能寄存器--------------------------*/
sfr     PCON						=0x87;  //电源控制寄存器
#define SMOD						0x80   //串口1波特率控制位
#define SMOD0						0x40   //帧错误检测控制位
#define LVDF						0x20   //低压检测中断请求标志
#define POF							0x10   //上电标志位
#define GF1							0x08   //用户专用标志位
#define GF0							0x04   //用户专用标志位
#define PD							0x02   //掉电模式控制位
#define IDL							0x01   //空闲模式控制位
sfr     AUXR2						=0x97;  //辅助寄存器2
#define TXLNRX						0x10   
sfr BUS_SPEED						=0xA1;  //总线速度控制寄存器
sfr     P_SW1						=0xA2;  //外设端口切换寄存器1
sfr     P_SW2						=0xBA;  //外设端口切换寄存器2
#define EAXFR						0x80
sfr     VOCTRL						=0xBB;  //电压控制寄存器
sfr     RSTCFG						=0xFF;  //复位配置寄存器
//-------------功能指令------------//
#define POWER_RESET					do{IAP_CONTR=(SWRST|SWBS);}while(0)	//相当于上电重启(数据会丢失)
#define MCU_RESET					do{IAP_CONTR=(SWRST);}while(0)		//相当于按键复位(数据不会丢失)
#define POWER_DOWN					do{PCON|=PD;}while(0)				//掉电模式
#define POWER_IDLE					do{PCON|=IDL;}while(0)				//空闲模式
#define EX_SFR_ENABLE				do{P_SW2|= EAXFR;}while(0)			//打开额外的寄存器地址。
#define EX_SFR_DISABLE				do{P_SW2&=~EAXFR;}while(0)			//关闭额外的寄存器地址。
//-------------寄存器读取----------//
#define	SYS_SET_REG_RSTCFG(value)	do{RSTCFG=(unsigned char)(value);}while(0)//设置RSTCFG寄存器
#define	SYS_GET_REG_RSTCFG			(RSTCFG)//读取RSTCFG寄存器
/*------------------------掉电定时器功能寄存器---------------------------*/
sfr		WKTCL						=0xAA;//掉电唤醒定时器（低8位）
sfr		WKTCH						=0xAB;//掉电唤醒定时器（高8位）
sfr16	WKTC						=0xAA;//掉电唤醒定时器（16位）
#define	WKTEN						0x80	//掉电唤醒使能
//-------------功能指令------------//
#define	WKT_ON						do{WKTCH|= WKTEN;}while(0)//打开掉电定时器
#define	WKT_OFF						do{WKTCH&=~WKTEN;}while(0)//关闭掉电定时器
//-------------寄存器读取----------//
#define	WKT_SET_REG_COUNT(value)	do{WKTC=(unsigned int)value}while(0)//设置掉电定时器
#define	WKT_GET_REG_COUNT			(WKTC)//读取掉电定时器
/*------------------------普通定时器功能寄存器---------------------------*/
/*###############################定时器0################################*/
sfr		TCON						=0x88;  //定时器控制寄存器
sbit	TF1							=TCON^7;//定时器1溢出中断标志位
sbit	TR1							=TCON^6;//定时器1运行控制位
sbit	TF0							=TCON^5;//定时器0溢出中断标志位
sbit	TR0							=TCON^4;//定时器0运行控制位
sbit	IE1							=TCON^3;//外部中断1请求标志位
sbit	IT1							=TCON^2;//外部中断1触发控制位
sbit	IE0							=TCON^1;//外部中断0请求标志位
sbit	IT0							=TCON^0;//外部中断0触发控制位
sfr		TMOD						=0x89;  //定时器0/1模式寄存器
#define T1_GATE						0x80   //定时器1门控位
#define T1_CT						0x40   //定时器1计数控制位
#define T1_M1						0x20   //定时器1模式选择位1
#define T1_M0						0x10   //定时器1模式选择位0
#define T0_GATE						0x08   //定时器0门控位
#define T0_CT						0x04   //定时器0计数控制位
#define T0_M1						0x02   //定时器0模式选择位1
#define T0_M0						0x01   //定时器0模式选择位0
sfr		TL0							=0x8A;  //定时器0计数寄存器（低8位）
sfr		TL1							=0x8B;  //定时器1计数寄存器（低8位）
sfr		TH0							=0x8C;  //定时器0计数寄存器（高8位）
sfr		TH1							=0x8D;  //定时器1计数寄存器（高8位）
sfr		AUXR						=0x8E;  //辅助寄存器1
#define	T0x12						0x80   //定时器0速度控制位 
#define	T1x12						0x40   //定时器1速度控制位
#define	UART_M0x6					0x20   //串口1模式0的通讯速度控制位
#define	T2R							0x10   //定时器2运行控制位
#define	T2_CT						0x08   //定时器2计数控制位
#define	T2x12						0x04   //定时器2速度控制位
#define	EXTRAM						0x02   //扩展RAM访问控制位
#define	S1ST2						0x01   //串口1波特率发射器选择为位
sfr		T2H							=0xD6;  //定时器2计数寄存器（高8位）
sfr		T2L							=0xD7;  //定时器2计数寄存器（低8位）
//-------------功能指令------------//
#define TIMER0_ON					do{TF0=0;TR0=1;}while(0)	//开定时器0
#define TIMER0_OFF					do{TR0=0;}while(0)			//关定时器0

#define TIMER0_IT_ENABLE			do{ET0=1;}while(0)			//开定时器0中断使能
#define TIMER0_IT_DISABLE			do{ET0=0;}while(0)			//关定时器0中断使能

#define TIMER0_GATE_ENABLE			do{TMOD|= T0_GATE;}while(0)	//开定时器0的门控位
#define TIMER0_GATE_DISABLE			do{TMOD&=~T0_GATE;}while(0)	//关定时器0的门控位

#define	TIMER0_OUT_ON				do{INTCLKO|= T0CLKO;}while(0)//开定时器0的时钟输出
#define	TIMER0_OUT_OFF				do{INTCLKO&=~T0CLKO;}while(0)//关定时器0的时钟输出

#define TIMER0_SET_MODE_COUNT		do{TMOD|= T0_CT;}while(0)	//设定定时器0为计数器
#define TIMER0_SET_MODE_TIMER		do{TMOD&=~T0_CT;}while(0)	//设定定时器0为定时器

#define TIMER0_SET_MODE_AUTO16		do{TMOD=(TMOD&(~0x03));}while(0)		//定时器0运行于16位模式
#define TIMER0_SET_MODE_16BIT		do{TMOD=(TMOD&(~0x03))|T0_M0;}while(0)	//定时器0运行于16位模式
#define TIMER0_SET_MODE_8BIT		do{TMOD=(TMOD&(~0x03))|T0_M1;}while(0)	//定时器0运行于8位自动重载
#define TIMER0_SET_MODE_1T			do{AUXR|= T0x12;}while(0)	//设定定时器0为1T模式
#define TIMER0_SET_MODE_12T			do{AUXR&=~T0x12;}while(0)	//设定定时器0为12T模式

#define	TIMER0_GET_FLAG				(TF0)//定时器0的溢出标志位
#define	TIMER0_FLAG_CLS				do{TF0=0;}while(0)//清定时器0的溢出标志位
//-------------寄存器读取----------//
#define	TIMER0_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x80))|((unsigned char)(value)&0x80));}while(0)//设置AUXR寄存器的定时器0部分
#define	TIMER0_GET_REG_AUXR			(AUXR&0x80)//读取AUXR寄存器的定时器0部分

#define TIMER0_SET_REG_TMOD(value)	do{TMOD=((TMOD&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)	//设置定时器0的工作模式
#define TIMER0_GET_REG_TMOD			(TMOD&0x0F)								//读取定时器0的工作模式

#define TIMER0_SET_REG_HL(value)	do{TL0=(unsigned char)(value);TH0=(unsigned char)(value>>8);}while(0)//设置定时器0的计数值
#define TIMER0_GET_REG_HL			((((unsigned int)TH0)<<8)|(unsigned int)TL0)//获取定时器0的计数值

#define TIMER0_SET_REG_H8(value)	do{TH0=(unsigned char)(value);}while(0)		//设置定时器0的计数值的高8位
#define TIMER0_GET_REG_H8			(TH0)										//获取定时器0的计数值的高8位

#define TIMER0_SET_REG_L8(value)	do{TL0=(unsigned char)(value);}while(0)		//设置定时器0的计数值的低8位
#define TIMER0_GET_REG_L8			(TL0)										//获取定时器0的计数值的低8位
//-------------功能定义------------//
#define TIMER0_IT_NUM				interrupt 1//定时器0的中断号
/*###############################定时器1################################*/
//-------------功能指令------------//
#define TIMER1_ON					do{TF1=0;TR1=1;}while(0)	//开定时器1
#define TIMER1_OFF					do{TR1=0;}while(0)			//关定时器1

#define TIMER1_IT_ENABLE			do{ET1=1;}while(0)			//开定时器1中断使能
#define TIMER1_IT_DISABLE			do{ET1=0;}while(0)			//关定时器1中断使能

#define TIMER1_GATE_ENABLE			do{TMOD|= T1_GATE;}while(0)	//开定时器1的门控位
#define TIMER1_GATE_DISABLE			do{TMOD&=~T1_GATE;}while(0)	//关定时器1的门控位

#define	TIMER1_OUT_ON				do{INTCLKO|= T1CLKO;}while(0)//开定时器1的时钟输出
#define	TIMER1_OUT_OFF				do{INTCLKO&=~T1CLKO;}while(0)//关定时器1的时钟输出

#define TIMER1_SET_MODE_COUNT		do{TMOD|= T1_CT;}while(0)//设定定时器1为计数器
#define TIMER1_SET_MODE_TIMER		do{TMOD&=~T1_CT;}while(0)//设定定时器1为定时器

#define TIMER1_SET_MODE_AUTO16		do{TMOD=(TMOD&(~0x30));}while(0)		//定时器1运行于16位模式
#define TIMER1_SET_MODE_16BIT		do{TMOD=(TMOD&(~0x30))|T1_M0;}while(0)	//定时器1运行于16位模式
#define TIMER1_SET_MODE_8BIT		do{TMOD=(TMOD&(~0x30))|T1_M1;}while(0)	//定时器1运行于8位自动重载

#define	TIMER1_SET_MODE_1T			do{AUXR|= T1x12;}while(0)//设定定时器1为1T模式
#define	TIMER1_SET_MODE_12T			do{AUXR&=~T1x12;}while(0)//设定定时器1为12T模式

#define	TIMER1_GET_FLAG				(TF1)//定时器1的溢出标志位
#define	TIMER1_FLAG_CLS				do{TF1=0;}while(0)//清定时器1的溢出标志位
//-------------寄存器读取----------//
#define	TIMER1_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x40))|((unsigned char)(value)&0x40));}while(0)//设置AUXR寄存器的定时器1部分
#define	TIMER1_GET_REG_AUXR			(AUXR&0x40)//读取AUXR寄存器的定时器1部分

#define TIMER1_SET_REG_TMOD(value)	do{TMOD=((TMOD&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//设置定时器1的工作模式
#define TIMER1_GET_REG_TMOD			(TMOD&0xF0)					//读取定时器1的工作模式

#define TIMER1_SET_REG_HL(value)	do{TL1=(unsigned char)(value);TH1=(unsigned char)(value>>8);}while(0)//设置定时器1的计数值
#define TIMER1_GET_REG_HL			((((unsigned int)TH1)<<8)|(unsigned int)TL1)//获取定时器1的计数值

#define TIMER1_SET_REG_H8(value)	do{TH1=(unsigned char)(value);}while(0)		//设置定时器1的计数值的高8位
#define TIMER1_GET_REG_H8			(TH1)										//获取定时器1的计数值的高8位

#define TIMER1_SET_REG_L8(value)	do{TL1=(unsigned char)(value);}while(0)		//设置定时器1的计数值的低8位
#define TIMER1_GET_REG_L8			(TL1)										//获取定时器1的计数值的低8位
//-------------功能定义------------//
#define TIMER1_IT_NUM				interrupt 3//定时器1的中断号
/*###############################定时器2################################*/
//-------------功能指令------------//
#define TIMER2_ON					do{AUXR|= T2R;}while(0)  //打开定时器2
#define TIMER2_OFF					do{AUXR&=~T2R;}while(0)  //关闭定时器2

#define TIMER2_IT_ENABLE			do{IE2 |= ET2;}while(0)  //打开定时器2中断
#define TIMER2_IT_DISABLE			do{IE2 &=~ET2;}while(0)  //关闭定时器2中断

#define	TIMER2_OUT_ON				do{INTCLKO|= T2CLKO;}while(0)//开定时器2的时钟输出
#define	TIMER2_OUT_OFF				do{INTCLKO&=~T2CLKO;}while(0)//关定时器2的时钟输出

#define TIMER2_SET_MODE_COUNT		do{AUXR|= T2_CT;}while(0)  //设定定时器2为计数器
#define TIMER2_SET_MODE_TIMER		do{AUXR&=~T2_CT;}while(0)  //设定定时器2为定时器

#define TIMER2_SET_MODE_1T			do{AUXR|= T2x12;}while(0)  //设定定时器2为1T模式
#define TIMER2_SET_MODE_12T			do{AUXR&=~T2x12;}while(0)  //设定定时器2为12T模式

#define	TIMER2_IT_CLS				do{AUXINTIF&=~T2IF;}while(0)//清定时器2中断标志
//-------------寄存器读取----------//
#define	TIMER2_SET_REG_AUXR(value)	do{AUXR=((AUXR&(~0x0C))|((unsigned char)(value)&0x0C));}while(0)//设置AUXR寄存器的定时器2部分
#define	TIMER2_GET_REG_AUXR			(AUXR&0x0C)//读取AUXR寄存器的定时器2部分

#define TIMER2_SET_REG_HL(value)	do{T2L=(unsigned char)(value);T2H=(unsigned char)(value>>8);}while(0)//设置定时器2的计数值
#define TIMER2_GET_REG_HL			((((unsigned int)T2H)<<8)|(unsigned int)T2L)//获取定时器2的计数值

#define TIMER2_SET_REG_H8(value)	do{T2H=(unsigned char)(value);}while(0)		//设置定时器2的计数值的高8位
#define TIMER2_GET_REG_H8			(T2H)										//获取定时器2的计数值的高8位

#define TIMER2_SET_REG_L8(value)	do{T2L=(unsigned char)(value);}while(0)		//设置定时器2的计数值的低8位
#define TIMER2_GET_REG_L8			(T2L)
//-------------功能定义------------//
#define TIMER2_IT_NUM				interrupt 12//定时器2的中断服务号
/*###############################定时器3################################*/
sfr		T4T3M						=0xD1;  //定时器4/3控制寄存器
#define	T4R							0x80   //定时器4允许控制位
#define	T4_CT						0x40   //定时器4计数控制位
#define	T4x12						0x20   //定时器4速度控制位
#define	T4CLKO						0x10   //定时器4时钟输出控制
#define	T3R							0x08   //定时器3允许控制位
#define	T3_CT						0x04   //定时器3计数控制位
#define	T3x12						0x02   //定时器3速度控制位
#define	T3CLKO						0x01   //定时器3时钟输出控制
sfr		T4H							=0xD2;  //定时器4计数寄存器（高8位）
sfr		T4L							=0xD3;  //定时器4计数寄存器（低8位）
sfr		T3H							=0xD4;  //定时器3计数寄存器（高8位）
sfr		T3L							=0xD5;  //定时器3计数寄存器（低8位）
//-------------功能指令------------//
#define TIMER3_ON					do{T4T3M|= T3R;}while(0) //打开定时器3
#define TIMER3_OFF					do{T4T3M&=~T3R;}while(0) //关闭定时器3

#define TIMER3_IT_ENABLE			do{IE2  |= ET3;}while(0) //打开定时器3中断
#define TIMER3_IT_DISABLE			do{IE2  &=~ET3;}while(0) //关闭定时器3中断

#define	TIMER3_OUT_ON				do{T4T3M|= T3CLKO;}while(0)//开定时器3的时钟输出
#define	TIMER3_OUT_OFF				do{T4T3M&=~T3CLKO;}while(0)//关定时器3的时钟输出

#define TIMER3_SET_MODE_COUNT		do{T4T3M|= T3_CT;}while(0) //设定定时器3为计数器
#define TIMER3_SET_MODE_TIMER		do{T4T3M&=~T3_CT;}while(0) //设定定时器3为定时器

#define TIMER3_SET_MODE_1T			do{T4T3M|= T3x12;}while(0) //设定定时器3为1T模式
#define TIMER3_SET_MODE_12T			do{T4T3M&=~T3x12;}while(0) //设定定时器3为12T模式

#define TIMER3_IT_CLS				do{AUXINTIF&=~T3IF;}while(0)//清定时器3中断标志
//-------------寄存器读取----------//
#define	TIMER3_SET_REG_T4T3M(value)	do{T4T3M=((T4T3M&(~0x0F))|((unsigned char)(value)&0x0F));}while(0)//设置T4T3M寄存器的定时器3部分
#define	TIMER3_GET_REG_T4T3M		(T4T3M&0x0F)//读取T4T3M寄存器的定时器3部分

#define TIMER3_SET_REG_HL(value)	do{T3L=(unsigned char)(value);T3H=(unsigned char)(value>>8);}while(0)//设置定时器3的计数值
#define TIMER3_GET_REG_HL			((((unsigned int)T3H)<<8)|(unsigned int)T3L)//获取定时器3的计数值

#define TIMER3_SET_REG_H8(value)	do{T3H=(unsigned char)(value);}while(0)		//设置定时器3的计数值的高8位
#define TIMER3_GET_REG_H8			(T3H)										//获取定时器3的计数值的高8位

#define TIMER3_SET_REG_L8(value)	do{T3L=(unsigned char)(value);}while(0)		//设置定时器3的计数值的低8位
#define TIMER3_GET_REG_L8			(T3L)
//-------------功能定义------------//
#define TIMER3_IT_NUM			interrupt 19//定时器3的中断服务号
/*###############################定时器4################################*/
//-------------功能指令------------//
#define TIMER4_ON					do{T4T3M|= T4R;}while(0) //打开定时器4
#define TIMER4_OFF					do{T4T3M&=~T4R;}while(0) //关闭定时器4

#define TIMER4_IT_ENABLE			do{IE2  |= ET4;}while(0) //打开定时器4中断
#define TIMER4_IT_DISABLE			do{IE2  &=~ET4;}while(0) //关闭定时器4中断

#define	TIMER4_OUT_ON				do{T4T3M|= T4CLKO;}while(0)//开定时器4的时钟输出
#define	TIMER4_OUT_OFF				do{T4T3M&=~T4CLKO;}while(0)//关定时器4的时钟输出

#define TIMER4_SET_MODE_COUNT		do{T4T3M|= T4_CT;}while(0) //设定定时器4为计数器
#define TIMER4_SET_MODE_TIMER		do{T4T3M&=~T4_CT;}while(0) //设定定时器4为定时器

#define TIMER4_SET_MODE_1T			do{T4T3M|= T4x12;}while(0) //设定定时器4为1T模式
#define TIMER4_SET_MODE_12T			do{T4T3M&=~T4x12;}while(0) //设定定时器4为12T模式

#define TIMER4_IT_CLS				do{AUXINTIF&=~T4IF;}while(0)//清定时器4中断标志
//-------------寄存器读取----------//
#define	TIMER4_SET_REG_T4T3M(value)	do{T4T3M=((T4T3M&(~0xF0))|((unsigned char)(value)&0xF0));}while(0)//设置T4T3M寄存器的定时器4部分
#define	TIMER4_GET_REG_T4T3M		(T4T3M&0xF0)//读取T4T3M寄存器的定时器4部分

#define TIMER4_SET_REG_HL(value)	do{T4L=(unsigned char)(value);T4H=(unsigned char)(value>>8);}while(0)//设置定时器4的计数值
#define TIMER4_GET_REG_HL			((((unsigned int)T4H)<<8)|(unsigned int)T4L)//获取定时器4的计数值

#define TIMER4_SET_REG_H8(value)	do{T4H=(unsigned char)(value);}while(0)		//设置定时器4的计数值的高8位
#define TIMER4_GET_REG_H8			(T4H)										//获取定时器4的计数值的高8位

#define TIMER4_SET_REG_L8(value)	do{T4L=(unsigned char)(value);}while(0)		//设置定时器4的计数值的低8位
#define TIMER4_GET_REG_L8			(T4L)
//-------------功能定义------------//
#define TIMER4_IT_NUM				interrupt 20//定时器4的中断服务号
/*-------------------------串口特殊功能寄存器----------------------------*/
/*################################串口1#################################*/
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
//-------------功能指令------------//
#define UART1_IT_ENABLE				do{ES=1;}while(0)	//打开串口1中断
#define UART1_IT_DISABLE			do{ES=0;}while(0)	//关闭串口1中断

#define UART1_TI_CLR				do{TI=0;}while(0)	//清除串口1的发送标志位
#define UART1_GET_TI_FLAG			(TI)				//读取串口1的发送标志位

#define UART1_RI_CLR				do{RI=0;}while(0)	//清除串口1的接受标志位
#define UART1_GET_RI_FLAG			(RI)				//读取串口1的接受标志位

#define UART1_SET_TXD_BYTE9_0		do{TB8=0;TB8=0;}while(0)	//设置串口1发送的第9位为0
#define UART1_SET_TXD_BYTE9_1		do{TB8=1;TB8=1;}while(0)	//设置串口1发送的第9位为1

#define UART1_GET_RXD_BYTE9			(RB8)						//读取串口1接收的第9位 

#define UART1_SET_PIN(value)		do{P_SW1=((P_SW1&(~0xC0))|((unsigned char)(value)&0xC0));}while(0)//设置串口1的输出引脚

#define UART1_SET_BAUD_1			do{PCON&=~SMOD;}while(0)//设置波特率不倍速
#define UART1_SET_BAUD_2			do{PCON|= SMOD;}while(0)//设置波特率二倍速

#define	UART1_SET_CLK_TIMER1		do{AUXR&=~S1ST2;}while(0)//设置串口1的时钟由定时器1产生
#define	UART1_SET_CLK_TIMER2		do{AUXR|= S1ST2;}while(0)//设置串口1的时钟由定时器2产生

#define UART1_SET_RXD_ENABLE		do{REN=1;}while(0)	//串口1的接受功能开启
#define UART1_SET_RXD_DISABLE		do{REN=0;}while(0)	//串口1的接受功能关闭

#define UART1_SET_MUX_ENABLE		do{SM2=1;}while(0)	//串口1的多机通信开启
#define UART1_SET_MUX_DISABLE		do{SM2=0;}while(0)	//串口1的多机通信关闭

#define UART1_SET_MODE_S_8			do{SCON=(SCON&(~0xC0))|0x00;}while(0)//串口1的工作模式为同步模式
#define UART1_SET_MODE_A_8_BAUD		do{SCON=(SCON&(~0xC0))|0x40;}while(0)//串口1的工作模式为异步8位模式，可变波特率
#define UART1_SET_MODE_A_9			do{SCON=(SCON&(~0xC0))|0x80;}while(0)//串口1的工作模式为异步9位模式
#define UART1_SET_MODE_A_9_BAUD		do{SCON=(SCON&(~0xC0))|0xC0;}while(0)//串口1的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART1_SET_REG_SADDR(value)	do{SADDR=((unsigned char)(value));}while(0)	//设置串口1的地址
#define UART1_GET_REG_SADDR			(SADDR)										//读取串口1的地址

#define UART1_SET_REG_SADEN(value)	do{SADEN=((unsigned char)(value));}while(0)	//设置串口1的地址掩码
#define UART1_GET_REG_SADEN			(SADEN)										//读取串口1的地址掩码

#define UART1_SET_REG_SBUF(value)	do{SBUF =((unsigned char)(value));}while(0)	//设置串口1要发送的数据
#define UART1_GET_REG_SBUF			(SBUF)										//读取串口1接收到的数据

#define UART1_SET_REG_SCON(value)	do{SCON =((unsigned char)(value));}while(0)	//设置SCON寄存器
#define UART1_GET_REG_SCON			(SCON)										//读取SCON寄存器

#define UART1_SET_REG_PCON(value)	do{PCON =((PCON &(~0xC0))|((unsigned char)(value)&0xC0));}while(0)//设置PCON寄存器的串口1部分
#define UART1_GET_REG_PCON			(PCON&0xC0)									//读取PCON寄存器的串口1部分

#define UART1_SET_REG_AUXR(value)	do{AUXR =((AUXR &(~0x21))|((unsigned char)(value)&0x21));}while(0)//设置AUXR寄存器的串口1部分
#define UART1_GET_REG_AUXR			(AUXR&0x21)									//读取AUXR寄存器的串口1部分
//-------------功能定义------------//
#define UART1_IT_NUM				interrupt 4//串口1中断号
/*################################串口2#################################*/
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
//-------------功能指令------------//
#define	UART2_IT_ENABLE				do{IE2|= ES2;}while(0)//打开串口2中断
#define	UART2_IT_DISABLE			do{IE2&=~ES2;}while(0)//关闭串口2中断

#define UART2_TI_CLR				do{S2CON&=~S2TI;}while(0)	//清除串口2的发送标志位
#define UART2_GET_TI_FLAG			(S2CON&S2TI)				//读取串口2的发送标志位

#define UART2_RI_CLR				do{S2CON&=~S2RI;}while(0)	//清除串口2的接受标志位
#define UART2_GET_RI_FLAG			(S2CON&S2RI)				//读取串口2的接受标志位

#define UART2_SET_TXD_BYTE9_0		do{S2CON&=~S2TB8;S2CON&=~S2TB8;}while(0)	//设置串口2发送的第9位为0
#define UART2_SET_TXD_BYTE9_1		do{S2CON|= S2TB8;S2CON|= S2TB8;}while(0)	//设置串口2发送的第9位为1

#define UART2_GET_RXD_BYTE9			(S2CON&S2RB8)								//读取串口2接收的第9位 

#define UART2_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x01))|((unsigned char)(value)&0x01));}while(0)//设置串口2的输出引脚

#define UART2_SET_RXD_ENABLE		do{S2CON|= S2REN;}while(0)	//串口2的接受功能开启
#define UART2_SET_RXD_DISABLE		do{S2CON&=~S2REN;}while(0)	//串口2的接受功能关闭

#define UART2_SET_MUX_ENABLE		do{S2CON|= S2SM2;}while(0)	//串口2的多机通信开启
#define UART2_SET_MUX_DISABLE		do{S2CON&=~S2SM2;}while(0)	//串口2的多机通信关闭

#define UART2_SET_MODE_A_8_BAUD		do{S2CON&=~S2SM0;}while(0)//串口2的工作模式为异步8位模式，可变波特率
#define UART2_SET_MODE_A_9_BAUD		do{S2CON|= S2SM0;}while(0)//串口2的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART2_SET_REG_S2BUF(value)	do{S2BUF =((unsigned char)(value));}while(0)//设置串口2要发送的数据
#define UART2_GET_REG_S2BUF			(S2BUF)										//读取串口2接收到的数据

#define UART2_SET_REG_S2CON(value)	do{S2CON =((unsigned char)(value));}while(0)//设置S2CON寄存器
#define UART2_GET_REG_S2CON			(S2CON)										//读取S2CON寄存器
//-------------功能定义------------//
#define UART2_IT_NUM				interrupt 8//串口2中断号
/*################################串口3#################################*/
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
//-------------功能指令------------//
#define	UART3_IT_ENABLE				do{IE2|= ES3;}while(0)//打开串口3中断
#define	UART3_IT_DISABLE			do{IE2&=~ES3;}while(0)//关闭串口3中断

#define UART3_TI_CLR				do{S3CON&=~S3TI;}while(0)	//清除串口3的发送标志位
#define UART3_GET_TI_FLAG			(S3CON&S3TI)				//读取串口3的发送标志位

#define UART3_RI_CLR				do{S3CON&=~S3RI;}while(0)	//清除串口3的接受标志位
#define UART3_GET_RI_FLAG			(S3CON&S3RI)				//读取串口3的接受标志位

#define UART3_SET_TXD_BYTE9_0		do{S3CON&=~S3TB8;S3CON&=~S3TB8;}while(0)	//设置串口3发送的第9位为0
#define UART3_SET_TXD_BYTE9_1		do{S3CON|= S3TB8;S3CON|= S3TB8;}while(0)	//设置串口3发送的第9位为1

#define UART3_GET_RXD_BYTE9			(S3CON&S3RB8)								//读取串口3接收的第9位 

#define UART3_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x02))|((unsigned char)(value)&0x02));}while(0)//设置串口3的输出引脚

#define	UART3_SET_CLK_TIMER2		do{S3CON&=~S3ST3;}while(0)//设置串口3的时钟由定时器2产生
#define	UART3_SET_CLK_TIMER3		do{S3CON|= S3ST3;}while(0)//设置串口3的时钟由定时器3产生

#define UART3_SET_RXD_ENABLE		do{S3CON|= S3REN;}while(0)	//串口3的接受功能开启
#define UART3_SET_RXD_DISABLE		do{S3CON&=~S3REN;}while(0)	//串口3的接受功能关闭

#define UART3_SET_MUX_ENABLE		do{S3CON|= S3SM2;}while(0)	//串口3的多机通信开启
#define UART3_SET_MUX_DISABLE		do{S3CON&=~S3SM2;}while(0)	//串口3的多机通信关闭

#define UART3_SET_MODE_A_8_BAUD		do{S3CON&=~S3SM0;}while(0)//串口3的工作模式为异步8位模式，可变波特率
#define UART3_SET_MODE_A_9_BAUD		do{S3CON|= S3SM0;}while(0)//串口3的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART3_SET_REG_S3BUF(value)	do{S3BUF =((unsigned char)(value));}while(0)//设置串口3要发送的数据
#define UART3_GET_REG_S3BUF			(S3BUF)										//读取串口3接收到的数据

#define UART3_SET_REG_S3CON(value)	do{S3CON =((unsigned char)(value));}while(0)//设置S3CON寄存器
#define UART3_GET_REG_S3CON			(S3CON)										//读取S3CON寄存器
//-------------功能定义------------//
#define UART3_IT_NUM				interrupt 17//串口3中断号
/*################################串口4#################################*/
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
//-------------功能指令------------//
#define	UART4_IT_ENABLE				do{IE2|= ES4;}while(0)//打开串口4中断
#define	UART4_IT_DISABLE			do{IE2&=~ES4;}while(0)//关闭串口4中断

#define UART4_TI_CLR				do{S4CON&=~S4TI;}while(0)	//清除串口4的发送标志位
#define UART4_GET_TI_FLAG			(S4CON&S4TI)				//读取串口4的发送标志位

#define UART4_RI_CLR				do{S4CON&=~S4RI;}while(0)	//清除串口4的接受标志位
#define UART4_GET_RI_FLAG			(S4CON&S4RI)				//读取串口4的接受标志位

#define UART4_SET_TXD_BYTE9_0		do{S4CON&=~S4TB8;S4CON&=~S4TB8;}while(0)	//设置串口4发送的第9位为0
#define UART4_SET_TXD_BYTE9_1		do{S4CON|= S4TB8;S4CON|= S4TB8;}while(0)	//设置串口4发送的第9位为1

#define UART4_GET_RXD_BYTE9			(S4CON&S4RB8)								//读取串口4接收的第9位 

#define UART4_SET_PIN(value)		do{P_SW2=((P_SW2&(~0x04))|((unsigned char)(value)&0x04));}while(0)//设置串口4的输出引脚

#define	UART4_SET_CLK_TIMER2		do{S4CON&=~S4ST4;}while(0)//设置串口4的时钟由定时器2产生
#define	UART4_SET_CLK_TIMER4		do{S4CON|= S4ST4;}while(0)//设置串口4的时钟由定时器4产生

#define UART4_SET_RXD_ENABLE		do{S4CON|= S4REN;}while(0)	//串口4的接受功能开启
#define UART4_SET_RXD_DISABLE		do{S4CON&=~S4REN;}while(0)	//串口4的接受功能关闭

#define UART4_SET_MUX_ENABLE		do{S4CON|= S4SM2;}while(0)	//串口4的多机通信开启
#define UART4_SET_MUX_DISABLE		do{S4CON&=~S4SM2;}while(0)	//串口4的多机通信关闭

#define UART4_SET_MODE_A_8_BAUD		do{S4CON&=~S4SM0;}while(0)//串口4的工作模式为异步8位模式，可变波特率
#define UART4_SET_MODE_A_9_BAUD		do{S4CON|= S4SM0;}while(0)//串口4的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART4_SET_REG_S4BUF(value)	do{S4BUF =((unsigned char)(value));}while(0)//设置串口4要发送的数据
#define UART4_GET_REG_S4BUF			(S4BUF)										//读取串口4接收到的数据

#define UART4_SET_REG_S4CON(value)	do{S4CON =((unsigned char)(value));}while(0)//设置S4CON寄存器
#define UART4_GET_REG_S4CON			(S4CON)										//读取S4CON寄存器
//-------------功能定义------------//
#define UART4_IT_NUM				interrupt 18//串口4中断号
/*------------------------比较器特殊功能寄存器---------------------------*/
sfr     CMPCR1						=0xE6;//比较器控制寄存器1
#define CMPEN						0x80//比较器使能位
#define CMPIF						0x40//比较器中断标志位
#define PIE							0x20//比较器上升沿中断使能位
#define NIE							0x10//比较器下降沿中断使能位
#define PIS							0x08//比较器正极选择位
#define NIS							0x04//比较器负极选择位
#define CMPOE						0x02//比较器结果输出控制位
#define CMPRES						0x01//比较器结果
sfr     CMPCR2						=0xE7;//比较器控制寄存器2
#define INVCMPO						0x80//比较器结果输出控制
#define DISFLT						0x40//模拟滤波功能控制
//-------------功能指令------------//
#define	CMP_POWER_ON				do{CMPCR1|= CMPEN;}while(0)//开启比较器
#define	CMP_POWER_OFF				do{CMPCR1&=~CMPEN;}while(0)//关闭比较器

#define	CMP_IT_CLS					do{CMPCR1&=~CMPIF;}while(0)//清除比较器中断标志位

#define	CMP_IT_POSITIVE_ENABLE		do{CMPCR1|= PIE;}while(0)//开启上升沿中断
#define	CMP_IT_POSITIVE_DISABLE		do{CMPCR1&=~PIE;}while(0)//关闭上升沿中断

#define	CMP_IT_NEGATIVE_ENABLE		do{CMPCR1|= NIE;}while(0)//开启上升沿中断
#define	CMP_IT_NEGATIVE_DISABLE		do{CMPCR1&=~NIE;}while(0)//关闭上升沿中断

#define	CMP_SET_POSITIVE_ADC		do{CMPCR1|= PIS;}while(0)//比较器的+端为ADC输入脚
#define	CMP_SET_POSITIVE_P37		do{CMPCR1&=~PIS;}while(0)//比较器的+端为P3.7脚

#define	CMP_SET_NEGATIVE_P36		do{CMPCR1|= NIS;}while(0)//比较器的-端为P3.6脚
#define	CMP_SET_NEGATIVE_BGV		do{CMPCR1&=~NIS;}while(0)//比较器的-端为内部1.9V电压

#define	CMP_SET_OUT_ENABLE			do{CMPCR1|= CMPOE;}while(0)//开启比较器结果输出
#define	CMP_SET_OUT_DISABLE			do{CMPCR1&=~CMPOE;}while(0)//关闭比较器结果输出

#define	CMP_GET_RESULT				(CMPCR1&CMPRES)//获取比较器结果

#define	CMP_SET_OUT_NEGATIVE		do{CMPCR2|= INVCMPO;}while(0)//比较器结果反向输出
#define	CMP_SET_OUT_POSITIVE		do{CMPCR2&=~INVCMPO;}while(0)//比较器结果正向输出

#define	CMP_SET_ANALOG_FILTER_ENABLE	do{CMPCR2|= DISFLT;}while(0)//开启比较器模拟滤波
#define	CMP_SET_ANALOG_FILTER_DISABLE	do{CMPCR2&=~DISFLT;}while(0)//关闭比较器模拟滤波

#define	CMP_SET_DIGITAL_FILTER(value)	do{CMPCR2=((CMPCR2&(~0x3F))|((unsigned char)(value)&0x3F));}while(0)//设置比较器数字滤波

#define CMP_SET_PIN(value)			do{P_SW2=((P_SW2&(~0x08))|((unsigned char)(value)&0x08));}while(0)//设置比较器的输出引脚
//-------------寄存器读取----------//
#define	CMP_SET_REG_CMPCR1(value)	do{CMPCR1=(unsigned char)(value);}while(0)//设置CMPCR1寄存器
#define	CMP_GET_REG_CMPCR1			(CMPCR1)//读取CMPCR1寄存器

#define	CMP_SET_REG_CMPCR2(value)	do{CMPCR2=(unsigned char)(value);}while(0)//设置CMPCR2寄存器
#define	CMP_GET_REG_CMPCR2			(CMPCR2)//读取CMPCR1寄存器
//-------------功能定义------------//
#define CMP_IT_NUM					interrupt 21//比较器中断号
/*-------------------------MDU16特殊功能寄存器---------------------------*/
#define	MD5MD4						(*(unsigned int  volatile xdata *)0xfcf4)//一般用来存放除数、余数、乘数。
#define	MD3MD2MD1MD0				(*(unsigned long volatile xdata *)0xfcf0)//一般用来存放32位被除数、32位商、积。
#define	MD1MD0						(*(unsigned int  volatile xdata *)0xfcf2)//一般用来存放16位被除数、16位商、16位被乘数。
#define	ARCON						(*(unsigned char volatile xdata *)0xfcf6)//MDU模式控制寄存器
#define	OPCON						(*(unsigned char volatile xdata *)0xfcf7)//MDU操作控制寄存器
#define	MDOV						0x40
#define	MDRST						0x02
#define	ENOP						0x01
//-------------功能指令------------//
#define	MDU16_RESET					do{OPCON=MDRST;}while(0)//复位乘除单元
#define	MDU16_START					do{OPCON=ENOP;}while(0)	//开始计算
#define	MDU16_GET_END_FLAG			(OPCON&ENOP)			//获取计算结束标志位
#define	MDU16_GET_MDOV_FLAG			(OPCON&MDOV)			//获取计算结果溢出位

#define	MDU16_SET_16MUL				do{ARCON=0x80;}while(0)	//16位乘法
#define	MDU16_SET_16DIV				do{ARCON=0xa0;}while(0)	//16位除法
#define	MDU16_SET_32DIV				do{ARCON=0xc0;}while(0)	//32位除法
//-------------寄存器读取----------//
#define	MDU16_SET_REG_ARCON(value)	do{ARCON=(unsigned char)(value);}while(0)//设置ARCON寄存器
#define	MDU16_GET_REG_ARCON			(ARCON)//读取ARCON寄存器

#define	MDU16_SET_REG_OPCON(value)	do{OPCON=(unsigned char)(value);}while(0)//设置OPCON寄存器
#define	MDU16_GET_REG_OPCON			(OPCON)//读取OPCON寄存器
/*-------------------------IIC特殊功能寄存器-----------------------------*/
#define	I2CCFG						(*(unsigned char volatile xdata *)0xfe80)//IIC配置寄存器
#define ENI2C						0x80//IIC电源使能
#define MSSL						0x40//IIC主从机选择
#define	I2CMSCR						(*(unsigned char volatile xdata *)0xfe81)//IIC主机控制寄存器
#define EMSI    				    0x80
#define	I2CMSST						(*(unsigned char volatile xdata *)0xfe82)//IIC主机状态寄存器
#define MSBUSY						0x80//主机模式时IIC控制器状态位
#define MSIF						0x40//主机模式时的中断请求位
#define MSACKI						0x02//主机模式时，接收到的ACK
#define MSACKO						0x01//主机模式时，要发送的ACK
#define	I2CMSAUX					(*(unsigned char volatile xdata *)0xfe88)//IIC主机辅助控制寄存器
#define	WDTA						0x01//自动发送ack位
#define I2CSLCR						(*(unsigned char volatile xdata *)0xfe83)//IIC从机控制寄存器
#define ESTAI						0x40//从机模式时接收START信号中断允许位
#define ERXI						0x20//从机模式时接收到1字节数据后中断允许位
#define ETXI						0x10//从机模式时发送完1字节数据后中断允许位
#define ESTOI						0x08//从机模式时接收STOP信号中断允许位
#define SLRST						0x01//复位从机模式
#define I2CSLST						(*(unsigned char volatile xdata *)0xfe84)//IIC从机状态寄存器
#define SLBUSY						0x80//从机模式时IIC控制器状态位
#define STAIF						0x40//从机模式时接收START信号中断请求位
#define RXIF						0x20//从机模式时接收到1字节数据后中断请求位
#define TXIF						0x10//从机模式时发送完1字节数据后中断请求位
#define STOIF						0x08//从机模式时接收STOP信号中断请求位
#define TXING						0x04
#define SLACKI						0x02//从机模式时接收到的ACK
#define SLACKO						0x01//从机模式时，将要发送的ACK
#define I2CSLADR					(*(unsigned char volatile xdata *)0xfe85)//IIC从机地址寄存器
#define I2CTXD						(*(unsigned char volatile xdata *)0xfe86)//IIC发送数据寄存器
#define I2CRXD						(*(unsigned char volatile xdata *)0xfe87)//IIC接收数据寄存器
//-------------功能指令------------//
#define	IIC_POWER_ON				do{I2CCFG|= ENI2C;}while(0)//打开IIC电源
#define	IIC_POWER_OFF				do{I2CCFG&=~ENI2C;}while(0)//关闭IIC电源

#define	IIC_SET_MODE_MASTER			do{I2CCFG|= MSSL;}while(0)//设置IIC为主机模式
#define	IIC_SET_MODE_SLAVE			do{I2CCFG&=~MSSL;}while(0)//设置IIC为从机模式

#define	IIC_SET_AUTOACK_ENABLE		do{I2CMSAUX|= WDTA;}while(0)//设置自动发送ACK
#define	IIC_SET_AUTOACK_DISABLE		do{I2CMSAUX&=~WDTA;}while(0)//取消自动发送ACK

#define IIC_SET_SPEED(value)		do{I2CCFG=((I2CCFG&(~0x3F))|((unsigned char)(value)&0x3F));}while(0)//设置IIC的输出速度

#define	IIC_GET_IT_FLAG				(I2CMSST&MSIF)//获取IIC中断标志位
#define	IIC_IT_CLS					do{I2CMSST&=~MSIF;}while(0)//清除IIC中断标志位

#define IIC_SET_PIN(value)			do{P_SW2=((P_SW2&(~0x30))|((unsigned char)(value)&0x30));}while(0)//设置IIC的输出引脚
//-------------寄存器读取----------//
#define	IIC_SET_REG_CFG(value)		do{I2CCFG=(unsigned char)value;}while(0)//设置IICCFG寄存器
#define	IIC_GET_REG_CFG				(I2CCFG)//读取IICCFG寄存器

#define	IIC_SET_REG_MSCR(value)		do{I2CMSCR=(unsigned char)value;}while(0)//设置IICMSCR寄存器
#define	IIC_GET_REG_MSCR			(I2CMSCR)//读取IICMSCR寄存器

#define	IIC_SET_REG_MSST(value)		do{I2CMSST=(unsigned char)value;}while(0)//设置I2CMSST寄存器
#define	IIC_GET_REG_MSST			(I2CMSST)//读取I2CMSST寄存器

#define	IIC_SET_REG_MSAUX(value)	do{I2CMSAUX=(unsigned char)value;}while(0)//设置I2CMSAUX寄存器
#define	IIC_GET_REG_MSAUX			(I2CMSAUX)//读取I2CMSAUX寄存器
//-------------功能定义------------//
#define IIC_IT_NUM					interrupt 24//IIC中断号
/*-------------------------IIC特殊功能寄存器-----------------------------*/
sfr     IP      =   0xb8;  //中断优先级控制寄存器
sbit    PPCA    =   IP^7;  //PCA中断优先级控制位（低）
sbit    PLVD    =   IP^6;  //低压检测中断优先级控制位（低）
sbit    PADC    =   IP^5;  //ADC中断优先级控制位（低）
sbit    PS      =   IP^4;  //串口1中断优先级控制位（低）
sbit    PT1     =   IP^3;  //定时器1中断优先级控制位（低）
sbit    PX1     =   IP^2;  //外部中断1中断优先级控制位（低）
sbit    PT0     =   IP^1;  //定时器0中断优先级控制位（低）
sbit    PX0     =   IP^0;  //外部中断0中断优先级控制位（低）
sfr     IP2     =   0xb5;  //中断优先级控制寄存器2
#define PI2C        0x40   //IIC中断优先级控制位（低）
#define PCMP        0x20   //比较器中断优先级控制位（低）
#define PX4         0x10   //外部中断4中断优先级控制位（低）
#define PPWMFD      0x08
#define PPWM        0x04
#define PSPI        0x02   //SPI中断优先级控制位（低）
#define PS2         0x01   //串口2中断优先级控制位（低）
sfr     IPH     =   0xb7;  //高中断优先级控制寄存器
#define PPCAH       0x80   //PCA中断优先级控制位（高）
#define PLVDH       0x40   //低压检测中断优先级控制位（高）
#define PADCH       0x20   //ADC中断优先级控制位（高）
#define PSH         0x10   //串口1中断优先级控制位（高）
#define PT1H        0x08   //定时器1中断优先级控制位（高）
#define PX1H        0x04   //外部中断1中断优先级控制位（高）
#define PT0H        0x02   //定时器0中断优先级控制位（高）
#define PX0H        0x01   //外部中断0中断优先级控制位（高）
sfr     IP2H    =   0xb6;  //高中断优先级控制寄存器2
#define PI2CH       0x40   //IIC中断优先级控制位（高）
#define PCMPH       0x20   //比较器中断优先级控制位（高）
#define PX4H        0x10   //外部中断4中断优先级控制位（高）
#define PPWMFDH     0x08
#define PPWMH       0x04
#define PSPIH       0x02   //SPI中断优先级控制位（高）
#define PS2H        0x01   //串口2中断优先级控制位（高）
sfr     IP3     =   0xDF;
sfr     IP3H    =   0xEE;
//-------------功能指令------------//
#define	IT_SET_EXTI0_PRIORITY_0		do{IPH&=~PX0H;IP&=~PX0H;}while(0)//设置外部中断0的优先级为0		
#define	IT_SET_EXTI0_PRIORITY_1		do{IPH&=~PX0H;IP|= PX0H;}while(0)//设置外部中断0的优先级为1		
#define	IT_SET_EXTI0_PRIORITY_2		do{IPH|= PX0H;IP&=~PX0H;}while(0)//设置外部中断0的优先级为2		
#define	IT_SET_EXTI0_PRIORITY_3		do{IPH|= PX0H;IP|= PX0H;}while(0)//设置外部中断0的优先级为3		

#define	IT_SET_TIMER0_PRIORITY_0	do{IPH&=~PT0H;IP&=~PT0H;}while(0)//设置定时器0的优先级为0		
#define	IT_SET_TIMER0_PRIORITY_1	do{IPH&=~PT0H;IP|= PT0H;}while(0)//设置定时器0的优先级为1		
#define	IT_SET_TIMER0_PRIORITY_2	do{IPH|= PT0H;IP&=~PT0H;}while(0)//设置定时器0的优先级为2		
#define	IT_SET_TIMER0_PRIORITY_3	do{IPH|= PT0H;IP|= PT0H;}while(0)//设置定时器0的优先级为3		

#define	IT_SET_EXTI1_PRIORITY_0		do{IPH&=~PX1H;IP&=~PX1H;}while(0)//设置外部中断1的优先级为0		
#define	IT_SET_EXTI1_PRIORITY_1		do{IPH&=~PX1H;IP|= PX1H;}while(0)//设置外部中断1的优先级为1		
#define	IT_SET_EXTI1_PRIORITY_2		do{IPH|= PX1H;IP&=~PX1H;}while(0)//设置外部中断1的优先级为2		
#define	IT_SET_EXTI1_PRIORITY_3		do{IPH|= PX1H;IP|= PX1H;}while(0)//设置外部中断1的优先级为3		

#define	IT_SET_TIMER1_PRIORITY_0	do{IPH&=~PT1H;IP&=~PT1H;}while(0)//设置定时器1的优先级为0		
#define	IT_SET_TIMER1_PRIORITY_1	do{IPH&=~PT1H;IP|= PT1H;}while(0)//设置定时器1的优先级为1		
#define	IT_SET_TIMER1_PRIORITY_2	do{IPH|= PT1H;IP&=~PT1H;}while(0)//设置定时器1的优先级为2		
#define	IT_SET_TIMER1_PRIORITY_3	do{IPH|= PT1H;IP|= PT1H;}while(0)//设置定时器1的优先级为3		

#define	IT_SET_UART1_PRIORITY_0		do{IPH&=~PSH;IP&=~PSH;}while(0)//设置串口1的优先级为0		
#define	IT_SET_UART1_PRIORITY_1		do{IPH&=~PSH;IP|= PSH;}while(0)//设置串口1的优先级为1		
#define	IT_SET_UART1_PRIORITY_2		do{IPH|= PSH;IP&=~PSH;}while(0)//设置串口1的优先级为2		
#define	IT_SET_UART1_PRIORITY_3		do{IPH|= PSH;IP|= PSH;}while(0)//设置串口1的优先级为3		

#define	IT_SET_ADC_PRIORITY_0		do{IPH&=~PADCH;IP&=~PADCH;}while(0)//设置ADC的优先级为0		
#define	IT_SET_ADC_PRIORITY_1		do{IPH&=~PADCH;IP|= PADCH;}while(0)//设置ADC的优先级为1		
#define	IT_SET_ADC_PRIORITY_2		do{IPH|= PADCH;IP&=~PADCH;}while(0)//设置ADC的优先级为2		
#define	IT_SET_ADC_PRIORITY_3		do{IPH|= PADCH;IP|= PADCH;}while(0)//设置ADC的优先级为3		

#define	IT_SET_LVD_PRIORITY_0		do{IPH&=~PLVDH;IP&=~PLVDH;}while(0)//设置LVD的优先级为0		
#define	IT_SET_LVD_PRIORITY_1		do{IPH&=~PLVDH;IP|= PLVDH;}while(0)//设置LVD的优先级为1		
#define	IT_SET_LVD_PRIORITY_2		do{IPH|= PLVDH;IP&=~PLVDH;}while(0)//设置LVD的优先级为2		
#define	IT_SET_LVD_PRIORITY_3		do{IPH|= PLVDH;IP|= PLVDH;}while(0)//设置LVD的优先级为3		

#define	IT_SET_PCA_PRIORITY_0		do{IPH&=~PPCAH;IP&=~PPCAH;}while(0)//设置PCA的优先级为0		
#define	IT_SET_PCA_PRIORITY_1		do{IPH&=~PPCAH;IP|= PPCAH;}while(0)//设置PCA的优先级为1		
#define	IT_SET_PCA_PRIORITY_2		do{IPH|= PPCAH;IP&=~PPCAH;}while(0)//设置PCA的优先级为2		
#define	IT_SET_PCA_PRIORITY_3		do{IPH|= PPCAH;IP|= PPCAH;}while(0)//设置PCA的优先级为3		

#define	IT_SET_UART2_PRIORITY_0		do{IP2H&=~PS2H;IP2&=~PS2H;}while(0)//设置串口2的优先级为0		
#define	IT_SET_UART2_PRIORITY_1		do{IP2H&=~PS2H;IP2|= PS2H;}while(0)//设置串口2的优先级为1		
#define	IT_SET_UART2_PRIORITY_2		do{IP2H|= PS2H;IP2&=~PS2H;}while(0)//设置串口2的优先级为2		
#define	IT_SET_UART2_PRIORITY_3		do{IP2H|= PS2H;IP2|= PS2H;}while(0)//设置串口2的优先级为3		

#define	IT_SET_SPI_PRIORITY_0		do{IP2H&=~PSPIH;IP2&=~PSPIH;}while(0)//设置SPI的优先级为0		
#define	IT_SET_SPI_PRIORITY_1		do{IP2H&=~PSPIH;IP2|= PSPIH;}while(0)//设置SPI的优先级为1		
#define	IT_SET_SPI_PRIORITY_2		do{IP2H|= PSPIH;IP2&=~PSPIH;}while(0)//设置SPI的优先级为2		
#define	IT_SET_SPI_PRIORITY_3		do{IP2H|= PSPIH;IP2|= PSPIH;}while(0)//设置SPI的优先级为3		

#define	IT_SET_PWM_PRIORITY_0		do{IP2H&=~PPWMH;IP2&=~PPWMH;}while(0)//设置PWM的优先级为0		
#define	IT_SET_PWM_PRIORITY_1		do{IP2H&=~PPWMH;IP2|= PPWMH;}while(0)//设置PWM的优先级为1		
#define	IT_SET_PWM_PRIORITY_2		do{IP2H|= PPWMH;IP2&=~PPWMH;}while(0)//设置PWM的优先级为2		
#define	IT_SET_PWM_PRIORITY_3		do{IP2H|= PPWMH;IP2|= PPWMH;}while(0)//设置PWM的优先级为3		

#define	IT_SET_PWMFD_PRIORITY_0		do{IP2H&=~PPWMFDH;IP2&=~PPWMFDH;}while(0)//设置PWMFD的优先级为0		
#define	IT_SET_PWMFD_PRIORITY_1		do{IP2H&=~PPWMFDH;IP2|= PPWMFDH;}while(0)//设置PWMFD的优先级为1		
#define	IT_SET_PWMFD_PRIORITY_2		do{IP2H|= PPWMFDH;IP2&=~PPWMFDH;}while(0)//设置PWMFD的优先级为2		
#define	IT_SET_PWMFD_PRIORITY_3		do{IP2H|= PPWMFDH;IP2|= PPWMFDH;}while(0)//设置PWMFD的优先级为3		

#define	IT_SET_EXTI4_PRIORITY_0		do{IP2H&=~PX4H;IP2&=~PX4H;}while(0)//设置外部中断4的优先级为0		
#define	IT_SET_EXTI4_PRIORITY_1		do{IP2H&=~PX4H;IP2|= PX4H;}while(0)//设置外部中断4的优先级为1		
#define	IT_SET_EXTI4_PRIORITY_2		do{IP2H|= PX4H;IP2&=~PX4H;}while(0)//设置外部中断4的优先级为2		
#define	IT_SET_EXTI4_PRIORITY_3		do{IP2H|= PX4H;IP2|= PX4H;}while(0)//设置外部中断4的优先级为3		

#define	IT_SET_CMP_PRIORITY_0		do{IP2H&=~PCMPH;IP2&=~PCMPH;}while(0)//设置比较器的优先级为0		
#define	IT_SET_CMP_PRIORITY_1		do{IP2H&=~PCMPH;IP2|= PCMPH;}while(0)//设置比较器的优先级为1		
#define	IT_SET_CMP_PRIORITY_2		do{IP2H|= PCMPH;IP2&=~PCMPH;}while(0)//设置比较器的优先级为2		
#define	IT_SET_CMP_PRIORITY_3		do{IP2H|= PCMPH;IP2|= PCMPH;}while(0)//设置比较器的优先级为3		

#define	IT_SET_IIC_PRIORITY_0		do{IP2H&=~PI2CH;IP2&=~PI2CH;}while(0)//设置IIC的优先级为0		
#define	IT_SET_IIC_PRIORITY_1		do{IP2H&=~PI2CH;IP2|= PI2CH;}while(0)//设置IIC的优先级为1		
#define	IT_SET_IIC_PRIORITY_2		do{IP2H|= PI2CH;IP2&=~PI2CH;}while(0)//设置IIC的优先级为2		
#define	IT_SET_IIC_PRIORITY_3		do{IP2H|= PI2CH;IP2|= PI2CH;}while(0)//设置IIC的优先级为3		
/*-------------------------PCA/PWM特殊功能寄存器-------------------------*/
sfr CCON        =   0xD8;	//PCA控制寄存器
sbit CF         =   CCON^7;	
sbit CR         =   CCON^6;
sbit CCF3       =   CCON^3;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xD9;	//PCA模式寄存器
#define CIDL        0x80	//空闲模式下是否停止PCA计数
#define ECF         0x01	//PCA计数器溢出中断允许位
sfr CL          =   0xE9;	//PCA计数器低字节
sfr CH          =   0xF9;	//PCA计数器高字节
//-------------功能指令------------//
#define	PCA_POWER_ON				do{CR=1;}while(0)//打开PCA模块
#define	PCA_POWER_OFF				do{CR=0;}while(0)//关闭PCA模块

#define	PCA_IT_ENABLE				do{CMOD|= ECF;}while(0)//打开PCA计数器的溢出中断
#define	PCA_IT_DISABLE				do{CMOD&=~ECF;}while(0)//关闭PCA计数器的溢出中断

#define	PCA_GET_IT_FLAG				(CF)//获取PCA计数器溢出中断标志位
#define	PCA_IT_CLS					do{CF=0;}while(0)//清除PCA计数器溢出中断标志位

#define	PCA0_GET_IT_FLAG			(CCF0)//获取PCA0捕获中断标志位
#define	PCA0_IT_CLS					do{CCF0=0;}while(0)//清除PCA0捕获中断标志位

#define	PCA1_GET_IT_FLAG			(CCF1)//获取PCA1捕获中断标志位
#define	PCA1_IT_CLS					do{CCF1=0;}while(0)//清除PCA1捕获中断标志位

#define	PCA2_GET_IT_FLAG			(CCF2)//获取PCA2捕获中断标志位
#define	PCA2_IT_CLS					do{CCF2=0;}while(0)//清除PCA2捕获中断标志位

#define	PCA3_GET_IT_FLAG			(CCF3)//获取PCA3捕获中断标志位
#define	PCA3_IT_CLS					do{CCF3=0;}while(0)//清除PCA3捕获中断标志位

#define PCA_SET_IDLE_ENABLE			do{CMOD&=~CIDL;}while(0)//PCA在空闲模式下继续计数
#define PCA_SET_IDLE_DISABLE		do{CMOD|= CIDL;}while(0)//PCA在空闲模式下停止计数

#define PCA_SET_CPS(value)			do{CMOD=((CMOD&(~0x0E))|((unsigned char)(value)&0x0E));}while(0)//设置PCA计数脉冲来源

#define PCA_SET_PIN(value)			do{P_SW1=((P_SW1&(~0x30))|((unsigned char)(value)&0x30));}while(0)//设置PCA的输出引脚
//-------------寄存器读取----------//
#define	PCA_SET_REG_CCON(value)		do{CCON=(unsigned char)value;}while(0)//设置CCON寄存器
#define	PCA_GET_REG_CCON			(CCON)//读取CCON寄存器

#define	PCA_SET_REG_CMOD(value)		do{CMOD=(unsigned char)value;}while(0)//设置CMOD寄存器
#define	PCA_GET_REG_CMOD			(CMOD)//读取CMOD寄存器

#define	PCA_SET_REG_CL(value)		do{CL=(unsigned char)value;}while(0)//设置CL寄存器
#define	PCA_GET_REG_CL				(CL)//读取CL寄存器

#define	PCA_SET_REG_CH(value)		do{CH=(unsigned char)value;}while(0)//设置CH寄存器
#define	PCA_GET_REG_CH				(CH)//读取CH寄存器

#define PCA_SET_REG_CHL(value)		do{CL=(unsigned char)(value);CH=(unsigned char)(value>>8);}while(0)//设置PCA的计数值
#define PCA_GET_REG_CHL				((((unsigned int)CH)<<8)|(unsigned int)CL)//获取PCA的计数值
//-------------功能定义------------//
#define PCA_IT_NUM					interrupt 7//PCA中断号
/*################################PCA0#################################*/
sfr 	CCAPM0						=0xDA;	//PCA模块0模式控制寄存器
#define ECOM0						0x40	//允许PCA模块0的比较功能
#define CCAPP0						0x20	//允许PCA模块0进行上升沿捕获
#define CCAPN0						0x10	//允许PCA模块0进行下降沿捕获
#define MAT0						0x08	//允许PCA模块0的匹配功能
#define TOG0						0x04	//允许PCA模块0的高速脉冲输出功能
#define PWM0						0x02	//允许PCA模块0的脉宽调制输出功能
#define ECCF0						0x01	//允许PCA模块0的匹配/捕获中断
sfr		CCAP0L						=0xEA;	//PCA模块0低字节
sfr		CCAP0H						=0xFA;	//PCA模块0高字节
sfr		PCA_PWM0					=0xF2;	//PCA0的PWM模式寄存器
//-------------功能指令------------//
#define	PCA0_SET_ECOM_ENABLE		do{CCAPM0|= ECOM0;}while(0)//打开PCA模块0的比较功能
#define	PCA0_SET_ECOM_DISABLE		do{CCAPM0&=~ECOM0;}while(0)//关闭PCA模块0的比较功能

#define	PCA0_SET_CCAPP_ENABLE		do{CCAPM0|= CCAPP0;}while(0)//打开PCA模块0的上升沿捕获功能
#define	PCA0_SET_CCAPP_DISABLE		do{CCAPM0&=~CCAPP0;}while(0)//关闭PCA模块0的上升沿捕获功能

#define	PCA0_SET_CCAPN_ENABLE		do{CCAPM0|= CCAPN0;}while(0)//打开PCA模块0的下降沿捕获功能
#define	PCA0_SET_CCAPN_DISABLE		do{CCAPM0&=~CCAPN0;}while(0)//关闭PCA模块0的下降沿捕获功能

#define	PCA0_SET_MAT_ENABLE			do{CCAPM0|= MAT0;}while(0)//打开PCA模块0的匹配功能
#define	PCA0_SET_MAT_DISABLE		do{CCAPM0&=~MAT0;}while(0)//关闭PCA模块0的匹配功能

#define	PCA0_SET_TOG_ENABLE			do{CCAPM0|= TOG0;}while(0)//打开PCA模块0的高速脉冲输出功能
#define	PCA0_SET_TOG_DISABLE		do{CCAPM0&=~TOG0;}while(0)//关闭PCA模块0的高速脉冲输出功能

#define	PCA0_SET_PWM_ENABLE			do{CCAPM0|= PWM0;}while(0)//打开PCA模块0的脉宽调制输出功能
#define	PCA0_SET_PWM_DISABLE		do{CCAPM0&=~PWM0;}while(0)//关闭PCA模块0的脉宽调制输出功能

#define	PCA0_SET_ECCF_ENABLE		do{CCAPM0|= ECCF0;}while(0)//打开PCA模块0的匹配/捕获中断
#define	PCA0_SET_ECCF_DISABLE		do{CCAPM0&=~ECCF0;}while(0)//关闭PCA模块0的匹配/捕获中断
//-------------寄存器读取----------//
#define	PCA_SET_REG_CCAPM0(value)	do{CCAPM0=(unsigned char)value;}while(0)//设置CCAPM0寄存器
#define	PCA_GET_REG_CCAPM0			(CCAPM0)//读取CCAPM0寄存器

#define	PCA_SET_REG_CCAP0L(value)	do{CCAP0L=(unsigned char)value;}while(0)//设置CCAP0L寄存器
#define	PCA_GET_REG_CCAP0L			(CCAP0L)//读取CCAP0L寄存器

#define	PCA_SET_REG_CCAP0H(value)	do{CCAP0H=(unsigned char)value;}while(0)//设置CCAP0H寄存器
#define	PCA_GET_REG_CCAP0H			(CCAP0H)//读取CCAP0H寄存器

#define PCA_SET_REG_CCAP0HL(value)	do{CCAP0L=(unsigned char)(value);CCAP0H=(unsigned char)(value>>8);}while(0)//设置PCA0的捕获值
#define PCA_GET_REG_CCAP0HL			((((unsigned int)CCAP0H)<<8)|(unsigned int)CCAP0L)//获取PCA0的捕获值

#define	PCA_SET_REG_PWM0(value)		do{PCA_PWM0=(unsigned char)value;}while(0)//设置PCA_PWM0寄存器
#define	PCA_GET_REG_PWM0			(PCA_PWM0)//读取PCA_PWM0寄存器
/*################################PCA1#################################*/
sfr CCAPM1      =   0xdb;	//PCA模块1模式控制寄存器
#define ECOM1       0x40	//允许PCA模块1的比较功能
#define CCAPP1      0x20	//允许PCA模块1进行上升沿捕获
#define CCAPN1      0x10	//允许PCA模块1进行下降沿捕获
#define MAT1        0x08	//允许PCA模块1的匹配功能
#define TOG1        0x04	//允许PCA模块1的高速脉冲输出功能
#define PWM1        0x02	//允许PCA模块1的脉宽调制输出功能
#define ECCF1       0x01	//允许PCA模块1的匹配/捕获中断
sfr CCAP1L      =   0xeb;	//PCA模块1低字节
sfr CCAP1H      =   0xfb;	//PCA模块1高字节
sfr PCA_PWM1    =   0xf3;	//PCA1的PWM模式寄存器
//-------------功能指令------------//
#define	PCA1_SET_ECOM_ENABLE		do{CCAPM1|= ECOM1;}while(0)//打开PCA模块1的比较功能
#define	PCA1_SET_ECOM_DISABLE		do{CCAPM1&=~ECOM1;}while(0)//关闭PCA模块1的比较功能

#define	PCA1_SET_CCAPP_ENABLE		do{CCAPM1|= CCAPP1;}while(0)//打开PCA模块1的上升沿捕获功能
#define	PCA1_SET_CCAPP_DISABLE		do{CCAPM1&=~CCAPP1;}while(0)//关闭PCA模块1的上升沿捕获功能

#define	PCA1_SET_CCAPN_ENABLE		do{CCAPM1|= CCAPN1;}while(0)//打开PCA模块1的下降沿捕获功能
#define	PCA1_SET_CCAPN_DISABLE		do{CCAPM1&=~CCAPN1;}while(0)//关闭PCA模块1的下降沿捕获功能

#define	PCA1_SET_MAT_ENABLE			do{CCAPM1|= MAT1;}while(0)//打开PCA模块1的匹配功能
#define	PCA1_SET_MAT_DISABLE		do{CCAPM1&=~MAT1;}while(0)//关闭PCA模块1的匹配功能

#define	PCA1_SET_TOG_ENABLE			do{CCAPM1|= TOG1;}while(0)//打开PCA模块1的高速脉冲输出功能
#define	PCA1_SET_TOG_DISABLE		do{CCAPM1&=~TOG1;}while(0)//关闭PCA模块1的高速脉冲输出功能

#define	PCA1_SET_PWM_ENABLE			do{CCAPM1|= PWM1;}while(0)//打开PCA模块1的脉宽调制输出功能
#define	PCA1_SET_PWM_DISABLE		do{CCAPM1&=~PWM1;}while(0)//关闭PCA模块1的脉宽调制输出功能

#define	PCA1_SET_ECCF_ENABLE		do{CCAPM1|= ECCF1;}while(0)//打开PCA模块1的匹配/捕获中断
#define	PCA1_SET_ECCF_DISABLE		do{CCAPM1&=~ECCF1;}while(0)//关闭PCA模块1的匹配/捕获中断
//-------------寄存器读取----------//
#define	PCA_SET_REG_CCAPM1(value)	do{CCAPM1=(unsigned char)value;}while(0)//设置CCAPM1寄存器
#define	PCA_GET_REG_CCAPM1			(CCAPM1)//读取CCAPM1寄存器

#define	PCA_SET_REG_CCAP1L(value)	do{CCAP1L=(unsigned char)value;}while(0)//设置CCAP1L寄存器
#define	PCA_GET_REG_CCAP1L			(CCAP1L)//读取CCAP1L寄存器

#define	PCA_SET_REG_CCAP1H(value)	do{CCAP1H=(unsigned char)value;}while(0)//设置CCAP1H寄存器
#define	PCA_GET_REG_CCAP1H			(CCAP1H)//读取CCAP1H寄存器

#define PCA_SET_REG_CCAP1HL(value)	do{CCAP1L=(unsigned char)(value);CCAP1H=(unsigned char)(value>>8);}while(0)//设置PCA1的捕获值
#define PCA_GET_REG_CCAP1HL			((((unsigned int)CCAP1H)<<8)|(unsigned int)CCAP1L)//获取PCA1的捕获值

#define	PCA_SET_REG_PWM1(value)		do{PCA_PWM1=(unsigned char)value;}while(0)//设置PCA_PWM1寄存器
#define	PCA_GET_REG_PWM1			(PCA_PWM1)//读取PCA_PWM1寄存器
/*################################PCA2#################################*/
sfr CCAPM2      =   0xdc;	//PCA模块2模式控制寄存器
#define ECOM2       0x40	//允许PCA模块2的比较功能
#define CCAPP2      0x20	//允许PCA模块2进行上升沿捕获
#define CCAPN2      0x10	//允许PCA模块2进行下降沿捕获
#define MAT2        0x08	//允许PCA模块2的匹配功能
#define TOG2        0x04	//允许PCA模块2的高速脉冲输出功能
#define PWM2        0x02	//允许PCA模块2的脉宽调制输出功能
#define ECCF2       0x01	//允许PCA模块2的匹配/捕获中断
sfr CCAP2L      =   0xec;	//PCA模块2低字节
sfr CCAP2H      =   0xfc;	//PCA模块2高字节
sfr PCA_PWM2    =   0xf4;	//PCA2的PWM模式寄存器
//-------------功能指令------------//
#define	PCA2_SET_ECOM_ENABLE		do{CCAPM2|= ECOM2;}while(0)//打开PCA模块2的比较功能
#define	PCA2_SET_ECOM_DISABLE		do{CCAPM2&=~ECOM2;}while(0)//关闭PCA模块2的比较功能

#define	PCA2_SET_CCAPP_ENABLE		do{CCAPM2|= CCAPP2;}while(0)//打开PCA模块2的上升沿捕获功能
#define	PCA2_SET_CCAPP_DISABLE		do{CCAPM2&=~CCAPP2;}while(0)//关闭PCA模块2的上升沿捕获功能

#define	PCA2_SET_CCAPN_ENABLE		do{CCAPM2|= CCAPN2;}while(0)//打开PCA模块2的下降沿捕获功能
#define	PCA2_SET_CCAPN_DISABLE		do{CCAPM2&=~CCAPN2;}while(0)//关闭PCA模块2的下降沿捕获功能

#define	PCA2_SET_MAT_ENABLE			do{CCAPM2|= MAT2;}while(0)//打开PCA模块2的匹配功能
#define	PCA2_SET_MAT_DISABLE		do{CCAPM2&=~MAT2;}while(0)//关闭PCA模块2的匹配功能

#define	PCA2_SET_TOG_ENABLE			do{CCAPM2|= TOG2;}while(0)//打开PCA模块2的高速脉冲输出功能
#define	PCA2_SET_TOG_DISABLE		do{CCAPM2&=~TOG2;}while(0)//关闭PCA模块2的高速脉冲输出功能

#define	PCA2_SET_PWM_ENABLE			do{CCAPM2|= PWM2;}while(0)//打开PCA模块2的脉宽调制输出功能
#define	PCA2_SET_PWM_DISABLE		do{CCAPM2&=~PWM2;}while(0)//关闭PCA模块2的脉宽调制输出功能

#define	PCA2_SET_ECCF_ENABLE		do{CCAPM2|= ECCF2;}while(0)//打开PCA模块2的匹配/捕获中断
#define	PCA2_SET_ECCF_DISABLE		do{CCAPM2&=~ECCF2;}while(0)//关闭PCA模块2的匹配/捕获中断
//-------------寄存器读取----------//
#define	PCA_SET_REG_CCAPM2(value)	do{CCAPM2=(unsigned char)value;}while(0)//设置CCAPM2寄存器
#define	PCA_GET_REG_CCAPM2			(CCAPM2)//读取CCAPM2寄存器

#define	PCA_SET_REG_CCAP2L(value)	do{CCAP2L=(unsigned char)value;}while(0)//设置CCAP2L寄存器
#define	PCA_GET_REG_CCAP2L			(CCAP2L)//读取CCAP2L寄存器

#define	PCA_SET_REG_CCAP2H(value)	do{CCAP2H=(unsigned char)value;}while(0)//设置CCAP2H寄存器
#define	PCA_GET_REG_CCAP2H			(CCAP2H)//读取CCAP2H寄存器

#define PCA_SET_REG_CCAP2HL(value)	do{CCAP2L=(unsigned char)(value);CCAP2H=(unsigned char)(value>>8);}while(0)//设置PCA2的捕获值
#define PCA_GET_REG_CCAP2HL			((((unsigned int)CCAP2H)<<8)|(unsigned int)CCAP2L)//获取PCA2的捕获值

#define	PCA_SET_REG_PWM2(value)		do{PCA_PWM2=(unsigned char)value;}while(0)//设置PCA_PWM2寄存器
#define	PCA_GET_REG_PWM2			(PCA_PWM2)//读取PCA_PWM2寄存器
/*################################PCA3#################################*/
sfr CCAPM3      =   0xdd;	//PCA模块3模式控制寄存器
#define ECOM3       0x40	//允许PCA模块3的比较功能
#define CCAPP3      0x20	//允许PCA模块3进行上升沿捕获
#define CCAPN3      0x10	//允许PCA模块3进行下降沿捕获
#define MAT3        0x08	//允许PCA模块3的匹配功能
#define TOG3        0x04	//允许PCA模块3的高速脉冲输出功能
#define PWM3        0x02	//允许PCA模块3的脉宽调制输出功能
#define ECCF3       0x01	//允许PCA模块3的匹配/捕获中断
sfr CCAP3L      =   0xed;	//PCA模块3低字节
sfr CCAP3H      =   0xfd;	//PCA模块3高字节
sfr PCA_PWM3    =   0xf5;	//PCA3的PWM模式寄存器
//-------------功能指令------------//
#define	PCA3_SET_ECOM_ENABLE		do{CCAPM3|= ECOM3;}while(0)//打开PCA模块3的比较功能
#define	PCA3_SET_ECOM_DISABLE		do{CCAPM3&=~ECOM3;}while(0)//关闭PCA模块3的比较功能

#define	PCA3_SET_CCAPP_ENABLE		do{CCAPM3|= CCAPP3;}while(0)//打开PCA模块3的上升沿捕获功能
#define	PCA3_SET_CCAPP_DISABLE		do{CCAPM3&=~CCAPP3;}while(0)//关闭PCA模块3的上升沿捕获功能

#define	PCA3_SET_CCAPN_ENABLE		do{CCAPM3|= CCAPN3;}while(0)//打开PCA模块3的下降沿捕获功能
#define	PCA3_SET_CCAPN_DISABLE		do{CCAPM3&=~CCAPN3;}while(0)//关闭PCA模块3的下降沿捕获功能

#define	PCA3_SET_MAT_ENABLE			do{CCAPM3|= MAT3;}while(0)//打开PCA模块3的匹配功能
#define	PCA3_SET_MAT_DISABLE		do{CCAPM3&=~MAT3;}while(0)//关闭PCA模块3的匹配功能

#define	PCA3_SET_TOG_ENABLE			do{CCAPM3|= TOG3;}while(0)//打开PCA模块3的高速脉冲输出功能
#define	PCA3_SET_TOG_DISABLE		do{CCAPM3&=~TOG3;}while(0)//关闭PCA模块3的高速脉冲输出功能

#define	PCA3_SET_PWM_ENABLE			do{CCAPM3|= PWM3;}while(0)//打开PCA模块3的脉宽调制输出功能
#define	PCA3_SET_PWM_DISABLE		do{CCAPM3&=~PWM3;}while(0)//关闭PCA模块3的脉宽调制输出功能

#define	PCA3_SET_ECCF_ENABLE		do{CCAPM3|= ECCF3;}while(0)//打开PCA模块3的匹配/捕获中断
#define	PCA3_SET_ECCF_DISABLE		do{CCAPM3&=~ECCF3;}while(0)//关闭PCA模块3的匹配/捕获中断
//-------------寄存器读取----------//
#define	PCA_SET_REG_CCAPM3(value)	do{CCAPM3=(unsigned char)value;}while(0)//设置CCAPM3寄存器
#define	PCA_GET_REG_CCAPM3			(CCAPM3)//读取CCAPM3寄存器

#define	PCA_SET_REG_CCAP3L(value)	do{CCAP3L=(unsigned char)value;}while(0)//设置CCAP3L寄存器
#define	PCA_GET_REG_CCAP3L			(CCAP3L)//读取CCAP3L寄存器

#define	PCA_SET_REG_CCAP3H(value)	do{CCAP3H=(unsigned char)value;}while(0)//设置CCAP3H寄存器
#define	PCA_GET_REG_CCAP3H			(CCAP3H)//读取CCAP3H寄存器

#define PCA_SET_REG_CCAP3HL(value)	do{CCAP3L=(unsigned char)(value);CCAP3H=(unsigned char)(value>>8);}while(0)//设置PCA3的捕获值
#define PCA_GET_REG_CCAP3HL			((((unsigned int)CCAP3H)<<8)|(unsigned int)CCAP3L)//获取PCA3的捕获值

#define	PCA_SET_REG_PWM3(value)		do{PCA_PWM3=(unsigned char)value;}while(0)//设置PCA_PWM3寄存器
#define	PCA_GET_REG_PWM3			(PCA_PWM3)//读取PCA_PWM3寄存器















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



//冲突的部分
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











//增强型PWM波形发生器特殊功能寄存器
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

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
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
