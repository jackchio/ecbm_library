#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_PCA_EN      //���뿪�أ��������ļ�û�м��ظ������.h�ļ�ʱ���Ͳ������.c�ļ�
/*--------------------------------------��������-----------------------------------*/
#if ECBM_PCA0_EN
u8  pca_mode_0=0;
u16 pca_timer_count_0=0;
u16 pca_timer_add_0=0;
#endif
#if ECBM_PCA1_EN
u8  pca_mode_1=0;
u16 pca_timer_count_1=0;
u16 pca_timer_add_1=0;
#endif
#if ECBM_PCA2_EN
u8  pca_mode_2=0;
u16 pca_timer_count_2=0;
u16 pca_timer_add_2=0;
#endif
#if ECBM_PCA3_EN
u8  pca_mode_3=0;
u16 pca_timer_count_3=0;
u16 pca_timer_add_3=0;
#endif
/*------------------------------------��Դ��ͻ����---------------------------------*/
//#if ECBM_XXX_XX < XX
//#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
PCA��ʼ���ú�����
-------------------------------------------------------*/
void pca_init(){
	CCON=0;	//��ʼ��PCA���ƼĴ���
	CL  =0;	//��λPCA�Ĵ���
	CH  =0;
	CMOD=ECBM_PCA_CMOD;
	pca_set_io(ECBM_PCA_IO);
	#if ECBM_PCA0_EN
	pca_set_mode(0,ECBM_PCA0_MODE);
	#endif
	#if ECBM_PCA1_EN
	pca_set_mode(1,ECBM_PCA1_MODE);
	#endif
	#if ECBM_PCA2_EN
	pca_set_mode(2,ECBM_PCA2_MODE);
	#endif
	#if ECBM_PCA3_EN
	pca_set_mode(3,ECBM_PCA3_MODE);
	#endif
	CR=1;
}
/*-------------------------------------------------------
PCA����IOӳ�亯����
-------------------------------------------------------*/
void pca_set_io(u8 io){
	switch(io){
		case PCA_PIN_P1:{
			P_SW1=(P_SW1&0xCF)|PCA_PIN_P1;
		}break;
		case PCA_PIN_P2:{
			P_SW1=(P_SW1&0xCF)|PCA_PIN_P2;
		}break;
		case PCA_PIN_P7:{
			P_SW1=(P_SW1&0xCF)|PCA_PIN_P7;
		}break;
		case PCA_PIN_P3:{
			P_SW1=(P_SW1&0xCF)|PCA_PIN_P3;
		}break;
		#if SYS_ERROR_EN
		default:error_printf("pca_set_io(<PCA_PIN_P%02X>);����ӳ�䵽��IO\r\n",(u16)io);break;
		#else
		default:while(1);break;
		#endif
	}
}
/*-------------------------------------------------------
PCA��PWMģʽ�µ�ռ�ձ����ú�����
-------------------------------------------------------*/
void pca_set_mode(u8 id,u8 mode){
	u8 pca_pwmx,pca_ccapmx;
	switch(mode){
		case 0:{
			
		}break;
		case 1:{//6λPWMģʽ
			pca_pwmx=0x80;
			pca_ccapmx=PCA_ECOMn_1|PCA_PWMn_1;
		}break;
		case 2:{//7λPWMģʽ
			pca_pwmx=0x40;
			pca_ccapmx=PCA_ECOMn_1|PCA_PWMn_1;
		}break;
		case 3:{//8λPWMģʽ
			pca_pwmx=0x00;
			pca_ccapmx=PCA_ECOMn_1|PCA_PWMn_1;
		}break;
		case 4:{//10λPWMģʽ
			pca_pwmx=0xC0;
			pca_ccapmx=PCA_ECOMn_1|PCA_PWMn_1;
		}break;
		case 5:{//16λ����ģʽ
			pca_ccapmx=ECBM_PCA0_UP_DOWN|0x01;
		}break;
		case 6:{//16λ�����ʱ��
			pca_ccapmx=PCA_ECOMn_1|PCA_MATn_1|0x01;
		}break;
		case 7:{//16λ�����������
			pca_ccapmx=PCA_ECOMn_1|PCA_MATn_1|PCA_TOGn_1|0x01;
		}break;
	}
	switch(id){
		#if ECBM_PCA0_EN
		case 0:{
			pca_mode_0=mode;
			if((mode>0)&&(mode<5)){
				PCA_PWM0=pca_pwmx;
			}
			CCAPM0=pca_ccapmx;
			CCAP0L= 0;  
			CCAP0H= 0;
		}break;
		#endif
		#if ECBM_PCA1_EN
		case 1:{
			pca_mode_1=mode;
			if((mode>0)&&(mode<5)){
				PCA_PWM1=pca_pwmx;
			}
			CCAPM1=pca_ccapmx;
			CCAP1L= 0;  
			CCAP1H= 0;
		}break;
		#endif
		#if ECBM_PCA2_EN
		case 2:{
			pca_mode_2=mode;
			if((mode>0)&&(mode<5)){
				PCA_PWM2=pca_pwmx;
			}
			CCAPM2=pca_ccapmx;
			CCAP2L= 0;  
			CCAP2H= 0;
		}break;
		#endif
		#if ECBM_PCA3_EN
		case 3:{
			pca_mode_3=mode;
			if((mode>0)&&(mode<5)){
				PCA_PWM3=pca_pwmx;
			}
			CCAPM3=pca_ccapmx;
			CCAP3L= 0;  
			CCAP3H= 0;
		}break;
		#endif
	}
}
/*-------------------------------------------------------
PCA�ڶ�ʱ��ģʽ������������ģʽ�µļ���ֵ���ú���
-------------------------------------------------------*/
void pca_set_timer(u8 id,u16 count){
	switch(id){
		#if ECBM_PCA0_EN
		case 0:{
			if(pca_mode_0>=6){
				pca_timer_count_0=count;
				pca_timer_add_0  =count;
			}
			CCAP0L=pca_timer_count_0;
			CCAP0H=pca_timer_count_0>>8;
			pca_timer_count_0+=pca_timer_add_0;
		}break;
		#endif
		#if ECBM_PCA1_EN
		case 1:{
			if(pca_mode_1>=6){
				pca_timer_count_1=count;
				pca_timer_add_1  =count;
			}
			CCAP1L=pca_timer_count_1;
			CCAP1H=pca_timer_count_1>>8;
			pca_timer_count_1+=pca_timer_add_1;
		}break;
		#endif
		#if ECBM_PCA2_EN
		case 2:{
			if(pca_mode_2>=6){
				pca_timer_count_2=count;
				pca_timer_add_2  =count;
			}
			CCAP2L=pca_timer_count_2;
			CCAP2H=pca_timer_count_2>>8;
			pca_timer_count_2+=pca_timer_add_2;
		}break;
		#endif
		#if ECBM_PCA3_EN
		case 3:{
			if(pca_mode_3>=6){
				pca_timer_count_3=count;
				pca_timer_add_3  =count;
			}
			CCAP3L=pca_timer_count_3;
			CCAP3H=pca_timer_count_3>>8;
			pca_timer_count_3+=pca_timer_add_3;
		}break;
		#endif
	}
}
/*-------------------------------------------------------
PCA��PWMģʽ�µ�ռ�ձ����ú�����
-------------------------------------------------------*/
void pca_set_duty(u8 id,u16 duty){
	u8 pcax,pcah=0,mode;
	u16 temp;
	if((mode<=4)&&(mode>0)){
		switch(id){
			#if ECBM_PCA0_EN
			case 0:{
				mode=pca_mode_0;
			}break;
			#endif
			#if ECBM_PCA1_EN
			case 1:{
				mode=pca_mode_1;
			}break;
			#endif
			#if ECBM_PCA2_EN
			case 2:{
				mode=pca_mode_2;
			}break;
			#endif
			#if ECBM_PCA3_EN
			case 3:{
				mode=pca_mode_3;
			}break;
			#endif
		}
		switch(mode){
			case 1:{//6λPWMģʽ
				if(duty>=1000){
					temp=0;
				}else{
					temp=(u16)((64*(1000-(u32)duty))/1000);
				}
				pcax=(u8)(temp&0x3F);
				if(temp&0x0040){
					pcah=0x02;
				}
			}break;
			case 2:{//7λPWMģʽ
				if(duty>=1000){
					temp=0;
				}else{
					temp=(u16)((128*(1000-(u32)duty))/1000);
				}
				pcax=(u8)(temp&0x7F);
				if(temp&0x0080){
					pcah=0x02;
				}
			}break;
			case 3:{//8λPWMģʽ
				if(duty>=1000){
					temp=0;
				}else{
					temp=(u16)((256*(1000-(u32)duty))/1000);
				}
				pcax=(u8)(temp);
				if(temp&0x0100){
					pcah=0x02;
				}
			}break;
			case 4:{//10λPWMģʽ
				if(duty>=1000){
					temp=0;
				}else{
					temp=(u16)((1024*(1000-(u32)duty))/1000);
				}
				pcax=(u8)(temp);
				pcah=(u8)(temp>>4)&0x30;
				if(temp&0x0400){
					pcah|=0x02;
				}
			}break;
		}
		switch(id){
			#if ECBM_PCA0_EN
			case 0:{
				PCA_PWM0=(PCA_PWM0&0xC0)|pcah;
				CCAP0H=pcax;
			}break;
			#endif
			#if ECBM_PCA1_EN
			case 1:{
				PCA_PWM1=(PCA_PWM1&0xC0)|pcah;
				CCAP1H=pcax;
			}break;
			#endif
			#if ECBM_PCA2_EN
			case 2:{
				PCA_PWM2=(PCA_PWM2&0xC0)|pcah;
				CCAP2H=pcax;
			}break;
			#endif
			#if ECBM_PCA3_EN
			case 3:{
				PCA_PWM3=(PCA_PWM3&0xC0)|pcah;
				CCAP3H=pcax;
			}break;
			#endif
		}
	}
}
/*-------------------------------------------------------
PCA�ĸ����жϴ�������
-------------------------------------------------------*/
void PCA_Isr() interrupt 7{
	if(CF){
		CF=0;
		#if ECBM_PCA_CALLBACK_EN == 1
		pca_timer_callback();
		#endif
	}
	#if ECBM_PCA0_EN
	if(CCF0){
		CCF0 = 0;
		#if ECBM_PCA0_TIMER_AUTO_EN == 1
		if(pca_mode_0>=6){
			CCAP0L=(u8)(pca_timer_count_0);//380ns
			CCAP0H=(u8)(pca_timer_count_0>>8);//120ns
			pca_timer_count_0+=pca_timer_add_0;//880ns
		}
		#endif
		#if ECBM_PCA0_CALLBACK_EN == 1
		pca0_callback();
		#endif
	}
	#endif
	#if ECBM_PCA1_EN
	if(CCF1){
		CCF1 = 0;
		#if ECBM_PCA1_TIMER_AUTO_EN == 1
		if(pca_mode_1>=6){
			CCAP1L=(u8)(pca_timer_count_1);//380ns
			CCAP1H=(u8)(pca_timer_count_1>>8);//120ns
			pca_timer_count_1+=pca_timer_add_1;//880ns
		}
		#endif
		#if ECBM_PCA1_CALLBACK_EN == 1
		pca1_callback();
		#endif
	}
	#endif
	#if ECBM_PCA2_EN
	if(CCF2){
		CCF2 = 0;
		#if ECBM_PCA2_TIMER_AUTO_EN == 1
		if(pca_mode_2>=6){
			CCAP2L=(u8)(pca_timer_count_2);//380ns
			CCAP2H=(u8)(pca_timer_count_2>>8);//120ns
			pca_timer_count_2+=pca_timer_add_2;//880ns
		}
		#endif
		#if ECBM_PCA2_CALLBACK_EN == 1
		pca2_callback();
		#endif
	}
	#endif
	#if ECBM_PCA3_EN
	if(CCF3){
		CCF3 = 0;
		#if ECBM_PCA3_TIMER_AUTO_EN == 1
		if(pca_mode_3>=6){
			CCAP3L=(u8)(pca_timer_count_3);//380ns
			CCAP3H=(u8)(pca_timer_count_3>>8);//120ns
			pca_timer_count_3+=pca_timer_add_3;//880ns
		}
		#endif
		#if ECBM_PCA3_CALLBACK_EN == 1
		pca3_callback();
		#endif
	}
	#endif
}
#endif
