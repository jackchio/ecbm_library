#include "ecbm_core.h"
#if ECBM_ADC_EN
/*--------------------------------------��������-----------------------------------*/
u8 xdata adc_busy;
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_MCU_ADC == 0)&&(ECBM_MCU_OTHER == 0)
#error Ŀǰѡ�еĵ�Ƭ���ͺŲ�֧��ADC������ecbm_core.h���鵥Ƭ���ͺţ����߹ر�adc���ʹ�ܡ�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ADC��ʼ��������
-------------------------------------------------------*/
void adc_init(){
	ADCCFG=ECBM_ADC_SPEED;//����ADC������
#if ECBM_ADC_IT_EN
	EADC=1;
	#if   ECBM_ADC_PRIORITY == 0
		IPH &= 0xDF;
		IP  &= 0xDF;
	#elif ECBM_ADC_PRIORITY == 1
		IPH &= 0xDF;
		IP  |= 0x20;
	#elif ECBM_ADC_PRIORITY == 2
		IPH |= 0x20;
		IP  &= 0xDF;
	#elif ECBM_ADC_PRIORITY == 3
		IPH |= 0x20;
		IP  |= 0x20;
	#endif	
#endif
#if ECBM_ADC_CH0//��������������Ӧͨ��ʹ�ܵ�����£�����IO��Ϊ����̬����ͬ��
	gpio_mode(A00,GPIO_HZ);
#endif
#if ECBM_ADC_CH1
	gpio_mode(A01,GPIO_HZ);
#endif
#if ECBM_ADC_CH2
	gpio_mode(A02,GPIO_HZ);
#endif
#if ECBM_ADC_CH3
	gpio_mode(A03,GPIO_HZ);
#endif
#if ECBM_ADC_CH4
	gpio_mode(A04,GPIO_HZ);
#endif
#if ECBM_ADC_CH5
	gpio_mode(A05,GPIO_HZ);
#endif
#if ECBM_ADC_CH6
	gpio_mode(A06,GPIO_HZ);
#endif
#if ECBM_ADC_CH7
	gpio_mode(A07,GPIO_HZ);
#endif
#if ECBM_ADC_CH8
	gpio_mode(A08,GPIO_HZ);
#endif
#if ECBM_ADC_CH9
	gpio_mode(A09,GPIO_HZ);
#endif
#if ECBM_ADC_CH10
	gpio_mode(A10,GPIO_HZ);
#endif
#if ECBM_ADC_CH11
	gpio_mode(A11,GPIO_HZ);
#endif
#if ECBM_ADC_CH12
	gpio_mode(A12,GPIO_HZ);
#endif
#if ECBM_ADC_CH13
	gpio_mode(A13,GPIO_HZ);
#endif
#if ECBM_ADC_CH14
	gpio_mode(A14,GPIO_HZ);
#endif
}
/*-------------------------------------------------------
��ѯ����ȡADֵ������
-------------------------------------------------------*/
#if ECBM_ADC_8BIT//ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
u8 adc_read(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//����Դ|��ʼת��|ͨ����
	_nop_();//��ˮ�߽ṹ����Ҫһ������ʱ��
	_nop_();
	#if ECBM_ADC_IT_EN
	adc_busy=1;
	while(adc_busy);
	#else 
	while((ADC_CONTR&0x20)==0);//�ȴ�ת����ϡ�
	ADC_CONTR&=0xDF;//���ת����־λ��
	#endif
	return ADC_RES;//���ؽ���Ĵ�����ֵ��
}
#else //�������12λ��ȡ������
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
	return (ADC_RES<<8|ADC_RESL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
}
#endif
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
	#if ECBM_ADC_8BIT//ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
u8 adc_read_it(){
	return ADC_RES;//���ؽ���Ĵ�����ֵ��
}
	#else //�������12λ��ȡ������
u16 adc_read_it(){
	return (ADC_RES<<8|ADC_RESL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
}
	#endif
#endif
/*-------------------------------------------------------
��ȡ��ѹ������
-------------------------------------------------------*/
float adc_voltage(u8 pin,float vref){
	u16 jg;
	jg=(u16)adc_read(pin);//�ȶ�ȡADֵ��
	#if ECBM_ADC_8BIT//�������ã���ADֵ����ɵ�ѹֵ��
	return (float)jg*vref/256.0f;//8λ���ݡ�
	#else
	return (float)jg*vref/(float)(ECBM_MCU_ADC);//12λ���ݡ�
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
#endif
