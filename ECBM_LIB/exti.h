#ifndef _ECBM_EXTI_H_
#define _ECBM_EXTI_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 奈特

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
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<e>外部中断0
//<i>对应的引脚为P32
//<i>支持两种中断方式：“上升沿/下降沿”和“只下降沿”。
#define ECBM_EXTI0_EN 1
//<o>中断模式选择
//<i>“上升沿/下降沿”模式：无论上升沿还是下降沿都会触发中断。
//<i>“只下降沿”模式：只有下降沿才会触发中断。
//<0=>上升沿/下降沿 <1=>只下降沿
#define ECBM_EXTI0_MODE 0
//<o>外部中断0的中断优先级
//<i>四级中断优先可选，总体的优先级可在it库里查询。 
//<0=>0级（最低级） <1=>1级（较低级）
//<2=>2级（较高级） <3=>3级（最高级）
#define ECBM_EXTI0_PRIORITY 0
//<q>初始化时就打开中断？
//<i>如果不勾选此选项的话，可以调用EXTI_start函数打开中断。
#define ECBM_EXTI0_INIT 1
//</e>
//<e>外部中断1
//<i>对应的引脚为P33
//<i>支持两种中断方式：“上升沿/下降沿”和“只下降沿”。
#define ECBM_EXTI1_EN 0
//<o>中断模式选择
//<i>“上升沿/下降沿”模式：无论上升沿还是下降沿都会触发中断。
//<i>“只下降沿”模式：只有下降沿才会触发中断。
//<0=>上升沿/下降沿 <1=>只下降沿
#define ECBM_EXTI1_MODE 0
//<o>外部中断1的中断优先级
//<i>四级中断优先可选，总体的优先级可在it库里查询。
//<0=>0级（最低级） <1=>1级（较低级）
//<2=>2级（较高级） <3=>3级（最高级）
#define ECBM_EXTI1_PRIORITY 0
//<q>初始化时就打开中断？
//<i>如果不勾选此选项的话，可以调用EXTI_start函数打开中断。
#define ECBM_EXTI1_INIT 1
//</e>
//<e>外部中断2
//<i>对应的引脚为P36
//<i>只支持一种中断方式：“只下降沿”。固定为0级中断优先，总体的优先级可在it库里查询。
#define ECBM_EXTI2_EN 0
//<q>初始化时就打开中断？
//<i>如果不勾选此选项的话，可以调用EXTI_start函数打开中断。
#define ECBM_EXTI2_INIT 1
//</e>
//<e>外部中断3
//<i>对应的引脚为P37
//<i>只支持一种中断方式：“只下降沿”。固定为0级中断优先，总体的优先级可在it库里查询。
#define ECBM_EXTI3_EN 0
//<q>初始化时就打开中断？
//<i>如果不勾选此选项的话，可以调用EXTI_start函数打开中断。
#define ECBM_EXTI3_INIT 1
//</e>
//<e>外部中断4
//<i>对应的引脚为P30
//<i>只支持一种中断方式：“只下降沿”。
#define ECBM_EXTI4_EN 0
//<o>外部中断4的中断优先级
//<i>四级中断优先可选，总体的优先级可在it库里查询。
//<0=>0级（最低级） <1=>1级（较低级）
//<2=>2级（较高级） <3=>3级（最高级）
#define ECBM_EXTI4_PRIORITY 0
//<q>初始化时就打开中断？
//<i>如果不勾选此选项的话，可以调用EXTI_start函数打开中断。
#define ECBM_EXTI4_INIT 1
//</e>
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define EXTI0_FUN interrupt 0       //中断号，放置于中断函数之后。中断函数由用户自定义。
#define EXTI0_ON  do{EX0=1;}while(0)//打开外部中断0。
#define EXTI0_OFF do{EX0=0;}while(0)//关闭外部中断0。
#define EXTI0_UD  do{IT0=0;}while(0)//外部中断0通过上升沿和下降沿触发。
#define EXTI0_D   do{IT0=1;}while(0)//外部中断0通过下降沿触发。
#define EXTI0_IO  P32               //通过读IO的电平能知道是上升沿触发还是下降沿触发。
#define EXTI1_FUN interrupt 2       //中断号，放置于中断函数之后。中断函数由用户自定义。
#define EXTI1_ON  do{EX1=1;}while(0)//打开外部中断1。
#define EXTI1_OFF do{EX1=0;}while(0)//关闭外部中断1。
#define EXTI1_UD  do{IT1=0;}while(0)//外部中断1通过上升沿和下降沿触发。
#define EXTI1_D   do{IT1=1;}while(0)//外部中断1通过下降沿触发。
#define EXTI1_IO  P33               //通过读IO的电平能知道是上升沿触发还是下降沿触发。
#define EXTI2_FUN interrupt 10      //中断号，放置于中断函数之后。中断函数由用户自定义。
#define EXTI2_ON  do{INTCLKO|=EX2; }while(0)//打开外部中断2。
#define EXTI2_OFF do{INTCLKO&=~EX2;}while(0)//关闭外部中断2。
#define EXTI2_IO  P36 
#define EXTI3_FUN interrupt 11      //中断号，放置于中断函数之后。中断函数由用户自定义。
#define EXTI3_ON  do{INTCLKO|=EX3; }while(0)//打开外部中断3。
#define EXTI3_OFF do{INTCLKO&=~EX3;}while(0)//关闭外部中断3。
#define EXTI3_IO  P37 
#define EXTI4_FUN interrupt 16      //中断号，放置于中断函数之后。中断函数由用户自定义。
#define EXTI4_ON  do{INTCLKO|=EX4; }while(0)//打开外部中断4。
#define EXTI4_OFF do{INTCLKO&=~EX4;}while(0)//关闭外部中断4。
#define EXTI4_IO  P30 
#define EXTI_UD 0//上升沿/下降沿都触发中断。
#define EXTI_D  1//只有下降沿才触发中断。
/*--------------------------------------程序定义-----------------------------------*/
/*------------------------------------------------------
函数名：exti_init
描  述：外部中断初始化函数。在图形界面里设置好参数，然后直接调用就行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：exti_init();
创建日期：2019-7-15
修改记录：
2019-7-17：增加了中断优先级。
2019-10-14：移入2.0框架。
-------------------------------------------------------*/
extern void exti_init(void);
/*------------------------------------------------------
函数名：exti_start
描  述：打开中断函数，用于在需要打开的情况下打开对应的外部中断使能。
输  入：需要打开的外部中断ID号，可输入0~4。
输  出：无
返回值：无
创建者：奈特
调用例程：exti_start(0);//打开外部中断0的中断使能。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。
2019-10-14：移入2.0框架。
-------------------------------------------------------*/
extern void exti_start(u8 id);
/*------------------------------------------------------
函数名：exti_stop
描  述：关闭中断函数，用于在需要关闭的情况下关闭对应的外部中断使能。
输  入：需要关闭的外部中断ID号，可输入0~4。
输  出：无
返回值：无
创建者：奈特
调用例程：EXTI_stop(0);//关闭外部中断0的中断使能。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。
2019-10-14：移入2.0框架。
-------------------------------------------------------*/
extern void exti_stop(u8 id);
/*------------------------------------------------------
函数名：exti_set_mode
描  述：中断模式设置函数。只有外部中断0和外部中断1能设置。
输  入：
       id   - 设置的外部中断ID，可输入0和1。
       mode - 中断模式，有“EXTI_UD”和“EXTI_D”两种。
输  出：无
返回值：无
创建者：奈特
调用例程：exti_set_mode(0,EXTI_UD);//将外部中断0的中断模式设置为上升沿/下降沿都触发中断。
创建日期：2019-7-15
修改记录：
2019-8-14：加入报错信息功能。
2019-10-14：移入2.0框架。
-------------------------------------------------------*/
extern void exti_set_mode(u8 id,bit mode);
#endif
