#ifndef _ECBM_SOFT_IIC_H_
#define _ECBM_SOFT_IIC_H_
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
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>深度优化
//<q>软件IIC扫描器件函数使能
#define SOFT_IIC_FIND_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------变量定义-----------------------------------*/
extern u8 xdata soft_iic_def_sda_port;//软件IIC数据脚所在的P口。
extern u8 xdata soft_iic_def_sda_pin; //软件IIC数据脚所在的IO口。
extern u8 xdata soft_iic_def_scl_port;//软件IIC时钟脚所在的P口。
extern u8 xdata soft_iic_def_scl_pin; //软件IIC时钟脚所在的IO口。
extern u8 xdata soft_iic_max;         //软件IIC设备的数量。
extern u8 xdata soft_iic_index;       //当前软件IIC函数所操作的对象。
typedef struct{
	u8 scl_pin;//IIC里的时钟脚。
	u8 sda_pin;//IIC里的数据脚。
	u8 dev_id; //软件IIC的唯一ID。作为切换的凭证。
}soft_iic_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：soft_iic_set_pin
描  述：软件IIC引脚切换函数。在多器件的应用下，切换IIC函数的操作对象。
输  入：软件IIC信息包。
输  出：无
返回值：无
创建者：奈特
调用例程：
	soft_iic_set_pin(&sht30);  //将IIC对象切换到名为SHT30的信息包。
	val=get_temp();            //读取SHT30的温度数据。
	soft_iic_set_pin(&at24c02);//将IIC对象切换到名为at24c02的信息包。
	at24_write(0,val);         //将温度数据写入到eeprom（24c02）里。
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
extern void soft_iic_set_pin(soft_iic_def * dev);
/*-------------------------------------------------------
函数名：soft_iic_init
描  述：软件IIC初始化函数。
输  入：dev - 软件IIC信息包。
		scl - 软件IIC的时钟脚。
		sda - 软件IIC的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：
	soft_iic_def at24;           //定义一个软件IIC操作对象，名字随意，但是推荐和目标器件有联系，方便记忆。
	soft_iic_init(&at24,D10,D11);//该对象所连接的引脚，先输入时钟脚SCL，再输入数据脚SDA。
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
extern void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：soft_iic_set_pin_linkage
描  述：软件IIC引脚切换函数（内联版）。主要用于其他库的调用，若不清楚原理请调用soft_iic_set_pin函数。
输  入：id  -  初始化软件IIC时分配的id号。
		scl - 软件IIC的时钟脚。
		sda - 软件IIC的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
extern void soft_iic_set_pin_linkage(u8 id,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：soft_iic_init_linkage
描  述：软件IIC初始化函数（内联版），主要用于其他库的调用，若不清楚原理请调用soft_iic_init函数。
输  入：	scl - 软件IIC的时钟脚。
		sda - 软件IIC的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
extern u8 soft_iic_init_linkage(u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：soft_iic_start
描  述：软件IIC启动函数，用于启动一次IIC传输。
输  入：无
输  出：无
返回值：0   - 正常通信，器件存在。
        -1 -  总线出错，器件忙。
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:优化后，一整屏的刷新时间从169.4ms降至167.4ms。
-------------------------------------------------------*/
extern u8 soft_iic_start(void);
/*-------------------------------------------------------
函数名：soft_iic_stop
描  述：软件IIC停止函数，用于停止一次IIC传输。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:优化后，一整屏的刷新时间从167.4ms降至167.0ms。
-------------------------------------------------------*/
extern void soft_iic_stop(void);
/*-------------------------------------------------------
函数名：soft_iic_write_ack
描  述：软件IIC主机写ACK函数，用于在传输8bit后发送一个ACK信号。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:优化后，一整屏的刷新时间从167.088ms降至167.059ms。
-------------------------------------------------------*/
extern void soft_iic_write_ack(void);
/*-------------------------------------------------------
函数名：soft_iic_write_nack
描  述：软件IIC主机写NO ACK函数，用于在传输8bit后发送一个NO ACK信号。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:优化后，一整屏的刷新时间从167.059ms降至167.023ms。
-------------------------------------------------------*/
extern void soft_iic_write_nack(void);
/*-------------------------------------------------------
函数名：soft_iic_read_ack
描  述：软件IIC主机读ACK函数，用于在传输8bit后读取从机的ACK信号。
输  入：无
输  出：无
返回值：0  - 收到ACK信号
		-1 - 没收到ACK信号，或者收到NO ACK信号。
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:优化后，一整屏的刷新时间从167.023ms降至165.549ms。
-------------------------------------------------------*/
extern u8 soft_iic_read_ack(void);
/*-------------------------------------------------------
函数名：soft_iic_write
描  述：软件IIC主机写函数，用于发送一个字节数据。
输  入：要发送的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
2020-03-20:刷一页128字节的时间从23.6ms降至20.6ms。
-------------------------------------------------------*/
extern void soft_iic_write(u8 dat);
/*-------------------------------------------------------
函数名：soft_iic_read
描  述：软件IIC主机读函数，用于接收一个字节数据。
输  入：无
输  出：无
返回值：收到的数据。
创建者：奈特
调用例程：见于下面的例子。
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
extern u8 soft_iic_read(void);
/*-------------------------------------------------------
函数名：soft_iic_find
描  述：软件IIC主机寻找函数，用寻找一个可用设备。
输  入：无
输  出：存在的设备的地址列表。
返回值：返回存在的设备的个数。
创建者：奈特
调用例程：
		count=soft_iic_find(iic_addr);//读取当前IIC总线上存在设备的地址，同时把设备数量存入变量count。
创建日期：2019-11-25
修改记录：
-------------------------------------------------------*/
extern u8 soft_iic_find(u8 addr[]);
/*-------------------------------------------------------
SOFT_IIC系列函数调用例程：
void OLED_send_cmd(unsigned char cmd){//OLED发送一个指令函数
	soft_iic_start   ();     //开启一次传输
	soft_iic_write   (0x78); //写入OLED的地址
	soft_iic_read_ack();     //等待ack
	soft_iic_write   (00);   //写入指令的代号
	soft_iic_read_ack();     //等待ack
	soft_iic_write   (cmd);  //写入具体的指令
	soft_iic_read_ack();     //等待ack
	soft_iic_stop    ();     //结束一次传输
}
创建日期：2019-10-18
修改记录：
-------------------------------------------------------*/
#endif
