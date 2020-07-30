#ifndef _AD9833_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _AD9833_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//�������д��ǰ��ĸ������á�
//<o>AD9833����ʱ��
//<i>��дAD9833ʹ�õ���ʱ��Ƶ�ʣ���λΪHz�����ݰ��ӵ�ʵ��ʱ������д��
#define AD9833_MCLK 25000000
//<h>AD9833��ʼ״̬����
//<i>����DDS�������̬���ıȽ�Ƶ�����������������������ֵֻ�����ڳ�ʼ��������
//<o.0..7>�������ѡ��
//<0x00=>���Ҳ�
//<0x02=>���ǲ�
//<0x68=>���β�
//<0xE8=>�����

#define AD9833_REG 0x2000
//<o>��ʼƵ��
//<i>����������������ѡ���˲����������ô��Ҫ���������ò��ε�Ƶ�ʡ���λHz��
#define AD9833_FREQ 10000000
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define AD9833_OFF_WAVE	0x00//�û�ר�ã��ر������
#define AD9833_TRI_WAVE	0x01//�û�ר�ã�������ǲ���
#define AD9833_SIN_WAVE	0x02//�û�ר�ã�������Ҳ���
#define AD9833_SQU_WAVE	0x03//�û�ר�ã�������β���


#define AD9833_REG_OFF_WAVE 0xE8//���üĴ���ר�ã��رղ��������
#define AD9833_REG_TRI_WAVE 0x02//���üĴ���ר�ã��������ǲ�������
#define AD9833_REG_SIN_WAVE 0x00//���üĴ���ר�ã��������Ҳ�������
#define AD9833_REG_SQU_WAVE 0x68//���üĴ���ר�ã����þ��β�������

#define AD9833_CONFIG_REG_MASK 0x0000	//�����ֵĵ�ַ���롣
#define AD9833_FREQ0_REG_MASK  0x4000	//Ƶ��0�Ĵ������롣
#define AD9833_FREQ1_REG_MASK  0x8000	//Ƶ��1�Ĵ������롣
#define AD9833_PHASE0_REG_MASK 0xC000	//��λ0�Ĵ������롣
#define AD9833_PHASE1_REG_MASK 0xE000	//��λ1�Ĵ������롣

/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 fsync;	//ad9833��Ƭѡ�š�
	u8 sclk;	//ad9833��ʱ�ӽš�
	u8 sdata;	//ad9833�����ݽš�
	u8 config;	//ad9833�ļ������á�
//|D7  D6  D5  D4 |   D3   |   D2   |   D1  D0  |
//|     Ԥ��      |��ǰƵ��|��ǰ��λ|�����������|
}ad9833_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������ad9833_write
��  ����ad9833��д������������ad9833����һ��16λ���ݡ�
��  �룺dev     -  ��Ҫ���͵�������
		txdata  -  ��Ҫ���͵�16λ���ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-25
�޸ļ�¼��
-------------------------------------------------------*/
extern void ad9833_write(ad9833_def * dev,u16 txdata);
/*-------------------------------------------------------
��������ad9833_set_freq
��  ����AD9833����Ƶ�ʺ�������������AD9833���������Ƶ�ʡ�
��  �룺dev  -  ��Ҫ�޸�Ƶ�ʵ�������
		freq -  ��Ҫ�޸ĵ�Ŀ��Ƶ�ʡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-25
�޸ļ�¼��
-------------------------------------------------------*/
extern void ad9833_set_freq(ad9833_def * dev,double freq);
/*-------------------------------------------------------
��������ad9833_set_wave
��  ����AD9833���ò��κ�������������AD9833��������Ρ�
��  �룺dev  -  ��Ҫ�޸�Ƶ�ʵ�������
		freq -  ��Ҫ�޸ĵ�Ŀ�겨�Ρ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-25
�޸ļ�¼��
-------------------------------------------------------*/
extern void ad9833_set_wave(ad9833_def * dev,u8 wave);
/*-------------------------------------------------------
��������ad9833_init
��  ����ad9833�ĳ�ʼ����������ʼ�����ŵĶ��塣
��  �룺dev  -  ��Ҫ��ʼ����������
		fsync-  ad9833��Ƭѡ�š�
		sclk -  ad9833��ʱ�ӽš�
		sdata-  ad9833�����ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-25
�޸ļ�¼��
-------------------------------------------------------*/
extern void ad9833_init(ad9833_def * dev,u8 fsync,u8 sclk,u8 sdata);

#endif
