#ifndef _ECBM_LCD_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_LCD_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<o.7>LCD时钟源选择
//<0=>CPU时钟
//<1=>外部32K晶振
//<o.0..2>VLCD电压选择位
//<0=>0.65*VCC
//<1=>0.70*VCC
//<2=>0.75*VCC
//<3=>0.80*VCC
//<4=>0.85*VCC
//<5=>0.90*VCC
//<6=>0.95*VCC
//<7=>1.00*VCC
#define ECBM_LCD_CFG (0x00)
//<o.0..2>死区时间
//可输入0~7。
#define ECBM_LCD_DBLEN (2)
//<o>刷新频率
//<60=>60Hz
//<i>测试中，暂不提供其他频率。
#define ECBM_LCD_FRAMERATE (60)
//<o>闪烁频率
//<1=>1Hz
//<i>测试中，暂不提供其他频率。
#define ECBM_LCD_BLANKRATE (1)
//<o.1..2>LCD显示模式
//<0=>普通显示模式
//<1=>长亮模式
//<2=>长暗模式
//<3=>闪烁模式
#define ECBM_LCD_CR (0)
//<h>COM线使能
//<q.0>COM0
//<i>P5.0
//<q.1>COM1
//<i>P5.1
//<q.2>COM2
//<i>P3.5
//<q.3>COM3
//<i>P3.6
#define ECBM_LCD_COMX_EN (0)
//</h>
//<h>SEG线使能
//<e.0>SEG0
#define ECBM_LCD_SEG0_EN (0)
//<o.0>SEG0控制脚
//<0=>P1.5
//<1=>P7.7
#define ECBM_LCD_CFG2_SEG0 (0)
//</e>
//<e.1>SEG1
#define ECBM_LCD_SEG1_EN (0)
//<o.1>SEG1控制脚
//<0=>P1.4
//<1=>P7.6
#define ECBM_LCD_CFG2_SEG1 (0)
//</e>
//<e.2>SEG2
#define ECBM_LCD_SEG2_EN (0)
//<o.2>SEG2控制脚
//<0=>P1.3
//<1=>P7.5
#define ECBM_LCD_CFG2_SEG2 (0)
//</e>
//<e.3>SEG3
#define ECBM_LCD_SEG3_EN (0)
//<o.3>SEG3控制脚
//<0=>-
//<1=>P7.4
#define ECBM_LCD_CFG2_SEG3 (0)
//</e>
//<q.4>SEG4
//<i>P4.7
//<q.5>SEG5
//<i>P1.1
//<q.6>SEG6
//<i>P1.0
//<q.7>SEG7
//<i>P0.7
#define ECBM_LCD_SEGON1 (0)
//<q.0>SEG8
//<i>P0.6
//<q.1>SEG9
//<i>P0.5
//<q.2>SEG10
//<i>P5.3
//<q.3>SEG11
//<i>P5.2
//<q.4>SEG12
//<i>P0.4
//<q.5>SEG13
//<i>P0.3
//<q.6>SEG14
//<i>P0.2
//<q.7>SEG15
//<i>P0.1
#define ECBM_LCD_SEGON2 (0)
//<q.0>SEG16
//<i>P0.0
//<q.1>SEG17
//<i>P4.6
//<q.2>SEG18
//<i>P4.5
//<q.3>SEG19
//<i>P2.7
//<q.4>SEG20
//<i>P2.6
//<q.5>SEG21
//<i>P2.5
//<q.6>SEG22
//<i>P2.4
//<q.7>SEG23
//<i>P2.3
#define ECBM_LCD_SEGON3 (0)
//<q.0>SEG24
//<i>P2.2
//<q.1>SEG25
//<i>P2.1
//<q.2>SEG26
//<i>P2.0
//<q.3>SEG27
//<i>P4.4
//<q.4>SEG28
//<i>P4.3
//<q.5>SEG29
//<i>P4.2
//<q.6>SEG30
//<i>P4.1
//<q.7>SEG31
//<i>P3.7
#define ECBM_LCD_SEGON4 (0)
//<q.0>SEG32
//<i>P7.3
//<q.1>SEG33
//<i>P7.2
//<q.2>SEG34
//<i>P7.1
//<q.3>SEG35
//<i>P7.0
//<q.4>SEG36
//<i>P6.0
//<q.5>SEG37
//<i>P6.1
//<q.6>SEG38
//<i>P6.2
//<q.7>SEG39
//<i>P6.3
#define ECBM_LCD_SEGON5 (0)
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：lcd_init
描  述：液晶初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-03-28
修改记录：
-------------------------------------------------------*/
extern void lcd_init(void);
/*-------------------------------------------------------
函数名：lcd_write_char
描  述：液晶写字节函数。
输  入：
    com     要写入的com号，可输入0~3。
    group   要写入的seg所在的组号，可输入0~4。
    dat     要写入的字节数据。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2023-03-28
修改记录：
-------------------------------------------------------*/
extern void lcd_write(u8 com,u8 group,u8 dat);

#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。