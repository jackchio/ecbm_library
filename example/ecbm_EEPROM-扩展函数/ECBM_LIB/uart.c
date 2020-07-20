#include "ecbm_core.h"
#if ECBM_UART_EN
/*--------------------------------------变量定义-----------------------------------*/
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
/*------------------------------------资源冲突警告---------------------------------*/
#if    (UART1_SCON_CONFIG&0x20)&&((UART1_SCON_CONFIG&0x80)==0)
#error 若开启串口1的多机通信功能，请把工作模式设置为9位！
#endif
#if    (UART2_S2CON_CONFIG&0x20)&&((UART2_S2CON_CONFIG&0x80)==0)
#error 若开启串口2的多机通信功能，请把工作模式设置为9位！
#endif
#if    (UART3_S3CON_CONFIG&0x20)&&((UART3_S3CON_CONFIG&0x80)==0)
#error 若开启串口3的多机通信功能，请把工作模式设置为9位！
#endif
#if    (UART4_S4CON_CONFIG&0x20)&&((UART4_S4CON_CONFIG&0x80)==0)
#error 若开启串口4的多机通信功能，请把工作模式设置为9位！
#endif
#if    (UART2_EN == 1)&&(ECBM_MCU_UART == 1)
#error 当前单片机型号不支持串口2，请更换型号或者关闭串口2。
#endif
#if    (UART3_EN == 1)&&(ECBM_MCU_UART < 4)
#error 当前单片机型号不支持串口3，请更换型号或者关闭串口3。
#endif
#if    (UART4_EN == 1)&&(ECBM_MCU_UART < 4)
#error 当前单片机型号不支持串口4，请更换型号或者关闭串口4。
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART2_EN == 1)
#if    UART1_BAUD_RATE != UART2_BAUD_RATE
#error 串口1和串口2的波特率产生器（定时器2）冲突。请更换串口1的波特率产生器或者将串口1和串口2的波特率调成一致。
#endif
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)
#if    UART1_BAUD_RATE != UART3_BAUD_RATE
#error 串口1和串口3的波特率产生器（定时器2）冲突。请更换串口1或串口3的波特率产生器或者将串口1和串口3的波特率调成一致。
#endif
#endif
#if    (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART1_BAUD_RATE != UART4_BAUD_RATE
#error 串口1和串口4的波特率产生器（定时器2）冲突。请更换串口1或串口4的波特率产生器或者将串口1和串口4的波特率调成一致。
#endif
#endif
#if    (UART2_EN == 1)&&(UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)
#if    UART2_BAUD_RATE != UART3_BAUD_RATE
#error 串口2和串口3的波特率产生器（定时器2）冲突。请更换串口3的波特率产生器或者将串口2和串口3的波特率调成一致。
#endif
#endif
#if    (UART2_EN == 1)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART2_BAUD_RATE != UART4_BAUD_RATE
#error 串口2和串口4的波特率产生器（定时器2）冲突。请更换串口4的波特率产生器或者将串口2和串口4的波特率调成一致。
#endif
#endif
#if    (UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0x00)&&(UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0x00)
#if    UART3_BAUD_RATE != UART4_BAUD_RATE
#error 串口3和串口4的波特率产生器（定时器2）冲突。请更换串口3或串口4的波特率产生器或者将串口3和串口4的波特率调成一致。
#endif
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
串口初始化函数。
-------------------------------------------------------*/
void uart_init(void){
	u16 res;
	#if UART1_EN == 1       //当串口1功能使能的时候。
	SCON=UART1_SCON_CONFIG; //写入SCON配置，包含工作模式、接收使能、多机通信的选项。
	PCON&=0x3F;             //清除原来的设置。
	PCON|=UART1_PCON_CONFIG;//写入PCON配置，包含波特率加倍。
	AUXR&=0xDE;             //清除原来的设置。
	AUXR|=UART1_AUXR_CONFIG;//写入AUXR配置，包含加倍控制、波特率发生器选择。
	P_SW1&=0x3F;            //清除原来的设置。
	P_SW1|=UART1_IO;        //写入IO选择控制位。
	#if (UART1_SCON_CONFIG&0x20)//如果打开了多机通信功能，
	SADDR=UART1_SADDR_CONFIG;//写入从机地址。
	SADEN=UART1_SADEN_CONFIG;//写入从机地址使能位。
	#endif
	res=(u16)(65536-ecbm_sys_clk/4/UART1_BAUD_RATE);//通过波特率设置定时器初值。
	#if (UART1_AUXR_CONFIG&0x01) == 0//如果选择了定时器1，
	TIMER1_1T;          //设定定时器1为1T模式，
	TMOD &= 0x0F;       //设定定时器1为16位自动重装方式，目前这样设置已经能满足常用的波特率了。
	TL1 =(u8)(res);     //设定定时初值低8位，
	TH1 =(u8)(res>>8);  //设定定时初值高8位。
	TIMER1_IT_OFF;      //禁止定时器1中断。
	TIMER1_ON;          //启动定时器1。
	#else               //如果选择了定时器2，
	TIMER2_1T;          //设定定时器2为1T模式。
	T2L =(u8)(res);     //设定定时初值低8位，
	T2H =(u8)(res>>8);  //设定定时初值高8位。
	TIMER2_IT_OFF;      //禁止定时器2中断。
	TIMER2_ON;          //启动定时器2。
	#endif
	uart1_busy=0;       //串口1忙标志位清0。
	UART1_IT_ON;        //打开串口1中断。
	#endif

	#if UART2_EN == 1   //当串口2功能使能的时候。
	S2CON=UART2_S2CON_CONFIG; //写入S2CON配置,包含了通信位数、接收允许、多机通信。
	P_SW2&=0xFE;        //清除原来的设置。
	P_SW2|=UART2_IO;    //写入IO选择控制位。
	TIMER2_1T;          //定时器2时钟为Fosc,即1T。
	res=(u16)(65536-ecbm_sys_clk/4/UART2_BAUD_RATE);//通过波特率设置定时器初值。
	T2L =(u8)(res);		//设定定时初值低8位，
	T2H =(u8)(res>>8);	//设定定时初值高8位。
	TIMER2_IT_OFF;      //禁止定时器2中断。
	TIMER2_ON;          //启动定时器2。
	uart2_busy=0;       //串口2忙标志位清0。
	UART2_IT_ON;        //打开串口2中断。
	#endif
	
	#if UART3_EN == 1   //当串口3功能使能的时候。
	S3CON=UART3_S3CON_CONFIG; //写入S3CON配置,包含了通信位数、接收允许、多机通信、波特率产生器选择。
	P_SW2&=0xFD;        //清除原来的设置。
	P_SW2|=UART3_IO;    //写入IO选择控制位。
	res=(u16)(65536-ecbm_sys_clk/4/UART3_BAUD_RATE);//通过波特率设置定时器初值。
	#if (UART3_S3CON_CONFIG&0x40)==0
	TIMER2_1T;          //定时器2时钟为Fosc,即1T。
	T2L =(u8)(res);		//设定定时初值低8位，
	T2H =(u8)(res>>8);	//设定定时初值高8位。
	TIMER2_IT_OFF;      //禁止定时器2中断。
	TIMER2_ON;          //启动定时器2。
	#else
	TIMER3_1T;          //定时器3时钟为Fosc,即1T。
	T3L =(u8)(res);		//设定定时初值低8位，
	T3H =(u8)(res>>8);	//设定定时初值高8位。
	TIMER3_IT_OFF;      //禁止定时器3中断。
	TIMER3_ON;          //启动定时器3。
	#endif
	uart3_busy=0;       //串口3忙标志位清0。
	UART3_IT_ON;        //打开串口3中断。
	#endif
	
	#if UART4_EN == 1   //当串口4功能使能的时候。
	S4CON=UART4_S4CON_CONFIG; //写入43CON配置,包含了通信位数、接收允许、多机通信、波特率产生器选择。
	P_SW2&=0xFB;        //清除原来的设置。
	P_SW2|=UART4_IO;    //写入IO选择控制位。
	res=(u16)(65536-ecbm_sys_clk/4/UART4_BAUD_RATE);//通过波特率设置定时器初值。
	#if (UART4_S4CON_CONFIG&0x40)==0
	TIMER2_1T;          //定时器2时钟为Fosc,即1T。
	T2L =(u8)(res);		//设定定时初值低8位，
	T2H =(u8)(res>>8);	//设定定时初值高8位。
	TIMER2_IT_OFF;      //禁止定时器2中断。
	TIMER2_ON;          //启动定时器2。
	#else
	TIMER4_1T;          //定时器4时钟为Fosc,即1T。
	T4L =(u8)(res);		//设定定时初值低8位，
	T4H =(u8)(res>>8);	//设定定时初值高8位。
	TIMER4_IT_OFF;      //禁止定时器4中断。
	TIMER4_ON;          //启动定时器4。
	#endif
	uart4_busy=0;       //串口4忙标志位清0。
	UART4_IT_ON;        //打开串口4中断。
	#endif
}
/*-------------------------------------------------------
串口输出IO设置函数。
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
串口波特率设置函数。
-------------------------------------------------------*/
void uart_set_baud(u8 id,u32 baud){
	u16 res;
	res=(u16)(65536-(u16)(ecbm_sys_clk/4/baud));//通过波特率设置定时器初值。
	switch(id){
		#if UART1_EN == 1       //当串口1功能使能的时候。
		case 1:{
			#if (UART1_AUXR_CONFIG&0x01) == 0//如果选择了定时器1，
			TL1 =(u8)(res);     //设定定时初值低8位，
			TH1 =(u8)(res>>8);  //设定定时初值高8位。
			#else               //如果选择了定时器2，
			T2L =(u8)(res);     //设定定时初值低8位，
			T2H =(u8)(res>>8);  //设定定时初值高8位。
			#endif
		}break;
		#endif
		#if UART2_EN == 1   //当串口2功能使能的时候。
		case 2:{
			T2L =(u8)(res);		//设定定时初值低8位，
			T2H =(u8)(res>>8);	//设定定时初值高8位。
		}break;
		#endif
		#if UART3_EN == 1   //当串口3功能使能的时候。
		case 3:{
			#if (UART3_S3CON_CONFIG&0x40)==0
			T2L =(u8)(res);		//设定定时初值低8位，
			T2H =(u8)(res>>8);	//设定定时初值高8位。
			#else
			T3L =(u8)(res);		//设定定时初值低8位，
			T3H =(u8)(res>>8);	//设定定时初值高8位。
			#endif
		}break;
		#endif
		#if UART4_EN == 1   //当串口4功能使能的时候。
		case 4:{
			#if (UART4_S4CON_CONFIG&0x40)==0
			T2L =(u8)(res);		//设定定时初值低8位，
			T2H =(u8)(res>>8);	//设定定时初值高8位。
			#else
			T4L =(u8)(res);		//设定定时初值低8位，
			T4H =(u8)(res>>8);	//设定定时初值高8位。
			#endif
		}break;
		#endif
	}
}
/*-------------------------------------------------------
串口单个字节发送函数。
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
			while(uart1_busy);
			uart1_busy=1;
			SBUF=ch;
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
			while(uart2_busy);
			uart2_busy=1;
			S2BUF=ch;
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
			while(uart3_busy);
			uart3_busy=1;
			S3BUF=ch;
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
			while(uart4_busy);
			uart4_busy=1;
			S4BUF=ch;
		}break;
		#endif
	}	
}
/*-------------------------------------------------------
9位模式下的字符发送函数。
-------------------------------------------------------*/
void uart_char_9(u8 id,u8 ch,bit bit9){
	switch(id){
		#if UART1_EN
		case 1:{
			TB8=bit9;
			while(uart1_busy);
			uart1_busy=1;
			SBUF=ch;
		}break;
		#endif
		#if UART2_EN
		case 2:{
			if(bit9){
				S2CON|=0x08;
			}else{
				S2CON&=~0x08;
			}
			while(uart2_busy);
			uart2_busy=1;
			S2BUF=ch;
		}break;
		#endif
		#if UART3_EN
		case 3:{
			if(bit9){
				S3CON|=0x08;
			}else{
				S3CON&=~0x08;
			}
			while(uart3_busy);
			uart3_busy=1;
			S3BUF=ch;
		}break;
		#endif
		#if UART4_EN
		case 4:{
			if(bit9){
				S4CON|=0x08;
			}else{
				S4CON&=~0x08;
			}
			while(uart4_busy);
			uart4_busy=1;
			S4BUF=ch;
		}break;
		#endif
	}
}
/*-------------------------------------------------------
串口字符串发送函数。
-------------------------------------------------------*/
void uart_string(u8 id,u8 * str){
	while(*str){
		uart_char(id,*str++);
	}	
}
/*-------------------------------------------------------
串口打印函数。
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
串口1中断服务程序
-------------------------------------------------------*/
#if UART1_EN
void uart1_it()UART1_FUN{
	if(RI){          //串口1接收中断。
		RI=0;        //清掉串口1接收标志。
		#if UART1_RECEIVE_CALLBACK_EN
		uart1_receive_callback();
		#endif
		#if AUTO_DOWNLOAD_EN
		system_uart_reset();//实现自动下载功能。
		#endif
    }
    if(TI){          //串口1发送中断。
        TI=0;        //清掉串口1发送标志。
		uart1_busy=0;//通知串口3发送函数。
		#if UART1_SEND_CALLBACK_EN
		uart1_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
串口2中断服务程序
-------------------------------------------------------*/
#if UART2_EN
void uart2_it()UART2_FUN{
	if(S2CON&0x01){  //串口2接收中断。
        S2CON&=0xFE; //清掉串口2接收标志。
		#if UART2_RECEIVE_CALLBACK_EN
		uart2_receive_callback();
		#endif
    }
	if(S2CON&0x02){  //串口2发送中断。
        S2CON&=0xFD; //清掉串口2发送标志。
		uart2_busy=0;//通知串口2发送函数。
		#if UART2_SEND_CALLBACK_EN
		uart2_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
串口3中断服务程序
-------------------------------------------------------*/
#if UART3_EN
void uart3_it()UART3_FUN{
	if(S3CON&0x01){  //串口3接收中断。
        S3CON&=0xFE; //清掉串口3接收标志。
		#if UART3_RECEIVE_CALLBACK_EN
		uart3_receive_callback();
		#endif
    }
	if(S3CON&0x02){  //串口3发送中断。
        S3CON&=0xFD; //清掉串口3发送标志。
		uart3_busy=0;//通知串口3发送函数。
		#if UART3_SEND_CALLBACK_EN
		uart3_send_callback();
		#endif
    }
}
#endif
/*-------------------------------------------------------
串口4中断服务程序
-------------------------------------------------------*/
#if UART4_EN
void uart4_it()UART4_FUN{
	if(S4CON&0x01){  //串口4接收中断。
        S4CON&=0xFE; //清掉串口4接收标志。
		#if UART4_RECEIVE_CALLBACK_EN
		uart4_receive_callback();
		#endif
    }
	if(S4CON&0x02){  //串口4发送中断。
        S4CON&=0xFD; //清掉串口4发送标志。
		uart4_busy=0;//通知串口4发送函数。
		#if UART4_SEND_CALLBACK_EN
		uart4_send_callback();
		#endif
    }
}
#endif
#endif
