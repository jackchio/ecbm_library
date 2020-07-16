#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_IIC_EN
/*--------------------------------------变量定义-----------------------------------*/
bit iic_busy;
u8 xdata iic_index;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
IIC的引脚设置函数。
-------------------------------------------------------*/
void iic_set_pin(u8 group){
	switch(group){
		case IIC_PIN_P1:{//切换至D14和D15
			P1M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P1M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P1PU|=0x30;//0011 0000 IIC需要一个上拉电阻       
		}break;
		case IIC_PIN_P2:{//切换至D24和D25
			P2M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P2M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
			P2PU|=0x30;//0011 0000 IIC需要一个上拉电阻
		}break;
		case IIC_PIN_P7:{//切换至D76和D77
			P7M1|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
			P7M0|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
			P7PU|=0xC0;//1100 0000 IIC需要一个上拉电阻
		}break;
		case IIC_PIN_P3:{//切换至D32和D33
			P3M1|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
			P3M0|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
			P3PU|=0x0C;//0000 1100 IIC需要一个上拉电阻
		}break;
		#if SYS_ERROR_EN
		default:error_printf("iic_set_pin(<%d>);不存在该组\r\n",(u16)group);break;
		#else
		default:while(1);break;
		#endif
	}
	P_SW2&=0xCF;
	P_SW2|=group;
}
/*-------------------------------------------------------
IIC的引脚设置函数（内联版）。
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group){
	if(iic_index!=group){
		iic_index=group;
		I2CCFG&=0x7F;
		P_SW2&=0xCF;
		P_SW2|=group;
		I2CCFG|=0x80;
	}
}
/*-------------------------------------------------------
IIC的引脚还原函数。
-------------------------------------------------------*/
void iic_reset_pin(u8 group){
	switch(group){
		case IIC_PIN_P1:{
			P1M1&=0xCF;//1100 1111 恢复弱上拉模式
			P1M0&=0xCF;//1100 1111 恢复弱上拉模式
			P1PU&=0xCF;//1100 1111 断开上拉电阻
		}break;
		case IIC_PIN_P2:{
			P2M1&=0xCF;//1100 1111 恢复弱上拉模式
			P2M0&=0xCF;//1100 1111 恢复弱上拉模式
			P2PU&=0xCF;//1100 1111 断开上拉电阻
		}break;
		case IIC_PIN_P7:{
			P7M1&=0x3F;//0011 1111 恢复弱上拉模式
			P7M0&=0x3F;//0011 1111 恢复弱上拉模式
			P7PU&=0x3F;//0011 1111 断开上拉电阻       
		}break;
		case IIC_PIN_P3:{
			P3M1&=0xF3;//1111 0011 恢复弱上拉模式
			P3M0&=0xF3;//1111 0011 恢复弱上拉模式
			P3PU&=0xF3;//1111 0011 断开上拉电阻
		}break;
		#if SYS_ERROR_EN
		default:error_printf("iic_reset_pin(<%d>);不存在该组\r\n",(u16)group);break;
		#else
		default:while(1);break;
		#endif
	}
}
/*-------------------------------------------------------
IIC主机初始化函数。
-------------------------------------------------------*/
void iic_master_init(void){
	I2CCFG=0x80|0x40|ECBM_IIC_WAIT; //开启IIC|主机|等待时钟
	I2CMSST=0x00;                   //清除所有标志位
	iic_set_pin(ECBM_IIC_IO);       //默认使用0组，即P14和P15
	iic_index=ECBM_IIC_IO;
}
/*-------------------------------------------------------
IIC从机初始化函数。
-------------------------------------------------------*/
void iic_slave_init(void){
	I2CCFG=0x80|0x00|ECBM_IIC_WAIT; //开启IIC|从机|等待时钟
	I2CMSST=0x00;                   //清除所有标志位
	iic_set_pin(ECBM_IIC_IO);
	iic_index=ECBM_IIC_IO;
}
/*-------------------------------------------------------
函数名：iic_isr
描  述：IIC中断函数。由于IIC需要开着中断，所以就写在库中，基本做主机不会用中断来干其他事。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无，无需调用。
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
void iic_isr() interrupt 24
{
    if (I2CMSST&0x40){
        I2CMSST&=0xBF;//~0x40;//清中断标志
        iic_busy=0;
    }
}
/*-------------------------------------------------------
IIC的各种操作函数。请根据器件的协议来排布。
iic_start     :开始函数，对应IIC开始帧。
iic_stop      :停止函数，对应IIC停止帧。
iic_write     :写数据函数，往总线上写1字节数据。
iic_write_ack :写ACK函数，往总线上写一个ACK。
iic_write_nack:写NO ACK函数，往总线上写一个NO ACK。
iic_read      :读数据函数，读取总线上一个字节的数据。
iic_read_ack  :读ACK函数，读取总线上是否有ACK。
-------------------------------------------------------*/
void iic_start(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x81;   //发送START命令
    while(iic_busy&&(timeout--));
}
void iic_stop(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy = 1;
    I2CMSCR=0x86;  //发送STOP命令
    while(iic_busy&&(timeout--));//while(iic_busy);
}
void iic_write(u8 dat){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CTXD=dat;    //写数据到数据缓冲区
    iic_busy=1;
    I2CMSCR=0x82;  //发送SEND命令
    while(iic_busy&&(timeout--));//while(iic_busy);
}
void iic_write_ack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CMSST=0x00; // 设置ACK信号
    iic_busy=1;
    I2CMSCR=0x85; //发送ACK命令
    while(iic_busy&&(timeout--));//while(iic_busy);  
}
void iic_write_nack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CMSST=0x01; //设置NAK信号
    iic_busy=1;
    I2CMSCR=0x85; //发送ACK命令
    while(iic_busy&&(timeout--));//while(iic_busy);
}
u8 iic_read(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x84;  //发送RECV命令
    while(iic_busy&&(timeout--));//while(iic_busy);
    return I2CRXD;
}
bit iic_read_ack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x83; //发送读ACK命令
    while(iic_busy&&(timeout--));//while(iic_busy);
	return (I2CMSST&0x02)>>1;
}
#endif
