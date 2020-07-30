#include "ecbm_core.h"
#if ECBM_EXTI_EN
/*--------------------------------------������-----------------------------------*/
/*------------------------------------------------------
�ⲿ�жϳ�ʼ��������
-------------------------------------------------------*/
void exti_init(void){
	#if ECBM_EXTI0_EN    //�ⲿ�ж�0����P32�ڡ���ѡ�񴥷���ʽ��
		P3M1&=0xFB;      //����P32Ϊ����״̬��
		P3M0&=0xFB;      //P3.2(11111011B,11111011B)��
		P32=1;           //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
		#if ECBM_EXTI0_MODE == 0 //ͨ��������Ϣ�ж�	��	
			EXTI0_UD;    //����������/�½����жϡ�
		#else
			EXTI0_D;     //�����½����жϡ�
		#endif
		#if ECBM_EXTI0_INIT
			EXTI0_ON;    //���ⲿ�ж�0��
		#endif
	#endif
	
	#if ECBM_EXTI1_EN    //�ⲿ�ж�1����P33�ڡ���ѡ�񴥷���ʽ��           
		P3M1&=0xF7;      //����P33Ϊ����״̬��
		P3M0&=0xF7;      //P3.3(11110111B,11110111B)��
		P33=1;           //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
		#if ECBM_EXTI1_MODE == 0 //ͨ��������Ϣ�жϡ�	
			EXTI1_UD;    //����������/�½����жϡ�
		#else
			EXTI1_D;     //�����½����жϡ�
		#endif
		#if ECBM_EXTI1_INIT
			EXTI1_ON;    //���ⲿ�ж�1��
		#endif
	#endif
	
	#if ECBM_EXTI2_EN    //�ⲿ�ж�2����P36�ڡ�           
		P3M1&=0xBF;      //����P36Ϊ����״̬��
		P3M0&=0xBF;      //P3.6(10111111B,10111111B)��
		P36=1;           //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
		#if ECBM_EXTI2_INIT
			EXTI2_ON;    //���ⲿ�ж�2��
		#endif
	#endif
	
	#if ECBM_EXTI3_EN    //�ⲿ�ж�3����P37�ڡ�              
		P3M1&=0x7F;      //����P37Ϊ����״̬��
		P3M0&=0x7F;      //P3.7(01111111B,01111111B)��
		P37=1;           //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��	
		#if ECBM_EXTI3_INIT
			EXTI3_ON;    //���ⲿ�ж�3��
		#endif
	#endif
	
	#if ECBM_EXTI4_EN    //�ⲿ�ж�4����P30�ڡ�
		P3M1&=0xFE;      //����P30Ϊ����״̬��
		P3M0&=0xFE;      //P3.0(11111110B,11111110B)��
		P30=1;           //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
		#if ECBM_EXTI4_INIT
			EXTI4_ON;            //���ⲿ�ж�4
		#endif
	#endif
}
/*------------------------------------------------------
���жϺ�����
-------------------------------------------------------*/
void exti_start(u8 id){
	switch(id){//����ID������Ӧ��֧��
		#if ECBM_EXTI0_EN
		case 0:{
			EXTI0_ON;
		}break;
		#endif
		#if ECBM_EXTI1_EN
		case 1:{
			EXTI1_ON;
		}break;
		#endif
		#if ECBM_EXTI2_EN
		case 2:{
			EXTI2_ON;
		}break;
		#endif
		#if ECBM_EXTI3_EN
		case 3:{
			EXTI3_ON;
		}break;
		#endif
		#if ECBM_EXTI4_EN
		case 4:{
			EXTI4_ON;
		}break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("exti_start(<%d>);�����ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*------------------------------------------------------
�ر��жϺ�����
-------------------------------------------------------*/
void exti_stop(u8 id){
	switch(id){//����ID������Ӧ��֧��
		#if ECBM_EXTI0_EN
		case 0:{
			EXTI0_OFF;
		}break;
		#endif
		#if ECBM_EXTI1_EN
		case 1:{
			EXTI1_OFF;
		}break;
		#endif
		#if ECBM_EXTI2_EN
		case 2:{
			EXTI2_OFF;
		}break;
		#endif
		#if ECBM_EXTI3_EN
		case 3:{
			EXTI3_OFF;
		}break;
		#endif
		#if ECBM_EXTI4_EN
		case 4:{
			EXTI4_OFF;
		}break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("exti_stop(<%d>);�����ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*------------------------------------------------------
�ж�ģʽ���ú�����
-------------------------------------------------------*/
void exti_set_mode(u8 id,bit mode){
	switch(id){//����ID������Ӧ��֧��
		#if ECBM_EXTI0_EN
		case 0:{
			IT0=mode;
		}break;
		#endif
		#if ECBM_EXTI1_EN
		case 1:{
			IT1=mode;
		}break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("exti_set_mode(<%d>,%d);�����ID\r\n",(u16)id,(u16)mode);break;
		#else
		default:while(1);break;
		#endif
	}	
}
#endif
