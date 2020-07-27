#ifndef _ECBM_AT24CXX_H_
#define _ECBM_AT24CXX_H_
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
//<q>�Զ���ʼ������
//<i>�ù�����һ����չ���ܣ���ͨ����д�������ж�оƬ�ͺź͵�ַ�����Ҫ��IIC����������ֻ��һ��EEPROMоƬ��
//<i>���ڶ�д�����ή��eeprom�������������Ƽ�ֻ��Ŀ������������ȫ������������ʹ�á�
//<i>��ʹ�øú���Ҳ��ʹ��eeprom���Ż����ú����ܽ�ʡһЩ�ռ䡣
#define AT24CXX_AUTO_INIT_EN 0
//<q>оƬȫд����
//<i>�ù�����һ����չ���ܣ�һ�����ڲ���оƬ�Ƿ���д�����ݣ���������������������ò��������������������debug�����Ĵ��ڡ�
#define AT24CXX_WRITE_ALL_EN 0
//<q>оƬȫ������
//<i>�ù�����һ����չ���ܣ�һ�����ڲ鿴оƬ�ڵ����ݣ���ȫд�������ã���������debug�����Ĵ��ڡ�
#define AT24CXX_READ_ALL_EN 0
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define AT24_ADDR 0x50 //ͨ��EEPROM�ĵ�ַ�Ǵ�0x50��������дλ������дλ����0xA0����ʼ��
#define AT24_A2   0x04 //��оƬ�ϵ�A2�ŽӸߵ�ƽ��ʱ�򣬰�����궨����ͺ���ȥ������AT24C02|AT24_A2��
#define AT24_A1   0x02 //��оƬ�ϵ�A1�ŽӸߵ�ƽ��ʱ�򣬰�����궨����ͺ���ȥ������AT24C02|AT24_A1��
#define AT24_A0   0x01 //��оƬ�ϵ�A0�ŽӸߵ�ƽ��ʱ�򣬰�����궨����ͺ���ȥ������AT24C02|AT24_A0��
#define AT24_OK            0  //������
#define AT24_ERROR_INIT    1  //��ʼ�����⡣
#define AT24_ERROR_NOACK   2  //�޻�Ӧ���⡣
#define AT24_ERROR_SEND    3  //����ʧ�ܡ�
#define AT24_ERROR_ADDR    4  //��ַ�Ƿ���
#define AT24_ERROR_NUMBER  5  //д��/���������Ƿ���
#define AT24_ERROR_UNKONW  6  //δ֪�ͺš�
#define AT24CXX  0x00 //δ֪�ͺ�
#define AT24C01  0x10 //����Ϊ128�ֽ�
#define AT24C02  0x20 //����Ϊ256�ֽ�
#define AT24C04  0x30 //����Ϊ512�ֽ�
#define AT24C08  0x40 //����Ϊ1024�ֽ�
#define AT24C16  0x50 //����Ϊ2048�ֽ�
#define AT24C32  0x60 //����Ϊ4096�ֽ�
#define AT24C64  0x70 //����Ϊ8192�ֽ�
#define AT24C128 0x80 //����Ϊ16384�ֽ�
#define AT24C256 0x90 //����Ϊ32768�ֽ�
#define AT24C512 0xA0 //����Ϊ65536�ֽ�
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 model;
	u8 id;
	u8 scl;
	u8 sda;
}at24_def;                  //�������棬ÿʹ��һ��������Ӧ�ô���һ�����档���ڶ��������á�
extern u8 xdata at24_model; //��ǰ�⺯�������Ķ�����Ϊ������������IIC�йأ����ԾͲ����������ˡ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������at24_set_work
��  �������ù���״̬��������һ����������Ϊ����״̬��
��  �룺dev  -  Ҫ���óɹ���״̬��������
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-11-26
�޸ļ�¼��
-------------------------------------------------------*/
extern void at24_set_work(at24_def * dev);
/*-------------------------------------------------------
��������at24_init
��  ����AT24CXXϵ�еĳ�ʼ��������
��  �룺dev   -  Ҫ��ʼ����������
		model -  ���������ͺţ��⺯��֧�ֵ��ͺſɼ��ں궨������
		scl   -  ��������SCL�����ӵ�IO��
		sda   -  ��������SDA�����ӵ�IO��
��  ������
����ֵ����
�����ߣ�����
�������̣�
�������ڣ�2019-11-26
�޸ļ�¼��
-------------------------------------------------------*/
extern void at24_init(at24_def * dev,u8 model,u8 scl,u8 sda);
/*-------------------------------------------------------
��������at24_write
��  ����AT24ϵ�е�д������֧�ֶ������д�롣
��  �룺addr  -  д��ĳ�ʼ��ַ��
		dat   -  д������ݻ��档
		num   -  д�����ݵ�������
��  ������
����ֵ��״̬�롣
�����ߣ�����
�������̣�
�������ڣ�2019-11-27
�޸ļ�¼��
2019-11-29:�����˴����ʱ��ر�IIC���ߡ�
2019-12-09:������at24c32��at24c512��5���ͺš�
-------------------------------------------------------*/
extern u8 at24_write(u16 addr,u8 dat[],u16 num);
/*-------------------------------------------------------
��������at24_read
��  ����AT24ϵ�еĶ�������֧�ֶ�����ݶ�ȡ��
��  �룺addr  -  ��ȡ�ĳ�ʼ��ַ��
		num   -  ��ȡ���ݵ�������
��  ����dat   -  ���ȡ�����ݵĻ��档
����ֵ��״̬�롣
�����ߣ�����
�������̣�
�������ڣ�2019-11-27
�޸ļ�¼��
2019-11-29:�����˴����ʱ��ر�IIC���ߡ�
2019-12-09:������at24c32��at24c512��5���ͺš�
-------------------------------------------------------*/
extern u8 at24_read(u16 addr,u8 dat[],u16 num);
/*-------------------------------------------------------
��������at24_write_all
��  ����AT24ϵ�е�ȫд��������128�ֽ�Ϊһ�飬��eeprom��д��00~FF���ú�����Ҫ����֧�֡�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-12-09
�޸ļ�¼��
-------------------------------------------------------*/
extern void at24_write_all(void);
/*-------------------------------------------------------
��������at24_read_all
��  ����AT24ϵ�е�ȫ����������ȡeeprom������ݷ��͵����ڡ��ú�����Ҫ����֧�֡�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-12-09
�޸ļ�¼��
-------------------------------------------------------*/
extern void at24_read_all(void);
/*-------------------------------------------------------
��������at24_auto_init
��  ����AT24ϵ�е��Զ���ʼ��������ֻ���ṩ���ž��ܳ�ʼ�������ǻή��оƬ������
��  �룺dev   -  Ҫ��ʼ����������
		scl   -  ��������SCL�����ӵ�IO��
		sda   -  ��������SDA�����ӵ�IO��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-12-09
�޸ļ�¼��
-------------------------------------------------------*/
extern void at24_auto_init(at24_def * dev,u8 scl,u8 sda);
#endif
