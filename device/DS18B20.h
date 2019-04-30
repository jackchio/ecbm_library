#ifndef _ECBM_DS18B20_H_
#define _ECBM_DS18B20_H_
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
//<i>此选项打勾，意味着DS18B20库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。并且支持多器件下的代码复用。
//<i>此选项不打勾，意味着DS18B20库能单独使用，不会再依赖其他ECBM库函数。需要移植基本的构造函数。但此时若再加载ECBM库会有重定义报错的可能，请注意。
#define ECBM_DS18B20_LINK_EN 0 //和ECBM库连接的使能，如果想脱离主库单独使用DS18B20外设，请设为0。
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_DS18B20_LINK_EN
#include "ecbm.h"
typedef struct{//结构体只适用于多器件复用，在单器件的情况下，省掉还能节约至少6字节的空间
	u8 port;
	u8 pin;
	float temp;
}ds18b20_def;
void ds18b20_init(ds18b20_def * dev,u8 pin){
	dev->port=pin>>4;
	dev->pin=0x01<<(pin&0x0f);
	gpio_mode(pin,GPIO_PP);
}
void ds18b20_write(ds18b20_def * dev,u8 dat){
	u8 i;
	for(i=0;i<8;i++){
		if(dat&0x01){
			gpio_out_fast(dev->port,dev->pin,0);//拉低总线，开始通信。
			delay_us(_10us);       //在15us（18B20最小采集时间）
			gpio_out_fast(dev->port,dev->pin,1);//前拉高总线。
			delay_us(_70us);       //延时70us，加前面的10us共80us时间（大于18B20最大采集时间）
		}
		else{
			gpio_out_fast(dev->port,dev->pin,0);//拉低总线，开始通信。
			delay_us(_70us);       //延时70us（超过18B20的最大采集时间）
			gpio_out_fast(dev->port,dev->pin,1);//拉高总线。
			delay_us(_10us);       //加入延时，使得写1写0的时间一致。		
		}
		dat>>=1;
	}
}
u8 ds18b20_read(ds18b20_def * dev){
	u8 i,dat=0;
	for(i=0;i<8;i++){
		
		gpio_out_fast(dev->port,dev->pin,0); //拉低总线，开始通信。
		dat>>=1;              //移动最高位下来，留出空间。
		gpio_out_fast(dev->port,dev->pin,1); //IO置一，为了读取IO状态。	
		delay_us(_10us);        //官方推荐在拉低总线后15us内读取，考虑库函数执行也要时间，就延时10us。
		if(gpio_in_fast(dev->port,dev->pin)){//读取IO状态。
		
			dat|=0x80;		  //是高电平就在高位补上1，是低电平就让右移指令自动补0。
		}
		delay_us(_50us);        //读取的时间要在60us，现在延时50us加上面的20us共70us。
	}
	return dat;
}
u8 ds18b20_check(ds18b20_def * dev){
	gpio_out_fast(dev->port,dev->pin,0);  //拉低总线，开始通信。
	delay_us(_500us);        //拉低500us(复位时间480us~960us)。
	gpio_out_fast(dev->port,dev->pin,1);		
	delay_us(_60us);         //等待DS18B20相应（需要等待15us~60us）。
	if(gpio_in_fast(dev->port,dev->pin)==0){
		return 1;          //总线被DS18B20拉低说明器件存在。
	}
	return 0;              //0表示器件不存在。
}
u8 ds18b20_run(ds18b20_def * dev){
	u8 h,l;
	u16 temp;
	if(ds18b20_check(dev)){
		delay_us(_100us);
		ds18b20_write(dev,0xcc);
		ds18b20_write(dev,0x44);
	}else return 1;
	if(ds18b20_check(dev)){
		delay_us(_100us);
		ds18b20_write(dev,0xcc);
		ds18b20_write(dev,0xbe);
		
		l=ds18b20_read(dev);
		h=ds18b20_read(dev);
		ds18b20_check(dev);
		temp=(h<<8)|l;
		if(temp&0x8000){
			temp=(~temp)+1;
			dev->temp=-((float)temp*0.0625f);
			
		}else{
			dev->temp=((float)temp*0.0625f);
		}
		return 0; 
	}else return 1;
}
#else
/*请根据公式（该公式只适用于STC8！）来计算延时值。
              延时值=延时时间*（时钟/10）。
例子1：
    现在stc8单片机运行在24MHz频率上，那么延时10us的
延时值=10*（24/10）=24；于是在下面的定义中填上24，即
#define _10us 24  
例子2：
    现在stc8单片机运行在11.0592MHz频率上，那么延时10us的
延时值=10*（11.0592/10）=11；结果保留整数。于是在下面的
定义中填上11，即#define _10us 11  
以此类推。
*/
#include "stc.h"     //移植请提供相应的头文件
#define _10us  13    //移植请修改延时值
#define _15us  20 
#define _50us  67
#define _60us  81
#define _70us  95
#define _100us 134
#define _500us 670
sbit    DS18B20=P3^3;   //移植请修改引脚,并修改下面的设置，将对应引脚设置为推挽模式。
#define GPIO_MODE_PP P3M1 &= 0xf7; P3M0 |= 0x08; //P3(00001000B,00001000B)

#define u8 unsigned char
#define u16 unsigned int
void delay_us(unsigned int us){
	unsigned int i;
	i = us;
	while (i--);
}
void ds18b20_init(){
	DS18B20=1;
	GPIO_MODE_PP;
}
void ds18b20_write(unsigned char dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x01){
			DS18B20=0;//拉低总线，开始通信。
			delay_us(_10us);       //在15us（18B20最小采集时间）
			DS18B20=1;;//前拉高总线。
			delay_us(_70us);       //延时70us，加前面的10us共80us时间（大于18B20最大采集时间）
		}
		else{
			DS18B20=0;//拉低总线，开始通信。
			delay_us(_70us);       //延时70us（超过18B20的最大采集时间）
			DS18B20=1;//拉高总线。
			delay_us(_10us);       //加入延时，使得写1写0的时间一致。		
		}
		dat>>=1;
	}
}
u8 ds18b20_read(){
	unsigned char i,dat=0;
	for(i=0;i<8;i++){
		DS18B20=0;//拉低总线，开始通信。
		dat>>=1;              //移动最高位下来，留出空间。
		DS18B20=1;//IO置一，为了读取IO状态。	
		delay_us(_15us);        //官方推荐在拉低总线后15us内读取。
		if(DS18B20){//读取IO状态。
			dat|=0x80;		  //是高电平就在高位补上1，是低电平就让右移指令自动补0。
		}
		delay_us(_50us);        //读取的时间要在60us，现在延时50us加上面的20us共70us。
	}
	return dat;
}
unsigned char ds18b20_check(){
	DS18B20=0;//拉低总线，开始通信。
	delay_us(_500us);        //拉低500us(复位时间480us~960us)。
	DS18B20=1;	
	delay_us(_60us);         //等待DS18B20相应（需要等待15us~60us）。
	if(DS18B20==0){
		return 1;          //总线被DS18B20拉低说明器件存在。
	}
	return 0;              //0表示器件不存在。
}
float ds18b20_run(){
	unsigned char h,l;
	unsigned int temp;
	if(ds18b20_check()){
		delay_us(_100us);
		ds18b20_write(0xcc);
		ds18b20_write(0x44);
	}else return -999.0f;
	if(ds18b20_check()){
		delay_us(_100us);
		ds18b20_write(0xcc);
		ds18b20_write(0xbe);
		
		l=ds18b20_read();
		h=ds18b20_read();
		ds18b20_check();
		temp=(h<<8)|l;
		return ((float)temp*0.0625f); 
	}else return -999.0f;
}
#endif
#endif
