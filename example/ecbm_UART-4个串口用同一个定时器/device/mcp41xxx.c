#include "mcp41xxx.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
MCP41XXX系列的初始化函数。
-------------------------------------------------------*/
void mcp41xxx_init(mcp41xxx_def *dev,u8 cs,u8 sck,u8 dat){
	dev->cs=cs;				//保存片选脚。
	dev->sck=sck;			//保存时钟脚。
	dev->dat=dat;			//保存数据脚。
	gpio_mode(cs,GPIO_OUT);	//设置片选端为输出模式。
	gpio_mode(sck,GPIO_OUT);//设置时钟端为输出模式。
	gpio_mode(dat,GPIO_OUT);//设置数据端为输出模式。
	mcp41xxx_set_amp(dev,MCP41XXX_INIT_AMP);//设置初始化幅度。
}
/*-------------------------------------------------------
MCP41XXX系列的设置幅值函数。
-------------------------------------------------------*/
void mcp41xxx_set_amp(mcp41xxx_def *dev,u8 amp){
	u8 i;
	u16 temp;
	gpio_out(dev->cs,0);		//拉低片选端，开始传输数据。
	temp =0x1100|amp;			//由于MCP42XXX有额外的引脚，所以该程序只支持MCP41XXX，所以控制字固定为0x1100。
	for(i=0;i<16;i++){			//传输16字节数据。
		gpio_out(dev->sck,0);	//拉低时钟脚，准备数据。
		if(temp&0x8000){		//先发高位。
			gpio_out(dev->dat,1);//发送数据到数据脚。
		}else{
			gpio_out(dev->dat,0);
		}
		temp<<=1;				//取下一位。
		gpio_out(dev->sck,1);	//拉高时钟脚，通知器件读取数据。
	}
	gpio_out(dev->cs,1);		//拉高片选脚，结束通信。
}
