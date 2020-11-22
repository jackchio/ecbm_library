#include "ecbm_core.h"
#if ECBM_TIMER_LIB_EN
/*------------------------------------��Դ��ͻ����---------------------------------*/
//------------------------------------���ڳ�ͻ����---------------------------------//
#if ECBM_UART_LIB_EN == 1  //�жϴ��ڿ��Ƿ���á�

#if (ECBM_UART1_EN == 1)&&((ECBM_UART1_AUXR_CONFIG&0x01) == 0)&&(ECBM_TIMER1_EN == 1)
#error ����1�Ͷ�ʱ��1��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART1_EN == 1)&&((ECBM_UART1_AUXR_CONFIG&0x01) == 0x01)&&(ECBM_TIMER2_EN == 1)
#error ����1�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART2_EN == 1)&&(ECBM_TIMER2_EN == 1)
#error ����2�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART3_EN == 1)&&((ECBM_UART3_S3CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN == 1)
#error ����3�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART3_EN == 1)&&(ECBM_UART3_S3CON_CONFIG&0x40)&&(ECBM_TIMER3_EN == 1)
#error ����3�Ͷ�ʱ��3��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART4_EN == 1)&&((ECBM_UART4_S4CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN == 1)
#error ����4�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#endif

#if (ECBM_UART4_EN == 1)&&(ECBM_UART4_S4CON_CONFIG&0x40)&&(ECBM_TIMER4_EN == 1)
#error ����4�Ͷ�ʱ��4��ͻ���뻻һ����ʱ��ʹ�ã�
#endif
#endif
//----------------------------------��ʱ����������---------------------------------//
#if ((ECBM_MCU&0x000F00)<0x000400)&&(ECBM_TIMER3_EN == 1)
#error ���ͺ�û�ж�ʱ��3���뻻һ����ʱ��ʹ�ã�
#endif

#if ((ECBM_MCU&0x000F00)<0x000500)&&(ECBM_TIMER4_EN == 1)
#error ���ͺ�û�ж�ʱ��4���뻻һ����ʱ��ʹ�ã�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��ʱ����ʼ������
-------------------------------------------------------*/
void timer_start(u8 id){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{TIMER0_ON;}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{TIMER1_ON;}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{TIMER2_ON;}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{TIMER3_ON;}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{TIMER4_ON;}break;	
		#endif	
		#if ECBM_ERROR_PRINTF_EN
		default:error_printf("timer_start(<%d>);�����ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*-------------------------------------------------------
��ʱ��ֹͣ������
-------------------------------------------------------*/
void timer_stop(u8 id){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{TIMER0_OFF;}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{TIMER1_OFF;}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{TIMER2_OFF;}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{TIMER3_OFF;}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{TIMER4_OFF;}break;	
		#endif	
		#if ECBM_ERROR_PRINTF_EN
		default:error_printf("timer_stop(<%d>);�����ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*-------------------------------------------------------
��ʱ��������ƺ�����
-------------------------------------------------------*/
void timer_out(u8 id,u8 en){
	if(en){
		switch(id){
			#if ECBM_TIMER0_EN
			case 0:{TIMER0_OUT_ON;gpio_mode(D35,GPIO_OUT);}break;		
			#endif
			#if ECBM_TIMER1_EN
			case 1:{TIMER1_OUT_ON;gpio_mode(D34,GPIO_OUT);}break;	
			#endif
			#if ECBM_TIMER2_EN
			case 2:{TIMER2_OUT_ON;gpio_mode(D13,GPIO_OUT);}break;		
			#endif
			#if ECBM_TIMER3_EN
			case 3:{TIMER3_OUT_ON;gpio_mode(D05,GPIO_OUT);}break;	
			#endif
			#if ECBM_TIMER4_EN
			case 4:{TIMER4_OUT_ON;gpio_mode(D07,GPIO_OUT);}break;	
			#endif	
			#if ECBM_ERROR_PRINTF_EN
			default:error_printf("timer_out(<%d>,1);�����ID\r\n",(u16)id);break;
			#else
			default:while(1);break;
			#endif
		}	
	}else{
		switch(id){
			#if ECBM_TIMER0_EN
			case 0:{TIMER0_OUT_OFF;gpio_mode(D35,GPIO_IN);}break;		
			#endif
			#if ECBM_TIMER1_EN
			case 1:{TIMER1_OUT_OFF;gpio_mode(D34,GPIO_IN);}break;	
			#endif
			#if ECBM_TIMER2_EN
			case 2:{TIMER2_OUT_OFF;gpio_mode(D13,GPIO_IN);}break;		
			#endif
			#if ECBM_TIMER3_EN
			case 3:{TIMER3_OUT_OFF;gpio_mode(D05,GPIO_IN);}break;	
			#endif
			#if ECBM_TIMER4_EN
			case 4:{TIMER4_OUT_OFF;gpio_mode(D07,GPIO_IN);}break;	
			#endif	
			#if ECBM_ERROR_PRINTF_EN
			default:error_printf("timer_out(<%d>,0);�����ID\r\n",(u16)id);break;
			#else
			default:while(1);break;
			#endif
		}	
	}
}
/*-------------------------------------------------------
��ʱ����ʼ��������
-------------------------------------------------------*/
void timer_init(void){
#if ECBM_TIMER0_EN     //�ж϶�ʱ��0��û��ʹ�ܡ�
	TIMER0_SET_REG_AUXR	(ECBM_TIMER0_AUXR);//д���趨�����ݡ�
	TIMER0_SET_REG_TMOD	(ECBM_TIMER0_TMOD);//д���趨�����ݡ�
	TIMER0_SET_REG_HL	(65536-ECBM_TIMER0_COUNT);//д���ֵ��
	#if ECBM_TIMER0_IT_EN == 1    //����������жϡ�
	TIMER0_IT_ENABLE;
	#endif
#endif
	
#if ECBM_TIMER1_EN     //�ж϶�ʱ��1��û��ʹ�ܡ�
	TIMER1_SET_REG_AUXR(ECBM_TIMER1_AUXR);//д���趨�����ݡ�
	TIMER1_SET_REG_TMOD(ECBM_TIMER1_TMOD);//д���趨�����ݡ�
	TIMER1_SET_REG_HL(65536-ECBM_TIMER1_COUNT);//д���ֵ��
	#if ECBM_TIMER1_IT_EN == 1    //����������жϡ�
	TIMER1_IT_ENABLE;
	#endif
#endif
	
#if ECBM_TIMER2_EN     //�ж϶�ʱ��2��û��ʹ�ܡ�
	TIMER2_SET_REG_AUXR	(ECBM_TIMER2_AUXR);//д���趨�����ݡ�
	TIMER2_SET_REG_HL	(65536-ECBM_TIMER2_COUNT);//д���ֵ��
	#if ECBM_TIMER2_IT_EN == 1    //����������жϡ�
	TIMER2_IT_ENABLE;
	#endif
#endif
		
#if ECBM_TIMER3_EN     //�ж϶�ʱ��3��û��ʹ�ܡ�
	TIMER3_SET_REG_T4T3M(ECBM_TIMER3_T4T3M);//д���趨�����ݡ�
	TIMER3_SET_REG_HL	(65536-ECBM_TIMER3_COUNT);//д���ֵ��
	#if ECBM_TIMER3_IT_EN == 1    //����������жϡ�
	TIMER3_IT_ENABLE;
	#endif
#endif

#if ECBM_TIMER4_EN     //�ж϶�ʱ��4��û��ʹ�ܡ�
	TIMER4_SET_REG_T4T3M(ECBM_TIMER4_T4T3M);//д���趨�����ݡ�
	TIMER4_SET_REG_HL	(65536-ECBM_TIMER4_COUNT);//д���ֵ��
	#if ECBM_TIMER4_IT_EN == 1    //����������жϡ�
	TIMER4_IT_ENABLE;
	#endif
#endif
}
/*-------------------------------------------------------
��ʱ���趨��ʱģʽ������
-------------------------------------------------------*/
void timer_set_timer_mode(u8 id,u16 us){
	u16 n,max_1T,max_12T;
	max_1T=(u16)(65535.0/((float)ecbm_sys_clk/1000000.0));
	if(ecbm_sys_clk<= 12000000L){
		max_12T=65535;
	}else{
		max_12T=(u16)(65535.0/((float)ecbm_sys_clk/12000000.0));
	}
	if((us<=max_1T)&&(us>0)){
		n=1;
	}else if((us<=max_12T)&&(us>0)){
		n=12;
	}else{
		#if ECBM_ERROR_PRINTF_EN
		error_printf("���������0us,С��%uus��ʱ��\r\n",max_12T);
		#else
		while(1);
		#endif	
	}
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			if(n==1){
				TIMER0_SET_MODE_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER0_SET_MODE_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TIMER0_SET_REG_HL(n);
			TIMER0_SET_MODE_TIMER;
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			if(n==1){
				TIMER1_SET_MODE_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER1_SET_MODE_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TIMER1_SET_REG_HL(n);
			TIMER1_SET_MODE_TIMER;
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			if(n==1){
				TIMER2_SET_MODE_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER2_SET_MODE_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TIMER2_SET_REG_HL(n);
			TIMER2_SET_MODE_TIMER;
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			if(n==1){
				TIMER3_SET_MODE_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER3_SET_MODE_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TIMER3_SET_REG_HL(n);
			TIMER3_SET_MODE_TIMER;
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			if(n==1){
				TIMER4_SET_MODE_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER4_SET_MODE_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TIMER4_SET_REG_HL(n);
			TIMER4_SET_MODE_TIMER;
		}break;
		#endif	
		#if ECBM_ERROR_PRINTF_EN
		default:error_printf("timer_set_timer_mode(<%d>,%u);�����ID\r\n",(u16)id,us);break;
		#else
		default:while(1);break;
		#endif	
	}
}
/*-------------------------------------------------------
��ʱ���趨��ֵ������
-------------------------------------------------------*/
void timer_set_value(u8 id,u16 value){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{TIMER0_SET_REG_HL(value);}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{TIMER1_SET_REG_HL(value);}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{TIMER2_SET_REG_HL(value);}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{TIMER3_SET_REG_HL(value);}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{TIMER4_SET_REG_HL(value);}break;
		#endif	
		#if ECBM_ERROR_PRINTF_EN
		default:error_printf("timer_set_value(<%d>,%u);�����ID\r\n",(u16)id,value);break;
		#else
		default:while(1);break;
		#endif	
	}
}
/*-------------------------------------------------------
��ʱ������ֵ��ȡ������
-------------------------------------------------------*/
u16 timer_get_value(u8 id){
	u16 value=0;
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{value=TIMER0_GET_REG_HL;}break;		
		#endif
		#if ECBM_TIMER1_EN 
		case 1:{value=TIMER1_GET_REG_HL;}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{value=TIMER2_GET_REG_HL;}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{value=TIMER3_GET_REG_HL;}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{value=TIMER4_GET_REG_HL;}break;
		#endif	
		#if ECBM_ERROR_PRINTF_EN
		default:error_printf("timer_set_value(<%d>);�����ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif	
	}
	return value;
}
#endif
