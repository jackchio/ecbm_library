#ifndef _ECBM_AT24CXX_H_
#define _ECBM_AT24CXX_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 奈特

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
//<i>此选项打勾，意味着AT24CXX库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。并且支持多器件下的代码复用。
//<i>此选项不打勾，意味着AT24CXX库能单独使用，不会再依赖其他ECBM库函数。需要移植基本的构造函数。但此时若再加载ECBM库会有重定义报错的可能，请注意。
#define ECBM_AT24CXX_LINK_EN 1 //和ECBM库连接的使能，如果想脱离主库单独使用AT24CXX外设，请设为0。
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_AT24CXX_LINK_EN     //如果需要加载主库
#include "ecbm.h"            //加载ecbm头文件
typedef struct{
	u8 mode;
	soft_iic_def io;	
}at24_def;
void at24_init_hard(at24_def * dev,u8 scl,u8 sda){
	if((scl==D15)&&(sda==D14))dev->mode=0;
	else if((scl==D25)&&(sda==D24))dev->mode=1;
	else if((scl==D77)&&(sda==D76))dev->mode=2;
	else if((scl==D32)&&(sda==D33))dev->mode=3;
	else {
		LED=0;
		while(1);
	}
	iic_master_init();
	iic_set_pin(dev->mode);
}
void at24_init_soft(at24_def * dev,u8 scl,u8 sda){
	dev->mode=0x10;
	soft_iic_init(&((*dev).io),scl,sda);
}
void at24_write(at24_def * dev,u8 addr,u8 dat[],u8 num){
	u8 i;
	if(dev->mode==0x10){
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa0);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_write    (&((*dev).io),addr);
		soft_iic_write_ack(&((*dev).io));
		for(i=0;i<num;i++){
			soft_iic_write(&((*dev).io),dat[i]);
			soft_iic_write_ack(&((*dev).io));
		}	
		soft_iic_stop     (&((*dev).io));
	}else{
		iic_start();
		iic_write(0xa0);
		iic_write_ack();
		iic_write(addr);
		iic_write_ack();
		for(i=0;i<num;i++){
			iic_write(dat[i]);
			iic_write_ack();
		}	
		iic_stop();
	}
}
void at24_read(at24_def * dev,u8 addr,u8 dat[],u8 num){
    u8 i;
    /*先写数据*/
	if(dev->mode==0x10){
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa0);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_write    (&((*dev).io),addr);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa1);
		for(i=0;i<num;i++){
			soft_iic_write_ack(&((*dev).io));
			dat[i]=soft_iic_read (&((*dev).io));
		}
		soft_iic_write_nack(&((*dev).io));
		soft_iic_stop     (&((*dev).io));
	}else{
		iic_start();
		iic_write(0xa0);
		iic_write_ack();
		iic_write(addr);
		iic_write_ack();
		iic_start();
		iic_write(0xa1);
		for(i=0;i<num;i++){
			iic_write_ack();
			dat[i]=iic_read();
		}
		iic_write_nack();
		iic_stop();
	}
}
#endif
#endif
