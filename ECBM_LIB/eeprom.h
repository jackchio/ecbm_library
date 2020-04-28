#ifndef _ECBM_EEPROM_H_
#define _ECBM_EEPROM_H_
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
//<e>手动输入eeprom大小
#define ECBM_EEPROM_SIZE_EN 1
//<i>针对某些型号的EEPROM的空间大小是可以在STC-ISP设置的，所以用到这些型号的时候，可打开此设置，手动填入EEPROM空间大小。
//<o>eeprom空间
//<i>单位是字节，如果是0.5K就填512
#define ECBM_EEPROM_SIZE 512
//</e>
//<<< end of configuration section >>>
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
//#if   SYS_CLK_SET == 5529600L  //根据时钟频率来选择内部eeprom的等待时间。
//#define EEPROM_WAIT 4
//#elif SYS_CLK_SET == 6000000L
//#define EEPROM_WAIT 4
//#elif SYS_CLK_SET == 11059200L
//#define EEPROM_WAIT 3
//#elif SYS_CLK_SET == 12000000L
//#define EEPROM_WAIT 3
//#elif SYS_CLK_SET == 18432000L
//#define EEPROM_WAIT 2
//#elif SYS_CLK_SET == 20000000L
//#define EEPROM_WAIT 2
//#elif SYS_CLK_SET == 22118400L
//#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 24000000L
#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 27000000L
//#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 30000000L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 33000000L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 33177600L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 35000000L
//#define EEPROM_WAIT 0
//#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：eeprom_erase
描  述：eeprom擦除函数，stc的eeprom都是由flash虚拟出来的，所以再写之前要擦除。
		同时因为一个扇区有512字节，如果你想擦除一个字节，就会把同一扇区的其他511字节一起擦掉。
		得好好注意这个问题，用读写flash的思维来使用这个eeprom。
输  入：要擦除的地址，会擦除该地址所在的整个扇区的全部数据。
输  出：无
返回值：无
创建者：奈特
调用例程：
		...//其他无关的代码。
		eeprom_erase(30);//擦除地址30的数据，但是由于30是第0扇区，所以0~511的数据也会一并被擦除掉。
		...//其他无关的代码。
创建日期：2019-10-12
修改记录：
-------------------------------------------------------*/
extern void eeprom_erase(u16 addr);
/*-------------------------------------------------------
函数名：eeprom_write
描  述：eeprom写函数。
输  入：addr - 要写入数值的地址。
        dat  - 要写入的数值，范围是u8型，即0~255。
输  出：无
返回值：无
创建者：奈特
调用例程：
		...//其他无关的代码。
		eeprom_write(123,15);//把数值15写入到地址123中去。
		...//其他无关的代码。
创建日期：2019-10-12
修改记录：
-------------------------------------------------------*/
extern void eeprom_write(u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：eeprom_read
描  述：eeprom读函数。
输  入：要读取的地址。
输  出：无
返回值：该地址存的值。
创建者：奈特
调用例程：
		...//其他无关的代码。
		val=eeprom_read(56);//读取地址56的值，赋予变量val。
		...//其他无关的代码。
创建日期：2019-10-12
修改记录：
-------------------------------------------------------*/
extern u8 eeprom_read(u16 addr);
#endif
