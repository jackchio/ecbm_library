#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_SPI_LIB_EN 
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
SPI的引脚设置函数。
-------------------------------------------------------*/
void spi_set_pin(u8 group){
#if	((ECBM_MCU&0xF00000)<=0x200000)
	switch(group){
		case SPI_PIN_P12_P13_P14_P15:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D12,GPIO_OUT);
			#endif
			gpio_mode(D13,GPIO_OUT);
			gpio_mode(D14,GPIO_IN);
			gpio_mode(D15,GPIO_OUT);
		}break;
		case SPI_PIN_P22_P23_P24_P25:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D22,GPIO_OUT);
			#endif
			gpio_mode(D23,GPIO_OUT);
			gpio_mode(D24,GPIO_IN);
			gpio_mode(D25,GPIO_OUT);
		}break;
		case SPI_PIN_P74_P75_P76_P77:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D74,GPIO_OUT);
			#endif
			gpio_mode(D75,GPIO_OUT);
			gpio_mode(D76,GPIO_IN);
			gpio_mode(D77,GPIO_OUT);
		}break;
		case SPI_PIN_P35_P34_P33_P32:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D35,GPIO_OUT);
			#endif
			gpio_mode(D34,GPIO_OUT);
			gpio_mode(D33,GPIO_IN);
			gpio_mode(D32,GPIO_OUT);
		}break;
	}
#endif
#if	((ECBM_MCU&0xF00000)==0x300000)
	#if (ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)
	switch(group){
		case SPI_PIN_P55_P54_P33_P32:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D55,GPIO_OUT);
			#endif
			gpio_mode(D54,GPIO_OUT);
			gpio_mode(D33,GPIO_IN);
			gpio_mode(D32,GPIO_OUT);
		}break;
	}
	#else
	switch(group){
		case SPI_PIN_P12_P13_P14_P15:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D12,GPIO_OUT);
			#endif
			gpio_mode(D13,GPIO_OUT);
			gpio_mode(D14,GPIO_IN);
			gpio_mode(D15,GPIO_OUT);
		}break;
		case SPI_PIN_P22_P23_P24_P25:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D22,GPIO_OUT);
			#endif
			gpio_mode(D23,GPIO_OUT);
			gpio_mode(D24,GPIO_IN);
			gpio_mode(D25,GPIO_OUT);
		}break;
		case SPI_PIN_P54_P40_P41_P43:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D54,GPIO_OUT);
			#endif
			gpio_mode(D40,GPIO_OUT);
			gpio_mode(D41,GPIO_IN);
			gpio_mode(D43,GPIO_OUT);
		}break;
		case SPI_PIN_P35_P34_P33_P32:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D35,GPIO_OUT);
			#endif
			gpio_mode(D34,GPIO_OUT);
			gpio_mode(D33,GPIO_IN);
			gpio_mode(D32,GPIO_OUT);
		}break;
	}
	#endif
#endif
#if	((ECBM_MCU&0xF00000)==0x400000)
	#if (ECBM_MCU==0x4205C4)||(ECBM_MCU==0x4805C4)
	switch(group){
		case SPI_PIN_P54_P13_P14_P15:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D54,GPIO_OUT);
			#endif
			gpio_mode(D13,GPIO_OUT);
			gpio_mode(D14,GPIO_IN);
			gpio_mode(D15,GPIO_OUT);
		}break;
	}
	#else
	switch(group){
		case SPI_PIN_P12_P13_P14_P15:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D12,GPIO_OUT);
			#endif
			gpio_mode(D13,GPIO_OUT);
			gpio_mode(D14,GPIO_IN);
			gpio_mode(D15,GPIO_OUT);
		}break;
		case SPI_PIN_P22_P23_P24_P25:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D22,GPIO_OUT);
			#endif
			gpio_mode(D23,GPIO_OUT);
			gpio_mode(D24,GPIO_IN);
			gpio_mode(D25,GPIO_OUT);
		}break;
		case SPI_PIN_P54_P40_P41_P43:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D54,GPIO_OUT);
			#endif
			gpio_mode(D40,GPIO_OUT);
			gpio_mode(D41,GPIO_IN);
			gpio_mode(D43,GPIO_OUT);
		}break;
		case SPI_PIN_P35_P34_P33_P32:{
			#if (ECBM_SPI_REG&0x80)
			gpio_mode(D35,GPIO_OUT);
			#endif
			gpio_mode(D34,GPIO_OUT);
			gpio_mode(D33,GPIO_IN);
			gpio_mode(D32,GPIO_OUT);
		}break;
	}
	#endif
#endif	
	SPI_SET_PIN(group);	
}
/*-------------------------------------------------------
SPI初始化函数。
-------------------------------------------------------*/
void spi_init(void){
	spi_set_pin			(ECBM_SPI_IO);
	SPI_SET_REG_SPCTL	(ECBM_SPI_REG);  //使能SPI主机模式
    SPI_SET_REG_SPSTAT	(0xc0); 
	SPI_POWER_ON;
}
/*-------------------------------------------------------
SPI发送/接收函数。
-------------------------------------------------------*/
u8 spi_send(u8 dat){
	SPI_SET_REG_SPDAT(dat);		//发送测试数据
	while(!(SPI_GET_IT_FLAG));	//查询完成标志
	SPI_IT_CLS; 				//清中断标志
	return SPI_GET_REG_SPDAT;
}
#endif