#include "ds1302.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
DS1302的写函数。
-------------------------------------------------------*/
void ds1302_write(ds1302_def * dev,u8 addr,u8 dat){
	u8 i;
	gpio_out(dev->rst,1);//启动DS1302总线					
	//写入目标地址：addr
	addr = addr & 0xFE; //最低位置零，寄存器0位为0时写，为1时读。
	for(i=0;i<8;i++){	//写8位数据。
		if(addr&0x01){	//从最低位发起。
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//产生时钟，
		gpio_out(dev->sck,0);//通过调用函数的时间来作为延时。
		addr=addr>>1;	//取下一位数据。
	}	
	//写入数据：dat
	for(i=0;i<8;i++){	//写8位数据。
		if(dat&0x01){	//从最低位发起。
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//产生时钟
		gpio_out(dev->sck,0);//通过调用函数的时间来作为延时。
		dat=dat>>1;		//取下一位数据。
	}
	gpio_out(dev->rst,0);//停止DS1302总线
}
/*-------------------------------------------------------
DS1302的读函数。
-------------------------------------------------------*/
u8 ds1302_read(ds1302_def * dev,u8 addr) {
	unsigned char i,temp;	
	gpio_out(dev->rst,1);//启动DS1302总线
	//写入目标地址：addr
	addr=addr|0x01;		//最低位置高，寄存器0位为0时写，为1时读。
	for(i=0;i<8;i++){	//写8位数据。	
		if(addr&0x01){	//从低位开始发。
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//产生时钟
		gpio_out(dev->sck,0);//通过调用函数的时间来作为延时。
		addr=addr>>1;		//取下一位数据。
	}	
	//输出数据：temp
	for(i=0;i<8;i++){	//读8位数据。
		temp=temp>>1;	//腾出最高位，
		if(gpio_in(dev->io)){//从最高位开始读。
			temp|=0x80;
		}else{
			temp&=0x7F;
		}
		gpio_out(dev->sck,1);//产生时钟
		gpio_out(dev->sck,0);//通过调用函数的时间来作为延时。
	}	
	gpio_out(dev->rst,0);//停止DS1302总线
	return temp;		//返回读取到的数据
}
/*-------------------------------------------------------
DS1302的储存函数。
-------------------------------------------------------*/
void ds1302_save(ds1302_def * dev){
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x00);		//关闭写保护
	ds1302_write(dev,DS1302_SECOND_ADDR,  0x80);		//暂停时钟 
	ds1302_write(dev,DS1302_CHARGER_ADDR, dev->charger);//充电设置
	ds1302_write(dev,DS1302_YEAR_ADDR,    dev->year);	//年 
	ds1302_write(dev,DS1302_MONTH_ADDR,   dev->month);	//月 
	ds1302_write(dev,DS1302_DATE_ADDR,    dev->date);	//日 
	ds1302_write(dev,DS1302_DAY_ADDR,     dev->day);    //周 
	ds1302_write(dev,DS1302_HOUR_ADDR,    dev->hour);	//时 
	ds1302_write(dev,DS1302_MINUTE_ADDR,  dev->minute); //分
	ds1302_write(dev,DS1302_SECOND_ADDR,  dev->second); //秒
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x80);        //打开写保护
}
/*-------------------------------------------------------
DS1302的加载函数。
-------------------------------------------------------*/
void ds1302_load(ds1302_def * dev){
	dev->year  =ds1302_read(dev,DS1302_YEAR_ADDR);	//年 
	dev->month =ds1302_read(dev,DS1302_MONTH_ADDR);	//月 
	dev->date  =ds1302_read(dev,DS1302_DATE_ADDR);	//日 
	dev->hour  =ds1302_read(dev,DS1302_HOUR_ADDR);	//时 
	dev->minute=ds1302_read(dev,DS1302_MINUTE_ADDR);//分 
	dev->second=ds1302_read(dev,DS1302_SECOND_ADDR);//秒
	dev->day   =ds1302_read(dev,DS1302_DAY_ADDR);	//周 	
}
/*-------------------------------------------------------
DS1302的初始化函数。
-------------------------------------------------------*/
void ds1302_init(ds1302_def * dev,u8 rst,u8 io,u8 sck){
	dev->rst=rst;//保存引脚设置。
	dev->io =io;
	dev->sck=sck;
	gpio_mode(dev->rst,GPIO_OUT);//设置引脚状态。
	gpio_mode(dev->io, GPIO_OUT);
	gpio_mode(dev->sck,GPIO_OUT);
	gpio_out(dev->rst,0);//设置初始电平。
	gpio_out(dev->sck,0);
	gpio_out(dev->io, 1);
	#if DS1302_INIT_DATA_EN  //加入使能了初始化写入时间功能，
	dev->year   =DS1302_YEAR;//就把图形界面设置的时间写入。
	dev->month  =DS1302_MONTH;
	dev->date   =DS1302_DATE;
	dev->day    =DS1302_DAY;
	dev->hour   =DS1302_HOUR;
	dev->minute =DS1302_MINUTE;
	dev->second =DS1302_SECOND;
	dev->charger=DS1302_CHARGER;
	ds1302_save(dev);		//然后保存到ds1302里。
	#endif	
}