#ifndef _X_MODEM_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _X_MODEM_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define	X_MODEM_STOP		0//停止状态，X_MODEM组件不工作。
#define	X_MODEM_READY		1//就绪状态，等待上位机发送SOH。
#define	X_MODEM_READ_PACK	2//读取包编号。
#define	X_MODEM_CHECK_PACK	3//确认包编号。
#define	X_MODEM_READ_MODE	4//读数据模式。
#define	X_MODEM_ERROR		5//错误状态，只能等待超时退出。
#define	X_MODEM_CHECK_DATA	6//检查校验和。
#define	X_MODEM_DOING		7//完成状态，表明正确接收了一个包。
#define	X_MODEM_AGAIN		8//重发状态，说明传输有问题了。
#define	X_MODEM_FINISH		9//结束状态，说明已经传输完毕了。
/*--------------------------------------变量定义-----------------------------------*/
extern	u8 x_modem_data[128];//接收数据缓存。
extern	u8 x_modem_sum		;//校验和。
extern	u8 x_modem_pack		;//数据包编号。
extern	u8 x_modem_status	;//Xmodem状态机状态。
extern	u8 x_modem_count	;//接收数据计数。
extern	u8 x_modem_timer_count;//超时计数。
extern	u8 x_modem_timer_max;//超时最大值。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：x_modem_do
描  述：帧执行函数，每接收一包数据帧会执行一次。该函数需要自己编写。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_do(void);
/*-------------------------------------------------------
函数名：x_modem_done
描  述：帧执行完毕函数，当所有数据帧都接收完时会执行。该函数需要自己编写。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_done(void);
/*-------------------------------------------------------
函数名：x_modem_send
描  述：数据发送函数，用于返回接收状态和通知传输开启。该函数需要自己编写。
输  入：要发送的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_send(u8 dat);
/*-------------------------------------------------------
函数名：x_modem_receive
描  述：数据接收函数，放在串口中断里执行。
输  入：接收到的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_receive(u8 x_modem_buf);
/*-------------------------------------------------------
函数名：x_modem_run
描  述：数据处理函数，放在主循环里执行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_run(void);
/*-------------------------------------------------------
函数名：x_modem_start
描  述：传输开始函数，用于开启一次xmodem传输。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_start(void);
/*-------------------------------------------------------
函数名：x_modem_timer
描  述：计时函数，用于判断通信是否超时，放在定时器中断运行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_timer(void);
/*-------------------------------------------------------
函数名：x_modem_init
描  述：初始化函数。
输  入：超时时间。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-12-30
修改记录：
-------------------------------------------------------*/
void x_modem_init(u8 max);
#endif //和最上面的#ifndef配合成一个程序段。
       //以一个空行为结尾。