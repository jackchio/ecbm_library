#ifndef _ECBM_PCA_H_
#define _ECBM_PCA_H_
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
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>PCA������
//<q.7>����ģʽ���Ƿ�ֹͣPCA����
//<i>��ѡ������ģʽ��PCAֹͣ������
//<i>����ѡ������ģʽ��PCA����������
//<o.1..3>PCA��������Դ
//<2=>��ʱ��0��������� <3=>ECI�ŵ��ⲿ����ʱ�� <4=>SYSCLK    <1=>SYSCLK/2 
//<5=>SYSCLK/4         <6=>SYSCLK/6           <7=>SYSCLK/8  <0=>SYSCLK/12 
//<q.0>PCA����������ж�ʹ��
#define ECBM_PCA_CMOD 0x08
//<q>PCA����������ص�����
#define ECBM_PCA_CALLBACK_EN 0
//<o.4..5>PCA����
//<0=>ECI-P12|CCP0-P17|CCP1-P16|CCP2-P15|CCP3-P14(STC8Aϵ��)
//<1=>ECI-P22|CCP0-P23|CCP1-P24|CCP2-P25|CCP3-P26(STC8Aϵ��)
//<2=>ECI-P74|CCP0-P70|CCP1-P71|CCP2-P72|CCP3-P73(STC8Aϵ��)
//<3=>ECI-P35|CCP0-P33|CCP1-P32|CCP2-P31|CCP3-P30(STC8Aϵ��)

//<0=>ECI-P12|CCP0-P11|CCP1-P10|CCP2-P37(STC8Gϵ��,��STC8G1K08A��STC8G1K08T֮��)
//<1=>ECI-P34|CCP0-P35|CCP1-P36|CCP2-P37(STC8Gϵ��,��STC8G1K08A��STC8G1K08T֮��)
//<2=>ECI-P24|CCP0-P25|CCP1-P26|CCP2-P27(STC8Gϵ��,��STC8G1K08A��STC8G1K08T֮��)

//<0=>ECI-P55|CCP0-P32|CCP1-P33|CCP2-P54(����STC8G1K08A)
//<1=>ECI-P55|CCP0-P31|CCP1-P33|CCP2-P54(����STC8G1K08A)
//<2=>ECI-P31|CCP0-P32|CCP1-P33|CCP2-P55(����STC8G1K08A)

//<0=>ECI-P13|CCP0-P11|CCP1-P10|CCP2-P37(����STC8G1K08T)
//<1=>ECI-P34|CCP0-P35|CCP1-P36|CCP2-P37(����STC8G1K08T)
//<2=>ECI-P54|CCP0-P13|CCP1-P14|CCP2-P15(����STC8G1K08T)
#define ECBM_PCA_IO 0x10
//</h>
//<e>PCA0
//<i>����ͨ��0��ʹ��
#define ECBM_PCA0_EN 1
//<o>����ģʽ
//<0=>�޹���
//<1=>6λPWMģʽ
//<2=>7λPWMģʽ
//<3=>8λPWMģʽ
//<4=>10λPWMģʽ
//<5=>16λ����ģʽ
//<6=>16λ�����ʱ��
//<7=>16λ�����������
#define ECBM_PCA0_MODE 1
//<q.5>�������ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ�������ʱ�жϡ�
//<q.4>�½����ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ��½���ʱ�жϡ�
#define ECBM_PCA0_UP_DOWN 0x00
//<q>�Զ���װ��ʱֵʹ��
//<i>��PCA�����ڶ�ʱ��ģʽ���߸����������ģʽʱ��ʹ�ܸù��ܿ������ж����Զ���װ��ʱ����
//<i>������Ϊÿ�εĶ�ʱֵ����Ҫ��us��ʱ��ȥ���㣬�����ʱ��ʱ��̫�̣��жϾͻῨס��Ȼ��Ƭ��������
#define ECBM_PCA0_TIMER_AUTO_EN 0
//<q>PCA0ģ���жϻص�����
#define ECBM_PCA0_CALLBACK_EN 0
//</e>

//<e>PCA1
//<i>����ͨ��1��ʹ��
#define ECBM_PCA1_EN 0
//<o>����ģʽ
//<0=>�޹���
//<1=>6λPWMģʽ
//<2=>7λPWMģʽ
//<3=>8λPWMģʽ
//<4=>10λPWMģʽ
//<5=>16λ����ģʽ
//<6=>16λ�����ʱ��
//<7=>16λ�����������
#define ECBM_PCA1_MODE 4
//<q.5>�������ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ�������ʱ�жϡ�
//<q.4>�½����ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ��½���ʱ�жϡ�
#define ECBM_PCA1_UP_DOWN 0x00
//<q>�Զ���װ��ʱֵʹ��
//<i>��PCA�����ڶ�ʱ��ģʽ���߸����������ģʽʱ��ʹ�ܸù��ܿ������ж����Զ���װ��ʱ����
//<i>������Ϊÿ�εĶ�ʱֵ����Ҫ��us��ʱ��ȥ���㣬�����ʱ��ʱ��̫�̣��жϾͻῨס��Ȼ��Ƭ��������
#define ECBM_PCA1_TIMER_AUTO_EN 1
//<q>PCA1ģ���жϻص�����
#define ECBM_PCA1_CALLBACK_EN 0
//</e>

//<e>PCA2
//<i>����ͨ��2��ʹ��
#define ECBM_PCA2_EN 0
//<o>����ģʽ
//<0=>�޹���
//<1=>6λPWMģʽ
//<2=>7λPWMģʽ
//<3=>8λPWMģʽ
//<4=>10λPWMģʽ
//<5=>16λ����ģʽ
//<6=>16λ�����ʱ��
//<7=>16λ�����������
#define ECBM_PCA2_MODE 1
//<q.5>�������ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ�������ʱ�жϡ�
//<q.4>�½����ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ��½���ʱ�жϡ�
#define ECBM_PCA2_UP_DOWN 0x00
//<q>�Զ���װ��ʱֵʹ��
//<i>��PCA�����ڶ�ʱ��ģʽ���߸����������ģʽʱ��ʹ�ܸù��ܿ������ж����Զ���װ��ʱ����
//<i>������Ϊÿ�εĶ�ʱֵ����Ҫ��us��ʱ��ȥ���㣬�����ʱ��ʱ��̫�̣��жϾͻῨס��Ȼ��Ƭ��������
#define ECBM_PCA2_TIMER_AUTO_EN 0
//<q>PCA2ģ���жϻص�����
#define ECBM_PCA2_CALLBACK_EN 0
//</e>

//<e>PCA3
//<i>����ͨ��3��ʹ��
#define ECBM_PCA3_EN 0
//<o>����ģʽ
//<0=>�޹���
//<1=>6λPWMģʽ
//<2=>7λPWMģʽ
//<3=>8λPWMģʽ
//<4=>10λPWMģʽ
//<5=>16λ����ģʽ
//<6=>16λ�����ʱ��
//<7=>16λ�����������
#define ECBM_PCA3_MODE 3
//<q.5>�������ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ�������ʱ�жϡ�
//<q.4>�½����ж�/����
//<i>�ڲ���ģʽ�£���ѡ��ѡ��������յ��ⲿ�źŵ��½���ʱ�жϡ�
#define ECBM_PCA3_UP_DOWN 0x00
//<q>�Զ���װ��ʱֵʹ��
//<i>��PCA�����ڶ�ʱ��ģʽ���߸����������ģʽʱ��ʹ�ܸù��ܿ������ж����Զ���װ��ʱ����
//<i>������Ϊÿ�εĶ�ʱֵ����Ҫ��us��ʱ��ȥ���㣬�����ʱ��ʱ��̫�̣��жϾͻῨס��Ȼ��Ƭ��������
#define ECBM_PCA3_TIMER_AUTO_EN 0
//<q>PCA3ģ���жϻص�����
#define ECBM_PCA3_CALLBACK_EN 0
//</e>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define PCA_ECOMn_1 0x40
#define PCA_ECOMn_0 0xBF

#define PCA_CAPPn_1 0x20
#define PCA_CAPPn_0 0xDF

#define PCA_CAPNn_1 0x10
#define PCA_CAPNn_0 0xEF

#define PCA_MATn_1  0x08
#define PCA_MATn_0  0xF7

#define PCA_TOGn_1  0x04
#define PCA_TOGn_0  0xFB

#define PCA_PWMn_1  0x02
#define PCA_PWMn_0  0xFD

#define PCA_ECCFn_1 0x01
#define PCA_ECCFn_0 0xFE

#define PCA_PIN_P12_P17_P16_P15_P14  0x00
#define PCA_PIN_P22_P23_P24_P25_P26  0x10
#define PCA_PIN_P74_P70_P71_P72_P73  0x20
#define PCA_PIN_P35_P33_P32_P31_P30  0x30

#define PCA_PIN_P12_P11_P10_P37  0x00
#define PCA_PIN_P34_P35_P36_P37  0x10
#define PCA_PIN_P24_P25_P26_P27  0x20

#define PCA_PIN_P55_P32_P33_P54  0x00
#define PCA_PIN_P55_P31_P33_P54  0x10
#define PCA_PIN_P31_P32_P33_P55  0x20

#define PCA_PIN_P13_P11_P10_P37  0x00
#define PCA_PIN_P34_P35_P36_P37  0x10
#define PCA_PIN_P54_P13_P14_P15  0x20
/*--------------------------------------��������-----------------------------------*/
extern u8  pca_mode_0;
extern u8  pca_mode_1;
extern u8  pca_mode_2;
extern u8  pca_mode_3;

extern u16 pca_timer_count_0;
extern u16 pca_timer_count_1;
extern u16 pca_timer_count_2;
extern u16 pca_timer_count_3;

extern u16 pca_timer_add_0;
extern u16 pca_timer_add_1;
extern u16 pca_timer_add_2;
extern u16 pca_timer_add_3;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������pca_init
��  ����PCA��ʼ���ú�������Ҫ��ͼ�λ��������úù���ģʽ��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_init(void);
/*-------------------------------------------------------
��������pca_set_io
��  ����PCA����IOӳ�亯������Ӧ��������ͼ�λ�������Կ��õ���
��  �룺io  -  ��������PCA_PIN_P1��PCA_PIN_P2��PCA_PIN_P7��PCA_PIN_P3��
		       ��Ӧ��ϵ��ͼ�λ�������Կ��õ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-14
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_set_io(u8 io);
/*-------------------------------------------------------
��������pca_set_mode
��  ����PCA��PWMģʽ�µ�ռ�ձ����ú�����ʹ�ñ�����ǰȷ�ϸ�ͨ���Ĺ���ģʽ��PWMģʽ��
��  �룺id   -  Ҫ����ռ�ձȵ�ͨ���ţ�������0~3����ӦCCP0~CCP3��
		mode -  Ҫ���õĹ���ģʽ��������0~7����Ӧ�Ĺ��ܼ��±�
		<0>�޹���
		<1>6λPWMģʽ
		<2>7λPWMģʽ
		<3>8λPWMģʽ
		<4>10λPWMģʽ
		<5>16λ����ģʽ
		<6>16λ�����ʱ��
		<7>16λ�����������
��  ������
����ֵ����
�����ߣ�����
�������̣�pca_set_mode(0,2);//����CCP0���7λPWM����
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_set_mode(u8 id,u8 mode);
/*-------------------------------------------------------
��������pca_set_timer
��  ����PCA�ڶ�ʱ��ģʽ������������ģʽ�µļ���ֵ���ú�����
		ʹ�ñ�����ǰȷ�ϸ�ͨ���Ĺ���ģʽ�Ƕ�ʱ��ģʽ������������ģʽ��
��  �룺id    -  Ҫ���ü���ֵ��ͨ���ţ�������0~3����ӦCCP0~CCP3��
		count -  Ҫ���õļ���ֵ���ɸ���PCA��ʱ�Ӻ�Ŀ�궨ʱʱ�����������ֵ��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_set_timer(u8 id,u16 count);
/*-------------------------------------------------------
��������pca_set_duty
��  ����PCA��PWMģʽ�µ�ռ�ձ����ú�����ʹ�ñ�����ǰȷ�ϸ�ͨ���Ĺ���ģʽ��PWMģʽ��
��  �룺id   -  Ҫ����ռ�ձȵ�ͨ���ţ�������0~3����ӦCCP0~CCP3��
		duty -  Ҫ���õ�ռ�ձȣ�������0~1000����Ӧ0%~100.0%�����Ǿ��Ⱥ�PWMλ���йء�
��  ������
����ֵ����
�����ߣ�����
�������̣�pca_set_duty(0,543);//����CCP0���PWM����ռ�ձ�Ϊ54.3%��
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_set_duty(u8 id,u16 duty);
/*-------------------------------------------------------
��������pca_timer_callback
��  ����PCA����������ص����������ڼ�������65535�����0��ʱ�򴥷��ġ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca_timer_callback(void);
/*-------------------------------------------------------
��������pca0_callback
��  ����PCAģ��0�жϻص�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca0_callback(void);
/*-------------------------------------------------------
��������pca1_callback
��  ����PCAģ��1�жϻص�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca1_callback(void);
/*-------------------------------------------------------
��������pca2_callback
��  ����PCAģ��2�жϻص�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca2_callback(void);
/*-------------------------------------------------------
��������pca3_callback
��  ����PCAģ��3�жϻص�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-07-13
�޸ļ�¼��
-------------------------------------------------------*/
extern void pca3_callback(void);
#endif
