#ifndef _ECBM_IIC_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_IIC_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 奈特

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
//<o>IIC等待时钟周期
//<0-63:1>
//<i>可输入0~63。该数字越小，即等待时钟越少，IIC的速度越快。如果目标器件的速度跟得上，可以设为0以获取最大的IIC通信速度。
//<i>如果目标器件的速度跟不上（一般通信出现乱码或直接通信失败），可以从63开始一步一步减少以获得最佳性能。嫌麻烦也可直接设为63。
#define ECBM_IIC_WAIT 50
//<o.4..5>IIC默认管脚
//<i>此设置只会改动初始化的管脚，在实际应用中随时可以使用iic_set_pin函数修改IIC管脚，达到分时复用的效果。
//<0=>SCL-P15|SDA-P14 <1=>SCL-P25|SDA-P24 <2=>SCL-P77|SDA-P76 <3=>SCL-P32|SDA-P33
#define ECBM_IIC_IO 0
//<o>无响应超时时间
//<i>输入的是时钟数，可以输入10~100。
//<10-100>
#define ECBM_IIC_TIMEOUT 10
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define IIC_PIN_P1 0	//将IIC的输出IO设置到P1口。
#define IIC_PIN_P2 16	//将IIC的输出IO设置到P2口。
#define IIC_PIN_P7 32	//将IIC的输出IO设置到P7口。
#define IIC_PIN_P3 48	//将IIC的输出IO设置到P3口。
/*--------------------------------------变量定义-----------------------------------*/
extern bit iic_busy; 
extern u8 xdata iic_index;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：iic_set_pin
描  述：IIC的引脚设置函数。IIC支持4个组，对应在P1、P2、P7、P3上。
输  入： 
        group - 设置IIC输出的引脚。可以输入IIC_PIN_P1、IIC_PIN_P2、IIC_PIN_P7、IIC_PIN_P3。
输  出：无
返回值：无
创建者：奈特
调用例程：iic_set_pin(IIC_PIN_P1);//SCL脚为P15，SDA脚为P14 
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
void iic_set_pin(u8 group);
/*-------------------------------------------------------
函数名：iic_set_pin_linkage
描  述：IIC的引脚设置函数（内联版）。该函数只会被库函数调用。
输  入：group - 设置IIC输出的引脚。可以输入IIC_PIN_P1、IIC_PIN_P2、IIC_PIN_P7、IIC_PIN_P3。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-03-05
修改记录：
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group);
/*-------------------------------------------------------
函数名：iic_reset_pin
描  述：IIC的引脚还原函数。当IIC转移到其他脚的时候，将原来的IO恢复正常的设置。
输  入： 
        group - 设置需要还原的引脚。可以输入IIC_PIN_P1、IIC_PIN_P2、IIC_PIN_P7、IIC_PIN_P3。
输  出：无
返回值：无
创建者：奈特
调用例程：iic_reset_pin(IIC_PIN_P1);//P15和P14还原成弱上拉模式 
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
void iic_reset_pin(u8 group);
/*-------------------------------------------------------
函数名：iic_master_init
描  述：IIC主机初始化函数。将硬件IIC当成主机来用，参数可以在图形界面输入。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：iic_master_init();//初始化IIC主机
创建日期：2019-8-23
修改记录：
2020-03-05:支持多路复用，但不会自动切换，需要手动切换。
-------------------------------------------------------*/
void iic_master_init(void);
/*-------------------------------------------------------
函数名：iic_slave_init
描  述：IIC从机初始化函数。将硬件IIC当成从机来用，参数可以在图形界面输入。（从机未完工）
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：iic_slave_init();//初始化IIC从机
创建日期：2019-8-23
修改记录：
2020-03-05:支持多路复用。 但是实际上从机无法做到真正的多路复用。先加进去先。
-------------------------------------------------------*/
void iic_slave_init(void);
/*-------------------------------------------------------
函数名：iic_start、iic_stop、iic_write、iic_write_ack、iic_write_nack、iic_read、iic_read_ack
描  述：IIC的各种操作函数。请根据器件的协议来排布。
        iic_start     :开始函数，对应IIC开始帧。
        iic_stop      :停止函数，对应IIC停止帧。
        iic_write     :写数据函数，往总线上写1字节数据。
        iic_write_ack :写ACK函数，往总线上写一个ACK。
        iic_write_nack:写NO ACK函数，往总线上写一个NO ACK。
        iic_read      :读数据函数，读取总线上一个字节的数据。
        iic_read_ack  :读ACK函数，读取总线上是否有ACK。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
          iic_start();    //开始传输
          iic_write(0x78);//先发地址0x78
          iic_read_ack(); //等器件回ACK
          iic_write(cd);  //发送数据类型
          iic_read_ack(); //等器件回ACK
          iic_write(buf); //发送数据
          iic_read_ack(); //等器件回ACK
          iic_stop();     //停止传输
创建日期：2019-8-23
修改记录：
2020-03-02:将参数类型从char改成了u8
2020-03-05:全员添加超时判定，防止了死循环。
-------------------------------------------------------*/
void iic_start     (void);
void iic_stop      (void);
void iic_write     (u8 dat);
void iic_write_ack (void);
void iic_write_nack(void);
u8   iic_read      (void);
bit iic_read_ack   (void);
#endif
