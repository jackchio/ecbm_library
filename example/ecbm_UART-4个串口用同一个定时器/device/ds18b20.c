#include "ds18b20.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
DS18B20的初始化函数。
-------------------------------------------------------*/
void ds18b20_init(ds18b20_def * dev,u8 pin){
	dev->port=io2port(pin);
	dev->pin =io2pin (pin);
	gpio_mode(pin,GPIO_IN);
}
/*-------------------------------------------------------
DS18B20的写函数。
-------------------------------------------------------*/
void ds18b20_write(ds18b20_def * dev,u8 dat){
	u8 i;
	u16 _10us,_70us;
	_10us=delay_set_us(10);
	_70us=delay_set_us(70);
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
/*-------------------------------------------------------
DS18B20的读函数。
-------------------------------------------------------*/
u8 ds18b20_read(ds18b20_def * dev){
	u8 i,dat=0;
	u16 _10us,_50us;
	_10us=delay_set_us(10);
	_50us=delay_set_us(50);
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
/*-------------------------------------------------------
DS18B20的检测函数。
-------------------------------------------------------*/
u8 ds18b20_check(ds18b20_def * dev){
	u16 _60us,_500us;
	_60us=delay_set_us(60);
	_500us=delay_set_us(500);
	gpio_out_fast(dev->port,dev->pin,0);  //拉低总线，开始通信。
	delay_us(_500us);        //拉低500us(复位时间480us~960us)。
	gpio_out_fast(dev->port,dev->pin,1);		
	delay_us(_60us);         //等待DS18B20相应（需要等待15us~60us）。
	if(gpio_in_fast(dev->port,dev->pin)==0){
		return 1;          //总线被DS18B20拉低说明器件存在。
	}
	return 0;              //0表示器件不存在。
}
/*-------------------------------------------------------
DS18B20的运行函数。
-------------------------------------------------------*/
u8 ds18b20_run(ds18b20_def * dev){
	u8 h,l;
	u16 temp;
	u16 _100us;
	_100us=delay_set_us(100);
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
