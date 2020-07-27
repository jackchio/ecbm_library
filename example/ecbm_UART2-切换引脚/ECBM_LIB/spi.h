#ifndef _ECBM_SPI_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_SPI_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 ����

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
//<h>SPI���ڲ�����
//<o.4>��/�ӻ�
//<0=>�ӻ�  <1=>����
//<i>�����Լ����������á�
//<o.7>SS����ʹ��
//<i>SS����Ƭѡ�ˡ�
//<i>ʹ��SS�ź����SS�ű�������ͣ���ô����֮ǰ���������Ǵӻ�������ǿ�Ʊ��л��ɴӻ���
//<i>ʹ��SS�ź����SS�ű�������ߣ���ô���������Ǵӻ���������ġ���/�ӻ���������������
//<i>ͨ��Ҫ��һֱ����Ϊ�����Ļ����Ϳ��Բ�ʹ��SS����
//<o.5>�����շ�˳��
//<0=>����/�����ݵĸ�λ��MSB�� <1=>����/�����ݵĵ�λ��LSB��
//<i>����Ŀ������ѡ��
//<o.0..1>SPIʱ��
//<i>SYSCLK������Ƶ����STC-ISP�����õ��Ǹ���
//<0=>SYSCLK/4 <1=>SYSCLK/8 <2=>SYSCLK/16 <3=>SYSCLK/32 
//<o.3>SPIʱ�Ӽ��Կ���
//<i>�����Ŀ��������Э��ѡ��
//<0=>SCLK����ʱΪ�͵�ƽ <1=>SCLK����ʱΪ�ߵ�ƽ
//<o.2>SPIʱ����λ����
//<i>�����Ŀ��������Э��ѡ��
//<0=>��ʱ�ӱ仯�ĵ�һ������ <1=>��ʱ�ӱ仯�ĵڶ�������
#define ECBM_SPI_REG 0x50
//<o.2..3>SPI����ܽ�
//<i>����SPI����Ĺܽţ�����4���ѡ��
//<0=>SS-P12|MOSI-P13|MISO-P14|SCLK-P15
//<1=>SS-P22|MOSI-P23|MISO-P24|SCLK-P25
//<2=>SS-P74|MOSI-P75|MISO-P76|SCLK-P77
//<3=>SS-P35|MOSI-P34|MISO-P33|SCLK-P32
#define ECBM_SPI_IO 0
//</h>
//<q>SPI�ж�
//<i>SPI�������һ���ֽھͻᴥ���жϡ�
#define ECBM_SPI_IT_EN 0
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define SPI_IT_ON  do{IE2|=0x02;}while(0)
#define SPI_IT_OFF do{IE2&=0xFD;}while(0)
#define SPI_IT_ID  interrupt 9
#define SPI_PIN_P1 0
#define SPI_PIN_P2 4
#define SPI_PIN_P7 8
#define SPI_PIN_P3 12
#if ECBM_SPI_IT_EN == 1
extern u8 xdata spi_busy;
#define SPI_IT_CLS do{SPSTAT = 0xc0;spi_busy=0;}while(0)
#endif
//void SPI_Isr() SPI_IT_ID
//{
//    SPI_IT_CLS;     //���жϱ�־
//    LED = !LED;     //���Զ˿�
//}
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������spi_set_pin
��  ����SPI���������ú�����SPI֧��4���飬��Ӧ��P1��P2��P7��P3�ϡ�
��  �룺group - ����SPI��������š���������SPI_PIN_P1��SPI_PIN_P2��SPI_PIN_P7��SPI_PIN_P3��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-22
�޸ļ�¼��
-------------------------------------------------------*/
extern void spi_set_pin(u8 group);
/*-------------------------------------------------------
��������spi_init
��  ����SPI��ʼ������������������ͼ�ν������롣
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�spi_init();//��ʼ��SPI
�������ڣ�2019-8-23
�޸ļ�¼��
-------------------------------------------------------*/
extern void spi_init(void);
/*-------------------------------------------------------
��������spi_send
��  ����SPI����/���պ�����
��  �룺Ҫ���͵����ݡ�
��  ������
����ֵ�����յ������ݡ�
�����ߣ�����
�������̣�
		spi_send(0x55);    //����ĳ�����ݡ�
		val=spi_send(0xff);//��ȡĳ�����ݣ�ͨ��������������Ļ�����0xff��
�������ڣ�2019-10-22
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 spi_send(u8 dat);
#endif
