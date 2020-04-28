#ifndef _MDU16_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _MDU16_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*---------------------------------------�궨��------------------------------------*/
#define MD5MD4       read_xdata_u16(0xfcf4)//һ��������ų�����������������
#define MD3MD2MD1MD0 read_xdata_u32(0xfcf0)//һ���������32λ��������32λ�̡�����
#define MD1MD0       read_xdata_u16(0xfcf2)//һ���������16λ��������16λ�̡�16λ��������
#define ARCON        read_xdata_u8 (0xfcf6)//MDUģʽ���ƼĴ�����
#define OPCON        read_xdata_u8 (0xfcf7)//MDU�������ƼĴ�����
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������div32
��  ����32λ��16λ����������
��  �룺num1  -  �޷���32λ��������
		num2  -  �޷���16λ������
��  ����num1  -  �޷���32λ�̡�
		num2  -  �޷���16λ������
����ֵ�����λ��
�����ߣ�����
�������̣���
�������ڣ�2020-03-27
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 div32(u32 * num1,u16 * num2);
/*-------------------------------------------------------
��������div16
��  ����16λ��16λ����������
��  �룺num1  -  �޷���16λ��������
		num2  -  �޷���16λ������
��  ����num1  -  �޷���16λ�̡�
		num2  -  �޷���16λ������
����ֵ�����λ��
�����ߣ�����
�������̣���
�������ڣ�2020-03-27
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 div16(u16 * num1,u16 * num2);
/*-------------------------------------------------------
��������mul16
��  ����16λ��16λ����������
��  �룺num1  -  �޷���16λ��������
		num2  -  �޷���16λ������
��  ����num3  -  �޷���32λ����
����ֵ�����λ��
�����ߣ�����
�������̣���
�������ڣ�2020-03-27
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 mul16(u16 num1,u16 num2,u32 * num3);
#endif
