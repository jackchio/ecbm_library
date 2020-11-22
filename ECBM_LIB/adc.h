#ifndef _ECBM_ADC_H_
#define _ECBM_ADC_H_
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
//<h>ͨ��ʹ������
//<i>ADC��ת����ʱ����ҪIO�Ǹ���ģʽ������������ʹ��֮�󣬻���adc_init�����а���Ӧ��IO�����óɸ���ģʽ��
//<i>��Щͨ�����ܺ�ĳЩ���Ż���Ӱ�죬�ᵼ�²��������׼�������뿴STC�������ֲᡣ
//<q>ͨ��0
//<i>STC8A4KxxS2A12_ALL    :P1.0
//<i>STC8A8KxxS4A12_ALL    :P1.0
//<i>STC8G1Kxx_16PIN_20PIN :P1.0
//<i>STC8G1KxxA_8PIN       :P3.0
//<i>STC8G1KxxT_20PIN      :P1.0
//<i>STC8G2KxxS2_ALL       :P1.0
//<i>STC8G2KxxS4_ALL       :P1.0
//<i>STC8H1Kxx_20PIN       :P1.0
//<i>STC8H1Kxx_32PIN       :P1.0
//<i>STC8H2KxxT_48PIN      :P1.0
//<i>STC8H3KxxS2_48PIN     :P1.0
//<i>STC8H3KxxS4_48PIN     :P1.0
//<i>STC8H8KxxU_48PIN_64PIN:P1.0
#define ECBM_ADC_CH0 1
//<q>ͨ��1
//<i>STC8A4KxxS2A12_ALL    :P1.1
//<i>STC8A8KxxS4A12_ALL    :P1.1
//<i>STC8G1Kxx_16PIN_20PIN :P1.1
//<i>STC8G1KxxA_8PIN       :P3.1
//<i>STC8G1KxxT_20PIN      :P1.1
//<i>STC8G2KxxS2_ALL       :P1.1
//<i>STC8G2KxxS4_ALL       :P1.1
//<i>STC8H1Kxx_20PIN       :P1.1
//<i>STC8H1Kxx_32PIN       :P1.1
//<i>STC8H2KxxT_48PIN      :P1.1
//<i>STC8H3KxxS2_48PIN     :P1.1
//<i>STC8H3KxxS4_48PIN     :P1.1
//<i>STC8H8KxxU_48PIN_64PIN:P1.1
#define ECBM_ADC_CH1 0
//<q>ͨ��2
//<i>STC8A4KxxS2A12_ALL    :P1.2
//<i>STC8A8KxxS4A12_ALL    :P1.2
//<i>STC8G1Kxx_16PIN_20PIN :P1.2
//<i>STC8G1KxxA_8PIN       :P3.2
//<i>STC8G1KxxT_20PIN      :P5.4
//<i>STC8G2KxxS2_ALL       :P1.2
//<i>STC8G2KxxS4_ALL       :P1.2
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P1.2
//<i>STC8H2KxxT_48PIN      :��
//<i>STC8H3KxxS2_48PIN     :P1.2
//<i>STC8H3KxxS4_48PIN     :P1.2
//<i>STC8H8KxxU_48PIN_64PIN:P5.4
#define ECBM_ADC_CH2 0
//<q>ͨ��3
//<i>STC8A4KxxS2A12_ALL    :P1.3
//<i>STC8A8KxxS4A12_ALL    :P1.3
//<i>STC8G1Kxx_16PIN_20PIN :P1.3
//<i>STC8G1KxxA_8PIN       :P3.3
//<i>STC8G1KxxT_20PIN      :P1.3
//<i>STC8G2KxxS2_ALL       :P1.3
//<i>STC8G2KxxS4_ALL       :P1.3
//<i>STC8H1Kxx_20PIN       :P3.0
//<i>STC8H1Kxx_32PIN       :P1.3
//<i>STC8H2KxxT_48PIN      :P1.3
//<i>STC8H3KxxS2_48PIN     :��
//<i>STC8H3KxxS4_48PIN     :��
//<i>STC8H8KxxU_48PIN_64PIN:P1.3
#define ECBM_ADC_CH3 0
//<q>ͨ��4
//<i>STC8A4KxxS2A12_ALL    :P1.4
//<i>STC8A8KxxS4A12_ALL    :P1.4
//<i>STC8G1Kxx_16PIN_20PIN :P1.4
//<i>STC8G1KxxA_8PIN       :P5.4
//<i>STC8G1KxxT_20PIN      :P1.4
//<i>STC8G2KxxS2_ALL       :P1.4
//<i>STC8G2KxxS4_ALL       :P1.4
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P1.4
//<i>STC8H2KxxT_48PIN      :P1.4
//<i>STC8H3KxxS2_48PIN     :��
//<i>STC8H3KxxS4_48PIN     :��
//<i>STC8H8KxxU_48PIN_64PIN:P1.4
#define ECBM_ADC_CH4 0
//<q>ͨ��5
//<i>STC8A4KxxS2A12_ALL    :P1.5
//<i>STC8A8KxxS4A12_ALL    :P1.5
//<i>STC8G1Kxx_16PIN_20PIN :P1.5
//<i>STC8G1KxxA_8PIN       :P5.5
//<i>STC8G1KxxT_20PIN      :P1.5
//<i>STC8G2KxxS2_ALL       :P1.5
//<i>STC8G2KxxS4_ALL       :P1.5
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P1.5
//<i>STC8H2KxxT_48PIN      :P1.5
//<i>STC8H3KxxS2_48PIN     :��
//<i>STC8H3KxxS4_48PIN     :��
//<i>STC8H8KxxU_48PIN_64PIN:P1.5
#define ECBM_ADC_CH5 0
//<q>ͨ��6
//<i>STC8A4KxxS2A12_ALL    :P1.6
//<i>STC8A8KxxS4A12_ALL    :P1.6
//<i>STC8G1Kxx_16PIN_20PIN :P1.6
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P1.6
//<i>STC8G2KxxS2_ALL       :P1.6
//<i>STC8G2KxxS4_ALL       :P1.6
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P1.6
//<i>STC8H2KxxT_48PIN      :P1.6
//<i>STC8H3KxxS2_48PIN     :P1.6
//<i>STC8H3KxxS4_48PIN     :P1.6
//<i>STC8H8KxxU_48PIN_64PIN:P1.6
#define ECBM_ADC_CH6 0
//<q>ͨ��7
//<i>STC8A4KxxS2A12_ALL    :P1.7
//<i>STC8A8KxxS4A12_ALL    :P1.7
//<i>STC8G1Kxx_16PIN_20PIN :P1.7
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P1.7
//<i>STC8G2KxxS2_ALL       :P1.7
//<i>STC8G2KxxS4_ALL       :P1.7
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P1.7
//<i>STC8H2KxxT_48PIN      :P1.7
//<i>STC8H3KxxS2_48PIN     :P1.7
//<i>STC8H3KxxS4_48PIN     :P1.7
//<i>STC8H8KxxU_48PIN_64PIN:P1.7
#define ECBM_ADC_CH7 0
//<q>ͨ��8
//<i>STC8A4KxxS2A12_ALL    :P0.0
//<i>STC8A8KxxS4A12_ALL    :P0.0
//<i>STC8G1Kxx_16PIN_20PIN :P3.0
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.0
//<i>STC8G2KxxS2_ALL       :P0.0
//<i>STC8G2KxxS4_ALL       :P0.0
//<i>STC8H1Kxx_20PIN       :��
//<i>STC8H1Kxx_32PIN       :P0.0
//<i>STC8H2KxxT_48PIN      :P0.0
//<i>STC8H3KxxS2_48PIN     :P0.0
//<i>STC8H3KxxS4_48PIN     :P0.0
//<i>STC8H8KxxU_48PIN_64PIN:P0.0
#define ECBM_ADC_CH8 0
//<q>ͨ��9
//<i>STC8A4KxxS2A12_ALL    :P0.1
//<i>STC8A8KxxS4A12_ALL    :P0.1
//<i>STC8G1Kxx_16PIN_20PIN :P3.1
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.1
//<i>STC8G2KxxS2_ALL       :P0.1
//<i>STC8G2KxxS4_ALL       :P0.1
//<i>STC8H1Kxx_20PIN       :P3.1
//<i>STC8H1Kxx_32PIN       :P0.1
//<i>STC8H2KxxT_48PIN      :P0.1
//<i>STC8H3KxxS2_48PIN     :P0.1
//<i>STC8H3KxxS4_48PIN     :P0.1
//<i>STC8H8KxxU_48PIN_64PIN:P0.1
#define ECBM_ADC_CH9 0
//<q>ͨ��10
//<i>STC8A4KxxS2A12_ALL    :P0.2
//<i>STC8A8KxxS4A12_ALL    :P0.2
//<i>STC8G1Kxx_16PIN_20PIN :P3.2
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.2
//<i>STC8G2KxxS2_ALL       :P0.2
//<i>STC8G2KxxS4_ALL       :P0.2
//<i>STC8H1Kxx_20PIN       :P3.2
//<i>STC8H1Kxx_32PIN       :P0.2
//<i>STC8H2KxxT_48PIN      :P0.2
//<i>STC8H3KxxS2_48PIN     :P0.2
//<i>STC8H3KxxS4_48PIN     :P0.2
//<i>STC8H8KxxU_48PIN_64PIN:P0.2
#define ECBM_ADC_CH10 0
//<q>ͨ��11
//<i>STC8A4KxxS2A12_ALL    :P0.3
//<i>STC8A8KxxS4A12_ALL    :P0.3
//<i>STC8G1Kxx_16PIN_20PIN :P3.3
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.3
//<i>STC8G2KxxS2_ALL       :P0.3
//<i>STC8G2KxxS4_ALL       :P0.3
//<i>STC8H1Kxx_20PIN       :P3.3
//<i>STC8H1Kxx_32PIN       :P0.3
//<i>STC8H2KxxT_48PIN      :P0.3
//<i>STC8H3KxxS2_48PIN     :P0.3
//<i>STC8H3KxxS4_48PIN     :P0.3
//<i>STC8H8KxxU_48PIN_64PIN:P0.3
#define ECBM_ADC_CH11 0
//<q>ͨ��12
//<i>STC8A4KxxS2A12_ALL    :P0.4
//<i>STC8A8KxxS4A12_ALL    :P0.4
//<i>STC8G1Kxx_16PIN_20PIN :P3.4
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.4
//<i>STC8G2KxxS2_ALL       :P0.4
//<i>STC8G2KxxS4_ALL       :P0.4
//<i>STC8H1Kxx_20PIN       :P3.4
//<i>STC8H1Kxx_32PIN       :��
//<i>STC8H2KxxT_48PIN      :P0.4
//<i>STC8H3KxxS2_48PIN     :P0.4
//<i>STC8H3KxxS4_48PIN     :P0.4
//<i>STC8H8KxxU_48PIN_64PIN:P0.4
#define ECBM_ADC_CH12 0
//<q>ͨ��13
//<i>STC8A4KxxS2A12_ALL    :P0.5
//<i>STC8A8KxxS4A12_ALL    :P0.5
//<i>STC8G1Kxx_16PIN_20PIN :P3.5
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.5
//<i>STC8G2KxxS2_ALL       :P0.5
//<i>STC8G2KxxS4_ALL       :P0.5
//<i>STC8H1Kxx_20PIN       :P3.5
//<i>STC8H1Kxx_32PIN       :��
//<i>STC8H2KxxT_48PIN      :P0.5
//<i>STC8H3KxxS2_48PIN     :P0.5
//<i>STC8H3KxxS4_48PIN     :P0.5
//<i>STC8H8KxxU_48PIN_64PIN:P0.5
#define ECBM_ADC_CH13 0
//<q>ͨ��14
//<i>STC8A4KxxS2A12_ALL    :P0.6
//<i>STC8A8KxxS4A12_ALL    :P0.6
//<i>STC8G1Kxx_16PIN_20PIN :P3.6
//<i>STC8G1KxxA_8PIN       :��
//<i>STC8G1KxxT_20PIN      :P3.6
//<i>STC8G2KxxS2_ALL       :P0.6
//<i>STC8G2KxxS4_ALL       :P0.6
//<i>STC8H1Kxx_20PIN       :P3.6
//<i>STC8H1Kxx_32PIN       :��
//<i>STC8H2KxxT_48PIN      :P0.6
//<i>STC8H3KxxS2_48PIN     :P0.6
//<i>STC8H3KxxS4_48PIN     :P0.6
//<i>STC8H8KxxU_48PIN_64PIN:P0.6
#define ECBM_ADC_CH14 0
//</h>
//<h>ADC��������
//<o.0..3>ADC�ķ�Ƶϵ��
//<6-15>
//<i>���������ADC��ת���ٶȡ���������0~15����Ӧ1��Ƶ��16��Ƶ��
//<i>����ʵ������6���µ�Ч���ܲ��������ֻ������6���ϵġ�
//<i>ADC�Ĳ�����=SYSCLK/2/16/��Ƶϵ����
//<o.5>ADC�Ķ��뷽ʽ
//<0=>����� <1=>�Ҷ���
//<i>�����Ϊ�������Ҷ������֣����������ʵ����˵�����ֶ������;��
//<i>����룺ADC_RES�������ĸ�8λ��ADC_RESL�������ĵ�4λ������12λADC��˵����
//<i>�����Ĳ���Ϊ[D11 D10 D9 D8 D7 D6 D5 D4][D3 D2 D1 D0 0 0 0 0]��ȡֵ��ΧΪ0~65520������ֵΪ16��ֱ�Ӱ������Ĵ���ƴ��һ���16λ���ݵĻ���ʹ���ϻ���Щ���㡣
//<i>���ǿ��ǵ�ADC��ת��ʱ�����ڵ�Դ���ȵ�ԭ����������ݵ�λ�����������Ŀ����Ҫ����̫��ȴҪ�������ȶ��Ļ�����������Բ�������˲���ֱ��������4λ���ɡ�
//<i>�Ҷ��룺ADC_RES�������ĸ�4λ������12λADC��˵����ADC_RESL�������ĵ�8λ��
//<i>�Ҷ���Ĳ���Ϊ[0 0 0 0 D11 D10 D9 D8][D7 D6 D5 D4 D3 D2 D1 D0]��ȡֵ��ΧΪ0~4095������ֵΪ1��
//<i>�������һ�ȽϾ�֪���Ҷ���ģʽ�¿���ֱ�Ӱ������Ĵ������ƴ��һ����Ϊһ��16λ������ʹ�á�
#define ECBM_ADC_SPEED 15
//<q>������λ����
//<i>��������Ľ��⣬���ȷʵ��Ҫ������λ���ݣ��빴ѡ��ѡ�֮��adc_read������ֻ���ADC_RES��ֵ��ADC_RESL��ֵ�ᱻ��ȥ��
#define ECBM_ADC_8BIT 0
//<q>ADC�ж�
#define ECBM_ADC_IT_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
/*#####################################ADCλ������##################################*/
#if			(ECBM_MCU&0x0000F0)==0x0000C0
#  define   ECBM_MCU_ADC_MAX  4096.0f
#elif		(ECBM_MCU&0x0000F0)==0x0000A0
#  define   ECBM_MCU_ADC_MAX  1024.0f
#else
#  define   ECBM_MCU_ADC_MAX  1.0f//��ֹ�ն���
#endif
/*#####################################ADCͨ������#################################*/
#if			ECBM_MCU	==	0x2405C2//STC8A4KxxS2A12_ALL
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x2805C4//STC8A8KxxS4A12_ALL 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x3103A2//STC8G1Kxx_16PIN_20PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x30
#  define   A09 0x31
#  define   A10 0x32
#  define   A11 0x33
#  define   A12 0x34
#  define   A13 0x35
#  define   A14 0x36
#elif		ECBM_MCU	==	0x3102A1//STC8G1KxxA_8PIN 
#  define   A00 0x30
#  define   A01 0x31
#  define   A02 0x32
#  define   A03 0x33
#  define   A04 0x54
#  define   A05 0x55
#elif		ECBM_MCU	==	0x3103A1//STC8G1KxxT_20PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x54
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x30
#  define   A09 0x31
#  define   A10 0x32
#  define   A11 0x33
#  define   A12 0x34
#  define   A13 0x35
#  define   A14 0x36
#elif		ECBM_MCU	==	0x3205A2//STC8G2KxxS2_ALL 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x3205A4//STC8G2KxxS4_ALL 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x4103A2//STC8H1Kxx_20PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A08 0x30
#  define   A09 0x31
#  define   A10 0x32
#  define   A11 0x33
#  define   A12 0x34
#  define   A13 0x35
#  define   A14 0x36
#elif		ECBM_MCU	==	0x4105A2//STC8H1Kxx_32PIN  
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#elif		ECBM_MCU	==	0x4205C4//STC8H2KxxT_48PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x4305C2//STC8H3KxxS2_48PIN  
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x4305C4//STC8H3KxxS4_48PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x12
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#elif		ECBM_MCU	==	0x4805C4//STC8H8KxxU_48PIN_64PIN 
#  define   A00 0x10
#  define   A01 0x11
#  define   A02 0x54
#  define   A03 0x13
#  define   A04 0x14
#  define   A05 0x15
#  define   A06 0x16
#  define   A07 0x17
#  define   A08 0x00
#  define   A09 0x01
#  define   A10 0x02
#  define   A11 0x03
#  define   A12 0x04
#  define   A13 0x05
#  define   A14 0x06
#endif
/*--------------------------------------��������-----------------------------------*/
extern float xdata adc_ch15;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������adc_init
��  ����ADC��ʼ����������������ADC�������ã�����Ӧ��IO���óɸ��衣
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�adc_init();//��ʼ��ADC
�������ڣ�2019-7-31
�޸ļ�¼��
2019-8-5���������ж�ʹ�ܺ��ж����ȼ����á�
-------------------------------------------------------*/
extern void adc_init(void);
/*-------------------------------------------------------
��������adc_read
��  ������ѯ����ȡADֵ���������ڰ�ĳͨ����Ӧ��IO�ڵ�ѹֵת����ADֵ��
��  �룺Ҫ��ȡ��ͨ���ţ�������0~15��
��  ������
����ֵ����ͨ����ADֵ���ɷ���8λ���ݻ���12λ���ݣ����������á�
�����ߣ�����
�������̣�val=adc_read(0);//��ȡͨ��0��ADֵ��
�������ڣ�2019-7-31
�޸ļ�¼��
2020-07-28��ֻ����һ������
-------------------------------------------------------*/
extern u16 adc_read(u8 ch);
/*-------------------------------------------------------
��������adc_read_start
��  ����ADCת����ʼ�������жϷ��������ڿ�����ĳͨ����Ӧ��IO�ڵ�ѹ��ת�����ú���ֻ��ʼһ��ת�������������ϵõ������
��  �룺Ҫ��ȡ��ͨ���ţ�������0~15��
��  ������
����ֵ����
�����ߣ�����
�������̣�adc_read_start(0);//׼����ȡͨ��0��ADֵ�����жϺ����ж�ȡADCת�������
�������ڣ�2019-8-5
�޸ļ�¼��
-------------------------------------------------------*/
extern void adc_read_start(u8 ch);
/*-------------------------------------------------------
��������adc_read_it
��  �����жϷ���ȡADֵ��������ADC�ж��е��ñ��������ɵõ�ADCת���Ľ����ת����ͨ����adc_read_start�������á�
��  �룺��
��  ������
����ֵ����ͨ����ADֵ��
�����ߣ�����
�������̣�//�������Ƿ����жϺ����еġ�
	void adc_it_fun() ADC_FUN	//ADC�жϺ���
	{
		ADC_CLS_IT;				//�����Ӧ���жϱ�־λ��
		val=adc_read_it();		//��ȡת�����ADֵ��
	}
�������ڣ�2019-8-5
�޸ļ�¼��
2020-07-28��ֻ����һ������
-------------------------------------------------------*/
extern u16 adc_read_it();
/*-------------------------------------------------------
��������adc_voltage
��  ������ȡ��ѹ���������ڶ�ȡĳͨ����Ӧ��IO�ڵ�ѹֵ��
��  �룺
       ch   - Ҫ��ȡ��ͨ���ţ�������0~15��
       vref - adc��vref��ѹ�����ʵ��õ���
��  ������
����ֵ����ͨ���ĵ�ѹֵ��
�����ߣ�����
�������̣�val=adc_voltage(0,3.299);//��ȡͨ��0�ĵ�ѹֵ��vref��3.299V��
�������ڣ�2019-7-31
�޸ļ�¼��
-------------------------------------------------------*/
extern float adc_voltage(u8 ch,float vref);
/*-------------------------------------------------------
��������adc_it_start
��  ��������ADC�жϺ��������ڴ�ADC���жϡ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�adc_it_start();//����ADC���жϡ�
�������ڣ�2019-8-5
�޸ļ�¼��
-------------------------------------------------------*/
extern void adc_it_start();
/*-------------------------------------------------------
��������adc_it_stop
��  �����ر�ADC�жϺ��������ڹر�ADC���жϡ�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�adc_it_stop();//�ر�ADC���жϡ�
�������ڣ�2019-8-5
�޸ļ�¼��
-------------------------------------------------------*/
extern void adc_it_stop();
/*-------------------------------------------------------
��������adc_read_vref
��  ����ADC��ȡVref������
��  �룺��
��  ������
����ֵ��Vref�ĵ�ѹֵ����λV��
�����ߣ�����
�������̣���
�������ڣ�2019-8-5
�޸ļ�¼��
-------------------------------------------------------*/
extern float adc_read_vref(void);
#endif
