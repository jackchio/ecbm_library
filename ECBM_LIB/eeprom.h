#ifndef _ECBM_EEPROM_H_
#define _ECBM_EEPROM_H_
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
//<e>�ֶ�����eeprom��С
#define ECBM_EEPROM_SIZE_EN 1
//<i>���ĳЩ�ͺŵ�EEPROM�Ŀռ��С�ǿ�����STC-ISP���õģ������õ���Щ�ͺŵ�ʱ�򣬿ɴ򿪴����ã��ֶ�����EEPROM�ռ��С��
//<o>eeprom�ռ�
//<i>��λ���ֽڣ������0.5K����512
#define ECBM_EEPROM_SIZE 512
//</e>
//<<< end of configuration section >>>
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
//#if   SYS_CLK_SET == 5529600L  //����ʱ��Ƶ����ѡ���ڲ�eeprom�ĵȴ�ʱ�䡣
//#define EEPROM_WAIT 4
//#elif SYS_CLK_SET == 6000000L
//#define EEPROM_WAIT 4
//#elif SYS_CLK_SET == 11059200L
//#define EEPROM_WAIT 3
//#elif SYS_CLK_SET == 12000000L
//#define EEPROM_WAIT 3
//#elif SYS_CLK_SET == 18432000L
//#define EEPROM_WAIT 2
//#elif SYS_CLK_SET == 20000000L
//#define EEPROM_WAIT 2
//#elif SYS_CLK_SET == 22118400L
//#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 24000000L
#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 27000000L
//#define EEPROM_WAIT 1
//#elif SYS_CLK_SET == 30000000L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 33000000L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 33177600L
//#define EEPROM_WAIT 0
//#elif SYS_CLK_SET == 35000000L
//#define EEPROM_WAIT 0
//#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������eeprom_erase
��  ����eeprom����������stc��eeprom������flash��������ģ�������д֮ǰҪ������
		ͬʱ��Ϊһ��������512�ֽڣ�����������һ���ֽڣ��ͻ��ͬһ����������511�ֽ�һ�������
		�úú�ע��������⣬�ö�дflash��˼ά��ʹ�����eeprom��
��  �룺Ҫ�����ĵ�ַ��������õ�ַ���ڵ�����������ȫ�����ݡ�
��  ������
����ֵ����
�����ߣ�����
�������̣�
		...//�����޹صĴ��롣
		eeprom_erase(30);//������ַ30�����ݣ���������30�ǵ�0����������0~511������Ҳ��һ������������
		...//�����޹صĴ��롣
�������ڣ�2019-10-12
�޸ļ�¼��
-------------------------------------------------------*/
extern void eeprom_erase(u16 addr);
/*-------------------------------------------------------
��������eeprom_write
��  ����eepromд������
��  �룺addr - Ҫд����ֵ�ĵ�ַ��
        dat  - Ҫд�����ֵ����Χ��u8�ͣ���0~255��
��  ������
����ֵ����
�����ߣ�����
�������̣�
		...//�����޹صĴ��롣
		eeprom_write(123,15);//����ֵ15д�뵽��ַ123��ȥ��
		...//�����޹صĴ��롣
�������ڣ�2019-10-12
�޸ļ�¼��
-------------------------------------------------------*/
extern void eeprom_write(u16 addr,u8 dat);
/*-------------------------------------------------------
��������eeprom_read
��  ����eeprom��������
��  �룺Ҫ��ȡ�ĵ�ַ��
��  ������
����ֵ���õ�ַ���ֵ��
�����ߣ�����
�������̣�
		...//�����޹صĴ��롣
		val=eeprom_read(56);//��ȡ��ַ56��ֵ���������val��
		...//�����޹صĴ��롣
�������ڣ�2019-10-12
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 eeprom_read(u16 addr);
#endif
