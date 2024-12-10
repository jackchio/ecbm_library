#ifndef _ECBM_STREAM_FUR_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_STREAM_FUR_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 奈特

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
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
/*------------------操作定义------------------*/
#define FUR_READ    (0x00)//读寄存器。
#define FUR_ADD     (0x01)//寄存器加上一个数。
#define FUR_DEC     (0x02)//寄存器减去一个数。
#define FUR_MUL     (0x03)//寄存器乘以一个数。
#define FUR_DIV     (0x04)//寄存器除以一个数。
#define FUR_AND     (0x05)//寄存器与上一个数。
#define FUR_OR      (0x06)//寄存器或上一个数。
#define FUR_XOR     (0x07)//寄存器异或上一个数。
#define FUR_BIT     (0x08)//寄存器位赋值。
#define FUR_EQU     (0x09)//寄存器赋值。
#define FUR_FBID    (0x0A)//返回ID，标记这条指令是查询ID用的。
/*------------------标志位定义----------------*/
#define FUR_WRITE   (0x80)//写入使能，标记这个数据需要写进寄存器。
#define FUR_HEX     (0x40)//16进制使能，标记这个数据需要以16进制表示。
/*------------------状态定义----------------*/
#define FUR_READY       (0)//就绪态，啥也不做。
#define FUR_GET_ADDR    (1)//接收地址状态。
#define FUR_GET_ID      (2)//接收ID状态。
#define FUR_GET_OP      (3)//接收操作码状态。
#define FUR_GET_OP_EX   (4)//接收操作数状态。
#define FUR_GET_DATA    (5)//接收数据状态。
#define FUR_GET_DATA16  (6)//接收16进制数据状态。
#define FUR_CMD_ID      (7)//确认ID的部分。
#define FUR_WAIT_END    (8)//等待结束符状态。
#define FUR_END_DO      (9)//协议结束，指令动作状态。
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_STREAM_FUR_CH_COUNT)//防止宏定义值为0时，数组的定义报错。
extern u8  es_fur_status_gu8a [ECBM_STREAM_FUR_CH_COUNT];//FUR接收状态机。
extern u16 es_fur_addr_gu16a  [ECBM_STREAM_FUR_CH_COUNT];//FUR地址。
extern u16 es_fur_dat16_gu16a [ECBM_STREAM_FUR_CH_COUNT];//FUR数据（16位）。
extern u8  es_fur_id_gu8a     [ECBM_STREAM_FUR_CH_COUNT];//FUR的ID临时变量。
extern u8  es_fur_dat8_gu8a   [ECBM_STREAM_FUR_CH_COUNT];//FUR数据（8位）。
extern u8  es_fur_operate_gu8a[ECBM_STREAM_FUR_CH_COUNT];//FUR操作数。
extern u8  es_fur_temp8_gu8a  [ECBM_STREAM_FUR_CH_COUNT];//FUR临时变量（8位）。
#endif
/*--------------------------------------程序定义-----------------------------------*/
///////////////////////////////////需要用户定义的函数////////////////////////////////
/*-------------------------------------------------------
函数名：es_fur_get_id
描  述：FUR获取ID函数，这个函数需要返回本机的ID号。
输  入：
    ch      本次通信的来源，通道号。
输  出：无
返回值：
    本机的ID号。
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern u8 es_fur_get_id(u8 ch);
/*-------------------------------------------------------
函数名：es_fur_read_reg
描  述：FUR读取寄存器函数。
输  入：
    ch      本次通信的来源，通道号。
    addr    要读取数据的寄存器的地址。
输  出：无
返回值：
    该地址对应的寄存器的数据。
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
2022-03-21：改名为es_fur_read_reg。
-------------------------------------------------------*/
extern u16 es_fur_read_reg(u8 ch,u16 addr);
/*-------------------------------------------------------
函数名：es_fur_write_reg
描  述：FUR写入寄存器函数。
输  入：
    ch      本次通信的来源，通道号。
    addr    要写入数据的寄存器的地址。
    dat     要写入的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
2022-03-21：改名为es_fur_write_reg。
-------------------------------------------------------*/
extern void es_fur_write_reg(u8 ch,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_fur_master_receive_callback
描  述：FUR主机接收回调函数，当本机作为主机发送指令给从机之后，从机返回数据时会调用本函数。
输  入：
    ch      本次通信的来源，通道号。
    addr    从机返回的寄存器地址，可以用来判断从机接收是否正确，或者用于区分不同操作。
    dat     从机的该地址的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_master_receive_callback(u8 ch,u16 addr,u16 dat);
///////////////////////////////////用户可以调用的函数////////////////////////////////
/*-------------------------------------------------------
函数名：es_fur_master_send
描  述：FUR主机发送函数，用于向一个支持FUR的设备发送一个数据。
输  入：
    ch      通过该通道发送数据。
    addr    要发送的目标寄存器地址。
    id      目标设备的ID。
    dat     要发送的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_master_send(u8 ch,u16 addr,u8 id,u16 dat);
/*-------------------------------------------------------
函数名：es_fur_master_read
描  述：FUR主机读取函数，用于读取一个支持FUR的设备的数据。
输  入：
    ch      通过该通道发送数据。
    addr    要读取的目标寄存器地址。
    id      目标设备的ID。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_master_read(u8 ch,u16 addr,u8 id);
////////////////////////////ECBM库调用的函数，用户不能调用//////////////////////////
/*-------------------------------------------------------
函数名：es_fur_reset
描  述：FUR重置函数，将FUR组件的参数全部重置。
输  入：
    ch  重置的通道。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_reset(u8 ch);
/*-------------------------------------------------------
函数名：es_fur_send_num_10
描  述：FUR发送数据函数，以10进制的格式发送。
输  入：
    ch      要发送的通道。
    num     要发送的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_send_num_10(u8 ch,u16 num);
/*-------------------------------------------------------
函数名：es_fur_send_num_16
描  述：FUR发送数据函数，以16进制的格式发送。
输  入：
    ch      要发送的通道。
    num     要发送的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_send_num_16(u8 ch,u16 num);
/*-------------------------------------------------------
函数名：es_fur_exe
描  述：FUR解析执行函数，放进stream框架里运行。
输  入：
    ch      和stream框架对接的通道。
    dat     和stream框架对接的参数。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-25
修改记录：
-------------------------------------------------------*/
extern void es_fur_exe(u8 ch,u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。