#include "max6675.h"//统一加载核心头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
MAX6675的初始化函数。
-------------------------------------------------------*/
void max6675_init(max6675_def * dev,u8 sck,u8 cs,u8 so){
	dev->sck =sck;		//保存时钟脚。
	dev->cs  =cs;		//保存片选脚。
	dev->so  =so;		//保存数据脚。
	#if MAX6675_FLAG_EN //如果使能了热电偶连接判断，
	dev->flag=0;		//那么就初始化为0，即未连接。
	#endif
	gpio_mode(sck,GPIO_OUT);//设置时钟脚为输出脚。
	gpio_mode(cs ,GPIO_OUT);//设置片选脚为输出脚。
	gpio_mode(so ,GPIO_IN);	//设置数据脚为输入脚。
	gpio_out(dev->sck,0);	//设置初始电平为低电平。
	gpio_out(dev->cs ,1);	//设置初始电平为高电平。
	gpio_out(dev->so ,1);	//设置初始电平为高电平。
}
/*-------------------------------------------------------
MAX6675的运行函数。
-------------------------------------------------------*/
void max6675_run(max6675_def * dev){
	u8 i;
	u16 dat=0;
	gpio_out(dev->cs ,0);//拉低片选脚，开始传输数据。
	gpio_out(dev->sck,0);//确保时钟脚为低。
	for(i=0;i<16;i++){	//读取16位字节。
		dat<<=1;		//左移一位，腾出最低位。
		gpio_out(dev->sck,1);//时钟置高，通知器件准备数据。
		if(gpio_in(dev->so)){//如果数据脚为高，
			dat=dat|0x0001;  //就令最低位为1。数据脚为0就不处理了，因为左移会自动补0。
		}
		gpio_out(dev->sck,0);//时钟置低，准备下一位数据传输。
	}
	gpio_out(dev->cs ,1);//片选脚拉高，结束通信。
	#if MAX6675_FLAG_EN//如果使能了热电偶检测，
	if(dat&0x0004){		//检查D2位，如果热电偶没接上。
		dev->flag=0;	//就令flag为0；
	}else{				//如果热电偶接上了，
		dev->flag=1;	//就令flag为1。
	}
	#endif
	dat>>=3;			//检查位读取之后就不需要了。
	dat&=0x0fff;		//最高位作用不大，都删掉。
	#if MAX6675_TEMP_TYPE == 0//如果选择了原始数据，
	dev->temp=dat;		//将读到的数据存入结构体中。
	#else				//如果选择了温度值，
	dev->temp=(float)dat*0.25f;//就乘以系数转换成温度值。
	#endif
}
