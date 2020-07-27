#ifndef _ECBM_SOFT_SPI_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_SOFT_SPI_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<h>���SPIģʽ����
//<q.7>MOSI��ʹ��
//<q.6>MISO��ʹ��
//<e.5>CS��ʹ��
//<o.4>CS�ŵĿ���Ȩ
//<0=>�û����� <1=>�⺯������
//</e>
//<o.2>�����շ�˳��
//<1=>����/�����ݵĸ�λ��MSB�� <0=>����/�����ݵĵ�λ��LSB��
//<o.1>SPIʱ�Ӽ��Կ���
//<i>�����Ŀ��������Э��ѡ��
//<0=>SCLK����ʱΪ�͵�ƽ <1=>SCLK����ʱΪ�ߵ�ƽ
//<o.0>SPIʱ����λ����
//<i>�����Ŀ��������Э��ѡ��
//<1=>��ʱ�ӱ仯�ĵ�һ������ <0=>��ʱ�ӱ仯�ĵڶ�������
#define ECBM_SOFT_SPI_MODE 0x94
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
//|  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
//|MOSIEN|MISOEN| CSEN |CS_CON|  --  |M/LSB | CPOL | CPHA |
#define SOFT_SPI_MOSI_EN_MASK 0x80 //MOSI��ʹ��
#define SOFT_SPI_MOSI_ENABLE  0x80 //����MOSI��
#define SOFT_SPI_MOSI_DISABLE 0x7F //�ر�MOSI��

#define SOFT_SPI_MISO_EN_MASK 0x40 //MISO��ʹ��
#define SOFT_SPI_MISO_ENABLE  0x40 //����MISO��
#define SOFT_SPI_MISO_DISABLE 0xBF //�ر�MISO��

#define SOFT_SPI_CS_EN_MASK   0x20 //CS��ʹ��
#define SOFT_SPI_CS_ENABLE    0x20 //����CS��
#define SOFT_SPI_CS_DISABLE   0xDF //�ر�CS��

#define SOFT_SPI_CS_CON_MASK  0x10 //CS�ſ���Ȩ��
#define SOFT_SPI_CS_SYSTEM    0x10 //CS�ɿ⺯������
#define SOFT_SPI_CS_USER      0xEF //CS���û��Լ�����

#define SOFT_SPI_MSB_LSB_MASK 0x04 //��/λѡ��
#define SOFT_SPI_MSB          0x04 //�ȷ���λ
#define SOFT_SPI_LSB          0xFB //�ȷ���λ

#define SOFT_SPI_CPOL_MASK    0x02 //ʱ�ӿ��е�ƽ
#define SOFT_SPI_CPOL_1       0x02 //���иߵ�ƽ
#define SOFT_SPI_CPOL_0       0xFD //���е͵�ƽ

#define SOFT_SPI_CPHA_MASK    0x01 //ʱ����λ
#define SOFT_SPI_CPHA_1       0x01 //�ڵ�һ��ʱ���ز���
#define SOFT_SPI_CPHA_0       0xFE //�ڵڶ���ʱ���ز���
/*--------------------------------------��������-----------------------------------*/
extern u8 xdata soft_spi_def_clk_port;
extern u8 xdata soft_spi_def_clk_pin;
extern u8 xdata soft_spi_def_mosi_port;
extern u8 xdata soft_spi_def_mosi_pin;
extern u8 xdata soft_spi_def_miso_port;
extern u8 xdata soft_spi_def_miso_pin;
extern u8 xdata soft_spi_def_cs_port;
extern u8 xdata soft_spi_def_cs_pin;
extern u8 xdata soft_spi_mode;
extern u8 xdata soft_spi_index;
extern u8 xdata soft_spi_max;
typedef struct{
	u8 clk_pin; //SPI���ʱ�ӽš�
	u8 mosi_pin;//SPI�����������š�
	u8 miso_pin;//SPI�����������š�
	u8 cs_pin;  //SPI���Ƭѡ�š�
	u8 mode;    //SPI������ģʽ��
	u8 dev_id;  //���SPI��ΨһID����Ϊ�л���ƾ֤��
}soft_spi_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������soft_spi_set_pin
��  �������SPI�����л�������
��  �룺���SPI����Ϣ����
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-24
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_spi_set_pin(soft_spi_def * dev);
/*-------------------------------------------------------
��������soft_spi_init��
��  �������SPI��ʼ��������
��  �룺	
		dev  -  ���SPI����Ϣ����
		clk  -  ���SPI��ʱ�ӽš�
		mosi -  ���SPI����������š�
		miso -  ���SPI����������š�
		cs   -  ���SPI��Ƭѡ�š�
		mode -  ���SPI�Ĺ���ģʽ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-24
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
��������soft_spi_set_pin_linkage
��  �������SPI�����л������������棩����Ҫ����������ĵ��ã��������ԭ�������soft_spi_set_pin������
��  �룺id   -  ��ʼ�����SPIʱ�����id�š�
		clk  -  ���SPI��ʱ�ӽš�
		mosi -  ���SPI����������š�
		miso -  ���SPI����������š�
		cs   -  ���SPI��Ƭѡ�š�
		mode -  ���SPI�Ĺ���ģʽ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-22
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
��������soft_spi_init_linkage
��  �������SPI��ʼ�������������棩����Ҫ����������ĵ��ã��������ԭ�������soft_spi_init������
��  �룺	clk  -  ���SPI��ʱ�ӽš�
		mosi -  ���SPI����������š�
		miso -  ���SPI����������š�
		cs   -  ���SPI��Ƭѡ�š�
		mode -  ���SPI�Ĺ���ģʽ��
��  ������
����ֵ����ʼ�����SPIʱ�����id�š�
�����ߣ�����
�������̣���
�������ڣ�2019-10-22
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode);
/*-------------------------------------------------------
��������soft_spi_send
��  �������SPI����/���պ�����
��  �룺Ҫ���͵����ݡ�
��  ������
����ֵ�����յ������ݡ�
�����ߣ�����
�������̣�
		soft_spi_send(0x55);    //����ĳ�����ݡ�
		val=soft_spi_send(0xff);//��ȡĳ�����ݣ�ͨ��������������Ļ�����0xff��
�������ڣ�2019-10-22
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_spi_send(u8 dat);
#endif
