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
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>自动初始化功能
//<i>该功能是一个拓展功能，会通过读写操作来判断芯片型号和地址。这就要求IIC总线上有且只有一个EEPROM芯片。
//<i>由于读写操作会降低eeprom的寿命，所以推荐只在目标器件配置完全不清楚的情况下使用。
//<i>不使用该函数也能使用eeprom，优化掉该函数能节省一些空间。
#define AT24CXX_AUTO_INIT_EN 0
//<q>芯片全写功能
//<i>该功能是一个拓展功能，一般用于测试芯片是否能写入数据，所以器件正常的情况下用不到这个函数。而且依赖debug函数的存在。
#define AT24CXX_WRITE_ALL_EN 0
//<q>芯片全读功能
//<i>该功能是一个拓展功能，一般用于查看芯片内的内容，比全写函数常用，但是依赖debug函数的存在。
#define AT24CXX_READ_ALL_EN 0
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define AT24_ADDR 0x50 //通常EEPROM的地址是从0x50（不含读写位，含读写位就是0xA0）开始。
#define AT24_A2   0x04 //当芯片上的A2脚接高电平的时候，把这个宏定义或到型号上去，比如AT24C02|AT24_A2。
#define AT24_A1   0x02 //当芯片上的A1脚接高电平的时候，把这个宏定义或到型号上去，比如AT24C02|AT24_A1。
#define AT24_A0   0x01 //当芯片上的A0脚接高电平的时候，把这个宏定义或到型号上去，比如AT24C02|AT24_A0。
#define AT24_OK            0  //正常。
#define AT24_ERROR_INIT    1  //初始化问题。
#define AT24_ERROR_NOACK   2  //无回应问题。
#define AT24_ERROR_SEND    3  //发送失败。
#define AT24_ERROR_ADDR    4  //地址非法。
#define AT24_ERROR_NUMBER  5  //写入/读出数量非法。
#define AT24_ERROR_UNKONW  6  //未知型号。
#define AT24CXX  0x00 //未知型号
#define AT24C01  0x10 //容量为128字节
#define AT24C02  0x20 //容量为256字节
#define AT24C04  0x30 //容量为512字节
#define AT24C08  0x40 //容量为1024字节
#define AT24C16  0x50 //容量为2048字节
#define AT24C32  0x60 //容量为4096字节
#define AT24C64  0x70 //容量为8192字节
#define AT24C128 0x80 //容量为16384字节
#define AT24C256 0x90 //容量为32768字节
#define AT24C512 0xA0 //容量为65536字节
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 model;
	u8 id;
	u8 scl;
	u8 sda;
}at24_def;                  //器件缓存，每使用一个器件都应该创建一个缓存。用于多器件复用。
extern u8 xdata at24_model; //当前库函数操作的对象，因为其他参数都是IIC有关，所以就不存在这里了。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：at24_set_work
描  述：设置工作状态函数，将一个器件设置为工作状态。
输  入：dev  -  要设置成工作状态的器件。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-11-26
修改记录：
-------------------------------------------------------*/
extern void at24_set_work(at24_def * dev);
/*-------------------------------------------------------
函数名：at24_init
描  述：AT24CXX系列的初始化函数。
输  入：dev   -  要初始化的器件。
		model -  该器件的型号，库函数支持的型号可见于宏定义区。
		scl   -  该器件的SCL脚连接的IO。
		sda   -  该器件的SDA脚连接的IO。
输  出：无
返回值：无
创建者：奈特
调用例程：
创建日期：2019-11-26
修改记录：
-------------------------------------------------------*/
extern void at24_init(at24_def * dev,u8 model,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：at24_write
描  述：AT24系列的写函数，支持多个数据写入。
输  入：addr  -  写入的初始地址。
		dat   -  写入的数据缓存。
		num   -  写入数据的数量。
输  出：无
返回值：状态码。
创建者：奈特
调用例程：
创建日期：2019-11-27
修改记录：
2019-11-29:新增了错误的时候关闭IIC总线。
2019-12-09:适配了at24c32到at24c512的5个型号。
-------------------------------------------------------*/
extern u8 at24_write(u16 addr,u8 dat[],u16 num);
/*-------------------------------------------------------
函数名：at24_read
描  述：AT24系列的读函数，支持多个数据读取。
输  入：addr  -  读取的初始地址。
		num   -  读取数据的数量。
输  出：dat   -  存读取的数据的缓存。
返回值：状态码。
创建者：奈特
调用例程：
创建日期：2019-11-27
修改记录：
2019-11-29:新增了错误的时候关闭IIC总线。
2019-12-09:适配了at24c32到at24c512的5个型号。
-------------------------------------------------------*/
extern u8 at24_read(u16 addr,u8 dat[],u16 num);
/*-------------------------------------------------------
函数名：at24_write_all
描  述：AT24系列的全写函数，以128字节为一块，往eeprom里写入00~FF。该函数需要串口支持。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-09
修改记录：
-------------------------------------------------------*/
extern void at24_write_all(void);
/*-------------------------------------------------------
函数名：at24_read_all
描  述：AT24系列的全读函数，读取eeprom里的内容发送到串口。该函数需要串口支持。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-09
修改记录：
-------------------------------------------------------*/
extern void at24_read_all(void);
/*-------------------------------------------------------
函数名：at24_auto_init
描  述：AT24系列的自动初始化函数，只需提供引脚就能初始化，但是会降低芯片寿命。
输  入：dev   -  要初始化的器件。
		scl   -  该器件的SCL脚连接的IO。
		sda   -  该器件的SDA脚连接的IO。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-09
修改记录：
-------------------------------------------------------*/
extern void at24_auto_init(at24_def * dev,u8 scl,u8 sda);
#endif
