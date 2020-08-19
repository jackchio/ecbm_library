/*
***********************************************************************************************
*例程名    ：发送字符串
*作者      ：奈特
*库函数版本：V2.1.5-2
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程使用了GPIO库和UART库。
			3.在uart.h里可以设置串口的波特率，推荐使用可视化界面来设置。即点击代码编辑串口左下角的
			Configuration Wizard标签（只在.h文件才会有）。本例使用115200，8位，无校验，一位停止位。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	u8 count=0;			//运行统计函数。
	system_init();		//系统初始化函数，也是必须的。默认开启了自动下载功能，所以串口会在这个函数里初始化。
	while(1){
		count++;//统计循环次数，也是为了演示uart_printf的功能。
		
		uart_printf(1,"Hello,ECBM is runing at %d times.\r\n",(u16)count);//向串口1发送字符串和count的值。
		//打开串口助手，设置好COM口，115200，8位，无校验，一位停止位。即可查看。
		//注意：所有在单片机上运行的printf函数，其占位符%d均无法支持u8型变量，请使用（u16）把变量强转成u16型才能正常输出。
		
		delay_ms(1000);//发送频率不用太快，否则串口助手会因大量数据而卡死。
		//当你不慎将串口发送数据间隔设置太小，导致单片机不能正常使用自动下载功能的时候。
		//请使用冷启动来下载程序，即先断电--在STCISP上点击下载--再上电。
	}
}