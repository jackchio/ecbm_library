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
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 port;        //DHT11Ӳ�����ӵ�P��
	u8 pin;         //P���ϵı��
	u8 temp;		//DHT11��������¶�ֵ
	u8 humi;		//DHT11�������ʪ��ֵ
}dht11_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������dht11_init
��  ����DHT11�ĳ�ʼ��������
��  �룺dev  -  ��Ҫ��ʼ����������
		pin  -  �����������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void dht11_init(dht11_def * dev,u8 pin);
/*-------------------------------------------------------
��������dht11_run
��  ����DHT11�����к��������о��ܵõ���ʪ��ֵ��
��  �룺dev  -  ��Ҫ������������
��  ����dev.temp - �����õ����¶�ֵ��
		dev.humi - �����õ���ʪ��ֵ��
����ֵ��ͨ��״̬��0-������1-���ߴ���2-���ʳ�ʱ
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 dht11_run(dht11_def * dev);
#endif
