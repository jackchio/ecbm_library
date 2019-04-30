#ifndef _ECBM_TIMER_H_
#define _ECBM_TIMER_H_
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
//<i>GPIO库为基础库，几乎没有依赖其他库。因此即可直接单独使用，又可联合使用。
//<i>所以此选项打勾，只是意味着GPIO库会使用ECBM库的头文件。此选项不打勾，则会使用基本的stc8头文件。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和gpio.h置于同一个文件夹。
#define ECBM_TIMER_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用外部中断，请设为0。
//<e>定时器0使能与设置
//<i>勾选该选项会使能定时器0，开放和定时器0相关的操作函数。若未使用定时器0，可以关掉优化空间。
#define ECBM_TIMER0_EN 1
//<o.4>定时器开关
//<0=>软件开关 <1=>软硬件开关。
//<i>当选择“软件开关”时，运行tim_start函数就能启动定时器0。
//<i>当选择“软硬件开关”时，除了运行tim_start函数外，INT0（P32）脚要为高电平才启动定时器0。通常会用在通过外部硬件来启动定时器的情况。
//<o.5>计数来源
//<0=>对系统时钟计数（定时器应用）  <1=>对外部T0（P34）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.2..3>工作模式
//<i>16位自动重载模式：当计数寄存器溢出时，自动重载设定好的初值。
//<i>16位不自动重载模式：当计数寄存器溢出时，从0开始计数（如果不想从0开始，需要在定时器中断里给定时器赋予初值）。
//<i>8位自动重载模式：只使用TL0计数，当TL0溢出时，自动把TH0的值赋予TL0。
//<i>16位自动重载（不可屏蔽中断）模式：与上面的16位自动重载模式一样，但是会产生一个不可屏蔽的中断。
//<0=>16位自动重载模式 <1=>16位不自动重载模式 <2=>8位自动重载模式 <3=>16位自动重载（不可屏蔽中断）模式 
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.7>对外输出时钟
//<i>勾选该选项后，每次定时器0发生溢出时，T0CLKO（P35）脚的电平自动发生翻转。
#define ECBM_TIMER0_MODE 0x40
//</e>
//<e>定时器1使能与设置
//<i>由于主库调用了定时器1用作串口的波特率发生器。所以该设置的优先级为：连接使能>主库自动下载使能>定时器1使能。
//<i>程序会先判断是否定时器库是否连接主库。如果连接了，则判断自动下载使能。如果没有连接，就判断定时器1使能。
#define ECBM_TIMER1_EN 0
//<o.4>定时器开关
//<0=>软件开关 <1=>软硬件开关。
//<i>当选择“软件开关”时，运行tim_start函数就能启动定时器1。
//<i>当选择“软硬件开关”时，除了运行tim_start函数外，INT1（P33）脚要为高电平才启动定时器1。通常会用在通过外部硬件来启动定时器的情况。
//<o.5>计数来源
//<0=>对系统时钟计数（定时器应用）  <1=>对外部T1（P35）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.2..3>工作模式
//<i>16位自动重载模式：当计数寄存器溢出时，自动重载设定好的初值。
//<i>16位不自动重载模式：当计数寄存器溢出时，从0开始计数（如果不想从0开始，需要在定时器中断里给定时器赋予初值）。
//<i>8位自动重载模式：只使用TL1计数，当TL1溢出时，自动把TH1的值赋予TL1。
//<0=>16位自动重载模式 <1=>16位不自动重载模式 <2=>8位自动重载模式 
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.7>对外输出时钟
//<i>勾选该选项后，每次定时器1发生溢出时，T1CLKO（P34）脚的电平自动发生翻转。
#define ECBM_TIMER1_MODE 0x00
//</e>
//<e>定时器2使能与设置
//<i>勾选该选项会使能定时器2，开放和定时器2相关的操作函数。若未使用定时器2，可以关掉优化空间。
//<i>定时器2固定为16位自动重载模式。
#define ECBM_TIMER2_EN 0
//<o.5>计数来源
//<0=>对系统时钟计数（定时器应用）  <1=>对外部T2（P12）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.7>对外输出时钟
//<i>勾选该选项后，每次定时器2发生溢出时，T2CLKO（P13）脚的电平自动发生翻转。
#define ECBM_TIMER2_MODE 0x40
//</e>
//<e>定时器3使能与设置
//<i>勾选该选项会使能定时器3，开放和定时器3相关的操作函数。若未使用定时器3，可以关掉优化空间。
//<i>定时器3固定为16位自动重载模式。
#define ECBM_TIMER3_EN 0
//<o.5>计数来源
//<0=>对系统时钟计数（定时器应用）  <1=>对外部T3（P04）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.7>对外输出时钟
//<i>勾选该选项后，每次定时器3发生溢出时，T3CLKO（P05）脚的电平自动发生翻转。
#define ECBM_TIMER3_MODE 0x40
//</e>
//<e>定时器4使能与设置
//<i>勾选该选项会使能定时器4，开放和定时器4相关的操作函数。若未使用定时器4，可以关掉优化空间。
//<i>定时器4固定为16位自动重载模式。
#define ECBM_TIMER4_EN 0
//<o.5>计数来源
//<0=>对系统时钟计数（定时器应用）  <1=>对外部T4（P06）脚的脉冲信号计数（计数器应用）
//<i>timer的本质就是计数器。对系统时钟计数时，由于时钟的周期T固定，计数值n可以从寄存器读出，那么就能通过t=nT算出时间。这样就能用作定时器。
//<i>因此如果外部脉冲信号也有固定不变的周期，那么也可以用外部脉冲信号来做定时器。不过一般外部信号都是随机的，没有固定周期，我们只能知道计数值n，所以就成了计数器。
//<o.6>时钟分频
//<i>就相当于STC-ISP工具里的12T模式和1T模式。
//<0=>系统时钟12分频（Fosc/12） <1=>系统时钟不分频
//<o.7>对外输出时钟
//<i>勾选该选项后，每次定时器4发生溢出时，T4CLKO（P07）脚的电平自动发生翻转。
#define ECBM_TIMER4_MODE 0x40
//</e>
//<e.15>掉电唤醒定时器
//<i>用于掉电唤醒的定时器，通过内置的32KHz时钟驱动。掉电后开始计数，当计到设置的数值时唤醒单片机。
//<o.0..14>计数次数
//<0-32767:1>
//<i>公式为：定时时间=（16000000*（计数次数+1））/Fwt。单位为微秒，其中Fwt为实际上的时钟频率，因为制造误差较大，需要从RAM区的F8H和F9H获取真实时钟频率。
//<i>范围：0~32767。
//<i>近似算法为：定时时间=0.5ms*（计数次数+1）。
#define ECBM_WKT 32767
//</e>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_TIMER_LINK_EN
#include "ecbm.h"//ECBM库的头文件，里面已经包含了STC8的头文件。
#else            //如果要脱离主库运行，也应该提供STC8的头文件。头文件可从STC-ISP工具当中生成。
#include "stc.h" //从STC-ISP工具生成时，命名为STC.h。
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
#define tim2_cls()      AUXINTIF &= ~T2IF //清中断标志
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
#define tim3_cls()      AUXINTIF &= ~T3IF //清中断标志
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
#define tim4_cls()      AUXINTIF&=~T4IF //清中断标志
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
		case 0:{//定时器0的配置方式
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
		case 1:{//定时器1的配置方式
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
		case 2:{//定时器2和4的配置方式
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
		case 3:{//定时器3的配置方式
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
		case 0:{//定时器0的配置方式
			tim0_start();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//定时器1的配置方式
			tim1_start();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//定时器2和4的配置方式
			if(tim->init.mode==1){//tim4
				tim4_start();
			}else{//tim2
				tim2_start();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//定时器3的配置方式
			tim3_start();
		}break;
		#endif
	}
}

void tim_stop(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//定时器0的配置方式
			tim0_stop();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//定时器1的配置方式
			tim1_stop();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//定时器2和4的配置方式
			if(tim->init.mode==1){//tim4
				tim4_stop();
			}else{//tim2
				tim2_stop();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//定时器3的配置方式
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
		case 0:{//定时器0的配置方式
			tim0_it_fun=it_fun;
			tim0_start_it();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//定时器1的配置方式
			tim1_it_fun=it_fun;
			tim1_start_it();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//定时器2和4的配置方式
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
		case 3:{//定时器3的配置方式
			tim3_it_fun=it_fun;
			tim3_start_it();
		}break;
		#endif
	}
}
void tim_stop_it(tim_def * tim){
	switch(tim->init.id){
		#if ECBM_TIMER0_EN
		case 0:{//定时器0的配置方式
			tim0_stop_it();
		}break;
		#endif
		#if ECBM_TIMER1_EN&&(SUART_EN==0)
		case 1:{//定时器1的配置方式
			tim1_stop_it();
		}break;
		#endif
		#if ECBM_TIMER2_EN||ECBM_TIMER4_EN
		case 2:{//定时器2和4的配置方式
			if(tim->init.mode==1){//tim4
				tim4_stop_it();
			}else{//tim2
				tim2_stop_it();
			}				
		}break;
		#endif
		#if ECBM_TIMER3_EN
		case 3:{//定时器3的配置方式
			tim3_stop_it();
		}break;
		#endif
	}
}
#endif
