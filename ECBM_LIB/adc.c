#include "ecbm_core.h"
#if ECBM_ADC_LIB_EN
/*--------------------------------------��������-----------------------------------*/
float xdata adc_ch15;
/*------------------------------------��Դ��ͻ����---------------------------------*/

/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ADC��ʼ��������
-------------------------------------------------------*/
void adc_init(){
	ADC_SET_REG_CFG(ECBM_ADC_SPEED);//����ADC������
	adc_ch15=(float)(REG_BGV)/1000.0f;//���ڲ���ѹ��׼ȡ��������ֹ֮��idata���ǡ�
#if ECBM_ADC_IT_EN
	ADC_IT_ENABLE;
#endif
#if	ECBM_ADC_CH0
	gpio_mode(A00,GPIO_HZ);
#endif
#if	ECBM_ADC_CH1
	gpio_mode(A01,GPIO_HZ);
#endif
#if	ECBM_ADC_CH2
	gpio_mode(A02,GPIO_HZ);
#endif
#if	ECBM_ADC_CH3
	gpio_mode(A03,GPIO_HZ);
#endif
#if	ECBM_ADC_CH4
	gpio_mode(A04,GPIO_HZ);
#endif
#if	ECBM_ADC_CH5
	gpio_mode(A05,GPIO_HZ);
#endif
#if	ECBM_ADC_CH6
	gpio_mode(A06,GPIO_HZ);
#endif
#if	ECBM_ADC_CH7
	gpio_mode(A07,GPIO_HZ);
#endif
#if	ECBM_ADC_CH8
	gpio_mode(A08,GPIO_HZ);
#endif
#if	ECBM_ADC_CH9
	gpio_mode(A09,GPIO_HZ);
#endif
#if	ECBM_ADC_CH10
	gpio_mode(A10,GPIO_HZ);
#endif
#if	ECBM_ADC_CH11
	gpio_mode(A11,GPIO_HZ);
#endif
#if	ECBM_ADC_CH12
	gpio_mode(A12,GPIO_HZ);
#endif
#if	ECBM_ADC_CH13
	gpio_mode(A13,GPIO_HZ);
#endif
#if	ECBM_ADC_CH14
	gpio_mode(A14,GPIO_HZ);
#endif
}
/*-------------------------------------------------------
��ѯ����ȡADֵ������
-------------------------------------------------------*/
u16 adc_read(u8 ch){
	ADC_SET_CHANNELS(ch);
	ADC_POWER_ON;
	ADC_MEASURE_ON;
	_nop_();
	_nop_();
	while(!(ADC_GET_IT_FLAG));
	ADC_IT_CLS;
	#if ECBM_ADC_8BIT//ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
	return (u16)(ADC_GET_REG_RES_H8);//���ؽ���Ĵ�����ֵ��
	#else            //�������12λ��ȡ������
	return (u16)(ADC_GET_REG_RES_HL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
	#endif
}
/*-------------------------------------------------------
ADCת����ʼ�������жϷ�����
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
void adc_read_start(u8 ch){
	ADC_SET_CHANNELS(ch);
	ADC_POWER_ON;
	ADC_MEASURE_ON;
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
	return (u16)(ADC_GET_REG_RES_H8);//���ؽ���Ĵ�����ֵ��
	#else            //�������12λ��ȡ������
	return (u16)(ADC_GET_REG_RES_HL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
	#endif
}
#endif
/*-------------------------------------------------------
��ȡ��ѹ������
-------------------------------------------------------*/
float adc_voltage(u8 ch,float vref){
	u16 jg;
	jg=adc_read(ch);//�ȶ�ȡADֵ��
	#if ECBM_ADC_8BIT//�������ã���ADֵ����ɵ�ѹֵ��
	return (float)jg*vref/256.0f;//8λ���ݡ�
	#else
	return (float)jg*vref/(ECBM_MCU_ADC_MAX);//12λ���ݡ�
	#endif
}
/*-------------------------------------------------------
����ADC�жϺ�����
-------------------------------------------------------*/
void adc_it_start(){
	ADC_IT_ENABLE;
}
/*-------------------------------------------------------
�ر�ADC�жϺ�����
-------------------------------------------------------*/
void adc_it_stop(){
	ADC_IT_DISABLE;
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
	return (adc_ch15)*(ECBM_MCU_ADC_MAX)/((float)jg);//12λ���ݡ�
	#endif
}
#endif
