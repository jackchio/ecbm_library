#include "ecbm_core.h"
#if ECBM_ADC_EN
/*--------------------------------------变量定义-----------------------------------*/
u8 xdata adc_busy;
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_MCU_ADC == 0)&&(ECBM_MCU_OTHER == 0)
#error 目前选中的单片机型号不支持ADC，请在ecbm_core.h里检查单片机型号，或者关闭adc库的使能。
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
ADC初始化函数。
-------------------------------------------------------*/
void adc_init(){
	ADCCFG=ECBM_ADC_SPEED;//设置ADC的配置
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
#if ECBM_ADC_CH0//在链接主库且相应通道使能的情况下，设置IO口为高阻态。下同。
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
查询法读取AD值函数。
-------------------------------------------------------*/
#if ECBM_ADC_8BIT//使能8位数据模式的话，编译8位读取函数。
u8 adc_read(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//开电源|开始转换|通道号
	_nop_();//流水线结构，需要一定的延时。
	_nop_();
	#if ECBM_ADC_IT_EN
	adc_busy=1;
	while(adc_busy);
	#else 
	while((ADC_CONTR&0x20)==0);//等待转换完毕。
	ADC_CONTR&=0xDF;//清掉转换标志位。
	#endif
	return ADC_RES;//返回结果寄存器的值。
}
#else //否则编译12位读取函数。
u16 adc_read(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//同上
	_nop_();
	_nop_();
	#if ECBM_ADC_IT_EN
	adc_busy=1;
	while(adc_busy);
	#else
	while((ADC_CONTR&0x20)==0);
	ADC_CONTR&=0xDF;
	#endif
	return (ADC_RES<<8|ADC_RESL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
}
#endif
/*-------------------------------------------------------
ADC转换开始函数（中断法）。
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
void adc_read_start(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//同上
	_nop_();
	_nop_();
}
#endif
/*-------------------------------------------------------
中断法读取AD值函数。
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
	#if ECBM_ADC_8BIT//使能8位数据模式的话，编译8位读取函数。
u8 adc_read_it(){
	return ADC_RES;//返回结果寄存器的值。
}
	#else //否则编译12位读取函数。
u16 adc_read_it(){
	return (ADC_RES<<8|ADC_RESL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
}
	#endif
#endif
/*-------------------------------------------------------
读取电压函数。
-------------------------------------------------------*/
float adc_voltage(u8 pin,float vref){
	u16 jg;
	jg=(u16)adc_read(pin);//先读取AD值。
	#if ECBM_ADC_8BIT//根据设置，把AD值换算成电压值。
	return (float)jg*vref/256.0f;//8位数据。
	#else
	return (float)jg*vref/(float)(ECBM_MCU_ADC);//12位数据。
	#endif
}
/*-------------------------------------------------------
开启ADC中断函数。
-------------------------------------------------------*/
void adc_it_start(){
	EADC=1;
}
/*-------------------------------------------------------
关闭ADC中断函数。
-------------------------------------------------------*/
void adc_it_stop(){
	EADC=0;
}
#endif
