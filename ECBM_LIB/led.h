#ifndef _ECBM_LED_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_LED_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<h>COMʹ��
//<q.0>COM0
//<q.1>COM1
//<q.2>COM2
//<q.3>COM3
//<q.4>COM4
//<q.5>COM5
//<q.6>COM6
//<q.7>COM7
#define ECBM_LED_COM_EN (0x00)
//</h>
//<h>SEGʹ��
//<q.0>SEG0
//<q.1>SEG1
//<q.2>SEG2
//<q.3>SEG3
//<q.4>SEG4
//<q.5>SEG5
//<q.6>SEG6
//<q.7>SEG7
#define ECBM_LED_SEGL_EN (0x00)
//<q.0>SEG8
//<q.1>SEG9
//<q.2>SEG10
//<q.3>SEG11
//<q.4>SEG12
//<q.5>SEG13
//<q.6>SEG14
//<q.7>SEG15
#define ECBM_LED_SEGH_EN (0x00)
//</h>
//<o.4..5>LED����ģʽ
//<0=>����ģʽ
//<1=>����ģʽ
//<2=>����/����ģʽ
//<o.0..2>LED���ȵ���
//<0=>100%
//<1=>87.5%
//<2=>75%
//<3=>62.5%
//<4=>50%
//<5=>37.5%
//<6=>25%
//<7=>12.5%
#define ECBM_LED_CTRL (0x00)
//<o>LEDʱ�ӷ���
//<0-255>
#define ECBM_LED_CLK_DIV (1)
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define LED_MODE_DC     (0x00)
#define LED_MODE_DA     (0x10)
#define LED_MODE_DCA    (0x20)

#define LED_DUTY_8_8    (0x00)
#define LED_DUTY_7_8    (0x01)
#define LED_DUTY_6_8    (0x02)
#define LED_DUTY_5_8    (0x03)
#define LED_DUTY_4_8    (0x04)
#define LED_DUTY_3_8    (0x05)
#define LED_DUTY_2_8    (0x06)
#define LED_DUTY_1_8    (0x07)
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������led_init
��  ����LED�����ʼ��������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_init(void);
/*-------------------------------------------------------
��������led_start
��  ����LED��ʼ����������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_start(void);
/*-------------------------------------------------------
��������led_stop
��  ����LEDֹͣ����������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_stop(void);
/*-------------------------------------------------------
��������led_set_mode
��  ����LED�������ú�����
��  �룺
    mode    ��3�ֹ���ģʽ����궨��Ϊ��
                LED_MODE_DC     ����ģʽ
                LED_MODE_DA     ����ģʽ
                LED_MODE_DCA    ����/����ģʽ
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_set_mode(u8 mode);
/*-------------------------------------------------------
��������led_set_duty
��  ����LED�������ú�����
��  �룺
    duty    ��8�����ȣ���궨��Ϊ��
                LED_DUTY_8_8    100%����
                LED_DUTY_7_8    87.5%����
                LED_DUTY_6_8    75%����
                LED_DUTY_5_8    62.5%����
                LED_DUTY_4_8    50%����
                LED_DUTY_3_8    37.5%����
                LED_DUTY_2_8    25%����
                LED_DUTY_1_8    12.5%����
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_set_duty(u8 duty);
/*-------------------------------------------------------
��������led_set_freq
��  ����LED����Ƶ�ʺ�����
��  �룺
    freq    ������10~255����λΪHz���Ƽ���75Hz���ϡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2022-2-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void led_set_freq(u8 freq);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��