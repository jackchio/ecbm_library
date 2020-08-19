/*
***********************************************************************************************
*例程名    ：环形流水灯
*作者      ：奈特
*库函数版本：V2.1.5-2
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程使用了GPIO库，UART库只是做自动下载功能而已。
			3.本例程由于使用了STC8A8K64S4A12的48脚单片机，所以也是按照这款单片机的引脚排布来写代码。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/

//由于环形流水灯这个概念不常见，所以我解释一下。限于篇幅和排版，我拿8脚单片机举例。
//以下是电路连接示意图：
//                        -----------
//3.3V----LED1----电阻----|P5.4  P3.3|----电阻----LED6----3.3V
//3.3V--------------------|VCC   P3.2|----电阻----LED5----3.3V
//3.3V----LED2----电阻----|P5.5  P3.1|----电阻----LED4----3.3V
//GND---------------------|GND   P3.0|----电阻----LED3----3.3V
//                        -----------
//就是流水灯从LED1点亮到LED6，正好绕单片机一圈，所以叫环形流水灯。
//其中最大的难点在于IO的排列有时候没有那么规律，也都不在同一个P口上，所以无法用左移右移。
//这时候用gpio库就好办了。

#include "ecbm_core.h"	//加载库函数的头文件。
u8 code io_list[]={//先把引脚顺序定义好，这里参照的的是STC8A8K64S4A12的48脚封装。从1号脚开始。
D52,D53,D11,D12,D13,D14,D44,D15,D16,D17,
D54,D55,D40,D30,D31,D32,D33,D34,D35,
D50,D51,D36,D37,D41,D20,D42,D21,D22,D23,D24,D25,
D26,D27,D00,D01,D02,D43,D03,D04,D05,D06,D07,D10,
};
void main(){			//main函数，必须的。
	u8 i;				//定义循环用的变量。
	system_init();		//系统初始化函数，也是必须的。
	for(i=0;i<43;i++){	//一共43个IO口，
		gpio_mode(io_list[i],GPIO_OUT);//所有IO口全部定义成推挽模式。
	}
	for(i=0;i<5;i++){	//因为是低电平点亮LED，所以先设置P0到P5的所有IO口全输出1，让所有LED熄灭。
		gpio_write(i,0xff);//设置P0~P5口输出0xff，也就是每个IO都输出高电平。
	}
	while(1){
		for(i=0;i<43;i++){//一共43个IO口，依次点亮。
			gpio_out(io_list[i],0);//IO口输出低电平就可以点亮LED。
			delay_ms(500);//适当的延时会使得观赏性更好。
		}
		for(i=0;i<5;i++){	//点亮完一圈之后，让所有LED熄灭。然后又接着点亮，如此反复。
			gpio_write(i,0xff);//设置P0~P5口输出0xff，也就是每个IO都输出高电平。
		}
	}
}