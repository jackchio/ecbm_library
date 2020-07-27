#ifndef _MCP41XXX_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _MCP41XXX_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<h>MCP41XXX��ʼ״̬����
//<i>����DDS�������̬���ıȽ�Ƶ�����������������������ֵֻ�����ڳ�ʼ��������
//<o>��ʼ����ֵ
//<i>��0��255��
//<0-255>
#define MCP41XXX_INIT_AMP 150
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 cs;	//Ƭѡ��
	u8 sck;	//ʱ�ӽ�
	u8 dat;	//���ݽ�
}mcp41xxx_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������mcp41xxx_init
��  ����MCP41XXXϵ�еĳ�ʼ��������
��  �룺dev   -  ��Ҫ��ʼ����������
		cs   -   ��������Ƭѡ�š�
		sck  -   ��������ʱ�ӽš�
		dat  -   �����������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-01
�޸ļ�¼��
-------------------------------------------------------*/
extern void mcp41xxx_init(mcp41xxx_def *dev,u8 cs,u8 sck,u8 dat);
/*-------------------------------------------------------
��������mcp41xxx_set_amp
��  ����MCP41XXXϵ�е����÷�ֵ��������������0~255��
��  �룺dev   -  ��Ҫ��ʼ����������
		amp  -  ��Ҫ���õķ�ֵ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-01
�޸ļ�¼��
-------------------------------------------------------*/
extern void mcp41xxx_set_amp(mcp41xxx_def *dev,u8 amp);
#endif
