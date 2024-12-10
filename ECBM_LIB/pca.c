#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_PCA_LIB_EN)      //检查本库有没有被使能
/*------------------------------------资源冲突警告---------------------------------*/
#if  ((ECBM_MCU&0xF00000)==0x400000)
#   error STC8H有更高级的PWM模块，所以取消了PCA功能。
#endif
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_PCA0_EN)
    u8  pca_mode_0_gu8=0;
    u16 pca_timer_count_0_gu16=0;
    u16 pca_timer_add_0_gu16=0;
#endif
#if (ECBM_PCA1_EN)
    u8  pca_mode_1_gu8=0;
    u16 pca_timer_count_1_gu16=0;
    u16 pca_timer_add_1_gu16=0;
#endif
#if (ECBM_PCA2_EN)
    u8  pca_mode_2_gu8=0;
    u16 pca_timer_count_2_gu16=0;
    u16 pca_timer_add_2_gu16=0;
#endif
#if (ECBM_PCA3_EN)
    u8  pca_mode_3_gu8=0;
    u16 pca_timer_count_3_gu16=0;
    u16 pca_timer_add_3_gu16=0;
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
PCA初始化置函数。
-------------------------------------------------------*/
void pca_init(){
    PCA_SET_REG_CCON(0);//初始化PCA控制寄存器。
    PCA_SET_REG_CHL(0); //复位PCA寄存器。
    PCA_SET_REG_CMOD(ECBM_PCA_CMOD);//设置PCA的工作模式。
    
    pca_set_io(ECBM_PCA_IO);
    
    #if (ECBM_PCA0_EN)
        pca_set_mode(0,ECBM_PCA0_MODE);
    #endif
    #if (ECBM_PCA1_EN)
        pca_set_mode(1,ECBM_PCA1_MODE);
    #endif
    #if (ECBM_PCA2_EN)
        pca_set_mode(2,ECBM_PCA2_MODE);
    #endif
    #if (ECBM_PCA3_EN)
        pca_set_mode(3,ECBM_PCA3_MODE);
    #endif
    PCA_POWER_ON;//打开PCA。
}
/*-------------------------------------------------------
PCA设置IO映射函数。
-------------------------------------------------------*/
void pca_set_io(u8 io){
    PCA_SET_PIN(io);
    #if ((ECBM_MCU&0xF00000)==0x200000)
        switch(io){
            case PCA_PIN_P12_P17_P16_P15_P14:{
                gpio_mode(D12,GPIO_IN);
                gpio_mode(D17,GPIO_IN);
                gpio_mode(D16,GPIO_IN);
                gpio_mode(D15,GPIO_IN);
                gpio_mode(D14,GPIO_IN);
            }break;
            case PCA_PIN_P22_P23_P24_P25_P26:{
                gpio_mode(D22,GPIO_IN);
                gpio_mode(D23,GPIO_IN);
                gpio_mode(D24,GPIO_IN);
                gpio_mode(D25,GPIO_IN);
                gpio_mode(D26,GPIO_IN);
            }break;
            case PCA_PIN_P74_P70_P71_P72_P73:{
                gpio_mode(D74,GPIO_IN);
                gpio_mode(D70,GPIO_IN);
                gpio_mode(D71,GPIO_IN);
                gpio_mode(D72,GPIO_IN);
                gpio_mode(D73,GPIO_IN);
            }break;
            case PCA_PIN_P35_P33_P32_P31_P30:{
                gpio_mode(D35,GPIO_IN);
                gpio_mode(D33,GPIO_IN);
                gpio_mode(D32,GPIO_IN);
                gpio_mode(D31,GPIO_IN);
                gpio_mode(D30,GPIO_IN);
            }break;
            default:break;
        }
    #endif
    
    #if (ECBM_MCU==0x3102A1)//STC8G1KxxA_8PIN
        switch(io){
            case PCA_PIN_P55_P32_P33_P54:{
                gpio_mode(D55,GPIO_IN);
                gpio_mode(D32,GPIO_IN);
                gpio_mode(D33,GPIO_IN);
                gpio_mode(D54,GPIO_IN);
            }break;
            case PCA_PIN_P55_P31_P33_P54:{
                gpio_mode(D55,GPIO_IN);
                gpio_mode(D31,GPIO_IN);
                gpio_mode(D33,GPIO_IN);
                gpio_mode(D54,GPIO_IN);
            }break;
            case PCA_PIN_P31_P32_P33_P55:{
                gpio_mode(D31,GPIO_IN);
                gpio_mode(D32,GPIO_IN);
                gpio_mode(D33,GPIO_IN);
                gpio_mode(D55,GPIO_IN);
            }break;
            default:break;
        }
    #elif (ECBM_MCU==0x3103A1)//STC8G1KxxT_20PIN
        switch(io){
            case PCA_PIN_P13_P11_P10_P37:{
                gpio_mode(D13,GPIO_IN);
                gpio_mode(D11,GPIO_IN);
                gpio_mode(D10,GPIO_IN);
                gpio_mode(D37,GPIO_IN);
            }break;
            case PCA_PIN_P34_P35_P36_P37:{
                gpio_mode(D34,GPIO_IN);
                gpio_mode(D35,GPIO_IN);
                gpio_mode(D36,GPIO_IN);
                gpio_mode(D37,GPIO_IN);
            }break;
            case PCA_PIN_P54_P13_P14_P15:{
                gpio_mode(D54,GPIO_IN);
                gpio_mode(D13,GPIO_IN);
                gpio_mode(D14,GPIO_IN);
                gpio_mode(D15,GPIO_IN);
            }break;
            default:break;
        }    
    #else
        switch(io){
            case PCA_PIN_P12_P11_P10_P37:{
                gpio_mode(D12,GPIO_IN);
                gpio_mode(D11,GPIO_IN);
                gpio_mode(D10,GPIO_IN);
                gpio_mode(D37,GPIO_IN);
            }break;
            case PCA_PIN_P34_P35_P36_P37:{
                gpio_mode(D34,GPIO_IN);
                gpio_mode(D35,GPIO_IN);
                gpio_mode(D36,GPIO_IN);
                gpio_mode(D37,GPIO_IN);
            }break;
            case PCA_PIN_P24_P25_P26_P27:{
                gpio_mode(D24,GPIO_IN);
                gpio_mode(D25,GPIO_IN);
                gpio_mode(D26,GPIO_IN);
                gpio_mode(D27,GPIO_IN);
            }break;
            default:break;
        }    
    #endif
}
/*-------------------------------------------------------
PCA在PWM模式下的占空比设置函数。
-------------------------------------------------------*/
void pca_set_mode(u8 id,u8 mode){
    u8 pca_pwmx_u8,pca_ccapmx_u8;
    switch(mode){
        case 0:{
            
        }break;
        case 1:{//6位PWM模式
            pca_pwmx_u8=0x80;
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_PWMn_1;
        }break;
        case 2:{//7位PWM模式
            pca_pwmx_u8=0x40;
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_PWMn_1;
        }break;
        case 3:{//8位PWM模式
            pca_pwmx_u8=0x00;
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_PWMn_1;
        }break;
        case 4:{//10位PWM模式
            pca_pwmx_u8=0xC0;
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_PWMn_1;
        }break;
        case 5:{//16位捕获模式
            switch(id){
                case 0:pca_ccapmx_u8=ECBM_PCA0_UP_DOWN|0x01;break;
                case 1:pca_ccapmx_u8=ECBM_PCA1_UP_DOWN|0x01;break;
                case 2:pca_ccapmx_u8=ECBM_PCA2_UP_DOWN|0x01;break;
                case 3:pca_ccapmx_u8=ECBM_PCA3_UP_DOWN|0x01;break;
            }
        }break;
        case 6:{//16位软件定时器
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_MATn_1|0x01;
        }break;
        case 7:{//16位高速脉冲输出
            pca_ccapmx_u8=PCA_ECOMn_1|PCA_MATn_1|PCA_TOGn_1|0x01;
        }break;
    }
    switch(id){
        #if (ECBM_PCA0_EN)
            case 0:{
                pca_mode_0_gu8=mode;
                if((mode>0)&&(mode<5)){
                    PCA_SET_REG_PWM0(pca_pwmx_u8);
                }
                PCA_SET_REG_CCAPM0(pca_ccapmx_u8);
                PCA_SET_REG_CCAP0HL(0);
            }break;
        #endif
        #if (ECBM_PCA1_EN)
            case 1:{
                pca_mode_1_gu8=mode;
                if((mode>0)&&(mode<5)){
                    PCA_SET_REG_PWM1(pca_pwmx_u8);
                }
                PCA_SET_REG_CCAPM1(pca_ccapmx_u8);
                PCA_SET_REG_CCAP1HL(0); 
            }break;
        #endif
        #if (ECBM_PCA2_EN)
            case 2:{
                pca_mode_2_gu8=mode;
                if((mode>0)&&(mode<5)){
                    PCA_SET_REG_PWM2(pca_pwmx_u8);
                }
                PCA_SET_REG_CCAPM2(pca_ccapmx_u8);
                PCA_SET_REG_CCAP2HL(0);
            }break;
        #endif
        #if (ECBM_PCA3_EN)
            case 3:{
                pca_mode_3_gu8=mode;
                if((mode>0)&&(mode<5)){
                    PCA_SET_REG_PWM3(pca_pwmx_u8);
                }
                PCA_SET_REG_CCAPM3(pca_ccapmx_u8);
                PCA_SET_REG_CCAP3HL(0);
            }break;
        #endif
    }
}
/*-------------------------------------------------------
PCA在定时器模式或高速脉冲输出模式下的计数值设置函数
-------------------------------------------------------*/
void pca_set_timer(u8 id,u16 count){
    count=count;
    switch(id){
        #if (ECBM_PCA0_EN)
            case 0:{
                if(pca_mode_0_gu8>=6){
                    pca_timer_count_0_gu16=count;
                    pca_timer_add_0_gu16  =count;
                }
                PCA_SET_REG_CCAP0HL(pca_timer_count_0_gu16);
                pca_timer_count_0_gu16+=pca_timer_add_0_gu16;
            }break;
        #endif
        #if (ECBM_PCA1_EN)
            case 1:{
                if(pca_mode_1_gu8>=6){
                    pca_timer_count_1_gu16=count;
                    pca_timer_add_1_gu16  =count;
                }
                PCA_SET_REG_CCAP1HL(pca_timer_count_1_gu16);
                pca_timer_count_1_gu16+=pca_timer_add_1_gu16;
            }break;
        #endif
        #if (ECBM_PCA2_EN)
            case 2:{
                if(pca_mode_2_gu8>=6){
                    pca_timer_count_2_gu16=count;
                    pca_timer_add_2_gu16  =count;
                }
                PCA_SET_REG_CCAP2HL(pca_timer_count_2_gu16);
                pca_timer_count_2_gu16+=pca_timer_add_2_gu16;
            }break;
        #endif
        #if (ECBM_PCA3_EN)
            case 3:{
                if(pca_mode_3_gu8>=6){
                    pca_timer_count_3_gu16=count;
                    pca_timer_add_3_gu16  =count;
                }
                PCA_SET_REG_CCAP3HL(pca_timer_count_3_gu16);
                pca_timer_count_3_gu16+=pca_timer_add_3_gu16;
            }break;
        #endif
    }
}
/*-------------------------------------------------------
PCA在PWM模式下的占空比设置函数。
-------------------------------------------------------*/
void pca_set_duty(u8 id,u16 duty){
    u8 pcax,pcah=0,mode_u8;
    u16 temp_u16;
    switch(id){
        #if (ECBM_PCA0_EN)
            case 0:{mode_u8=pca_mode_0_gu8;}break;
        #endif
        #if (ECBM_PCA1_EN)
            case 1:{mode_u8=pca_mode_1_gu8;}break;
        #endif
        #if (ECBM_PCA2_EN)
            case 2:{mode_u8=pca_mode_2_gu8;}break;
        #endif
        #if (ECBM_PCA3_EN)
            case 3:{mode_u8=pca_mode_3_gu8;}break;
        #endif
    }
    if((mode_u8<=4)&&(mode_u8>0)){
        switch(mode_u8){
            case 1:{//6位PWM模式
                if(duty>=1000){
                    temp_u16=0;
                }else{
                    temp_u16=(u16)((64*(1000-(u32)duty))/1000);
                }
                pcax=(u8)(temp_u16&0x3F);
                if(temp_u16&0x0040){
                    pcah=0x02;
                }
            }break;
            case 2:{//7位PWM模式
                if(duty>=1000){
                    temp_u16=0;
                }else{
                    temp_u16=(u16)((128*(1000-(u32)duty))/1000);
                }
                pcax=(u8)(temp_u16&0x7F);
                if(temp_u16&0x0080){
                    pcah=0x02;
                }
            }break;
            case 3:{//8位PWM模式
                if(duty>=1000){
                    temp_u16=0;
                }else{
                    temp_u16=(u16)((256*(1000-(u32)duty))/1000);
                }
                pcax=(u8)(temp_u16);
                if(temp_u16&0x0100){
                    pcah=0x02;
                }
            }break;
            case 4:{//10位PWM模式
                if(duty>=1000){
                    temp_u16=0;
                }else{
                    temp_u16=(u16)((1024*(1000-(u32)duty))/1000);
                }
                pcax=(u8)(temp_u16);
                pcah=(u8)(temp_u16>>4)&0x30;
                if(temp_u16&0x0400){
                    pcah|=0x02;
                }
            }break;
        }
        switch(id){
            #if (ECBM_PCA0_EN)
                case 0:{
                    PCA_SET_REG_PWM0((PCA_GET_REG_PWM0&0xC0)|pcah);
                    PCA_SET_REG_CCAP0H(pcax);
                }break;
            #endif
            #if (ECBM_PCA1_EN)
                case 1:{
                    PCA_SET_REG_PWM1((PCA_GET_REG_PWM1&0xC0)|pcah);
                    PCA_SET_REG_CCAP1H(pcax);
                }break;
            #endif
            #if (ECBM_PCA2_EN)
                case 2:{
                    PCA_SET_REG_PWM2((PCA_GET_REG_PWM2&0xC0)|pcah);
                    PCA_SET_REG_CCAP2H(pcax);
                }break;
            #endif
            #if (ECBM_PCA3_EN)
                case 3:{
                    PCA_SET_REG_PWM3((PCA_GET_REG_PWM3&0xC0)|pcah);
                    PCA_SET_REG_CCAP3H(pcax);
                }break;
            #endif
        }
    }
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。