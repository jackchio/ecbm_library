/************************************
*   这是.h文件的通用模板，建立.h文件的*
*时候可以参考这个模板的模式。         *
************************************/
#ifndef _XXXX_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _XXXX_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 奈特

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
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//这里就填写当前库的各项设置。
//<q>单选框
#define dxk 1
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define XXX_XXX_XXX do{XXX_XXX}while(0) //这样定义指令型的宏定义。
#define XXX_XXX		XXX_XX				//这样定义常量型宏定义。
/*--------------------------------------变量定义-----------------------------------*/
extern u8 value;//定义需要的变量。
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用**************************XX模块*******************************/#if 1//假如一个文件内有几个不同的模块构成，可以用这个区分和分割。
/*-------------------------------------------------------
函数名：
描  述：
输  入：
输  出：
返回值：
创建者：
调用例程：
创建日期：
修改记录：
-------------------------------------------------------*/
//库函数通用关键词模板
//XXX  		库标识；开头以当前库的名字命名，比如iic库就是iic开头。
//init 		初始化；说明该函数用于初始化外设。但也不是所有外设都需要初始化才能用，比如内置eeprom。
//set		设置；说明该函数是用于设置外设的某项参数的。
//pin		引脚；常和set配合，表达设置外设的输出引脚。比如iic_set_pin。
//linkage	联动；代表这该函数用于和其他库直接耦合。通常不需要去关注它。
//start		开始；开始某项进程，具体情况根据库的不同也不同。比如iic里的start是协议的开始动作，而adc里的start是开启一次装换。
//stop		结束；结束某项进程，具体情况根据库的不同也不同。
//it		中断；表达该函数和中断有关。
//mode		模式；一般是指外设的工作模式。
//soft		软件；一些协议，如果是软件实现的，就会有这个关键词。
//auto		自动；对于一些初始化复杂的函数，自动化的填写某些参数。
//work		工作状态；对于一些共用IO，或者共用协议的外设。只能同时有一个在工作状态。需要用这个函数来设置成工作状态。
/*程序区折叠专用**************************************************************/#endif

#endif //和最上面的#ifndef配合成一个程序段。
       //以一个空行为结尾。