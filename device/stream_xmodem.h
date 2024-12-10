#ifndef _ECBM_STREAM_XMODEM_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_STREAM_XMODEM_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��ԴҪ��-----------------------------------*/
#if (ECBM_STREAM_SZIE<=132)
#   error STREAM�Ļ���̫С�ˣ�Ҫʹ��X-modem���޸ĵ�132���ϡ�
#endif
/*---------------------------------------�궨��------------------------------------*/
/*------------------״̬����----------------*/
#define ES_XMODEM_STOP          (0)//ֹͣ״̬��ES_XMODEM�����������
#define ES_XMODEM_READY         (1)//����״̬���ȴ���λ������SOH��
#define ES_XMODEM_READ_PACK     (2)//��ȡ����š�
#define ES_XMODEM_CHECK_PACK    (3)//ȷ�ϰ���š�
#define ES_XMODEM_READ_MODE     (4)//������ģʽ��
#define ES_XMODEM_ERROR         (5)//����״̬��ֻ�ܵȴ���ʱ�˳���
#define ES_XMODEM_CHECK_DATA    (6)//���У��͡�
/*-----------------ASCII����---------------*/
#define ES_XMODEM_SOH   (0x01)
#define ES_XMODEM_EOT   (0x04)
#define ES_XMODEM_ACK   (0x06)
#define ES_XMODEM_NAK   (0x15)
#define ES_XMODEM_CAN   (0x18)
/*--------------------------------------��������-----------------------------------*/
extern u8 es_xmodem_buf_start[];//xmodem�������ڻ����еĿ�ʼλ�á�
extern u8 es_xmodem_sum;      //У��͡�
extern u8 es_xmodem_pack;     //���ݰ���š�
extern u8 es_xmodem_status;   //Xmodem״̬��״̬��
extern u8 es_xmodem_count;    //�������ݼ�����
/*--------------------------------------������-----------------------------------*/
/*------------------��Ҫ�û�����ĺ���------------------*/
/*-------------------------------------------------------
��������es_xmodem_write_reg
��  ����xmodem�������뺯������������Ὣ���ܵ�����д�뵽��Ƭ����ĳ����
��  �룺
    pack    ����ţ�����xmodem�߱��ط����ܣ���Ҫͨ����������ж��������ݻ����ط������ݡ�
    offset  ��������ƫ�ƣ�xmodemһ������128�ֽڡ����Ը�ֵ�����0�ӵ�127��
    buf     ��ǰƫ�ƶ�Ӧ����ֵ��
��  ������
����ֵ����
�����ߣ�����
�ο����̣�
    void es_xmodem_write_reg(u8 pack,u8 offset,u8 buf){
        //������źͰ���ƫ�ƺϲ���һ����ַ�������ɰ����ݶԽ�д�뵽eeprom��
        eeprom_write((u16)(pack-1)*128+(u16)offset,buf);//����Ŵ�1��ʼ����ַ����ȴ��0��ʼ������Ҫ��һ��
    }
�������ڣ�2021-11-12
�޸ļ�¼��
2022-03-21:����Ϊes_xmodem_write_reg��
-------------------------------------------------------*/
extern void es_xmodem_write_reg(u8 pack,u8 offset,u8 buf);
/*-----------------------ϵͳ����-----------------------*/
/*-------------------------------------------------------
��������es_xmodem_start
��  ����xmodem��ʼ���պ��������ú��֪ͨ��λ����ʼ�������ݡ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2021-11-12
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_xmodem_start(void);
/*-------------------------------------------------------
��������es_xmodem_exe
��  ����xmodem����ִ�к������Ž�stream��������С�
��  �룺
    dat     ��stream��ܶԽӵĲ�����
��  ������
����ֵ����
�����ߣ�����
�ο����̣�
    void ecbm_stream_exe(u8 dat){
        es_xmodem_exe(dat);
    }
�������ڣ�2021-11-12
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_xmodem_exe(u8 dat);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��