#include "hx7xx.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
hx7xx系列的初始化函数。
-------------------------------------------------------*/
void hx7xx_init(hx7xx_def * dev,u8 sck,u8 sda){
	dev->sck_port=io2port(sck);//解析IO信息并保存。
	dev->sck_pin =io2pin (sck);
	dev->sda_port=io2port(sda);
	dev->sda_pin =io2pin (sda);
	dev->dat=0;					//测量数据在初始化的时候清零。
	gpio_mode(sda,GPIO_IN);		//IO口设置为输入型。
	gpio_mode(sck,GPIO_IN);
	gpio_out(sda,1);			//空闲电平为高。
	gpio_out(sck,1);			//空闲电平为高。
}
/*-------------------------------------------------------
hx7xx系列的运行函数。
-------------------------------------------------------*/
void hx7xx_run(hx7xx_def * dev,u8 next){
	signed long temp;
	u8 i;
	u16 time=5000,_10us;
	_10us=delay_set_us(10);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);//时钟拉低，使能AD。
	temp=0;
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);//保证数据脚为高。因为测量结束的时候芯片会拉低数据脚。
	while((gpio_in_fast(dev->sda_port,dev->sda_pin))&&(time--))delay_ms(1);//引脚没拉低说明AD转换未结束，需等待，否则开始读取。
	for (i=0;i<24;i++){//读取24位数据。
		gpio_out_fast(dev->sck_port,dev->sck_pin,1); //时钟脚置高（发送脉冲）
		delay_us(_10us);
		temp=temp<<1; //下降沿来时变量temp左移一位，右侧补零
		gpio_out_fast(dev->sck_port,dev->sck_pin,0); //时钟脚置低
		delay_us(_10us);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)){//数据脚高电平时，
			temp++;									 //临时变量最低置1，由于左移会补0，所以数据脚低电平的情况不用考虑。
		}
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第25个脉冲下降沿来时，转换数据
	delay_us(_10us);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	if(next>0){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第26个脉冲下降沿来时，转换数据
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(next==2){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//第27个脉冲下降沿来时，转换数据
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(time==0){//假如在上面等待的时候超时了，
		dev->dat=0;//就令结果为0。
	}else{//否则就按正常数据处理。
		if(temp&(0x800000))temp|=0xFF000000;
		dev->dat=temp;
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//拉高时钟脚，结束通信。
}
