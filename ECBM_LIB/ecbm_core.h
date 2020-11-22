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
#define ECBM_FVN 3
//Release Version Number 发布版本号
//当发生关键库文件增减时，该版本号加一。
#define ECBM_RVN 0
//BUG Version Number 发布版本号
//每次发布到网上时，若只是修改BUG，该版本号加一。
#define ECBM_BVN 0
//<o>STC8系列型号选择
//<i>列表提供的芯片类型都是在数据手册中出现的，仅根据理论进行设置，若有兼容性问题请入群告知我。
//<i>ROM容量留空，在下一个选项中选择。
//<0x110301=>STC8F1Kxx_8PIN 
//<0x110302=>STC8F1KxxS2_16PIN_20PIN 
//<0x120502=>STC8F2KxxS2_ALL 
//<0x120504=>STC8F2KxxS4_ALL 
//<0x2405C2=>STC8A4KxxS2A12_ALL 
//<0x2805C4=>STC8A8KxxS4A12_ALL 
//<0x3103A2=>STC8G1Kxx_16PIN_20PIN 
//<0x310201=>STC8G1Kxx_8PIN 
//<0x3102A1=>STC8G1KxxA_8PIN 
//<0x3103A1=>STC8G1KxxT_20PIN 
//<0x3205A2=>STC8G2KxxS2_ALL 
//<0x3205A4=>STC8G2KxxS4_ALL 
//<0x4103A2=>STC8H1Kxx_20PIN 
//<0x4105A2=>STC8H1Kxx_32PIN  
//<0x4205C4=>STC8H2KxxT_48PIN 
//<0x4305C2=>STC8H3KxxS2_48PIN  
//<0x4305C4=>STC8H3KxxS4_48PIN  
//<0x4805C4=>STC8H8KxxU_48PIN_64PIN 
#define ECBM_MCU 3278244
//<o>ROM选择
//<i>选择单片机的flash容量大小，主要影响唯一ID的读取。
//<8=>08 <12=>12 <16=>16 <17=>17 <28=>28 
//<32=>32 <60=>60 <64=>64
#define ECBM_MCU_ROM_SIZE 64
//<h>单片机系统设置
//<i>该框内的选项有互斥的选项，请仔细阅读了解了结果再选择。
//<o>单片机系统时钟设置
//<i>该选项可以选择单片机时钟来源。后期也可以用函数修改时钟来源。
//<i>内部高速时钟HSI(标准)：选择这个选项的话，ecbm库会自动获取STCISP工具的设置的标准频率。（标准频率是指11.0592M、12M、24M这种）
//<i>内部高速时钟HSI(自定义)：自定义频率是指6.666M、22.33M这种自己输入的频率。需要在下面的“高速(HSI/HSE)频率选择”选项中输入该频率。
//<i>内部低速时钟LSI：由于内部32K晶振误差很大，使用这个时钟源会导致很多关于时序的操作失效。非常不推荐使用这个。
//<i>外部有源晶振：选择这个选项的话，需要在下面的“高速(HSI/HSE)频率选择”选项中把时钟频率设置成外部有源晶振的频率。
//<i>外部无源晶振：选择这个选项的话，需要在下面的“高速(HSI/HSE)频率选择”选项中把时钟频率设置成外部无源晶振的频率。
//<0=>内部高速时钟HSI(标准) <1=>内部高速时钟HSI(自定义) <2=>内部低速时钟LSI <3=>外部低速晶振 <4=>外部高速有源晶振 <5=>外部高速无源晶振 
#define ECBM_SYSCLK_TYPE 0
//<o>高速(HSI/HSE)频率选择
//<i>定义单片机运行的时钟频率（单位Hz）。
//<i>当你在stcisp工具上输入了自定义频率或者使用了外部晶振的时候，需要在这里输入晶振频率。
#define ECBM_SYSCLK_SETTING 16000000L
//<e>系统时钟输出
//<i>可以输出时钟频率用于驱动其他外设，或者用于检测内部的工作频率。
#define ECBM_SYSCLK_OUT_EN 0
//<o>输出引脚
//<0=>输出到P54 <1=>输出到P16
#define	ECBM_SYSLCK_OUT_PIN 1
//<o.4..7>STC8F和STC8A设置输出分频
//<i>根据上面的型号选择，两个设置分频的选项只会生效一个。
//< 1=>SYSCLK/ 1  < 2=>SYSCLK/ 2 < 4=>SYSCLK/ 4 
//< 6=>SYSCLK/ 8  < 8=>SYSCLK/16 <10=>SYSCLK/32 
//<12=>SYSCLK/64  <14=>SYSCLK/128
#define ECBM_SYSCLK_OUT_SETTING_FA 0x18
//<o>STC8G和STC8H设置输出分频
//<1-127>
//<i>根据上面的型号选择，两个设置分频的选项只会生效一个。
//<i>填多少就是分频多少，比如填6，就是SYSCLK/6。
#define ECBM_SYSCLK_OUT_SETTING_GH 1
//</e>
//</h>
//<h>ECBM基础功能
//<q>自动下载功能
//<i>勾选此选项，就能使用自动下载功能。由于下载使用了串口1，所以得确保串口1呈使能状态并且输出引脚映射到P30和P31。
//<i>开启自动下载功能后，uart_int函数就会在system_init里被调用，不用再手动调用uart_int函数了。
#define ECBM_AUTO_DOWNLOAD_EN  1
//<q>单片机设置检查
//<i>勾选此选项，会自动调用system_check函数，然后在电脑端的串口助手看到单片机的一些信息。
//<i>system_check函数会对晶振频率等信息进行检测，然后给出结果。如果有设置错误的，可根据提示修改。
#define ECBM_MCU_CHECK_EN  0 
//<q>软调试功能
//<i>为了自动下载功能，一般都会打开串口1。平时使用串口1来调试皆可。
//<i>但是如果有特殊需求，比如没有硬件串口或者串口被占用的情况，可以使用该功能。
//<i>只需指定某个IO口，该IO口就会以9600的波特率发送调试信息。需要延时函数和GPIO库的支持。
#define ECBM_SOFT_DEBUG_EN 0
//</h>
//<h>深度优化
//<i>当你想在8K容量的小单片机或者更小的单片机里使用本库的时候，在这里把多余的函数优化掉。
//<q>error_printf
//<i>该函数主要是为了库函数的报错功能。
#define ECBM_ERROR_PRINTF_EN 1
//<q>str系列
//<i>该系列函数主要是为了从字符串中获取有用的信息。某些库可能使用到，但是作为扩展功能，在实现最基本的库的时候可以优化掉。
#define ECBM_STRING_EN 1
//<q>crc16系列
//<i>该系列函数主要用于计算、生成、检测CRC16。会用在通信中的校验部分，如果不涉及到通信，可以优化掉。
//<i>算数因子是X16+X15+X2+1，不过程序来源于网上，所以它用的是倒序的A001。
#define ECBM_CRC16_EN 0
//</h>
//<h>单片机外设库的选用
//<i>有些库会对别的库有依赖，请注意看说明部分。在勾选某库的时候连同依赖的库一起勾选。
//<q>POWER库
//<i>该库提供了关于STC8的电源、复位、看门狗相关操作函数。
#define ECBM_POWER_LIB_EN 0
//<q>UART库
//<i>该库提供了关于STC8的硬件UART相关操作函数。
#define ECBM_UART_LIB_EN 1
//<q>EXTI库
//<i>该库提供了关于STC8的外部中断相关操作函数。
#define ECBM_EXTI_LIB_EN 0
//<q>TIMER库
//<i>该库提供了关于STC8的硬件TIMER相关操作函数。
#define ECBM_TIMER_LIB_EN 0
//<q>EEPROM库
//<i>该库提供了关于STC8使用内置FLASH模拟的EEPROM相关操作函数。
#define ECBM_EEPROM_LIB_EN 0
//<q>SPI库
//<i>该库提供了关于STC8的硬件SPI相关操作函数。
#define ECBM_SPI_LIB_EN 0
//<q>SOFT_SPI库
//<i>该库提供了关于STC8基于GPIO库的软件SPI相关操作函数。
#define ECBM_SOFTSPI_LIB_EN 0
//<q>IIC库
//<i>该库提供了关于STC8的硬件IIC相关操作函数。
#define ECBM_IIC_LIB_EN 0
//<q>SOFT_IIC库
//<i>该库提供了关于STC8基于GPIO库的软件IIC相关操作函数。
#define ECBM_SOFTIIC_LIB_EN 0
//<q>ADC库
//<i>该库提供了关于STC8的硬件ADC相关操作函数。
#define ECBM_ADC_LIB_EN 0
//<q>CMP库
//<i>该库提供了关于STC8的硬件CMP相关操作函数。
#define ECBM_CMP_LIB_EN 0
//<q>MDU16库
//<i>该库提供了关于STC8G的硬件乘除法相关操作函数。
#define ECBM_MDU16_LIB_EN 0
//<q>IT库
//<i>该库提供了关于STC8的中断优先级相关操作函数。
#define ECBM_IT_LIB_EN 0
//<q>PCA库
//<i>该库提供了关于STC8A的硬件PCA相关操作函数。
#define ECBM_PCA_LIB_EN 0
//<q>PWM库
//<i>该库提供了关于STC8的硬件PWM相关操作函数。
#define ECBM_PWM_LIB_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*------------------------------------头文件加载------------------------------------*/
#include "ecbm.h"        //单片机寄存器的头文件。
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
/*####################################芯片名字解析##################################*/
#if			(ECBM_MCU&0xF00000)==0x100000
#	define	ECBM_MCU_NAME	"STC8F"
#elif		(ECBM_MCU&0xF00000)==0x200000
#	define	ECBM_MCU_NAME	"STC8A"
#elif		(ECBM_MCU&0xF00000)==0x300000
#	define	ECBM_MCU_NAME	"STC8G"
#elif		(ECBM_MCU&0xF00000)==0x400000
#	define	ECBM_MCU_NAME	"STC8H"
#endif
/*##################################特殊参数地址解析################################*/
#if		(ECBM_MCU==0x110301)||(ECBM_MCU==0x110302)//STC8F1Kxx_8PIN//STC8F1KxxS2_16PIN_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz的IRC参数。
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz的IRC参数。
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz的IRC参数。
#	endif
#elif	(ECBM_MCU==0x120502)||(ECBM_MCU==0x120504)||(ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)//STC8F2KxxS2_ALL//STC8F2KxxS4_ALL//STC8A4KxxS2A12_ALL//STC8A8KxxS4A12_ALL    
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz的IRC参数。
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz的IRC参数。
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz的IRC参数。
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz的IRC参数。
#	endif
#elif	(ECBM_MCU==0x3103A2)||(ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)||(ECBM_MCU==0x3103A1)//STC8G1Kxx_16PIN_20PIN//STC8G1Kxx_8PIN//STC8G1KxxA_8PIN//STC8G1KxxT_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40M频段的VRTRIM参数。
#	endif
#elif	(ECBM_MCU==0x3205A2)||(ECBM_MCU==0x3205A4)//STC8G2KxxS2_ALL//STC8G2KxxS4_ALL 
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40M频段的VRTRIM参数。
#	endif
#elif	(ECBM_MCU==0x4103A2)||(ECBM_MCU==0x4105A2)//STC8H1Kxx_20PIN//STC8H1Kxx_32PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==28
#		define	MCUID			(  (unsigned char code *)(0x6FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x6FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x6FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x6FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x6FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x6FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x6FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x6FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x6FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x6FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x6FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x6FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x6FE9)))	//40M频段的VRTRIM参数。
#	endif
#elif	(ECBM_MCU==0x4205C4)||(ECBM_MCU==0x4305C2)||(ECBM_MCU==0x4305C4)//STC8H2KxxT_48PIN//STC8H3KxxS2_48PIN//STC8H3KxxS4_48PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz的IRC参数。
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz的IRC参数。
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24M频段的VRTRIM参数。
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40M频段的VRTRIM参数。
#	endif
#elif	ECBM_MCU == 0x4805C4//STC8H8KxxU_48PIN_64PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF2)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF1)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FF0)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEF)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FEE)))	//36.864MHz的IRC参数。
#		define	IRC40MHZ		(*((unsigned char code *)(0x7FED)))	//40MHz的IRC参数。
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0x7FEC)))	//44.2368MHz的IRC参数。
#		define	IRC48MHZ		(*((unsigned char code *)(0x7FEB)))	//48MHz的IRC参数。
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24M频段的VRTRIM参数。
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF2)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF1)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFF0)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEF)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFEE)))	//36.864MHz的IRC参数。
#		define	IRC40MHZ		(*((unsigned char code *)(0xEFED)))	//40MHz的IRC参数。
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xEFEC)))	//44.2368MHz的IRC参数。
#		define	IRC48MHZ		(*((unsigned char code *)(0xEFEB)))	//48MHz的IRC参数。
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24M频段的VRTRIM参数。
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40M频段的VRTRIM参数。
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//单片机的唯一ID码。
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//片内间隙电压的实测值。
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K掉电唤醒定时器频率。
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz的IRC参数。
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz的IRC参数。
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF2)))	//27MHz的IRC参数。
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF1)))	//30MHz的IRC参数。
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDF0)))	//33.1776MHz的IRC参数。
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEF)))	//35MHz的IRC参数。
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDEE)))	//36.864MHz的IRC参数。
#		define	IRC40MHZ		(*((unsigned char code *)(0xFDED)))	//40MHz的IRC参数。
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xFDEC)))	//44.2368MHz的IRC参数。
#		define	IRC48MHZ		(*((unsigned char code *)(0xFDEB)))	//48MHz的IRC参数。
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24M频段的VRTRIM参数。
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40M频段的VRTRIM参数。
#	endif
#endif
/*------------------------------------通用配置设定----------------------------------*/
sbit    LED       =P5^5;     //通常ECBM的板子都会带一个LED，该LED采用低电平驱动。
#define LED_ON    LED=0;     //点亮LED。
#define LED_OFF   LED=1;     //关闭LED。
#define LED_BLINK LED=!LED;  //让LED闪烁。
/*------------------------------------常用功能设定----------------------------------*/
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
#include "it.h"
#include "pca.h"
//#include "pwm.h"
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
/***********************************串口调试模块***************/#if ECBM_AUTO_DOWNLOAD_EN
extern u8 xdata old_char;  //保存上一次接收的数据
extern u8 xdata char_count;//相同数据计数
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
2020-10-09：移出自动下载使能的控制。
-------------------------------------------------------*/
extern void debug(const char * str,...);
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
/********************************str系列函数************************/#if ECBM_STRING_EN
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
/*程序区折叠专用******************CRC16模块***********************/#if ECBM_CRC16_EN
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
