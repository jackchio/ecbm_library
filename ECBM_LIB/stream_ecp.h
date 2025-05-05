#ifndef _ECBM_STREAM_ECP_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_STREAM_ECP_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
/*------------------------------------״̬���궨��---------------------------------*/
#define ES_ECP_READY             (0)   //��֡ͷ��
#define ES_ECP_GET_DATA_LEN      (1)   //��ȡ���ݳ��ȡ�
#define ES_ECP_CHECK_DATA_LEN    (2)   //������ݳ��ȡ�
#define ES_ECP_GET_TARGET_ID     (3)   //��ȡĿ��ID��
#define ES_ECP_GET_SOURCE_ID     (4)   //��ȡԴͷID��
#define ES_ECP_GET_OPERATION     (5)   //��ȡ�����롣
#define ES_ECP_GET_ADDR_31_24    (6)   //��ȡ��ַ31~24��
#define ES_ECP_GET_ADDR_23_16    (7)   //��ȡ��ַ23~16��
#define ES_ECP_GET_ADDR_15_8     (8)   //��ȡ��ַ15~8��
#define ES_ECP_GET_ADDR_7_0      (9)   //��ȡ��ַ7~0��
#define ES_ECP_GET_DATA          (10)  //��ȡ���ݡ�
#define ES_ECP_GET_CRC_H         (11)  //��ȡCRC��λ��
#define ES_ECP_GET_CRC_L         (12)  //��ȡCRC��λ��
#define ES_ECP_END               (13)  //��֡β��
/*-------------------------------------ָ��궨��----------------------------------*/
#define ES_ECP_CMD_TRIG             (0)//������
#define ES_ECP_CMD_TRIG_REPLY       (1)//�����ظ���
#define ES_ECP_CMD_READ             (2)//��ȡ��
#define ES_ECP_CMD_READ_REPLY       (3)//��ȡ�ظ���
#define ES_ECP_CMD_WRITE            (4)//д�롣
#define ES_ECP_CMD_WRITE_REPLY      (5)//д��ظ���
#define ES_ECP_CMD_SET_BIT          (6)//��λ��
#define ES_ECP_CMD_SET_BIT_REPLY    (7)//��λ�ظ���
#define ES_ECP_CMD_RESET_BIT        (8)//��λλ��
#define ES_ECP_CMD_RESET_BIT_REPLY  (9)//��λ�ظ���

#define ES_ECP_CMD_AUTO_UPDATA      (200)//�Զ��Ϸ���
#define ES_ECP_CMD_ERROR_OPERATE    (254)//��������
#define ES_ECP_CMD_ERROR_CRC        (255)//CRC����
/*--------------------------------------��������-----------------------------------*/
#if (ECBM_STREAM_ECP_CH_COUNT)//��ֹ�궨��ֵΪ0ʱ������Ķ��屨��
    extern u8  es_ecp_status_gu8a   [ECBM_STREAM_ECP_CH_COUNT]; //״̬��������
    extern u8  es_ecp_data_len_gu8a [ECBM_STREAM_ECP_CH_COUNT]; //���ڴ�Ų��������ݵĳ��ȡ�
    extern u8  es_ecp_count_gu8a    [ECBM_STREAM_ECP_CH_COUNT]; //����ͳ��ʵ�ʽ��յĲ��������ݳ��ȡ�
    extern u8  es_ecp_source_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //ԴͷID�������֡�����ID������������
    extern u8  es_ecp_target_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //Ŀ��ID�������֡Ӧ�������ID���������ա�
    extern u8  es_ecp_operation_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //�����뻺�档
    extern u16 es_ecp_addr16_ex_gu16a[ECBM_STREAM_ECP_CH_COUNT];//16λ��չ��ַ���档
    extern u16 es_ecp_addr16_gu16a [ECBM_STREAM_ECP_CH_COUNT];  //16λ��ַ���档
    extern u16 es_ecp_crc_gu16a    [ECBM_STREAM_ECP_CH_COUNT];  //���ڼ���������ݵ�CRC��
    extern u16 es_ecp_crc_buf_gu16a[ECBM_STREAM_ECP_CH_COUNT];  //���ڴ������֡���CRC��
    extern u8  es_ecp_data_buf_gu8a[ECBM_STREAM_ECP_CH_COUNT][ES_ECP_DATA_BUF_MAX];//���ڶ�д�����Ļ��档
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������es_ecp_reset
��  ����ecp���ú�������ecp����Ĳ���ȫ�����á�
��  �룺
    ch  ���õ�ͨ����
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2023-10-14
�޸ļ�¼��
-------------------------------------------------------*/
void es_ecp_reset(u8 ch);
/*------------------��Ҫ�û�����ĺ���------------------*/
/*-------------------------------------------------------
��������es_ecp_get_id
��  ������ȡ������ID������
��  �룺��
��  ������
����ֵ��
    ���豸��ID��
�����ߣ�����
�ο����̣�
    u8 es_ecp_get_id(void){
        return 1;
    }
�������ڣ�2022-05-27
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 es_ecp_get_id(u8 ch);
/*-------------------------------------------------------
��������es_ecp_trig
��  ����ECP�Ĵ���������
��  �룺
    addr    �����ĵ�ַ��
��  ������  
����ֵ��
    0       ����ִ�С�
    1       ��ַ���󡣣�����õ�ַ�ǽ��շ�û����ƶ����ġ���
�����ߣ�����
�ο����̣�
    u8 es_ecp_trig(u16 addr){
        if(addr==0){
            LED_OFF;
        }else if(addr==1){
            LED_ON;
        }else{
            return 1;
        }
        return 0;
    }
�������ڣ�2022-08-11
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 es_ecp_trig(u8 ch,u16 addr);
/*-------------------------------------------------------
��������es_ecp_write
��  ����ECP��д�뺯����
��  �룺
    addr    д��ĵ�ַ��
    buf     д�����ݵĻ��档
    len     д�����������
��  ������  
����ֵ��
    0       ����ִ�С�
    1       ��ַ���󡣣�����õ�ַû��ӳ�䵽�κμĴ����ϡ���
    2       ���ݴ��󡣣�����õ�ַ��Ӧ�ļĴ�������Ҫĳ�������ֵ���������������ݲ���������䡣��
    3       ���ȴ��󡣣�����õ�ַ��Ӧ��һ��16λ�Ĵ��������һ���Ҫͬʱд�������ֽڵ����ݣ�������ֻ����һ���ֽڡ���
�����ߣ�����
�ο����̣�
    u8 es_ecp_write(u16 addr,u8 * buf,u8 len){
        u8 i;
        for(i=0;i<len;i++){
            es_ecp_test[i]=buf[i];
        }
        return 0;
    }
�������ڣ�2022-05-27
�޸ļ�¼��
2022-08-11������״̬���ء�
-------------------------------------------------------*/
extern u8 es_ecp_write(u8 ch,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
��������es_ecp_read
��  ����ECP�Ķ�ȡ������
��  �룺
    addr    ��ȡ�ĵ�ַ��
    buf     ��ȡ���ݵĻ��档
    len     ��ȡ����������
��  ������  
����ֵ��
    0       ����ִ�С�
    1       ��ַ���󡣣�����õ�ַû��ӳ�䵽�κμĴ����ϡ���
    2       ���ݴ��󡣣�����õ�ַ��Ӧ�ļĴ�����ǰ״̬���ǽ�ֹ��ȡ�ġ���
    3       ���ȴ��󡣣�����õ�ַ��Ӧ��һ��16λ�Ĵ���������ȴҪ�������ֽڣ��Ӷ������������
�����ߣ�����
�ο����̣�
    u8 es_ecp_read(u16 addr,u8 * buf,u8 len){
        u8 i;
        for(i=0;i<len;i++){
            buf[i]=es_ecp_test[i];
        }
        return 0;
    }
�������ڣ�2022-05-27
�޸ļ�¼��
2022-08-11������״̬���ء�
-------------------------------------------------------*/
extern u8 es_ecp_read(u8 ch,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
��������es_ecp_read_callback
��  ����ECP�Ķ�ȡ�ص�����������Ϊ�������Ͷ�ȡָ��֮���յ��ӻ��������ݵ�ʱ��ִ�б�������
��  �룺
    addr    ��ȡ�ĵ�ַ��
    buf     ��ȡ���ݵĻ��档
    len     ��ȡ����������
��  ������  
����ֵ����
�����ߣ�����
�ο����̣�
    void es_ecp_read_callback(u16 addr,u8 * buf,u8 len){
        if(addr==0x0000){
            oled_show(0,0,"%s",buf);
        }
    }
�������ڣ�2022-05-30
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_read_callback(u8 ch,u16 addr,u8 * buf,u8 len);
/*----------------------ϵͳ����-----------------------*/
/*-------------------------------------------------------
��������es_ecp_reply
��  ����ECP�ظ���������
��  �룺
    len     �ظ��ĳ��ȡ�
    cmd     �ظ���ָ��š�
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-08-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_reply(u8 ch,u8 len,u8 cmd);
/*-------------------------------------------------------
��������es_ecp_cmd00
��  ����00ָ�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-08-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_cmd00(u8 ch);
/*-------------------------------------------------------
��������es_ecp_cmd02
��  ����02ָ�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-05-27
�޸ļ�¼��
2022-08-11����д���ڲ��߼���
-------------------------------------------------------*/
extern void es_ecp_cmd02(u8 ch);
/*-------------------------------------------------------
��������es_ecp_cmd04
��  ����04ָ�������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-05-27
�޸ļ�¼��
2022-08-11����д���ڲ��߼���
-------------------------------------------------------*/
extern void es_ecp_cmd04(u8 ch);
/*-------------------------------------------------------
��������es_ecp_cmd0608
��  ����06��08ָ�������
��  �룺
    cmd     ����Ĳ�������
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-08-11
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_cmd0608(u8 ch,u8 cmd);
/*-------------------------------------------------------
��������es_ecp_master_write
��  ����ECP����д��������һ���ӻ�д��һ�����ݡ�
��  �룺
    id      �ӻ���ID��
    addr    Ҫд����׵�ַ��
    buf     Ҫд������ݡ�
    len     Ҫд�����ݵĳ��ȡ�
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-05-30
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_master_write(u8 ch,u8 id,u16 addr,u8 * buf,u8 len);
/*-------------------------------------------------------
��������es_ecp_master_read
��  ����ECP��������������һ���ӻ����Ͷ����������յ��ӻ�������ʱ����ûص�������
��  �룺
    id      �ӻ���ID��
    addr    Ҫ��ȡ���׵�ַ��
    len     Ҫ��ȡ���ݵĳ��ȡ�
��  ������
����ֵ����
�����ߣ�����
�ο����̣���
�������ڣ�2022-05-30
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_master_read(u8 ch,u8 id,u16 addr,u8 len);
/*-------------------------------------------------------
��������es_ecp_exe
��  ����ECP����ִ�к������Ž�stream��������С�
��  �룺
    dat     ��stream��ܶԽӵĲ�����
��  ������
����ֵ����
�����ߣ�����
�ο����̣�
    void ecbm_stream_exe(u8 dat){
        es_ecp_exe(dat);
    }
�������ڣ�2022-05-27
�޸ļ�¼��
-------------------------------------------------------*/
extern void es_ecp_exe(u8 ch,u8 dat);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��