#ifndef _ECBM_STREAM_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_STREAM_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
#define ECBM_STREAM_VERSION "V2.0"
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>�������
//<o>����֡���ʱ��
//<10-2500:10>
//<i>��λmS��Ĭ�϶�ʱ��10mS�ж�һ��,������ʱ����10�ı�����
//<i>�ӽ��յ����һ�����ݿ�ʼ���㣬�������ʱ��û���ٴν��ܵ�����ʱ����Ϊ�Է��Ѿ�������һ������֡��
#define ECBM_STREAM_TIME_MS  (20)
#define ECBM_STREAM_TIME_MAX (ECBM_STREAM_TIME_MS/10)
//<o>���ڿ���ʱ��
//<10-2500:10>
//<i>��λmS��Ĭ�϶�ʱ��10mS�ж�һ��,������ʱ����10�ı�����
//<i>�ӽ��յ����һ�����ݿ�ʼ���㣬�������ʱ��û���ٴν��յ�����ʱ����Ϊ�Է��Ѿ�������ȫ�����ݣ����ڻָ�������״̬��
//<i>��ֵӦ�ñ�����֡���ʱ���
#define ECBM_STREAM_IDLE_MS  (80)
#define ECBM_STREAM_IDLE_MAX (ECBM_STREAM_IDLE_MS/10)
//</h>
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>ͨ������
//<e>ͨ��1ʹ��
//<i>ʹ��֮�󣬻��Զ�������1�����ݶԽӵ�ͨ��1��
#define ECBM_STREAM_CH1_EN (1)
//<o>���л����С
//<i>��λ���ֽڡ���
#define ECBM_STREAM_CH1_SZIE    (10)
//<q>�Զ���Э��
#define ECBM_STREAM_USER_CH1_EN  (0)
//<q>FUR���
//<i>����ECBM�����з��Ŀ���(Fast)����(Uart)���ʼĴ���(Reg)�����
//<i>����ASCII�������ͨ�ţ�Э��ͨ���׶����������Կ��ٶ�д�Ĵ��������ܶ���������㡣
#define ECBM_STREAM_FUR_CH1_EN  (0)
//<q>MODBUS���
//<i>ͨ�õ�MODBUSЭ��RTU�汾��Ŀǰ������[01H][05H][03H][06H][10H][02H][04H]��7��ָ�
//<i>������Ҳ�����ڶ�д�Ĵ����ġ�
#define ECBM_STREAM_MODBUS_CH1_EN (1)
//<q>ECP���
//<i>����ECBM�����з���ECBMͨ��(Communication)Э��(Protocol)�����
//<i>�����������Ը���������һЩ��Ҫ�ġ����������ݡ�
//<i>�����ڵ�Ƭ��û�����������ʱ��Ҳ����ȫ����ECP������������ݡ�
#define ECBM_STREAM_ECP_CH1_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>ͨ��2ʹ��
//<i>ʹ��֮�󣬻��Զ�������2�����ݶԽӵ�ͨ��2��
#define ECBM_STREAM_CH2_EN (0)
//<o>���л����С
//<i>��λ���ֽڡ���
#define ECBM_STREAM_CH2_SZIE    (10)
//<q>�Զ���Э��
#define ECBM_STREAM_USER_CH2_EN  (0)
//<q>FUR���
//<i>����ECBM�����з��Ŀ���(Fast)����(Uart)���ʼĴ���(Reg)�����
//<i>����ASCII�������ͨ�ţ�Э��ͨ���׶����������Կ��ٶ�д�Ĵ��������ܶ���������㡣
#define ECBM_STREAM_FUR_CH2_EN (0)
//<q>MODBUS���
//<i>ͨ�õ�MODBUSЭ��RTU�汾��Ŀǰ������[01H][05H][03H][06H][10H][02H][04H]��7��ָ�
//<i>������Ҳ�����ڶ�д�Ĵ����ġ�
#define ECBM_STREAM_MODBUS_CH2_EN (0)
//<q>ECP���
//<i>����ECBM�����з���ECBMͨ��(Communication)Э��(Protocol)�����
//<i>�����������Ը���������һЩ��Ҫ�ġ����������ݡ�
//<i>�����ڵ�Ƭ��û�����������ʱ��Ҳ����ȫ����ECP������������ݡ�
#define ECBM_STREAM_ECP_CH2_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>ͨ��3ʹ��
//<i>ʹ��֮�󣬻��Զ�������3�����ݶԽӵ�ͨ��3��
#define ECBM_STREAM_CH3_EN (0)
//<o>���л����С
//<i>��λ���ֽڡ���
#define ECBM_STREAM_CH3_SZIE    (10)
//<q>�Զ���Э��
#define ECBM_STREAM_USER_CH3_EN  (0)
//<q>FUR���
//<i>����ECBM�����з��Ŀ���(Fast)����(Uart)���ʼĴ���(Reg)�����
//<i>����ASCII�������ͨ�ţ�Э��ͨ���׶����������Կ��ٶ�д�Ĵ��������ܶ���������㡣
#define ECBM_STREAM_FUR_CH3_EN (0)
//<q>MODBUS���
//<i>ͨ�õ�MODBUSЭ��RTU�汾��Ŀǰ������[01H][05H][03H][06H][10H][02H][04H]��7��ָ�
//<i>������Ҳ�����ڶ�д�Ĵ����ġ�
#define ECBM_STREAM_MODBUS_CH3_EN (0)
//<q>ECP���
//<i>����ECBM�����з���ECBMͨ��(Communication)Э��(Protocol)�����
//<i>�����������Ը���������һЩ��Ҫ�ġ����������ݡ�
//<i>�����ڵ�Ƭ��û�����������ʱ��Ҳ����ȫ����ECP������������ݡ�
#define ECBM_STREAM_ECP_CH3_EN (0)
//</e>
//////////////////////////////////////////////////////////////////////////////////////////////
//<e>ͨ��4ʹ��
//<i>ʹ��֮�󣬻��Զ�������4�����ݶԽӵ�ͨ��4��
#define ECBM_STREAM_CH4_EN (0)
//<o>���л����С
//<i>��λ���ֽڡ���
#define ECBM_STREAM_CH4_SZIE    (10)
//<q>�Զ���Э��
#define ECBM_STREAM_USER_CH4_EN  (0)
//<q>FUR���
//<i>����ECBM�����з��Ŀ���(Fast)����(Uart)���ʼĴ���(Reg)�����
//<i>����ASCII�������ͨ�ţ�Э��ͨ���׶����������Կ��ٶ�д�Ĵ��������ܶ���������㡣
#define ECBM_STREAM_FUR_CH4_EN (0)
//<q>MODBUS���
//<i>ͨ�õ�MODBUSЭ��RTU�汾��Ŀǰ������[01H][05H][03H][06H][10H][02H][04H]��7��ָ�
//<i>������Ҳ�����ڶ�д�Ĵ����ġ�
#define ECBM_STREAM_MODBUS_CH4_EN (0)
//<q>ECP���
//<i>����ECBM�����з���ECBMͨ��(Communication)Э��(Protocol)�����
//<i>�����������Ը���������һЩ��Ҫ�ġ����������ݡ�
//<i>�����ڵ�Ƭ��û�����������ʱ��Ҳ����ȫ����ECP������������ݡ�
#define ECBM_STREAM_ECP_CH4_EN (0)
//</e>
#define ECBM_STREAM_CH_COUNT (ECBM_STREAM_CH1_EN+ECBM_STREAM_CH2_EN+ECBM_STREAM_CH3_EN+ECBM_STREAM_CH4_EN)
//</h>
//////////////////////////////////////////////////////////////////////////////////////////////
//<h>����ڲ�����ʹ��������
//<q>�Ƚ����
//<i>���ǶԽ��յ����ַ�����Ŀ���ַ������бȽϣ�������������Ŀ���ַ�����ʱ�򣬿��Դ���ĳЩ������
#define ECBM_STREAM_CMP_EN (0)
//<h>FUR���
//<i>����ECBM�����з��Ŀ���(Fast)����(Uart)���ʼĴ���(Reg)�����
//<i>����ASCII�������ͨ�ţ�Э��ͨ���׶����������Կ��ٶ�д�Ĵ��������ܶ���������㡣
#define ECBM_STREAM_FUR_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_FUR_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_FUR_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_FUR_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_FUR_CH4_EN))
//<q>���ڻظ�ʹ��
//<i>FUR��Ȼ�ǻ��ڴ��ڵ�Ӧ�ã��������ݵķ�������������������ʽ��
//<i>�����ð���OLED����ʾ���ݡ� ֱ�ӹ۲�������ת�Ƕȵȡ���ʱ�ѻظ�����ȡ�������Խ�ʡһЩ�ռ䡣
#define ECBM_STREAM_FUR_UART_SEND_EN (1)
//<q>����ʹ��
//<i>FUR�����֮������������Դ������ֺ͵�Ƭ���ı��ͨ�ţ���������Ҳ֧�ֵ�Ƭ���͵�Ƭ����ͨ�š�
//<i>�������Ҫ����������ܣ�����ȡ���Խ�ʡ�ռ䡣
#define ECBM_STREAM_FUR_MATER_EN (1)
//</h>
//<h>MODBUS���
//<i>ͨ�õ�MODBUSЭ��RTU�汾��Ŀǰ������[01H][05H][03H][06H][10H][02H][04H]��7��ָ�
//<i>������Ҳ�����ڶ�д�Ĵ����ġ�
#define ECBM_STREAM_MODBUS_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_MODBUS_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_MODBUS_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_MODBUS_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_MODBUS_CH4_EN))
//<h>�ӻ�����ѡ��
//<q>[01H]����Ȧ
//<i>�������Ȧ�йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD01_EN (1)
//<q>[05H]д������Ȧ
//<i>�������Ȧ�йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD05_EN (1)
//<q>[03H]���Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD03_EN (1)
//<q>[06H]д�����Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD06_EN (1)
//<q>[10H]д����Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD10_EN (1)
//<q>[02H]����ɢ������
//<i>�����IOϵͳ�йص�ָ�û�б�ʹ�ܣ���ôIO��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD02_EN (1)
//<q>[04H]������Ĵ���
//<i>�����IOϵͳ�йص�ָ�û�б�ʹ�ܣ���ôIO��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_CMD04_EN (1)
//<q>CRC����ص�����
//<i>���ͨ���г�����CRC������ô�ͻ��������ص������������������д������Բ�ʹ�����ѡ�
#define ES_MODBUS_RTU_CRC_ERR_EN (0)
//�����Ǻϲ�������ɢ�ĺ궨����ܽᶨ�壺
#define ES_MODBUS_RTU_CMD_BIT_EN  (ES_MODBUS_RTU_CMD01_EN+ES_MODBUS_RTU_CMD05_EN)
#define ES_MODBUS_RTU_CMD_REG_EN  (ES_MODBUS_RTU_CMD03_EN+ES_MODBUS_RTU_CMD06_EN+ES_MODBUS_RTU_CMD10_EN)
#define ES_MODBUS_RTU_CMD_IO_EN   (ES_MODBUS_RTU_CMD02_EN+ES_MODBUS_RTU_CMD04_EN)
#define ES_MODBUS_RTU_CMD_ALL_EN  (ES_MODBUS_RTU_CMD_BIT_EN+ES_MODBUS_RTU_CMD_REG_EN+ES_MODBUS_RTU_CMD_IO_EN)
//</h>
//<e>��������ѡ��
//<i>modbus���Ǵӻ�����������ṩ������ʹ�ܣ��ڲ�ʹ��������������Խ�Լflash�ռ䡣
#define ES_MODBUS_RTU_MASTER_EN (0)
//<q>[01H]����Ȧ
//<i>�������Ȧ�йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD01_EN (1)
//<q>[05H]д������Ȧ
//<i>�������Ȧ�йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD05_EN (1)
//<q>[03H]���Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD03_EN (1)
//<q>[06H]д�����Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD06_EN (1)
//<q>[10H]д����Ĵ���
//<i>����ͼĴ����йص�ָ�û�б�ʹ�ܣ���ô��Ȧ��д��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD10_EN (1)
//<q>[02H]����ɢ������
//<i>�����IOϵͳ�йص�ָ�û�б�ʹ�ܣ���ôIO��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD02_EN (1)
//<q>[04H]������Ĵ���
//<i>�����IOϵͳ�йص�ָ�û�б�ʹ�ܣ���ôIO��صĺ����ͻ��涼�����Ż�����
#define ES_MODBUS_RTU_MASTER_CMD04_EN (1)
//<q>CRC����ص�����
//<i>���ͨ���г�����CRC������ô�ͻ��������ص������������������д������Բ�ʹ�����ѡ�
#define ES_MODBUS_RTU_MASTER_CRC_ERR_EN (0)
//�����Ǻϲ�������ɢ�ĺ궨����ܽᶨ�壺
#define ES_MODBUS_RTU_MASTER_CMD_0102_EN        (ES_MODBUS_RTU_MASTER_CMD01_EN+ES_MODBUS_RTU_MASTER_CMD02_EN)
#define ES_MODBUS_RTU_MASTER_CMD_0304_EN        (ES_MODBUS_RTU_MASTER_CMD03_EN+ES_MODBUS_RTU_MASTER_CMD04_EN)
#define ES_MODBUS_RTU_MASTER_CMD_01020304_EN    (ES_MODBUS_RTU_MASTER_CMD_0102_EN+ES_MODBUS_RTU_MASTER_CMD_0304_EN)
#define ES_MODBUS_RTU_MASTER_CMD_050610_EN      (ES_MODBUS_RTU_MASTER_CMD05_EN+ES_MODBUS_RTU_MASTER_CMD06_EN+ES_MODBUS_RTU_MASTER_CMD10_EN)
//</e>
//<o>ͨ�û�������
//<i>��λ���֣�16λ����
//<i>�ڴӻ�ģʽ�У�����CRC�Ĵ��ڣ��ڶ��ֽ�д���ʱ�򣬲������̰����ݴ��룬��Ҫ��һ���������������CRC��֤���֮�����һ��д�롣
//<i>������ģʽ�У����ܴӻ������˶�����ݣ�����CRC��ԭ�򣬲������̶���Щ���ص����ݽ��д��������������Ҳ���ⷽ����ô���
#define ES_MODBUS_RTU_BUF_SIZE  (10)
//</h>
//<h>ECP���
//<i>����ECBM�����з���ECBMͨ��(Communication)Э��(Protocol)�����
//<i>�����������Ը���������һЩ��Ҫ�ġ����������ݡ�
//<i>�����ڵ�Ƭ��û�����������ʱ��Ҳ����ȫ����ECP������������ݡ�
#define ECBM_STREAM_ECP_CH_COUNT ((ECBM_STREAM_CH1_EN*ECBM_STREAM_ECP_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_ECP_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_ECP_CH3_EN)+(ECBM_STREAM_CH4_EN*ECBM_STREAM_ECP_CH4_EN))
//<o>���ݻ����С
//<1-200>
//<i>�û����ڶ�ȡָ���д��ָ���ﶼ�õõ����������ڴ��㹻������£����õ�Խ��Խ�á�
#define ES_ECP_DATA_BUF_MAX (32)
//<q>����ʹ��
//<i>���������������ӻ�����ô�������ִ���Ϳ��Բ�Ҫ�ˡ�ʡ��һ��ռ䡣
#define ES_ECP_MASTER_EN (1)
//</h>
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-------------------------------------ͷ�ļ�����-----------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define ECBM_STREAM_TIME_EN   (0x01)  //��ʱʹ�ܡ�
#define ECBM_STREAM_TIME_OUT  (0x02)  //��ʱ����ʱ��־��
#define ECBM_STREAM_UART_IDLE (0x04)  //���ڿ��б�־��
/*--------------------------------------��������-----------------------------------*/
#if ((ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)) 
    #if (ECBM_STREAM_CH1_EN)
    extern u8 xdata ecbm_stream_ch1_buf_gxu8a[ECBM_STREAM_CH1_SZIE];//stream��ͨ��1���ջ��档
    extern u8 ecbm_stream_ch1_point_gu8;                            //stream��ͨ��1���ջ����д���ַ��
    extern u8 ecbm_stream_ch1_read_point_gu8;                       //stream��ͨ��1������Ľ��ȡ�
    extern u8 ecbm_stream_ch1_count_gu8;                            //stream��ͨ��1���յ�������������
    extern u8 ecbm_stream_ch1_time_gu8;                             //stream��ͨ��1��ʱ����ʱ������
    extern u8 ecbm_stream_ch1_status_gu8;                           //stream��ͨ��1״̬��
    #endif
    #if (ECBM_STREAM_CH2_EN)
    extern u8 xdata ecbm_stream_ch2_buf_gxu8a[ECBM_STREAM_CH2_SZIE];//stream��ͨ��2���ջ��档
    extern u8 ecbm_stream_ch2_point_gu8;                            //stream��ͨ��2���ջ����д���ַ��
    extern u8 ecbm_stream_ch2_read_point_gu8;                       //stream��ͨ��2������Ľ��ȡ�
    extern u8 ecbm_stream_ch2_count_gu8;                            //stream��ͨ��2���յ�������������
    extern u8 ecbm_stream_ch2_time_gu8;                             //stream��ͨ��2��ʱ����ʱ������
    extern u8 ecbm_stream_ch2_status_gu8;                           //stream��ͨ��2״̬��
    #endif
    #if (ECBM_STREAM_CH3_EN)
    extern u8 xdata ecbm_stream_ch3_buf_gxu8a[ECBM_STREAM_CH3_SZIE];//stream��ͨ��3���ջ��档
    extern u8 ecbm_stream_ch3_point_gu8;                            //stream��ͨ��3���ջ����д���ַ��
    extern u8 ecbm_stream_ch3_read_point_gu8;                       //stream��ͨ��3������Ľ��ȡ�
    extern u8 ecbm_stream_ch3_count_gu8;                            //stream��ͨ��3���յ�������������
    extern u8 ecbm_stream_ch3_time_gu8;                             //stream��ͨ��3��ʱ����ʱ������
    extern u8 ecbm_stream_ch3_status_gu8;                           //stream��ͨ��3״̬��
    #endif
    #if (ECBM_STREAM_CH4_EN)
    extern u8 xdata ecbm_stream_ch4_buf_gxu8a[ECBM_STREAM_CH4_SZIE];//stream��ͨ��4���ջ��档
    extern u8 ecbm_stream_ch4_point_gu8;                            //stream��ͨ��4���ջ����д���ַ��
    extern u8 ecbm_stream_ch4_read_point_gu8;                       //stream��ͨ��4������Ľ��ȡ�
    extern u8 ecbm_stream_ch4_count_gu8;                            //stream��ͨ��4���յ�������������
    extern u8 ecbm_stream_ch4_time_gu8;                             //stream��ͨ��4��ʱ����ʱ������
    extern u8 ecbm_stream_ch4_status_gu8;                           //stream��ͨ��4״̬��
    #endif
#endif    
/*--------------------------------------������-----------------------------------*/
///////////////////////////////////��Ҫ�û�����ĺ���////////////////////////////////
/*-------------------------------------------------------
��������ecbm_stream_user_exe
��  �����û��Զ���������������ɸ�����Ҫ��ӡ�
��  �룺
    ch       ͨ���š�
    dat      ���յ������ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2024-05-18
�޸ļ�¼��
-------------------------------------------------------*/
extern void ecbm_stream_user_exe(u8 ch,u8 dat);
///////////////////////////////////�û����Ե��õĺ���////////////////////////////////
/*-------------------------------------------------------
��������ecbm_stream_init
��  ����stream��ʼ��������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2023-05-22
�޸ļ�¼��
-------------------------------------------------------*/
extern void ecbm_stream_init(void);
/*-------------------------------------------------------
��������ecbm_stream_main
��  ����������������������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2021-03-24
�޸ļ�¼��
2021-11-11����Դ��ڿ��е��ж������޸ġ�
-------------------------------------------------------*/
extern void ecbm_stream_main(void);
/*-------------------------------------------------------
��������ecbm_stream_cmp
��  ����������ȶԺ�����
��  �룺
    dat     ��ecbm_stream_exe�ԽӵĽӿڡ�
    str     ��Ҫ�ȶԵ��ַ�����
��  ����
    count   �ȶԵļ���ֵ������ֵ���ַ����������ʱ����ʾ�ȶԳɹ���
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2021-10-21
�޸ļ�¼��
-------------------------------------------------------*/
extern void ecbm_stream_strcmp(u8 dat,u8 code * str,u8 * count);
////////////////////////////ECBM����õĺ������û����ܵ���//////////////////////////
/*-------------------------------------------------------
��������ecbm_stream_timer_run
��  ����ʱ�����к����������ṩ�������ʱ���жϹ��ܡ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2021-03-24
�޸ļ�¼��
2021-11-11�������˴��ڿ��е��жϡ�
-------------------------------------------------------*/    
extern void ecbm_stream_timer_run(void);
/*-------------------------------------------------------
��������es_crc16
��  ����CRC16λУ�麯�����㷨����Ҫ��modbus���ݡ�
��  �룺
    crc     ��ǰ��CRCֵ��
    buf     ��ǰ��Ҫ����CRCУ������ݡ�
��  ������  
����ֵ��
    ���������õ�����CRCֵ��
�����ߣ�����
�ο����̣���
�������ڣ�2022-05-27
�޸ļ�¼��
-------------------------------------------------------*/
extern u16 es_crc16(u16 crc,u8 buf);
extern u16 es_send_whit_crc(u8 ch,u16 crc,u8 dat);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��