#include "ecbm_core.h"
#if ECBM_PWM_EN
/*--------------------------------------程序定义-----------------------------------*/
#if  ECBM_MCU_MAIN_RAM == 1 //STC8A8K
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
#elif ECBM_MCU_MAIN_RAM == 2 //STC8G2K
/*-------------------------------------------------------
PWM初始化函数。
-------------------------------------------------------*/
void pwm_init(){
	PWMSET=ECBM_G_PWM_CONFIG|ECBM_G_P0_EN|ECBM_G_P1_EN|ECBM_G_P2_EN|ECBM_G_P3_EN|ECBM_G_P4_EN|ECBM_G_P5_EN;
	#if ECBM_G_PWM_CONFIG&0x01
		PWM0CKS=ECBM_PWM0_CKS;
		#if ECBM_PWM00_CR&0x80
			PWM00CR=ECBM_PWM00_CR;
		#endif
		#if ECBM_PWM01_CR&0x80
			PWM01CR=ECBM_PWM01_CR;
		#endif
		#if ECBM_PWM02_CR&0x80
			PWM02CR=ECBM_PWM02_CR;
		#endif
		#if ECBM_PWM03_CR&0x80
			PWM03CR=ECBM_PWM03_CR;
		#endif
		#if ECBM_PWM04_CR&0x80
			PWM04CR=ECBM_PWM04_CR;
		#endif
		#if ECBM_PWM05_CR&0x80
			PWM05CR=ECBM_PWM05_CR;
		#endif
		#if ECBM_PWM06_CR&0x80
			PWM06CR=ECBM_PWM06_CR;
		#endif
		#if ECBM_PWM07_CR&0x80
			PWM07CR=ECBM_PWM07_CR;
		#endif
	#endif
	#if ECBM_G_PWM_CONFIG&0x02
		PWM1CKS=ECBM_PWM1_CKS;
		#if ECBM_PWM10_CR&0x80
			PWM10CR=ECBM_PWM10_CR;
		#endif
		#if ECBM_PWM11_CR&0x80
			PWM11CR=ECBM_PWM11_CR;
		#endif
		#if ECBM_PWM12_CR&0x80
			PWM12CR=ECBM_PWM12_CR;
		#endif
		#if ECBM_PWM13_CR&0x80
			PWM13CR=ECBM_PWM13_CR;
		#endif
		#if ECBM_PWM14_CR&0x80
			PWM14CR=ECBM_PWM14_CR;
		#endif
		#if ECBM_PWM15_CR&0x80
			PWM15CR=ECBM_PWM15_CR;
		#endif
		#if ECBM_PWM16_CR&0x80
			PWM16CR=ECBM_PWM16_CR;
		#endif
		#if ECBM_PWM17_CR&0x80
			PWM17CR=ECBM_PWM17_CR;
		#endif
	#endif
	#if ECBM_G_PWM_CONFIG&0x04
		PWM2CKS=ECBM_PWM2_CKS;
		#if ECBM_PWM20_CR&0x80
			PWM20CR=ECBM_PWM20_CR;
		#endif
		#if ECBM_PWM21_CR&0x80
			PWM21CR=ECBM_PWM21_CR;
		#endif
		#if ECBM_PWM22_CR&0x80
			PWM22CR=ECBM_PWM22_CR;
		#endif
		#if ECBM_PWM23_CR&0x80
			PWM23CR=ECBM_PWM23_CR;
		#endif
		#if ECBM_PWM24_CR&0x80
			PWM24CR=ECBM_PWM24_CR;
		#endif
		#if ECBM_PWM25_CR&0x80
			PWM25CR=ECBM_PWM25_CR;
		#endif
		#if ECBM_PWM26_CR&0x80
			PWM26CR=ECBM_PWM26_CR;
		#endif
		#if ECBM_PWM27_CR&0x80
			PWM27CR=ECBM_PWM27_CR;
		#endif
	#endif
	#if ECBM_G_PWM_CONFIG&0x08
		PWM3CKS=ECBM_PWM3_CKS;
		#if ECBM_PWM30_CR&0x80
			PWM30CR=ECBM_PWM30_CR;
		#endif
		#if ECBM_PWM31_CR&0x80
			PWM31CR=ECBM_PWM31_CR;
		#endif
		#if ECBM_PWM32_CR&0x80
			PWM32CR=ECBM_PWM32_CR;
		#endif
		#if ECBM_PWM33_CR&0x80
			PWM33CR=ECBM_PWM33_CR;
		#endif
		#if ECBM_PWM34_CR&0x80
			PWM34CR=ECBM_PWM34_CR;
		#endif
		#if ECBM_PWM35_CR&0x80
			PWM35CR=ECBM_PWM35_CR;
		#endif
		#if ECBM_PWM36_CR&0x80
			PWM36CR=ECBM_PWM36_CR;
		#endif
		#if ECBM_PWM37_CR&0x80
			PWM37CR=ECBM_PWM37_CR;
		#endif
	#endif
	#if ECBM_G_PWM_CONFIG&0x10
		PWM4CKS=ECBM_PWM4_CKS;
		#if ECBM_PWM40_CR&0x80
			PWM40CR=ECBM_PWM40_CR;
		#endif
		#if ECBM_PWM41_CR&0x80
			PWM41CR=ECBM_PWM41_CR;
		#endif
		#if ECBM_PWM42_CR&0x80
			PWM42CR=ECBM_PWM42_CR;
		#endif
		#if ECBM_PWM43_CR&0x80
			PWM43CR=ECBM_PWM43_CR;
		#endif
		#if ECBM_PWM44_CR&0x80
			PWM44CR=ECBM_PWM44_CR;
		#endif
		#if ECBM_PWM45_CR&0x80
			PWM45CR=ECBM_PWM45_CR;
		#endif
		#if ECBM_PWM46_CR&0x80
			PWM46CR=ECBM_PWM46_CR;
		#endif
		#if ECBM_PWM47_CR&0x80
			PWM47CR=ECBM_PWM47_CR;
		#endif
	#endif
	#if ECBM_G_PWM_CONFIG&0x20
		PWM5CKS=ECBM_PWM5_CKS;
		#if ECBM_PWM50_CR&0x80
			PWM50CR=ECBM_PWM50_CR;
		#endif
		#if ECBM_PWM51_CR&0x80
			PWM51CR=ECBM_PWM51_CR;
		#endif
		#if ECBM_PWM52_CR&0x80
			PWM52CR=ECBM_PWM52_CR;
		#endif
		#if ECBM_PWM53_CR&0x80
			PWM53CR=ECBM_PWM53_CR;
		#endif
		#if ECBM_PWM54_CR&0x80
			PWM54CR=ECBM_PWM54_CR;
		#endif
		#if ECBM_PWM55_CR&0x80
			PWM55CR=ECBM_PWM55_CR;
		#endif
		#if ECBM_PWM56_CR&0x80
			PWM56CR=ECBM_PWM56_CR;
		#endif
		#if ECBM_PWM57_CR&0x80
			PWM57CR=ECBM_PWM57_CR;
		#endif
	#endif
}
/*-------------------------------------------------------
PWM设置频率函数。
-------------------------------------------------------*/
void pwm_set_freq(u8 gpio,u32 freq){
	u16 i;
	u32 temp;
	for(i=1;i<16;i++){
		if((ecbm_sys_clk/i/32767)<freq)break;
	}
	temp=(ecbm_sys_clk/i/freq);
	if(temp>32767){
		LED=0;
		while(1);
	}
	switch(gpio){
		#if ECBM_G_P0_EN&0x01
		case GPIO_P0:{
			PWM_GPIO0_OFF;
			PWM0CKS=(i-1);
			PWM0C=(u16)temp;
			PWM_GPIO0_ON;
		}break;
		#endif
		#if ECBM_G_P1_EN&0x02
		case GPIO_P1:{
			PWM_GPIO1_OFF;
			PWM1CKS=(i-1);
			PWM1C=(u16)temp;
			PWM_GPIO1_ON;
		}break;
		#endif
		#if ECBM_G_P2_EN&0x04
		case GPIO_P2:{
			PWM_GPIO2_OFF;
			PWM2CKS=(i-1);
			PWM2C=(u16)temp;
			PWM_GPIO2_ON;
		}break;
		#endif
		#if ECBM_G_P3_EN&0x08
		case GPIO_P3:{
			PWM_GPIO3_OFF;
			PWM3CKS=(i-1);
			PWM3C=(u16)temp;
			PWM_GPIO3_ON;
		}break;
		#endif
		#if ECBM_G_P4_EN&0x10
		case GPIO_P4:{
			PWM_GPIO4_OFF;
			PWM4CKS=(i-1);
			PWM4C=(u16)temp;
			PWM_GPIO4_ON;
		}break;
		#endif
		#if ECBM_G_P5_EN&0x20
		case GPIO_P5:{
			PWM_GPIO5_OFF;
			PWM5CKS=(i-1);
			PWM5C=(u16)temp;
			PWM_GPIO5_ON;
		}break;
		#endif
	}
}
/*-------------------------------------------------------
PWM设置占空比函数。
-------------------------------------------------------*/
void pwm_set_duty(u8 pin,u16 duty){
	gpio_mode(pin,GPIO_OUT);
	switch(pin){
		#if ECBM_PWM00_CR&0x80
		case D00:{
			PWM00T2=0x0000;
			PWM00T1=(u16)((u32)PWM0C*duty/1000);
			PWM00CR=ECBM_PWM00_CR;
		}break;
		#endif
		#if ECBM_PWM01_CR&0x80
		case D01:{
			PWM01T2=0x0000;
			PWM01T1=(u16)((u32)PWM0C*duty/1000);
			PWM01CR=ECBM_PWM01_CR;
		}break;
		#endif
		#if ECBM_PWM02_CR&0x80
		case D02:{
			PWM02T2=0x0000;
			PWM02T1=(u16)((u32)PWM0C*duty/1000);
			PWM02CR=ECBM_PWM02_CR;
		}break;
		#endif
		#if ECBM_PWM03_CR&0x80
		case D03:{
			PWM03T2=0x0000;
			PWM03T1=(u16)((u32)PWM0C*duty/1000);
			PWM03CR=ECBM_PWM03_CR;
		}break;
		#endif
		#if ECBM_PWM04_CR&0x80
		case D04:{
			PWM04T2=0x0000;
			PWM04T1=(u16)((u32)PWM0C*duty/1000);
			PWM04CR=ECBM_PWM04_CR;
		}break;
		#endif
		#if ECBM_PWM05_CR&0x80
		case D05:{
			PWM05T2=0x0000;
			PWM05T1=(u16)((u32)PWM0C*duty/1000);
			PWM05CR=ECBM_PWM05_CR;
		}break;
		#endif
		#if ECBM_PWM06_CR&0x80
		case D06:{
			PWM06T2=0x0000;
			PWM06T1=(u16)((u32)PWM0C*duty/1000);
			PWM06CR=ECBM_PWM06_CR;
		}break;
		#endif
		#if ECBM_PWM07_CR&0x80
		case D07:{
			PWM07T2=0x0000;
			PWM07T1=(u16)((u32)PWM0C*duty/1000);
			PWM07CR=ECBM_PWM07_CR;
		}break;
		#endif
		#if ECBM_PWM10_CR&0x80
		case D10:{
			PWM10T2=0x0000;
			PWM10T1=(u16)((u32)PWM1C*duty/1000);
			PWM10CR=ECBM_PWM10_CR;
		}break;
		#endif
		#if ECBM_PWM11_CR&0x80
		case D11:{
			PWM11T2=0x0000;
			PWM11T1=(u16)((u32)PWM1C*duty/1000);
			PWM11CR=ECBM_PWM11_CR;
		}break;
		#endif
		#if ECBM_PWM12_CR&0x80
		case D12:{
			PWM12T2=0x0000;
			PWM12T1=(u16)((u32)PWM1C*duty/1000);
			PWM12CR=ECBM_PWM12_CR;
		}break;
		#endif
		#if ECBM_PWM13_CR&0x80
		case D13:{
			PWM13T2=0x0000;
			PWM13T1=(u16)((u32)PWM1C*duty/1000);
			PWM13CR=ECBM_PWM13_CR;
		}break;
		#endif
		#if ECBM_PWM14_CR&0x80
		case D14:{
			PWM14T2=0x0000;
			PWM14T1=(u16)((u32)PWM1C*duty/1000);
			PWM14CR=ECBM_PWM14_CR;
		}break;
		#endif
		#if ECBM_PWM15_CR&0x80
		case D15:{
			PWM15T2=0x0000;
			PWM15T1=(u16)((u32)PWM1C*duty/1000);
			PWM15CR=ECBM_PWM15_CR;
		}break;
		#endif
		#if ECBM_PWM16_CR&0x80
		case D16:{
			PWM16T2=0x0000;
			PWM16T1=(u16)((u32)PWM1C*duty/1000);
			PWM16CR=ECBM_PWM16_CR;
		}break;
		#endif
		#if ECBM_PWM17_CR&0x80
		case D17:{
			PWM17T2=0x0000;
			PWM17T1=(u16)((u32)PWM1C*duty/1000);
			PWM17CR=ECBM_PWM17_CR;
		}break;
		#endif
		#if ECBM_PWM20_CR&0x80
		case D20:{
			PWM20T2=0x0000;
			PWM20T1=(u16)((u32)PWM2C*duty/1000);
			PWM20CR=ECBM_PWM20_CR;
		}break;
		#endif
		#if ECBM_PWM21_CR&0x80
		case D21:{
			PWM21T2=0x0000;
			PWM21T1=(u16)((u32)PWM2C*duty/1000);
			PWM21CR=ECBM_PWM21_CR;
		}break;
		#endif
		#if ECBM_PWM22_CR&0x80
		case D22:{
			PWM22T2=0x0000;
			PWM22T1=(u16)((u32)PWM2C*duty/1000);
			PWM22CR=ECBM_PWM22_CR;
		}break;
		#endif
		#if ECBM_PWM23_CR&0x80
		case D23:{
			PWM23T2=0x0000;
			PWM23T1=(u16)((u32)PWM2C*duty/1000);
			PWM23CR=ECBM_PWM23_CR;
		}break;
		#endif
		#if ECBM_PWM24_CR&0x80
		case D24:{
			PWM24T2=0x0000;
			PWM24T1=(u16)((u32)PWM2C*duty/1000);
			PWM24CR=ECBM_PWM24_CR;
		}break;
		#endif
		#if ECBM_PWM25_CR&0x80
		case D25:{
			PWM25T2=0x0000;
			PWM25T1=(u16)((u32)PWM2C*duty/1000);
			PWM25CR=ECBM_PWM25_CR;
		}break;
		#endif
		#if ECBM_PWM26_CR&0x80
		case D26:{
			PWM26T2=0x0000;
			PWM26T1=(u16)((u32)PWM2C*duty/1000);
			PWM26CR=ECBM_PWM26_CR;
		}break;
		#endif
		#if ECBM_PWM27_CR&0x80
		case D27:{
			PWM27T2=0x0000;
			PWM27T1=(u16)((u32)PWM2C*duty/1000);
			PWM27CR=ECBM_PWM27_CR;
		}break;
		#endif
		
		#if ECBM_PWM30_CR&0x80
		case D30:{
			PWM30T2=0x0000;
			PWM30T1=(u16)((u32)PWM3C*duty/1000);
			PWM30CR=ECBM_PWM30_CR;
		}break;
		#endif
		#if ECBM_PWM31_CR&0x80
		case D31:{
			PWM31T2=0x0000;
			PWM31T1=(u16)((u32)PWM3C*duty/1000);
			PWM31CR=ECBM_PWM31_CR;
		}break;
		#endif
		#if ECBM_PWM32_CR&0x80
		case D32:{
			PWM32T2=0x0000;
			PWM32T1=(u16)((u32)PWM3C*duty/1000);
			PWM32CR=ECBM_PWM32_CR;
		}break;
		#endif
		#if ECBM_PWM33_CR&0x80
		case D33:{
			PWM33T2=0x0000;
			PWM33T1=(u16)((u32)PWM3C*duty/1000);
			PWM33CR=ECBM_PWM33_CR;
		}break;
		#endif
		#if ECBM_PWM34_CR&0x80
		case D34:{
			PWM34T2=0x0000;
			PWM34T1=(u16)((u32)PWM3C*duty/1000);
			PWM34CR=ECBM_PWM34_CR;
		}break;
		#endif
		#if ECBM_PWM35_CR&0x80
		case D35:{
			PWM35T2=0x0000;
			PWM35T1=(u16)((u32)PWM3C*duty/1000);
			PWM35CR=ECBM_PWM35_CR;
		}break;
		#endif
		#if ECBM_PWM36_CR&0x80
		case D36:{
			PWM36T2=0x0000;
			PWM36T1=(u16)((u32)PWM3C*duty/1000);
			PWM36CR=ECBM_PWM36_CR;
		}break;
		#endif
		#if ECBM_PWM37_CR&0x80
		case D37:{
			PWM37T2=0x0000;
			PWM37T1=(u16)((u32)PWM3C*duty/1000);
			PWM37CR=ECBM_PWM37_CR;
		}break;
		#endif
		
		#if ECBM_PWM40_CR&0x80
		case D40:{
			PWM40T2=0x0000;
			PWM40T1=(u16)((u32)PWM4C*duty/1000);
			PWM40CR=ECBM_PWM40_CR;
		}break;
		#endif
		#if ECBM_PWM41_CR&0x80
		case D41:{
			PWM41T2=0x0000;
			PWM41T1=(u16)((u32)PWM4C*duty/1000);
			PWM41CR=ECBM_PWM41_CR;
		}break;
		#endif
		#if ECBM_PWM42_CR&0x80
		case D42:{
			PWM42T2=0x0000;
			PWM42T1=(u16)((u32)PWM4C*duty/1000);
			PWM42CR=ECBM_PWM42_CR;
		}break;
		#endif
		#if ECBM_PWM43_CR&0x80
		case D43:{
			PWM43T2=0x0000;
			PWM43T1=(u16)((u32)PWM4C*duty/1000);
			PWM43CR=ECBM_PWM43_CR;
		}break;
		#endif
		#if ECBM_PWM44_CR&0x80
		case D44:{
			PWM44T2=0x0000;
			PWM44T1=(u16)((u32)PWM4C*duty/1000);
			PWM44CR=ECBM_PWM44_CR;
		}break;
		#endif
		#if ECBM_PWM45_CR&0x80
		case D45:{
			PWM45T2=0x0000;
			PWM45T1=(u16)((u32)PWM4C*duty/1000);
			PWM45CR=ECBM_PWM45_CR;
		}break;
		#endif
		#if ECBM_PWM46_CR&0x80
		case D46:{
			PWM46T2=0x0000;
			PWM46T1=(u16)((u32)PWM4C*duty/1000);
			PWM46CR=ECBM_PWM46_CR;
		}break;
		#endif
		#if ECBM_PWM47_CR&0x80
		case D47:{
			PWM47T2=0x0000;
			PWM47T1=(u16)((u32)PWM4C*duty/1000);
			PWM47CR=ECBM_PWM47_CR;
		}break;
		#endif
		
		#if ECBM_PWM50_CR&0x80
		case D50:{
			PWM50T2=0x0000;
			PWM50T1=(u16)((u32)PWM5C*duty/1000);
			PWM50CR=ECBM_PWM50_CR;
		}break;
		#endif
		#if ECBM_PWM51_CR&0x80
		case D51:{
			PWM51T2=0x0000;
			PWM51T1=(u16)((u32)PWM5C*duty/1000);
			PWM51CR=ECBM_PWM51_CR;
		}break;
		#endif
		#if ECBM_PWM52_CR&0x80
		case D52:{
			PWM52T2=0x0000;
			PWM52T1=(u16)((u32)PWM5C*duty/1000);
			PWM52CR=ECBM_PWM52_CR;
		}break;
		#endif
		#if ECBM_PWM53_CR&0x80
		case D53:{
			PWM53T2=0x0000;
			PWM53T1=(u16)((u32)PWM5C*duty/1000);
			PWM53CR=ECBM_PWM53_CR;
		}break;
		#endif
		#if ECBM_PWM54_CR&0x80
		case D54:{
			PWM54T2=0x0000;
			PWM54T1=(u16)((u32)PWM5C*duty/1000);
			PWM54CR=ECBM_PWM54_CR;
		}break;
		#endif
		#if ECBM_PWM55_CR&0x80
		case D55:{
			PWM55T2=0x0000;
			PWM55T1=(u16)((u32)PWM5C*duty/1000);
			PWM55CR=ECBM_PWM55_CR;
		}break;
		#endif
		#if ECBM_PWM56_CR&0x80
		case D56:{
			PWM56T2=0x0000;
			PWM56T1=(u16)((u32)PWM5C*duty/1000);
			PWM56CR=ECBM_PWM56_CR;
		}break;
		#endif
		#if ECBM_PWM57_CR&0x80
		case D57:{
			PWM57T2=0x0000;
			PWM57T1=(u16)((u32)PWM5C*duty/1000);
			PWM57CR=ECBM_PWM57_CR;
		}break;
		#endif
	}
}
#endif
#endif