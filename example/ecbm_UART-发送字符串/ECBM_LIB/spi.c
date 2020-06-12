#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_SPI_EN 
/*--------------------------------------变量定义-----------------------------------*/
#if ECBM_SPI_IT_EN == 1
u8 xdata spi_busy  =0;
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
SPI的引脚设置函数。
-------------------------------------------------------*/
void spi_set_pin(u8 group){
	switch(group){
		case SPI_PIN_P1:{
			P1M1&=0xC3;
			P1M0&=0xC3;
		}break;
		case SPI_PIN_P2:{
			P2M1&=0xC3;
			P2M0&=0xC3;
		}break;
		case SPI_PIN_P7:{
			P7M1&=0xC3;
			P7M0&=0xC3;
		}break;
		case SPI_PIN_P3:{
			P3M1&=0xC3;
			P3M0&=0xC3;
		}break;
	}
	P_SW1&=0xf3;
	P_SW1|=group;	
}
/*-------------------------------------------------------
SPI初始化函数。
-------------------------------------------------------*/
void spi_init(void){
	spi_set_pin(ECBM_SPI_IO);
	SPCTL  = ECBM_SPI_REG;  //使能SPI主机模式
    SPSTAT = 0xc0; 
	#if ECBM_SPI_IT_EN
	SPI_IT_ON;
		#if   ECBM_SPI_IT_PRIORITY == 0
		IP2H &= 0xFD;
		IP2  &= 0xFD;
		#elif ECBM_SPI_IT_PRIORITY == 1
		IP2H &= 0xFD;
		IP2  |= 0x02;
		#elif ECBM_SPI_IT_PRIORITY == 2
		IP2H |= 0x02;
		IP2  &= 0xFD;
		#elif ECBM_SPI_IT_PRIORITY == 3
		IP2H |= 0x02;
		IP2  |= 0x02;
		#endif
	#endif
}
/*-------------------------------------------------------
SPI发送/接收函数。
-------------------------------------------------------*/
u8 spi_send(u8 dat){
	SPDAT = dat;                           //发送测试数据
	#if ECBM_SPI_IT_EN == 0
    while (!(SPSTAT & 0x80));               //查询完成标志
    SPSTAT = 0xc0;                          //清中断标志
	#else
	spi_busy=1;
	while(spi_busy);
	#endif
	return SPDAT;
}
#endif