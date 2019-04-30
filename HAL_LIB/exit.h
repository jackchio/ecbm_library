#ifndef _ECBM_EXIT_H_
#define _ECBM_EXIT_H_
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
//<i>��ѡ��򹴣���ζ��EXIT���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣
//<i>��ѡ��򹴣���ζ��EXIT���ܵ���ʹ�ã���������������ECBM�⺯����ֻ��Ҫ�߱�������stc8ͷ�ļ����ɡ�����ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����exit.h����ͬһ���ļ��С�
#define ECBM_EXIT_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ���ⲿ�жϣ�����Ϊ0��
//<h>�Ż�����
//<i>������ѡ��Ҫʹ���ⲿ�жϡ������ò������ⲿ�жϾͲ�����룬��Լflash�ռ䡣
//<e>�ⲿ�ж�0
#define ECBM_EXIT0_EN 0
//</e>
//<e>�ⲿ�ж�1
#define ECBM_EXIT1_EN 0
//</e>
//<e>�ⲿ�ж�2
#define ECBM_EXIT2_EN 0
//</e>
//<e>�ⲿ�ж�3
#define ECBM_EXIT3_EN 0
//</e>
//<e>�ⲿ�ж�4
#define ECBM_EXIT4_EN 0
//</e>
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------

/*---------------------------------------------����ͷ�ļ���Ԥ����---------------------------------------------*/
#if ECBM_EXIT_LINK_EN
#include "ecbm.h"         //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
#else                     //���Ҫ�����������У�ҲӦ���ṩSTC8��ͷ�ļ���ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ�
#include "stc.h"          //��STC-ISP��������ʱ������ΪSTC.h��
#include "intrins.h"      //ʹ��nopָ�������ͷ�ļ�
#define u8  unsigned char
#endif
/*-----------------------------------------------------------------------------------------------------------*/
typedef struct{
	u8 exit_num:3; //����ⲿ�жϵı�ţ�0~4��
	u8 exit_mode:1;//��ŵ�ǰ�ⲿ�жϵ��жϷ�ʽ�������������ⲿ�ж϶�������ѡ���жϷ�ʽ��
	u8 exit_status:1;//��ŵ�ǰ�ⲿ�жϵ�ʹ��״̬��
}exit_def;
typedef enum{
	exit0,//�ⲿ�ж�0
	exit1,//�ⲿ�ж�1
	exit2,//�ⲿ�ж�2
	exit3,//�ⲿ�ж�3
	exit4 //�ⲿ�ж�4	
}exit_num_def;
typedef enum{
	r_f_edge, //������/�½��ض����Դ����жϡ�
	f_edge	  //ֻ���½��ؿ��Դ����жϡ�
}exit_mode_def;
#define INT0_FUN interrupt 0   //�жϺţ��������жϺ���֮���жϺ������û��Զ���
#define INT0_ON  EX0=1         //���ⲿ�ж�0
#define INT0_OFF EX0=0         //�ر��ⲿ�ж�0
#define INT0_UD  IT0=0         //�ⲿ�ж�0ͨ�������غ��½��ش���
#define INT0_D   IT0=1         //�ⲿ�ж�0ͨ���½��ش���
#define INT0_IO  P32           //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
#define INT1_FUN interrupt 2   //�жϺţ��������жϺ���֮���жϺ������û��Զ���
#define INT1_ON  EX1=1         //���ⲿ�ж�1
#define INT1_OFF EX1=0         //�ر��ⲿ�ж�1
#define INT1_UD  IT1=0         //�ⲿ�ж�1ͨ�������غ��½��ش���
#define INT1_D   IT1=1         //�ⲿ�ж�1ͨ���½��ش���
#define INT1_IO  P33           //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
#define INT2_FUN interrupt 10  //�жϺţ��������жϺ���֮���жϺ������û��Զ���
#define INT2_ON  INTCLKO|=EX2  //���ⲿ�ж�2
#define INT2_OFF INTCLKO&=~EX2 //�ر��ⲿ�ж�2
#define INT3_FUN interrupt 11  //�жϺţ��������жϺ���֮���жϺ������û��Զ���
#define INT3_ON  INTCLKO|=EX3  //���ⲿ�ж�3
#define INT3_OFF INTCLKO&=~EX3 //�ر��ⲿ�ж�3
#define INT4_FUN interrupt 16  //�жϺţ��������жϺ���֮���жϺ������û��Զ���
#define INT4_ON  INTCLKO|=EX4  //���ⲿ�ж�4
#define INT4_OFF INTCLKO&=~EX4 //�ر��ⲿ�ж�4
void exit_init (exit_def * exit_inf,exit_num_def exit_num,exit_mode_def exit_mode){
	exit_inf->exit_num=exit_num;
	exit_inf->exit_mode=exit_mode;
	exit_inf->exit_status=1;
	switch(exit_num){
		#if ECBM_EXIT0_EN
		case exit0:{                   //�ⲿ�ж�0����P32�ڡ���ѡ�񴥷���ʽ
			P3M1&=0xFB;                //����P32Ϊ����״̬
			P3M0&=0xFB;                //P3.2(11111011B,11111011B)
			P32=1;                     //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ
			if(exit_mode==r_f_edge){
				INT0_UD;               //����������/�½����ж�
			}else if(exit_mode==f_edge){
				INT0_D;                //�����½����ж�
			}
			INT0_ON;                   //���ⲿ�ж�0
		}break;
		#endif
		#if ECBM_EXIT1_EN
		case exit1:{                   //�ⲿ�ж�1����P33�ڡ���ѡ�񴥷���ʽ
			P3M1&=0xF7;                //����P33Ϊ����״̬
			P3M0&=0xF7;                //P3.3(11110111B,11110111B)
			P33=1;                     //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ
			if(exit_mode==r_f_edge){
				INT1_UD;               //����������/�½����ж�
			}else if(exit_mode==f_edge){
				INT1_D;                //�����½����ж�
			}
			INT1_ON;                   //���ⲿ�ж�1
		}break;
		#endif
		#if ECBM_EXIT2_EN
		case exit2:{                   //�ⲿ�ж�2����P36��
			P3M1&=0xBF;                //����P36Ϊ����״̬
			P3M0&=0xBF;                //P3.6(10111111B,10111111B)
			P36=1;                     //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ
			INT2_ON;                   //���ⲿ�ж�2
		}break;
		#endif
		#if ECBM_EXIT3_EN
		case exit3:{                   //�ⲿ�ж�3����P37��
			P3M1&=0x7F;                //����P37Ϊ����״̬
			P3M0&=0x7F;                //P3.7(01111111B,01111111B)
			P37=1;                     //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ		
			INT3_ON;                   //���ⲿ�ж�3
		}break;
		#endif
		#if ECBM_EXIT4_EN
		case exit4:{                   //�ⲿ�ж�4����P30��
			P3M1&=0xFE;                //����P30Ϊ����״̬
			P3M0&=0xFE;                //P3.0(11111110B,11111110B)
			P30=1;                     //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ
			INT4_ON;                   //���ⲿ�ж�4
		}break;
		#endif
	}
	#if ECBM_EXIT_LINK_EN  == 0
	_nop_();EA=1;_nop_();              //�����ж�
	#endif
}
void exit_start(exit_def * exit_inf){
	exit_inf->exit_status=1;
	switch(exit_inf->exit_num){
		#if ECBM_EXIT0_EN
		case exit0:INT0_ON;break;      //���ⲿ�ж�0
		#endif
		#if ECBM_EXIT1_EN
		case exit1:INT1_ON;break;      //���ⲿ�ж�1
		#endif
		#if ECBM_EXIT2_EN
		case exit2:INT2_ON;break;      //���ⲿ�ж�2
		#endif
		#if ECBM_EXIT3_EN
		case exit3:INT3_ON;break;      //���ⲿ�ж�3
		#endif
		#if ECBM_EXIT4_EN
		case exit4:INT4_ON;break;      //���ⲿ�ж�4
		#endif
	}
}
void exit_stop (exit_def * exit_inf){
	exit_inf->exit_status=0;
	switch(exit_inf->exit_num){
		#if ECBM_EXIT0_EN
		case exit0:INT0_OFF;break;      //�ر��ⲿ�ж�0
		#endif
		#if ECBM_EXIT1_EN
		case exit1:INT1_OFF;break;      //�ر��ⲿ�ж�1
		#endif
		#if ECBM_EXIT2_EN
		case exit2:INT2_OFF;break;      //�ر��ⲿ�ж�2
		#endif
		#if ECBM_EXIT3_EN
		case exit3:INT3_OFF;break;      //�ر��ⲿ�ж�3
		#endif
		#if ECBM_EXIT4_EN
		case exit4:INT4_OFF;break;      //�ر��ⲿ�ж�4
		#endif
	}
}
#endif
