#include "ecbm_core.h"
#if ECBM_TIMER_EN
/*------------------------------------资源冲突警告---------------------------------*/
#if ECBM_UART_EN == 1  //判断串口库是否调用。

#if (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0)&&(ECBM_TIMER1_EN == 1)
#error 串口1和定时器1冲突，请换一个定时器使用！
#endif

#if (UART1_EN == 1)&&((UART1_AUXR_CONFIG&0x01) == 0x01)&&(ECBM_TIMER2_EN == 1)
#error 串口1和定时器2冲突，请换一个定时器使用！
#endif

#if (UART2_EN == 1)&&(ECBM_TIMER2_EN == 1)
#error 串口2和定时器2冲突，请换一个定时器使用！
#endif

#if (UART3_EN == 1)&&((UART3_S3CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN == 1)
#error 串口3和定时器2冲突，请换一个定时器使用！
#endif

#if (UART3_EN == 1)&&(UART3_S3CON_CONFIG&0x40)&&(ECBM_TIMER3_EN == 1)
#error 串口3和定时器3冲突，请换一个定时器使用！
#endif

#if (UART4_EN == 1)&&((UART4_S4CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN == 1)
#error 串口4和定时器2冲突，请换一个定时器使用！
#endif

#if (UART4_EN == 1)&&(UART4_S4CON_CONFIG&0x40)&&(ECBM_TIMER4_EN == 1)
#error 串口4和定时器4冲突，请换一个定时器使用！
#endif

#if (ECBM_MCU_MAIN_RAM == 4)&&(ECBM_TIMER3_EN == 1)
#error 该型号没有定时器3，请换一个定时器使用！
#endif

#if (ECBM_MCU_MAIN_RAM == 4)&&(ECBM_TIMER4_EN == 1)
#error 该型号没有定时器4，请换一个定时器使用！
#endif
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
定时器开始函数。
-------------------------------------------------------*/
void timer_start(u8 id){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			INTCLKO&=0xFE;
			INTCLKO|=ECBM_TIMER0_INTCLKO;
			TIMER0_ON;
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			INTCLKO&=0xFD;
			INTCLKO|=ECBM_TIMER1_INTCLKO;
			TIMER1_ON;
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			INTCLKO&=0xFB;
			INTCLKO|=ECBM_TIMER2_INTCLKO;
			TIMER2_ON;
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			T4T3M&=0xFE;
			T4T3M|=ECBM_TIMER3_T4T3M;
			TIMER3_ON;
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			T4T3M&=0xEF;
			T4T3M|=ECBM_TIMER4_T4T3M;
			TIMER4_ON;
		}break;	
		#endif	
		#if SYS_ERROR_EN
		default:error_printf("timer_start(<%d>);错误的ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*-------------------------------------------------------
定时器停止函数。
-------------------------------------------------------*/
void timer_stop(u8 id){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			INTCLKO&=0xFE;
			TIMER0_OFF;
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			INTCLKO&=0xFD;
			TIMER1_OFF;
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			INTCLKO&=0xFB;
			TIMER2_OFF;
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			T4T3M&=0xFE;
			TIMER3_OFF;
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			T4T3M&=0xEF;
			TIMER4_OFF;
		}break;	
		#endif	
		#if SYS_ERROR_EN
		default:error_printf("timer_stop(<%d>);错误的ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*-------------------------------------------------------
定时器初始化函数。
-------------------------------------------------------*/
void timer_init(void){
	u16 value;
	#if ECBM_TIMER0_EN     //判断定时器0有没有使能。
	AUXR&=0x7F;            //清空该位原来的数据。
	AUXR|=ECBM_TIMER0_AUXR;//写上设定的数据。
	TMOD&=0xF0;            //清空该位原来的数据。
	TMOD|=ECBM_TIMER0_TMOD;//写上设定的数据。
	value=65536-ECBM_TIMER0_COUNT;//计算初值。
	TL0=(u8)(value);              //写入初值。
	TH0=(u8)(value>>8);
	#if ECBM_TIMER0_IT_EN == 1    //如果开启了中断。
	TIMER0_IT_ON;
	#endif
	#endif
	
	#if ECBM_TIMER1_EN     //判断定时器1有没有使能。
	AUXR&=0xBF;            //清空该位原来的数据。
	AUXR|=ECBM_TIMER1_AUXR;//写上设定的数据。
	TMOD&=0x0F;            //清空该位原来的数据。
	TMOD|=ECBM_TIMER1_TMOD;//写上设定的数据。
	value=65536-ECBM_TIMER1_COUNT;//计算初值。
	TL1=(u8)(value);              //写入初值。
	TH1=(u8)(value>>8);
	#if ECBM_TIMER1_IT_EN == 1    //如果开启了中断。
	TIMER1_IT_ON;
	#endif
	#endif
	
	#if ECBM_TIMER2_EN     //判断定时器2有没有使能。
	AUXR&=0xF3;            //清空该位原来的数据。
	AUXR|=ECBM_TIMER2_AUXR;//写上设定的数据。
	value=65536-ECBM_TIMER2_COUNT;//计算初值。
	T2L=(u8)(value);              //写入初值。
	T2H=(u8)(value>>8);
	#if ECBM_TIMER2_IT_EN == 1    //如果开启了中断。
	TIMER2_IT_ON;
	#endif
	#endif
		
	#if ECBM_TIMER3_EN     //判断定时器3有没有使能。
	T4T3M&=0xF0;           //清空该位原来的数据。
	T4T3M|=ECBM_TIMER3_T4T3M;//写上设定的数据。
	value=65536-ECBM_TIMER3_COUNT;//计算初值。
	T3L=(u8)(value);              //写入初值。
	T3H=(u8)(value>>8);
	#if ECBM_TIMER3_IT_EN == 1    //如果开启了中断。
	TIMER3_IT_ON;
	#endif
	#endif

	#if ECBM_TIMER4_EN     //判断定时器4有没有使能。
	T4T3M&=0x0F;           //清空该位原来的数据。
	T4T3M|=ECBM_TIMER4_T4T3M;//写上设定的数据。
	value=65536-ECBM_TIMER4_COUNT;//计算初值。
	T4L=(u8)(value);              //写入初值。
	T4H=(u8)(value>>8);
	#if ECBM_TIMER4_IT_EN == 1    //如果开启了中断。
	TIMER4_IT_ON;
	#endif
	#endif
}
/*-------------------------------------------------------
定时器设定定时模式函数。
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
		#if SYS_ERROR_EN
		error_printf("请输入大于0us,小于%uus的时间\r\n",max_12T);
		#else
		while(1);
		#endif	
	}
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			if(n==1){
				TIMER0_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER0_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TL0=(u8)(n);      //写入初值。
			TH0=(u8)(n>>8);
			TIMER0_TIMER;
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			if(n==1){
				TIMER1_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER1_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			TL1=(u8)(n);      //写入初值。
			TH1=(u8)(n>>8);
			TIMER1_TIMER;
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			if(n==1){
				TIMER2_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER2_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			T2L=(u8)(n);      //写入初值。
			T2H=(u8)(n>>8);
			TIMER2_TIMER;
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			if(n==1){
				TIMER3_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER3_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			T3L=(u8)(n);      //写入初值。
			T3H=(u8)(n>>8);
			TIMER3_TIMER;
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			if(n==1){
				TIMER4_1T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/1000000.0));
			}else if(n==12){
				TIMER4_12T;
				n=65536-(u16)((float)us*((float)ecbm_sys_clk/12.0/1000000.0));
			}
			T4L=(u8)(n);      //写入初值。
			T4H=(u8)(n>>8);
			TIMER4_TIMER;
		}break;
		#endif	
		#if SYS_ERROR_EN
		default:error_printf("timer_set_timer_mode(<%d>,%u);错误的ID\r\n",(u16)id,us);break;
		#else
		default:while(1);break;
		#endif	
	}
}
/*-------------------------------------------------------
定时器设定初值函数。
-------------------------------------------------------*/
void timer_set_value(u8 id,u16 value){
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			TL0=(u8)(value);      //写入初值。
			TH0=(u8)(value>>8);
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			TL1=(u8)(value);      //写入初值。
			TH1=(u8)(value>>8);
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			T2L=(u8)(value);      //写入初值。
			T2H=(u8)(value>>8);
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			T3L=(u8)(value);      //写入初值。
			T3H=(u8)(value>>8);
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			T4L=(u8)(value);      //写入初值。
			T4H=(u8)(value>>8);
		}break;
		#endif	
		#if SYS_ERROR_EN
		default:error_printf("timer_set_value(<%d>,%u);错误的ID\r\n",(u16)id,value);break;
		#else
		default:while(1);break;
		#endif	
	}
}
/*-------------------------------------------------------
定时器计数值获取函数。
-------------------------------------------------------*/
u16 timer_get_value(u8 id){
	u16 value=0;
	switch(id){
		#if ECBM_TIMER0_EN
		case 0:{
			value=TH0*256+TL0;
		}break;		
		#endif
		#if ECBM_TIMER1_EN
		case 1:{
			value=TH1*256+TL1;
		}break;	
		#endif
		#if ECBM_TIMER2_EN
		case 2:{
			value=T2H*256+T2L;
		}break;		
		#endif
		#if ECBM_TIMER3_EN
		case 3:{
			value=T3H*256+T3L;
		}break;	
		#endif
		#if ECBM_TIMER4_EN
		case 4:{
			value=T3H*256+T3L;
		}break;
		#endif	
		#if SYS_ERROR_EN
		default:error_printf("timer_set_value(<%d>);错误的ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif	
	}
	return value;
}
#endif
