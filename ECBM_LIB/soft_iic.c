#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_SOFT_IIC_EN
/*--------------------------------------变量定义-----------------------------------*/
u8 xdata soft_iic_def_sda_port;
u8 xdata soft_iic_def_sda_pin;
u8 xdata soft_iic_def_scl_port;
u8 xdata soft_iic_def_scl_pin;
u8 xdata soft_iic_max=0;
u8 xdata soft_iic_index=0;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
软件IIC引脚切换函数。
-------------------------------------------------------*/
void soft_iic_set_pin(soft_iic_def * dev){
	if(soft_iic_index!=dev->dev_id){
		soft_iic_def_scl_port=io2port(dev->scl_pin);
		soft_iic_def_scl_pin =io2pin (dev->scl_pin);
		soft_iic_def_sda_port=io2port(dev->sda_pin);
		soft_iic_def_sda_pin =io2pin (dev->sda_pin);
		soft_iic_index=dev->dev_id;
	}	
}
/*-------------------------------------------------------
软件IIC初始化函数。
-------------------------------------------------------*/
void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda){
	dev->scl_pin=scl;
	dev->sda_pin=sda;
	gpio_mode   (scl,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_mode   (sda,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_uppull (scl,1);    //IIC需要一个上拉电阻
	gpio_uppull (sda,1);    //IIC需要一个上拉电阻
	gpio_out    (scl,1);
	gpio_out    (sda,1);
	dev->dev_id =++soft_iic_max;
	soft_iic_set_pin(dev);
}
/*-------------------------------------------------------
软件IIC引脚切换函数（内联版）。
-------------------------------------------------------*/
void soft_iic_set_pin_linkage(u8 id,u8 scl,u8 sda){
	if(soft_iic_index!=id){
		soft_iic_def_scl_port=io2port(scl);
		soft_iic_def_scl_pin =io2pin (scl);
		soft_iic_def_sda_port=io2port(sda);
		soft_iic_def_sda_pin =io2pin (sda);
		soft_iic_index=id;
	}	
}
/*-------------------------------------------------------
软件IIC初始化函数（内联版）。
-------------------------------------------------------*/
u8 soft_iic_init_linkage(u8 scl,u8 sda){
	u8 id;
	gpio_mode   (scl,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_mode   (sda,GPIO_OD);//IIC的引脚需要是开漏模式
	gpio_uppull (scl,1);    //IIC需要一个上拉电阻
	gpio_uppull (sda,1);    //IIC需要一个上拉电阻
	gpio_out    (scl,1);
	gpio_out    (sda,1);
	id =++soft_iic_max;
	soft_iic_set_pin_linkage(id,scl,sda);
	return id;
}
/*-------------------------------------------------------
软件IIC启动函数。
-------------------------------------------------------*/
u8	soft_iic_start(void){
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
	if(gpio_in_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin)==0)return -1;/* SDA线为低电平则总线忙,退出 */
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,0);
	if(gpio_in_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin)==1)return -1;/* SDA线为高电平则总线出错,退出 */
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,0);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	return 0;
}
/*-------------------------------------------------------
软件IIC停止函数。
-------------------------------------------------------*/
void soft_iic_stop(void){
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,0);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
}
/*-------------------------------------------------------
软件IIC主机写ACK函数。
-------------------------------------------------------*/
void soft_iic_write_ack(void){
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,0);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
}
/*-------------------------------------------------------
软件IIC主机写NO ACK函数。
-------------------------------------------------------*/
void soft_iic_write_nack(void){
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
}
/*-------------------------------------------------------
软件IIC主机读ACK函数。
-------------------------------------------------------*/
u8 soft_iic_read_ack(void){
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
	if(gpio_in_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin)==1){
		gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
		return -1;
	}
	gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	return 0;
}
/*-------------------------------------------------------
软件IIC主机写函数。
-------------------------------------------------------*/
void soft_iic_write(u8 dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x80){
			gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
		}
		else{
			gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,0);
		}
		gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
		gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
		dat<<=1;
	}
}
/*-------------------------------------------------------
软件IIC主机读函数。
-------------------------------------------------------*/
u8 soft_iic_read(void){
	unsigned char i,dat;
	dat=0;
	gpio_out_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin,1);
	for(i=0;i<8;i++){
		dat<<=1;
		gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,1);
		if(gpio_in_fast(soft_iic_def_sda_port,soft_iic_def_sda_pin)==1){
			dat|=0x01;
		}
		gpio_out_fast(soft_iic_def_scl_port,soft_iic_def_scl_pin,0);
	}
	return dat;
}
/*-------------------------------------------------------
软件IIC主机寻找函数。
-------------------------------------------------------*/
u8 soft_iic_find(u8 addr[]){
	u8 i,c;
	c=0;
	for(i=0;i<128;i++){
		soft_iic_start();
		soft_iic_write(i<<1);
		if(soft_iic_read_ack()==0){
			addr[c]=(i<<1);
			c++;
		}
		soft_iic_stop();
	}	
	return c;
}
#endif