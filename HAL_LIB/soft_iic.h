#ifndef _ECBM_SOFT_IIC_H_
#define _ECBM_SOFT_IIC_H_
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
//<i>此选项打勾，意味着SOFT_IIC库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。
//<i>此选项不打勾，意味着SOFT_IIC库能单独使用，不会再依赖其他ECBM库函数。只需要具备基本的stc8头文件即可。但此时若再加载ECBM库会有重定义报错的可能，请注意。
//<i>单独使用SOFT_IIC库的话，需要手动把对应的IO口设置为开漏模式，并且在硬件上接入4.7K左右的上拉电阻。否则可能会有通信上的问题。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和iic.h置于同一个文件夹。
#define ECBM_SOFT_IIC_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用SOFT_IIC外设，请设为0。
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_SOFT_IIC_LINK_EN
typedef struct{
	u8 scl_port;
	u8 scl_pin;
	u8 sda_port;
	u8 sda_pin;
//	u16 iic_delay;
}soft_iic_def;
void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda){
	dev->scl_port=scl>>4;
	dev->scl_pin=0x01<<(scl&0x0f);
	dev->sda_port=sda>>4;
	dev->sda_pin=0x01<<(sda&0x0f);
	gpio_mode(scl,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_mode(sda,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_uppull(scl,1);    //IIC需要一个上拉电阻
	gpio_uppull(sda,1);    //IIC需要一个上拉电阻
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	dev->iic_delay=delay_set_us(1);
}
//IIC启动函数
u8	soft_iic_start(soft_iic_def * dev){
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==0)return -1;/* SDA线为低电平则总线忙,退出 */
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
//	delay_us(dev->iic_delay);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1)return -1;/* SDA线为高电平则总线出错,退出 */
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	return 0;
}
//IIC停止函数
void soft_iic_stop(soft_iic_def * dev){
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
}
//主机返回一个ACK
void soft_iic_write_ack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
}
//主机返回一个非ACk
void soft_iic_write_nack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
}
//等待从机发送一个ACK
unsigned char soft_iic_read_ack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1){
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
		return -1;
	}
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	return 0;
}
//向IIC总线上发送一个字节的数据
void soft_iic_write(soft_iic_def * dev,u8 dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x80){
			gpio_out_fast(dev->sda_port,dev->sda_pin,1);
		}
		else{
			gpio_out_fast(dev->sda_port,dev->sda_pin,0);
		}
		gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//		delay_us(dev->iic_delay);
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
		dat<<=1;
//		delay_us(dev->iic_delay);
	}
}
//向IIC总线上读取一个字节的数据
unsigned char soft_iic_read(soft_iic_def * dev){
	unsigned char i,dat;
	dat=0;
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	for(i=0;i<8;i++){
		dat<<=1;
		gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//		delay_us(dev->iic_delay);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1){
			dat|=0x01;
		}
//		else{
//			dat&=0xfe;
//		}
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
//		delay_us(dev->iic_delay);
	}
	return dat;
}
#else
sbit soft_iic_scl=P1^0;
sbit soft_iic_sda=P1^1;
void soft_iic_init(){
	soft_iic_sda=1;
	soft_iic_scl=1;
}
//IIC启动函数
u8	soft_iic_start(){
	soft_iic_sda=1;
	soft_iic_scl=1;
	if(soft_iic_sda==0)return -1;/* SDA线为低电平则总线忙,退出 */
	soft_iic_sda=0;
	if(soft_iic_sda==1)return -1;/* SDA线为高电平则总线出错,退出 */
	soft_iic_sda=0;
	soft_iic_scl=0;
	return 0;
}
//IIC停止函数
void soft_iic_stop(){
	soft_iic_sda=0;
	soft_iic_scl=0;
	soft_iic_scl=1;
	soft_iic_sda=1;
}
//主机返回一个ACK
void soft_iic_write_ack(){
	soft_iic_scl=0;
	soft_iic_sda=0;
	soft_iic_scl=1;
	soft_iic_scl=0;
}
//主机返回一个非ACk
void soft_iic_write_nack(){
	soft_iic_scl=0;
	soft_iic_sda=1;
	soft_iic_scl=1;
	soft_iic_scl=0;
}
//等待从机发送一个ACK
unsigned char soft_iic_read_ack(){
	soft_iic_scl=0;
	soft_iic_sda=1;
	soft_iic_scl=1;
	if(soft_iic_sda==1){
		soft_iic_scl=0;
		return -1;
	}
	soft_iic_scl=0;
	return 0;
}
//向IIC总线上发送一个字节的数据
void soft_iic_write(u8 dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x80){
			soft_iic_sda=1;
		}
		else{
			soft_iic_sda=0;
		}
		soft_iic_scl=1;
		soft_iic_scl=0;
		dat<<=1;
	}
}
//向IIC总线上读取一个字节的数据
unsigned char soft_iic_read(){
	unsigned char i,dat;
	dat=0;
	soft_iic_sda=1;
	for(i=0;i<8;i++){
		dat<<=1;
		soft_iic_scl=1;
		if(soft_iic_sda==1){
			dat|=0x01;
		}
		soft_iic_scl=0;
	}
	return dat;
}
#endif
#endif
