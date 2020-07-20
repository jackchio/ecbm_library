#ifndef _MCP4725_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _MCP4725_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
	u8 scl_pin;	//ʱ�ӽš�
	u8 sda_pin;	//���ݽš�
	u8 id;		//���IIC��ID��
	u8 config;  //оƬ�����á�
//  D7  |  D6  D5  D4  D3  D2  D1  D0 
//��Ӳ��|Ԥ��
//	
	u8 addr;	//оƬ�ĵ�ַ��
}mcp4725_def;
/*--------------------------------------������-----------------------------------*/
/*---------------------------------------�궨��------------------------------------*/
#define MCP4725_IIC_MASK	0x80//IIC���������롣
#define MCP4725_SOFT_IIC	0x00//ʹ�������IIC��
#define MCP4725_HARD_IIC	0x80//ʹ��Ӳ����IIC��
/*-------------------------------------------------------
��������mcp4725_soft_init
��  ����MCP4725�ĳ�ʼ��������ʹ�����IIC��
��  �룺dev  -  Ҫ��ʼ����������
		scl  -  ��������ʱ�ӽš�
		sda  -  �����������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-03-01
�޸ļ�¼��
-------------------------------------------------------*/
void mcp4725_soft_init(mcp4725_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
��������mcp4725_hard_init
��  ����MCP4725�ĳ�ʼ��������ʹ��Ӳ��IIC��
��  �룺dev  -  Ҫ��ʼ����������
		scl  -  ��������ʱ�ӽš�
		sda  -  �����������ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-03-02
�޸ļ�¼��
-------------------------------------------------------*/
void mcp4725_hard_init(mcp4725_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
��������mcp4725_set_addr
��  ����MCP4725�����õ�ַ�����������޸�������ַ��
��  �룺dev  -  Ҫ�޸ĵ�������
		addr -  ��������IIC��ַ��������0~7��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-03-01
�޸ļ�¼��
-------------------------------------------------------*/
void mcp4725_set_addr(mcp4725_def * dev,u8 addr);
/*-------------------------------------------------------
��������mcp4725_run
��  ����MCP4725�����к������������һ��ģ������
��  �룺dev  -  Ҫ������������
		dat  -  Ҫת����ģ��������������������0~4095����ӦоƬ��0~VCC-1LSB��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-03-01
�޸ļ�¼��
-------------------------------------------------------*/
void mcp4725_run(mcp4725_def * dev,u16 dat);
/*-------------------------------------------------------
��������mcp4725_out
��  ����MCP4725����������������к�����࣬����֧��ģ��ֵ��
��  �룺dev  -  Ҫ������������
		vcc  -  ������VCC,������Ҫע����Ǹ�оƬ����ƫ���������������ֵҪ��ʵ��VCCҪСһ�㡣
		out  -  Ҫ��������ĵ�ѹֵ��ҪС�ڲ�����VCCֵ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-03-01
�޸ļ�¼��
-------------------------------------------------------*/
void mcp4725_out(mcp4725_def * dev,float vcc,float out);
#endif
