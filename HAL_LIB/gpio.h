#ifndef _ECBM_GPIO_H_
#define _ECBM_GPIO_H_
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
#define ECBM_GPIO_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用外部中断，请设为0。
//<h>优化设置
//<i>在这里选择将要使用IO口。这样用不到的Px口就不会编译，节约flash空间。比如8脚的STC8F1K08只有P3和P5，那么为了压缩空间，只使能P3和P5即可。
//<q>P0口使能
#define ECBM_GPIO0_EN 1
//<q>P1口使能
#define ECBM_GPIO1_EN 1
//<q>P2口使能
#define ECBM_GPIO2_EN 1
//<q>P3口使能
#define ECBM_GPIO3_EN 1
//<q>P4口使能
#define ECBM_GPIO4_EN 0
//<q>P5口使能
#define ECBM_GPIO5_EN 1
//<q>P6口使能
#define ECBM_GPIO6_EN 0
//<q>P7口使能
#define ECBM_GPIO7_EN 0
//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_GPIO_LINK_EN
#include "ecbm.h"//ECBM库的头文件，里面已经包含了STC8的头文件。
#else            //如果要脱离主库运行，也应该提供STC8的头文件。头文件可从STC-ISP工具当中生成。
#include "stc.h" //从STC-ISP工具生成时，命名为STC.h。
#define u8 unsigned char
#endif

#if 1  //快速折叠宏定义项
/*
目前实测直接操作寄存器的IO翻转速度为3.3MHz。而使用gpio_toggle达到144KHz。所以除非有自适应接口
的需求，否则不推荐用库函数来控制IO口。
*/
#define GPIO_PU 0
#define GPIO_HZ 1
#define GPIO_OD 2
#define GPIO_PP 3
#define GPIO_IN  GPIO_PU
#define GPIO_OUT GPIO_PP

#define	GPIO_PIN_0		0x01	//IO引脚 Px.0
#define	GPIO_PIN_1		0x02	//IO引脚 Px.1
#define	GPIO_PIN_2		0x04	//IO引脚 Px.2
#define	GPIO_PIN_3		0x08	//IO引脚 Px.3
#define	GPIO_PIN_4		0x10	//IO引脚 Px.4
#define	GPIO_PIN_5		0x20	//IO引脚 Px.5
#define	GPIO_PIN_6		0x40	//IO引脚 Px.6
#define	GPIO_PIN_7		0x80	//IO引脚 Px.7
#define	GPIO_PIN_All	0xFF	//IO所有引脚

#define	GPIO_P0			0		
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5
#define	GPIO_P6			6
#define	GPIO_P7			7

#define D00 0x00
#define D01 0x01
#define D02 0x02
#define D03 0x03
#define D04 0x04
#define D05 0x05
#define D06 0x06
#define D07 0x07

#define D10 0x10
#define D11 0x11
#define D12 0x12
#define D13 0x13
#define D14 0x14
#define D15 0x15
#define D16 0x16
#define D17 0x17

#define D20 0x20
#define D21 0x21
#define D22 0x22
#define D23 0x23
#define D24 0x24
#define D25 0x25
#define D26 0x26
#define D27 0x27

#define D30 0x30
#define D31 0x31
#define D32 0x32
#define D33 0x33
#define D34 0x34
#define D35 0x35
#define D36 0x36
#define D37 0x37

#define D40 0x40
#define D41 0x41
#define D42 0x42
#define D43 0x43
#define D44 0x44
#define D45 0x45
#define D46 0x46
#define D47 0x47

#define D50 0x50
#define D51 0x51
#define D52 0x52
#define D53 0x53
#define D54 0x54
#define D55 0x55
#define D56 0x56
#define D57 0x57

#define D60 0x60
#define D61 0x61
#define D62 0x62
#define D63 0x63
#define D64 0x64
#define D65 0x65
#define D66 0x66
#define D67 0x67

#define D70 0x70
#define D71 0x71
#define D72 0x72
#define D73 0x73
#define D74 0x74
#define D75 0x75
#define D76 0x76
#define D77 0x77
#endif

void gpio_write(u8 port,u8 dat){
	switch(port){
		#if ECBM_GPIO0_EN
		case GPIO_P0:P0=dat;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:P1=dat;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:P2=dat;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:P3=dat;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:P4=dat;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:P5=dat;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:P6=dat;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:P7=dat;break;
		#endif
	}	
}

u8 gpio_read(u8 port){
	switch(port){
		#if ECBM_GPIO0_EN
		case GPIO_P0:return P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:return P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:return P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:return P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:return P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:return P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:return P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:return P7;break;
		#endif
	}
	return 0xFF;
}

void gpio_uppull(u8 pin,bit en){
	u8 io_port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	io_port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	/*-------到这里结束，解读完成。-------*/
	if(en){
		switch(io_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU|=io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU|=io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU|=io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU|=io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU|=io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU|=io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU|=io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU|=io_pin;break;
			#endif
			default:LED_ON;while(1);break;
		}
	}else{
		switch(io_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU&=~io_pin;break;
			#endif
			default:LED_ON;while(1);break;
		}
	}
}

void gpio_mode(u8 pin,u8 mode){
	u8 io_port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	io_port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	switch(io_port){
		#if ECBM_GPIO0_EN
		case 0x00:io_port=GPIO_P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:io_port=GPIO_P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:io_port=GPIO_P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:io_port=GPIO_P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:io_port=GPIO_P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:io_port=GPIO_P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:io_port=GPIO_P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:io_port=GPIO_P7;break;
		#endif
		default:LED_ON;while(1);break;
	}
	/*-------到这里结束，解读完成。-------*/
	#if ECBM_GPIO0_EN
	if(io_port==GPIO_P0){
		if(mode==GPIO_PU){P0M1&=~io_pin;P0M0&=~io_pin;}
		if(mode==GPIO_HZ){P0M1|= io_pin;P0M0&=~io_pin;}
		if(mode==GPIO_OD){P0M1|= io_pin;P0M0|= io_pin;}
		if(mode==GPIO_PP){P0M1&=~io_pin;P0M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO1_EN
	if(io_port==GPIO_P1){
		if(mode==GPIO_PU){P1M1&=~io_pin;P1M0&=~io_pin;}
		if(mode==GPIO_HZ){P1M1|= io_pin;P1M0&=~io_pin;}
		if(mode==GPIO_OD){P1M1|= io_pin;P1M0|= io_pin;}
		if(mode==GPIO_PP){P1M1&=~io_pin;P1M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO2_EN
	if(io_port==GPIO_P2){
		if(mode==GPIO_PU){P2M1&=~io_pin;P2M0&=~io_pin;}
		if(mode==GPIO_HZ){P2M1|= io_pin;P2M0&=~io_pin;}
		if(mode==GPIO_OD){P2M1|= io_pin;P2M0|= io_pin;}
		if(mode==GPIO_PP){P2M1&=~io_pin;P2M0|= io_pin;}
	}	
	#endif
	#if ECBM_GPIO3_EN
	if(io_port==GPIO_P3){
		if(mode==GPIO_PU){P3M1&=~io_pin;P3M0&=~io_pin;}
		if(mode==GPIO_HZ){P3M1|= io_pin;P3M0&=~io_pin;}
		if(mode==GPIO_OD){P3M1|= io_pin;P3M0|= io_pin;}
		if(mode==GPIO_PP){P3M1&=~io_pin;P3M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO4_EN
	if(io_port==GPIO_P4){
		if(mode==GPIO_PU){P4M1&=~io_pin;P4M0&=~io_pin;}
		if(mode==GPIO_HZ){P4M1|= io_pin;P4M0&=~io_pin;}
		if(mode==GPIO_OD){P4M1|= io_pin;P4M0|= io_pin;}
		if(mode==GPIO_PP){P4M1&=~io_pin;P4M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO5_EN
	if(io_port==GPIO_P5){
		if(mode==GPIO_PU){P5M1&=~io_pin;P5M0&=~io_pin;}
		if(mode==GPIO_HZ){P5M1|= io_pin;P5M0&=~io_pin;}
		if(mode==GPIO_OD){P5M1|= io_pin;P5M0|= io_pin;}
		if(mode==GPIO_PP){P5M1&=~io_pin;P5M0|= io_pin;}
	}	
	#endif
	#if ECBM_GPIO6_EN
	if(io_port==GPIO_P6){
		if(mode==GPIO_PU){P6M1&=~io_pin;P6M0&=~io_pin;}
		if(mode==GPIO_HZ){P6M1|= io_pin;P6M0&=~io_pin;}
		if(mode==GPIO_OD){P6M1|= io_pin;P6M0|= io_pin;}
		if(mode==GPIO_PP){P6M1&=~io_pin;P6M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO7_EN
	if(io_port==GPIO_P7){
		if(mode==GPIO_PU){P7M1&=~io_pin;P7M0&=~io_pin;}
		if(mode==GPIO_HZ){P7M1|= io_pin;P7M0&=~io_pin;}
		if(mode==GPIO_OD){P7M1|= io_pin;P7M0|= io_pin;}
		if(mode==GPIO_PP){P7M1&=~io_pin;P7M0|= io_pin;}
	}	
	#endif
}
void gpio_out(u8 pin,bit value){
	u8 port,io_pin;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if(value){
		switch(port){
			#if ECBM_GPIO0_EN
			case 0x00:P0|=io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1|=io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2|=io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3|=io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4|=io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5|=io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6|=io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7|=io_pin;break;
			#endif
			default:LED_ON;while(1);break;
		}
	}else{
		switch(port){
			#if ECBM_GPIO0_EN
			case 0x00:P0&=~io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1&=~io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2&=~io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3&=~io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4&=~io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5&=~io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6&=~io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7&=~io_pin;break;
			#endif
			default:LED_ON;while(1);break;
		}		
	}
}

bit  gpio_in(u8 pin){
	u8 port,io_pin,value;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	switch(port){
		#if ECBM_GPIO0_EN
		case 0x00:value=P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:value=P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:value=P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:value=P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:value=P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:value=P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:value=P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:value=P7;break;
		#endif
		default:LED_ON;while(1);break;		
	}
	if(value&io_pin)return 1;
	else return 0;
}
void gpio_toggle(u8 pin){
	u8 port,io_pin;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	switch(port){
		#if ECBM_GPIO0_EN
		case 0x00:P0^=io_pin;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:P1^=io_pin;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:P2^=io_pin;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:P3^=io_pin;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:P4^=io_pin;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:P5^=io_pin;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:P6^=io_pin;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:P7^=io_pin;break;
		#endif
		default:LED_ON;while(1);break;
	}
}
void gpio_toggle_fast(u8 port,u8 pin){
	switch(port){
		#if ECBM_GPIO0_EN
		case GPIO_P0:P0^=pin;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:P1^=pin;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:P2^=pin;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:P3^=pin;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:P4^=pin;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:P5^=pin;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:P6^=pin;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:P7^=pin;break;
		#endif
		default:LED_ON;while(1);break;
	}
}
void gpio_out_fast(u8 port,u8 pin,bit val){
	if(val){
		switch(port){
			#if ECBM_GPIO0_EN
			case GPIO_P0:P0|=pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case GPIO_P1:P1|=pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case GPIO_P2:P2|=pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case GPIO_P3:P3|=pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case GPIO_P4:P4|=pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case GPIO_P5:P5|=pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case GPIO_P6:P6|=pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case GPIO_P7:P7|=pin;break;
			#endif
		} 
	}else{
		switch(port){
			#if ECBM_GPIO0_EN
			case GPIO_P0:P0&=~pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case GPIO_P1:P1&=~pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case GPIO_P2:P2&=~pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case GPIO_P3:P3&=~pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case GPIO_P4:P4&=~pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case GPIO_P5:P5&=~pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case GPIO_P6:P6&=~pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case GPIO_P7:P7&=~pin;break;
			#endif
		} 
	}
}
bit gpio_in_fast(u8 port,u8 pin){
	u8 val;
	switch(port){
		#if ECBM_GPIO0_EN
		case GPIO_P0:val=P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:val=P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:val=P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:val=P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:val=P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:val=P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:val=P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:val=P7;break;
		#endif
	} 
	if(val&pin)return 1;
	else return 0;
}
#endif
