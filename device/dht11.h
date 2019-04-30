#ifndef _DHT11_H_
#define _DHT11_H_
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
//<i>此选项打勾，意味着DHT11库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。并且支持多器件下的代码复用。
//<i>此选项不打勾，意味着DHT11库能单独使用，不会再依赖其他ECBM库函数。需要移植基本的构造函数。但此时若再加载ECBM库会有重定义报错的可能，请注意。
#define ECBM_DHT11_LINK_EN 1 //和ECBM库连接的使能，如果想脱离主库单独使用DHT11外设，请设为0。
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_DHT11_LINK_EN
/*----------------------------------------
本驱动运用到了外部的延时函数和通用IO控制函数，
因此要保证以下头文件存在且能加载。
-----------------------------------------*/
#include "ecbm.h"
/*----------------------------------------
DHT11的信息结构体定义。由于相关函数可复用，所
以每增加一个DHT11器件，就多定义一个信息结构体。
使用方法：
	像定义变量一样，想好一个变量名，如dev1。
然后 dht11_def dev1;
	多个器件连接时，亦可像定义变量一样操作，即
dht11_def dev1,dev2;
-----------------------------------------*/
typedef struct{
	u8 port;        //DHT11硬件连接的P口
	u8 pin;         //P口上的编号
	u8 temp;		//DHT11测出来的温度值
	u8 humi;		//DHT11测出来的湿度值
}dht11_def;
/*----------------------------------------
DHT11初始化函数。用于初始化IO口配置和初始化信
息结构体。该函数可复用，所以每增加一个DHT11器
件，就多调用一次该函数。
使用方法：
	将之前定义的DHT11信息结构体和DHT11硬件连接
的IO标号作为参数输入。例如，定义了dht11_def dev1;
硬件连接了名为D17的IO口上。则有
        dht11_init(&dev1,D17);
由于要修改结构体内的变量，所以&号不能少！
多个器件的写法：
        dht11_init(&dev1,D17);//初始化器件1
        dht11_init(&dev2,D16);//初始化器件2
要注意，严禁将两个器件置于同一个IO口！
-----------------------------------------*/
void dht11_init(dht11_def * dev,u8 pin){
	dev->port=pin>>4;
	dev->pin=0x01<<(pin&0x0f);
	dev->temp=0;
	dev->humi=0;
	gpio_mode(pin,GPIO_IN);
	gpio_out(pin,1);
}
/*----------------------------------------
DHT11读取函数。用于读取DHT11测量到的温湿度值。
该函数可复用。可根据需要去调用，但要注意DHT11
推荐的采样率是1秒/次。因此两次调用之前要一定的
时间间隔。可以用定时器定1秒钟，每秒调用一次。
使用方法：
	将之前定义的DHT11信息结构体作为参数输入。
例如，定义了dht11_def dev1;
        dht11_run(&dev1);
多个器件的写法：
        dht11_run(&dev1);//读取器件1的数据
        dht11_run(&dev2);//读取器件2的数据
由于要修改结构体内的变量，所以&号不能少！
调用这个函数之后，结构体变量内就有了温湿度值了。
此时 dev1.temp 里存着器件1的温度；
dev1.humi 里存着器件1的湿度。
同理  dev2.temp 里存着器件2的温度；
dev2.humi 里存着器件2的湿度。
-----------------------------------------*/
unsigned char dht11_run(dht11_def * dev){//返回0-正常。1-总线错误。2-访问超时
	u8 timeout,i,t,j;
	u8 temp[5];
	gpio_out_fast(dev->port,dev->pin,0);//开始信号			
	delay_ms(19);			//拉低18ms以上
	gpio_out_fast(dev->port,dev->pin,1);//拉高总线
	delay_us(_30us);		//等待DHT11响应
	if(gpio_in_fast(dev->port,dev->pin)==0){			//判断DHT11是否响应，如果没有低电平说明没响应
		timeout=2;
		while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_10us);//等待低电平响应结束
		if(timeout==1)return 2;//超时返回，时间为10us*255=2.5ms
		timeout=2;
		while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_10us);//等待高电平响应结束
		if(timeout==1)return 2;//超时返回
		for(j=0;j<5;j++){//一共接收5位数据
			t=0;						//清零临时变量
			for(i=0;i<8;i++){
				timeout=2;
				while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_5us);//等待数据开始信号（低电平）结束
				if(timeout==1)return 2;//超时返回,时间为1us*255=255us
				delay_us(_30us);//低电平之后接的高电平的持续时间在26us~28us表示0.那么就延时29us看引脚电平
				t<<=1;
				if(gpio_in_fast(dev->port,dev->pin)==1){//此时还是高电平的话，说明是数据“1”
					t|=1;				
				}//否则就是数据“0”，就啥都不用干
				timeout=2;
				while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_5us);//确保高电平结束
				if(timeout==1)return 2;//超时
			}
			temp[j]=t;//将临时变量的值装填到输出数组
		}
		t=temp[0]+temp[1]+temp[2]+temp[3];//计算校验和
		if(t==temp[4]){//校验和正确就返回0，表示一切正常
			dev->temp=temp[2];
			dev->humi=temp[0];
			return 0;//正常
		}
	}
	return 1;//数据传输错误
}
/*-------------------------------------------
                   DEMO程序
#include "device/dht11.h"//加载本头文件
...//这个...是次要代码的意思，这里就不举例防止混淆
...
...
void main(){
	...
	dht11_def dev1;			//定义一个器件，名字随意，不重复即可。
	dht11_init(&dev1,D17);	//初始化该器件
	...
	...
	while(1){
		...
		dht11_run(&dev1);//读取温湿度值
		if(dev1.temp>38){//用温湿度做某些处理，
			...			//比如这里就是判断温度大于38度时做某事。
		}
		...
	}
}
--------------------------------------------*/
#else
#include "stc.h"
sbit dht_io=P3^5;
void dht11_init(){
	dht_io=1;
}
void dht11_delay_19ms(){
	unsigned char i, j, k;
	i = 3;
	j = 81;
	k = 48;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void delay_us(unsigned int us){
	unsigned int i;
	i = us;
	while (i--);
}
#define _5us 12
#define _10us 24
#define _30us 72
unsigned char dht11_run(unsigned char * temp_val,unsigned char * humi_val){//返回0-正常。1-总线错误。2-访问超时
	unsigned char timeout,i,t,j;
	unsigned char temp[5];
	dht_io=0;//开始信号			
	dht11_delay_19ms();		//拉低18ms以上
	dht_io=1;//拉高总线
	delay_us(_30us);		//等待DHT11响应
	if(dht_io==0){			//判断DHT11是否响应，如果没有低电平说明没响应
		timeout=2;
		while((dht_io==0)&&(timeout++))delay_us(_10us);//等待低电平响应结束
		if(timeout==1)return 2;//超时返回，时间为10us*255=2.5ms
		timeout=2;
		while((dht_io==1)&&(timeout++))delay_us(_10us);//等待高电平响应结束
		if(timeout==1)return 2;//超时返回
		for(j=0;j<5;j++){//一共接收5位数据
			t=0;						//清零临时变量
			for(i=0;i<8;i++){
				timeout=2;
				while((dht_io==0)&&(timeout++))delay_us(_5us);//等待数据开始信号（低电平）结束
				if(timeout==1)return 2;//超时返回,时间为1us*255=255us
				delay_us(_30us);//低电平之后接的高电平的持续时间在26us~28us表示0.那么就延时29us看引脚电平
				t<<=1;
				if(dht_io==1){//此时还是高电平的话，说明是数据“1”
					t|=1;				
				}//否则就是数据“0”，就啥都不用干
				timeout=2;
				while((dht_io==1)&&(timeout++))delay_us(_5us);//确保高电平结束
				if(timeout==1)return 2;//超时
			}
			temp[j]=t;//将临时变量的值装填到输出数组
		}
		t=temp[0]+temp[1]+temp[2]+temp[3];//计算校验和
		if(t==temp[4]){//校验和正确就返回0，表示一切正常
			*temp_val=temp[2];
			*humi_val=temp[0];
			return 0;//正常
		}
	}
	return 1;//数据传输错误
}



#endif
#endif