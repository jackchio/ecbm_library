#ifndef _ALFOLF_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ALFOLF_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
------------------------------------------------------------------------------------*///���ǿ�ԴЭ�飬������ͼ�ν���ѡ�
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	float min;
	float max;
	float err;
	float value;
}alfolf_def;//�޷�һ�������˲�����
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������alfolf_init
��  �����޷�һ�������˲����ĳ�ʼ��������
��  �룺dev   -   Ҫ��ʼ�����˲�����
		min   -   Ҫ�޷�����Сֵ��
		max   -   Ҫ�޷������ֵ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-29
�޸ļ�¼��
-------------------------------------------------------*/
extern void alfolf_init(alfolf_def * dev,float min,float max);
/*-------------------------------------------------------
��������alfolf_in
��  �����޷�һ�������˲������������뺯����
��  �룺dev       -   Ҫ�������ݵ��˲�����
		in        -   ���˲������ݡ�
��  ����dev.value  -  �˲��������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-29
�޸ļ�¼��
-------------------------------------------------------*/
extern void alfolf_in(alfolf_def * dev,float in);
#endif
