#ifndef _ECBM_WS2812_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_WS2812_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2024 奈特

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
                            ***************************
                            * 联系方式 ：进群778916610 *
                            * 若1群满人：进群927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>数据输出脚对应的port
//<0x80=>P0
//<0x90=>P1
//<0xA0=>P2
//<0xB0=>P3
//<0xC0=>P4
//<0xC8=>P5
//<0xE8=>P6
//<0xF8=>P7
#define ECBM_WS2812_IO_PORT (0xC8)
//<o>数据输出脚对应的pin
//<0x00=>0
//<0x01=>1
//<0x02=>2
//<0x03=>3
//<0x04=>4
//<0x05=>5
//<0x06=>6
//<0x07=>7
#define ECBM_WS2812_IO_PIN  (0x05)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：ws2812_init
描  述：WS2812的初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2024-09-12
修改记录：
-------------------------------------------------------*/
extern void ws2812_init(void);
/*-------------------------------------------------------
函数名：ws2812_send
描  述：WS2812的发送函数。
输  入：
    dat     需要发送的数据，以GRB三色数据为单元，每3个数据为一组。
    len     dat数据的长度，肯定是3的倍数。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2024-09-12
修改记录：
-------------------------------------------------------*/
extern void ws2812_send(u8 dat[],u16 len);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。