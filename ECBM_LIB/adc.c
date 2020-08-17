#include "ecbm_core.h"
#if ECBM_ADC_EN
/*--------------------------------------��������-----------------------------------*/
u8 xdata adc_busy;
float xdata adc_ch15;
/*------------------------------------��Դ��ͻ����---------------------------------*/

/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ADC��ʼ��������
-------------------------------------------------------*/
void adc_init(){
	ADCCFG=ECBM_ADC_SPEED;//����ADC������
	adc_ch15=(float)(REG_BGV)/1000.0f;//���ڲ���ѹ��׼ȡ��������ֹ֮��idata���ǡ�
#if ECBM_ADC_IT_EN
	EADC=1;
#endif
#if ECBM_MCU_MAIN_RAM == 1 //STC8A8K__S4A12	
	#if ECBM_T1_ADC_CH0//��������������Ӧͨ��ʹ�ܵ�����£�����IO��Ϊ����̬����ͬ��
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH6
		gpio_mode(A06,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH7
		gpio_mode(A07,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH8
		gpio_mode(A08,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH9
		gpio_mode(A09,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH10
		gpio_mode(A10,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH11
		gpio_mode(A11,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH12
		gpio_mode(A12,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH13
		gpio_mode(A13,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH14
		gpio_mode(A14,GPIO_HZ);
	#endif
#endif
#if ECBM_MCU_MAIN_RAM == 2 //STC8G2K__S4-48PIN	
	#if ECBM_T2_ADC_CH0//��������������Ӧͨ��ʹ�ܵ�����£�����IO��Ϊ����̬����ͬ��
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH6
		gpio_mode(A06,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH7
		gpio_mode(A07,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH8
		gpio_mode(A08,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH9
		gpio_mode(A09,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH10
		gpio_mode(A10,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH11
		gpio_mode(A11,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH12
		gpio_mode(A12,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH13
		gpio_mode(A13,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH14
		gpio_mode(A14,GPIO_HZ);
	#endif
#endif
#if ECBM_MCU_MAIN_RAM == 3 //STC8G1K__A-8Pin
	#if ECBM_T3_ADC_CH0
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
#endif
}
/*-------------------------------------------------------
��ѯ����ȡADֵ������
-------------------------------------------------------*/
u16 adc_read(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//ͬ��
	_nop_();
	_nop_();
	#if ECBM_ADC_IT_EN
	adc_busy=1;
	while(adc_busy);
	#else
	while((ADC_CONTR&0x20)==0);
	ADC_CONTR&=0xDF;
	#endif
	#if ECBM_ADC_8BIT//ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
	return (u16)ADC_RES;  //���ؽ���Ĵ�����ֵ��
	#else            //�������12λ��ȡ������
	return (u16)(ADC_RES<<8|ADC_RESL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
	#endif
}
/*-------------------------------------------------------
ADCת����ʼ�������жϷ�����
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
void adc_read_start(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//ͬ��
	_nop_();
	_nop_();
}
#endif
/*-------------------------------------------------------
�жϷ���ȡADֵ������
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
u16 adc_read_it(){
	#if ECBM_ADC_8BIT//ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
	return ADC_RES;//���ؽ���Ĵ�����ֵ��
	#else //�������12λ��ȡ������
	return (ADC_RES<<8|ADC_RESL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
	#endif
}
#endif
/*-------------------------------------------------------
��ȡ��ѹ������
-------------------------------------------------------*/
float adc_voltage(u8 pin,float vref){
	u16 jg;
	jg=adc_read(pin);//�ȶ�ȡADֵ��
	#if ECBM_ADC_8BIT//�������ã���ADֵ����ɵ�ѹֵ��
	return (float)jg*vref/256.0f;//8λ���ݡ�
	#else
	return (float)jg*vref/(ECBM_MCU_ADC);//12λ���ݡ�
	#endif
}
/*-------------------------------------------------------
����ADC�жϺ�����
-------------------------------------------------------*/
void adc_it_start(){
	EADC=1;
}
/*-------------------------------------------------------
�ر�ADC�жϺ�����
-------------------------------------------------------*/
void adc_it_stop(){
	EADC=0;
}
/*-------------------------------------------------------
ADC��ȡVref������
-------------------------------------------------------*/
float adc_read_vref(void){
	u16 jg;
	jg=adc_read(15);//�ȶ�ȡADֵ��  
	if(jg==0)return 0.0f;//��ֹ����NaN
	#if ECBM_ADC_8BIT//�������ã���ADֵ����ɵ�ѹֵ��
	return (adc_ch15*256.0f)/((float)jg);//8λ���ݡ�
	#else
	return (adc_ch15)*(ECBM_MCU_ADC)/((float)jg);//12λ���ݡ�
	#endif
}
#endif
