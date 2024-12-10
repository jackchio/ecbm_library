#ifndef _ECBM_REG_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_REG_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<o>STC8系列型号选择
//<i>列表提供的芯片类型都是在数据手册中出现的，仅根据理论进行设置，若有兼容性问题请入群告知我。
//<i>ROM容量留空，在下一个选项中选择。
//<0x110301=>STC8F1Kxx_8PIN
//<0x110302=>STC8F1KxxS2_16PIN_20PIN
//<0x120502=>STC8F2KxxS2_ALL
//<0x120504=>STC8F2KxxS4_ALL
//<0x2405C2=>STC8A4KxxS2A12_ALL
//<0x2805C4=>STC8A8KxxS4A12_ALL
//<0x2815C4=>STC8A8KxxD4_ALL
//<0x310201=>STC8G1Kxx_8PIN
//<0x3102A1=>STC8G1KxxA_8PIN
//<0x3103A2=>STC8G1Kxx_16PIN_20PIN
//<0x3103A1=>STC8G1KxxT_20PIN
//<0x3205A2=>STC8G2KxxS2_ALL
//<0x3205A4=>STC8G2KxxS4_ALL
//<0x4103A2=>STC8H1Kxx_20PIN
//<0x4105A2=>STC8H1Kxx_32PIN
//<0x4305C2=>STC8H3KxxS2_ALL
//<0x4305C4=>STC8H3KxxS4_ALL
//<0x4805C4=>STC8H8KxxU_ALL
//<0x520502=>STC8C2K64S2_ALL
//<0x520504=>STC8C2K64S4_ALL
#define ECBM_MCU (0x4805C4)
//<o>ROM选择
//<i>选择单片机的flash容量大小，主要影响唯一ID的读取。
//<8=>08 
//<12=>12 
//<16=>16 
//<17=>17 
//<28=>28 
//<32=>32 
//<60=>60 
//<64=>64
#define ECBM_MCU_ROM_SIZE (64)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-----------------------------------变量类型重映射---------------------------------*/
#define __IO     volatile  //防止优化的声明，目的是让编译器每次使用的时候都得去内存拿值。
typedef unsigned char u8;  //无符号的 8位变量，在C51里就是无符号字符型变量。
typedef unsigned int  u16; //无符号的16位变量，在C51里就是无符号  整型变量。
typedef unsigned long u32; //无符号的32位变量，在C51里就是无符号长整型变量。
typedef   signed char s8;  //有符号的 8位变量，在C51里就是有符号字符型变量。
typedef   signed int  s16; //有符号的16位变量，在C51里就是有符号  整型变量。
typedef   signed long s32; //有符号的32位变量，在C51里就是有符号长整型变量。
/*------------------------------------常用功能设定----------------------------------*/
#define REG_IN_MASK(reg,mask,value) do{reg=((reg&(~mask))|((u8)(value)&mask));}while(0)//以掩码的形式向在指定寄存器存入一个值。
#define REG_SET_BIT(reg,bit_mask)   do{reg|= (bit_mask);}while(0)//向指定寄存器置某些位为1。
#define REG_RESET_BIT(reg,bit_mask) do{reg&=~(bit_mask);}while(0)//向指定寄存器置某些位为0。
#define read_idata_u8(x)    (*((u8  volatile idata *)x))//从idata区读取一个u8 变量。
#define read_idata_u16(x)   (*((u16 volatile idata *)x))//从idata区读取一个u16变量。
#define read_idata_u32(x)   (*((u32 volatile idata *)x))//从idata区读取一个u32变量。
#define read_xdata_u8(x)    (*((u8  volatile xdata *)x))//从xdata区读取一个u8 变量。
#define read_xdata_u16(x)   (*((u16 volatile xdata *)x))//从xdata区读取一个u16变量。
#define read_xdata_u32(x)   (*((u32 volatile xdata *)x))//从xdata区读取一个u32变量。
#define read_idata_s8(x)    (*((s8  volatile idata *)x))//从idata区读取一个s8 变量。
#define read_idata_s16(x)   (*((s16 volatile idata *)x))//从idata区读取一个s16变量。
#define read_idata_s32(x)   (*((s32 volatile idata *)x))//从idata区读取一个s32变量。
#define read_xdata_s8(x)    (*((s8  volatile xdata *)x))//从xdata区读取一个s8 变量。
#define read_xdata_s16(x)   (*((s16 volatile xdata *)x))//从xdata区读取一个s16变量。
#define read_xdata_s32(x)   (*((s32 volatile xdata *)x))//从xdata区读取一个s32变量。
/*##################################特殊参数地址解析################################*/
#if     (ECBM_MCU_ROM_SIZE==8)
#   define MCUID    (  (u8  code *)(0x1FF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0x1FF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==12)
#   define MCUID    (  (u8  code *)(0x2FF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0x2FF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==16)
#   define MCUID    (  (u8  code *)(0x3FF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0x3FF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==17)
#   define MCUID    (  (u8  code *)(0x43F9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0x43F7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==28)
#   define  MCUID   (  (u8  code *)(0x6FF9))  //单片机的唯一ID码。
#   define  BGV     (*((u16 code *)(0x6FF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==32)
#   define MCUID    (  (u8  code *)(0x7FF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0x7FF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==60)
#   define MCUID    (  (u8  code *)(0xEFF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0xEFF7))) //片内间隙电压的实测值。
#elif   (ECBM_MCU_ROM_SIZE==64)
#   define MCUID    (  (u8  code *)(0xFDF9))  //单片机的唯一ID码。
#   define BGV      (*((u16 code *)(0xFDF7))) //片内间隙电压的实测值。
#endif
#if 1//以下是SFR区寄存器定义。通过这个宏定义快速折叠。
/*------------------------------------80H~87H------------------------------------*/
sfr P0          =0x80;//P0端口
sfr SP          =0x81;//堆栈指针
sfr DPL         =0x82;//数据指针（低字节）
sfr DPH         =0x83;//数据指针（高字节）
sfr S4CON       =0x84;//串口4控制寄存器
sfr S4BUF       =0x85;//串口4数据寄存器

sfr PCON        =0x87;//电源控制寄存器
/*------------------------------------88H~8FH------------------------------------*/
sfr TCON        =0x88;//定时器控制寄存器
sfr TMOD        =0x89;//定时器0/1模式寄存器
sfr TL0         =0x8A;//定时器0计数寄存器（低8位）
sfr TL1         =0x8B;//定时器1计数寄存器（低8位）
sfr TH0         =0x8C;//定时器0计数寄存器（高8位）
sfr TH1         =0x8D;//定时器1计数寄存器（高8位）
sfr AUXR        =0x8E;//辅助寄存器1
sfr INTCLKO     =0x8F;//外部中断与时钟输出控制寄存器
/*------------------------------------90H~97H------------------------------------*/
sfr P1          =0x90;//P1端口
sfr P1M1        =0x91;//P1口配置寄存器1
sfr P1M0        =0x92;//P1口配置寄存器0
sfr P0M1        =0x93;//P0口配置寄存器1
sfr P0M0        =0x94;//P0口配置寄存器0
sfr P2M1        =0x95;//P2口配置寄存器1
sfr P2M0        =0x96;//P2口配置寄存器0

/*------------------------------------98H~9FH------------------------------------*/
sfr SCON        =0x98;//串口1控制寄存器
sfr SBUF        =0x99;//串口1数据寄存器
sfr S2CON       =0x9A;//串口2控制寄存器
sfr S2BUF       =0x9B;//串口2数据寄存器

sfr IRCBAND     =0x9D;//IRC频段选择寄存器
sfr LIRTRIM     =0x9E;//内部高精度IRC频率微调寄存器
sfr IRTRIM      =0x9F;//内部高精度IRC频率调整寄存器
/*------------------------------------A0H~A7H------------------------------------*/
sfr P2          =0xA0;//P2端口
sfr BUS_SPEED   =0xA1;//总线速度控制寄存器
sfr P_SW1       =0xA2;//外设端口切换寄存器1





/*------------------------------------A8H~AFH------------------------------------*/
sfr IE          =0xA8;//中断允许寄存器
sfr SADDR       =0xA9;//串口1从机地址寄存器
sfr WKTCL       =0xAA;//掉电唤醒定时器（低8位）
sfr WKTCH       =0xAB;//掉电唤醒定时器（高8位）
sfr16   WKTC    =0xAA;//掉电唤醒定时器（16位）
sfr S3CON       =0xAC;//串口3控制寄存器
sfr S3BUF       =0xAD;//串口3数据寄存器
sfr TA          =0xAE;//DPTR时序控制寄存器
sfr IE2         =0xAF;//中断允许寄存器2
/*------------------------------------B0H~B7H------------------------------------*/
sfr P3          =0xB0;//P3端口
sfr P3M1        =0xB1;//P3口配置寄存器1
sfr P3M0        =0xB2;//P3口配置寄存器0
sfr P4M1        =0xB3;//P4口配置寄存器1
sfr P4M0        =0xB4;//P4口配置寄存器0
sfr IP2         =0xB5;//中断优先级控制寄存器2
sfr IP2H        =0xB6;//高中断优先级控制寄存器2
sfr IPH         =0xB7;//高中断优先级控制寄存器
/*------------------------------------B8H~BFH------------------------------------*/
sfr IP          =0xB8;//中断优先级控制寄存器
sfr SADEN       =0xB9;//串口1从机地址屏蔽寄存器
sfr P_SW2       =0xBA;//外设端口切换寄存器2
sfr VOCTRL      =0xBB;//电压控制寄存器
sfr ADC_CONTR   =0xBC;//ADC控制寄存器
sfr ADC_RES     =0xBD;//ADC转换结果寄存器（高）
sfr ADC_RESL    =0xBE;//ADC转换结果寄存器（低）

/*------------------------------------C0H~C7H------------------------------------*/
sfr P4          =0xC0;//P4端口
sfr WDT_CONTR   =0xC1;//看门狗控制寄存器
sfr IAP_DATA    =0xC2;//IAP数据寄存器
sfr IAP_ADDRH   =0xC3;//IAP高地址寄存器
sfr IAP_ADDRL   =0xC4;//IAP低地址寄存器
sfr IAP_CMD     =0xC5;//IAP命令寄存器
sfr IAP_TRIG    =0xC6;//IAP触发寄存器
sfr IAP_CONTR   =0xC7;//IAP控制寄存器
/*------------------------------------C8H~CFH------------------------------------*/
sfr P5          =0xC8;//P5端口
sfr P5M1        =0xC9;//P5口配置寄存器1
sfr P5M0        =0xCA;//P5口配置寄存器0
sfr P6M1        =0xCB;//P6口配置寄存器1
sfr P6M0        =0xCC;//P6口配置寄存器0
sfr SPSTAT      =0xCD;//SPI状态寄存器
sfr SPCTL       =0xCE;//SPI控制寄存器
sfr SPDAT       =0xCF;//SPI数据寄存器
/*------------------------------------D0H~D7H------------------------------------*/
sfr PSW         =0xD0;//程序状态字寄存器
sfr T4T3M       =0xD1;//定时器4/3控制寄存器
sfr T4H         =0xD2;//定时器4计数寄存器（高8位）
sfr T4L         =0xD3;//定时器4计数寄存器（低8位）
sfr T3H         =0xD4;//定时器3计数寄存器（高8位）
sfr T3L         =0xD5;//定时器3计数寄存器（低8位）
sfr T2H         =0xD6;//定时器2计数寄存器（高8位）
sfr T2L         =0xD7;//定时器2计数寄存器（低8位）
/*------------------------------------D8H~DFH------------------------------------*/
sfr CCON        =0xD8;//PCA控制寄存器
sfr CMOD        =0xD9;//PCA模式寄存器
sfr CCAPM0      =0xDA;//PCA模块0模式控制寄存器
sfr CCAPM1      =0xDB;//PCA模块1模式控制寄存器
#if (ECBM_MCU==0x4805C4)//STC8带U的版本比较特殊
sfr USBCLK      =0xDC;//USB时钟控制寄存器
#else
sfr CCAPM2      =0xDC;//PCA模块2模式控制寄存器
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
#define CCAPM3  read_xdata_u8(0xFD54)//PCA模块3模式控制寄存器
#else
sfr CCAPM3      =0xDD;//PCA模块3模式控制寄存器
#endif
sfr ADC_CFG     =0xDE;//ADC配置寄存器
sfr IP3         =0xDF;//中断优先级控制寄存器3
/*------------------------------------E0H~E7H------------------------------------*/
sfr ACC         =0xE0;//累加器
sfr P7M1        =0xE1;//P7口配置寄存器1
sfr P7M0        =0xE2;//P7口配置寄存器0
sfr DPS         =0xE3;//DPTR指针选择器
sfr DPL1        =0xE4;//第二组数据指针（低字节）
sfr DPH1        =0xE5;//第二组数据指针（高字节）
sfr CMPCR1      =0xE6;//比较器控制寄存器1
sfr CMPCR2      =0xE7;//比较器控制寄存器2
/*------------------------------------E8H~EFH------------------------------------*/
sfr P6          =0xE8;//P6端口
sfr CL          =0xE9;//PCA计数器低8位
sfr CCAP0L      =0xEA;//PCA模块0低8位
sfr CCAP1L      =0xEB;//PCA模块1低8位
#if (ECBM_MCU==0x4805C4)//STC8带U的版本比较特殊
sfr USBDAT      =0xEC;//USB数据寄存器
#else
sfr CCAP2L      =0xEC;//PCA模块2低8位
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
#define CCAP3L  read_xdata_u8(0xFD55)//PCA模块3低8位
#else
sfr CCAP3L      =0xED;//PCA模块3低8位
#endif
sfr IP3H        =0xEE;//高中断优先级控制寄存器3
sfr AUXINTIF    =0xEF;//扩展中断标志位寄存器
/*------------------------------------F0H~F7H------------------------------------*/
sfr B           =0xF0;//B寄存器
#if (ECBM_MCU==0x3205A4)||(ECBM_MCU==0x2815C4)
sfr PWMSET      =0xF1;//增强型PWM全局配置寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCFG      =0xF1;//增强型PWM配置寄存器
#endif
sfr PCA_PWM0    =0xF2;//PCA0的PWM模式寄存器
sfr PCA_PWM1    =0xF3;//PCA1的PWM模式寄存器
#if (ECBM_MCU==0x4805C4)//STC8带U的版本比较特殊
sfr USBCON      =0xF4;//USB控制寄存器
#else
sfr PCA_PWM2    =0xF4;//PCA2的PWM模式寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PCA_PWM3    =0xF5;//PCA3的PWM模式寄存器
#else
sfr IAP_TPS     =0xF5;//EEPROM擦除等待时间控制寄存器
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
#define PCA_PWM3    read_xdata_u8(0xFD57)//PCA3的PWM模式寄存器
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
sfr PWMCFG      =0xF6;//增强型PWM配置寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMIF       =0xF6;//增强型PWM中断标志寄存器
sfr PWMFDCR     =0xF7;//异常检测控制器
#endif
#if (ECBM_MCU==0x3205A2)||(ECBM_MCU==0x3205A4)
sfr PWMCFG01    =0xF6;//增强型PWM配置寄存器
sfr PWMCFG23    =0xF7;//增强型PWM配置寄存器
#endif
/*------------------------------------F8H~FFH------------------------------------*/
sfr P7          =0xF8;//P7端口
sfr CH          =0xF9;//PCA计数器高8位
sfr CCAP0H      =0xFA;//PCA模块0高8位
sfr CCAP1H      =0xFB;//PCA模块1高8位
#if (ECBM_MCU==0x4805C4)//STC8带U的版本比较特殊
sfr USBADR      =0xFC;//USB地址寄存器
#else
sfr CCAP2H      =0xFC;//PCA模块2高8位
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
#define CCAP3H  read_xdata_u8(0xFD56)//PCA模块3高8位
#else
sfr CCAP3H      =0xFD;//PCA模块3高8位
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCR       =0xFE;//PWM控制寄存器
#endif
#if (ECBM_MCU==0x3205A4)
sfr PWMCFG45    =0xFE;//增强型PWM配置寄存器
#endif
sfr RSTCFG      =0xFF;//复位配置寄存器
/*-------------------------------------------------------------------------------*/
#endif
#if 1//以下是XDATA区寄存器定义。通过这个宏定义快速折叠。
/*----------------------------------FA00H~FA0FH----------------------------------*/
#define DMA_M2M_CFG                 read_xdata_u8(0xFA00)//MEM_MEM配置寄存器
#define DMA_M2M_CR                  read_xdata_u8(0xFA01)//MEM_MEM控制寄存器
#define DMA_M2M_STA                 read_xdata_u8(0xFA02)//MEM_MEM状态寄存器
#define DMA_M2M_AMT                 read_xdata_u8(0xFA03)//MEM_MEM传输总字节寄存器
#define DMA_M2M_DONE                read_xdata_u8(0xFA04)//MEM_MEM传输完成字节寄存器
#define DMA_M2M_TXA                 read_xdata_u16(0xFA05)//MEM_MEM发送地址寄存器（16位）
#define DMA_M2M_TXAH                read_xdata_u8(0xFA05)//MEM_MEM发送地址寄存器（高8位）
#define DMA_M2M_TXAL                read_xdata_u8(0xFA06)//MEM_MEM发送地址寄存器（低8位）
#define DMA_M2M_RXA                 read_xdata_u16(0xFA07)//MEM_MEM接收地址寄存器（16位）
#define DMA_M2M_RXAH                read_xdata_u8(0xFA07)//MEM_MEM接收地址寄存器（高8位）
#define DMA_M2M_RXAL                read_xdata_u8(0xFA08)//MEM_MEM接收地址寄存器（低8位）
/*----------------------------------FA10H~FA1FH----------------------------------*/
#define DMA_ADC_CFG                 read_xdata_u8(0xFA10)//ADC_MEM配置寄存器
#define DMA_ADC_CR                  read_xdata_u8(0xFA11)//ADC_MEM控制寄存器
#define DMA_ADC_STA                 read_xdata_u8(0xFA12)//ADC_MEM状态寄存器
#define DMA_ADC_RXA                 read_xdata_u16(0xFA17)//ADC_MEM接收地址寄存器（16位）
#define DMA_ADC_RXAH                read_xdata_u8(0xFA17)//ADC_MEM接收地址寄存器（高8位）
#define DMA_ADC_RXAL                read_xdata_u8(0xFA18)//ADC_MEM接收地址寄存器（低8位）
#define DMA_ADC_CFG2                read_xdata_u8(0xFA19)//ADC_MEM配置寄存器2
#define DMA_ADC_CHSW0               read_xdata_u8(0xFA1A)//ADC_MEM通道使能寄存器0
#define DMA_ADC_CHSW1               read_xdata_u8(0xFA1B)//ADC_MEM通道使能寄存器1
/*----------------------------------FA20H~FA2FH----------------------------------*/
#define DMA_SPI_CFG                 read_xdata_u8(0xFA20)//SPI_MEM配置寄存器
#define DMA_SPI_CR                  read_xdata_u8(0xFA21)//SPI_MEM控制寄存器
#define DMA_SPI_STA                 read_xdata_u8(0xFA22)//SPI_MEM状态寄存器
#define DMA_SPI_AMT                 read_xdata_u8(0xFA23)//SPI_MEM传输总字节寄存器
#define DMA_SPI_DONE                read_xdata_u8(0xFA24)//SPI_MEM传输完成字节寄存器
#define DMA_SPI_TXA                 read_xdata_u16(0xFA25)//SPI_MEM发送地址寄存器（16位）
#define DMA_SPI_TXAH                read_xdata_u8(0xFA25)//SPI_MEM发送地址寄存器（高8位）
#define DMA_SPI_TXAL                read_xdata_u8(0xFA26)//SPI_MEM发送地址寄存器（低8位）
#define DMA_SPI_RXA                 read_xdata_u16(0xFA27)//SPI_MEM接收地址寄存器（16位）
#define DMA_SPI_RXAH                read_xdata_u8(0xFA27)//SPI_MEM接收地址寄存器（高8位）
#define DMA_SPI_RXAL                read_xdata_u8(0xFA28)//SPI_MEM接收地址寄存器（低8位）
#define DMA_SPI_CFG2                read_xdata_u8(0xFA29)//SPI_MEM配置寄存器2
/*----------------------------------FA30H~FA3FH----------------------------------*/
#define DMA_UR1T_CFG                read_xdata_u8(0xFA30)//UART12MEM发送配置寄存器
#define DMA_UR1T_CR                 read_xdata_u8(0xFA31)//UART12MEM发送控制寄存器
#define DMA_UR1T_STA                read_xdata_u8(0xFA32)//UART12MEM发送状态寄存器
#define DMA_UR1T_AMT                read_xdata_u8(0xFA33)//UART12MEM发送总字节寄存器
#define DMA_UR1T_DONE               read_xdata_u8(0xFA34)//UART12MEM发送完成字节寄存器
#define DMA_UR1T_TXA                read_xdata_u16(0xFA35)//UART12MEM发送地址寄存器（16位）
#define DMA_UR1T_TXAH               read_xdata_u8(0xFA35)//UART12MEM发送地址寄存器（高8位）
#define DMA_UR1T_TXAL               read_xdata_u8(0xFA36)//UART12MEM发送地址寄存器（低8位）
#define DMA_UR1R_CFG                read_xdata_u8(0xFA38)//UART12MEM接收配置寄存器
#define DMA_UR1R_CR                 read_xdata_u8(0xFA39)//UART12MEM接收控制寄存器
#define DMA_UR1R_STA                read_xdata_u8(0xFA3A)//UART12MEM接收状态寄存器
#define DMA_UR1R_AMT                read_xdata_u8(0xFA3B)//UART12MEM接收总字节寄存器
#define DMA_UR1R_DONE               read_xdata_u8(0xFA3C)//UART12MEM接收完成字节寄存器
#define DMA_UR1R_RXA                read_xdata_u16(0xFA3D)//UART12MEM接收发送地址寄存器（16位）
#define DMA_UR1R_RXAH               read_xdata_u8(0xFA3D)//UART12MEM接收地址寄存器（高8位）
#define DMA_UR1R_RXAL               read_xdata_u8(0xFA3E)//UART12MEM接收地址寄存器（低8位）
/*----------------------------------FA40H~FA4FH----------------------------------*/
#define DMA_UR2T_CFG                read_xdata_u8(0xFA40)//UART22MEM发送配置寄存器
#define DMA_UR2T_CR                 read_xdata_u8(0xFA41)//UART22MEM发送控制寄存器
#define DMA_UR2T_STA                read_xdata_u8(0xFA42)//UART22MEM发送状态寄存器
#define DMA_UR2T_AMT                read_xdata_u8(0xFA43)//UART22MEM发送总字节寄存器
#define DMA_UR2T_DONE               read_xdata_u8(0xFA44)//UART22MEM发送完成字节寄存器
#define DMA_UR2T_TXA                read_xdata_u16(0xFA45)//UART22MEM发送地址寄存器（16位）
#define DMA_UR2T_TXAH               read_xdata_u8(0xFA45)//UART22MEM发送地址寄存器（高8位）
#define DMA_UR2T_TXAL               read_xdata_u8(0xFA46)//UART22MEM发送地址寄存器（低8位）
#define DMA_UR2R_CFG                read_xdata_u8(0xFA48)//UART22MEM接收配置寄存器
#define DMA_UR2R_CR                 read_xdata_u8(0xFA49)//UART22MEM接收控制寄存器
#define DMA_UR2R_STA                read_xdata_u8(0xFA4A)//UART22MEM接收状态寄存器
#define DMA_UR2R_AMT                read_xdata_u8(0xFA4B)//UART22MEM接收总字节寄存器
#define DMA_UR2R_DONE               read_xdata_u8(0xFA4C)//UART22MEM接收完成字节寄存器
#define DMA_UR2R_RXA                read_xdata_u16(0xFA4D)//UART22MEM接收发送地址寄存器（16位）
#define DMA_UR2R_RXAH               read_xdata_u8(0xFA4D)//UART22MEM接收地址寄存器（高8位）
#define DMA_UR2R_RXAL               read_xdata_u8(0xFA4E)//UART22MEM接收地址寄存器（低8位）
/*----------------------------------FA50H~FA5FH----------------------------------*/
#define DMA_UR3T_CFG                read_xdata_u8(0xFA50)//UART32MEM发送配置寄存器
#define DMA_UR3T_CR                 read_xdata_u8(0xFA51)//UART32MEM发送控制寄存器
#define DMA_UR3T_STA                read_xdata_u8(0xFA52)//UART32MEM发送状态寄存器
#define DMA_UR3T_AMT                read_xdata_u8(0xFA53)//UART32MEM发送总字节寄存器
#define DMA_UR3T_DONE               read_xdata_u8(0xFA54)//UART32MEM发送完成字节寄存器
#define DMA_UR3T_TXA                read_xdata_u16(0xFA55)//UART32MEM发送地址寄存器（16位）
#define DMA_UR3T_TXAH               read_xdata_u8(0xFA55)//UART32MEM发送地址寄存器（高8位）
#define DMA_UR3T_TXAL               read_xdata_u8(0xFA56)//UART32MEM发送地址寄存器（低8位）
#define DMA_UR3R_CFG                read_xdata_u8(0xFA58)//UART32MEM接收配置寄存器
#define DMA_UR3R_CR                 read_xdata_u8(0xFA59)//UART32MEM接收控制寄存器
#define DMA_UR3R_STA                read_xdata_u8(0xFA5A)//UART32MEM接收状态寄存器
#define DMA_UR3R_AMT                read_xdata_u8(0xFA5B)//UART32MEM接收总字节寄存器
#define DMA_UR3R_DONE               read_xdata_u8(0xFA5C)//UART32MEM接收完成字节寄存器
#define DMA_UR3R_RXA                read_xdata_u16(0xFA5D)//UART32MEM接收发送地址寄存器（16位）
#define DMA_UR3R_RXAH               read_xdata_u8(0xFA5D)//UART32MEM接收地址寄存器（高8位）
#define DMA_UR3R_RXAL               read_xdata_u8(0xFA5E)//UART32MEM接收地址寄存器（低8位）
/*----------------------------------FA60H~FA6FH----------------------------------*/
#define DMA_UR4T_CFG                read_xdata_u8(0xFA60)//UART42MEM发送配置寄存器
#define DMA_UR4T_CR                 read_xdata_u8(0xFA61)//UART42MEM发送控制寄存器
#define DMA_UR4T_STA                read_xdata_u8(0xFA62)//UART42MEM发送状态寄存器
#define DMA_UR4T_AMT                read_xdata_u8(0xFA63)//UART42MEM发送总字节寄存器
#define DMA_UR4T_DONE               read_xdata_u8(0xFA64)//UART42MEM发送完成字节寄存器
#define DMA_UR4T_TXA                read_xdata_u16(0xFA65)//UART42MEM发送地址寄存器（16位）
#define DMA_UR4T_TXAH               read_xdata_u8(0xFA65)//UART42MEM发送地址寄存器（高8位）
#define DMA_UR4T_TXAL               read_xdata_u8(0xFA66)//UART42MEM发送地址寄存器（低8位）
#define DMA_UR4R_CFG                read_xdata_u8(0xFA68)//UART42MEM接收配置寄存器
#define DMA_UR4R_CR                 read_xdata_u8(0xFA69)//UART42MEM接收控制寄存器
#define DMA_UR4R_STA                read_xdata_u8(0xFA6A)//UART42MEM接收状态寄存器
#define DMA_UR4R_AMT                read_xdata_u8(0xFA6B)//UART42MEM接收总字节寄存器
#define DMA_UR4R_DONE               read_xdata_u8(0xFA6C)//UART42MEM接收完成字节寄存器
#define DMA_UR4R_RXA                read_xdata_u16(0xFA6D)//UART42MEM接收发送地址寄存器（16位）
#define DMA_UR4R_RXAH               read_xdata_u8(0xFA6D)//UART42MEM接收地址寄存器（高8位）
#define DMA_UR4R_RXAL               read_xdata_u8(0xFA6E)//UART42MEM接收地址寄存器（低8位）
/*----------------------------------FA70H~FA7FH----------------------------------*/
#define DMA_LCM_CFG                 read_xdata_u8(0xFA70)//LCM_MEM配置寄存器
#define DMA_LCM_CR                  read_xdata_u8(0xFA71)//LCM_MEM控制寄存器
#define DMA_LCM_STA                 read_xdata_u8(0xFA72)//LCM_MEM状态寄存器
#define DMA_LCM_AMT                 read_xdata_u8(0xFA73)//LCM_MEM总字节寄存器
#define DMA_LCM_DONE                read_xdata_u8(0xFA74)//LCM_MEM传输完成字节寄存器
#define DMA_LCM_TXA                 read_xdata_u16(0xFA75)//LCM_MEM发送地址寄存器（16位）
#define DMA_LCM_TXAH                read_xdata_u8(0xFA75)//LCM_MEM发送地址寄存器（高8位）
#define DMA_LCM_TXAL                read_xdata_u8(0xFA76)//LCM_MEM发送地址寄存器（低8位）
#define DMA_LCM_RXA                 read_xdata_u16(0xFA77)//LCM_MEM接收发送地址寄存器（16位）
#define DMA_LCM_RXAH                read_xdata_u8(0xFA77)//LCM_MEM接收地址寄存器（高8位）
#define DMA_LCM_RXAL                read_xdata_u8(0xFA78)//LCM_MEM接收地址寄存器（低8位）
/*----------------------------------FB00H~FB2FH----------------------------------*/
#define COMEN                       read_xdata_u8(0xFB00)
#define SEGENL                      read_xdata_u8(0xFB01)
#define SEGENH                      read_xdata_u8(0xFB02)
#define LEDCTRL                     read_xdata_u8(0xFB03)
#define LEDCKS                      read_xdata_u8(0xFB04)
#define COM0_DA_L                   read_xdata_u8(0xFB10)
#define COM1_DA_L                   read_xdata_u8(0xFB11)
#define COM2_DA_L                   read_xdata_u8(0xFB12)
#define COM3_DA_L                   read_xdata_u8(0xFB13)
#define COM4_DA_L                   read_xdata_u8(0xFB14)
#define COM5_DA_L                   read_xdata_u8(0xFB15)
#define COM6_DA_L                   read_xdata_u8(0xFB16)
#define COM7_DA_L                   read_xdata_u8(0xFB17)
#define COM0_DA_H                   read_xdata_u8(0xFB18)
#define COM1_DA_H                   read_xdata_u8(0xFB19)
#define COM2_DA_H                   read_xdata_u8(0xFB1A)
#define COM3_DA_H                   read_xdata_u8(0xFB1B)
#define COM4_DA_H                   read_xdata_u8(0xFB1C)
#define COM5_DA_H                   read_xdata_u8(0xFB1D)
#define COM6_DA_H                   read_xdata_u8(0xFB1E)
#define COM7_DA_H                   read_xdata_u8(0xFB1F)
#define COM0_DC_L                   read_xdata_u8(0xFB20)
#define COM1_DC_L                   read_xdata_u8(0xFB21)
#define COM2_DC_L                   read_xdata_u8(0xFB22)
#define COM3_DC_L                   read_xdata_u8(0xFB23)
#define COM4_DC_L                   read_xdata_u8(0xFB24)
#define COM5_DC_L                   read_xdata_u8(0xFB25)
#define COM6_DC_L                   read_xdata_u8(0xFB26)
#define COM7_DC_L                   read_xdata_u8(0xFB27)
#define COM0_DC_H                   read_xdata_u8(0xFB28)
#define COM1_DC_H                   read_xdata_u8(0xFB29)
#define COM2_DC_H                   read_xdata_u8(0xFB2A)
#define COM3_DC_H                   read_xdata_u8(0xFB2B)
#define COM4_DC_H                   read_xdata_u8(0xFB2C)
#define COM5_DC_H                   read_xdata_u8(0xFB2D)
#define COM6_DC_H                   read_xdata_u8(0xFB2E)
#define COM7_DC_H                   read_xdata_u8(0xFB2F)
/*----------------------------------FB40H~FB6FH----------------------------------*/
#define TSCHEN1                     read_xdata_u8(0xFB40)
#define TSCHEN2                     read_xdata_u8(0xFB41)
#define TSCFG1                      read_xdata_u8(0xFB42)
#define TSCFG2                      read_xdata_u8(0xFB43)
#define TSWUTC                      read_xdata_u8(0xFB44)
#define TSCTRL                      read_xdata_u8(0xFB45)
#define TSSTA1                      read_xdata_u8(0xFB46)
#define TSSTA2                      read_xdata_u8(0xFB47)
#define TSRT                        read_xdata_u8(0xFB48)
#define TSDATH                      read_xdata_u8(0xFB49)
#define TSDATL                      read_xdata_u8(0xFB4A)
#define TSTH00H                     read_xdata_u8(0xFB50)
#define TSTH00L                     read_xdata_u8(0xFB51)
#define TSTH01H                     read_xdata_u8(0xFB52)
#define TSTH01L                     read_xdata_u8(0xFB53)
#define TSTH02H                     read_xdata_u8(0xFB54)
#define TSTH02L                     read_xdata_u8(0xFB55)
#define TSTH03H                     read_xdata_u8(0xFB56)
#define TSTH03L                     read_xdata_u8(0xFB57)
#define TSTH04H                     read_xdata_u8(0xFB58)
#define TSTH04L                     read_xdata_u8(0xFB59)
#define TSTH05H                     read_xdata_u8(0xFB5A)
#define TSTH05L                     read_xdata_u8(0xFB5B)
#define TSTH06H                     read_xdata_u8(0xFB5C)
#define TSTH06L                     read_xdata_u8(0xFB5D)
#define TSTH07H                     read_xdata_u8(0xFB5E)
#define TSTH07L                     read_xdata_u8(0xFB5F)
#define TSTH08H                     read_xdata_u8(0xFB60)
#define TSTH08L                     read_xdata_u8(0xFB61)
#define TSTH09H                     read_xdata_u8(0xFB62)
#define TSTH09L                     read_xdata_u8(0xFB63)
#define TSTH10H                     read_xdata_u8(0xFB64)
#define TSTH10L                     read_xdata_u8(0xFB65)
#define TSTH11H                     read_xdata_u8(0xFB66)
#define TSTH11L                     read_xdata_u8(0xFB67)
#define TSTH12H                     read_xdata_u8(0xFB68)
#define TSTH12L                     read_xdata_u8(0xFB69)
#define TSTH13H                     read_xdata_u8(0xFB6A)
#define TSTH13L                     read_xdata_u8(0xFB6B)
#define TSTH14H                     read_xdata_u8(0xFB6C)
#define TSTH14L                     read_xdata_u8(0xFB6D)
#define TSTH15H                     read_xdata_u8(0xFB6E)
#define TSTH15L                     read_xdata_u8(0xFB6F)
/*----------------------------------FB80H~FBACH----------------------------------*/
#define LCDCFG                      read_xdata_u8(0xFB80)
#define LCDCFG2                     read_xdata_u8(0xFB81)
#define DBLEN                       read_xdata_u8(0xFB82)
#define COMLENL                     read_xdata_u8(0xFB83)
#define COMLENM                     read_xdata_u8(0xFB84)
#define COMLENH                     read_xdata_u8(0xFB85)
#define BLINKRATE                   read_xdata_u8(0xFB86)
#define LCDCR                       read_xdata_u8(0xFB87)
#define COMON                       read_xdata_u8(0xFB88)
#define SEGON1                      read_xdata_u8(0xFB8A)
#define SEGON2                      read_xdata_u8(0xFB8B)
#define SEGON3                      read_xdata_u8(0xFB8C)
#define SEGON4                      read_xdata_u8(0xFB8D)
#define SEGON5                      read_xdata_u8(0xFB8E)
#define C0SEGV0                     read_xdata_u8(0xFB90)
#define C0SEGV1                     read_xdata_u8(0xFB91)
#define C0SEGV2                     read_xdata_u8(0xFB92)
#define C0SEGV3                     read_xdata_u8(0xFB93)
#define C0SEGV4                     read_xdata_u8(0xFB94)
#define C1SEGV0                     read_xdata_u8(0xFB98)
#define C1SEGV1                     read_xdata_u8(0xFB99)
#define C1SEGV2                     read_xdata_u8(0xFB9A)
#define C1SEGV3                     read_xdata_u8(0xFB9B)
#define C1SEGV4                     read_xdata_u8(0xFB9C)
#define C2SEGV0                     read_xdata_u8(0xFBA0)
#define C2SEGV1                     read_xdata_u8(0xFBA1)
#define C2SEGV2                     read_xdata_u8(0xFBA2)
#define C2SEGV3                     read_xdata_u8(0xFBA3)
#define C2SEGV4                     read_xdata_u8(0xFBA4)
#define C3SEGV0                     read_xdata_u8(0xFBA8)
#define C3SEGV1                     read_xdata_u8(0xFBA9)
#define C3SEGV2                     read_xdata_u8(0xFBAA)
#define C3SEGV3                     read_xdata_u8(0xFBAB)
#define C3SEGV4                     read_xdata_u8(0xFBAC)
/*----------------------------------FC00H~FCEFH----------------------------------*/
#define PWM_P3_C                    read_xdata_u16(0xFC00)
#define PWM_P3_CH                   read_xdata_u8(0xFC00)
#define PWM_P3_CL                   read_xdata_u8(0xFC01)
#define PWM_P3_CKS                  read_xdata_u8(0xFC02)
#define PWM_P3_IF                   read_xdata_u8(0xFC05)
#define PWM_P3_FDCR                 read_xdata_u8(0xFC06)
#define PWM_P30_T1                  read_xdata_u16(0xFC10)
#define PWM_P30_T1H                 read_xdata_u8(0xFC10)
#define PWM_P30_T1L                 read_xdata_u8(0xFC11)
#define PWM_P30_T2                  read_xdata_u16(0xFC12)
#define PWM_P30_T2H                 read_xdata_u8(0xFC12)
#define PWM_P30_T2L                 read_xdata_u8(0xFC13)
#define PWM_P30_CR                  read_xdata_u8(0xFC14)
#define PWM_P30_HLD                 read_xdata_u8(0xFC15)
#define PWM_P31_T1                  read_xdata_u16(0xFC18)
#define PWM_P31_T1H                 read_xdata_u8(0xFC18)
#define PWM_P31_T1L                 read_xdata_u8(0xFC19)
#define PWM_P31_T2                  read_xdata_u16(0xFC1A)
#define PWM_P31_T2H                 read_xdata_u8(0xFC1A)
#define PWM_P31_T2L                 read_xdata_u8(0xFC1B)
#define PWM_P31_CR                  read_xdata_u8(0xFC1C)
#define PWM_P31_HLD                 read_xdata_u8(0xFC1D)
#define PWM_P32_T1                  read_xdata_u16(0xFC20)
#define PWM_P32_T1H                 read_xdata_u8(0xFC20)
#define PWM_P32_T1L                 read_xdata_u8(0xFC21)
#define PWM_P32_T2                  read_xdata_u16(0xFC22)
#define PWM_P32_T2H                 read_xdata_u8(0xFC22)
#define PWM_P32_T2L                 read_xdata_u8(0xFC23)
#define PWM_P32_CR                  read_xdata_u8(0xFC24)
#define PWM_P32_HLD                 read_xdata_u8(0xFC25)
#define PWM_P33_T1                  read_xdata_u16(0xFC28)
#define PWM_P33_T1H                 read_xdata_u8(0xFC28)
#define PWM_P33_T1L                 read_xdata_u8(0xFC29)
#define PWM_P33_T2                  read_xdata_u16(0xFC2A)
#define PWM_P33_T2H                 read_xdata_u8(0xFC2A)
#define PWM_P33_T2L                 read_xdata_u8(0xFC2B)
#define PWM_P33_CR                  read_xdata_u8(0xFC2C)
#define PWM_P33_HLD                 read_xdata_u8(0xFC2D)
#define PWM_P34_T1                  read_xdata_u16(0xFC30)
#define PWM_P34_T1H                 read_xdata_u8(0xFC30)
#define PWM_P34_T1L                 read_xdata_u8(0xFC31)
#define PWM_P34_T2                  read_xdata_u16(0xFC32)
#define PWM_P34_T2H                 read_xdata_u8(0xFC32)
#define PWM_P34_T2L                 read_xdata_u8(0xFC33)
#define PWM_P34_CR                  read_xdata_u8(0xFC34)
#define PWM_P34_HLD                 read_xdata_u8(0xFC35)
#define PWM_P35_T1                  read_xdata_u16(0xFC38)
#define PWM_P35_T1H                 read_xdata_u8(0xFC38)
#define PWM_P35_T1L                 read_xdata_u8(0xFC39)
#define PWM_P35_T2                  read_xdata_u16(0xFC3A)
#define PWM_P35_T2H                 read_xdata_u8(0xFC3A)
#define PWM_P35_T2L                 read_xdata_u8(0xFC3B)
#define PWM_P35_CR                  read_xdata_u8(0xFC3C)
#define PWM_P35_HLD                 read_xdata_u8(0xFC3D)
#define PWM_P36_T1                  read_xdata_u16(0xFC40)
#define PWM_P36_T1H                 read_xdata_u8(0xFC40)
#define PWM_P36_T1L                 read_xdata_u8(0xFC41)
#define PWM_P36_T2                  read_xdata_u16(0xFC42)
#define PWM_P36_T2H                 read_xdata_u8(0xFC42)
#define PWM_P36_T2L                 read_xdata_u8(0xFC43)
#define PWM_P36_CR                  read_xdata_u8(0xFC44)
#define PWM_P36_HLD                 read_xdata_u8(0xFC45)
#define PWM_P37_T1                  read_xdata_u16(0xFC48)
#define PWM_P37_T1H                 read_xdata_u8(0xFC48)
#define PWM_P37_T1L                 read_xdata_u8(0xFC49)
#define PWM_P37_T2                  read_xdata_u16(0xFC4A)
#define PWM_P37_T2H                 read_xdata_u8(0xFC4A)
#define PWM_P37_T2L                 read_xdata_u8(0xFC4B)
#define PWM_P37_CR                  read_xdata_u8(0xFC4C)
#define PWM_P37_HLD                 read_xdata_u8(0xFC4D)
#define PWM_P4_C                    read_xdata_u16(0xFC50)
#define PWM_P4_CH                   read_xdata_u8(0xFC50)
#define PWM_P4_CL                   read_xdata_u8(0xFC51)
#define PWM_P4_CKS                  read_xdata_u8(0xFC52)
#define PWM_P4_TADC                 read_xdata_u16(0xFC53)
#define PWM_P4_TADCH                read_xdata_u8(0xFC53)
#define PWM_P4_TADCL                read_xdata_u8(0xFC54)
#define PWM_P4_IF                   read_xdata_u8(0xFC55)
#define PWM_P4_FDCR                 read_xdata_u8(0xFC56)
#define PWM_P40_T1                  read_xdata_u16(0xFC60)
#define PWM_P40_T1H                 read_xdata_u8(0xFC60)
#define PWM_P40_T1L                 read_xdata_u8(0xFC61)
#define PWM_P40_T2                  read_xdata_u16(0xFC62)
#define PWM_P40_T2H                 read_xdata_u8(0xFC62)
#define PWM_P40_T2L                 read_xdata_u8(0xFC63)
#define PWM_P40_CR                  read_xdata_u8(0xFC64)
#define PWM_P40_HLD                 read_xdata_u8(0xFC65)
#define PWM_P41_T1                  read_xdata_u16(0xFC68)
#define PWM_P41_T1H                 read_xdata_u8(0xFC68)
#define PWM_P41_T1L                 read_xdata_u8(0xFC69)
#define PWM_P41_T2                  read_xdata_u16(0xFC6A)
#define PWM_P41_T2H                 read_xdata_u8(0xFC6A)
#define PWM_P41_T2L                 read_xdata_u8(0xFC6B)
#define PWM_P41_CR                  read_xdata_u8(0xFC6C)
#define PWM_P41_HLD                 read_xdata_u8(0xFC6D)
#define PWM_P42_T1                  read_xdata_u16(0xFC70)
#define PWM_P42_T1H                 read_xdata_u8(0xFC70)
#define PWM_P42_T1L                 read_xdata_u8(0xFC71)
#define PWM_P42_T2                  read_xdata_u16(0xFC72)
#define PWM_P42_T2H                 read_xdata_u8(0xFC72)
#define PWM_P42_T2L                 read_xdata_u8(0xFC73)
#define PWM_P42_CR                  read_xdata_u8(0xFC74)
#define PWM_P42_HLD                 read_xdata_u8(0xFC75)
#define PWM_P43_T1                  read_xdata_u16(0xFC78)
#define PWM_P43_T1H                 read_xdata_u8(0xFC78)
#define PWM_P43_T1L                 read_xdata_u8(0xFC79)
#define PWM_P43_T2                  read_xdata_u16(0xFC7A)
#define PWM_P43_T2H                 read_xdata_u8(0xFC7A)
#define PWM_P43_T2L                 read_xdata_u8(0xFC7B)
#define PWM_P43_CR                  read_xdata_u8(0xFC7C)
#define PWM_P43_HLD                 read_xdata_u8(0xFC7D)
#define PWM_P44_T1                  read_xdata_u16(0xFC80)
#define PWM_P44_T1H                 read_xdata_u8(0xFC80)
#define PWM_P44_T1L                 read_xdata_u8(0xFC81)
#define PWM_P44_T2                  read_xdata_u16(0xFC82)
#define PWM_P44_T2H                 read_xdata_u8(0xFC82)
#define PWM_P44_T2L                 read_xdata_u8(0xFC83)
#define PWM_P44_CR                  read_xdata_u8(0xFC84)
#define PWM_P44_HLD                 read_xdata_u8(0xFC85)
#define PWM_P45_T1                  read_xdata_u16(0xFC88)
#define PWM_P45_T1H                 read_xdata_u8(0xFC88)
#define PWM_P45_T1L                 read_xdata_u8(0xFC89)
#define PWM_P45_T2                  read_xdata_u16(0xFC8A)
#define PWM_P45_T2H                 read_xdata_u8(0xFC8A)
#define PWM_P45_T2L                 read_xdata_u8(0xFC8B)
#define PWM_P45_CR                  read_xdata_u8(0xFC8C)
#define PWM_P45_HLD                 read_xdata_u8(0xFC8D)
#define PWM_P46_T1                  read_xdata_u16(0xFC90)
#define PWM_P46_T1H                 read_xdata_u8(0xFC90)
#define PWM_P46_T1L                 read_xdata_u8(0xFC91)
#define PWM_P46_T2                  read_xdata_u16(0xFC92)
#define PWM_P46_T2H                 read_xdata_u8(0xFC92)
#define PWM_P46_T2L                 read_xdata_u8(0xFC93)
#define PWM_P46_CR                  read_xdata_u8(0xFC94)
#define PWM_P46_HLD                 read_xdata_u8(0xFC95)
#define PWM_P47_T1                  read_xdata_u16(0xFC98)
#define PWM_P47_T1H                 read_xdata_u8(0xFC98)
#define PWM_P47_T1L                 read_xdata_u8(0xFC99)
#define PWM_P47_T2                  read_xdata_u16(0xFC9A)
#define PWM_P47_T2H                 read_xdata_u8(0xFC9A)
#define PWM_P47_T2L                 read_xdata_u8(0xFC9B)
#define PWM_P47_CR                  read_xdata_u8(0xFC9C)
#define PWM_P47_HLD                 read_xdata_u8(0xFC9D)
#define PWM_P5_C                    read_xdata_u16(0xFCA0)
#define PWM_P5_CH                   read_xdata_u8(0xFCA0)
#define PWM_P5_CL                   read_xdata_u8(0xFCA1)
#define PWM_P5_CKS                  read_xdata_u8(0xFCA2)
#define PWM_P5_IF                   read_xdata_u8(0xFCA5)
#define PWM_P5_FDCR                 read_xdata_u8(0xFCA6)
#define PWM_P50_T1                  read_xdata_u16(0xFCB0)
#define PWM_P50_T1H                 read_xdata_u8(0xFCB0)
#define PWM_P50_T1L                 read_xdata_u8(0xFCB1)
#define PWM_P50_T2                  read_xdata_u16(0xFCB2)
#define PWM_P50_T2H                 read_xdata_u8(0xFCB2)
#define PWM_P50_T2L                 read_xdata_u8(0xFCB3)
#define PWM_P50_CR                  read_xdata_u8(0xFCB4)
#define PWM_P50_HLD                 read_xdata_u8(0xFCB5)
#define PWM_P51_T1                  read_xdata_u16(0xFCB8)
#define PWM_P51_T1H                 read_xdata_u8(0xFCB8)
#define PWM_P51_T1L                 read_xdata_u8(0xFCB9)
#define PWM_P51_T2                  read_xdata_u16(0xFCBA)
#define PWM_P51_T2H                 read_xdata_u8(0xFCBA)
#define PWM_P51_T2L                 read_xdata_u8(0xFCBB)
#define PWM_P51_CR                  read_xdata_u8(0xFCBC)
#define PWM_P51_HLD                 read_xdata_u8(0xFCBD)
#define PWM_P52_T1                  read_xdata_u16(0xFCC0)
#define PWM_P52_T1H                 read_xdata_u8(0xFCC0)
#define PWM_P52_T1L                 read_xdata_u8(0xFCC1)
#define PWM_P52_T2                  read_xdata_u16(0xFCC2)
#define PWM_P52_T2H                 read_xdata_u8(0xFCC2)
#define PWM_P52_T2L                 read_xdata_u8(0xFCC3)
#define PWM_P52_CR                  read_xdata_u8(0xFCC4)
#define PWM_P52_HLD                 read_xdata_u8(0xFCC5)
#define PWM_P53_T1                  read_xdata_u16(0xFCC8)
#define PWM_P53_T1H                 read_xdata_u8(0xFCC8)
#define PWM_P53_T1L                 read_xdata_u8(0xFCC9)
#define PWM_P53_T2                  read_xdata_u16(0xFCCA)
#define PWM_P53_T2H                 read_xdata_u8(0xFCCA)
#define PWM_P53_T2L                 read_xdata_u8(0xFCCB)
#define PWM_P53_CR                  read_xdata_u8(0xFCCC)
#define PWM_P53_HLD                 read_xdata_u8(0xFCCD)
#define PWM_P54_T1                  read_xdata_u16(0xFCD0)
#define PWM_P54_T1H                 read_xdata_u8(0xFCD0)
#define PWM_P54_T1L                 read_xdata_u8(0xFCD1)
#define PWM_P54_T2                  read_xdata_u16(0xFCD2)
#define PWM_P54_T2H                 read_xdata_u8(0xFCD2)
#define PWM_P54_T2L                 read_xdata_u8(0xFCD3)
#define PWM_P54_CR                  read_xdata_u8(0xFCD4)
#define PWM_P54_HLD                 read_xdata_u8(0xFCD5)
#define PWM_P55_T1                  read_xdata_u16(0xFCD8)
#define PWM_P55_T1H                 read_xdata_u8(0xFCD8)
#define PWM_P55_T1L                 read_xdata_u8(0xFCD9)
#define PWM_P55_T2                  read_xdata_u16(0xFCDA)
#define PWM_P55_T2H                 read_xdata_u8(0xFCDA)
#define PWM_P55_T2L                 read_xdata_u8(0xFCDB)
#define PWM_P55_CR                  read_xdata_u8(0xFCDC)
#define PWM_P55_HLD                 read_xdata_u8(0xFCDD)
#define PWM_P56_T1                  read_xdata_u16(0xFCE0)
#define PWM_P56_T1H                 read_xdata_u8(0xFCE0)
#define PWM_P56_T1L                 read_xdata_u8(0xFCE1)
#define PWM_P56_T2                  read_xdata_u16(0xFCE2)
#define PWM_P56_T2H                 read_xdata_u8(0xFCE2)
#define PWM_P56_T2L                 read_xdata_u8(0xFCE3)
#define PWM_P56_CR                  read_xdata_u8(0xFCE4)
#define PWM_P56_HLD                 read_xdata_u8(0xFCE5)
#define PWM_P57_T1                  read_xdata_u16(0xFCE8)
#define PWM_P57_T1H                 read_xdata_u8(0xFCE8)
#define PWM_P57_T1L                 read_xdata_u8(0xFCE9)
#define PWM_P57_T2                  read_xdata_u16(0xFCEA)
#define PWM_P57_T2H                 read_xdata_u8(0xFCEA)
#define PWM_P57_T2L                 read_xdata_u8(0xFCEB)
#define PWM_P57_CR                  read_xdata_u8(0xFCEC)
#define PWM_P57_HLD                 read_xdata_u8(0xFCED)
/*----------------------------------FCF0H~FCF7H----------------------------------*/
#define MD3MD2MD1MD0                read_xdata_u32(0xFCF0)//一般用来存放32位被除数、32位商、积。
#define MD1MD0                      read_xdata_u16(0xFCF2)//一般用来存放16位被除数、16位商、16位被乘数。
#define MD5MD4                      read_xdata_u16(0xFCF4)//一般用来存放除数、余数、乘数。
#define ARCON                       read_xdata_u8(0xFCF6)//MDU模式控制寄存器
#define OPCON                       read_xdata_u8(0xFCF7)//MDU操作控制寄存器
/*----------------------------------FD00H~FD67H----------------------------------*/
#define P0INTE                      read_xdata_u8(0xFD00)
#define P1INTE                      read_xdata_u8(0xFD01)
#define P2INTE                      read_xdata_u8(0xFD02)
#define P3INTE                      read_xdata_u8(0xFD03)
#define P4INTE                      read_xdata_u8(0xFD04)
#define P5INTE                      read_xdata_u8(0xFD05)
#define P6INTE                      read_xdata_u8(0xFD06)
#define P7INTE                      read_xdata_u8(0xFD07)
#define P0INTF                      read_xdata_u8(0xFD10)
#define P1INTF                      read_xdata_u8(0xFD11)
#define P2INTF                      read_xdata_u8(0xFD12)
#define P3INTF                      read_xdata_u8(0xFD13)
#define P4INTF                      read_xdata_u8(0xFD14)
#define P5INTF                      read_xdata_u8(0xFD15)
#define P6INTF                      read_xdata_u8(0xFD16)
#define P7INTF                      read_xdata_u8(0xFD17)
#define P0IM0                       read_xdata_u8(0xFD20)
#define P1IM0                       read_xdata_u8(0xFD21)
#define P2IM0                       read_xdata_u8(0xFD22)
#define P3IM0                       read_xdata_u8(0xFD23)
#define P4IM0                       read_xdata_u8(0xFD24)
#define P5IM0                       read_xdata_u8(0xFD25)
#define P6IM0                       read_xdata_u8(0xFD26)
#define P7IM0                       read_xdata_u8(0xFD27)
#define P0IM1                       read_xdata_u8(0xFD30)
#define P1IM1                       read_xdata_u8(0xFD31)
#define P2IM1                       read_xdata_u8(0xFD32)
#define P3IM1                       read_xdata_u8(0xFD33)
#define P4IM1                       read_xdata_u8(0xFD34)
#define P5IM1                       read_xdata_u8(0xFD35)
#define P6IM1                       read_xdata_u8(0xFD36)
#define P7IM1                       read_xdata_u8(0xFD37)

#define P0WKUE                      read_xdata_u8(0xFD40)
#define P1WKUE                      read_xdata_u8(0xFD41)
#define P2WKUE                      read_xdata_u8(0xFD42)
#define P3WKUE                      read_xdata_u8(0xFD43)
#define P4WKUE                      read_xdata_u8(0xFD44)
#define P5WKUE                      read_xdata_u8(0xFD45)
#define P6WKUE                      read_xdata_u8(0xFD46)
#define P7WKUE                      read_xdata_u8(0xFD47)

#define PINIPL                      read_xdata_u8(0xFD60)
#define PINIPH                      read_xdata_u8(0xFD61)
/*----------------------------------FE00H~FE07H----------------------------------*/
#define CKSEL                       read_xdata_u8(0xFE00)//时钟选择寄存器
#define CLKDIV                      read_xdata_u8(0xFE01)//时钟分频寄存器
#define HIRCCR                      read_xdata_u8(0xFE02)//内部高速振荡器控制寄存器
#define XOSCCR                      read_xdata_u8(0xFE03)//外部晶振控制寄存器
#define IRC32KCR                    read_xdata_u8(0xFE04)//内部32K振荡器控制寄存器
#define MCLKOCR                     read_xdata_u8(0xFE05)//主时钟输出控制寄存器
#define IRCDB                       read_xdata_u8(0xFE06)//内部高速振荡器去抖控制寄存器
#define IRC48MCR                    read_xdata_u8(0xFE07)//内部48M振荡器控制寄存器
/*----------------------------------FE08H~FE0FH----------------------------------*/
#define X32KCR                      read_xdata_u8(0xFE08)//外部32K振荡器控制寄存器
#define SPFUNC                      read_xdata_u8(0xFE08)
#define RSTFLAG                     read_xdata_u8(0xFE09)
/*----------------------------------FE10H~FE17H----------------------------------*/
#define P0PU                        read_xdata_u8(0xFE10)//P0口上拉电阻控制寄存器
#define P1PU                        read_xdata_u8(0xFE11)//P1口上拉电阻控制寄存器
#define P2PU                        read_xdata_u8(0xFE12)//P2口上拉电阻控制寄存器
#define P3PU                        read_xdata_u8(0xFE13)//P3口上拉电阻控制寄存器
#define P4PU                        read_xdata_u8(0xFE14)//P4口上拉电阻控制寄存器
#define P5PU                        read_xdata_u8(0xFE15)//P5口上拉电阻控制寄存器
#define P6PU                        read_xdata_u8(0xFE16)//P6口上拉电阻控制寄存器
#define P7PU                        read_xdata_u8(0xFE17)//P7口上拉电阻控制寄存器
/*----------------------------------FE18H~FE1FH----------------------------------*/
#define P0NCS                       read_xdata_u8(0xFE18)//P0口施密特触发控制寄存器
#define P1NCS                       read_xdata_u8(0xFE19)//P1口施密特触发控制寄存器
#define P2NCS                       read_xdata_u8(0xFE1A)//P2口施密特触发控制寄存器
#define P3NCS                       read_xdata_u8(0xFE1B)//P3口施密特触发控制寄存器
#define P4NCS                       read_xdata_u8(0xFE1C)//P4口施密特触发控制寄存器
#define P5NCS                       read_xdata_u8(0xFE1D)//P5口施密特触发控制寄存器
#define P6NCS                       read_xdata_u8(0xFE1E)//P6口施密特触发控制寄存器
#define P7NCS                       read_xdata_u8(0xFE1F)//P7口施密特触发控制寄存器
/*----------------------------------FE20H~FE27H----------------------------------*/
#define P0SR                        read_xdata_u8(0xFE20)//P0口电平转换速度控制寄存器
#define P1SR                        read_xdata_u8(0xFE21)//P1口电平转换速度控制寄存器
#define P2SR                        read_xdata_u8(0xFE22)//P2口电平转换速度控制寄存器
#define P3SR                        read_xdata_u8(0xFE23)//P3口电平转换速度控制寄存器
#define P4SR                        read_xdata_u8(0xFE24)//P4口电平转换速度控制寄存器
#define P5SR                        read_xdata_u8(0xFE25)//P5口电平转换速度控制寄存器
#define P6SR                        read_xdata_u8(0xFE26)//P6口电平转换速度控制寄存器
#define P7SR                        read_xdata_u8(0xFE27)//P7口电平转换速度控制寄存器
/*----------------------------------FE28H~FE2FH----------------------------------*/
#define P0DR                        read_xdata_u8(0xFE28)//P0口驱动电流控制寄存器
#define P1DR                        read_xdata_u8(0xFE29)//P1口驱动电流控制寄存器
#define P2DR                        read_xdata_u8(0xFE2A)//P2口驱动电流控制寄存器
#define P3DR                        read_xdata_u8(0xFE2B)//P3口驱动电流控制寄存器
#define P4DR                        read_xdata_u8(0xFE2C)//P4口驱动电流控制寄存器
#define P5DR                        read_xdata_u8(0xFE2D)//P5口驱动电流控制寄存器
#define P6DR                        read_xdata_u8(0xFE2E)//P6口驱动电流控制寄存器
#define P7DR                        read_xdata_u8(0xFE2F)//P7口驱动电流控制寄存器
/*----------------------------------FE30H~FE37H----------------------------------*/
#define P0IE                        read_xdata_u8(0xFE30)//P0口数字信号输入使能控制寄存器
#define P1IE                        read_xdata_u8(0xFE31)//P1口数字信号输入使能控制寄存器
#define P2IE                        read_xdata_u8(0xFE32)//P2口数字信号输入使能控制寄存器
#define P3IE                        read_xdata_u8(0xFE33)//P3口数字信号输入使能控制寄存器
#define P4IE                        read_xdata_u8(0xFE34)//P4口数字信号输入使能控制寄存器
#define P5IE                        read_xdata_u8(0xFE35)//P5口数字信号输入使能控制寄存器
#define P6IE                        read_xdata_u8(0xFE36)//P6口数字信号输入使能控制寄存器
#define P7IE                        read_xdata_u8(0xFE37)//P7口数字信号输入使能控制寄存器
/*----------------------------------FE50H~FE57H----------------------------------*/
#define LCMIFCFG                    read_xdata_u8(0xFE50)//LCM接口配置寄存器
#define LCMIFCFG2                   read_xdata_u8(0xFE51)//LCM接口配置寄存器2
#define LCMIFCR                     read_xdata_u8(0xFE52)//LCM接口控制寄存器
#define LCMIFSTA                    read_xdata_u8(0xFE53)//LCM接口状态寄存器
#define LCMIFDATL                   read_xdata_u8(0xFE54)//LCM接口低字节数据
#define LCMIFDATH                   read_xdata_u8(0xFE55)//LCM接口高字节数据

/*----------------------------------FE60H~FE77H----------------------------------*/
#define RTCCR                       read_xdata_u8(0xFE60)
#define RTCCFG                      read_xdata_u8(0xFE61)
#define RTCIEN                      read_xdata_u8(0xFE62)
#define RTCIF                       read_xdata_u8(0xFE63)
#define ALAHOUR                     read_xdata_u8(0xFE64)
#define ALAMIN                      read_xdata_u8(0xFE65)
#define ALASEC                      read_xdata_u8(0xFE66)
#define ALASSEC                     read_xdata_u8(0xFE67)
#define INIYEAR                     read_xdata_u8(0xFE68)
#define INIMONTH                    read_xdata_u8(0xFE69)
#define INIDAY                      read_xdata_u8(0xFE6A)
#define INIHOUR                     read_xdata_u8(0xFE6B)
#define INIMIN                      read_xdata_u8(0xFE6C)
#define INISEC                      read_xdata_u8(0xFE6D)
#define INISSEC                     read_xdata_u8(0xFE6E)
#define YEAR                        read_xdata_u8(0xFE70)
#define MONTH                       read_xdata_u8(0xFE71)
#define DAY                         read_xdata_u8(0xFE72)
#define HOUR                        read_xdata_u8(0xFE73)
#define MIN                         read_xdata_u8(0xFE74)
#define SEC                         read_xdata_u8(0xFE75)
#define SSEC                        read_xdata_u8(0xFE76)

/*----------------------------------FE80H~FE8FH----------------------------------*/
#define I2CCFG                      read_xdata_u8(0xFE80)//IIC配置寄存器
#define I2CMSCR                     read_xdata_u8(0xFE81)//IIC主机控制寄存器
#define I2CMSST                     read_xdata_u8(0xFE82)//IIC主机状态寄存器
#define I2CSLCR                     read_xdata_u8(0xFE83)//IIC从机控制寄存器
#define I2CSLST                     read_xdata_u8(0xFE84)//IIC从机状态寄存器
#define I2CSLADR                    read_xdata_u8(0xFE85)//IIC从机地址寄存器
#define I2CTXD                      read_xdata_u8(0xFE86)//IIC发送数据寄存器
#define I2CRXD                      read_xdata_u8(0xFE87)//IIC接收数据寄存器
#define I2CMSAUX                    read_xdata_u8(0xFE88)//IIC主机辅助控制寄存器
/*----------------------------------FEA0H~FEA7H----------------------------------*/
#define TM2PS                       read_xdata_u8(0xFEA2)
#define TM3PS                       read_xdata_u8(0xFEA3)
#define TM4PS                       read_xdata_u8(0xFEA4)
/*----------------------------------FEA8H~FEAFH----------------------------------*/
#define ADC_TIM                     read_xdata_u8(0xFEA8)//ADC时序控制寄存器
#define T3T4PIN                     read_xdata_u8(0xFEAC)
#define ADCEXCFG                    read_xdata_u8(0xFEAD)//ADC扩展配置寄存器
#define CMPEXCFG                    read_xdata_u8(0xFEAE)//CMP扩展配置寄存器
/*----------------------------------FEB0H~FEFFH----------------------------------*/
#define PWMA_ETRPS                  read_xdata_u8(0xFEB0)
#define PWMA_ENO                    read_xdata_u8(0xFEB1)
#define PWMA_PS                     read_xdata_u8(0xFEB2)
#define PWMA_IOAUX                  read_xdata_u8(0xFEB3)
#define PWMB_ETRPS                  read_xdata_u8(0xFEB4)
#define PWMB_ENO                    read_xdata_u8(0xFEB5)
#define PWMB_PS                     read_xdata_u8(0xFEB6)
#define PWMB_IOAUX                  read_xdata_u8(0xFEB7)
#define PWMA_CR1                    read_xdata_u8(0xFEC0)
#define PWMA_CR2                    read_xdata_u8(0xFEC1)
#define PWMA_SMCR                   read_xdata_u8(0xFEC2)
#define PWMA_ETR                    read_xdata_u8(0xFEC3)
#define PWMA_IER                    read_xdata_u8(0xFEC4)
#define PWMA_SR1                    read_xdata_u8(0xFEC5)
#define PWMA_SR2                    read_xdata_u8(0xFEC6)
#define PWMA_EGR                    read_xdata_u8(0xFEC7)
#define PWMA_CCMR1                  read_xdata_u8(0xFEC8)
#define PWMA_CCMR2                  read_xdata_u8(0xFEC9)
#define PWMA_CCMR3                  read_xdata_u8(0xFECA)
#define PWMA_CCMR4                  read_xdata_u8(0xFECB)
#define PWMA_CCER1                  read_xdata_u8(0xFECC)
#define PWMA_CCER2                  read_xdata_u8(0xFECD)
#define PWMA_CNTR                   read_xdata_u16(0xFECE)
#define PWMA_CNTRH                  read_xdata_u8(0xFECE)
#define PWMA_CNTRL                  read_xdata_u8(0xFECF)
#define PWMA_PSCR                   read_xdata_u16(0xFED0)
#define PWMA_PSCRH                  read_xdata_u8(0xFED0)
#define PWMA_PSCRL                  read_xdata_u8(0xFED1)
#define PWMA_ARR                    read_xdata_u16(0xFED2)
#define PWMA_ARRH                   read_xdata_u8(0xFED2)
#define PWMA_ARRL                   read_xdata_u8(0xFED3)
#define PWMA_RCR                    read_xdata_u8(0xFED4)
#define PWMA_CCR1                   read_xdata_u16(0xFED5)
#define PWMA_CCR1H                  read_xdata_u8(0xFED5)
#define PWMA_CCR1L                  read_xdata_u8(0xFED6)
#define PWMA_CCR2                   read_xdata_u16(0xFED7)
#define PWMA_CCR2H                  read_xdata_u8(0xFED7)
#define PWMA_CCR2L                  read_xdata_u8(0xFED8)
#define PWMA_CCR3                   read_xdata_u16(0xFED9)
#define PWMA_CCR3H                  read_xdata_u8(0xFED9)
#define PWMA_CCR3L                  read_xdata_u8(0xFEDA)
#define PWMA_CCR4                   read_xdata_u16(0xFEDB)
#define PWMA_CCR4H                  read_xdata_u8(0xFEDB)
#define PWMA_CCR4L                  read_xdata_u8(0xFEDC)
#define PWMA_BKR                    read_xdata_u8(0xFEDD)
#define PWMA_DTR                    read_xdata_u8(0xFEDE)
#define PWMA_OISR                   read_xdata_u8(0xFEDF)
#define PWMB_CR1                    read_xdata_u8(0xFEE0)
#define PWMB_CR2                    read_xdata_u8(0xFEE1)
#define PWMB_SMCR                   read_xdata_u8(0xFEE2)
#define PWMB_ETR                    read_xdata_u8(0xFEE3)
#define PWMB_IER                    read_xdata_u8(0xFEE4)
#define PWMB_SR1                    read_xdata_u8(0xFEE5)
#define PWMB_SR2                    read_xdata_u8(0xFEE6)
#define PWMB_EGR                    read_xdata_u8(0xFEE7)
#define PWMB_CCMR1                  read_xdata_u8(0xFEE8)
#define PWMB_CCMR2                  read_xdata_u8(0xFEE9)
#define PWMB_CCMR3                  read_xdata_u8(0xFEEA)
#define PWMB_CCMR4                  read_xdata_u8(0xFEEB)
#define PWMB_CCER1                  read_xdata_u8(0xFEEC)
#define PWMB_CCER2                  read_xdata_u8(0xFEED)
#define PWMB_CNTR                   read_xdata_u16(0xFEEE)
#define PWMB_CNTRH                  read_xdata_u8(0xFEEE)
#define PWMB_CNTRL                  read_xdata_u8(0xFEEF)
#define PWMB_PSCR                   read_xdata_u16(0xFEF0)
#define PWMB_PSCRH                  read_xdata_u8(0xFEF0)
#define PWMB_PSCRL                  read_xdata_u8(0xFEF1)
#define PWMB_ARR                    read_xdata_u16(0xFEF2)
#define PWMB_ARRH                   read_xdata_u8(0xFEF2)
#define PWMB_ARRL                   read_xdata_u8(0xFEF3)
#define PWMB_RCR                    read_xdata_u8(0xFEF4)
#define PWMB_CCR5                   read_xdata_u16(0xFEF5)
#define PWMB_CCR5H                  read_xdata_u8(0xFEF5)
#define PWMB_CCR5L                  read_xdata_u8(0xFEF6)
#define PWMB_CCR6                   read_xdata_u16(0xFEF7)
#define PWMB_CCR6H                  read_xdata_u8(0xFEF7)
#define PWMB_CCR6L                  read_xdata_u8(0xFEF8)
#define PWMB_CCR7                   read_xdata_u16(0xFEF9)
#define PWMB_CCR7H                  read_xdata_u8(0xFEF9)
#define PWMB_CCR7L                  read_xdata_u8(0xFEFA)
#define PWMB_CCR8                   read_xdata_u16(0xFEFB)
#define PWMB_CCR8H                  read_xdata_u8(0xFEFB)
#define PWMB_CCR8L                  read_xdata_u8(0xFEFC)
#define PWMB_BKR                    read_xdata_u8(0xFEFD)
#define PWMB_DTR                    read_xdata_u8(0xFEFE)
#define PWMB_OISR                   read_xdata_u8(0xFEFF)
/*----------------------------------FF00H~FE37H----------------------------------*/
#define PWM_P0_C                    read_xdata_u16(0xFF00)
#define PWM_P0_CH                   read_xdata_u8(0xFF00)
#define PWM_P0_CL                   read_xdata_u8(0xFF01)
#define PWM_P0_CKS                  read_xdata_u8(0xFF02)
#define PWM_P0_TADC                 read_xdata_u16(0xFF03)
#define PWM_P0_TADCH                read_xdata_u8(0xFF03)
#define PWM_P0_TADCL                read_xdata_u8(0xFF04)
#define PWM_P0_IF                   read_xdata_u8(0xFF05)
#define PWM_P0_FDCR                 read_xdata_u8(0xFF06)
#define PWM_P00_T1                  read_xdata_u16(0xFF10)
#define PWM_P00_T1H                 read_xdata_u8(0xFF10)
#define PWM_P00_T1L                 read_xdata_u8(0xFF11)
#define PWM_P00_T2                  read_xdata_u16(0xFF12)
#define PWM_P00_T2H                 read_xdata_u8(0xFF12)
#define PWM_P00_T2L                 read_xdata_u8(0xFF13)
#define PWM_P00_CR                  read_xdata_u8(0xFF14)
#define PWM_P00_HLD                 read_xdata_u8(0xFF15)
#define PWM_P01_T1                  read_xdata_u16(0xFF18)
#define PWM_P01_T1H                 read_xdata_u8(0xFF18)
#define PWM_P01_T1L                 read_xdata_u8(0xFF19)
#define PWM_P01_T2                  read_xdata_u16(0xFF1A)
#define PWM_P01_T2H                 read_xdata_u8(0xFF1A)
#define PWM_P01_T2L                 read_xdata_u8(0xFF1B)
#define PWM_P01_CR                  read_xdata_u8(0xFF1C)
#define PWM_P01_HLD                 read_xdata_u8(0xFF1D)
#define PWM_P02_T1                  read_xdata_u16(0xFF20)
#define PWM_P02_T1H                 read_xdata_u8(0xFF20)
#define PWM_P02_T1L                 read_xdata_u8(0xFF21)
#define PWM_P02_T2                  read_xdata_u16(0xFF22)
#define PWM_P02_T2H                 read_xdata_u8(0xFF22)
#define PWM_P02_T2L                 read_xdata_u8(0xFF23)
#define PWM_P02_CR                  read_xdata_u8(0xFF24)
#define PWM_P02_HLD                 read_xdata_u8(0xFF25)
#define PWM_P03_T1                  read_xdata_u16(0xFF28)
#define PWM_P03_T1H                 read_xdata_u8(0xFF28)
#define PWM_P03_T1L                 read_xdata_u8(0xFF29)
#define PWM_P03_T2                  read_xdata_u16(0xFF2A)
#define PWM_P03_T2H                 read_xdata_u8(0xFF2A)
#define PWM_P03_T2L                 read_xdata_u8(0xFF2B)
#define PWM_P03_CR                  read_xdata_u8(0xFF2C)
#define PWM_P03_HLD                 read_xdata_u8(0xFF2D)
#define PWM_P04_T1                  read_xdata_u16(0xFF30)
#define PWM_P04_T1H                 read_xdata_u8(0xFF30)
#define PWM_P04_T1L                 read_xdata_u8(0xFF31)
#define PWM_P04_T2                  read_xdata_u16(0xFF32)
#define PWM_P04_T2H                 read_xdata_u8(0xFF32)
#define PWM_P04_T2L                 read_xdata_u8(0xFF33)
#define PWM_P04_CR                  read_xdata_u8(0xFF34)
#define PWM_P04_HLD                 read_xdata_u8(0xFF35)
#define PWM_P05_T1                  read_xdata_u16(0xFF38)
#define PWM_P05_T1H                 read_xdata_u8(0xFF38)
#define PWM_P05_T1L                 read_xdata_u8(0xFF39)
#define PWM_P05_T2                  read_xdata_u16(0xFF3A)
#define PWM_P05_T2H                 read_xdata_u8(0xFF3A)
#define PWM_P05_T2L                 read_xdata_u8(0xFF3B)
#define PWM_P05_CR                  read_xdata_u8(0xFF3C)
#define PWM_P05_HLD                 read_xdata_u8(0xFF3D)
#define PWM_P06_T1                  read_xdata_u16(0xFF40)
#define PWM_P06_T1H                 read_xdata_u8(0xFF40)
#define PWM_P06_T1L                 read_xdata_u8(0xFF41)
#define PWM_P06_T2                  read_xdata_u16(0xFF42)
#define PWM_P06_T2H                 read_xdata_u8(0xFF42)
#define PWM_P06_T2L                 read_xdata_u8(0xFF43)
#define PWM_P06_CR                  read_xdata_u8(0xFF44)
#define PWM_P06_HLD                 read_xdata_u8(0xFF45)
#define PWM_P07_T1                  read_xdata_u16(0xFF48)
#define PWM_P07_T1H                 read_xdata_u8(0xFF48)
#define PWM_P07_T1L                 read_xdata_u8(0xFF49)
#define PWM_P07_T2                  read_xdata_u16(0xFF4A)
#define PWM_P07_T2H                 read_xdata_u8(0xFF4A)
#define PWM_P07_T2L                 read_xdata_u8(0xFF4B)
#define PWM_P07_CR                  read_xdata_u8(0xFF4C)
#define PWM_P07_HLD                 read_xdata_u8(0xFF4D)
#define PWM_P1_C                    read_xdata_u16(0xFF50)
#define PWM_P1_CH                   read_xdata_u8(0xFF50)
#define PWM_P1_CL                   read_xdata_u8(0xFF51)
#define PWM_P1_CKS                  read_xdata_u8(0xFF52)
#define PWM_P1_IF                   read_xdata_u8(0xFF55)
#define PWM_P1_FDCR                 read_xdata_u8(0xFF56)
#define PWM_P10_T1                  read_xdata_u16(0xFF60)
#define PWM_P10_T1H                 read_xdata_u8(0xFF60)
#define PWM_P10_T1L                 read_xdata_u8(0xFF61)
#define PWM_P10_T2                  read_xdata_u16(0xFF62)
#define PWM_P10_T2H                 read_xdata_u8(0xFF62)
#define PWM_P10_T2L                 read_xdata_u8(0xFF63)
#define PWM_P10_CR                  read_xdata_u8(0xFF64)
#define PWM_P10_HLD                 read_xdata_u8(0xFF65)
#define PWM_P11_T1                  read_xdata_u16(0xFF68)
#define PWM_P11_T1H                 read_xdata_u8(0xFF68)
#define PWM_P11_T1L                 read_xdata_u8(0xFF69)
#define PWM_P11_T2                  read_xdata_u16(0xFF6A)
#define PWM_P11_T2H                 read_xdata_u8(0xFF6A)
#define PWM_P11_T2L                 read_xdata_u8(0xFF6B)
#define PWM_P11_CR                  read_xdata_u8(0xFF6C)
#define PWM_P11_HLD                 read_xdata_u8(0xFF6D)
#define PWM_P12_T1                  read_xdata_u16(0xFF70)
#define PWM_P12_T1H                 read_xdata_u8(0xFF70)
#define PWM_P12_T1L                 read_xdata_u8(0xFF71)
#define PWM_P12_T2                  read_xdata_u16(0xFF72)
#define PWM_P12_T2H                 read_xdata_u8(0xFF72)
#define PWM_P12_T2L                 read_xdata_u8(0xFF73)
#define PWM_P12_CR                  read_xdata_u8(0xFF74)
#define PWM_P12_HLD                 read_xdata_u8(0xFF75)
#define PWM_P13_T1                  read_xdata_u16(0xFF78)
#define PWM_P13_T1H                 read_xdata_u8(0xFF78)
#define PWM_P13_T1L                 read_xdata_u8(0xFF79)
#define PWM_P13_T2                  read_xdata_u16(0xFF7A)
#define PWM_P13_T2H                 read_xdata_u8(0xFF7A)
#define PWM_P13_T2L                 read_xdata_u8(0xFF7B)
#define PWM_P13_CR                  read_xdata_u8(0xFF7C)
#define PWM_P13_HLD                 read_xdata_u8(0xFF7D)
#define PWM_P14_T1                  read_xdata_u16(0xFF80)
#define PWM_P14_T1H                 read_xdata_u8(0xFF80)
#define PWM_P14_T1L                 read_xdata_u8(0xFF81)
#define PWM_P14_T2                  read_xdata_u16(0xFF82)
#define PWM_P14_T2H                 read_xdata_u8(0xFF82)
#define PWM_P14_T2L                 read_xdata_u8(0xFF83)
#define PWM_P14_CR                  read_xdata_u8(0xFF84)
#define PWM_P14_HLD                 read_xdata_u8(0xFF85)
#define PWM_P15_T1                  read_xdata_u16(0xFF88)
#define PWM_P15_T1H                 read_xdata_u8(0xFF88)
#define PWM_P15_T1L                 read_xdata_u8(0xFF89)
#define PWM_P15_T2                  read_xdata_u16(0xFF8A)
#define PWM_P15_T2H                 read_xdata_u8(0xFF8A)
#define PWM_P15_T2L                 read_xdata_u8(0xFF8B)
#define PWM_P15_CR                  read_xdata_u8(0xFF8C)
#define PWM_P15_HLD                 read_xdata_u8(0xFF8D)
#define PWM_P16_T1                  read_xdata_u16(0xFF90)
#define PWM_P16_T1H                 read_xdata_u8(0xFF90)
#define PWM_P16_T1L                 read_xdata_u8(0xFF91)
#define PWM_P16_T2                  read_xdata_u16(0xFF92)
#define PWM_P16_T2H                 read_xdata_u8(0xFF92)
#define PWM_P16_T2L                 read_xdata_u8(0xFF93)
#define PWM_P16_CR                  read_xdata_u8(0xFF94)
#define PWM_P16_HLD                 read_xdata_u8(0xFF95)
#define PWM_P17_T1                  read_xdata_u16(0xFF98)
#define PWM_P17_T1H                 read_xdata_u8(0xFF98)
#define PWM_P17_T1L                 read_xdata_u8(0xFF99)
#define PWM_P17_T2                  read_xdata_u16(0xFF9A)
#define PWM_P17_T2H                 read_xdata_u8(0xFF9A)
#define PWM_P17_T2L                 read_xdata_u8(0xFF9B)
#define PWM_P17_CR                  read_xdata_u8(0xFF9C)
#define PWM_P17_HLD                 read_xdata_u8(0xFF9D)
#define PWM_P2_C                    read_xdata_u16(0xFFA0)
#define PWM_P2_CH                   read_xdata_u8(0xFFA0)
#define PWM_P2_CL                   read_xdata_u8(0xFFA1)
#define PWM_P2_CKS                  read_xdata_u8(0xFFA2)
#define PWM_P2_TADC                 read_xdata_u16(0xFFA3)
#define PWM_P2_TADCH                read_xdata_u8(0xFFA3)
#define PWM_P2_TADCL                read_xdata_u8(0xFFA4)
#define PWM_P2_IF                   read_xdata_u8(0xFFA5)
#define PWM_P2_FDCR                 read_xdata_u8(0xFFA6)
#define PWM_P20_T1                  read_xdata_u16(0xFFB0)
#define PWM_P20_T1H                 read_xdata_u8(0xFFB0)
#define PWM_P20_T1L                 read_xdata_u8(0xFFB1)
#define PWM_P20_T2                  read_xdata_u16(0xFFB2)
#define PWM_P20_T2H                 read_xdata_u8(0xFFB2)
#define PWM_P20_T2L                 read_xdata_u8(0xFFB3)
#define PWM_P20_CR                  read_xdata_u8(0xFFB4)
#define PWM_P20_HLD                 read_xdata_u8(0xFFB5)
#define PWM_P21_T1                  read_xdata_u16(0xFFB8)
#define PWM_P21_T1H                 read_xdata_u8(0xFFB8)
#define PWM_P21_T1L                 read_xdata_u8(0xFFB9)
#define PWM_P21_T2                  read_xdata_u16(0xFFBA)
#define PWM_P21_T2H                 read_xdata_u8(0xFFBA)
#define PWM_P21_T2L                 read_xdata_u8(0xFFBB)
#define PWM_P21_CR                  read_xdata_u8(0xFFBC)
#define PWM_P21_HLD                 read_xdata_u8(0xFFBD)
#define PWM_P22_T1                  read_xdata_u16(0xFFC0)
#define PWM_P22_T1H                 read_xdata_u8(0xFFC0)
#define PWM_P22_T1L                 read_xdata_u8(0xFFC1)
#define PWM_P22_T2                  read_xdata_u16(0xFFC2)
#define PWM_P22_T2H                 read_xdata_u8(0xFFC2)
#define PWM_P22_T2L                 read_xdata_u8(0xFFC3)
#define PWM_P22_CR                  read_xdata_u8(0xFFC4)
#define PWM_P22_HLD                 read_xdata_u8(0xFFC5)
#define PWM_P23_T1                  read_xdata_u16(0xFFC8)
#define PWM_P23_T1H                 read_xdata_u8(0xFFC8)
#define PWM_P23_T1L                 read_xdata_u8(0xFFC9)
#define PWM_P23_T2                  read_xdata_u16(0xFFCA)
#define PWM_P23_T2H                 read_xdata_u8(0xFFCA)
#define PWM_P23_T2L                 read_xdata_u8(0xFFCB)
#define PWM_P23_CR                  read_xdata_u8(0xFFCC)
#define PWM_P23_HLD                 read_xdata_u8(0xFFCD)
#define PWM_P24_T1                  read_xdata_u16(0xFFD0)
#define PWM_P24_T1H                 read_xdata_u8(0xFFD0)
#define PWM_P24_T1L                 read_xdata_u8(0xFFD1)
#define PWM_P24_T2                  read_xdata_u16(0xFFD2)
#define PWM_P24_T2H                 read_xdata_u8(0xFFD2)
#define PWM_P24_T2L                 read_xdata_u8(0xFFD3)
#define PWM_P24_CR                  read_xdata_u8(0xFFD4)
#define PWM_P24_HLD                 read_xdata_u8(0xFFD5)
#define PWM_P25_T1                  read_xdata_u16(0xFFD8)
#define PWM_P25_T1H                 read_xdata_u8(0xFFD8)
#define PWM_P25_T1L                 read_xdata_u8(0xFFD9)
#define PWM_P25_T2                  read_xdata_u16(0xFFDA)
#define PWM_P25_T2H                 read_xdata_u8(0xFFDA)
#define PWM_P25_T2L                 read_xdata_u8(0xFFDB)
#define PWM_P25_CR                  read_xdata_u8(0xFFDC)
#define PWM_P25_HLD                 read_xdata_u8(0xFFDD)
#define PWM_P26_T1                  read_xdata_u16(0xFFE0)
#define PWM_P26_T1H                 read_xdata_u8(0xFFE0)
#define PWM_P26_T1L                 read_xdata_u8(0xFFE1)
#define PWM_P26_T2                  read_xdata_u16(0xFFE2)
#define PWM_P26_T2H                 read_xdata_u8(0xFFE2)
#define PWM_P26_T2L                 read_xdata_u8(0xFFE3)
#define PWM_P26_CR                  read_xdata_u8(0xFFE4)
#define PWM_P26_HLD                 read_xdata_u8(0xFFE5)
#define PWM_P27_T1                  read_xdata_u16(0xFFE8)
#define PWM_P27_T1H                 read_xdata_u8(0xFFE8)
#define PWM_P27_T1L                 read_xdata_u8(0xFFE9)
#define PWM_P27_T2                  read_xdata_u16(0xFFEA)
#define PWM_P27_T2H                 read_xdata_u8(0xFFEA)
#define PWM_P27_T2L                 read_xdata_u8(0xFFEB)
#define PWM_P27_CR                  read_xdata_u8(0xFFEC)
#define PWM_P27_HLD                 read_xdata_u8(0xFFED)
#if     (ECBM_MCU==0x2815C4)        //STC8A8K64D4
#define PWM_C                       read_xdata_u16(0xFF00)
#define PWM_CH                      read_xdata_u8(0xFF00)
#define PWM_CL                      read_xdata_u8(0xFF01)
#define PWM_CKS                     read_xdata_u8(0xFF02)
#define PWM_TADC                    read_xdata_u16(0xFF03)
#define PWM_TADCH                   read_xdata_u8(0xFF03)
#define PWM_TADCL                   read_xdata_u8(0xFF04)
#define PWM_IF                      read_xdata_u8(0xFF05)
#define PWM_FDCR                    read_xdata_u8(0xFF06)
#define PWM_DELSEL                  read_xdata_u8(0xFF07)
#define PWM_CH0_T1                  read_xdata_u16(0xFF10)
#define PWM_CH0_T1H                 read_xdata_u8(0xFF10)
#define PWM_CH0_T1L                 read_xdata_u8(0xFF11)
#define PWM_CH0_T2                  read_xdata_u16(0xFF12)
#define PWM_CH0_T2H                 read_xdata_u8(0xFF12)
#define PWM_CH0_T2L                 read_xdata_u8(0xFF13)
#define PWM_CH0_CR                  read_xdata_u8(0xFF14)
#define PWM_CH0_HLD                 read_xdata_u8(0xFF15)
#define PWM_CH1_T1                  read_xdata_u16(0xFF18)
#define PWM_CH1_T1H                 read_xdata_u8(0xFF18)
#define PWM_CH1_T1L                 read_xdata_u8(0xFF19)
#define PWM_CH1_T2                  read_xdata_u16(0xFF1A)
#define PWM_CH1_T2H                 read_xdata_u8(0xFF1A)
#define PWM_CH1_T2L                 read_xdata_u8(0xFF1B)
#define PWM_CH1_CR                  read_xdata_u8(0xFF1C)
#define PWM_CH1_HLD                 read_xdata_u8(0xFF1D)
#define PWM_CH2_T1                  read_xdata_u16(0xFF20)
#define PWM_CH2_T1H                 read_xdata_u8(0xFF20)
#define PWM_CH2_T1L                 read_xdata_u8(0xFF21)
#define PWM_CH2_T2                  read_xdata_u16(0xFF22)
#define PWM_CH2_T2H                 read_xdata_u8(0xFF22)
#define PWM_CH2_T2L                 read_xdata_u8(0xFF23)
#define PWM_CH2_CR                  read_xdata_u8(0xFF24)
#define PWM_CH2_HLD                 read_xdata_u8(0xFF25)
#define PWM_CH3_T1                  read_xdata_u16(0xFF28)
#define PWM_CH3_T1H                 read_xdata_u8(0xFF28)
#define PWM_CH3_T1L                 read_xdata_u8(0xFF29)
#define PWM_CH3_T2                  read_xdata_u16(0xFF2A)
#define PWM_CH3_T2H                 read_xdata_u8(0xFF2A)
#define PWM_CH3_T2L                 read_xdata_u8(0xFF2B)
#define PWM_CH3_CR                  read_xdata_u8(0xFF2C)
#define PWM_CH3_HLD                 read_xdata_u8(0xFF2D)
#define PWM_CH4_T1                  read_xdata_u16(0xFF30)
#define PWM_CH4_T1H                 read_xdata_u8(0xFF30)
#define PWM_CH4_T1L                 read_xdata_u8(0xFF31)
#define PWM_CH4_T2                  read_xdata_u16(0xFF32)
#define PWM_CH4_T2H                 read_xdata_u8(0xFF32)
#define PWM_CH4_T2L                 read_xdata_u8(0xFF33)
#define PWM_CH4_CR                  read_xdata_u8(0xFF34)
#define PWM_CH4_HLD                 read_xdata_u8(0xFF35)
#define PWM_CH5_T1                  read_xdata_u16(0xFF38)
#define PWM_CH5_T1H                 read_xdata_u8(0xFF38)
#define PWM_CH5_T1L                 read_xdata_u8(0xFF39)
#define PWM_CH5_T2                  read_xdata_u16(0xFF3A)
#define PWM_CH5_T2H                 read_xdata_u8(0xFF3A)
#define PWM_CH5_T2L                 read_xdata_u8(0xFF3B)
#define PWM_CH5_CR                  read_xdata_u8(0xFF3C)
#define PWM_CH5_HLD                 read_xdata_u8(0xFF3D)
#define PWM_CH6_T1                  read_xdata_u16(0xFF40)
#define PWM_CH6_T1H                 read_xdata_u8(0xFF40)
#define PWM_CH6_T1L                 read_xdata_u8(0xFF41)
#define PWM_CH6_T2                  read_xdata_u16(0xFF42)
#define PWM_CH6_T2H                 read_xdata_u8(0xFF42)
#define PWM_CH6_T2L                 read_xdata_u8(0xFF43)
#define PWM_CH6_CR                  read_xdata_u8(0xFF44)
#define PWM_CH6_HLD                 read_xdata_u8(0xFF45)
#define PWM_CH7_T1                  read_xdata_u16(0xFF48)
#define PWM_CH7_T1H                 read_xdata_u8(0xFF48)
#define PWM_CH7_T1L                 read_xdata_u8(0xFF49)
#define PWM_CH7_T2                  read_xdata_u16(0xFF4A)
#define PWM_CH7_T2H                 read_xdata_u8(0xFF4A)
#define PWM_CH7_T2L                 read_xdata_u8(0xFF4B)
#define PWM_CH7_CR                  read_xdata_u8(0xFF4C)
#define PWM_CH7_HLD                 read_xdata_u8(0xFF4D)
#endif
#if     ((ECBM_MCU&0xF0F000)==0x200000)   //除STC8A8K64D4以外的STC8A
#define PWM_C                       read_xdata_u16(0xFFF0)
#define PWM_CH                      read_xdata_u8(0xFFF0)
#define PWM_CL                      read_xdata_u8(0xFFF1)
#define PWM_CKS                     read_xdata_u8(0xFFF2)
#define PWM_TADCP                   read_xdata_u8(0xFFF3)
#define PWM_TADCPH                  read_xdata_u8(0xFFF3)
#define PWM_TADCPL                  read_xdata_u8(0xFFF4)
#define PWM_CH0_T1                  read_xdata_u16(0xFF00)
#define PWM_CH0_T1H                 read_xdata_u8(0xFF00)
#define PWM_CH0_T1L                 read_xdata_u8(0xFF01)
#define PWM_CH0_T2                  read_xdata_u16(0xFF02)
#define PWM_CH0_T2H                 read_xdata_u8(0xFF02)
#define PWM_CH0_T2L                 read_xdata_u8(0xFF03)
#define PWM_CH0_CR                  read_xdata_u8(0xFF04)
#define PWM_CH0_HLD                 read_xdata_u8(0xFF05)
#define PWM_CH1_T1                  read_xdata_u16(0xFF10)
#define PWM_CH1_T1H                 read_xdata_u8(0xFF10)
#define PWM_CH1_T1L                 read_xdata_u8(0xFF11)
#define PWM_CH1_T2                  read_xdata_u16(0xFF12)
#define PWM_CH1_T2H                 read_xdata_u8(0xFF12)
#define PWM_CH1_T2L                 read_xdata_u8(0xFF13)
#define PWM_CH1_CR                  read_xdata_u8(0xFF14)
#define PWM_CH1_HLD                 read_xdata_u8(0xFF15)
#define PWM_CH2_T1                  read_xdata_u16(0xFF20)
#define PWM_CH2_T1H                 read_xdata_u8(0xFF20)
#define PWM_CH2_T1L                 read_xdata_u8(0xFF21)
#define PWM_CH2_T2                  read_xdata_u16(0xFF22)
#define PWM_CH2_T2H                 read_xdata_u8(0xFF22)
#define PWM_CH2_T2L                 read_xdata_u8(0xFF23)
#define PWM_CH2_CR                  read_xdata_u8(0xFF24)
#define PWM_CH2_HLD                 read_xdata_u8(0xFF25)
#define PWM_CH3_T1                  read_xdata_u16(0xFF30)
#define PWM_CH3_T1H                 read_xdata_u8(0xFF30)
#define PWM_CH3_T1L                 read_xdata_u8(0xFF31)
#define PWM_CH3_T2                  read_xdata_u16(0xFF32)
#define PWM_CH3_T2H                 read_xdata_u8(0xFF32)
#define PWM_CH3_T2L                 read_xdata_u8(0xFF33)
#define PWM_CH3_CR                  read_xdata_u8(0xFF34)
#define PWM_CH3_HLD                 read_xdata_u8(0xFF35)
#define PWM_CH4_T1                  read_xdata_u16(0xFF40)
#define PWM_CH4_T1H                 read_xdata_u8(0xFF40)
#define PWM_CH4_T1L                 read_xdata_u8(0xFF41)
#define PWM_CH4_T2                  read_xdata_u16(0xFF42)
#define PWM_CH4_T2H                 read_xdata_u8(0xFF42)
#define PWM_CH4_T2L                 read_xdata_u8(0xFF43)
#define PWM_CH4_CR                  read_xdata_u8(0xFF44)
#define PWM_CH4_HLD                 read_xdata_u8(0xFF45)
#define PWM_CH5_T1                  read_xdata_u16(0xFF50)
#define PWM_CH5_T1H                 read_xdata_u8(0xFF50)
#define PWM_CH5_T1L                 read_xdata_u8(0xFF51)
#define PWM_CH5_T2                  read_xdata_u16(0xFF52)
#define PWM_CH5_T2H                 read_xdata_u8(0xFF52)
#define PWM_CH5_T2L                 read_xdata_u8(0xFF53)
#define PWM_CH5_CR                  read_xdata_u8(0xFF54)
#define PWM_CH5_HLD                 read_xdata_u8(0xFF55)
#define PWM_CH6_T1                  read_xdata_u16(0xFF60)
#define PWM_CH6_T1H                 read_xdata_u8(0xFF60)
#define PWM_CH6_T1L                 read_xdata_u8(0xFF61)
#define PWM_CH6_T2                  read_xdata_u16(0xFF62)
#define PWM_CH6_T2H                 read_xdata_u8(0xFF62)
#define PWM_CH6_T2L                 read_xdata_u8(0xFF63)
#define PWM_CH6_CR                  read_xdata_u8(0xFF64)
#define PWM_CH6_HLD                 read_xdata_u8(0xFF65)
#define PWM_CH7_T1                  read_xdata_u16(0xFF70)
#define PWM_CH7_T1H                 read_xdata_u8(0xFF70)
#define PWM_CH7_T1L                 read_xdata_u8(0xFF71)
#define PWM_CH7_T2                  read_xdata_u16(0xFF72)
#define PWM_CH7_T2H                 read_xdata_u8(0xFF72)
#define PWM_CH7_T2L                 read_xdata_u8(0xFF73)
#define PWM_CH7_CR                  read_xdata_u8(0xFF74)
#define PWM_CH7_HLD                 read_xdata_u8(0xFF75)
#endif
#endif
//以下是寄存器位定义和功能实现指令。
/*-------------------------------看门狗特殊功能寄存器-----------------------------*/
#define WDT_FLAG                    0x80//看门狗溢出标志位
#define EN_WDT                      0x20//看门狗使能位
#define CLR_WDT                     0x10//看门狗定时器清零
#define IDL_WDT                     0x08//看门狗在空闲模式下的控制位
//-------------功能指令------------//
#define WDT_POWER_ON                REG_SET_BIT(WDT_CONTR,EN_WDT)   //打开看门狗
#define WDT_CLR                     REG_SET_BIT(WDT_CONTR,CLR_WDT)  //喂狗
#define WDT_SET_IDLE_ENABLE         REG_SET_BIT(WDT_CONTR,IDL_WDT)  //看门狗在空闲模式下继续计数
#define WDT_SET_IDLE_DISABLE        REG_RESET_BIT(WDT_CONTR,IDL_WDT)//看门狗在空闲模式下停止计数
#define WDT_SET_SCALE(value)        REG_IN_MASK(WDT_CONTR,0x07,value)//设置看门狗的预分频系数
#define WDT_GET_FLAG                (WDT_CONTR & WDT_FLAG)           //获取看门狗溢出标志位
//-------------寄存器读取----------//
#define WDT_SET_REG_CONTR(value)    do{WDT_CONTR=(u8)(value);}while(0)//设置WDT_CONTR寄存器
#define WDT_GET_REG_CONTR           (WDT_CONTR)                      //获取WDT_CONTR寄存器的值
/*------------------------------------外部中断0----------------------------------*/
sbit    EX0                         =IE^0;  //外部中断0允许位
sbit    IT0                         =TCON^0;//外部中断0触发控制位
sbit    IE0                         =TCON^1;//外部中断0中断请求标志位
sbit    PX0                         =IP^0;  //外部中断0中断优先级控制位（低）
#define PX0H                        0x01    //外部中断0中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI0_ENABLE                do{EX0=1;}while(0)//打开外部中断0
#define EXTI0_DISABLE               do{EX0=0;}while(0)//关闭外部中断0
#define EXTI0_SET_MODE_UP_DOWN      do{IT0=0;}while(0)//外部中断0通过上升沿和下降沿触发
#define EXTI0_SET_MODE_DOWN         do{IT0=1;}while(0)//外部中断0通过下降沿触发
#define EXTI0_SET_IT_FLAG           do{IE0=1;}while(0)//置位外部中断0中断请求标志位
#define EXTI0_CLS_IT_FLAG           do{IE0=0;}while(0)//清除外部中断0中断请求标志位
#define EXTI0_GET_IT_FLAG           (IE0)             //获取外部中断0中断请求标志位
#define EXTI0_SET_IO_HIGH           do{P32=1;}while(0)//设置IO的默认电平为高电平
#define EXTI0_GET_IO                (P32)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define EXTI0_SET_IT_PRIORITY_0     do{IPH&=~PX0H;PX0=0;}while(0)//设置外部中断0的优先级为0
#define EXTI0_SET_IT_PRIORITY_1     do{IPH&=~PX0H;PX0=1;}while(0)//设置外部中断0的优先级为1
#define EXTI0_SET_IT_PRIORITY_2     do{IPH|= PX0H;PX0=0;}while(0)//设置外部中断0的优先级为2
#define EXTI0_SET_IT_PRIORITY_3     do{IPH|= PX0H;PX0=1;}while(0)//设置外部中断0的优先级为3
//-------------功能定义------------//
#define EXTI0_IT_NUM                interrupt 0//外部中断0中断号
/*------------------------------------外部中断1----------------------------------*/
sbit    EX1                         =IE^2;  //外部中断1允许位
sbit    IT1                         =TCON^2;//外部中断1触发控制位
sbit    IE1                         =TCON^3;//外部中断1中断请求标志位
sbit    PX1                         =IP^2;  //外部中断1中断优先级控制位（低）
#define PX1H                        0x04    //外部中断1中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI1_ENABLE                do{EX1=1;}while(0)//打开外部中断1
#define EXTI1_DISABLE               do{EX1=0;}while(0)//关闭外部中断1
#define EXTI1_SET_MODE_UP_DOWN      do{IT1=0;}while(0)//外部中断1通过上升沿和下降沿触发
#define EXTI1_SET_MODE_DOWN         do{IT1=1;}while(0)//外部中断1通过下降沿触发
#define EXTI1_SET_IT_FLAG           do{IE1=1;}while(0)//置位外部中断1中断请求标志位
#define EXTI1_CLS_IT_FLAG           do{IE1=0;}while(0)//清除外部中断1中断请求标志位
#define EXTI1_GET_IT_FLAG           (IE1)             //获取外部中断1中断请求标志位
#define EXTI1_SET_IO_HIGH           do{P33=1;}while(0)//设置IO的默认电平为高电平
#define EXTI1_GET_IO                (P33)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define EXTI1_SET_IT_PRIORITY_0     do{IPH&=~PX1H;PX1=0;}while(0)//设置外部中断1的优先级为0
#define EXTI1_SET_IT_PRIORITY_1     do{IPH&=~PX1H;PX1=1;}while(0)//设置外部中断1的优先级为1
#define EXTI1_SET_IT_PRIORITY_2     do{IPH|= PX1H;PX1=0;}while(0)//设置外部中断1的优先级为2
#define EXTI1_SET_IT_PRIORITY_3     do{IPH|= PX1H;PX1=1;}while(0)//设置外部中断1的优先级为3
//-------------功能定义------------//
#define EXTI1_IT_NUM                interrupt 2//外部中断1中断号
/*------------------------------------外部中断2----------------------------------*/
#define EX2                         0x10//外部中断2中断允许位
#define INT2IF                      0x10//外部中断2的中断请求标志位
//-------------功能指令------------//
#define EXTI2_ENABLE                REG_SET_BIT(INTCLKO,EX2)    //打开外部中断2
#define EXTI2_DISABLE               REG_RESET_BIT(INTCLKO,EX2)  //关闭外部中断2
#define EXTI2_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT2IF)//置位外部中断2中断请求标志位
#define EXTI2_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT2IF)//清除外部中断2中断请求标志位
#define EXTI2_GET_IT_FLAG           (AUXINTIF & INT2IF)           //获取外部中断2中断请求标志位
#define EXTI2_SET_IO_HIGH           do{P36=1;}while(0)//设置IO的默认电平为高电平
#define EXTI2_GET_IO                (P36) 
//-------------功能定义------------//
#define EXTI2_IT_NUM                interrupt 10//外部中断2中断号
/*------------------------------------外部中断3----------------------------------*/
#define EX3                         0x20//外部中断3中断允许位
#define INT3IF                      0x20//外部中断3的中断标志位
//-------------功能指令------------//
#define EXTI3_ENABLE                REG_SET_BIT(INTCLKO,EX3)    //打开外部中断3
#define EXTI3_DISABLE               REG_RESET_BIT(INTCLKO,EX3)  //关闭外部中断3
#define EXTI3_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT3IF)//置位外部中断3中断请求标志位
#define EXTI3_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT3IF)//清除外部中断3中断请求标志位
#define EXTI3_GET_IT_FLAG           (AUXINTIF & INT3IF)           //获取外部中断3中断请求标志位
#define EXTI3_SET_IO_HIGH           do{P37=1;}while(0)//设置IO的默认电平为高电平
#define EXTI3_GET_IO                (P37) 
//-------------功能定义------------//
#define EXTI3_IT_NUM                interrupt 11//外部中断3中断号
/*------------------------------------外部中断4----------------------------------*/
#define EX4                         0x40//外部中断4中断允许位
#define INT4IF                      0x40//外部中断4的中断标志位
#define PX4                         0x10//外部中断4中断优先级控制位（低）
#define PX4H                        0x10//外部中断4中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI4_ENABLE                REG_SET_BIT(INTCLKO,EX4)    //打开外部中断4
#define EXTI4_DISABLE               REG_RESET_BIT(INTCLKO,EX4)  //关闭外部中断4
#define EXTI4_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT4IF)//置位外部中断4中断请求标志位
#define EXTI4_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT4IF)//清除外部中断4中断请求标志位
#define EXTI4_GET_IT_FLAG           (AUXINTIF & INT4IF)           //获取外部中断4中断请求标志位
#define EXTI4_SET_IO_HIGH           do{P30=1;}while(0)//设置IO的默认电平为高电平
#define EXTI4_GET_IO                P30 
#define EXTI4_SET_IT_PRIORITY_0     do{IP2H&=~PX4H;IP2&=~PX4;}while(0)//设置外部中断4的优先级为0
#define EXTI4_SET_IT_PRIORITY_1     do{IP2H&=~PX4H;IP2|= PX4;}while(0)//设置外部中断4的优先级为1
#define EXTI4_SET_IT_PRIORITY_2     do{IP2H|= PX4H;IP2&=~PX4;}while(0)//设置外部中断4的优先级为2
#define EXTI4_SET_IT_PRIORITY_3     do{IP2H|= PX4H;IP2|= PX4;}while(0)//设置外部中断4的优先级为3
//-------------功能定义------------//
#define EXTI4_IT_NUM                interrupt 16//外部中断4中断号
/*------------------------------IAP/ISP特殊功能寄存器-----------------------------*/
#define IAP_IDL                     0x00//EEPROM空闲指令
#define IAP_READ                    0x01//EEPROM读指令
#define IAP_WRITE                   0x02//EEPROM写指令
#define IAP_ERASE                   0x03//EEPROM清除指令
#define IAP_EN                      0x80//EEPROM操作使能控制位
#define IAP_FAIL                    0x10//EEPROM操作失败状态位
//-------------功能指令------------//
#define IAP_POWER_ON                REG_SET_BIT(IAP_CONTR,IAP_EN)  //打开IAP功能
#define IAP_POWER_OFF               REG_RESET_BIT(IAP_CONTR,IAP_EN)//关闭IAP功能
#define IAP_CMD_NOP                 do{IAP_CMD=IAP_IDL;   }while(0)//空操作
#define IAP_CMD_READ                do{IAP_CMD=IAP_READ;  }while(0)//读一个字节
#define IAP_CMD_WRITE               do{IAP_CMD=IAP_WRITE; }while(0)//写一个字节
#define IAP_CMD_ERASE               do{IAP_CMD=IAP_ERASE; }while(0)//擦除一个扇区
#define IAP_TRIG_ON                 do{IAP_TRIG=0x5A;IAP_TRIG=0xA5;}while(0)//触发一次EEPROM操作
#define IAP_TRIG_CLS                do{IAP_TRIG=0;}while(0)//清空触发寄存器
#define IAP_GET_FAIL                (IAP_CONTR & IAP_FAIL)
//-------------寄存器读取----------//
#define IAP_SET_REG_DATA(value)     do{IAP_DATA=(u8)(value);}while(0)//写一个数据到IAP_DATA
#define IAP_GET_REG_DATA            (IAP_DATA)//从IAP_DATA读一个数据
#define IAP_SET_REG_ADDR_HL(value)  do{IAP_ADDRL=(u8)(value);IAP_ADDRH=(u8)(value>>8);}while(0)//写一个地址到IAP_ADDRH和IAP_ADDRL中
#define IAP_GET_REG_ADDR_HL         ((((u16)IAP_ADDRH)<<8)|(u16)IAP_ADDRL)//读一个地址IAP_ADDR
#define IAP_SET_REG_ADDR_H8(value)  do{IAP_ADDRH=(u8)(value);}while(0)//写一个地址到IAP_ADDRH中
#define IAP_GET_REG_ADDR_H8         (IAP_ADDRH)//读IAP_ADDRH
#define IAP_SET_REG_ADDR_L8(value)  do{IAP_ADDRL=(u8)(value);}while(0)//写一个地址到IAP_ADDRL中
#define IAP_GET_REG_ADDR_L8         (IAP_ADDRL)//读IAP_ADDRL
#define IAP_SET_REG_CONTR(value)    do{IAP_CONTR=(u8)(value);}while(0)//写入一个数据到IAP_CONTR寄存器
#define IAP_GET_REG_CONTR           (IAP_CONTR)//读取IAP_CONTR寄存器
#define IAP_SET_REG_TPS(value)      do{IAP_TPS=(u8)(value);}while(0)//写一个数据到IAP_TPS寄存器
#define IAP_GET_REG_TPS             (IAP_TPS)//读IAP_TPS寄存器
/*--------------------------------SPI特殊功能寄存器-------------------------------*/
#define SPIF                        0x80//SPI中断标志位
#define WCOL                        0x40//SPI写冲突标志位
#define SSIG                        0x80//SPI的SS引脚功能控制位
#define SPEN                        0x40//SPI使能控制位
#define DORD                        0x20//SPI数据位发送/接收顺序位
#define MSTR                        0x10//SPI主/从模式选择位
#define CPOL                        0x08//SPI时钟极性控制
#define CPHA                        0x04//SPI时钟相位控制
#define ESPI                        0x02//SPI中断允许位
#define PSPIH                       0x02//SPI中断优先级（高位）
#define PSPI                        0x02//SPI中断优先级（低位）
//-------------功能指令------------//
#define SPI_POWER_ON                REG_SET_BIT(SPCTL,SPEN)  //打开SPI
#define SPI_POWER_OFF               REG_RESET_BIT(SPCTL,SPEN)//关闭SPI
#define SPI_SET_CS_ENABLE           REG_RESET_BIT(SPCTL,SSIG)//打开CS脚的使能
#define SPI_SET_CS_DISABLE          REG_SET_BIT(SPCTL,SSIG)  //关闭CS脚的使能
#define SPI_SET_DATA_MSB            REG_RESET_BIT(SPCTL,DORD)//设置先发/收数据的高位
#define SPI_SET_DATA_LSB            REG_SET_BIT(SPCTL,DORD)  //设置先发/收数据的低位
#define SPI_SET_MODE_MASTER         REG_SET_BIT(SPCTL,MSTR)  //设置SPI为主机模式
#define SPI_SET_MODE_SLAVE          REG_RESET_BIT(SPCTL,MSTR)//设置SPI为从机模式
#define SPI_SET_CPOL_1              REG_SET_BIT(SPCTL,CPOL)  //设置CPOL位为1
#define SPI_SET_CPOL_0              REG_RESET_BIT(SPCTL,CPOL)//设置CPOL位为0
#define SPI_SET_CPHA_1              REG_SET_BIT(SPCTL,CPHA)  //设置CPHA位为1
#define SPI_SET_CPHA_0              REG_RESET_BIT(SPCTL,CPHA)//设置CPHA位为0
#define SPI_SET_PIN(value)          REG_IN_MASK(P_SW1,0x0C,value)//设置串口1的输出引脚
#define SPI_CLS_IT_FLAG             REG_SET_BIT(SPSTAT,(SPIF|WCOL)) //清SPI中断标志位和冲突标志位
#define SPI_GET_IT_FLAG             (SPSTAT & SPIF)                 //获取SPI中断标志位
#define SPI_CLS_WCOL_FLAG           REG_SET_BIT(SPSTAT,WCOL) //清SPI写冲突标志位
#define SPI_GET_WCOL_FLAG           (SPSTAT & WCOL)          //获取SPI写冲突标志位
#define SPI_IT_ENABLE               REG_SET_BIT(IE2,ESPI)    //开SPI中断
#define SPI_IT_DISABLE              REG_RESET_BIT(IE2,ESPI)  //关SPI中断
#define SPI_SET_SPR(value)          REG_IN_MASK(SPCTL,0x03,value)//设置SPI时钟分频
#define SPI_GET_SPR                 (SPCTL & 0x03)           //读取SPI时钟分频
#define SPI_SET_IT_PRIORITY_0       do{IP2H&=~PSPIH;IP2&=~PSPI;}while(0)//设置SPI的中断优先级为0
#define SPI_SET_IT_PRIORITY_1       do{IP2H&=~PSPIH;IP2|= PSPI;}while(0)//设置SPI的中断优先级为1
#define SPI_SET_IT_PRIORITY_2       do{IP2H|= PSPIH;IP2&=~PSPI;}while(0)//设置SPI的中断优先级为2
#define SPI_SET_IT_PRIORITY_3       do{IP2H|= PSPIH;IP2|= PSPI;}while(0)//设置SPI的中断优先级为3
//-------------寄存器读取----------//
#define SPI_SET_REG_SPSTAT(value)   do{SPSTAT=(u8)(value);}while(0)//写一个数据到SPCTL寄存器
#define SPI_GET_REG_SPSTAT          (SPSTAT)//获取SPCTL寄存器的值
#define SPI_SET_REG_SPCTL(value)    do{SPCTL=(u8)(value);}while(0)//写一个数据到SPCTL寄存器
#define SPI_GET_REG_SPCTL           (SPCTL) //获取SPCTL寄存器的值
#define SPI_SET_REG_SPDAT(value)    do{SPDAT=(u8)(value);}while(0)//写一个数据到SPDAT寄存器
#define SPI_GET_REG_SPDAT           (SPDAT) //获取SPDAT寄存器的值
//-------------功能定义------------//
#define SPI_IT_NUM                  interrupt 9//SPI的中断号
/*-------------------------------比较器特殊功能寄存器-----------------------------*/
#define CMPEN                       0x80//比较器使能位
#define CMPIF                       0x40//比较器中断标志位
#define PIE                         0x20//比较器上升沿中断使能位
#define NIE                         0x10//比较器下降沿中断使能位
#define PIS                         0x08//比较器正极选择位
#define NIS                         0x04//比较器负极选择位
#define CMPOE                       0x02//比较器结果输出控制位
#define CMPRES                      0x01//比较器结果
#define INVCMPO                     0x80//比较器结果输出控制
#define DISFLT                      0x40//比较器模拟滤波功能控制
#define PCMP                        0x20//比较器中断优先级控制位（低）
#define PCMPH                       0x20//比较器中断优先级控制位（高）
//-------------功能指令------------//
#define CMP_POWER_ON                do{CMPCR1|= CMPEN;}while(0)//开启比较器
#define CMP_POWER_OFF               do{CMPCR1&=~CMPEN;}while(0)//关闭比较器
#define CMP_IT_CLS                  do{CMPCR1&=~CMPIF;}while(0)//清除比较器中断标志位
#define CMP_IT_POSITIVE_ENABLE      do{CMPCR1|= PIE;  }while(0)//开启上升沿中断
#define CMP_IT_POSITIVE_DISABLE     do{CMPCR1&=~PIE;  }while(0)//关闭上升沿中断
#define CMP_IT_NEGATIVE_ENABLE      do{CMPCR1|= NIE;  }while(0)//开启上升沿中断
#define CMP_IT_NEGATIVE_DISABLE     do{CMPCR1&=~NIE;  }while(0)//关闭上升沿中断
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_POSITIVE_ADC        REG_IN_MASK(CMPEXCFG,0x03,0x03)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P51        REG_IN_MASK(CMPEXCFG,0x03,0x02)//比较器的+端为P3.7脚
#define CMP_SET_POSITIVE_A50        REG_IN_MASK(CMPEXCFG,0x03,0x01)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P37        REG_IN_MASK(CMPEXCFG,0x03,0x00)//比较器的+端为P3.7脚
#else
#define CMP_SET_POSITIVE_ADC        do{CMPCR1|= PIS;  }while(0)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P37        do{CMPCR1&=~PIS;  }while(0)//比较器的+端为P3.7脚
#endif
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_NEGATIVE_P36        do{CMPEXCFG&=~NIS;}while(0)//比较器的-端为P3.6脚
#define CMP_SET_NEGATIVE_BGV        do{CMPEXCFG|= NIS;}while(0)//比较器的-端为内部1.9V电压
#else
#define CMP_SET_NEGATIVE_P36        do{CMPCR1|= NIS;  }while(0)//比较器的-端为P3.6脚
#define CMP_SET_NEGATIVE_BGV        do{CMPCR1&=~NIS;  }while(0)//比较器的-端为内部1.9V电压
#endif
#define CMP_SET_OUT_ENABLE          do{CMPCR1|= CMPOE;}while(0)//开启比较器结果输出
#define CMP_SET_OUT_DISABLE         do{CMPCR1&=~CMPOE;}while(0)//关闭比较器结果输出
#define CMP_GET_RESULT              (CMPCR1 & CMPRES)//获取比较器结果
#define CMP_SET_OUT_NEGATIVE        do{CMPCR2|= INVCMPO;}while(0)//比较器结果反向输出
#define CMP_SET_OUT_POSITIVE        do{CMPCR2&=~INVCMPO;}while(0)//比较器结果正向输出
#define CMP_SET_ANALOG_FILTER_ENABLE    do{CMPCR2&=~DISFLT;}while(0)//开启比较器模拟滤波
#define CMP_SET_ANALOG_FILTER_DISABLE   do{CMPCR2|= DISFLT;}while(0)//关闭比较器模拟滤波
#define CMP_SET_DIGITAL_FILTER(value)   REG_IN_MASK(CMPCR2,0x3F,value)//设置比较器数字滤波
#define CMP_SET_OUT_PIN(value)      REG_IN_MASK(P_SW2,0x08,value)     //设置比较器的输出引脚
#define CMP_SET_IT_PRIORITY_0       do{IP2H&=~PCMPH;IP2&=~PCMP;}while(0)//设置比较器的优先级为0
#define CMP_SET_IT_PRIORITY_1       do{IP2H&=~PCMPH;IP2|= PCMP;}while(0)//设置比较器的优先级为1
#define CMP_SET_IT_PRIORITY_2       do{IP2H|= PCMPH;IP2&=~PCMP;}while(0)//设置比较器的优先级为2
#define CMP_SET_IT_PRIORITY_3       do{IP2H|= PCMPH;IP2|= PCMP;}while(0)//设置比较器的优先级为3
//-------------寄存器读取----------//
#define CMP_SET_REG_CMPCR1(value)   do{CMPCR1=(u8)(value);}while(0)//设置CMPCR1寄存器
#define CMP_GET_REG_CMPCR1          (CMPCR1)//读取CMPCR1寄存器
#define CMP_SET_REG_CMPCR2(value)   do{CMPCR2=(u8)(value);}while(0)//设置CMPCR2寄存器
#define CMP_GET_REG_CMPCR2          (CMPCR2)//读取CMPCR1寄存器
#define CMP_SET_REG_CMPEXCFG(value) do{CMPEXCFG=(u8)(value);}while(0)//设置CMPEXCFG寄存器
#define CMP_GET_REG_CMPEXCFG        (CMPEXCFG)//读取CMPEXCFG寄存器
//-------------功能定义------------//
#define CMP_IT_NUM                  interrupt 21//比较器中断号
/*------------------------------系统管理特殊功能寄存器----------------------------*/
#define SWBS                        0x40//软件复位选择控制位
#define SWRST                       0x20//软件复位操作
#define PD                          0x02//掉电模式控制位
#define IDL                         0x01//空闲模式控制位
#define EAXFR                       0x80//XFR访问控制位
//-------------功能指令------------//
#define POWER_RESET                 do{IAP_CONTR=(SWRST|SWBS);}while(0)//相当于上电重启(数据会丢失)
#define MCU_RESET                   do{IAP_CONTR=(SWRST);     }while(0)//相当于按键复位(数据不会丢失)
#define POWER_DOWN                  REG_SET_BIT(PCON,PD)      //掉电模式
#define POWER_IDLE                  REG_SET_BIT(PCON,IDL)     //空闲模式
#define EX_SFR_ENABLE               REG_SET_BIT(P_SW2,EAXFR)  //打开额外的寄存器地址。
#define EX_SFR_DISABLE              REG_RESET_BIT(P_SW2,EAXFR)//关闭额外的寄存器地址。
//-------------寄存器读取----------//
#define SYS_SET_REG_RSTCFG(value)   do{RSTCFG=(u8)(value);}while(0)//设置RSTCFG寄存器
#define SYS_GET_REG_RSTCFG          (RSTCFG)//读取RSTCFG寄存器
/*-------------------------------掉电定时器功能寄存器-----------------------------*/
#define WKTEN                       0x80//掉电唤醒使能
//-------------功能指令------------//
#define WKT_ON                      REG_SET_BIT(WKTCH,WKTEN)  //打开掉电定时器
#define WKT_OFF                     REG_RESET_BIT(WKTCH,WKTEN)//关闭掉电定时器
//-------------寄存器读取----------//
#define WKT_SET_REG_COUNT(value)    do{WKTC=(u16)(value);}while(0)//设置掉电定时器
#define WKT_GET_REG_COUNT           (WKTC)//读取掉电定时器
/*--------------------------------定时器0功能寄存器-------------------------------*/
sbit    TF0                         =TCON^5;//定时器0溢出中断标志位
sbit    TR0                         =TCON^4;//定时器0运行控制位
sbit    ET0                         =IE^1;  //定时器0中断允许位
#define T0_GATE                     0x08    //定时器0门控位
#define T0CLKO                      0x01    //定时器0时钟输出控制
#define T0_CT                       0x04    //定时器0计数控制位
#define T0_M1                       0x02    //定时器0模式选择位1
#define T0_M0                       0x01    //定时器0模式选择位0
#define T0x12                       0x80    //定时器0速度控制位 
sbit    PT0                         =IP^1;  //定时器0中断优先级控制位（低）
#define PT0H                        0x02    //定时器0中断优先级控制位（高）
//-------------功能指令------------//
#define TIMER0_POWER_ON             do{TF0=0;TR0=1;}while(0)//开定时器0
#define TIMER0_POWER_OFF            do{TR0=0;}while(0)      //关定时器0
#define TIMER0_IT_ENABLE            do{ET0=1;}while(0)      //开定时器0中断使能
#define TIMER0_IT_DISABLE           do{ET0=0;}while(0)      //关定时器0中断使能
#define TIMER0_GATE_ENABLE          REG_SET_BIT(TMOD,T0_GATE)  //开定时器0的门控位
#define TIMER0_GATE_DISABLE         REG_RESET_BIT(TMOD,T0_GATE)//关定时器0的门控位
#define TIMER0_OUT_ON               REG_SET_BIT(INTCLKO,T0CLKO)  //开定时器0的时钟输出
#define TIMER0_OUT_OFF              REG_RESET_BIT(INTCLKO,T0CLKO)//关定时器0的时钟输出
#define TIMER0_SET_MODE_COUNT       REG_SET_BIT(TMOD,T0_CT)  //设定定时器0为计数器
#define TIMER0_SET_MODE_TIMER       REG_RESET_BIT(TMOD,T0_CT)//设定定时器0为定时器
#define TIMER0_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x03));}while(0)//定时器0运行于16位模式
#define TIMER0_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x03))|T0_M0;}while(0)//定时器0运行于16位模式
#define TIMER0_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x03))|T0_M1;}while(0)//定时器0运行于8位自动重载
#define TIMER0_SET_MODE_1T          REG_SET_BIT(AUXR,T0x12)  //设定定时器0为1T模式
#define TIMER0_SET_MODE_12T         REG_RESET_BIT(AUXR,T0x12)//设定定时器0为12T模式
#define TIMER0_GET_FLAG             (TF0)//获取定时器0的溢出标志位
#define TIMER0_CLS_FLAG             do{TF0=0;}while(0)//清定时器0的溢出标志位
#define TIMER0_SET_IT_PRIORITY_0    do{IPH&=~PT0H;PT0=0;}while(0)//设置定时器0的优先级为0
#define TIMER0_SET_IT_PRIORITY_1    do{IPH&=~PT0H;PT0=1;}while(0)//设置定时器0的优先级为1
#define TIMER0_SET_IT_PRIORITY_2    do{IPH|= PT0H;PT0=0;}while(0)//设置定时器0的优先级为2
#define TIMER0_SET_IT_PRIORITY_3    do{IPH|= PT0H;PT0=1;}while(0)//设置定时器0的优先级为3
//-------------寄存器读取----------//
#define TIMER0_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x80,value) //设置AUXR寄存器的定时器0部分
#define TIMER0_GET_REG_AUXR         (AUXR & 0x80)                //读取AUXR寄存器的定时器0部分
#define TIMER0_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0x0F,value) //设置定时器0的工作模式
#define TIMER0_GET_REG_TMOD         (TMOD & 0x0F)                //读取定时器0的工作模式
#define TIMER0_SET_REG_HL(value)    do{TL0=(u8)(value);TH0=(u8)(value>>8);}while(0)//设置定时器0的计数值
#define TIMER0_GET_REG_HL           ((((u16)TH0)<<8)|(u16)TL0)  //获取定时器0的计数值
#define TIMER0_SET_REG_H8(value)    do{TH0=(u8)(value);}while(0)//设置定时器0的计数值的高8位
#define TIMER0_GET_REG_H8           (TH0)                       //获取定时器0的计数值的高8位
#define TIMER0_SET_REG_L8(value)    do{TL0=(u8)(value);}while(0)//设置定时器0的计数值的低8位
#define TIMER0_GET_REG_L8           (TL0)                       //获取定时器0的计数值的低8位
//-------------功能定义------------//
#define TIMER0_IT_NUM               interrupt 1//定时器0的中断号
/*--------------------------------定时器1功能寄存器-------------------------------*/
sbit    TF1                         =TCON^7;//定时器1溢出中断标志位
sbit    TR1                         =TCON^6;//定时器1运行控制位
sbit    ET1                         =IE^3;  //定时器1中断允许位
#define T1_GATE                     0x80    //定时器1门控位
#define T1CLKO                      0x02    //定时器1时钟输出控制
#define T1_CT                       0x40    //定时器1计数控制位
#define T1_M1                       0x20    //定时器1模式选择位1
#define T1_M0                       0x10    //定时器1模式选择位0
#define T1x12                       0x40    //定时器1速度控制位
sbit    PT1                         =IP^3;  //定时器1中断优先级控制位（低）
#define PT1H                        0x08    //定时器1中断优先级控制位（高）
//-------------功能指令------------//
#define TIMER1_POWER_ON             do{TF1=0;TR1=1;}while(0)//开定时器1
#define TIMER1_POWER_OFF            do{TR1=0;}while(0)      //关定时器1
#define TIMER1_IT_ENABLE            do{ET1=1;}while(0)      //开定时器1中断使能
#define TIMER1_IT_DISABLE           do{ET1=0;}while(0)      //关定时器1中断使能
#define TIMER1_GATE_ENABLE          REG_SET_BIT(TMOD,T1_GATE)  //开定时器1的门控位
#define TIMER1_GATE_DISABLE         REG_RESET_BIT(TMOD,T1_GATE)//关定时器1的门控位
#define TIMER1_OUT_ON               REG_SET_BIT(INTCLKO,T1CLKO)  //开定时器1的时钟输出
#define TIMER1_OUT_OFF              REG_RESET_BIT(INTCLKO,T1CLKO)//关定时器1的时钟输出
#define TIMER1_SET_MODE_COUNT       REG_SET_BIT(TMOD,T1_CT)  //设定定时器1为计数器
#define TIMER1_SET_MODE_TIMER       REG_RESET_BIT(TMOD,T1_CT)//设定定时器1为定时器
#define TIMER1_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x30));}while(0)//定时器1运行于16位模式
#define TIMER1_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x30))|T1_M0;}while(0)//定时器1运行于16位模式
#define TIMER1_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x30))|T1_M1;}while(0)//定时器1运行于8位自动重载
#define TIMER1_SET_MODE_1T          REG_SET_BIT(AUXR,T1x12)  //设定定时器1为1T模式
#define TIMER1_SET_MODE_12T         REG_RESET_BIT(AUXR,T1x12)//设定定时器1为12T模式
#define TIMER1_GET_FLAG             (TF1)//获取定时器1的溢出标志位
#define TIMER1_CLS_FLAG             do{TF1=0;}while(0)//清定时器1的溢出标志位
#define TIMER1_SET_IT_PRIORITY_0    do{IPH&=~PT1H;PT1=0;}while(0)//设置定时器1的优先级为0
#define TIMER1_SET_IT_PRIORITY_1    do{IPH&=~PT1H;PT1=1;}while(0)//设置定时器1的优先级为1
#define TIMER1_SET_IT_PRIORITY_2    do{IPH|= PT1H;PT1=0;}while(0)//设置定时器1的优先级为2
#define TIMER1_SET_IT_PRIORITY_3    do{IPH|= PT1H;PT1=1;}while(0)//设置定时器1的优先级为3
//-------------寄存器读取----------//
#define TIMER1_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x40,value)//设置AUXR寄存器的定时器1部分
#define TIMER1_GET_REG_AUXR         (AUXR & 0x40)               //读取AUXR寄存器的定时器1部分
#define TIMER1_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0xF0,value)//设置定时器1的工作模式
#define TIMER1_GET_REG_TMOD         (TMOD & 0xF0)               //读取定时器1的工作模式
#define TIMER1_SET_REG_HL(value)    do{TL1=(u8)(value);TH1=(u8)(value>>8);}while(0)//设置定时器1的计数值
#define TIMER1_GET_REG_HL           ((((u16)TH1)<<8)|(u16)TL1)  //获取定时器1的计数值
#define TIMER1_SET_REG_H8(value)    do{TH1=(u8)(value);}while(0)//设置定时器1的计数值的高8位
#define TIMER1_GET_REG_H8           (TH1)                       //获取定时器1的计数值的高8位
#define TIMER1_SET_REG_L8(value)    do{TL1=(u8)(value);}while(0)//设置定时器1的计数值的低8位
#define TIMER1_GET_REG_L8           (TL1)                       //获取定时器1的计数值的低8位
//-------------功能定义------------//
#define TIMER1_IT_NUM               interrupt 3//定时器1的中断号
/*--------------------------------定时器2功能寄存器-------------------------------*/
#define T2R                         0x10//定时器2运行控制位
#define ET2                         0x04//定时器2中断允许位
#define T2CLKO                      0x04//定时器2时钟输出控制
#define T2_CT                       0x08//定时器2计数控制位
#define T2x12                       0x04//定时器2速度控制位
#define T2IF                        0x01//定时器2的溢出标志位
//-------------功能指令------------//
#define TIMER2_POWER_ON             REG_SET_BIT(AUXR,T2R)  //打开定时器2
#define TIMER2_POWER_OFF            REG_RESET_BIT(AUXR,T2R)//关闭定时器2
#define TIMER2_IT_ENABLE            REG_SET_BIT(IE2,ET2)   //打开定时器2中断
#define TIMER2_IT_DISABLE           REG_RESET_BIT(IE2,ET2) //关闭定时器2中断
#define TIMER2_OUT_ON               REG_SET_BIT(INTCLKO,T2CLKO)  //开定时器2的时钟输出
#define TIMER2_OUT_OFF              REG_RESET_BIT(INTCLKO,T2CLKO)//关定时器2的时钟输出
#define TIMER2_SET_MODE_COUNT       REG_SET_BIT(AUXR,T2_CT)  //设定定时器2为计数器
#define TIMER2_SET_MODE_TIMER       REG_RESET_BIT(AUXR,T2_CT)//设定定时器2为定时器
#define TIMER2_SET_MODE_1T          REG_SET_BIT(AUXR,T2x12)  //设定定时器2为1T模式
#define TIMER2_SET_MODE_12T         REG_RESET_BIT(AUXR,T2x12)//设定定时器2为12T模式
#define TIMER2_CLS_FLAG             REG_RESET_BIT(AUXINTIF,T2IF)//清定时器2溢出标志
//-------------寄存器读取----------//
#define TIMER2_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x0C,value)//设置AUXR寄存器的定时器2部分
#define TIMER2_GET_REG_AUXR         (AUXR&0x0C)//读取AUXR寄存器的定时器2部分
#define TIMER2_SET_REG_HL(value)    do{T2L=(u8)(value);T2H=(u8)(value>>8);}while(0)//设置定时器2的计数值
#define TIMER2_GET_REG_HL           ((((u16)T2H)<<8)|(u16)T2L)//获取定时器2的计数值
#define TIMER2_SET_REG_H8(value)    do{T2H=(u8)(value);}while(0)//设置定时器2的计数值的高8位
#define TIMER2_GET_REG_H8           (T2H)                       //获取定时器2的计数值的高8位
#define TIMER2_SET_REG_L8(value)    do{T2L=(u8)(value);}while(0)//设置定时器2的计数值的低8位
#define TIMER2_GET_REG_L8           (T2L)                       //获取定时器2的计数值的低8位
//-------------功能定义------------//
#define TIMER2_IT_NUM               interrupt 12//定时器2的中断服务号
/*--------------------------------定时器3功能寄存器-------------------------------*/
#define T3R                         0x08//定时器3允许控制位
#define ET3                         0x20//定时器3中断允许位
#define T3CLKO                      0x01//定时器3时钟输出控制
#define T3_CT                       0x04//定时器3计数控制位
#define T3x12                       0x02//定时器3速度控制位
#define T3IF                        0x02//定时器3的中断标志位
//-------------功能指令------------//
#define TIMER3_POWER_ON             REG_SET_BIT(T4T3M,T3R)      //打开定时器3
#define TIMER3_POWER_OFF            REG_RESET_BIT(T4T3M,T3R)    //关闭定时器3
#define TIMER3_IT_ENABLE            REG_SET_BIT(IE2,ET3)        //打开定时器3中断
#define TIMER3_IT_DISABLE           REG_RESET_BIT(IE2,ET3)      //关闭定时器3中断
#define TIMER3_OUT_ON               REG_SET_BIT(T4T3M,T3CLKO)   //开定时器3的时钟输出
#define TIMER3_OUT_OFF              REG_RESET_BIT(T4T3M,T3CLKO) //关定时器3的时钟输出
#define TIMER3_SET_MODE_COUNT       REG_SET_BIT(T4T3M,T3_CT)    //设定定时器3为计数器
#define TIMER3_SET_MODE_TIMER       REG_RESET_BIT(T4T3M,T3_CT)  //设定定时器3为定时器
#define TIMER3_SET_MODE_1T          REG_SET_BIT(T4T3M,T3x12)    //设定定时器3为1T模式
#define TIMER3_SET_MODE_12T         REG_RESET_BIT(T4T3M,T3x12)  //设定定时器3为12T模式
#define TIMER3_CLS_FLAG             REG_RESET_BIT(AUXINTIF,T3IF)//清定时器3中断标志
//-------------寄存器读取----------//
#define TIMER3_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0x0F,value)//设置T4T3M寄存器的定时器3部分
#define TIMER3_GET_REG_T4T3M        (T4T3M & 0x0F)//读取T4T3M寄存器的定时器3部分
#define TIMER3_SET_REG_HL(value)    do{T3L=(u8)(value);T3H=(u8)(value>>8);}while(0)//设置定时器3的计数值
#define TIMER3_GET_REG_HL           ((((u16)T3H)<<8)|(u16)T3L)  //获取定时器3的计数值
#define TIMER3_SET_REG_H8(value)    do{T3H=(u8)(value);}while(0)//设置定时器3的计数值的高8位
#define TIMER3_GET_REG_H8           (T3H)                       //获取定时器3的计数值的高8位
#define TIMER3_SET_REG_L8(value)    do{T3L=(u8)(value);}while(0)//设置定时器3的计数值的低8位
#define TIMER3_GET_REG_L8           (T3L)
//-------------功能定义------------//
#define TIMER3_IT_NUM               interrupt 19//定时器3的中断服务号
/*--------------------------------定时器4功能寄存器-------------------------------*/
#define T4R                         0x80//定时器4允许控制位
#define ET4                         0x40//定时器4中断允许位
#define T4CLKO                      0x10//定时器4时钟输出控制
#define T4_CT                       0x40//定时器4计数控制位
#define T4x12                       0x20//定时器4速度控制位
#define T4IF                        0x04//定时器4的中断标志位
//-------------功能指令------------//
#define TIMER4_POWER_ON             REG_SET_BIT(T4T3M,T4R)      //打开定时器4
#define TIMER4_POWER_OFF            REG_RESET_BIT(T4T3M,T4R)    //关闭定时器4
#define TIMER4_IT_ENABLE            REG_SET_BIT(IE2,ET4)        //打开定时器4中断
#define TIMER4_IT_DISABLE           REG_RESET_BIT(IE2,ET4)      //关闭定时器4中断
#define TIMER4_OUT_ON               REG_SET_BIT(T4T3M,T4CLKO)   //开定时器4的时钟输出
#define TIMER4_OUT_OFF              REG_RESET_BIT(T4T3M,T4CLKO) //关定时器4的时钟输出
#define TIMER4_SET_MODE_COUNT       REG_SET_BIT(T4T3M,T4_CT)    //设定定时器4为计数器
#define TIMER4_SET_MODE_TIMER       REG_RESET_BIT(T4T3M,T4_CT)  //设定定时器4为定时器
#define TIMER4_SET_MODE_1T          REG_SET_BIT(T4T3M,T4x12)    //设定定时器4为1T模式
#define TIMER4_SET_MODE_12T         REG_RESET_BIT(T4T3M,T4x12)  //设定定时器4为12T模式
#define TIMER4_CLS_FLAG              REG_RESET_BIT(AUXINTIF,T4IF)//清定时器4中断标志
//-------------寄存器读取----------//
#define TIMER4_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0xF0,value)//设置T4T3M寄存器的定时器4部分
#define TIMER4_GET_REG_T4T3M        (T4T3M & 0xF0)//读取T4T3M寄存器的定时器4部分
#define TIMER4_SET_REG_HL(value)    do{T4L=(u8)(value);T4H=(u8)(value>>8);}while(0)//设置定时器4的计数值
#define TIMER4_GET_REG_HL           ((((u16)T4H)<<8)|(u16)T4L)  //获取定时器4的计数值
#define TIMER4_SET_REG_H8(value)    do{T4H=(u8)(value);}while(0)//设置定时器4的计数值的高8位
#define TIMER4_GET_REG_H8           (T4H)                       //获取定时器4的计数值的高8位
#define TIMER4_SET_REG_L8(value)    do{T4L=(u8)(value);}while(0)//设置定时器4的计数值的低8位
#define TIMER4_GET_REG_L8           (T4L)
//-------------功能定义------------//
#define TIMER4_IT_NUM               interrupt 20//定时器4的中断服务号
/*-------------------------------串口1特殊功能寄存器------------------------------*/
sbit    ES                          =IE^4;  //串口1中断允许位
sbit    SM0                         =SCON^7;//串口1工作模式选择位0
sbit    SM1                         =SCON^6;//串口1工作模式选择位1
sbit    SM2                         =SCON^5;//串口1多机通信控制位
sbit    REN                         =SCON^4;//串口1接收控制位
sbit    TB8                         =SCON^3;//串口1发送的第9位
sbit    RB8                         =SCON^2;//串口1接收的第9位
sbit    TI                          =SCON^1;//串口1发送中断请求标志位
sbit    RI                          =SCON^0;//串口1接收中断请求标志位
#define SMOD                        0x80    //串口1波特率控制位
#define SMOD0                       0x40    //串口1帧错误检测控制位
#define UART_M0x6                   0x20    //串口1模式0的通讯速度控制位
#define S1ST2                       0x01    //串口1波特率发生器选择位
sbit    PS                          =IP^4;  //串口1中断优先级控制位（低）
#define PSH                         0x10    //串口1中断优先级控制位（高）
//-------------功能指令------------//
#define UART1_IT_ENABLE             do{ES=1;}while(0)   //打开串口1中断
#define UART1_IT_DISABLE            do{ES=0;}while(0)   //关闭串口1中断
#define UART1_CLR_TI_FLAG           do{TI=0;}while(0)   //清除串口1的发送标志位
#define UART1_GET_TI_FLAG           (TI)                //读取串口1的发送标志位
#define UART1_CLR_RI_FLAG           do{RI=0;}while(0)   //清除串口1的接受标志位
#define UART1_GET_RI_FLAG           (RI)                //读取串口1的接受标志位
#define UART1_SET_TXD_BYTE9_0       do{TB8=0;TB8=0;}while(0)    //设置串口1发送的第9位为0
#define UART1_SET_TXD_BYTE9_1       do{TB8=1;TB8=1;}while(0)    //设置串口1发送的第9位为1
#define UART1_GET_RXD_BYTE9         (RB8)                       //读取串口1接收的第9位 
#define UART1_SET_PIN(value)        REG_IN_MASK(P_SW1,0xC0,value)//设置串口1的输出引脚
#define UART1_SET_BAUD_1            REG_RESET_BIT(PCON,SMOD)//设置波特率不倍速
#define UART1_SET_BAUD_2            REG_SET_BIT(PCON,SMOD)  //设置波特率二倍速
#define UART1_SET_CLK_TIMER1        REG_RESET_BIT(AUXR,S1ST2)//设置串口1的时钟由定时器1产生
#define UART1_SET_CLK_TIMER2        REG_SET_BIT(AUXR,S1ST2)  //设置串口1的时钟由定时器2产生
#define UART1_SET_RXD_ENABLE        do{REN=1;}while(0)  //串口1的接受功能开启
#define UART1_SET_RXD_DISABLE       do{REN=0;}while(0)  //串口1的接受功能关闭
#define UART1_SET_MUX_ENABLE        do{SM2=1;}while(0)  //串口1的多机通信开启
#define UART1_SET_MUX_DISABLE       do{SM2=0;}while(0)  //串口1的多机通信关闭
#define UART1_SET_MODE_S_8          do{SCON=(SCON&(~0xC0))|0x00;}while(0)//串口1的工作模式为同步模式
#define UART1_SET_MODE_A_8_BAUD     do{SCON=(SCON&(~0xC0))|0x40;}while(0)//串口1的工作模式为异步8位模式，可变波特率
#define UART1_SET_MODE_A_9          do{SCON=(SCON&(~0xC0))|0x80;}while(0)//串口1的工作模式为异步9位模式
#define UART1_SET_MODE_A_9_BAUD     do{SCON=(SCON&(~0xC0))|0xC0;}while(0)//串口1的工作模式为异步9位模式，可变波特率
#define UART1_SET_IT_PRIORITY_0     do{IPH&=~PSH;PS=0;}while(0)//设置串口1的优先级为0
#define UART1_SET_IT_PRIORITY_1     do{IPH&=~PSH;PS=1;}while(0)//设置串口1的优先级为1
#define UART1_SET_IT_PRIORITY_2     do{IPH|= PSH;PS=0;}while(0)//设置串口1的优先级为2
#define UART1_SET_IT_PRIORITY_3     do{IPH|= PSH;PS=1;}while(0)//设置串口1的优先级为3
//-------------寄存器读取----------//
#define UART1_SET_REG_SADDR(value)  do{SADDR=(u8)(value);}while(0)//设置串口1的地址
#define UART1_GET_REG_SADDR         (SADDR)                       //读取串口1的地址
#define UART1_SET_REG_SADEN(value)  do{SADEN=(u8)(value);}while(0)//设置串口1的地址掩码
#define UART1_GET_REG_SADEN         (SADEN)                       //读取串口1的地址掩码
#define UART1_SET_REG_SBUF(value)   do{SBUF =(u8)(value);}while(0)//设置串口1要发送的数据
#define UART1_GET_REG_SBUF          (SBUF)                        //读取串口1接收到的数据
#define UART1_SET_REG_SCON(value)   do{SCON =(u8)(value);}while(0)//设置SCON寄存器
#define UART1_GET_REG_SCON          (SCON)                        //读取SCON寄存器
#define UART1_SET_REG_PCON(value)   REG_IN_MASK(PCON,0xC0,value)  //设置PCON寄存器的串口1部分
#define UART1_GET_REG_PCON          (PCON & 0xC0)                 //读取PCON寄存器的串口1部分
#define UART1_SET_REG_AUXR(value)   REG_IN_MASK(AUXR,0x21,value)//设置AUXR寄存器的串口1部分
#define UART1_GET_REG_AUXR          (AUXR & 0x21)                 //读取AUXR寄存器的串口1部分
//-------------功能定义------------//
#define UART1_IT_NUM                interrupt 4//串口1中断号
/*-------------------------------串口2特殊功能寄存器------------------------------*/
#define ES2                         0x01//串口2中断允许位
#define S2SM0                       0x80//串口2工作模式选择位
#define S2SM2                       0x20//串口2多机通信控制位
#define S2REN                       0x10//串口2接收控制位
#define S2TB8                       0x08//串口2发送的第9位
#define S2RB8                       0x04//串口2接收的第9位
#define S2TI                        0x02//串口2发送中断请求标志位
#define S2RI                        0x01//串口2接收中断请求标志位
#define PS2                         0x01//串口2中断优先级控制位（低）
#define PS2H                        0x01//串口2中断优先级控制位（高）
//-------------功能指令------------//
#define UART2_IT_ENABLE             REG_SET_BIT(IE2,ES2)//打开串口2中断
#define UART2_IT_DISABLE            REG_RESET_BIT(IE2,ES2)//关闭串口2中断
#define UART2_CLR_TI_FLAG           REG_RESET_BIT(S2CON,S2TI)//清除串口2的发送标志位
#define UART2_GET_TI_FLAG           (S2CON & S2TI)           //读取串口2的发送标志位
#define UART2_CLR_RI_FLAG           REG_RESET_BIT(S2CON,S2RI)//清除串口2的接受标志位
#define UART2_GET_RI_FLAG           (S2CON & S2RI)           //读取串口2的接受标志位
#define UART2_SET_TXD_BYTE9_0       do{S2CON&=~S2TB8;S2CON&=~S2TB8;}while(0)//设置串口2发送的第9位为0
#define UART2_SET_TXD_BYTE9_1       do{S2CON|= S2TB8;S2CON|= S2TB8;}while(0)//设置串口2发送的第9位为1
#define UART2_GET_RXD_BYTE9         (S2CON & S2RB8)                         //读取串口2接收的第9位 
#define UART2_SET_PIN(value)        REG_IN_MASK(P_SW2,0x01,value)//设置串口2的输出引脚
#define UART2_SET_RXD_ENABLE        REG_SET_BIT(S2CON,S2REN)  //串口2的接受功能开启
#define UART2_SET_RXD_DISABLE       REG_RESET_BIT(S2CON,S2REN)//串口2的接受功能关闭
#define UART2_SET_MUX_ENABLE        REG_SET_BIT(S2CON,S2SM2)  //串口2的多机通信开启
#define UART2_SET_MUX_DISABLE       REG_RESET_BIT(S2CON,S2SM2)//串口2的多机通信关闭
#define UART2_SET_MODE_A_8_BAUD     REG_RESET_BIT(S2CON,S2SM0)//串口2的工作模式为异步8位模式，可变波特率
#define UART2_SET_MODE_A_9_BAUD     REG_SET_BIT(S2CON,S2SM0)  //串口2的工作模式为异步9位模式，可变波特率
#define UART2_SET_IT_PRIORITY_0     do{IP2H&=~PS2H;IP2&=~PS2;}while(0)//设置串口2的优先级为0
#define UART2_SET_IT_PRIORITY_1     do{IP2H&=~PS2H;IP2|= PS2;}while(0)//设置串口2的优先级为1
#define UART2_SET_IT_PRIORITY_2     do{IP2H|= PS2H;IP2&=~PS2;}while(0)//设置串口2的优先级为2
#define UART2_SET_IT_PRIORITY_3     do{IP2H|= PS2H;IP2|= PS2;}while(0)//设置串口2的优先级为3
//-------------寄存器读取----------//
#define UART2_SET_REG_S2BUF(value)  do{S2BUF =(u8)(value);}while(0)//设置串口2要发送的数据
#define UART2_GET_REG_S2BUF         (S2BUF)                        //读取串口2接收到的数据
#define UART2_SET_REG_S2CON(value)  do{S2CON =(u8)(value);}while(0)//设置S2CON寄存器
#define UART2_GET_REG_S2CON         (S2CON)                        //读取S2CON寄存器
//-------------功能定义------------//
#define UART2_IT_NUM                interrupt 8//串口2中断号
/*-------------------------------串口3特殊功能寄存器------------------------------*/
#define ES3                         0x08//串口3中断允许位
#define S3SM0                       0x80//串口3工作模式选择位
#define S3ST3                       0x40//串口3波特率发生器选择位
#define S3SM2                       0x20//串口3多机通信控制位
#define S3REN                       0x10//串口3接收控制位
#define S3TB8                       0x08//串口3发送的第9位
#define S3RB8                       0x04//串口3接收的第9位
#define S3TI                        0x02//串口3发送中断请求标志位
#define S3RI                        0x01//串口3接收中断请求标志位
#define PS3                         0x01//串口3中断优先级控制位（低）
#define PS3H                        0x01//串口3中断优先级控制位（高）
//-------------功能指令------------//
#define UART3_IT_ENABLE             REG_SET_BIT(IE2,ES3)    //打开串口3中断
#define UART3_IT_DISABLE            REG_RESET_BIT(IE2,ES3)  //关闭串口3中断
#define UART3_CLR_TI_FLAG           REG_RESET_BIT(S3CON,S3TI)//清除串口3的发送标志位
#define UART3_GET_TI_FLAG           (S3CON & S3TI)           //读取串口3的发送标志位
#define UART3_CLR_RI_FLAG           REG_RESET_BIT(S3CON,S3RI)//清除串口3的接受标志位
#define UART3_GET_RI_FLAG           (S3CON & S3RI)           //读取串口3的接受标志位
#define UART3_SET_TXD_BYTE9_0       do{S3CON&=~S3TB8;S3CON&=~S3TB8;}while(0)//设置串口3发送的第9位为0
#define UART3_SET_TXD_BYTE9_1       do{S3CON|= S3TB8;S3CON|= S3TB8;}while(0)//设置串口3发送的第9位为1
#define UART3_GET_RXD_BYTE9         (S3CON & S3RB8)//读取串口3接收的第9位 
#define UART3_SET_PIN(value)        REG_IN_MASK(P_SW2,0x02,value)//设置串口3的输出引脚
#define UART3_SET_CLK_TIMER2        REG_RESET_BIT(S3CON,S3ST3)  //设置串口3的时钟由定时器2产生
#define UART3_SET_CLK_TIMER3        REG_SET_BIT(S3CON,S3ST3)    //设置串口3的时钟由定时器3产生
#define UART3_SET_RXD_ENABLE        REG_SET_BIT(S3CON,S3REN)    //串口3的接受功能开启
#define UART3_SET_RXD_DISABLE       REG_RESET_BIT(S3CON,S3REN)  //串口3的接受功能关闭
#define UART3_SET_MUX_ENABLE        REG_SET_BIT(S3CON,S3SM2)    //串口3的多机通信开启
#define UART3_SET_MUX_DISABLE       REG_RESET_BIT(S3CON,S3SM2)  //串口3的多机通信关闭
#define UART3_SET_MODE_A_8_BAUD     REG_RESET_BIT(S3CON,S3SM0)  //串口3的工作模式为异步8位模式，可变波特率
#define UART3_SET_MODE_A_9_BAUD     REG_SET_BIT(S3CON,S3SM0)    //串口3的工作模式为异步9位模式，可变波特率
#define UART3_SET_IT_PRIORITY_0     do{IP3H&=~PS3H;IP3&=~PS3;}while(0)//设置串口3的优先级为0
#define UART3_SET_IT_PRIORITY_1     do{IP3H&=~PS3H;IP3|= PS3;}while(0)//设置串口3的优先级为1
#define UART3_SET_IT_PRIORITY_2     do{IP3H|= PS3H;IP3&=~PS3;}while(0)//设置串口3的优先级为2
#define UART3_SET_IT_PRIORITY_3     do{IP3H|= PS3H;IP3|= PS3;}while(0)//设置串口3的优先级为3
//-------------寄存器读取----------//
#define UART3_SET_REG_S3BUF(value)  do{S3BUF =((u8)(value));}while(0)//设置串口3要发送的数据
#define UART3_GET_REG_S3BUF         (S3BUF)                          //读取串口3接收到的数据
#define UART3_SET_REG_S3CON(value)  do{S3CON =((u8)(value));}while(0)//设置S3CON寄存器
#define UART3_GET_REG_S3CON         (S3CON)                          //读取S3CON寄存器
//-------------功能定义------------//
#define UART3_IT_NUM                interrupt 17//串口3中断号
/*-------------------------------串口4特殊功能寄存器------------------------------*/
#define ES4                         0x10//串口4中断允许位
#define S4SM0                       0x80//串口4工作模式选择位
#define S4ST4                       0x40//串口4波特率发生器选择位
#define S4SM2                       0x20//串口4多机通信控制位
#define S4REN                       0x10//串口4接收控制位
#define S4TB8                       0x08//串口4发送的第9位
#define S4RB8                       0x04//串口4接收的第9位
#define S4TI                        0x02//串口4发送中断请求标志位
#define S4RI                        0x01//串口4接收中断请求标志位
#define PS4                         0x02//串口4中断优先级控制位（低）
#define PS4H                        0x02//串口4中断优先级控制位（高）
//-------------功能指令------------//
#define UART4_IT_ENABLE             REG_SET_BIT(IE2,ES4)  //打开串口4中断
#define UART4_IT_DISABLE            REG_RESET_BIT(IE2,ES4)//关闭串口4中断
#define UART4_CLR_TI_FLAG           REG_RESET_BIT(S4CON,S4TI)//清除串口4的发送标志位
#define UART4_GET_TI_FLAG           (S4CON & S4TI)           //读取串口4的发送标志位
#define UART4_CLR_RI_FLAG           REG_RESET_BIT(S4CON,S4RI)//清除串口4的接受标志位
#define UART4_GET_RI_FLAG           (S4CON & S4RI)           //读取串口4的接受标志位
#define UART4_SET_TXD_BYTE9_0       do{S4CON&=~S4TB8;S4CON&=~S4TB8;}while(0)//设置串口4发送的第9位为0
#define UART4_SET_TXD_BYTE9_1       do{S4CON|= S4TB8;S4CON|= S4TB8;}while(0)//设置串口4发送的第9位为1
#define UART4_GET_RXD_BYTE9         (S4CON & S4RB8)//读取串口4接收的第9位 
#define UART4_SET_PIN(value)        REG_IN_MASK(P_SW2,0x04,value)//设置串口4的输出引脚
#define UART4_SET_CLK_TIMER2        REG_RESET_BIT(S4CON,S4ST4)//设置串口4的时钟由定时器2产生
#define UART4_SET_CLK_TIMER4        REG_SET_BIT(S4CON,S4ST4)  //设置串口4的时钟由定时器4产生
#define UART4_SET_RXD_ENABLE        REG_SET_BIT(S4CON,S4REN)  //串口4的接受功能开启
#define UART4_SET_RXD_DISABLE       REG_RESET_BIT(S4CON,S4REN)//串口4的接受功能关闭
#define UART4_SET_MUX_ENABLE        REG_SET_BIT(S4CON,S4SM2)  //串口4的多机通信开启
#define UART4_SET_MUX_DISABLE       REG_RESET_BIT(S4CON,S4SM2)//串口4的多机通信关闭
#define UART4_SET_MODE_A_8_BAUD     REG_RESET_BIT(S4CON,S4SM0)//串口4的工作模式为异步8位模式，可变波特率
#define UART4_SET_MODE_A_9_BAUD     REG_SET_BIT(S4CON,S4SM0)  //串口4的工作模式为异步9位模式，可变波特率
#define UART4_SET_IT_PRIORITY_0     do{IP3H&=~PS4H;IP3&=~PS4;}while(0)//设置串口4的优先级为0
#define UART4_SET_IT_PRIORITY_1     do{IP3H&=~PS4H;IP3|= PS4;}while(0)//设置串口4的优先级为1
#define UART4_SET_IT_PRIORITY_2     do{IP3H|= PS4H;IP3&=~PS4;}while(0)//设置串口4的优先级为2
#define UART4_SET_IT_PRIORITY_3     do{IP3H|= PS4H;IP3|= PS4;}while(0)//设置串口4的优先级为3
//-------------寄存器读取----------//
#define UART4_SET_REG_S4BUF(value)  do{S4BUF =(u8)(value);}while(0)//设置串口4要发送的数据
#define UART4_GET_REG_S4BUF         (S4BUF)                        //读取串口4接收到的数据
#define UART4_SET_REG_S4CON(value)  do{S4CON =(u8)(value);}while(0)//设置S4CON寄存器
#define UART4_GET_REG_S4CON         (S4CON)                        //读取S4CON寄存器
//-------------功能定义------------//
#define UART4_IT_NUM                interrupt 18//串口4中断号
/*-------------------------------MDU16特殊功能寄存器------------------------------*/
#define MDOV                        0x40//MDU溢出标志位
#define MDRST                       0x02//MDU复位控制位
#define ENOP                        0x01//MDU使能与状态位
//-------------功能指令------------//
#define MDU16_RESET                 do{OPCON=MDRST;}while(0)//复位乘除单元
#define MDU16_START                 do{OPCON=ENOP; }while(0)//开始计算
#define MDU16_GET_END_FLAG          (OPCON & ENOP)          //获取计算结束标志位
#define MDU16_GET_MDOV_FLAG         (OPCON & MDOV)          //获取计算结果溢出位
#define MDU16_SET_16MUL             do{ARCON=0x80; }while(0)//16位乘法
#define MDU16_SET_16DIV             do{ARCON=0xa0; }while(0)//16位除法
#define MDU16_SET_32DIV             do{ARCON=0xc0; }while(0)//32位除法
//-------------寄存器读取----------//
#define MDU16_SET_REG_ARCON(value)  do{ARCON=(u8)(value);}while(0)//设置ARCON寄存器
#define MDU16_GET_REG_ARCON         (ARCON)//读取ARCON寄存器
#define MDU16_SET_REG_OPCON(value)  do{OPCON=(u8)(value);}while(0)//设置OPCON寄存器
#define MDU16_GET_REG_OPCON         (OPCON)//读取OPCON寄存器
/*--------------------------------IIC特殊功能寄存器-------------------------------*/
#define ENI2C                       0x80//IIC电源使能位
#define MSSL                        0x40//IIC主从机选择
#define EMSI                        0x80//IIC主机中断使能位
#define MSBUSY                      0x80//IIC主机模式时状态位
#define MSIF                        0x40//IIC主机模式时的中断请求位
#define MSACKI                      0x02//IIC主机模式时接收到的ACK
#define MSACKO                      0x01//IIC主机模式时要发送的ACK
#define WDTA                        0x01//IIC自动发送ack控制位
#define ESTAI                       0x40//IIC从机模式时接收START信号中断允许位
#define ERXI                        0x20//IIC从机模式时接收到1字节数据后中断允许位
#define ETXI                        0x10//IIC从机模式时发送完1字节数据后中断允许位
#define ESTOI                       0x08//IIC从机模式时接收STOP信号中断允许位
#define SLRST                       0x01//IIC复位从机模式
#define SLBUSY                      0x80//IIC从机模式时IIC控制器状态位
#define STAIF                       0x40//IIC从机模式时接收START信号中断请求位
#define RXIF                        0x20//IIC从机模式时接收到1字节数据后中断请求位
#define TXIF                        0x10//IIC从机模式时发送完1字节数据后中断请求位
#define STOIF                       0x08//IIC从机模式时接收STOP信号中断请求位
#define SLACKI                      0x02//IIC从机模式时接收到的ACK
#define SLACKO                      0x01//IIC从机模式时将要发送的ACK
#define PI2C                        0x40//IIC中断优先级控制位（低）
#define PI2CH                       0x40//IIC中断优先级控制位（高）
//-------------功能指令------------//
#define IIC_POWER_ON                REG_SET_BIT(I2CCFG,ENI2C)   //打开IIC电源
#define IIC_POWER_OFF               REG_RESET_BIT(I2CCFG,ENI2C) //关闭IIC电源
#define IIC_SET_MODE_MASTER         REG_SET_BIT(I2CCFG,MSSL)    //设置IIC为主机模式
#define IIC_SET_MODE_SLAVE          REG_RESET_BIT(I2CCFG,MSSL)  //设置IIC为从机模式
#define IIC_SET_AUTOACK_ENABLE      REG_SET_BIT(I2CMSAUX,WDTA)  //设置自动发送ACK
#define IIC_SET_AUTOACK_DISABLE     REG_RESET_BIT(I2CMSAUX,WDTA)//取消自动发送ACK
#define IIC_SET_SPEED(value)        REG_IN_MASK(I2CCFG,0x3F,value)//设置IIC的输出速度
#define IIC_GET_M_IT_FLAG           (I2CMSST & MSIF)             //获取IIC主机模式中断标志位
#define IIC_CLS_M_IT_FLAG           REG_RESET_BIT(I2CMSST,MSIF)  //清除IIC主机模式中断标志位
#define IIC_GET_S_STA_FLAG          (I2CSLST & STAIF)           //获取IIC从机模式开始帧中断标志位。
#define IIC_CLS_S_STA_FLAG          REG_RESET_BIT(I2CSLST,STAIF)//清除IIC从机模式开始帧中断标志位。
#define IIC_GET_S_STO_FLAG          (I2CSLST & STOIF)           //获取IIC从机模式结束帧中断标志位。
#define IIC_CLS_S_STO_FLAG          REG_RESET_BIT(I2CSLST,STOIF)//清除IIC从机模式结束帧中断标志位。
#define IIC_GET_S_RX_FLAG           (I2CSLST & RXIF)            //获取IIC从机模式数据帧中断标志位。
#define IIC_CLS_S_RX_FLAG           REG_RESET_BIT(I2CSLST,RXIF) //清除IIC从机模式数据帧中断标志位。
#define IIC_GET_ACK                 (I2CMSST & MSACKI)           //获取收到的ACK信号
#define IIC_SET_PIN(value)          REG_IN_MASK(P_SW2,0x30,value)//设置IIC的输出引脚
#define IIC_SET_IT_PRIORITY_0       do{IP2H&=~PI2CH;IP2&=~PI2C;}while(0)//设置IIC的优先级为0
#define IIC_SET_IT_PRIORITY_1       do{IP2H&=~PI2CH;IP2|= PI2C;}while(0)//设置IIC的优先级为1
#define IIC_SET_IT_PRIORITY_2       do{IP2H|= PI2CH;IP2&=~PI2C;}while(0)//设置IIC的优先级为2
#define IIC_SET_IT_PRIORITY_3       do{IP2H|= PI2CH;IP2|= PI2C;}while(0)//设置IIC的优先级为3
#define IIC_CMD_START               do{I2CMSCR=(EMSI|0x01);}while(0)//发送一个START信号
#define IIC_CMD_TX_DATA             do{I2CMSCR=(EMSI|0x02);}while(0)//发送一个字节数据
#define IIC_CMD_RX_ACK              do{I2CMSCR=(EMSI|0x03);}while(0)//接收一个ACK信号
#define IIC_CMD_RX_DATA             do{I2CMSCR=(EMSI|0x04);}while(0)//接收一个字节数据
#define IIC_CMD_TX_ACK              do{I2CMSST=0x00;I2CMSCR=(EMSI|0x05);}while(0)//发送一个ACK信号
#define IIC_CMD_TX_NACK             do{I2CMSST=0x01;I2CMSCR=(EMSI|0x05);}while(0)//发送一个nACK信号
#define IIC_CMD_STOP                do{I2CMSCR=(EMSI|0x06);}while(0)//发送一个STOP信号
#define IIC_CMD_START_TXDATA_RXACK  do{I2CMSCR=(EMSI|0x09);}while(0)//连续动作。发送START信号和8位数据，再接收一个ACK。
#define IIC_CMD_TXDATA_RXACK        do{I2CMSCR=(EMSI|0x0A);}while(0)//连续动作。发送8位数据，然后接收一个ACK。
#define IIC_CMD_RXDATA_ACK          do{I2CMSCR=(EMSI|0x0B);}while(0)//连续动作。接收8位数据，然后发送一个ACK。
#define IIC_CMD_RXDATA_NACK         do{I2CMSCR=(EMSI|0x0C);}while(0)//连续动作。接收8位数据，然后发送一个NACK。
//-------------寄存器读取----------//
#define IIC_SET_REG_CFG(value)      do{I2CCFG=(u8)(value);}while(0)//设置I2CCFG寄存器
#define IIC_GET_REG_CFG             (I2CCFG)//读取I2CCFG寄存器
#define IIC_SET_REG_MSCR(value)     do{I2CMSCR=(u8)(value);}while(0)//设置I2CMSCR寄存器
#define IIC_GET_REG_MSCR            (I2CMSCR)//读取I2CMSCR寄存器
#define IIC_SET_REG_MSST(value)     do{I2CMSST=(u8)(value);}while(0)//设置I2CMSST寄存器
#define IIC_GET_REG_MSST            (I2CMSST)//读取I2CMSST寄存器
#define IIC_SET_REG_MSAUX(value)    do{I2CMSAUX=(u8)(value);}while(0)//设置I2CMSAUX寄存器
#define IIC_GET_REG_MSAUX           (I2CMSAUX)//读取I2CMSAUX寄存器
#define IIC_SET_REG_DATA(value)     do{I2CTXD=(u8)(value);}while(0)//设置发送数据寄存器
#define IIC_GET_REG_DATA            (I2CRXD)  //读取接收数据寄存器

#define IIC_SET_REG_SLCR(value)     do{I2CSLCR=(u8)(value);}while(0)//设置I2CSLCR寄存器
#define IIC_GET_REG_SLCR            (I2CSLCR)//读取I2CSLCR寄存器
#define IIC_SET_REG_SLST(value)     do{I2CSLST=(u8)(value);}while(0)//设置I2CSLST寄存器
#define IIC_GET_REG_SLST            (I2CSLST)//读取I2CSLST寄存器
#define IIC_SET_REG_SLADR(value)    do{I2CSLADR=(u8)(value);}while(0)//设置I2CSLADR寄存器
#define IIC_GET_REG_SLADR           (I2CSLADR)//读取I2CSLADR寄存器
//-------------功能定义------------//
#define IIC_IT_NUM                  interrupt 24//IIC中断号
/*--------------------------------ADC特殊功能寄存器------------------------------*/
sbit    EADC                        =IE^5;//ADC转换中断允许位
#define ADC_POWER                   0x80  //ADC电源控制位
#define ADC_START                   0x40  //ADC转换启动控制位
#define ADC_FLAG                    0x20  //ADC转换结束标志位
#define ADC_EPWMT                   0x10  //ADC与PWM协同控制标志位
#define ADC_RESFMT                  0x20  //ADC转换结果格式控制位
sbit    PADC                        =IP^5;//ADC中断优先级控制位（低）
#define PADCH                       0x20  //ADC中断优先级控制位（高）
//-------------功能指令------------//
#define ADC_POWER_ON                REG_SET_BIT(ADC_CONTR,ADC_POWER)  //打开ADC的电源
#define ADC_POWER_OFF               REG_RESET_BIT(ADC_CONTR,ADC_POWER)//关闭ADC的电源
#define ADC_IT_ENABLE               do{EADC=1;}while(0)               //打开ADC中断
#define ADC_IT_DISABLE              do{EADC=0;}while(0)               //关闭ADC中断
#define ADC_PWM_ENABLE              REG_SET_BIT(ADC_CONTR,ADC_EPWMT)  //打开ADC与PWM关联
#define ADC_PWM_DISABLE             REG_RESET_BIT(ADC_CONTR,ADC_EPWMT)//关闭ADC与PWM关联
#define ADC_GET_IT_FLAG             (ADC_CONTR & ADC_FLAG)            //获取AD转换结束标志位
#define ADC_CLS_IT_FLAG             REG_RESET_BIT(ADC_CONTR,(ADC_START|ADC_FLAG)) //清除AD转换结束标志位
#define ADC_MEASURE_ON              REG_SET_BIT(ADC_CONTR,ADC_START)  //开始AD转换
#define ADC_SET_CHANNELS(value)     REG_IN_MASK(ADC_CONTR,0x0F,value)//设置ADC的转换通道
#define ADC_SET_ALIGN_LEFT          REG_RESET_BIT(ADC_CFG,ADC_RESFMT)//设置ADC的结果左对齐排列
#define ADC_SET_ALIGN_RIGHT         REG_SET_BIT(ADC_CFG,ADC_RESFMT)//设置ADC的结果右对齐排列
#define ADC_SET_SPEED(value)        REG_IN_MASK(ADC_CFG,0x0F,value)//设置ADC的转换速度
#define ADC_SET_IT_PRIORITY_0       do{IPH&=~PADCH;PADC=0;}while(0)//设置ADC的优先级为0
#define ADC_SET_IT_PRIORITY_1       do{IPH&=~PADCH;PADC=1;}while(0)//设置ADC的优先级为1
#define ADC_SET_IT_PRIORITY_2       do{IPH|= PADCH;PADC=0;}while(0)//设置ADC的优先级为2
#define ADC_SET_IT_PRIORITY_3       do{IPH|= PADCH;PADC=1;}while(0)//设置ADC的优先级为3
//-------------寄存器读取----------//
#define ADC_SET_REG_CONTR(value)    do{ADC_CONTR=(u8)(value);}while(0)//设置ADC_CONTR寄存器
#define ADC_GET_REG_CONTR           (ADC_CONTR)                       //获取ADC_CONTR寄存器的值
#define ADC_SET_REG_CFG(value)      do{ADC_CFG=(u8)(value);}while(0)  //设置ADC_CFG寄存器
#define ADC_GET_REG_CFG             (ADC_CFG)                         //获取ADC_CFG寄存器的值
#define ADC_SET_REG_EXCFG(value)    do{ADCEXCFG=(u8)(value);}while(0) //设置ADC_EXCFG寄存器
#define ADC_GET_REG_EXCFG           (ADCEXCFG)                        //获取ADC_EXCFG寄存器的值
#define ADC_SET_REG_TIM(value)      do{ADC_TIM=(u8)(value);}while(0)  //设置ADC_TIM寄存器
#define ADC_GET_REG_TIM             (ADC_TIM)                         //获取ADC_TIM寄存器的值
#define ADC_GET_REG_RES_HL          ((((u16)ADC_RES)<<8)|(u16)ADC_RESL)//获取ADC结果寄存器的全部
#define ADC_GET_REG_RES_H8          (ADC_RES )  //获取ADC结果寄存器的高8位
#define ADC_GET_REG_RES_L8          (ADC_RESL)  //获取ADC结果寄存器的低8位
//-------------功能定义------------//
#define ADC_IT_NUM                  interrupt 5//ADC的中断号
/*-------------------------------I/O口特殊功能寄存器-----------------------------*/
sbit    P00                         =P0^0;  //P0.0口
sbit    P01                         =P0^1;  //P0.1口
sbit    P02                         =P0^2;  //P0.2口
sbit    P03                         =P0^3;  //P0.3口
sbit    P04                         =P0^4;  //P0.4口
sbit    P05                         =P0^5;  //P0.5口
sbit    P06                         =P0^6;  //P0.6口
sbit    P07                         =P0^7;  //P0.7口
sbit    P10                         =P1^0;  //P1.0口
sbit    P11                         =P1^1;  //P1.1口
sbit    P12                         =P1^2;  //P1.2口
sbit    P13                         =P1^3;  //P1.3口
sbit    P14                         =P1^4;  //P1.4口
sbit    P15                         =P1^5;  //P1.5口
sbit    P16                         =P1^6;  //P1.6口
sbit    P17                         =P1^7;  //P1.7口
sbit    P20                         =P2^0;  //P2.0口
sbit    P21                         =P2^1;  //P2.1口
sbit    P22                         =P2^2;  //P2.2口
sbit    P23                         =P2^3;  //P2.3口
sbit    P24                         =P2^4;  //P2.4口
sbit    P25                         =P2^5;  //P2.5口
sbit    P26                         =P2^6;  //P2.6口
sbit    P27                         =P2^7;  //P2.7口
sbit    P30                         =P3^0;  //P3.0口
sbit    P31                         =P3^1;  //P3.1口
sbit    P32                         =P3^2;  //P3.2口
sbit    P33                         =P3^3;  //P3.3口
sbit    P34                         =P3^4;  //P3.4口
sbit    P35                         =P3^5;  //P3.5口
sbit    P36                         =P3^6;  //P3.6口
sbit    P37                         =P3^7;  //P3.7口
sbit    P40                         =P4^0;  //P4.0口
sbit    P41                         =P4^1;  //P4.1口
sbit    P42                         =P4^2;  //P4.2口
sbit    P43                         =P4^3;  //P4.3口
sbit    P44                         =P4^4;  //P4.4口
sbit    P45                         =P4^5;  //P4.5口
sbit    P46                         =P4^6;  //P4.6口
sbit    P47                         =P4^7;  //P4.7口
sbit    P50                         =P5^0;  //P5.0口
sbit    P51                         =P5^1;  //P5.1口
sbit    P52                         =P5^2;  //P5.2口
sbit    P53                         =P5^3;  //P5.3口
sbit    P54                         =P5^4;  //P5.4口
sbit    P55                         =P5^5;  //P5.5口
sbit    P56                         =P5^6;  //P5.6口
sbit    P57                         =P5^7;  //P5.7口
sbit    P60                         =P6^0;  //P6.0口
sbit    P61                         =P6^1;  //P6.1口
sbit    P62                         =P6^2;  //P6.2口
sbit    P63                         =P6^3;  //P6.3口
sbit    P64                         =P6^4;  //P6.4口
sbit    P65                         =P6^5;  //P6.5口
sbit    P66                         =P6^6;  //P6.6口
sbit    P67                         =P6^7;  //P6.7口
sbit    P70                         =P7^0;  //P7.0口
sbit    P71                         =P7^1;  //P7.1口
sbit    P72                         =P7^2;  //P7.2口
sbit    P73                         =P7^3;  //P7.3口
sbit    P74                         =P7^4;  //P7.4口
sbit    P75                         =P7^5;  //P7.5口
sbit    P76                         =P7^6;  //P7.6口
sbit    P77                         =P7^7;  //P7.7口
/*--------------------------------内核特殊功能寄存器------------------------------*/
sbit    CY                          =PSW^7; //进位标志位
sbit    AC                          =PSW^6; //辅助进位标志位
sbit    F0                          =PSW^5; //留给用户的标志位
sbit    RS1                         =PSW^4; //工作寄存器选择位（高位）
sbit    RS0                         =PSW^3; //工作寄存器选择位（低位）
sbit    OV                          =PSW^2; //溢出标志位
sbit    P                           =PSW^0; //奇偶校验位
#define IF_ODD(_OE_)                ACC=_OE_;if(P)//判断是不是奇数
/*------------------------------时钟管理特殊功能寄存器----------------------------*/
//-------------功能指令------------//
#define CLK_SET_SOURCE_HSI          do{CKSEL=((CKSEL&(~0x03))|0x00);}while(0)//设置时钟源为内部高速IRC
#define CLK_SET_SOURCE_HSE          do{CKSEL=((CKSEL&(~0x03))|0x01);}while(0)//设置时钟源为外部高速晶振
#define CLK_SET_SOURCE_LSE          do{CKSEL=((CKSEL&(~0x03))|0x02);}while(0)//设置时钟源为外部低速晶振
#define CLK_SET_SOURCE_LSI          do{CKSEL=((CKSEL&(~0x03))|0x03);}while(0)//设置时钟源为内部低速IRC
#define CLK_HSI_POWER_ON            do{HIRCCR=((HIRCCR&(~0x81))|0x80);}while(!(HIRCCR&0x01))//开启HSI电源
#define CLK_HSI_POWER_OFF           do{HIRCCR=0x00;}while(0)//关闭HSI电源
#define CLK_HSE_A_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0x80);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成有源晶振
#define CLK_HSE_P_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0xC0);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成无源晶振
#define CLK_HSE_POWER_OFF           do{XOSCCR=0x00;}while(0)//关闭HSE电源
#define CLK_HSE_GAIN_ENABLE         do{XOSCCR|= 0x20;}while(0)//打开外部高速晶振增益
#define CLK_HSE_GAIN_DISABLE        do{XOSCCR&=~0x20;}while(0)//关闭外部高速晶振增益
#define CLK_LSE_POWER_ON            do{X32KCR=((X32KCR&(~0x81))|0x80);}while(!(X32KCR&0x01))//开启LSE电源
#define CLK_LSE_POWER_OFF           do{X32KCR  = 0x00;}while(0)//关闭LSE电源
#define CLK_LSE_GAIN_ENABLE         do{X32KCR |= 0x40;}while(0)//打开外部低速晶振增益
#define CLK_LSE_GAIN_DISABLE        do{X32KCR &=~0x40;}while(0)//关闭外部低速晶振增益
#define CLK_LSI_POWER_ON            do{IRC32KCR=((IRC32KCR&(~0x81))|0x80);}while(!(IRC32KCR&0x01))//开启LSI电源
#define CLK_LSI_POWER_OFF           do{IRC32KCR= 0x00;}while(0)//关闭LSI电源
#define CLK_SET_OUT_TO_P54_FA       do{CKSEL  &=~0x08;}while(0)//设置时钟输出脚为P5.4(适用于STC8F和STC8A)
#define CLK_SET_OUT_TO_P16_FA       do{CKSEL  |= 0x08;}while(0)//设置时钟输出脚为P1.6(适用于STC8F和STC8A)
#define CLK_OUT_SET_DIV_FA(value)   REG_IN_MASK(CKSEL,0xF0,value)//设置时钟输出分频(适用于STC8F和STC8A)
#define CLK_SET_OUT_TO_P54_GH       do{MCLKOCR&=~0x80;}while(0)//设置时钟输出脚为P5.4(适用于STC8G和STC8H)
#define CLK_SET_OUT_TO_P16_GH       do{MCLKOCR|= 0x80;}while(0)//设置时钟输出脚为P1.6(适用于STC8G和STC8H)
#define CLK_OUT_SET_DIV_GH(value)   REG_IN_MASK(MCLKOCR,0x7F,value)//设置时钟输出分频(适用于STC8G和STC8H)
//-------------寄存器读取----------//
#define CLK_SET_REG_CLKDIV(value)   do{CLKDIV=(u8)value;}while(0)//设置CLKDIV寄存器
#define CLK_GET_REG_CLKDIV          (CLKDIV)//获取CLKDIV寄存器
/*--------------------------------中断特殊功能寄存器-----------------------------*/
sbit    EA                          =IE^7;//总中断允许控制位
sbit    ELVD                        =IE^6;//低压检测中断允许位
#define LVDF                        0x20  //低压检测中断请求标志
#define PLVDH                       0x40  //低压检测中断优先级（高位）
sbit    PLVD                        =IP^6;//低压检测中断优先级（低位）
//-------------功能指令------------//
#define EA_ENABLE                   do{EA=1;}while(0)//打开总中断开关
#define EA_DISABLE                  do{EA=0;}while(0)//关闭总中断开关
#define LVD_IT_ENABLE               do{ELVD=1;}while(0)//打开低压中断开关
#define LVD_IT_DISABLE              do{ELVD=0;}while(0)//关闭低压中断开关
#define LVD_GET_IT_FLAG             (PCON & LVDF)
#define LVD_CLS_IT_FLAG             REG_RESET_BIT(PCON,LVDF)
#define LVD_SET_IT_PRIORITY_0       do{IPH&=~PLVDH;PLVD=0;}while(0)//设置LVD中断的优先级为0
#define LVD_SET_IT_PRIORITY_1       do{IPH&=~PLVDH;PLVD=1;}while(0)//设置LVD中断的优先级为1
#define LVD_SET_IT_PRIORITY_2       do{IPH|= PLVDH;PLVD=0;}while(0)//设置LVD中断的优先级为2
#define LVD_SET_IT_PRIORITY_3       do{IPH|= PLVDH;PLVD=1;}while(0)//设置LVD中断的优先级为3
/*--------------------------------LCM特殊功能寄存器------------------------------*/
#define LCMIFIE                     0x80//LCM接口中断使能控制位
#define D16_D8                      0x02//LCM接口数据宽度控制位
#define M68_I80                     0x01//LCM接口模式选择位
#define ELCMIF                      0x80//LCM接口使能控制位
#define LCMIFIF                     0x01//LCM接口中断请求标志位
//-------------功能指令------------//
#define LCM_IT_ENABLE               do{LCMIFCFG|= LCMIFIE;}while(0)//打开LCM接口中断
#define LCM_IT_DISABLE              do{LCMIFCFG&=~LCMIFIE;}while(0)//关闭LCM接口中断
#define LCM_SET_IT_PRIORITY_0       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x00;}while(0)//设置LCM中断的优先级为0
#define LCM_SET_IT_PRIORITY_1       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x10;}while(0)//设置LCM中断的优先级为1
#define LCM_SET_IT_PRIORITY_2       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x20;}while(0)//设置LCM中断的优先级为2
#define LCM_SET_IT_PRIORITY_3       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x30;}while(0)//设置LCM中断的优先级为3
#define LCM_SET_DATABUS_NA_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x00;}while(0)//设置LCM的数据线为P2
#define LCM_SET_DATABUS_NA_P6       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x04;}while(0)//设置LCM的数据线为P6
#define LCM_SET_DATABUS_P2_P0       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x02;}while(0)//设置LCM的数据线为P2~P0
#define LCM_SET_DATABUS_P6_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x06;}while(0)//设置LCM的数据线为P6~P2
#define LCM_SET_DATABUS_P2_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0A;}while(0)//设置LCM的数据线为P2~P7
#define LCM_SET_DATABUS_P6_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0E;}while(0)//设置LCM的数据线为P6~P7
#define LCM_SET_MODE_I8080          do{LCMIFCFG&=~M68_I80;}while(0)//设置LCM的工作模式是8080
#define LCM_SET_MODE_M6800          do{LCMIFCFG|= M68_I80;}while(0)//设置LCM的工作模式是6800
#define LCM_SET_P41_P44_P43         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x00;}while(0)//设置RS、RD、WR分别为P41、P44、P43
#define LCM_SET_P41_P37_P46         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x20;}while(0)//设置RS、RD、WR分别为P41、P37、P46
#define LCM_SET_P41_P42_P40         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x40;}while(0)//设置RS、RD、WR分别为P41、P42、P40
#define LCM_SET_P40_P37_P36         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x60;}while(0)//设置RS、RD、WR分别为P40、P37、P36
#define LCM_WRITE_CMD               do{LCMIFCR=(ELCMIF|0x04);}while(0)//向LCM接口发送一个指令
#define LCM_WRITE_DATA              do{LCMIFCR=(ELCMIF|0x05);}while(0)//向LCM接口发送一个数据
#define LCM_READ_CMD                do{LCMIFCR=(ELCMIF|0x06);}while(0)//向LCM接口接收一个指令
#define LCM_READ_DATA               do{LCMIFCR=(ELCMIF|0x07);}while(0)//向LCM接口接收一个数据
#define LCM_GET_FLAG                (LCMIFSTA & LCMIFIF)              //获取LCM接口中断标志位
#define LCM_CLS_FLAG                do{LCMIFSTA&=~LCMIFIF;}while(0)   //清除LCM接口中断标志位
/*------------------------------PCA/PWM特殊功能寄存器----------------------------*/
sbit    CF                          =CCON^7;//PCA计数器溢出标志位	
sbit    CR                          =CCON^6;//PCA计数运行控制位
sbit    CCF3                        =CCON^3;//PCA3模块中断标志位
sbit    CCF2                        =CCON^2;//PCA2模块中断标志位
sbit    CCF1                        =CCON^1;//PCA1模块中断标志位
sbit    CCF0                        =CCON^0;//PCA0模块中断标志位
#define CIDL                        0x80    //空闲模式下是否停止PCA计数
#define ECF                         0x01    //PCA计数器溢出中断允许位
#define ECOM0_3                     0x40    //允许PCA模块0~3的比较功能
#define CCAPP0_3                    0x20    //允许PCA模块0~3进行上升沿捕获
#define CCAPN0_3                    0x10    //允许PCA模块0~3进行下降沿捕获
#define MAT0_3                      0x08    //允许PCA模块0~3的匹配功能
#define TOG0_3                      0x04    //允许PCA模块0~3的高速脉冲输出功能
#define PWM0_3                      0x02    //允许PCA模块0~3的脉宽调制输出功能
#define ECCF0_3                     0x01    //允许PCA模块0~3的匹配/捕获中断
//-------------功能指令------------//
#define PCA_POWER_ON                do{CR=1;}while(0)//打开PCA模块
#define PCA_POWER_OFF               do{CR=0;}while(0)//关闭PCA模块
#define PCA_IT_ENABLE               do{CMOD|= ECF;}while(0)//打开PCA计数器的溢出中断
#define PCA_IT_DISABLE              do{CMOD&=~ECF;}while(0)//关闭PCA计数器的溢出中断
#define PCA_GET_IT_FLAG             (CF)                   //获取PCA计数器溢出中断标志位
#define PCA_CLS_IT_FLAG             do{CF=0;}while(0)      //清除PCA计数器溢出中断标志位
#define PCA_SET_IDLE_ENABLE         do{CMOD&=~CIDL;}while(0)//PCA在空闲模式下继续计数
#define PCA_SET_IDLE_DISABLE        do{CMOD|= CIDL;}while(0)//PCA在空闲模式下停止计数
#define PCA_SET_CPS(value)          REG_IN_MASK(CMOD,0x0E,value)//设置PCA计数脉冲来源
#define PCA_SET_PIN(value)          REG_IN_MASK(P_SW1,0x30,value)//设置PCA的输出引脚
#define PCA0_GET_IT_FLAG            (CCF0)                        //获取PCA0捕获中断标志位
#define PCA0_CLS_IT_FLAG            do{CCF0=0;}while(0)           //清除PCA0捕获中断标志位
#define PCA0_SET_ECOM_ENABLE        do{CCAPM0|= ECOM0_3; }while(0)//打开PCA模块0的比较功能
#define PCA0_SET_ECOM_DISABLE       do{CCAPM0&=~ECOM0_3; }while(0)//关闭PCA模块0的比较功能
#define PCA0_SET_CCAPP_ENABLE       do{CCAPM0|= CCAPP0_3;}while(0)//打开PCA模块0的上升沿捕获功能
#define PCA0_SET_CCAPP_DISABLE      do{CCAPM0&=~CCAPP0_3;}while(0)//关闭PCA模块0的上升沿捕获功能
#define PCA0_SET_CCAPN_ENABLE       do{CCAPM0|= CCAPN0_3;}while(0)//打开PCA模块0的下降沿捕获功能
#define PCA0_SET_CCAPN_DISABLE      do{CCAPM0&=~CCAPN0_3;}while(0)//关闭PCA模块0的下降沿捕获功能
#define PCA0_SET_MAT_ENABLE         do{CCAPM0|= MAT0_3;  }while(0)//打开PCA模块0的匹配功能
#define PCA0_SET_MAT_DISABLE        do{CCAPM0&=~MAT0_3;  }while(0)//关闭PCA模块0的匹配功能
#define PCA0_SET_TOG_ENABLE         do{CCAPM0|= TOG0_3;  }while(0)//打开PCA模块0的高速脉冲输出功能
#define PCA0_SET_TOG_DISABLE        do{CCAPM0&=~TOG0_3;  }while(0)//关闭PCA模块0的高速脉冲输出功能
#define PCA0_SET_PWM_ENABLE         do{CCAPM0|= PWM0_3;  }while(0)//打开PCA模块0的脉宽调制输出功能
#define PCA0_SET_PWM_DISABLE        do{CCAPM0&=~PWM0_3;  }while(0)//关闭PCA模块0的脉宽调制输出功能
#define PCA0_SET_ECCF_ENABLE        do{CCAPM0|= ECCF0_3; }while(0)//打开PCA模块0的匹配/捕获中断
#define PCA0_SET_ECCF_DISABLE       do{CCAPM0&=~ECCF0_3; }while(0)//关闭PCA模块0的匹配/捕获中断
#define PCA1_GET_IT_FLAG            (CCF1)                        //获取PCA1捕获中断标志位
#define PCA1_CLS_IT_FLAG            do{CCF1=0;}while(0)           //清除PCA1捕获中断标志位
#define PCA1_SET_ECOM_ENABLE        do{CCAPM1|= ECOM0_3; }while(0)//打开PCA模块1的比较功能
#define PCA1_SET_ECOM_DISABLE       do{CCAPM1&=~ECOM0_3; }while(0)//关闭PCA模块1的比较功能
#define PCA1_SET_CCAPP_ENABLE       do{CCAPM1|= CCAPP0_3;}while(0)//打开PCA模块1的上升沿捕获功能
#define PCA1_SET_CCAPP_DISABLE      do{CCAPM1&=~CCAPP0_3;}while(0)//关闭PCA模块1的上升沿捕获功能
#define PCA1_SET_CCAPN_ENABLE       do{CCAPM1|= CCAPN0_3;}while(0)//打开PCA模块1的下降沿捕获功能
#define PCA1_SET_CCAPN_DISABLE      do{CCAPM1&=~CCAPN0_3;}while(0)//关闭PCA模块1的下降沿捕获功能
#define PCA1_SET_MAT_ENABLE         do{CCAPM1|= MAT0_3;  }while(0)//打开PCA模块1的匹配功能
#define PCA1_SET_MAT_DISABLE        do{CCAPM1&=~MAT0_3;  }while(0)//关闭PCA模块1的匹配功能
#define PCA1_SET_TOG_ENABLE         do{CCAPM1|= TOG0_3;  }while(0)//打开PCA模块1的高速脉冲输出功能
#define PCA1_SET_TOG_DISABLE        do{CCAPM1&=~TOG0_3;  }while(0)//关闭PCA模块1的高速脉冲输出功能
#define PCA1_SET_PWM_ENABLE         do{CCAPM1|= PWM0_3;  }while(0)//打开PCA模块1的脉宽调制输出功能
#define PCA1_SET_PWM_DISABLE        do{CCAPM1&=~PWM0_3;  }while(0)//关闭PCA模块1的脉宽调制输出功能
#define PCA1_SET_ECCF_ENABLE        do{CCAPM1|= ECCF0_3; }while(0)//打开PCA模块1的匹配/捕获中断
#define PCA1_SET_ECCF_DISABLE       do{CCAPM1&=~ECCF0_3; }while(0)//关闭PCA模块1的匹配/捕获中断
#define PCA2_GET_IT_FLAG            (CCF2)                        //获取PCA2捕获中断标志位
#define PCA2_CLS_IT_FLAG            do{CCF2=0;}while(0)           //清除PCA2捕获中断标志位
#define PCA2_SET_ECOM_ENABLE        do{CCAPM2|= ECOM0_3; }while(0)//打开PCA模块2的比较功能
#define PCA2_SET_ECOM_DISABLE       do{CCAPM2&=~ECOM0_3; }while(0)//关闭PCA模块2的比较功能
#define PCA2_SET_CCAPP_ENABLE       do{CCAPM2|= CCAPP0_3;}while(0)//打开PCA模块2的上升沿捕获功能
#define PCA2_SET_CCAPP_DISABLE      do{CCAPM2&=~CCAPP0_3;}while(0)//关闭PCA模块2的上升沿捕获功能
#define PCA2_SET_CCAPN_ENABLE       do{CCAPM2|= CCAPN0_3;}while(0)//打开PCA模块2的下降沿捕获功能
#define PCA2_SET_CCAPN_DISABLE      do{CCAPM2&=~CCAPN0_3;}while(0)//关闭PCA模块2的下降沿捕获功能
#define PCA2_SET_MAT_ENABLE         do{CCAPM2|= MAT0_3;  }while(0)//打开PCA模块2的匹配功能
#define PCA2_SET_MAT_DISABLE        do{CCAPM2&=~MAT0_3;  }while(0)//关闭PCA模块2的匹配功能
#define PCA2_SET_TOG_ENABLE         do{CCAPM2|= TOG0_3;  }while(0)//打开PCA模块2的高速脉冲输出功能
#define PCA2_SET_TOG_DISABLE        do{CCAPM2&=~TOG0_3;  }while(0)//关闭PCA模块2的高速脉冲输出功能
#define PCA2_SET_PWM_ENABLE         do{CCAPM2|= PWM0_3;  }while(0)//打开PCA模块2的脉宽调制输出功能
#define PCA2_SET_PWM_DISABLE        do{CCAPM2&=~PWM0_3;  }while(0)//关闭PCA模块2的脉宽调制输出功能
#define PCA2_SET_ECCF_ENABLE        do{CCAPM2|= ECCF0_3; }while(0)//打开PCA模块2的匹配/捕获中断
#define PCA2_SET_ECCF_DISABLE       do{CCAPM2&=~ECCF0_3; }while(0)//关闭PCA模块2的匹配/捕获中断
#define PCA3_GET_IT_FLAG            (CCF3)                        //获取PCA3捕获中断标志位
#define PCA3_CLS_IT_FLAG            do{CCF3=0;}while(0)           //清除PCA3捕获中断标志位
#define PCA3_SET_ECOM_ENABLE        do{CCAPM3|= ECOM0_3;  }while(0)//打开PCA模块3的比较功能
#define PCA3_SET_ECOM_DISABLE       do{CCAPM3&=~ECOM0_3;  }while(0)//关闭PCA模块3的比较功能
#define PCA3_SET_CCAPP_ENABLE       do{CCAPM3|= CCAPP0_3; }while(0)//打开PCA模块3的上升沿捕获功能
#define PCA3_SET_CCAPP_DISABLE      do{CCAPM3&=~CCAPP0_3; }while(0)//关闭PCA模块3的上升沿捕获功能
#define PCA3_SET_CCAPN_ENABLE       do{CCAPM3|= CCAPN0_3; }while(0)//打开PCA模块3的下降沿捕获功能
#define PCA3_SET_CCAPN_DISABLE      do{CCAPM3&=~CCAPN0_3; }while(0)//关闭PCA模块3的下降沿捕获功能
#define PCA3_SET_MAT_ENABLE         do{CCAPM3|= MAT0_3;   }while(0)//打开PCA模块3的匹配功能
#define PCA3_SET_MAT_DISABLE        do{CCAPM3&=~MAT0_3;   }while(0)//关闭PCA模块3的匹配功能
#define PCA3_SET_TOG_ENABLE         do{CCAPM3|= TOG0_3;   }while(0)//打开PCA模块3的高速脉冲输出功能
#define PCA3_SET_TOG_DISABLE        do{CCAPM3&=~TOG0_3;   }while(0)//关闭PCA模块3的高速脉冲输出功能
#define PCA3_SET_PWM_ENABLE         do{CCAPM3|= PWM0_3;   }while(0)//打开PCA模块3的脉宽调制输出功能
#define PCA3_SET_PWM_DISABLE        do{CCAPM3&=~PWM0_3;   }while(0)//关闭PCA模块3的脉宽调制输出功能
#define PCA3_SET_ECCF_ENABLE        do{CCAPM3|= ECCF0_3;  }while(0)//打开PCA模块3的匹配/捕获中断
#define PCA3_SET_ECCF_DISABLE       do{CCAPM3&=~ECCF0_3;  }while(0)//关闭PCA模块3的匹配/捕获中断
//-------------寄存器读取----------//
#define PCA_SET_REG_CCON(value)     do{CCON=(u8)(value);}while(0)//设置CCON寄存器
#define PCA_GET_REG_CCON            (CCON)                       //读取CCON寄存器
#define PCA_SET_REG_CMOD(value)     do{CMOD=(u8)(value);}while(0)//设置CMOD寄存器
#define PCA_GET_REG_CMOD            (CMOD)                       //读取CMOD寄存器
#define PCA_SET_REG_CL(value)       do{CL=(u8)(value);}while(0)  //设置CL寄存器
#define PCA_GET_REG_CL              (CL)                         //读取CL寄存器
#define PCA_SET_REG_CH(value)       do{CH=(u8)(value);}while(0)  //设置CH寄存器
#define PCA_GET_REG_CH              (CH)                         //读取CH寄存器
#define PCA_SET_REG_CHL(value)      do{CL=(u8)(value);CH=(u8)(value>>8);}while(0)//设置PCA的计数值
#define PCA_GET_REG_CHL             ((((u16)CH)<<8)|(u16)CL)       //获取PCA的计数值
#define PCA_SET_REG_CCAPM0(value)   do{CCAPM0=(u8)value;}while(0)  //设置CCAPM0寄存器
#define PCA_GET_REG_CCAPM0          (CCAPM0)                       //读取CCAPM0寄存器
#define PCA_SET_REG_CCAP0L(value)   do{CCAP0L=(u8)(value);}while(0)//设置CCAP0L寄存器
#define PCA_GET_REG_CCAP0L          (CCAP0L)                       //读取CCAP0L寄存器
#define PCA_SET_REG_CCAP0H(value)   do{CCAP0H=(u8)(value);}while(0)//设置CCAP0H寄存器
#define PCA_GET_REG_CCAP0H          (CCAP0H)                       //读取CCAP0H寄存器
#define PCA_SET_REG_CCAP0HL(value)  do{CCAP0L=(u8)(value);CCAP0H=(u8)(value>>8);}while(0)//设置PCA0的捕获值
#define PCA_GET_REG_CCAP0HL         ((((u16)CCAP0H)<<8)|(u16)CCAP0L) //获取PCA0的捕获值
#define PCA_SET_REG_PWM0(value)     do{PCA_PWM0=(u8)(value);}while(0)//设置PCA_PWM0寄存器
#define PCA_GET_REG_PWM0            (PCA_PWM0)                       //读取PCA_PWM0寄存器
#define PCA_SET_REG_CCAPM1(value)   do{CCAPM1=(u8)value;}while(0)    //设置CCAPM1寄存器
#define PCA_GET_REG_CCAPM1          (CCAPM1)                         //读取CCAPM1寄存器
#define PCA_SET_REG_CCAP1L(value)   do{CCAP1L=(u8)(value);}while(0)  //设置CCAP1L寄存器
#define PCA_GET_REG_CCAP1L          (CCAP1L)                         //读取CCAP1L寄存器
#define PCA_SET_REG_CCAP1H(value)   do{CCAP1H=(u8)(value);}while(0)  //设置CCAP1H寄存器
#define PCA_GET_REG_CCAP1H          (CCAP1H)                         //读取CCAP1H寄存器
#define PCA_SET_REG_CCAP1HL(value)  do{CCAP1L=(u8)(value);CCAP1H=(u8)(value>>8);}while(0)//设置PCA1的捕获值
#define PCA_GET_REG_CCAP1HL         ((((u16)CCAP1H)<<8)|(u16)CCAP1L) //获取PCA1的捕获值
#define PCA_SET_REG_PWM1(value)     do{PCA_PWM1=(u8)(value);}while(0)//设置PCA_PWM1寄存器
#define PCA_GET_REG_PWM1            (PCA_PWM1)                       //读取PCA_PWM1寄存器
#define PCA_SET_REG_CCAPM2(value)   do{CCAPM2=(u8)value;}while(0)    //设置CCAPM2寄存器
#define PCA_GET_REG_CCAPM2          (CCAPM2)                         //读取CCAPM2寄存器
#define PCA_SET_REG_CCAP2L(value)   do{CCAP2L=(u8)(value);}while(0)  //设置CCAP2L寄存器
#define PCA_GET_REG_CCAP2L          (CCAP2L)                         //读取CCAP2L寄存器
#define PCA_SET_REG_CCAP2H(value)   do{CCAP2H=(u8)(value);}while(0)  //设置CCAP2H寄存器
#define PCA_GET_REG_CCAP2H          (CCAP2H)                         //读取CCAP2H寄存器
#define PCA_SET_REG_CCAP2HL(value)  do{CCAP2L=(u8)(value);CCAP2H=(u8)(value>>8);}while(0)//设置PCA2的捕获值
#define PCA_GET_REG_CCAP2HL         ((((u16)CCAP2H)<<8)|(u16)CCAP2L) //获取PCA2的捕获值
#define PCA_SET_REG_PWM2(value)     do{PCA_PWM2=(u8)(value);}while(0)//设置PCA_PWM2寄存器
#define PCA_GET_REG_PWM2            (PCA_PWM2)                       //读取PCA_PWM2寄存器
#define PCA_SET_REG_CCAPM3(value)   do{CCAPM3=(u8)value;}while(0)    //设置CCAPM3寄存器
#define PCA_GET_REG_CCAPM3          (CCAPM3)                         //读取CCAPM3寄存器
#define PCA_SET_REG_CCAP3L(value)   do{CCAP3L=(u8)value;}while(0)    //设置CCAP3L寄存器
#define PCA_GET_REG_CCAP3L          (CCAP3L)                         //读取CCAP3L寄存器
#define PCA_SET_REG_CCAP3H(value)   do{CCAP3H=(u8)value;}while(0)    //设置CCAP3H寄存器
#define PCA_GET_REG_CCAP3H          (CCAP3H)                         //读取CCAP3H寄存器
#define PCA_SET_REG_CCAP3HL(value)  do{CCAP3L=(u8)(value);CCAP3H=(u8)(value>>8);}while(0)//设置PCA3的捕获值
#define PCA_GET_REG_CCAP3HL         ((((u16)CCAP3H)<<8)|(u16)CCAP3L) //获取PCA3的捕获值
#define PCA_SET_REG_PWM3(value)     do{PCA_PWM3=(u8)value;}while(0)  //设置PCA_PWM3寄存器
#define PCA_GET_REG_PWM3            (PCA_PWM3)                       //读取PCA_PWM3寄存器
//-------------功能定义------------//
#define PCA_IT_NUM                  interrupt 7//PCA中断号
/*------------------------------BMM/DMA特殊功能寄存器----------------------------*/
#define M2MIE                       0x80//DMA_MEM_MEM中断使能控制位
#define TXACO                       0x40//DMA_MEM_MEM源地址方向控制位
#define RXACO                       0x20//DMA_MEM_MEM目标地址方向控制位
#define ENM2M                       0x80//DMA_MEM_MEM功能使能位
#define M2MTRIG                     0x40//DMA_MEM_MEM功能触发位
#define ADCIE                       0x80//DMA_ADC_MEM中断使能控制位
#define ENADC                       0x80//DMA_ADC_MEM功能使能位
#define A2MTRIG                     0x40//DMA_ADC_MEM功能触发位
#define SPIIE                       0x80//DMA_SPI_MEM中断使能控制位
#define ACT_TX                      0x40//DMA_SPI_MEM发送数据控制位
#define ACT_RX                      0x20//DMA_SPI_MEM接收数据控制位
#define ENSPI                       0x80//DMA_SPI_MEM功能使能位
#define S2MTRIG_M                   0x40//DMA_SPI_MEM主机功能触发位
#define S2MTRIG_S                   0x20//DMA_SPI_MEM从机功能触发位
#define CLRFIFO                     0x01//DMA_SPI_MEM清除FIFO位
#define SPIIF                       0x01//DMA_SPI_MEM中断请求标志位
#define SPIRXLOSS                   0x02//DMA_SPI_MEM接收数据丢弃标志位
#define SPITXOVW                    0x04//DMA_SPI_MEM数据覆盖标志位
#define WRPSS                       0x04//DMA_SPI_MEM使能SS脚控制位
#define URTIE                       0x80//DMA_UART_MEM发送中断使能控制位
#define ENURT                       0x80//DMA_UART_MEM发送功能使能位
#define URTTRIG                     0x40//DMA_UART_MEM发送触发控制位
#define URTIF                       0x01//DMA_UART_MEM发送中断请求标志位
#define URTXOVW                     0x04//DMA_UART_MEM发送数据覆盖标志位
#define URRIE                       0x80//DMA_UART_MEM接收中断使能控制位
#define ENURR                       0x80//DMA_UART_MEM接收功能使能位
#define URRTRIG                     0x40//DMA_UART_MEM接收触发控制位
#define URRIF                       0x01//DMA_UART_MEM接收中断请求标志位
#define URRXOVW                     0x04//DMA_UART_MEM接收数据覆盖标志位
#define LCMIE                       0x80//DMA_LCM_MEM中断使能控制位
#define ENLCM                       0x80//DMA_LCM_MEM功能使能位
#define TRIGWC                      0x40//DMA_LCM_MEM发送命令模式触发控制位
#define TRIGWD                      0x20//DMA_LCM_MEM发送数据模式触发控制位
#define TRIGRC                      0x10//DMA_LCM_MEM接收指令模式触发控制位
#define TRIGRD                      0x08//DMA_LCM_MEM接收数据模式触发控制位
#define LCMIF                       0x01//DMA_LCM_MEM中断请求标志位
#define LCMTXOVW                    0x02//DMA_LCM_MEM数据覆盖标志位
//-------------功能指令------------//
#define MEM_MEM_IT_ENABLE               do{DMA_M2M_CFG|= M2MIE;}while(0)//打开MEM到MEM的中断使能
#define MEM_MEM_IT_DISABLE              do{DMA_M2M_CFG&=~M2MIE;}while(0)//改变MEM到MEM的中断使能
#define MEM_MEM_SET_TX_ADD              do{DMA_M2M_CFG&=~TXACO;}while(0)//MEM到MEM的源地址递增
#define MEM_MEM_SET_TX_DEC              do{DMA_M2M_CFG|= TXACO;}while(0)//MEM到MEM的源地址递减
#define MEM_MEM_SET_RX_ADD              do{DMA_M2M_CFG&=~RXACO;}while(0)//MEM到MEM的目标地址递增
#define MEM_MEM_SET_RX_DEC              do{DMA_M2M_CFG|= RXACO;}while(0)//MEM到MEM的目标地址递减
#define MEM_MEM_SET_IT_PRIORITY_0       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x00);}while(0)//设置MEM到MEM的中断优先级为0
#define MEM_MEM_SET_IT_PRIORITY_1       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x04);}while(0)//设置MEM到MEM的中断优先级为1
#define MEM_MEM_SET_IT_PRIORITY_2       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x08);}while(0)//设置MEM到MEM的中断优先级为2
#define MEM_MEM_SET_IT_PRIORITY_3       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到MEM的中断优先级为3
#define MEM_MEM_SET_BUS_PRIORITY_0      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x00);}while(0)//设置MEM到MEM的总线优先级为0
#define MEM_MEM_SET_BUS_PRIORITY_1      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x01);}while(0)//设置MEM到MEM的总线优先级为1
#define MEM_MEM_SET_BUS_PRIORITY_2      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x02);}while(0)//设置MEM到MEM的总线优先级为2
#define MEM_MEM_SET_BUS_PRIORITY_3      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x03);}while(0)//设置MEM到MEM的总线优先级为3
#define MEM_MEM_ENABLE                  do{DMA_M2M_CR|= ENM2M;}while(0)  //打开MEM到MEM功能
#define MEM_MEM_DISABLE                 do{DMA_M2M_CR&=~ENM2M;}while(0)  //关闭MEM到MEM功能
#define MEM_MEM_START                   do{DMA_M2M_CR|= M2MTRIG;}while(0)//开始一次MEM到MEM的传输
#define MEM_MEM_GET_FLAG                (DMA_M2M_STA)                    //获取MEM到MEM传输的状态
#define MEM_MEM_CLS_FLAG                do{DMA_M2M_STA=0;}while(0)       //清除MEM到MEM的状态值
#define MEM_MEM_SET_COUNT_MAX(value)    do{DMA_M2M_AMT=(u8)(value);}while(0)//设置MEM到MEM传输的总字节数
#define MEM_MEM_GET_COUNT_DONE          (DMA_M2M_DONE)                   //获取MEM到MEM已经传输完成的字节数
#define MEM_MEM_SET_TX_ADDR(value)      do{DMA_M2M_TXA=(u16)(value);}while(0)//设置MEM到MEM的源地址
#define MEM_MEM_SET_RX_ADDR(value)      do{DMA_M2M_RXA=(u16)(value);}while(0)//设置MEM到MEM的目标地址
#define ADC_MEM_IT_ENABLE               do{DMA_ADC_CFG|= ADCIE;}while(0)//打开ADC到MEM的中断使能
#define ADC_MEM_IT_DISABLE              do{DMA_ADC_CFG&=~ADCIE;}while(0)//关闭ADC到MEM的中断使能
#define ADC_MEM_SET_IT_PRIORITY_0       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x00);}while(0)//设置ADC到MEM的中断优先级为0
#define ADC_MEM_SET_IT_PRIORITY_1       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x04);}while(0)//设置ADC到MEM的中断优先级为1
#define ADC_MEM_SET_IT_PRIORITY_2       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x08);}while(0)//设置ADC到MEM的中断优先级为2
#define ADC_MEM_SET_IT_PRIORITY_3       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x0C);}while(0)//设置ADC到MEM的中断优先级为3
#define ADC_MEM_SET_BUS_PRIORITY_0      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x00);}while(0)//设置ADC到MEM的总线优先级为0
#define ADC_MEM_SET_BUS_PRIORITY_1      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x01);}while(0)//设置ADC到MEM的总线优先级为1
#define ADC_MEM_SET_BUS_PRIORITY_2      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x02);}while(0)//设置ADC到MEM的总线优先级为2
#define ADC_MEM_SET_BUS_PRIORITY_3      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x03);}while(0)//设置ADC到MEM的总线优先级为3
#define ADC_MEM_ENABLE                  do{DMA_ADC_CR|= ENADC;}while(0)  //打开ADC到MEM功能
#define ADC_MEM_DISABLE                 do{DMA_ADC_CR&=~ENADC;}while(0)  //关闭ADC到MEM功能
#define ADC_MEM_START                   do{DMA_ADC_CR|= A2MTRIG;}while(0)//开始一次ADC到MEM的传输
#define ADC_MEM_GET_FLAG                (DMA_ADC_STA)                    //获取ADC到MEM传输的状态
#define ADC_MEM_CLS_FLAG                do{DMA_ADC_STA=0;}while(0)       //清除ADC到MEM的状态值
#define ADC_MEM_SET_RX_ADDR(value)      do{DMA_ADC_RXA=(u16)(value);}while(0)//设置接收ADC数据的地址
#define ADC_MEM_SET_CH_COUNT(value)     do{DMA_ADC_CFG2=((u8)(value)&0x0F);}while(0)//设置每个通道采集多少次
#define ADC_MEM_SET_CH_0_7_EN(value)    do{DMA_ADC_CHSW1=(u8)(value);}while(0)//设置参与ADC_MEM传输的通道（0~7）
#define ADC_MEM_SET_CH_8_15_EN(value)   do{DMA_ADC_CHSW0=(u8)(value);}while(0)//设置参与ADC_MEM传输的通道（8~15）
#define SPI_MEM_IT_ENABLE               do{DMA_SPI_CFG|= SPIIE;}while(0)//打开SPI到MEM的中断使能
#define SPI_MEM_IT_DISABLE              do{DMA_SPI_CFG&=~SPIIE;}while(0)//关闭SPI到MEM的中断使能
#define SPI_MEM_SET_TX_ENABLE           do{DMA_SPI_CFG|= ACT_TX;}while(0)//允许SPI_MEM发送数据
#define SPI_MEM_SET_TX_DISABLE          do{DMA_SPI_CFG&=~ACT_TX;}while(0)//禁止SPI_MEM发送数据
#define SPI_MEM_SET_RX_ENABLE           do{DMA_SPI_CFG|= ACT_RX;}while(0)//允许SPI_MEM接收数据
#define SPI_MEM_SET_RX_DISABLE          do{DMA_SPI_CFG&=~ACT_RX;}while(0)//禁止SPI_MEM接收数据
#define SPI_MEM_SET_IT_PRIORITY_0       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x00);}while(0)//设置SPI到MEM的中断优先级为0
#define SPI_MEM_SET_IT_PRIORITY_1       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x04);}while(0)//设置SPI到MEM的中断优先级为1
#define SPI_MEM_SET_IT_PRIORITY_2       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x08);}while(0)//设置SPI到MEM的中断优先级为2
#define SPI_MEM_SET_IT_PRIORITY_3       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x0C);}while(0)//设置SPI到MEM的中断优先级为3
#define SPI_MEM_SET_BUS_PRIORITY_0      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x00);}while(0)//设置SPI到MEM的总线优先级为0
#define SPI_MEM_SET_BUS_PRIORITY_1      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x01);}while(0)//设置SPI到MEM的总线优先级为1
#define SPI_MEM_SET_BUS_PRIORITY_2      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x02);}while(0)//设置SPI到MEM的总线优先级为2
#define SPI_MEM_SET_BUS_PRIORITY_3      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x03);}while(0)//设置SPIC到MEM的总线优先级为3
#define SPI_MEM_ENABLE                  do{DMA_SPI_CR|= ENSPI;}while(0)     //打开SPI到MEM功能
#define SPI_MEM_DISABLE                 do{DMA_SPI_CR&=~ENSPI;}while(0)     //关闭SPI到MEM功能
#define SPI_MEM_MODE_M_START            do{DMA_SPI_CR|= S2MTRIG_M;}while(0) //开始一次SPI到MEM的主机传输
#define SPI_MEM_MODE_S_START            do{DMA_SPI_CR|= S2MTRIG_S;}while(0) //开始一次SPI到MEM的从机传
#define SPI_MEM_CLS_FIFO                do{DMA_SPI_CR|= CLRFIFO;}while(0)   //清空SPI到MEM的FIFO
#define SPI_MEM_GET_FLAG                (DMA_SPI_STA & SPIIF)               //读取SPI到MEM中断标志位
#define SPI_MEM_GET_FLAG_RXLOSS         (DMA_SPI_STA & SPIRXLOSS)           //读取SPI到MEM数据丢失标志位
#define SPI_MEM_GET_FLAG_TXOVW          (DMA_SPI_STA & SPITXOVW)            //读取SPI到MEM数据覆盖标志位
#define SPI_MEM_CLS_FLAG                do{DMA_SPI_STA&=~SPIIF;}while(0)    //清除SPI到MEM中断标志位
#define SPI_MEM_CLS_FLAG_RXLOSS         do{DMA_SPI_STA&=~SPIRXLOSS;}while(0)//清除SPI到MEM数据丢失标志位
#define SPI_MEM_CLS_FLAG_TXOVW          do{DMA_SPI_STA&=~SPITXOVW;}while(0) //清除SPI到MEM数据覆盖标志位
#define SPI_MEM_SET_COUNT_MAX(value)    do{DMA_SPI_AMT=(u8)(value);}while(0)//设置SPI到MEM的发送/接收总字节数
#define SPI_MEM_GET_COUNT_DONE          (DMA_SPI_DONE)                      //读取SPI到MEM已经传输的字节数
#define SPI_MEM_SET_TX_ADDR(value)      do{DMA_SPI_TXA=(u16)(value);}while(0)//设置SPI到MEM的发送地址
#define SPI_MEM_SET_RX_ADDR(value)      do{DMA_SPI_RXA=(u16)(value);}while(0)//设置SPI到MEM的接收地址
#define SPI_MEM_SET_SS_AUTO_ENABLE      do{DMA_SPI_CFG2|= WRPSS;}while(0)    //设置SPI到MEM的SS脚自动控制
#define SPI_MEM_SET_SS_AUTO_DISABLE     do{DMA_SPI_CFG2&=~WRPSS;}while(0)    //设置SPI到MEM的SS脚手动控制
#define SPI_MEM_SET_SS_P12              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x00;}while(0)//设置自动控制的SS脚为P12脚
#define SPI_MEM_SET_SS_P22              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x01;}while(0)//设置自动控制的SS脚为P22脚
#define SPI_MEM_SET_SS_P74              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x02;}while(0)//设置自动控制的SS脚为P74脚
#define SPI_MEM_SET_SS_P35              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x03;}while(0)//设置自动控制的SS脚为P35脚
#define UR1_MEM_TX_IT_ENABLE            do{DMA_UR1T_CFG|= URTIE;}while(0)//打开MEM到UART1的发送中断使能
#define UR1_MEM_TX_IT_DISABLE           do{DMA_UR1T_CFG|= URTIE;}while(0)//关闭MEM到UART1的发送中断使能
#define UR1_MEM_RX_IT_ENABLE            do{DMA_UR1R_CFG|= URRIE;}while(0)//打开UART1到MEM的接收中断使能
#define UR1_MEM_RX_IT_DISABLE           do{DMA_UR1R_CFG|= URRIE;}while(0)//关闭UART1到MEM的接收中断使能
#define UR1_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART1的发送中断优先级为0
#define UR1_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART1的发送中断优先级为1
#define UR1_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART1的发送中断优先级为2
#define UR1_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART1的发送中断优先级为3
#define UR1_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x00);}while(0)//设置UART1到MEM的接收中断优先级为0
#define UR1_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x04);}while(0)//设置UART1到MEM的接收中断优先级为1
#define UR1_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x08);}while(0)//设置UART1到MEM的接收中断优先级为2
#define UR1_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x0C);}while(0)//设置UART1到MEM的接收中断优先级为3
#define UR1_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART1的发送总线优先级为0
#define UR1_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART1的发送总线优先级为1
#define UR1_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART1的发送总线优先级为2
#define UR1_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART1的发送总线优先级为3
#define UR1_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x00);}while(0)//设置UART1到MEM的接收总线优先级为0
#define UR1_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x01);}while(0)//设置UART1到MEM的接收总线优先级为1
#define UR1_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x02);}while(0)//设置UART1到MEM的接收总线优先级为2
#define UR1_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x03);}while(0)//设置UART1到MEM的接收总线优先级为3
#define UR1_MEM_TX_ENABLE               do{DMA_UR1T_CR|= ENURT;}while(0)   //打开MEM到UART1的发送使能
#define UR1_MEM_TX_DISABLE              do{DMA_UR1T_CR&=~ENURT;}while(0)   //关闭MEM到UART1的发送使能
#define UR1_MEM_RX_ENABLE               do{DMA_UR1R_CR|= ENURR;}while(0)   //打开UART1到MEM的接收使能
#define UR1_MEM_RX_DISABLE              do{DMA_UR1R_CR&=~ENURR;}while(0)   //关闭UART1到MEM的接收使能
#define UR1_MEM_TX_START                do{DMA_UR1T_CR|= URTTRIG;}while(0) //开始一次MEM到UART1的传输
#define UR1_MEM_RX_START                do{DMA_UR1R_CR|= URRTRIG;}while(0) //开始一次UART1到MEM的传输
#define UR1_MEM_GET_TX_FLAG             (DMA_UR1T_STA & URTIF)             //读取MEM到UART1的中断标志位
#define UR1_MEM_GET_TX_FLAG_TXOVW       (DMA_UR1T_STA & URTXOVW)           //读取MEM到UART1的覆盖标志位
#define UR1_MEM_GET_RX_FLAG             (DMA_UR1R_STA & URRIF)             //读取UART1到MEM的中断标志位
#define UR1_MEM_GET_RX_FLAG_RXOVW       (DMA_UR1R_STA & URRXOVW)           //读取UART1到MEM的覆盖标志位
#define UR1_MEM_CLS_TX_FLAG             do{DMA_UR1T_STA&=~URTIF;}while(0)  //清除MEM到UART1的中断标志位
#define UR1_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR1T_STA&=~URTXOVW;}while(0)//清除MEM到UART1的覆盖标志位
#define UR1_MEM_CLS_RX_FLAG             do{DMA_UR1R_STA&=~URRIF;}while(0)  //清除UART1到MEM的中断标志位
#define UR1_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR1R_STA&=~URRXOVW;}while(0)//清除UART1到MEM的覆盖标志位
#define UR1_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR1T_AMT=(u8)(value);}while(0)//设置MEM到UART1发送总字节数
#define UR1_MEM_GET_TX_COUNT_DONE       (DMA_UR1T_DONE)                 //读取MEM到UART1已经发送的字节数
#define UR1_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR1R_AMT=(u8)(value);}while(0)//设置UART1到MEM接收总字节数
#define UR1_MEM_GET_RX_COUNT_DONE       (DMA_UR1R_DONE)                 //读取UART1到MEM已经接收的字节数
#define UR1_MEM_SET_TX_ADDR(value)      do{DMA_UR1T_TXA=(u16)(value);}while(0)//设置MEM到UART1的发送地址
#define UR1_MEM_SET_RX_ADDR(value)      do{DMA_UR1R_RXA=(u16)(value);}while(0)//设置UART1到MEM的接收地址
#define UR2_MEM_TX_IT_ENABLE            do{DMA_UR2T_CFG|= URTIE;}while(0)//打开MEM到UART2的发送中断使能
#define UR2_MEM_TX_IT_DISABLE           do{DMA_UR2T_CFG|= URTIE;}while(0)//关闭MEM到UART2的发送中断使能
#define UR2_MEM_RX_IT_ENABLE            do{DMA_UR2R_CFG|= URRIE;}while(0)//打开UART2到MEM的接收中断使能
#define UR2_MEM_RX_IT_DISABLE           do{DMA_UR2R_CFG|= URRIE;}while(0)//关闭UART2到MEM的接收中断使能
#define UR2_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART2的发送中断优先级为0
#define UR2_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART2的发送中断优先级为1
#define UR2_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART2的发送中断优先级为2
#define UR2_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART2的发送中断优先级为3
#define UR2_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x00);}while(0)//设置UART2到MEM的接收中断优先级为0
#define UR2_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x04);}while(0)//设置UART2到MEM的接收中断优先级为1
#define UR2_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x08);}while(0)//设置UART2到MEM的接收中断优先级为2
#define UR2_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x0C);}while(0)//设置UART2到MEM的接收中断优先级为3
#define UR2_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART2的发送总线优先级为0
#define UR2_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART2的发送总线优先级为1
#define UR2_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART2的发送总线优先级为2
#define UR2_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART2的发送总线优先级为3
#define UR2_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x00);}while(0)//设置UART2到MEM的接收总线优先级为0
#define UR2_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x01);}while(0)//设置UART2到MEM的接收总线优先级为1
#define UR2_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x02);}while(0)//设置UART2到MEM的接收总线优先级为2
#define UR2_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x03);}while(0)//设置UART2到MEM的接收总线优先级为3
#define UR2_MEM_TX_ENABLE               do{DMA_UR2T_CR|= ENURT;}while(0)   //打开MEM到UART2的发送使能
#define UR2_MEM_TX_DISABLE              do{DMA_UR2T_CR&=~ENURT;}while(0)   //关闭MEM到UART2的发送使能
#define UR2_MEM_RX_ENABLE               do{DMA_UR2R_CR|= ENURR;}while(0)   //打开UART2到MEM的接收使能
#define UR2_MEM_RX_DISABLE              do{DMA_UR2R_CR&=~ENURR;}while(0)   //关闭UART2到MEM的接收使能
#define UR2_MEM_TX_START                do{DMA_UR2T_CR|= URTTRIG;}while(0) //开始一次MEM到UART2的传输
#define UR2_MEM_RX_START                do{DMA_UR2R_CR|= URRTRIG;}while(0) //开始一次UART2到MEM的传输
#define UR2_MEM_GET_TX_FLAG             (DMA_UR2T_STA & URTIF)             //读取MEM到UART2的中断标志位
#define UR2_MEM_GET_TX_FLAG_TXOVW       (DMA_UR2T_STA & URTXOVW)           //读取MEM到UART2的覆盖标志位
#define UR2_MEM_GET_RX_FLAG             (DMA_UR2R_STA & URRIF)             //读取UART2到MEM的中断标志位
#define UR2_MEM_GET_RX_FLAG_RXOVW       (DMA_UR2R_STA & URRXOVW)           //读取UART2到MEM的覆盖标志位
#define UR2_MEM_CLS_TX_FLAG             do{DMA_UR2T_STA&=~URTIF;}while(0)  //清除MEM到UART2的中断标志位
#define UR2_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR2T_STA&=~URTXOVW;}while(0)//清除MEM到UART2的覆盖标志位
#define UR2_MEM_CLS_RX_FLAG             do{DMA_UR2R_STA&=~URRIF;}while(0)  //清除UART2到MEM的中断标志位
#define UR2_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR2R_STA&=~URRXOVW;}while(0)//清除UART2到MEM的覆盖标志位
#define UR2_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR2T_AMT=(u8)(value);}while(0)//设置MEM到UART2发送总字节数
#define UR2_MEM_GET_TX_COUNT_DONE       (DMA_UR2T_DONE)                //读取MEM到UART2已经发送的字节数
#define UR2_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR2R_AMT=(u8)(value);}while(0)//设置UART2到MEM接收总字节数
#define UR2_MEM_GET_RX_COUNT_DONE       (DMA_UR2R_DONE)                //读取UART2到MEM已经接收的字节数
#define UR2_MEM_SET_TX_ADDR(value)      do{DMA_UR2T_TXA=(u16)(value);}while(0)//设置MEM到UART2的发送地址
#define UR2_MEM_SET_RX_ADDR(value)      do{DMA_UR2R_RXA=(u16)(value);}while(0)//设置UART2到MEM的接收地址
#define UR3_MEM_TX_IT_ENABLE            do{DMA_UR3T_CFG|= URTIE;}while(0)//打开MEM到UART3的发送中断使能
#define UR3_MEM_TX_IT_DISABLE           do{DMA_UR3T_CFG|= URTIE;}while(0)//关闭MEM到UART3的发送中断使能
#define UR3_MEM_RX_IT_ENABLE            do{DMA_UR3R_CFG|= URRIE;}while(0)//打开UART3到MEM的接收中断使能
#define UR3_MEM_RX_IT_DISABLE           do{DMA_UR3R_CFG|= URRIE;}while(0)//关闭UART3到MEM的接收中断使能
#define UR3_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART3的发送中断优先级为0
#define UR3_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART3的发送中断优先级为1
#define UR3_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART3的发送中断优先级为2
#define UR3_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART3的发送中断优先级为3
#define UR3_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x00);}while(0)//设置UART3到MEM的接收中断优先级为0
#define UR3_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x04);}while(0)//设置UART3到MEM的接收中断优先级为1
#define UR3_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x08);}while(0)//设置UART3到MEM的接收中断优先级为2
#define UR3_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x0C);}while(0)//设置UART3到MEM的接收中断优先级为3
#define UR3_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART3的发送总线优先级为0
#define UR3_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART3的发送总线优先级为1
#define UR3_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART3的发送总线优先级为2
#define UR3_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART3的发送总线优先级为3
#define UR3_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x00);}while(0)//设置UART3到MEM的接收总线优先级为0
#define UR3_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x01);}while(0)//设置UART3到MEM的接收总线优先级为1
#define UR3_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x02);}while(0)//设置UART3到MEM的接收总线优先级为2
#define UR3_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x03);}while(0)//设置UART3到MEM的接收总线优先级为3
#define UR3_MEM_TX_ENABLE               do{DMA_UR3T_CR|= ENURT;}while(0)   //打开MEM到UART3的发送使能
#define UR3_MEM_TX_DISABLE              do{DMA_UR3T_CR&=~ENURT;}while(0)   //关闭MEM到UART3的发送使能
#define UR3_MEM_RX_ENABLE               do{DMA_UR3R_CR|= ENURR;}while(0)   //打开UART3到MEM的接收使能
#define UR3_MEM_RX_DISABLE              do{DMA_UR3R_CR&=~ENURR;}while(0)   //关闭UART3到MEM的接收使能
#define UR3_MEM_TX_START                do{DMA_UR3T_CR|= URTTRIG;}while(0) //开始一次MEM到UART3的传输
#define UR3_MEM_RX_START                do{DMA_UR3R_CR|= URRTRIG;}while(0) //开始一次UART3到MEM的传输
#define UR3_MEM_GET_TX_FLAG             (DMA_UR3T_STA & URTIF)             //读取MEM到UART3的中断标志位
#define UR3_MEM_GET_TX_FLAG_TXOVW       (DMA_UR3T_STA & URTXOVW)           //读取MEM到UART3的覆盖标志位
#define UR3_MEM_GET_RX_FLAG             (DMA_UR3R_STA & URRIF)             //读取UART3到MEM的中断标志位
#define UR3_MEM_GET_RX_FLAG_RXOVW       (DMA_UR3R_STA & URRXOVW)           //读取UART3到MEM的覆盖标志位
#define UR3_MEM_CLS_TX_FLAG             do{DMA_UR3T_STA&=~URTIF;}while(0)  //清除MEM到UART3的中断标志位
#define UR3_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR3T_STA&=~URTXOVW;}while(0)//清除MEM到UART3的覆盖标志位
#define UR3_MEM_CLS_RX_FLAG             do{DMA_UR3R_STA&=~URRIF;}while(0)  //清除UART3到MEM的中断标志位
#define UR3_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR3R_STA&=~URRXOVW;}while(0)//清除UART3到MEM的覆盖标志位
#define UR3_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR3T_AMT=(u8)(value);}while(0)//设置MEM到UART3发送总字节数
#define UR3_MEM_GET_TX_COUNT_DONE       (DMA_UR3T_DONE)                //读取MEM到UART3已经发送的字节数
#define UR3_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR3R_AMT=(u8)(value);}while(0)//设置UART3到MEM接收总字节数
#define UR3_MEM_GET_RX_COUNT_DONE       (DMA_UR3R_DONE)                //读取UART3到MEM已经接收的字节数
#define UR3_MEM_SET_TX_ADDR(value)      do{DMA_UR3T_TXA=(u16)(value);}while(0)//设置MEM到UART3的发送地址
#define UR3_MEM_SET_RX_ADDR(value)      do{DMA_UR3R_RXA=(u16)(value);}while(0)//设置UART3到MEM的接收地址
#define UR4_MEM_TX_IT_ENABLE            do{DMA_UR4T_CFG|= URTIE;}while(0)//打开MEM到UART4的发送中断使能
#define UR4_MEM_TX_IT_DISABLE           do{DMA_UR4T_CFG|= URTIE;}while(0)//关闭MEM到UART4的发送中断使能
#define UR4_MEM_RX_IT_ENABLE            do{DMA_UR4R_CFG|= URRIE;}while(0)//打开UART4到MEM的接收中断使能
#define UR4_MEM_RX_IT_DISABLE           do{DMA_UR4R_CFG|= URRIE;}while(0)//关闭UART4到MEM的接收中断使能
#define UR4_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART4的发送中断优先级为0
#define UR4_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART4的发送中断优先级为1
#define UR4_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART4的发送中断优先级为2
#define UR4_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART4的发送中断优先级为3
#define UR4_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x00);}while(0)//设置UART4到MEM的接收中断优先级为0
#define UR4_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x04);}while(0)//设置UART4到MEM的接收中断优先级为1
#define UR4_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x08);}while(0)//设置UART4到MEM的接收中断优先级为2
#define UR4_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x0C);}while(0)//设置UART4到MEM的接收中断优先级为3
#define UR4_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART4的发送总线优先级为0
#define UR4_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART4的发送总线优先级为1
#define UR4_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART4的发送总线优先级为2
#define UR4_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART4的发送总线优先级为3
#define UR4_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x00);}while(0)//设置UART4到MEM的接收总线优先级为0
#define UR4_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x01);}while(0)//设置UART4到MEM的接收总线优先级为1
#define UR4_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x02);}while(0)//设置UART4到MEM的接收总线优先级为2
#define UR4_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x03);}while(0)//设置UART4到MEM的接收总线优先级为3
#define UR4_MEM_TX_ENABLE               do{DMA_UR4T_CR|= ENURT;}while(0)   //打开MEM到UART4的发送使能
#define UR4_MEM_TX_DISABLE              do{DMA_UR4T_CR&=~ENURT;}while(0)   //关闭MEM到UART4的发送使能
#define UR4_MEM_RX_ENABLE               do{DMA_UR4R_CR|= ENURR;}while(0)   //打开UART4到MEM的接收使能
#define UR4_MEM_RX_DISABLE              do{DMA_UR4R_CR&=~ENURR;}while(0)   //关闭UART4到MEM的接收使能
#define UR4_MEM_TX_START                do{DMA_UR4T_CR|= URTTRIG;}while(0) //开始一次MEM到UART4的传输
#define UR4_MEM_RX_START                do{DMA_UR4R_CR|= URRTRIG;}while(0) //开始一次UART4到MEM的传输
#define UR4_MEM_GET_TX_FLAG             (DMA_UR4T_STA & URTIF)             //读取MEM到UART4的中断标志位
#define UR4_MEM_GET_TX_FLAG_TXOVW       (DMA_UR4T_STA & URTXOVW)           //读取MEM到UART4的覆盖标志位
#define UR4_MEM_GET_RX_FLAG             (DMA_UR4R_STA & URRIF)             //读取UART4到MEM的中断标志位
#define UR4_MEM_GET_RX_FLAG_RXOVW       (DMA_UR4R_STA & URRXOVW)           //读取UART4到MEM的覆盖标志位
#define UR4_MEM_CLS_TX_FLAG             do{DMA_UR4T_STA&=~URTIF;}while(0)  //清除MEM到UART4的中断标志位
#define UR4_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR4T_STA&=~URTXOVW;}while(0)//清除MEM到UART4的覆盖标志位
#define UR4_MEM_CLS_RX_FLAG             do{DMA_UR4R_STA&=~URRIF;}while(0)  //清除UART4到MEM的中断标志位
#define UR4_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR4R_STA&=~URRXOVW;}while(0)//清除UART4到MEM的覆盖标志位
#define UR4_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR4T_AMT=(u8)(value);}while(0)//设置MEM到UART4发送总字节数
#define UR4_MEM_GET_TX_COUNT_DONE       (DMA_UR4T_DONE)                //读取MEM到UART4已经发送的字节数
#define UR4_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR4R_AMT=(u8)(value);}while(0)//设置UART4到MEM接收总字节数
#define UR4_MEM_GET_RX_COUNT_DONE       (DMA_UR4R_DONE)                //读取UART4到MEM已经接收的字节数
#define UR4_MEM_SET_TX_ADDR(value)      do{DMA_UR4T_TXA=(u16)(value);}while(0)//设置MEM到UART4的发送地址
#define UR4_MEM_SET_RX_ADDR(value)      do{DMA_UR4R_RXA=(u16)(value);}while(0)//设置UART4到MEM的接收地址
#define LCM_MEM_IT_ENABLE               do{DMA_LCM_CFG|= LCMIE;}while(0)   //打开MEM到LCM的中断
#define LCM_MEM_IT_DISABLE              do{DMA_LCM_CFG&=~LCMIE;}while(0)   //关闭MEM到LCM的中断
#define LCM_MEM_SET_IT_PRIORITY_0       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x00);}while(0)//设置MEM到LCM的中断优先级为0
#define LCM_MEM_SET_IT_PRIORITY_1       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x04);}while(0)//设置MEM到LCM的中断优先级为1
#define LCM_MEM_SET_IT_PRIORITY_2       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x08);}while(0)//设置MEM到LCM的中断优先级为2
#define LCM_MEM_SET_IT_PRIORITY_3       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到LCM的中断优先级为3
#define LCM_MEM_SET_BUS_PRIORITY_0      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x00);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_1      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x01);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_2      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x02);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_3      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x03);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_ENABLE                  do{DMA_LCM_CR|= ENLCM;}while(0)   //打开MEM到LCM功能
#define LCM_MEM_DISABLE                 do{DMA_LCM_CR&=~ENLCM;}while(0)   //关闭MEM到LCM功能
#define LCM_MEM_START_TX_CMD            do{DMA_LCM_CR|= TRIGWC;}while(0)  //开始从MEM发送指令到LCM
#define LCM_MEM_START_TX_DAT            do{DMA_LCM_CR|= TRIGWD;}while(0)  //开始从MEM发送数据到LCM
#define LCM_MEM_START_RX_CMD            do{DMA_LCM_CR|= TRIGRC;}while(0)  //开始从LCM读取指令到MEM
#define LCM_MEM_START_RX_DAT            do{DMA_LCM_CR|= TRIGRD;}while(0)  //开始从LCM读取数据到MEM
#define LCM_MEM_GET_FLAG                (DMA_LCM_STA & LCMIF)             //读取MEM到LCM的中断标志位
#define LCM_MEM_GET_FLAG_TXOVW          (DMA_LCM_STA & LCMTXOVW)          //读取MEM到LCM的数据覆盖标志位
#define LCM_MEM_CLS_FLAG                (DMA_LCM_STA&=~LCMIF)             //清除MEM到LCM的中断标志位
#define LCM_MEM_CLS_FLAG_TXOVW          (DMA_LCM_STA&=~LCMTXOVW)          //清除MEM到LCM的数据覆盖标志位
#define LCM_MEM_SET_COUNT_MAX(value)    do{DMA_LCM_AMT=(u8)(value);}while(0)//设置MEM到LCM传输的字节数
#define LCM_MEM_GET_COUNT_DONE          (DMA_LCM_DONE)                   //读取MEM到LCM的已传输完成字节数
#define LCM_MEM_SET_TX_ADDR(value)      do{DMA_LCM_TXA=(u16)(value);}while(0)//设置MEM到LCM的发送地址
#define LCM_MEM_SET_RX_ADDR(value)      do{DMA_LCM_RXA=(u16)(value);}while(0)//设置LCM到MEM的接收地址
/*------------------------------15位PWM特殊功能寄存器----------------------------*/
#define PWMRST                      0x40//PWM重置位
#define ENPWM                       0x01//PWM使能位
#define PWMCBIF                     0x08//PWM计数器归零中断标志位
#define EPWMCBI                     0x04//PWM计数器归零中断使能位 
#define EPWMTA                      0x02//PWM与ADC关联位
#define PWMCEN                      0x01//PWM计数开始位
#define INVCMP                      0x80//PWM异常检测中比较器结果控制位
#define INVIO                       0x40//PWM异常检测中IO信号控制位
#define ENFD                        0x20//PWM异常检测控制位
#define FLTFLIO                     0x10//PWM发生异常时对PWM输出口控制位
#define EFDI                        0x08//PWM异常检测中断使能位
#define FDCMP                       0x04//PWM异常检测使用比较器检测使能位
#define FDIO                        0x02//PWM异常检测使用IO检测使能位
#define FDIF                        0x01//PWM异常检测中断标志位
#define SELT2                       0x10//PWM时钟源选择
#define ENO                         0x80//PWM输出使能位
#define INI                         0x40//PWM初始电平控制位
#define ENI                         0x04//PWM通道中断使能位
#define ENT2I                       0x02//PWM通道在第二个点中断使能位
#define ENT1I                       0x01//PWM通道在第一个点中断使能位
#define PWM_EN                      0x80//PWM使能并开始计数（STC8A普通版）
//-------------功能指令------------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8A全系列
#define PWM15_SET_CLK_TIMER2        do{PWMCKS=SELT2;}while(0)
#define PWM15_SET_CLK_SYS(value)    do{PWMCKS=((u8)(value)&0x0F);}while(0)

#define PWM15_SET_CH0_IO_P20        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x00);}while(0)//PWM通道0的引脚切换到P20
#define PWM15_SET_CH0_IO_P10        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x08);}while(0)//PWM通道0的引脚切换到P10
#define PWM15_SET_CH0_IO_P60        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x10);}while(0)//PWM通道0的引脚切换到P60
#define PWM15_SET_CH1_IO_P21        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x00);}while(0)//PWM通道1的引脚切换到P21
#define PWM15_SET_CH1_IO_P11        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x08);}while(0)//PWM通道1的引脚切换到P11
#define PWM15_SET_CH1_IO_P61        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x10);}while(0)//PWM通道1的引脚切换到P61
#define PWM15_SET_CH2_IO_P22        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x00);}while(0)//PWM通道2的引脚切换到P22
#define PWM15_SET_CH2_IO_P12        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x08);}while(0)//PWM通道2的引脚切换到P12
#define PWM15_SET_CH2_IO_P62        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x10);}while(0)//PWM通道2的引脚切换到P62
#define PWM15_SET_CH3_IO_P23        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x00);}while(0)//PWM通道3的引脚切换到P23
#define PWM15_SET_CH3_IO_P13        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x08);}while(0)//PWM通道3的引脚切换到P13
#define PWM15_SET_CH3_IO_P63        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x10);}while(0)//PWM通道3的引脚切换到P63
#define PWM15_SET_CH4_IO_P24        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x00);}while(0)//PWM通道4的引脚切换到P24
#define PWM15_SET_CH4_IO_P14        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x08);}while(0)//PWM通道4的引脚切换到P14
#define PWM15_SET_CH4_IO_P64        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x10);}while(0)//PWM通道4的引脚切换到P64
#define PWM15_SET_CH5_IO_P25        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x00);}while(0)//PWM通道5的引脚切换到P25
#define PWM15_SET_CH5_IO_P15        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x08);}while(0)//PWM通道5的引脚切换到P15
#define PWM15_SET_CH5_IO_P65        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x10);}while(0)//PWM通道5的引脚切换到P65
#define PWM15_SET_CH6_IO_P26        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x00);}while(0)//PWM通道6的引脚切换到P26
#define PWM15_SET_CH6_IO_P16        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x08);}while(0)//PWM通道6的引脚切换到P16
#define PWM15_SET_CH6_IO_P66        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x10);}while(0)//PWM通道6的引脚切换到P66
#define PWM15_SET_CH7_IO_P27        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x00);}while(0)//PWM通道7的引脚切换到P27
#define PWM15_SET_CH7_IO_P17        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x08);}while(0)//PWM通道7的引脚切换到P17
#define PWM15_SET_CH7_IO_P67        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x10);}while(0)//PWM通道7的引脚切换到P67

#define PWM15_GET_CH0_IT_FLAG       (PWMIF & 0x01)
#define PWM15_GET_CH1_IT_FLAG       (PWMIF & 0x02)
#define PWM15_GET_CH2_IT_FLAG       (PWMIF & 0x04)
#define PWM15_GET_CH3_IT_FLAG       (PWMIF & 0x08)
#define PWM15_GET_CH4_IT_FLAG       (PWMIF & 0x10)
#define PWM15_GET_CH5_IT_FLAG       (PWMIF & 0x20)
#define PWM15_GET_CH6_IT_FLAG       (PWMIF & 0x40)
#define PWM15_GET_CH7_IT_FLAG       (PWMIF & 0x80)

#define PWM15_CLS_CH0_IT_FLAG       do{PWMIF&=~0x01}while(0)
#define PWM15_CLS_CH1_IT_FLAG       do{PWMIF&=~0x02}while(0)
#define PWM15_CLS_CH2_IT_FLAG       do{PWMIF&=~0x04}while(0)
#define PWM15_CLS_CH3_IT_FLAG       do{PWMIF&=~0x08}while(0)
#define PWM15_CLS_CH4_IT_FLAG       do{PWMIF&=~0x10}while(0)
#define PWM15_CLS_CH5_IT_FLAG       do{PWMIF&=~0x20}while(0)
#define PWM15_CLS_CH6_IT_FLAG       do{PWMIF&=~0x40}while(0)
#define PWM15_CLS_CH7_IT_FLAG       do{PWMIF&=~0x80}while(0)

#define PWM15_SET_CH0_OUT_ENABLE    do{PWM_CH0_CR|= ENO;}while(0)
#define PWM15_SET_CH0_OUT_DISABLE   do{PWM_CH0_CR&=~ENO;}while(0)
#define PWM15_SET_CH0_INIT_H        do{PWM_CH0_CR|= INI;}while(0)
#define PWM15_SET_CH0_INIT_L        do{PWM_CH0_CR&=~INI;}while(0)
#define PWM15_SET_CH0_IT_ENABLE     do{PWM_CH0_CR|= ENI;}while(0)
#define PWM15_SET_CH0_IT_DISABLE    do{PWM_CH0_CR&=~ENI;}while(0)
#define PWM15_SET_CH0_T1_IT_ENABLE  do{PWM_CH0_CR|= ENT1I;}while(0)
#define PWM15_SET_CH0_T1_IT_DISABLE do{PWM_CH0_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH0_T2_IT_ENABLE  do{PWM_CH0_CR|= ENT2I;}while(0)
#define PWM15_SET_CH0_T2_IT_DISABLE do{PWM_CH0_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH0_HOLD_H        do{PWM_CH0_HLD=0x02;}while(0)
#define PWM15_SET_CH0_HOLD_L        do{PWM_CH0_HLD=0x01;}while(0)
#define PWM15_SET_CH0_HOLD_OFF      do{PWM_CH0_HLD=0x00;}while(0)
#define PWM15_SET_CH1_OUT_ENABLE    do{PWM_CH1_CR|= ENO;}while(0)
#define PWM15_SET_CH1_OUT_DISABLE   do{PWM_CH1_CR&=~ENO;}while(0)
#define PWM15_SET_CH1_INIT_H        do{PWM_CH1_CR|= INI;}while(0)
#define PWM15_SET_CH1_INIT_L        do{PWM_CH1_CR&=~INI;}while(0)
#define PWM15_SET_CH1_IT_ENABLE     do{PWM_CH1_CR|= ENI;}while(0)
#define PWM15_SET_CH1_IT_DISABLE    do{PWM_CH1_CR&=~ENI;}while(0)
#define PWM15_SET_CH1_T1_IT_ENABLE  do{PWM_CH1_CR|= ENT1I;}while(0)
#define PWM15_SET_CH1_T1_IT_DISABLE do{PWM_CH1_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH1_T2_IT_ENABLE  do{PWM_CH1_CR|= ENT2I;}while(0)
#define PWM15_SET_CH1_T2_IT_DISABLE do{PWM_CH1_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH1_HOLD_H        do{PWM_CH1_HLD=0x02;}while(0)
#define PWM15_SET_CH1_HOLD_L        do{PWM_CH1_HLD=0x01;}while(0)
#define PWM15_SET_CH1_HOLD_OFF      do{PWM_CH1_HLD=0x00;}while(0)
#define PWM15_SET_CH2_OUT_ENABLE    do{PWM_CH2_CR|= ENO;}while(0)
#define PWM15_SET_CH2_OUT_DISABLE   do{PWM_CH2_CR&=~ENO;}while(0)
#define PWM15_SET_CH2_INIT_H        do{PWM_CH2_CR|= INI;}while(0)
#define PWM15_SET_CH2_INIT_L        do{PWM_CH2_CR&=~INI;}while(0)
#define PWM15_SET_CH2_IT_ENABLE     do{PWM_CH2_CR|= ENI;}while(0)
#define PWM15_SET_CH2_IT_DISABLE    do{PWM_CH2_CR&=~ENI;}while(0)
#define PWM15_SET_CH2_T1_IT_ENABLE  do{PWM_CH2_CR|= ENT1I;}while(0)
#define PWM15_SET_CH2_T1_IT_DISABLE do{PWM_CH2_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH2_T2_IT_ENABLE  do{PWM_CH2_CR|= ENT2I;}while(0)
#define PWM15_SET_CH2_T2_IT_DISABLE do{PWM_CH2_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH2_HOLD_H        do{PWM_CH2_HLD=0x02;}while(0)
#define PWM15_SET_CH2_HOLD_L        do{PWM_CH2_HLD=0x01;}while(0)
#define PWM15_SET_CH2_HOLD_OFF      do{PWM_CH2_HLD=0x00;}while(0)
#define PWM15_SET_CH3_OUT_ENABLE    do{PWM_CH3_CR|= ENO;}while(0)
#define PWM15_SET_CH3_OUT_DISABLE   do{PWM_CH3_CR&=~ENO;}while(0)
#define PWM15_SET_CH3_INIT_H        do{PWM_CH3_CR|= INI;}while(0)
#define PWM15_SET_CH3_INIT_L        do{PWM_CH3_CR&=~INI;}while(0)
#define PWM15_SET_CH3_IT_ENABLE     do{PWM_CH3_CR|= ENI;}while(0)
#define PWM15_SET_CH3_IT_DISABLE    do{PWM_CH3_CR&=~ENI;}while(0)
#define PWM15_SET_CH3_T1_IT_ENABLE  do{PWM_CH3_CR|= ENT1I;}while(0)
#define PWM15_SET_CH3_T1_IT_DISABLE do{PWM_CH3_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH3_T2_IT_ENABLE  do{PWM_CH3_CR|= ENT2I;}while(0)
#define PWM15_SET_CH3_T2_IT_DISABLE do{PWM_CH3_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH3_HOLD_H        do{PWM_CH3_HLD=0x02;}while(0)
#define PWM15_SET_CH3_HOLD_L        do{PWM_CH3_HLD=0x01;}while(0)
#define PWM15_SET_CH3_HOLD_OFF      do{PWM_CH3_HLD=0x00;}while(0)
#define PWM15_SET_CH4_OUT_ENABLE    do{PWM_CH4_CR|= ENO;}while(0)
#define PWM15_SET_CH4_OUT_DISABLE   do{PWM_CH4_CR&=~ENO;}while(0)
#define PWM15_SET_CH4_INIT_H        do{PWM_CH4_CR|= INI;}while(0)
#define PWM15_SET_CH4_INIT_L        do{PWM_CH4_CR&=~INI;}while(0)
#define PWM15_SET_CH4_IT_ENABLE     do{PWM_CH4_CR|= ENI;}while(0)
#define PWM15_SET_CH4_IT_DISABLE    do{PWM_CH4_CR&=~ENI;}while(0)
#define PWM15_SET_CH4_T1_IT_ENABLE  do{PWM_CH4_CR|= ENT1I;}while(0)
#define PWM15_SET_CH4_T1_IT_DISABLE do{PWM_CH4_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH4_T2_IT_ENABLE  do{PWM_CH4_CR|= ENT2I;}while(0)
#define PWM15_SET_CH4_T2_IT_DISABLE do{PWM_CH4_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH4_HOLD_H        do{PWM_CH4_HLD=0x02;}while(0)
#define PWM15_SET_CH4_HOLD_L        do{PWM_CH4_HLD=0x01;}while(0)
#define PWM15_SET_CH4_HOLD_OFF      do{PWM_CH4_HLD=0x00;}while(0)
#define PWM15_SET_CH5_OUT_ENABLE    do{PWM_CH5_CR|= ENO;}while(0)
#define PWM15_SET_CH5_OUT_DISABLE   do{PWM_CH5_CR&=~ENO;}while(0)
#define PWM15_SET_CH5_INIT_H        do{PWM_CH5_CR|= INI;}while(0)
#define PWM15_SET_CH5_INIT_L        do{PWM_CH5_CR&=~INI;}while(0)
#define PWM15_SET_CH5_IT_ENABLE     do{PWM_CH5_CR|= ENI;}while(0)
#define PWM15_SET_CH5_IT_DISABLE    do{PWM_CH5_CR&=~ENI;}while(0)
#define PWM15_SET_CH5_T1_IT_ENABLE  do{PWM_CH5_CR|= ENT1I;}while(0)
#define PWM15_SET_CH5_T1_IT_DISABLE do{PWM_CH5_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH5_T2_IT_ENABLE  do{PWM_CH5_CR|= ENT2I;}while(0)
#define PWM15_SET_CH5_T2_IT_DISABLE do{PWM_CH5_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH5_HOLD_H        do{PWM_CH5_HLD=0x02;}while(0)
#define PWM15_SET_CH5_HOLD_L        do{PWM_CH5_HLD=0x01;}while(0)
#define PWM15_SET_CH5_HOLD_OFF      do{PWM_CH5_HLD=0x00;}while(0)
#define PWM15_SET_CH6_OUT_ENABLE    do{PWM_CH6_CR|= ENO;}while(0)
#define PWM15_SET_CH6_OUT_DISABLE   do{PWM_CH6_CR&=~ENO;}while(0)
#define PWM15_SET_CH6_INIT_H        do{PWM_CH6_CR|= INI;}while(0)
#define PWM15_SET_CH6_INIT_L        do{PWM_CH6_CR&=~INI;}while(0)
#define PWM15_SET_CH6_IT_ENABLE     do{PWM_CH6_CR|= ENI;}while(0)
#define PWM15_SET_CH6_IT_DISABLE    do{PWM_CH6_CR&=~ENI;}while(0)
#define PWM15_SET_CH6_T1_IT_ENABLE  do{PWM_CH6_CR|= ENT1I;}while(0)
#define PWM15_SET_CH6_T1_IT_DISABLE do{PWM_CH6_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH6_T2_IT_ENABLE  do{PWM_CH6_CR|= ENT2I;}while(0)
#define PWM15_SET_CH6_T2_IT_DISABLE do{PWM_CH6_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH6_HOLD_H        do{PWM_CH6_HLD=0x02;}while(0)
#define PWM15_SET_CH6_HOLD_L        do{PWM_CH6_HLD=0x01;}while(0)
#define PWM15_SET_CH6_HOLD_OFF      do{PWM_CH6_HLD=0x00;}while(0)
#define PWM15_SET_CH7_OUT_ENABLE    do{PWM_CH7_CR|= ENO;}while(0)
#define PWM15_SET_CH7_OUT_DISABLE   do{PWM_CH7_CR&=~ENO;}while(0)
#define PWM15_SET_CH7_INIT_H        do{PWM_CH7_CR|= INI;}while(0)
#define PWM15_SET_CH7_INIT_L        do{PWM_CH7_CR&=~INI;}while(0)
#define PWM15_SET_CH7_IT_ENABLE     do{PWM_CH7_CR|= ENI;}while(0)
#define PWM15_SET_CH7_IT_DISABLE    do{PWM_CH7_CR&=~ENI;}while(0)
#define PWM15_SET_CH7_T1_IT_ENABLE  do{PWM_CH7_CR|= ENT1I;}while(0)
#define PWM15_SET_CH7_T1_IT_DISABLE do{PWM_CH7_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH7_T2_IT_ENABLE  do{PWM_CH7_CR|= ENT2I;}while(0)
#define PWM15_SET_CH7_T2_IT_DISABLE do{PWM_CH7_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH7_HOLD_H        do{PWM_CH7_HLD=0x02;}while(0)
#define PWM15_SET_CH7_HOLD_L        do{PWM_CH7_HLD=0x01;}while(0)
#define PWM15_SET_CH7_HOLD_OFF      do{PWM_CH7_HLD=0x00;}while(0)
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_SET_G0_CLK_TIMER2     do{PWM_P0_CKS=SELT2;}while(0)
#define PWM15_SET_G1_CLK_TIMER2     do{PWM_P1_CKS=SELT2;}while(0)
#define PWM15_SET_G2_CLK_TIMER2     do{PWM_P2_CKS=SELT2;}while(0)
#define PWM15_SET_G3_CLK_TIMER2     do{PWM_P3_CKS=SELT2;}while(0)
#define PWM15_SET_G4_CLK_TIMER2     do{PWM_P4_CKS=SELT2;}while(0)
#define PWM15_SET_G5_CLK_TIMER2     do{PWM_P5_CKS=SELT2;}while(0)

#define PWM15_SET_G0_CLK_SYS(value) do{PWM_P0_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G1_CLK_SYS(value) do{PWM_P1_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G2_CLK_SYS(value) do{PWM_P2_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G3_CLK_SYS(value) do{PWM_P3_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G4_CLK_SYS(value) do{PWM_P4_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G5_CLK_SYS(value) do{PWM_P5_CKS=((u8)(value)&0x0F);}while(0)

#define PWM15_GET_G0_CH0_IT_FLAG    (PWM_P0_IF & 0x01)
#define PWM15_GET_G0_CH1_IT_FLAG    (PWM_P0_IF & 0x02)
#define PWM15_GET_G0_CH2_IT_FLAG    (PWM_P0_IF & 0x04)
#define PWM15_GET_G0_CH3_IT_FLAG    (PWM_P0_IF & 0x08)
#define PWM15_GET_G0_CH4_IT_FLAG    (PWM_P0_IF & 0x10)
#define PWM15_GET_G0_CH5_IT_FLAG    (PWM_P0_IF & 0x20)
#define PWM15_GET_G0_CH6_IT_FLAG    (PWM_P0_IF & 0x40)
#define PWM15_GET_G0_CH7_IT_FLAG    (PWM_P0_IF & 0x80)
#define PWM15_GET_G1_CH0_IT_FLAG    (PWM_P1_IF & 0x01)
#define PWM15_GET_G1_CH1_IT_FLAG    (PWM_P1_IF & 0x02)
#define PWM15_GET_G1_CH2_IT_FLAG    (PWM_P1_IF & 0x04)
#define PWM15_GET_G1_CH3_IT_FLAG    (PWM_P1_IF & 0x08)
#define PWM15_GET_G1_CH4_IT_FLAG    (PWM_P1_IF & 0x10)
#define PWM15_GET_G1_CH5_IT_FLAG    (PWM_P1_IF & 0x20)
#define PWM15_GET_G1_CH6_IT_FLAG    (PWM_P1_IF & 0x40)
#define PWM15_GET_G1_CH7_IT_FLAG    (PWM_P1_IF & 0x80)
#define PWM15_GET_G2_CH0_IT_FLAG    (PWM_P2_IF & 0x01)
#define PWM15_GET_G2_CH1_IT_FLAG    (PWM_P2_IF & 0x02)
#define PWM15_GET_G2_CH2_IT_FLAG    (PWM_P2_IF & 0x04)
#define PWM15_GET_G2_CH3_IT_FLAG    (PWM_P2_IF & 0x08)
#define PWM15_GET_G2_CH4_IT_FLAG    (PWM_P2_IF & 0x10)
#define PWM15_GET_G2_CH5_IT_FLAG    (PWM_P2_IF & 0x20)
#define PWM15_GET_G2_CH6_IT_FLAG    (PWM_P2_IF & 0x40)
#define PWM15_GET_G2_CH7_IT_FLAG    (PWM_P2_IF & 0x80)
#define PWM15_GET_G3_CH0_IT_FLAG    (PWM_P3_IF & 0x01)
#define PWM15_GET_G3_CH1_IT_FLAG    (PWM_P3_IF & 0x02)
#define PWM15_GET_G3_CH2_IT_FLAG    (PWM_P3_IF & 0x04)
#define PWM15_GET_G3_CH3_IT_FLAG    (PWM_P3_IF & 0x08)
#define PWM15_GET_G3_CH4_IT_FLAG    (PWM_P3_IF & 0x10)
#define PWM15_GET_G3_CH5_IT_FLAG    (PWM_P3_IF & 0x20)
#define PWM15_GET_G3_CH6_IT_FLAG    (PWM_P3_IF & 0x40)
#define PWM15_GET_G3_CH7_IT_FLAG    (PWM_P3_IF & 0x80)
#define PWM15_GET_G4_CH0_IT_FLAG    (PWM_P4_IF & 0x01)
#define PWM15_GET_G4_CH1_IT_FLAG    (PWM_P4_IF & 0x02)
#define PWM15_GET_G4_CH2_IT_FLAG    (PWM_P4_IF & 0x04)
#define PWM15_GET_G4_CH3_IT_FLAG    (PWM_P4_IF & 0x08)
#define PWM15_GET_G4_CH4_IT_FLAG    (PWM_P4_IF & 0x10)
#define PWM15_GET_G4_CH5_IT_FLAG    (PWM_P4_IF & 0x20)
#define PWM15_GET_G4_CH6_IT_FLAG    (PWM_P4_IF & 0x40)
#define PWM15_GET_G4_CH7_IT_FLAG    (PWM_P4_IF & 0x80)
#define PWM15_GET_G5_CH0_IT_FLAG    (PWM_P5_IF & 0x01)
#define PWM15_GET_G5_CH1_IT_FLAG    (PWM_P5_IF & 0x02)
#define PWM15_GET_G5_CH2_IT_FLAG    (PWM_P5_IF & 0x04)
#define PWM15_GET_G5_CH3_IT_FLAG    (PWM_P5_IF & 0x08)
#define PWM15_GET_G5_CH4_IT_FLAG    (PWM_P5_IF & 0x10)
#define PWM15_GET_G5_CH5_IT_FLAG    (PWM_P5_IF & 0x20)
#define PWM15_GET_G5_CH6_IT_FLAG    (PWM_P5_IF & 0x40)
#define PWM15_GET_G5_CH7_IT_FLAG    (PWM_P5_IF & 0x80)

#define PWM15_CLS_G0_CH0_IT_FLAG    do{PWM_P0_IF&=~0x01}while(0)
#define PWM15_CLS_G0_CH1_IT_FLAG    do{PWM_P0_IF&=~0x02}while(0)
#define PWM15_CLS_G0_CH2_IT_FLAG    do{PWM_P0_IF&=~0x04}while(0)
#define PWM15_CLS_G0_CH3_IT_FLAG    do{PWM_P0_IF&=~0x08}while(0)
#define PWM15_CLS_G0_CH4_IT_FLAG    do{PWM_P0_IF&=~0x10}while(0)
#define PWM15_CLS_G0_CH5_IT_FLAG    do{PWM_P0_IF&=~0x20}while(0)
#define PWM15_CLS_G0_CH6_IT_FLAG    do{PWM_P0_IF&=~0x40}while(0)
#define PWM15_CLS_G0_CH7_IT_FLAG    do{PWM_P0_IF&=~0x80}while(0)
#define PWM15_CLS_G1_CH0_IT_FLAG    do{PWM_P1_IF&=~0x01}while(0)
#define PWM15_CLS_G1_CH1_IT_FLAG    do{PWM_P1_IF&=~0x02}while(0)
#define PWM15_CLS_G1_CH2_IT_FLAG    do{PWM_P1_IF&=~0x04}while(0)
#define PWM15_CLS_G1_CH3_IT_FLAG    do{PWM_P1_IF&=~0x08}while(0)
#define PWM15_CLS_G1_CH4_IT_FLAG    do{PWM_P1_IF&=~0x10}while(0)
#define PWM15_CLS_G1_CH5_IT_FLAG    do{PWM_P1_IF&=~0x20}while(0)
#define PWM15_CLS_G1_CH6_IT_FLAG    do{PWM_P1_IF&=~0x40}while(0)
#define PWM15_CLS_G1_CH7_IT_FLAG    do{PWM_P1_IF&=~0x80}while(0)
#define PWM15_CLS_G2_CH0_IT_FLAG    do{PWM_P2_IF&=~0x01}while(0)
#define PWM15_CLS_G2_CH1_IT_FLAG    do{PWM_P2_IF&=~0x02}while(0)
#define PWM15_CLS_G2_CH2_IT_FLAG    do{PWM_P2_IF&=~0x04}while(0)
#define PWM15_CLS_G2_CH3_IT_FLAG    do{PWM_P2_IF&=~0x08}while(0)
#define PWM15_CLS_G2_CH4_IT_FLAG    do{PWM_P2_IF&=~0x10}while(0)
#define PWM15_CLS_G2_CH5_IT_FLAG    do{PWM_P2_IF&=~0x20}while(0)
#define PWM15_CLS_G2_CH6_IT_FLAG    do{PWM_P2_IF&=~0x40}while(0)
#define PWM15_CLS_G2_CH7_IT_FLAG    do{PWM_P2_IF&=~0x80}while(0)
#define PWM15_CLS_G3_CH0_IT_FLAG    do{PWM_P3_IF&=~0x01}while(0)
#define PWM15_CLS_G3_CH1_IT_FLAG    do{PWM_P3_IF&=~0x02}while(0)
#define PWM15_CLS_G3_CH2_IT_FLAG    do{PWM_P3_IF&=~0x04}while(0)
#define PWM15_CLS_G3_CH3_IT_FLAG    do{PWM_P3_IF&=~0x08}while(0)
#define PWM15_CLS_G3_CH4_IT_FLAG    do{PWM_P3_IF&=~0x10}while(0)
#define PWM15_CLS_G3_CH5_IT_FLAG    do{PWM_P3_IF&=~0x20}while(0)
#define PWM15_CLS_G3_CH6_IT_FLAG    do{PWM_P3_IF&=~0x40}while(0)
#define PWM15_CLS_G3_CH7_IT_FLAG    do{PWM_P3_IF&=~0x80}while(0)
#define PWM15_CLS_G4_CH0_IT_FLAG    do{PWM_P4_IF&=~0x01}while(0)
#define PWM15_CLS_G4_CH1_IT_FLAG    do{PWM_P4_IF&=~0x02}while(0)
#define PWM15_CLS_G4_CH2_IT_FLAG    do{PWM_P4_IF&=~0x04}while(0)
#define PWM15_CLS_G4_CH3_IT_FLAG    do{PWM_P4_IF&=~0x08}while(0)
#define PWM15_CLS_G4_CH4_IT_FLAG    do{PWM_P4_IF&=~0x10}while(0)
#define PWM15_CLS_G4_CH5_IT_FLAG    do{PWM_P4_IF&=~0x20}while(0)
#define PWM15_CLS_G4_CH6_IT_FLAG    do{PWM_P4_IF&=~0x40}while(0)
#define PWM15_CLS_G4_CH7_IT_FLAG    do{PWM_P4_IF&=~0x80}while(0)
#define PWM15_CLS_G5_CH0_IT_FLAG    do{PWM_P5_IF&=~0x01}while(0)
#define PWM15_CLS_G5_CH1_IT_FLAG    do{PWM_P5_IF&=~0x02}while(0)
#define PWM15_CLS_G5_CH2_IT_FLAG    do{PWM_P5_IF&=~0x04}while(0)
#define PWM15_CLS_G5_CH3_IT_FLAG    do{PWM_P5_IF&=~0x08}while(0)
#define PWM15_CLS_G5_CH4_IT_FLAG    do{PWM_P5_IF&=~0x10}while(0)
#define PWM15_CLS_G5_CH5_IT_FLAG    do{PWM_P5_IF&=~0x20}while(0)
#define PWM15_CLS_G5_CH6_IT_FLAG    do{PWM_P5_IF&=~0x40}while(0)
#define PWM15_CLS_G5_CH7_IT_FLAG    do{PWM_P5_IF&=~0x80}while(0)

#define PWM15_SET_G0_CH0_OUT_ENABLE    do{PWM_P00_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH0_OUT_DISABLE   do{PWM_P00_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH0_INIT_H        do{PWM_P00_CR|= INI;}while(0)
#define PWM15_SET_G0_CH0_INIT_L        do{PWM_P00_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH0_IT_ENABLE     do{PWM_P00_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH0_IT_DISABLE    do{PWM_P00_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH0_T1_IT_ENABLE  do{PWM_P00_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH0_T1_IT_DISABLE do{PWM_P00_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH0_T2_IT_ENABLE  do{PWM_P00_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH0_T2_IT_DISABLE do{PWM_P00_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH0_HOLD_H        do{PWM_P00_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH0_HOLD_L        do{PWM_P00_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH0_HOLD_OFF      do{PWM_P00_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH1_OUT_ENABLE    do{PWM_P01_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH1_OUT_DISABLE   do{PWM_P01_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH1_INIT_H        do{PWM_P01_CR|= INI;}while(0)
#define PWM15_SET_G0_CH1_INIT_L        do{PWM_P01_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH1_IT_ENABLE     do{PWM_P01_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH1_IT_DISABLE    do{PWM_P01_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH1_T1_IT_ENABLE  do{PWM_P01_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH1_T1_IT_DISABLE do{PWM_P01_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH1_T2_IT_ENABLE  do{PWM_P01_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH1_T2_IT_DISABLE do{PWM_P01_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH1_HOLD_H        do{PWM_P01_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH1_HOLD_L        do{PWM_P01_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH1_HOLD_OFF      do{PWM_P01_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH2_OUT_ENABLE    do{PWM_P02_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH2_OUT_DISABLE   do{PWM_P02_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH2_INIT_H        do{PWM_P02_CR|= INI;}while(0)
#define PWM15_SET_G0_CH2_INIT_L        do{PWM_P02_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH2_IT_ENABLE     do{PWM_P02_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH2_IT_DISABLE    do{PWM_P02_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH2_T1_IT_ENABLE  do{PWM_P02_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH2_T1_IT_DISABLE do{PWM_P02_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH2_T2_IT_ENABLE  do{PWM_P02_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH2_T2_IT_DISABLE do{PWM_P02_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH2_HOLD_H        do{PWM_P02_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH2_HOLD_L        do{PWM_P02_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH2_HOLD_OFF      do{PWM_P02_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH3_OUT_ENABLE    do{PWM_P03_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH3_OUT_DISABLE   do{PWM_P03_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH3_INIT_H        do{PWM_P03_CR|= INI;}while(0)
#define PWM15_SET_G0_CH3_INIT_L        do{PWM_P03_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH3_IT_ENABLE     do{PWM_P03_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH3_IT_DISABLE    do{PWM_P03_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH3_T1_IT_ENABLE  do{PWM_P03_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH3_T1_IT_DISABLE do{PWM_P03_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH3_T2_IT_ENABLE  do{PWM_P03_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH3_T2_IT_DISABLE do{PWM_P03_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH3_HOLD_H        do{PWM_P03_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH3_HOLD_L        do{PWM_P03_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH3_HOLD_OFF      do{PWM_P03_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH4_OUT_ENABLE    do{PWM_P04_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH4_OUT_DISABLE   do{PWM_P04_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH4_INIT_H        do{PWM_P04_CR|= INI;}while(0)
#define PWM15_SET_G0_CH4_INIT_L        do{PWM_P04_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH4_IT_ENABLE     do{PWM_P04_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH4_IT_DISABLE    do{PWM_P04_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH4_T1_IT_ENABLE  do{PWM_P04_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH4_T1_IT_DISABLE do{PWM_P04_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH4_T2_IT_ENABLE  do{PWM_P04_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH4_T2_IT_DISABLE do{PWM_P04_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH4_HOLD_H        do{PWM_P04_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH4_HOLD_L        do{PWM_P04_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH4_HOLD_OFF      do{PWM_P04_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH5_OUT_ENABLE    do{PWM_P05_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH5_OUT_DISABLE   do{PWM_P05_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH5_INIT_H        do{PWM_P05_CR|= INI;}while(0)
#define PWM15_SET_G0_CH5_INIT_L        do{PWM_P05_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH5_IT_ENABLE     do{PWM_P05_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH5_IT_DISABLE    do{PWM_P05_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH5_T1_IT_ENABLE  do{PWM_P05_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH5_T1_IT_DISABLE do{PWM_P05_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH5_T2_IT_ENABLE  do{PWM_P05_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH5_T2_IT_DISABLE do{PWM_P05_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH5_HOLD_H        do{PWM_P05_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH5_HOLD_L        do{PWM_P05_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH5_HOLD_OFF      do{PWM_P05_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH6_OUT_ENABLE    do{PWM_P06_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH6_OUT_DISABLE   do{PWM_P06_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH6_INIT_H        do{PWM_P06_CR|= INI;}while(0)
#define PWM15_SET_G0_CH6_INIT_L        do{PWM_P06_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH6_IT_ENABLE     do{PWM_P06_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH6_IT_DISABLE    do{PWM_P06_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH6_T1_IT_ENABLE  do{PWM_P06_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH6_T1_IT_DISABLE do{PWM_P06_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH6_T2_IT_ENABLE  do{PWM_P06_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH6_T2_IT_DISABLE do{PWM_P06_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH6_HOLD_H        do{PWM_P06_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH6_HOLD_L        do{PWM_P06_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH6_HOLD_OFF      do{PWM_P06_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH7_OUT_ENABLE    do{PWM_P07_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH7_OUT_DISABLE   do{PWM_P07_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH7_INIT_H        do{PWM_P07_CR|= INI;}while(0)
#define PWM15_SET_G0_CH7_INIT_L        do{PWM_P07_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH7_IT_ENABLE     do{PWM_P07_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH7_IT_DISABLE    do{PWM_P07_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH7_T1_IT_ENABLE  do{PWM_P07_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH7_T1_IT_DISABLE do{PWM_P07_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH7_T2_IT_ENABLE  do{PWM_P07_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH7_T2_IT_DISABLE do{PWM_P07_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH7_HOLD_H        do{PWM_P07_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH7_HOLD_L        do{PWM_P07_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH7_HOLD_OFF      do{PWM_P07_HLD=0x00;}while(0)

#define PWM15_SET_G1_CH0_OUT_ENABLE    do{PWM_P10_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH0_OUT_DISABLE   do{PWM_P10_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH0_INIT_H        do{PWM_P10_CR|= INI;}while(0)
#define PWM15_SET_G1_CH0_INIT_L        do{PWM_P10_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH0_IT_ENABLE     do{PWM_P10_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH0_IT_DISABLE    do{PWM_P10_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH0_T1_IT_ENABLE  do{PWM_P10_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH0_T1_IT_DISABLE do{PWM_P10_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH0_T2_IT_ENABLE  do{PWM_P10_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH0_T2_IT_DISABLE do{PWM_P10_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH0_HOLD_H        do{PWM_P10_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH0_HOLD_L        do{PWM_P10_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH0_HOLD_OFF      do{PWM_P10_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH1_OUT_ENABLE    do{PWM_P11_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH1_OUT_DISABLE   do{PWM_P11_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH1_INIT_H        do{PWM_P11_CR|= INI;}while(0)
#define PWM15_SET_G1_CH1_INIT_L        do{PWM_P11_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH1_IT_ENABLE     do{PWM_P11_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH1_IT_DISABLE    do{PWM_P11_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH1_T1_IT_ENABLE  do{PWM_P11_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH1_T1_IT_DISABLE do{PWM_P11_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH1_T2_IT_ENABLE  do{PWM_P11_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH1_T2_IT_DISABLE do{PWM_P11_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH1_HOLD_H        do{PWM_P11_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH1_HOLD_L        do{PWM_P11_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH1_HOLD_OFF      do{PWM_P11_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH2_OUT_ENABLE    do{PWM_P12_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH2_OUT_DISABLE   do{PWM_P12_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH2_INIT_H        do{PWM_P12_CR|= INI;}while(0)
#define PWM15_SET_G1_CH2_INIT_L        do{PWM_P12_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH2_IT_ENABLE     do{PWM_P12_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH2_IT_DISABLE    do{PWM_P12_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH2_T1_IT_ENABLE  do{PWM_P12_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH2_T1_IT_DISABLE do{PWM_P12_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH2_T2_IT_ENABLE  do{PWM_P12_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH2_T2_IT_DISABLE do{PWM_P12_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH2_HOLD_H        do{PWM_P12_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH2_HOLD_L        do{PWM_P12_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH2_HOLD_OFF      do{PWM_P12_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH3_OUT_ENABLE    do{PWM_P13_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH3_OUT_DISABLE   do{PWM_P13_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH3_INIT_H        do{PWM_P13_CR|= INI;}while(0)
#define PWM15_SET_G1_CH3_INIT_L        do{PWM_P13_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH3_IT_ENABLE     do{PWM_P13_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH3_IT_DISABLE    do{PWM_P13_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH3_T1_IT_ENABLE  do{PWM_P13_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH3_T1_IT_DISABLE do{PWM_P13_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH3_T2_IT_ENABLE  do{PWM_P13_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH3_T2_IT_DISABLE do{PWM_P13_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH3_HOLD_H        do{PWM_P13_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH3_HOLD_L        do{PWM_P13_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH3_HOLD_OFF      do{PWM_P13_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH4_OUT_ENABLE    do{PWM_P14_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH4_OUT_DISABLE   do{PWM_P14_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH4_INIT_H        do{PWM_P14_CR|= INI;}while(0)
#define PWM15_SET_G1_CH4_INIT_L        do{PWM_P14_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH4_IT_ENABLE     do{PWM_P14_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH4_IT_DISABLE    do{PWM_P14_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH4_T1_IT_ENABLE  do{PWM_P14_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH4_T1_IT_DISABLE do{PWM_P14_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH4_T2_IT_ENABLE  do{PWM_P14_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH4_T2_IT_DISABLE do{PWM_P14_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH4_HOLD_H        do{PWM_P14_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH4_HOLD_L        do{PWM_P14_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH4_HOLD_OFF      do{PWM_P14_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH5_OUT_ENABLE    do{PWM_P15_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH5_OUT_DISABLE   do{PWM_P15_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH5_INIT_H        do{PWM_P15_CR|= INI;}while(0)
#define PWM15_SET_G1_CH5_INIT_L        do{PWM_P15_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH5_IT_ENABLE     do{PWM_P15_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH5_IT_DISABLE    do{PWM_P15_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH5_T1_IT_ENABLE  do{PWM_P15_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH5_T1_IT_DISABLE do{PWM_P15_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH5_T2_IT_ENABLE  do{PWM_P15_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH5_T2_IT_DISABLE do{PWM_P15_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH5_HOLD_H        do{PWM_P15_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH5_HOLD_L        do{PWM_P15_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH5_HOLD_OFF      do{PWM_P15_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH6_OUT_ENABLE    do{PWM_P16_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH6_OUT_DISABLE   do{PWM_P16_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH6_INIT_H        do{PWM_P16_CR|= INI;}while(0)
#define PWM15_SET_G1_CH6_INIT_L        do{PWM_P16_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH6_IT_ENABLE     do{PWM_P16_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH6_IT_DISABLE    do{PWM_P16_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH6_T1_IT_ENABLE  do{PWM_P16_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH6_T1_IT_DISABLE do{PWM_P16_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH6_T2_IT_ENABLE  do{PWM_P16_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH6_T2_IT_DISABLE do{PWM_P16_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH6_HOLD_H        do{PWM_P16_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH6_HOLD_L        do{PWM_P16_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH6_HOLD_OFF      do{PWM_P16_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH7_OUT_ENABLE    do{PWM_P17_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH7_OUT_DISABLE   do{PWM_P17_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH7_INIT_H        do{PWM_P17_CR|= INI;}while(0)
#define PWM15_SET_G1_CH7_INIT_L        do{PWM_P17_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH7_IT_ENABLE     do{PWM_P17_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH7_IT_DISABLE    do{PWM_P17_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH7_T1_IT_ENABLE  do{PWM_P17_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH7_T1_IT_DISABLE do{PWM_P17_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH7_T2_IT_ENABLE  do{PWM_P17_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH7_T2_IT_DISABLE do{PWM_P17_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH7_HOLD_H        do{PWM_P17_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH7_HOLD_L        do{PWM_P17_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH7_HOLD_OFF      do{PWM_P17_HLD=0x00;}while(0)

#define PWM15_SET_G2_CH0_OUT_ENABLE    do{PWM_P20_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH0_OUT_DISABLE   do{PWM_P20_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH0_INIT_H        do{PWM_P20_CR|= INI;}while(0)
#define PWM15_SET_G2_CH0_INIT_L        do{PWM_P20_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH0_IT_ENABLE     do{PWM_P20_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH0_IT_DISABLE    do{PWM_P20_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH0_T1_IT_ENABLE  do{PWM_P20_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH0_T1_IT_DISABLE do{PWM_P20_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH0_T2_IT_ENABLE  do{PWM_P20_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH0_T2_IT_DISABLE do{PWM_P20_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH0_HOLD_H        do{PWM_P20_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH0_HOLD_L        do{PWM_P20_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH0_HOLD_OFF      do{PWM_P20_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH1_OUT_ENABLE    do{PWM_P21_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH1_OUT_DISABLE   do{PWM_P21_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH1_INIT_H        do{PWM_P21_CR|= INI;}while(0)
#define PWM15_SET_G2_CH1_INIT_L        do{PWM_P21_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH1_IT_ENABLE     do{PWM_P21_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH1_IT_DISABLE    do{PWM_P21_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH1_T1_IT_ENABLE  do{PWM_P21_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH1_T1_IT_DISABLE do{PWM_P21_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH1_T2_IT_ENABLE  do{PWM_P21_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH1_T2_IT_DISABLE do{PWM_P21_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH1_HOLD_H        do{PWM_P21_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH1_HOLD_L        do{PWM_P21_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH1_HOLD_OFF      do{PWM_P21_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH2_OUT_ENABLE    do{PWM_P22_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH2_OUT_DISABLE   do{PWM_P22_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH2_INIT_H        do{PWM_P22_CR|= INI;}while(0)
#define PWM15_SET_G2_CH2_INIT_L        do{PWM_P22_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH2_IT_ENABLE     do{PWM_P22_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH2_IT_DISABLE    do{PWM_P22_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH2_T1_IT_ENABLE  do{PWM_P22_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH2_T1_IT_DISABLE do{PWM_P22_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH2_T2_IT_ENABLE  do{PWM_P22_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH2_T2_IT_DISABLE do{PWM_P22_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH2_HOLD_H        do{PWM_P22_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH2_HOLD_L        do{PWM_P22_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH2_HOLD_OFF      do{PWM_P22_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH3_OUT_ENABLE    do{PWM_P23_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH3_OUT_DISABLE   do{PWM_P23_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH3_INIT_H        do{PWM_P23_CR|= INI;}while(0)
#define PWM15_SET_G2_CH3_INIT_L        do{PWM_P23_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH3_IT_ENABLE     do{PWM_P23_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH3_IT_DISABLE    do{PWM_P23_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH3_T1_IT_ENABLE  do{PWM_P23_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH3_T1_IT_DISABLE do{PWM_P23_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH3_T2_IT_ENABLE  do{PWM_P23_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH3_T2_IT_DISABLE do{PWM_P23_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH3_HOLD_H        do{PWM_P23_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH3_HOLD_L        do{PWM_P23_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH3_HOLD_OFF      do{PWM_P23_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH4_OUT_ENABLE    do{PWM_P24_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH4_OUT_DISABLE   do{PWM_P24_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH4_INIT_H        do{PWM_P24_CR|= INI;}while(0)
#define PWM15_SET_G2_CH4_INIT_L        do{PWM_P24_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH4_IT_ENABLE     do{PWM_P24_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH4_IT_DISABLE    do{PWM_P24_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH4_T1_IT_ENABLE  do{PWM_P24_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH4_T1_IT_DISABLE do{PWM_P24_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH4_T2_IT_ENABLE  do{PWM_P24_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH4_T2_IT_DISABLE do{PWM_P24_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH4_HOLD_H        do{PWM_P24_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH4_HOLD_L        do{PWM_P24_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH4_HOLD_OFF      do{PWM_P24_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH5_OUT_ENABLE    do{PWM_P25_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH5_OUT_DISABLE   do{PWM_P25_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH5_INIT_H        do{PWM_P25_CR|= INI;}while(0)
#define PWM15_SET_G2_CH5_INIT_L        do{PWM_P25_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH5_IT_ENABLE     do{PWM_P25_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH5_IT_DISABLE    do{PWM_P25_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH5_T1_IT_ENABLE  do{PWM_P25_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH5_T1_IT_DISABLE do{PWM_P25_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH5_T2_IT_ENABLE  do{PWM_P25_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH5_T2_IT_DISABLE do{PWM_P25_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH5_HOLD_H        do{PWM_P25_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH5_HOLD_L        do{PWM_P25_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH5_HOLD_OFF      do{PWM_P25_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH6_OUT_ENABLE    do{PWM_P26_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH6_OUT_DISABLE   do{PWM_P26_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH6_INIT_H        do{PWM_P26_CR|= INI;}while(0)
#define PWM15_SET_G2_CH6_INIT_L        do{PWM_P26_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH6_IT_ENABLE     do{PWM_P26_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH6_IT_DISABLE    do{PWM_P26_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH6_T1_IT_ENABLE  do{PWM_P26_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH6_T1_IT_DISABLE do{PWM_P26_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH6_T2_IT_ENABLE  do{PWM_P26_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH6_T2_IT_DISABLE do{PWM_P26_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH6_HOLD_H        do{PWM_P26_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH6_HOLD_L        do{PWM_P26_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH6_HOLD_OFF      do{PWM_P26_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH7_OUT_ENABLE    do{PWM_P27_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH7_OUT_DISABLE   do{PWM_P27_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH7_INIT_H        do{PWM_P27_CR|= INI;}while(0)
#define PWM15_SET_G2_CH7_INIT_L        do{PWM_P27_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH7_IT_ENABLE     do{PWM_P27_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH7_IT_DISABLE    do{PWM_P27_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH7_T1_IT_ENABLE  do{PWM_P27_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH7_T1_IT_DISABLE do{PWM_P27_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH7_T2_IT_ENABLE  do{PWM_P27_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH7_T2_IT_DISABLE do{PWM_P27_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH7_HOLD_H        do{PWM_P27_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH7_HOLD_L        do{PWM_P27_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH7_HOLD_OFF      do{PWM_P27_HLD=0x00;}while(0)

#define PWM15_SET_G3_CH0_OUT_ENABLE    do{PWM_P30_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH0_OUT_DISABLE   do{PWM_P30_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH0_INIT_H        do{PWM_P30_CR|= INI;}while(0)
#define PWM15_SET_G3_CH0_INIT_L        do{PWM_P30_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH0_IT_ENABLE     do{PWM_P30_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH0_IT_DISABLE    do{PWM_P30_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH0_T1_IT_ENABLE  do{PWM_P30_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH0_T1_IT_DISABLE do{PWM_P30_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH0_T2_IT_ENABLE  do{PWM_P30_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH0_T2_IT_DISABLE do{PWM_P30_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH0_HOLD_H        do{PWM_P30_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH0_HOLD_L        do{PWM_P30_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH0_HOLD_OFF      do{PWM_P30_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH1_OUT_ENABLE    do{PWM_P31_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH1_OUT_DISABLE   do{PWM_P31_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH1_INIT_H        do{PWM_P31_CR|= INI;}while(0)
#define PWM15_SET_G3_CH1_INIT_L        do{PWM_P31_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH1_IT_ENABLE     do{PWM_P31_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH1_IT_DISABLE    do{PWM_P31_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH1_T1_IT_ENABLE  do{PWM_P31_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH1_T1_IT_DISABLE do{PWM_P31_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH1_T2_IT_ENABLE  do{PWM_P31_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH1_T2_IT_DISABLE do{PWM_P31_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH1_HOLD_H        do{PWM_P31_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH1_HOLD_L        do{PWM_P31_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH1_HOLD_OFF      do{PWM_P31_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH2_OUT_ENABLE    do{PWM_P32_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH2_OUT_DISABLE   do{PWM_P32_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH2_INIT_H        do{PWM_P32_CR|= INI;}while(0)
#define PWM15_SET_G3_CH2_INIT_L        do{PWM_P32_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH2_IT_ENABLE     do{PWM_P32_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH2_IT_DISABLE    do{PWM_P32_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH2_T1_IT_ENABLE  do{PWM_P32_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH2_T1_IT_DISABLE do{PWM_P32_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH2_T2_IT_ENABLE  do{PWM_P32_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH2_T2_IT_DISABLE do{PWM_P32_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH2_HOLD_H        do{PWM_P32_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH2_HOLD_L        do{PWM_P32_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH2_HOLD_OFF      do{PWM_P32_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH3_OUT_ENABLE    do{PWM_P33_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH3_OUT_DISABLE   do{PWM_P33_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH3_INIT_H        do{PWM_P33_CR|= INI;}while(0)
#define PWM15_SET_G3_CH3_INIT_L        do{PWM_P33_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH3_IT_ENABLE     do{PWM_P33_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH3_IT_DISABLE    do{PWM_P33_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH3_T1_IT_ENABLE  do{PWM_P33_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH3_T1_IT_DISABLE do{PWM_P33_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH3_T2_IT_ENABLE  do{PWM_P33_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH3_T2_IT_DISABLE do{PWM_P33_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH3_HOLD_H        do{PWM_P33_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH3_HOLD_L        do{PWM_P33_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH3_HOLD_OFF      do{PWM_P33_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH4_OUT_ENABLE    do{PWM_P34_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH4_OUT_DISABLE   do{PWM_P34_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH4_INIT_H        do{PWM_P34_CR|= INI;}while(0)
#define PWM15_SET_G3_CH4_INIT_L        do{PWM_P34_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH4_IT_ENABLE     do{PWM_P34_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH4_IT_DISABLE    do{PWM_P34_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH4_T1_IT_ENABLE  do{PWM_P34_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH4_T1_IT_DISABLE do{PWM_P34_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH4_T2_IT_ENABLE  do{PWM_P34_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH4_T2_IT_DISABLE do{PWM_P34_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH4_HOLD_H        do{PWM_P34_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH4_HOLD_L        do{PWM_P34_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH4_HOLD_OFF      do{PWM_P34_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH5_OUT_ENABLE    do{PWM_P35_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH5_OUT_DISABLE   do{PWM_P35_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH5_INIT_H        do{PWM_P35_CR|= INI;}while(0)
#define PWM15_SET_G3_CH5_INIT_L        do{PWM_P35_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH5_IT_ENABLE     do{PWM_P35_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH5_IT_DISABLE    do{PWM_P35_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH5_T1_IT_ENABLE  do{PWM_P35_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH5_T1_IT_DISABLE do{PWM_P35_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH5_T2_IT_ENABLE  do{PWM_P35_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH5_T2_IT_DISABLE do{PWM_P35_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH5_HOLD_H        do{PWM_P35_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH5_HOLD_L        do{PWM_P35_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH5_HOLD_OFF      do{PWM_P35_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH6_OUT_ENABLE    do{PWM_P36_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH6_OUT_DISABLE   do{PWM_P36_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH6_INIT_H        do{PWM_P36_CR|= INI;}while(0)
#define PWM15_SET_G3_CH6_INIT_L        do{PWM_P36_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH6_IT_ENABLE     do{PWM_P36_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH6_IT_DISABLE    do{PWM_P36_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH6_T1_IT_ENABLE  do{PWM_P36_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH6_T1_IT_DISABLE do{PWM_P36_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH6_T2_IT_ENABLE  do{PWM_P36_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH6_T2_IT_DISABLE do{PWM_P36_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH6_HOLD_H        do{PWM_P36_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH6_HOLD_L        do{PWM_P36_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH6_HOLD_OFF      do{PWM_P36_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH7_OUT_ENABLE    do{PWM_P37_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH7_OUT_DISABLE   do{PWM_P37_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH7_INIT_H        do{PWM_P37_CR|= INI;}while(0)
#define PWM15_SET_G3_CH7_INIT_L        do{PWM_P37_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH7_IT_ENABLE     do{PWM_P37_CR|= ENI;}while(0) 
#define PWM15_SET_G3_CH7_IT_DISABLE    do{PWM_P37_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH7_T1_IT_ENABLE  do{PWM_P37_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH7_T1_IT_DISABLE do{PWM_P37_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH7_T2_IT_ENABLE  do{PWM_P37_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH7_T2_IT_DISABLE do{PWM_P37_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH7_HOLD_H        do{PWM_P37_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH7_HOLD_L        do{PWM_P37_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH7_HOLD_OFF      do{PWM_P37_HLD=0x00;}while(0)

#define PWM15_SET_G4_CH0_OUT_ENABLE    do{PWM_P40_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH0_OUT_DISABLE   do{PWM_P40_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH0_INIT_H        do{PWM_P40_CR|= INI;}while(0)
#define PWM15_SET_G4_CH0_INIT_L        do{PWM_P40_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH0_IT_ENABLE     do{PWM_P40_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH0_IT_DISABLE    do{PWM_P40_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH0_T1_IT_ENABLE  do{PWM_P40_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH0_T1_IT_DISABLE do{PWM_P40_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH0_T2_IT_ENABLE  do{PWM_P40_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH0_T2_IT_DISABLE do{PWM_P40_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH0_HOLD_H        do{PWM_P40_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH0_HOLD_L        do{PWM_P40_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH0_HOLD_OFF      do{PWM_P40_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH1_OUT_ENABLE    do{PWM_P41_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH1_OUT_DISABLE   do{PWM_P41_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH1_INIT_H        do{PWM_P41_CR|= INI;}while(0)
#define PWM15_SET_G4_CH1_INIT_L        do{PWM_P41_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH1_IT_ENABLE     do{PWM_P41_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH1_IT_DISABLE    do{PWM_P41_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH1_T1_IT_ENABLE  do{PWM_P41_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH1_T1_IT_DISABLE do{PWM_P41_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH1_T2_IT_ENABLE  do{PWM_P41_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH1_T2_IT_DISABLE do{PWM_P41_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH1_HOLD_H        do{PWM_P41_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH1_HOLD_L        do{PWM_P41_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH1_HOLD_OFF      do{PWM_P41_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH2_OUT_ENABLE    do{PWM_P42_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH2_OUT_DISABLE   do{PWM_P42_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH2_INIT_H        do{PWM_P42_CR|= INI;}while(0)
#define PWM15_SET_G4_CH2_INIT_L        do{PWM_P42_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH2_IT_ENABLE     do{PWM_P42_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH2_IT_DISABLE    do{PWM_P42_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH2_T1_IT_ENABLE  do{PWM_P42_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH2_T1_IT_DISABLE do{PWM_P42_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH2_T2_IT_ENABLE  do{PWM_P42_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH2_T2_IT_DISABLE do{PWM_P42_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH2_HOLD_H        do{PWM_P42_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH2_HOLD_L        do{PWM_P42_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH2_HOLD_OFF      do{PWM_P42_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH3_OUT_ENABLE    do{PWM_P43_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH3_OUT_DISABLE   do{PWM_P43_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH3_INIT_H        do{PWM_P43_CR|= INI;}while(0)
#define PWM15_SET_G4_CH3_INIT_L        do{PWM_P43_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH3_IT_ENABLE     do{PWM_P43_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH3_IT_DISABLE    do{PWM_P43_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH3_T1_IT_ENABLE  do{PWM_P43_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH3_T1_IT_DISABLE do{PWM_P43_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH3_T2_IT_ENABLE  do{PWM_P43_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH3_T2_IT_DISABLE do{PWM_P43_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH3_HOLD_H        do{PWM_P43_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH3_HOLD_L        do{PWM_P43_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH3_HOLD_OFF      do{PWM_P43_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH4_OUT_ENABLE    do{PWM_P44_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH4_OUT_DISABLE   do{PWM_P44_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH4_INIT_H        do{PWM_P44_CR|= INI;}while(0)
#define PWM15_SET_G4_CH4_INIT_L        do{PWM_P44_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH4_IT_ENABLE     do{PWM_P44_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH4_IT_DISABLE    do{PWM_P44_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH4_T1_IT_ENABLE  do{PWM_P44_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH4_T1_IT_DISABLE do{PWM_P44_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH4_T2_IT_ENABLE  do{PWM_P44_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH4_T2_IT_DISABLE do{PWM_P44_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH4_HOLD_H        do{PWM_P44_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH4_HOLD_L        do{PWM_P44_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH4_HOLD_OFF      do{PWM_P44_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH5_OUT_ENABLE    do{PWM_P45_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH5_OUT_DISABLE   do{PWM_P45_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH5_INIT_H        do{PWM_P45_CR|= INI;}while(0)
#define PWM15_SET_G4_CH5_INIT_L        do{PWM_P45_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH5_IT_ENABLE     do{PWM_P45_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH5_IT_DISABLE    do{PWM_P45_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH5_T1_IT_ENABLE  do{PWM_P45_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH5_T1_IT_DISABLE do{PWM_P45_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH5_T2_IT_ENABLE  do{PWM_P45_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH5_T2_IT_DISABLE do{PWM_P45_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH5_HOLD_H        do{PWM_P45_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH5_HOLD_L        do{PWM_P45_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH5_HOLD_OFF      do{PWM_P45_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH6_OUT_ENABLE    do{PWM_P46_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH6_OUT_DISABLE   do{PWM_P46_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH6_INIT_H        do{PWM_P46_CR|= INI;}while(0)
#define PWM15_SET_G4_CH6_INIT_L        do{PWM_P46_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH6_IT_ENABLE     do{PWM_P46_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH6_IT_DISABLE    do{PWM_P46_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH6_T1_IT_ENABLE  do{PWM_P46_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH6_T1_IT_DISABLE do{PWM_P46_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH6_T2_IT_ENABLE  do{PWM_P46_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH6_T2_IT_DISABLE do{PWM_P46_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH6_HOLD_H        do{PWM_P46_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH6_HOLD_L        do{PWM_P46_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH6_HOLD_OFF      do{PWM_P46_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH7_OUT_ENABLE    do{PWM_P47_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH7_OUT_DISABLE   do{PWM_P47_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH7_INIT_H        do{PWM_P47_CR|= INI;}while(0)
#define PWM15_SET_G4_CH7_INIT_L        do{PWM_P47_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH7_IT_ENABLE     do{PWM_P47_CR|= ENI;}while(0) 
#define PWM15_SET_G4_CH7_IT_DISABLE    do{PWM_P47_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH7_T1_IT_ENABLE  do{PWM_P47_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH7_T1_IT_DISABLE do{PWM_P47_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH7_T2_IT_ENABLE  do{PWM_P47_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH7_T2_IT_DISABLE do{PWM_P47_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH7_HOLD_H        do{PWM_P47_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH7_HOLD_L        do{PWM_P47_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH7_HOLD_OFF      do{PWM_P47_HLD=0x00;}while(0)

#define PWM15_SET_G5_CH0_OUT_ENABLE    do{PWM_P50_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH0_OUT_DISABLE   do{PWM_P50_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH0_INIT_H        do{PWM_P50_CR|= INI;}while(0)
#define PWM15_SET_G5_CH0_INIT_L        do{PWM_P50_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH0_IT_ENABLE     do{PWM_P50_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH0_IT_DISABLE    do{PWM_P50_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH0_T1_IT_ENABLE  do{PWM_P50_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH0_T1_IT_DISABLE do{PWM_P50_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH0_T2_IT_ENABLE  do{PWM_P50_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH0_T2_IT_DISABLE do{PWM_P50_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH0_HOLD_H        do{PWM_P50_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH0_HOLD_L        do{PWM_P50_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH0_HOLD_OFF      do{PWM_P50_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH1_OUT_ENABLE    do{PWM_P51_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH1_OUT_DISABLE   do{PWM_P51_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH1_INIT_H        do{PWM_P51_CR|= INI;}while(0)
#define PWM15_SET_G5_CH1_INIT_L        do{PWM_P51_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH1_IT_ENABLE     do{PWM_P51_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH1_IT_DISABLE    do{PWM_P51_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH1_T1_IT_ENABLE  do{PWM_P51_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH1_T1_IT_DISABLE do{PWM_P51_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH1_T2_IT_ENABLE  do{PWM_P51_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH1_T2_IT_DISABLE do{PWM_P51_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH1_HOLD_H        do{PWM_P51_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH1_HOLD_L        do{PWM_P51_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH1_HOLD_OFF      do{PWM_P51_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH2_OUT_ENABLE    do{PWM_P52_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH2_OUT_DISABLE   do{PWM_P52_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH2_INIT_H        do{PWM_P52_CR|= INI;}while(0)
#define PWM15_SET_G5_CH2_INIT_L        do{PWM_P52_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH2_IT_ENABLE     do{PWM_P52_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH2_IT_DISABLE    do{PWM_P52_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH2_T1_IT_ENABLE  do{PWM_P52_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH2_T1_IT_DISABLE do{PWM_P52_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH2_T2_IT_ENABLE  do{PWM_P52_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH2_T2_IT_DISABLE do{PWM_P52_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH2_HOLD_H        do{PWM_P52_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH2_HOLD_L        do{PWM_P52_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH2_HOLD_OFF      do{PWM_P52_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH3_OUT_ENABLE    do{PWM_P53_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH3_OUT_DISABLE   do{PWM_P53_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH3_INIT_H        do{PWM_P53_CR|= INI;}while(0)
#define PWM15_SET_G5_CH3_INIT_L        do{PWM_P53_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH3_IT_ENABLE     do{PWM_P53_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH3_IT_DISABLE    do{PWM_P53_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH3_T1_IT_ENABLE  do{PWM_P53_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH3_T1_IT_DISABLE do{PWM_P53_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH3_T2_IT_ENABLE  do{PWM_P53_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH3_T2_IT_DISABLE do{PWM_P53_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH3_HOLD_H        do{PWM_P53_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH3_HOLD_L        do{PWM_P53_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH3_HOLD_OFF      do{PWM_P53_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH4_OUT_ENABLE    do{PWM_P54_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH4_OUT_DISABLE   do{PWM_P54_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH4_INIT_H        do{PWM_P54_CR|= INI;}while(0)
#define PWM15_SET_G5_CH4_INIT_L        do{PWM_P54_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH4_IT_ENABLE     do{PWM_P54_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH4_IT_DISABLE    do{PWM_P54_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH4_T1_IT_ENABLE  do{PWM_P54_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH4_T1_IT_DISABLE do{PWM_P54_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH4_T2_IT_ENABLE  do{PWM_P54_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH4_T2_IT_DISABLE do{PWM_P54_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH4_HOLD_H        do{PWM_P54_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH4_HOLD_L        do{PWM_P54_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH4_HOLD_OFF      do{PWM_P54_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH5_OUT_ENABLE    do{PWM_P55_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH5_OUT_DISABLE   do{PWM_P55_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH5_INIT_H        do{PWM_P55_CR|= INI;}while(0)
#define PWM15_SET_G5_CH5_INIT_L        do{PWM_P55_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH5_IT_ENABLE     do{PWM_P55_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH5_IT_DISABLE    do{PWM_P55_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH5_T1_IT_ENABLE  do{PWM_P55_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH5_T1_IT_DISABLE do{PWM_P55_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH5_T2_IT_ENABLE  do{PWM_P55_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH5_T2_IT_DISABLE do{PWM_P55_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH5_HOLD_H        do{PWM_P55_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH5_HOLD_L        do{PWM_P55_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH5_HOLD_OFF      do{PWM_P55_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH6_OUT_ENABLE    do{PWM_P56_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH6_OUT_DISABLE   do{PWM_P56_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH6_INIT_H        do{PWM_P56_CR|= INI;}while(0)
#define PWM15_SET_G5_CH6_INIT_L        do{PWM_P56_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH6_IT_ENABLE     do{PWM_P56_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH6_IT_DISABLE    do{PWM_P56_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH6_T1_IT_ENABLE  do{PWM_P56_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH6_T1_IT_DISABLE do{PWM_P56_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH6_T2_IT_ENABLE  do{PWM_P56_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH6_T2_IT_DISABLE do{PWM_P56_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH6_HOLD_H        do{PWM_P56_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH6_HOLD_L        do{PWM_P56_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH6_HOLD_OFF      do{PWM_P56_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH7_OUT_ENABLE    do{PWM_P57_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH7_OUT_DISABLE   do{PWM_P57_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH7_INIT_H        do{PWM_P57_CR|= INI;}while(0)
#define PWM15_SET_G5_CH7_INIT_L        do{PWM_P57_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH7_IT_ENABLE     do{PWM_P57_CR|= ENI;}while(0) 
#define PWM15_SET_G5_CH7_IT_DISABLE    do{PWM_P57_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH7_T1_IT_ENABLE  do{PWM_P57_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH7_T1_IT_DISABLE do{PWM_P57_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH7_T2_IT_ENABLE  do{PWM_P57_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH7_T2_IT_DISABLE do{PWM_P57_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH7_HOLD_H        do{PWM_P57_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH7_HOLD_L        do{PWM_P57_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH7_HOLD_OFF      do{PWM_P57_HLD=0x00;}while(0)
#endif



#if     ((ECBM_MCU&0xF0F000)==0x201000)   //STC8A8K64D4
#define PWM15_RESET                 do{PWMSET|= PWMRST;}while(0)
#define PWM15_POWER_ON              do{PWMSET|= ENPWM; }while(0)
#define PWM15_POWER_OFF             do{PWMSET&=~ENPWM; }while(0)
#define PWM15_START                 do{PWMCFG|= PWMCEN;}while(0)
#define PWM15_STOP                  do{PWMCFG&=~PWMCEN;}while(0)
#elif   ((ECBM_MCU&0xF0F000)==0x200000)   //除STC8A8K64D4以外的STC8A
#define PWM15_RESET                 do{}while(0)
#define PWM15_POWER_ON              do{}while(0)
#define PWM15_POWER_OFF             do{}while(0)
#define PWM15_START                 do{PWMCR|= PWM_EN;}while(0)
#define PWM15_STOP                  do{PWMCR&=~PWM_EN;}while(0)
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_RESET                 do{PWMSET|= PWMRST;}while(0)

#define PWM15_G0_POWER_ON           do{PWMSET|= 0x01;}while(0)
#define PWM15_G1_POWER_ON           do{PWMSET|= 0x02;}while(0)
#define PWM15_G2_POWER_ON           do{PWMSET|= 0x04;}while(0)
#define PWM15_G3_POWER_ON           do{PWMSET|= 0x08;}while(0)
#define PWM15_G4_POWER_ON           do{PWMSET|= 0x10;}while(0)
#define PWM15_G5_POWER_ON           do{PWMSET|= 0x20;}while(0)

#define PWM15_G0_POWER_OFF          do{PWMSET&=~0x01;}while(0)
#define PWM15_G1_POWER_OFF          do{PWMSET&=~0x02;}while(0)
#define PWM15_G2_POWER_OFF          do{PWMSET&=~0x04;}while(0)
#define PWM15_G3_POWER_OFF          do{PWMSET&=~0x08;}while(0)
#define PWM15_G4_POWER_OFF          do{PWMSET&=~0x10;}while(0)
#define PWM15_G5_POWER_OFF          do{PWMSET&=~0x20;}while(0)

#define PWM15_G0_START              do{PWMCFG01|= 0x01;}while(0)
#define PWM15_G1_START              do{PWMCFG01|= 0x10;}while(0)
#define PWM15_G2_START              do{PWMCFG23|= 0x01;}while(0)
#define PWM15_G3_START              do{PWMCFG23|= 0x10;}while(0)
#define PWM15_G4_START              do{PWMCFG45|= 0x01;}while(0)
#define PWM15_G5_START              do{PWMCFG45|= 0x10;}while(0)

#define PWM15_G0_STOP               do{PWMCFG01&=~0x01;}while(0)
#define PWM15_G1_STOP               do{PWMCFG01&=~0x10;}while(0)
#define PWM15_G2_STOP               do{PWMCFG23&=~0x01;}while(0)
#define PWM15_G3_STOP               do{PWMCFG23&=~0x10;}while(0)
#define PWM15_G4_STOP               do{PWMCFG45&=~0x01;}while(0)
#define PWM15_G5_STOP               do{PWMCFG45&=~0x10;}while(0)
#endif


/*

#define PWM15_CBIT_ENABLE           do{PWMCFG|= EPWMCBI;}while(0)
#define PWM15_CBIT_DISABLE          do{PWMCFG&=~EPWMCBI;}while(0)
#define PWM15_GET_CBIT_FLAG         (PWMCFG & PWMCBIF)
#define PWM15_CLS_CBIT_FLAG         do{PWMCFG&=~PWMCBIF;}while(0)
#define PWM15_SET_ADC_ENABLE        do{PWMCFG|= EPWMTA; }while(0)
#define PWM15_SET_ADC_DISABLE       do{PWMCFG|=~EPWMTA; }while(0)

#define PWM15_SET_CMP_SIG_H_L       do{PWMFDCR|= INVCMP;}while(0)
#define PWM15_SET_CMP_SIG_L_H       do{PWMFDCR&=~INVCMP;}while(0)
#define PWM15_SET_IO_SIG_H_L        do{PWMFDCR|= INVIO;}while(0)
#define PWM15_SET_IO_SIG_L_H        do{PWMFDCR&=~INVIO;}while(0)
#define PWM15_FD_ENABLE             do{PWMFDCR|= ENFD;}while(0)
#define PWM15_FD_DISABLE            do{PWMFDCR&=~ENFD;}while(0)
#define PWM15_SET_PWMFD_IO_HZ       do{PWMFDCR|= FLTFLIO;}while(0)
#define PWM15_SET_PWMFD_IO_OUT      do{PWMFDCR&=~FLTFLIO;}while(0)
#define PWM15_FD_IT_ENABLE          do{PWMFDCR|= EFDI;}while(0)
#define PWM15_FD_IT_DISABLE         do{PWMFDCR&=~EFDI;}while(0)
#define PWM15_SET_FD_CMP_ENABLE     do{PWMFDCR|= FDCMP;}while(0)
#define PWM15_SET_FD_CMP_DISABLE    do{PWMFDCR&=~FDCMP;}while(0)
#define PWM15_SET_FD_IO_ENABLE      do{PWMFDCR|= FDIO;}while(0)
#define PWM15_SET_FD_IO_DISABLE     do{PWMFDCR&=~FDIO;}while(0)
#define PWM15_GET_FD_IT_FLAG        (PWMFDCR & FDIF)
#define PWM15_CLS_FD_IT_FLAG        do{PWMFDCR&=~FDIF;}while(0)

*/


//-------------寄存器读取----------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8A全系列
#define PWM15_SET_REG_CLK(value)    do{PWM_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_CLK           (PWM_CKS) 
#define PWM15_SET_REG_COUNT(value)  do{PWM_C=(u16)(value);}while(0)
#define PWM15_GET_REG_COUNT         (PWM_C) 

#define PWM15_SET_REG_CH0_T1(value) do{PWM_CH0_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH1_T1(value) do{PWM_CH1_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH2_T1(value) do{PWM_CH2_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH3_T1(value) do{PWM_CH3_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH4_T1(value) do{PWM_CH4_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH5_T1(value) do{PWM_CH5_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH6_T1(value) do{PWM_CH6_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH7_T1(value) do{PWM_CH7_T1=(u16)(value);}while(0)

#define PWM15_SET_REG_CH0_T2(value) do{PWM_CH0_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH1_T2(value) do{PWM_CH1_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH2_T2(value) do{PWM_CH2_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH3_T2(value) do{PWM_CH3_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH4_T2(value) do{PWM_CH4_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH5_T2(value) do{PWM_CH5_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH6_T2(value) do{PWM_CH6_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH7_T2(value) do{PWM_CH7_T2=(u16)(value);}while(0)

#define PWM15_SET_REG_CH0_CR(value) do{PWM_CH0_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH1_CR(value) do{PWM_CH1_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH2_CR(value) do{PWM_CH2_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH3_CR(value) do{PWM_CH3_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH4_CR(value) do{PWM_CH4_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH5_CR(value) do{PWM_CH5_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH6_CR(value) do{PWM_CH6_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH7_CR(value) do{PWM_CH7_CR=(u8)(value);}while(0)

#define PWM15_GET_REG_CH0_T1        (PWM_CH0_T1)
#define PWM15_GET_REG_CH1_T1        (PWM_CH1_T1)
#define PWM15_GET_REG_CH2_T1        (PWM_CH2_T1)
#define PWM15_GET_REG_CH3_T1        (PWM_CH3_T1)
#define PWM15_GET_REG_CH4_T1        (PWM_CH4_T1)
#define PWM15_GET_REG_CH5_T1        (PWM_CH5_T1)
#define PWM15_GET_REG_CH6_T1        (PWM_CH6_T1)
#define PWM15_GET_REG_CH7_T1        (PWM_CH7_T1)

#define PWM15_GET_REG_CH0_T2        (PWM_CH0_T2)
#define PWM15_GET_REG_CH1_T2        (PWM_CH1_T2)
#define PWM15_GET_REG_CH2_T2        (PWM_CH2_T2)
#define PWM15_GET_REG_CH3_T2        (PWM_CH3_T2)
#define PWM15_GET_REG_CH4_T2        (PWM_CH4_T2)
#define PWM15_GET_REG_CH5_T2        (PWM_CH5_T2)
#define PWM15_GET_REG_CH6_T2        (PWM_CH6_T2)
#define PWM15_GET_REG_CH7_T2        (PWM_CH7_T2)

#define PWM15_GET_REG_CH0_CR        (PWM_CH0_CR)
#define PWM15_GET_REG_CH1_CR        (PWM_CH1_CR)
#define PWM15_GET_REG_CH2_CR        (PWM_CH2_CR)
#define PWM15_GET_REG_CH3_CR        (PWM_CH3_CR)
#define PWM15_GET_REG_CH4_CR        (PWM_CH4_CR)
#define PWM15_GET_REG_CH5_CR        (PWM_CH5_CR)
#define PWM15_GET_REG_CH6_CR        (PWM_CH6_CR)
#define PWM15_GET_REG_CH7_CR        (PWM_CH7_CR)

#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_SET_REG_G0_CLK(value)    do{PWM_P0_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G0_CLK           (PWM_P0_CKS) 
#define PWM15_SET_REG_G0_COUNT(value)  do{PWM_P0_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G0_COUNT         (PWM_P0_C) 
#define PWM15_SET_REG_G1_CLK(value)    do{PWM_P1_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G1_CLK           (PWM_P1_CKS) 
#define PWM15_SET_REG_G1_COUNT(value)  do{PWM_P1_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G1_COUNT         (PWM_P1_C) 
#define PWM15_SET_REG_G2_CLK(value)    do{PWM_P2_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G2_CLK           (PWM_P2_CKS) 
#define PWM15_SET_REG_G2_COUNT(value)  do{PWM_P2_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G2_COUNT         (PWM_P2_C) 
#define PWM15_SET_REG_G3_CLK(value)    do{PWM_P3_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G3_CLK           (PWM_P3_CKS) 
#define PWM15_SET_REG_G3_COUNT(value)  do{PWM_P3_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G3_COUNT         (PWM_P3_C) 
#define PWM15_SET_REG_G4_CLK(value)    do{PWM_P4_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G4_CLK           (PWM_P4_CKS) 
#define PWM15_SET_REG_G4_COUNT(value)  do{PWM_P4_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G4_COUNT         (PWM_P4_C) 
#define PWM15_SET_REG_G5_CLK(value)    do{PWM_P5_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G5_CLK           (PWM_P5_CKS) 
#define PWM15_SET_REG_G5_COUNT(value)  do{PWM_P5_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G5_COUNT         (PWM_P5_C) 

#define PWM15_SET_REG_G0_CH0_T1(value) do{PWM_P00_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_T1(value) do{PWM_P01_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_T1(value) do{PWM_P02_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_T1(value) do{PWM_P03_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_T1(value) do{PWM_P04_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_T1(value) do{PWM_P05_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_T1(value) do{PWM_P06_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_T1(value) do{PWM_P07_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_T1(value) do{PWM_P10_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_T1(value) do{PWM_P11_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_T1(value) do{PWM_P12_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_T1(value) do{PWM_P13_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_T1(value) do{PWM_P14_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_T1(value) do{PWM_P15_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_T1(value) do{PWM_P16_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_T1(value) do{PWM_P17_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_T1(value) do{PWM_P20_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_T1(value) do{PWM_P21_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_T1(value) do{PWM_P22_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_T1(value) do{PWM_P23_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_T1(value) do{PWM_P24_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_T1(value) do{PWM_P25_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_T1(value) do{PWM_P26_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_T1(value) do{PWM_P27_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_T1(value) do{PWM_P30_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_T1(value) do{PWM_P31_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_T1(value) do{PWM_P32_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_T1(value) do{PWM_P33_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_T1(value) do{PWM_P34_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_T1(value) do{PWM_P35_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_T1(value) do{PWM_P36_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_T1(value) do{PWM_P37_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_T1(value) do{PWM_P40_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_T1(value) do{PWM_P41_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_T1(value) do{PWM_P42_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_T1(value) do{PWM_P43_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_T1(value) do{PWM_P44_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_T1(value) do{PWM_P45_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_T1(value) do{PWM_P46_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_T1(value) do{PWM_P47_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_T1(value) do{PWM_P50_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_T1(value) do{PWM_P51_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_T1(value) do{PWM_P52_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_T1(value) do{PWM_P53_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_T1(value) do{PWM_P54_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_T1(value) do{PWM_P55_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_T1(value) do{PWM_P56_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_T1(value) do{PWM_P57_T1=(u16)(value);}while(0)

#define PWM15_SET_REG_G0_CH0_T2(value) do{PWM_P00_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_T2(value) do{PWM_P01_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_T2(value) do{PWM_P02_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_T2(value) do{PWM_P03_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_T2(value) do{PWM_P04_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_T2(value) do{PWM_P05_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_T2(value) do{PWM_P06_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_T2(value) do{PWM_P07_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_T2(value) do{PWM_P10_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_T2(value) do{PWM_P11_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_T2(value) do{PWM_P12_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_T2(value) do{PWM_P13_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_T2(value) do{PWM_P14_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_T2(value) do{PWM_P15_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_T2(value) do{PWM_P16_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_T2(value) do{PWM_P17_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_T2(value) do{PWM_P20_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_T2(value) do{PWM_P21_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_T2(value) do{PWM_P22_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_T2(value) do{PWM_P23_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_T2(value) do{PWM_P24_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_T2(value) do{PWM_P25_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_T2(value) do{PWM_P26_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_T2(value) do{PWM_P27_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_T2(value) do{PWM_P30_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_T2(value) do{PWM_P31_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_T2(value) do{PWM_P32_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_T2(value) do{PWM_P33_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_T2(value) do{PWM_P34_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_T2(value) do{PWM_P35_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_T2(value) do{PWM_P36_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_T2(value) do{PWM_P37_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_T2(value) do{PWM_P40_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_T2(value) do{PWM_P41_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_T2(value) do{PWM_P42_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_T2(value) do{PWM_P43_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_T2(value) do{PWM_P44_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_T2(value) do{PWM_P45_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_T2(value) do{PWM_P46_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_T2(value) do{PWM_P47_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_T2(value) do{PWM_P50_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_T2(value) do{PWM_P51_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_T2(value) do{PWM_P52_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_T2(value) do{PWM_P53_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_T2(value) do{PWM_P54_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_T2(value) do{PWM_P55_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_T2(value) do{PWM_P56_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_T2(value) do{PWM_P57_T2=(u16)(value);}while(0)

#define PWM15_SET_REG_G0_CH0_CR(value) do{PWM_P00_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_CR(value) do{PWM_P01_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_CR(value) do{PWM_P02_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_CR(value) do{PWM_P03_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_CR(value) do{PWM_P04_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_CR(value) do{PWM_P05_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_CR(value) do{PWM_P06_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_CR(value) do{PWM_P07_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_CR(value) do{PWM_P10_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_CR(value) do{PWM_P11_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_CR(value) do{PWM_P12_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_CR(value) do{PWM_P13_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_CR(value) do{PWM_P14_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_CR(value) do{PWM_P15_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_CR(value) do{PWM_P16_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_CR(value) do{PWM_P17_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_CR(value) do{PWM_P20_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_CR(value) do{PWM_P21_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_CR(value) do{PWM_P22_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_CR(value) do{PWM_P23_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_CR(value) do{PWM_P24_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_CR(value) do{PWM_P25_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_CR(value) do{PWM_P26_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_CR(value) do{PWM_P27_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_CR(value) do{PWM_P30_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_CR(value) do{PWM_P31_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_CR(value) do{PWM_P32_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_CR(value) do{PWM_P33_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_CR(value) do{PWM_P34_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_CR(value) do{PWM_P35_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_CR(value) do{PWM_P36_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_CR(value) do{PWM_P37_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_CR(value) do{PWM_P40_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_CR(value) do{PWM_P41_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_CR(value) do{PWM_P42_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_CR(value) do{PWM_P43_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_CR(value) do{PWM_P44_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_CR(value) do{PWM_P45_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_CR(value) do{PWM_P46_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_CR(value) do{PWM_P47_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_CR(value) do{PWM_P50_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_CR(value) do{PWM_P51_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_CR(value) do{PWM_P52_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_CR(value) do{PWM_P53_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_CR(value) do{PWM_P54_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_CR(value) do{PWM_P55_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_CR(value) do{PWM_P56_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_CR(value) do{PWM_P57_CR=(u16)(value);}while(0)

#define PWM15_GET_REG_G0_CH0_T1        (PWM_P00_T1)
#define PWM15_GET_REG_G0_CH1_T1        (PWM_P01_T1)
#define PWM15_GET_REG_G0_CH2_T1        (PWM_P02_T1)
#define PWM15_GET_REG_G0_CH3_T1        (PWM_P03_T1)
#define PWM15_GET_REG_G0_CH4_T1        (PWM_P04_T1)
#define PWM15_GET_REG_G0_CH5_T1        (PWM_P05_T1)
#define PWM15_GET_REG_G0_CH6_T1        (PWM_P06_T1)
#define PWM15_GET_REG_G0_CH7_T1        (PWM_P07_T1)
#define PWM15_GET_REG_G1_CH0_T1        (PWM_P10_T1)
#define PWM15_GET_REG_G1_CH1_T1        (PWM_P11_T1)
#define PWM15_GET_REG_G1_CH2_T1        (PWM_P12_T1)
#define PWM15_GET_REG_G1_CH3_T1        (PWM_P13_T1)
#define PWM15_GET_REG_G1_CH4_T1        (PWM_P14_T1)
#define PWM15_GET_REG_G1_CH5_T1        (PWM_P15_T1)
#define PWM15_GET_REG_G1_CH6_T1        (PWM_P16_T1)
#define PWM15_GET_REG_G1_CH7_T1        (PWM_P17_T1)
#define PWM15_GET_REG_G2_CH0_T1        (PWM_P20_T1)
#define PWM15_GET_REG_G2_CH1_T1        (PWM_P21_T1)
#define PWM15_GET_REG_G2_CH2_T1        (PWM_P22_T1)
#define PWM15_GET_REG_G2_CH3_T1        (PWM_P23_T1)
#define PWM15_GET_REG_G2_CH4_T1        (PWM_P24_T1)
#define PWM15_GET_REG_G2_CH5_T1        (PWM_P25_T1)
#define PWM15_GET_REG_G2_CH6_T1        (PWM_P26_T1)
#define PWM15_GET_REG_G2_CH7_T1        (PWM_P27_T1)
#define PWM15_GET_REG_G3_CH0_T1        (PWM_P30_T1)
#define PWM15_GET_REG_G3_CH1_T1        (PWM_P31_T1)
#define PWM15_GET_REG_G3_CH2_T1        (PWM_P32_T1)
#define PWM15_GET_REG_G3_CH3_T1        (PWM_P33_T1)
#define PWM15_GET_REG_G3_CH4_T1        (PWM_P34_T1)
#define PWM15_GET_REG_G3_CH5_T1        (PWM_P35_T1)
#define PWM15_GET_REG_G3_CH6_T1        (PWM_P36_T1)
#define PWM15_GET_REG_G3_CH7_T1        (PWM_P37_T1)
#define PWM15_GET_REG_G4_CH0_T1        (PWM_P40_T1)
#define PWM15_GET_REG_G4_CH1_T1        (PWM_P41_T1)
#define PWM15_GET_REG_G4_CH2_T1        (PWM_P42_T1)
#define PWM15_GET_REG_G4_CH3_T1        (PWM_P43_T1)
#define PWM15_GET_REG_G4_CH4_T1        (PWM_P44_T1)
#define PWM15_GET_REG_G4_CH5_T1        (PWM_P45_T1)
#define PWM15_GET_REG_G4_CH6_T1        (PWM_P46_T1)
#define PWM15_GET_REG_G4_CH7_T1        (PWM_P47_T1)
#define PWM15_GET_REG_G5_CH0_T1        (PWM_P50_T1)
#define PWM15_GET_REG_G5_CH1_T1        (PWM_P51_T1)
#define PWM15_GET_REG_G5_CH2_T1        (PWM_P52_T1)
#define PWM15_GET_REG_G5_CH3_T1        (PWM_P53_T1)
#define PWM15_GET_REG_G5_CH4_T1        (PWM_P54_T1)
#define PWM15_GET_REG_G5_CH5_T1        (PWM_P55_T1)
#define PWM15_GET_REG_G5_CH6_T1        (PWM_P56_T1)
#define PWM15_GET_REG_G5_CH7_T1        (PWM_P57_T1)

#define PWM15_GET_REG_G0_CH0_T2        (PWM_P00_T2)
#define PWM15_GET_REG_G0_CH1_T2        (PWM_P01_T2)
#define PWM15_GET_REG_G0_CH2_T2        (PWM_P02_T2)
#define PWM15_GET_REG_G0_CH3_T2        (PWM_P03_T2)
#define PWM15_GET_REG_G0_CH4_T2        (PWM_P04_T2)
#define PWM15_GET_REG_G0_CH5_T2        (PWM_P05_T2)
#define PWM15_GET_REG_G0_CH6_T2        (PWM_P06_T2)
#define PWM15_GET_REG_G0_CH7_T2        (PWM_P07_T2)
#define PWM15_GET_REG_G1_CH0_T2        (PWM_P10_T2)
#define PWM15_GET_REG_G1_CH1_T2        (PWM_P11_T2)
#define PWM15_GET_REG_G1_CH2_T2        (PWM_P12_T2)
#define PWM15_GET_REG_G1_CH3_T2        (PWM_P13_T2)
#define PWM15_GET_REG_G1_CH4_T2        (PWM_P14_T2)
#define PWM15_GET_REG_G1_CH5_T2        (PWM_P15_T2)
#define PWM15_GET_REG_G1_CH6_T2        (PWM_P16_T2)
#define PWM15_GET_REG_G1_CH7_T2        (PWM_P17_T2)
#define PWM15_GET_REG_G2_CH0_T2        (PWM_P20_T2)
#define PWM15_GET_REG_G2_CH1_T2        (PWM_P21_T2)
#define PWM15_GET_REG_G2_CH2_T2        (PWM_P22_T2)
#define PWM15_GET_REG_G2_CH3_T2        (PWM_P23_T2)
#define PWM15_GET_REG_G2_CH4_T2        (PWM_P24_T2)
#define PWM15_GET_REG_G2_CH5_T2        (PWM_P25_T2)
#define PWM15_GET_REG_G2_CH6_T2        (PWM_P26_T2)
#define PWM15_GET_REG_G2_CH7_T2        (PWM_P27_T2)
#define PWM15_GET_REG_G3_CH0_T2        (PWM_P30_T2)
#define PWM15_GET_REG_G3_CH1_T2        (PWM_P31_T2)
#define PWM15_GET_REG_G3_CH2_T2        (PWM_P32_T2)
#define PWM15_GET_REG_G3_CH3_T2        (PWM_P33_T2)
#define PWM15_GET_REG_G3_CH4_T2        (PWM_P34_T2)
#define PWM15_GET_REG_G3_CH5_T2        (PWM_P35_T2)
#define PWM15_GET_REG_G3_CH6_T2        (PWM_P36_T2)
#define PWM15_GET_REG_G3_CH7_T2        (PWM_P37_T2)
#define PWM15_GET_REG_G4_CH0_T2        (PWM_P40_T2)
#define PWM15_GET_REG_G4_CH1_T2        (PWM_P41_T2)
#define PWM15_GET_REG_G4_CH2_T2        (PWM_P42_T2)
#define PWM15_GET_REG_G4_CH3_T2        (PWM_P43_T2)
#define PWM15_GET_REG_G4_CH4_T2        (PWM_P44_T2)
#define PWM15_GET_REG_G4_CH5_T2        (PWM_P45_T2)
#define PWM15_GET_REG_G4_CH6_T2        (PWM_P46_T2)
#define PWM15_GET_REG_G4_CH7_T2        (PWM_P47_T2)
#define PWM15_GET_REG_G5_CH0_T2        (PWM_P50_T2)
#define PWM15_GET_REG_G5_CH1_T2        (PWM_P51_T2)
#define PWM15_GET_REG_G5_CH2_T2        (PWM_P52_T2)
#define PWM15_GET_REG_G5_CH3_T2        (PWM_P53_T2)
#define PWM15_GET_REG_G5_CH4_T2        (PWM_P54_T2)
#define PWM15_GET_REG_G5_CH5_T2        (PWM_P55_T2)
#define PWM15_GET_REG_G5_CH6_T2        (PWM_P56_T2)
#define PWM15_GET_REG_G5_CH7_T2        (PWM_P57_T2)

#define PWM15_GET_REG_G0_CH0_CR        (PWM_P00_CR)
#define PWM15_GET_REG_G0_CH1_CR        (PWM_P01_CR)
#define PWM15_GET_REG_G0_CH2_CR        (PWM_P02_CR)
#define PWM15_GET_REG_G0_CH3_CR        (PWM_P03_CR)
#define PWM15_GET_REG_G0_CH4_CR        (PWM_P04_CR)
#define PWM15_GET_REG_G0_CH5_CR        (PWM_P05_CR)
#define PWM15_GET_REG_G0_CH6_CR        (PWM_P06_CR)
#define PWM15_GET_REG_G0_CH7_CR        (PWM_P07_CR)
#define PWM15_GET_REG_G1_CH0_CR        (PWM_P10_CR)
#define PWM15_GET_REG_G1_CH1_CR        (PWM_P11_CR)
#define PWM15_GET_REG_G1_CH2_CR        (PWM_P12_CR)
#define PWM15_GET_REG_G1_CH3_CR        (PWM_P13_CR)
#define PWM15_GET_REG_G1_CH4_CR        (PWM_P14_CR)
#define PWM15_GET_REG_G1_CH5_CR        (PWM_P15_CR)
#define PWM15_GET_REG_G1_CH6_CR        (PWM_P16_CR)
#define PWM15_GET_REG_G1_CH7_CR        (PWM_P17_CR)
#define PWM15_GET_REG_G2_CH0_CR        (PWM_P20_CR)
#define PWM15_GET_REG_G2_CH1_CR        (PWM_P21_CR)
#define PWM15_GET_REG_G2_CH2_CR        (PWM_P22_CR)
#define PWM15_GET_REG_G2_CH3_CR        (PWM_P23_CR)
#define PWM15_GET_REG_G2_CH4_CR        (PWM_P24_CR)
#define PWM15_GET_REG_G2_CH5_CR        (PWM_P25_CR)
#define PWM15_GET_REG_G2_CH6_CR        (PWM_P26_CR)
#define PWM15_GET_REG_G2_CH7_CR        (PWM_P27_CR)
#define PWM15_GET_REG_G3_CH0_CR        (PWM_P30_CR)
#define PWM15_GET_REG_G3_CH1_CR        (PWM_P31_CR)
#define PWM15_GET_REG_G3_CH2_CR        (PWM_P32_CR)
#define PWM15_GET_REG_G3_CH3_CR        (PWM_P33_CR)
#define PWM15_GET_REG_G3_CH4_CR        (PWM_P34_CR)
#define PWM15_GET_REG_G3_CH5_CR        (PWM_P35_CR)
#define PWM15_GET_REG_G3_CH6_CR        (PWM_P36_CR)
#define PWM15_GET_REG_G3_CH7_CR        (PWM_P37_CR)
#define PWM15_GET_REG_G4_CH0_CR        (PWM_P40_CR)
#define PWM15_GET_REG_G4_CH1_CR        (PWM_P41_CR)
#define PWM15_GET_REG_G4_CH2_CR        (PWM_P42_CR)
#define PWM15_GET_REG_G4_CH3_CR        (PWM_P43_CR)
#define PWM15_GET_REG_G4_CH4_CR        (PWM_P44_CR)
#define PWM15_GET_REG_G4_CH5_CR        (PWM_P45_CR)
#define PWM15_GET_REG_G4_CH6_CR        (PWM_P46_CR)
#define PWM15_GET_REG_G4_CH7_CR        (PWM_P47_CR)
#define PWM15_GET_REG_G5_CH0_CR        (PWM_P50_CR)
#define PWM15_GET_REG_G5_CH1_CR        (PWM_P51_CR)
#define PWM15_GET_REG_G5_CH2_CR        (PWM_P52_CR)
#define PWM15_GET_REG_G5_CH3_CR        (PWM_P53_CR)
#define PWM15_GET_REG_G5_CH4_CR        (PWM_P54_CR)
#define PWM15_GET_REG_G5_CH5_CR        (PWM_P55_CR)
#define PWM15_GET_REG_G5_CH6_CR        (PWM_P56_CR)
#define PWM15_GET_REG_G5_CH7_CR        (PWM_P57_CR)
#endif
/*
#define PWM15_SET_REG_TADC(value)   do{PWM_TADCP=(u16)(value);}while(0)
#define PWM15_GET_REG_TADC          (PWM_TADCP) 
#define PWM15_SET_REG_FDCR(value)   do{PWM_FDCR=(u8)(value);}while(0)
#define PWM15_GET_REG_FDCR          (PWM_FDCR)
*/
/*--------------------------------RTC特殊功能寄存器------------------------------*/
#define RUNRTC      0X01
#define RTCCKS      0X02
#define SETRTC      0X01
#define EALAI       0X80
#define EDAYI       0X40
#define EHOURI      0X20
#define EMINI       0X10
#define ESECI       0X08
#define ESEC2I      0X04
#define ESEC8I      0X02
#define ESEC32I     0X01
#define ALAIF       0X80
#define DAYIF       0X40
#define HOURIF      0X20
#define MINIF       0X10
#define SECIF       0X08
#define SEC2IF      0X04
#define SEC8IF      0X02
#define SEC32IF     0X01
//-------------功能指令------------//
#define RTC_POWER_ON                do{RTCCR=1;}while(0)
#define RTC_POWER_OFF               do{RTCCR=0;}while(0)
#define RTC_SET_CLK_LSE             REG_RESET_BIT(RTCCFG,RTCCKS)
#define RTC_SET_CLK_LSI             REG_SET_BIT(RTCCFG,RTCCKS)
#define RTC_RESET                   REG_SET_BIT(RTCCFG,SETRTC)
#define RTC_ALARM_IT_ENABLE         REG_SET_BIT(RTCIEN,EALAI)
#define RTC_ALARM_IT_DISBLE         REG_RESET_BIT(RTCIEN,EALAI)
#define RTC_DAY_IT_ENABLE           REG_SET_BIT(RTCIEN,EDAYI)
#define RTC_DAY_IT_DISBLE           REG_RESET_BIT(RTCIEN,EDAYI)
#define RTC_HOUR_IT_ENABLE          REG_SET_BIT(RTCIEN,EHOURI)
#define RTC_HOUR_IT_DISBLE          REG_RESET_BIT(RTCIEN,EHOURI)
#define RTC_MIN_IT_ENABLE           REG_SET_BIT(RTCIEN,EMINI)
#define RTC_MIN_IT_DISBLE           REG_RESET_BIT(RTCIEN,EMINI)
#define RTC_SEC_IT_ENABLE           REG_SET_BIT(RTCIEN,ESECI)
#define RTC_SEC_IT_DISBLE           REG_RESET_BIT(RTCIEN,ESECI)
#define RTC_SEC2_IT_ENABLE          REG_SET_BIT(RTCIEN,ESEC2I)
#define RTC_SEC2_IT_DISBLE          REG_RESET_BIT(RTCIEN,ESEC2I)
#define RTC_SEC8_IT_ENABLE          REG_SET_BIT(RTCIEN,ESEC8I)
#define RTC_SEC8_IT_DISBLE          REG_RESET_BIT(RTCIEN,ESEC8I)
#define RTC_SEC32_IT_ENABLE         REG_SET_BIT(RTCIEN,ESEC32I)
#define RTC_SEC32_IT_DISBLE         REG_RESET_BIT(RTCIEN,ESEC32I)

#define RTC_GET_ALARM_IT_FLAG       (RTCIF & ALAIF)  
#define RTC_CLS_ALARM_IT_FLAG       REG_RESET_BIT(RTCIF,ALAIF)
#define RTC_GET_DAY_IT_FLAG         (RTCIF & DAYIF)  
#define RTC_CLS_DAY_IT_FLAG         REG_RESET_BIT(RTCIF,DAYIF)
#define RTC_GET_HOUR_IT_FLAG        (RTCIF & HOURIF)  
#define RTC_CLS_HOUR_IT_FLAG        REG_RESET_BIT(RTCIF,HOURIF)
#define RTC_GET_MIN_IT_FLAG         (RTCIF & MINIF)  
#define RTC_CLS_MIN_IT_FLAG         REG_RESET_BIT(RTCIF,MINIF)
#define RTC_GET_SEC_IT_FLAG         (RTCIF & SECIF)  
#define RTC_CLS_SEC_IT_FLAG         REG_RESET_BIT(RTCIF,SECIF)
#define RTC_GET_SEC2_IT_FLAG        (RTCIF & SEC2IF)  
#define RTC_CLS_SEC2_IT_FLAG        REG_RESET_BIT(RTCIF,SEC2IF)
#define RTC_GET_SEC8_IT_FLAG        (RTCIF & SEC8IF)  
#define RTC_CLS_SEC8_IT_FLAG        REG_RESET_BIT(RTCIF,SEC8IF)
#define RTC_GET_SEC32_IT_FLAG       (RTCIF & SEC32IF)  
#define RTC_CLS_SEC32_IT_FLAG       REG_RESET_BIT(RTCIF,SEC32IF)
//-------------寄存器读取----------//
#define RTC_SET_REG_CR(value)       do{RTCCR=(u8)(value);}while(0)
#define RTC_GET_REG_CR              (RTCCR)   
#define RTC_SET_REG_CFG(value)      do{RTCCFG=(u8)(value);}while(0)
#define RTC_GET_REG_CFG             (RTCCFG)   
#define RTC_SET_REG_IEN(value)      do{RTCIEN=(u8)(value);}while(0)
#define RTC_GET_REG_IEN             (RTCIEN)   
#define RTC_SET_REG_IF(value)       do{RTCIF=(u8)(value);}while(0)
#define RTC_GET_REG_IF              (RTCIF)   

#define RTC_SET_REG_ALAHOUR(value)  do{ALAHOUR=(u8)(value);}while(0)
#define RTC_GET_REG_ALAHOUR         (ALAHOUR)   
#define RTC_SET_REG_ALAMIN(value)   do{ALAMIN=(u8)(value);}while(0)
#define RTC_GET_REG_ALAMIN          (ALAMIN)   
#define RTC_SET_REG_ALASEC(value)   do{ALASEC=(u8)(value);}while(0)
#define RTC_GET_REG_ALASEC          (ALASEC)   
#define RTC_SET_REG_ALASSEC(value)  do{ALASSEC=(u8)(value);}while(0)
#define RTC_GET_REG_ALASSEC         (ALASSEC)   
#define RTC_SET_REG_INIYEAR(value)  do{INIYEAR=(u8)(value);}while(0)
#define RTC_GET_REG_INIYEAR         (INIYEAR)   
#define RTC_SET_REG_INIMONTH(value) do{INIMONTH=(u8)(value);}while(0)
#define RTC_GET_REG_INIMONTH        (INIMONTH) 
#define RTC_SET_REG_INIDAY(value)   do{INIDAY=(u8)(value);}while(0)
#define RTC_GET_REG_INIDAY          (INIDAY) 
#define RTC_SET_REG_INIHOUR(value)  do{INIHOUR=(u8)(value);}while(0)
#define RTC_GET_REG_INIHOUR         (INIHOUR)
#define RTC_SET_REG_INIMIN(value)   do{INIMIN=(u8)(value);}while(0)
#define RTC_GET_REG_INIMIN          (INIMIN) 
#define RTC_SET_REG_INISEC(value)   do{INISEC=(u8)(value);}while(0)
#define RTC_GET_REG_INISEC          (INISEC) 
#define RTC_SET_REG_INISSEC(value)  do{INISSEC=(u8)(value);}while(0)
#define RTC_GET_REG_INISSEC         (INISSEC) 
/*--------------------------------LED特殊功能寄存器------------------------------*/
#define C7EN    0X80
#define C6EN    0X40
#define C5EN    0X20
#define C4EN    0X10
#define C3EN    0X08
#define C2EN    0X04
#define C1EN    0X02
#define C0EN    0X01

#define S15EN   0X80
#define S14EN   0X40
#define S13EN   0X20
#define S12EN   0X10
#define S11EN   0X08
#define S10EN   0X04
#define S9EN    0X02
#define S8EN    0X01
#define S7EN    0X80
#define S6EN    0X40
#define S5EN    0X20
#define S4EN    0X10
#define S3EN    0X08
#define S2EN    0X04
#define S1EN    0X02
#define S0EN    0X01

#define LEDON   0X80
#define LEDMODE 0X30
#define LEDDUTY 0X07
//-------------功能指令------------//
#define LED_COM0_ENABLE      REG_SET_BIT(COMEN,C0EN)
#define LED_COM0_DISABLE     REG_RESET_BIT(COMEN,C0EN)
#define LED_COM1_ENABLE      REG_SET_BIT(COMEN,C1EN)
#define LED_COM1_DISABLE     REG_RESET_BIT(COMEN,C1EN)
#define LED_COM2_ENABLE      REG_SET_BIT(COMEN,C2EN)
#define LED_COM2_DISABLE     REG_RESET_BIT(COMEN,C2EN)
#define LED_COM3_ENABLE      REG_SET_BIT(COMEN,C3EN)
#define LED_COM3_DISABLE     REG_RESET_BIT(COMEN,C3EN)
#define LED_COM4_ENABLE      REG_SET_BIT(COMEN,C4EN)
#define LED_COM4_DISABLE     REG_RESET_BIT(COMEN,C4EN)
#define LED_COM5_ENABLE      REG_SET_BIT(COMEN,C5EN)
#define LED_COM5_DISABLE     REG_RESET_BIT(COMEN,C5EN)
#define LED_COM6_ENABLE      REG_SET_BIT(COMEN,C6EN)
#define LED_COM6_DISABLE     REG_RESET_BIT(COMEN,C6EN)
#define LED_COM7_ENABLE      REG_SET_BIT(COMEN,C7EN)
#define LED_COM7_DISABLE     REG_RESET_BIT(COMEN,C7EN)

#define LED_SEG0_ENABLE      REG_SET_BIT(SEGENL,S0EN)
#define LED_SEG0_DISABLE     REG_RESET_BIT(SEGENL,S0EN)
#define LED_SEG1_ENABLE      REG_SET_BIT(SEGENL,S1EN)
#define LED_SEG1_DISABLE     REG_RESET_BIT(SEGENL,S1EN)
#define LED_SEG2_ENABLE      REG_SET_BIT(SEGENL,S2EN)
#define LED_SEG2_DISABLE     REG_RESET_BIT(SEGENL,S2EN)
#define LED_SEG3_ENABLE      REG_SET_BIT(SEGENL,S3EN)
#define LED_SEG3_DISABLE     REG_RESET_BIT(SEGENL,S3EN)
#define LED_SEG4_ENABLE      REG_SET_BIT(SEGENL,S4EN)
#define LED_SEG4_DISABLE     REG_RESET_BIT(SEGENL,S4EN)
#define LED_SEG5_ENABLE      REG_SET_BIT(SEGENL,S5EN)
#define LED_SEG5_DISABLE     REG_RESET_BIT(SEGENL,S5EN)
#define LED_SEG6_ENABLE      REG_SET_BIT(SEGENL,S6EN)
#define LED_SEG6_DISABLE     REG_RESET_BIT(SEGENL,S6EN)
#define LED_SEG7_ENABLE      REG_SET_BIT(SEGENL,S7EN)
#define LED_SEG7_DISABLE     REG_RESET_BIT(SEGENL,S7EN)

#define LED_SEG8_ENABLE      REG_SET_BIT(SEGENH,S8EN)
#define LED_SEG8_DISABLE     REG_RESET_BIT(SEGENH,S8EN)
#define LED_SEG9_ENABLE      REG_SET_BIT(SEGENH,S9EN)
#define LED_SEG9_DISABLE     REG_RESET_BIT(SEGENH,S9EN)
#define LED_SEG10_ENABLE      REG_SET_BIT(SEGENH,S10EN)
#define LED_SEG10_DISABLE     REG_RESET_BIT(SEGENH,S10EN)
#define LED_SEG11_ENABLE      REG_SET_BIT(SEGENH,S11EN)
#define LED_SEG11_DISABLE     REG_RESET_BIT(SEGENH,S11EN)
#define LED_SEG12_ENABLE      REG_SET_BIT(SEGENH,S12EN)
#define LED_SEG12_DISABLE     REG_RESET_BIT(SEGENH,S12EN)
#define LED_SEG13_ENABLE      REG_SET_BIT(SEGENH,S13EN)
#define LED_SEG13_DISABLE     REG_RESET_BIT(SEGENH,S13EN)
#define LED_SEG14_ENABLE      REG_SET_BIT(SEGENH,S14EN)
#define LED_SEG14_DISABLE     REG_RESET_BIT(SEGENH,S14EN)
#define LED_SEG15_ENABLE      REG_SET_BIT(SEGENH,S15EN)
#define LED_SEG15_DISABLE     REG_RESET_BIT(SEGENH,S15EN)

#define LED_POWER_ON          REG_SET_BIT(LEDCTRL,LEDON)
#define LED_POWER_OFF         REG_RESET_BIT(LEDCTRL,LEDON)

#define LED_SET_MODE_DC       REG_IN_MASK(LEDCTRL,LEDMODE,0x00)
#define LED_SET_MODE_DA       REG_IN_MASK(LEDCTRL,LEDMODE,0x10)
#define LED_SET_MODE_DCA      REG_IN_MASK(LEDCTRL,LEDMODE,0x20)
#define LED_SET_DUTY(value)   REG_IN_MASK(LEDCTRL,LEDDUTY,value)
#define LED_SET_CLK_DIV(value)       do{LEDCKS=(u8)(value);}while(0)
//-------------寄存器读取----------//
#define LED_SET_REG_COMEN(value)    do{COMEN=(u8)(value);}while(0)
#define LED_GET_REG_COMEN           (COMEN)                       
#define LED_SET_REG_SEGENL(value)   do{SEGENL=(u8)(value);}while(0)
#define LED_GET_REG_SEGENL          (SEGENL)      
#define LED_SET_REG_SEGENH(value)   do{SEGENH=(u8)(value);}while(0)
#define LED_GET_REG_SEGENH          (SEGENH)     
#define LED_SET_REG_CTRL(value)     do{LEDCTRL=(u8)(value);}while(0)
#define LED_GET_REG_CTRL            (LEDCTRL)  
#define LED_SET_REG_CKS(value)      do{LEDCKS=(u8)(value);}while(0)
#define LED_GET_REG_CKS             (LEDCKS) 

#define LED_SET_REG_COM0_DA_L(value)      do{COM0_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM0_DA_L             (COM0_DA_L) 
#define LED_SET_REG_COM1_DA_L(value)      do{COM1_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM1_DA_L             (COM1_DA_L) 
#define LED_SET_REG_COM2_DA_L(value)      do{COM2_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM2_DA_L             (COM2_DA_L) 
#define LED_SET_REG_COM3_DA_L(value)      do{COM3_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM3_DA_L             (COM3_DA_L) 
#define LED_SET_REG_COM4_DA_L(value)      do{COM4_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM4_DA_L             (COM4_DA_L) 
#define LED_SET_REG_COM5_DA_L(value)      do{COM5_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM5_DA_L             (COM5_DA_L) 
#define LED_SET_REG_COM6_DA_L(value)      do{COM6_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM6_DA_L             (COM6_DA_L) 
#define LED_SET_REG_COM7_DA_L(value)      do{COM7_DA_L=(u8)(value);}while(0)
#define LED_GET_REG_COM7_DA_L             (COM7_DA_L) 

#define LED_SET_REG_COM0_DA_H(value)      do{COM0_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM0_DA_H             (COM0_DA_H) 
#define LED_SET_REG_COM1_DA_H(value)      do{COM1_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM1_DA_H             (COM1_DA_H) 
#define LED_SET_REG_COM2_DA_H(value)      do{COM2_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM2_DA_H             (COM2_DA_H) 
#define LED_SET_REG_COM3_DA_H(value)      do{COM3_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM3_DA_H             (COM3_DA_H) 
#define LED_SET_REG_COM4_DA_H(value)      do{COM4_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM4_DA_H             (COM4_DA_H) 
#define LED_SET_REG_COM5_DA_H(value)      do{COM5_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM5_DA_H             (COM5_DA_H) 
#define LED_SET_REG_COM6_DA_H(value)      do{COM6_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM6_DA_H             (COM6_DA_H) 
#define LED_SET_REG_COM7_DA_H(value)      do{COM7_DA_H=(u8)(value);}while(0)
#define LED_GET_REG_COM7_DA_H             (COM7_DA_H) 

#define LED_SET_REG_COM0_DC_L(value)      do{COM0_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM0_DC_L             (COM0_DC_L) 
#define LED_SET_REG_COM1_DC_L(value)      do{COM1_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM1_DC_L             (COM1_DC_L) 
#define LED_SET_REG_COM2_DC_L(value)      do{COM2_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM2_DC_L             (COM2_DC_L) 
#define LED_SET_REG_COM3_DC_L(value)      do{COM3_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM3_DC_L             (COM3_DC_L) 
#define LED_SET_REG_COM4_DC_L(value)      do{COM4_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM4_DC_L             (COM4_DC_L) 
#define LED_SET_REG_COM5_DC_L(value)      do{COM5_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM5_DC_L             (COM5_DC_L) 
#define LED_SET_REG_COM6_DC_L(value)      do{COM6_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM6_DC_L             (COM6_DC_L) 
#define LED_SET_REG_COM7_DC_L(value)      do{COM7_DC_L=(u8)(value);}while(0)
#define LED_GET_REG_COM7_DC_L             (COM7_DC_L) 

#define LED_SET_REG_COM0_DC_H(value)      do{COM0_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM0_DC_H             (COM0_DC_H) 
#define LED_SET_REG_COM1_DC_H(value)      do{COM1_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM1_DC_H             (COM1_DC_H) 
#define LED_SET_REG_COM2_DC_H(value)      do{COM2_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM2_DC_H             (COM2_DC_H) 
#define LED_SET_REG_COM3_DC_H(value)      do{COM3_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM3_DC_H             (COM3_DC_H) 
#define LED_SET_REG_COM4_DC_H(value)      do{COM4_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM4_DC_H             (COM4_DC_H) 
#define LED_SET_REG_COM5_DC_H(value)      do{COM5_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM5_DC_H             (COM5_DC_H) 
#define LED_SET_REG_COM6_DC_H(value)      do{COM6_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM6_DC_H             (COM6_DC_H) 
#define LED_SET_REG_COM7_DC_H(value)      do{COM7_DC_H=(u8)(value);}while(0)
#define LED_GET_REG_COM7_DC_H             (COM7_DC_H) 
/*--------------------------------LCD特殊功能寄存器------------------------------*/
#define COM0EN  0x01
#define COM1EN  0x02
#define COM2EN  0x04
#define COM3EN  0x08

#define SEG0EN  0x01
#define SEG1EN  0x02
#define SEG2EN  0x04
#define SEG3EN  0x08
#define SEG4EN  0x10
#define SEG5EN  0x20
#define SEG6EN  0x40
#define SEG7EN  0x80

#define SEG8EN  0x01
#define SEG9EN  0x02
#define SEG10EN 0x04
#define SEG11EN 0x08
#define SEG12EN 0x10
#define SEG13EN 0x20
#define SEG14EN 0x40
#define SEG15EN 0x80

#define SEG16EN 0x01
#define SEG17EN 0x02
#define SEG18EN 0x04
#define SEG19EN 0x08
#define SEG20EN 0x10
#define SEG21EN 0x20
#define SEG22EN 0x40
#define SEG23EN 0x80

#define SEG24EN 0x01
#define SEG25EN 0x02
#define SEG26EN 0x04
#define SEG27EN 0x08
#define SEG28EN 0x10
#define SEG29EN 0x20
#define SEG30EN 0x40
#define SEG31EN 0x80

#define SEG32EN 0x01
#define SEG33EN 0x02
#define SEG34EN 0x04
#define SEG35EN 0x08
#define SEG36EN 0x10
#define SEG37EN 0x20
#define SEG38EN 0x40
#define SEG39EN 0x80

#define LCD_EN  0x01
#define LCD_MODE_NORMAL 0x00
#define LCD_MODE_LIGHT  0x02
#define LCD_MODE_DARK   0x04
#define LCD_MODE_BLINK  0x06

#define LCD_CLKSEL  0x80

#define SEG0PS  0x01
#define SEG1PS  0x02
#define SEG2PS  0x04
#define SEG3PS  0x08
//-------------功能指令------------//
#define LCD_POWER_ON         REG_SET_BIT(LCDCR,LCD_EN)
#define LCD_POWER_OFF        REG_RESET_BIT(LCDCR,LCD_EN)

#define LCD_SET_DISMODE_NORMAL  REG_IN_MASK(LCDCR,0x06,LCD_MODE_NORMAL)
#define LCD_SET_DISMODE_LIGHT   REG_IN_MASK(LCDCR,0x06,LCD_MODE_LIGHT)
#define LCD_SET_DISMODE_DARK    REG_IN_MASK(LCDCR,0x06,LCD_MODE_DARK)
#define LCD_SET_DISMODE_BLINK   REG_IN_MASK(LCDCR,0x06,LCD_MODE_BLINK)

#define LCD_COM0_ENABLE      REG_SET_BIT(COMON,COM0EN)
#define LCD_COM0_DISABLE     REG_RESET_BIT(COMON,COM0EN)
#define LCD_COM1_ENABLE      REG_SET_BIT(COMON,COM1EN)
#define LCD_COM1_DISABLE     REG_RESET_BIT(COMON,COM1EN)
#define LCD_COM2_ENABLE      REG_SET_BIT(COMON,COM2EN)
#define LCD_COM2_DISABLE     REG_RESET_BIT(COMON,COM2EN)
#define LCD_COM3_ENABLE      REG_SET_BIT(COMON,COM3EN)
#define LCD_COM3_DISABLE     REG_RESET_BIT(COMON,COM3EN)

#define LCD_SEG0_ENABLE      REG_SET_BIT(SEGON1,SEG0EN)
#define LCD_SEG0_DISABLE     REG_RESET_BIT(SEGON1,SEG0EN)
#define LCD_SEG1_ENABLE      REG_SET_BIT(SEGON1,SEG1EN)
#define LCD_SEG1_DISABLE     REG_RESET_BIT(SEGON1,SEG1EN)
#define LCD_SEG2_ENABLE      REG_SET_BIT(SEGON1,SEG2EN)
#define LCD_SEG2_DISABLE     REG_RESET_BIT(SEGON1,SEG2EN)
#define LCD_SEG3_ENABLE      REG_SET_BIT(SEGON1,SEG3EN)
#define LCD_SEG3_DISABLE     REG_RESET_BIT(SEGON1,SEG3EN)
#define LCD_SEG4_ENABLE      REG_SET_BIT(SEGON1,SEG4EN)
#define LCD_SEG4_DISABLE     REG_RESET_BIT(SEGON1,SEG4EN)
#define LCD_SEG5_ENABLE      REG_SET_BIT(SEGON1,SEG5EN)
#define LCD_SEG5_DISABLE     REG_RESET_BIT(SEGON1,SEG5EN)
#define LCD_SEG6_ENABLE      REG_SET_BIT(SEGON1,SEG6EN)
#define LCD_SEG6_DISABLE     REG_RESET_BIT(SEGON1,SEG6EN)
#define LCD_SEG7_ENABLE      REG_SET_BIT(SEGON1,SEG7EN)
#define LCD_SEG7_DISABLE     REG_RESET_BIT(SEGON1,SEG7EN)

#define LCD_SEG8_ENABLE      REG_SET_BIT(SEGON2,SEG8EN)
#define LCD_SEG8_DISABLE     REG_RESET_BIT(SEGON2,SEG8EN)
#define LCD_SEG9_ENABLE      REG_SET_BIT(SEGON2,SEG9EN)
#define LCD_SEG9_DISABLE     REG_RESET_BIT(SEGON2,SEG9EN)
#define LCD_SEG10_ENABLE     REG_SET_BIT(SEGON2,SEG10EN)
#define LCD_SEG10_DISABLE    REG_RESET_BIT(SEGON2,SEG10EN)
#define LCD_SEG11_ENABLE     REG_SET_BIT(SEGON2,SEG11EN)
#define LCD_SEG11_DISABLE    REG_RESET_BIT(SEGON2,SEG11EN)
#define LCD_SEG12_ENABLE     REG_SET_BIT(SEGON2,SEG12EN)
#define LCD_SEG12_DISABLE    REG_RESET_BIT(SEGON2,SEG12EN)
#define LCD_SEG13_ENABLE     REG_SET_BIT(SEGON2,SEG13EN)
#define LCD_SEG13_DISABLE    REG_RESET_BIT(SEGON2,SEG13EN)
#define LCD_SEG14_ENABLE     REG_SET_BIT(SEGON2,SEG14EN)
#define LCD_SEG14_DISABLE    REG_RESET_BIT(SEGON2,SEG14EN)
#define LCD_SEG15_ENABLE     REG_SET_BIT(SEGON2,SEG15EN)
#define LCD_SEG15_DISABLE    REG_RESET_BIT(SEGON2,SEG15EN)

#define LCD_SEG16_ENABLE     REG_SET_BIT(SEGON3,SEG16EN)
#define LCD_SEG16_DISABLE    REG_RESET_BIT(SEGON3,SEG16EN)
#define LCD_SEG17_ENABLE     REG_SET_BIT(SEGON3,SEG17EN)
#define LCD_SEG17_DISABLE    REG_RESET_BIT(SEGON3,SEG17EN)
#define LCD_SEG18_ENABLE     REG_SET_BIT(SEGON3,SEG18EN)
#define LCD_SEG18_DISABLE    REG_RESET_BIT(SEGON3,SEG18EN)
#define LCD_SEG19_ENABLE     REG_SET_BIT(SEGON3,SEG19EN)
#define LCD_SEG19_DISABLE    REG_RESET_BIT(SEGON3,SEG19EN)
#define LCD_SEG20_ENABLE     REG_SET_BIT(SEGON3,SEG20EN)
#define LCD_SEG20_DISABLE    REG_RESET_BIT(SEGON3,SEG20EN)
#define LCD_SEG21_ENABLE     REG_SET_BIT(SEGON3,SEG21EN)
#define LCD_SEG21_DISABLE    REG_RESET_BIT(SEGON3,SEG21EN)
#define LCD_SEG22_ENABLE     REG_SET_BIT(SEGON3,SEG22EN)
#define LCD_SEG22_DISABLE    REG_RESET_BIT(SEGON3,SEG22EN)
#define LCD_SEG23_ENABLE     REG_SET_BIT(SEGON3,SEG23EN)
#define LCD_SEG23_DISABLE    REG_RESET_BIT(SEGON3,SEG23EN)

#define LCD_SEG24_ENABLE     REG_SET_BIT(SEGON4,SEG24EN)
#define LCD_SEG24_DISABLE    REG_RESET_BIT(SEGON4,SEG24EN)
#define LCD_SEG25_ENABLE     REG_SET_BIT(SEGON4,SEG25EN)
#define LCD_SEG25_DISABLE    REG_RESET_BIT(SEGON4,SEG25EN)
#define LCD_SEG26_ENABLE     REG_SET_BIT(SEGON4,SEG26EN)
#define LCD_SEG26_DISABLE    REG_RESET_BIT(SEGON4,SEG26EN)
#define LCD_SEG27_ENABLE     REG_SET_BIT(SEGON4,SEG27EN)
#define LCD_SEG27_DISABLE    REG_RESET_BIT(SEGON4,SEG27EN)
#define LCD_SEG28_ENABLE     REG_SET_BIT(SEGON4,SEG28EN)
#define LCD_SEG28_DISABLE    REG_RESET_BIT(SEGON4,SEG28EN)
#define LCD_SEG29_ENABLE     REG_SET_BIT(SEGON4,SEG29EN)
#define LCD_SEG29_DISABLE    REG_RESET_BIT(SEGON4,SEG29EN)
#define LCD_SEG30_ENABLE     REG_SET_BIT(SEGON4,SEG30EN)
#define LCD_SEG30_DISABLE    REG_RESET_BIT(SEGON4,SEG30EN)
#define LCD_SEG31_ENABLE     REG_SET_BIT(SEGON4,SEG31EN)
#define LCD_SEG31_DISABLE    REG_RESET_BIT(SEGON4,SEG31EN)

#define LCD_SEG24_ENABLE     REG_SET_BIT(SEGON4,SEG24EN)
#define LCD_SEG24_DISABLE    REG_RESET_BIT(SEGON4,SEG24EN)
#define LCD_SEG25_ENABLE     REG_SET_BIT(SEGON4,SEG25EN)
#define LCD_SEG25_DISABLE    REG_RESET_BIT(SEGON4,SEG25EN)
#define LCD_SEG26_ENABLE     REG_SET_BIT(SEGON4,SEG26EN)
#define LCD_SEG26_DISABLE    REG_RESET_BIT(SEGON4,SEG26EN)
#define LCD_SEG27_ENABLE     REG_SET_BIT(SEGON4,SEG27EN)
#define LCD_SEG27_DISABLE    REG_RESET_BIT(SEGON4,SEG27EN)
#define LCD_SEG28_ENABLE     REG_SET_BIT(SEGON4,SEG28EN)
#define LCD_SEG28_DISABLE    REG_RESET_BIT(SEGON4,SEG28EN)
#define LCD_SEG29_ENABLE     REG_SET_BIT(SEGON4,SEG29EN)
#define LCD_SEG29_DISABLE    REG_RESET_BIT(SEGON4,SEG29EN)
#define LCD_SEG30_ENABLE     REG_SET_BIT(SEGON4,SEG30EN)
#define LCD_SEG30_DISABLE    REG_RESET_BIT(SEGON4,SEG30EN)
#define LCD_SEG31_ENABLE     REG_SET_BIT(SEGON4,SEG31EN)
#define LCD_SEG31_DISABLE    REG_RESET_BIT(SEGON4,SEG31EN)

#define LCD_SEG32_ENABLE     REG_SET_BIT(SEGON5,SEG32EN)
#define LCD_SEG32_DISABLE    REG_RESET_BIT(SEGON5,SEG32EN)
#define LCD_SEG33_ENABLE     REG_SET_BIT(SEGON5,SEG33EN)
#define LCD_SEG33_DISABLE    REG_RESET_BIT(SEGON5,SEG33EN)
#define LCD_SEG34_ENABLE     REG_SET_BIT(SEGON5,SEG34EN)
#define LCD_SEG34_DISABLE    REG_RESET_BIT(SEGON5,SEG34EN)
#define LCD_SEG35_ENABLE     REG_SET_BIT(SEGON5,SEG35EN)
#define LCD_SEG35_DISABLE    REG_RESET_BIT(SEGON5,SEG35EN)
#define LCD_SEG36_ENABLE     REG_SET_BIT(SEGON5,SEG36EN)
#define LCD_SEG36_DISABLE    REG_RESET_BIT(SEGON5,SEG36EN)
#define LCD_SEG37_ENABLE     REG_SET_BIT(SEGON5,SEG37EN)
#define LCD_SEG37_DISABLE    REG_RESET_BIT(SEGON5,SEG37EN)
#define LCD_SEG38_ENABLE     REG_SET_BIT(SEGON5,SEG38EN)
#define LCD_SEG38_DISABLE    REG_RESET_BIT(SEGON5,SEG38EN)
#define LCD_SEG39_ENABLE     REG_SET_BIT(SEGON5,SEG39EN)
#define LCD_SEG39_DISABLE    REG_RESET_BIT(SEGON5,SEG39EN)
//-------------寄存器读取----------//
#define LCD_SET_REG_CFG(value)      do{LCDCFG=(u8)(value);}while(0)
#define LCD_GET_REG_CFG             (LCDCFG)
#define LCD_SET_REG_CFG2(value)     do{LCDCFG2=(u8)(value);}while(0)
#define LCD_GET_REG_CFG2            (LCDCFG2)
#define LCD_SET_REG_DBLEN(value)    do{DBLEN=(u8)(value);}while(0)
#define LCD_GET_REG_DBLEN           (DBLEN)
#define LCD_SET_REG_COMLENL(value)  do{COMLENL=(u8)(value);}while(0)
#define LCD_GET_REG_COMLENL         (COMLENL)
#define LCD_SET_REG_COMLENM(value)  do{COMLENM=(u8)(value);}while(0)
#define LCD_GET_REG_COMLENM         (COMLENM)
#define LCD_SET_REG_COMLENH(value)  do{COMLENH=(u8)(value);}while(0)
#define LCD_GET_REG_COMLENH         (COMLENH)
#define LCD_SET_REG_BLINKRATE(value) do{BLINKRATE=(u8)(value);}while(0)
#define LCD_GET_REG_BLINKRATE       (BLINKRATE)
#define LCD_SET_REG_CR(value)       do{LCDCR=(u8)(value);}while(0)
#define LCD_GET_REG_CR              (LCDCR)

#define LCD_SET_REG_COMON(value)    do{COMON=(u8)(value);}while(0)
#define LCD_GET_REG_COMON           (COMON)

#define LCD_SET_REG_SEGON1(value)   do{SEGON1=(u8)(value);}while(0)
#define LCD_GET_REG_SEGON1          (SEGON1)
#define LCD_SET_REG_SEGON2(value)   do{SEGON2=(u8)(value);}while(0)
#define LCD_GET_REG_SEGON2          (SEGON2)
#define LCD_SET_REG_SEGON3(value)   do{SEGON3=(u8)(value);}while(0)
#define LCD_GET_REG_SEGON3          (SEGON3)
#define LCD_SET_REG_SEGON4(value)   do{SEGON4=(u8)(value);}while(0)
#define LCD_GET_REG_SEGON4          (SEGON4)
#define LCD_SET_REG_SEGON5(value)   do{SEGON5=(u8)(value);}while(0)
#define LCD_GET_REG_SEGON5          (SEGON5)

#define LCD_SET_REG_C0S0_7(value)   do{C0SEGV0=(u8)(value);}while(0)
#define LCD_GET_REG_C0S0_7          (C0SEGV0)
#define LCD_SET_REG_C0S8_15(value)  do{C0SEGV1=(u8)(value);}while(0)
#define LCD_GET_REG_C0S8_15         (C0SEGV1)
#define LCD_SET_REG_C0S16_23(value) do{C0SEGV2=(u8)(value);}while(0)
#define LCD_GET_REG_C0S16_23        (C0SEGV2)
#define LCD_SET_REG_C0S24_31(value) do{C0SEGV3=(u8)(value);}while(0)
#define LCD_GET_REG_C0S24_31        (C0SEGV3)
#define LCD_SET_REG_C0S32_39(value) do{C0SEGV4=(u8)(value);}while(0)
#define LCD_GET_REG_C0S32_39        (C0SEGV4)

#define LCD_SET_REG_C1S0_7(value)   do{C1SEGV0=(u8)(value);}while(0)
#define LCD_GET_REG_C1S0_7          (C1SEGV0)
#define LCD_SET_REG_C1S8_15(value)  do{C1SEGV1=(u8)(value);}while(0)
#define LCD_GET_REG_C1S8_15         (C1SEGV1)
#define LCD_SET_REG_C1S16_23(value) do{C1SEGV2=(u8)(value);}while(0)
#define LCD_GET_REG_C1S16_23        (C1SEGV2)
#define LCD_SET_REG_C1S24_31(value) do{C1SEGV3=(u8)(value);}while(0)
#define LCD_GET_REG_C1S24_31        (C1SEGV3)
#define LCD_SET_REG_C1S32_39(value) do{C1SEGV4=(u8)(value);}while(0)
#define LCD_GET_REG_C1S32_39        (C1SEGV4)

#define LCD_SET_REG_C2S0_7(value)   do{C2SEGV0=(u8)(value);}while(0)
#define LCD_GET_REG_C2S0_7          (C2SEGV0)
#define LCD_SET_REG_C2S8_15(value)  do{C2SEGV1=(u8)(value);}while(0)
#define LCD_GET_REG_C2S8_15         (C2SEGV1)
#define LCD_SET_REG_C2S16_23(value) do{C2SEGV2=(u8)(value);}while(0)
#define LCD_GET_REG_C2S16_23        (C2SEGV2)
#define LCD_SET_REG_C2S24_31(value) do{C2SEGV3=(u8)(value);}while(0)
#define LCD_GET_REG_C2S24_31        (C2SEGV3)
#define LCD_SET_REG_C2S32_39(value) do{C2SEGV4=(u8)(value);}while(0)
#define LCD_GET_REG_C2S32_39        (C2SEGV4)

#define LCD_SET_REG_C3S0_7(value)   do{C3SEGV0=(u8)(value);}while(0)
#define LCD_GET_REG_C3S0_7          (C3SEGV0)
#define LCD_SET_REG_C3S8_15(value)  do{C3SEGV1=(u8)(value);}while(0)
#define LCD_GET_REG_C3S8_15         (C3SEGV1)
#define LCD_SET_REG_C3S16_23(value) do{C3SEGV2=(u8)(value);}while(0)
#define LCD_GET_REG_C3S16_23        (C3SEGV2)
#define LCD_SET_REG_C3S24_31(value) do{C3SEGV3=(u8)(value);}while(0)
#define LCD_GET_REG_C3S24_31        (C3SEGV3)
#define LCD_SET_REG_C3S32_39(value) do{C3SEGV4=(u8)(value);}while(0)
#define LCD_GET_REG_C3S32_39        (C3SEGV4)
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。