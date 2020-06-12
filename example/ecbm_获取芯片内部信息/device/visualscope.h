#ifndef _VISUALSCOPE_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _VISUALSCOPE_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������vs_send
��  ��������ʾ�������ͺ�����
��  �룺id	-	�������ݵĴ��ںš�������ֱ�ӵ��ô��ڷ��ͺ��������Ҫʹ�õĴ�����Ҫ��ǰ��ʼ����
		ch	-	���͵�����ʾ����ͨ������������1~4��
		dat	-	���͵����ݻ��档
��  ������
����ֵ����
�����ߣ�����
�������̣�
��1��
	s16 adc_buf;//���建�������
	...//�޹ش��롣
	adc_buf=(s16)adc_read(0);//��ȡadc��ͨ��0��adֵ�浽������,ע���������ת����
	vs_send(1,1,&adc_buf);//ͨ������1������adֵ�����⴮�ڣ�ֻ����һ������ʾ����ͨ����
	...//�޹ش��롣
��2��
	s16 rocker[2];//����ҡ�˻������飬2��Ԫ�طֱ��ӦX���Y�ᡣ
	...//�޹ش��롣
	rocker[0]=(s16)adc_read(0);//��ȡҡ��X��ƫ������
	rocker[1]=(s16)adc_read(1);//��ȡҡ��Y��ƫ������
	vs_send(1,2,rocker);////ͨ������1������ҡ��ƫ���������⴮�ڣ�������������ʾ����ͨ����
	...//�޹ش��롣
�������ڣ�2020-05-08
�޸ļ�¼��
-------------------------------------------------------*/
extern void vs_send(u8 id,u8 ch,s16 * dat);
#endif
