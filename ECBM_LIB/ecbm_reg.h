#ifndef _ECBM_REG_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_REG_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 ����

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

����˵����
    ���������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ�������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽����
                            ***************************
                            * ��ϵ��ʽ ����Ⱥ778916610 *
                            * ��1Ⱥ���ˣ���Ⱥ927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>STC8ϵ���ͺ�ѡ��
//<i>�б��ṩ��оƬ���Ͷ����������ֲ��г��ֵģ����������۽������ã����м�������������Ⱥ��֪�ҡ�
//<i>ROM�������գ�����һ��ѡ����ѡ��
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
//<o>ROMѡ��
//<i>ѡ��Ƭ����flash������С����ҪӰ��ΨһID�Ķ�ȡ��
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
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-----------------------------------����������ӳ��---------------------------------*/
#define __IO     volatile  //��ֹ�Ż���������Ŀ�����ñ�����ÿ��ʹ�õ�ʱ�򶼵�ȥ�ڴ���ֵ��
typedef unsigned char u8;  //�޷��ŵ� 8λ��������C51������޷����ַ��ͱ�����
typedef unsigned int  u16; //�޷��ŵ�16λ��������C51������޷���  ���ͱ�����
typedef unsigned long u32; //�޷��ŵ�32λ��������C51������޷��ų����ͱ�����
typedef   signed char s8;  //�з��ŵ� 8λ��������C51������з����ַ��ͱ�����
typedef   signed int  s16; //�з��ŵ�16λ��������C51������з���  ���ͱ�����
typedef   signed long s32; //�з��ŵ�32λ��������C51������з��ų����ͱ�����
/*------------------------------------���ù����趨----------------------------------*/
#define REG_IN_MASK(reg,mask,value) do{reg=((reg&(~mask))|((u8)(value)&mask));}while(0)//���������ʽ����ָ���Ĵ�������һ��ֵ��
#define REG_SET_BIT(reg,bit_mask)   do{reg|= (bit_mask);}while(0)//��ָ���Ĵ�����ĳЩλΪ1��
#define REG_RESET_BIT(reg,bit_mask) do{reg&=~(bit_mask);}while(0)//��ָ���Ĵ�����ĳЩλΪ0��
#define read_idata_u8(x)    (*((u8  volatile idata *)x))//��idata����ȡһ��u8 ������
#define read_idata_u16(x)   (*((u16 volatile idata *)x))//��idata����ȡһ��u16������
#define read_idata_u32(x)   (*((u32 volatile idata *)x))//��idata����ȡһ��u32������
#define read_xdata_u8(x)    (*((u8  volatile xdata *)x))//��xdata����ȡһ��u8 ������
#define read_xdata_u16(x)   (*((u16 volatile xdata *)x))//��xdata����ȡһ��u16������
#define read_xdata_u32(x)   (*((u32 volatile xdata *)x))//��xdata����ȡһ��u32������
#define read_idata_s8(x)    (*((s8  volatile idata *)x))//��idata����ȡһ��s8 ������
#define read_idata_s16(x)   (*((s16 volatile idata *)x))//��idata����ȡһ��s16������
#define read_idata_s32(x)   (*((s32 volatile idata *)x))//��idata����ȡһ��s32������
#define read_xdata_s8(x)    (*((s8  volatile xdata *)x))//��xdata����ȡһ��s8 ������
#define read_xdata_s16(x)   (*((s16 volatile xdata *)x))//��xdata����ȡһ��s16������
#define read_xdata_s32(x)   (*((s32 volatile xdata *)x))//��xdata����ȡһ��s32������
/*##################################���������ַ����################################*/
#if     (ECBM_MCU_ROM_SIZE==8)
#   define MCUID    (  (u8  code *)(0x1FF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0x1FF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==12)
#   define MCUID    (  (u8  code *)(0x2FF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0x2FF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==16)
#   define MCUID    (  (u8  code *)(0x3FF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0x3FF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==17)
#   define MCUID    (  (u8  code *)(0x43F9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0x43F7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==28)
#   define  MCUID   (  (u8  code *)(0x6FF9))  //��Ƭ����ΨһID�롣
#   define  BGV     (*((u16 code *)(0x6FF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==32)
#   define MCUID    (  (u8  code *)(0x7FF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0x7FF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==60)
#   define MCUID    (  (u8  code *)(0xEFF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0xEFF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#elif   (ECBM_MCU_ROM_SIZE==64)
#   define MCUID    (  (u8  code *)(0xFDF9))  //��Ƭ����ΨһID�롣
#   define BGV      (*((u16 code *)(0xFDF7))) //Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#endif
#if 1//������SFR���Ĵ������塣ͨ������궨������۵���
/*------------------------------------80H~87H------------------------------------*/
sfr P0          =0x80;//P0�˿�
sfr SP          =0x81;//��ջָ��
sfr DPL         =0x82;//����ָ�루���ֽڣ�
sfr DPH         =0x83;//����ָ�루���ֽڣ�
sfr S4CON       =0x84;//����4���ƼĴ���
sfr S4BUF       =0x85;//����4���ݼĴ���

sfr PCON        =0x87;//��Դ���ƼĴ���
/*------------------------------------88H~8FH------------------------------------*/
sfr TCON        =0x88;//��ʱ�����ƼĴ���
sfr TMOD        =0x89;//��ʱ��0/1ģʽ�Ĵ���
sfr TL0         =0x8A;//��ʱ��0�����Ĵ�������8λ��
sfr TL1         =0x8B;//��ʱ��1�����Ĵ�������8λ��
sfr TH0         =0x8C;//��ʱ��0�����Ĵ�������8λ��
sfr TH1         =0x8D;//��ʱ��1�����Ĵ�������8λ��
sfr AUXR        =0x8E;//�����Ĵ���1
sfr INTCLKO     =0x8F;//�ⲿ�ж���ʱ��������ƼĴ���
/*------------------------------------90H~97H------------------------------------*/
sfr P1          =0x90;//P1�˿�
sfr P1M1        =0x91;//P1�����üĴ���1
sfr P1M0        =0x92;//P1�����üĴ���0
sfr P0M1        =0x93;//P0�����üĴ���1
sfr P0M0        =0x94;//P0�����üĴ���0
sfr P2M1        =0x95;//P2�����üĴ���1
sfr P2M0        =0x96;//P2�����üĴ���0

/*------------------------------------98H~9FH------------------------------------*/
sfr SCON        =0x98;//����1���ƼĴ���
sfr SBUF        =0x99;//����1���ݼĴ���
sfr S2CON       =0x9A;//����2���ƼĴ���
sfr S2BUF       =0x9B;//����2���ݼĴ���

sfr IRCBAND     =0x9D;//IRCƵ��ѡ��Ĵ���
sfr LIRTRIM     =0x9E;//�ڲ��߾���IRCƵ��΢���Ĵ���
sfr IRTRIM      =0x9F;//�ڲ��߾���IRCƵ�ʵ����Ĵ���
/*------------------------------------A0H~A7H------------------------------------*/
sfr P2          =0xA0;//P2�˿�
sfr BUS_SPEED   =0xA1;//�����ٶȿ��ƼĴ���
sfr P_SW1       =0xA2;//����˿��л��Ĵ���1





/*------------------------------------A8H~AFH------------------------------------*/
sfr IE          =0xA8;//�ж�����Ĵ���
sfr SADDR       =0xA9;//����1�ӻ���ַ�Ĵ���
sfr WKTCL       =0xAA;//���绽�Ѷ�ʱ������8λ��
sfr WKTCH       =0xAB;//���绽�Ѷ�ʱ������8λ��
sfr16   WKTC    =0xAA;//���绽�Ѷ�ʱ����16λ��
sfr S3CON       =0xAC;//����3���ƼĴ���
sfr S3BUF       =0xAD;//����3���ݼĴ���
sfr TA          =0xAE;//DPTRʱ����ƼĴ���
sfr IE2         =0xAF;//�ж�����Ĵ���2
/*------------------------------------B0H~B7H------------------------------------*/
sfr P3          =0xB0;//P3�˿�
sfr P3M1        =0xB1;//P3�����üĴ���1
sfr P3M0        =0xB2;//P3�����üĴ���0
sfr P4M1        =0xB3;//P4�����üĴ���1
sfr P4M0        =0xB4;//P4�����üĴ���0
sfr IP2         =0xB5;//�ж����ȼ����ƼĴ���2
sfr IP2H        =0xB6;//���ж����ȼ����ƼĴ���2
sfr IPH         =0xB7;//���ж����ȼ����ƼĴ���
/*------------------------------------B8H~BFH------------------------------------*/
sfr IP          =0xB8;//�ж����ȼ����ƼĴ���
sfr SADEN       =0xB9;//����1�ӻ���ַ���μĴ���
sfr P_SW2       =0xBA;//����˿��л��Ĵ���2
sfr VOCTRL      =0xBB;//��ѹ���ƼĴ���
sfr ADC_CONTR   =0xBC;//ADC���ƼĴ���
sfr ADC_RES     =0xBD;//ADCת������Ĵ������ߣ�
sfr ADC_RESL    =0xBE;//ADCת������Ĵ������ͣ�

/*------------------------------------C0H~C7H------------------------------------*/
sfr P4          =0xC0;//P4�˿�
sfr WDT_CONTR   =0xC1;//���Ź����ƼĴ���
sfr IAP_DATA    =0xC2;//IAP���ݼĴ���
sfr IAP_ADDRH   =0xC3;//IAP�ߵ�ַ�Ĵ���
sfr IAP_ADDRL   =0xC4;//IAP�͵�ַ�Ĵ���
sfr IAP_CMD     =0xC5;//IAP����Ĵ���
sfr IAP_TRIG    =0xC6;//IAP�����Ĵ���
sfr IAP_CONTR   =0xC7;//IAP���ƼĴ���
/*------------------------------------C8H~CFH------------------------------------*/
sfr P5          =0xC8;//P5�˿�
sfr P5M1        =0xC9;//P5�����üĴ���1
sfr P5M0        =0xCA;//P5�����üĴ���0
sfr P6M1        =0xCB;//P6�����üĴ���1
sfr P6M0        =0xCC;//P6�����üĴ���0
sfr SPSTAT      =0xCD;//SPI״̬�Ĵ���
sfr SPCTL       =0xCE;//SPI���ƼĴ���
sfr SPDAT       =0xCF;//SPI���ݼĴ���
/*------------------------------------D0H~D7H------------------------------------*/
sfr PSW         =0xD0;//����״̬�ּĴ���
sfr T4T3M       =0xD1;//��ʱ��4/3���ƼĴ���
sfr T4H         =0xD2;//��ʱ��4�����Ĵ�������8λ��
sfr T4L         =0xD3;//��ʱ��4�����Ĵ�������8λ��
sfr T3H         =0xD4;//��ʱ��3�����Ĵ�������8λ��
sfr T3L         =0xD5;//��ʱ��3�����Ĵ�������8λ��
sfr T2H         =0xD6;//��ʱ��2�����Ĵ�������8λ��
sfr T2L         =0xD7;//��ʱ��2�����Ĵ�������8λ��
/*------------------------------------D8H~DFH------------------------------------*/
sfr CCON        =0xD8;//PCA���ƼĴ���
sfr CMOD        =0xD9;//PCAģʽ�Ĵ���
sfr CCAPM0      =0xDA;//PCAģ��0ģʽ���ƼĴ���
sfr CCAPM1      =0xDB;//PCAģ��1ģʽ���ƼĴ���
#if (ECBM_MCU==0x4805C4)//STC8��U�İ汾�Ƚ�����
sfr USBCLK      =0xDC;//USBʱ�ӿ��ƼĴ���
#else
sfr CCAPM2      =0xDC;//PCAģ��2ģʽ���ƼĴ���
#endif
#if (ECBM_MCU==0x2815C4)//STC��D�İ汾�Ƚ�����
#define CCAPM3  read_xdata_u8(0xFD54)//PCAģ��3ģʽ���ƼĴ���
#else
sfr CCAPM3      =0xDD;//PCAģ��3ģʽ���ƼĴ���
#endif
sfr ADC_CFG     =0xDE;//ADC���üĴ���
sfr IP3         =0xDF;//�ж����ȼ����ƼĴ���3
/*------------------------------------E0H~E7H------------------------------------*/
sfr ACC         =0xE0;//�ۼ���
sfr P7M1        =0xE1;//P7�����üĴ���1
sfr P7M0        =0xE2;//P7�����üĴ���0
sfr DPS         =0xE3;//DPTRָ��ѡ����
sfr DPL1        =0xE4;//�ڶ�������ָ�루���ֽڣ�
sfr DPH1        =0xE5;//�ڶ�������ָ�루���ֽڣ�
sfr CMPCR1      =0xE6;//�Ƚ������ƼĴ���1
sfr CMPCR2      =0xE7;//�Ƚ������ƼĴ���2
/*------------------------------------E8H~EFH------------------------------------*/
sfr P6          =0xE8;//P6�˿�
sfr CL          =0xE9;//PCA��������8λ
sfr CCAP0L      =0xEA;//PCAģ��0��8λ
sfr CCAP1L      =0xEB;//PCAģ��1��8λ
#if (ECBM_MCU==0x4805C4)//STC8��U�İ汾�Ƚ�����
sfr USBDAT      =0xEC;//USB���ݼĴ���
#else
sfr CCAP2L      =0xEC;//PCAģ��2��8λ
#endif
#if (ECBM_MCU==0x2815C4)//STC��D�İ汾�Ƚ�����
#define CCAP3L  read_xdata_u8(0xFD55)//PCAģ��3��8λ
#else
sfr CCAP3L      =0xED;//PCAģ��3��8λ
#endif
sfr IP3H        =0xEE;//���ж����ȼ����ƼĴ���3
sfr AUXINTIF    =0xEF;//��չ�жϱ�־λ�Ĵ���
/*------------------------------------F0H~F7H------------------------------------*/
sfr B           =0xF0;//B�Ĵ���
#if (ECBM_MCU==0x3205A4)||(ECBM_MCU==0x2815C4)
sfr PWMSET      =0xF1;//��ǿ��PWMȫ�����üĴ���
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCFG      =0xF1;//��ǿ��PWM���üĴ���
#endif
sfr PCA_PWM0    =0xF2;//PCA0��PWMģʽ�Ĵ���
sfr PCA_PWM1    =0xF3;//PCA1��PWMģʽ�Ĵ���
#if (ECBM_MCU==0x4805C4)//STC8��U�İ汾�Ƚ�����
sfr USBCON      =0xF4;//USB���ƼĴ���
#else
sfr PCA_PWM2    =0xF4;//PCA2��PWMģʽ�Ĵ���
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PCA_PWM3    =0xF5;//PCA3��PWMģʽ�Ĵ���
#else
sfr IAP_TPS     =0xF5;//EEPROM�����ȴ�ʱ����ƼĴ���
#endif
#if (ECBM_MCU==0x2815C4)//STC��D�İ汾�Ƚ�����
#define PCA_PWM3    read_xdata_u8(0xFD57)//PCA3��PWMģʽ�Ĵ���
#endif
#if (ECBM_MCU==0x2815C4)//STC��D�İ汾�Ƚ�����
sfr PWMCFG      =0xF6;//��ǿ��PWM���üĴ���
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMIF       =0xF6;//��ǿ��PWM�жϱ�־�Ĵ���
sfr PWMFDCR     =0xF7;//�쳣��������
#endif
#if (ECBM_MCU==0x3205A2)||(ECBM_MCU==0x3205A4)
sfr PWMCFG01    =0xF6;//��ǿ��PWM���üĴ���
sfr PWMCFG23    =0xF7;//��ǿ��PWM���üĴ���
#endif
/*------------------------------------F8H~FFH------------------------------------*/
sfr P7          =0xF8;//P7�˿�
sfr CH          =0xF9;//PCA��������8λ
sfr CCAP0H      =0xFA;//PCAģ��0��8λ
sfr CCAP1H      =0xFB;//PCAģ��1��8λ
#if (ECBM_MCU==0x4805C4)//STC8��U�İ汾�Ƚ�����
sfr USBADR      =0xFC;//USB��ַ�Ĵ���
#else
sfr CCAP2H      =0xFC;//PCAģ��2��8λ
#endif
#if (ECBM_MCU==0x2815C4)//STC��D�İ汾�Ƚ�����
#define CCAP3H  read_xdata_u8(0xFD56)//PCAģ��3��8λ
#else
sfr CCAP3H      =0xFD;//PCAģ��3��8λ
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCR       =0xFE;//PWM���ƼĴ���
#endif
#if (ECBM_MCU==0x3205A4)
sfr PWMCFG45    =0xFE;//��ǿ��PWM���üĴ���
#endif
sfr RSTCFG      =0xFF;//��λ���üĴ���
/*-------------------------------------------------------------------------------*/
#endif
#if 1//������XDATA���Ĵ������塣ͨ������궨������۵���
/*----------------------------------FA00H~FA0FH----------------------------------*/
#define DMA_M2M_CFG                 read_xdata_u8(0xFA00)//MEM_MEM���üĴ���
#define DMA_M2M_CR                  read_xdata_u8(0xFA01)//MEM_MEM���ƼĴ���
#define DMA_M2M_STA                 read_xdata_u8(0xFA02)//MEM_MEM״̬�Ĵ���
#define DMA_M2M_AMT                 read_xdata_u8(0xFA03)//MEM_MEM�������ֽڼĴ���
#define DMA_M2M_DONE                read_xdata_u8(0xFA04)//MEM_MEM��������ֽڼĴ���
#define DMA_M2M_TXA                 read_xdata_u16(0xFA05)//MEM_MEM���͵�ַ�Ĵ�����16λ��
#define DMA_M2M_TXAH                read_xdata_u8(0xFA05)//MEM_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_M2M_TXAL                read_xdata_u8(0xFA06)//MEM_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_M2M_RXA                 read_xdata_u16(0xFA07)//MEM_MEM���յ�ַ�Ĵ�����16λ��
#define DMA_M2M_RXAH                read_xdata_u8(0xFA07)//MEM_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_M2M_RXAL                read_xdata_u8(0xFA08)//MEM_MEM���յ�ַ�Ĵ�������8λ��
/*----------------------------------FA10H~FA1FH----------------------------------*/
#define DMA_ADC_CFG                 read_xdata_u8(0xFA10)//ADC_MEM���üĴ���
#define DMA_ADC_CR                  read_xdata_u8(0xFA11)//ADC_MEM���ƼĴ���
#define DMA_ADC_STA                 read_xdata_u8(0xFA12)//ADC_MEM״̬�Ĵ���
#define DMA_ADC_RXA                 read_xdata_u16(0xFA17)//ADC_MEM���յ�ַ�Ĵ�����16λ��
#define DMA_ADC_RXAH                read_xdata_u8(0xFA17)//ADC_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_ADC_RXAL                read_xdata_u8(0xFA18)//ADC_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_ADC_CFG2                read_xdata_u8(0xFA19)//ADC_MEM���üĴ���2
#define DMA_ADC_CHSW0               read_xdata_u8(0xFA1A)//ADC_MEMͨ��ʹ�ܼĴ���0
#define DMA_ADC_CHSW1               read_xdata_u8(0xFA1B)//ADC_MEMͨ��ʹ�ܼĴ���1
/*----------------------------------FA20H~FA2FH----------------------------------*/
#define DMA_SPI_CFG                 read_xdata_u8(0xFA20)//SPI_MEM���üĴ���
#define DMA_SPI_CR                  read_xdata_u8(0xFA21)//SPI_MEM���ƼĴ���
#define DMA_SPI_STA                 read_xdata_u8(0xFA22)//SPI_MEM״̬�Ĵ���
#define DMA_SPI_AMT                 read_xdata_u8(0xFA23)//SPI_MEM�������ֽڼĴ���
#define DMA_SPI_DONE                read_xdata_u8(0xFA24)//SPI_MEM��������ֽڼĴ���
#define DMA_SPI_TXA                 read_xdata_u16(0xFA25)//SPI_MEM���͵�ַ�Ĵ�����16λ��
#define DMA_SPI_TXAH                read_xdata_u8(0xFA25)//SPI_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_SPI_TXAL                read_xdata_u8(0xFA26)//SPI_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_SPI_RXA                 read_xdata_u16(0xFA27)//SPI_MEM���յ�ַ�Ĵ�����16λ��
#define DMA_SPI_RXAH                read_xdata_u8(0xFA27)//SPI_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_SPI_RXAL                read_xdata_u8(0xFA28)//SPI_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_SPI_CFG2                read_xdata_u8(0xFA29)//SPI_MEM���üĴ���2
/*----------------------------------FA30H~FA3FH----------------------------------*/
#define DMA_UR1T_CFG                read_xdata_u8(0xFA30)//UART12MEM�������üĴ���
#define DMA_UR1T_CR                 read_xdata_u8(0xFA31)//UART12MEM���Ϳ��ƼĴ���
#define DMA_UR1T_STA                read_xdata_u8(0xFA32)//UART12MEM����״̬�Ĵ���
#define DMA_UR1T_AMT                read_xdata_u8(0xFA33)//UART12MEM�������ֽڼĴ���
#define DMA_UR1T_DONE               read_xdata_u8(0xFA34)//UART12MEM��������ֽڼĴ���
#define DMA_UR1T_TXA                read_xdata_u16(0xFA35)//UART12MEM���͵�ַ�Ĵ�����16λ��
#define DMA_UR1T_TXAH               read_xdata_u8(0xFA35)//UART12MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR1T_TXAL               read_xdata_u8(0xFA36)//UART12MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR1R_CFG                read_xdata_u8(0xFA38)//UART12MEM�������üĴ���
#define DMA_UR1R_CR                 read_xdata_u8(0xFA39)//UART12MEM���տ��ƼĴ���
#define DMA_UR1R_STA                read_xdata_u8(0xFA3A)//UART12MEM����״̬�Ĵ���
#define DMA_UR1R_AMT                read_xdata_u8(0xFA3B)//UART12MEM�������ֽڼĴ���
#define DMA_UR1R_DONE               read_xdata_u8(0xFA3C)//UART12MEM��������ֽڼĴ���
#define DMA_UR1R_RXA                read_xdata_u16(0xFA3D)//UART12MEM���շ��͵�ַ�Ĵ�����16λ��
#define DMA_UR1R_RXAH               read_xdata_u8(0xFA3D)//UART12MEM���յ�ַ�Ĵ�������8λ��
#define DMA_UR1R_RXAL               read_xdata_u8(0xFA3E)//UART12MEM���յ�ַ�Ĵ�������8λ��
/*----------------------------------FA40H~FA4FH----------------------------------*/
#define DMA_UR2T_CFG                read_xdata_u8(0xFA40)//UART22MEM�������üĴ���
#define DMA_UR2T_CR                 read_xdata_u8(0xFA41)//UART22MEM���Ϳ��ƼĴ���
#define DMA_UR2T_STA                read_xdata_u8(0xFA42)//UART22MEM����״̬�Ĵ���
#define DMA_UR2T_AMT                read_xdata_u8(0xFA43)//UART22MEM�������ֽڼĴ���
#define DMA_UR2T_DONE               read_xdata_u8(0xFA44)//UART22MEM��������ֽڼĴ���
#define DMA_UR2T_TXA                read_xdata_u16(0xFA45)//UART22MEM���͵�ַ�Ĵ�����16λ��
#define DMA_UR2T_TXAH               read_xdata_u8(0xFA45)//UART22MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR2T_TXAL               read_xdata_u8(0xFA46)//UART22MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR2R_CFG                read_xdata_u8(0xFA48)//UART22MEM�������üĴ���
#define DMA_UR2R_CR                 read_xdata_u8(0xFA49)//UART22MEM���տ��ƼĴ���
#define DMA_UR2R_STA                read_xdata_u8(0xFA4A)//UART22MEM����״̬�Ĵ���
#define DMA_UR2R_AMT                read_xdata_u8(0xFA4B)//UART22MEM�������ֽڼĴ���
#define DMA_UR2R_DONE               read_xdata_u8(0xFA4C)//UART22MEM��������ֽڼĴ���
#define DMA_UR2R_RXA                read_xdata_u16(0xFA4D)//UART22MEM���շ��͵�ַ�Ĵ�����16λ��
#define DMA_UR2R_RXAH               read_xdata_u8(0xFA4D)//UART22MEM���յ�ַ�Ĵ�������8λ��
#define DMA_UR2R_RXAL               read_xdata_u8(0xFA4E)//UART22MEM���յ�ַ�Ĵ�������8λ��
/*----------------------------------FA50H~FA5FH----------------------------------*/
#define DMA_UR3T_CFG                read_xdata_u8(0xFA50)//UART32MEM�������üĴ���
#define DMA_UR3T_CR                 read_xdata_u8(0xFA51)//UART32MEM���Ϳ��ƼĴ���
#define DMA_UR3T_STA                read_xdata_u8(0xFA52)//UART32MEM����״̬�Ĵ���
#define DMA_UR3T_AMT                read_xdata_u8(0xFA53)//UART32MEM�������ֽڼĴ���
#define DMA_UR3T_DONE               read_xdata_u8(0xFA54)//UART32MEM��������ֽڼĴ���
#define DMA_UR3T_TXA                read_xdata_u16(0xFA55)//UART32MEM���͵�ַ�Ĵ�����16λ��
#define DMA_UR3T_TXAH               read_xdata_u8(0xFA55)//UART32MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR3T_TXAL               read_xdata_u8(0xFA56)//UART32MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR3R_CFG                read_xdata_u8(0xFA58)//UART32MEM�������üĴ���
#define DMA_UR3R_CR                 read_xdata_u8(0xFA59)//UART32MEM���տ��ƼĴ���
#define DMA_UR3R_STA                read_xdata_u8(0xFA5A)//UART32MEM����״̬�Ĵ���
#define DMA_UR3R_AMT                read_xdata_u8(0xFA5B)//UART32MEM�������ֽڼĴ���
#define DMA_UR3R_DONE               read_xdata_u8(0xFA5C)//UART32MEM��������ֽڼĴ���
#define DMA_UR3R_RXA                read_xdata_u16(0xFA5D)//UART32MEM���շ��͵�ַ�Ĵ�����16λ��
#define DMA_UR3R_RXAH               read_xdata_u8(0xFA5D)//UART32MEM���յ�ַ�Ĵ�������8λ��
#define DMA_UR3R_RXAL               read_xdata_u8(0xFA5E)//UART32MEM���յ�ַ�Ĵ�������8λ��
/*----------------------------------FA60H~FA6FH----------------------------------*/
#define DMA_UR4T_CFG                read_xdata_u8(0xFA60)//UART42MEM�������üĴ���
#define DMA_UR4T_CR                 read_xdata_u8(0xFA61)//UART42MEM���Ϳ��ƼĴ���
#define DMA_UR4T_STA                read_xdata_u8(0xFA62)//UART42MEM����״̬�Ĵ���
#define DMA_UR4T_AMT                read_xdata_u8(0xFA63)//UART42MEM�������ֽڼĴ���
#define DMA_UR4T_DONE               read_xdata_u8(0xFA64)//UART42MEM��������ֽڼĴ���
#define DMA_UR4T_TXA                read_xdata_u16(0xFA65)//UART42MEM���͵�ַ�Ĵ�����16λ��
#define DMA_UR4T_TXAH               read_xdata_u8(0xFA65)//UART42MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR4T_TXAL               read_xdata_u8(0xFA66)//UART42MEM���͵�ַ�Ĵ�������8λ��
#define DMA_UR4R_CFG                read_xdata_u8(0xFA68)//UART42MEM�������üĴ���
#define DMA_UR4R_CR                 read_xdata_u8(0xFA69)//UART42MEM���տ��ƼĴ���
#define DMA_UR4R_STA                read_xdata_u8(0xFA6A)//UART42MEM����״̬�Ĵ���
#define DMA_UR4R_AMT                read_xdata_u8(0xFA6B)//UART42MEM�������ֽڼĴ���
#define DMA_UR4R_DONE               read_xdata_u8(0xFA6C)//UART42MEM��������ֽڼĴ���
#define DMA_UR4R_RXA                read_xdata_u16(0xFA6D)//UART42MEM���շ��͵�ַ�Ĵ�����16λ��
#define DMA_UR4R_RXAH               read_xdata_u8(0xFA6D)//UART42MEM���յ�ַ�Ĵ�������8λ��
#define DMA_UR4R_RXAL               read_xdata_u8(0xFA6E)//UART42MEM���յ�ַ�Ĵ�������8λ��
/*----------------------------------FA70H~FA7FH----------------------------------*/
#define DMA_LCM_CFG                 read_xdata_u8(0xFA70)//LCM_MEM���üĴ���
#define DMA_LCM_CR                  read_xdata_u8(0xFA71)//LCM_MEM���ƼĴ���
#define DMA_LCM_STA                 read_xdata_u8(0xFA72)//LCM_MEM״̬�Ĵ���
#define DMA_LCM_AMT                 read_xdata_u8(0xFA73)//LCM_MEM���ֽڼĴ���
#define DMA_LCM_DONE                read_xdata_u8(0xFA74)//LCM_MEM��������ֽڼĴ���
#define DMA_LCM_TXA                 read_xdata_u16(0xFA75)//LCM_MEM���͵�ַ�Ĵ�����16λ��
#define DMA_LCM_TXAH                read_xdata_u8(0xFA75)//LCM_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_LCM_TXAL                read_xdata_u8(0xFA76)//LCM_MEM���͵�ַ�Ĵ�������8λ��
#define DMA_LCM_RXA                 read_xdata_u16(0xFA77)//LCM_MEM���շ��͵�ַ�Ĵ�����16λ��
#define DMA_LCM_RXAH                read_xdata_u8(0xFA77)//LCM_MEM���յ�ַ�Ĵ�������8λ��
#define DMA_LCM_RXAL                read_xdata_u8(0xFA78)//LCM_MEM���յ�ַ�Ĵ�������8λ��
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
#define MD3MD2MD1MD0                read_xdata_u32(0xFCF0)//һ���������32λ��������32λ�̡�����
#define MD1MD0                      read_xdata_u16(0xFCF2)//һ���������16λ��������16λ�̡�16λ��������
#define MD5MD4                      read_xdata_u16(0xFCF4)//һ��������ų�����������������
#define ARCON                       read_xdata_u8(0xFCF6)//MDUģʽ���ƼĴ���
#define OPCON                       read_xdata_u8(0xFCF7)//MDU�������ƼĴ���
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
#define CKSEL                       read_xdata_u8(0xFE00)//ʱ��ѡ��Ĵ���
#define CLKDIV                      read_xdata_u8(0xFE01)//ʱ�ӷ�Ƶ�Ĵ���
#define HIRCCR                      read_xdata_u8(0xFE02)//�ڲ������������ƼĴ���
#define XOSCCR                      read_xdata_u8(0xFE03)//�ⲿ������ƼĴ���
#define IRC32KCR                    read_xdata_u8(0xFE04)//�ڲ�32K�������ƼĴ���
#define MCLKOCR                     read_xdata_u8(0xFE05)//��ʱ��������ƼĴ���
#define IRCDB                       read_xdata_u8(0xFE06)//�ڲ���������ȥ�����ƼĴ���
#define IRC48MCR                    read_xdata_u8(0xFE07)//�ڲ�48M�������ƼĴ���
/*----------------------------------FE08H~FE0FH----------------------------------*/
#define X32KCR                      read_xdata_u8(0xFE08)//�ⲿ32K�������ƼĴ���
#define SPFUNC                      read_xdata_u8(0xFE08)
#define RSTFLAG                     read_xdata_u8(0xFE09)
/*----------------------------------FE10H~FE17H----------------------------------*/
#define P0PU                        read_xdata_u8(0xFE10)//P0������������ƼĴ���
#define P1PU                        read_xdata_u8(0xFE11)//P1������������ƼĴ���
#define P2PU                        read_xdata_u8(0xFE12)//P2������������ƼĴ���
#define P3PU                        read_xdata_u8(0xFE13)//P3������������ƼĴ���
#define P4PU                        read_xdata_u8(0xFE14)//P4������������ƼĴ���
#define P5PU                        read_xdata_u8(0xFE15)//P5������������ƼĴ���
#define P6PU                        read_xdata_u8(0xFE16)//P6������������ƼĴ���
#define P7PU                        read_xdata_u8(0xFE17)//P7������������ƼĴ���
/*----------------------------------FE18H~FE1FH----------------------------------*/
#define P0NCS                       read_xdata_u8(0xFE18)//P0��ʩ���ش������ƼĴ���
#define P1NCS                       read_xdata_u8(0xFE19)//P1��ʩ���ش������ƼĴ���
#define P2NCS                       read_xdata_u8(0xFE1A)//P2��ʩ���ش������ƼĴ���
#define P3NCS                       read_xdata_u8(0xFE1B)//P3��ʩ���ش������ƼĴ���
#define P4NCS                       read_xdata_u8(0xFE1C)//P4��ʩ���ش������ƼĴ���
#define P5NCS                       read_xdata_u8(0xFE1D)//P5��ʩ���ش������ƼĴ���
#define P6NCS                       read_xdata_u8(0xFE1E)//P6��ʩ���ش������ƼĴ���
#define P7NCS                       read_xdata_u8(0xFE1F)//P7��ʩ���ش������ƼĴ���
/*----------------------------------FE20H~FE27H----------------------------------*/
#define P0SR                        read_xdata_u8(0xFE20)//P0�ڵ�ƽת���ٶȿ��ƼĴ���
#define P1SR                        read_xdata_u8(0xFE21)//P1�ڵ�ƽת���ٶȿ��ƼĴ���
#define P2SR                        read_xdata_u8(0xFE22)//P2�ڵ�ƽת���ٶȿ��ƼĴ���
#define P3SR                        read_xdata_u8(0xFE23)//P3�ڵ�ƽת���ٶȿ��ƼĴ���
#define P4SR                        read_xdata_u8(0xFE24)//P4�ڵ�ƽת���ٶȿ��ƼĴ���
#define P5SR                        read_xdata_u8(0xFE25)//P5�ڵ�ƽת���ٶȿ��ƼĴ���
#define P6SR                        read_xdata_u8(0xFE26)//P6�ڵ�ƽת���ٶȿ��ƼĴ���
#define P7SR                        read_xdata_u8(0xFE27)//P7�ڵ�ƽת���ٶȿ��ƼĴ���
/*----------------------------------FE28H~FE2FH----------------------------------*/
#define P0DR                        read_xdata_u8(0xFE28)//P0�������������ƼĴ���
#define P1DR                        read_xdata_u8(0xFE29)//P1�������������ƼĴ���
#define P2DR                        read_xdata_u8(0xFE2A)//P2�������������ƼĴ���
#define P3DR                        read_xdata_u8(0xFE2B)//P3�������������ƼĴ���
#define P4DR                        read_xdata_u8(0xFE2C)//P4�������������ƼĴ���
#define P5DR                        read_xdata_u8(0xFE2D)//P5�������������ƼĴ���
#define P6DR                        read_xdata_u8(0xFE2E)//P6�������������ƼĴ���
#define P7DR                        read_xdata_u8(0xFE2F)//P7�������������ƼĴ���
/*----------------------------------FE30H~FE37H----------------------------------*/
#define P0IE                        read_xdata_u8(0xFE30)//P0�������ź�����ʹ�ܿ��ƼĴ���
#define P1IE                        read_xdata_u8(0xFE31)//P1�������ź�����ʹ�ܿ��ƼĴ���
#define P2IE                        read_xdata_u8(0xFE32)//P2�������ź�����ʹ�ܿ��ƼĴ���
#define P3IE                        read_xdata_u8(0xFE33)//P3�������ź�����ʹ�ܿ��ƼĴ���
#define P4IE                        read_xdata_u8(0xFE34)//P4�������ź�����ʹ�ܿ��ƼĴ���
#define P5IE                        read_xdata_u8(0xFE35)//P5�������ź�����ʹ�ܿ��ƼĴ���
#define P6IE                        read_xdata_u8(0xFE36)//P6�������ź�����ʹ�ܿ��ƼĴ���
#define P7IE                        read_xdata_u8(0xFE37)//P7�������ź�����ʹ�ܿ��ƼĴ���
/*----------------------------------FE50H~FE57H----------------------------------*/
#define LCMIFCFG                    read_xdata_u8(0xFE50)//LCM�ӿ����üĴ���
#define LCMIFCFG2                   read_xdata_u8(0xFE51)//LCM�ӿ����üĴ���2
#define LCMIFCR                     read_xdata_u8(0xFE52)//LCM�ӿڿ��ƼĴ���
#define LCMIFSTA                    read_xdata_u8(0xFE53)//LCM�ӿ�״̬�Ĵ���
#define LCMIFDATL                   read_xdata_u8(0xFE54)//LCM�ӿڵ��ֽ�����
#define LCMIFDATH                   read_xdata_u8(0xFE55)//LCM�ӿڸ��ֽ�����

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
#define I2CCFG                      read_xdata_u8(0xFE80)//IIC���üĴ���
#define I2CMSCR                     read_xdata_u8(0xFE81)//IIC�������ƼĴ���
#define I2CMSST                     read_xdata_u8(0xFE82)//IIC����״̬�Ĵ���
#define I2CSLCR                     read_xdata_u8(0xFE83)//IIC�ӻ����ƼĴ���
#define I2CSLST                     read_xdata_u8(0xFE84)//IIC�ӻ�״̬�Ĵ���
#define I2CSLADR                    read_xdata_u8(0xFE85)//IIC�ӻ���ַ�Ĵ���
#define I2CTXD                      read_xdata_u8(0xFE86)//IIC�������ݼĴ���
#define I2CRXD                      read_xdata_u8(0xFE87)//IIC�������ݼĴ���
#define I2CMSAUX                    read_xdata_u8(0xFE88)//IIC�����������ƼĴ���
/*----------------------------------FEA0H~FEA7H----------------------------------*/
#define TM2PS                       read_xdata_u8(0xFEA2)
#define TM3PS                       read_xdata_u8(0xFEA3)
#define TM4PS                       read_xdata_u8(0xFEA4)
/*----------------------------------FEA8H~FEAFH----------------------------------*/
#define ADC_TIM                     read_xdata_u8(0xFEA8)//ADCʱ����ƼĴ���
#define T3T4PIN                     read_xdata_u8(0xFEAC)
#define ADCEXCFG                    read_xdata_u8(0xFEAD)//ADC��չ���üĴ���
#define CMPEXCFG                    read_xdata_u8(0xFEAE)//CMP��չ���üĴ���
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
#if     ((ECBM_MCU&0xF0F000)==0x200000)   //��STC8A8K64D4�����STC8A
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
//�����ǼĴ���λ����͹���ʵ��ָ�
/*-------------------------------���Ź����⹦�ܼĴ���-----------------------------*/
#define WDT_FLAG                    0x80//���Ź������־λ
#define EN_WDT                      0x20//���Ź�ʹ��λ
#define CLR_WDT                     0x10//���Ź���ʱ������
#define IDL_WDT                     0x08//���Ź��ڿ���ģʽ�µĿ���λ
//-------------����ָ��------------//
#define WDT_POWER_ON                REG_SET_BIT(WDT_CONTR,EN_WDT)   //�򿪿��Ź�
#define WDT_CLR                     REG_SET_BIT(WDT_CONTR,CLR_WDT)  //ι��
#define WDT_SET_IDLE_ENABLE         REG_SET_BIT(WDT_CONTR,IDL_WDT)  //���Ź��ڿ���ģʽ�¼�������
#define WDT_SET_IDLE_DISABLE        REG_RESET_BIT(WDT_CONTR,IDL_WDT)//���Ź��ڿ���ģʽ��ֹͣ����
#define WDT_SET_SCALE(value)        REG_IN_MASK(WDT_CONTR,0x07,value)//���ÿ��Ź���Ԥ��Ƶϵ��
#define WDT_GET_FLAG                (WDT_CONTR & WDT_FLAG)           //��ȡ���Ź������־λ
//-------------�Ĵ�����ȡ----------//
#define WDT_SET_REG_CONTR(value)    do{WDT_CONTR=(u8)(value);}while(0)//����WDT_CONTR�Ĵ���
#define WDT_GET_REG_CONTR           (WDT_CONTR)                      //��ȡWDT_CONTR�Ĵ�����ֵ
/*------------------------------------�ⲿ�ж�0----------------------------------*/
sbit    EX0                         =IE^0;  //�ⲿ�ж�0����λ
sbit    IT0                         =TCON^0;//�ⲿ�ж�0��������λ
sbit    IE0                         =TCON^1;//�ⲿ�ж�0�ж������־λ
sbit    PX0                         =IP^0;  //�ⲿ�ж�0�ж����ȼ�����λ���ͣ�
#define PX0H                        0x01    //�ⲿ�ж�0�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define EXTI0_ENABLE                do{EX0=1;}while(0)//���ⲿ�ж�0
#define EXTI0_DISABLE               do{EX0=0;}while(0)//�ر��ⲿ�ж�0
#define EXTI0_SET_MODE_UP_DOWN      do{IT0=0;}while(0)//�ⲿ�ж�0ͨ�������غ��½��ش���
#define EXTI0_SET_MODE_DOWN         do{IT0=1;}while(0)//�ⲿ�ж�0ͨ���½��ش���
#define EXTI0_SET_IT_FLAG           do{IE0=1;}while(0)//��λ�ⲿ�ж�0�ж������־λ
#define EXTI0_CLS_IT_FLAG           do{IE0=0;}while(0)//����ⲿ�ж�0�ж������־λ
#define EXTI0_GET_IT_FLAG           (IE0)             //��ȡ�ⲿ�ж�0�ж������־λ
#define EXTI0_SET_IO_HIGH           do{P32=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI0_GET_IO                (P32)             //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
#define EXTI0_SET_IT_PRIORITY_0     do{IPH&=~PX0H;PX0=0;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ0
#define EXTI0_SET_IT_PRIORITY_1     do{IPH&=~PX0H;PX0=1;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ1
#define EXTI0_SET_IT_PRIORITY_2     do{IPH|= PX0H;PX0=0;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ2
#define EXTI0_SET_IT_PRIORITY_3     do{IPH|= PX0H;PX0=1;}while(0)//�����ⲿ�ж�0�����ȼ�Ϊ3
//-------------���ܶ���------------//
#define EXTI0_IT_NUM                interrupt 0//�ⲿ�ж�0�жϺ�
/*------------------------------------�ⲿ�ж�1----------------------------------*/
sbit    EX1                         =IE^2;  //�ⲿ�ж�1����λ
sbit    IT1                         =TCON^2;//�ⲿ�ж�1��������λ
sbit    IE1                         =TCON^3;//�ⲿ�ж�1�ж������־λ
sbit    PX1                         =IP^2;  //�ⲿ�ж�1�ж����ȼ�����λ���ͣ�
#define PX1H                        0x04    //�ⲿ�ж�1�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define EXTI1_ENABLE                do{EX1=1;}while(0)//���ⲿ�ж�1
#define EXTI1_DISABLE               do{EX1=0;}while(0)//�ر��ⲿ�ж�1
#define EXTI1_SET_MODE_UP_DOWN      do{IT1=0;}while(0)//�ⲿ�ж�1ͨ�������غ��½��ش���
#define EXTI1_SET_MODE_DOWN         do{IT1=1;}while(0)//�ⲿ�ж�1ͨ���½��ش���
#define EXTI1_SET_IT_FLAG           do{IE1=1;}while(0)//��λ�ⲿ�ж�1�ж������־λ
#define EXTI1_CLS_IT_FLAG           do{IE1=0;}while(0)//����ⲿ�ж�1�ж������־λ
#define EXTI1_GET_IT_FLAG           (IE1)             //��ȡ�ⲿ�ж�1�ж������־λ
#define EXTI1_SET_IO_HIGH           do{P33=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI1_GET_IO                (P33)             //ͨ����IO�ĵ�ƽ��֪���������ش��������½��ش���
#define EXTI1_SET_IT_PRIORITY_0     do{IPH&=~PX1H;PX1=0;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ0
#define EXTI1_SET_IT_PRIORITY_1     do{IPH&=~PX1H;PX1=1;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ1
#define EXTI1_SET_IT_PRIORITY_2     do{IPH|= PX1H;PX1=0;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ2
#define EXTI1_SET_IT_PRIORITY_3     do{IPH|= PX1H;PX1=1;}while(0)//�����ⲿ�ж�1�����ȼ�Ϊ3
//-------------���ܶ���------------//
#define EXTI1_IT_NUM                interrupt 2//�ⲿ�ж�1�жϺ�
/*------------------------------------�ⲿ�ж�2----------------------------------*/
#define EX2                         0x10//�ⲿ�ж�2�ж�����λ
#define INT2IF                      0x10//�ⲿ�ж�2���ж������־λ
//-------------����ָ��------------//
#define EXTI2_ENABLE                REG_SET_BIT(INTCLKO,EX2)    //���ⲿ�ж�2
#define EXTI2_DISABLE               REG_RESET_BIT(INTCLKO,EX2)  //�ر��ⲿ�ж�2
#define EXTI2_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT2IF)//��λ�ⲿ�ж�2�ж������־λ
#define EXTI2_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT2IF)//����ⲿ�ж�2�ж������־λ
#define EXTI2_GET_IT_FLAG           (AUXINTIF & INT2IF)           //��ȡ�ⲿ�ж�2�ж������־λ
#define EXTI2_SET_IO_HIGH           do{P36=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI2_GET_IO                (P36) 
//-------------���ܶ���------------//
#define EXTI2_IT_NUM                interrupt 10//�ⲿ�ж�2�жϺ�
/*------------------------------------�ⲿ�ж�3----------------------------------*/
#define EX3                         0x20//�ⲿ�ж�3�ж�����λ
#define INT3IF                      0x20//�ⲿ�ж�3���жϱ�־λ
//-------------����ָ��------------//
#define EXTI3_ENABLE                REG_SET_BIT(INTCLKO,EX3)    //���ⲿ�ж�3
#define EXTI3_DISABLE               REG_RESET_BIT(INTCLKO,EX3)  //�ر��ⲿ�ж�3
#define EXTI3_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT3IF)//��λ�ⲿ�ж�3�ж������־λ
#define EXTI3_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT3IF)//����ⲿ�ж�3�ж������־λ
#define EXTI3_GET_IT_FLAG           (AUXINTIF & INT3IF)           //��ȡ�ⲿ�ж�3�ж������־λ
#define EXTI3_SET_IO_HIGH           do{P37=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI3_GET_IO                (P37) 
//-------------���ܶ���------------//
#define EXTI3_IT_NUM                interrupt 11//�ⲿ�ж�3�жϺ�
/*------------------------------------�ⲿ�ж�4----------------------------------*/
#define EX4                         0x40//�ⲿ�ж�4�ж�����λ
#define INT4IF                      0x40//�ⲿ�ж�4���жϱ�־λ
#define PX4                         0x10//�ⲿ�ж�4�ж����ȼ�����λ���ͣ�
#define PX4H                        0x10//�ⲿ�ж�4�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define EXTI4_ENABLE                REG_SET_BIT(INTCLKO,EX4)    //���ⲿ�ж�4
#define EXTI4_DISABLE               REG_RESET_BIT(INTCLKO,EX4)  //�ر��ⲿ�ж�4
#define EXTI4_SET_IT_FLAG           REG_SET_BIT(AUXINTIF,INT4IF)//��λ�ⲿ�ж�4�ж������־λ
#define EXTI4_CLS_IT_FLAG           REG_RESET_BIT(AUXINTIF,INT4IF)//����ⲿ�ж�4�ж������־λ
#define EXTI4_GET_IT_FLAG           (AUXINTIF & INT4IF)           //��ȡ�ⲿ�ж�4�ж������־λ
#define EXTI4_SET_IO_HIGH           do{P30=1;}while(0)//����IO��Ĭ�ϵ�ƽΪ�ߵ�ƽ
#define EXTI4_GET_IO                P30 
#define EXTI4_SET_IT_PRIORITY_0     do{IP2H&=~PX4H;IP2&=~PX4;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ0
#define EXTI4_SET_IT_PRIORITY_1     do{IP2H&=~PX4H;IP2|= PX4;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ1
#define EXTI4_SET_IT_PRIORITY_2     do{IP2H|= PX4H;IP2&=~PX4;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ2
#define EXTI4_SET_IT_PRIORITY_3     do{IP2H|= PX4H;IP2|= PX4;}while(0)//�����ⲿ�ж�4�����ȼ�Ϊ3
//-------------���ܶ���------------//
#define EXTI4_IT_NUM                interrupt 16//�ⲿ�ж�4�жϺ�
/*------------------------------IAP/ISP���⹦�ܼĴ���-----------------------------*/
#define IAP_IDL                     0x00//EEPROM����ָ��
#define IAP_READ                    0x01//EEPROM��ָ��
#define IAP_WRITE                   0x02//EEPROMдָ��
#define IAP_ERASE                   0x03//EEPROM���ָ��
#define IAP_EN                      0x80//EEPROM����ʹ�ܿ���λ
#define IAP_FAIL                    0x10//EEPROM����ʧ��״̬λ
//-------------����ָ��------------//
#define IAP_POWER_ON                REG_SET_BIT(IAP_CONTR,IAP_EN)  //��IAP����
#define IAP_POWER_OFF               REG_RESET_BIT(IAP_CONTR,IAP_EN)//�ر�IAP����
#define IAP_CMD_NOP                 do{IAP_CMD=IAP_IDL;   }while(0)//�ղ���
#define IAP_CMD_READ                do{IAP_CMD=IAP_READ;  }while(0)//��һ���ֽ�
#define IAP_CMD_WRITE               do{IAP_CMD=IAP_WRITE; }while(0)//дһ���ֽ�
#define IAP_CMD_ERASE               do{IAP_CMD=IAP_ERASE; }while(0)//����һ������
#define IAP_TRIG_ON                 do{IAP_TRIG=0x5A;IAP_TRIG=0xA5;}while(0)//����һ��EEPROM����
#define IAP_TRIG_CLS                do{IAP_TRIG=0;}while(0)//��մ����Ĵ���
#define IAP_GET_FAIL                (IAP_CONTR & IAP_FAIL)
//-------------�Ĵ�����ȡ----------//
#define IAP_SET_REG_DATA(value)     do{IAP_DATA=(u8)(value);}while(0)//дһ�����ݵ�IAP_DATA
#define IAP_GET_REG_DATA            (IAP_DATA)//��IAP_DATA��һ������
#define IAP_SET_REG_ADDR_HL(value)  do{IAP_ADDRL=(u8)(value);IAP_ADDRH=(u8)(value>>8);}while(0)//дһ����ַ��IAP_ADDRH��IAP_ADDRL��
#define IAP_GET_REG_ADDR_HL         ((((u16)IAP_ADDRH)<<8)|(u16)IAP_ADDRL)//��һ����ַIAP_ADDR
#define IAP_SET_REG_ADDR_H8(value)  do{IAP_ADDRH=(u8)(value);}while(0)//дһ����ַ��IAP_ADDRH��
#define IAP_GET_REG_ADDR_H8         (IAP_ADDRH)//��IAP_ADDRH
#define IAP_SET_REG_ADDR_L8(value)  do{IAP_ADDRL=(u8)(value);}while(0)//дһ����ַ��IAP_ADDRL��
#define IAP_GET_REG_ADDR_L8         (IAP_ADDRL)//��IAP_ADDRL
#define IAP_SET_REG_CONTR(value)    do{IAP_CONTR=(u8)(value);}while(0)//д��һ�����ݵ�IAP_CONTR�Ĵ���
#define IAP_GET_REG_CONTR           (IAP_CONTR)//��ȡIAP_CONTR�Ĵ���
#define IAP_SET_REG_TPS(value)      do{IAP_TPS=(u8)(value);}while(0)//дһ�����ݵ�IAP_TPS�Ĵ���
#define IAP_GET_REG_TPS             (IAP_TPS)//��IAP_TPS�Ĵ���
/*--------------------------------SPI���⹦�ܼĴ���-------------------------------*/
#define SPIF                        0x80//SPI�жϱ�־λ
#define WCOL                        0x40//SPIд��ͻ��־λ
#define SSIG                        0x80//SPI��SS���Ź��ܿ���λ
#define SPEN                        0x40//SPIʹ�ܿ���λ
#define DORD                        0x20//SPI����λ����/����˳��λ
#define MSTR                        0x10//SPI��/��ģʽѡ��λ
#define CPOL                        0x08//SPIʱ�Ӽ��Կ���
#define CPHA                        0x04//SPIʱ����λ����
#define ESPI                        0x02//SPI�ж�����λ
#define PSPIH                       0x02//SPI�ж����ȼ�����λ��
#define PSPI                        0x02//SPI�ж����ȼ�����λ��
//-------------����ָ��------------//
#define SPI_POWER_ON                REG_SET_BIT(SPCTL,SPEN)  //��SPI
#define SPI_POWER_OFF               REG_RESET_BIT(SPCTL,SPEN)//�ر�SPI
#define SPI_SET_CS_ENABLE           REG_RESET_BIT(SPCTL,SSIG)//��CS�ŵ�ʹ��
#define SPI_SET_CS_DISABLE          REG_SET_BIT(SPCTL,SSIG)  //�ر�CS�ŵ�ʹ��
#define SPI_SET_DATA_MSB            REG_RESET_BIT(SPCTL,DORD)//�����ȷ�/�����ݵĸ�λ
#define SPI_SET_DATA_LSB            REG_SET_BIT(SPCTL,DORD)  //�����ȷ�/�����ݵĵ�λ
#define SPI_SET_MODE_MASTER         REG_SET_BIT(SPCTL,MSTR)  //����SPIΪ����ģʽ
#define SPI_SET_MODE_SLAVE          REG_RESET_BIT(SPCTL,MSTR)//����SPIΪ�ӻ�ģʽ
#define SPI_SET_CPOL_1              REG_SET_BIT(SPCTL,CPOL)  //����CPOLλΪ1
#define SPI_SET_CPOL_0              REG_RESET_BIT(SPCTL,CPOL)//����CPOLλΪ0
#define SPI_SET_CPHA_1              REG_SET_BIT(SPCTL,CPHA)  //����CPHAλΪ1
#define SPI_SET_CPHA_0              REG_RESET_BIT(SPCTL,CPHA)//����CPHAλΪ0
#define SPI_SET_PIN(value)          REG_IN_MASK(P_SW1,0x0C,value)//���ô���1���������
#define SPI_CLS_IT_FLAG             REG_SET_BIT(SPSTAT,(SPIF|WCOL)) //��SPI�жϱ�־λ�ͳ�ͻ��־λ
#define SPI_GET_IT_FLAG             (SPSTAT & SPIF)                 //��ȡSPI�жϱ�־λ
#define SPI_CLS_WCOL_FLAG           REG_SET_BIT(SPSTAT,WCOL) //��SPIд��ͻ��־λ
#define SPI_GET_WCOL_FLAG           (SPSTAT & WCOL)          //��ȡSPIд��ͻ��־λ
#define SPI_IT_ENABLE               REG_SET_BIT(IE2,ESPI)    //��SPI�ж�
#define SPI_IT_DISABLE              REG_RESET_BIT(IE2,ESPI)  //��SPI�ж�
#define SPI_SET_SPR(value)          REG_IN_MASK(SPCTL,0x03,value)//����SPIʱ�ӷ�Ƶ
#define SPI_GET_SPR                 (SPCTL & 0x03)           //��ȡSPIʱ�ӷ�Ƶ
#define SPI_SET_IT_PRIORITY_0       do{IP2H&=~PSPIH;IP2&=~PSPI;}while(0)//����SPI���ж����ȼ�Ϊ0
#define SPI_SET_IT_PRIORITY_1       do{IP2H&=~PSPIH;IP2|= PSPI;}while(0)//����SPI���ж����ȼ�Ϊ1
#define SPI_SET_IT_PRIORITY_2       do{IP2H|= PSPIH;IP2&=~PSPI;}while(0)//����SPI���ж����ȼ�Ϊ2
#define SPI_SET_IT_PRIORITY_3       do{IP2H|= PSPIH;IP2|= PSPI;}while(0)//����SPI���ж����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define SPI_SET_REG_SPSTAT(value)   do{SPSTAT=(u8)(value);}while(0)//дһ�����ݵ�SPCTL�Ĵ���
#define SPI_GET_REG_SPSTAT          (SPSTAT)//��ȡSPCTL�Ĵ�����ֵ
#define SPI_SET_REG_SPCTL(value)    do{SPCTL=(u8)(value);}while(0)//дһ�����ݵ�SPCTL�Ĵ���
#define SPI_GET_REG_SPCTL           (SPCTL) //��ȡSPCTL�Ĵ�����ֵ
#define SPI_SET_REG_SPDAT(value)    do{SPDAT=(u8)(value);}while(0)//дһ�����ݵ�SPDAT�Ĵ���
#define SPI_GET_REG_SPDAT           (SPDAT) //��ȡSPDAT�Ĵ�����ֵ
//-------------���ܶ���------------//
#define SPI_IT_NUM                  interrupt 9//SPI���жϺ�
/*-------------------------------�Ƚ������⹦�ܼĴ���-----------------------------*/
#define CMPEN                       0x80//�Ƚ���ʹ��λ
#define CMPIF                       0x40//�Ƚ����жϱ�־λ
#define PIE                         0x20//�Ƚ����������ж�ʹ��λ
#define NIE                         0x10//�Ƚ����½����ж�ʹ��λ
#define PIS                         0x08//�Ƚ�������ѡ��λ
#define NIS                         0x04//�Ƚ�������ѡ��λ
#define CMPOE                       0x02//�Ƚ�������������λ
#define CMPRES                      0x01//�Ƚ������
#define INVCMPO                     0x80//�Ƚ�������������
#define DISFLT                      0x40//�Ƚ���ģ���˲����ܿ���
#define PCMP                        0x20//�Ƚ����ж����ȼ�����λ���ͣ�
#define PCMPH                       0x20//�Ƚ����ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define CMP_POWER_ON                do{CMPCR1|= CMPEN;}while(0)//�����Ƚ���
#define CMP_POWER_OFF               do{CMPCR1&=~CMPEN;}while(0)//�رձȽ���
#define CMP_IT_CLS                  do{CMPCR1&=~CMPIF;}while(0)//����Ƚ����жϱ�־λ
#define CMP_IT_POSITIVE_ENABLE      do{CMPCR1|= PIE;  }while(0)//�����������ж�
#define CMP_IT_POSITIVE_DISABLE     do{CMPCR1&=~PIE;  }while(0)//�ر��������ж�
#define CMP_IT_NEGATIVE_ENABLE      do{CMPCR1|= NIE;  }while(0)//�����������ж�
#define CMP_IT_NEGATIVE_DISABLE     do{CMPCR1&=~NIE;  }while(0)//�ر��������ж�
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_POSITIVE_ADC        REG_IN_MASK(CMPEXCFG,0x03,0x03)//�Ƚ�����+��ΪADC�����
#define CMP_SET_POSITIVE_P51        REG_IN_MASK(CMPEXCFG,0x03,0x02)//�Ƚ�����+��ΪP3.7��
#define CMP_SET_POSITIVE_A50        REG_IN_MASK(CMPEXCFG,0x03,0x01)//�Ƚ�����+��ΪADC�����
#define CMP_SET_POSITIVE_P37        REG_IN_MASK(CMPEXCFG,0x03,0x00)//�Ƚ�����+��ΪP3.7��
#else
#define CMP_SET_POSITIVE_ADC        do{CMPCR1|= PIS;  }while(0)//�Ƚ�����+��ΪADC�����
#define CMP_SET_POSITIVE_P37        do{CMPCR1&=~PIS;  }while(0)//�Ƚ�����+��ΪP3.7��
#endif
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_NEGATIVE_P36        do{CMPEXCFG&=~NIS;}while(0)//�Ƚ�����-��ΪP3.6��
#define CMP_SET_NEGATIVE_BGV        do{CMPEXCFG|= NIS;}while(0)//�Ƚ�����-��Ϊ�ڲ�1.9V��ѹ
#else
#define CMP_SET_NEGATIVE_P36        do{CMPCR1|= NIS;  }while(0)//�Ƚ�����-��ΪP3.6��
#define CMP_SET_NEGATIVE_BGV        do{CMPCR1&=~NIS;  }while(0)//�Ƚ�����-��Ϊ�ڲ�1.9V��ѹ
#endif
#define CMP_SET_OUT_ENABLE          do{CMPCR1|= CMPOE;}while(0)//�����Ƚ���������
#define CMP_SET_OUT_DISABLE         do{CMPCR1&=~CMPOE;}while(0)//�رձȽ���������
#define CMP_GET_RESULT              (CMPCR1 & CMPRES)//��ȡ�Ƚ������
#define CMP_SET_OUT_NEGATIVE        do{CMPCR2|= INVCMPO;}while(0)//�Ƚ�������������
#define CMP_SET_OUT_POSITIVE        do{CMPCR2&=~INVCMPO;}while(0)//�Ƚ�������������
#define CMP_SET_ANALOG_FILTER_ENABLE    do{CMPCR2&=~DISFLT;}while(0)//�����Ƚ���ģ���˲�
#define CMP_SET_ANALOG_FILTER_DISABLE   do{CMPCR2|= DISFLT;}while(0)//�رձȽ���ģ���˲�
#define CMP_SET_DIGITAL_FILTER(value)   REG_IN_MASK(CMPCR2,0x3F,value)//���ñȽ��������˲�
#define CMP_SET_OUT_PIN(value)      REG_IN_MASK(P_SW2,0x08,value)     //���ñȽ������������
#define CMP_SET_IT_PRIORITY_0       do{IP2H&=~PCMPH;IP2&=~PCMP;}while(0)//���ñȽ��������ȼ�Ϊ0
#define CMP_SET_IT_PRIORITY_1       do{IP2H&=~PCMPH;IP2|= PCMP;}while(0)//���ñȽ��������ȼ�Ϊ1
#define CMP_SET_IT_PRIORITY_2       do{IP2H|= PCMPH;IP2&=~PCMP;}while(0)//���ñȽ��������ȼ�Ϊ2
#define CMP_SET_IT_PRIORITY_3       do{IP2H|= PCMPH;IP2|= PCMP;}while(0)//���ñȽ��������ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define CMP_SET_REG_CMPCR1(value)   do{CMPCR1=(u8)(value);}while(0)//����CMPCR1�Ĵ���
#define CMP_GET_REG_CMPCR1          (CMPCR1)//��ȡCMPCR1�Ĵ���
#define CMP_SET_REG_CMPCR2(value)   do{CMPCR2=(u8)(value);}while(0)//����CMPCR2�Ĵ���
#define CMP_GET_REG_CMPCR2          (CMPCR2)//��ȡCMPCR1�Ĵ���
#define CMP_SET_REG_CMPEXCFG(value) do{CMPEXCFG=(u8)(value);}while(0)//����CMPEXCFG�Ĵ���
#define CMP_GET_REG_CMPEXCFG        (CMPEXCFG)//��ȡCMPEXCFG�Ĵ���
//-------------���ܶ���------------//
#define CMP_IT_NUM                  interrupt 21//�Ƚ����жϺ�
/*------------------------------ϵͳ�������⹦�ܼĴ���----------------------------*/
#define SWBS                        0x40//�����λѡ�����λ
#define SWRST                       0x20//�����λ����
#define PD                          0x02//����ģʽ����λ
#define IDL                         0x01//����ģʽ����λ
#define EAXFR                       0x80//XFR���ʿ���λ
//-------------����ָ��------------//
#define POWER_RESET                 do{IAP_CONTR=(SWRST|SWBS);}while(0)//�൱���ϵ�����(���ݻᶪʧ)
#define MCU_RESET                   do{IAP_CONTR=(SWRST);     }while(0)//�൱�ڰ�����λ(���ݲ��ᶪʧ)
#define POWER_DOWN                  REG_SET_BIT(PCON,PD)      //����ģʽ
#define POWER_IDLE                  REG_SET_BIT(PCON,IDL)     //����ģʽ
#define EX_SFR_ENABLE               REG_SET_BIT(P_SW2,EAXFR)  //�򿪶���ļĴ�����ַ��
#define EX_SFR_DISABLE              REG_RESET_BIT(P_SW2,EAXFR)//�رն���ļĴ�����ַ��
//-------------�Ĵ�����ȡ----------//
#define SYS_SET_REG_RSTCFG(value)   do{RSTCFG=(u8)(value);}while(0)//����RSTCFG�Ĵ���
#define SYS_GET_REG_RSTCFG          (RSTCFG)//��ȡRSTCFG�Ĵ���
/*-------------------------------���綨ʱ�����ܼĴ���-----------------------------*/
#define WKTEN                       0x80//���绽��ʹ��
//-------------����ָ��------------//
#define WKT_ON                      REG_SET_BIT(WKTCH,WKTEN)  //�򿪵��綨ʱ��
#define WKT_OFF                     REG_RESET_BIT(WKTCH,WKTEN)//�رյ��綨ʱ��
//-------------�Ĵ�����ȡ----------//
#define WKT_SET_REG_COUNT(value)    do{WKTC=(u16)(value);}while(0)//���õ��綨ʱ��
#define WKT_GET_REG_COUNT           (WKTC)//��ȡ���綨ʱ��
/*--------------------------------��ʱ��0���ܼĴ���-------------------------------*/
sbit    TF0                         =TCON^5;//��ʱ��0����жϱ�־λ
sbit    TR0                         =TCON^4;//��ʱ��0���п���λ
sbit    ET0                         =IE^1;  //��ʱ��0�ж�����λ
#define T0_GATE                     0x08    //��ʱ��0�ſ�λ
#define T0CLKO                      0x01    //��ʱ��0ʱ���������
#define T0_CT                       0x04    //��ʱ��0��������λ
#define T0_M1                       0x02    //��ʱ��0ģʽѡ��λ1
#define T0_M0                       0x01    //��ʱ��0ģʽѡ��λ0
#define T0x12                       0x80    //��ʱ��0�ٶȿ���λ 
sbit    PT0                         =IP^1;  //��ʱ��0�ж����ȼ�����λ���ͣ�
#define PT0H                        0x02    //��ʱ��0�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define TIMER0_POWER_ON             do{TF0=0;TR0=1;}while(0)//����ʱ��0
#define TIMER0_POWER_OFF            do{TR0=0;}while(0)      //�ض�ʱ��0
#define TIMER0_IT_ENABLE            do{ET0=1;}while(0)      //����ʱ��0�ж�ʹ��
#define TIMER0_IT_DISABLE           do{ET0=0;}while(0)      //�ض�ʱ��0�ж�ʹ��
#define TIMER0_GATE_ENABLE          REG_SET_BIT(TMOD,T0_GATE)  //����ʱ��0���ſ�λ
#define TIMER0_GATE_DISABLE         REG_RESET_BIT(TMOD,T0_GATE)//�ض�ʱ��0���ſ�λ
#define TIMER0_OUT_ON               REG_SET_BIT(INTCLKO,T0CLKO)  //����ʱ��0��ʱ�����
#define TIMER0_OUT_OFF              REG_RESET_BIT(INTCLKO,T0CLKO)//�ض�ʱ��0��ʱ�����
#define TIMER0_SET_MODE_COUNT       REG_SET_BIT(TMOD,T0_CT)  //�趨��ʱ��0Ϊ������
#define TIMER0_SET_MODE_TIMER       REG_RESET_BIT(TMOD,T0_CT)//�趨��ʱ��0Ϊ��ʱ��
#define TIMER0_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x03));}while(0)//��ʱ��0������16λģʽ
#define TIMER0_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x03))|T0_M0;}while(0)//��ʱ��0������16λģʽ
#define TIMER0_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x03))|T0_M1;}while(0)//��ʱ��0������8λ�Զ�����
#define TIMER0_SET_MODE_1T          REG_SET_BIT(AUXR,T0x12)  //�趨��ʱ��0Ϊ1Tģʽ
#define TIMER0_SET_MODE_12T         REG_RESET_BIT(AUXR,T0x12)//�趨��ʱ��0Ϊ12Tģʽ
#define TIMER0_GET_FLAG             (TF0)//��ȡ��ʱ��0�������־λ
#define TIMER0_CLS_FLAG             do{TF0=0;}while(0)//�嶨ʱ��0�������־λ
#define TIMER0_SET_IT_PRIORITY_0    do{IPH&=~PT0H;PT0=0;}while(0)//���ö�ʱ��0�����ȼ�Ϊ0
#define TIMER0_SET_IT_PRIORITY_1    do{IPH&=~PT0H;PT0=1;}while(0)//���ö�ʱ��0�����ȼ�Ϊ1
#define TIMER0_SET_IT_PRIORITY_2    do{IPH|= PT0H;PT0=0;}while(0)//���ö�ʱ��0�����ȼ�Ϊ2
#define TIMER0_SET_IT_PRIORITY_3    do{IPH|= PT0H;PT0=1;}while(0)//���ö�ʱ��0�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define TIMER0_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x80,value) //����AUXR�Ĵ����Ķ�ʱ��0����
#define TIMER0_GET_REG_AUXR         (AUXR & 0x80)                //��ȡAUXR�Ĵ����Ķ�ʱ��0����
#define TIMER0_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0x0F,value) //���ö�ʱ��0�Ĺ���ģʽ
#define TIMER0_GET_REG_TMOD         (TMOD & 0x0F)                //��ȡ��ʱ��0�Ĺ���ģʽ
#define TIMER0_SET_REG_HL(value)    do{TL0=(u8)(value);TH0=(u8)(value>>8);}while(0)//���ö�ʱ��0�ļ���ֵ
#define TIMER0_GET_REG_HL           ((((u16)TH0)<<8)|(u16)TL0)  //��ȡ��ʱ��0�ļ���ֵ
#define TIMER0_SET_REG_H8(value)    do{TH0=(u8)(value);}while(0)//���ö�ʱ��0�ļ���ֵ�ĸ�8λ
#define TIMER0_GET_REG_H8           (TH0)                       //��ȡ��ʱ��0�ļ���ֵ�ĸ�8λ
#define TIMER0_SET_REG_L8(value)    do{TL0=(u8)(value);}while(0)//���ö�ʱ��0�ļ���ֵ�ĵ�8λ
#define TIMER0_GET_REG_L8           (TL0)                       //��ȡ��ʱ��0�ļ���ֵ�ĵ�8λ
//-------------���ܶ���------------//
#define TIMER0_IT_NUM               interrupt 1//��ʱ��0���жϺ�
/*--------------------------------��ʱ��1���ܼĴ���-------------------------------*/
sbit    TF1                         =TCON^7;//��ʱ��1����жϱ�־λ
sbit    TR1                         =TCON^6;//��ʱ��1���п���λ
sbit    ET1                         =IE^3;  //��ʱ��1�ж�����λ
#define T1_GATE                     0x80    //��ʱ��1�ſ�λ
#define T1CLKO                      0x02    //��ʱ��1ʱ���������
#define T1_CT                       0x40    //��ʱ��1��������λ
#define T1_M1                       0x20    //��ʱ��1ģʽѡ��λ1
#define T1_M0                       0x10    //��ʱ��1ģʽѡ��λ0
#define T1x12                       0x40    //��ʱ��1�ٶȿ���λ
sbit    PT1                         =IP^3;  //��ʱ��1�ж����ȼ�����λ���ͣ�
#define PT1H                        0x08    //��ʱ��1�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define TIMER1_POWER_ON             do{TF1=0;TR1=1;}while(0)//����ʱ��1
#define TIMER1_POWER_OFF            do{TR1=0;}while(0)      //�ض�ʱ��1
#define TIMER1_IT_ENABLE            do{ET1=1;}while(0)      //����ʱ��1�ж�ʹ��
#define TIMER1_IT_DISABLE           do{ET1=0;}while(0)      //�ض�ʱ��1�ж�ʹ��
#define TIMER1_GATE_ENABLE          REG_SET_BIT(TMOD,T1_GATE)  //����ʱ��1���ſ�λ
#define TIMER1_GATE_DISABLE         REG_RESET_BIT(TMOD,T1_GATE)//�ض�ʱ��1���ſ�λ
#define TIMER1_OUT_ON               REG_SET_BIT(INTCLKO,T1CLKO)  //����ʱ��1��ʱ�����
#define TIMER1_OUT_OFF              REG_RESET_BIT(INTCLKO,T1CLKO)//�ض�ʱ��1��ʱ�����
#define TIMER1_SET_MODE_COUNT       REG_SET_BIT(TMOD,T1_CT)  //�趨��ʱ��1Ϊ������
#define TIMER1_SET_MODE_TIMER       REG_RESET_BIT(TMOD,T1_CT)//�趨��ʱ��1Ϊ��ʱ��
#define TIMER1_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x30));}while(0)//��ʱ��1������16λģʽ
#define TIMER1_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x30))|T1_M0;}while(0)//��ʱ��1������16λģʽ
#define TIMER1_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x30))|T1_M1;}while(0)//��ʱ��1������8λ�Զ�����
#define TIMER1_SET_MODE_1T          REG_SET_BIT(AUXR,T1x12)  //�趨��ʱ��1Ϊ1Tģʽ
#define TIMER1_SET_MODE_12T         REG_RESET_BIT(AUXR,T1x12)//�趨��ʱ��1Ϊ12Tģʽ
#define TIMER1_GET_FLAG             (TF1)//��ȡ��ʱ��1�������־λ
#define TIMER1_CLS_FLAG             do{TF1=0;}while(0)//�嶨ʱ��1�������־λ
#define TIMER1_SET_IT_PRIORITY_0    do{IPH&=~PT1H;PT1=0;}while(0)//���ö�ʱ��1�����ȼ�Ϊ0
#define TIMER1_SET_IT_PRIORITY_1    do{IPH&=~PT1H;PT1=1;}while(0)//���ö�ʱ��1�����ȼ�Ϊ1
#define TIMER1_SET_IT_PRIORITY_2    do{IPH|= PT1H;PT1=0;}while(0)//���ö�ʱ��1�����ȼ�Ϊ2
#define TIMER1_SET_IT_PRIORITY_3    do{IPH|= PT1H;PT1=1;}while(0)//���ö�ʱ��1�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define TIMER1_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x40,value)//����AUXR�Ĵ����Ķ�ʱ��1����
#define TIMER1_GET_REG_AUXR         (AUXR & 0x40)               //��ȡAUXR�Ĵ����Ķ�ʱ��1����
#define TIMER1_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0xF0,value)//���ö�ʱ��1�Ĺ���ģʽ
#define TIMER1_GET_REG_TMOD         (TMOD & 0xF0)               //��ȡ��ʱ��1�Ĺ���ģʽ
#define TIMER1_SET_REG_HL(value)    do{TL1=(u8)(value);TH1=(u8)(value>>8);}while(0)//���ö�ʱ��1�ļ���ֵ
#define TIMER1_GET_REG_HL           ((((u16)TH1)<<8)|(u16)TL1)  //��ȡ��ʱ��1�ļ���ֵ
#define TIMER1_SET_REG_H8(value)    do{TH1=(u8)(value);}while(0)//���ö�ʱ��1�ļ���ֵ�ĸ�8λ
#define TIMER1_GET_REG_H8           (TH1)                       //��ȡ��ʱ��1�ļ���ֵ�ĸ�8λ
#define TIMER1_SET_REG_L8(value)    do{TL1=(u8)(value);}while(0)//���ö�ʱ��1�ļ���ֵ�ĵ�8λ
#define TIMER1_GET_REG_L8           (TL1)                       //��ȡ��ʱ��1�ļ���ֵ�ĵ�8λ
//-------------���ܶ���------------//
#define TIMER1_IT_NUM               interrupt 3//��ʱ��1���жϺ�
/*--------------------------------��ʱ��2���ܼĴ���-------------------------------*/
#define T2R                         0x10//��ʱ��2���п���λ
#define ET2                         0x04//��ʱ��2�ж�����λ
#define T2CLKO                      0x04//��ʱ��2ʱ���������
#define T2_CT                       0x08//��ʱ��2��������λ
#define T2x12                       0x04//��ʱ��2�ٶȿ���λ
#define T2IF                        0x01//��ʱ��2�������־λ
//-------------����ָ��------------//
#define TIMER2_POWER_ON             REG_SET_BIT(AUXR,T2R)  //�򿪶�ʱ��2
#define TIMER2_POWER_OFF            REG_RESET_BIT(AUXR,T2R)//�رն�ʱ��2
#define TIMER2_IT_ENABLE            REG_SET_BIT(IE2,ET2)   //�򿪶�ʱ��2�ж�
#define TIMER2_IT_DISABLE           REG_RESET_BIT(IE2,ET2) //�رն�ʱ��2�ж�
#define TIMER2_OUT_ON               REG_SET_BIT(INTCLKO,T2CLKO)  //����ʱ��2��ʱ�����
#define TIMER2_OUT_OFF              REG_RESET_BIT(INTCLKO,T2CLKO)//�ض�ʱ��2��ʱ�����
#define TIMER2_SET_MODE_COUNT       REG_SET_BIT(AUXR,T2_CT)  //�趨��ʱ��2Ϊ������
#define TIMER2_SET_MODE_TIMER       REG_RESET_BIT(AUXR,T2_CT)//�趨��ʱ��2Ϊ��ʱ��
#define TIMER2_SET_MODE_1T          REG_SET_BIT(AUXR,T2x12)  //�趨��ʱ��2Ϊ1Tģʽ
#define TIMER2_SET_MODE_12T         REG_RESET_BIT(AUXR,T2x12)//�趨��ʱ��2Ϊ12Tģʽ
#define TIMER2_CLS_FLAG             REG_RESET_BIT(AUXINTIF,T2IF)//�嶨ʱ��2�����־
//-------------�Ĵ�����ȡ----------//
#define TIMER2_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x0C,value)//����AUXR�Ĵ����Ķ�ʱ��2����
#define TIMER2_GET_REG_AUXR         (AUXR&0x0C)//��ȡAUXR�Ĵ����Ķ�ʱ��2����
#define TIMER2_SET_REG_HL(value)    do{T2L=(u8)(value);T2H=(u8)(value>>8);}while(0)//���ö�ʱ��2�ļ���ֵ
#define TIMER2_GET_REG_HL           ((((u16)T2H)<<8)|(u16)T2L)//��ȡ��ʱ��2�ļ���ֵ
#define TIMER2_SET_REG_H8(value)    do{T2H=(u8)(value);}while(0)//���ö�ʱ��2�ļ���ֵ�ĸ�8λ
#define TIMER2_GET_REG_H8           (T2H)                       //��ȡ��ʱ��2�ļ���ֵ�ĸ�8λ
#define TIMER2_SET_REG_L8(value)    do{T2L=(u8)(value);}while(0)//���ö�ʱ��2�ļ���ֵ�ĵ�8λ
#define TIMER2_GET_REG_L8           (T2L)                       //��ȡ��ʱ��2�ļ���ֵ�ĵ�8λ
//-------------���ܶ���------------//
#define TIMER2_IT_NUM               interrupt 12//��ʱ��2���жϷ����
/*--------------------------------��ʱ��3���ܼĴ���-------------------------------*/
#define T3R                         0x08//��ʱ��3�������λ
#define ET3                         0x20//��ʱ��3�ж�����λ
#define T3CLKO                      0x01//��ʱ��3ʱ���������
#define T3_CT                       0x04//��ʱ��3��������λ
#define T3x12                       0x02//��ʱ��3�ٶȿ���λ
#define T3IF                        0x02//��ʱ��3���жϱ�־λ
//-------------����ָ��------------//
#define TIMER3_POWER_ON             REG_SET_BIT(T4T3M,T3R)      //�򿪶�ʱ��3
#define TIMER3_POWER_OFF            REG_RESET_BIT(T4T3M,T3R)    //�رն�ʱ��3
#define TIMER3_IT_ENABLE            REG_SET_BIT(IE2,ET3)        //�򿪶�ʱ��3�ж�
#define TIMER3_IT_DISABLE           REG_RESET_BIT(IE2,ET3)      //�رն�ʱ��3�ж�
#define TIMER3_OUT_ON               REG_SET_BIT(T4T3M,T3CLKO)   //����ʱ��3��ʱ�����
#define TIMER3_OUT_OFF              REG_RESET_BIT(T4T3M,T3CLKO) //�ض�ʱ��3��ʱ�����
#define TIMER3_SET_MODE_COUNT       REG_SET_BIT(T4T3M,T3_CT)    //�趨��ʱ��3Ϊ������
#define TIMER3_SET_MODE_TIMER       REG_RESET_BIT(T4T3M,T3_CT)  //�趨��ʱ��3Ϊ��ʱ��
#define TIMER3_SET_MODE_1T          REG_SET_BIT(T4T3M,T3x12)    //�趨��ʱ��3Ϊ1Tģʽ
#define TIMER3_SET_MODE_12T         REG_RESET_BIT(T4T3M,T3x12)  //�趨��ʱ��3Ϊ12Tģʽ
#define TIMER3_CLS_FLAG             REG_RESET_BIT(AUXINTIF,T3IF)//�嶨ʱ��3�жϱ�־
//-------------�Ĵ�����ȡ----------//
#define TIMER3_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0x0F,value)//����T4T3M�Ĵ����Ķ�ʱ��3����
#define TIMER3_GET_REG_T4T3M        (T4T3M & 0x0F)//��ȡT4T3M�Ĵ����Ķ�ʱ��3����
#define TIMER3_SET_REG_HL(value)    do{T3L=(u8)(value);T3H=(u8)(value>>8);}while(0)//���ö�ʱ��3�ļ���ֵ
#define TIMER3_GET_REG_HL           ((((u16)T3H)<<8)|(u16)T3L)  //��ȡ��ʱ��3�ļ���ֵ
#define TIMER3_SET_REG_H8(value)    do{T3H=(u8)(value);}while(0)//���ö�ʱ��3�ļ���ֵ�ĸ�8λ
#define TIMER3_GET_REG_H8           (T3H)                       //��ȡ��ʱ��3�ļ���ֵ�ĸ�8λ
#define TIMER3_SET_REG_L8(value)    do{T3L=(u8)(value);}while(0)//���ö�ʱ��3�ļ���ֵ�ĵ�8λ
#define TIMER3_GET_REG_L8           (T3L)
//-------------���ܶ���------------//
#define TIMER3_IT_NUM               interrupt 19//��ʱ��3���жϷ����
/*--------------------------------��ʱ��4���ܼĴ���-------------------------------*/
#define T4R                         0x80//��ʱ��4�������λ
#define ET4                         0x40//��ʱ��4�ж�����λ
#define T4CLKO                      0x10//��ʱ��4ʱ���������
#define T4_CT                       0x40//��ʱ��4��������λ
#define T4x12                       0x20//��ʱ��4�ٶȿ���λ
#define T4IF                        0x04//��ʱ��4���жϱ�־λ
//-------------����ָ��------------//
#define TIMER4_POWER_ON             REG_SET_BIT(T4T3M,T4R)      //�򿪶�ʱ��4
#define TIMER4_POWER_OFF            REG_RESET_BIT(T4T3M,T4R)    //�رն�ʱ��4
#define TIMER4_IT_ENABLE            REG_SET_BIT(IE2,ET4)        //�򿪶�ʱ��4�ж�
#define TIMER4_IT_DISABLE           REG_RESET_BIT(IE2,ET4)      //�رն�ʱ��4�ж�
#define TIMER4_OUT_ON               REG_SET_BIT(T4T3M,T4CLKO)   //����ʱ��4��ʱ�����
#define TIMER4_OUT_OFF              REG_RESET_BIT(T4T3M,T4CLKO) //�ض�ʱ��4��ʱ�����
#define TIMER4_SET_MODE_COUNT       REG_SET_BIT(T4T3M,T4_CT)    //�趨��ʱ��4Ϊ������
#define TIMER4_SET_MODE_TIMER       REG_RESET_BIT(T4T3M,T4_CT)  //�趨��ʱ��4Ϊ��ʱ��
#define TIMER4_SET_MODE_1T          REG_SET_BIT(T4T3M,T4x12)    //�趨��ʱ��4Ϊ1Tģʽ
#define TIMER4_SET_MODE_12T         REG_RESET_BIT(T4T3M,T4x12)  //�趨��ʱ��4Ϊ12Tģʽ
#define TIMER4_CLS_FLAG              REG_RESET_BIT(AUXINTIF,T4IF)//�嶨ʱ��4�жϱ�־
//-------------�Ĵ�����ȡ----------//
#define TIMER4_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0xF0,value)//����T4T3M�Ĵ����Ķ�ʱ��4����
#define TIMER4_GET_REG_T4T3M        (T4T3M & 0xF0)//��ȡT4T3M�Ĵ����Ķ�ʱ��4����
#define TIMER4_SET_REG_HL(value)    do{T4L=(u8)(value);T4H=(u8)(value>>8);}while(0)//���ö�ʱ��4�ļ���ֵ
#define TIMER4_GET_REG_HL           ((((u16)T4H)<<8)|(u16)T4L)  //��ȡ��ʱ��4�ļ���ֵ
#define TIMER4_SET_REG_H8(value)    do{T4H=(u8)(value);}while(0)//���ö�ʱ��4�ļ���ֵ�ĸ�8λ
#define TIMER4_GET_REG_H8           (T4H)                       //��ȡ��ʱ��4�ļ���ֵ�ĸ�8λ
#define TIMER4_SET_REG_L8(value)    do{T4L=(u8)(value);}while(0)//���ö�ʱ��4�ļ���ֵ�ĵ�8λ
#define TIMER4_GET_REG_L8           (T4L)
//-------------���ܶ���------------//
#define TIMER4_IT_NUM               interrupt 20//��ʱ��4���жϷ����
/*-------------------------------����1���⹦�ܼĴ���------------------------------*/
sbit    ES                          =IE^4;  //����1�ж�����λ
sbit    SM0                         =SCON^7;//����1����ģʽѡ��λ0
sbit    SM1                         =SCON^6;//����1����ģʽѡ��λ1
sbit    SM2                         =SCON^5;//����1���ͨ�ſ���λ
sbit    REN                         =SCON^4;//����1���տ���λ
sbit    TB8                         =SCON^3;//����1���͵ĵ�9λ
sbit    RB8                         =SCON^2;//����1���յĵ�9λ
sbit    TI                          =SCON^1;//����1�����ж������־λ
sbit    RI                          =SCON^0;//����1�����ж������־λ
#define SMOD                        0x80    //����1�����ʿ���λ
#define SMOD0                       0x40    //����1֡���������λ
#define UART_M0x6                   0x20    //����1ģʽ0��ͨѶ�ٶȿ���λ
#define S1ST2                       0x01    //����1�����ʷ�����ѡ��λ
sbit    PS                          =IP^4;  //����1�ж����ȼ�����λ���ͣ�
#define PSH                         0x10    //����1�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define UART1_IT_ENABLE             do{ES=1;}while(0)   //�򿪴���1�ж�
#define UART1_IT_DISABLE            do{ES=0;}while(0)   //�رմ���1�ж�
#define UART1_CLR_TI_FLAG           do{TI=0;}while(0)   //�������1�ķ��ͱ�־λ
#define UART1_GET_TI_FLAG           (TI)                //��ȡ����1�ķ��ͱ�־λ
#define UART1_CLR_RI_FLAG           do{RI=0;}while(0)   //�������1�Ľ��ܱ�־λ
#define UART1_GET_RI_FLAG           (RI)                //��ȡ����1�Ľ��ܱ�־λ
#define UART1_SET_TXD_BYTE9_0       do{TB8=0;TB8=0;}while(0)    //���ô���1���͵ĵ�9λΪ0
#define UART1_SET_TXD_BYTE9_1       do{TB8=1;TB8=1;}while(0)    //���ô���1���͵ĵ�9λΪ1
#define UART1_GET_RXD_BYTE9         (RB8)                       //��ȡ����1���յĵ�9λ 
#define UART1_SET_PIN(value)        REG_IN_MASK(P_SW1,0xC0,value)//���ô���1���������
#define UART1_SET_BAUD_1            REG_RESET_BIT(PCON,SMOD)//���ò����ʲ�����
#define UART1_SET_BAUD_2            REG_SET_BIT(PCON,SMOD)  //���ò����ʶ�����
#define UART1_SET_CLK_TIMER1        REG_RESET_BIT(AUXR,S1ST2)//���ô���1��ʱ���ɶ�ʱ��1����
#define UART1_SET_CLK_TIMER2        REG_SET_BIT(AUXR,S1ST2)  //���ô���1��ʱ���ɶ�ʱ��2����
#define UART1_SET_RXD_ENABLE        do{REN=1;}while(0)  //����1�Ľ��ܹ��ܿ���
#define UART1_SET_RXD_DISABLE       do{REN=0;}while(0)  //����1�Ľ��ܹ��ܹر�
#define UART1_SET_MUX_ENABLE        do{SM2=1;}while(0)  //����1�Ķ��ͨ�ſ���
#define UART1_SET_MUX_DISABLE       do{SM2=0;}while(0)  //����1�Ķ��ͨ�Źر�
#define UART1_SET_MODE_S_8          do{SCON=(SCON&(~0xC0))|0x00;}while(0)//����1�Ĺ���ģʽΪͬ��ģʽ
#define UART1_SET_MODE_A_8_BAUD     do{SCON=(SCON&(~0xC0))|0x40;}while(0)//����1�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART1_SET_MODE_A_9          do{SCON=(SCON&(~0xC0))|0x80;}while(0)//����1�Ĺ���ģʽΪ�첽9λģʽ
#define UART1_SET_MODE_A_9_BAUD     do{SCON=(SCON&(~0xC0))|0xC0;}while(0)//����1�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
#define UART1_SET_IT_PRIORITY_0     do{IPH&=~PSH;PS=0;}while(0)//���ô���1�����ȼ�Ϊ0
#define UART1_SET_IT_PRIORITY_1     do{IPH&=~PSH;PS=1;}while(0)//���ô���1�����ȼ�Ϊ1
#define UART1_SET_IT_PRIORITY_2     do{IPH|= PSH;PS=0;}while(0)//���ô���1�����ȼ�Ϊ2
#define UART1_SET_IT_PRIORITY_3     do{IPH|= PSH;PS=1;}while(0)//���ô���1�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define UART1_SET_REG_SADDR(value)  do{SADDR=(u8)(value);}while(0)//���ô���1�ĵ�ַ
#define UART1_GET_REG_SADDR         (SADDR)                       //��ȡ����1�ĵ�ַ
#define UART1_SET_REG_SADEN(value)  do{SADEN=(u8)(value);}while(0)//���ô���1�ĵ�ַ����
#define UART1_GET_REG_SADEN         (SADEN)                       //��ȡ����1�ĵ�ַ����
#define UART1_SET_REG_SBUF(value)   do{SBUF =(u8)(value);}while(0)//���ô���1Ҫ���͵�����
#define UART1_GET_REG_SBUF          (SBUF)                        //��ȡ����1���յ�������
#define UART1_SET_REG_SCON(value)   do{SCON =(u8)(value);}while(0)//����SCON�Ĵ���
#define UART1_GET_REG_SCON          (SCON)                        //��ȡSCON�Ĵ���
#define UART1_SET_REG_PCON(value)   REG_IN_MASK(PCON,0xC0,value)  //����PCON�Ĵ����Ĵ���1����
#define UART1_GET_REG_PCON          (PCON & 0xC0)                 //��ȡPCON�Ĵ����Ĵ���1����
#define UART1_SET_REG_AUXR(value)   REG_IN_MASK(AUXR,0x21,value)//����AUXR�Ĵ����Ĵ���1����
#define UART1_GET_REG_AUXR          (AUXR & 0x21)                 //��ȡAUXR�Ĵ����Ĵ���1����
//-------------���ܶ���------------//
#define UART1_IT_NUM                interrupt 4//����1�жϺ�
/*-------------------------------����2���⹦�ܼĴ���------------------------------*/
#define ES2                         0x01//����2�ж�����λ
#define S2SM0                       0x80//����2����ģʽѡ��λ
#define S2SM2                       0x20//����2���ͨ�ſ���λ
#define S2REN                       0x10//����2���տ���λ
#define S2TB8                       0x08//����2���͵ĵ�9λ
#define S2RB8                       0x04//����2���յĵ�9λ
#define S2TI                        0x02//����2�����ж������־λ
#define S2RI                        0x01//����2�����ж������־λ
#define PS2                         0x01//����2�ж����ȼ�����λ���ͣ�
#define PS2H                        0x01//����2�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define UART2_IT_ENABLE             REG_SET_BIT(IE2,ES2)//�򿪴���2�ж�
#define UART2_IT_DISABLE            REG_RESET_BIT(IE2,ES2)//�رմ���2�ж�
#define UART2_CLR_TI_FLAG           REG_RESET_BIT(S2CON,S2TI)//�������2�ķ��ͱ�־λ
#define UART2_GET_TI_FLAG           (S2CON & S2TI)           //��ȡ����2�ķ��ͱ�־λ
#define UART2_CLR_RI_FLAG           REG_RESET_BIT(S2CON,S2RI)//�������2�Ľ��ܱ�־λ
#define UART2_GET_RI_FLAG           (S2CON & S2RI)           //��ȡ����2�Ľ��ܱ�־λ
#define UART2_SET_TXD_BYTE9_0       do{S2CON&=~S2TB8;S2CON&=~S2TB8;}while(0)//���ô���2���͵ĵ�9λΪ0
#define UART2_SET_TXD_BYTE9_1       do{S2CON|= S2TB8;S2CON|= S2TB8;}while(0)//���ô���2���͵ĵ�9λΪ1
#define UART2_GET_RXD_BYTE9         (S2CON & S2RB8)                         //��ȡ����2���յĵ�9λ 
#define UART2_SET_PIN(value)        REG_IN_MASK(P_SW2,0x01,value)//���ô���2���������
#define UART2_SET_RXD_ENABLE        REG_SET_BIT(S2CON,S2REN)  //����2�Ľ��ܹ��ܿ���
#define UART2_SET_RXD_DISABLE       REG_RESET_BIT(S2CON,S2REN)//����2�Ľ��ܹ��ܹر�
#define UART2_SET_MUX_ENABLE        REG_SET_BIT(S2CON,S2SM2)  //����2�Ķ��ͨ�ſ���
#define UART2_SET_MUX_DISABLE       REG_RESET_BIT(S2CON,S2SM2)//����2�Ķ��ͨ�Źر�
#define UART2_SET_MODE_A_8_BAUD     REG_RESET_BIT(S2CON,S2SM0)//����2�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART2_SET_MODE_A_9_BAUD     REG_SET_BIT(S2CON,S2SM0)  //����2�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
#define UART2_SET_IT_PRIORITY_0     do{IP2H&=~PS2H;IP2&=~PS2;}while(0)//���ô���2�����ȼ�Ϊ0
#define UART2_SET_IT_PRIORITY_1     do{IP2H&=~PS2H;IP2|= PS2;}while(0)//���ô���2�����ȼ�Ϊ1
#define UART2_SET_IT_PRIORITY_2     do{IP2H|= PS2H;IP2&=~PS2;}while(0)//���ô���2�����ȼ�Ϊ2
#define UART2_SET_IT_PRIORITY_3     do{IP2H|= PS2H;IP2|= PS2;}while(0)//���ô���2�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define UART2_SET_REG_S2BUF(value)  do{S2BUF =(u8)(value);}while(0)//���ô���2Ҫ���͵�����
#define UART2_GET_REG_S2BUF         (S2BUF)                        //��ȡ����2���յ�������
#define UART2_SET_REG_S2CON(value)  do{S2CON =(u8)(value);}while(0)//����S2CON�Ĵ���
#define UART2_GET_REG_S2CON         (S2CON)                        //��ȡS2CON�Ĵ���
//-------------���ܶ���------------//
#define UART2_IT_NUM                interrupt 8//����2�жϺ�
/*-------------------------------����3���⹦�ܼĴ���------------------------------*/
#define ES3                         0x08//����3�ж�����λ
#define S3SM0                       0x80//����3����ģʽѡ��λ
#define S3ST3                       0x40//����3�����ʷ�����ѡ��λ
#define S3SM2                       0x20//����3���ͨ�ſ���λ
#define S3REN                       0x10//����3���տ���λ
#define S3TB8                       0x08//����3���͵ĵ�9λ
#define S3RB8                       0x04//����3���յĵ�9λ
#define S3TI                        0x02//����3�����ж������־λ
#define S3RI                        0x01//����3�����ж������־λ
#define PS3                         0x01//����3�ж����ȼ�����λ���ͣ�
#define PS3H                        0x01//����3�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define UART3_IT_ENABLE             REG_SET_BIT(IE2,ES3)    //�򿪴���3�ж�
#define UART3_IT_DISABLE            REG_RESET_BIT(IE2,ES3)  //�رմ���3�ж�
#define UART3_CLR_TI_FLAG           REG_RESET_BIT(S3CON,S3TI)//�������3�ķ��ͱ�־λ
#define UART3_GET_TI_FLAG           (S3CON & S3TI)           //��ȡ����3�ķ��ͱ�־λ
#define UART3_CLR_RI_FLAG           REG_RESET_BIT(S3CON,S3RI)//�������3�Ľ��ܱ�־λ
#define UART3_GET_RI_FLAG           (S3CON & S3RI)           //��ȡ����3�Ľ��ܱ�־λ
#define UART3_SET_TXD_BYTE9_0       do{S3CON&=~S3TB8;S3CON&=~S3TB8;}while(0)//���ô���3���͵ĵ�9λΪ0
#define UART3_SET_TXD_BYTE9_1       do{S3CON|= S3TB8;S3CON|= S3TB8;}while(0)//���ô���3���͵ĵ�9λΪ1
#define UART3_GET_RXD_BYTE9         (S3CON & S3RB8)//��ȡ����3���յĵ�9λ 
#define UART3_SET_PIN(value)        REG_IN_MASK(P_SW2,0x02,value)//���ô���3���������
#define UART3_SET_CLK_TIMER2        REG_RESET_BIT(S3CON,S3ST3)  //���ô���3��ʱ���ɶ�ʱ��2����
#define UART3_SET_CLK_TIMER3        REG_SET_BIT(S3CON,S3ST3)    //���ô���3��ʱ���ɶ�ʱ��3����
#define UART3_SET_RXD_ENABLE        REG_SET_BIT(S3CON,S3REN)    //����3�Ľ��ܹ��ܿ���
#define UART3_SET_RXD_DISABLE       REG_RESET_BIT(S3CON,S3REN)  //����3�Ľ��ܹ��ܹر�
#define UART3_SET_MUX_ENABLE        REG_SET_BIT(S3CON,S3SM2)    //����3�Ķ��ͨ�ſ���
#define UART3_SET_MUX_DISABLE       REG_RESET_BIT(S3CON,S3SM2)  //����3�Ķ��ͨ�Źر�
#define UART3_SET_MODE_A_8_BAUD     REG_RESET_BIT(S3CON,S3SM0)  //����3�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART3_SET_MODE_A_9_BAUD     REG_SET_BIT(S3CON,S3SM0)    //����3�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
#define UART3_SET_IT_PRIORITY_0     do{IP3H&=~PS3H;IP3&=~PS3;}while(0)//���ô���3�����ȼ�Ϊ0
#define UART3_SET_IT_PRIORITY_1     do{IP3H&=~PS3H;IP3|= PS3;}while(0)//���ô���3�����ȼ�Ϊ1
#define UART3_SET_IT_PRIORITY_2     do{IP3H|= PS3H;IP3&=~PS3;}while(0)//���ô���3�����ȼ�Ϊ2
#define UART3_SET_IT_PRIORITY_3     do{IP3H|= PS3H;IP3|= PS3;}while(0)//���ô���3�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define UART3_SET_REG_S3BUF(value)  do{S3BUF =((u8)(value));}while(0)//���ô���3Ҫ���͵�����
#define UART3_GET_REG_S3BUF         (S3BUF)                          //��ȡ����3���յ�������
#define UART3_SET_REG_S3CON(value)  do{S3CON =((u8)(value));}while(0)//����S3CON�Ĵ���
#define UART3_GET_REG_S3CON         (S3CON)                          //��ȡS3CON�Ĵ���
//-------------���ܶ���------------//
#define UART3_IT_NUM                interrupt 17//����3�жϺ�
/*-------------------------------����4���⹦�ܼĴ���------------------------------*/
#define ES4                         0x10//����4�ж�����λ
#define S4SM0                       0x80//����4����ģʽѡ��λ
#define S4ST4                       0x40//����4�����ʷ�����ѡ��λ
#define S4SM2                       0x20//����4���ͨ�ſ���λ
#define S4REN                       0x10//����4���տ���λ
#define S4TB8                       0x08//����4���͵ĵ�9λ
#define S4RB8                       0x04//����4���յĵ�9λ
#define S4TI                        0x02//����4�����ж������־λ
#define S4RI                        0x01//����4�����ж������־λ
#define PS4                         0x02//����4�ж����ȼ�����λ���ͣ�
#define PS4H                        0x02//����4�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define UART4_IT_ENABLE             REG_SET_BIT(IE2,ES4)  //�򿪴���4�ж�
#define UART4_IT_DISABLE            REG_RESET_BIT(IE2,ES4)//�رմ���4�ж�
#define UART4_CLR_TI_FLAG           REG_RESET_BIT(S4CON,S4TI)//�������4�ķ��ͱ�־λ
#define UART4_GET_TI_FLAG           (S4CON & S4TI)           //��ȡ����4�ķ��ͱ�־λ
#define UART4_CLR_RI_FLAG           REG_RESET_BIT(S4CON,S4RI)//�������4�Ľ��ܱ�־λ
#define UART4_GET_RI_FLAG           (S4CON & S4RI)           //��ȡ����4�Ľ��ܱ�־λ
#define UART4_SET_TXD_BYTE9_0       do{S4CON&=~S4TB8;S4CON&=~S4TB8;}while(0)//���ô���4���͵ĵ�9λΪ0
#define UART4_SET_TXD_BYTE9_1       do{S4CON|= S4TB8;S4CON|= S4TB8;}while(0)//���ô���4���͵ĵ�9λΪ1
#define UART4_GET_RXD_BYTE9         (S4CON & S4RB8)//��ȡ����4���յĵ�9λ 
#define UART4_SET_PIN(value)        REG_IN_MASK(P_SW2,0x04,value)//���ô���4���������
#define UART4_SET_CLK_TIMER2        REG_RESET_BIT(S4CON,S4ST4)//���ô���4��ʱ���ɶ�ʱ��2����
#define UART4_SET_CLK_TIMER4        REG_SET_BIT(S4CON,S4ST4)  //���ô���4��ʱ���ɶ�ʱ��4����
#define UART4_SET_RXD_ENABLE        REG_SET_BIT(S4CON,S4REN)  //����4�Ľ��ܹ��ܿ���
#define UART4_SET_RXD_DISABLE       REG_RESET_BIT(S4CON,S4REN)//����4�Ľ��ܹ��ܹر�
#define UART4_SET_MUX_ENABLE        REG_SET_BIT(S4CON,S4SM2)  //����4�Ķ��ͨ�ſ���
#define UART4_SET_MUX_DISABLE       REG_RESET_BIT(S4CON,S4SM2)//����4�Ķ��ͨ�Źر�
#define UART4_SET_MODE_A_8_BAUD     REG_RESET_BIT(S4CON,S4SM0)//����4�Ĺ���ģʽΪ�첽8λģʽ���ɱ䲨����
#define UART4_SET_MODE_A_9_BAUD     REG_SET_BIT(S4CON,S4SM0)  //����4�Ĺ���ģʽΪ�첽9λģʽ���ɱ䲨����
#define UART4_SET_IT_PRIORITY_0     do{IP3H&=~PS4H;IP3&=~PS4;}while(0)//���ô���4�����ȼ�Ϊ0
#define UART4_SET_IT_PRIORITY_1     do{IP3H&=~PS4H;IP3|= PS4;}while(0)//���ô���4�����ȼ�Ϊ1
#define UART4_SET_IT_PRIORITY_2     do{IP3H|= PS4H;IP3&=~PS4;}while(0)//���ô���4�����ȼ�Ϊ2
#define UART4_SET_IT_PRIORITY_3     do{IP3H|= PS4H;IP3|= PS4;}while(0)//���ô���4�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define UART4_SET_REG_S4BUF(value)  do{S4BUF =(u8)(value);}while(0)//���ô���4Ҫ���͵�����
#define UART4_GET_REG_S4BUF         (S4BUF)                        //��ȡ����4���յ�������
#define UART4_SET_REG_S4CON(value)  do{S4CON =(u8)(value);}while(0)//����S4CON�Ĵ���
#define UART4_GET_REG_S4CON         (S4CON)                        //��ȡS4CON�Ĵ���
//-------------���ܶ���------------//
#define UART4_IT_NUM                interrupt 18//����4�жϺ�
/*-------------------------------MDU16���⹦�ܼĴ���------------------------------*/
#define MDOV                        0x40//MDU�����־λ
#define MDRST                       0x02//MDU��λ����λ
#define ENOP                        0x01//MDUʹ����״̬λ
//-------------����ָ��------------//
#define MDU16_RESET                 do{OPCON=MDRST;}while(0)//��λ�˳���Ԫ
#define MDU16_START                 do{OPCON=ENOP; }while(0)//��ʼ����
#define MDU16_GET_END_FLAG          (OPCON & ENOP)          //��ȡ���������־λ
#define MDU16_GET_MDOV_FLAG         (OPCON & MDOV)          //��ȡ���������λ
#define MDU16_SET_16MUL             do{ARCON=0x80; }while(0)//16λ�˷�
#define MDU16_SET_16DIV             do{ARCON=0xa0; }while(0)//16λ����
#define MDU16_SET_32DIV             do{ARCON=0xc0; }while(0)//32λ����
//-------------�Ĵ�����ȡ----------//
#define MDU16_SET_REG_ARCON(value)  do{ARCON=(u8)(value);}while(0)//����ARCON�Ĵ���
#define MDU16_GET_REG_ARCON         (ARCON)//��ȡARCON�Ĵ���
#define MDU16_SET_REG_OPCON(value)  do{OPCON=(u8)(value);}while(0)//����OPCON�Ĵ���
#define MDU16_GET_REG_OPCON         (OPCON)//��ȡOPCON�Ĵ���
/*--------------------------------IIC���⹦�ܼĴ���-------------------------------*/
#define ENI2C                       0x80//IIC��Դʹ��λ
#define MSSL                        0x40//IIC���ӻ�ѡ��
#define EMSI                        0x80//IIC�����ж�ʹ��λ
#define MSBUSY                      0x80//IIC����ģʽʱ״̬λ
#define MSIF                        0x40//IIC����ģʽʱ���ж�����λ
#define MSACKI                      0x02//IIC����ģʽʱ���յ���ACK
#define MSACKO                      0x01//IIC����ģʽʱҪ���͵�ACK
#define WDTA                        0x01//IIC�Զ�����ack����λ
#define ESTAI                       0x40//IIC�ӻ�ģʽʱ����START�ź��ж�����λ
#define ERXI                        0x20//IIC�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define ETXI                        0x10//IIC�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define ESTOI                       0x08//IIC�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define SLRST                       0x01//IIC��λ�ӻ�ģʽ
#define SLBUSY                      0x80//IIC�ӻ�ģʽʱIIC������״̬λ
#define STAIF                       0x40//IIC�ӻ�ģʽʱ����START�ź��ж�����λ
#define RXIF                        0x20//IIC�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define TXIF                        0x10//IIC�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define STOIF                       0x08//IIC�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define SLACKI                      0x02//IIC�ӻ�ģʽʱ���յ���ACK
#define SLACKO                      0x01//IIC�ӻ�ģʽʱ��Ҫ���͵�ACK
#define PI2C                        0x40//IIC�ж����ȼ�����λ���ͣ�
#define PI2CH                       0x40//IIC�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define IIC_POWER_ON                REG_SET_BIT(I2CCFG,ENI2C)   //��IIC��Դ
#define IIC_POWER_OFF               REG_RESET_BIT(I2CCFG,ENI2C) //�ر�IIC��Դ
#define IIC_SET_MODE_MASTER         REG_SET_BIT(I2CCFG,MSSL)    //����IICΪ����ģʽ
#define IIC_SET_MODE_SLAVE          REG_RESET_BIT(I2CCFG,MSSL)  //����IICΪ�ӻ�ģʽ
#define IIC_SET_AUTOACK_ENABLE      REG_SET_BIT(I2CMSAUX,WDTA)  //�����Զ�����ACK
#define IIC_SET_AUTOACK_DISABLE     REG_RESET_BIT(I2CMSAUX,WDTA)//ȡ���Զ�����ACK
#define IIC_SET_SPEED(value)        REG_IN_MASK(I2CCFG,0x3F,value)//����IIC������ٶ�
#define IIC_GET_M_IT_FLAG           (I2CMSST & MSIF)             //��ȡIIC����ģʽ�жϱ�־λ
#define IIC_CLS_M_IT_FLAG           REG_RESET_BIT(I2CMSST,MSIF)  //���IIC����ģʽ�жϱ�־λ
#define IIC_GET_S_STA_FLAG          (I2CSLST & STAIF)           //��ȡIIC�ӻ�ģʽ��ʼ֡�жϱ�־λ��
#define IIC_CLS_S_STA_FLAG          REG_RESET_BIT(I2CSLST,STAIF)//���IIC�ӻ�ģʽ��ʼ֡�жϱ�־λ��
#define IIC_GET_S_STO_FLAG          (I2CSLST & STOIF)           //��ȡIIC�ӻ�ģʽ����֡�жϱ�־λ��
#define IIC_CLS_S_STO_FLAG          REG_RESET_BIT(I2CSLST,STOIF)//���IIC�ӻ�ģʽ����֡�жϱ�־λ��
#define IIC_GET_S_RX_FLAG           (I2CSLST & RXIF)            //��ȡIIC�ӻ�ģʽ����֡�жϱ�־λ��
#define IIC_CLS_S_RX_FLAG           REG_RESET_BIT(I2CSLST,RXIF) //���IIC�ӻ�ģʽ����֡�жϱ�־λ��
#define IIC_GET_ACK                 (I2CMSST & MSACKI)           //��ȡ�յ���ACK�ź�
#define IIC_SET_PIN(value)          REG_IN_MASK(P_SW2,0x30,value)//����IIC���������
#define IIC_SET_IT_PRIORITY_0       do{IP2H&=~PI2CH;IP2&=~PI2C;}while(0)//����IIC�����ȼ�Ϊ0
#define IIC_SET_IT_PRIORITY_1       do{IP2H&=~PI2CH;IP2|= PI2C;}while(0)//����IIC�����ȼ�Ϊ1
#define IIC_SET_IT_PRIORITY_2       do{IP2H|= PI2CH;IP2&=~PI2C;}while(0)//����IIC�����ȼ�Ϊ2
#define IIC_SET_IT_PRIORITY_3       do{IP2H|= PI2CH;IP2|= PI2C;}while(0)//����IIC�����ȼ�Ϊ3
#define IIC_CMD_START               do{I2CMSCR=(EMSI|0x01);}while(0)//����һ��START�ź�
#define IIC_CMD_TX_DATA             do{I2CMSCR=(EMSI|0x02);}while(0)//����һ���ֽ�����
#define IIC_CMD_RX_ACK              do{I2CMSCR=(EMSI|0x03);}while(0)//����һ��ACK�ź�
#define IIC_CMD_RX_DATA             do{I2CMSCR=(EMSI|0x04);}while(0)//����һ���ֽ�����
#define IIC_CMD_TX_ACK              do{I2CMSST=0x00;I2CMSCR=(EMSI|0x05);}while(0)//����һ��ACK�ź�
#define IIC_CMD_TX_NACK             do{I2CMSST=0x01;I2CMSCR=(EMSI|0x05);}while(0)//����һ��nACK�ź�
#define IIC_CMD_STOP                do{I2CMSCR=(EMSI|0x06);}while(0)//����һ��STOP�ź�
#define IIC_CMD_START_TXDATA_RXACK  do{I2CMSCR=(EMSI|0x09);}while(0)//��������������START�źź�8λ���ݣ��ٽ���һ��ACK��
#define IIC_CMD_TXDATA_RXACK        do{I2CMSCR=(EMSI|0x0A);}while(0)//��������������8λ���ݣ�Ȼ�����һ��ACK��
#define IIC_CMD_RXDATA_ACK          do{I2CMSCR=(EMSI|0x0B);}while(0)//��������������8λ���ݣ�Ȼ����һ��ACK��
#define IIC_CMD_RXDATA_NACK         do{I2CMSCR=(EMSI|0x0C);}while(0)//��������������8λ���ݣ�Ȼ����һ��NACK��
//-------------�Ĵ�����ȡ----------//
#define IIC_SET_REG_CFG(value)      do{I2CCFG=(u8)(value);}while(0)//����I2CCFG�Ĵ���
#define IIC_GET_REG_CFG             (I2CCFG)//��ȡI2CCFG�Ĵ���
#define IIC_SET_REG_MSCR(value)     do{I2CMSCR=(u8)(value);}while(0)//����I2CMSCR�Ĵ���
#define IIC_GET_REG_MSCR            (I2CMSCR)//��ȡI2CMSCR�Ĵ���
#define IIC_SET_REG_MSST(value)     do{I2CMSST=(u8)(value);}while(0)//����I2CMSST�Ĵ���
#define IIC_GET_REG_MSST            (I2CMSST)//��ȡI2CMSST�Ĵ���
#define IIC_SET_REG_MSAUX(value)    do{I2CMSAUX=(u8)(value);}while(0)//����I2CMSAUX�Ĵ���
#define IIC_GET_REG_MSAUX           (I2CMSAUX)//��ȡI2CMSAUX�Ĵ���
#define IIC_SET_REG_DATA(value)     do{I2CTXD=(u8)(value);}while(0)//���÷������ݼĴ���
#define IIC_GET_REG_DATA            (I2CRXD)  //��ȡ�������ݼĴ���

#define IIC_SET_REG_SLCR(value)     do{I2CSLCR=(u8)(value);}while(0)//����I2CSLCR�Ĵ���
#define IIC_GET_REG_SLCR            (I2CSLCR)//��ȡI2CSLCR�Ĵ���
#define IIC_SET_REG_SLST(value)     do{I2CSLST=(u8)(value);}while(0)//����I2CSLST�Ĵ���
#define IIC_GET_REG_SLST            (I2CSLST)//��ȡI2CSLST�Ĵ���
#define IIC_SET_REG_SLADR(value)    do{I2CSLADR=(u8)(value);}while(0)//����I2CSLADR�Ĵ���
#define IIC_GET_REG_SLADR           (I2CSLADR)//��ȡI2CSLADR�Ĵ���
//-------------���ܶ���------------//
#define IIC_IT_NUM                  interrupt 24//IIC�жϺ�
/*--------------------------------ADC���⹦�ܼĴ���------------------------------*/
sbit    EADC                        =IE^5;//ADCת���ж�����λ
#define ADC_POWER                   0x80  //ADC��Դ����λ
#define ADC_START                   0x40  //ADCת����������λ
#define ADC_FLAG                    0x20  //ADCת��������־λ
#define ADC_EPWMT                   0x10  //ADC��PWMЭͬ���Ʊ�־λ
#define ADC_RESFMT                  0x20  //ADCת�������ʽ����λ
sbit    PADC                        =IP^5;//ADC�ж����ȼ�����λ���ͣ�
#define PADCH                       0x20  //ADC�ж����ȼ�����λ���ߣ�
//-------------����ָ��------------//
#define ADC_POWER_ON                REG_SET_BIT(ADC_CONTR,ADC_POWER)  //��ADC�ĵ�Դ
#define ADC_POWER_OFF               REG_RESET_BIT(ADC_CONTR,ADC_POWER)//�ر�ADC�ĵ�Դ
#define ADC_IT_ENABLE               do{EADC=1;}while(0)               //��ADC�ж�
#define ADC_IT_DISABLE              do{EADC=0;}while(0)               //�ر�ADC�ж�
#define ADC_PWM_ENABLE              REG_SET_BIT(ADC_CONTR,ADC_EPWMT)  //��ADC��PWM����
#define ADC_PWM_DISABLE             REG_RESET_BIT(ADC_CONTR,ADC_EPWMT)//�ر�ADC��PWM����
#define ADC_GET_IT_FLAG             (ADC_CONTR & ADC_FLAG)            //��ȡADת��������־λ
#define ADC_CLS_IT_FLAG             REG_RESET_BIT(ADC_CONTR,(ADC_START|ADC_FLAG)) //���ADת��������־λ
#define ADC_MEASURE_ON              REG_SET_BIT(ADC_CONTR,ADC_START)  //��ʼADת��
#define ADC_SET_CHANNELS(value)     REG_IN_MASK(ADC_CONTR,0x0F,value)//����ADC��ת��ͨ��
#define ADC_SET_ALIGN_LEFT          REG_RESET_BIT(ADC_CFG,ADC_RESFMT)//����ADC�Ľ�����������
#define ADC_SET_ALIGN_RIGHT         REG_SET_BIT(ADC_CFG,ADC_RESFMT)//����ADC�Ľ���Ҷ�������
#define ADC_SET_SPEED(value)        REG_IN_MASK(ADC_CFG,0x0F,value)//����ADC��ת���ٶ�
#define ADC_SET_IT_PRIORITY_0       do{IPH&=~PADCH;PADC=0;}while(0)//����ADC�����ȼ�Ϊ0
#define ADC_SET_IT_PRIORITY_1       do{IPH&=~PADCH;PADC=1;}while(0)//����ADC�����ȼ�Ϊ1
#define ADC_SET_IT_PRIORITY_2       do{IPH|= PADCH;PADC=0;}while(0)//����ADC�����ȼ�Ϊ2
#define ADC_SET_IT_PRIORITY_3       do{IPH|= PADCH;PADC=1;}while(0)//����ADC�����ȼ�Ϊ3
//-------------�Ĵ�����ȡ----------//
#define ADC_SET_REG_CONTR(value)    do{ADC_CONTR=(u8)(value);}while(0)//����ADC_CONTR�Ĵ���
#define ADC_GET_REG_CONTR           (ADC_CONTR)                       //��ȡADC_CONTR�Ĵ�����ֵ
#define ADC_SET_REG_CFG(value)      do{ADC_CFG=(u8)(value);}while(0)  //����ADC_CFG�Ĵ���
#define ADC_GET_REG_CFG             (ADC_CFG)                         //��ȡADC_CFG�Ĵ�����ֵ
#define ADC_SET_REG_EXCFG(value)    do{ADCEXCFG=(u8)(value);}while(0) //����ADC_EXCFG�Ĵ���
#define ADC_GET_REG_EXCFG           (ADCEXCFG)                        //��ȡADC_EXCFG�Ĵ�����ֵ
#define ADC_SET_REG_TIM(value)      do{ADC_TIM=(u8)(value);}while(0)  //����ADC_TIM�Ĵ���
#define ADC_GET_REG_TIM             (ADC_TIM)                         //��ȡADC_TIM�Ĵ�����ֵ
#define ADC_GET_REG_RES_HL          ((((u16)ADC_RES)<<8)|(u16)ADC_RESL)//��ȡADC����Ĵ�����ȫ��
#define ADC_GET_REG_RES_H8          (ADC_RES )  //��ȡADC����Ĵ����ĸ�8λ
#define ADC_GET_REG_RES_L8          (ADC_RESL)  //��ȡADC����Ĵ����ĵ�8λ
//-------------���ܶ���------------//
#define ADC_IT_NUM                  interrupt 5//ADC���жϺ�
/*-------------------------------I/O�����⹦�ܼĴ���-----------------------------*/
sbit    P00                         =P0^0;  //P0.0��
sbit    P01                         =P0^1;  //P0.1��
sbit    P02                         =P0^2;  //P0.2��
sbit    P03                         =P0^3;  //P0.3��
sbit    P04                         =P0^4;  //P0.4��
sbit    P05                         =P0^5;  //P0.5��
sbit    P06                         =P0^6;  //P0.6��
sbit    P07                         =P0^7;  //P0.7��
sbit    P10                         =P1^0;  //P1.0��
sbit    P11                         =P1^1;  //P1.1��
sbit    P12                         =P1^2;  //P1.2��
sbit    P13                         =P1^3;  //P1.3��
sbit    P14                         =P1^4;  //P1.4��
sbit    P15                         =P1^5;  //P1.5��
sbit    P16                         =P1^6;  //P1.6��
sbit    P17                         =P1^7;  //P1.7��
sbit    P20                         =P2^0;  //P2.0��
sbit    P21                         =P2^1;  //P2.1��
sbit    P22                         =P2^2;  //P2.2��
sbit    P23                         =P2^3;  //P2.3��
sbit    P24                         =P2^4;  //P2.4��
sbit    P25                         =P2^5;  //P2.5��
sbit    P26                         =P2^6;  //P2.6��
sbit    P27                         =P2^7;  //P2.7��
sbit    P30                         =P3^0;  //P3.0��
sbit    P31                         =P3^1;  //P3.1��
sbit    P32                         =P3^2;  //P3.2��
sbit    P33                         =P3^3;  //P3.3��
sbit    P34                         =P3^4;  //P3.4��
sbit    P35                         =P3^5;  //P3.5��
sbit    P36                         =P3^6;  //P3.6��
sbit    P37                         =P3^7;  //P3.7��
sbit    P40                         =P4^0;  //P4.0��
sbit    P41                         =P4^1;  //P4.1��
sbit    P42                         =P4^2;  //P4.2��
sbit    P43                         =P4^3;  //P4.3��
sbit    P44                         =P4^4;  //P4.4��
sbit    P45                         =P4^5;  //P4.5��
sbit    P46                         =P4^6;  //P4.6��
sbit    P47                         =P4^7;  //P4.7��
sbit    P50                         =P5^0;  //P5.0��
sbit    P51                         =P5^1;  //P5.1��
sbit    P52                         =P5^2;  //P5.2��
sbit    P53                         =P5^3;  //P5.3��
sbit    P54                         =P5^4;  //P5.4��
sbit    P55                         =P5^5;  //P5.5��
sbit    P56                         =P5^6;  //P5.6��
sbit    P57                         =P5^7;  //P5.7��
sbit    P60                         =P6^0;  //P6.0��
sbit    P61                         =P6^1;  //P6.1��
sbit    P62                         =P6^2;  //P6.2��
sbit    P63                         =P6^3;  //P6.3��
sbit    P64                         =P6^4;  //P6.4��
sbit    P65                         =P6^5;  //P6.5��
sbit    P66                         =P6^6;  //P6.6��
sbit    P67                         =P6^7;  //P6.7��
sbit    P70                         =P7^0;  //P7.0��
sbit    P71                         =P7^1;  //P7.1��
sbit    P72                         =P7^2;  //P7.2��
sbit    P73                         =P7^3;  //P7.3��
sbit    P74                         =P7^4;  //P7.4��
sbit    P75                         =P7^5;  //P7.5��
sbit    P76                         =P7^6;  //P7.6��
sbit    P77                         =P7^7;  //P7.7��
/*--------------------------------�ں����⹦�ܼĴ���------------------------------*/
sbit    CY                          =PSW^7; //��λ��־λ
sbit    AC                          =PSW^6; //������λ��־λ
sbit    F0                          =PSW^5; //�����û��ı�־λ
sbit    RS1                         =PSW^4; //�����Ĵ���ѡ��λ����λ��
sbit    RS0                         =PSW^3; //�����Ĵ���ѡ��λ����λ��
sbit    OV                          =PSW^2; //�����־λ
sbit    P                           =PSW^0; //��żУ��λ
#define IF_ODD(_OE_)                ACC=_OE_;if(P)//�ж��ǲ�������
/*------------------------------ʱ�ӹ������⹦�ܼĴ���----------------------------*/
//-------------����ָ��------------//
#define CLK_SET_SOURCE_HSI          do{CKSEL=((CKSEL&(~0x03))|0x00);}while(0)//����ʱ��ԴΪ�ڲ�����IRC
#define CLK_SET_SOURCE_HSE          do{CKSEL=((CKSEL&(~0x03))|0x01);}while(0)//����ʱ��ԴΪ�ⲿ���پ���
#define CLK_SET_SOURCE_LSE          do{CKSEL=((CKSEL&(~0x03))|0x02);}while(0)//����ʱ��ԴΪ�ⲿ���پ���
#define CLK_SET_SOURCE_LSI          do{CKSEL=((CKSEL&(~0x03))|0x03);}while(0)//����ʱ��ԴΪ�ڲ�����IRC
#define CLK_HSI_POWER_ON            do{HIRCCR=((HIRCCR&(~0x81))|0x80);}while(!(HIRCCR&0x01))//����HSI��Դ
#define CLK_HSI_POWER_OFF           do{HIRCCR=0x00;}while(0)//�ر�HSI��Դ
#define CLK_HSE_A_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0x80);}while(!(XOSCCR&0x01))//����HSE��Դ�������ó���Դ����
#define CLK_HSE_P_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0xC0);}while(!(XOSCCR&0x01))//����HSE��Դ�������ó���Դ����
#define CLK_HSE_POWER_OFF           do{XOSCCR=0x00;}while(0)//�ر�HSE��Դ
#define CLK_HSE_GAIN_ENABLE         do{XOSCCR|= 0x20;}while(0)//���ⲿ���پ�������
#define CLK_HSE_GAIN_DISABLE        do{XOSCCR&=~0x20;}while(0)//�ر��ⲿ���پ�������
#define CLK_LSE_POWER_ON            do{X32KCR=((X32KCR&(~0x81))|0x80);}while(!(X32KCR&0x01))//����LSE��Դ
#define CLK_LSE_POWER_OFF           do{X32KCR  = 0x00;}while(0)//�ر�LSE��Դ
#define CLK_LSE_GAIN_ENABLE         do{X32KCR |= 0x40;}while(0)//���ⲿ���پ�������
#define CLK_LSE_GAIN_DISABLE        do{X32KCR &=~0x40;}while(0)//�ر��ⲿ���پ�������
#define CLK_LSI_POWER_ON            do{IRC32KCR=((IRC32KCR&(~0x81))|0x80);}while(!(IRC32KCR&0x01))//����LSI��Դ
#define CLK_LSI_POWER_OFF           do{IRC32KCR= 0x00;}while(0)//�ر�LSI��Դ
#define CLK_SET_OUT_TO_P54_FA       do{CKSEL  &=~0x08;}while(0)//����ʱ�������ΪP5.4(������STC8F��STC8A)
#define CLK_SET_OUT_TO_P16_FA       do{CKSEL  |= 0x08;}while(0)//����ʱ�������ΪP1.6(������STC8F��STC8A)
#define CLK_OUT_SET_DIV_FA(value)   REG_IN_MASK(CKSEL,0xF0,value)//����ʱ�������Ƶ(������STC8F��STC8A)
#define CLK_SET_OUT_TO_P54_GH       do{MCLKOCR&=~0x80;}while(0)//����ʱ�������ΪP5.4(������STC8G��STC8H)
#define CLK_SET_OUT_TO_P16_GH       do{MCLKOCR|= 0x80;}while(0)//����ʱ�������ΪP1.6(������STC8G��STC8H)
#define CLK_OUT_SET_DIV_GH(value)   REG_IN_MASK(MCLKOCR,0x7F,value)//����ʱ�������Ƶ(������STC8G��STC8H)
//-------------�Ĵ�����ȡ----------//
#define CLK_SET_REG_CLKDIV(value)   do{CLKDIV=(u8)value;}while(0)//����CLKDIV�Ĵ���
#define CLK_GET_REG_CLKDIV          (CLKDIV)//��ȡCLKDIV�Ĵ���
/*--------------------------------�ж����⹦�ܼĴ���-----------------------------*/
sbit    EA                          =IE^7;//���ж��������λ
sbit    ELVD                        =IE^6;//��ѹ����ж�����λ
#define LVDF                        0x20  //��ѹ����ж������־
#define PLVDH                       0x40  //��ѹ����ж����ȼ�����λ��
sbit    PLVD                        =IP^6;//��ѹ����ж����ȼ�����λ��
//-------------����ָ��------------//
#define EA_ENABLE                   do{EA=1;}while(0)//�����жϿ���
#define EA_DISABLE                  do{EA=0;}while(0)//�ر����жϿ���
#define LVD_IT_ENABLE               do{ELVD=1;}while(0)//�򿪵�ѹ�жϿ���
#define LVD_IT_DISABLE              do{ELVD=0;}while(0)//�رյ�ѹ�жϿ���
#define LVD_GET_IT_FLAG             (PCON & LVDF)
#define LVD_CLS_IT_FLAG             REG_RESET_BIT(PCON,LVDF)
#define LVD_SET_IT_PRIORITY_0       do{IPH&=~PLVDH;PLVD=0;}while(0)//����LVD�жϵ����ȼ�Ϊ0
#define LVD_SET_IT_PRIORITY_1       do{IPH&=~PLVDH;PLVD=1;}while(0)//����LVD�жϵ����ȼ�Ϊ1
#define LVD_SET_IT_PRIORITY_2       do{IPH|= PLVDH;PLVD=0;}while(0)//����LVD�жϵ����ȼ�Ϊ2
#define LVD_SET_IT_PRIORITY_3       do{IPH|= PLVDH;PLVD=1;}while(0)//����LVD�жϵ����ȼ�Ϊ3
/*--------------------------------LCM���⹦�ܼĴ���------------------------------*/
#define LCMIFIE                     0x80//LCM�ӿ��ж�ʹ�ܿ���λ
#define D16_D8                      0x02//LCM�ӿ����ݿ�ȿ���λ
#define M68_I80                     0x01//LCM�ӿ�ģʽѡ��λ
#define ELCMIF                      0x80//LCM�ӿ�ʹ�ܿ���λ
#define LCMIFIF                     0x01//LCM�ӿ��ж������־λ
//-------------����ָ��------------//
#define LCM_IT_ENABLE               do{LCMIFCFG|= LCMIFIE;}while(0)//��LCM�ӿ��ж�
#define LCM_IT_DISABLE              do{LCMIFCFG&=~LCMIFIE;}while(0)//�ر�LCM�ӿ��ж�
#define LCM_SET_IT_PRIORITY_0       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x00;}while(0)//����LCM�жϵ����ȼ�Ϊ0
#define LCM_SET_IT_PRIORITY_1       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x10;}while(0)//����LCM�жϵ����ȼ�Ϊ1
#define LCM_SET_IT_PRIORITY_2       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x20;}while(0)//����LCM�жϵ����ȼ�Ϊ2
#define LCM_SET_IT_PRIORITY_3       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x30;}while(0)//����LCM�жϵ����ȼ�Ϊ3
#define LCM_SET_DATABUS_NA_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x00;}while(0)//����LCM��������ΪP2
#define LCM_SET_DATABUS_NA_P6       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x04;}while(0)//����LCM��������ΪP6
#define LCM_SET_DATABUS_P2_P0       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x02;}while(0)//����LCM��������ΪP2~P0
#define LCM_SET_DATABUS_P6_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x06;}while(0)//����LCM��������ΪP6~P2
#define LCM_SET_DATABUS_P2_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0A;}while(0)//����LCM��������ΪP2~P7
#define LCM_SET_DATABUS_P6_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0E;}while(0)//����LCM��������ΪP6~P7
#define LCM_SET_MODE_I8080          do{LCMIFCFG&=~M68_I80;}while(0)//����LCM�Ĺ���ģʽ��8080
#define LCM_SET_MODE_M6800          do{LCMIFCFG|= M68_I80;}while(0)//����LCM�Ĺ���ģʽ��6800
#define LCM_SET_P41_P44_P43         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x00;}while(0)//����RS��RD��WR�ֱ�ΪP41��P44��P43
#define LCM_SET_P41_P37_P46         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x20;}while(0)//����RS��RD��WR�ֱ�ΪP41��P37��P46
#define LCM_SET_P41_P42_P40         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x40;}while(0)//����RS��RD��WR�ֱ�ΪP41��P42��P40
#define LCM_SET_P40_P37_P36         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x60;}while(0)//����RS��RD��WR�ֱ�ΪP40��P37��P36
#define LCM_WRITE_CMD               do{LCMIFCR=(ELCMIF|0x04);}while(0)//��LCM�ӿڷ���һ��ָ��
#define LCM_WRITE_DATA              do{LCMIFCR=(ELCMIF|0x05);}while(0)//��LCM�ӿڷ���һ������
#define LCM_READ_CMD                do{LCMIFCR=(ELCMIF|0x06);}while(0)//��LCM�ӿڽ���һ��ָ��
#define LCM_READ_DATA               do{LCMIFCR=(ELCMIF|0x07);}while(0)//��LCM�ӿڽ���һ������
#define LCM_GET_FLAG                (LCMIFSTA & LCMIFIF)              //��ȡLCM�ӿ��жϱ�־λ
#define LCM_CLS_FLAG                do{LCMIFSTA&=~LCMIFIF;}while(0)   //���LCM�ӿ��жϱ�־λ
/*------------------------------PCA/PWM���⹦�ܼĴ���----------------------------*/
sbit    CF                          =CCON^7;//PCA�����������־λ	
sbit    CR                          =CCON^6;//PCA�������п���λ
sbit    CCF3                        =CCON^3;//PCA3ģ���жϱ�־λ
sbit    CCF2                        =CCON^2;//PCA2ģ���жϱ�־λ
sbit    CCF1                        =CCON^1;//PCA1ģ���жϱ�־λ
sbit    CCF0                        =CCON^0;//PCA0ģ���жϱ�־λ
#define CIDL                        0x80    //����ģʽ���Ƿ�ֹͣPCA����
#define ECF                         0x01    //PCA����������ж�����λ
#define ECOM0_3                     0x40    //����PCAģ��0~3�ıȽϹ���
#define CCAPP0_3                    0x20    //����PCAģ��0~3���������ز���
#define CCAPN0_3                    0x10    //����PCAģ��0~3�����½��ز���
#define MAT0_3                      0x08    //����PCAģ��0~3��ƥ�书��
#define TOG0_3                      0x04    //����PCAģ��0~3�ĸ��������������
#define PWM0_3                      0x02    //����PCAģ��0~3����������������
#define ECCF0_3                     0x01    //����PCAģ��0~3��ƥ��/�����ж�
//-------------����ָ��------------//
#define PCA_POWER_ON                do{CR=1;}while(0)//��PCAģ��
#define PCA_POWER_OFF               do{CR=0;}while(0)//�ر�PCAģ��
#define PCA_IT_ENABLE               do{CMOD|= ECF;}while(0)//��PCA������������ж�
#define PCA_IT_DISABLE              do{CMOD&=~ECF;}while(0)//�ر�PCA������������ж�
#define PCA_GET_IT_FLAG             (CF)                   //��ȡPCA����������жϱ�־λ
#define PCA_CLS_IT_FLAG             do{CF=0;}while(0)      //���PCA����������жϱ�־λ
#define PCA_SET_IDLE_ENABLE         do{CMOD&=~CIDL;}while(0)//PCA�ڿ���ģʽ�¼�������
#define PCA_SET_IDLE_DISABLE        do{CMOD|= CIDL;}while(0)//PCA�ڿ���ģʽ��ֹͣ����
#define PCA_SET_CPS(value)          REG_IN_MASK(CMOD,0x0E,value)//����PCA����������Դ
#define PCA_SET_PIN(value)          REG_IN_MASK(P_SW1,0x30,value)//����PCA���������
#define PCA0_GET_IT_FLAG            (CCF0)                        //��ȡPCA0�����жϱ�־λ
#define PCA0_CLS_IT_FLAG            do{CCF0=0;}while(0)           //���PCA0�����жϱ�־λ
#define PCA0_SET_ECOM_ENABLE        do{CCAPM0|= ECOM0_3; }while(0)//��PCAģ��0�ıȽϹ���
#define PCA0_SET_ECOM_DISABLE       do{CCAPM0&=~ECOM0_3; }while(0)//�ر�PCAģ��0�ıȽϹ���
#define PCA0_SET_CCAPP_ENABLE       do{CCAPM0|= CCAPP0_3;}while(0)//��PCAģ��0�������ز�����
#define PCA0_SET_CCAPP_DISABLE      do{CCAPM0&=~CCAPP0_3;}while(0)//�ر�PCAģ��0�������ز�����
#define PCA0_SET_CCAPN_ENABLE       do{CCAPM0|= CCAPN0_3;}while(0)//��PCAģ��0���½��ز�����
#define PCA0_SET_CCAPN_DISABLE      do{CCAPM0&=~CCAPN0_3;}while(0)//�ر�PCAģ��0���½��ز�����
#define PCA0_SET_MAT_ENABLE         do{CCAPM0|= MAT0_3;  }while(0)//��PCAģ��0��ƥ�书��
#define PCA0_SET_MAT_DISABLE        do{CCAPM0&=~MAT0_3;  }while(0)//�ر�PCAģ��0��ƥ�书��
#define PCA0_SET_TOG_ENABLE         do{CCAPM0|= TOG0_3;  }while(0)//��PCAģ��0�ĸ��������������
#define PCA0_SET_TOG_DISABLE        do{CCAPM0&=~TOG0_3;  }while(0)//�ر�PCAģ��0�ĸ��������������
#define PCA0_SET_PWM_ENABLE         do{CCAPM0|= PWM0_3;  }while(0)//��PCAģ��0����������������
#define PCA0_SET_PWM_DISABLE        do{CCAPM0&=~PWM0_3;  }while(0)//�ر�PCAģ��0����������������
#define PCA0_SET_ECCF_ENABLE        do{CCAPM0|= ECCF0_3; }while(0)//��PCAģ��0��ƥ��/�����ж�
#define PCA0_SET_ECCF_DISABLE       do{CCAPM0&=~ECCF0_3; }while(0)//�ر�PCAģ��0��ƥ��/�����ж�
#define PCA1_GET_IT_FLAG            (CCF1)                        //��ȡPCA1�����жϱ�־λ
#define PCA1_CLS_IT_FLAG            do{CCF1=0;}while(0)           //���PCA1�����жϱ�־λ
#define PCA1_SET_ECOM_ENABLE        do{CCAPM1|= ECOM0_3; }while(0)//��PCAģ��1�ıȽϹ���
#define PCA1_SET_ECOM_DISABLE       do{CCAPM1&=~ECOM0_3; }while(0)//�ر�PCAģ��1�ıȽϹ���
#define PCA1_SET_CCAPP_ENABLE       do{CCAPM1|= CCAPP0_3;}while(0)//��PCAģ��1�������ز�����
#define PCA1_SET_CCAPP_DISABLE      do{CCAPM1&=~CCAPP0_3;}while(0)//�ر�PCAģ��1�������ز�����
#define PCA1_SET_CCAPN_ENABLE       do{CCAPM1|= CCAPN0_3;}while(0)//��PCAģ��1���½��ز�����
#define PCA1_SET_CCAPN_DISABLE      do{CCAPM1&=~CCAPN0_3;}while(0)//�ر�PCAģ��1���½��ز�����
#define PCA1_SET_MAT_ENABLE         do{CCAPM1|= MAT0_3;  }while(0)//��PCAģ��1��ƥ�书��
#define PCA1_SET_MAT_DISABLE        do{CCAPM1&=~MAT0_3;  }while(0)//�ر�PCAģ��1��ƥ�书��
#define PCA1_SET_TOG_ENABLE         do{CCAPM1|= TOG0_3;  }while(0)//��PCAģ��1�ĸ��������������
#define PCA1_SET_TOG_DISABLE        do{CCAPM1&=~TOG0_3;  }while(0)//�ر�PCAģ��1�ĸ��������������
#define PCA1_SET_PWM_ENABLE         do{CCAPM1|= PWM0_3;  }while(0)//��PCAģ��1����������������
#define PCA1_SET_PWM_DISABLE        do{CCAPM1&=~PWM0_3;  }while(0)//�ر�PCAģ��1����������������
#define PCA1_SET_ECCF_ENABLE        do{CCAPM1|= ECCF0_3; }while(0)//��PCAģ��1��ƥ��/�����ж�
#define PCA1_SET_ECCF_DISABLE       do{CCAPM1&=~ECCF0_3; }while(0)//�ر�PCAģ��1��ƥ��/�����ж�
#define PCA2_GET_IT_FLAG            (CCF2)                        //��ȡPCA2�����жϱ�־λ
#define PCA2_CLS_IT_FLAG            do{CCF2=0;}while(0)           //���PCA2�����жϱ�־λ
#define PCA2_SET_ECOM_ENABLE        do{CCAPM2|= ECOM0_3; }while(0)//��PCAģ��2�ıȽϹ���
#define PCA2_SET_ECOM_DISABLE       do{CCAPM2&=~ECOM0_3; }while(0)//�ر�PCAģ��2�ıȽϹ���
#define PCA2_SET_CCAPP_ENABLE       do{CCAPM2|= CCAPP0_3;}while(0)//��PCAģ��2�������ز�����
#define PCA2_SET_CCAPP_DISABLE      do{CCAPM2&=~CCAPP0_3;}while(0)//�ر�PCAģ��2�������ز�����
#define PCA2_SET_CCAPN_ENABLE       do{CCAPM2|= CCAPN0_3;}while(0)//��PCAģ��2���½��ز�����
#define PCA2_SET_CCAPN_DISABLE      do{CCAPM2&=~CCAPN0_3;}while(0)//�ر�PCAģ��2���½��ز�����
#define PCA2_SET_MAT_ENABLE         do{CCAPM2|= MAT0_3;  }while(0)//��PCAģ��2��ƥ�书��
#define PCA2_SET_MAT_DISABLE        do{CCAPM2&=~MAT0_3;  }while(0)//�ر�PCAģ��2��ƥ�书��
#define PCA2_SET_TOG_ENABLE         do{CCAPM2|= TOG0_3;  }while(0)//��PCAģ��2�ĸ��������������
#define PCA2_SET_TOG_DISABLE        do{CCAPM2&=~TOG0_3;  }while(0)//�ر�PCAģ��2�ĸ��������������
#define PCA2_SET_PWM_ENABLE         do{CCAPM2|= PWM0_3;  }while(0)//��PCAģ��2����������������
#define PCA2_SET_PWM_DISABLE        do{CCAPM2&=~PWM0_3;  }while(0)//�ر�PCAģ��2����������������
#define PCA2_SET_ECCF_ENABLE        do{CCAPM2|= ECCF0_3; }while(0)//��PCAģ��2��ƥ��/�����ж�
#define PCA2_SET_ECCF_DISABLE       do{CCAPM2&=~ECCF0_3; }while(0)//�ر�PCAģ��2��ƥ��/�����ж�
#define PCA3_GET_IT_FLAG            (CCF3)                        //��ȡPCA3�����жϱ�־λ
#define PCA3_CLS_IT_FLAG            do{CCF3=0;}while(0)           //���PCA3�����жϱ�־λ
#define PCA3_SET_ECOM_ENABLE        do{CCAPM3|= ECOM0_3;  }while(0)//��PCAģ��3�ıȽϹ���
#define PCA3_SET_ECOM_DISABLE       do{CCAPM3&=~ECOM0_3;  }while(0)//�ر�PCAģ��3�ıȽϹ���
#define PCA3_SET_CCAPP_ENABLE       do{CCAPM3|= CCAPP0_3; }while(0)//��PCAģ��3�������ز�����
#define PCA3_SET_CCAPP_DISABLE      do{CCAPM3&=~CCAPP0_3; }while(0)//�ر�PCAģ��3�������ز�����
#define PCA3_SET_CCAPN_ENABLE       do{CCAPM3|= CCAPN0_3; }while(0)//��PCAģ��3���½��ز�����
#define PCA3_SET_CCAPN_DISABLE      do{CCAPM3&=~CCAPN0_3; }while(0)//�ر�PCAģ��3���½��ز�����
#define PCA3_SET_MAT_ENABLE         do{CCAPM3|= MAT0_3;   }while(0)//��PCAģ��3��ƥ�书��
#define PCA3_SET_MAT_DISABLE        do{CCAPM3&=~MAT0_3;   }while(0)//�ر�PCAģ��3��ƥ�书��
#define PCA3_SET_TOG_ENABLE         do{CCAPM3|= TOG0_3;   }while(0)//��PCAģ��3�ĸ��������������
#define PCA3_SET_TOG_DISABLE        do{CCAPM3&=~TOG0_3;   }while(0)//�ر�PCAģ��3�ĸ��������������
#define PCA3_SET_PWM_ENABLE         do{CCAPM3|= PWM0_3;   }while(0)//��PCAģ��3����������������
#define PCA3_SET_PWM_DISABLE        do{CCAPM3&=~PWM0_3;   }while(0)//�ر�PCAģ��3����������������
#define PCA3_SET_ECCF_ENABLE        do{CCAPM3|= ECCF0_3;  }while(0)//��PCAģ��3��ƥ��/�����ж�
#define PCA3_SET_ECCF_DISABLE       do{CCAPM3&=~ECCF0_3;  }while(0)//�ر�PCAģ��3��ƥ��/�����ж�
//-------------�Ĵ�����ȡ----------//
#define PCA_SET_REG_CCON(value)     do{CCON=(u8)(value);}while(0)//����CCON�Ĵ���
#define PCA_GET_REG_CCON            (CCON)                       //��ȡCCON�Ĵ���
#define PCA_SET_REG_CMOD(value)     do{CMOD=(u8)(value);}while(0)//����CMOD�Ĵ���
#define PCA_GET_REG_CMOD            (CMOD)                       //��ȡCMOD�Ĵ���
#define PCA_SET_REG_CL(value)       do{CL=(u8)(value);}while(0)  //����CL�Ĵ���
#define PCA_GET_REG_CL              (CL)                         //��ȡCL�Ĵ���
#define PCA_SET_REG_CH(value)       do{CH=(u8)(value);}while(0)  //����CH�Ĵ���
#define PCA_GET_REG_CH              (CH)                         //��ȡCH�Ĵ���
#define PCA_SET_REG_CHL(value)      do{CL=(u8)(value);CH=(u8)(value>>8);}while(0)//����PCA�ļ���ֵ
#define PCA_GET_REG_CHL             ((((u16)CH)<<8)|(u16)CL)       //��ȡPCA�ļ���ֵ
#define PCA_SET_REG_CCAPM0(value)   do{CCAPM0=(u8)value;}while(0)  //����CCAPM0�Ĵ���
#define PCA_GET_REG_CCAPM0          (CCAPM0)                       //��ȡCCAPM0�Ĵ���
#define PCA_SET_REG_CCAP0L(value)   do{CCAP0L=(u8)(value);}while(0)//����CCAP0L�Ĵ���
#define PCA_GET_REG_CCAP0L          (CCAP0L)                       //��ȡCCAP0L�Ĵ���
#define PCA_SET_REG_CCAP0H(value)   do{CCAP0H=(u8)(value);}while(0)//����CCAP0H�Ĵ���
#define PCA_GET_REG_CCAP0H          (CCAP0H)                       //��ȡCCAP0H�Ĵ���
#define PCA_SET_REG_CCAP0HL(value)  do{CCAP0L=(u8)(value);CCAP0H=(u8)(value>>8);}while(0)//����PCA0�Ĳ���ֵ
#define PCA_GET_REG_CCAP0HL         ((((u16)CCAP0H)<<8)|(u16)CCAP0L) //��ȡPCA0�Ĳ���ֵ
#define PCA_SET_REG_PWM0(value)     do{PCA_PWM0=(u8)(value);}while(0)//����PCA_PWM0�Ĵ���
#define PCA_GET_REG_PWM0            (PCA_PWM0)                       //��ȡPCA_PWM0�Ĵ���
#define PCA_SET_REG_CCAPM1(value)   do{CCAPM1=(u8)value;}while(0)    //����CCAPM1�Ĵ���
#define PCA_GET_REG_CCAPM1          (CCAPM1)                         //��ȡCCAPM1�Ĵ���
#define PCA_SET_REG_CCAP1L(value)   do{CCAP1L=(u8)(value);}while(0)  //����CCAP1L�Ĵ���
#define PCA_GET_REG_CCAP1L          (CCAP1L)                         //��ȡCCAP1L�Ĵ���
#define PCA_SET_REG_CCAP1H(value)   do{CCAP1H=(u8)(value);}while(0)  //����CCAP1H�Ĵ���
#define PCA_GET_REG_CCAP1H          (CCAP1H)                         //��ȡCCAP1H�Ĵ���
#define PCA_SET_REG_CCAP1HL(value)  do{CCAP1L=(u8)(value);CCAP1H=(u8)(value>>8);}while(0)//����PCA1�Ĳ���ֵ
#define PCA_GET_REG_CCAP1HL         ((((u16)CCAP1H)<<8)|(u16)CCAP1L) //��ȡPCA1�Ĳ���ֵ
#define PCA_SET_REG_PWM1(value)     do{PCA_PWM1=(u8)(value);}while(0)//����PCA_PWM1�Ĵ���
#define PCA_GET_REG_PWM1            (PCA_PWM1)                       //��ȡPCA_PWM1�Ĵ���
#define PCA_SET_REG_CCAPM2(value)   do{CCAPM2=(u8)value;}while(0)    //����CCAPM2�Ĵ���
#define PCA_GET_REG_CCAPM2          (CCAPM2)                         //��ȡCCAPM2�Ĵ���
#define PCA_SET_REG_CCAP2L(value)   do{CCAP2L=(u8)(value);}while(0)  //����CCAP2L�Ĵ���
#define PCA_GET_REG_CCAP2L          (CCAP2L)                         //��ȡCCAP2L�Ĵ���
#define PCA_SET_REG_CCAP2H(value)   do{CCAP2H=(u8)(value);}while(0)  //����CCAP2H�Ĵ���
#define PCA_GET_REG_CCAP2H          (CCAP2H)                         //��ȡCCAP2H�Ĵ���
#define PCA_SET_REG_CCAP2HL(value)  do{CCAP2L=(u8)(value);CCAP2H=(u8)(value>>8);}while(0)//����PCA2�Ĳ���ֵ
#define PCA_GET_REG_CCAP2HL         ((((u16)CCAP2H)<<8)|(u16)CCAP2L) //��ȡPCA2�Ĳ���ֵ
#define PCA_SET_REG_PWM2(value)     do{PCA_PWM2=(u8)(value);}while(0)//����PCA_PWM2�Ĵ���
#define PCA_GET_REG_PWM2            (PCA_PWM2)                       //��ȡPCA_PWM2�Ĵ���
#define PCA_SET_REG_CCAPM3(value)   do{CCAPM3=(u8)value;}while(0)    //����CCAPM3�Ĵ���
#define PCA_GET_REG_CCAPM3          (CCAPM3)                         //��ȡCCAPM3�Ĵ���
#define PCA_SET_REG_CCAP3L(value)   do{CCAP3L=(u8)value;}while(0)    //����CCAP3L�Ĵ���
#define PCA_GET_REG_CCAP3L          (CCAP3L)                         //��ȡCCAP3L�Ĵ���
#define PCA_SET_REG_CCAP3H(value)   do{CCAP3H=(u8)value;}while(0)    //����CCAP3H�Ĵ���
#define PCA_GET_REG_CCAP3H          (CCAP3H)                         //��ȡCCAP3H�Ĵ���
#define PCA_SET_REG_CCAP3HL(value)  do{CCAP3L=(u8)(value);CCAP3H=(u8)(value>>8);}while(0)//����PCA3�Ĳ���ֵ
#define PCA_GET_REG_CCAP3HL         ((((u16)CCAP3H)<<8)|(u16)CCAP3L) //��ȡPCA3�Ĳ���ֵ
#define PCA_SET_REG_PWM3(value)     do{PCA_PWM3=(u8)value;}while(0)  //����PCA_PWM3�Ĵ���
#define PCA_GET_REG_PWM3            (PCA_PWM3)                       //��ȡPCA_PWM3�Ĵ���
//-------------���ܶ���------------//
#define PCA_IT_NUM                  interrupt 7//PCA�жϺ�
/*------------------------------BMM/DMA���⹦�ܼĴ���----------------------------*/
#define M2MIE                       0x80//DMA_MEM_MEM�ж�ʹ�ܿ���λ
#define TXACO                       0x40//DMA_MEM_MEMԴ��ַ�������λ
#define RXACO                       0x20//DMA_MEM_MEMĿ���ַ�������λ
#define ENM2M                       0x80//DMA_MEM_MEM����ʹ��λ
#define M2MTRIG                     0x40//DMA_MEM_MEM���ܴ���λ
#define ADCIE                       0x80//DMA_ADC_MEM�ж�ʹ�ܿ���λ
#define ENADC                       0x80//DMA_ADC_MEM����ʹ��λ
#define A2MTRIG                     0x40//DMA_ADC_MEM���ܴ���λ
#define SPIIE                       0x80//DMA_SPI_MEM�ж�ʹ�ܿ���λ
#define ACT_TX                      0x40//DMA_SPI_MEM�������ݿ���λ
#define ACT_RX                      0x20//DMA_SPI_MEM�������ݿ���λ
#define ENSPI                       0x80//DMA_SPI_MEM����ʹ��λ
#define S2MTRIG_M                   0x40//DMA_SPI_MEM�������ܴ���λ
#define S2MTRIG_S                   0x20//DMA_SPI_MEM�ӻ����ܴ���λ
#define CLRFIFO                     0x01//DMA_SPI_MEM���FIFOλ
#define SPIIF                       0x01//DMA_SPI_MEM�ж������־λ
#define SPIRXLOSS                   0x02//DMA_SPI_MEM�������ݶ�����־λ
#define SPITXOVW                    0x04//DMA_SPI_MEM���ݸ��Ǳ�־λ
#define WRPSS                       0x04//DMA_SPI_MEMʹ��SS�ſ���λ
#define URTIE                       0x80//DMA_UART_MEM�����ж�ʹ�ܿ���λ
#define ENURT                       0x80//DMA_UART_MEM���͹���ʹ��λ
#define URTTRIG                     0x40//DMA_UART_MEM���ʹ�������λ
#define URTIF                       0x01//DMA_UART_MEM�����ж������־λ
#define URTXOVW                     0x04//DMA_UART_MEM�������ݸ��Ǳ�־λ
#define URRIE                       0x80//DMA_UART_MEM�����ж�ʹ�ܿ���λ
#define ENURR                       0x80//DMA_UART_MEM���չ���ʹ��λ
#define URRTRIG                     0x40//DMA_UART_MEM���մ�������λ
#define URRIF                       0x01//DMA_UART_MEM�����ж������־λ
#define URRXOVW                     0x04//DMA_UART_MEM�������ݸ��Ǳ�־λ
#define LCMIE                       0x80//DMA_LCM_MEM�ж�ʹ�ܿ���λ
#define ENLCM                       0x80//DMA_LCM_MEM����ʹ��λ
#define TRIGWC                      0x40//DMA_LCM_MEM��������ģʽ��������λ
#define TRIGWD                      0x20//DMA_LCM_MEM��������ģʽ��������λ
#define TRIGRC                      0x10//DMA_LCM_MEM����ָ��ģʽ��������λ
#define TRIGRD                      0x08//DMA_LCM_MEM��������ģʽ��������λ
#define LCMIF                       0x01//DMA_LCM_MEM�ж������־λ
#define LCMTXOVW                    0x02//DMA_LCM_MEM���ݸ��Ǳ�־λ
//-------------����ָ��------------//
#define MEM_MEM_IT_ENABLE               do{DMA_M2M_CFG|= M2MIE;}while(0)//��MEM��MEM���ж�ʹ��
#define MEM_MEM_IT_DISABLE              do{DMA_M2M_CFG&=~M2MIE;}while(0)//�ı�MEM��MEM���ж�ʹ��
#define MEM_MEM_SET_TX_ADD              do{DMA_M2M_CFG&=~TXACO;}while(0)//MEM��MEM��Դ��ַ����
#define MEM_MEM_SET_TX_DEC              do{DMA_M2M_CFG|= TXACO;}while(0)//MEM��MEM��Դ��ַ�ݼ�
#define MEM_MEM_SET_RX_ADD              do{DMA_M2M_CFG&=~RXACO;}while(0)//MEM��MEM��Ŀ���ַ����
#define MEM_MEM_SET_RX_DEC              do{DMA_M2M_CFG|= RXACO;}while(0)//MEM��MEM��Ŀ���ַ�ݼ�
#define MEM_MEM_SET_IT_PRIORITY_0       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x00);}while(0)//����MEM��MEM���ж����ȼ�Ϊ0
#define MEM_MEM_SET_IT_PRIORITY_1       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x04);}while(0)//����MEM��MEM���ж����ȼ�Ϊ1
#define MEM_MEM_SET_IT_PRIORITY_2       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x08);}while(0)//����MEM��MEM���ж����ȼ�Ϊ2
#define MEM_MEM_SET_IT_PRIORITY_3       do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x0C))|0x0C);}while(0)//����MEM��MEM���ж����ȼ�Ϊ3
#define MEM_MEM_SET_BUS_PRIORITY_0      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x00);}while(0)//����MEM��MEM���������ȼ�Ϊ0
#define MEM_MEM_SET_BUS_PRIORITY_1      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x01);}while(0)//����MEM��MEM���������ȼ�Ϊ1
#define MEM_MEM_SET_BUS_PRIORITY_2      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x02);}while(0)//����MEM��MEM���������ȼ�Ϊ2
#define MEM_MEM_SET_BUS_PRIORITY_3      do{DMA_M2M_CFG=((DMA_M2M_CFG&(~0x03))|0x03);}while(0)//����MEM��MEM���������ȼ�Ϊ3
#define MEM_MEM_ENABLE                  do{DMA_M2M_CR|= ENM2M;}while(0)  //��MEM��MEM����
#define MEM_MEM_DISABLE                 do{DMA_M2M_CR&=~ENM2M;}while(0)  //�ر�MEM��MEM����
#define MEM_MEM_START                   do{DMA_M2M_CR|= M2MTRIG;}while(0)//��ʼһ��MEM��MEM�Ĵ���
#define MEM_MEM_GET_FLAG                (DMA_M2M_STA)                    //��ȡMEM��MEM�����״̬
#define MEM_MEM_CLS_FLAG                do{DMA_M2M_STA=0;}while(0)       //���MEM��MEM��״ֵ̬
#define MEM_MEM_SET_COUNT_MAX(value)    do{DMA_M2M_AMT=(u8)(value);}while(0)//����MEM��MEM��������ֽ���
#define MEM_MEM_GET_COUNT_DONE          (DMA_M2M_DONE)                   //��ȡMEM��MEM�Ѿ�������ɵ��ֽ���
#define MEM_MEM_SET_TX_ADDR(value)      do{DMA_M2M_TXA=(u16)(value);}while(0)//����MEM��MEM��Դ��ַ
#define MEM_MEM_SET_RX_ADDR(value)      do{DMA_M2M_RXA=(u16)(value);}while(0)//����MEM��MEM��Ŀ���ַ
#define ADC_MEM_IT_ENABLE               do{DMA_ADC_CFG|= ADCIE;}while(0)//��ADC��MEM���ж�ʹ��
#define ADC_MEM_IT_DISABLE              do{DMA_ADC_CFG&=~ADCIE;}while(0)//�ر�ADC��MEM���ж�ʹ��
#define ADC_MEM_SET_IT_PRIORITY_0       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x00);}while(0)//����ADC��MEM���ж����ȼ�Ϊ0
#define ADC_MEM_SET_IT_PRIORITY_1       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x04);}while(0)//����ADC��MEM���ж����ȼ�Ϊ1
#define ADC_MEM_SET_IT_PRIORITY_2       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x08);}while(0)//����ADC��MEM���ж����ȼ�Ϊ2
#define ADC_MEM_SET_IT_PRIORITY_3       do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x0C))|0x0C);}while(0)//����ADC��MEM���ж����ȼ�Ϊ3
#define ADC_MEM_SET_BUS_PRIORITY_0      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x00);}while(0)//����ADC��MEM���������ȼ�Ϊ0
#define ADC_MEM_SET_BUS_PRIORITY_1      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x01);}while(0)//����ADC��MEM���������ȼ�Ϊ1
#define ADC_MEM_SET_BUS_PRIORITY_2      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x02);}while(0)//����ADC��MEM���������ȼ�Ϊ2
#define ADC_MEM_SET_BUS_PRIORITY_3      do{DMA_ADC_CFG=((DMA_ADC_CFG&(~0x03))|0x03);}while(0)//����ADC��MEM���������ȼ�Ϊ3
#define ADC_MEM_ENABLE                  do{DMA_ADC_CR|= ENADC;}while(0)  //��ADC��MEM����
#define ADC_MEM_DISABLE                 do{DMA_ADC_CR&=~ENADC;}while(0)  //�ر�ADC��MEM����
#define ADC_MEM_START                   do{DMA_ADC_CR|= A2MTRIG;}while(0)//��ʼһ��ADC��MEM�Ĵ���
#define ADC_MEM_GET_FLAG                (DMA_ADC_STA)                    //��ȡADC��MEM�����״̬
#define ADC_MEM_CLS_FLAG                do{DMA_ADC_STA=0;}while(0)       //���ADC��MEM��״ֵ̬
#define ADC_MEM_SET_RX_ADDR(value)      do{DMA_ADC_RXA=(u16)(value);}while(0)//���ý���ADC���ݵĵ�ַ
#define ADC_MEM_SET_CH_COUNT(value)     do{DMA_ADC_CFG2=((u8)(value)&0x0F);}while(0)//����ÿ��ͨ���ɼ����ٴ�
#define ADC_MEM_SET_CH_0_7_EN(value)    do{DMA_ADC_CHSW1=(u8)(value);}while(0)//���ò���ADC_MEM�����ͨ����0~7��
#define ADC_MEM_SET_CH_8_15_EN(value)   do{DMA_ADC_CHSW0=(u8)(value);}while(0)//���ò���ADC_MEM�����ͨ����8~15��
#define SPI_MEM_IT_ENABLE               do{DMA_SPI_CFG|= SPIIE;}while(0)//��SPI��MEM���ж�ʹ��
#define SPI_MEM_IT_DISABLE              do{DMA_SPI_CFG&=~SPIIE;}while(0)//�ر�SPI��MEM���ж�ʹ��
#define SPI_MEM_SET_TX_ENABLE           do{DMA_SPI_CFG|= ACT_TX;}while(0)//����SPI_MEM��������
#define SPI_MEM_SET_TX_DISABLE          do{DMA_SPI_CFG&=~ACT_TX;}while(0)//��ֹSPI_MEM��������
#define SPI_MEM_SET_RX_ENABLE           do{DMA_SPI_CFG|= ACT_RX;}while(0)//����SPI_MEM��������
#define SPI_MEM_SET_RX_DISABLE          do{DMA_SPI_CFG&=~ACT_RX;}while(0)//��ֹSPI_MEM��������
#define SPI_MEM_SET_IT_PRIORITY_0       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x00);}while(0)//����SPI��MEM���ж����ȼ�Ϊ0
#define SPI_MEM_SET_IT_PRIORITY_1       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x04);}while(0)//����SPI��MEM���ж����ȼ�Ϊ1
#define SPI_MEM_SET_IT_PRIORITY_2       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x08);}while(0)//����SPI��MEM���ж����ȼ�Ϊ2
#define SPI_MEM_SET_IT_PRIORITY_3       do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x0C))|0x0C);}while(0)//����SPI��MEM���ж����ȼ�Ϊ3
#define SPI_MEM_SET_BUS_PRIORITY_0      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x00);}while(0)//����SPI��MEM���������ȼ�Ϊ0
#define SPI_MEM_SET_BUS_PRIORITY_1      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x01);}while(0)//����SPI��MEM���������ȼ�Ϊ1
#define SPI_MEM_SET_BUS_PRIORITY_2      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x02);}while(0)//����SPI��MEM���������ȼ�Ϊ2
#define SPI_MEM_SET_BUS_PRIORITY_3      do{DMA_SPI_CFG=((DMA_SPI_CFG&(~0x03))|0x03);}while(0)//����SPIC��MEM���������ȼ�Ϊ3
#define SPI_MEM_ENABLE                  do{DMA_SPI_CR|= ENSPI;}while(0)     //��SPI��MEM����
#define SPI_MEM_DISABLE                 do{DMA_SPI_CR&=~ENSPI;}while(0)     //�ر�SPI��MEM����
#define SPI_MEM_MODE_M_START            do{DMA_SPI_CR|= S2MTRIG_M;}while(0) //��ʼһ��SPI��MEM����������
#define SPI_MEM_MODE_S_START            do{DMA_SPI_CR|= S2MTRIG_S;}while(0) //��ʼһ��SPI��MEM�Ĵӻ���
#define SPI_MEM_CLS_FIFO                do{DMA_SPI_CR|= CLRFIFO;}while(0)   //���SPI��MEM��FIFO
#define SPI_MEM_GET_FLAG                (DMA_SPI_STA & SPIIF)               //��ȡSPI��MEM�жϱ�־λ
#define SPI_MEM_GET_FLAG_RXLOSS         (DMA_SPI_STA & SPIRXLOSS)           //��ȡSPI��MEM���ݶ�ʧ��־λ
#define SPI_MEM_GET_FLAG_TXOVW          (DMA_SPI_STA & SPITXOVW)            //��ȡSPI��MEM���ݸ��Ǳ�־λ
#define SPI_MEM_CLS_FLAG                do{DMA_SPI_STA&=~SPIIF;}while(0)    //���SPI��MEM�жϱ�־λ
#define SPI_MEM_CLS_FLAG_RXLOSS         do{DMA_SPI_STA&=~SPIRXLOSS;}while(0)//���SPI��MEM���ݶ�ʧ��־λ
#define SPI_MEM_CLS_FLAG_TXOVW          do{DMA_SPI_STA&=~SPITXOVW;}while(0) //���SPI��MEM���ݸ��Ǳ�־λ
#define SPI_MEM_SET_COUNT_MAX(value)    do{DMA_SPI_AMT=(u8)(value);}while(0)//����SPI��MEM�ķ���/�������ֽ���
#define SPI_MEM_GET_COUNT_DONE          (DMA_SPI_DONE)                      //��ȡSPI��MEM�Ѿ�������ֽ���
#define SPI_MEM_SET_TX_ADDR(value)      do{DMA_SPI_TXA=(u16)(value);}while(0)//����SPI��MEM�ķ��͵�ַ
#define SPI_MEM_SET_RX_ADDR(value)      do{DMA_SPI_RXA=(u16)(value);}while(0)//����SPI��MEM�Ľ��յ�ַ
#define SPI_MEM_SET_SS_AUTO_ENABLE      do{DMA_SPI_CFG2|= WRPSS;}while(0)    //����SPI��MEM��SS���Զ�����
#define SPI_MEM_SET_SS_AUTO_DISABLE     do{DMA_SPI_CFG2&=~WRPSS;}while(0)    //����SPI��MEM��SS���ֶ�����
#define SPI_MEM_SET_SS_P12              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x00;}while(0)//�����Զ����Ƶ�SS��ΪP12��
#define SPI_MEM_SET_SS_P22              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x01;}while(0)//�����Զ����Ƶ�SS��ΪP22��
#define SPI_MEM_SET_SS_P74              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x02;}while(0)//�����Զ����Ƶ�SS��ΪP74��
#define SPI_MEM_SET_SS_P35              do{DMA_SPI_CFG2=(DMA_SPI_CFG2&(~0x03))|0x03;}while(0)//�����Զ����Ƶ�SS��ΪP35��
#define UR1_MEM_TX_IT_ENABLE            do{DMA_UR1T_CFG|= URTIE;}while(0)//��MEM��UART1�ķ����ж�ʹ��
#define UR1_MEM_TX_IT_DISABLE           do{DMA_UR1T_CFG|= URTIE;}while(0)//�ر�MEM��UART1�ķ����ж�ʹ��
#define UR1_MEM_RX_IT_ENABLE            do{DMA_UR1R_CFG|= URRIE;}while(0)//��UART1��MEM�Ľ����ж�ʹ��
#define UR1_MEM_RX_IT_DISABLE           do{DMA_UR1R_CFG|= URRIE;}while(0)//�ر�UART1��MEM�Ľ����ж�ʹ��
#define UR1_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x00);}while(0)//����MEM��UART1�ķ����ж����ȼ�Ϊ0
#define UR1_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x04);}while(0)//����MEM��UART1�ķ����ж����ȼ�Ϊ1
#define UR1_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x08);}while(0)//����MEM��UART1�ķ����ж����ȼ�Ϊ2
#define UR1_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x0C))|0x0C);}while(0)//����MEM��UART1�ķ����ж����ȼ�Ϊ3
#define UR1_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x00);}while(0)//����UART1��MEM�Ľ����ж����ȼ�Ϊ0
#define UR1_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x04);}while(0)//����UART1��MEM�Ľ����ж����ȼ�Ϊ1
#define UR1_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x08);}while(0)//����UART1��MEM�Ľ����ж����ȼ�Ϊ2
#define UR1_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x0C))|0x0C);}while(0)//����UART1��MEM�Ľ����ж����ȼ�Ϊ3
#define UR1_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x00);}while(0)//����MEM��UART1�ķ����������ȼ�Ϊ0
#define UR1_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x01);}while(0)//����MEM��UART1�ķ����������ȼ�Ϊ1
#define UR1_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x02);}while(0)//����MEM��UART1�ķ����������ȼ�Ϊ2
#define UR1_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR1T_CFG=((DMA_UR1T_CFG&(~0x03))|0x03);}while(0)//����MEM��UART1�ķ����������ȼ�Ϊ3
#define UR1_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x00);}while(0)//����UART1��MEM�Ľ����������ȼ�Ϊ0
#define UR1_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x01);}while(0)//����UART1��MEM�Ľ����������ȼ�Ϊ1
#define UR1_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x02);}while(0)//����UART1��MEM�Ľ����������ȼ�Ϊ2
#define UR1_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR1R_CFG=((DMA_UR1R_CFG&(~0x03))|0x03);}while(0)//����UART1��MEM�Ľ����������ȼ�Ϊ3
#define UR1_MEM_TX_ENABLE               do{DMA_UR1T_CR|= ENURT;}while(0)   //��MEM��UART1�ķ���ʹ��
#define UR1_MEM_TX_DISABLE              do{DMA_UR1T_CR&=~ENURT;}while(0)   //�ر�MEM��UART1�ķ���ʹ��
#define UR1_MEM_RX_ENABLE               do{DMA_UR1R_CR|= ENURR;}while(0)   //��UART1��MEM�Ľ���ʹ��
#define UR1_MEM_RX_DISABLE              do{DMA_UR1R_CR&=~ENURR;}while(0)   //�ر�UART1��MEM�Ľ���ʹ��
#define UR1_MEM_TX_START                do{DMA_UR1T_CR|= URTTRIG;}while(0) //��ʼһ��MEM��UART1�Ĵ���
#define UR1_MEM_RX_START                do{DMA_UR1R_CR|= URRTRIG;}while(0) //��ʼһ��UART1��MEM�Ĵ���
#define UR1_MEM_GET_TX_FLAG             (DMA_UR1T_STA & URTIF)             //��ȡMEM��UART1���жϱ�־λ
#define UR1_MEM_GET_TX_FLAG_TXOVW       (DMA_UR1T_STA & URTXOVW)           //��ȡMEM��UART1�ĸ��Ǳ�־λ
#define UR1_MEM_GET_RX_FLAG             (DMA_UR1R_STA & URRIF)             //��ȡUART1��MEM���жϱ�־λ
#define UR1_MEM_GET_RX_FLAG_RXOVW       (DMA_UR1R_STA & URRXOVW)           //��ȡUART1��MEM�ĸ��Ǳ�־λ
#define UR1_MEM_CLS_TX_FLAG             do{DMA_UR1T_STA&=~URTIF;}while(0)  //���MEM��UART1���жϱ�־λ
#define UR1_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR1T_STA&=~URTXOVW;}while(0)//���MEM��UART1�ĸ��Ǳ�־λ
#define UR1_MEM_CLS_RX_FLAG             do{DMA_UR1R_STA&=~URRIF;}while(0)  //���UART1��MEM���жϱ�־λ
#define UR1_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR1R_STA&=~URRXOVW;}while(0)//���UART1��MEM�ĸ��Ǳ�־λ
#define UR1_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR1T_AMT=(u8)(value);}while(0)//����MEM��UART1�������ֽ���
#define UR1_MEM_GET_TX_COUNT_DONE       (DMA_UR1T_DONE)                 //��ȡMEM��UART1�Ѿ����͵��ֽ���
#define UR1_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR1R_AMT=(u8)(value);}while(0)//����UART1��MEM�������ֽ���
#define UR1_MEM_GET_RX_COUNT_DONE       (DMA_UR1R_DONE)                 //��ȡUART1��MEM�Ѿ����յ��ֽ���
#define UR1_MEM_SET_TX_ADDR(value)      do{DMA_UR1T_TXA=(u16)(value);}while(0)//����MEM��UART1�ķ��͵�ַ
#define UR1_MEM_SET_RX_ADDR(value)      do{DMA_UR1R_RXA=(u16)(value);}while(0)//����UART1��MEM�Ľ��յ�ַ
#define UR2_MEM_TX_IT_ENABLE            do{DMA_UR2T_CFG|= URTIE;}while(0)//��MEM��UART2�ķ����ж�ʹ��
#define UR2_MEM_TX_IT_DISABLE           do{DMA_UR2T_CFG|= URTIE;}while(0)//�ر�MEM��UART2�ķ����ж�ʹ��
#define UR2_MEM_RX_IT_ENABLE            do{DMA_UR2R_CFG|= URRIE;}while(0)//��UART2��MEM�Ľ����ж�ʹ��
#define UR2_MEM_RX_IT_DISABLE           do{DMA_UR2R_CFG|= URRIE;}while(0)//�ر�UART2��MEM�Ľ����ж�ʹ��
#define UR2_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x00);}while(0)//����MEM��UART2�ķ����ж����ȼ�Ϊ0
#define UR2_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x04);}while(0)//����MEM��UART2�ķ����ж����ȼ�Ϊ1
#define UR2_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x08);}while(0)//����MEM��UART2�ķ����ж����ȼ�Ϊ2
#define UR2_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x0C))|0x0C);}while(0)//����MEM��UART2�ķ����ж����ȼ�Ϊ3
#define UR2_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x00);}while(0)//����UART2��MEM�Ľ����ж����ȼ�Ϊ0
#define UR2_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x04);}while(0)//����UART2��MEM�Ľ����ж����ȼ�Ϊ1
#define UR2_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x08);}while(0)//����UART2��MEM�Ľ����ж����ȼ�Ϊ2
#define UR2_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x0C))|0x0C);}while(0)//����UART2��MEM�Ľ����ж����ȼ�Ϊ3
#define UR2_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x00);}while(0)//����MEM��UART2�ķ����������ȼ�Ϊ0
#define UR2_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x01);}while(0)//����MEM��UART2�ķ����������ȼ�Ϊ1
#define UR2_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x02);}while(0)//����MEM��UART2�ķ����������ȼ�Ϊ2
#define UR2_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR2T_CFG=((DMA_UR2T_CFG&(~0x03))|0x03);}while(0)//����MEM��UART2�ķ����������ȼ�Ϊ3
#define UR2_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x00);}while(0)//����UART2��MEM�Ľ����������ȼ�Ϊ0
#define UR2_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x01);}while(0)//����UART2��MEM�Ľ����������ȼ�Ϊ1
#define UR2_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x02);}while(0)//����UART2��MEM�Ľ����������ȼ�Ϊ2
#define UR2_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR2R_CFG=((DMA_UR2R_CFG&(~0x03))|0x03);}while(0)//����UART2��MEM�Ľ����������ȼ�Ϊ3
#define UR2_MEM_TX_ENABLE               do{DMA_UR2T_CR|= ENURT;}while(0)   //��MEM��UART2�ķ���ʹ��
#define UR2_MEM_TX_DISABLE              do{DMA_UR2T_CR&=~ENURT;}while(0)   //�ر�MEM��UART2�ķ���ʹ��
#define UR2_MEM_RX_ENABLE               do{DMA_UR2R_CR|= ENURR;}while(0)   //��UART2��MEM�Ľ���ʹ��
#define UR2_MEM_RX_DISABLE              do{DMA_UR2R_CR&=~ENURR;}while(0)   //�ر�UART2��MEM�Ľ���ʹ��
#define UR2_MEM_TX_START                do{DMA_UR2T_CR|= URTTRIG;}while(0) //��ʼһ��MEM��UART2�Ĵ���
#define UR2_MEM_RX_START                do{DMA_UR2R_CR|= URRTRIG;}while(0) //��ʼһ��UART2��MEM�Ĵ���
#define UR2_MEM_GET_TX_FLAG             (DMA_UR2T_STA & URTIF)             //��ȡMEM��UART2���жϱ�־λ
#define UR2_MEM_GET_TX_FLAG_TXOVW       (DMA_UR2T_STA & URTXOVW)           //��ȡMEM��UART2�ĸ��Ǳ�־λ
#define UR2_MEM_GET_RX_FLAG             (DMA_UR2R_STA & URRIF)             //��ȡUART2��MEM���жϱ�־λ
#define UR2_MEM_GET_RX_FLAG_RXOVW       (DMA_UR2R_STA & URRXOVW)           //��ȡUART2��MEM�ĸ��Ǳ�־λ
#define UR2_MEM_CLS_TX_FLAG             do{DMA_UR2T_STA&=~URTIF;}while(0)  //���MEM��UART2���жϱ�־λ
#define UR2_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR2T_STA&=~URTXOVW;}while(0)//���MEM��UART2�ĸ��Ǳ�־λ
#define UR2_MEM_CLS_RX_FLAG             do{DMA_UR2R_STA&=~URRIF;}while(0)  //���UART2��MEM���жϱ�־λ
#define UR2_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR2R_STA&=~URRXOVW;}while(0)//���UART2��MEM�ĸ��Ǳ�־λ
#define UR2_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR2T_AMT=(u8)(value);}while(0)//����MEM��UART2�������ֽ���
#define UR2_MEM_GET_TX_COUNT_DONE       (DMA_UR2T_DONE)                //��ȡMEM��UART2�Ѿ����͵��ֽ���
#define UR2_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR2R_AMT=(u8)(value);}while(0)//����UART2��MEM�������ֽ���
#define UR2_MEM_GET_RX_COUNT_DONE       (DMA_UR2R_DONE)                //��ȡUART2��MEM�Ѿ����յ��ֽ���
#define UR2_MEM_SET_TX_ADDR(value)      do{DMA_UR2T_TXA=(u16)(value);}while(0)//����MEM��UART2�ķ��͵�ַ
#define UR2_MEM_SET_RX_ADDR(value)      do{DMA_UR2R_RXA=(u16)(value);}while(0)//����UART2��MEM�Ľ��յ�ַ
#define UR3_MEM_TX_IT_ENABLE            do{DMA_UR3T_CFG|= URTIE;}while(0)//��MEM��UART3�ķ����ж�ʹ��
#define UR3_MEM_TX_IT_DISABLE           do{DMA_UR3T_CFG|= URTIE;}while(0)//�ر�MEM��UART3�ķ����ж�ʹ��
#define UR3_MEM_RX_IT_ENABLE            do{DMA_UR3R_CFG|= URRIE;}while(0)//��UART3��MEM�Ľ����ж�ʹ��
#define UR3_MEM_RX_IT_DISABLE           do{DMA_UR3R_CFG|= URRIE;}while(0)//�ر�UART3��MEM�Ľ����ж�ʹ��
#define UR3_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x00);}while(0)//����MEM��UART3�ķ����ж����ȼ�Ϊ0
#define UR3_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x04);}while(0)//����MEM��UART3�ķ����ж����ȼ�Ϊ1
#define UR3_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x08);}while(0)//����MEM��UART3�ķ����ж����ȼ�Ϊ2
#define UR3_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x0C))|0x0C);}while(0)//����MEM��UART3�ķ����ж����ȼ�Ϊ3
#define UR3_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x00);}while(0)//����UART3��MEM�Ľ����ж����ȼ�Ϊ0
#define UR3_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x04);}while(0)//����UART3��MEM�Ľ����ж����ȼ�Ϊ1
#define UR3_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x08);}while(0)//����UART3��MEM�Ľ����ж����ȼ�Ϊ2
#define UR3_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x0C))|0x0C);}while(0)//����UART3��MEM�Ľ����ж����ȼ�Ϊ3
#define UR3_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x00);}while(0)//����MEM��UART3�ķ����������ȼ�Ϊ0
#define UR3_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x01);}while(0)//����MEM��UART3�ķ����������ȼ�Ϊ1
#define UR3_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x02);}while(0)//����MEM��UART3�ķ����������ȼ�Ϊ2
#define UR3_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR3T_CFG=((DMA_UR3T_CFG&(~0x03))|0x03);}while(0)//����MEM��UART3�ķ����������ȼ�Ϊ3
#define UR3_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x00);}while(0)//����UART3��MEM�Ľ����������ȼ�Ϊ0
#define UR3_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x01);}while(0)//����UART3��MEM�Ľ����������ȼ�Ϊ1
#define UR3_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x02);}while(0)//����UART3��MEM�Ľ����������ȼ�Ϊ2
#define UR3_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR3R_CFG=((DMA_UR3R_CFG&(~0x03))|0x03);}while(0)//����UART3��MEM�Ľ����������ȼ�Ϊ3
#define UR3_MEM_TX_ENABLE               do{DMA_UR3T_CR|= ENURT;}while(0)   //��MEM��UART3�ķ���ʹ��
#define UR3_MEM_TX_DISABLE              do{DMA_UR3T_CR&=~ENURT;}while(0)   //�ر�MEM��UART3�ķ���ʹ��
#define UR3_MEM_RX_ENABLE               do{DMA_UR3R_CR|= ENURR;}while(0)   //��UART3��MEM�Ľ���ʹ��
#define UR3_MEM_RX_DISABLE              do{DMA_UR3R_CR&=~ENURR;}while(0)   //�ر�UART3��MEM�Ľ���ʹ��
#define UR3_MEM_TX_START                do{DMA_UR3T_CR|= URTTRIG;}while(0) //��ʼһ��MEM��UART3�Ĵ���
#define UR3_MEM_RX_START                do{DMA_UR3R_CR|= URRTRIG;}while(0) //��ʼһ��UART3��MEM�Ĵ���
#define UR3_MEM_GET_TX_FLAG             (DMA_UR3T_STA & URTIF)             //��ȡMEM��UART3���жϱ�־λ
#define UR3_MEM_GET_TX_FLAG_TXOVW       (DMA_UR3T_STA & URTXOVW)           //��ȡMEM��UART3�ĸ��Ǳ�־λ
#define UR3_MEM_GET_RX_FLAG             (DMA_UR3R_STA & URRIF)             //��ȡUART3��MEM���жϱ�־λ
#define UR3_MEM_GET_RX_FLAG_RXOVW       (DMA_UR3R_STA & URRXOVW)           //��ȡUART3��MEM�ĸ��Ǳ�־λ
#define UR3_MEM_CLS_TX_FLAG             do{DMA_UR3T_STA&=~URTIF;}while(0)  //���MEM��UART3���жϱ�־λ
#define UR3_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR3T_STA&=~URTXOVW;}while(0)//���MEM��UART3�ĸ��Ǳ�־λ
#define UR3_MEM_CLS_RX_FLAG             do{DMA_UR3R_STA&=~URRIF;}while(0)  //���UART3��MEM���жϱ�־λ
#define UR3_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR3R_STA&=~URRXOVW;}while(0)//���UART3��MEM�ĸ��Ǳ�־λ
#define UR3_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR3T_AMT=(u8)(value);}while(0)//����MEM��UART3�������ֽ���
#define UR3_MEM_GET_TX_COUNT_DONE       (DMA_UR3T_DONE)                //��ȡMEM��UART3�Ѿ����͵��ֽ���
#define UR3_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR3R_AMT=(u8)(value);}while(0)//����UART3��MEM�������ֽ���
#define UR3_MEM_GET_RX_COUNT_DONE       (DMA_UR3R_DONE)                //��ȡUART3��MEM�Ѿ����յ��ֽ���
#define UR3_MEM_SET_TX_ADDR(value)      do{DMA_UR3T_TXA=(u16)(value);}while(0)//����MEM��UART3�ķ��͵�ַ
#define UR3_MEM_SET_RX_ADDR(value)      do{DMA_UR3R_RXA=(u16)(value);}while(0)//����UART3��MEM�Ľ��յ�ַ
#define UR4_MEM_TX_IT_ENABLE            do{DMA_UR4T_CFG|= URTIE;}while(0)//��MEM��UART4�ķ����ж�ʹ��
#define UR4_MEM_TX_IT_DISABLE           do{DMA_UR4T_CFG|= URTIE;}while(0)//�ر�MEM��UART4�ķ����ж�ʹ��
#define UR4_MEM_RX_IT_ENABLE            do{DMA_UR4R_CFG|= URRIE;}while(0)//��UART4��MEM�Ľ����ж�ʹ��
#define UR4_MEM_RX_IT_DISABLE           do{DMA_UR4R_CFG|= URRIE;}while(0)//�ر�UART4��MEM�Ľ����ж�ʹ��
#define UR4_MEM_SET_TX_IT_PRIORITY_0    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x00);}while(0)//����MEM��UART4�ķ����ж����ȼ�Ϊ0
#define UR4_MEM_SET_TX_IT_PRIORITY_1    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x04);}while(0)//����MEM��UART4�ķ����ж����ȼ�Ϊ1
#define UR4_MEM_SET_TX_IT_PRIORITY_2    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x08);}while(0)//����MEM��UART4�ķ����ж����ȼ�Ϊ2
#define UR4_MEM_SET_TX_IT_PRIORITY_3    do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x0C))|0x0C);}while(0)//����MEM��UART4�ķ����ж����ȼ�Ϊ3
#define UR4_MEM_SET_RX_IT_PRIORITY_0    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x00);}while(0)//����UART4��MEM�Ľ����ж����ȼ�Ϊ0
#define UR4_MEM_SET_RX_IT_PRIORITY_1    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x04);}while(0)//����UART4��MEM�Ľ����ж����ȼ�Ϊ1
#define UR4_MEM_SET_RX_IT_PRIORITY_2    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x08);}while(0)//����UART4��MEM�Ľ����ж����ȼ�Ϊ2
#define UR4_MEM_SET_RX_IT_PRIORITY_3    do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x0C))|0x0C);}while(0)//����UART4��MEM�Ľ����ж����ȼ�Ϊ3
#define UR4_MEM_SET_TX_BUS_PRIORITY_0   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x00);}while(0)//����MEM��UART4�ķ����������ȼ�Ϊ0
#define UR4_MEM_SET_TX_BUS_PRIORITY_1   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x01);}while(0)//����MEM��UART4�ķ����������ȼ�Ϊ1
#define UR4_MEM_SET_TX_BUS_PRIORITY_2   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x02);}while(0)//����MEM��UART4�ķ����������ȼ�Ϊ2
#define UR4_MEM_SET_TX_BUS_PRIORITY_3   do{DMA_UR4T_CFG=((DMA_UR4T_CFG&(~0x03))|0x03);}while(0)//����MEM��UART4�ķ����������ȼ�Ϊ3
#define UR4_MEM_SET_RX_BUS_PRIORITY_0   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x00);}while(0)//����UART4��MEM�Ľ����������ȼ�Ϊ0
#define UR4_MEM_SET_RX_BUS_PRIORITY_1   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x01);}while(0)//����UART4��MEM�Ľ����������ȼ�Ϊ1
#define UR4_MEM_SET_RX_BUS_PRIORITY_2   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x02);}while(0)//����UART4��MEM�Ľ����������ȼ�Ϊ2
#define UR4_MEM_SET_RX_BUS_PRIORITY_3   do{DMA_UR4R_CFG=((DMA_UR4R_CFG&(~0x03))|0x03);}while(0)//����UART4��MEM�Ľ����������ȼ�Ϊ3
#define UR4_MEM_TX_ENABLE               do{DMA_UR4T_CR|= ENURT;}while(0)   //��MEM��UART4�ķ���ʹ��
#define UR4_MEM_TX_DISABLE              do{DMA_UR4T_CR&=~ENURT;}while(0)   //�ر�MEM��UART4�ķ���ʹ��
#define UR4_MEM_RX_ENABLE               do{DMA_UR4R_CR|= ENURR;}while(0)   //��UART4��MEM�Ľ���ʹ��
#define UR4_MEM_RX_DISABLE              do{DMA_UR4R_CR&=~ENURR;}while(0)   //�ر�UART4��MEM�Ľ���ʹ��
#define UR4_MEM_TX_START                do{DMA_UR4T_CR|= URTTRIG;}while(0) //��ʼһ��MEM��UART4�Ĵ���
#define UR4_MEM_RX_START                do{DMA_UR4R_CR|= URRTRIG;}while(0) //��ʼһ��UART4��MEM�Ĵ���
#define UR4_MEM_GET_TX_FLAG             (DMA_UR4T_STA & URTIF)             //��ȡMEM��UART4���жϱ�־λ
#define UR4_MEM_GET_TX_FLAG_TXOVW       (DMA_UR4T_STA & URTXOVW)           //��ȡMEM��UART4�ĸ��Ǳ�־λ
#define UR4_MEM_GET_RX_FLAG             (DMA_UR4R_STA & URRIF)             //��ȡUART4��MEM���жϱ�־λ
#define UR4_MEM_GET_RX_FLAG_RXOVW       (DMA_UR4R_STA & URRXOVW)           //��ȡUART4��MEM�ĸ��Ǳ�־λ
#define UR4_MEM_CLS_TX_FLAG             do{DMA_UR4T_STA&=~URTIF;}while(0)  //���MEM��UART4���жϱ�־λ
#define UR4_MEM_CLS_TX_FLAG_TXOVW       do{DMA_UR4T_STA&=~URTXOVW;}while(0)//���MEM��UART4�ĸ��Ǳ�־λ
#define UR4_MEM_CLS_RX_FLAG             do{DMA_UR4R_STA&=~URRIF;}while(0)  //���UART4��MEM���жϱ�־λ
#define UR4_MEM_CLS_RX_FLAG_RXOVW       do{DMA_UR4R_STA&=~URRXOVW;}while(0)//���UART4��MEM�ĸ��Ǳ�־λ
#define UR4_MEM_SET_TX_COUNT_MAX(value) do{DMA_UR4T_AMT=(u8)(value);}while(0)//����MEM��UART4�������ֽ���
#define UR4_MEM_GET_TX_COUNT_DONE       (DMA_UR4T_DONE)                //��ȡMEM��UART4�Ѿ����͵��ֽ���
#define UR4_MEM_SET_RX_COUNT_MAX(value) do{DMA_UR4R_AMT=(u8)(value);}while(0)//����UART4��MEM�������ֽ���
#define UR4_MEM_GET_RX_COUNT_DONE       (DMA_UR4R_DONE)                //��ȡUART4��MEM�Ѿ����յ��ֽ���
#define UR4_MEM_SET_TX_ADDR(value)      do{DMA_UR4T_TXA=(u16)(value);}while(0)//����MEM��UART4�ķ��͵�ַ
#define UR4_MEM_SET_RX_ADDR(value)      do{DMA_UR4R_RXA=(u16)(value);}while(0)//����UART4��MEM�Ľ��յ�ַ
#define LCM_MEM_IT_ENABLE               do{DMA_LCM_CFG|= LCMIE;}while(0)   //��MEM��LCM���ж�
#define LCM_MEM_IT_DISABLE              do{DMA_LCM_CFG&=~LCMIE;}while(0)   //�ر�MEM��LCM���ж�
#define LCM_MEM_SET_IT_PRIORITY_0       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x00);}while(0)//����MEM��LCM���ж����ȼ�Ϊ0
#define LCM_MEM_SET_IT_PRIORITY_1       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x04);}while(0)//����MEM��LCM���ж����ȼ�Ϊ1
#define LCM_MEM_SET_IT_PRIORITY_2       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x08);}while(0)//����MEM��LCM���ж����ȼ�Ϊ2
#define LCM_MEM_SET_IT_PRIORITY_3       do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x0C))|0x0C);}while(0)//����MEM��LCM���ж����ȼ�Ϊ3
#define LCM_MEM_SET_BUS_PRIORITY_0      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x00);}while(0)//����MEM��LCM���������ȼ�Ϊ0
#define LCM_MEM_SET_BUS_PRIORITY_1      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x01);}while(0)//����MEM��LCM���������ȼ�Ϊ0
#define LCM_MEM_SET_BUS_PRIORITY_2      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x02);}while(0)//����MEM��LCM���������ȼ�Ϊ0
#define LCM_MEM_SET_BUS_PRIORITY_3      do{DMA_LCM_CFG=((DMA_LCM_CFG&(~0x03))|0x03);}while(0)//����MEM��LCM���������ȼ�Ϊ0
#define LCM_MEM_ENABLE                  do{DMA_LCM_CR|= ENLCM;}while(0)   //��MEM��LCM����
#define LCM_MEM_DISABLE                 do{DMA_LCM_CR&=~ENLCM;}while(0)   //�ر�MEM��LCM����
#define LCM_MEM_START_TX_CMD            do{DMA_LCM_CR|= TRIGWC;}while(0)  //��ʼ��MEM����ָ�LCM
#define LCM_MEM_START_TX_DAT            do{DMA_LCM_CR|= TRIGWD;}while(0)  //��ʼ��MEM�������ݵ�LCM
#define LCM_MEM_START_RX_CMD            do{DMA_LCM_CR|= TRIGRC;}while(0)  //��ʼ��LCM��ȡָ�MEM
#define LCM_MEM_START_RX_DAT            do{DMA_LCM_CR|= TRIGRD;}while(0)  //��ʼ��LCM��ȡ���ݵ�MEM
#define LCM_MEM_GET_FLAG                (DMA_LCM_STA & LCMIF)             //��ȡMEM��LCM���жϱ�־λ
#define LCM_MEM_GET_FLAG_TXOVW          (DMA_LCM_STA & LCMTXOVW)          //��ȡMEM��LCM�����ݸ��Ǳ�־λ
#define LCM_MEM_CLS_FLAG                (DMA_LCM_STA&=~LCMIF)             //���MEM��LCM���жϱ�־λ
#define LCM_MEM_CLS_FLAG_TXOVW          (DMA_LCM_STA&=~LCMTXOVW)          //���MEM��LCM�����ݸ��Ǳ�־λ
#define LCM_MEM_SET_COUNT_MAX(value)    do{DMA_LCM_AMT=(u8)(value);}while(0)//����MEM��LCM������ֽ���
#define LCM_MEM_GET_COUNT_DONE          (DMA_LCM_DONE)                   //��ȡMEM��LCM���Ѵ�������ֽ���
#define LCM_MEM_SET_TX_ADDR(value)      do{DMA_LCM_TXA=(u16)(value);}while(0)//����MEM��LCM�ķ��͵�ַ
#define LCM_MEM_SET_RX_ADDR(value)      do{DMA_LCM_RXA=(u16)(value);}while(0)//����LCM��MEM�Ľ��յ�ַ
/*------------------------------15λPWM���⹦�ܼĴ���----------------------------*/
#define PWMRST                      0x40//PWM����λ
#define ENPWM                       0x01//PWMʹ��λ
#define PWMCBIF                     0x08//PWM�����������жϱ�־λ
#define EPWMCBI                     0x04//PWM�����������ж�ʹ��λ 
#define EPWMTA                      0x02//PWM��ADC����λ
#define PWMCEN                      0x01//PWM������ʼλ
#define INVCMP                      0x80//PWM�쳣����бȽ����������λ
#define INVIO                       0x40//PWM�쳣�����IO�źſ���λ
#define ENFD                        0x20//PWM�쳣������λ
#define FLTFLIO                     0x10//PWM�����쳣ʱ��PWM����ڿ���λ
#define EFDI                        0x08//PWM�쳣����ж�ʹ��λ
#define FDCMP                       0x04//PWM�쳣���ʹ�ñȽ������ʹ��λ
#define FDIO                        0x02//PWM�쳣���ʹ��IO���ʹ��λ
#define FDIF                        0x01//PWM�쳣����жϱ�־λ
#define SELT2                       0x10//PWMʱ��Դѡ��
#define ENO                         0x80//PWM���ʹ��λ
#define INI                         0x40//PWM��ʼ��ƽ����λ
#define ENI                         0x04//PWMͨ���ж�ʹ��λ
#define ENT2I                       0x02//PWMͨ���ڵڶ������ж�ʹ��λ
#define ENT1I                       0x01//PWMͨ���ڵ�һ�����ж�ʹ��λ
#define PWM_EN                      0x80//PWMʹ�ܲ���ʼ������STC8A��ͨ�棩
//-------------����ָ��------------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8Aȫϵ��
#define PWM15_SET_CLK_TIMER2        do{PWMCKS=SELT2;}while(0)
#define PWM15_SET_CLK_SYS(value)    do{PWMCKS=((u8)(value)&0x0F);}while(0)

#define PWM15_SET_CH0_IO_P20        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x00);}while(0)//PWMͨ��0�������л���P20
#define PWM15_SET_CH0_IO_P10        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x08);}while(0)//PWMͨ��0�������л���P10
#define PWM15_SET_CH0_IO_P60        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x10);}while(0)//PWMͨ��0�������л���P60
#define PWM15_SET_CH1_IO_P21        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x00);}while(0)//PWMͨ��1�������л���P21
#define PWM15_SET_CH1_IO_P11        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x08);}while(0)//PWMͨ��1�������л���P11
#define PWM15_SET_CH1_IO_P61        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x10);}while(0)//PWMͨ��1�������л���P61
#define PWM15_SET_CH2_IO_P22        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x00);}while(0)//PWMͨ��2�������л���P22
#define PWM15_SET_CH2_IO_P12        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x08);}while(0)//PWMͨ��2�������л���P12
#define PWM15_SET_CH2_IO_P62        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x10);}while(0)//PWMͨ��2�������л���P62
#define PWM15_SET_CH3_IO_P23        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x00);}while(0)//PWMͨ��3�������л���P23
#define PWM15_SET_CH3_IO_P13        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x08);}while(0)//PWMͨ��3�������л���P13
#define PWM15_SET_CH3_IO_P63        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x10);}while(0)//PWMͨ��3�������л���P63
#define PWM15_SET_CH4_IO_P24        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x00);}while(0)//PWMͨ��4�������л���P24
#define PWM15_SET_CH4_IO_P14        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x08);}while(0)//PWMͨ��4�������л���P14
#define PWM15_SET_CH4_IO_P64        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x10);}while(0)//PWMͨ��4�������л���P64
#define PWM15_SET_CH5_IO_P25        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x00);}while(0)//PWMͨ��5�������л���P25
#define PWM15_SET_CH5_IO_P15        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x08);}while(0)//PWMͨ��5�������л���P15
#define PWM15_SET_CH5_IO_P65        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x10);}while(0)//PWMͨ��5�������л���P65
#define PWM15_SET_CH6_IO_P26        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x00);}while(0)//PWMͨ��6�������л���P26
#define PWM15_SET_CH6_IO_P16        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x08);}while(0)//PWMͨ��6�������л���P16
#define PWM15_SET_CH6_IO_P66        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x10);}while(0)//PWMͨ��6�������л���P66
#define PWM15_SET_CH7_IO_P27        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x00);}while(0)//PWMͨ��7�������л���P27
#define PWM15_SET_CH7_IO_P17        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x08);}while(0)//PWMͨ��7�������л���P17
#define PWM15_SET_CH7_IO_P67        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x10);}while(0)//PWMͨ��7�������л���P67

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
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
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
#elif   ((ECBM_MCU&0xF0F000)==0x200000)   //��STC8A8K64D4�����STC8A
#define PWM15_RESET                 do{}while(0)
#define PWM15_POWER_ON              do{}while(0)
#define PWM15_POWER_OFF             do{}while(0)
#define PWM15_START                 do{PWMCR|= PWM_EN;}while(0)
#define PWM15_STOP                  do{PWMCR&=~PWM_EN;}while(0)
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
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


//-------------�Ĵ�����ȡ----------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8Aȫϵ��
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

#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
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
/*--------------------------------RTC���⹦�ܼĴ���------------------------------*/
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
//-------------����ָ��------------//
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
//-------------�Ĵ�����ȡ----------//
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
/*--------------------------------LED���⹦�ܼĴ���------------------------------*/
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
//-------------����ָ��------------//
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
//-------------�Ĵ�����ȡ----------//
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
/*--------------------------------LCD���⹦�ܼĴ���------------------------------*/
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
//-------------����ָ��------------//
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
//-------------�Ĵ�����ȡ----------//
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
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��