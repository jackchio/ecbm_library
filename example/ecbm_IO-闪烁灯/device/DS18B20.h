#ifndef _DS18B20_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _DS18B20_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 port;	//����18b20��ͨѶ��ʱ��Ҫ��ߣ����Խ�IO�ڲ�֡�
	u8 pin;		
	float temp;	//����¶�ֵ
}ds18b20_def;
//DS18B20�Ĺܽ������ǣ���ƽ�泯���Լ���ʱ���������£������ҷֱ���GND��DQ��VCC
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������ds18b20_init
��  ����DS18B20�ĳ�ʼ��������
��  �룺dev  -  ��Ҫ��ʼ����������
		pin  -  �����������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-04
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds18b20_init(ds18b20_def * dev,u8 pin);
/*-------------------------------------------------------
��������ds18b20_write
��  ����DS18B20��д������������DS18B20д��һ���ֽڵ����ݡ�
��  �룺dev  -  Ҫ������������
		dat  -  Ҫ���͵����ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-04
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds18b20_write(ds18b20_def * dev,u8 dat);
/*-------------------------------------------------------
��������ds18b20_read
��  ����DS18B20�Ķ�������������DS18B20��ȡһ���ֽڵ����ݡ�
��  �룺dev  -  Ҫ������������
��  ������
����ֵ����ȡ�������ݡ�
�����ߣ�����
�������̣���
�������ڣ�2020-02-04
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 ds18b20_read(ds18b20_def * dev);
/*-------------------------------------------------------
��������ds18b20_check
��  ����DS18B20�ļ�⺯�������ڼ��DS18B20�Ƿ���ڣ�����λ��
��  �룺dev  -  Ŀ��������
��  ������
����ֵ��1�����������ڡ�0�������������ڡ�
�����ߣ�����
�������̣���
�������ڣ�2020-02-04
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 ds18b20_check(ds18b20_def * dev);
/*-------------------------------------------------------
��������ds18b20_run
��  ����DS18B20�����к���������֮����Ի�ȡ�¶�ֵ��
��  �룺dev      -  Ŀ��������
��  ����dev.temp - ���������¶ȡ�
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-04
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 ds18b20_run(ds18b20_def * dev);
#endif

