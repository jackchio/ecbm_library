#ifndef _ECBM_STREAM_MODBUS_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_STREAM_MODBUS_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
#define ES_MODBUS_RTU_READY           (0)   //就绪态，此时可以接受一帧modbus数据。
#define ES_MODBUS_RTU_WAIT            (1)   //等待态，当发生错误之后，在此等待当前数据帧结束。
#define ES_MODBUS_RTU_FUN_NUM         (2)   //读取功能码，在此读取功能码。
#define ES_MODBUS_RTU_ADDRH           (3)   //读取地址高8位。
#define ES_MODBUS_RTU_ADDRL           (4)   //读取地址低8位。
#define ES_MODBUS_RTU_DATA_COUNTH     (5)   //读取数据或者个数的高8位。
#define ES_MODBUS_RTU_DATA_COUNTL     (6)   //读取数据或者个数的低8位。
#define ES_MODBUS_RTU_COUNT_ERR       (7)   //读取个数错误。
#define ES_MODBUS_RTU_CRCH            (8)   //读取CRC的高8位。
#define ES_MODBUS_RTU_CRCL            (9)   //读取CRC的低8位。
#define ES_MODBUS_RTU_DO              (10)  //处理态，在该状态下处理数据。
#define ES_MODBUS_RTU_DATAH           (11)  //读取地址高8位。
#define ES_MODBUS_RTU_DATAL           (12)  //读取地址低8位。
#define ES_MODBUS_RTU_BYTE_COUNT      (13)  //读取字节数量。
#define ES_MODBUS_RTU_RETURN_COUNT    (14)  //返回的字节数量。
#define ES_MODBUS_RTU_0102_RETURN     (15)  //[01H][02H]读指令的返回帧。
#define ES_MODBUS_RTU_0304_RETURN     (16)  //[03H][04H]读指令的返回帧。
#define ES_MODBUS_RTU_ERROR_CODE      (17)  //接收错误码。
/*-------------------------------------模式宏定义----------------------------------*/
#define ES_MODBUS_RTU_MODE_SLAVE      (0)   //从机模式。
#define ES_MODBUS_RTU_MODE_MASTER     (1)   //主机模式。
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_STREAM_MODBUS_CH_COUNT)//防止宏定义值为0时，数组的定义报错。
    extern u8  es_modbus_rtu_mode        [ECBM_STREAM_MODBUS_CH_COUNT]; //主从模式。
    extern u8  es_modbus_rtu_send_id     [ECBM_STREAM_MODBUS_CH_COUNT]; //发送的ID。
    extern u8  es_modbus_rtu_reply_count [ECBM_STREAM_MODBUS_CH_COUNT]; //返回的数据数量。
    extern u8  es_modbus_rtu_status      [ECBM_STREAM_MODBUS_CH_COUNT]; //状态机使用的变量。
    extern u8  es_modbus_rtu_broadcast_en[ECBM_STREAM_MODBUS_CH_COUNT]; //广播模式。
    extern u8  es_modbus_rtu_fun_code    [ECBM_STREAM_MODBUS_CH_COUNT]; //功能码。
    extern u16 es_modbus_rtu_address     [ECBM_STREAM_MODBUS_CH_COUNT]; //数据地址。
    extern u16 es_modbus_rtu_data_count  [ECBM_STREAM_MODBUS_CH_COUNT]; //数据/个数。
    extern u16 es_modbus_rtu_uart_crc    [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC计算缓存。
    extern u16 es_modbus_rtu_crc_buf     [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC缓存。
    extern u8  es_modbus_rtu_cmd_count   [ECBM_STREAM_MODBUS_CH_COUNT]; //指令缓存计数。
    extern u8  es_modbus_rtu_count_gu8a  [ECBM_STREAM_MODBUS_CH_COUNT]; //通用计数。
    extern u16 es_modbus_rtu_cmd_buf[ECBM_STREAM_MODBUS_CH_COUNT][ES_MODBUS_RTU_BUF_SIZE];//通用缓存。
#endif
/*--------------------------------------程序定义-----------------------------------*/
/////////////////////////////需要用户定义的函数（从机部分）///////////////////////////
/*-------------------------------------------------------
函数名：es_modbus_rtu_get_id
描  述：获取本机ID函数，modbus通讯中会调用，要返回本机的ID号。
输  入：
    ch      数据来源的通道。
输  出：无
返回值：
    本机的ID值。
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern u8 es_modbus_rtu_get_id(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_cmd_read_io_bit
描  述：读取离散输入寄存器函数，功能码02H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
输  出：
    dat     该地址对应的离散输入寄存器的数据，只有0和1两种可能。
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_read_io_bit(u8 ch,u16 addr,u8 * dat);
/*-------------------------------------------------------
函数名：es_modbus_cmd_read_io_reg
描  述：读取离散输入寄存器函数，功能码04H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
输  出：
    dat     该地址对应的输入寄存器的数据。
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_read_io_reg(u8 ch,u16 addr,u16 * dat);
/*-------------------------------------------------------
函数名：es_modbus_cmd_write_bit
描  述：写单个线圈寄存器函数，功能码05H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
    dat     要写入该地址的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_write_bit(u8 ch,u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：es_modbus_cmd_read_bit
描  述：读单个线圈寄存器函数，功能码01H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
输  出：
    dat     该地址对应的线圈寄存器的数据。
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_read_bit(u8 ch,u16 addr,u8 * dat);
/*-------------------------------------------------------
函数名：es_modbus_cmd_write_reg
描  述：写单个保持寄存器函数，功能码06H和10H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
    dat     要写入该地址的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_write_reg(u8 ch,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_modbus_cmd_read_reg
描  述：读单个保持寄存器函数，功能码03H会用到。
输  入：
    ch      数据来源的通道。
    addr    主机传来的地址信息。
输  出：
    dat     该地址对应的保持寄存器的数据。
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_cmd_read_reg(u8 ch,u16 addr,u16 * dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_crc_err_callback
描  述：CRC出错回调函数，当modbus通讯的CRC校验出错时调用。
输  入：
    ch      数据来源的通道。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_crc_err_callback(u8 ch);
/////////////////////////////需要用户定义的函数（主机部分）///////////////////////////
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_crc_err_callback
描  述：CRC出错回调函数，当modbus通讯的CRC校验出错时调用。
输  入：
    ch      数据来源的通道。
    id      出错的器件ID。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-17
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_crc_err_callback(u8 ch,u8 id);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_err_code_callback
描  述：错误码回调函数，当从机返回的是错误码时调用。
输  入：
    ch          数据来源的通道。
    id          出错的器件ID。
    cmd         出错的功能码。
    err_code    错误码。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-17
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_err_code_callback(u8 ch,u8 id,u8 cmd,u8 err_code);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x01_callback
描  述：主机01号功能码回调函数，当主机发送01号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    读到的线圈寄存器地址。
    dat     读到的该地址对应的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x01_callback(u8 ch,u8 id,u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x02_callback
描  述：主机02号功能码回调函数，当主机发送02号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    读到的离散输入寄存器地址。
    dat     读到的该地址对应的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x02_callback(u8 ch,u8 id,u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x03_callback
描  述：主机03号功能码回调函数，当主机发送03号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    读到的保持寄存器地址。
    dat     读到的该地址对应的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x03_callback(u8 ch,u8 id,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x04_callback
描  述：主机04号功能码回调函数，当主机发送04号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    读到的输入寄存器地址。
    dat     读到的该地址对应的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x04_callback(u8 ch,u8 id,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x05_callback
描  述：主机05号功能码回调函数，当主机发送05号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    已写入线圈寄存器地址。
    dat     已写入的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x05_callback(u8 ch,u8 id,u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x06_callback
描  述：主机06号功能码回调函数，当主机发送06号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    已写入保持寄存器地址。
    dat     已写入的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x06_callback(u8 ch,u8 id,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x10_callback
描  述：主机16号功能码回调函数，当主机发送16号功能码之后，从机返回时调用本函数。
输  入：
    ch      数据来源的通道。
    id      返回数据的器件ID。
    addr    已写入保持寄存器地址首地址。
    len     已写入的数据数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x10_callback(u8 ch,u8 id,u16 addr,u16 len); 
/////////////////////////////用户可以调用的函数（主机部分）///////////////////////////
/*-------------------------------------------------------
函数名：es_modbus_rtu_set_slave_mode
描  述：设置从机模式函数，调用任意主机发送函数都会把modbus切换到主机模式，而后就得靠这个函数切换回来。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-15
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_set_slave_mode(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x01
描  述：主机01号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要读的线圈地址。
    len     要读的数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x01(u8 ch,u8 id,u16 addr,u16 len);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x02
描  述：主机02号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要读的离散输入寄存器地址。
    len     要读的数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x02(u8 ch,u8 id,u16 addr,u16 len);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x03
描  述：主机03号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要读的保持寄存器地址。
    len     要读的数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x03(u8 ch,u8 id,u16 addr,u16 len);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x04
描  述：主机04号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要读的输入寄存器地址。
    len     要读的数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x04(u8 ch,u8 id,u16 addr,u16 len);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x05
描  述：主机05号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要写的线圈地址。
    dat     要写的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x05(u8 ch,u8 id,u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x06
描  述：主机06号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要写的保持寄存器地址。
    dat     要写的数据。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x06(u8 ch,u8 id,u16 addr,u16 dat);
/*-------------------------------------------------------
函数名：es_modbus_rtu_master_0x10
描  述：主机16号功能码发送函数。
输  入：
    id      对方的ID。
    addr    要写的保持寄存器地址。
    dat     要写的数据数组。
    len     要写的数量。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2022-08-12
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_master_0x10(u8 ch,u8 id,u16 addr,u16 * dat,u16 len);
/////////////////////////////////系统函数，不需要调用////////////////////////////////
/*-------------------------------------------------------
函数名：es_modbus_rtu_reset
描  述：modbus重置函数，将modbus组件的参数全部重置。
输  入：
    ch  重置的通道。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2023-10-14
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_reset(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_err_num
描  述：modbus返回错误码函数。
输  入：
    fun_num     当前的功能码。
    err_num     需要报错的错误码。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_err_num(u8 ch,u8 fun_num,u8 err_num);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x01
描  述：01号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x01(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x02
描  述：02号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x02(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x03
描  述：03号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x03(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x04
描  述：04号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x04(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x05
描  述：05号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x05(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x06
描  述：06号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x06(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_cmd_0x10
描  述：16号功能码处理函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_cmd_0x10(u8 ch);
/*-------------------------------------------------------
函数名：es_modbus_rtu_exe
描  述：modbus_rtu解析执行函数，放进stream框架里运行。
输  入：
    ch      当前通道。
    dat     和stream框架对接的参数。
输  出：无
返回值：无
创建者：奈特
参考例程：无
创建日期：2021-10-28
修改记录：
-------------------------------------------------------*/
extern void es_modbus_rtu_exe(u8 ch,u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。