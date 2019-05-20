#ifndef _ECBM_H_
#define _ECBM_H_

/*---------ͷ�ļ�����---------*/
#include "stc.h"
#include "intrins.h"
#include <STDARG.H>
/*---------ͷ�ļ�����---------*/

/*---------����������ӳ��---------*/
#define __IO          volatile
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned long u32;
typedef   signed char s8;
typedef   signed int  s16;
typedef   signed long s32;
/*---------����������ӳ��---------*/

/*����STC-ISP�����й�ѡ���ڳ������Ľ����������Ҫ���Բ������� */

//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>ECBMĬ��������������ܼ���
//<o>����оƬ��ѡ��
//<i>�б��ṩ��оƬ���Ͷ��ǲ���ͨ����ʹ�õġ���ȻĿǰֻ�ܻ���STC8ϵ�С�
//<0=>STC8F2K16S2 <1=>STC8F2K32S2 <2=>STC8F1K08 <3=>STC8A8K64S4A12
#define ECBM_MCU 3
//<o>IRCƵ��ѡ��
//<i>���嵥Ƭ�����е�ʱ��Ƶ�ʡ����óɺ�STC-ISP�����ϵ�һ����Ƶ�ʼ��ɡ�
//<i>����30MHz���ϵ��ٶȲ���ÿһ���ͺŶ��ܴﵽ����ֻ�ṩ��30MHz���������ı����ֶ��޸ĸ�ֵ����λHz��
//<5529600=>5.5296MHz <6000000=>6.000MHz <11059200=>11.0592MHz <12000000=>12.000MHz
//<18432000=>18.432MHz <20000000=>20.000MHz <22118400=>22.1184MHz <24000000=>24.000MHz
//<27000000=>27.000MHz <30000000=>30.000MHz <33000000=>33.000MHz <33177600=>33.1776MHz
//<35000000=>35.000MHz
#define SYS_CLK 27000000
//<e>����1�������ܺ��Զ����ع���
//<i>��ѡ��ѡ�����ʹ���Զ����ع��ܡ�ͬʱ�����˴���1��غ�������ֱ��ʹ�ô���1���е��ԡ�
//<i>�����˹��ܣ���ռ�ô���1�Ͷ�ʱ��1����Դ����д����ʱ��ע�⣡
#define SUART_EN  1
//<o>������ѡ��
//<i>���崮��1�Ĳ�����
//<600=>600 <1200=>1200 <2400=>2400 <4800=>4800 <9600=>9600 <14400=>14400 
//<19200=>19200 <28800=>28800 <38400=>38400 <57600=>57600 <115200=>115200
//<230400=>230400 <460800=>460800
#define UART_BAUDRATE 115200 //Ĭ�ϵĲ����ʣ���ȻҲ�ǿ��Ըĵġ�
//<q>��Ƭ����Ϣ���
//<i>��ѡ��ѡ��ɵ���system_check������Ȼ���ڵ��Զ˵Ĵ������ֿ�����Ƭ����һЩ��Ϣ��
//<i>��Щ��Ϣ�в�������STC-ISP����������STC-ISP�����й�ѡ���ڳ������Ľ����������Ҫ���Բ�������
#define CHECK_EN  0 
//</e>
//<q>��ʱ����
//<i>��ѡ��ѡ���ʹ�û��ڿ�ָ�nop����forѭ������ʱ������
//<i>Ŀǰ�ľ����Ѿ�����Ӧ�󲿷�Ӧ�á����и��߾���Ҫ�󣬿�ȥ����ѡȻ���Լ��ö�ʱ��ʵ����ʱ������
#define DELAY_EN  1
//</h>
//<h>��Ƭ��������ѡ��
//<i>��Щ���Ա�Ŀ�����������ע�⿴˵�����֡��ڹ�ѡĳ���ʱ����ͬ�����Ŀ�һ��ѡ��
//<q>GPIO��
//<i>�ÿ��ṩ�˹���STC8��IO����ز���������
#define ECBM_GPIO_EN 1
//<q>EXIT��
//<i>�ÿ��ṩ�˹���STC8���ⲿ�ж���ز����������ⲿ�жϵĺ�����
//<i>�ÿ�����GPIO�⡣
#define ECBM_EXIT_EN 0
//<q>ADC��
//<i>�ÿ��ṩ�˹���STC8��ģ��ת����������غ�����
#define ECBM_ADC_EN 1
//<q>TIMER��
//<i>�ÿ��ṩ�˹���STC8�Ķ�ʱ��������غ�����
#define ECBM_TIMER_EN 0
//<q>EEPROM��
//<i>�ÿ��ṩ�˹���STC8����EEPROM��ʵ��ΪFlash���Ĳ�����غ�����
#define ECBM_EEPROM_EN 0
//<q>IIC��
//<i>�ÿ��ṩ�˹���STC8����IIC�Ĳ�����غ�����
//<i>�ÿ�����GPIO�⡣
#define ECBM_IIC_EN 1
//<q>���IIC��
//<i>�ÿ��ṩ�˹���STC8��IOģ��IIC�����Ĳ�����غ�����
//<i>�ÿ�����GPIO�⡣
#define ECBM_SOFT_IIC_EN 1
//<q>CMP��
//<i>�ÿ��ṩ�˹���STC8���ñȽ����Ĳ�����غ�����
#define ECBM_CMP_EN 0
//</h>
//<h>ϵͳ����
//<e>���Ź�
//<i>��ѡ��ֻ���ñ��������뿴�Ź��Ĵ��룬������򿪿��Ź���Ϊ�˷�ֹ���Ź��򿪵�̫�磬��ʼ������ʱ����ι�����µ�Ƭ��һֱ��������
//<i>�������Ź�ʹ��wd_start();
#define ECBM_WDOG_EN 0
//<q.3>IDLEģʽʱ����������
//<i>��IDLEģʽ�£�������������Ļ�����Ƭ������Ϊû��ι����������
//<o.0..2>���Ź���ʱ����Ƶϵ��
//<i>���Ź����ʱ��=��12*32768*��Ƶϵ����/SYSclk��
//<i>�����֮ǰ����wdt_feed();ι���������С�
//<0=>2 <1=>4 <2=>8 <3=>16 <4=>32 <5=>64 <6=>128 <7=>256  
#define WDT_MODE 0x07
//</e>

//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------


/*----------оƬ���ü���--------*/
#if   ECBM_MCU == 0
#include "mcu/stc8f2k16s2.h"
#elif ECBM_MCU == 1
#include "mcu/stc8f2k32s2.h"
#elif ECBM_MCU == 2
#include "mcu/stc8f1k08.h"
#elif ECBM_MCU == 3
#include "mcu/stc8a8k64s4a12.h"
#endif
//���Ŷ���
sbit    LED=P5^5;
//�궨��
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



//��������
__IO u32 xdata sys_clock=SYS_CLK;

//��������
#if SUART_EN
void uart_init(unsigned long btl){
	u16 rel;
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	rel=(u16)(65535-(sys_clock/btl/4));
	TL1 =(u8)(rel);		    //�趨��ʱ��ֵ
	TH1 =(u8)(rel>>8);		//�趨��ʱ��ֵ
	ET1 = 0;			//��ֹ��ʱ��1�ж�
	TR1 = 1;			//������ʱ��1
	ES=1;
}
u8 xdata oldchar,charcount=0;
void system_uart_reset(){
	if(SBUF!=oldchar){			//�ж��ظ��ַ�
		oldchar=SBUF;			//����oldchar
		charcount=0;			//����������
	}else{
		charcount++;			//�ظ�������+1
	}
	if(charcount==222)			//���յ�222���ظ�����ʱ
		MCU_RESET;				//����
}
bit busy=0;
void uart_sendchar(u8 ch){
	while (busy);
	busy = 1;
    SBUF = ch;
}
void uart_sendstring(u8 * str){
	while (*str){                  //����ַ���������־
		uart_sendchar(*str++);         //���͵�ǰ�ַ�
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
UART �жϷ������
-----------------------------*/

void Uart() interrupt 4 using 1
{
    if (RI)
    {
       RI = 0;                //���RIλ
			 system_uart_reset();
    }
    if (TI)
    {
        TI = 0;                 //���TIλ
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
	j=sys_clock/10000;//����ʱ�ӵ�����ʱ��ʱ�䡣9925
	do{
		i=j;
		while(--i);
	}while(--ms);
}

u16  delay_set_us(u16 us){//��ʽ����������ʱ��̫������ֳ�����������������������������ʱ����ֵ����������ĺ������á�
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

