#ifndef _ECBM_BEEP_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_BEEP_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2025 ����

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
                            ***************************
                            * ��ϵ��ʽ ����Ⱥ778916610 *
                            * ��1Ⱥ���ˣ���Ⱥ927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>��������ĵ�ƽ
//<i>�����ⲿ��·����ȫ���ɵģ�����NPN��·�Ǹߵ�ƽ�죬PNP��·�ǵ͵�ƽ�졣�������Ե������÷������������ĵ�ƽ��
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_BEEP_IO_WORK (0)
//<o>�����������Ŷ�Ӧ��port
//<0x80=>P0
//<0x90=>P1
//<0xA0=>P2
//<0xB0=>P3
//<0xC0=>P4
//<0xC8=>P5
//<0xE8=>P6
//<0xF8=>P7
#define ECBM_BEEP_IO_PORT (0xB0)
//<o>�����������Ŷ�Ӧ��pin
//<0x00=>0
//<0x01=>1
//<0x02=>2
//<0x03=>3
//<0x04=>4
//<0x05=>5
//<0x06=>6
//<0x07=>7
#define ECBM_BEEP_IO_PIN  (0x03)
//<o>���ʱ��
//<i>����Ĭ��״̬�·��������ʱ�䳤�ȣ�����Ҳ������beep_set_class�����޸ġ�
//<i>��ֵΪ10mS�ı�������������5��������5*10=50mS��
#define ECBM_BEEP_ON_TIME_MAX  (8)
//<o>�����ʱ��
//<i>����Ĭ��״̬�����η�������ļ��ʱ�䳤�ȣ�����Ҳ������beep_set_class�����޸ġ�ͨ�����������ε�ʱ��Ż��õ����ֵ��
//<i>��ֵΪ10mS�ı�������������5��������5*10=50mS��
#define ECBM_BEEP_OFF_TIME_MAX  (12)
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������beep_set_class
��  �����������޸���ʽ�������������÷��������ʱ���ͼ��ʱ����
��  �룺
    on_time     ���ʱ����
    off_time    �����ʱ����
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2025-03-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void beep_set_class(u8 on_time,u8 off_time);
/*-------------------------------------------------------
��������beep_start
��  �����������캯����
��  �룺
    count     ��Ĵ�����
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2025-03-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void beep_start(u8 count);
/*-------------------------------------------------------
��������beep_idle
��  �������������к������Ͽ����IO�Ŀ��ƣ�ʵ���Զ���ķ��������ơ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2025-03-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void beep_idle(void);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��