#ifndef _ECBM_STREAM_XMODEM_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_STREAM_XMODEM_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
/*--------------------------------------资源要求-----------------------------------*/
#if (ECBM_STREAM_SZIE<=132)
#   error STREAM的缓存太小了，要使用X-modem请修改到132以上。
#endif
/*---------------------------------------宏定义------------------------------------*/
/*------------------状态定义----------------*/
#define ES_XMODEM_STOP          (0)//停止状态，ES_XMODEM组件不工作。
#define ES_XMODEM_READY         (1)//就绪状态，等待上位机发送SOH。
#define ES_XMODEM_READ_PACK     (2)//读取包编号。
#define ES_XMODEM_CHECK_PACK    (3)//确认包编号。
#define ES_XMODEM_READ_MODE     (4)//读数据模式。
#define ES_XMODEM_ERROR         (5)//错误状态，只能等待超时退出。
#define ES_XMODEM_CHECK_DATA    (6)//检查校验和。
/*-----------------ASCII定义---------------*/
#define ES_XMODEM_SOH   (0x01)
#define ES_XMODEM_EOT   (0x04)
#define ES_XMODEM_ACK   (0x06)
#define ES_XMODEM_NAK   (0x15)
#define ES_XMODEM_CAN   (0x18)
/*--------------------------------------变量定义-----------------------------------*/
extern u8 es_xmodem_buf_start[];//xmodem的数据在缓存中的开始位置。
extern u8 es_xmodem_sum;      //校验和。
extern u8 es_xmodem_pack;     //数据包编号。
extern u8 es_xmodem_status;   //Xmodem状态机状态。
extern u8 es_xmodem_count;    //接收数据计数。
/*--------------------------------------程序定义-----------------------------------*/
/*------------------需要用户定义的函数------------------*/
/*-------------------------------------------------------
函数名：es_xmodem_write_reg
描  述：xmodem数据输入函数，这个函数会将接受到数据写入到单片机的某处。
输  入：
    pack    包编号，鉴于xmodem具备重发功能，需要通过包编号来判断是新数据还是重发的数据。
    offset  包内数据偏移，xmodem一个包有128字节。所以该值将会从0加到127。
    buf     当前偏移对应的数值。
输  出：无
返回值：无
创建者：奈特
参考例程：
    void es_xmodem_write_reg(u8 pack,u8 offset,u8 buf){
        //将包编号和包内偏移合并成一个地址量，即可把数据对接写入到eeprom。
        eeprom_write((u16)(pack-1)*128+(u16)offset,buf);//包编号从1开始，地址计算却从0开始，所以要减一。
    }
创建日期：2021-11-12
修改记录：
2022-03-21:改名为es_xmodem_write_reg。
-------------------------------------------------------*/
extern void es_xmodem_write_reg(u8 pack,u8 offset,u8 buf);
/*-----------------------系统函数-----------------------*/
/*-------------------------------------------------------
函数名：es_xmodem_start
描  述：xmodem开始接收函数，调用后会通知上位机开始发送数据。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-11-12
修改记录：
-------------------------------------------------------*/
extern void es_xmodem_start(void);
/*-------------------------------------------------------
函数名：es_xmodem_exe
描  述：xmodem解析执行函数，放进stream框架里运行。
输  入：
    dat     和stream框架对接的参数。
输  出：无
返回值：无
创建者：奈特
参考例程：
    void ecbm_stream_exe(u8 dat){
        es_xmodem_exe(dat);
    }
创建日期：2021-11-12
修改记录：
-------------------------------------------------------*/
extern void es_xmodem_exe(u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。