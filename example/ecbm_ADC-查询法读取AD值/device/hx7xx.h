#ifndef _XXXX_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _XXXX_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<h>����֧��
//<q>HX710A
//<i>��оƬ��ͨ��A����128���������������źţ�ͨ��B�ܲ���Ƭ���¶ȡ�
#define HX7XX_HX710A_EN 1
//<q>HX710B
//<i>��оƬ��ͨ��A����128���������������źţ�ͨ��B�ܲ���DVDD-AVDD�ĵ�ѹ�
#define HX7XX_HX710B_EN 1
//<q>HX710C
//<i>��оƬ��ͨ��A����128���������������źţ����д�������Դ���ء�
#define HX7XX_HX710C_EN 1
//<q>HX711
//<i>��оƬ��ͨ��A����128����64���������������źţ�ͨ��B����32���������������źš�
#define HX7XX_HX711_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define HX710A_CHA      0//�´β�������Aͨ����������HX710A
#define HX710A_TEMP     1//�´β��������¶�ͨ����������HX710A
#define HX710A_CHA_40HZ 2//�´β�������Aͨ��������Ƶ���л���40Hz��������HX710A

#define HX710B_CHA      0//�´β�������Aͨ����������HX710B
#define HX710B_VDD      1//�´β�������VDD��������HX710B
#define HX710B_CHA_40HZ 2//�´β�������Aͨ��������Ƶ���л���40Hz��������HX710B

#define HX710C_CHA      0//�´β�������Aͨ����������HX710C

#define HX711_CHA       0//�´β�������Aͨ����������HX711
#define HX711_CHB       1//�´β�������Bͨ����������HX711
#define HX711_CHA_64    2//�´β�������Aͨ�����Ŵ�����Ϊ64��������HX711

#define HX720_CHA       0//�´β�������Aͨ����������HX720
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 sck_port;//ʱ�ӽš�
	u8 sck_pin;
	u8 sda_port;//���ݽš�
	u8 sda_pin;
	s32 dat;	//�����õ����ݡ�
}hx7xx_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������hx7xx_init
��  ����hx7xxϵ�еĳ�ʼ��������
��  �룺dev   -  ��Ҫ��ʼ����������
		sck   -  ������ʱ�ӽš�
		sda   -  ���������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
void hx7xx_init(hx7xx_def * dev,u8 sck,u8 sda);
/*-------------------------------------------------------
��������hx7xx_run
��  ����hx7xxϵ�е����к��������ڵĵ�ADC�Ĳ���ֵ��
��  �룺dev  -  Ҫ������������
		next - �´β�����ͨ��/���ܡ�
��  ����dev.dat - �����Ľ����
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
void hx7xx_run(hx7xx_def * dev,u8 next);
#endif
