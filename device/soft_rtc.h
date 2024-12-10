#ifndef _ECBM_SOFT_RTC_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_SOFT_RTC_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2024 ����

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
//<q>SOFT-RTC���к���ʹ��
//<i>���ڶ�ʱ����Դ���Ż���������RTC����Ŀ���ԣ����Թص���RTC�����к�����ֻʹ�����ú�����
//<i>���ʹ�������к�������Ҫ��һ��ÿ��1��ִ��һ�εĺ�������һ�����жϺ�����ֻҪִ�м������1����У��ڵ���soft_rtc_run������
//<i>�����ʹ�����к���������Ҫ���о���Ӧ��ʹ��ʲô��������ʱ�䡣
#define SOFT_RTC_RUN_EN  (1)
//<e>SOFT-RTCʱ����º���ʹ��
//<i>��ͬ����Ŀ���в�ͬ�ĸ���ʱ��ķ�ʽ�����簴���ֶ������ʹ������������
//<i>�����ᵽ��ʱ����º������ǻ���STC-ISP��λ����ʱ��У׼�������Ĵ��ڽ��մ�������
//<i>�������㲻��Ҫ���ڸ���ʱ�书�ܣ��Ϳ��Թر������������Լ�ռ䡣
#define SOFT_RTC_UPDATE_EN  (1)
//<s>����ͷ
//<i>��STC-ISP�У����������ڷ���Уʱ����֮ǰ�ȷ���һ���Զ��������ͷ��������HEXҲ�������ַ�����
//<i>����Ϊ���ó�����õ�ʶ�𣬷�ֹһЩ�󴥷����ڱ����У���Ҫ��ʹ���ַ�����������ͷ��
#define SOFT_RTC_UPDATE_STRING  "SOFT-RTC"
//</e>
//<q>SOFT-RTCʱ�����ú���ʹ��
//<i>��ͬ����Ŀ���в�ͬ�ĸ���ʱ��ķ�ʽ�����簴���ֶ������ʹ������������
//<i>�����ᵽ�����ú����ǿɹ��û����õ���������soft_rtc_set_date��soft_rtc_set_time��
//<i>����������Ҳû��ʲô�ر�ģ���������ֵ������Լ�������������·���1~12֮��ȡ�
//<i>��������ʱ��ȷ����100%��ȷ����������λ�����µ�ʱ�䣬��ô�Ϳ��Բ���������������
#define SOFT_RTC_SET_EN  (1)
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define SOFTRTC_OK       (0)//����OK
#define SOFTRTC_MON_ERR  (1)//�����ô���
#define SOFTRTC_DAY_ERR  (2)//�����ô���
#define SOFTRTC_WEEK_ERR (3)//�������ô���
#define SOFTRTC_HOUR_ERR (4)//Сʱ���ô���
#define SOFTRTC_MIN_ERR  (5)//�������ô���
#define SOFTRTC_SEC_ERR  (6)//�������ô���
/*--------------------------------------��������-----------------------------------*/
extern u16 soft_rtc_year;   //��
extern u8  soft_rtc_month;  //��
extern u8  soft_rtc_day;    //��
extern u8  soft_rtc_week;   //����
extern u8  soft_rtc_hour;   //ʱ
extern u8  soft_rtc_minute; //��
extern u8  soft_rtc_second; //��
/*--------------------------------------��������-----------------------------------*/
/*-------------------------------------------------------
��������soft_rtc_get_day_max
��  ������ȡ�������ֵ������
��  �룺��
��  ������
����ֵ��
    ��ǰ��ݺ͵�ǰ�·ݵ��������ֵ��
�����ߣ�����
�������̣���
�������ڣ�2021-8-31
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_rtc_get_day_max(u16 year,u8 month);
/*-------------------------------------------------------
��������soft_rtc_run
��  �������к�����ÿһ������һ�μ��ɡ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2021-8-31
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_rtc_run(void);
/*-------------------------------------------------------
��������soft_rtc_set_date
��  �����������ں�����
��  �룺
    year    ���
    month   �·�
    day     ����
��  ������
����ֵ��
    SOFTRTC_OK          ������ȷ
    SOFTRTC_MON_ERR     �·����ô���
    SOFTRTC_DAY_ERR     �������ô���
    SOFTRTC_WEEK_ERR    �������ô���
�����ߣ�����
�������̣���
�������ڣ�2021-8-31
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_rtc_set_date(u16 year,u8 month,u8 day,u8 week);
/*-------------------------------------------------------
��������soft_rtc_set_time
��  ��������ʱ�亯����
��  �룺
    hour    ʱ
    minute  ��
    second  ��
��  ������
����ֵ��
    SOFTRTC_OK          ������ȷ
    SOFTRTC_HOUR_ERR    ʱ���ô���
    SOFTRTC_MIN_ERR     �����ô���
    SOFTRTC_SEC_ERR     �����ô���
�����ߣ�����
�������̣���
�������ڣ�2021-8-31
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_rtc_set_time(u8 hour,u8 minute,u8 second);
/*-------------------------------------------------------
��������soft_rtc_update
��  ��������ʱ�亯���������������봮���жϻص��С�
��  �룺
    dat     ���ڽ��յ������ݡ�
��  ������
����ֵ��
    0   û�и������ݡ�
    1   �и������ݡ�
�����ߣ�����
�������̣���
�������ڣ�2024-09-13
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_rtc_update(u8 dat);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��