#ifndef _ECBM_LCD1602_H_
#define _ECBM_LCD1602_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 奈特

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
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM主库连接使能
//<i>此选项打勾，意味着LCD1602库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。并且支持多器件下的代码复用。
//<i>此选项不打勾，意味着LCD1602库能单独使用，不会再依赖其他ECBM库函数。需要移植基本的构造函数。但此时若再加载ECBM库会有重定义报错的可能，请注意。
#define ECBM_LINK_LCD1602_BIT 1 //和ECBM库连接的使能，如果想脱离主库单独使用LCD1602外设，请设为0。
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------

#define LCD_CMD 0            //定义传输的类型是指令
#define LCD_DAT 1            //定义传输的类型是数据
#define LCD_CURSOR_ON        0x02//有光标
#define LCD_CURSOR_OFF       0x00//无光标
#define LCD_CURSOR_ON_FLASH  0x03//有光标并闪烁
#define LCD_CURSOR_OFF_FLASH 0x01//无光标并闪烁
#define LCD_CURSOR_LEFT      0x10//光标左移
#define LCD_CURSOR_RIGHT     0x14//光标右移

#if ECBM_LINK_LCD1602_BIT     //如果需要加载主库
#include "ecbm_core.h"            //加载ecbm头文件
typedef struct{
	u8 lcd_rs_port;          //对应RS脚
	u8 lcd_rs_pin;
	u8 lcd_rw_port;          //对应RW脚
	u8 lcd_rw_pin;
	u8 lcd_en_port;          //对应EN脚
	u8 lcd_en_pin;
	u8 lcd_data_port;        //对应D0~D7
}lcd1602_def;
void lcd_write(lcd1602_def * dev,bit cla,u8 dat){//写入函数
	gpio_out_fast(dev->lcd_rs_port,dev->lcd_rs_pin,cla);		
	gpio_out_fast(dev->lcd_rw_port,dev->lcd_rw_pin,0);
	gpio_write(dev->lcd_data_port,dat);
	delay_ms(1);
	gpio_out_fast(dev->lcd_en_port,dev->lcd_en_pin,1);
	gpio_out_fast(dev->lcd_en_port,dev->lcd_en_pin,0);
}
void lcd_clear(lcd1602_def * dev){//清屏，需要ms级别的时间。
	lcd_write(dev,LCD_CMD,0x01);
}
void lcd_reset_cursor(lcd1602_def * dev){//光标回到左上角
	lcd_write(dev,LCD_CMD,0x02);
}
void lcd_set_cursor(lcd1602_def * dev,u8 cmd){//光标操作函数
	if(cmd<4)lcd_write(dev,LCD_CMD,0x0C|cmd);
	else lcd_write(dev,LCD_CMD,cmd);
}
void lcd1602_printf(lcd1602_def * dev,u8 hang,u8 lie,char * str,...){//打印函数，将字符打印到LCD1602上
	char xdata buf[16],n,i;
	va_list vp;
    va_start(vp, str);
    n=vsprintf(buf,str,vp);
    va_end(vp);
	if(hang==0){
		lcd_write(dev,LCD_CMD,0x80+lie); 
	}else if(hang==1){
		lcd_write(dev,LCD_CMD,0xC0+lie); 
	}
	for(i=0;i<n;i++){
		lcd_write(dev,LCD_DAT,buf[i]); 
	}
}
void lcd1602_init(lcd1602_def * dev,u8 rs,u8 rw,u8 en,u8 port){//初始化函数，需要提供使用的IO等信息
	dev->lcd_rs_port=io2port(rs);
	dev->lcd_rs_pin=io2pin(rs);
	dev->lcd_rw_port=io2port(rw);
	dev->lcd_rw_pin=io2pin(rw);
	dev->lcd_en_port=io2port(en);
	dev->lcd_en_pin=io2pin(en);
	dev->lcd_data_port=port;
	lcd_write(dev,LCD_CMD,0x38);//8位数据，双列，5*7字形 
	lcd_write(dev,LCD_CMD,0x0C);//开启显示屏，关光标，光标不闪烁 
	lcd_write(dev,LCD_CMD,0x06);//显示地址递增，即写一个数据后，显示位置右移一位 
	lcd_clear(dev);//清屏 
	delay_ms(2);
}
#else    //脱离主库使用请在这里开始移植
#include "intrins.h"
#include <STDARG.H>
#include <stdio.h>
#define u8 unsigned char
sbit lcd_rs=P5^0;    //修改使用的IO口
sbit lcd_rw=P5^1;    //修改使用的IO口
sbit lcd_en=P5^2;    //修改使用的IO口
#define lcd_data P4  //修改使用的IO口
void Delay1ms()		 //在STC-ISP工具中
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
void lcd_write(bit cla,u8 dat){
	lcd_rs=cla;		
	lcd_rw=0;
	lcd_data=dat;
	Delay1ms();
	lcd_en=1;
	lcd_en=0;
}
void lcd_clear(){
	lcd_write(LCD_CMD,0x01);
}
void lcd_reset_cursor(){
	lcd_write(LCD_CMD,0x02);
}
void lcd_set_cursor(u8 cmd){
	if(cmd<4)lcd_write(LCD_CMD,0x0C|cmd);
	else lcd_write(LCD_CMD,cmd);
}

void lcd1602_printf(u8 hang,u8 lie,char * str,...){
	char xdata buf[16],n,i;
	va_list vp;
    va_start(vp, str);
    n=vsprintf(buf,str,vp);
    va_end(vp);
	if(hang==0){
		lcd_write(LCD_CMD,0x80+lie); 
	}else if(hang==1){
		lcd_write(LCD_CMD,0xC0+lie); 
	}
	for(i=0;i<n;i++){
		lcd_write(LCD_DAT,buf[i]); 
	}
}
void lcd1602_init(){
	lcd_write(LCD_CMD,0x38);//8位数据，双列，5*7字形 
	lcd_write(LCD_CMD,0x0C);//开启显示屏，关光标，光标不闪烁 
	lcd_write(LCD_CMD,0x06);//显示地址递增，即写一个数据后，显示位置右移一位 
	lcd_clear();//清屏 
	Delay1ms();
	Delay1ms();
}
#endif
#endif
