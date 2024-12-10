#ifndef _ECBM_IIC_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_IIC_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<o>IIC速度
//<100000=>100KHz  
//<400000=>400KHz
#define ECBM_IIC_WAIT (400000L)
//<o.4..5>IIC默认管脚
//<i>此设置只会改动初始化的管脚，在实际应用中随时可以使用iic_set_pin函数修改IIC管脚，达到分时复用的效果。
//<0=>SCL-P15|SDA-P14(全系列,除STC8G1K08和STC8G1K08A以外)
//<1=>SCL-P25|SDA-P24(全系列,除STC8G1K08和STC8G1K08A以外) 
//<2=>SCL-P77|SDA-P76(全系列,除STC8G1K08和STC8G1K08A以外) 
//<3=>SCL-P32|SDA-P33(全系列,除STC8G1K08和STC8G1K08A以外)
//<0=>SCL-P32|SDA-P33(仅限STC8G1K08和STC8G1K08A) 
//<1=>SCL-P54|SDA-P55(仅限STC8G1K08和STC8G1K08A) 
#define ECBM_IIC_IO (0)
//<o>无响应超时时间
//<i>输入的是时钟数，可以输入1000~65530。
//<1000-65530>
#define ECBM_IIC_TIMEOUT (20000)
//<h>从机设置
//<e>从机地址筛选
//<i>从机需要一个地址来筛选信息，当然也可以不用筛选，不过最好是在监听的时候才这样做。
#define ECBM_IIC_SLAVE_ADDR_EN (0)
//<o>从机地址
//<i>如果要跑EIICP协议的话，这个设置就失效了。
//<i>请注意：由于IIC中把地址的最后一位做读写位。所以这里的地址其实是7位的。除了0用于广播之外，1~127都可以用。
//<1-127>
#define ECBM_IIC_SLAVE_ADDR (0x0F)
//</e>
//<o>从机数据缓存
//<i>这里定义了缓存的大小，理论当然是越大越好，但是为了不占用太多空间，协议最长用到多少就设多少就好了。
#define ECBM_IIC_BUF_MAX (20)
//<q>EIICP协议支持
//<i>这是一个以IIC为基础的异步通信协议，采用一问一答的形式，可以实现多主多从通信。不过为了不冲突，同一时间内最好还是一个主机。
#define ECBM_EIICP_EN (0)
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#if ((ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1))
#define IIC_PIN_P32_P33 (0)  //将IIC的输出IO设置到P1口。
#define IIC_PIN_P54_P55 (16) //将IIC的输出IO设置到P2口。
#else
#define IIC_PIN_P15_P14 (0)  //将IIC的输出IO设置到P1口。
#define IIC_PIN_P25_P24 (16) //将IIC的输出IO设置到P2口。
#define IIC_PIN_P77_P76 (32) //将IIC的输出IO设置到P7口。
#define IIC_PIN_P32_P33 (48) //将IIC的输出IO设置到P3口。
#endif
#define EIICP_CMD_TRIG             (0)//触发。
#define EIICP_CMD_TRIG_REPLY       (1)//触发回复。
#define EIICP_CMD_READ             (2)//读取。
#define EIICP_CMD_READ_REPLY       (3)//读取回复。
#define EIICP_CMD_WRITE            (4)//写入。
#define EIICP_CMD_WRITE_REPLY      (5)//写入回复。

#define EIICP_CMD_AUTO_UPDATA      (200)//自动上发。
#define EIICP_CMD_ERROR_OPERATE    (254)//操作错误。
/*--------------------------------------变量定义-----------------------------------*/
extern bit iic_master_busy_gb;                      //主机状态下，发送的忙标志位。
extern u8 xdata iic_index_gxu8;                     //IIC当前使用的目录号。
extern bit eiicp_trig_gb;                           //EIICP中用于触发处理函数的标志位。
extern u8  eiicp_data_count_gu8;                    //EIICP中用于统计接收数据数量的变量。
extern u8  eiicp_data_buf_gu8a[ECBM_IIC_BUF_MAX];   //EIICP中用于保存数据的缓存。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：iic_set_pin
描  述：IIC的引脚设置函数。
输  入：
    group   设置IIC输出的引脚。可以输入以上宏定义区列举的引脚。
输  出：无
返回值：无
创建者：奈特
调用例程：iic_set_pin(IIC_PIN_P1);//SCL脚为P15，SDA脚为P14 
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
extern void iic_set_pin(u8 group);
/*-------------------------------------------------------
函数名：iic_set_pin_linkage
描  述：IIC的引脚设置函数（内联版）。该函数只会被库函数调用。
输  入：
    group   设置IIC输出的引脚。可以输入以上宏定义区列举的引脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-03-05
修改记录：
-------------------------------------------------------*/
extern void iic_set_pin_linkage(u8 group);
/*-------------------------------------------------------
函数名：iic_reset_pin
描  述：IIC的引脚还原函数。当IIC转移到其他脚的时候，将原来的IO恢复正常的设置。
输  入：
    group   设置需要还原的引脚。可以输入以上宏定义区列举的引脚。
输  出：无
返回值：无
创建者：奈特
调用例程：iic_reset_pin(IIC_PIN_P15_P14);//P15和P14还原成弱上拉模式 
创建日期：2019-8-23
修改记录：
-------------------------------------------------------*/
extern void iic_reset_pin(u8 group);
/*-------------------------------------------------------
函数名：iic_master_init
描  述：IIC主机初始化函数。将硬件IIC当成主机来用，参数可以在图形界面输入。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：iic_master_init();//初始化IIC主机
创建日期：2019-8-23
修改记录：
2020-03-05:支持多路复用，但不会自动切换，需要手动切换。
-------------------------------------------------------*/
extern void iic_master_init(void);
/*-------------------------------------------------------
函数名：iic_slave_init
描  述：IIC从机初始化函数。将硬件IIC当成从机来用，参数可以在图形界面输入。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：iic_slave_init();//初始化IIC从机
创建日期：2019-8-23
修改记录：
2020-03-05:支持多路复用。 但是实际上从机无法做到真正的多路复用。先加进去先。
-------------------------------------------------------*/
extern void iic_slave_init(void);
/*-------------------------------------------------------
函数名：iic_set_master_mode
描  述：IIC设置主机函数。可以将已经初始化好的IIC硬件转成主机模式。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-10-24
修改记录：
-------------------------------------------------------*/
extern void iic_set_master_mode(void);
/*-------------------------------------------------------
函数名：iic_set_slave_mode
描  述：IIC设置从机函数。可以将已经初始化好的IIC硬件转成从机模式。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-10-24
修改记录：
-------------------------------------------------------*/
extern void iic_set_slave_mode(void);
/*-------------------------------------------------------
函数名：iic_start、iic_stop、iic_write、iic_write_ack、iic_write_nack、iic_read、iic_read_ack
描  述：
    IIC的各种操作函数。请根据器件的协议来排布。
        iic_start     :开始函数，对应IIC开始帧。
        iic_stop      :停止函数，对应IIC停止帧。
        iic_write     :写数据函数，往总线上写1字节数据。
        iic_write_ack :写ACK函数，往总线上写一个ACK。
        iic_write_nack:写NO ACK函数，往总线上写一个NO ACK。
        iic_read      :读数据函数，读取总线上一个字节的数据。
        iic_read_ack  :读ACK函数，读取总线上是否有ACK。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    iic_start();    //开始传输
    iic_write(0x78);//先发地址0x78
    iic_read_ack(); //等器件回ACK
    iic_write(cd);  //发送数据类型
    iic_read_ack(); //等器件回ACK
    iic_write(buf); //发送数据
    iic_read_ack(); //等器件回ACK
    iic_stop();     //停止传输
创建日期：2019-8-23
修改记录：
2020-03-02:将参数类型从char改成了u8
2020-03-05:全员添加超时判定，防止了死循环。
-------------------------------------------------------*/
extern void iic_start     (void);
extern void iic_stop      (void);
extern void iic_write     (u8 dat);
extern void iic_write_ack (void);
extern void iic_write_nack(void);
extern u8   iic_read      (void);
extern bit iic_read_ack   (void);
/*-------------------------------------------------------
函数名：eiicp_master_trig
描  述：EIICP主机模式触发函数。
输  入：
    target_id   目标的ID。
    addr        要触发的地址。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_trig(u8 target_id,u16 addr);
/*-------------------------------------------------------
函数名：eiicp_master_write
描  述：EIICP主机模式写函数。
输  入：
    target_id   目标的ID。
    addr        要写入的首地址。
    dat         要写入的数据。
    len         要写入的数据长度。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_write(u8 target_id,u16 addr,u8 * dat,u8 len);
/*-------------------------------------------------------
函数名：eiicp_master_read
描  述：EIICP主机模式读函数。
输  入：
    target_id   目标的ID。
    addr        要读取的首地址。
    len         要读取的数据长度。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_read(u8 target_id,u16 addr,u8 len);
/*-------------------------------------------------------
函数名：eiip_main
描  述：EIICP协议的主函数，放到main里去执行，通过eiicp_trig_gb标志位触发执行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_main(void);
///////////////////////////////////需要用户定义的函数////////////////////////////////
/*-------------------------------------------------------
函数名：eiicp_get_id
描  述：EIICP获取本机ID函数。
输  入：无
输  出：无
返回值：
    本机的ID。
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern u8 eiicp_get_id(void);
/*-------------------------------------------------------
函数名：eiicp_base_reg_trig
描  述：EIICP的基础函数——寄存器触发函数。
输  入：
    addr    被触发的寄存器地址。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_base_reg_trig(u16 addr);
/*-------------------------------------------------------
函数名：eiicp_base_reg_read
描  述：EIICP的基础函数——读寄存器函数。
输  入：
    addr    要读取的寄存器地址。
输  出：无
返回值：
    该寄存器的数据。
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern u8 eiicp_base_reg_read(u16 addr);
/*-------------------------------------------------------
函数名：eiicp_base_reg_write
描  述：EIICP的基础函数——写寄存器函数。
输  入：
    addr    要读取的寄存器地址。
    dat     写入该寄存器的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_base_reg_write(u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：eiicp_master_trig_callback
描  述：EIICP的主机触发回调函数。
输  入：
    addr    触发的寄存器地址。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_trig_callback(u16 addr);
/*-------------------------------------------------------
函数名：eiicp_master_read_callback
描  述：EIICP的主机读取寄存器回调函数。
输  入：
    addr    读到的寄存器地址。
    dat     该寄存器内部的数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_read_callback(u16 addr,u8 dat);
/*-------------------------------------------------------
函数名：eiicp_master_write_callback
描  述：EIICP的主机写入寄存器回调函数。
输  入：
    addr    写到寄存器的地址。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-11-28
修改记录：
-------------------------------------------------------*/
extern void eiicp_master_write_callback(u16 addr);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。