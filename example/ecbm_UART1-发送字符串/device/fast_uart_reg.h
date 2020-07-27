#ifndef _FAST_UART_REG_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _FAST_UART_REG_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>Fast Uart Reg功能中寄存器的总数
//<2-256>
//<i>最大支持256个16位寄存器。
#define ECBM_FUE_MAX 16
//<o>Fast Uart Reg功能搭载的串口号
//<1-4>
//<i>这里设置之后，也要把fast_uart_in函数放到该串口的接收回调中。
#define ECBM_FUE_UART_ID  1
//<q>Fast Uart Reg的保存功能
//<i>开启的话需要用到内部EEPROM。
#define ECBM_FUE_EEPROM_EN 0
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define FUE_VER	"V0.1"
/*--------------------------------------变量定义-----------------------------------*/
extern  u8  fue_state          ;//串口接收状态机变量。
extern  u8  fue_reg_point      ;//寄存器指针，指向要写入的寄存器。
extern  u8  fue_cmd_buf[16]    ;//指令环形缓存，用于减轻串口中断压力。
extern  u8  fue_cmd_wr_buf[16] ;//指令读写状态环形缓存，用于异步处理中分辨指令是读还是写。
extern  u8  fue_cmd_start      ;//环形缓存的开始指针。
extern  u8  fue_cmd_end        ;//环形缓存的结束指针。
extern  u16 fue_reg_temp       ;//写入寄存器的缓存。
extern  u16 fue_reg    [ECBM_FUE_MAX];//寄存器本体，直接和功能挂钩。
extern  u16 fue_reg_buf[ECBM_FUE_MAX];//影子寄存器，串口写入的数据先在这里存放，验证后再存入本体。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：fue_in
描  述：FUE功能的串口读取函数，用于从串口读入一个字节的数据。
输  入：当前串口的SBUF。
输  出：无
返回值：无
创建者：奈特
调用例程：
void uart1_receive_callback(){//搭载在串口1上，
	fast_uart_in(SBUF);//将串口1的SBUF作为参数。
}
创建日期：2020-06-01
修改记录：
-------------------------------------------------------*/
extern void fue_in(u8 buf);
/*-------------------------------------------------------
函数名：fue_check
描  述：FUE的校对和返回函数，可以对某些指令进行响应、也用于返回寄存器值（查询功能）。放入主循环中。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-01
修改记录：
-------------------------------------------------------*/
extern void fue_check(void);
/*-------------------------------------------------------
函数名：fue_init
描  述：FUE的初始化函数，调用eeprom函数来读取保存值。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-01
修改记录：
-------------------------------------------------------*/
extern void fue_init(void);
#endif 
