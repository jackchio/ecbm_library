/*
***********************************************************************************************
*例程名    ：片内EEPROM基本操作
*作者      ：奈特
*库函数版本：V2.2.6-5
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。这个型号一定要选对，否则
			操作EEPROM的时候，会算错地址。
			2.本例程主要用了EEPROM库和UART库，通过串口反馈EEPROM的信息。
			3.本例程用到了串口，波特率在uart.h里可以设置。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	eeprom_init();		//初始化内部EEPROM。
	eeprom_erase(0);	//擦除函数，擦除地址0所在的扇区，即将该扇区共512字节的数据全变成0xff。
	eeprom_write(0,22); //向地址0,写入数据22。
	//因为“写”这个操作只能把1变成0。也就是说只有原内容是0xff的是才能写数据。而只有“擦除”这个操作才能把0变成1，也就是把储存单元的值变成0xff。
	//因此要在写函数之前先擦除。但是擦除会擦掉整个扇区共512字节的数据。所以除非整个扇区只放一个数据，不然就得做好数据备份。（当然如果这些数据是互有联系的，要改一起改要删一起删的那种，也可以不备份）
	while(1){
		delay_ms(1000);//串口不要发送太频繁，否则串口助手会卡住。这里延时1秒。
		debug("%u\r\n",(u16)eeprom_read(0));//读取地址0的数据，通过串口发送出去。debug函数其实就是调用了printf函数，而printf在C51里不支持显示u8型，所以要转换成u16型。
	}
}