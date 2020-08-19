#include "ecbm_core.h"
#if ECBM_EXTI_EN
/*--------------------------------------程序定义-----------------------------------*/
/*------------------------------------------------------
外部中断初始化函数。
-------------------------------------------------------*/
void exti_init(void){
	#if ECBM_EXTI0_EN    //外部中断0，即P32口。可选择触发方式。
		P3M1&=0xFB;      //设置P32为输入状态。
		P3M0&=0xFB;      //P3.2(11111011B,11111011B)。
		P32=1;           //置一，防止内部接地影响读取。
		#if ECBM_EXTI0_MODE == 0 //通过配置信息判断	。	
			EXTI0_UD;    //设置上升沿/下降沿中断。
		#else
			EXTI0_D;     //设置下降沿中断。
		#endif
		#if   ECBM_EXTI0_PRIORITY == 0 //根据优先级配置来设置。
			IPH &= 0xFE;
			IP  &= 0xFE;
		#elif ECBM_EXTI0_PRIORITY == 1
			IPH &= 0xFE;
			IP  |= 0x01;
		#elif ECBM_EXTI0_PRIORITY == 2
			IPH |= 0x01;
			IP  &= 0xFE;
		#elif ECBM_EXTI0_PRIORITY == 3
			IPH |= 0x01;
			IP  |= 0x01;
		#endif
		#if ECBM_EXTI0_INIT
			EXTI0_ON;    //打开外部中断0。
		#endif
	#endif
	
	#if ECBM_EXTI1_EN    //外部中断1，即P33口。可选择触发方式。           
		P3M1&=0xF7;      //设置P33为输入状态。
		P3M0&=0xF7;      //P3.3(11110111B,11110111B)。
		P33=1;           //置一，防止内部接地影响读取。
		#if ECBM_EXTI1_MODE == 0 //通过配置信息判断。	
			EXTI1_UD;    //设置上升沿/下降沿中断。
		#else
			EXTI1_D;     //设置下降沿中断。
		#endif
		#if   ECBM_EXTI1_PRIORITY == 0 //根据优先级配置来设置。
			IPH &= 0xFB;
			IP  &= 0xFB;
		#elif ECBM_EXTI1_PRIORITY == 1
			IPH &= 0xFB;
			IP  |= 0x04;
		#elif ECBM_EXTI1_PRIORITY == 2
			IPH |= 0x04;
			IP  &= 0xFB;
		#elif ECBM_EXTI1_PRIORITY == 3
			IPH |= 0x04;
			IP  |= 0x04;
		#endif
		#if ECBM_EXTI1_INIT
			EXTI1_ON;    //打开外部中断1。
		#endif
	#endif
	
	#if ECBM_EXTI2_EN    //外部中断2，即P36口。           
		P3M1&=0xBF;      //设置P36为输入状态。
		P3M0&=0xBF;      //P3.6(10111111B,10111111B)。
		P36=1;           //置一，防止内部接地影响读取。
		#if ECBM_EXTI2_INIT
			EXTI2_ON;    //打开外部中断2。
		#endif
	#endif
	
	#if ECBM_EXTI3_EN    //外部中断3，即P37口。              
		P3M1&=0x7F;      //设置P37为输入状态。
		P3M0&=0x7F;      //P3.7(01111111B,01111111B)。
		P37=1;           //置一，防止内部接地影响读取。	
		#if ECBM_EXTI3_INIT
			EXTI3_ON;    //打开外部中断3。
		#endif
	#endif
	
	#if ECBM_EXTI4_EN    //外部中断4，即P30口。
		P3M1&=0xFE;      //设置P30为输入状态。
		P3M0&=0xFE;      //P3.0(11111110B,11111110B)。
		P30=1;           //置一，防止内部接地影响读取。
		#if   ECBM_EXTI4_PRIORITY == 0 //根据优先级配置来设置。
			IP2H &= 0xEF;
			IP2  &= 0xEF;
		#elif ECBM_EXTI4_PRIORITY == 1
			IP2H &= 0xEF;
			IP2  |= 0x10;
		#elif ECBM_EXTI4_PRIORITY == 2
			IP2H |= 0x10;
			IP2  &= 0xEF;
		#elif ECBM_EXTI4_PRIORITY == 3
			IP2H |= 0x10;
			IP2  |= 0x10;
		#endif
		#if ECBM_EXTI4_INIT
			EXTI4_ON;            //打开外部中断4
		#endif
	#endif
}
/*------------------------------------------------------
打开中断函数。
-------------------------------------------------------*/
void exti_start(u8 id){
	switch(id){//根据ID跳到对应分支。
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
		default:error_printf("exti_start(<%d>);错误的ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*------------------------------------------------------
关闭中断函数。
-------------------------------------------------------*/
void exti_stop(u8 id){
	switch(id){//根据ID跳到对应分支。
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
		default:error_printf("exti_stop(<%d>);错误的ID\r\n",(u16)id);break;
		#else
		default:while(1);break;
		#endif
	}	
}
/*------------------------------------------------------
中断模式设置函数。
-------------------------------------------------------*/
void exti_set_mode(u8 id,bit mode){
	switch(id){//根据ID跳到对应分支。
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
		default:error_printf("exti_set_mode(<%d>,%d);错误的ID\r\n",(u16)id,(u16)mode);break;
		#else
		default:while(1);break;
		#endif
	}	
}
#endif
