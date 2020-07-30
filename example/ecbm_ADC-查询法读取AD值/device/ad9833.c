#include "ad9833.h"//统一加载核心头文件

/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
ad9833的写函数。
-------------------------------------------------------*/
void ad9833_write(ad9833_def * dev,u16 txdata){
	u8 i;
	u16 _5us;
	_5us=delay_set_us(5);	//计算出需要延时5us的计数值。
	gpio_out(dev->sclk,1);	//确保开始通信前，sclk是高电平。
	gpio_out(dev->fsync,1);	//确保开始通信前，fsync是高电平。
	gpio_out(dev->fsync,0);	//拉低fsync脚，开始通信。
	for(i=0;i<16;i++){		//要发16位数据。
		if(txdata&0x8000){	//从最高位开始发。
			gpio_out(dev->sdata,1);
		}else{
			gpio_out(dev->sdata,0);
		}
		delay_us(_5us);		//不需要通信太快，做一定的延时。
		gpio_out(dev->sclk,0);//sclk脚拉低。通过下降沿传输数据。
		delay_us(_5us);
		gpio_out(dev->sclk,1);//sclk脚拉高，可以变动数据脚。
		txdata <<= 1;		//取下一位数据。
	}
	gpio_out(dev->fsync,1);//拉高fsync脚，结束通信。
} 
/*-------------------------------------------------------
AD9833设置频率函数。
-------------------------------------------------------*/
void ad9833_set_freq(ad9833_def * dev,double freq){
	double   count;
	u32 count_hex;
	u16 count_lsb,count_msb;
	count=freq*(268435456.0f/(double)AD9833_MCLK);
	count_hex=(u32)(count);			//将算出来的结果转换成u32型，然后拆分成两个14位进行处理；
	count_lsb=(u16)(count_hex);		//count_hex低16位送给count_LSB
	count_lsb=count_lsb&0x3fff;		//去除最高两位，16位数换去掉高位后变成了14位
	count_msb=(u16)(count_hex>>14);	//count_hex高16位送给count_HSB
	count_msb=count_msb&0x3fff;		//去除最高两位，16位数换去掉高位后变成了14位
	if((dev->config)&0x08){
		count_lsb=count_lsb|AD9833_FREQ1_REG_MASK;
		count_msb=count_msb|AD9833_FREQ1_REG_MASK;//使用频率寄存器1输出波形
	}else{
		count_lsb=count_lsb|AD9833_FREQ0_REG_MASK;
		count_msb=count_msb|AD9833_FREQ0_REG_MASK;//使用频率寄存器0输出波形
	}
	ad9833_write(dev,count_lsb); //L14，选择频率寄存器0的低14位数据输入
	ad9833_write(dev,count_msb); //H14 频率寄存器的高14位数据输入
}
/*-------------------------------------------------------
AD9833设置波形函数。
-------------------------------------------------------*/
void ad9833_set_wave(ad9833_def * dev,u8 wave){
	u16 reg;
	reg=0x2000;
	if(dev->config&0x08){
		reg|=0x0800;
	}
	if(dev->config&0x04){
		reg|=0x0400;
	}
	switch(wave){
		case AD9833_OFF_WAVE:{
			reg|=AD9833_REG_OFF_WAVE;
		}break;
		case AD9833_TRI_WAVE:{
			reg|=AD9833_REG_TRI_WAVE;
		}break;
		case AD9833_SIN_WAVE:{
			reg|=AD9833_REG_SIN_WAVE;
		}break;
		case AD9833_SQU_WAVE:{
			reg|=AD9833_REG_SQU_WAVE;
		}break;
	}
	ad9833_write(dev,reg); 
}
/*-------------------------------------------------------
ad9833的初始化函数。
-------------------------------------------------------*/
void ad9833_init(ad9833_def * dev,u8 fsync,u8 sclk,u8 sdata){
	dev->fsync=fsync;			//把引脚信息存入结构体，下同。
	dev->sclk =sclk;
	dev->sdata=sdata;
	gpio_mode(fsync,GPIO_OUT);	//将相应的引脚设置为推挽模式，因为只有输出。
	gpio_mode(sclk ,GPIO_OUT);
	gpio_mode(sdata,GPIO_OUT);
	ad9833_write(dev,0x0100);	//复位AD9833,即RESET位为1，同时复位操作会把其他位改成0。
	ad9833_write(dev,AD9833_REG);//设置AD9833为初始状态。
	#if   AD9833_REG == 0x2000 //选择了正弦波
	dev->config=AD9833_SIN_WAVE;
	#elif AD9833_REG == 0x2002 //选择了三角波
	dev->config=AD9833_TRI_WAVE;
	#elif AD9833_REG == 0x2068 //选择了矩形波
	dev->config=AD9833_SQU_WAVE;
	#elif AD9833_REG == 0x20E8 //选择了不输出
	dev->config=AD9833_OFF_WAVE;
	#endif
	ad9833_set_freq(dev,AD9833_FREQ);
}
/*-------------------------------------------------------
函数名：
描  述：
输  入：
输  出：
返回值：
创建者：
调用例程：
创建日期：
修改记录：
-------------------------------------------------------*/
//void ad9833_set_freqaddr(ad9833_def * dev,u8 addr){
//	if(addr){
//		dev->config|=0x08;
//	}else{
//		dev->config&=0xF7;
//	}
//}