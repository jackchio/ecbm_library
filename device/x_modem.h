#ifndef _X_MODEM_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _X_MODEM_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*---------------------------------------�궨��------------------------------------*/
#define	X_MODEM_STOP		0//ֹͣ״̬��X_MODEM�����������
#define	X_MODEM_READY		1//����״̬���ȴ���λ������SOH��
#define	X_MODEM_READ_PACK	2//��ȡ����š�
#define	X_MODEM_CHECK_PACK	3//ȷ�ϰ���š�
#define	X_MODEM_READ_MODE	4//������ģʽ��
#define	X_MODEM_ERROR		5//����״̬��ֻ�ܵȴ���ʱ�˳���
#define	X_MODEM_CHECK_DATA	6//���У��͡�
#define	X_MODEM_DOING		7//���״̬��������ȷ������һ������
#define	X_MODEM_AGAIN		8//�ط�״̬��˵�������������ˡ�
#define	X_MODEM_FINISH		9//����״̬��˵���Ѿ���������ˡ�
/*--------------------------------------��������-----------------------------------*/
extern	u8 x_modem_data[128];//�������ݻ��档
extern	u8 x_modem_sum		;//У��͡�
extern	u8 x_modem_pack		;//���ݰ���š�
extern	u8 x_modem_status	;//Xmodem״̬��״̬��
extern	u8 x_modem_count	;//�������ݼ�����
extern	u8 x_modem_timer_count;//��ʱ������
extern	u8 x_modem_timer_max;//��ʱ���ֵ��
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������x_modem_do
��  ����ִ֡�к�����ÿ����һ������֡��ִ��һ�Ρ��ú�����Ҫ�Լ���д��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_do(void);
/*-------------------------------------------------------
��������x_modem_done
��  ����ִ֡����Ϻ���������������֡��������ʱ��ִ�С��ú�����Ҫ�Լ���д��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_done(void);
/*-------------------------------------------------------
��������x_modem_send
��  �������ݷ��ͺ��������ڷ��ؽ���״̬��֪ͨ���俪�����ú�����Ҫ�Լ���д��
��  �룺Ҫ���͵����ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_send(u8 dat);
/*-------------------------------------------------------
��������x_modem_receive
��  �������ݽ��պ��������ڴ����ж���ִ�С�
��  �룺���յ������ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_receive(u8 x_modem_buf);
/*-------------------------------------------------------
��������x_modem_run
��  �������ݴ�������������ѭ����ִ�С�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_run(void);
/*-------------------------------------------------------
��������x_modem_start
��  �������俪ʼ���������ڿ���һ��xmodem���䡣
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_start(void);
/*-------------------------------------------------------
��������x_modem_timer
��  ������ʱ�����������ж�ͨ���Ƿ�ʱ�����ڶ�ʱ���ж����С�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_timer(void);
/*-------------------------------------------------------
��������x_modem_init
��  ������ʼ��������
��  �룺��ʱʱ�䡣
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-12-30
�޸ļ�¼��
-------------------------------------------------------*/
void x_modem_init(u8 max);
#endif //���������#ifndef��ϳ�һ������Ρ�
       //��һ������Ϊ��β��