#ifndef _ECBM_PWM_H_
#define _ECBM_PWM_H_
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
//<h>STC8A配置
//<h>PWM主配置
//<e.6>PWM是否和ADC关联
//<i>PWM与ADC相关联。允许在PWM周期中的某个时间点触发A/D转换。
//<i>使用TADCPH和TADCPL进行设置。
//<i>使用此功能时，请确认ADC功能已经开启。
#define ECBM_PWM_ETADC 0x00
//<o>触发A/D转换的时间
//<i>由于PWM计数器是15位的，所以输入范围是1~32767。
//<i>当PWM计数器里的值和本设置值相等时，触发A/D转换，所以本设置值也要小于PWM的周期值。否则PWM永远无法触发A/D转换。
//<1-32767>
#define ECBM_PWM_TADCP 32767
//</e>
//<q.6>使能PWM计数器归零中断
//<i>使能之后，在PWM计数器计满到设置值并归零时触发中断。即每个PWM周期触发一次中断。
#define ECBM_PWM_ECBI 0x00
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_CLK 0x00
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_C 2400
//<e.5>PWM异常检测使能
//<i>使能该功能可以在PWM异常时及时做一些处理。
//<q.3>异常检测中断使能
//<i>当发生异常时触发中断。
//<o.4>异常时IO处理
//<0=>IO方面不做任何改变 <1=>IO设置为高阻模式
//<i>只限那些使能PWM输出的IO，例如PWM0没有选择输出PWM波，那么发生异常时P2.0就不会被设置为高阻态。
//<e.1>P3.5电平异常检测使能
//<i>使能该功能，就能用P3.5口取获取异常信息。
//<o.6>异常信号特征
//<i>用于设定异常信号的形态。
//<1=>当P3.5的电平由高变低时，视为异常信号
//<0=>当P3.5的电平由低变高时，视为异常信号
//</e>
//<e.2>比较器输出异常检测使能
//<i>使能该功能，就能用比较器输出来获取异常信息。
//<o.7>异常信号特征
//<i>用于设定异常信号的形态。
//<1=>当比较器的结果由高变低时，视为异常信号
//<0=>当比较器的结果由低变高时，视为异常信号
//</e>
#define ECBM_PWM_FDCR 0xC0
//</e>
//</h>
//<e>PWM0使能和参数调整
#define ECBM_PWM0_EN 0
//<q.2>PWM0中断使能
//<i>想用PWM0中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM0T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM0T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM0输出引脚
//<0=>P2.0 <1=>P1.0 <2=>P6.0 
#define ECBM_PWM0_CR 128
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM0_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM0_T2 21600
//</e>
//<e>PWM1使能和参数调整
#define ECBM_PWM1_EN 0
//<q.2>PWM1中断使能
//<i>想用PWM1中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM1T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM1T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM1输出引脚
//<0=>P2.1 <1=>P1.1 <2=>P6.1 
#define ECBM_PWM1_CR 200
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM1_T1 800
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM1_T2 1400
//</e>
//<e>PWM2使能和参数调整
#define ECBM_PWM2_EN 0
//<q.2>PWM2中断使能
//<i>想用PWM2中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM2T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM2T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM2输出引脚
//<0=>P2.2 <1=>P1.2 <2=>P6.2 
#define ECBM_PWM2_CR 136
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM2_T1 600
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM2_T2 1800
//</e>
//<e>PWM3使能和参数调整
#define ECBM_PWM3_EN 0
//<q.2>PWM3中断使能
//<i>想用PWM3中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM3T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM3T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM3输出引脚
//<0=>P2.3 <1=>P1.3 <2=>P6.3 
#define ECBM_PWM3_CR 0
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM3_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM3_T2 0
//</e>
//<e>PWM4使能和参数调整
#define ECBM_PWM4_EN 0
//<q.2>PWM4中断使能
//<i>想用PWM4中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM4T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM4T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM4输出引脚
//<0=>P2.4 <1=>P1.4 <2=>P6.4 
#define ECBM_PWM4_CR 0
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM4_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM4_T2 0
//</e>
//<e>PWM5使能和参数调整
#define ECBM_PWM5_EN 0

//<q.2>PWM5中断使能
//<i>想用PWM5中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM5T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM5T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM5输出引脚
//<0=>P2.5 <1=>P1.5 <2=>P6.5 
#define ECBM_PWM5_CR 0
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM5_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM5_T2 0
//</e>
//<e>PWM6使能和参数调整
#define ECBM_PWM6_EN 0
//<q.2>PWM6中断使能
//<i>想用PWM6中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM6T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM6T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM6输出引脚
//<0=>P2.6 <1=>P1.6 <2=>P6.6 
#define ECBM_PWM6_CR 0
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM6_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM6_T2 0
//</e>
//<e>PWM7使能和参数调整
#define ECBM_PWM7_EN 0

//<q.2>PWM7中断使能
//<i>想用PWM7中断，可以先使能这个，然后在下面选择中断方式
//<q.0>在第一个翻转点中断
//<i>当PWM计数器和PWM7T1相等时，电平翻转到低电平，触发中断。
//<q.1>在第二个翻转点中断
//<i>当PWM计数器和PWM7T2相等时，电平翻转到高电平，触发中断。
//<q.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>PWM7输出引脚
//<0=>P2.7 <1=>P1.7 <2=>P6.7 
#define ECBM_PWM7_CR 128
//<o>第一个翻转点
//<i>当PWM计数器达到第一个翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM7_T1 0
//<o>第二个翻转点
//<i>当PWM计数器达到第二个翻转点时，将IO翻转到高电平。
//<i>如果第二个翻转点和第一个翻转点一致，那么第二翻转点会被忽略掉。
//<0-32767>
#define ECBM_PWM7_T2 0
//</e>
//</h>
//<h>STC8G配置(中断号超出限制了，所以先不放和中断有关的设置)
//<h>PWM全局配置
//<o.7>全局功能控制
//<0=>6组PWM采用独立设置方式
//<1=>6组PWM采用统一设置方式
#define ECBM_G_PWM_CONFIG 0x03
//</h>
//<e.0>P0口PWM设置
#define ECBM_G_P0_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM0_CKS 0x00
//<e.7>P0.0脚的PWM使能
//<o.6>P0.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM00_CR 0x80
//</e>
//<e.7>P0.1脚的PWM使能
//<o.6>P0.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM01_CR 0x00
//</e>
//<e.7>P0.2脚的PWM使能
//<o.6>P0.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM02_CR 0x80
//</e>
//<e.7>P0.3脚的PWM使能
//<o.6>P0.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM03_CR 0x00
//</e>
//<e.7>P0.4脚的PWM使能
//<o.6>P0.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM04_CR 0x00
//</e>
//<e.7>P0.5脚的PWM使能
//<o.6>P0.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM05_CR 0x00
//</e>
//<e.7>P0.6脚的PWM使能
//<o.6>P0.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM06_CR 0x00
//</e>
//<e.7>P0.7脚的PWM使能
//<o.6>P0.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM07_CR 0x00
//</e>
//</e>


//<e.1>P1口PWM设置
#define ECBM_G_P1_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM1_CKS 0x00
//<e.7>P1.0脚的PWM使能
//<o.6>P1.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM10_CR 0x00
//</e>
//<e.7>P1.1脚的PWM使能
//<o.6>P1.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM11_CR 0x00
//</e>
//<e.7>P1.2脚的PWM使能
//<o.6>P1.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM12_CR 0x00
//</e>
//<e.7>P1.3脚的PWM使能
//<o.6>P1.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM13_CR 0x00
//</e>
//<e.7>P1.4脚的PWM使能
//<o.6>P1.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM14_CR 0x00
//</e>
//<e.7>P1.5脚的PWM使能
//<o.6>P1.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM15_CR 0x00
//</e>
//<e.7>P1.6脚的PWM使能
//<o.6>P1.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM16_CR 0x00
//</e>
//<e.7>P1.7脚的PWM使能
//<o.6>P1.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM17_CR 0x80
//</e>
//</e>

//<e.2>P2口PWM设置
#define ECBM_G_P2_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM2_CKS 0x09
//<e.7>P2.0脚的PWM使能
//<o.6>P2.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM20_CR 0x00
//</e>
//<e.7>P2.1脚的PWM使能
//<o.6>P2.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM21_CR 0x00
//</e>
//<e.7>P2.2脚的PWM使能
//<o.6>P2.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM22_CR 0x00
//</e>
//<e.7>P2.3脚的PWM使能
//<o.6>P2.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM23_CR 0x00
//</e>
//<e.7>P2.4脚的PWM使能
//<o.6>P2.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM24_CR 0x00
//</e>
//<e.7>P2.5脚的PWM使能
//<o.6>P2.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM25_CR 0x00
//</e>
//<e.7>P2.6脚的PWM使能
//<o.6>P2.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM26_CR 0x00
//</e>
//<e.7>P2.7脚的PWM使能
//<o.6>P2.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM27_CR 0x00
//</e>
//</e>


//<e.3>P3口PWM设置
#define ECBM_G_P3_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM3_CKS 0x09
//<e.7>P3.0脚的PWM使能
//<o.6>P3.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM30_CR 0x00
//</e>
//<e.7>P3.1脚的PWM使能
//<o.6>P3.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM31_CR 0x00
//</e>
//<e.7>P3.2脚的PWM使能
//<o.6>P3.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM32_CR 0x00
//</e>
//<e.7>P3.3脚的PWM使能
//<o.6>P3.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM33_CR 0x00
//</e>
//<e.7>P3.4脚的PWM使能
//<o.6>P3.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM34_CR 0x00
//</e>
//<e.7>P3.5脚的PWM使能
//<o.6>P3.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM35_CR 0x00
//</e>
//<e.7>P3.6脚的PWM使能
//<o.6>P3.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM36_CR 0x00
//</e>
//<e.7>P3.7脚的PWM使能
//<o.6>P3.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM37_CR 0x00
//</e>
//</e>


//<e.4>P4口PWM设置
#define ECBM_G_P4_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM4_CKS 0x09
//<e.7>P4.0脚的PWM使能
//<o.6>P4.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM40_CR 0x00
//</e>
//<e.7>P4.1脚的PWM使能
//<o.6>P4.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM41_CR 0x00
//</e>
//<e.7>P4.2脚的PWM使能
//<o.6>P4.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM42_CR 0x00
//</e>
//<e.7>P4.3脚的PWM使能
//<o.6>P4.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM43_CR 0x00
//</e>
//<e.7>P4.4脚的PWM使能
//<o.6>P4.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM44_CR 0x00
//</e>
//<e.7>P4.5脚的PWM使能
//<o.6>P4.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM45_CR 0x00
//</e>
//<e.7>P4.6脚的PWM使能
//<o.6>P4.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM46_CR 0x00
//</e>
//<e.7>P4.7脚的PWM使能
//<o.6>P4.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM47_CR 0x00
//</e>
//</e>

//<e.5>P5口PWM设置
#define ECBM_G_P5_EN 0x00
//<o.0..4>时钟选择
//< 0=>SYSclk/01 < 1=>SYSclk/02 < 2=>SYSclk/03 < 3=>SYSclk/04 < 4=>SYSclk/05 
//< 5=>SYSclk/06 < 6=>SYSclk/07 < 7=>SYSclk/08 < 8=>SYSclk/09 < 9=>SYSclk/10
//<10=>SYSclk/11 <11=>SYSclk/12 <12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 
//<15=>SYSclk/16 <16=>定时器2的溢出脉冲
#define ECBM_PWM5_CKS 0x00
//<e.7>P5.0脚的PWM使能
//<o.6>P5.0脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM50_CR 0x80
//</e>
//<e.7>P5.1脚的PWM使能
//<o.6>P5.1脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM51_CR 0x80
//</e>
//<e.7>P5.2脚的PWM使能
//<o.6>P5.2脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM52_CR 0x80
//</e>
//<e.7>P5.3脚的PWM使能
//<o.6>P5.3脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM53_CR 0x80
//</e>
//<e.7>P5.4脚的PWM使能
//<o.6>P5.4脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM54_CR 0x00
//</e>
//<e.7>P5.5脚的PWM使能
//<o.6>P5.5脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM55_CR 0x00
//</e>
//<e.7>P5.6脚的PWM使能
//<o.6>P5.6脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM56_CR 0x00
//</e>
//<e.7>P5.7脚的PWM使能
//<o.6>P5.7脚的初始电平
//<0=>低电平
//<1=>高电平
#define ECBM_PWM57_CR 0x00
//</e>
//</e>

//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"
/*---------------------------------------宏定义------------------------------------*/
#if   ECBM_MCU_MAIN_RAM == 1 //STC8A8K
	#define PWM_ON      do{PWMCR|=0x80;}while(0)//打开PWM。
	#define PWM_OFF     do{PWMCR&=0x7F;}while(0)//关闭PWM。
	#define PWM_CH0_ON  do{PWM0CR|=0x80;}while(0)//打开PWM的通道0。
	#define PWM_CH0_OFF do{PWM0CR&=0x7F;}while(0)//关闭PWM的通道0。
	#define PWM_CH0_1   do{PWM0HLD=0x02;}while(0)//PWM的通道0强制输出高电平。
	#define PWM_CH0_0   do{PWM0HLD=0x01;}while(0)//PWM的通道0强制输出低电平。
	#define PWM_CH0_OUT do{PWM0HLD=0x00;}while(0)//PWM的通道0恢复输出PWM波状态。

	#define PWM_CH1_ON  do{PWM1CR|=0x80;}while(0)//打开PWM的通道1。
	#define PWM_CH1_OFF do{PWM1CR&=0x7F;}while(0)//关闭PWM的通道1。
	#define PWM_CH1_1   do{PWM1HLD=0x02;}while(0)//PWM的通道1强制输出高电平。
	#define PWM_CH1_0   do{PWM1HLD=0x01;}while(0)//PWM的通道1强制输出低电平。
	#define PWM_CH1_OUT do{PWM1HLD=0x00;}while(0)//PWM的通道1恢复输出PWM波状态。

	#define PWM_CH2_ON  do{PWM2CR|=0x80;}while(0)//打开PWM的通道2。
	#define PWM_CH2_OFF do{PWM2CR&=0x7F;}while(0)//关闭PWM的通道2。
	#define PWM_CH2_1   do{PWM2HLD=0x02;}while(0)//PWM的通道2强制输出高电平。
	#define PWM_CH2_0   do{PWM2HLD=0x01;}while(0)//PWM的通道2强制输出低电平。
	#define PWM_CH2_OUT do{PWM2HLD=0x00;}while(0)//PWM的通道2恢复输出PWM波状态。

	#define PWM_CH3_ON  do{PWM3CR|=0x80;}while(0)//打开PWM的通道3。
	#define PWM_CH3_OFF do{PWM3CR&=0x7F;}while(0)//关闭PWM的通道3。
	#define PWM_CH3_1   do{PWM3HLD=0x02;}while(0)//PWM的通道3强制输出高电平。
	#define PWM_CH3_0   do{PWM3HLD=0x01;}while(0)//PWM的通道3强制输出低电平。
	#define PWM_CH3_OUT do{PWM3HLD=0x00;}while(0)//PWM的通道3恢复输出PWM波状态。

	#define PWM_CH4_ON  do{PWM4CR|=0x80;}while(0)//打开PWM的通道4。
	#define PWM_CH4_OFF do{PWM4CR&=0x7F;}while(0)//关闭PWM的通道4。
	#define PWM_CH4_1   do{PWM4HLD=0x02;}while(0)//PWM的通道4强制输出高电平。
	#define PWM_CH4_0   do{PWM4HLD=0x01;}while(0)//PWM的通道4强制输出低电平。
	#define PWM_CH4_OUT do{PWM4HLD=0x00;}while(0)//PWM的通道4恢复输出PWM波状态。

	#define PWM_CH5_ON  do{PWM5CR|=0x80;}while(0)//打开PWM的通道5。
	#define PWM_CH5_OFF do{PWM5CR&=0x7F;}while(0)//关闭PWM的通道5。
	#define PWM_CH5_1   do{PWM5HLD=0x02;}while(0)//PWM的通道5强制输出高电平。
	#define PWM_CH5_0   do{PWM5HLD=0x01;}while(0)//PWM的通道5强制输出低电平。
	#define PWM_CH5_OUT do{PWM5HLD=0x00;}while(0)//PWM的通道5恢复输出PWM波状态。

	#define PWM_CH6_ON  do{PWM6CR|=0x80;}while(0)//打开PWM的通道6。
	#define PWM_CH6_OFF do{PWM6CR&=0x7F;}while(0)//关闭PWM的通道6。
	#define PWM_CH6_1   do{PWM6HLD=0x02;}while(0)//PWM的通道6强制输出高电平。
	#define PWM_CH6_0   do{PWM6HLD=0x01;}while(0)//PWM的通道6强制输出低电平。
	#define PWM_CH6_OUT do{PWM6HLD=0x00;}while(0)//PWM的通道6恢复输出PWM波状态。

	#define PWM_CH7_ON  do{PWM7CR|=0x80;}while(0)//打开PWM的通道7。
	#define PWM_CH7_OFF do{PWM7CR&=0x7F;}while(0)//关闭PWM的通道7。
	#define PWM_CH7_1   do{PWM7HLD=0x02;}while(0)//PWM的通道7强制输出高电平。
	#define PWM_CH7_0   do{PWM7HLD=0x01;}while(0)//PWM的通道7强制输出低电平。
	#define PWM_CH7_OUT do{PWM7HLD=0x00;}while(0)//PWM的通道7恢复输出PWM波状态。
#elif   ECBM_MCU_MAIN_RAM == 2 //STC8G2K
	#define PWM_G_RST     do{PWMSET|=0x04;PWMSET=0x00;}while(0)
	#define	PWM_GPIO0_ON  do{PWMCFG01|=0x01;}while(0)
	#define	PWM_GPIO0_OFF do{PWMCFG01&=0xFE;}while(0)
	
	#define	PWM_GPIO1_ON  do{PWMCFG01|=0x10;}while(0)
	#define	PWM_GPIO1_OFF do{PWMCFG01&=0xEF;}while(0)
	
	#define	PWM_GPIO2_ON  do{PWMCFG23|=0x01;}while(0)
	#define	PWM_GPIO2_OFF do{PWMCFG23&=0xFE;}while(0)
	
	#define	PWM_GPIO3_ON  do{PWMCFG23|=0x10;}while(0)
	#define	PWM_GPIO3_OFF do{PWMCFG23&=0xEF;}while(0)
	
	#define	PWM_GPIO4_ON  do{PWMCFG45|=0x01;}while(0)
	#define	PWM_GPIO4_OFF do{PWMCFG45&=0xFE;}while(0)
	
	#define	PWM_GPIO5_ON  do{PWMCFG45|=0x10;}while(0)
	#define	PWM_GPIO5_OFF do{PWMCFG45&=0xEF;}while(0)
#endif
/*--------------------------------------程序定义-----------------------------------*/
#if   ECBM_MCU_MAIN_RAM == 1 //STC8A8K
/*-------------------------------------------------------
函数名：pwm_init
描  述：PWM初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_init(void);
/*-------------------------------------------------------
函数名：pwm_set_freq
描  述：PWM设置频率函数。
输  入：PWM的输出频率。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_freq(u32 freq);
/*-------------------------------------------------------
函数名：pwm_set_cycle
描  述：PWM设置周期函数。
输  入：PWM的输出周期。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_cycle(u32 cycle);
/*-------------------------------------------------------
函数名：pwm_set_duty
描  述：PWM设置占空比函数，一般和pwm_set_freq函数配套使用。
输  入：id   -  要输出的PWM通道号。
		duty -  该通道的占空比，单位是千分之几，比如要设置15.6%，就写156。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_duty(u8 id,u16 duty);
/*-------------------------------------------------------
函数名：pwm_set_us
描  述：PWM设置高电平持续时间函数，一般和pwm_set_cycle函数配套使用。
输  入：id  -  要输出的PWM通道号。
		us  -  该通道的高电平持续时间。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_us(u8 id,u32 us);
#elif    ECBM_MCU_MAIN_RAM == 2 //STC8G2K
/*-------------------------------------------------------
函数名：pwm_init
描  述：PWM初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
2020-05-23：修复了STC8G只能使用一部分IO输出PWM的问题。
-------------------------------------------------------*/
void pwm_init(void);
/*-------------------------------------------------------
函数名：pwm_set_freq
描  述：PWM设置频率函数。
输  入：PWM的输出频率。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_freq(u8 gpio,u32 freq);
/*-------------------------------------------------------
函数名：pwm_set_duty
描  述：PWM设置占空比函数，一般和pwm_set_freq函数配套使用。
输  入：pin   -  要输出PWM的引脚。
		duty -  该通道的占空比，单位是千分之几，比如要设置15.6%，就写156。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-01-08
修改记录：
-------------------------------------------------------*/
void pwm_set_duty(u8 pin,u16 duty);
#endif
#endif
