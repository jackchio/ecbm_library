#ifndef _ECBM_IIC_H_
#define _ECBM_IIC_H_
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
//<i>此选项打勾，意味着IIC库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。
//<i>此选项不打勾，意味着IIC库能单独使用，不会再依赖其他ECBM库函数。只需要具备基本的stc8头文件即可。但此时若再加载ECBM库会有重定义报错的可能，请注意。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和iic.h置于同一个文件夹。
#define ECBM_IIC_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用IIC外设，请设为0。
//<h>IIC库内部设置
//<o>IIC等待时钟周期
//<0-63:1>
//<i>可输入0~63。该数字越小，即等待时钟越少，IIC的速度越快。如果目标器件的速度跟得上，可以设为0以获取最大的IIC通信速度。
//<i>如果目标器件的速度跟不上（一般通信出现乱码或直接通信失败），可以从63开始一步一步减少以获得最佳性能。嫌麻烦也可直接设为63。
#define ECBM_IIC_WAIT 1
//<o>IIC默认管脚
//<i>此设置只会改动初始化的管脚，在实际应用中随时可以使用iic_set_pin函数修改IIC管脚，达到分时复用的效果。
//<0=>SCL-P15|SDA-P14 <1=>SCL-P25|SDA-P24 <2=>SCL-P77|SDA-P76 <3=>SCL-P32|SDA-P33
#define ECBM_IIC_IO 3
//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------

/*---------------------------------------------加载头文件和预定义---------------------------------------------*/
#if ECBM_IIC_LINK_EN      //当连接到ecbm主库的时候，需要加载如下文件：
#include "ecbm.h"         //ECBM库的头文件，里面已经包含了STC8的头文件。
#else                     //如果要脱离主库运行，也应该提供STC8的头文件。头文件可从STC-ISP工具当中生成。
#include "stc.h"          //从STC-ISP工具生成时，命名为STC.h。
#include "intrins.h"      //使用nop指令所需的头文件
#define u8  unsigned char //独立使用IIC库时，将变量的简写补上。
#define u16 unsigned int
#define u32 unsigned long
#define s8    signed char
#define s16   signed int
#define s32   signed long
#endif
/*-----------------------------------------------------------------------------------------------------------*/
bit iic_busy;
void iic_isr() interrupt 24
{
    if (I2CMSST&0x40){
        I2CMSST&=~0x40;//清中断标志
        iic_busy=0;
    }
}
void iic_start(){
    iic_busy=1;
    I2CMSCR=0x81;   //发送START命令
    while(iic_busy);
}
void iic_stop(){
    iic_busy = 1;
    I2CMSCR=0x86;  //发送STOP命令
    while(iic_busy);
}
void iic_write(char dat){
    I2CTXD=dat;    //写数据到数据缓冲区
    iic_busy=1;
    I2CMSCR=0x82;  //发送SEND命令
    while(iic_busy);
}
void iic_write_ack(){
    I2CMSST=0x00; // 设置ACK信号
    iic_busy=1;
    I2CMSCR=0x85; //发送ACK命令
    while(iic_busy);  
}
void iic_write_nack(){
    I2CMSST=0x01; //设置NAK信号
    iic_busy=1;
    I2CMSCR=0x85; //发送ACK命令
    while(iic_busy);
}
char iic_read(){
    iic_busy=1;
    I2CMSCR=0x84;  //发送RECV命令
    while(iic_busy);
    return I2CRXD;
}
bit iic_read_ack(){
    iic_busy=1;
    I2CMSCR=0x83; //发送读ACK命令
    while(iic_busy);
	return (I2CMSST&0x02)>>1;
}
#if ECBM_IIC_LINK_EN
void iic_set_pin(u8 group){
	switch(group){
		case 0:{
			gpio_mode(D14,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_mode(D15,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_uppull(D14,1);    //IIC需要一个上拉电阻
			gpio_uppull(D15,1);    //IIC需要一个上拉电阻
			P_SW2&=0xCF;           //切换至D14和D15
		}break;
		case 1:{
			gpio_mode(D24,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_mode(D25,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_uppull(D24,1);    //IIC需要一个上拉电阻
			gpio_uppull(D25,1);    //IIC需要一个上拉电阻
			P_SW2&=0xDF;           //切换至D24和D25
			P_SW2|=0x10;
		}break;
		case 2:{
			gpio_mode(D76,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_mode(D77,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_uppull(D76,1);    //IIC需要一个上拉电阻
			gpio_uppull(D77,1);    //IIC需要一个上拉电阻
			P_SW2|=0x20;           //切换至D76和D77
			P_SW2&=0xEF;
		}break;
		case 3:{
			gpio_mode(D32,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_mode(D33,GPIO_OD);//IIC的引脚需要是开漏模式
			gpio_uppull(D32,1);    //IIC需要一个上拉电阻
			gpio_uppull(D33,1);    //IIC需要一个上拉电阻
			P_SW2|=0x30;           //切换至D32和D33
		}break;
	}
}
void iic_reset_pin(u8 group){
	switch(group){
		case 0:{
			gpio_mode(D14,GPIO_IN);//恢复弱上拉模式
			gpio_mode(D15,GPIO_IN);//恢复弱上拉模式
			gpio_uppull(D14,0);    //断开上拉电阻
			gpio_uppull(D15,0);    //断开上拉电阻
		}break;
		case 1:{
			gpio_mode(D24,GPIO_IN);//恢复弱上拉模式
			gpio_mode(D25,GPIO_IN);//恢复弱上拉模式
			gpio_uppull(D24,0);    //断开上拉电阻
			gpio_uppull(D25,0);    //断开上拉电阻
		}break;
		case 2:{
			gpio_mode(D76,GPIO_IN);//恢复弱上拉模式
			gpio_mode(D77,GPIO_IN);//恢复弱上拉模式
			gpio_uppull(D76,0);    //断开上拉电阻
			gpio_uppull(D77,0);    //断开上拉电阻         
		}break;
		case 3:{
			gpio_mode(D32,GPIO_IN);//恢复弱上拉模式
			gpio_mode(D33,GPIO_IN);//恢复弱上拉模式
			gpio_uppull(D32,0);    //断开上拉电阻
			gpio_uppull(D33,0);    //断开上拉电阻   
		}break;
	}
}
#else
void iic_set_pin(u8 group){
	switch(group){
		case 0:{
			P1M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P1M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P1PU|=0x30;//0011 0000 IIC需要一个上拉电阻
			P_SW2&=0xCF;           //切换至D14和D15
		}break;
		case 1:{
			P2M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P2M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P2PU|=0x30;//0011 0000 IIC需要一个上拉电阻
			P_SW2&=0xDF;           //切换至D24和D25
			P_SW2|=0x10;
		}break;
		case 2:{
			P7M1|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
			P7M0|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
			P7PU|=0xC0;//1100 0000 IIC需要一个上拉电阻
			P_SW2|=0x20;           //切换至D76和D77
			P_SW2&=0xEF;
		}break;
		case 3:{
			P3M1|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
			P3M0|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
			P3PU|=0x0C;//0000 1100 IIC需要一个上拉电阻
			P_SW2|=0x30;           //切换至D32和D33
		}break;
	}
}
void iic_reset_pin(u8 group){
	switch(group){
		case 0:{
			P1M1&=0xCF;//1100 1111 恢复弱上拉模式
			P1M0&=0xCF;//1100 1111 恢复弱上拉模式
			P1PU&=0xCF;//1100 1111 断开上拉电阻
		}break;
		case 1:{
			P2M1&=0xCF;//1100 1111 恢复弱上拉模式
			P2M0&=0xCF;//1100 1111 恢复弱上拉模式
			P2PU&=0xCF;//1100 1111 断开上拉电阻
		}break;
		case 2:{
			P7M1&=0x3F;//0011 1111 恢复弱上拉模式
			P7M0&=0x3F;//0011 1111 恢复弱上拉模式
			P7PU&=0x3F;//0011 1111 断开上拉电阻       
		}break;
		case 3:{
			P3M1&=0xF3;//1111 0011 恢复弱上拉模式
			P3M0&=0xF3;//1111 0011 恢复弱上拉模式
			P3PU&=0xF3;//1111 0011 断开上拉电阻
		}break;
	}
}
#endif
void iic_master_init(){
	#if ECBM_IIC_LINK_EN == 0       //如果是独立使用，则需要打开外扩寄存器的使能
	P_SW2|=0x80;
	_nop_();EA=1;_nop_();
	#endif
	I2CCFG=0x80|0x40|ECBM_IIC_WAIT; //开启IIC|主机|等待时钟
	I2CMSST=0x00;                   //清除所有标志位
	iic_set_pin(ECBM_IIC_IO);                 //默认使用0组，即P14和P15
}
void iic_slave_init(){
	#if ECBM_IIC_LINK_EN == 0       //如果是独立使用，则需要打开外扩寄存器的使能
	P_SW2|=0x80;
	_nop_();EA=1;_nop_();
	#endif
	I2CCFG=0x80|0x00|ECBM_IIC_WAIT; //开启IIC|从机|等待时钟
	I2CMSST=0x00;                   //清除所有标志位
	iic_set_pin(ECBM_IIC_IO);
}

#endif
