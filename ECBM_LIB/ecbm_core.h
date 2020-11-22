#ifndef _ECBM_CORE_H_
#define _ECBM_CORE_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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

����˵����
	���������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ�������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽����
                             **************************
                             * ��ϵ��ʽ����Ⱥ778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//Frame Version Number ��ܰ汾��
#define ECBM_FVN 3
//Release Version Number �����汾��
//�������ؼ����ļ�����ʱ���ð汾�ż�һ��
#define ECBM_RVN 0
//BUG Version Number �����汾��
//ÿ�η���������ʱ����ֻ���޸�BUG���ð汾�ż�һ��
#define ECBM_BVN 0
//<o>STC8ϵ���ͺ�ѡ��
//<i>�б��ṩ��оƬ���Ͷ����������ֲ��г��ֵģ����������۽������ã����м�������������Ⱥ��֪�ҡ�
//<i>ROM�������գ�����һ��ѡ����ѡ��
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
//<o>ROMѡ��
//<i>ѡ��Ƭ����flash������С����ҪӰ��ΨһID�Ķ�ȡ��
//<8=>08 <12=>12 <16=>16 <17=>17 <28=>28 
//<32=>32 <60=>60 <64=>64
#define ECBM_MCU_ROM_SIZE 64
//<h>��Ƭ��ϵͳ����
//<i>�ÿ��ڵ�ѡ���л����ѡ�����ϸ�Ķ��˽��˽����ѡ��
//<o>��Ƭ��ϵͳʱ������
//<i>��ѡ�����ѡ��Ƭ��ʱ����Դ������Ҳ�����ú����޸�ʱ����Դ��
//<i>�ڲ�����ʱ��HSI(��׼)��ѡ�����ѡ��Ļ���ecbm����Զ���ȡSTCISP���ߵ����õı�׼Ƶ�ʡ�����׼Ƶ����ָ11.0592M��12M��24M���֣�
//<i>�ڲ�����ʱ��HSI(�Զ���)���Զ���Ƶ����ָ6.666M��22.33M�����Լ������Ƶ�ʡ���Ҫ������ġ�����(HSI/HSE)Ƶ��ѡ��ѡ���������Ƶ�ʡ�
//<i>�ڲ�����ʱ��LSI�������ڲ�32K�������ܴ�ʹ�����ʱ��Դ�ᵼ�ºܶ����ʱ��Ĳ���ʧЧ���ǳ����Ƽ�ʹ�������
//<i>�ⲿ��Դ����ѡ�����ѡ��Ļ�����Ҫ������ġ�����(HSI/HSE)Ƶ��ѡ��ѡ���а�ʱ��Ƶ�����ó��ⲿ��Դ�����Ƶ�ʡ�
//<i>�ⲿ��Դ����ѡ�����ѡ��Ļ�����Ҫ������ġ�����(HSI/HSE)Ƶ��ѡ��ѡ���а�ʱ��Ƶ�����ó��ⲿ��Դ�����Ƶ�ʡ�
//<0=>�ڲ�����ʱ��HSI(��׼) <1=>�ڲ�����ʱ��HSI(�Զ���) <2=>�ڲ�����ʱ��LSI <3=>�ⲿ���پ��� <4=>�ⲿ������Դ���� <5=>�ⲿ������Դ���� 
#define ECBM_SYSCLK_TYPE 0
//<o>����(HSI/HSE)Ƶ��ѡ��
//<i>���嵥Ƭ�����е�ʱ��Ƶ�ʣ���λHz����
//<i>������stcisp�������������Զ���Ƶ�ʻ���ʹ�����ⲿ�����ʱ����Ҫ���������뾧��Ƶ�ʡ�
#define ECBM_SYSCLK_SETTING 16000000L
//<e>ϵͳʱ�����
//<i>�������ʱ��Ƶ�����������������裬�������ڼ���ڲ��Ĺ���Ƶ�ʡ�
#define ECBM_SYSCLK_OUT_EN 0
//<o>�������
//<0=>�����P54 <1=>�����P16
#define	ECBM_SYSLCK_OUT_PIN 1
//<o.4..7>STC8F��STC8A���������Ƶ
//<i>����������ͺ�ѡ���������÷�Ƶ��ѡ��ֻ����Чһ����
//< 1=>SYSCLK/ 1  < 2=>SYSCLK/ 2 < 4=>SYSCLK/ 4 
//< 6=>SYSCLK/ 8  < 8=>SYSCLK/16 <10=>SYSCLK/32 
//<12=>SYSCLK/64  <14=>SYSCLK/128
#define ECBM_SYSCLK_OUT_SETTING_FA 0x18
//<o>STC8G��STC8H���������Ƶ
//<1-127>
//<i>����������ͺ�ѡ���������÷�Ƶ��ѡ��ֻ����Чһ����
//<i>����پ��Ƿ�Ƶ���٣�������6������SYSCLK/6��
#define ECBM_SYSCLK_OUT_SETTING_GH 1
//</e>
//</h>
//<h>ECBM��������
//<q>�Զ����ع���
//<i>��ѡ��ѡ�����ʹ���Զ����ع��ܡ���������ʹ���˴���1�����Ե�ȷ������1��ʹ��״̬�����������ӳ�䵽P30��P31��
//<i>�����Զ����ع��ܺ�uart_int�����ͻ���system_init�ﱻ���ã��������ֶ�����uart_int�����ˡ�
#define ECBM_AUTO_DOWNLOAD_EN  1
//<q>��Ƭ�����ü��
//<i>��ѡ��ѡ����Զ�����system_check������Ȼ���ڵ��Զ˵Ĵ������ֿ�����Ƭ����һЩ��Ϣ��
//<i>system_check������Ծ���Ƶ�ʵ���Ϣ���м�⣬Ȼ������������������ô���ģ��ɸ�����ʾ�޸ġ�
#define ECBM_MCU_CHECK_EN  0 
//<q>����Թ���
//<i>Ϊ���Զ����ع��ܣ�һ�㶼��򿪴���1��ƽʱʹ�ô���1�����ԽԿɡ�
//<i>����������������󣬱���û��Ӳ�����ڻ��ߴ��ڱ�ռ�õ����������ʹ�øù��ܡ�
//<i>ֻ��ָ��ĳ��IO�ڣ���IO�ھͻ���9600�Ĳ����ʷ��͵�����Ϣ����Ҫ��ʱ������GPIO���֧�֡�
#define ECBM_SOFT_DEBUG_EN 0
//</h>
//<h>����Ż�
//<i>��������8K������С��Ƭ�����߸�С�ĵ�Ƭ����ʹ�ñ����ʱ��������Ѷ���ĺ����Ż�����
//<q>error_printf
//<i>�ú�����Ҫ��Ϊ�˿⺯���ı����ܡ�
#define ECBM_ERROR_PRINTF_EN 1
//<q>strϵ��
//<i>��ϵ�к�����Ҫ��Ϊ�˴��ַ����л�ȡ���õ���Ϣ��ĳЩ�����ʹ�õ���������Ϊ��չ���ܣ���ʵ��������Ŀ��ʱ������Ż�����
#define ECBM_STRING_EN 1
//<q>crc16ϵ��
//<i>��ϵ�к�����Ҫ���ڼ��㡢���ɡ����CRC16��������ͨ���е�У�鲿�֣�������漰��ͨ�ţ������Ż�����
//<i>����������X16+X15+X2+1������������Դ�����ϣ��������õ��ǵ����A001��
#define ECBM_CRC16_EN 0
//</h>
//<h>��Ƭ��������ѡ��
//<i>��Щ���Ա�Ŀ�����������ע�⿴˵�����֡��ڹ�ѡĳ���ʱ����ͬ�����Ŀ�һ��ѡ��
//<q>POWER��
//<i>�ÿ��ṩ�˹���STC8�ĵ�Դ����λ�����Ź���ز���������
#define ECBM_POWER_LIB_EN 0
//<q>UART��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��UART��ز���������
#define ECBM_UART_LIB_EN 1
//<q>EXTI��
//<i>�ÿ��ṩ�˹���STC8���ⲿ�ж���ز���������
#define ECBM_EXTI_LIB_EN 0
//<q>TIMER��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��TIMER��ز���������
#define ECBM_TIMER_LIB_EN 0
//<q>EEPROM��
//<i>�ÿ��ṩ�˹���STC8ʹ������FLASHģ���EEPROM��ز���������
#define ECBM_EEPROM_LIB_EN 0
//<q>SPI��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��SPI��ز���������
#define ECBM_SPI_LIB_EN 0
//<q>SOFT_SPI��
//<i>�ÿ��ṩ�˹���STC8����GPIO������SPI��ز���������
#define ECBM_SOFTSPI_LIB_EN 0
//<q>IIC��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��IIC��ز���������
#define ECBM_IIC_LIB_EN 0
//<q>SOFT_IIC��
//<i>�ÿ��ṩ�˹���STC8����GPIO������IIC��ز���������
#define ECBM_SOFTIIC_LIB_EN 0
//<q>ADC��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��ADC��ز���������
#define ECBM_ADC_LIB_EN 0
//<q>CMP��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��CMP��ز���������
#define ECBM_CMP_LIB_EN 0
//<q>MDU16��
//<i>�ÿ��ṩ�˹���STC8G��Ӳ���˳�����ز���������
#define ECBM_MDU16_LIB_EN 0
//<q>IT��
//<i>�ÿ��ṩ�˹���STC8���ж����ȼ���ز���������
#define ECBM_IT_LIB_EN 0
//<q>PCA��
//<i>�ÿ��ṩ�˹���STC8A��Ӳ��PCA��ز���������
#define ECBM_PCA_LIB_EN 0
//<q>PWM��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��PWM��ز���������
#define ECBM_PWM_LIB_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*------------------------------------ͷ�ļ�����------------------------------------*/
#include "ecbm.h"        //��Ƭ���Ĵ�����ͷ�ļ���
#include "intrins.h"    //��Ƭ��C����ʹ�û��ָ���ͷ�ļ���
#include <STDARG.H>     //���������֧�ֵ�ͷ�ļ���	
#include "stdio.h"      //sprintf��غ���֧�ֵ�ͷ�ļ���
/*----------------------------------����������ӳ��----------------------------------*/
#define __IO     volatile  //��ֹ�Ż���������Ŀ�����ñ�����ÿ��ʹ�õ�ʱ�򶼵�ȥ�ڴ���ֵ��
typedef unsigned char u8;  //�޷��ŵ� 8λ��������C51������޷����ַ��ͱ�����
typedef unsigned int  u16; //�޷��ŵ�16λ��������C51������޷���  ���ͱ�����
typedef unsigned long u32; //�޷��ŵ�32λ��������C51������޷��ų����ͱ�����
typedef   signed char s8;  //�з��ŵ� 8λ��������C51������з����ַ��ͱ�����
typedef   signed int  s16; //�з��ŵ�16λ��������C51������з���  ���ͱ�����
typedef   signed long s32; //�з��ŵ�32λ��������C51������з��ų����ͱ�����
/*--------------------------------------��������-----------------------------------*/
extern u32 xdata ecbm_sys_clk;
extern u16 xdata ecbm_delay_base;
/*------------------------------------оƬ���ü���----------------------------------*/
/*####################################оƬ���ֽ���##################################*/
#if			(ECBM_MCU&0xF00000)==0x100000
#	define	ECBM_MCU_NAME	"STC8F"
#elif		(ECBM_MCU&0xF00000)==0x200000
#	define	ECBM_MCU_NAME	"STC8A"
#elif		(ECBM_MCU&0xF00000)==0x300000
#	define	ECBM_MCU_NAME	"STC8G"
#elif		(ECBM_MCU&0xF00000)==0x400000
#	define	ECBM_MCU_NAME	"STC8H"
#endif
/*##################################���������ַ����################################*/
#if		(ECBM_MCU==0x110301)||(ECBM_MCU==0x110302)//STC8F1Kxx_8PIN//STC8F1KxxS2_16PIN_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#	endif
#elif	(ECBM_MCU==0x120502)||(ECBM_MCU==0x120504)||(ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)//STC8F2KxxS2_ALL//STC8F2KxxS4_ALL//STC8A4KxxS2A12_ALL//STC8A8KxxS4A12_ALL    
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#	endif
#elif	(ECBM_MCU==0x3103A2)||(ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)||(ECBM_MCU==0x3103A1)//STC8G1Kxx_16PIN_20PIN//STC8G1Kxx_8PIN//STC8G1KxxA_8PIN//STC8G1KxxT_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x3205A2)||(ECBM_MCU==0x3205A4)//STC8G2KxxS2_ALL//STC8G2KxxS4_ALL 
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x4103A2)||(ECBM_MCU==0x4105A2)//STC8H1Kxx_20PIN//STC8H1Kxx_32PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==28
#		define	MCUID			(  (unsigned char code *)(0x6FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x6FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x6FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x6FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x6FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x6FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x6FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x6FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x6FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x6FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x6FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x6FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x6FE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x4205C4)||(ECBM_MCU==0x4305C2)||(ECBM_MCU==0x4305C4)//STC8H2KxxT_48PIN//STC8H3KxxS2_48PIN//STC8H3KxxS4_48PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	ECBM_MCU == 0x4805C4//STC8H8KxxU_48PIN_64PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0x7FED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0x7FEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0x7FEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0xEFED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xEFEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0xEFEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0xFDED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xFDEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0xFDEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#endif
/*------------------------------------ͨ�������趨----------------------------------*/
sbit    LED       =P5^5;     //ͨ��ECBM�İ��Ӷ����һ��LED����LED���õ͵�ƽ������
#define LED_ON    LED=0;     //����LED��
#define LED_OFF   LED=1;     //�ر�LED��
#define LED_BLINK LED=!LED;  //��LED��˸��
/*------------------------------------���ù����趨----------------------------------*/
//���¼�����������idata������ʱ����б����ǵķ��գ����鱣��idata����Ҫʹ�ã���ʹ��xdata����
#define REG_HSI1  read_idata_u8 (0xFA)//Ƭ��24M��·������ֵ��
#define REG_HSI   read_idata_u8 (0xFB)//Ƭ��24M��·������ֵ��
#define REG_BGV   read_idata_u16(0xEF)//Ƭ��1.3V��ѹ��ʵ��ֵ��
#define REG_LSI   read_idata_u16(0xF8)//Ƭ��32K��·������ֵ��
#define REG_ID(x) read_idata_u8 (0xF1+x)//��Ƭ����ΨһID�롣

#define io2port(n) (n)>>4           //ȡ�������ڵ�P�ڣ����Ÿ�ʽ�����0xXX�ĸ�ʽ��
#define io2pin(n)  0x01<<((n)&0x0f) //ȡ�������ڵ�PIN�����Ÿ�ʽ�����0xXX�ĸ�ʽ��
#define read_idata_u8(x)  (*((u8  volatile idata *)x))//��idata����ȡһ��u8 ������
#define read_idata_u16(x) (*((u16 volatile idata *)x))//��idata����ȡһ��u16������
#define read_idata_u32(x) (*((u32 volatile idata *)x))//��idata����ȡһ��u32������
#define read_xdata_u8(x)  (*((u8  volatile xdata *)x))//��xdata����ȡһ��u8 ������
#define read_xdata_u16(x) (*((u16 volatile xdata *)x))//��xdata����ȡһ��u16������
#define read_xdata_u32(x) (*((u32 volatile xdata *)x))//��xdata����ȡһ��u32������
#define read_idata_s8(x)  (*((s8  volatile idata *)x))//��idata����ȡһ��s8 ������
#define read_idata_s16(x) (*((s16 volatile idata *)x))//��idata����ȡһ��s16������
#define read_idata_s32(x) (*((s32 volatile idata *)x))//��idata����ȡһ��s32������
#define read_xdata_s8(x)  (*((s8  volatile xdata *)x))//��xdata����ȡһ��s8 ������
#define read_xdata_s16(x) (*((s16 volatile xdata *)x))//��xdata����ȡһ��s16������
#define read_xdata_s32(x) (*((s32 volatile xdata *)x))//��xdata����ȡһ��s32������
/*-----------------------------------�⺯������-----------------------------------*/
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
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������delay_ms
��  �������뼶��ʱ����
��  �룺��Ҫ��ʱ�ĺ�������������1~65535��
��  ������
����ֵ����
�����ߣ�����
�������̣�delay_ms(500);//��ʱ500����
�������ڣ�2019-10-8
�޸ļ�¼��
2020-06-02:�޸�����ʱ0ms�����ʱ65535ms��BUG��
-------------------------------------------------------*/
extern void delay_ms(u16 ms);
/*-------------------------------------------------------
��������delay_us
��  ����΢�뼶��ʱ����
��  �룺��Ҫ��ʱ�Ľ�����������΢����������ͨ��delay_set_us
        �����������΢���Ӧ�Ľ�������
��  ������
����ֵ����
�����ߣ�����
�������̣�
		us_val=delay_set_us(20);//�����20us��Ӧ�Ľ�������
		...//�����޹صĴ��롣
		delay_us(us_val);//��ʱ20us��
		...//�����޹صĴ��롣
�������ڣ�2019-10-8
�޸ļ�¼��
2020-1-3��ȥ����us_code.h�ļ�
-------------------------------------------------------*/
extern void delay_us(u16 us);
/*-------------------------------------------------------
��������delay_set_us
��  ����΢�뼶��ʱת�����������ڰ�΢����ת���ɶ�Ӧ��������
��  �룺������ʱ��΢������
��  ������
����ֵ����΢������Ӧ�Ľ�������
�����ߣ�����
�������̣�
		us_val=delay_set_us(20);//�����20us��Ӧ�Ľ�������
		...//�����޹صĴ��롣
		delay_us(us_val);//��ʱ20us��
		...//�����޹صĴ��롣
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
extern u16  delay_set_us(u16 us);
/***********************************���ڵ���ģ��***************/#if ECBM_AUTO_DOWNLOAD_EN
extern u8 xdata old_char;  //������һ�ν��յ�����
extern u8 xdata char_count;//��ͬ���ݼ���
/*-------------------------------------------------------
��������system_uart_reset
��  �����Զ�����������������õ������жϵĽ��ղ��־���ʵ���Զ����ء�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
extern void system_uart_reset();
/*-------------------------------------------------------
��������system_check
��  ����ϵͳ��⺯�������򴮿ڷ��͵�Ƭ����һЩ������Ϣ�������յĵ�
		��Ϣ˵���⺯�������������������һ�㲻���á���ͼ�ν����п�
		���Ż�����������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�system_check();//���͵�Ƭ����Ϣ�����ڡ�
�������ڣ�2019-10-8
�޸ļ�¼��
2020-01-02�������˼�����Ŀ��
-------------------------------------------------------*/
extern void system_check();
/****************************************************************************/#endif
/*-------------------------------------------------------
��������debug
��  �����൱��Ӧ���ڵ�Ƭ����printf�����������ڲ�ֻ����64�ֽڻ��棬
		���Խ�����ʹ���У��ַ�����Ҫ����64�ֽڵĳ��ȡ�
��  �룺���������printfһ�����÷���
��  ������
����ֵ����
�����ߣ�����
�������̣�debug("i=%d\r\n",(u16)i);//������i��ֵ���͵����ڡ�
�������ڣ�2019-10-8
�޸ļ�¼��
2019-12-28���޸ĳɵ��ô���1�ķ��ͺ�����
2020-10-09���Ƴ��Զ�����ʹ�ܵĿ��ơ�
-------------------------------------------------------*/
extern void debug(const char * str,...);
/*----------------------------------����ϵͳ����-----------------------------------*/
/*-------------------------------------------------------
��������system_init
��  ����ECBM�⺯���ĳ�ʼ���������������еĺ�����
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�
	void main(){
		system_init();//��ʼ�������⺯����
		while(1){  
		}	
	}
�������ڣ�2019-10-8
�޸ļ�¼��
2020-1-3���¼����Զ��жϾ���Ĺ��ܡ�
-------------------------------------------------------*/
extern void system_init(void);
/*-------------------------------------------------------
��������error_printf
��  ����������Ϣ��ӡ�������������κο⺯�������衣����ÿ�����ε�Ƶ�ʷ��ͳ�����Ϣ��
		ͬʱ�����޷������ߣ�����stm32��Ӳ�������жϡ��������ú궨��ı������IO��
		���ǲ����ʹ̶�Ϊ9600��
��  �룺���������printfһ�����÷���
��  ������
����ֵ����
�����ߣ�����
�������̣�
	...//�����޹صĴ��롣
	case GPIO_P7:P7=dat;break;
	default:error_printf("gpio_write(<%d>,%d);�����ڸ�P��\r\n",(u16)port,(u16)dat);break;
	...//�����޹صĴ���
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
#define error_io P31//�˴������޸ı����IO�ڣ��޸�ΪP31��ͨ������������޸ĳ�LED�ɱ������LED��
extern void error_printf(const char * str,...); 
/*---------------------------------������ϵͳ����---------------------------------*/
/*-------------------------------------------------------
��������debug_soft
��  ����������ڣ�������������(û�н��չ���)��������ʱ���GPIO�⡣�ʺ�û��Ӳ�����ڵĵ�Ƭ����
		�����ʹ̶�Ϊ9600��
��  �룺io - ��Ҫ���������Ϣ��IO�ڡ�
		���������printfһ�����÷���
��  ������
����ֵ����
�����ߣ�����
�������̣�
	debug_soft(D31,"i=%d",i);//��P31�ڷ��ͱ���i��ֵ��
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
extern void debug_soft(u8 io,const char * str,...);
/********************************strϵ�к���************************/#if ECBM_STRING_EN
/*-------------------------------------------------------
��������str_find
��  �����ַ������Һ��������ڲ���һ���ַ����Ƿ�����һ���ַ����ڡ�
��  �룺
		dest - ��Ҫ���ҵ�Ŀ���ַ�����
		key  - ��Ҫ���ҵ��ַ���������
��  ������
����ֵ���ַ���������Ŀ���ַ�����λ�ã���0��ʼ���㡣�����-1��˵��Ŀ���ַ���û�и�������
�����ߣ�����
�������̣�
	str_find("0123456789","4",i);//��"0123456789"�в���"4"���ڵ�λ�á�
�������ڣ�2019-10-9
�޸ļ�¼��
-------------------------------------------------------*/
extern u16 str_find(char * dest,char * key);
/*-------------------------------------------------------
��������str_read_pin
��  ����IO��Ϣ��ȡ���������ڶ�ȡ�ַ�����Ŀ��λ�õ�IO��Ϣ��
��  �룺
		str - ����IO��Ϣ���ַ�����
		pos - IO��Ϣ��λ�ã�ͨ������������ַ����ڵĶ��IO��Ϣ��
��  ������
����ֵ���ڸ�λ�õ�IO��Ϣ��
�����ߣ�����
�������̣�
	str_read_pin("SCL=D13,SDA=D14",11);//��ȡ���±�11��ʼ��IO��Ϣ�����᷵��0x14��
�������ڣ�2019-10-9
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 str_read_pin(char * str,u16 pos);
/*-------------------------------------------------------
��������str_read_u16
��  ����u16������ȡ���������ڶ�ȡ�ַ�����Ŀ��λ�õ�u16����ֵ��
��  �룺
		str - ������ֵ���ַ�����
		pos - ��ֵ��λ�ã�ͨ������������ַ����ڵĶ����ֵ��
��  ������
����ֵ���ڸ�λ�õ���ֵ��U16���ͣ���0~65535��
�����ߣ�����
�������̣�
	str_read_u16("SCL=D13,w=128",9);//��ȡ���±�8��ʼ����ֵ�����᷵��128��
�������ڣ�2019-10-9
�޸ļ�¼��
2020-02-17��������һ��ֹͣ�����������������ҲҪֹͣ��
-------------------------------------------------------*/
extern u16 str_read_u16(char * str,u16 pos);
/*-------------------------------------------------------
��������str_push_len
��  �����ַ����Ƴ�ָ��������ַ������Ȳ����棩�����ڰ�ָ�������е�ָ���ؼ����Ƴ��û��档
		Ϊ�˷�ֹǰ������������ɸ��ţ����硰LEDLED_ON_OFF�����Ƴ���LED_ON����ʣ�µĲ��ֻ�������ɡ�LED_OFF������
		�����Ƴ��ؼ���֮��ֻ��ѹؼ�������λ�����㣬����������β���ݣ�����LEDLED_ON_OFF�����Ƴ���LED_ON����ʣ�¡�LED      _OFF������
��  �룺dest  -  Ŀ���ַ������档
		dlen  -  Ŀ���ַ�������ĳ��ȡ�
		key   -  ��Ҫ�Ƴ��Ĺؼ��ʡ�
		klen  -  �ؼ��ʵĳ��ȡ�
��  ������
����ֵ��0 - �Ƴ�ʧ�ܣ�������Ŀ�껺����û�иùؼ��ʡ�
		1 - �Ƴ��ɹ���
�����ߣ�����
�������̣���
�������ڣ�2020-02-17
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen);
/**************************************************************************/#endif
/*�������۵�ר��******************CRC16ģ��***********************/#if ECBM_CRC16_EN
/*-------------------------------------------------------
��������crc16
��  ��������CRC16���������õ���MODBUSģʽ����X16+X15+X2+1��
��  �룺buf - ��Ҫ����CRC16�Ļ������顣
		len - ������ĳ��ȣ�CRC16������0��len-1��Ԫ�ص�CRC16ֵ��
��  ������
����ֵ���û���������������CRC16ֵ��
�����ߣ���Դ�����ϣ�����������
�������̣���
�������ڣ�2020-02-17
�޸ļ�¼��
-------------------------------------------------------*/
extern u16 crc16(u8 buf[],u16 len);
/*-------------------------------------------------------
��������crc16_insert_buf
��  ��������CRC16����������һ�������CRC16�����Ȼ����뵽����Ľ�β����
��  �룺buf - ��Ҫ����CRC16�Ļ������顣
		len - ������ĳ��ȣ�CRC16������0��len-2��Ԫ�ص�CRC16ֵ��Ȼ����뵽len-2~len-1��λ�á�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-17
�޸ļ�¼��
-------------------------------------------------------*/
extern void crc16_insert_buf(u8 buf[],u16 len);
/*-------------------------------------------------------
��������crc16_check_buf
��  �������CRC16���������һ������CRC16����Ļ����CRC16����Ƿ���ȷ��
		�����������ͨ���Ƿ���ȷ���Ƽ���crc16_insert_buf����������Ŀ���ʽ���档
��  �룺buf - ��Ҫ����CRC16�Ļ������顣
		len - ������ĳ��ȣ�CRC16������0��len-2��Ԫ�ص�CRC16ֵ��Ȼ��Ƚ�������󴢴��CRC16ֵ�Ƿ���ȷ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-17
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 crc16_check_buf(u8 buf[],u16 len);
/*�������۵�ר��************************************************************/#endif
#endif
