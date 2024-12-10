#ifndef _ECBM_NVIC_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_NVIC_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<q>设置优先级函数使能
//<i>如果不需要改变优先级，那么这个函数其实没有必要使能。
#define ECBM_NVIC_FUNCTION_EN (0)
//<o>EXTI0
//<i>权重值越大，优先级越高。
//<0=>56  
//<1=>126 
//<2=>196  
//<3=>266
#define ECBM_NVIC_EXTI0_PRIORITY (0)
//<o>TIMER0
//<i>权重值越大，优先级越高。
//<0=>55  
//<1=>125  
//<2=>195  
//<3=>265
#define ECBM_NVIC_TIMER0_PRIORITY (0)
//<o>EXTI1
//<i>权重值越大，优先级越高。
//<0=>54  
//<1=>124  
//<2=>194  
//<3=>264
#define ECBM_NVIC_EXTI1_PRIORITY (0)
//<o>TIMER1
//<i>权重值越大，优先级越高。
//<0=>53  
//<1=>123  
//<2=>193  
//<3=>263
#define ECBM_NVIC_TIMER1_PRIORITY (0)
//<o>UART1
//<i>权重值越大，优先级越高。
//<0=>52  
//<1=>122  
//<2=>192  
//<3=>262
#define ECBM_NVIC_UART1_PRIORITY (0)
//<o>ADC
//<i>权重值越大，优先级越高。
//<0=>51  
//<1=>121  
//<2=>191  
//<3=>261
#define ECBM_NVIC_ADC_PRIORITY (0)
//<o>LVD
//<i>权重值越大，优先级越高。
//<0=>50  
//<1=>120  
//<2=>190  
//<3=>260
#define ECBM_NVIC_LVD_PRIORITY (0)
//<o>PCA
//<i>权重值越大，优先级越高。
//<0=>49  
//<1=>119  
//<2=>189  
//<3=>259
#define ECBM_NVIC_PCA_PRIORITY (0)
//<o>UART2
//<i>权重值越大，优先级越高。
//<0=>48  
//<1=>118  
//<2=>188  
//<3=>258
#define ECBM_NVIC_UART2_PRIORITY (0)
//<o>SPI
//<i>权重值越大，优先级越高。
//<0=>47  
//<1=>117  
//<2=>187  
//<3=>257
#define ECBM_NVIC_SPI_PRIORITY (0)
//<o>EXTI2
//<i>权重值越大，优先级越高。
//<0=>46
#define ECBM_NVIC_EXTI2_PRIORITY (0)
//<o>EXTI3
//<i>权重值越大，优先级越高。
//<0=>45
#define ECBM_NVIC_EXTI3_PRIORITY (0)
//<o>TIMER2
//<i>权重值越大，优先级越高。
//<0=>44
#define ECBM_NVIC_TIMER2_PRIORITY (0)
//<o>EXTI4
//<i>权重值越大，优先级越高。
//<0=>43  
//<1=>113  
//<2=>183  
//<3=>253
#define ECBM_NVIC_EXTI4_PRIORITY (0)
//<o>UART3
//<i>权重值越大，优先级越高。
//<0=>42  
//<1=>112  
//<2=>182  
//<3=>252
#define ECBM_NVIC_UART3_PRIORITY (0)
//<o>UART4
//<i>权重值越大，优先级越高。
//<0=>41  
//<1=>111  
//<2=>181  
//<3=>251
#define ECBM_NVIC_UART4_PRIORITY (0)
//<o>TIMER3
//<i>权重值越大，优先级越高。
//<0=>40
#define ECBM_NVIC_TIMER3_PRIORITY (0)
//<o>TIMER4
//<i>权重值越大，优先级越高。
//<0=>39
#define ECBM_NVIC_TIMER4_PRIORITY (0)
//<o>CMP
//<i>权重值越大，优先级越高。
//<0=>38  
//<1=>108  
//<2=>178  
//<3=>248
#define ECBM_NVIC_CMP_PRIORITY (0)
//<o>PWM0
//<i>权重值越大，优先级越高。
//<0=>37  
//<1=>107  
//<2=>177  
//<3=>247
#define ECBM_NVIC_PWM0_PRIORITY (0)
//<o>PWM0FD
//<i>权重值越大，优先级越高。
//<0=>36  
//<1=>106  
//<2=>176  
//<3=>246
#define ECBM_NVIC_PWM0FD_PRIORITY (0)
//<o>IIC
//<i>权重值越大，优先级越高。
//<0=>35  
//<1=>105  
//<2=>175  
//<3=>245
#define ECBM_NVIC_IIC_PRIORITY (0)
//<o>USB
//<i>权重值越大，优先级越高。
//<0=>34  
//<1=>104  
//<2=>174  
//<3=>244
#define ECBM_NVIC_USB_PRIORITY (0)
//<o>PWMA
//<i>权重值越大，优先级越高。
//<0=>33  
//<1=>103  
//<2=>173  
//<3=>243
#define ECBM_NVIC_PWMA_PRIORITY (0)
//<o>PWMB
//<i>权重值越大，优先级越高。
//<0=>32  
//<1=>102  
//<2=>172  
//<3=>242
#define ECBM_NVIC_PWMB_PRIORITY (0)
//<o>PWM1
//<i>权重值越大，优先级越高。
//<0=>31  
//<1=>101  
//<2=>171  
//<3=>241
#define ECBM_NVIC_PWM1_PRIORITY (0)
//<o>PWM2
//<i>权重值越大，优先级越高。
//<0=>30  
//<1=>100  
//<2=>170  
//<3=>240
#define ECBM_NVIC_PWM2_PRIORITY (0)
//<o>PWM3
//<i>权重值越大，优先级越高。
//<0=>29  
//<1=>99  
//<2=>169  
//<3=>239
#define ECBM_NVIC_PWM3_PRIORITY (0)
//<o>PWM4
//<i>权重值越大，优先级越高。
//<0=>28  
//<1=>98  
//<2=>168 
//<3=>238
#define ECBM_NVIC_PWM4_PRIORITY (0)
//<o>PWM5
//<i>权重值越大，优先级越高。
//<0=>27  
//<1=>97  
//<2=>167  
//<3=>237
#define ECBM_NVIC_PWM5_PRIORITY (0)
//<o>PWM2FD
//<i>权重值越大，优先级越高。
//<0=>26  
//<1=>96  
//<2=>166  
//<3=>236
#define ECBM_NVIC_PWM2FD_PRIORITY (0)
//<o>PWM4FD
//<i>权重值越大，优先级越高。
//<0=>25  
//<1=>95  
//<2=>165  
//<3=>235
#define ECBM_NVIC_PWM4FD_PRIORITY (0)
//<o>TKSU
//<i>权重值越大，优先级越高。
//<0=>24  
//<1=>94  
//<2=>164  
//<3=>234
#define ECBM_NVIC_TKSU_PRIORITY (0)
//<o>RTC
//<i>权重值越大，优先级越高。
//<0=>23  
//<1=>93  
//<2=>163  
//<3=>233
#define ECBM_NVIC_RTC_PRIORITY (0)
//<o>P0INT
//<i>权重值越大，优先级越高。
//<0=>22  
//<1=>92  
//<2=>162  
//<3=>232
#define ECBM_NVIC_P0INT_PRIORITY (0)
//<o>P1INT
//<i>权重值越大，优先级越高。
//<0=>21  
//<1=>91  
//<2=>161  
//<3=>231
#define ECBM_NVIC_P1INT_PRIORITY (0)
//<o>P2INT
//<i>权重值越大，优先级越高。
//<0=>20  
//<1=>90  
//<2=>160  
//<3=>230
#define ECBM_NVIC_P2INT_PRIORITY (0)
//<o>P3INT
//<i>权重值越大，优先级越高。
//<0=>19  
//<1=>89  
//<2=>159  
//<3=>229
#define ECBM_NVIC_P3INT_PRIORITY (0)
//<o>P4INT
//<i>权重值越大，优先级越高。
//<0=>18  
//<1=>88  
//<2=>158  
//<3=>228
#define ECBM_NVIC_P4INT_PRIORITY (0)
//<o>P5INT
//<i>权重值越大，优先级越高。
//<0=>17  
//<1=>87  
//<2=>157  
//<3=>227
#define ECBM_NVIC_P5INT_PRIORITY (0)
//<o>P6INT
//<i>权重值越大，优先级越高。
//<0=>16  
//<1=>86  
//<2=>156  
//<3=>226
#define ECBM_NVIC_P6INT_PRIORITY (0)
//<o>P7INT
//<i>权重值越大，优先级越高。
//<0=>15  
//<1=>85  
//<2=>155  
//<3=>225
#define ECBM_NVIC_P7INT_PRIORITY (0)
//<o>P8INT
//<i>权重值越大，优先级越高。
//<0=>14  
//<1=>84  
//<2=>154  
//<3=>224
#define ECBM_NVIC_P8INT_PRIORITY (0)
//<o>P9INT
//<i>权重值越大，优先级越高。
//<0=>13  
//<1=>83  
//<2=>153  
//<3=>223
#define ECBM_NVIC_P9INT_PRIORITY (0)
//<o>DMA_MEM
//<i>权重值越大，优先级越高。
//<0=>12  
//<1=>82  
//<2=>152  
//<3=>222
#define ECBM_NVIC_DMA_MEM_PRIORITY (0)
//<o>DMA_ADC
//<i>权重值越大，优先级越高。
//<0=>11  
//<1=>81  
//<2=>151  
//<3=>221
#define ECBM_NVIC_DMA_ADC_PRIORITY (0)
//<o>DMA_SPI
//<i>权重值越大，优先级越高。
//<0=>10  
//<1=>80  
//<2=>150  
//<3=>220
#define ECBM_NVIC_DMA_SPI_PRIORITY (0)
//<o>DMA_UART1_TX
//<i>权重值越大，优先级越高。
//<0=>9  
//<1=>79 
//<2=>149  
//<3=>219
#define ECBM_NVIC_DMA_UART1_TX_PRIORITY (0)
//<o>DMA_UART1_RX
//<i>权重值越大，优先级越高。
//<0=>8  
//<1=>78  
//<2=>148  
//<3=>218
#define ECBM_NVIC_DMA_UART1_RX_PRIORITY (0)
//<o>DMA_UART2_TX
//<i>权重值越大，优先级越高。
//<0=>7  
//<1=>77  
//<2=>147  
//<3=>217
#define ECBM_NVIC_DMA_UART2_TX_PRIORITY (0)
//<o>DMA_UART2_RX
//<i>权重值越大，优先级越高。
//<0=>6  
//<1=>76  
//<2=>146  
//<3=>216
#define ECBM_NVIC_DMA_UART2_RX_PRIORITY (0)
//<o>DMA_UART3_TX
//<i>权重值越大，优先级越高。
//<0=>5  
//<1=>75  
//<2=>145  
//<3=>215
#define ECBM_NVIC_DMA_UART3_TX_PRIORITY (0)
//<o>DMA_UART3_RX
//<i>权重值越大，优先级越高。
//<0=>4  
//<1=>74  
//<2=>144  
//<3=>214
#define ECBM_NVIC_DMA_UART3_RX_PRIORITY (0)
//<o>DMA_UART4_TX
//<i>权重值越大，优先级越高。
//<0=>3  
//<1=>73  
//<2=>143  
//<3=>213
#define ECBM_NVIC_DMA_UART4_TX_PRIORITY (0)
//<o>DMA_UART4_RX
//<i>权重值越大，优先级越高。
//<0=>2  
//<1=>72  
//<2=>142  
//<3=>212
#define ECBM_NVIC_DMA_UART4_RX_PRIORITY (0)
//<o>DMA_LCM
//<i>权重值越大，优先级越高。
//<0=>1  
//<1=>71  
//<2=>141  
//<3=>211
#define ECBM_NVIC_DMA_LCM_PRIORITY (0)
//<o>LCM
//<i>权重值越大，优先级越高。
//<0=>0  
//<1=>70  
//<2=>140  
//<3=>210
#define ECBM_NVIC_LCM_PRIORITY (0)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：nvic_set_priority
描  述：设置优先级函数，只有在各个.h文件中使能了中断才会设置其优先级。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-02-07
修改记录：
-------------------------------------------------------*/
extern void nvic_set_priority(void);
/*-------------------------------------------------------
函数名：p0_int_callback
描  述：P0口中断回调函数。P0口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p0_int_callback(void);
/*-------------------------------------------------------
函数名：p1_int_callback
描  述：P1口中断回调函数。P1口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p1_int_callback(void);
/*-------------------------------------------------------
函数名：p2_int_callback
描  述：P2口中断回调函数。P2口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p2_int_callback(void);
/*-------------------------------------------------------
函数名：p3_int_callback
描  述：P3口中断回调函数。P3口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p3_int_callback(void);
/*-------------------------------------------------------
函数名：p4_int_callback
描  述：P4口中断回调函数。P4口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p4_int_callback(void);
/*-------------------------------------------------------
函数名：p5_int_callback
描  述：P5口中断回调函数。P5口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p5_int_callback(void);
/*-------------------------------------------------------
函数名：p6_int_callback
描  述：P6口中断回调函数。P6口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p6_int_callback(void);
/*-------------------------------------------------------
函数名：p7_int_callback
描  述：P7口中断回调函数。P7口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p7_int_callback(void);
/*-------------------------------------------------------
函数名：p8_int_callback
描  述：P8口中断回调函数。P8口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p8_int_callback(void);
/*-------------------------------------------------------
函数名：p9_int_callback
描  述：P9口中断回调函数。P9口任意IO触发中断时会调用该函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void p9_int_callback(void);
/*-------------------------------------------------------
函数名：bmm_mem_callback
描  述：BMM的MEM2MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_mem_callback(void);
/*-------------------------------------------------------
函数名：bmm_adc_callback
描  述：BMM的ADC2MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_adc_callback(void);
/*-------------------------------------------------------
函数名：bmm_spi_callback
描  述：BMM的SPI2MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_spi_callback(void);
/*-------------------------------------------------------
函数名：bmm_u1tx_callback
描  述：BMM的MEM到串口1传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u1tx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u1rx_callback
描  述：BMM的串口1到MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u1rx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u2tx_callback
描  述：BMM的MEM到串口2传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u2tx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u2rx_callback
描  述：BMM的串口2到MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u2rx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u3tx_callback
描  述：BMM的MEM到串口3传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u3tx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u3rx_callback
描  述：BMM的串口3到MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u3rx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u4tx_callback
描  述：BMM的MEM到串口4传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u4tx_callback(void);
/*-------------------------------------------------------
函数名：bmm_u4rx_callback
描  述：BMM的串口4到MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_u4rx_callback(void);
/*-------------------------------------------------------
函数名：bmm_lcm_callback
描  述：BMM的LCM2MEM传输中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void bmm_lcm_callback(void);
/*-------------------------------------------------------
函数名：lcm_it_callback
描  述：LCM接口中断回调函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-06
修改记录：
-------------------------------------------------------*/
extern void lcm_it_callback(void);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。