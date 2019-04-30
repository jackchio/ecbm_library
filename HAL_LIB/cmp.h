#ifndef _ECBM_CMP_H_
#define _ECBM_CMP_H_
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
//<i>GPIO库为基础库，几乎没有依赖其他库。因此即可直接单独使用，又可联合使用。
//<i>所以此选项打勾，只是意味着GPIO库会使用ECBM库的头文件。此选项不打勾，则会使用基本的stc8头文件。
//<i>stc8头文件可从STC-ISP工具当中生成。从STC-ISP工具生成头文件时，请命名为stc.h并和gpio.h置于同一个文件夹。
#define ECBM_CMP_LINK_EN 1 //和ecbm库连接的使能，如果想脱离主库单独使用外部中断，请设为0。
//<h>比较器配置
//<i>在这里选择内部比较器的配置
//<o>比较器“+”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“+”端可以从P3.7口输入，也可以使用当前的ADC转换脚作为输入。
//<i>（比如当前ADC在转换P1.2口，就把P1.2口当做比较器输入端。具体的引脚由ADC的寄存器决定。）
//<0xF7=>P3.7脚  <0x08=>ADC转换脚  
#define ECBM_CMP_INP 247
//<o>比较器“-”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“-”端可以从P3.6口输入，也可以使用内部电压基准作为输入。
//<i>内部电压基准可以在STC-ISP工具上查看，每次下载的时候都能看到。电压值的范围为1.34V～1.35V。
//<0x04=>P3.6脚  <0xFB=>内部电压基准 
#define ECBM_CMP_INN 4
//<o>比较器输出端
//<i>比较器名字的由来，便是通过比较“+”端和“-”端的电压值大小，然后将比较结果送到输出端。
//<i>独立比较器基本都会有两个输入和一个输出，但是内置比较器可以选择不对外输出，只用中断法或查询法处理比较结果。
//<i>当输入的“+”端电压值比“-”端电压值大时，寄存器的结果为1！若选择了正向输出，则输出脚输出高电平。若选择了反向输出，则输出脚输出低电平。
//<i>当输入的“+”端电压值比“-”端电压值小时，寄存器的结果为0！若选择了正向输出，则输出脚输出低电平。若选择了反向输出，则输出脚输出高电平。
//<0xFD=>不对外输出 <0x02=>正向输出到P3.4脚 <0x03=>正向输出到P4.1脚 <0x06=>反向输出到P3.4脚 <0x07=>反向输出到P4.1脚
#define ECBM_CMP_OUT 253
//<o>比较器中断
//<i>实测如果输入端电压抖动太厉害的话，中断会被连续触发N次。使用时请注意。
//<0x00=>不开中断 <0x20=>比较结果从0变成1时触发中断 <0x10=>比较结果从1变成0时触发中断 <0x30=>只要比较结果发生变化都会触发中断 
#define ECBM_CMP_IT 0
//<q>初始化的时候开启比较器？
//<i>勾选此选项，将会在执行cmp_init函数时开启比较器。若想在某个特定的时候才开启，就不勾选此选项。然后在那个特定的时候调用CMP_ON即可。
#define ECBM_CMP_INIT_ON 1
//</h>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
#if ECBM_CMP_LINK_EN
#include "ecbm.h"//ECBM库的头文件，里面已经包含了STC8的头文件。
#else            //如果要脱离主库运行，也应该提供STC8的头文件。头文件可从STC-ISP工具当中生成。
#include "stc.h" //从STC-ISP工具生成时，命名为STC.h。
#define u8 unsigned char
#endif


#define CMP_INP_D37  0xF7
#define CMP_INP_ADC  0x08

#define CMP_INN_D36  0x04
#define CMP_INN_BGV  0xFB

#define CMP_OUT_D34  0x02
#define CMP_OUT_D34N 0x06
#define CMP_OUT_D41  0x03
#define CMP_OUT_D41N 0x07
#define CMP_OUT_OFF  0xFD

#define CMP_IT_U   0x20
#define CMP_IT_D   0x10
#define CMP_IT_UD  0x30
#define CMP_IT_OFF 0x00


#define CMP_ON     CMPCR1|=0x80
#define CMP_OFF    CMPCR1&=0x7F
#define CMP_CLS_IT CMPCR1&=0xBF
#define CMP_FUN    interrupt 21


void cmp_init(){
	u8 reg;
	reg=CMPCR1;//避免频繁更改寄存器，先读出来缓存。
	#if   ECBM_CMP_INP == CMP_INP_D37
	reg&=CMP_INP_D37;//输入脚“+”选择为P3.7脚
	#elif ECBM_CMP_INP == CMP_INP_ADC
	reg|=CMP_INP_ADC;//输入脚“-”选择为ADC转换脚
	#endif
	#if   ECBM_CMP_INN == CMP_INN_D36
	reg|=CMP_INN_D36;//输入脚“-”选择为P3.6脚
	#elif ECBM_CMP_INN == CMP_INN_BGV
	reg&=CMP_INN_BGV;//输入脚“-”选择为内部电压基准
	#endif
	#if   ECBM_CMP_OUT == CMP_OUT_D34
	reg|=(CMP_OUT_D34&0x02);//打开输出
	CMPCR2&=0x7F;			//正向输出
	P_SW2&=0xF7;			//D34
	#elif ECBM_CMP_OUT == CMP_OUT_D34N
	reg|=(CMP_OUT_D34N&0x02);//打开输出
	CMPCR2|=0x80;			 //反向输出
	P_SW2&=0xF7;			//D34
	#elif ECBM_CMP_OUT == CMP_OUT_D41
	reg|=(CMP_OUT_D41&0x02);//打开输出
	CMPCR2&=0x7F;			//正向输出
	P_SW2|=0x08;			//D41
	#elif ECBM_CMP_OUT == CMP_OUT_D41N
	reg|=(CMP_OUT_D41N&0x02);//打开输出
	CMPCR2|=0x80;			 //反向输出
	P_SW2|=0x08;			//D41
	#elif ECBM_CMP_OUT == CMP_OUT_OFF
	reg&=CMP_OUT_OFF;
	#endif
	CMPCR1=reg;//将输入输出设置保存先
	CMPCR1&=0xCF;//清除中断位
	#if   ECBM_CMP_IT == CMP_IT_U
	CMPCR1|=CMP_IT_U;//使能结果值上升沿中断
	#elif ECBM_CMP_IT == CMP_IT_D
	CMPCR1|=CMP_IT_D;//使能结果值下降沿中断
	#elif ECBM_CMP_IT == CMP_IT_UD
	CMPCR1|=CMP_IT_UD;//使能结果值上升沿、下降沿都触发中断
	#elif ECBM_CMP_IT == CMP_IT_OFF
	CMPCR1|=CMP_IT_OFF;//不开中断，理论上不要这句也行。留着凑数。
	#endif
	CMPCR2&=0xBF;//使能软件滤波器
	CMPCR2|=0x3F;//把数字滤波器的滤波值设置为最大
	#if ECBM_CMP_INIT_ON
	CMP_ON;
	#endif
}
bit cmp_read(){
	if(CMPCR1&0x01)return 1;
	else return 0;	
}
//void cmp_set_it(u8 it){
//	CMPCR1&=0xCF;
//	CMPCR1|=it;
//}

#endif
