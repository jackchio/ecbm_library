#ifndef _ECBM_GPIO_H_
#define _ECBM_GPIO_H_
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
#define ECBM_GPIO_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ���ⲿ�жϣ�����Ϊ0��
//<h>�Ż�����
//<i>������ѡ��Ҫʹ��IO�ڡ������ò�����Px�ھͲ�����룬��Լflash�ռ䡣����8�ŵ�STC8F1K08ֻ��P3��P5����ôΪ��ѹ���ռ䣬ֻʹ��P3��P5���ɡ�
//<q>P0��ʹ��
#define ECBM_GPIO0_EN 1
//<q>P1��ʹ��
#define ECBM_GPIO1_EN 1
//<q>P2��ʹ��
#define ECBM_GPIO2_EN 1
//<q>P3��ʹ��
#define ECBM_GPIO3_EN 1
//<q>P4��ʹ��
#define ECBM_GPIO4_EN 0
//<q>P5��ʹ��
#define ECBM_GPIO5_EN 1
//<q>P6��ʹ��
#define ECBM_GPIO6_EN 0
//<q>P7��ʹ��
#define ECBM_GPIO7_EN 0
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_GPIO_LINK_EN
#include "ecbm.h"//ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
#else            //���Ҫ�����������У�ҲӦ���ṩSTC8��ͷ�ļ���ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ�
#include "stc.h" //��STC-ISP��������ʱ������ΪSTC.h��
#define u8 unsigned char
#endif

#if 1  //�����۵��궨����
/*
Ŀǰʵ��ֱ�Ӳ����Ĵ�����IO��ת�ٶ�Ϊ3.3MHz����ʹ��gpio_toggle�ﵽ144KHz�����Գ���������Ӧ�ӿ�
�����󣬷����Ƽ��ÿ⺯��������IO�ڡ�
*/
#define GPIO_PU 0
#define GPIO_HZ 1
#define GPIO_OD 2
#define GPIO_PP 3
#define GPIO_IN  GPIO_PU
#define GPIO_OUT GPIO_PP

#define	GPIO_PIN_0		0x01	//IO���� Px.0
#define	GPIO_PIN_1		0x02	//IO���� Px.1
#define	GPIO_PIN_2		0x04	//IO���� Px.2
#define	GPIO_PIN_3		0x08	//IO���� Px.3
#define	GPIO_PIN_4		0x10	//IO���� Px.4
#define	GPIO_PIN_5		0x20	//IO���� Px.5
#define	GPIO_PIN_6		0x40	//IO���� Px.6
#define	GPIO_PIN_7		0x80	//IO���� Px.7
#define	GPIO_PIN_All	0xFF	//IO��������

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
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	io_port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	/*-------����������������ɡ�-------*/
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
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
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
	/*-------����������������ɡ�-------*/
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
