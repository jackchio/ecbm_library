#ifndef _ECBM_PCA_H_
#define _ECBM_PCA_H_
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
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q.7>空闲模式下是否停止PCA计数
//<i>勾选：空闲模式下PCA停止计数。
//<i>不勾选：空闲模式下PCA继续计数。
//<o.1..3>PCA计数脉冲源
//<2=>定时器0的溢出脉冲 <3=>ECI脚的外部输入时钟 <4=>SYSCLK    <1=>SYSCLK/2 
//<5=>SYSCLK/4         <6=>SYSCLK/6           <7=>SYSCLK/8  <0=>SYSCLK/12 
//<q.0>PCA计数器溢出中断使能
#define ECBM_PCA_CMOD 0x08
//<e>PCA0
#define ECBM_PCA0_EN 0
//<q.6>允许PCA模块0的比较功能
//<q.5>允许PCA模块0进行上升沿捕获
//<q.4>允许PCA模块0进行下降沿捕获
//<q.3>允许PCA模块0的匹配功能
//<q.2>允许PCA模块0的高速脉冲输出功能
//<q.1>允许PCA模块0的脉宽调制输出功能
//<q.0>允许PCA模块0的匹配/捕获中断
#define ECBM_PCA0_CCAPM0 0x00
//</e>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#include "ecbm_core.h"
#endif
