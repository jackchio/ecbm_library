#ifndef _ECBM_KEY_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_KEY_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//------------------------------------------------------------------------------
#define key_u8 unsigned char
//------------------------------------------------------------------------------
#define KEY_EVENT_DOWN         0x01//�����¼�
#define KEY_EVENT_ONE          0x02//�����¼�
#define KEY_EVENT_HOLD         0x04//�����¼�
#define KEY_EVENT_DOUBLE       0x08//˫���¼�

#define KEY_EVENT_LEVEL_DOWN   0x10//��ƽ���¼�����Ե�ƽ��
#define KEY_EVENT_LEVEL_UP     0x20//��ƽ���¼�����Ե�ƽ��
#define KEY_EVENT_EDGE_DOWN    0x40//��ƽ�½��¼�����Ե�ƽ��
#define KEY_EVENT_EDGE_UP      0x80//��ƽ�����¼�����Ե�ƽ��

#define KEY_EVENT_HOLD_LOCK    0x01//��������
#define KEY_EVENT_DOUBLE1_LOCK 0x02//˫��1����
#define KEY_EVENT_DOUBLE2_LOCK 0x04//˫��2����
//------------------------------------------------------------------------------
typedef struct{
    key_u8 key_val;       //���εİ���ֵ
    key_u8 key_old_val;   //�ϴεİ���ֵ
    key_u8 key_up;        //̧��ļ�ֵ
    key_u8 key_down;      //���µļ�ֵ
    key_u8 key_up_count;  //̧��ļ�ʱ
    key_u8 key_down_count;//���µļ�ʱ
    key_u8 key_min_time;  //��С�ж�ʱ��
    key_u8 key_max_time;  //����ж�ʱ��
    key_u8 key_event;     //�����¼�
    key_u8 key_lock;      //��������ֵ��
}key_def;
/*------------------------------------------------------------------------------
��������key_init
��  ����������ʼ������
��  �룺
    dev         Ҫ��ʼ��������
    up_val      ����̧��ʱ�ļ�ֵ
    down_val    ��������ʱ�ļ�ֵ
    min_time    ������С�ж�ʱ�䣨��˫���йأ�
    max_time    ��������ж�ʱ�䣨�ͳ����йأ�
��  ����
    dev         ��ʼ��֮�������
����ֵ����
�����ˣ�����
�������ڣ�2020-06-28
�������ڣ�
�汾��ʷ��
------------------------------------------------------------------------------*/
extern void key_init(key_def * dev,key_u8 up_val,key_u8 down_val,key_u8 min_time,key_u8 max_time);
/*------------------------------------------------------------------------------
��������key_deal
��  ��������������
��  �룺
    dev     Ҫ����İ���
    val     �����ļ�ֵ
��  ����
    dev     ������״̬
����ֵ����
�����ˣ�����
�������ڣ�2020-06-28
�������ڣ�
�汾��ʷ��
------------------------------------------------------------------------------*/
extern void key_deal(key_def * dev,key_u8 val);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��