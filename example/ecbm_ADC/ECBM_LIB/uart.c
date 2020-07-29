#include "ecbm_core.h"
#if ECBM_UART_EN
/*--------------------------------------��������-----------------------------------*/
#if UART1_EN
bit uart1_busy;
#endif
#if UART2_EN
bit uart2_busy;
#endif
#if UART3_EN
bit uart3_busy;
#endif
#if UART4_EN
bit uart4_busy;
#endif
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if    (UART1_SCON_CONFIG&0x20)&&((UART1_SCON_CONFIG&0x80)==0)
#error ����������1�Ķ��ͨ�Ź��ܣ���ѹ���ģʽ����Ϊ9λ��
#endif
#if    (UART2_S2CON_CONFIG&0x20)&&((UART2_S2CON_CONFIG&0x80)==0)
#error ����������2�Ķ��ͨ�Ź��ܣ���ѹ���ģʽ����Ϊ9λ��
#endif
#if    (UART3_S3CON_CONFIG&0x20)&&((UART3_S3CON_CONFIG&0x80)==0)
#error ����������3�Ķ��ͨ�Ź��ܣ���ѹ���ģʽ����Ϊ9λ��
#endif
#if    (UART4_S4CON_CONFIG&0x20)&&((UART4_S4CON_CONFIG&0x80)==0)
#error ����������4�Ķ��ͨ�Ź��ܣ���ѹ���ģʽ����Ϊ9λ��
#endif
#if    (UART2_EN == 1)&&(ECBM_MCU_UART == 1)
#error ��ǰ��Ƭ���ͺŲ�֧�ִ���2��������ͺŻ��߹رմ���2��
#endif
#if    (UART3_EN == 1)&&(ECBM_MCU_UART < 4)
#error ��ǰ��Ƭ���ͺŲ�֧�ִ���3��������ͺŻ��߹رմ���3��
#endif
#if    (UART4_EN == 1)&&(ECBM_MCU_UART < 4)
#error ��ǰ��Ƭ���ͺŲ�֧�ִ���4��������ͺŻ��߹رմ���4��
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART2_EN == 1)
#if    UART1_BAUD_RATE != UART2_BAUD_RATE
#error ����1�ʹ���2�Ĳ����ʲ���������ʱ��2����ͻ�����������1�Ĳ����ʲ��������߽�����1�ʹ���2�Ĳ����ʵ���һ�¡�
#endif
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)
#if    UART1_BAUD_RATE != UART3_BAUD_RATE
#error ����1�ʹ���3�Ĳ����ʲ���������ʱ��2����ͻ�����������1�򴮿�3�Ĳ����ʲ��������߽�����1�ʹ���3�Ĳ����ʵ���һ�¡�
#endif
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART1_BAUD_RATE != UART4_BAUD_RATE
#error ����1�ʹ���4�Ĳ����ʲ���������ʱ��2����ͻ�����������1�򴮿�4�Ĳ����ʲ��������߽�����1�ʹ���4�Ĳ����ʵ���һ�¡�
#endif
#endif
#if    (UART2_EN == 1)&&(UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)
#if    UART2_BAUD_RATE != UART3_BAUD_RATE
#error ����2�ʹ���3�Ĳ����ʲ���������ʱ��2����ͻ�����������3�Ĳ����ʲ��������߽�����2�ʹ���3�Ĳ����ʵ���һ�¡�
#endif
#endif
#if    (UART2_EN == 1)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART2_BAUD_RATE != UART4_BAUD_RATE
#error ����2�ʹ���4�Ĳ����ʲ���������ʱ��2����ͻ�����������4�Ĳ����ʲ��������߽�����2�ʹ���4�Ĳ����ʵ���һ�¡�
#endif
#endif
#if    (UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART3_BAUD_RATE != UART4_BAUD_RATE
#error ����3�ʹ���4�Ĳ����ʲ���������ʱ��2����ͻ�����������3�򴮿�4�Ĳ����ʲ��������߽�����3�ʹ���4�Ĳ����ʵ���һ�¡�
#endif
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
���ڳ�ʼ��������
-------------------------------------------------------*/
void uart_init(void){
	u16 res;
	#if UART1_EN == 1       //������1����ʹ�ܵ�ʱ��
	SCON=UART1_SCON_CONFIG; //д��SCON���ã���������ģʽ������ʹ�ܡ����ͨ�ŵ�ѡ�
	PCON&=0x3F;             //���ԭ�������á�
	PCON|=UART1_PCON_CONFIG;//д��PCON���ã����������ʼӱ���
	AUXR&=0xDE;             //���ԭ�������á�
	AUXR|=UART1_AUXR_CONFIG;//д��AUXR���ã������ӱ����ơ������ʷ�����ѡ��
	P_SW1&=0x3F;            //���ԭ�������á�
	P_SW1|=UART1_IO;        //д��IOѡ�����λ��
	#if (UART1_SCON_CONFIG&0x20)//������˶��ͨ�Ź��ܣ�
	SADDR=UART1_SADDR_CONFIG;//д��ӻ���ַ��
	SADEN=UART1_SADEN_CONFIG;//д��ӻ���ַʹ��λ��
	#endif
	res=(u16)(65536-ecbm_sys_clk/4/UART1_BAUD_RATE);//ͨ�����������ö�ʱ����ֵ��
	#if (UART1_AUXR_CONFIG&0x01) == 0//���ѡ���˶�ʱ��1��
	TIMER1_1T;          //�趨��ʱ��1Ϊ1Tģʽ��
	TMOD &= 0x0F;       //�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ��Ŀǰ���������Ѿ������㳣�õĲ������ˡ�
	TL1 =(u8)(res);     //�趨��ʱ��ֵ��8λ��
	TH1 =(u8)(res>>8);  //�趨��ʱ��ֵ��8λ��
	TIMER1_IT_OFF;      //��ֹ��ʱ��1�жϡ�
	TIMER1_ON;          //������ʱ��1��
	#else               //���ѡ���˶�ʱ��2��
	TIMER2_1T;          //�趨��ʱ��2Ϊ1Tģʽ��
	T2L =(u8)(res);     //�趨��ʱ��ֵ��8λ��
	T2H =(u8)(res>>8);  //�趨��ʱ��ֵ��8λ��
	TIMER2_IT_OFF;      //��ֹ��ʱ��2�жϡ�
	TIMER2_ON;          //������ʱ��2��
	#endif
	uart1_busy=0;       //����1æ��־λ��0��
	UART1_IT_ON;        //�򿪴���1�жϡ�
	#endif

	#if UART2_EN == 1   //������2����ʹ�ܵ�ʱ��
	S2CON=UART2_S2CON_CONFIG; //д��S2CON����,������ͨ��λ���������������ͨ�š�
	P_SW2&=0xFE;        //���ԭ�������á�
	P_SW2|=UART2_IO;    //д��IOѡ�����λ��
	TIMER2_1T;          //��ʱ��2ʱ��ΪFosc,��1T��
	res=(u16)(65536-ecbm_sys_clk/4/UART2_BAUD_RATE);//ͨ�����������ö�ʱ����ֵ��
	T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
	T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
	TIMER2_IT_OFF;      //��ֹ��ʱ��2�жϡ�
	TIMER2_ON;          //������ʱ��2��
	uart2_busy=0;       //����2æ��־λ��0��
	UART2_IT_ON;        //�򿪴���2�жϡ�
	#endif
	
	#if UART3_EN == 1   //������3����ʹ�ܵ�ʱ��
	S3CON=UART3_S3CON_CONFIG; //д��S3CON����,������ͨ��λ���������������ͨ�š������ʲ�����ѡ��
	P_SW2&=0xFD;        //���ԭ�������á�
	P_SW2|=UART3_IO;    //д��IOѡ�����λ��
	res=(u16)(65536-ecbm_sys_clk/4/UART3_BAUD_RATE);//ͨ�����������ö�ʱ����ֵ��
	#if (UART3_S3CON_CONFIG&0x40)==0
	TIMER2_1T;          //��ʱ��2ʱ��ΪFosc,��1T��
	T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
	T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
	TIMER2_IT_OFF;      //��ֹ��ʱ��2�жϡ�
	TIMER2_ON;          //������ʱ��2��
	#else
	TIMER3_1T;          //��ʱ��3ʱ��ΪFosc,��1T��
	T3L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
	T3H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
	TIMER3_IT_OFF;      //��ֹ��ʱ��3�жϡ�
	TIMER3_ON;          //������ʱ��3��
	#endif
	uart3_busy=0;       //����3æ��־λ��0��
	UART3_IT_ON;        //�򿪴���3�жϡ�
	#endif
	
	#if UART4_EN == 1   //������4����ʹ�ܵ�ʱ��
	S4CON=UART4_S4CON_CONFIG; //д��43CON����,������ͨ��λ���������������ͨ�š������ʲ�����ѡ��
	P_SW2&=0xFB;        //���ԭ�������á�
	P_SW2|=UART4_IO;    //д��IOѡ�����λ��
	res=(u16)(65536-ecbm_sys_clk/4/UART4_BAUD_RATE);//ͨ�����������ö�ʱ����ֵ��
	#if (UART4_S4CON_CONFIG&0x40)==0
	TIMER2_1T;          //��ʱ��2ʱ��ΪFosc,��1T��
	T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
	T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
	TIMER2_IT_OFF;      //��ֹ��ʱ��2�жϡ�
	TIMER2_ON;          //������ʱ��2��
	#else
	TIMER4_1T;          //��ʱ��4ʱ��ΪFosc,��1T��
	T4L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
	T4H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
	TIMER4_IT_OFF;      //��ֹ��ʱ��4�жϡ�
	TIMER4_ON;          //������ʱ��4��
	#endif
	uart4_busy=0;       //����4æ��־λ��0��
	UART4_IT_ON;        //�򿪴���4�жϡ�
	#endif
}
/*-------------------------------------------------------
�������IO���ú�����
-------------------------------------------------------*/
void uart_set_io(u8 id,u8 io){
	switch(id){
		#if UART1_EN
		case 1:{
			P_SW1 &=0x3F;
			P_SW1 |=io;
		}break;
		#endif
		#if UART2_EN
		case 2:{
			P_SW2 &=0xFE;
			P_SW2 |=io;
		}break;
		#endif
		#if UART3_EN
		case 3:{
			P_SW2 &=0xFD;
			P_SW2 |=io;
		}break;
		#endif
		#if UART4_EN
		case 4:{
			P_SW2 &=0xFB;
			P_SW2 |=io;
		}break;
		#endif
	}
}
/*-------------------------------------------------------
���ڲ��������ú�����
-------------------------------------------------------*/
void uart_set_baud(u8 id,u32 baud){
	u16 res;
	res=(u16)(65536-(u16)(ecbm_sys_clk/4/baud));//ͨ�����������ö�ʱ����ֵ��
	switch(id){
		#if UART1_EN == 1       //������1����ʹ�ܵ�ʱ��
		case 1:{
			#if (UART1_AUXR_CONFIG&0x01) == 0//���ѡ���˶�ʱ��1��
			TL1 =(u8)(res);     //�趨��ʱ��ֵ��8λ��
			TH1 =(u8)(res>>8);  //�趨��ʱ��ֵ��8λ��
			#else               //���ѡ���˶�ʱ��2��
			T2L =(u8)(res);     //�趨��ʱ��ֵ��8λ��
			T2H =(u8)(res>>8);  //�趨��ʱ��ֵ��8λ��
			#endif
		}break;
		#endif
		#if UART2_EN == 1   //������2����ʹ�ܵ�ʱ��
		case 2:{
			T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
			T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
		}break;
		#endif
		#if UART3_EN == 1   //������3����ʹ�ܵ�ʱ��
		case 3:{
			#if (UART3_S3CON_CONFIG&0x40)==0
			T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
			T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
			#else
			T3L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
			T3H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
			#endif
		}break;
		#endif
		#if UART4_EN == 1   //������4����ʹ�ܵ�ʱ��
		case 4:{
			#if (UART4_S4CON_CONFIG&0x40)==0
			T2L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
			T2H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
			#else
			T4L =(u8)(res);		//�趨��ʱ��ֵ��8λ��
			T4H =(u8)(res>>8);	//�趨��ʱ��ֵ��8λ��
			#endif
		}break;
		#endif
	}
}
/*-------------------------------------------------------
���ڵ����ֽڷ��ͺ�����
-------------------------------------------------------*/
void uart_char(u8 id,u8 ch){
	switch(id){
		#if UART1_EN
		case 1:{
			#if   UART1_PARITY == 1
			ACC=ch;
			if(P){TB8=0;}else{TB8=1;}
			#elif UART1_PARITY == 2
			ACC=ch;
			if(P){TB8=1;}else{TB8=0;}	
			#elif UART1_PARITY == 3
			TB8=1;
			#elif UART1_PARITY == 4
			TB8=0;
			#endif
			SBUF=ch;
			uart1_busy=1;
			while(uart1_busy);
		}break;
		#endif
		#if UART2_EN
		case 2:{
			#if   UART2_PARITY == 1
			ACC=ch;
			if(P){S2CON&=~0x08;}else{S2CON|=0x08;}
			#elif UART2_PARITY == 2
			ACC=ch;
			if(P){S2CON|=0x08;}else{S2CON&=~0x08;}	
			#elif UART2_PARITY == 3
			S2CON|=0x08;
			#elif UART2_PARITY == 4
			S2CON&=~0x08;
			#endif
			S2BUF=ch;
			uart2_busy=1;
			while(uart2_busy);
		}break;
		#endif
		#if UART3_EN
		case 3:{
			#if   UART3_PARITY == 1
			ACC=ch;
			if(P){S3CON&=~0x08;}else{S3CON|=0x08;}
			#elif UART3_PARITY == 2
			ACC=ch;
			if(P){S3CON|=0x08;}else{S3CON&=~0x08;}	
			#elif UART3_PARITY == 3
			S3CON|=0x08;
			#elif UART3_PARITY == 4
			S3CON&=~0x08;
			#endif
			S3BUF=ch;
			uart3_busy=1;
			while(uart3_busy);
		}break;
		#endif
		#if UART4_EN
		case 4:{
			#if   UART4_PARITY == 1
			ACC=ch;
			if(P){S4CON&=~0x08;}else{S4CON|=0x08;}
			#elif UART4_PARITY == 2
			ACC=ch;
			if(P){S4CON|=0x08;}else{S4CON&=~0x08;}	
			#elif UART4_PARITY == 3
			S4CON|=0x08;
			#elif UART4_PARITY == 4
			S4CON&=~0x08;
			#endif
			S4BUF=ch;
			uart4_busy=1;
			while(uart4_busy);
		}break;
		#endif
	}	
}
/*-------------------------------------------------------
9λģʽ�µ��ַ����ͺ�����
-------------------------------------------------------*/
void uart_char_9(u8 id,u8 ch,bit bit9){
	switch(id){
		#if UART1_EN
		case 1:{
			TB8=bit9;
			SBUF=ch;
			uart1_busy=1;
			while(uart1_busy);
		}break;
		#endif
		#if UART2_EN
		case 2:{
			if(bit9){
				S2CON|=0x08;
			}else{
				S2CON&=~0x08;
			}
			S2BUF=ch;
			uart2_busy=1;
			while(uart2_busy);
		}break;
		#endif
		#if UART3_EN
		case 3:{
			if(bit9){
				S3CON|=0x08;
			}else{
				S3CON&=~0x08;
			}
			S3BUF=ch;
			uart3_busy=1;
			while(uart3_busy);
		}break;
		#endif
		#if UART4_EN
		case 4:{
			if(bit9){
				S4CON|=0x08;
			}else{
				S4CON&=~0x08;
			}
			S4BUF=ch;
			uart4_busy=1;
			while(uart4_busy);
		}break;
		#endif
	}
}
/*-------------------------------------------------------
�����ַ������ͺ�����
-------------------------------------------------------*/
void uart_string(u8 id,u8 * str){
	while(*str){
		uart_char(id,*str++);
	}	
}
/*-------------------------------------------------------
���ڴ�ӡ������
-------------------------------------------------------*/
void uart_printf(u8 id,const char * str,...){
	char xdata buf[UART_BUF_MAX];
	va_list vp;
    va_start(vp, str);
	
    vsprintf(buf,str,vp);
    va_end(vp);
	uart_string(id,buf);
}
/*-------------------------------------------------------
����1�жϷ������
-------------------------------------------------------*/
#if UART1_EN
void uart1_it()UART1_FUN{
	if(RI){          //����1�����жϡ�
		RI=0;        //�������1���ձ�־��
		#if UART1_RECEIVE_CALLBACK_EN
		uart1_receive_callback();
		#endif
		#if AUTO_DOWNLOAD_EN
		system_uart_reset();//ʵ���Զ����ع��ܡ�
		#endif
    }
    if(TI){          //����1�����жϡ�
        TI=0;        //�������1���ͱ�־��
		uart1_busy=0;//֪ͨ����3���ͺ�����
		#if UART1_SEND_CALLBACK_EN
		uart1_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
����2�жϷ������
-------------------------------------------------------*/
#if UART2_EN
void uart2_it()UART2_FUN{
	if(S2CON&0x01){  //����2�����жϡ�
        S2CON&=0xFE; //�������2���ձ�־��
		#if UART2_RECEIVE_CALLBACK_EN
		uart2_receive_callback();
		#endif
    }
	if(S2CON&0x02){  //����2�����жϡ�
        S2CON&=0xFD; //�������2���ͱ�־��
		uart2_busy=0;//֪ͨ����2���ͺ�����
		#if UART2_SEND_CALLBACK_EN
		uart2_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
����3�жϷ������
-------------------------------------------------------*/
#if UART3_EN
void uart3_it()UART3_FUN{
	if(S3CON&0x01){  //����3�����жϡ�
        S3CON&=0xFE; //�������3���ձ�־��
		#if UART3_RECEIVE_CALLBACK_EN
		uart3_receive_callback();
		#endif
    }
	if(S3CON&0x02){  //����3�����жϡ�
        S3CON&=0xFD; //�������3���ͱ�־��
		uart3_busy=0;//֪ͨ����3���ͺ�����
		#if UART3_SEND_CALLBACK_EN
		uart3_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
����4�жϷ������
-------------------------------------------------------*/
#if UART4_EN
void uart4_it()UART4_FUN{
	if(S4CON&0x01){  //����4�����жϡ�
        S4CON&=0xFE; //�������4���ձ�־��
		#if UART4_RECEIVE_CALLBACK_EN
		uart4_receive_callback();
		#endif
    }
	if(S4CON&0x02){  //����4�����жϡ�
        S4CON&=0xFD; //�������4���ͱ�־��
		uart4_busy=0;//֪ͨ����4���ͺ�����
		#if UART4_SEND_CALLBACK_EN
		uart4_send_callback();
		#endif
    }
}
#endif
#endif
