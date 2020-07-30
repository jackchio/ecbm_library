#ifndef _ECBM_PWM_H_
#define _ECBM_PWM_H_
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
//<h>STC8A����
//<h>PWM������
//<e.6>PWM�Ƿ��ADC����
//<i>PWM��ADC�������������PWM�����е�ĳ��ʱ��㴥��A/Dת����
//<i>ʹ��TADCPH��TADCPL�������á�
//<i>ʹ�ô˹���ʱ����ȷ��ADC�����Ѿ�������
#define ECBM_PWM_ETADC 0x00
//<o>����A/Dת����ʱ��
//<i>����PWM��������15λ�ģ��������뷶Χ��1~32767��
//<i>��PWM���������ֵ�ͱ�����ֵ���ʱ������A/Dת�������Ա�����ֵҲҪС��PWM������ֵ������PWM��Զ�޷�����A/Dת����
//<1-32767>
#define ECBM_PWM_TADCP 32767
//</e>
//<q.6>ʹ��PWM�����������ж�
//<i>ʹ��֮����PWM����������������ֵ������ʱ�����жϡ���ÿ��PWM���ڴ���һ���жϡ�
#define ECBM_PWM_ECBI 0x00
//<o>PWMʱ��ѡ��
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>��ʱ��2�����ʱ��
#define ECBM_PWM_CLK 0x00
//<o>PWM����
//<i>��������ʱ��Ϊ��λ����������100������PWM������Ϊ100��ʱ�ӡ�
//<i>Ҫ��֪�������ʱ�䣬���԰���PWMʱ��ѡ�񡱵�ѡ���STC-ISP���õ���ƵSYSclk�����㡣
//<i>��������240��SYSclk����12MHz��PWMʱ��ΪSYSclk/ 1����ô����Ϊ240/��12000000/1��=0.00002s=20us��
//<1-32767>
#define ECBM_PWM_C 2400
//<e.5>PWM�쳣���ʹ��
//<i>ʹ�ܸù��ܿ�����PWM�쳣ʱ��ʱ��һЩ����
//<q.3>�쳣����ж�ʹ��
//<i>�������쳣ʱ�����жϡ�
//<o.4>�쳣ʱIO����
//<0=>IO���治���κθı� <1=>IO����Ϊ����ģʽ
//<i>ֻ����Щʹ��PWM�����IO������PWM0û��ѡ�����PWM������ô�����쳣ʱP2.0�Ͳ��ᱻ����Ϊ����̬��
//<e.1>P3.5��ƽ�쳣���ʹ��
//<i>ʹ�ܸù��ܣ�������P3.5��ȡ��ȡ�쳣��Ϣ��
//<o.6>�쳣�ź�����
//<i>�����趨�쳣�źŵ���̬��
//<1=>��P3.5�ĵ�ƽ�ɸ߱��ʱ����Ϊ�쳣�ź�
//<0=>��P3.5�ĵ�ƽ�ɵͱ��ʱ����Ϊ�쳣�ź�
//</e>
//<e.2>�Ƚ�������쳣���ʹ��
//<i>ʹ�ܸù��ܣ������ñȽ����������ȡ�쳣��Ϣ��
//<o.7>�쳣�ź�����
//<i>�����趨�쳣�źŵ���̬��
//<1=>���Ƚ����Ľ���ɸ߱��ʱ����Ϊ�쳣�ź�
//<0=>���Ƚ����Ľ���ɵͱ��ʱ����Ϊ�쳣�ź�
//</e>
#define ECBM_PWM_FDCR 0xC0
//</e>
//</h>
//<e>PWM0ʹ�ܺͲ�������
#define ECBM_PWM0_EN 0
//<q.2>PWM0�ж�ʹ��
//<i>����PWM0�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM0T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM0T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM0�������
//<0=>P2.0 <1=>P1.0 <2=>P6.0 
#define ECBM_PWM0_CR 128
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM0_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM0_T2 21600
//</e>
//<e>PWM1ʹ�ܺͲ�������
#define ECBM_PWM1_EN 0
//<q.2>PWM1�ж�ʹ��
//<i>����PWM1�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM1T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM1T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM1�������
//<0=>P2.1 <1=>P1.1 <2=>P6.1 
#define ECBM_PWM1_CR 200
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM1_T1 800
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM1_T2 1400
//</e>
//<e>PWM2ʹ�ܺͲ�������
#define ECBM_PWM2_EN 0
//<q.2>PWM2�ж�ʹ��
//<i>����PWM2�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM2T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM2T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM2�������
//<0=>P2.2 <1=>P1.2 <2=>P6.2 
#define ECBM_PWM2_CR 136
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM2_T1 600
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM2_T2 1800
//</e>
//<e>PWM3ʹ�ܺͲ�������
#define ECBM_PWM3_EN 0
//<q.2>PWM3�ж�ʹ��
//<i>����PWM3�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM3T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM3T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM3�������
//<0=>P2.3 <1=>P1.3 <2=>P6.3 
#define ECBM_PWM3_CR 0
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM3_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM3_T2 0
//</e>
//<e>PWM4ʹ�ܺͲ�������
#define ECBM_PWM4_EN 0
//<q.2>PWM4�ж�ʹ��
//<i>����PWM4�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM4T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM4T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM4�������
//<0=>P2.4 <1=>P1.4 <2=>P6.4 
#define ECBM_PWM4_CR 0
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM4_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM4_T2 0
//</e>
//<e>PWM5ʹ�ܺͲ�������
#define ECBM_PWM5_EN 0

//<q.2>PWM5�ж�ʹ��
//<i>����PWM5�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM5T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM5T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM5�������
//<0=>P2.5 <1=>P1.5 <2=>P6.5 
#define ECBM_PWM5_CR 0
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM5_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM5_T2 0
//</e>
//<e>PWM6ʹ�ܺͲ�������
#define ECBM_PWM6_EN 0
//<q.2>PWM6�ж�ʹ��
//<i>����PWM6�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM6T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM6T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM6�������
//<0=>P2.6 <1=>P1.6 <2=>P6.6 
#define ECBM_PWM6_CR 0
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM6_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM6_T2 0
//</e>
//<e>PWM7ʹ�ܺͲ�������
#define ECBM_PWM7_EN 1

//<q.2>PWM7�ж�ʹ��
//<i>����PWM7�жϣ�������ʹ�������Ȼ��������ѡ���жϷ�ʽ
//<q.0>�ڵ�һ����ת���ж�
//<i>��PWM��������PWM7T1���ʱ����ƽ��ת���͵�ƽ�������жϡ�
//<q.1>�ڵڶ�����ת���ж�
//<i>��PWM��������PWM7T2���ʱ����ƽ��ת���ߵ�ƽ�������жϡ�
//<q.7>���PWM��
//<i>��Ȼ��PWMģ�飬���ǲ����PWM��Ҳ�ǿ��Եģ������ͳ��˶�ʱ��Ӧ���ˡ�
//<i>���ѡ�����PWM������Ҫ������ѡ�������IO�ڡ�
//<o.6>��ʼ��ƽ
//<0=>�͵�ƽ <1=>�ߵ�ƽ
//<i>���ǳ�ʼ��PWM֮��IO�ڳ��ֵĵ�ƽ��
//<o.3..4>PWM7�������
//<0=>P2.7 <1=>P1.7 <2=>P6.7 
#define ECBM_PWM7_CR 128
//<o>��һ����ת��
//<i>��PWM�������ﵽ��һ����ת��ʱ����IO��ת���͵�ƽ��
//<0-32767>
#define ECBM_PWM7_T1 0
//<o>�ڶ�����ת��
//<i>��PWM�������ﵽ�ڶ�����ת��ʱ����IO��ת���ߵ�ƽ��
//<i>����ڶ�����ת��͵�һ����ת��һ�£���ô�ڶ���ת��ᱻ���Ե���
//<0-32767>
#define ECBM_PWM7_T2 0
//</e>
//</h>
//<h>STC8G����(�жϺų��������ˣ������Ȳ��ź��ж��йص�����)
//<h>PWMȫ������
//<o.7>ȫ�ֹ��ܿ���
//<0=>6��PWM���ö������÷�ʽ
//<1=>6��PWM����ͳһ���÷�ʽ
#define ECBM_G_PWM_CONFIG 0x03
//</h>
//<e.0>P0��PWM����
#define ECBM_G_P0_EN 0x00
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM0_CKS 0x00
//<e.7>P0.0�ŵ�PWMʹ��
//<o.6>P0.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM00_CR 0x80
//</e>
//<e.7>P0.1�ŵ�PWMʹ��
//<o.6>P0.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM01_CR 0x00
//</e>
//<e.7>P0.2�ŵ�PWMʹ��
//<o.6>P0.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM02_CR 0x80
//</e>
//<e.7>P0.3�ŵ�PWMʹ��
//<o.6>P0.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM03_CR 0x00
//</e>
//<e.7>P0.4�ŵ�PWMʹ��
//<o.6>P0.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM04_CR 0x00
//</e>
//<e.7>P0.5�ŵ�PWMʹ��
//<o.6>P0.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM05_CR 0x00
//</e>
//<e.7>P0.6�ŵ�PWMʹ��
//<o.6>P0.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM06_CR 0x00
//</e>
//<e.7>P0.7�ŵ�PWMʹ��
//<o.6>P0.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM07_CR 0x00
//</e>
//</e>


//<e.1>P1��PWM����
#define ECBM_G_P1_EN 0x00
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM1_CKS 0x00
//<e.7>P1.0�ŵ�PWMʹ��
//<o.6>P1.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM10_CR 0x00
//</e>
//<e.7>P1.1�ŵ�PWMʹ��
//<o.6>P1.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM11_CR 0x00
//</e>
//<e.7>P1.2�ŵ�PWMʹ��
//<o.6>P1.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM12_CR 0x00
//</e>
//<e.7>P1.3�ŵ�PWMʹ��
//<o.6>P1.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM13_CR 0x00
//</e>
//<e.7>P1.4�ŵ�PWMʹ��
//<o.6>P1.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM14_CR 0x00
//</e>
//<e.7>P1.5�ŵ�PWMʹ��
//<o.6>P1.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM15_CR 0x00
//</e>
//<e.7>P1.6�ŵ�PWMʹ��
//<o.6>P1.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM16_CR 0x00
//</e>
//<e.7>P1.7�ŵ�PWMʹ��
//<o.6>P1.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM17_CR 0x80
//</e>
//</e>

//<e.2>P2��PWM����
#define ECBM_G_P2_EN 0x00
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM2_CKS 0x09
//<e.7>P2.0�ŵ�PWMʹ��
//<o.6>P2.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM20_CR 0x00
//</e>
//<e.7>P2.1�ŵ�PWMʹ��
//<o.6>P2.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM21_CR 0x00
//</e>
//<e.7>P2.2�ŵ�PWMʹ��
//<o.6>P2.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM22_CR 0x00
//</e>
//<e.7>P2.3�ŵ�PWMʹ��
//<o.6>P2.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM23_CR 0x00
//</e>
//<e.7>P2.4�ŵ�PWMʹ��
//<o.6>P2.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM24_CR 0x00
//</e>
//<e.7>P2.5�ŵ�PWMʹ��
//<o.6>P2.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM25_CR 0x00
//</e>
//<e.7>P2.6�ŵ�PWMʹ��
//<o.6>P2.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM26_CR 0x00
//</e>
//<e.7>P2.7�ŵ�PWMʹ��
//<o.6>P2.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM27_CR 0x00
//</e>
//</e>


//<e.3>P3��PWM����
#define ECBM_G_P3_EN 0x00
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM3_CKS 0x09
//<e.7>P3.0�ŵ�PWMʹ��
//<o.6>P3.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM30_CR 0x00
//</e>
//<e.7>P3.1�ŵ�PWMʹ��
//<o.6>P3.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM31_CR 0x00
//</e>
//<e.7>P3.2�ŵ�PWMʹ��
//<o.6>P3.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM32_CR 0x00
//</e>
//<e.7>P3.3�ŵ�PWMʹ��
//<o.6>P3.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM33_CR 0x00
//</e>
//<e.7>P3.4�ŵ�PWMʹ��
//<o.6>P3.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM34_CR 0x00
//</e>
//<e.7>P3.5�ŵ�PWMʹ��
//<o.6>P3.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM35_CR 0x00
//</e>
//<e.7>P3.6�ŵ�PWMʹ��
//<o.6>P3.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM36_CR 0x00
//</e>
//<e.7>P3.7�ŵ�PWMʹ��
//<o.6>P3.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM37_CR 0x00
//</e>
//</e>


//<e.4>P4��PWM����
#define ECBM_G_P4_EN 0x00
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM4_CKS 0x09
//<e.7>P4.0�ŵ�PWMʹ��
//<o.6>P4.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM40_CR 0x00
//</e>
//<e.7>P4.1�ŵ�PWMʹ��
//<o.6>P4.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM41_CR 0x00
//</e>
//<e.7>P4.2�ŵ�PWMʹ��
//<o.6>P4.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM42_CR 0x00
//</e>
//<e.7>P4.3�ŵ�PWMʹ��
//<o.6>P4.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM43_CR 0x00
//</e>
//<e.7>P4.4�ŵ�PWMʹ��
//<o.6>P4.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM44_CR 0x00
//</e>
//<e.7>P4.5�ŵ�PWMʹ��
//<o.6>P4.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM45_CR 0x00
//</e>
//<e.7>P4.6�ŵ�PWMʹ��
//<o.6>P4.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM46_CR 0x00
//</e>
//<e.7>P4.7�ŵ�PWMʹ��
//<o.6>P4.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM47_CR 0x00
//</e>
//</e>

//<e.5>P5��PWM����
#define ECBM_G_P5_EN 0x20
//<o.0..4>ʱ��ѡ��
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>��ʱ��2���������
#define ECBM_PWM5_CKS 0x00
//<e.7>P5.0�ŵ�PWMʹ��
//<o.6>P5.0�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM50_CR 0x80
//</e>
//<e.7>P5.1�ŵ�PWMʹ��
//<o.6>P5.1�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM51_CR 0x80
//</e>
//<e.7>P5.2�ŵ�PWMʹ��
//<o.6>P5.2�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM52_CR 0x80
//</e>
//<e.7>P5.3�ŵ�PWMʹ��
//<o.6>P5.3�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM53_CR 0x80
//</e>
//<e.7>P5.4�ŵ�PWMʹ��
//<o.6>P5.4�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM54_CR 0x00
//</e>
//<e.7>P5.5�ŵ�PWMʹ��
//<o.6>P5.5�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM55_CR 0x00
//</e>
//<e.7>P5.6�ŵ�PWMʹ��
//<o.6>P5.6�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM56_CR 0x00
//</e>
//<e.7>P5.7�ŵ�PWMʹ��
//<o.6>P5.7�ŵĳ�ʼ��ƽ
//<0=>�͵�ƽ
//<1=>�ߵ�ƽ
#define ECBM_PWM57_CR 0x00
//</e>
//</e>

//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"
/*---------------------------------------�궨��------------------------------------*/
#if   ECBM_MCU_MAIN_RAM == 1 //STC8A8K
	#define PWM_ON      do{PWMCR|=0x80;}while(0)//��PWM��
	#define PWM_OFF     do{PWMCR&=0x7F;}while(0)//�ر�PWM��
	#define PWM_CH0_ON  do{PWM0CR|=0x80;}while(0)//��PWM��ͨ��0��
	#define PWM_CH0_OFF do{PWM0CR&=0x7F;}while(0)//�ر�PWM��ͨ��0��
	#define PWM_CH0_1   do{PWM0HLD=0x02;}while(0)//PWM��ͨ��0ǿ������ߵ�ƽ��
	#define PWM_CH0_0   do{PWM0HLD=0x01;}while(0)//PWM��ͨ��0ǿ������͵�ƽ��
	#define PWM_CH0_OUT do{PWM0HLD=0x00;}while(0)//PWM��ͨ��0�ָ����PWM��״̬��

	#define PWM_CH1_ON  do{PWM1CR|=0x80;}while(0)//��PWM��ͨ��1��
	#define PWM_CH1_OFF do{PWM1CR&=0x7F;}while(0)//�ر�PWM��ͨ��1��
	#define PWM_CH1_1   do{PWM1HLD=0x02;}while(0)//PWM��ͨ��1ǿ������ߵ�ƽ��
	#define PWM_CH1_0   do{PWM1HLD=0x01;}while(0)//PWM��ͨ��1ǿ������͵�ƽ��
	#define PWM_CH1_OUT do{PWM1HLD=0x00;}while(0)//PWM��ͨ��1�ָ����PWM��״̬��

	#define PWM_CH2_ON  do{PWM2CR|=0x80;}while(0)//��PWM��ͨ��2��
	#define PWM_CH2_OFF do{PWM2CR&=0x7F;}while(0)//�ر�PWM��ͨ��2��
	#define PWM_CH2_1   do{PWM2HLD=0x02;}while(0)//PWM��ͨ��2ǿ������ߵ�ƽ��
	#define PWM_CH2_0   do{PWM2HLD=0x01;}while(0)//PWM��ͨ��2ǿ������͵�ƽ��
	#define PWM_CH2_OUT do{PWM2HLD=0x00;}while(0)//PWM��ͨ��2�ָ����PWM��״̬��

	#define PWM_CH3_ON  do{PWM3CR|=0x80;}while(0)//��PWM��ͨ��3��
	#define PWM_CH3_OFF do{PWM3CR&=0x7F;}while(0)//�ر�PWM��ͨ��3��
	#define PWM_CH3_1   do{PWM3HLD=0x02;}while(0)//PWM��ͨ��3ǿ������ߵ�ƽ��
	#define PWM_CH3_0   do{PWM3HLD=0x01;}while(0)//PWM��ͨ��3ǿ������͵�ƽ��
	#define PWM_CH3_OUT do{PWM3HLD=0x00;}while(0)//PWM��ͨ��3�ָ����PWM��״̬��

	#define PWM_CH4_ON  do{PWM4CR|=0x80;}while(0)//��PWM��ͨ��4��
	#define PWM_CH4_OFF do{PWM4CR&=0x7F;}while(0)//�ر�PWM��ͨ��4��
	#define PWM_CH4_1   do{PWM4HLD=0x02;}while(0)//PWM��ͨ��4ǿ������ߵ�ƽ��
	#define PWM_CH4_0   do{PWM4HLD=0x01;}while(0)//PWM��ͨ��4ǿ������͵�ƽ��
	#define PWM_CH4_OUT do{PWM4HLD=0x00;}while(0)//PWM��ͨ��4�ָ����PWM��״̬��

	#define PWM_CH5_ON  do{PWM5CR|=0x80;}while(0)//��PWM��ͨ��5��
	#define PWM_CH5_OFF do{PWM5CR&=0x7F;}while(0)//�ر�PWM��ͨ��5��
	#define PWM_CH5_1   do{PWM5HLD=0x02;}while(0)//PWM��ͨ��5ǿ������ߵ�ƽ��
	#define PWM_CH5_0   do{PWM5HLD=0x01;}while(0)//PWM��ͨ��5ǿ������͵�ƽ��
	#define PWM_CH5_OUT do{PWM5HLD=0x00;}while(0)//PWM��ͨ��5�ָ����PWM��״̬��

	#define PWM_CH6_ON  do{PWM6CR|=0x80;}while(0)//��PWM��ͨ��6��
	#define PWM_CH6_OFF do{PWM6CR&=0x7F;}while(0)//�ر�PWM��ͨ��6��
	#define PWM_CH6_1   do{PWM6HLD=0x02;}while(0)//PWM��ͨ��6ǿ������ߵ�ƽ��
	#define PWM_CH6_0   do{PWM6HLD=0x01;}while(0)//PWM��ͨ��6ǿ������͵�ƽ��
	#define PWM_CH6_OUT do{PWM6HLD=0x00;}while(0)//PWM��ͨ��6�ָ����PWM��״̬��

	#define PWM_CH7_ON  do{PWM7CR|=0x80;}while(0)//��PWM��ͨ��7��
	#define PWM_CH7_OFF do{PWM7CR&=0x7F;}while(0)//�ر�PWM��ͨ��7��
	#define PWM_CH7_1   do{PWM7HLD=0x02;}while(0)//PWM��ͨ��7ǿ������ߵ�ƽ��
	#define PWM_CH7_0   do{PWM7HLD=0x01;}while(0)//PWM��ͨ��7ǿ������͵�ƽ��
	#define PWM_CH7_OUT do{PWM7HLD=0x00;}while(0)//PWM��ͨ��7�ָ����PWM��״̬��
#elif   ECBM_MCU_MAIN_RAM == 2 //STC8G2K
	#define PWM_G_RST     do{PWMSET|=0x04;PWMSET=0x00;}while(0)
	#define	PWM_GPIO0_ON  do{PWMCFG01|=0x01;}while(0)
	#define	PWM_GPIO0_OFF do{PWMCFG01&=0xFE;}while(0)
	
	#define	PWM_GPIO1_ON  do{PWMCFG01|=0x10;}while(0)
	#define	PWM_GPIO1_OFF do{PWMCFG01&=0xEF;}while(0)
	
	#define	PWM_GPIO2_ON  do{PWMCFG23|=0x01;}while(0)
	#define	PWM_GPIO2_OFF do{PWMCFG23&=0xFE;}while(0)
	
	#define	PWM_GPIO3_ON  do{PWMCFG23|=0x10;}while(0)
	#define	PWM_GPIO3_OFF do{PWMCFG23&=0xEF;}while(0)
	
	#define	PWM_GPIO4_ON  do{PWMCFG45|=0x01;}while(0)
	#define	PWM_GPIO4_OFF do{PWMCFG45&=0xFE;}while(0)
	
	#define	PWM_GPIO5_ON  do{PWMCFG45|=0x10;}while(0)
	#define	PWM_GPIO5_OFF do{PWMCFG45&=0xEF;}while(0)
#endif
/*--------------------------------------������-----------------------------------*/
#if   ECBM_MCU_MAIN_RAM == 1 //STC8A8K
/*-------------------------------------------------------
��������pwm_init
��  ����PWM��ʼ��������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_init(void);
/*-------------------------------------------------------
��������pwm_set_freq
��  ����PWM����Ƶ�ʺ�����
��  �룺PWM�����Ƶ�ʡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_freq(u32 freq);
/*-------------------------------------------------------
��������pwm_set_cycle
��  ����PWM�������ں�����
��  �룺PWM��������ڡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_cycle(u32 cycle);
/*-------------------------------------------------------
��������pwm_set_duty
��  ����PWM����ռ�ձȺ�����һ���pwm_set_freq��������ʹ�á�
��  �룺id   -  Ҫ�����PWMͨ���š�
		duty -  ��ͨ����ռ�ձȣ���λ��ǧ��֮��������Ҫ����15.6%����д156��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_duty(u8 id,u16 duty);
/*-------------------------------------------------------
��������pwm_set_us
��  ����PWM���øߵ�ƽ����ʱ�亯����һ���pwm_set_cycle��������ʹ�á�
��  �룺id  -  Ҫ�����PWMͨ���š�
		us  -  ��ͨ���ĸߵ�ƽ����ʱ�䡣
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_us(u8 id,u32 us);
#elif    ECBM_MCU_MAIN_RAM == 2 //STC8G2K
/*-------------------------------------------------------
��������pwm_init
��  ����PWM��ʼ��������
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
2020-05-23���޸���STC8Gֻ��ʹ��һ����IO���PWM�����⡣
-------------------------------------------------------*/
void pwm_init(void);
/*-------------------------------------------------------
��������pwm_set_freq
��  ����PWM����Ƶ�ʺ�����
��  �룺PWM�����Ƶ�ʡ�
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_freq(u8 gpio,u32 freq);
/*-------------------------------------------------------
��������pwm_set_duty
��  ����PWM����ռ�ձȺ�����һ���pwm_set_freq��������ʹ�á�
��  �룺pin   -  Ҫ���PWM�����š�
		duty -  ��ͨ����ռ�ձȣ���λ��ǧ��֮��������Ҫ����15.6%����д156��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2020-01-08
�޸ļ�¼��
-------------------------------------------------------*/
void pwm_set_duty(u8 pin,u16 duty);
#endif
#endif
