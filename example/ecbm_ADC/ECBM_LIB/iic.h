#ifndef _ECBM_IIC_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_IIC_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>IIC�ȴ�ʱ������
//<0-63:1>
//<i>������0~63��������ԽС�����ȴ�ʱ��Խ�٣�IIC���ٶ�Խ�졣���Ŀ���������ٶȸ����ϣ�������Ϊ0�Ի�ȡ����IICͨ���ٶȡ�
//<i>���Ŀ���������ٶȸ����ϣ�һ��ͨ�ų��������ֱ��ͨ��ʧ�ܣ������Դ�63��ʼһ��һ�������Ի��������ܡ����鷳Ҳ��ֱ����Ϊ63��
#define ECBM_IIC_WAIT 50
//<o.4..5>IICĬ�Ϲܽ�
//<i>������ֻ��Ķ���ʼ���Ĺܽţ���ʵ��Ӧ������ʱ����ʹ��iic_set_pin�����޸�IIC�ܽţ��ﵽ��ʱ���õ�Ч����
//<0=>SCL-P15|SDA-P14 <1=>SCL-P25|SDA-P24 <2=>SCL-P77|SDA-P76 <3=>SCL-P32|SDA-P33
#define ECBM_IIC_IO 0
//<o>����Ӧ��ʱʱ��
//<i>�������ʱ��������������10~100��
//<10-100>
#define ECBM_IIC_TIMEOUT 10
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define IIC_PIN_P1 0	//��IIC�����IO���õ�P1�ڡ�
#define IIC_PIN_P2 16	//��IIC�����IO���õ�P2�ڡ�
#define IIC_PIN_P7 32	//��IIC�����IO���õ�P7�ڡ�
#define IIC_PIN_P3 48	//��IIC�����IO���õ�P3�ڡ�
/*--------------------------------------��������-----------------------------------*/
extern bit iic_busy; 
extern u8 xdata iic_index;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������iic_set_pin
��  ����IIC���������ú�����IIC֧��4���飬��Ӧ��P1��P2��P7��P3�ϡ�
��  �룺 
        group - ����IIC��������š���������IIC_PIN_P1��IIC_PIN_P2��IIC_PIN_P7��IIC_PIN_P3��
��  ������
����ֵ����
�����ߣ�����
�������̣�iic_set_pin(IIC_PIN_P1);//SCL��ΪP15��SDA��ΪP14 
�������ڣ�2019-8-23
�޸ļ�¼��
-------------------------------------------------------*/
void iic_set_pin(u8 group);
/*-------------------------------------------------------
��������iic_set_pin_linkage
��  ����IIC���������ú����������棩���ú���ֻ�ᱻ�⺯�����á�
��  �룺group - ����IIC��������š���������IIC_PIN_P1��IIC_PIN_P2��IIC_PIN_P7��IIC_PIN_P3��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-03-05
�޸ļ�¼��
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group);
/*-------------------------------------------------------
��������iic_reset_pin
��  ����IIC�����Ż�ԭ��������IICת�Ƶ������ŵ�ʱ�򣬽�ԭ����IO�ָ����������á�
��  �룺 
        group - ������Ҫ��ԭ�����š���������IIC_PIN_P1��IIC_PIN_P2��IIC_PIN_P7��IIC_PIN_P3��
��  ������
����ֵ����
�����ߣ�����
�������̣�iic_reset_pin(IIC_PIN_P1);//P15��P14��ԭ��������ģʽ 
�������ڣ�2019-8-23
�޸ļ�¼��
-------------------------------------------------------*/
void iic_reset_pin(u8 group);
/*-------------------------------------------------------
��������iic_master_init
��  ����IIC������ʼ����������Ӳ��IIC�����������ã�����������ͼ�ν������롣
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�iic_master_init();//��ʼ��IIC����
�������ڣ�2019-8-23
�޸ļ�¼��
2020-03-05:֧�ֶ�·���ã��������Զ��л�����Ҫ�ֶ��л���
-------------------------------------------------------*/
void iic_master_init(void);
/*-------------------------------------------------------
��������iic_slave_init
��  ����IIC�ӻ���ʼ����������Ӳ��IIC���ɴӻ����ã�����������ͼ�ν������롣���ӻ�δ�깤��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�iic_slave_init();//��ʼ��IIC�ӻ�
�������ڣ�2019-8-23
�޸ļ�¼��
2020-03-05:֧�ֶ�·���á� ����ʵ���ϴӻ��޷����������Ķ�·���á��ȼӽ�ȥ�ȡ�
-------------------------------------------------------*/
void iic_slave_init(void);
/*-------------------------------------------------------
��������iic_start��iic_stop��iic_write��iic_write_ack��iic_write_nack��iic_read��iic_read_ack
��  ����IIC�ĸ��ֲ��������������������Э�����Ų���
        iic_start     :��ʼ��������ӦIIC��ʼ֡��
        iic_stop      :ֹͣ��������ӦIICֹͣ֡��
        iic_write     :д���ݺ�������������д1�ֽ����ݡ�
        iic_write_ack :дACK��������������дһ��ACK��
        iic_write_nack:дNO ACK��������������дһ��NO ACK��
        iic_read      :�����ݺ�������ȡ������һ���ֽڵ����ݡ�
        iic_read_ack  :��ACK��������ȡ�������Ƿ���ACK��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�
          iic_start();    //��ʼ����
          iic_write(0x78);//�ȷ���ַ0x78
          iic_read_ack(); //��������ACK
          iic_write(cd);  //������������
          iic_read_ack(); //��������ACK
          iic_write(buf); //��������
          iic_read_ack(); //��������ACK
          iic_stop();     //ֹͣ����
�������ڣ�2019-8-23
�޸ļ�¼��
2020-03-02:���������ʹ�char�ĳ���u8
2020-03-05:ȫԱ��ӳ�ʱ�ж�����ֹ����ѭ����
-------------------------------------------------------*/
void iic_start     (void);
void iic_stop      (void);
void iic_write     (u8 dat);
void iic_write_ack (void);
void iic_write_nack(void);
u8   iic_read      (void);
bit iic_read_ack   (void);
#endif
