#include "ecbm_core.h"
#if ECBM_PWM_EN
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
PWM初始化函数。
-------------------------------------------------------*/
void pwm_init(){
	PWMCKS=ECBM_PWM_CLK;//写入PWM时钟配置参数。
	PWMC  =ECBM_PWM_C;  //写入PWM计时最大值。
	#if ECBM_PWM0_EN    //如果使能了PWM的通道0。
	PWM0T1=ECBM_PWM0_T1;//写入通道0的第一次翻转点。
	PWM0T2=ECBM_PWM0_T2;//写入通道0的第二次翻转点。
	PWM0CR=ECBM_PWM0_CR;//写入通道0的配置。
	#endif
	#if ECBM_PWM1_EN    //如果使能了PWM的通道1。
	PWM1T1=ECBM_PWM1_T1;//写入通道1的第一次翻转点。
	PWM1T2=ECBM_PWM1_T2;//写入通道1的第二次翻转点。
	PWM1CR=ECBM_PWM1_CR;//写入通道1的配置。
	#endif
	#if ECBM_PWM2_EN    //如果使能了PWM的通道2。
	PWM2T1=ECBM_PWM2_T1;//写入通道2的第一次翻转点。
	PWM2T2=ECBM_PWM2_T2;//写入通道2的第二次翻转点。
	PWM2CR=ECBM_PWM2_CR;//写入通道2的配置。
	#endif
	#if ECBM_PWM3_EN    //如果使能了PWM的通道3。
	PWM3T1=ECBM_PWM3_T1;//写入通道3的第一次翻转点。
	PWM3T2=ECBM_PWM3_T2;//写入通道3的第二次翻转点。
	PWM3CR=ECBM_PWM3_CR;//写入通道3的配置。
	#endif
	#if ECBM_PWM4_EN    //如果使能了PWM的通道4。
	PWM4T1=ECBM_PWM4_T1;//写入通道4的第一次翻转点。
	PWM4T2=ECBM_PWM4_T2;//写入通道4的第二次翻转点。
	PWM4CR=ECBM_PWM4_CR;//写入通道4的配置。
	#endif
	#if ECBM_PWM5_EN    //如果使能了PWM的通道5。
	PWM5T1=ECBM_PWM5_T1;//写入通道5的第一次翻转点。
	PWM5T2=ECBM_PWM5_T2;//写入通道5的第二次翻转点。
	PWM5CR=ECBM_PWM5_CR;//写入通道5的配置。
	#endif
	#if ECBM_PWM6_EN    //如果使能了PWM的通道6。
	PWM6T1=ECBM_PWM6_T1;//写入通道6的第一次翻转点。
	PWM6T2=ECBM_PWM6_T2;//写入通道6的第二次翻转点。
	PWM6CR=ECBM_PWM6_CR;//写入通道6的配置。
	#endif
	#if ECBM_PWM7_EN    //如果使能了PWM的通道7。
	PWM7T1=ECBM_PWM7_T1;//写入通道7的第一次翻转点。
	PWM7T2=ECBM_PWM7_T2;//写入通道7的第二次翻转点。
	PWM7CR=ECBM_PWM7_CR;//写入通道7的配置。
	#endif
	#if ECBM_PWM_ETADC
	PWMCFG=ECBM_PWM_ETADC;
	TADCP=ECBM_PWM_TADCP;
	#endif
	#if (ECBM_PWM_FDCR&0x20)//如果使能了PWM异常检测。
	PWMFDCR=ECBM_PWM_FDCR;  //将其设置写入寄存器。
	#endif
	PWMCR=0x80|ECBM_PWM_ECBI;//打开PWM并写入一个配置。
}
/*-------------------------------------------------------
PWM设置频率函数。
-------------------------------------------------------*/
void pwm_set_freq(u32 freq){
	u8 i;
	u32 temp;
	for(i=1;i<16;i++){
		if((ecbm_sys_clk/i/32767)<freq)break;
	}
	temp=(ecbm_sys_clk/i/freq);
	if(temp>32767){
		LED=0;
		while(1);
	}
	PWM_OFF;
	PWMCKS=(u16)(i-1);
	PWMC=(u16)temp;
	PWM_ON;
}
/*-------------------------------------------------------
PWM设置周期函数。
-------------------------------------------------------*/
void pwm_set_cycle(u32 cycle){//80000
	u8 i;
	float tim;
	u32 n;
	for(i=1;i<16;i++){
		tim=(float)ecbm_sys_clk/(float)i/1000000.0f;
		n=(u32)(cycle*tim);
		if(n<32767)break;
	}
	if(n>32767){
		LED=0;
		while(1);
	}
	PWM_OFF;
	PWMCKS=(u16)(i-1);
	PWMC=(u16)n;
	PWM_ON;
}
/*-------------------------------------------------------
PWM设置占空比函数。
-------------------------------------------------------*/
void pwm_set_duty(u8 id,u16 duty){
	PWM_OFF;
	switch(id){
		#if ECBM_PWM0_EN
		case 0:{
			PWM0T2=0x0000;
			PWM0T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM1_EN
		case 1:{
			PWM1T2=0x0000;
			PWM1T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM2_EN
		case 2:{
			PWM2T2=0x0000;
			PWM2T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM3_EN
		case 3:{
			PWM3T2=0x0000;
			PWM3T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM4_EN
		case 4:{
			PWM4T2=0x0000;
			PWM4T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM5_EN
		case 5:{
			PWM5T2=0x0000;
			PWM5T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM6_EN
		case 6:{
			PWM6T2=0x0000;
			PWM6T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		#if ECBM_PWM7_EN
		case 7:{
			PWM7T2=0x0000;
			PWM7T1=(u16)((u32)PWMC*duty/1000);
		}break;
		#endif
		default:{
		}break;
	}
	PWM_ON;
}
/*-------------------------------------------------------
PWM设置高电平持续时间函数。
-------------------------------------------------------*/
void pwm_set_us(u8 id,u32 us){
	float tim;
	tim=(float)ecbm_sys_clk/(float)(PWMCKS+1)/1000000.0f;
	PWM_OFF;
	switch(id){
		#if ECBM_PWM0_EN
		case 0:{
			PWM0T2=0x0000;
			PWM0T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM1_EN
		case 1:{
			PWM1T2=0x0000;
			PWM1T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM2_EN
		case 2:{
			PWM2T2=0x0000;
			PWM2T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM3_EN
		case 3:{
			PWM3T2=0x0000;
			PWM3T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM4_EN
		case 4:{
			PWM4T2=0x0000;
			PWM4T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM5_EN
		case 5:{
			PWM5T2=0x0000;
			PWM5T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM6_EN
		case 6:{
			PWM6T2=0x0000;
			PWM6T1=(u16)((float)us*tim);
		}break;
		#endif
		#if ECBM_PWM7_EN
		case 7:{
			PWM7T2=0x0000;
			PWM7T1=(u16)((float)us*tim);
		}break;
		#endif
		default:{
		}break;
	}
	PWM_ON;
}
#endif
