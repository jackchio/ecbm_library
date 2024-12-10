#ifndef _ECBM_EDS_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_EDS_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<o>��ȡУ��ͳ����Ĵ���ʽ
//<i>����ȡ��ʱ�����У��ʹ��󣬿���ѡ���Լ���������Զ��ع���
//<i>Ϊ�˷�ֹ��ֹ���Ļع�������ѭ�����ع��������Ϊ5�Σ�5��֮���Ǵ���Ļ���Ҳ������Ҫ�Լ�����
//<i>ͨ��������ϵ������д�����ֻ��Ҫ�ع�һ�ξͿ����ˡ������ĳ���5�ζ�����������������Ӳ���ϵķ������߼��ҵ������Ƿ��и�дEDS������������䡣
//<1=>���д���
//<5=>�ع�����
#define EDS_ERROR_SUM_HANDLING (5)
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define EDS_OK          (0)   //EDS����������
#define EDS_ERR_NULL    (1)   //�Ҳ���EDS��ʶ��˵��������û����EDS�Ĺ����С�
#define EDS_ERR_ID      (2)   //EDS�е�ID����˵���õ�ַ���ܲ���EDS�������������
#define EDS_ERR_SECTOR  (3)   //EDS��ʼ��ʱ����û���öԡ�

#define EDS_ERR_SUM     (4)   //EDS����У��ʹ���
#define EDS_ERR_DATA    (5)   //EDS���ݴ��� 

#define EDS_WAR_DATA    (6)   //EDS���ݾ��棬�����ݿ��ܲ������µġ�

#define EDS_DATA_VOID   (7)   //EDS��û�����ݡ�
#define EDS_DATA_EXISTS (8)   //EDS�����Ѵ��ڣ���������д�������
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������eds_init
��  ����eds��ʼ��������
��  �룺
    sector_start    ��ʼ������
    sector_szie     ��������/�ܴ�С��
    pack_len        ���ݰ���С��
��  ������
����ֵ��
    EDS_OK          EDS���ж�������
    EDS_ERR_SECTOR  EDS��ʼ��ʱ����û���öԡ�
    EDS_DATA_VOID   EDS��û�����ݡ�
�����ߣ�����
�������̣���
�������ڣ�2022-04-21
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 eds_init(u8 sector_start,u8 sector_szie,u16 pack_len);
/*-------------------------------------------------------
��������eds_write
��  ����edsд������
��  �룺
    sector_start    ��ʼ������
    buf             Ҫд������ݰ���
��  ������
����ֵ��
    EDS_OK          EDS���ж�������
    EDS_ERR_NULL    �Ҳ���EDS��
    EDS_ERR_ID      EDS�е�ID����
    EDS_DATA_VOID   EDS��û�����ݡ�
�����ߣ�����
�������̣���
�������ڣ�2022-04-21
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 eds_write(u8 sector_start,u8 * buf);
/*-------------------------------------------------------
��������eds_read
��  ����eds��������
��  �룺
    sector_start    ��ʼ������
��  ����
    buf             ��ȡ�������ݰ���
����ֵ��
    EDS_OK          EDS���ж�������
    EDS_ERR_NULL    �Ҳ���EDS��
    EDS_ERR_ID      EDS�е�ID����
    EDS_DATA_VOID   EDS��û�����ݡ�
�����ߣ�����
�������̣���
�������ڣ�2022-04-21
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 eds_read(u8 sector_start,u8 * buf);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��