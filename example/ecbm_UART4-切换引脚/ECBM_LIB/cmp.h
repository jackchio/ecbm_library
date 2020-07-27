#ifndef _ECBM_CMP_H_
#define _ECBM_CMP_H_
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
//<o.3>比较器“+”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“+”端可以从P3.7口输入，也可以使用当前的ADC转换脚作为输入。
//<i>（比如当前ADC在转换P1.2口，就把P1.2口当做比较器输入端。具体的引脚由ADC的寄存器决定。）
//<0=>P3.7脚  <1=>ADC转换脚  
//<o.2>比较器“-”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“-”端可以从P3.6口输入，也可以使用内部电压基准作为输入。
//<i>内部电压基准可以在STC-ISP工具上查看，每次下载的时候都能看到。电压值的范围为1.34V～1.35V。
//<1=>P3.6脚  <0=>内部电压基准 
//<o.4..5>比较器中断
//<i>实测如果输入端电压抖动太厉害的话，中断会被连续触发N次。使用时请注意。
//<0=>不开中断 <1=>比较结果从1变成0时触发中断 <2=>比较结果从0变成1时触发中断 <3=>只要比较结果发生变化都会触发中断 
//<e.1>比较器是否对外输出
//<i>比较器名字的由来，便是通过比较“+”端和“-”端的电压值大小，然后将比较结果送到输出端。
//<i>独立比较器基本都会有两个输入和一个输出，但是内置比较器可以选择不对外输出，只用中断法或查询法处理比较结果。
//<i>当输入的“+”端电压值比“-”端电压值大时，寄存器的结果为1！若选择了正向输出，则输出脚输出高电平。若选择了反向输出，则输出脚输出低电平。
//<i>当输入的“+”端电压值比“-”端电压值小时，寄存器的结果为0！若选择了正向输出，则输出脚输出低电平。若选择了反向输出，则输出脚输出高电平。
#define ECBM_CMP_CMPCR1 0x34
//<o.3>输出引脚
//<0=>P3.4 <1=>P4.1 
#define ECBM_CMP_IO 0x00
//<o.7>结果输出控制
//<0=>正向输出。
//<1=>反向输出。
//</e>
//<q.6>模拟滤波功能
//<i>开启后会添加一个0.1us的滤波。
//<o.0..5>数字滤波功能
//<0-63>
//<i>所谓数字滤波就是等待信号稳定了1~63时钟的时间后才认为数据是有效的。
//<i>不过对于24M的主频来说，也就2.6us左右。输入0代表不开启这个功能。
#define ECBM_CMP_CMPCR2 193
//<q>初始化的时候开启比较器？
//<i>勾选此选项，将会在执行cmp_init函数时开启比较器。若想在某个特定的时候才开启，就不勾选此选项。然后在那个特定的时候调用CMP_ON即可。
#define ECBM_CMP_INIT_ON 1
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define CMP_ON       do{CMPCR1|=0x80;}while(0)//开启比较器。
#define CMP_OFF      do{CMPCR1&=0x7F;}while(0)//关闭比较器。
#define CMP_CLS_IT   do{CMPCR1&=0xBF;}while(0)//清除比较器中断标志位，中断法必须要有！
#define CMP_FUN      interrupt 21             //比较器中断的中断号。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：cmp_init
描  述：比较器初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-12
修改记录：
-------------------------------------------------------*/
extern void cmp_init(void);
/*-------------------------------------------------------
函数名：cmp_read
描  述：比较器读取结果函数。
输  入：无
输  出：无
返回值：比较器的结果。
创建者：奈特
调用例程：无
创建日期：2019-12-12
修改记录：
-------------------------------------------------------*/
extern bit cmp_read(void);
/*-------------------------------------------------------
函数名：cmp_start
描  述：比较器开启函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-12
修改记录：
-------------------------------------------------------*/
extern void cmp_start(void);
/*-------------------------------------------------------
函数名：cmp_stop
描  述：比较器关闭函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-12-12
修改记录：
-------------------------------------------------------*/
extern void cmp_stop(void);
#endif
