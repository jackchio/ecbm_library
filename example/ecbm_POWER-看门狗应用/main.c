/*
***********************************************************************************************
*例程名    ：看门狗应用
*作者      ：奈特
*库函数版本：V2.2.6-5
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程主要用了GPIO库和POWER库，使能UART库是为了提供自动下载功能。
			3.本例程将会用到一个LED来指示工作状态，因此如果用的不是ECBM的开发板的话，需要自己定义一个
			LED引脚。在本例中，LED定义到P5.5脚，低电平点亮。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	LED_ON;//点亮LED
	delay_ms(1000);//延时1秒。
	LED_OFF;//关闭LED，也就是说LED将会点亮1秒钟。
	wdt_start();//启动看门狗。
	while(1){
		//看门狗的设置在power.h里，打开图形化界面后，
		//找到“优化和功能使能”，点进去找到“看门狗”。使能该功能后可以选择看门狗的分频系数。
		//比如本例中，单片机运行在24MHz下，分频系数16。那么看门狗溢出时间为12*32768*16/24000000=0.262144秒。
		delay_ms(200);//将延时设置为200毫秒，也就是0.2秒。
		wdt_feed();//每0.2秒喂一次，看门狗就不会溢出。
		//由于看门狗没有溢出，你能看到的现象就是单片机在上电的时候，LED亮了一秒，然后就一直熄灭了。
		//接下来可以试着把延时从200ms改成500ms，此时由于喂狗不及时，看门狗就会溢出，复位单片机。
		//于是从头开始执行代码，LED又被点亮了。所以此时的现象是LED在不停的闪烁。
	}
}