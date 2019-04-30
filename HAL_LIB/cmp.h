#ifndef _ECBM_CMP_H_
#define _ECBM_CMP_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 ����

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
�汾����BUGʱ������ϵ���߽������ϵ��ʽ����Ⱥ778916610
------------------------------------------------------------------------------------*/
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM��������ʹ��
//<i>GPIO��Ϊ�����⣬����û�����������⡣��˼���ֱ�ӵ���ʹ�ã��ֿ�����ʹ�á�
//<i>���Դ�ѡ��򹴣�ֻ����ζ��GPIO���ʹ��ECBM���ͷ�ļ�����ѡ��򹴣����ʹ�û�����stc8ͷ�ļ���
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����gpio.h����ͬһ���ļ��С�
#define ECBM_CMP_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ���ⲿ�жϣ�����Ϊ0��
//<h>�Ƚ�������
//<i>������ѡ���ڲ��Ƚ���������
//<o>�Ƚ�����+�������
//<i>�Ƚ�������������ˣ��ֱ��ǡ�+���͡�-�������С�+���˿��Դ�P3.7�����룬Ҳ����ʹ�õ�ǰ��ADCת������Ϊ���롣
//<i>�����統ǰADC��ת��P1.2�ڣ��Ͱ�P1.2�ڵ����Ƚ�������ˡ������������ADC�ļĴ�����������
//<0xF7=>P3.7��  <0x08=>ADCת����  
#define ECBM_CMP_INP 247
//<o>�Ƚ�����-�������
//<i>�Ƚ�������������ˣ��ֱ��ǡ�+���͡�-�������С�-���˿��Դ�P3.6�����룬Ҳ����ʹ���ڲ���ѹ��׼��Ϊ���롣
//<i>�ڲ���ѹ��׼������STC-ISP�����ϲ鿴��ÿ�����ص�ʱ���ܿ�������ѹֵ�ķ�ΧΪ1.34V��1.35V��
//<0x04=>P3.6��  <0xFB=>�ڲ���ѹ��׼ 
#define ECBM_CMP_INN 4
//<o>�Ƚ��������
//<i>�Ƚ������ֵ�����������ͨ���Ƚϡ�+���˺͡�-���˵ĵ�ѹֵ��С��Ȼ�󽫱ȽϽ���͵�����ˡ�
//<i>�����Ƚ����������������������һ��������������ñȽ�������ѡ�񲻶��������ֻ���жϷ����ѯ������ȽϽ����
//<i>������ġ�+���˵�ѹֵ�ȡ�-���˵�ѹֵ��ʱ���Ĵ����Ľ��Ϊ1����ѡ������������������������ߵ�ƽ����ѡ���˷�������������������͵�ƽ��
//<i>������ġ�+���˵�ѹֵ�ȡ�-���˵�ѹֵСʱ���Ĵ����Ľ��Ϊ0����ѡ������������������������͵�ƽ����ѡ���˷�������������������ߵ�ƽ��
//<0xFD=>��������� <0x02=>���������P3.4�� <0x03=>���������P4.1�� <0x06=>���������P3.4�� <0x07=>���������P4.1��
#define ECBM_CMP_OUT 253
//<o>�Ƚ����ж�
//<i>ʵ���������˵�ѹ����̫�����Ļ����жϻᱻ��������N�Ρ�ʹ��ʱ��ע�⡣
//<0x00=>�����ж� <0x20=>�ȽϽ����0���1ʱ�����ж� <0x10=>�ȽϽ����1���0ʱ�����ж� <0x30=>ֻҪ�ȽϽ�������仯���ᴥ���ж� 
#define ECBM_CMP_IT 0
//<q>��ʼ����ʱ�����Ƚ�����
//<i>��ѡ��ѡ�������ִ��cmp_init����ʱ�����Ƚ�����������ĳ���ض���ʱ��ſ������Ͳ���ѡ��ѡ�Ȼ�����Ǹ��ض���ʱ�����CMP_ON���ɡ�
#define ECBM_CMP_INIT_ON 1
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_CMP_LINK_EN
#include "ecbm.h"//ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
#else            //���Ҫ�����������У�ҲӦ���ṩSTC8��ͷ�ļ���ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ�
#include "stc.h" //��STC-ISP��������ʱ������ΪSTC.h��
#define u8 unsigned char
#endif


#define CMP_INP_D37  0xF7
#define CMP_INP_ADC  0x08

#define CMP_INN_D36  0x04
#define CMP_INN_BGV  0xFB

#define CMP_OUT_D34  0x02
#define CMP_OUT_D34N 0x06
#define CMP_OUT_D41  0x03
#define CMP_OUT_D41N 0x07
#define CMP_OUT_OFF  0xFD

#define CMP_IT_U   0x20
#define CMP_IT_D   0x10
#define CMP_IT_UD  0x30
#define CMP_IT_OFF 0x00


#define CMP_ON     CMPCR1|=0x80
#define CMP_OFF    CMPCR1&=0x7F
#define CMP_CLS_IT CMPCR1&=0xBF
#define CMP_FUN    interrupt 21


void cmp_init(){
	u8 reg;
	reg=CMPCR1;//����Ƶ�����ļĴ������ȶ��������档
	#if   ECBM_CMP_INP == CMP_INP_D37
	reg&=CMP_INP_D37;//����š�+��ѡ��ΪP3.7��
	#elif ECBM_CMP_INP == CMP_INP_ADC
	reg|=CMP_INP_ADC;//����š�-��ѡ��ΪADCת����
	#endif
	#if   ECBM_CMP_INN == CMP_INN_D36
	reg|=CMP_INN_D36;//����š�-��ѡ��ΪP3.6��
	#elif ECBM_CMP_INN == CMP_INN_BGV
	reg&=CMP_INN_BGV;//����š�-��ѡ��Ϊ�ڲ���ѹ��׼
	#endif
	#if   ECBM_CMP_OUT == CMP_OUT_D34
	reg|=(CMP_OUT_D34&0x02);//�����
	CMPCR2&=0x7F;			//�������
	P_SW2&=0xF7;			//D34
	#elif ECBM_CMP_OUT == CMP_OUT_D34N
	reg|=(CMP_OUT_D34N&0x02);//�����
	CMPCR2|=0x80;			 //�������
	P_SW2&=0xF7;			//D34
	#elif ECBM_CMP_OUT == CMP_OUT_D41
	reg|=(CMP_OUT_D41&0x02);//�����
	CMPCR2&=0x7F;			//�������
	P_SW2|=0x08;			//D41
	#elif ECBM_CMP_OUT == CMP_OUT_D41N
	reg|=(CMP_OUT_D41N&0x02);//�����
	CMPCR2|=0x80;			 //�������
	P_SW2|=0x08;			//D41
	#elif ECBM_CMP_OUT == CMP_OUT_OFF
	reg&=CMP_OUT_OFF;
	#endif
	CMPCR1=reg;//������������ñ�����
	CMPCR1&=0xCF;//����ж�λ
	#if   ECBM_CMP_IT == CMP_IT_U
	CMPCR1|=CMP_IT_U;//ʹ�ܽ��ֵ�������ж�
	#elif ECBM_CMP_IT == CMP_IT_D
	CMPCR1|=CMP_IT_D;//ʹ�ܽ��ֵ�½����ж�
	#elif ECBM_CMP_IT == CMP_IT_UD
	CMPCR1|=CMP_IT_UD;//ʹ�ܽ��ֵ�����ء��½��ض������ж�
	#elif ECBM_CMP_IT == CMP_IT_OFF
	CMPCR1|=CMP_IT_OFF;//�����жϣ������ϲ�Ҫ���Ҳ�С����Ŵ�����
	#endif
	CMPCR2&=0xBF;//ʹ������˲���
	CMPCR2|=0x3F;//�������˲������˲�ֵ����Ϊ���
	#if ECBM_CMP_INIT_ON
	CMP_ON;
	#endif
}
bit cmp_read(){
	if(CMPCR1&0x01)return 1;
	else return 0;	
}
//void cmp_set_it(u8 it){
//	CMPCR1&=0xCF;
//	CMPCR1|=it;
//}

#endif
