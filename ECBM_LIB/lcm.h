#ifndef _ECBM_LCM_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_LCM_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 ����

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
//<q.7>�ж�ʹ��
//<o.1..3>��������
//<i>ѡ��8λ��ʱ�����硰8λ[P2]������ʾ��P2����8λ���ݡ�
//<i>ѡ��16λ��ʱ�����硰16λ[P2][P0]������ʾ��P2�����8λ���ݣ�����P0�����8λ���ݡ�
//<0=>8λ[P2] 
//<2=>8λ[P6] 
//<1=>16λ[P2][P0] 
//<3=>16λ[P6][P2] 
//<5=>16λ[P2][P7] 
//<7=>16λ[P6][P7]  
//<o.0>����ģʽ
//<0=>I8080ģʽ 
//<1=>M6800ģʽ
#define ECBM_LCM_CFG1 (0x00)
//<o.5..6>���ƽ�ѡ��
//<i>8080ģʽ�¶�ӦRS��RD��WR�������ƽ�
//<i>6800ģʽ�¶�ӦRS��E ��RW�������ƽ�
//<0=>[P41][P44][P43] 
//<1=>[P41][P37][P36] 
//<2=>[P41][P42][P40] 
//<3=>[P40][P37][P36]
//<o.2..4>����ʱ��
//<0-7>
//<o.0..1>����ʱ��
//<0-3>
#define ECBM_LCM_CFG2 (0x1F)
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������lcm_init
��  ����LCM�ӿڳ�ʼ������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�lcm_init();//��ʼ��LCM����
�������ڣ�2021-6-9
�޸ļ�¼��
-------------------------------------------------------*/
extern void lcm_init(void);
/*-------------------------------------------------------
��������lcm_write_8cmd
��  ����LCM����8λָ�����ʹ��8λ���ߣ�
��  �룺
    cmd     Ҫ���͵�ָ��
��  ������
����ֵ����
�����ߣ�����
�������̣�lcm_write_8cmd(0x50);//����ָ��0x50
�������ڣ�2021-6-9
�޸ļ�¼��
-------------------------------------------------------*/
extern void lcm_write_8cmd(u8 cmd);
/*-------------------------------------------------------
��������lcm_write_8data
��  ����LCM����8λ���ݺ�����ʹ��8λ���ߣ�
��  �룺
    dat     Ҫ���͵�����
��  ������
����ֵ����
�����ߣ�����
�������̣�lcm_write_8data(0x50);//��������0x50
�������ڣ�2021-6-9
�޸ļ�¼��
-------------------------------------------------------*/
extern void lcm_write_8data(u8 dat);
/*-------------------------------------------------------
��������lcm_write_16cmd
��  ����LCM����16λָ�����ʹ��16λ���ߣ�
��  �룺
    cmd     Ҫ���͵�ָ��
��  ������
����ֵ����
�����ߣ�����
�������̣�lcm_write_16cmd(0x0050);//����ָ��0x0050
�������ڣ�2021-6-9
�޸ļ�¼��
-------------------------------------------------------*/
extern void lcm_write_16cmd(u16 cmd);
/*-------------------------------------------------------
��������lcm_write_16data
��  ����LCM����16λ���ݺ�����ʹ��16λ���ߣ�
��  �룺
    dat     Ҫ���͵�����
��  ������
����ֵ����
�����ߣ�����
�������̣�lcm_write_16data(0x1250);//��������0x1250
�������ڣ�2021-6-9
�޸ļ�¼��
-------------------------------------------------------*/
extern void lcm_write_16data(u16 dat);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��