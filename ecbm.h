#ifndef _ECBM_H_
#define _ECBM_H_

/*---------头文件加载---------*/
#include "stc.h"
#include "intrins.h"
#include <STDARG.H>
/*---------头文件加载---------*/

/*---------变量类型重映射---------*/
#define __IO          volatile
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned long u32;
typedef   signed char s8;
typedef   signed int  s16;
typedef   signed long s32;
/*---------变量类型重映射---------*/

/*请在STC-ISP工具中勾选“在程序区的结束处添加重要测试参数”！ */

//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>ECBM默认设置与基础功能加载
//<o>主控芯片的选择
//<i>列表提供的芯片类型都是测试通过能使用的。当然目前只能基于STC8系列。
//<0=>STC8F2K16S2 <1=>STC8F2K32S2 <2=>STC8F1K08 <3=>STC8A8K64S4A12
#define ECBM_MCU 3
//<o>IRC频率选择
//<i>定义单片机运行的时钟频率。设置成和STC-ISP工具上的一样的频率即可。
//<i>由于30MHz以上的速度不是每一个型号都能达到，故只提供到30MHz。可以在文本区手动修改该值（单位Hz）
//<5529600=>5.5296MHz <6000000=>6.000MHz <11059200=>11.0592MHz <12000000=>12.000MHz
//<18432000=>18.432MHz <20000000=>20.000MHz <22118400=>22.1184MHz <24000000=>24.000MHz
//<27000000=>27.000MHz <30000000=>30.000MHz <33000000=>33.000MHz <33177600=>33.1776MHz
//<35000000=>35.000MHz
#define SYS_CLK 27000000
//<e>串口1基本功能和自动下载功能
//<i>勾选此选项，就能使用自动下载功能。同时包含了串口1相关函数，可直接使用串口1进行调试。
//<i>开启此功能，会占用串口1和定时器1的资源。编写代码时请注意！
#define SUART_EN  1
//<o>波特率选择
//<i>定义串口1的波特率
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART_BAUDRATE 115200 //默认的波特率，当然也是可以改的。
//<q>单片机信息输出
//<i>勾选此选项，可调用system_check函数，然后在电脑端的串口助手看到单片机的一些信息。
//<i>这些信息有部分来自STC-ISP，所以请在STC-ISP工具中勾选“在程序区的结束处添加重要测试参数”！
#define CHECK_EN  0 
//</e>
//<q>延时函数
//<i>勾选此选项，可使用基于空指令（nop）和for循环的延时函数。
//<i>目前的精度已经能适应大部分应用。若有更高精度要求，可去掉勾选然后自己用定时器实现延时函数。
#define DELAY_EN  1
//</h>
//<h>单片机外设库的选用
//<i>有些库会对别的库有依赖，请注意看说明部分。在勾选某库的时候连同依赖的库一起勾选。
//<q>GPIO库
//<i>该库提供了关于STC8的IO口相关操作函数。
#define ECBM_GPIO_EN 1
//<q>EXIT库
//<i>该库提供了关于STC8的外部中断相关操作函数和外部中断的函数。
//<i>该库依赖GPIO库。
#define ECBM_EXIT_EN 0
//<q>ADC库
//<i>该库提供了关于STC8的模数转换器操作相关函数。
#define ECBM_ADC_EN 1
//<q>TIMER库
//<i>该库提供了关于STC8的定时器操作相关函数。
#define ECBM_TIMER_EN 0
//<q>EEPROM库
//<i>该库提供了关于STC8内置EEPROM（实质为Flash）的操作相关函数。
#define ECBM_EEPROM_EN 0
//<q>IIC库
//<i>该库提供了关于STC8内置IIC的操作相关函数。
//<i>该库依赖GPIO库。
#define ECBM_IIC_EN 1
//<q>软件IIC库
//<i>该库提供了关于STC8用IO模拟IIC主机的操作相关函数。
//<i>该库依赖GPIO库。
#define ECBM_SOFT_IIC_EN 1
//<q>CMP库
//<i>该库提供了关于STC8内置比较器的操作相关函数。
#define ECBM_CMP_EN 0
//</h>
//<h>系统设置
//<e>看门狗
//<i>该选项只是让编译器编译看门狗的代码，并不会打开看门狗（为了防止看门狗打开得太早，初始化外设时不能喂狗导致单片机一直重启）。
//<i>开启看门狗使用wd_start();
#define ECBM_WDOG_EN 0
//<q.3>IDLE模式时继续计数？
//<i>在IDLE模式下，如果继续计数的话，单片机会因为没有喂狗而重启。
//<o.0..2>看门狗定时器分频系数
//<i>看门狗溢出时间=（12*32768*分频系数）/SYSclk。
//<i>在溢出之前调用wdt_feed();喂狗函数就行。
//<0=>2 <1=>4 <2=>8 <3=>16 <4=>32 <5=>64 <6=>128 <7=>256  
#define WDT_MODE 0x07
//</e>

//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------


/*----------芯片配置加载--------*/
#if   ECBM_MCU == 0
#include "mcu/stc8f2k16s2.h"
#elif ECBM_MCU == 1
#include "mcu/stc8f2k32s2.h"
#elif ECBM_MCU == 2
#include "mcu/stc8f1k08.h"
#elif ECBM_MCU == 3
#include "mcu/stc8a8k64s4a12.h"
#endif
//引脚定义
sbit    LED=P5^5;
//宏定义
#define MCU_RESET     IAP_CONTR=0x60
#define EA_ON         _nop_();EA=1;_nop_()
#define EA_OFF        _nop_();EA=0;_nop_()
#define EX_SFR_ON     P_SW2|=0x80
#define EX_SFR_OFF    P_SW2&=0x7f
#define LED_ON        LED=0
#define LED_OFF       LED=1
#define IRC24         (*((unsigned char code *)(FLASH_SIZE-13)))
#define BGV           (*((unsigned int  code *)(FLASH_SIZE-9)))
#define IRC32         (*((unsigned int  code *)(FLASH_SIZE-11)))
unsigned char * MCUID=(   unsigned char code *)(FLASH_SIZE-7);



//变量定义
__IO u32 xdata sys_clock=SYS_CLK;

//函数定义
#if SUART_EN
void uart_init(unsigned long btl){
	u16 rel;
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	rel=(u16)(65535-(sys_clock/btl/4));
	TL1 =(u8)(rel);		    //设定定时初值
	TH1 =(u8)(rel>>8);		//设定定时初值
	ET1 = 0;			//禁止定时器1中断
	TR1 = 1;			//启动定时器1
	ES=1;
}
u8 xdata oldchar,charcount=0;
void system_uart_reset(){
	if(SBUF!=oldchar){			//判断重复字符
		oldchar=SBUF;			//更新oldchar
		charcount=0;			//计数器清零
	}else{
		charcount++;			//重复计数器+1
	}
	if(charcount==222)			//接收到222个重复数据时
		MCU_RESET;				//重启
}
bit busy=0;
void uart_sendchar(u8 ch){
	while (busy);
	busy = 1;
    SBUF = ch;
}
void uart_sendstring(u8 * str){
	while (*str){                  //检测字符串结束标志
		uart_sendchar(*str++);         //发送当前字符
	}
}
void uart_sendenter(){
	uart_sendstring("\r\n");
}
#include "stdio.h"
void uart_printf(const char * str,...){
	char xdata buf[64];
	va_list vp;
    va_start(vp, str);
    vsprintf(buf,str,vp);
    va_end(vp);
	uart_sendstring(buf);
}
/*----------------------------
UART 中断服务程序
-----------------------------*/

void Uart() interrupt 4 using 1
{
    if (RI)
    {
       RI = 0;                //清除RI位
			 system_uart_reset();
    }
    if (TI)
    {
        TI = 0;                 //清除TI位
		busy=0;
    }
}
#if CHECK_EN
void system_check(){
	u8 i;
	uart_printf("|------------------|\r\n");
	uart_printf("|MCU:%s   |\r\n",MCU_NAME);
	uart_printf("|ID :");
	for(i=0;i<7;i++){
		uart_printf("%X",(u16)MCUID[i]);
	}
	uart_printf(" |\r\n");
	uart_printf("|------------------|\r\n");
	uart_printf("|DATA  :  128 Byte |\r\n");
	uart_printf("|IDATA :  128 Byte |\r\n");
	uart_printf("|XDATA :%5u Byte |\r\n",(u16)XDATA_SIZE);
	uart_printf("|FLASH :%5u Byte |\r\n",(u16)FLASH_SIZE);
	uart_printf("|EEPROM:%5u Byte |\r\n",(u16)EEPROM_SIZE);
	uart_printf("|------------------|\r\n");
	uart_printf("|IRC:%6.3f MHz    |\r\n",sys_clock/1000000.0f);
	uart_printf("|BGV:%4dmV        |\r\n",(u16)BGV);
	uart_printf("|------------------|\r\n");
}
#endif
#endif
#if DELAY_EN
#include "HAL_LIB/us_code.h"
void delay_ms(u16 ms){
	u16 i,j;
	j=sys_clock/10000;//根据时钟调整延时的时间。9925
	do{
		i=j;
		while(--i);
	}while(--ms);
}

u16  delay_set_us(u16 us){//公式计算所花的时间太长，拆分成两个函数。先用这个函数推算出延时的数值，再用下面的函数调用。
	return (u16)((float)sys_clock/10000000.0f*us);
}
void delay_us(u16 us){
	u16 i;
	i = us;
	while (i--);
}
#endif
#if ECBM_WDOG_EN
void wdt_start(){
	WDT_CONTR=WDT_MODE|0x20;
}
void wdt_feed(){
	WDT_CONTR|=0x10;
}
#endif
void system_init(void){
	EX_SFR_ON;
	#if SUART_EN
	uart_init(UART_BAUDRATE);
	#endif
	EA_ON;
}
#if ECBM_GPIO_EN
#include "HAL_LIB/gpio.h"
#endif
#if ECBM_EXIT_EN
#include "HAL_LIB/exit.h"
#endif
#if ECBM_EEPROM_EN
#include "HAL_LIB/eeprom.h"
#endif
#if ECBM_CMP_EN
#include "HAL_LIB/cmp.h"
#endif
#if ECBM_TIMER_EN
#include "HAL_LIB/timer.h"
#endif
#if ECBM_IIC_EN
#include "HAL_LIB/iic.h"
#endif
#if ECBM_SOFT_IIC_EN
#include "HAL_LIB/soft_iic.h"
#endif
#if ECBM_ADC_EN
#include "HAL_LIB/adc.h"
#endif

#endif

