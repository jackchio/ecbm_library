#include "ecbm_core.h"	//加载库函数的头文件。
#include "oled.h"
oled_def oled_main;
sbit pga1=P4^1;
sbit pga2=P4^2;
sbit pga3=P4^3;
sbit cap1=P4^4;
void main(){			//main函数，必须的。
	u8 i;
	system_init();		//系统初始化函数，也是必须的。
	adc_init();
	delay_ms(500);
	oled_auto_init(&oled_main,"softiic,scl=P25,sda=P24");
	gpio_mode(D41,GPIO_OUT);
	gpio_mode(D42,GPIO_OUT);
	gpio_mode(D43,GPIO_OUT);
	gpio_mode(D44,GPIO_OUT);
	pga1=0;
	pga2=1;
	pga3=1;
	cap1=1;
	//oled_display_y_test(&oled_main);
	while(1){
		oled_printf(&oled_main,0,0,"ADC=%0.3f",adc_voltage(7,2.502f)*5.576f);
		oled_printf(&oled_main,0,1,"%5u",(u16)i++);
		//oled_display_mode_test(&oled_main,(i++)&0x0f);
		//debug("i am working\r\n");
		delay_ms(500);
	}
}