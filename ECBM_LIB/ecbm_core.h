#ifndef _ECBM_CORE_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_CORE_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
                            **************************
                            * 联系方式：进群778916610 *
                            * 若1群满人：进群927297508*
                            **************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//Frame Version Number 框架版本号
#define ECBM_FVN (3)
//Release Version Number 发布版本号
//当发生关键库文件增减时，该版本号加一。
#define ECBM_RVN (6)
//BUG Version Number 发布版本号
//每次发布到网上时，若只是修改BUG，该版本号加一。
#define ECBM_BVN (3)
//<h>单片机系统设置
//<i>该框内的选项有互斥的选项，请仔细阅读了解了结果再选择。
//<o>XDATA区初始化的大小
//<i>单位：字节。
//<i>为了加快启动速度，启动文件中不会再清零XDATA区数据，这意味着如果你没有对XDATA区变量进行赋初值的话，其内容可能是随机的。
//<i>但又由于清零语句在system_init函数中执行，所以会导致个别赋初值的变量被清零。
//<i>这个取舍问题请移步至说明文档【ECBM-V3说明书总章.pdf】。
//<i>因为清零原理就是一个for循环加赋值0语句，所以肯定清零的字节越多就耗时越长。
//<i>当实际应用的内存远远小于单片机最大容量时，建议在这里把值设置小一些，加快清零速度。
//<0-65535>
#define SYSTEM_CLEAR_XDATA_LEN  (0)
//<o>系统时钟频率选择
//<i>定义单片机运行的时钟频率（单位Hz）。
//<5529600UL => 5.5296M 
//<6000000UL => 6.0000M 
//<11059200UL=>11.0592M 
//<12000000UL=>12.0000M 
//<18432000UL=>18.4320M  
//<20000000UL=>20.0000M 
//<22118400UL=>22.1184M 
//<24000000UL=>24.0000M 
//<26000000UL=>26.0000M
//<27000000UL=>27.0000M
//<30000000UL=>30.0000M 
//<33000000UL=>33.0000M 
//<33177600UL=>33.1776M 
//<35000000UL=>35.0000M 
//<36864000UL=>36.8640M 
//<40000000UL=>40.0000M 
//<44236800UL=>44.2368M 
//<45000000UL=>45.0000M 
//<45158400UL=>45.1584M 
#define ECBM_SYSCLK_SETTING (24000000UL)
//<e>系统时钟输出
//<i>可以输出时钟频率用于驱动其他外设，或者用于检测内部的工作频率。
#define ECBM_SYSCLK_OUT_EN (0)
//<o>输出引脚
//<0=>输出到P54 
//<1=>输出到P16
#define ECBM_SYSLCK_OUT_PIN (1)
//<o.4..7>STC8F和STC8A设置输出分频
//<i>根据上面的型号选择，两个设置分频的选项只会生效一个。
//< 1=>SYSCLK/ 1  
//< 2=>SYSCLK/ 2 
//< 4=>SYSCLK/ 4 
//< 6=>SYSCLK/ 8  
//< 8=>SYSCLK/16 
//<10=>SYSCLK/32 
//<12=>SYSCLK/64  
//<14=>SYSCLK/128
#define ECBM_SYSCLK_OUT_SETTING_FA (0x18)
//<o>STC8G和STC8H设置输出分频
//<1-127>
//<i>根据上面的型号选择，两个设置分频的选项只会生效一个。
//<i>填多少就是分频多少，比如填6，就是SYSCLK/6。
#define ECBM_SYSCLK_OUT_SETTING_GH (1)
//</e>
//<q>单片机设置检查
//<i>勾选此选项，会自动调用system_check函数，然后在电脑端的串口助手看到单片机的一些信息。
//<i>只要能看到正常的信息输出，就说明库里的设置基本正确。
#define ECBM_MCU_CHECK_EN  (0) 
//</h>
//<h>单片机外设库的选用
//<i>这些是用于驱动单片机硬件外设的驱动库，有些库会对别的库有依赖，请注意看说明部分。在勾选某库的时候连同依赖的库一起勾选。
//<q>POWER库
//<i>该库提供了关于STC8的电源、复位、看门狗相关操作函数。
#define ECBM_POWER_LIB_EN (0)
//<e>UART库
//<i>该库提供了关于STC8的硬件UART相关操作函数。
#define ECBM_UART_LIB_EN (0)
//<q>自动下载功能
//<i>勾选此选项，就能使用自动下载功能。由于下载使用了串口1，所以得确保串口1呈使能状态并且输出引脚映射到P30和P31。
//<i>开启自动下载功能后，uart_int函数就会在system_init里被调用，不用再手动调用uart_int函数了。
#define ECBM_AUTO_DOWNLOAD_EN  (0)
//</e>
//<q>EXTI库
//<i>该库提供了关于STC8的外部中断相关操作函数。
#define ECBM_EXTI_LIB_EN (0)
//<q>TIMER库
//<i>该库提供了关于STC8的硬件TIMER相关操作函数。
#define ECBM_TIMER_LIB_EN (0)
//<q>EEPROM库
//<i>该库提供了关于STC8使用内置FLASH模拟的EEPROM相关操作函数。
#define ECBM_EEPROM_LIB_EN (0)
//<q>SPI库
//<i>该库提供了关于STC8的硬件SPI相关操作函数。
#define ECBM_SPI_LIB_EN (0)
//<q>IIC库
//<i>该库提供了关于STC8的硬件IIC相关操作函数。
#define ECBM_IIC_LIB_EN (0)
//<q>ADC库
//<i>该库提供了关于STC8的硬件ADC相关操作函数。
#define ECBM_ADC_LIB_EN (0)
//<q>CMP库
//<i>该库提供了关于STC8的硬件CMP相关操作函数。
#define ECBM_CMP_LIB_EN (0)
//<q>MDU16库
//<i>该库提供了关于STC8G的硬件乘除法相关操作函数。
#define ECBM_MDU16_LIB_EN (0)
//<q>PCA库
//<i>该库提供了关于STC8A的硬件PCA相关操作函数。
#define ECBM_PCA_LIB_EN (0)
//<q>PWM库
//<i>该库提供了关于STC8的硬件PWM相关操作函数。
#define ECBM_PWM_LIB_EN (0)
//<q>PWM16_OUT库
//<i>该库提供了关于STC8H的硬件PWM和输出有关的操作函数。目前仅在STC8H8K64U上测试过。
#define ECBM_PWM16_OUT_LIB_EN (0)
//<q>LCM库
//<i>该库提供了关于STC8的硬件LCM相关操作函数。
#define ECBM_LCM_LIB_EN (0)
//<q>LED库
//<i>该库提供了关于STC8的硬件LED相关操作函数。
#define ECBM_LED_LIB_EN (0)
//<q>LCD库
//<i>该库提供了关于STC8的硬件LCD相关操作函数。
#define ECBM_LCD_LIB_EN (0)
//</h>

//<h>单片机软件库的选用
//<i>这些是基于外设库的上层应用库或者是软件实现的某些外设功能库，这些库可能会对别的库有依赖，请注意看说明部分。在勾选某库的时候连同依赖的库一起勾选。
//<q>delay系列函数
//<i>该系列函数主要就是死循环延时，如果有其他实现方法，可以不用这个。
//<i>某些库会使用到，但是作为扩展功能，在实现最基本的操作时可以优化掉。
#define ECBM_DELAY_EN (0)
//<q>printf系列函数
//<i>该系列函数主要是为了将数据按字符串占位符的格式输出。
//<i>某些库（特别是串口）可能使用到，但是作为扩展功能，在实现最基本的操作时可以优化掉。
#define ECBM_PRINTF_EN (0)
//<q>str处理函数
//<i>该系列函数主要是为了从字符串中获取有用的信息。
//<i>某些库可能使用到，但是作为扩展功能，在实现最基本的库的时候可以优化掉。
#define ECBM_STRING_EN (0)
//<q>SOFT_SPI库
//<i>该库提供了关于STC8的软件SPI相关操作函数。
//<i>依赖GPIO库。
#define ECBM_SOFTSPI_LIB_EN (0)
//<q>SOFT_IIC库
//<i>该库提供了关于STC8的软件IIC相关操作函数。
//<i>依赖GPIO库。
#define ECBM_SOFTIIC_LIB_EN (0)
//<q>Eeprom-Data-System库
//<i>这是一个专为flash虚拟的eeprom打造的数据管理系统。模仿平衡擦的概念，使用flash空间来换flash寿命。
//<i>同时还实现了真eeprom的效果，即写入函数可以直接写入，不需要擦除。
//<i>依赖EEPROM库。
#define ECBM_EDS_LIB_EN (0)
//<e>10mS联盟
//<i>该联盟下的所有库或者框架都是基于10mS的定时器中断完成。
#define ECBM_10MS_EN (0)
//<o>选择10mS时基的生成定时器
//<0=>定时器0
//<1=>定时器1
//<2=>定时器2
//<3=>定时器3
//<4=>定时器4
#define ECBM_10MS_TIMER (0)
//<q>stream框架
//<i>使能之后可以使用强大的stream组件，但是相关的设置请移步到stream.h中去操作。
//<i>依赖UART库。
#define ECBM_STREAM_LIB_EN (0)
//</e>
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*------------------------------------头文件加载------------------------------------*/
#include "ecbm_reg.h"   //单片机寄存器的头文件。
#include "intrins.h"    //单片机C语言使用汇编指令的头文件。
#include "STDARG.H"     //多参数函数支持的头文件。
#if (ECBM_PRINTF_EN)
#include "stdio.h"      //sprintf相关函数支持的头文件。
#endif
/*------------------------------------通用配置设定----------------------------------*/
sbit    LED       =P5^5;     //通常ECBM的板子都会带一个LED，该LED采用低电平驱动。
#define LED_ON    LED=0;     //点亮LED。
#define LED_OFF   LED=1;     //关闭LED。
#define LED_BLINK LED=!LED;  //让LED闪烁。
/*------------------------------------常用功能设定----------------------------------*/
//以下几个参数，当idata用满的时候会有被覆盖的风险，建议保持idata区不要使用，多使用xdata区。
#define REG_BGV   read_idata_u16(0xEF)//片内1.3V电压的实测值。
#define REG_ID(x) read_idata_u8 (0xF1+x)//单片机的唯一ID码。

#define io2port(n) ((n)>>4)           //取引脚所在的P口，引脚格式需符合0xXX的格式。
#define io2pin(n)  (0x01<<((n)&0x0f)) //取引脚所在的PIN，引脚格式需符合0xXX的格式。
/*-----------------------------------库函数加载-----------------------------------*/
#include "gpio.h"
#include "power.h"
#include "uart.h"
#include "exti.h"
#include "timer.h"
#include "eeprom.h"
#include "spi.h"
#include "soft_spi.h"
#include "iic.h"
#include "soft_iic.h"
#include "adc.h"
#include "cmp.h"
#include "mdu16.h"
#include "pca.h"
#include "lcm.h"
#include "pwm.h"
#include "pwm16_out.h"
#include "led.h"
#include "lcd.h"
#include "nvic.h"
#include "stream.h"
#include "stream_fur.h"
#include "stream_modbus.h"
// #include "stream_xmodem.h"未开发
#include "stream_ecp.h"
#include "eds.h"
/*--------------------------------------变量定义-----------------------------------*/
extern bit     auto_download_en_gb;          //自动下载的使能
extern u8 data auto_download_old_char_gdu8;  //保存上一次接收的数据
extern u8 data auto_download_char_count_gdu8;//相同数据计数
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：delay_ms
描  述：毫秒级延时函数
输  入：需要延时的毫秒数，可输入1~65535。
输  出：无
返回值：无
创建者：奈特
调用例程：
    delay_ms(500);//延时500毫秒
创建日期：2019-10-8
修改记录：
2020-06-02:修复了延时0ms变成延时65535ms的BUG。
2022-02-06:从变量控制延时改成宏定义控制延时。
-------------------------------------------------------*/
extern void delay_ms(u16 ms);
/*-------------------------------------------------------
函数名：delay_us
描  述：微秒级延时函数
输  入：需要延时的节拍数，不是微秒数。可以通过delay_set_us函数算出所需微秒对应的节拍数。
输  出：无
返回值：无
创建者：奈特
调用例程：
    us_val=delay_set_us(20);//先算出20us对应的节拍数。
    ...//其他无关的代码。
    delay_us(us_val);//延时20us。
    ...//其他无关的代码。
创建日期：2019-10-8
修改记录：
2020-1-3：去掉了us_code.h文件
2022-02-06:从变量控制延时改成宏定义控制延时。
-------------------------------------------------------*/
extern void delay_us(u16 us);
/*-------------------------------------------------------
函数名：delay_set_us
描  述：微秒级延时转换函数，用于把微秒数转换成对应节拍数。
输  入：所需延时的微秒数。
输  出：无
返回值：该微秒数对应的节拍数。
创建者：奈特
调用例程：
    us_val=delay_set_us(20);//先算出20us对应的节拍数。
    ...//其他无关的代码。
    delay_us(us_val);//延时20us。
    ...//其他无关的代码。
创建日期：2019-10-8
修改记录：
-------------------------------------------------------*/
extern u16  delay_set_us(u16 us);
/*-------------------------------------------------------
函数名：system_uart_reset
描  述：自动重启函数，将其放置到串口中断的接收部分就能实现自动下载。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-8
修改记录：
2022-2-9：调整了代码，提升了下载成功率。
-------------------------------------------------------*/
extern void system_uart_reset(void);
/*-------------------------------------------------------
函数名：system_check
描  述：系统检测函数，会向串口发送单片机的一些基础信息。
    电脑收的到信息说明库函数运作正常。这个函数一般不常用。
    在图形界面中可以优化掉本函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    system_check();//发送单片机信息到串口。
创建日期：2019-10-8
修改记录：
2020-01-02：增加了检测的项目。
-------------------------------------------------------*/
extern void system_check(void);
/*----------------------------------其他系统函数-----------------------------------*/
/*-------------------------------------------------------
函数名：system_init
描  述：ECBM库函数的初始化函数，必须运行的函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    void main(){
        system_init();//初始化整个库函数。
        while(1){  
        }    
    }
创建日期：2019-10-8
修改记录：
2020-1-3：新加了自动判断晶振的功能。
2022-2-6：取消了自动判断晶振的功能。
-------------------------------------------------------*/
extern void system_init(void);
/*-------------------------------------------------------
函数名：str_find
描  述：字符串查找函数，用于查找一个字符串是否在另一个字符串内。
输  入：
    dest    需要查找的目标字符串。
    key     需要查找的字符串特征。
输  出：无
返回值：字符串特征在目标字符串的位置，从0开始计算。如果是-1，说明目标字符串没有该特征。
创建者：奈特
调用例程：
    str_find("0123456789","4",i);//在"0123456789"中查找"4"所在的位置。
创建日期：2019-10-9
修改记录：
2022-2-6：修复了重复字符会找不到的bug。
-------------------------------------------------------*/
extern u16 str_find(s8 * dest,s8 * key);
/*-------------------------------------------------------
函数名：str_read_pin
描  述：IO信息读取函数，用于读取字符串内目标位置的IO信息。
输  入：
    str     存有IO信息的字符串。
    pos     IO信息的位置，通过这个来区分字符串内的多个IO信息。
输  出：无
返回值：在该位置的IO信息。
创建者：奈特
调用例程：
    str_read_pin("SCL=D13,SDA=D14",11);//读取从下标11开始的IO信息，即会返回0x14。
创建日期：2019-10-9
修改记录：
-------------------------------------------------------*/
extern u8 str_read_pin(s8 * str,u16 pos);
/*-------------------------------------------------------
函数名：str_read_u16
描  述：u16变量读取函数，用于读取字符串内目标位置的u16型数值。
输  入：
    str     存有数值的字符串。
    pos     数值的位置，通过这个来区分字符串内的多个数值。
输  出：无
返回值：在该位置的数值。U16类型，即0~65535。
创建者：奈特
调用例程：
    str_read_u16("SCL=D13,w=128",9);//读取从下标8开始的数值，即会返回128。
创建日期：2019-10-9
修改记录：
2020-02-17：增加了一个停止的条件，即遇到点号也要停止。
-------------------------------------------------------*/
extern u16 str_read_u16(s8 * str,u16 pos);
/*-------------------------------------------------------
函数名：str_push_len
描  述：字符串推出指令函数（带字符串长度参数版）。用于把指定缓存中的指定关键词推出该缓存。
        为了防止前后数据重组造成干扰（比如“LEDLED_ON_OFF”在推出“LED_ON”后，剩下的部分还能重组成“LED_OFF”），
        所以推出关键词之后，只会把关键词所在位置清零，不会连接首尾数据（即“LEDLED_ON_OFF”在推出“LED_ON”后剩下“LED      _OFF”）。
输  入：
    dest    目标字符串缓存。
    dlen    目标字符串缓存的长度。
    key     需要推出的关键词。
    klen    关键词的长度。
输  出：无
返回值：
    0   推出失败，可能是目标缓存内没有该关键词。
    1   推出成功。
创建者：奈特
调用例程：无
创建日期：2020-02-17
修改记录：
-------------------------------------------------------*/
extern u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。