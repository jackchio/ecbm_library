#include "ecbm_core.h"
#if ECBM_PWM_EN
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
PWM��ʼ��������
-------------------------------------------------------*/
void pwm_init(){
	PWMCKS=ECBM_PWM_CLK;//д��PWMʱ�����ò�����
	PWMC  =ECBM_PWM_C;  //д��PWM��ʱ���ֵ��
	#if ECBM_PWM0_EN    //���ʹ����PWM��ͨ��0��
	PWM0T1=ECBM_PWM0_T1;//д��ͨ��0�ĵ�һ�η�ת�㡣
	PWM0T2=ECBM_PWM0_T2;//д��ͨ��0�ĵڶ��η�ת�㡣
	PWM0CR=ECBM_PWM0_CR;//д��ͨ��0�����á�
	#endif
	#if ECBM_PWM1_EN    //���ʹ����PWM��ͨ��1��
	PWM1T1=ECBM_PWM1_T1;//д��ͨ��1�ĵ�һ�η�ת�㡣
	PWM1T2=ECBM_PWM1_T2;//д��ͨ��1�ĵڶ��η�ת�㡣
	PWM1CR=ECBM_PWM1_CR;//д��ͨ��1�����á�
	#endif
	#if ECBM_PWM2_EN    //���ʹ����PWM��ͨ��2��
	PWM2T1=ECBM_PWM2_T1;//д��ͨ��2�ĵ�һ�η�ת�㡣
	PWM2T2=ECBM_PWM2_T2;//д��ͨ��2�ĵڶ��η�ת�㡣
	PWM2CR=ECBM_PWM2_CR;//д��ͨ��2�����á�
	#endif
	#if ECBM_PWM3_EN    //���ʹ����PWM��ͨ��3��
	PWM3T1=ECBM_PWM3_T1;//д��ͨ��3�ĵ�һ�η�ת�㡣
	PWM3T2=ECBM_PWM3_T2;//д��ͨ��3�ĵڶ��η�ת�㡣
	PWM3CR=ECBM_PWM3_CR;//д��ͨ��3�����á�
	#endif
	#if ECBM_PWM4_EN    //���ʹ����PWM��ͨ��4��
	PWM4T1=ECBM_PWM4_T1;//д��ͨ��4�ĵ�һ�η�ת�㡣
	PWM4T2=ECBM_PWM4_T2;//д��ͨ��4�ĵڶ��η�ת�㡣
	PWM4CR=ECBM_PWM4_CR;//д��ͨ��4�����á�
	#endif
	#if ECBM_PWM5_EN    //���ʹ����PWM��ͨ��5��
	PWM5T1=ECBM_PWM5_T1;//д��ͨ��5�ĵ�һ�η�ת�㡣
	PWM5T2=ECBM_PWM5_T2;//д��ͨ��5�ĵڶ��η�ת�㡣
	PWM5CR=ECBM_PWM5_CR;//д��ͨ��5�����á�
	#endif
	#if ECBM_PWM6_EN    //���ʹ����PWM��ͨ��6��
	PWM6T1=ECBM_PWM6_T1;//д��ͨ��6�ĵ�һ�η�ת�㡣
	PWM6T2=ECBM_PWM6_T2;//д��ͨ��6�ĵڶ��η�ת�㡣
	PWM6CR=ECBM_PWM6_CR;//д��ͨ��6�����á�
	#endif
	#if ECBM_PWM7_EN    //���ʹ����PWM��ͨ��7��
	PWM7T1=ECBM_PWM7_T1;//д��ͨ��7�ĵ�һ�η�ת�㡣
	PWM7T2=ECBM_PWM7_T2;//д��ͨ��7�ĵڶ��η�ת�㡣
	PWM7CR=ECBM_PWM7_CR;//д��ͨ��7�����á�
	#endif
	#if ECBM_PWM_ETADC
	PWMCFG=ECBM_PWM_ETADC;
	TADCP=ECBM_PWM_TADCP;
	#endif
	#if (ECBM_PWM_FDCR&0x20)//���ʹ����PWM�쳣��⡣
	PWMFDCR=ECBM_PWM_FDCR;  //��������д��Ĵ�����
	#endif
	PWMCR=0x80|ECBM_PWM_ECBI;//��PWM��д��һ�����á�
}
/*-------------------------------------------------------
PWM����Ƶ�ʺ�����
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
PWM�������ں�����
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
PWM����ռ�ձȺ�����
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
PWM���øߵ�ƽ����ʱ�亯����
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
