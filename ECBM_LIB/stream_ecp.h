#ifndef _ECBM_STREAM_ECP_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_STREAM_ECP_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
/*------------------------------------状态机宏定义---------------------------------*/
#define ES_ECP_READY             (0)   //等帧头。
#define ES_ECP_GET_DATA_LEN      (1)   //读取数据长度。
#define ES_ECP_CHECK_DATA_LEN    (2)   //检查数据长度。
#define ES_ECP_GET_TARGET_ID     (3)   //读取目标ID。
#define ES_ECP_GET_SOURCE_ID     (4)   //读取源头ID。
#define ES_ECP_GET_OPERATION     (5)   //读取操作码。
#define ES_ECP_GET_ADDR_31_24    (6)   //读取地址31~24。
#define ES_ECP_GET_ADDR_23_16    (7)   //读取地址23~16。
#define ES_ECP_GET_ADDR_15_8     (8)   //读取地址15~8。
#define ES_ECP_GET_ADDR_7_0      (9)   //读取地址7~0。
#define ES_ECP_GET_DATA          (10)  //读取数据。
#define ES_ECP_GET_CRC_H         (11)  //读取CRC高位。
#define ES_ECP_GET_CRC_L         (12)  //读取CRC低位。
#define ES_ECP_END               (13)  //等帧尾。
/*-------------------------------------指令宏定义----------------------------------*/
#define ES_ECP_CMD_TRIG             (0)//触发。
#define ES_ECP_CMD_TRIG_REPLY       (1)//触发回复。
#define ES_ECP_CMD_READ             (2)//读取。
#define ES_ECP_CMD_READ_REPLY       (3)//读取回复。
#define ES_ECP_CMD_WRITE            (4)//写入。
#define ES_ECP_CMD_WRITE_REPLY      (5)//写入回复。
#define ES_ECP_CMD_SET_BIT          (6)//置位。
#define ES_ECP_CMD_SET_BIT_REPLY    (7)//置位回复。
#define ES_ECP_CMD_RESET_BIT        (8)//复位位。
#define ES_ECP_CMD_RESET_BIT_REPLY  (9)//复位回复。

#define ES_ECP_CMD_AUTO_UPDATA      (200)//自动上发。
#define ES_ECP_CMD_ERROR_OPERATE    (254)//操作错误。
#define ES_ECP_CMD_ERROR_CRC        (255)//CRC错误。
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_STREAM_ECP_CH_COUNT)//防止宏定义值为0时，数组的定义报错。
    extern u8  es_ecp_status_gu8a   [ECBM_STREAM_ECP_CH_COUNT]; //状态机变量。
    extern u8  es_ecp_data_len_gu8a [ECBM_STREAM_ECP_CH_COUNT]; //用于存放参数、数据的长度。
    extern u8  es_ecp_count_gu8a    [ECBM_STREAM_ECP_CH_COUNT]; //用于统计实际接收的参数、数据长度。
    extern u8  es_ecp_source_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //源头ID，代表该帧由这个ID的器件发出。
    extern u8  es_ecp_target_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //目标ID，代表该帧应该由这个ID的器件接收。
    extern u8  es_ecp_operation_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //操作码缓存。
    extern u16 es_ecp_addr16_ex_gu16a[ECBM_STREAM_ECP_CH_COUNT];//16位扩展地址缓存。
    extern u16 es_ecp_addr16_gu16a [ECBM_STREAM_ECP_CH_COUNT];  //16位地址缓存。
    extern u16 es_ecp_crc_gu16a    [ECBM_STREAM_ECP_CH_COUNT];  //用于计算接收数据的CRC。
    extern u16 es_ecp_crc_buf_gu16a[ECBM_STREAM_ECP_CH_COUNT];  //用于存放数据帧里的CRC。
    extern u8  es_ecp_data_buf_gu8a[ECBM_STREAM_ECP_CH_COUNT][ES_ECP_DATA_BUF_MAX];//用于读写操作的缓存。
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：es_ecp_reset
描  述：ecp重置函数，将ecp组件的参数全部重置。
输  入：
    ch  重置的通道。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2023-10-14
修改记录：
-------------------------------------------------------*/
void es_ecp_reset(u8 ch);
/*------------------需要用户定义的函数------------------*/
/*-------------------------------------------------------
函数名：es_ecp_get_id
描  述：获取本机的ID函数。
输  入：无
输  出：无
返回值：
    本设备的ID。
创建者：奈特
参考例程：
    u8 es_ecp_get_id(void){
        return 1;
    }
创建日期：2022-05-27
修改记录：
-------------------------------------------------------*/
extern u8 es_ecp_get_id(u8 ch);
/*-------------------------------------------------------
函数名：es_ecp_trig
描  述：ECP的触发函数。
输  入：
    addr    触发的地址。
输  出：无  
返回值：
    0       正常执行。
    1       地址错误。（比如该地址是接收方没有设计动作的。）
创建者：奈特
参考例程：
    u8 es_ecp_trig(u16 addr){
        if(addr==0){
            LED_OFF;
        }else if(addr==1){
            LED_ON;
        }else{
            return 1;
        }
        return 0;
    }
创建日期：2022-08-11
修改记录：
-------------------------------------------------------*/
extern u8 es_ecp_trig(u8 ch,u16 addr);
/*-------------------------------------------------------
函数名：es_ecp_write
描  述：ECP的写入函数。
输  入：
    addr    写入的地址。
    buf     写入数据的缓存。
    len     写入的数据量。
输  出：无  
返回值：
    0       正常执行。
    1       地址错误。（比如该地址没有映射到任何寄存器上。）
    2       数据错误。（比如该地址对应的寄存器是需要某个区间的值，而参数给的数据不在这个区间。）
    3       长度错误。（比如该地址对应了一个16位寄存器，而且还需要同时写入两个字节的数据，但参数只给了一个字节。）
创建者：奈特
参考例程：
    u8 es_ecp_write(u16 addr,u8 * buf,u8 len){
        u8 i;
        for(i=0;i<len;i++){
            es_ecp_test[i]=buf[i];
        }
        return 0;
    }
创建日期：2022-05-27
修改记录：
2022-08-11：新增状态返回。
-------------------------------------------------------*/
extern u8 es_ecp_write(u8 ch,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
函数名：es_ecp_read
描  述：ECP的读取函数。
输  入：
    addr    读取的地址。
    buf     读取数据的缓存。
    len     读取的数据量。
输  出：无  
返回值：
    0       正常执行。
    1       地址错误。（比如该地址没有映射到任何寄存器上。）
    2       数据错误。（比如该地址对应的寄存器当前状态下是禁止读取的。）
    3       长度错误。（比如该地址对应了一个16位寄存器，参数却要读三个字节，从而引发溢出。）
创建者：奈特
参考例程：
    u8 es_ecp_read(u16 addr,u8 * buf,u8 len){
        u8 i;
        for(i=0;i<len;i++){
            buf[i]=es_ecp_test[i];
        }
        return 0;
    }
创建日期：2022-05-27
修改记录：
2022-08-11：新增状态返回。
-------------------------------------------------------*/
extern u8 es_ecp_read(u8 ch,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
函数名：es_ecp_read_callback
描  述：ECP的读取回调函数，当作为主机发送读取指令之后，收到从机返回数据的时候，执行本函数。
输  入：
    addr    读取的地址。
    buf     读取数据的缓存。
    len     读取的数据量。
输  出：无  
返回值：无
创建者：奈特
参考例程：
    void es_ecp_read_callback(u16 addr,u8 * buf,u8 len){
        if(addr==0x0000){
            oled_show(0,0,"%s",buf);
        }
    }
创建日期：2022-05-30
修改记录：
-------------------------------------------------------*/
extern void es_ecp_read_callback(u8 ch,u16 addr,u8 * buf,u8 len);
/*----------------------系统函数-----------------------*/
/*-------------------------------------------------------
函数名：es_ecp_reply
描  述：ECP回复处理函数。
输  入：
    len     回复的长度。
    cmd     回复的指令号。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-11
修改记录：
-------------------------------------------------------*/
extern void es_ecp_reply(u8 ch,u8 len,u8 cmd);
/*-------------------------------------------------------
函数名：es_ecp_cmd00
描  述：00指令处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-11
修改记录：
-------------------------------------------------------*/
extern void es_ecp_cmd00(u8 ch);
/*-------------------------------------------------------
函数名：es_ecp_cmd02
描  述：02指令处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-05-27
修改记录：
2022-08-11：重写了内部逻辑。
-------------------------------------------------------*/
extern void es_ecp_cmd02(u8 ch);
/*-------------------------------------------------------
函数名：es_ecp_cmd04
描  述：04指令处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-05-27
修改记录：
2022-08-11：重写了内部逻辑。
-------------------------------------------------------*/
extern void es_ecp_cmd04(u8 ch);
/*-------------------------------------------------------
函数名：es_ecp_cmd0608
描  述：06和08指令处理函数。
输  入：
    cmd     具体的操作数。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-11
修改记录：
-------------------------------------------------------*/
extern void es_ecp_cmd0608(u8 ch,u8 cmd);
/*-------------------------------------------------------
函数名：es_ecp_master_write
描  述：ECP主机写函数，向一个从机写入一串数据。
输  入：
    id      从机的ID。
    addr    要写入的首地址。
    buf     要写入的数据。
    len     要写入数据的长度。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-05-30
修改记录：
-------------------------------------------------------*/
extern void es_ecp_master_write(u8 ch,u8 id,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
函数名：es_ecp_master_read
描  述：ECP主机读函数，向一个从机发送读数据请求，收到从机的数据时会调用回调函数。
输  入：
    id      从机的ID。
    addr    要读取的首地址。
    len     要读取数据的长度。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-05-30
修改记录：
-------------------------------------------------------*/
extern void es_ecp_master_read(u8 ch,u8 id,u16 addr,u8 len);
/*-------------------------------------------------------
函数名：es_ecp_exe
描  述：ECP解析执行函数，放进stream框架里运行。
输  入：
    dat     和stream框架对接的参数。
输  出：无
返回值：无
创建者：奈特
参考例程：
    void ecbm_stream_exe(u8 dat){
        es_ecp_exe(dat);
    }
创建日期：2022-05-27
修改记录：
-------------------------------------------------------*/
extern void es_ecp_exe(u8 ch,u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。