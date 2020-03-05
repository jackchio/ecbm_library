#ifndef _ECBM_EXIT_H_
#define _ECBM_EXIT_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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
//<e>�ⲿ�ж�0
//<i>��Ӧ������ΪP32
//<i>֧�������жϷ�ʽ����������/�½��ء��͡�ֻ�½��ء���
#define ECBM_EXIT0_EN 1
//<o>�ж�ģʽѡ��
//<i>��������/�½��ء�ģʽ�����������ػ����½��ض��ᴥ���жϡ�
//<i>��ֻ�½��ء�ģʽ��ֻ���½��زŻᴥ���жϡ�
//<0=>������/�½��� <1=>ֻ�½���
#define ECBM_EXIT0_MODE 1
//<o>�ⲿ�ж�0���ж����ȼ�
//<i>�ļ��ж����ȿ�ѡ����������ȼ�����it�����ѯ�� 
//<0=>0������ͼ��� <1=>1�����ϵͼ���
//<2=>2�����ϸ߼��� <3=>3������߼���
#define ECBM_EXIT0_PRIORITY 0
//<q>��ʼ��ʱ�ʹ��жϣ�
//<i>�������ѡ��ѡ��Ļ������Ե���exit_start�������жϡ�
#define ECBM_EXIT0_INIT 1
//</e>
//<e>�ⲿ�ж�1
//<i>��Ӧ������ΪP33
//<i>֧�������жϷ�ʽ����������/�½��ء��͡�ֻ�½��ء���
#define ECBM_EXIT1_EN 0
//<o>�ж�ģʽѡ��
//<i>��������/�½��ء�ģʽ�����������ػ����½��ض��ᴥ���жϡ�
//<i>��ֻ�½��ء�ģʽ��ֻ���½��زŻᴥ���жϡ�
//<0=>������/�½��� <1=>ֻ�½���
#define ECBM_EXIT1_MODE 0
//<o>�ⲿ�ж�1���ж����ȼ�
//<i>�ļ��ж����ȿ�ѡ����������ȼ�����it�����ѯ��
//<0=>0������ͼ��� <1=>1�����ϵͼ���
//<2=>2�����ϸ߼��� <3=>3������߼���
#define ECBM_EXIT1_PRIORITY 0
//<q>��ʼ��ʱ�ʹ��жϣ�
//<i>�������ѡ��ѡ��Ļ������Ե���exit_start�������жϡ�
#define ECBM_EXIT1_INIT 1
//</e>
//<e>�ⲿ�ж�2
//<i>��Ӧ������ΪP36
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء����̶�Ϊ0���ж����ȣ���������ȼ�����it�����ѯ��
#define ECBM_EXIT2_EN 0
//<q>��ʼ��ʱ�ʹ��жϣ�
//<i>�������ѡ��ѡ��Ļ������Ե���exit_start�������жϡ�
#define ECBM_EXIT2_INIT 1
//</e>
//<e>�ⲿ�ж�3
//<i>��Ӧ������ΪP37
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء����̶�Ϊ0���ж����ȣ���������ȼ�����it�����ѯ��
#define ECBM_EXIT3_EN 0
//<q>��ʼ��ʱ�ʹ��жϣ�
//<i>�������ѡ��ѡ��Ļ������Ե���exit_start�������жϡ�
#define ECBM_EXIT3_INIT 1
//</e>
//<e>�ⲿ�ж�4
//<i>��Ӧ������ΪP30
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء���
#define ECBM_EXIT4_EN 0
//<o>�ⲿ�ж�4���ж����ȼ�
//<i>�ļ��ж����ȿ�ѡ����������ȼ�����it�����ѯ��
//<0=>0������ͼ��� <1=>1�����ϵͼ���
//<2=>2�����ϸ߼��� <3=>3������߼���
#define ECBM_EXIT4_PRIORITY 0
//<q>��ʼ��ʱ�ʹ��жϣ�
//<i>�������ѡ��ѡ��Ļ������Ե���exit_start�������жϡ�
#define ECBM_EXIT4_INIT 1
//</e>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define EXIT0_FUN interrupt 0       //�жϺţ��������жϺ���֮���жϺ������û��Զ��塣
#define EXIT0_ON  do{EX0=1;}while(0)//���ⲿ�ж�0��
#define EXIT0_OFF do{EX0=0;}while(0)//�ر��ⲿ�ж�0��
#define EXIT0_UD  do{IT0=0;}while(0)//�ⲿ�ж�0ͨ�������غ��½��ش�����
#define EXIT0_D   do{IT0=1;}while(0)//�ⲿ�ж�0ͨ���½��ش�����
#define EXIT0_IO  P32               //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش�����
#define EXIT1_FUN interrupt 2       //�жϺţ��������жϺ���֮���жϺ������û��Զ��塣
#define EXIT1_ON  do{EX1=1;}while(0)//���ⲿ�ж�1��
#define EXIT1_OFF do{EX1=0;}while(0)//�ر��ⲿ�ж�1��
#define EXIT1_UD  do{IT1=0;}while(0)//�ⲿ�ж�1ͨ�������غ��½��ش�����
#define EXIT1_D   do{IT1=1;}while(0)//�ⲿ�ж�1ͨ���½��ش�����
#define EXIT1_IO  P33               //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش�����
#define EXIT2_FUN interrupt 10      //�жϺţ��������жϺ���֮���жϺ������û��Զ��塣
#define EXIT2_ON  do{INTCLKO|=EX2; }while(0)//���ⲿ�ж�2��
#define EXIT2_OFF do{INTCLKO&=~EX2;}while(0)//�ر��ⲿ�ж�2��
#define EXIT2_IO  P36 
#define EXIT3_FUN interrupt 11      //�жϺţ��������жϺ���֮���жϺ������û��Զ��塣
#define EXIT3_ON  do{INTCLKO|=EX3; }while(0)//���ⲿ�ж�3��
#define EXIT3_OFF do{INTCLKO&=~EX3;}while(0)//�ر��ⲿ�ж�3��
#define EXIT3_IO  P37 
#define EXIT4_FUN interrupt 16      //�жϺţ��������жϺ���֮���жϺ������û��Զ��塣
#define EXIT4_ON  do{INTCLKO|=EX4; }while(0)//���ⲿ�ж�4��
#define EXIT4_OFF do{INTCLKO&=~EX4;}while(0)//�ر��ⲿ�ж�4��
#define EXIT4_IO  P30 
#define EXIT_UD 0//������/�½��ض������жϡ�
#define EXIT_D  1//ֻ���½��زŴ����жϡ�
/*--------------------------------------������-----------------------------------*/
/*------------------------------------------------------
��������exit_init
��  �����ⲿ�жϳ�ʼ����������ͼ�ν��������úò�����Ȼ��ֱ�ӵ��þ��С�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�exit_init();
�������ڣ�2019-7-15
�޸ļ�¼��
2019-7-17���������ж����ȼ���
2019-10-14������2.0��ܡ�
-------------------------------------------------------*/
extern void exit_init(void);
/*------------------------------------------------------
��������exit_start
��  �������жϺ�������������Ҫ�򿪵�����´򿪶�Ӧ���ⲿ�ж�ʹ�ܡ�
��  �룺��Ҫ�򿪵��ⲿ�ж�ID�ţ�������0~4��
��  ������
����ֵ����
�����ߣ�����
�������̣�exit_start(0);//���ⲿ�ж�0���ж�ʹ�ܡ�
�������ڣ�2019-7-15
�޸ļ�¼��
2019-8-14�����뱨����Ϣ���ܡ�
2019-10-14������2.0��ܡ�
-------------------------------------------------------*/
extern void exit_start(u8 id);
/*------------------------------------------------------
��������exit_stop
��  �����ر��жϺ�������������Ҫ�رյ�����¹رն�Ӧ���ⲿ�ж�ʹ�ܡ�
��  �룺��Ҫ�رյ��ⲿ�ж�ID�ţ�������0~4��
��  ������
����ֵ����
�����ߣ�����
�������̣�exit_stop(0);//�ر��ⲿ�ж�0���ж�ʹ�ܡ�
�������ڣ�2019-7-15
�޸ļ�¼��
2019-8-14�����뱨����Ϣ���ܡ�
2019-10-14������2.0��ܡ�
-------------------------------------------------------*/
extern void exit_stop(u8 id);
/*------------------------------------------------------
��������exit_set_mode
��  �����ж�ģʽ���ú�����ֻ���ⲿ�ж�0���ⲿ�ж�1�����á�
��  �룺
       id   - ���õ��ⲿ�ж�ID��������0��1��
       mode - �ж�ģʽ���С�EXIT_UD���͡�EXIT_D�����֡�
��  ������
����ֵ����
�����ߣ�����
�������̣�exit_set_mode(0,EXIT_UD);//���ⲿ�ж�0���ж�ģʽ����Ϊ������/�½��ض������жϡ�
�������ڣ�2019-7-15
�޸ļ�¼��
2019-8-14�����뱨����Ϣ���ܡ�
2019-10-14������2.0��ܡ�
-------------------------------------------------------*/
extern void exit_set_mode(u8 id,bit mode);
#endif
