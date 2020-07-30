#ifndef _MAX6675_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _MAX6675_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<h>�ṹ���Ż�
//<q>�ȵ�ż��·��⹦��
//<i>���������ܺ󣬷��ʽṹ���flag����֪���ȵ�ż�Ƿ����ӵ�MAX6675�ϡ�
//<i>����ʱ��flag=1���Ͽ�ʱ��flag=0��
#define MAX6675_FLAG_EN 1 
//<o>�¶���������
//<0=>u16��(ԭʼ����) <1=>float��(�¶�ֵ)
//<i>�������оƬ���¶ȵķֱ���Ҳ����ܸߣ�ֻ��0.25�ȡ�������float�͵��ŵ�Ҳ����̫�󡣻���u16�Ϳ��Խ�ԼһЩ�ռ䣨ʡ2�ֽڣ���
//<i>MAX6675�Ĳ�����Χ��0~1023.75��,��ѡ��u16��(ԭʼ����)��ʱ���Ӧ0~4095��
#define MAX6675_TEMP_TYPE 1
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	#if MAX6675_TEMP_TYPE == 0 	//���ѡ����ԭʼ���ݣ�
	u16 temp;					//�Ͷ����u16�͡�
	#else						//���ѡ�����¶�ֵ��
	float temp;					//�Ͷ����float�͡�
	#endif
	u8 sck;						//ʱ�ӽš�
	u8 cs;						//Ƭѡ�š�
	u8 so;						//���ݽš�
	#if MAX6675_FLAG_EN			//���ʹ�����ȵ�ż��⣬
	u8 flag;					//�Ͷ���һ�����������ȵ�ż����״̬��
	#endif
}max6675_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������max6675_init
��  ����MAX6675�ĳ�ʼ��������
��  �룺dev  -  ��Ҫ��ʼ����������
		sck  -  ������ʱ�ӽš�
		cs   -  ������Ƭѡ�š�
		so   -  ���������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-02
�޸ļ�¼��
-------------------------------------------------------*/
extern void max6675_init(max6675_def * dev,u8 sck,u8 cs,u8 so);
/*-------------------------------------------------------
��������max6675_run
��  ����MAX6675�����к��������д˺����ܵõ��¶�ֵ��
��  �룺dev      -  ��Ҫ��ȡ�¶ȵ�������
��  ����dev.temp -  �¶�ֵ��
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-02
�޸ļ�¼��
-------------------------------------------------------*/
extern void max6675_run(max6675_def * dev);
#endif
