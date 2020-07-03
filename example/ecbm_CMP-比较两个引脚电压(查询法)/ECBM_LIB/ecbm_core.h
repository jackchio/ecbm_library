#ifndef _ECBM_CORE_H_
#define _ECBM_CORE_H_
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
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//Frame Version Number 框架版本号
#define ECBM_FVN 2
//Release Version Number 发布版本号
//当发生关键库文件增减时，该版本号加一。
#define ECBM_RVN 1
//BUG Version Number 发布版本号
//每次发布到网上时，若只是修改BUG，该版本号加一。
#define ECBM_BVN 5
//<o>STC8系列前缀和RAM选择
//<i>列表提供的芯片类型都是测试通过能使用的。按照加入ecbm库的时间排序。
//<0=>STC8F2K <1=>STC8A8K <2=>STC8G2K  <3=>STC8G1K
#define ECBM_MCU_MAIN_RAM 1
//<o>ROM选择
//<i>选择单片机的flash容量大小，主要影响唯一ID的读取和EEPROM空间的大小。
//<8192=>08 <16384=>16 <24576=>24 <32768=>32 <40960=>40 
//<49152=>48 <57344=>56 <61440=>60 <65024=>64
#define ECBM_MCU_ROM 65024
//<o>串口后缀
//<i>这个选项会影响uart.h的使能情况。请根据实际芯片选择。
//< 1=>无  < 2=>S2 < 4=>S4
#define ECBM_MCU_UART 4
//<o>ADC后缀
//<i>这个选项会影响adc.h的计算结果。请根据实际芯片选择。
//< 0=>无 <10=>A10 <12=>A12
#define ECBM_MCU_ADC_BIT 12
//<o>其他后缀
//<i>这个选项根据型号的不同会影响不同的外设。请根据实际芯片选择。
//< 0=>无 <1=>-48PIN <2=>A-8PIN
#define ECBM_MCU_OTHER 0
//<o>EEPROM选择
//<i>由于ROM为64的型号，它的EEPROM大小是可选的，所以需要这里提供EEPROM的大小。
//<i>非64的型号，EEPROM的大小是固定的，这个参数就可以不用管了，程序也不会用到。
#define ECBM_MCU_EEPROM_SIZE 512
//<h>单片机系统设置
//<i>该框内的选项有互斥的选项，请仔细阅读了解了结果再选择。
//<o>单片机系统时钟设置
//<i>该选项可以选择单片机时钟来源。后期也可以用函数修改时钟来源。
//<i>内部高速时钟HSI(标准)：选择这个选项的话，ecbm库会自动获取STCISP工具的设置的标准频率。（标准频率是指11.0592M、12M、24M这种）
//<i>内部高速时钟HSI(自定义)：自定义频率是指6.666M、22.33M这种自己输入的频率。需要在下面的“高速(HSI/HSE)频率选择”选项中输入该频率。
//<i>内部低速时钟LSI：由于内部32K晶振误差很大，使用这个时钟源会导致很多关于时序的操作失效。非常不推荐使用这个。
//<i>外部有源晶振：选择这个选项的话，需要在下面的“高速(HSI/HSE)频率选择”选项中把时钟频率设置成外部有源晶振的频率。
//<i>外部无源晶振：选择这个选项的话，需要在下面的“高速(HSI/HSE)频率选择”选项中把时钟频率设置成外部无源晶振的频率。
//<0=>内部高速时钟HSI(标准) <1=>内部高速时钟HSI(自定义) <2=>内部低速时钟LSI <3=>外部有源晶振 <4=>外部无源晶振 
#define SYS_CLOCK 0
//<o>高速(HSI/HSE)频率选择
//<i>定义单片机运行的时钟频率（单位Hz）。
//<i>当你在stcisp工具上输入了自定义频率或者使用了外部晶振的时候，需要在这里输入晶振频率。
/*<5529600L =>5.5296MHz <6000000L =>6.000MHz  <11059200L=>11.0592MHz <12000000L=>12.000MHz
<18432000L=>18.432MHz <20000000L=>20.000MHz <22118400L=>22.1184MHz <24000000L=>24.000MHz
<27000000L=>27.000MHz <30000000L=>30.000MHz <33000000L=>33.000MHz  <33177600L=>33.1776MHz
<35000000L=>35.000MHz*/
#define SYS_CLK_SET 25000000L
//<e>系统时钟输出
//<i>可以输出时钟频率用于驱动其他外设，或者用于检测内部的工作频率。
#define SYSCLK_OUT_EN 1
//<o.4..7>输出分频
//< 1=>SYSCLK/ 1  < 2=>SYSCLK/ 2 < 4=>SYSCLK/ 4 
//< 6=>SYSCLK/ 8  < 8=>SYSCLK/16 <10=>SYSCLK/32 
//<12=>SYSCLK/64  <14=>SYSCLK/128
//<o.3>输出引脚
//<0=>输出到P54 <1=>输出到P16
#define SYSCLK_OUT 0xE8
//</e>
//</h>



//<h>ECBM基础功能
//<q>自动下载功能
//<i>勾选此选项，就能使用自动下载功能。由于下载使用了串口1，所以得确保串口1呈使能状态并且输出引脚映射到P30和P31。
//<i>开启自动下载功能后，uart_int函数就会在system_init里被调用，不用再手动调用uart_int函数了。
#define AUTO_DOWNLOAD_EN  1
//<q>单片机设置检查
//<i>勾选此选项，会自动调用system_check函数，然后在电脑端的串口助手看到单片机的一些信息。
//<i>system_check函数会对晶振频率等信息进行检测，然后给出结果。如果有设置错误的，可根据提示修改。
#define CHECK_EN  0 
//<q>软调试功能
//<i>为了自动下载功能，一般都会打开串口1。平时使用串口1来调试皆可。
//<i>但是如果有特殊需求，比如没有硬件串口或者串口被占用的情况，可以使用该功能。
//<i>只需指定某个IO口，该IO口就会以9600的波特率发送调试信息。需要延时函数和GPIO库的支持。
#define SOFT_DEBUG 1
//</h>






//<h>深度优化
//<i>当你想在8K容量的小单片机或者更小的单片机里使用本库的时候，在这里把多余的函数优化掉。
//<q>error_printf
//<i>该函数主要是为了库函数的报错功能。
#define SYS_ERROR_EN 1
//<q>str系列
//<i>该系列函数主要是为了从字符串中获取有用的信息。某些库可能使用到，但是作为扩展功能，在实现最基本的库的时候可以优化掉。
#define SYS_STR_EN 1
//<q>crc16系列
//<i>该系列函数主要用于计算、生成、检测CRC16。会用在通信中的校验部分，如果不涉及到通信，可以优化掉。
//<i>算数因子是X16+X15+X2+1，不过程序来源于网上，所以它用的是倒序的A001。
#define SYS_CRC16_EN 0
//</h>
//<h>单片机外设库的选用
//<i>有些库会对别的库有依赖，请注意看说明部分。在勾选某库的时候连同依赖的库一起勾选。
//<q>POWER库
//<i>该库提供了关于STC8的电源、复位、看门狗相关操作函数。
#define ECBM_POWER_EN 0
//<q>GPIO库
//<i>该库提供了关于STC8的IO口相关操作函数。
#define ECBM_GPIO_EN 1
//<q>EEPROM库
//<i>该库提供了关于STC8使用内置FLASH模拟的EEPROM相关操作函数。
#define ECBM_EEPROM_EN 0
//<q>EXTI库
//<i>该库提供了关于STC8的外部中断相关操作函数。
#define ECBM_EXTI_EN 0
//<q>SOFT_IIC库
//<i>该库提供了关于STC8基于GPIO库的软件IIC相关操作函数。
#define ECBM_SOFT_IIC_EN 0
//<q>IIC库
//<i>该库提供了关于STC8的硬件IIC相关操作函数。
#define ECBM_IIC_EN 0
//<q>SOFT_SPI库
//<i>该库提供了关于STC8基于GPIO库的软件SPI相关操作函数。
#define ECBM_SOFT_SPI_EN 0
//<q>SPI库
//<i>该库提供了关于STC8的硬件SPI相关操作函数。
#define ECBM_SPI_EN 0
//<q>ADC库
//<i>该库提供了关于STC8的硬件ADC相关操作函数。
#define ECBM_ADC_EN 0
//<q>PWM库
//<i>该库提供了关于STC8的硬件PWM相关操作函数。
#define ECBM_PWM_EN 0
//<q>UART库
//<i>该库提供了关于STC8的硬件UART相关操作函数。
#define ECBM_UART_EN 1
//<q>CMP库
//<i>该库提供了关于STC8的硬件CMP相关操作函数。
#define ECBM_CMP_EN 1
//<q>TIMER库
//<i>该库提供了关于STC8的硬件TIMER相关操作函数。
#define ECBM_TIMER_EN 0

//<q>MDU16库
//<i>该库提供了关于STC8G的硬件乘除法相关操作函数。
#define ECBM_MDU16_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*------------------------------------头文件加载------------------------------------*/
#include "stc.h"        //单片机寄存器的头文件。
#include "intrins.h"    //单片机C语言使用汇编指令的头文件。
#include <STDARG.H>     //多参数函数支持的头文件。	
#include "stdio.h"      //sprintf相关函数支持的头文件。
/*----------------------------------变量类型重映射----------------------------------*/
#define __IO     volatile  //防止优化的声明，目的是让编译器每次使用的时候都得去内存拿值。
typedef unsigned char u8;  //无符号的 8位变量，在C51里就是无符号字符型变量。
typedef unsigned int  u16; //无符号的16位变量，在C51里就是无符号  整型变量。
typedef unsigned long u32; //无符号的32位变量，在C51里就是无符号长整型变量。
typedef   signed char s8;  //有符号的 8位变量，在C51里就是有符号字符型变量。
typedef   signed int  s16; //有符号的16位变量，在C51里就是有符号  整型变量。
typedef   signed long s32; //有符号的32位变量，在C51里就是有符号长整型变量。
/*--------------------------------------变量定义-----------------------------------*/
extern u32 xdata ecbm_sys_clk;
extern u16 xdata ecbm_delay_base;
/*------------------------------------芯片配置加载----------------------------------*/
/*#################################################################################*/
#if         ECBM_MCU_MAIN_RAM == 0 //STC8F2K
#  define   ECBM_MCU_NAME    "STC8F2K"
#  define   ECBM_MCU_XDATA   2048
#  define   ECBM_MCU_EEPROM  (65536-ECBM_MCU_ROM)
#  if       ECBM_ADC_EN
#    error  该型号可能没有ADC功能，请确认型号！
#  endif
/*#################################################################################*/
#elif       ECBM_MCU_MAIN_RAM == 1 //STC8A8K
#  define   ECBM_MCU_NAME    "STC8A8K"
#  define   ECBM_MCU_XDATA   8192
#  if       ECBM_MCU_ROM != 65024
#    define ECBM_MCU_EEPROM  (65536-ECBM_MCU_ROM)
#  else
#    define ECBM_MCU_EEPROM   ECBM_MCU_EEPROM_SIZE
#  endif
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#  define   ECBM_MCU_ADC     ECBM_MCU_ADC_BIT
/*#################################################################################*/
#elif       ECBM_MCU_MAIN_RAM == 2 //STC8G2K
#  define   ECBM_MCU_NAME    "STC8G2K"
#  define   ECBM_MCU_XDATA   2048
#  if       ECBM_MCU_ROM != 65024
#    define ECBM_MCU_EEPROM  (65536-ECBM_MCU_ROM)
#  else
#    define ECBM_MCU_EEPROM  ECBM_MCU_EEPROM_SIZE
#  endif
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#  if       ECBM_MCU_OTHER == 1
#    define ECBM_MCU_ADC	10
#endif
/*#################################################################################*/
#elif       ECBM_MCU_MAIN_RAM == 3 //STC8G1K
#  define   ECBM_MCU_NAME    "STC8G1K"
#  define   ECBM_MCU_XDATA   1024
#  if       ECBM_MCU_ROM != 65024
#    define ECBM_MCU_EEPROM  (65536-ECBM_MCU_ROM)
#  else
#    define ECBM_MCU_EEPROM  ECBM_MCU_EEPROM_SIZE
#  endif
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x54
#  define   A05 0x55
#  if       ECBM_MCU_OTHER == 2
#    define ECBM_MCU_ADC	10
#  endif
#endif
/*#################################################################################*/
/*------------------------------------通用配置设定----------------------------------*/
sbit    LED       =P5^5;     //通常ECBM的板子都会带一个LED，该LED采用低电平驱动。
#define LED_ON    LED=0;     //点亮LED。
#define LED_OFF   LED=1;     //关闭LED。
#define LED_BLINK LED=!LED;  //让LED闪烁。
/*------------------------------------常用功能设定----------------------------------*/
#define BL_RESET   do{_nop_();_nop_();IAP_CONTR=0x60;_nop_();_nop_();}while(0)//软重启单片机。
#define EA_ON      do{_nop_();EA=1;_nop_();}while(0)//打开总中断开关。
#define EA_OFF     do{_nop_();EA=0;_nop_();}while(0)//关闭总中断开关。
#define EX_SFR_ON  do{P_SW2|=0x80;}while(0)         //打开额外的寄存器地址。
#define EX_SFR_OFF do{P_SW2&=0x7f;}while(0)         //关闭额外的寄存器地址。

#define SYS_PD     do{_nop_();PCON|=0x02;_nop_();_nop_();}while(0) //进入掉电模式。
#define SYS_IDLE   do{_nop_();PCON|=0x01;_nop_();_nop_();}while(0) //进入空闲模式。

//以下几个参数，会一直在程序中生效，可以随时调用。但是需要在stcisp上勾选“在程序区的结束处添加重要测试参数”。
#define IRC24MHZ   (*((unsigned char code *)(ECBM_MCU_ROM-13)))//片内24M电路的设置值。
#define BGV        (*((unsigned int  code *)(ECBM_MCU_ROM-9))) //片内1.3V电压的实测值。
#define IRC32KHZ   (*((unsigned int  code *)(ECBM_MCU_ROM-11)))//片内32K电路的设置值。
#define MCUID        ((unsigned char code *)(ECBM_MCU_ROM-7))  //单片机的唯一ID码。
//以下几个参数，当idata用满的时候会有被覆盖的风险，建议保持idata区不要使用，多使用xdata区。
#define REG_HSI1  read_idata_u8 (0xFA)//片内24M电路的设置值。
#define REG_HSI   read_idata_u8 (0xFB)//片内24M电路的设置值。
#define REG_BGV   read_idata_u16(0xEF)//片内1.3V电压的实测值。
#define REG_LSI   read_idata_u16(0xF8)//片内32K电路的设置值。
#define REG_ID(x) read_idata_u8 (0xF1+x)//单片机的唯一ID码。

#define io2port(n) (n)>>4           //取引脚所在的P口，引脚格式需符合0xXX的格式。
#define io2pin(n)  0x01<<((n)&0x0f) //取引脚所在的PIN，引脚格式需符合0xXX的格式。
#define read_idata_u8(x)  (*((u8  volatile idata *)x))//从idata区读取一个u8 变量。
#define read_idata_u16(x) (*((u16 volatile idata *)x))//从idata区读取一个u16变量。
#define read_idata_u32(x) (*((u32 volatile idata *)x))//从idata区读取一个u32变量。
#define read_xdata_u8(x)  (*((u8  volatile xdata *)x))//从xdata区读取一个u8 变量。
#define read_xdata_u16(x) (*((u16 volatile xdata *)x))//从xdata区读取一个u16变量。
#define read_xdata_u32(x) (*((u32 volatile xdata *)x))//从xdata区读取一个u32变量。
#define read_idata_s8(x)  (*((s8  volatile idata *)x))//从idata区读取一个s8 变量。
#define read_idata_s16(x) (*((s16 volatile idata *)x))//从idata区读取一个s16变量。
#define read_idata_s32(x) (*((s32 volatile idata *)x))//从idata区读取一个s32变量。
#define read_xdata_s8(x)  (*((s8  volatile xdata *)x))//从xdata区读取一个s8 变量。
#define read_xdata_s16(x) (*((s16 volatile xdata *)x))//从xdata区读取一个s16变量。
#define read_xdata_s32(x) (*((s32 volatile xdata *)x))//从xdata区读取一个s32变量。
/*-----------------------------------库函数加载-----------------------------------*/
#include "power.h"
#include "gpio.h"
#include "eeprom.h"
#include "exti.h"
#include "soft_iic.h"
#include "iic.h"
#include "soft_spi.h"
#include "spi.h"
#include "adc.h"
#include "pwm.h"
#include "uart.h"
#include "cmp.h"
#include "timer.h"
#include "mdu16.h"
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：delay_ms
描  述：毫秒级延时函数
输  入：需要延时的毫秒数，可输入1~65535。
输  出：无
返回值：无
创建者：奈特
调用例程：delay_ms(500);//延时500毫秒
创建日期：2019-10-8
修改记录：
2020-06-02:修复了延时0ms变成延时65535ms的BUG。
-------------------------------------------------------*/
extern void delay_ms(u16 ms);
/*-------------------------------------------------------
函数名：delay_us
描  述：微秒级延时函数
输  入：需要延时的节拍数，不是微秒数。可以通过delay_set_us
        函数算出所需微秒对应的节拍数。
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
/***********************************串口调试模块***************/#if AUTO_DOWNLOAD_EN
extern u8 xdata old_char;  //保存上一次接收的数据
extern u8 xdata char_count;//相同数据计数
extern    bit   debug_busy;//发送忙标志位
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
-------------------------------------------------------*/
extern void system_uart_reset();
/*-------------------------------------------------------
函数名：debug
描  述：相当于应用于单片机的printf函数。由于内部只开了64字节缓存，
		所以建议在使用中，字符串不要超过64字节的长度。
输  入：多参数，和printf一样的用法。
输  出：无
返回值：无
创建者：奈特
调用例程：debug("i=%d\r\n",(u16)i);//将变量i的值发送到串口。
创建日期：2019-10-8
修改记录：
2019-12-28：修改成调用串口1的发送函数。
-------------------------------------------------------*/
extern void debug(const char * str,...);
/*-------------------------------------------------------
函数名：system_check
描  述：系统检测函数，会向串口发送单片机的一些基础信息。电脑收的到
		信息说明库函数运作正常。这个函数一般不常用。在图形界面中可
		以优化掉本函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：system_check();//发送单片机信息到串口。
创建日期：2019-10-8
修改记录：
2020-01-02：增加了检测的项目。
-------------------------------------------------------*/
extern void system_check();
/****************************************************************************/#endif
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
-------------------------------------------------------*/
extern void system_init(void);
/*-------------------------------------------------------
函数名：error_printf
描  述：错误信息打印函数，不依赖任何库函数和外设。会以每秒两次的频率发送出错信息。
		同时程序无法向下走，类似stm32的硬件错误中断。可以设置宏定义改变输出的IO。
		但是波特率固定为9600。
输  入：多参数，和printf一样的用法。
输  出：无
返回值：无
创建者：奈特
调用例程：
	...//其他无关的代码。
	case GPIO_P7:P7=dat;break;
	default:error_printf("gpio_write(<%d>,%d);不存在该P口\r\n",(u16)port,(u16)dat);break;
	...//其他无关的代码
创建日期：2019-10-8
修改记录：
-------------------------------------------------------*/
#define error_io P31//此处可以修改报错的IO口，修改为P31可通过串口输出。修改成LED可变成智能LED。
extern void error_printf(const char * str,...); 
/*---------------------------------其他非系统函数---------------------------------*/
/*-------------------------------------------------------
函数名：debug_soft
描  述：软件串口，可以用来调试(没有接收功能)，依赖延时库和GPIO库。适合没有硬件串口的单片机。
		波特率固定为9600。
输  入：io - 需要输出调试信息的IO口。
		其余参数和printf一样的用法。
输  出：无
返回值：无
创建者：奈特
调用例程：
	debug_soft(D31,"i=%d",i);//向P31口发送变量i的值。
创建日期：2019-10-8
修改记录：
-------------------------------------------------------*/
extern void debug_soft(u8 io,const char * str,...);
/********************************str系列函数************************/#if SYS_STR_EN
/*-------------------------------------------------------
函数名：str_find
描  述：字符串查找函数，用于查找一个字符串是否在另一个字符串内。
输  入：
		dest - 需要查找的目标字符串。
		key  - 需要查找的字符串特征。
输  出：无
返回值：字符串特征在目标字符串的位置，从0开始计算。如果是-1，说明目标字符串没有该特征。
创建者：奈特
调用例程：
	str_find("0123456789","4",i);//在"0123456789"中查找"4"所在的位置。
创建日期：2019-10-9
修改记录：
-------------------------------------------------------*/
extern u16 str_find(char * dest,char * key);
/*-------------------------------------------------------
函数名：str_read_pin
描  述：IO信息读取函数，用于读取字符串内目标位置的IO信息。
输  入：
		str - 存有IO信息的字符串。
		pos - IO信息的位置，通过这个来区分字符串内的多个IO信息。
输  出：无
返回值：在该位置的IO信息。
创建者：奈特
调用例程：
	str_read_pin("SCL=D13,SDA=D14",11);//读取从下标11开始的IO信息，即会返回0x14。
创建日期：2019-10-9
修改记录：
-------------------------------------------------------*/
extern u8 str_read_pin(char * str,u16 pos);
/*-------------------------------------------------------
函数名：str_read_u16
描  述：u16变量读取函数，用于读取字符串内目标位置的u16型数值。
输  入：
		str - 存有数值的字符串。
		pos - 数值的位置，通过这个来区分字符串内的多个数值。
输  出：无
返回值：在该位置的数值。U16类型，即0~65535。
创建者：奈特
调用例程：
	str_read_u16("SCL=D13,w=128",9);//读取从下标8开始的数值，即会返回128。
创建日期：2019-10-9
修改记录：
2020-02-17：增加了一个停止的条件，即遇到点号也要停止。
-------------------------------------------------------*/
extern u16 str_read_u16(char * str,u16 pos);
/*-------------------------------------------------------
函数名：str_push_len
描  述：字符串推出指令函数（带字符串长度参数版）。用于把指定缓存中的指定关键词推出该缓存。
		为了防止前后数据重组造成干扰（比如“LEDLED_ON_OFF”在推出“LED_ON”后，剩下的部分还能重组成“LED_OFF”），
		所以推出关键词之后，只会把关键词所在位置清零，不会连接首尾数据（即“LEDLED_ON_OFF”在推出“LED_ON”后剩下“LED      _OFF”）。
输  入：dest  -  目标字符串缓存。
		dlen  -  目标字符串缓存的长度。
		key   -  需要推出的关键词。
		klen  -  关键词的长度。
输  出：无
返回值：0 - 推出失败，可能是目标缓存内没有该关键词。
		1 - 推出成功。
创建者：奈特
调用例程：无
创建日期：2020-02-17
修改记录：
-------------------------------------------------------*/
extern u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen);
/**************************************************************************/#endif
/*程序区折叠专用******************CRC16模块***********************/#if SYS_CRC16_EN
/*-------------------------------------------------------
函数名：crc16
描  述：计算CRC16函数，采用的是MODBUS模式，即X16+X15+X2+1。
输  入：buf - 需要计算CRC16的缓存数组。
		len - 该数组的长度，CRC16会计算从0到len-1的元素的CRC16值。
输  出：无
返回值：该缓存数组计算出来的CRC16值。
创建者：来源于网上，由奈特整理
调用例程：无
创建日期：2020-02-17
修改记录：
-------------------------------------------------------*/
extern u16 crc16(u8 buf[],u16 len);
/*-------------------------------------------------------
函数名：crc16_insert_buf
描  述：插入CRC16函数。计算一个缓存的CRC16结果，然后插入到缓存的结尾处。
输  入：buf - 需要计算CRC16的缓存数组。
		len - 该数组的长度，CRC16会计算从0到len-2的元素的CRC16值，然后插入到len-2~len-1的位置。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-17
修改记录：
-------------------------------------------------------*/
extern void crc16_insert_buf(u8 buf[],u16 len);
/*-------------------------------------------------------
函数名：crc16_check_buf
描  述：检查CRC16函数。检查一个包含CRC16结果的缓存的CRC16结果是否正确。
		可以用来检测通信是否正确，推荐用crc16_insert_buf函数来生成目标格式缓存。
输  入：buf - 需要计算CRC16的缓存数组。
		len - 该数组的长度，CRC16会计算从0到len-2的元素的CRC16值，然后比较数组最后储存的CRC16值是否正确。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-02-17
修改记录：
-------------------------------------------------------*/
extern u8 crc16_check_buf(u8 buf[],u16 len);
/*程序区折叠专用************************************************************/#endif
#endif
