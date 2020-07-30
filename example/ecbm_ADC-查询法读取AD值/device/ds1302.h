#ifndef _DS1302_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _DS1302_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<e>初始化器件时是否写入时间？
#define DS1302_INIT_DATA_EN 0
//<o>秒
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入秒数。比如52秒，就输入0x52。
//<i>范围0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_SECOND 0x40
//<o>分
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入分数。比如08分，就输入0x08。
//<i>范围0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_MINUTE 0x03
//<o.0..5>时
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入小时数。比如9点钟，就输入0x09。
//<i>在24小时制内输入范围为0x00~0x23；在12小时制内输入范围为0x01~0x12；
//<0x00-0x23:0x01>
//<o.7>时制选择
//<0=>24小时制 <1=>12小时制
//<o.5>上下午选择
//<i>注意：如果选了24小时制，则此选项一定得是上午，否则数据会出错。
//<i>原因是该寄存器的bit5位是12小时制的AM/PM位，而bit5位、bit4位是24小时制的存放小时数十位上数字的存储位。
//<i>由于bit5位共用导致了冲突。所以在24小时制时只有设置为“上午”，才不会引起冲突。因为“上午”对应的值是0。
//<0=>上午 <1=>下午
#define DS1302_HOUR 0x21
//<o>日期
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入日期。比如14号，就输入0x14。
//<i>范围0x01~0x31
//<0x01-0x31:0x01>
#define DS1302_DATE 0x05
//<o>月份
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入月份。比如2月份，就输入0x02。
//<i>范围0x01~0x12
//<0x01-0x12:0x01>
#define DS1302_MONTH 0x02
//<o>星期
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入星期。比如星期四，就输入0x04。
//<i>范围0x01~0x07
//<0x01-0x07:0x01>
#define DS1302_DAY 0x03
//<o>年份
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入年份。比如19年，就输入0x19。
//<i>范围0x00~0x99。由于寄存器只能存两位数字。所以无论是1919年和2019年都是19年。需要留意百年虫问题。
//<0x01-0x31:0x01>
#define DS1302_YEAR 0x20
//</e>
//<h>最大充电电流设置
//<i>从VCC2到VCC1的充电电流最大值=（VCC2电压-二极管数量*0.7V）/（电阻阻值）。
//<i>例如VCC2接5V电压，VCC1接一个超级电容。二极管数量为1，电阻阻值为2K。
//<i>那么Imax=（5.0V-1*0.7V）/2K=2.15mA。
//<o.2..3>VCC2到VCC1的二极管数量
//<1=>一个二极管 <2=>两个二极管
//<o.0..1>VCC2到VCC1的电阻阻值
//<1=>2K <2=>4K <3=>8K
#define DS1302_CHARGER 0xA5
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
//DS1302地址定义
#define DS1302_SECOND_ADDR  0x80//秒数据地址
#define DS1302_MINUTE_ADDR  0x82//分数据地址
#define DS1302_HOUR_ADDR    0x84//时数据地址
#define DS1302_DATE_ADDR    0x86//日数据地址
#define DS1302_MONTH_ADDR   0x88//月数据地址
#define DS1302_DAY_ADDR     0x8A//星期数据地址
#define DS1302_YEAR_ADDR    0x8C//年数据地址
#define DS1302_CONTROL_ADDR 0x8E//控制数据地址
#define DS1302_CHARGER_ADDR 0x90//充电控制器地址 					 
#define DS1302_RAM0  0xC0
#define DS1302_RAM1  0xC2
#define DS1302_RAM2  0xC4
#define DS1302_RAM3  0xC6
#define DS1302_RAM4  0xC8
#define DS1302_RAM5  0xCA
#define DS1302_RAM6  0xCC
#define DS1302_RAM7  0xCE
#define DS1302_RAM8  0xD0
#define DS1302_RAM9  0xD2
#define DS1302_RAM10 0xD4
#define DS1302_RAM11 0xD6
#define DS1302_RAM12 0xD8
#define DS1302_RAM13 0xDA
#define DS1302_RAM14 0xDC
#define DS1302_RAM15 0xDE
#define DS1302_RAM16 0xE0
#define DS1302_RAM17 0xE2
#define DS1302_RAM18 0xE4
#define DS1302_RAM19 0xE6
#define DS1302_RAM20 0xE8
#define DS1302_RAM21 0xEA
#define DS1302_RAM22 0xEC
#define DS1302_RAM23 0xEE
#define DS1302_RAM24 0xF0
#define DS1302_RAM25 0xF2
#define DS1302_RAM26 0xF4
#define DS1302_RAM27 0xF6
#define DS1302_RAM28 0xF8//最后3位RAM
#define DS1302_RAM29 0xFA//被征用为
#define DS1302_RAM30 0xFC//第一次初始化判断位
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 rst;		//芯片的复位脚。
	u8 io;		//芯片的数据脚。
	u8 sck;		//芯片的时钟脚。
	u8 year;	//年。
	u8 month;	//月。
	u8 date;	//星期。
	u8 day;		//日。
	u8 hour;	//时。
	u8 minute;	//分。
	u8 second;	//秒。
	u8 charger;	//充电寄存器。
}ds1302_def;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：ds1302_write
描  述：DS1302的写函数，用于向DS1302写入一个字节的数据。
输  入：dev  -  要写入的器件。
		addr -  要写入的寄存器地址。
		dat  -  要写入的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern void ds1302_write(ds1302_def * dev,u8 addr,u8 dat);
/*-------------------------------------------------------
函数名：ds1302_read
描  述：DS1302的读函数，用于向DS1302读取一个字节的数据。
输  入：dev  -  要读取的器件。
		addr -  要读取的寄存器地址。
输  出：无
返回值：该寄存器的数据。
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern u8 ds1302_read(ds1302_def * dev,u8 addr);
/*-------------------------------------------------------
函数名：ds1302_save
描  述：DS1302的储存函数，用于把结构体里的时间保存到DS1302芯片里。
输  入：dev  - 要保存到的器件。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern void ds1302_save(ds1302_def * dev);
/*-------------------------------------------------------
函数名：ds1302_load
描  述：DS1302的加载函数，运行此函数可以从DS1302芯片中读取时间。
输  入：dev  -  要操作的器件。
输  出：	dev.year    - 年 
		dev.month   - 月 
		dev.date    - 日 
		dev.hour    - 时 
		dev.minute  - 分 
		dev.second  - 秒
		dev.day     - 周 	
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern void ds1302_load(ds1302_def * dev);
/*-------------------------------------------------------
函数名：ds1302_init
描  述：DS1302的初始化函数。
输  入：dev -  要初始化的器件。
		rst -  器件的复位脚。
		io  -  器件的数据脚。
		sck -  器件的时钟脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-05
修改记录：
-------------------------------------------------------*/
extern void ds1302_init(ds1302_def * dev,u8 rst,u8 io,u8 sck);
#endif
