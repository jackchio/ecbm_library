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
//<s>Fast Uart Reg的版本号
//<i>请不要修改版本号。
#define FUR_VER	"V0.3"
//<o>Fast Uart Reg功能中本机的ID地址
//<0-255>
//<i>最大支持256个ID地址。
//<i>支持后期更改，但如果要保存ID地址的话，需要使能保存功能。
#define ECBM_FUR_ID 233
//<o>Fast Uart Reg功能中寄存器的总数
//<0-60000>
//<i>最大支持60000个16位寄存器。
//<i>之所以最小可以设置0个寄存器，是因为可以外扩寄存器。
#define ECBM_FUR_REG_MAX 1
//<o>Fast Uart Reg功能搭载的串口
//<1=>串口1 <2=>串口2 <3=>串口3 <4=>串口4 
//<i>这里设置之后，也要把fur_in函数放到该串口的接收回调中。
#define ECBM_FUR_UART_ID  1
//<q>Fast Uart Reg的保存功能
//<i>开启的话需要用到内部EEPROM。
#define ECBM_FUR_EEPROM_EN 0
//<q>Fast Uart Reg的帮助功能
//<i>由于需要自己填写帮助函数，所以正常情况下用户不必开启此功能。
//<i>因为函数没定义的话，开启本功能必然会导致单片机跑飞！
#define ECBM_FUR_HELP_EN 1
//<q>Fast Uart Reg的读写回调功能
//<i>需要自己填写回调函数，用于实现在接收到某个数据时执行自定义的动作。
//<i>只有接收到正确的地址和数据才会调用回调函数。
//<i>因为函数没定义的话，开启本功能必然会导致单片机跑飞！
#define ECBM_FUR_WR_CALLBACK_EN 1
//<q>Fast Uart Reg的错误回调功能
//<i>需要自己填写回调函数，用于实现在接收到某个错误数据时执行自定义的动作。
//<i>但是寄存器1属于系统专用寄存器，所以这部分错误分析不会调用该函数。
//<i>定义回调函数时，请根据参数的错误码来分别处理对应的错误。
//<i>因为函数没定义的话，开启本功能必然会导致单片机跑飞！
#define ECBM_FUR_ERR_CALLBACK_EN 1
//<e>Fast Uart Reg的扩展功能
//<i>由于需要自己填写扩展函数，所以正常情况下用户不必开启此功能。
//<i>因为函数没定义的话，开启本功能必然会导致单片机跑飞！
#define ECBM_FUR_EX_EN 0
//<o>Fast Uart Reg功能中外扩寄存器的总数
//<1-60000>
//<i>支持最多60000个16位寄存器。
#define ECBM_FUR_EX_MAX 1200
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
//---------------------------------变量类型宏定义区-----------------------------------
#define fur_u8  unsigned char //为了更通用化，重新定义u8型
#define fur_u16 unsigned  int //为了更通用化，重新定义u16型

//---------------------------------参数类型宏定义区-----------------------------------
#define FUR_REG_OFFSET   2    //目前需要保存的系统寄存器（有别于用户寄存器）的数量。

//--------------------------------标志位类型宏定义区----------------------------------
#define FUR_FLAG_DATA    0x01 //从机模式，当收到规定外的数据时，该位置一。
#define FUR_FLAG_ADDR    0x02 //从机模式，当收到规定外的地址时，该位置一。
#define FUR_M_FLAG_DATA  0x04 //主机模式，当对方返还一个数据接收错误时，该位置一。
#define FUR_M_FLAG_ADDR  0x08 //主机模式，当对方返还一个地址接收错误时，该位置一。
#define FUR_M_FLAG_OK    0x10 //主机模式，当对方返还一个正确的回复时，该位置一。
#define FUR_M_FLAG_TIME  0x20 //主机模式，如果对方迟迟不回复，该位置一。
#define FUR_M_FLAG_READ  0x40 //主机模式，如果收到对方的回复，该位置一。
#define FUR_FLAG_MS_M    0x80 //主机模式
#define FUR_FLAG_MS_S    0x7F //从机模式

//-----------------------------------函数宏定义区-------------------------------------
#define fur_printf fur_printf_base

//---------------------------------字符压缩宏定义区-----------------------------------
#define fur_cmd_in  fur_cmd_wr_buf[fur_cmd_end]
#define fur_cmd_out fur_cmd_wr_buf[fur_cmd_start]
/*--------------------------------------变量定义-----------------------------------*/
extern  fur_u8  fur_bit              ;  //寄存器位数标志。
extern  fur_u8  fur_flag             ;//寄存器状态。 
extern  fur_u8  fur_state            ;//串口接收状态机变量。
extern  fur_u8  fur_cmd_start        ;//环形缓存的开始指针。
extern  fur_u8  fur_cmd_end          ;//环形缓存的结束指针。
extern  fur_u8  fur_cmd_wr_buf[16]   ;//指令读写状态环形缓存，用于异步处理中分辨指令是读还是写。
extern  fur_u16 fur_cmd_buf   [16]   ;//指令环形缓存，用于减轻串口中断压力。
extern  fur_u16 fur_reg_point        ;//寄存器指针，指向要写入的寄存器。
extern  fur_u16 fur_reg_temp         ;//写入寄存器的缓存。
extern  fur_u16 fur_reg_buf   [16]   ;//影子寄存器，串口写入的数据先在这里存放，验证后再存入本体。
extern  fur_u16 fur_reg[ECBM_FUR_REG_MAX+FUR_REG_OFFSET];//寄存器本体，直接和功能挂钩。
extern  fur_u16 fur_addr             ;//主机模式下，用于验证地址返回值。
extern  fur_u16 fur_dat              ;//主机模式下，用于验证数据返回值。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：fur_printf_base
描  述：FUR功能的串口打印函数，用于向串口发送的字符串。
输  入：str  -  要发送的字符串
输  出：无
返回值：无
创建者：奈特
调用例程：
创建日期：2020-07-15
修改记录：
-------------------------------------------------------*/
extern void fur_printf_base(const char * str,...);
/*-------------------------------------------------------
函数名：fur_in
描  述：FUR功能的串口读取函数，用于从串口读入一个字节的数据。
输  入：当前串口的SBUF。
输  出：无
返回值：无
创建者：奈特
调用例程：
void uart1_receive_callback(){//搭载在串口1上，
	fur_in(SBUF);//将串口1的SBUF作为参数。
}
创建日期：2020-06-01
修改记录：
2020-06-03:正式名称确定，修改函数名。
-------------------------------------------------------*/
extern void fur_in(u8 buf);
/*-------------------------------------------------------
函数名：fur_check
描  述：FUR的校对和返回函数，可以对某些指令进行响应、也用于返回寄存器值（查询功能）。放入主循环中。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-01
修改记录：
2020-06-03:正式名称确定，修改函数名。
-------------------------------------------------------*/
extern void fur_check(void);
/*-------------------------------------------------------
函数名：fur_init
描  述：FUR的初始化函数，调用eeprom函数来读取保存值。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-01
修改记录：
2020-06-03:正式名称确定，修改函数名。新增设定波特率功能。
-------------------------------------------------------*/
extern void fur_init(void);
/*-------------------------------------------------------
函数名：fur_help
描  述：FUR的帮助函数，应用在产品中可以帮助用户了解寄存器。
输  入：addr  -  寄存器地址。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-18
修改记录：
2020-07-09：新增参数addr，可以单独查询某个寄存器的说明。
在自己构建该函数时，注意有效参数是0~59999。如果收到了65535，
说明是要给全部用户寄存器写简要说明。如果是0~59999，说明是要
着重介绍该寄存器具体位的详细说明。
-------------------------------------------------------*/
extern void fur_help(u16 addr);
/*-------------------------------------------------------
函数名：fur_reg_in
描  述：FUR的数据存入函数。为了加快存储速度，该函数其实是个宏定义。
输  入：addr  -  要存入的地址。
        dat   -  要存入的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-22
修改记录：
2020-07-08：为了加快速度，修改成宏定义。
-------------------------------------------------------*/
#define fur_reg_in(addr,dat) fur_reg[addr+FUR_REG_OFFSET]=dat
/*-------------------------------------------------------
函数名：fur_reg_out
描  述：FUR的数据取出函数。为了加快读取速度，该函数其实是个宏定义。
输  入：addr  -  要存入的地址。
输  出：无
返回值：要取出的数据。
创建者：奈特
调用例程：无
创建日期：2020-06-22
修改记录：
2020-07-08：为了加快速度，修改成宏定义。
-------------------------------------------------------*/
#define fur_reg_out(addr) fur_reg[addr+FUR_REG_OFFSET]
/*-------------------------------------------------------
函数名：fur_reg_uart_reset
描  述：FUR的串口重置函数，用于在修改波特率无法通信时，强行把波特率转成115200。
输  入：无
输  出：无
返回值：要取出的数据。
创建者：奈特
调用例程：无
创建日期：2020-06-22
修改记录：
-------------------------------------------------------*/
extern void fur_reg_uart_reset(void);
/*-------------------------------------------------------
函数名：fur_reg_io_callback
描  述：FUR的寄存器读写处理回调函数，用于在接收一串数据后执行自己想要的动作。
输  入：addr  -  接收到的地址。
		dat   -  接收到的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-07
修改记录：
-------------------------------------------------------*/
extern void fur_reg_io_callback(u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：fur_error_callback
描  述：FUR的错误处理回调函数，用于在收到错误的数据时执行一些自定义动作。主机的用法和从机的用法差不多。
输  入：error_id  -  错误ID，详情参考宏定义。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-07
修改记录：
-------------------------------------------------------*/
extern void fur_error_callback(u8 error_id);
/*-------------------------------------------------------
函数名：fur_read
描  述：FUR主机的读取函数，用于读取另一个从机的寄存器。
输  入：addr  -  要读取的寄存器地址。
输  出：无
返回值：对应寄存器的值。
创建者：奈特
调用例程：无
创建日期：2020-07-08
修改记录：
-------------------------------------------------------*/
extern u16 fur_read(u16 addr);
/*-------------------------------------------------------
函数名：fur_write
描  述：FUR主机的读写函数，用于向一个从机的寄存器写入一个值。
输  入：addr  -  要写入的寄存器地址。
		dat  -   要写入的寄存器的值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-08
修改记录：
-------------------------------------------------------*/
extern void fur_write(u16 addr,u16 dat);
#endif 
