#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_IT_EN      //编译开关，当配置文件没有加载该外设的.h文件时，就不编译该.c文件
/*--------------------------------------变量定义-----------------------------------*/
#if ECBM_IT_CHECK_EN == 1
u8 STC8A_IT_LIST[22][9]={
{21,'I','N','T','0',' ',' ',0,0},//0
{20,'T','i','m','e','r','0',0,0},//1
{19,'I','N','T','1',' ',' ',0,0},//2
{18,'T','i','m','e','r','1',0,0},//3
{17,'U','A','R','T','1',' ',0,0},//4
{16,'A','D','C',' ',' ',' ',0,0},//5
{15,'L','V','D',' ',' ',' ',0,0},//6
{14,'P','C','A',' ',' ',' ',0,0},//7
{13,'U','A','R','T','2',' ',0,0},//8
{12,'S','P','I',' ',' ',' ',0,0},//9
{11,'I','N','T','2',' ',' ',0,0},//10
{10,'I','N','T','3',' ',' ',0,0},//11
{ 9,'T','i','m','e','r','2',0,0},//12
{ 8,'I','N','T','4',' ',' ',0,0},//13
{ 7,'U','A','R','T','3',' ',0,0},//14
{ 6,'U','A','R','T','4',' ',0,0},//15
{ 5,'T','i','m','e','r','3',0,0},//16
{ 4,'T','i','m','e','r','4',0,0},//17
{ 3,'C','M','P',' ',' ',' ',0,0},//18
{ 2,'P','W','M',' ',' ',' ',0,0},//19
{ 1,'P','W','M','F','D',' ',0,0},//20
{ 0,'I','I','C',' ',' ',' ',0,0},//21
};
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
中断优先级检测函数。
-------------------------------------------------------*/
void it_priority_check(void){
	#if ECBM_IT_CHECK_EN == 1
	u8 i,j,k,buf;
	if(IP &0x01)IT_LIST[0][0]+=IT_RANGE_1;//INT0
	if(IPH&0x01)IT_LIST[0][0]+=IT_RANGE_2;
	if(EX0)     IT_LIST[0][8]=1;
	
	if(IP &0x02)IT_LIST[1][0]+=IT_RANGE_1;//Timer0
	if(IPH&0x02)IT_LIST[1][0]+=IT_RANGE_2;
	if(ET0)     IT_LIST[1][8]=1;
	
	if(IP &0x04)IT_LIST[2][0]+=IT_RANGE_1;//INT1
	if(IPH&0x04)IT_LIST[2][0]+=IT_RANGE_2;
	if(EX1)     IT_LIST[2][8]=1;
	
	if(IP &0x08)IT_LIST[3][0]+=IT_RANGE_1;//Timer1
	if(IPH&0x08)IT_LIST[3][0]+=IT_RANGE_2;
	if(ET1)     IT_LIST[3][8]=1;
	
	if(IP &0x10)IT_LIST[4][0]+=IT_RANGE_1;//UART1
	if(IPH&0x10)IT_LIST[4][0]+=IT_RANGE_2;
	if(ES)      IT_LIST[4][8]=1;
	
	if(IP &0x20)IT_LIST[5][0]+=IT_RANGE_1;//ADC
	if(IPH&0x20)IT_LIST[5][0]+=IT_RANGE_2;
	if(EADC)    IT_LIST[5][8]=1;
	
	if(IP &0x40)IT_LIST[6][0]+=IT_RANGE_1;//LVD
	if(IPH&0x40)IT_LIST[6][0]+=IT_RANGE_2;
	if(ELVD)    IT_LIST[6][8]=1;
	
	if(IP &0x80)IT_LIST[7][0]+=IT_RANGE_1;//PCA
	if(IPH&0x80)IT_LIST[7][0]+=IT_RANGE_2;
	if(CMOD&0x01)IT_LIST[7][8]=1;
	
	if(IP2 &0x01)IT_LIST[8][0]+=IT_RANGE_1;//UART2
	if(IP2H&0x01)IT_LIST[8][0]+=IT_RANGE_2;
	if(IE2 &0x01)IT_LIST[8][8]=1;
	
	if(IP2 &0x02)IT_LIST[9][0]+=IT_RANGE_1;//SPI
	if(IP2H&0x02)IT_LIST[9][0]+=IT_RANGE_2;
	if(IE2 &0x02)IT_LIST[9][8]=1;
	
	if(IP2 &0x04)IT_LIST[19][0]+=IT_RANGE_1;//PWM
	if(IP2H&0x04)IT_LIST[19][0]+=IT_RANGE_2;
	if(PWMCR&0x40)IT_LIST[19][8]=1;
	
	if(IP2 &0x08)IT_LIST[20][0]+=IT_RANGE_1;//PWMFD
	if(IP2H&0x08)IT_LIST[20][0]+=IT_RANGE_2;
	if(PWMFDCR&0x08)IT_LIST[20][8]=1;
	
	if(IP2 &0x10)IT_LIST[13][0]+=IT_RANGE_1;//INT4
	if(IP2H&0x10)IT_LIST[13][0]+=IT_RANGE_2;
	if(INTCLKO&0x40)IT_LIST[13][8]=1;
	
	if(IP2 &0x20)IT_LIST[18][0]+=IT_RANGE_1;//CMP
	if(IP2H&0x20)IT_LIST[18][0]+=IT_RANGE_2;
	if(CMPCR1&0x30)IT_LIST[18][8]=1;
	
	if(IP2 &0x40)IT_LIST[21][0]+=IT_RANGE_1;//IIC
	if(IP2H&0x40)IT_LIST[21][0]+=IT_RANGE_2;
	if(I2CMSCR&0x80)IT_LIST[21][8]=1;
	
	
	if(INTCLKO&0x10)IT_LIST[10][8]=1;//INT2
	if(INTCLKO&0x20)IT_LIST[11][8]=1;//INT3
	if(IE2 &0x04)IT_LIST[12][8]=1;//Timer2
	if(IE2 &0x08)IT_LIST[14][8]=1;//UART3
	if(IE2 &0x10)IT_LIST[15][8]=1;//UART4
	if(IE2 &0x20)IT_LIST[16][8]=1;//Timer3
	if(IE2 &0x40)IT_LIST[17][8]=1;//Timer4
	
	for(i=0;i<22;i++){
		for(j=i+1;j<22;j++){
			if(IT_LIST[i][0]<IT_LIST[j][0]){
				for(k=0;k<9;k++){
					buf=IT_LIST[i][k];
					IT_LIST[i][k]=IT_LIST[j][k];
					IT_LIST[j][k]=buf;
				}
			}
		}
	}
	for(i=0;i<22;i++){
		if(IT_LIST[i][8])debug("%s\r\n",&IT_LIST[i][1]);		
	}
	#else
	debug("没有使能该功能\r\n");
	#endif
}
/*-------------------------------------------------------
外部中断0的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_int0(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x01;
			IP &=~0x01;
		}break;
		case 1:{
			IPH&=~0x01;
			IP |= 0x01;
		}break;
		case 2:{
			IPH|= 0x01;
			IP &=~0x01;
		}break;
		case 3:{
			IPH|= 0x01;
			IP |= 0x01;
		}break;
	}
}
/*-------------------------------------------------------
定时器0的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_timer0(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x02;
			IP &=~0x02;
		}break;
		case 1:{
			IPH&=~0x02;
			IP |= 0x02;
		}break;
		case 2:{
			IPH|= 0x02;
			IP &=~0x02;
		}break;
		case 3:{
			IPH|= 0x02;
			IP |= 0x02;
		}break;
	}
}
/*-------------------------------------------------------
外部中断1的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_int1(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x04;
			IP &=~0x04;
		}break;
		case 1:{
			IPH&=~0x04;
			IP |= 0x04;
		}break;
		case 2:{
			IPH|= 0x04;
			IP &=~0x04;
		}break;
		case 3:{
			IPH|= 0x04;
			IP |= 0x04;
		}break;
	}
}
/*-------------------------------------------------------
定时器1的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_timer1(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x08;
			IP &=~0x08;
		}break;
		case 1:{
			IPH&=~0x08;
			IP |= 0x08;
		}break;
		case 2:{
			IPH|= 0x08;
			IP &=~0x08;
		}break;
		case 3:{
			IPH|= 0x08;
			IP |= 0x08;
		}break;
	}
}
/*-------------------------------------------------------
串口1的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_uart1(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x10;
			IP &=~0x10;
		}break;
		case 1:{
			IPH&=~0x10;
			IP |= 0x10;
		}break;
		case 2:{
			IPH|= 0x10;
			IP &=~0x10;
		}break;
		case 3:{
			IPH|= 0x10;
			IP |= 0x10;
		}break;
	}
}
/*-------------------------------------------------------
ADC的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_adc(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x20;
			IP &=~0x20;
		}break;
		case 1:{
			IPH&=~0x20;
			IP |= 0x20;
		}break;
		case 2:{
			IPH|= 0x20;
			IP &=~0x20;
		}break;
		case 3:{
			IPH|= 0x20;
			IP |= 0x20;
		}break;
	}
}
/*-------------------------------------------------------
LVD的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_lvd(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x40;
			IP &=~0x40;
		}break;
		case 1:{
			IPH&=~0x40;
			IP |= 0x40;
		}break;
		case 2:{
			IPH|= 0x40;
			IP &=~0x40;
		}break;
		case 3:{
			IPH|= 0x40;
			IP |= 0x40;
		}break;
	}
}
/*-------------------------------------------------------
函数名：it_set_pca
描  述：PCA的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
void it_set_pca(u8 priority){
	switch(priority){
		case 0:{
			IPH&=~0x80;
			IP &=~0x80;
		}break;
		case 1:{
			IPH&=~0x80;
			IP |= 0x80;
		}break;
		case 2:{
			IPH|= 0x80;
			IP &=~0x80;
		}break;
		case 3:{
			IPH|= 0x80;
			IP |= 0x80;
		}break;
	}
}
/*-------------------------------------------------------
串口2的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_uart2(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x01;
			IP2 &=~0x01;
		}break;
		case 1:{
			IP2H&=~0x01;
			IP2 |= 0x01;
		}break;
		case 2:{
			IP2H|= 0x01;
			IP2 &=~0x01;
		}break;
		case 3:{
			IP2H|= 0x01;
			IP2 |= 0x01;
		}break;
	}
}
/*-------------------------------------------------------
SPI的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_spi(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x02;
			IP2 &=~0x02;
		}break;
		case 1:{
			IP2H&=~0x02;
			IP2 |= 0x02;
		}break;
		case 2:{
			IP2H|= 0x02;
			IP2 &=~0x02;
		}break;
		case 3:{
			IP2H|= 0x02;
			IP2 |= 0x02;
		}break;
	}
}
/*-------------------------------------------------------
PWM的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_pwm(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x04;
			IP2 &=~0x04;
		}break;
		case 1:{
			IP2H&=~0x04;
			IP2 |= 0x04;
		}break;
		case 2:{
			IP2H|= 0x04;
			IP2 &=~0x04;
		}break;
		case 3:{
			IP2H|= 0x04;
			IP2 |= 0x04;
		}break;
	}
}
/*-------------------------------------------------------
PWMFD的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_pwmfd(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x08;
			IP2 &=~0x08;
		}break;
		case 1:{
			IP2H&=~0x08;
			IP2 |= 0x08;
		}break;
		case 2:{
			IP2H|= 0x08;
			IP2 &=~0x08;
		}break;
		case 3:{
			IP2H|= 0x08;
			IP2 |= 0x08;
		}break;
	}
}
/*-------------------------------------------------------
外部中断4的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_int4(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x10;
			IP2 &=~0x10;
		}break;
		case 1:{
			IP2H&=~0x10;
			IP2 |= 0x10;
		}break;
		case 2:{
			IP2H|= 0x10;
			IP2 &=~0x10;
		}break;
		case 3:{
			IP2H|= 0x10;
			IP2 |= 0x10;
		}break;
	}
}
/*-------------------------------------------------------
CMP的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_cmp(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x20;
			IP2 &=~0x20;
		}break;
		case 1:{
			IP2H&=~0x20;
			IP2 |= 0x20;
		}break;
		case 2:{
			IP2H|= 0x20;
			IP2 &=~0x20;
		}break;
		case 3:{
			IP2H|= 0x20;
			IP2 |= 0x20;
		}break;
	}
}
/*-------------------------------------------------------
IIC的中断优先级设置函数。
-------------------------------------------------------*/
void it_set_iic(u8 priority){
	switch(priority){
		case 0:{
			IP2H&=~0x40;
			IP2 &=~0x40;
		}break;
		case 1:{
			IP2H&=~0x40;
			IP2 |= 0x40;
		}break;
		case 2:{
			IP2H|= 0x40;
			IP2 &=~0x40;
		}break;
		case 3:{
			IP2H|= 0x40;
			IP2 |= 0x40;
		}break;
	}
}
/*-------------------------------------------------------
全体中断优先级一键设置函数。
-------------------------------------------------------*/
void it_set_all(void){
	it_set_int0  (ECBM_IT_INT0_PRIORITY);
	it_set_timer0(ECBM_IT_TIMER0_PRIORITY);
	it_set_int1  (ECBM_IT_INT1_PRIORITY);
	it_set_timer1(ECBM_IT_TIMER1_PRIORITY);
	it_set_uart1 (ECBM_IT_UART1_PRIORITY);
	it_set_adc   (ECBM_IT_ADC_PRIORITY);
	it_set_lvd   (ECBM_IT_LVD_PRIORITY);
	it_set_pca   (ECBM_IT_PCA_PRIORITY);
	it_set_uart2 (ECBM_IT_UART2_PRIORITY);
	it_set_spi   (ECBM_IT_SPI_PRIORITY);
	it_set_pwm   (ECBM_IT_PWM_PRIORITY);
	it_set_pwmfd (ECBM_IT_PWMFD_PRIORITY);
	it_set_int4  (ECBM_IT_INT4_PRIORITY);
	it_set_cmp   (ECBM_IT_CMP_PRIORITY);
	it_set_iic   (ECBM_IT_IIC_PRIORITY);
}
/*-------------------------------------------------------
全体中断优先级一键还原函数。
-------------------------------------------------------*/
void it_reset_all(void){
	it_set_int0  (0);
	it_set_timer0(0);
	it_set_int1  (0);
	it_set_timer1(0);
	it_set_uart1 (0);
	it_set_adc   (0);
	it_set_lvd   (0);
	it_set_pca   (0);
	it_set_uart2 (0);
	it_set_spi   (0);
	it_set_pwm   (0);
	it_set_pwmfd (0);
	it_set_int4  (0);
	it_set_cmp   (0);
	it_set_iic   (0);
}
#endif
