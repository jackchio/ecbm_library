/************************************
*   ����.h�ļ���ͨ��ģ�壬����.h�ļ���*
*ʱ����Բο����ģ���ģʽ��         *
************************************/
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
------------------------------------------------------------------------------------*///���ǿ�ԴЭ�飬������ͼ�ν���ѡ�
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//�������д��ǰ��ĸ������á�
//<q>��ѡ��
#define dxk 1
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define XXX_XXX_XXX do{XXX_XXX}while(0) //��������ָ���͵ĺ궨�塣
#define XXX_XXX		XXX_XX				//�������峣���ͺ궨�塣
/*--------------------------------------��������-----------------------------------*/
extern u8 value;//������Ҫ�ı�����
/*--------------------------------------������-----------------------------------*/
/*�������۵�ר��**************************XXģ��*******************************/#if 1//����һ���ļ����м�����ͬ��ģ�鹹�ɣ�������������ֺͷָ
/*-------------------------------------------------------
��������
��  ����
��  �룺
��  ����
����ֵ��
�����ߣ�
�������̣�
�������ڣ�
�޸ļ�¼��
-------------------------------------------------------*/
//�⺯��ͨ�ùؼ���ģ��
//XXX  		���ʶ����ͷ�Ե�ǰ�����������������iic�����iic��ͷ��
//init 		��ʼ����˵���ú������ڳ�ʼ�����衣��Ҳ�����������趼��Ҫ��ʼ�������ã���������eeprom��
//set		���ã�˵���ú������������������ĳ������ġ�
//pin		���ţ�����set��ϣ�������������������š�����iic_set_pin��
//linkage	������������ú������ں�������ֱ����ϡ�ͨ������Ҫȥ��ע����
//start		��ʼ����ʼĳ����̣�����������ݿ�Ĳ�ͬҲ��ͬ������iic���start��Э��Ŀ�ʼ��������adc���start�ǿ���һ��װ����
//stop		����������ĳ����̣�����������ݿ�Ĳ�ͬҲ��ͬ��
//it		�жϣ����ú������ж��йء�
//mode		ģʽ��һ����ָ����Ĺ���ģʽ��
//soft		�����һЩЭ�飬��������ʵ�ֵģ��ͻ�������ؼ��ʡ�
//auto		�Զ�������һЩ��ʼ�����ӵĺ������Զ�������дĳЩ������
//work		����״̬������һЩ����IO�����߹���Э������衣ֻ��ͬʱ��һ���ڹ���״̬����Ҫ��������������óɹ���״̬��
/*�������۵�ר��**************************************************************/#endif

#endif //���������#ifndef��ϳ�һ������Ρ�
       //��һ������Ϊ��β��