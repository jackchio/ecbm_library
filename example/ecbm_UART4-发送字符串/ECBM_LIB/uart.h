#ifndef _ECBM_UART_H_
#define _ECBM_UART_H_
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
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>printf函数缓存
//<i>设定缓存数组的大小，当RAM足够的时候，可以设大一些，这样能输入的字也多一些。
#define UART_BUF_MAX 64
//<e>串口1使能与设置
#define UART1_EN 1
//<o>波特率
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART1_BAUD_RATE 115200
//<o.6..7>工作模式
//<0=>同步移位串行方式 <1=>可变波特率8位数据方式
//<2=>固定波特率9位数据方式 <3=>可变波特率9位数据方式
//<i>模式0：同步移位串行模式。TXD脚输出同步时钟，RXD收发数据。波特率为Fosc/12或者Fosc/2。
//<i>模式1：可变波特率8位数据。最常用的模式，TXD发、RXD收。波特率由定时器的溢出率决定。
//<i>模式2：固定波特率9位数据。第9位可做校验位。TXD发、RXD收。波特率为Fosc/64或者Fosc/32。
//<i>模式3：可变波特率9位数据。第9位可做校验位。TXD发、RXD收。波特率由定时器的溢出率决定。
//<q.4>允许接收
//<i>允许串口1的接收功能。
//<e.5>多机通信模式
//<i>在该模式下，串口会通过第9位来筛选地址帧。
//<i>当第9位为1时，说明是地址帧，设置RI=1。
//<i>否则该帧数据会被放弃。
#define UART1_SCON_CONFIG 0x50
//<o>从机地址
//<i>可设置0x00~0xFE。因为0xFF是广播地址。
//<i>设置从机地址之后，还可以设置地址使能，使得从机不需要完全匹配地址就能响应。
//<i>比如从机地址为0xA2,设置D7~D4位使能，那么串口发来0xA0~0xAF都能唤醒从机。
//<i>又比如从机地址为0xA2,设置D7~D3位使能，那么串口发来0xA0~0xA7都能唤醒从机。
//<i>还比如从机地址为0xA2,设置D7~D0位使能，那么只有串口发来0xA2才能唤醒从机。
//<0-0xFE>
#define UART1_SADDR_CONFIG 0xA1
//<q.7>从机地址D7位使能
//<q.6>从机地址D6位使能
//<q.5>从机地址D5位使能
//<q.4>从机地址D4位使能
//<q.3>从机地址D3位使能
//<q.2>从机地址D2位使能
//<q.1>从机地址D1位使能
//<q.0>从机地址D0位使能
#define UART1_SADEN_CONFIG 0xFE
//</e>
//<o.7>波特率加倍控制位
//<i>只针对模式1、模式2、模式3的波特率加倍。
//<i>但是推荐模式2才用加倍功能，模式1和模式3别用。
//<0=>不加倍 <1=>加倍
#define UART1_PCON_CONFIG 0x00
//<o.5>模式0的加倍控制位
//<i>针对模式0的波特率加倍。但实测IO翻转频率超过3M后，会有比较严重的毛刺。
//<i>所以除非晶振是6M的，否则不建议用6倍数。
//<0=>不加倍，固定为Fosc/12 <1=>6倍速，即Fosc/2
//<o.0>波特率产生器选择
//<0=>定时器1 <1=>定时器2 
#define UART1_AUXR_CONFIG 0x00
//<o.6..7>输出引脚
//<i>串口1有四对引脚可以选择，分时复用相当于四个串口。
//<0=>RxD-P30|TxD-P31  <1=>RxD-P36|TxD-P37
//<2=>RxD-P16|TxD-P17  <3=>RxD-P43|TxD-P44
#define UART1_IO 0x00
//<o>校验方式
//<i>选择校验功能的话，必须先把通信位数改成9位数据。
//<0=>无校验 <1=>奇校验 <2=>偶校验 <3=>1校验 <4=>0校验 
#define UART1_PARITY 0
//<q>开放串口1发送回调函数
#define UART1_SEND_CALLBACK_EN 0
//<q>开放串口1接收回调函数
#define UART1_RECEIVE_CALLBACK_EN 0
//</e>
//<e>串口2使能与设置
#define UART2_EN 0
//<o>波特率
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART2_BAUD_RATE 115200
//<o.7>通信位数
//<0=>8位数据 <1=>9位数据
//<q.4>允许接收
//<i>允许串口2的接收功能。
//<q.5>多机通信模式
//<i>在该模式下，串口会通过第9位来筛选地址帧。
//<i>当第9位为1时，说明是地址帧，设置S2RI=1。
//<i>否则该帧数据会被放弃。
#define UART2_S2CON_CONFIG 0x10
//<o.0>输出引脚
//<i>串口2有两对引脚可以选择，分时复用相当于两个串口。
//<0=>RxD-P10|TxD-P11  <1=>RxD-P40|TxD-P42
#define UART2_IO 0x00
//<o>校验方式
//<i>选择校验功能的话，必须先把通信位数改成9位数据。
//<0=>无校验 <1=>奇校验 <2=>偶校验 <3=>1校验 <4=>0校验 
#define UART2_PARITY 0
//<q>开放串口2发送回调函数
#define UART2_SEND_CALLBACK_EN 0
//<q>开放串口2接收回调函数
#define UART2_RECEIVE_CALLBACK_EN 0
//</e>
//<e>串口3使能与设置
#define UART3_EN 0
//<o>波特率
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART3_BAUD_RATE 115200
//<o.7>通信位数
//<0=>8位数据 <1=>9位数据
//<o.6>波特率产生器选择
//<0=>定时器2 <1=>定时器3
//<q.4>允许接收
//<i>允许串口3的接收功能。
//<q.5>多机通信模式
//<i>在该模式下，串口会通过第9位来筛选地址帧。
//<i>当第9位为1时，说明是地址帧，设置S3RI=1。
//<i>否则该帧数据会被放弃。
#define UART3_S3CON_CONFIG 0x10
//<o.1>输出引脚
//<i>串口3有两对引脚可以选择，分时复用相当于两个串口。
//<0=>RxD-P00|TxD-P01  <1=>RxD-P50|TxD-P51
#define UART3_IO 0
//<o>校验方式
//<i>选择校验功能的话，必须先把通信位数改成9位数据。
//<0=>无校验 <1=>奇校验 <2=>偶校验 <3=>1校验 <4=>0校验 
#define UART3_PARITY 0
//<q>开放串口3发送回调函数
#define UART3_SEND_CALLBACK_EN 0
//<q>开放串口3接收回调函数
#define UART3_RECEIVE_CALLBACK_EN 0
//</e>
//<e>串口4使能与设置
#define UART4_EN 1
//<o>波特率
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART4_BAUD_RATE 115200
//<o.7>通信位数
//<0=>8位数据 <1=>9位数据
//<o.6>波特率产生器选择
//<0=>定时器2 <1=>定时器4
//<q.4>允许接收
//<i>允许串口4的接收功能。
//<q.5>多机通信模式
//<i>在该模式下，串口会通过第9位来筛选地址帧。
//<i>当第9位为1时，说明是地址帧，设置S4RI=1。
//<i>否则该帧数据会被放弃。
#define UART4_S4CON_CONFIG 0x50
//<o.2>输出引脚
//<i>串口4有两对引脚可以选择，分时复用相当于两个串口。
//<0=>RxD-P02|TxD-P03  <1=>RxD-P52|TxD-P53
#define UART4_IO 0
//<o>校验方式
//<i>选择校验功能的话，必须先把通信位数改成9位数据。
//<0=>无校验 <1=>奇校验 <2=>偶校验 <3=>1校验 <4=>0校验 
#define UART4_PARITY 0
//<q>开放串口4发送回调函数
#define UART4_SEND_CALLBACK_EN 0
//<q>开放串口4接收回调函数
#define UART4_RECEIVE_CALLBACK_EN 0
//</e>

//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define UART1_IT_ON  do{ES=1;}while(0)     //打开串口1的中断开关。
#define UART1_IT_OFF do{ES=0;}while(0)     //关闭串口1的中断开关。
#define UART2_IT_ON  do{IE2|=0x01;}while(0)//打开串口2的中断开关。
#define UART2_IT_OFF do{IE2&=0xFE;}while(0)//关闭串口2的中断开关。
#define UART3_IT_ON  do{IE2|=0x08;}while(0)//打开串口3的中断开关。
#define UART3_IT_OFF do{IE2&=0xF7;}while(0)//关闭串口3的中断开关。
#define UART4_IT_ON  do{IE2|=0x10;}while(0)//打开串口4的中断开关。
#define UART4_IT_OFF do{IE2&=0xEF;}while(0)//关闭串口4的中断开关。
#define UART1_FUN    interrupt 4 //串口1中断号。
#define UART2_FUN    interrupt 8 //串口2中断号。
#define UART3_FUN    interrupt 17//串口3中断号。
#define UART4_FUN    interrupt 18//串口4中断号。

#define UART1_PIN_P30_P31 0x00
#define UART1_PIN_P36_P37 0x40
#define UART1_PIN_P16_P17 0x80
#define UART1_PIN_P43_P44 0xC0

#define UART2_PIN_P10_P11 0x00
#define UART2_PIN_P40_P42 0x01
/*--------------------------------------变量定义-----------------------------------*/
extern bit uart1_busy;//串口1发送忙标志位。
extern bit uart2_busy;//串口2发送忙标志位。
extern bit uart3_busy;//串口3发送忙标志位。
extern bit uart4_busy;//串口4发送忙标志位。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：uart_init
描  述：串口初始化函数，可以根据设置初始化所有的串口。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
2019-12-26:增加了串口3和串口4。
2020-1-5：现在uart_init可以在system_init自动开启了。
-------------------------------------------------------*/
extern void uart_init(void);
/*-------------------------------------------------------
函数名：uart_set_io
描  述：串口输出IO设置函数。可以将串口映射到别的IO口上。
输  入：id  -  要操作的串口编号，从1开始。
		io  -  要切换的目标IO，输入值参考宏定义。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
2019-12-26:增加了串口3和串口4。
-------------------------------------------------------*/
extern void uart_set_io(u8 id,u8 io);
/*-------------------------------------------------------
函数名：uart_set_baud
描  述：串口波特率设置函数。
输  入：id  -  要操作的串口编号，从1开始。
		baud-  要设置的波特率，立即生效。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-06-01
修改记录：
-------------------------------------------------------*/
extern void uart_set_baud(u8 id,u32 baud);
/*-------------------------------------------------------
函数名：uart_char
描  述：串口单个字节发送函数。
输  入：id  -  要操作的串口编号，从1开始。
		ch  -  要发送的字符。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
2019-12-26:增加了串口3和串口4。
-------------------------------------------------------*/
extern void uart_char(u8 id,u8 ch);
/*-------------------------------------------------------
函数名：uart_char_9
描  述：9位模式下的字符发送函数。
输  入：id  -  要操作的串口编号，从1开始。
		ch  -  要发送的字符。
		bit9-  第九位的电平值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
-------------------------------------------------------*/
extern void uart_char_9(u8 id,u8 ch,bit bit9);
/*-------------------------------------------------------
函数名：uart_string
描  述：串口字符串发送函数。
输  入：id  -  要操作的串口编号，从1开始。
		str -  要发送的字符串。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
-------------------------------------------------------*/
extern void uart_string(u8 id,u8 * str);
/*-------------------------------------------------------
函数名：uart_printf
描  述：串口打印函数。除了带上串口编号外，和printf一样的用法。
输  入：id  -  要操作的串口编号，从1开始。
		str -  要发送的格式化内容。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-11
修改记录：
-------------------------------------------------------*/
extern void uart_printf(u8 id,const char * str,...);
/*-------------------------------------------------------
函数名：uart1_receive_callback
描  述：串口1接收回调函数。串口1接收到数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart1_receive_callback(void);
/*-------------------------------------------------------
函数名：uart1_send_callback
描  述：串口1发送回调函数。串口1发送完一个数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart1_send_callback(void);
/*-------------------------------------------------------
函数名：uart2_receive_callback
描  述：串口2接收回调函数。串口2接收到数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart2_receive_callback(void);
/*-------------------------------------------------------
函数名：uart2_send_callback
描  述：串口2发送回调函数。串口2发送完一个数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart2_send_callback(void);
/*-------------------------------------------------------
函数名：uart3_receive_callback
描  述：串口3接收回调函数。串口3接收到数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart3_receive_callback(void);
/*-------------------------------------------------------
函数名：uart3_send_callback
描  述：串口3发送回调函数。串口3发送完一个数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart3_send_callback(void);
/*-------------------------------------------------------
函数名：uart4_receive_callback
描  述：串口4接收回调函数。串口4接收到数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart4_receive_callback(void);
/*-------------------------------------------------------
函数名：uart4_send_callback
描  述：串口4发送回调函数。串口4发送完一个数据的时候会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-07
修改记录：
-------------------------------------------------------*/
extern void uart4_send_callback(void);
#endif
