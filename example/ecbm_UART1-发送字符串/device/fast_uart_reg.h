#ifndef _FAST_UART_REG_H_ //ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _FAST_UART_REG_H_ //û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
------------------------------------------------------------------------------------*///���ǿ�ԴЭ�飬������ͼ�ν���ѡ�
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>Fast Uart Reg�����мĴ���������
//<2-256>
//<i>���֧��256��16λ�Ĵ�����
#define ECBM_FUE_MAX 16
//<o>Fast Uart Reg���ܴ��صĴ��ں�
//<1-4>
//<i>��������֮��ҲҪ��fast_uart_in�����ŵ��ô��ڵĽ��ջص��С�
#define ECBM_FUE_UART_ID  1
//<q>Fast Uart Reg�ı��湦��
//<i>�����Ļ���Ҫ�õ��ڲ�EEPROM��
#define ECBM_FUE_EEPROM_EN 0
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define FUE_VER	"V0.1"
/*--------------------------------------��������-----------------------------------*/
extern  u8  fue_state          ;//���ڽ���״̬��������
extern  u8  fue_reg_point      ;//�Ĵ���ָ�룬ָ��Ҫд��ļĴ�����
extern  u8  fue_cmd_buf[16]    ;//ָ��λ��棬���ڼ��ᴮ���ж�ѹ����
extern  u8  fue_cmd_wr_buf[16] ;//ָ���д״̬���λ��棬�����첽�����зֱ�ָ���Ƕ�����д��
extern  u8  fue_cmd_start      ;//���λ���Ŀ�ʼָ�롣
extern  u8  fue_cmd_end        ;//���λ���Ľ���ָ�롣
extern  u16 fue_reg_temp       ;//д��Ĵ����Ļ��档
extern  u16 fue_reg    [ECBM_FUE_MAX];//�Ĵ������壬ֱ�Ӻ͹��ܹҹ���
extern  u16 fue_reg_buf[ECBM_FUE_MAX];//Ӱ�ӼĴ���������д����������������ţ���֤���ٴ��뱾�塣
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������fue_in
��  ����FUE���ܵĴ��ڶ�ȡ���������ڴӴ��ڶ���һ���ֽڵ����ݡ�
��  �룺��ǰ���ڵ�SBUF��
��  ������
����ֵ����
�����ߣ�����
�������̣�
void uart1_receive_callback(){//�����ڴ���1�ϣ�
	fast_uart_in(SBUF);//������1��SBUF��Ϊ������
}
�������ڣ�2020-06-01
�޸ļ�¼��
-------------------------------------------------------*/
extern void fue_in(u8 buf);
/*-------------------------------------------------------
��������fue_check
��  ����FUE��У�Ժͷ��غ��������Զ�ĳЩָ�������Ӧ��Ҳ���ڷ��ؼĴ���ֵ����ѯ���ܣ���������ѭ���С�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-06-01
�޸ļ�¼��
-------------------------------------------------------*/
extern void fue_check(void);
/*-------------------------------------------------------
��������fue_init
��  ����FUE�ĳ�ʼ������������eeprom��������ȡ����ֵ��
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-06-01
�޸ļ�¼��
-------------------------------------------------------*/
extern void fue_init(void);
#endif 
