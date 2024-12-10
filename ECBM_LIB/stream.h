#ifndef _ECBM_STREAM_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_STREAM_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
#define ECBM_STREAM_VERSION "V2.0"
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>框架配置
//<o>数据帧间隔时间
//<10-2500:10>
//<i>单位mS。默认定时器10mS中断一次,因此这个时间是10的倍数。
//<i>从接收到最后一个数据开始计算，超过这个时间没有再次接受到数据时，认为对方已经传送完一个数据帧。
#define ECBM_STREAM_TIME_MS  (20)
#define ECBM_STREAM_TIME_MAX (ECBM_STREAM_TIME_MS/10)
//<o>串口空闲时间
//<10-2500:10>
//<i>单位mS。默认定时器10mS中断一次,因此这个时间是10的倍数。
//<i>从接收到最后一个数据开始计算，超过这个时间没有再次接收到数据时，认为对方已经发送完全部数据，串口恢复到空闲状态。
//<i>该值应该比数据帧间隔时间大。
#define ECBM_STREAM_IDLE_MS  (80)
#define ECBM_STREAM_IDLE_MAX (ECBM_STREAM_IDLE_MS/10)
//</h>
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>通道配置
//<e>通道1使能
//<i>使能之后，会自动将串口1的数据对接到通道1。
#define ECBM_STREAM_CH1_EN (1)
//<o>队列缓存大小
//<i>单位“字节”。
#define ECBM_STREAM_CH1_SZIE    (10)
//<q>自定义协议
#define ECBM_STREAM_USER_CH1_EN  (0)
//<q>FUR组件
//<i>这是ECBM自主研发的快速(Fast)串口(Uart)访问寄存器(Reg)组件。
//<i>基于ASCII码的明文通信，协议通俗易懂，不仅可以快速读写寄存器，还能对其进行运算。
#define ECBM_STREAM_FUR_CH1_EN  (0)
//<q>MODBUS组件
//<i>通用的MODBUS协议RTU版本，目前集成了[01H][05H][03H][06H][10H][02H][04H]共7个指令。
//<i>这个组件也是用于读写寄存器的。
#define ECBM_STREAM_MODBUS_CH1_EN (1)
//<q>ECP组件
//<i>这是ECBM自主研发的ECBM通信(Communication)协议(Protocol)组件。
//<i>这个组件可以以高质量传输一些重要的、少量的数据。
//<i>不过在单片机没有其他任务的时候也可以全速跑ECP来传输大量数据。
#define ECBM_STREAM_ECP_CH1_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>通道2使能
//<i>使能之后，会自动将串口2的数据对接到通道2。
#define ECBM_STREAM_CH2_EN (0)
//<o>队列缓存大小
//<i>单位“字节”。
#define ECBM_STREAM_CH2_SZIE    (10)
//<q>自定义协议
#define ECBM_STREAM_USER_CH2_EN  (0)
//<q>FUR组件
//<i>这是ECBM自主研发的快速(Fast)串口(Uart)访问寄存器(Reg)组件。
//<i>基于ASCII码的明文通信，协议通俗易懂，不仅可以快速读写寄存器，还能对其进行运算。
#define ECBM_STREAM_FUR_CH2_EN (0)
//<q>MODBUS组件
//<i>通用的MODBUS协议RTU版本，目前集成了[01H][05H][03H][06H][10H][02H][04H]共7个指令。
//<i>这个组件也是用于读写寄存器的。
#define ECBM_STREAM_MODBUS_CH2_EN (0)
//<q>ECP组件
//<i>这是ECBM自主研发的ECBM通信(Communication)协议(Protocol)组件。
//<i>这个组件可以以高质量传输一些重要的、少量的数据。
//<i>不过在单片机没有其他任务的时候也可以全速跑ECP来传输大量数据。
#define ECBM_STREAM_ECP_CH2_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>通道3使能
//<i>使能之后，会自动将串口3的数据对接到通道3。
#define ECBM_STREAM_CH3_EN (0)
//<o>队列缓存大小
//<i>单位“字节”。
#define ECBM_STREAM_CH3_SZIE    (10)
//<q>自定义协议
#define ECBM_STREAM_USER_CH3_EN  (0)
//<q>FUR组件
//<i>这是ECBM自主研发的快速(Fast)串口(Uart)访问寄存器(Reg)组件。
//<i>基于ASCII码的明文通信，协议通俗易懂，不仅可以快速读写寄存器，还能对其进行运算。
#define ECBM_STREAM_FUR_CH3_EN (0)
//<q>MODBUS组件
//<i>通用的MODBUS协议RTU版本，目前集成了[01H][05H][03H][06H][10H][02H][04H]共7个指令。
//<i>这个组件也是用于读写寄存器的。
#define ECBM_STREAM_MODBUS_CH3_EN (0)
//<q>ECP组件
//<i>这是ECBM自主研发的ECBM通信(Communication)协议(Protocol)组件。
//<i>这个组件可以以高质量传输一些重要的、少量的数据。
//<i>不过在单片机没有其他任务的时候也可以全速跑ECP来传输大量数据。
#define ECBM_STREAM_ECP_CH3_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>通道4使能
//<i>使能之后，会自动将串口4的数据对接到通道4。
#define ECBM_STREAM_CH4_EN (0)
//<o>队列缓存大小
//<i>单位“字节”。
#define ECBM_STREAM_CH4_SZIE    (10)
//<q>自定义协议
#define ECBM_STREAM_USER_CH4_EN  (0)
//<q>FUR组件
//<i>这是ECBM自主研发的快速(Fast)串口(Uart)访问寄存器(Reg)组件。
//<i>基于ASCII码的明文通信，协议通俗易懂，不仅可以快速读写寄存器，还能对其进行运算。
#define ECBM_STREAM_FUR_CH4_EN (0)
//<q>MODBUS组件
//<i>通用的MODBUS协议RTU版本，目前集成了[01H][05H][03H][06H][10H][02H][04H]共7个指令。
//<i>这个组件也是用于读写寄存器的。
#define ECBM_STREAM_MODBUS_CH4_EN (0)
//<q>ECP组件
//<i>这是ECBM自主研发的ECBM通信(Communication)协议(Protocol)组件。
//<i>这个组件可以以高质量传输一些重要的、少量的数据。
//<i>不过在单片机没有其他任务的时候也可以全速跑ECP来传输大量数据。
#define ECBM_STREAM_ECP_CH4_EN (0)
//</e>
#define ECBM_STREAM_CH_COUNT (ECBM_STREAM_CH1_EN+ECBM_STREAM_CH2_EN+ECBM_STREAM_CH3_EN+ECBM_STREAM_CH4_EN)
//</h>
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>组件内部功能使能与配置
//<q>比较组件
//<i>就是对接收到的字符串和目标字符串进行比较，当缓冲区存在目标字符串的时候，可以触发某些动作。
#define ECBM_STREAM_CMP_EN (0)
//<h>FUR组件
//<i>这是ECBM自主研发的快速(Fast)串口(Uart)访问寄存器(Reg)组件。
//<i>基于ASCII码的明文通信，协议通俗易懂，不仅可以快速读写寄存器，还能对其进行运算。
#define ECBM_STREAM_FUR_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_FUR_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_FUR_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_FUR_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_FUR_CH4_EN))
//<q>串口回复使能
//<i>FUR虽然是基于串口的应用，但是数据的反馈往往可以用其他形式。
//<i>比如用板载OLED来显示数据、 直接观察舵机的旋转角度等。此时把回复功能取消掉可以节省一些空间。
#define ECBM_STREAM_FUR_UART_SEND_EN (1)
//<q>主机使能
//<i>FUR在设计之初就是主打电脑串口助手和单片机的便捷通信，但是现在也支持单片机和单片机的通信。
//<i>如果不需要这个主机功能，可以取消以节省空间。
#define ECBM_STREAM_FUR_MATER_EN (1)
//</h>
//<h>MODBUS组件
//<i>通用的MODBUS协议RTU版本，目前集成了[01H][05H][03H][06H][10H][02H][04H]共7个指令。
//<i>这个组件也是用于读写寄存器的。
#define ECBM_STREAM_MODBUS_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_MODBUS_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_MODBUS_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_MODBUS_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_MODBUS_CH4_EN))
//<h>从机功能选择
//<q>[01H]读线圈
//<i>如果和线圈有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD01_EN (1)
//<q>[05H]写单个线圈
//<i>如果和线圈有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD05_EN (1)
//<q>[03H]读寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD03_EN (1)
//<q>[06H]写单个寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD06_EN (1)
//<q>[10H]写多个寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD10_EN (1)
//<q>[02H]读离散量输入
//<i>如果和IO系统有关的指令都没有被使能，那么IO相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD02_EN (1)
//<q>[04H]读输入寄存器
//<i>如果和IO系统有关的指令都没有被使能，那么IO相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_CMD04_EN (1)
//<q>CRC错误回调函数
//<i>如果通信中出现了CRC错误，那么就会调用这个回调函数。如果不对其进行处理，可以不使能这个选项。
#define ES_MODBUS_RTU_CRC_ERR_EN (0)
//以下是合并各个分散的宏定义的总结定义：
#define ES_MODBUS_RTU_CMD_BIT_EN  (ES_MODBUS_RTU_CMD01_EN+ES_MODBUS_RTU_CMD05_EN)
#define ES_MODBUS_RTU_CMD_REG_EN  (ES_MODBUS_RTU_CMD03_EN+ES_MODBUS_RTU_CMD06_EN+ES_MODBUS_RTU_CMD10_EN)
#define ES_MODBUS_RTU_CMD_IO_EN   (ES_MODBUS_RTU_CMD02_EN+ES_MODBUS_RTU_CMD04_EN)
#define ES_MODBUS_RTU_CMD_ALL_EN  (ES_MODBUS_RTU_CMD_BIT_EN+ES_MODBUS_RTU_CMD_REG_EN+ES_MODBUS_RTU_CMD_IO_EN)
//</h>
//<e>主机功能选择
//<i>modbus大都是从机，因此这里提供主机的使能，在不使用主机的情况可以节约flash空间。
#define ES_MODBUS_RTU_MASTER_EN (0)
//<q>[01H]读线圈
//<i>如果和线圈有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD01_EN (1)
//<q>[05H]写单个线圈
//<i>如果和线圈有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD05_EN (1)
//<q>[03H]读寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD03_EN (1)
//<q>[06H]写单个寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD06_EN (1)
//<q>[10H]写多个寄存器
//<i>如果和寄存器有关的指令都没有被使能，那么线圈读写相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD10_EN (1)
//<q>[02H]读离散量输入
//<i>如果和IO系统有关的指令都没有被使能，那么IO相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD02_EN (1)
//<q>[04H]读输入寄存器
//<i>如果和IO系统有关的指令都没有被使能，那么IO相关的函数和缓存都将被优化掉。
#define ES_MODBUS_RTU_MASTER_CMD04_EN (1)
//<q>CRC错误回调函数
//<i>如果通信中出现了CRC错误，那么就会调用这个回调函数。如果不对其进行处理，可以不使能这个选项。
#define ES_MODBUS_RTU_MASTER_CRC_ERR_EN (0)
//以下是合并各个分散的宏定义的总结定义：
#define ES_MODBUS_RTU_MASTER_CMD_0102_EN        (ES_MODBUS_RTU_MASTER_CMD01_EN+ES_MODBUS_RTU_MASTER_CMD02_EN)
#define ES_MODBUS_RTU_MASTER_CMD_0304_EN        (ES_MODBUS_RTU_MASTER_CMD03_EN+ES_MODBUS_RTU_MASTER_CMD04_EN)
#define ES_MODBUS_RTU_MASTER_CMD_01020304_EN    (ES_MODBUS_RTU_MASTER_CMD_0102_EN+ES_MODBUS_RTU_MASTER_CMD_0304_EN)
#define ES_MODBUS_RTU_MASTER_CMD_050610_EN      (ES_MODBUS_RTU_MASTER_CMD05_EN+ES_MODBUS_RTU_MASTER_CMD06_EN+ES_MODBUS_RTU_MASTER_CMD10_EN)
//</e>
//<o>通用缓存总数
//<i>单位是字（16位）。
//<i>在从机模式中，由于CRC的存在，在多字节写入的时候，不能立刻把数据存入，需要用一个缓存存起来，待CRC验证完毕之后才能一起写入。
//<i>在主机模式中，可能从机返回了多个数据，还是CRC的原因，不能立刻对这些返回的数据进行处理，所以这个缓存也有这方面的用处。
#define ES_MODBUS_RTU_BUF_SIZE  (10)
//</h>
//<h>ECP组件
//<i>这是ECBM自主研发的ECBM通信(Communication)协议(Protocol)组件。
//<i>这个组件可以以高质量传输一些重要的、少量的数据。
//<i>不过在单片机没有其他任务的时候也可以全速跑ECP来传输大量数据。
#define ECBM_STREAM_ECP_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_ECP_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_ECP_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_ECP_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_ECP_CH4_EN))
//<o>数据缓存大小
//<1-200>
//<i>该缓存在读取指令和写入指令里都用得到，所以在内存足够的情况下，设置得越大越好。
#define ES_ECP_DATA_BUF_MAX (32)
//<q>主机使能
//<i>若仅仅是拿来当从机，那么主机部分代码就可以不要了。省出一点空间。
#define ES_ECP_MASTER_EN (1)
//</h>
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define ECBM_STREAM_TIME_EN   (0x01)  //计时使能。
#define ECBM_STREAM_TIME_OUT  (0x02)  //定时器超时标志。
#define ECBM_STREAM_UART_IDLE (0x04)  //串口空闲标志。
/*--------------------------------------变量定义-----------------------------------*/
#if ((ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)) 
    #if (ECBM_STREAM_CH1_EN)
    extern u8 xdata ecbm_stream_ch1_buf_gxu8a[ECBM_STREAM_CH1_SZIE];//stream的通道1接收缓存。
    extern u8 ecbm_stream_ch1_point_gu8;                            //stream的通道1接收缓存的写入地址。
    extern u8 ecbm_stream_ch1_read_point_gu8;                       //stream的通道1读缓存的进度。
    extern u8 ecbm_stream_ch1_count_gu8;                            //stream的通道1接收到的数据数量。
    extern u8 ecbm_stream_ch1_time_gu8;                             //stream的通道1定时器计时变量。
    extern u8 ecbm_stream_ch1_status_gu8;                           //stream的通道1状态。
    #endif
    #if (ECBM_STREAM_CH2_EN)
    extern u8 xdata ecbm_stream_ch2_buf_gxu8a[ECBM_STREAM_CH2_SZIE];//stream的通道2接收缓存。
    extern u8 ecbm_stream_ch2_point_gu8;                            //stream的通道2接收缓存的写入地址。
    extern u8 ecbm_stream_ch2_read_point_gu8;                       //stream的通道2读缓存的进度。
    extern u8 ecbm_stream_ch2_count_gu8;                            //stream的通道2接收到的数据数量。
    extern u8 ecbm_stream_ch2_time_gu8;                             //stream的通道2定时器计时变量。
    extern u8 ecbm_stream_ch2_status_gu8;                           //stream的通道2状态。
    #endif
    #if (ECBM_STREAM_CH3_EN)
    extern u8 xdata ecbm_stream_ch3_buf_gxu8a[ECBM_STREAM_CH3_SZIE];//stream的通道3接收缓存。
    extern u8 ecbm_stream_ch3_point_gu8;                            //stream的通道3接收缓存的写入地址。
    extern u8 ecbm_stream_ch3_read_point_gu8;                       //stream的通道3读缓存的进度。
    extern u8 ecbm_stream_ch3_count_gu8;                            //stream的通道3接收到的数据数量。
    extern u8 ecbm_stream_ch3_time_gu8;                             //stream的通道3定时器计时变量。
    extern u8 ecbm_stream_ch3_status_gu8;                           //stream的通道3状态。
    #endif
    #if (ECBM_STREAM_CH4_EN)
    extern u8 xdata ecbm_stream_ch4_buf_gxu8a[ECBM_STREAM_CH4_SZIE];//stream的通道4接收缓存。
    extern u8 ecbm_stream_ch4_point_gu8;                            //stream的通道4接收缓存的写入地址。
    extern u8 ecbm_stream_ch4_read_point_gu8;                       //stream的通道4读缓存的进度。
    extern u8 ecbm_stream_ch4_count_gu8;                            //stream的通道4接收到的数据数量。
    extern u8 ecbm_stream_ch4_time_gu8;                             //stream的通道4定时器计时变量。
    extern u8 ecbm_stream_ch4_status_gu8;                           //stream的通道4状态。
    #endif
#endif    
/*--------------------------------------程序定义-----------------------------------*/
///////////////////////////////////需要用户定义的函数////////////////////////////////
/*-------------------------------------------------------
函数名：ecbm_stream_user_exe
描  述：用户自定义的流处理函数，可根据需要添加。
输  入：
    ch       通道号。
    dat      接收到的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2024-05-18
修改记录：
-------------------------------------------------------*/
extern void ecbm_stream_user_exe(u8 ch,u8 dat);
///////////////////////////////////用户可以调用的函数////////////////////////////////
/*-------------------------------------------------------
函数名：ecbm_stream_init
描  述：stream初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-05-22
修改记录：
-------------------------------------------------------*/
extern void ecbm_stream_init(void);
/*-------------------------------------------------------
函数名：ecbm_stream_main
描  述：流处理主函数函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-03-24
修改记录：
2021-11-11：针对串口空闲的判断做了修改。
-------------------------------------------------------*/
extern void ecbm_stream_main(void);
/*-------------------------------------------------------
函数名：ecbm_stream_cmp
描  述：流处理比对函数。
输  入：
    dat     和ecbm_stream_exe对接的接口。
    str     需要比对的字符串。
输  出：
    count   比对的计数值，当该值和字符串长度相等时，表示比对成功。
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-10-21
修改记录：
-------------------------------------------------------*/
extern void ecbm_stream_strcmp(u8 dat,u8 code * str,u8 * count);
////////////////////////////ECBM库调用的函数，用户不能调用//////////////////////////
/*-------------------------------------------------------
函数名：ecbm_stream_timer_run
描  述：时间运行函数，用于提供流处理的时间判断功能。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-03-24
修改记录：
2021-11-11：新增了串口空闲的判断。
-------------------------------------------------------*/    
extern void ecbm_stream_timer_run(void);
/*-------------------------------------------------------
函数名：es_crc16
描  述：CRC16位校验函数，算法上主要和modbus兼容。
输  入：
    crc     当前的CRC值。
    buf     当前需要进行CRC校验的数据。
输  出：无  
返回值：
    经过计算后得到的新CRC值。
创建者：奈特
参考例程：无
创建日期：2022-05-27
修改记录：
-------------------------------------------------------*/
extern u16 es_crc16(u16 crc,u8 buf);
extern u16 es_send_whit_crc(u8 ch,u16 crc,u8 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。