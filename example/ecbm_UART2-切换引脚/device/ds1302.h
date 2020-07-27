#ifndef _DS1302_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _DS1302_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<e>��ʼ������ʱ�Ƿ�д��ʱ�䣿
#define DS1302_INIT_DATA_EN 0
//<o>��
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x������������������52�룬������0x52��
//<i>��Χ0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_SECOND 0x40
//<o>��
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x�����������������08�֣�������0x08��
//<i>��Χ0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_MINUTE 0x03
//<o.0..5>ʱ
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x��������Сʱ��������9���ӣ�������0x09��
//<i>��24Сʱ�������뷶ΧΪ0x00~0x23����12Сʱ�������뷶ΧΪ0x01~0x12��
//<0x00-0x23:0x01>
//<o.7>ʱ��ѡ��
//<0=>24Сʱ�� <1=>12Сʱ��
//<o.5>������ѡ��
//<i>ע�⣺���ѡ��24Сʱ�ƣ����ѡ��һ���������磬�������ݻ����
//<i>ԭ���ǸüĴ�����bit5λ��12Сʱ�Ƶ�AM/PMλ����bit5λ��bit4λ��24Сʱ�ƵĴ��Сʱ��ʮλ�����ֵĴ洢λ��
//<i>����bit5λ���õ����˳�ͻ��������24Сʱ��ʱֻ������Ϊ�����硱���Ų��������ͻ����Ϊ�����硱��Ӧ��ֵ��0��
//<0=>���� <1=>����
#define DS1302_HOUR 0x21
//<o>����
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x�����������ڡ�����14�ţ�������0x14��
//<i>��Χ0x01~0x31
//<0x01-0x31:0x01>
#define DS1302_DATE 0x05
//<o>�·�
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x���������·ݡ�����2�·ݣ�������0x02��
//<i>��Χ0x01~0x12
//<0x01-0x12:0x01>
#define DS1302_MONTH 0x02
//<o>����
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x�����������ڡ����������ģ�������0x04��
//<i>��Χ0x01~0x07
//<0x01-0x07:0x01>
#define DS1302_DAY 0x03
//<o>���
//<i>������BCD�롣�������BCD�Ķ��壬��ô��������0x����������ݡ�����19�꣬������0x19��
//<i>��Χ0x00~0x99�����ڼĴ���ֻ�ܴ���λ���֡�����������1919���2019�궼��19�ꡣ��Ҫ�����������⡣
//<0x01-0x31:0x01>
#define DS1302_YEAR 0x20
//</e>
//<h>������������
//<i>��VCC2��VCC1�ĳ��������ֵ=��VCC2��ѹ-����������*0.7V��/��������ֵ����
//<i>����VCC2��5V��ѹ��VCC1��һ���������ݡ�����������Ϊ1��������ֵΪ2K��
//<i>��ôImax=��5.0V-1*0.7V��/2K=2.15mA��
//<o.2..3>VCC2��VCC1�Ķ���������
//<1=>һ�������� <2=>����������
//<o.0..1>VCC2��VCC1�ĵ�����ֵ
//<1=>2K <2=>4K <3=>8K
#define DS1302_CHARGER 0xA5
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
//DS1302��ַ����
#define DS1302_SECOND_ADDR  0x80//�����ݵ�ַ
#define DS1302_MINUTE_ADDR  0x82//�����ݵ�ַ
#define DS1302_HOUR_ADDR    0x84//ʱ���ݵ�ַ
#define DS1302_DATE_ADDR    0x86//�����ݵ�ַ
#define DS1302_MONTH_ADDR   0x88//�����ݵ�ַ
#define DS1302_DAY_ADDR     0x8A//�������ݵ�ַ
#define DS1302_YEAR_ADDR    0x8C//�����ݵ�ַ
#define DS1302_CONTROL_ADDR 0x8E//�������ݵ�ַ
#define DS1302_CHARGER_ADDR 0x90//����������ַ 					 
#define DS1302_RAM0  0xC0
#define DS1302_RAM1  0xC2
#define DS1302_RAM2  0xC4
#define DS1302_RAM3  0xC6
#define DS1302_RAM4  0xC8
#define DS1302_RAM5  0xCA
#define DS1302_RAM6  0xCC
#define DS1302_RAM7  0xCE
#define DS1302_RAM8  0xD0
#define DS1302_RAM9  0xD2
#define DS1302_RAM10 0xD4
#define DS1302_RAM11 0xD6
#define DS1302_RAM12 0xD8
#define DS1302_RAM13 0xDA
#define DS1302_RAM14 0xDC
#define DS1302_RAM15 0xDE
#define DS1302_RAM16 0xE0
#define DS1302_RAM17 0xE2
#define DS1302_RAM18 0xE4
#define DS1302_RAM19 0xE6
#define DS1302_RAM20 0xE8
#define DS1302_RAM21 0xEA
#define DS1302_RAM22 0xEC
#define DS1302_RAM23 0xEE
#define DS1302_RAM24 0xF0
#define DS1302_RAM25 0xF2
#define DS1302_RAM26 0xF4
#define DS1302_RAM27 0xF6
#define DS1302_RAM28 0xF8//���3λRAM
#define DS1302_RAM29 0xFA//������Ϊ
#define DS1302_RAM30 0xFC//��һ�γ�ʼ���ж�λ
/*--------------------------------------��������-----------------------------------*/
typedef struct{
	u8 rst;		//оƬ�ĸ�λ�š�
	u8 io;		//оƬ�����ݽš�
	u8 sck;		//оƬ��ʱ�ӽš�
	u8 year;	//�ꡣ
	u8 month;	//�¡�
	u8 date;	//���ڡ�
	u8 day;		//�ա�
	u8 hour;	//ʱ��
	u8 minute;	//�֡�
	u8 second;	//�롣
	u8 charger;	//���Ĵ�����
}ds1302_def;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������ds1302_write
��  ����DS1302��д������������DS1302д��һ���ֽڵ����ݡ�
��  �룺dev  -  Ҫд���������
		addr -  Ҫд��ļĴ�����ַ��
		dat  -  Ҫд������ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds1302_write(ds1302_def * dev,u8 addr,u8 dat);
/*-------------------------------------------------------
��������ds1302_read
��  ����DS1302�Ķ�������������DS1302��ȡһ���ֽڵ����ݡ�
��  �룺dev  -  Ҫ��ȡ��������
		addr -  Ҫ��ȡ�ļĴ�����ַ��
��  ������
����ֵ���üĴ��������ݡ�
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 ds1302_read(ds1302_def * dev,u8 addr);
/*-------------------------------------------------------
��������ds1302_save
��  ����DS1302�Ĵ��溯�������ڰѽṹ�����ʱ�䱣�浽DS1302оƬ�
��  �룺dev  - Ҫ���浽��������
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds1302_save(ds1302_def * dev);
/*-------------------------------------------------------
��������ds1302_load
��  ����DS1302�ļ��غ��������д˺������Դ�DS1302оƬ�ж�ȡʱ�䡣
��  �룺dev  -  Ҫ������������
��  ����	dev.year    - �� 
		dev.month   - �� 
		dev.date    - �� 
		dev.hour    - ʱ 
		dev.minute  - �� 
		dev.second  - ��
		dev.day     - �� 	
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds1302_load(ds1302_def * dev);
/*-------------------------------------------------------
��������ds1302_init
��  ����DS1302�ĳ�ʼ��������
��  �룺dev -  Ҫ��ʼ����������
		rst -  �����ĸ�λ�š�
		io  -  ���������ݽš�
		sck -  ������ʱ�ӽš�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-02-05
�޸ļ�¼��
-------------------------------------------------------*/
extern void ds1302_init(ds1302_def * dev,u8 rst,u8 io,u8 sck);
#endif
