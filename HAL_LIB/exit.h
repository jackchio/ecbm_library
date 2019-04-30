#ifndef _ECBM_EXIT_H_
#define _ECBM_EXIT_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
	本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。联系方式：进群778916610
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM主库连接使能
//<i>此选项打勾，意味着EXIT库会使用ECBM库的其他函数（比如gpio库的gpio_mode函数）。只要ECBM库完整，就不会有编译上的问题。
//<i>此选项不打勾，意味着EXIT库能单独使用，不会再依赖其他ECBM库函数。只需要具备基本的stc8头文件即可。但此时若再加载ECBM库会有重定义报错的可能，请注意。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和exit.h置于同一个文件夹。
#define ECBM_EXIT_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用外部中断，请设为0。
//<h>优化设置
//<i>在这里选择将要使用外部中断。这样用不到的外部中断就不会编译，节约flash空间。
//<e>外部中断0
#define ECBM_EXIT0_EN 0
//</e>
//<e>外部中断1
#define ECBM_EXIT1_EN 0
//</e>
//<e>外部中断2
#define ECBM_EXIT2_EN 0
//</e>
//<e>外部中断3
#define ECBM_EXIT3_EN 0
//</e>
//<e>外部中断4
#define ECBM_EXIT4_EN 0
//</e>
//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------

/*---------------------------------------------加载头文件和预定义---------------------------------------------*/
#if ECBM_EXIT_LINK_EN
#include "ecbm.h"         //ECBM库的头文件，里面已经包含了STC8的头文件。
#else                     //如果要脱离主库运行，也应该提供STC8的头文件。头文件可从STC-ISP工具当中生成。
#include "stc.h"          //从STC-ISP工具生成时，命名为STC.h。
#include "intrins.h"      //使用nop指令所需的头文件
#define u8  unsigned char
#endif
/*-----------------------------------------------------------------------------------------------------------*/
typedef struct{
	u8 exit_num:3; //存放外部中断的编号，0~4。
	u8 exit_mode:1;//存放当前外部中断的中断方式。（不是所有外部中断都能自由选择中断方式）
	u8 exit_status:1;//存放当前外部中断的使能状态。
}exit_def;
typedef enum{
	exit0,//外部中断0
	exit1,//外部中断1
	exit2,//外部中断2
	exit3,//外部中断3
	exit4 //外部中断4	
}exit_num_def;
typedef enum{
	r_f_edge, //上升沿/下降沿都可以触发中断。
	f_edge	  //只有下降沿可以触发中断。
}exit_mode_def;
#define INT0_FUN interrupt 0   //中断号，放置于中断函数之后。中断函数由用户自定义
#define INT0_ON  EX0=1         //打开外部中断0
#define INT0_OFF EX0=0         //关闭外部中断0
#define INT0_UD  IT0=0         //外部中断0通过上升沿和下降沿触发
#define INT0_D   IT0=1         //外部中断0通过下降沿触发
#define INT0_IO  P32           //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define INT1_FUN interrupt 2   //中断号，放置于中断函数之后。中断函数由用户自定义
#define INT1_ON  EX1=1         //打开外部中断1
#define INT1_OFF EX1=0         //关闭外部中断1
#define INT1_UD  IT1=0         //外部中断1通过上升沿和下降沿触发
#define INT1_D   IT1=1         //外部中断1通过下降沿触发
#define INT1_IO  P33           //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define INT2_FUN interrupt 10  //中断号，放置于中断函数之后。中断函数由用户自定义
#define INT2_ON  INTCLKO|=EX2  //打开外部中断2
#define INT2_OFF INTCLKO&=~EX2 //关闭外部中断2
#define INT3_FUN interrupt 11  //中断号，放置于中断函数之后。中断函数由用户自定义
#define INT3_ON  INTCLKO|=EX3  //打开外部中断3
#define INT3_OFF INTCLKO&=~EX3 //关闭外部中断3
#define INT4_FUN interrupt 16  //中断号，放置于中断函数之后。中断函数由用户自定义
#define INT4_ON  INTCLKO|=EX4  //打开外部中断4
#define INT4_OFF INTCLKO&=~EX4 //关闭外部中断4
void exit_init (exit_def * exit_inf,exit_num_def exit_num,exit_mode_def exit_mode){
	exit_inf->exit_num=exit_num;
	exit_inf->exit_mode=exit_mode;
	exit_inf->exit_status=1;
	switch(exit_num){
		#if ECBM_EXIT0_EN
		case exit0:{                   //外部中断0，即P32口。可选择触发方式
			P3M1&=0xFB;                //设置P32为输入状态
			P3M0&=0xFB;                //P3.2(11111011B,11111011B)
			P32=1;                     //置一，防止内部接地影响读取
			if(exit_mode==r_f_edge){
				INT0_UD;               //设置上升沿/下降沿中断
			}else if(exit_mode==f_edge){
				INT0_D;                //设置下降沿中断
			}
			INT0_ON;                   //打开外部中断0
		}break;
		#endif
		#if ECBM_EXIT1_EN
		case exit1:{                   //外部中断1，即P33口。可选择触发方式
			P3M1&=0xF7;                //设置P33为输入状态
			P3M0&=0xF7;                //P3.3(11110111B,11110111B)
			P33=1;                     //置一，防止内部接地影响读取
			if(exit_mode==r_f_edge){
				INT1_UD;               //设置上升沿/下降沿中断
			}else if(exit_mode==f_edge){
				INT1_D;                //设置下降沿中断
			}
			INT1_ON;                   //打开外部中断1
		}break;
		#endif
		#if ECBM_EXIT2_EN
		case exit2:{                   //外部中断2，即P36口
			P3M1&=0xBF;                //设置P36为输入状态
			P3M0&=0xBF;                //P3.6(10111111B,10111111B)
			P36=1;                     //置一，防止内部接地影响读取
			INT2_ON;                   //打开外部中断2
		}break;
		#endif
		#if ECBM_EXIT3_EN
		case exit3:{                   //外部中断3，即P37口
			P3M1&=0x7F;                //设置P37为输入状态
			P3M0&=0x7F;                //P3.7(01111111B,01111111B)
			P37=1;                     //置一，防止内部接地影响读取		
			INT3_ON;                   //打开外部中断3
		}break;
		#endif
		#if ECBM_EXIT4_EN
		case exit4:{                   //外部中断4，即P30口
			P3M1&=0xFE;                //设置P30为输入状态
			P3M0&=0xFE;                //P3.0(11111110B,11111110B)
			P30=1;                     //置一，防止内部接地影响读取
			INT4_ON;                   //打开外部中断4
		}break;
		#endif
	}
	#if ECBM_EXIT_LINK_EN  == 0
	_nop_();EA=1;_nop_();              //开总中断
	#endif
}
void exit_start(exit_def * exit_inf){
	exit_inf->exit_status=1;
	switch(exit_inf->exit_num){
		#if ECBM_EXIT0_EN
		case exit0:INT0_ON;break;      //打开外部中断0
		#endif
		#if ECBM_EXIT1_EN
		case exit1:INT1_ON;break;      //打开外部中断1
		#endif
		#if ECBM_EXIT2_EN
		case exit2:INT2_ON;break;      //打开外部中断2
		#endif
		#if ECBM_EXIT3_EN
		case exit3:INT3_ON;break;      //打开外部中断3
		#endif
		#if ECBM_EXIT4_EN
		case exit4:INT4_ON;break;      //打开外部中断4
		#endif
	}
}
void exit_stop (exit_def * exit_inf){
	exit_inf->exit_status=0;
	switch(exit_inf->exit_num){
		#if ECBM_EXIT0_EN
		case exit0:INT0_OFF;break;      //关闭外部中断0
		#endif
		#if ECBM_EXIT1_EN
		case exit1:INT1_OFF;break;      //关闭外部中断1
		#endif
		#if ECBM_EXIT2_EN
		case exit2:INT2_OFF;break;      //关闭外部中断2
		#endif
		#if ECBM_EXIT3_EN
		case exit3:INT3_OFF;break;      //关闭外部中断3
		#endif
		#if ECBM_EXIT4_EN
		case exit4:INT4_OFF;break;      //关闭外部中断4
		#endif
	}
}
#endif
