#include "mcp4725.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
MCP4725的初始化函数。使用软件IIC。
-------------------------------------------------------*/
void mcp4725_soft_init(mcp4725_def * dev,u8 scl,u8 sda){
	dev->config=MCP4725_SOFT_IIC;//设置为软件IIC的形式。
	dev->scl_pin=scl;//保存时钟脚。
	dev->sda_pin=sda;//保存数据脚。
	dev->addr=0xC0;	 //设置默认的芯片地址。
	dev->id=soft_iic_init_linkage(scl,sda);//初始化软件IIC，并获取ID号。
}
/*-------------------------------------------------------
MCP4725的初始化函数。使用硬件IIC。
-------------------------------------------------------*/
void mcp4725_hard_init(mcp4725_def * dev,u8 scl,u8 sda){
	dev->config=MCP4725_HARD_IIC;//设置为硬件IIC的形式。
	dev->scl_pin=scl;//保存时钟脚。
	dev->sda_pin=sda;//保存数据脚。
	dev->addr=0xC0;	 //设置默认的芯片地址。
	iic_master_init();
	dev->id=0;
}
/*-------------------------------------------------------
MCP4725的设置地址函数。
-------------------------------------------------------*/
void mcp4725_set_addr(mcp4725_def * dev,u8 addr){
	dev->addr=0xC0;						//高位的0xC0是固定的，
	if((addr>=0)&&(addr<=7)){			//如果地址在正确的范围内。
		dev->addr=(dev->addr)|(addr<<1);//IIC的D0是读写位，所以要左移1位。
	}
}
/*-------------------------------------------------------
MCP4725的运行函数。
-------------------------------------------------------*/
void mcp4725_run(mcp4725_def * dev,u16 dat){
	if((dev->config&MCP4725_IIC_MASK)==MCP4725_SOFT_IIC){
		soft_iic_set_pin_linkage(dev->id,dev->scl_pin,dev->sda_pin);//切换管脚。
		soft_iic_start   ();			//开始通信。
		soft_iic_write   (dev->addr);	//先写IIC地址。
		soft_iic_read_ack();			//等待回应。
		soft_iic_write   (0x00|((u8)(dat>>8)&0x0f));//快速模式、只写入寄存器，同时写高4位。
		soft_iic_read_ack();			//等待回应。
		soft_iic_write   ((u8)dat);		//写低8位。
		soft_iic_read_ack();			//等待回应。
		soft_iic_stop    ();			//结束通信。
	}else{
		iic_start   ();			//开始通信。
		iic_write   (dev->addr);//先写IIC地址。
		iic_read_ack();			//等待回应。
		iic_write   (0x00|((u8)(dat>>8)&0x0f));//快速模式、只写入寄存器，同时写高4位。
		iic_read_ack();			//等待回应。
		iic_write   ((u8)dat);	//写低8位。
		iic_read_ack();			//等待回应。
		iic_stop    ();			//结束通信。
	}
}
/*-------------------------------------------------------
MCP4725的输出函数。
-------------------------------------------------------*/
void mcp4725_out(mcp4725_def * dev,float vcc,float out){
	mcp4725_run(dev,(u16)(out/vcc*4096));
}