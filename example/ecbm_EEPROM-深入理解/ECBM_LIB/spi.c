#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_SPI_EN 
/*--------------------------------------��������-----------------------------------*/
#if ECBM_SPI_IT_EN == 1
u8 xdata spi_busy  =0;
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
SPI���������ú�����
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
SPI��ʼ��������
-------------------------------------------------------*/
void spi_init(void){
	spi_set_pin(ECBM_SPI_IO);
	SPCTL  = ECBM_SPI_REG;  //ʹ��SPI����ģʽ
    SPSTAT = 0xc0; 
	#if ECBM_SPI_IT_EN
	SPI_IT_ON;
	#endif
}
/*-------------------------------------------------------
SPI����/���պ�����
-------------------------------------------------------*/
u8 spi_send(u8 dat){
	SPDAT = dat;                           //���Ͳ�������
	#if ECBM_SPI_IT_EN == 0
    while (!(SPSTAT & 0x80));               //��ѯ��ɱ�־
    SPSTAT = 0xc0;                          //���жϱ�־
	#else
	spi_busy=1;
	while(spi_busy);
	#endif
	return SPDAT;
}
#endif