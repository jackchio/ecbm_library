#ifndef _ECBM_LCM_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_LCM_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 奈特

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
                            ***************************
                            * 联系方式 ：进群778916610 *
                            * 若1群满人：进群927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q.7>中断使能
//<o.1..3>数据总线
//<i>选择8位的时候，例如“8位[P2]”，表示用P2传输8位数据。
//<i>选择16位的时候，例如“16位[P2][P0]”，表示用P2传输高8位数据，用是P0传输低8位数据。
//<0=>8位[P2] 
//<2=>8位[P6] 
//<1=>16位[P2][P0] 
//<3=>16位[P6][P2] 
//<5=>16位[P2][P7] 
//<7=>16位[P6][P7]  
//<o.0>工作模式
//<0=>I8080模式 
//<1=>M6800模式
#define ECBM_LCM_CFG1 (0x00)
//<o.5..6>控制脚选择
//<i>8080模式下对应RS、RD和WR三个控制脚
//<i>6800模式下对应RS、E 和RW三个控制脚
//<0=>[P41][P44][P43] 
//<1=>[P41][P37][P36] 
//<2=>[P41][P42][P40] 
//<3=>[P40][P37][P36]
//<o.2..4>建立时间
//<0-7>
//<o.0..1>保持时间
//<0-3>
#define ECBM_LCM_CFG2 (0x1F)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：lcm_init
描  述：LCM接口初始化函数
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：lcm_init();//初始化LCM参数
创建日期：2021-6-9
修改记录：
-------------------------------------------------------*/
extern void lcm_init(void);
/*-------------------------------------------------------
函数名：lcm_write_8cmd
描  述：LCM发送8位指令函数（使用8位总线）
输  入：
    cmd     要发送的指令
输  出：无
返回值：无
创建者：奈特
调用例程：lcm_write_8cmd(0x50);//发送指令0x50
创建日期：2021-6-9
修改记录：
-------------------------------------------------------*/
extern void lcm_write_8cmd(u8 cmd);
/*-------------------------------------------------------
函数名：lcm_write_8data
描  述：LCM发送8位数据函数（使用8位总线）
输  入：
    dat     要发送的数据
输  出：无
返回值：无
创建者：奈特
调用例程：lcm_write_8data(0x50);//发送数据0x50
创建日期：2021-6-9
修改记录：
-------------------------------------------------------*/
extern void lcm_write_8data(u8 dat);
/*-------------------------------------------------------
函数名：lcm_write_16cmd
描  述：LCM发送16位指令函数（使用16位总线）
输  入：
    cmd     要发送的指令
输  出：无
返回值：无
创建者：奈特
调用例程：lcm_write_16cmd(0x0050);//发送指令0x0050
创建日期：2021-6-9
修改记录：
-------------------------------------------------------*/
extern void lcm_write_16cmd(u16 cmd);
/*-------------------------------------------------------
函数名：lcm_write_16data
描  述：LCM发送16位数据函数（使用16位总线）
输  入：
    dat     要发送的数据
输  出：无
返回值：无
创建者：奈特
调用例程：lcm_write_16data(0x1250);//发送数据0x1250
创建日期：2021-6-9
修改记录：
-------------------------------------------------------*/
extern void lcm_write_16data(u16 dat);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。