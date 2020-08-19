#ifndef _ECBM_PCA_H_
#define _ECBM_PCA_H_
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
�汾����BUGʱ������ϵ���߽����
                             **************************
                             * ��ϵ��ʽ����Ⱥ778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q.7>����ģʽ���Ƿ�ֹͣPCA����
//<i>��ѡ������ģʽ��PCAֹͣ������
//<i>����ѡ������ģʽ��PCA����������
//<o.1..3>PCA��������Դ
//<2=>��ʱ��0��������� <3=>ECI�ŵ��ⲿ����ʱ�� <4=>SYSCLK    <1=>SYSCLK/2 
//<5=>SYSCLK/4         <6=>SYSCLK/6           <7=>SYSCLK/8  <0=>SYSCLK/12 
//<q.0>PCA����������ж�ʹ��
#define ECBM_PCA_CMOD 0x08
//<e>PCA0
#define ECBM_PCA0_EN 0
//<q.6>����PCAģ��0�ıȽϹ���
//<q.5>����PCAģ��0���������ز���
//<q.4>����PCAģ��0�����½��ز���
//<q.3>����PCAģ��0��ƥ�书��
//<q.2>����PCAģ��0�ĸ��������������
//<q.1>����PCAģ��0����������������
//<q.0>����PCAģ��0��ƥ��/�����ж�
#define ECBM_PCA0_CCAPM0 0x00
//</e>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#include "ecbm_core.h"
#endif
