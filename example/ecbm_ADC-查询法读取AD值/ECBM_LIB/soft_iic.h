#ifndef _ECBM_SOFT_IIC_H_
#define _ECBM_SOFT_IIC_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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
//<h>����Ż�
//<q>���IICɨ����������ʹ��
#define SOFT_IIC_FIND_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
extern u8 xdata soft_iic_def_sda_port;//���IIC���ݽ����ڵ�P�ڡ�
extern u8 xdata soft_iic_def_sda_pin; //���IIC���ݽ����ڵ�IO�ڡ�
extern u8 xdata soft_iic_def_scl_port;//���IICʱ�ӽ����ڵ�P�ڡ�
extern u8 xdata soft_iic_def_scl_pin; //���IICʱ�ӽ����ڵ�IO�ڡ�
extern u8 xdata soft_iic_max;         //���IIC�豸��������
extern u8 xdata soft_iic_index;       //��ǰ���IIC�����������Ķ���
typedef struct{
	u8 scl_pin;//IIC���ʱ�ӽš�
	u8 sda_pin;//IIC������ݽš�
	u8 dev_id; //���IIC��ΨһID����Ϊ�л���ƾ֤��
}soft_iic_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������soft_iic_set_pin
��  �������IIC�����л��������ڶ�������Ӧ���£��л�IIC�����Ĳ�������
��  �룺���IIC��Ϣ����
��  ������
����ֵ����
�����ߣ�����
�������̣�
	soft_iic_set_pin(&sht30);  //��IIC�����л�����ΪSHT30����Ϣ����
	val=get_temp();            //��ȡSHT30���¶����ݡ�
	soft_iic_set_pin(&at24c02);//��IIC�����л�����Ϊat24c02����Ϣ����
	at24_write(0,val);         //���¶�����д�뵽eeprom��24c02���
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_iic_set_pin(soft_iic_def * dev);
/*-------------------------------------------------------
��������soft_iic_init
��  �������IIC��ʼ��������
��  �룺dev - ���IIC��Ϣ����
		scl - ���IIC��ʱ�ӽš�
		sda - ���IIC�����ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣�
	soft_iic_def at24;           //����һ�����IIC���������������⣬�����Ƽ���Ŀ����������ϵ��������䡣
	soft_iic_init(&at24,D10,D11);//�ö��������ӵ����ţ�������ʱ�ӽ�SCL�����������ݽ�SDA��
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
��������soft_iic_set_pin_linkage
��  �������IIC�����л������������棩����Ҫ����������ĵ��ã��������ԭ�������soft_iic_set_pin������
��  �룺id  -  ��ʼ�����IICʱ�����id�š�
		scl - ���IIC��ʱ�ӽš�
		sda - ���IIC�����ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
extern void soft_iic_set_pin_linkage(u8 id,u8 scl,u8 sda);
/*-------------------------------------------------------
��������soft_iic_init_linkage
��  �������IIC��ʼ�������������棩����Ҫ����������ĵ��ã��������ԭ�������soft_iic_init������
��  �룺	scl - ���IIC��ʱ�ӽš�
		sda - ���IIC�����ݽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_iic_init_linkage(u8 scl,u8 sda);
/*-------------------------------------------------------
��������soft_iic_start
��  �������IIC������������������һ��IIC���䡣
��  �룺��
��  ������
����ֵ��0   - ����ͨ�ţ��������ڡ�
        -1 -  ���߳�������æ��
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:�Ż���һ������ˢ��ʱ���169.4ms����167.4ms��
-------------------------------------------------------*/
extern u8 soft_iic_start(void);
/*-------------------------------------------------------
��������soft_iic_stop
��  �������IICֹͣ����������ֹͣһ��IIC���䡣
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:�Ż���һ������ˢ��ʱ���167.4ms����167.0ms��
-------------------------------------------------------*/
extern void soft_iic_stop(void);
/*-------------------------------------------------------
��������soft_iic_write_ack
��  �������IIC����дACK�����������ڴ���8bit����һ��ACK�źš�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:�Ż���һ������ˢ��ʱ���167.088ms����167.059ms��
-------------------------------------------------------*/
extern void soft_iic_write_ack(void);
/*-------------------------------------------------------
��������soft_iic_write_nack
��  �������IIC����дNO ACK�����������ڴ���8bit����һ��NO ACK�źš�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:�Ż���һ������ˢ��ʱ���167.059ms����167.023ms��
-------------------------------------------------------*/
extern void soft_iic_write_nack(void);
/*-------------------------------------------------------
��������soft_iic_read_ack
��  �������IIC������ACK�����������ڴ���8bit���ȡ�ӻ���ACK�źš�
��  �룺��
��  ������
����ֵ��0  - �յ�ACK�ź�
		-1 - û�յ�ACK�źţ������յ�NO ACK�źš�
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:�Ż���һ������ˢ��ʱ���167.023ms����165.549ms��
-------------------------------------------------------*/
extern u8 soft_iic_read_ack(void);
/*-------------------------------------------------------
��������soft_iic_write
��  �������IIC����д���������ڷ���һ���ֽ����ݡ�
��  �룺Ҫ���͵����ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
2020-03-20:ˢһҳ128�ֽڵ�ʱ���23.6ms����20.6ms��
-------------------------------------------------------*/
extern void soft_iic_write(u8 dat);
/*-------------------------------------------------------
��������soft_iic_read
��  �������IIC���������������ڽ���һ���ֽ����ݡ�
��  �룺��
��  ������
����ֵ���յ������ݡ�
�����ߣ�����
�������̣�������������ӡ�
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_iic_read(void);
/*-------------------------------------------------------
��������soft_iic_find
��  �������IIC����Ѱ�Һ�������Ѱ��һ�������豸��
��  �룺��
��  �������ڵ��豸�ĵ�ַ�б�
����ֵ�����ش��ڵ��豸�ĸ�����
�����ߣ�����
�������̣�
		count=soft_iic_find(iic_addr);//��ȡ��ǰIIC�����ϴ����豸�ĵ�ַ��ͬʱ���豸�����������count��
�������ڣ�2019-11-25
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 soft_iic_find(u8 addr[]);
/*-------------------------------------------------------
SOFT_IICϵ�к����������̣�
void OLED_send_cmd(unsigned char cmd){//OLED����һ��ָ���
	soft_iic_start   ();     //����һ�δ���
	soft_iic_write   (0x78); //д��OLED�ĵ�ַ
	soft_iic_read_ack();     //�ȴ�ack
	soft_iic_write   (00);   //д��ָ��Ĵ���
	soft_iic_read_ack();     //�ȴ�ack
	soft_iic_write   (cmd);  //д������ָ��
	soft_iic_read_ack();     //�ȴ�ack
	soft_iic_stop    ();     //����һ�δ���
}
�������ڣ�2019-10-18
�޸ļ�¼��
-------------------------------------------------------*/
#endif
