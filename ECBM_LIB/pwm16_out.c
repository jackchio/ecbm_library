#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_PWM16_OUT_LIB_EN)      //检查本库有没有被使能
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_MCU!=0x4805C4)
#error "本库只适用于STC8H8K64U,其他型号的PWM原理和寄存器不同不能使用!"
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
高级16位PWM的初始化函数。
-------------------------------------------------------*/
void pwm16_out_init(void){
    PWMA_PS   =ECBM_PWM16_OUT_GROUPA_PIN_SEL;       //设置PWM输出引脚位置。
    PWMA_ETRPS=ECBM_PWM16_OUT_GROUPA_EXT_PIN_SEL;   //设置外部触发引脚。
    PWMA_ENO  =ECBM_PWM16_OUT_GROUPA_PIN_EN;        //设置PWM输出引脚使能。
    PWMA_IOAUX=ECBM_PWM16_OUT_GROUPA_IOAUX;         //设置刹车功能覆盖的引脚。
    PWMA_PSCR =ECBM_PWM16_OUT_GROUPA_FREQ;          //设置预分频。
    PWMA_ARR  =ECBM_PWM16_OUT_GROUPA_ARR;           //设置计数值，和预分频共同决定了频率。
    PWMA_CCR1 =ECBM_PWM16_OUT_GROUPA_CH1_DUTY;      //设置通道1比较值。
    PWMA_CCR2 =ECBM_PWM16_OUT_GROUPA_CH2_DUTY;      //设置通道2比较值。
    PWMA_CCR3 =ECBM_PWM16_OUT_GROUPA_CH3_DUTY;      //设置通道3比较值。
    PWMA_CCR4 =ECBM_PWM16_OUT_GROUPA_CH4_DUTY;      //设置通道4比较值。
    PWMA_DTR  =ECBM_PWM16_OUT_GROUPA_DTR;           //设置死区时间。
    PWMA_OISR =ECBM_PWM16_OUT_GROUPA_PIN_OIS;       //设置空闲状态的输出电平。
    PWMA_CCER1=ECBM_PWM16_OUT_GROUPA_PIN12_POL;     //设置通道1和通道2的极性。
    PWMA_CCER2=ECBM_PWM16_OUT_GROUPA_PIN34_POL;     //设置通道3和通道4的极性。
    PWMA_BKR  =ECBM_PWM16_OUT_GROUPA_BKR;           //使能主输出且设置刹车。
    PWMA_CR1  =ECBM_PWM16_OUT_GROUPA_CR1;           //设置运行模式。

    PWMB_PS   =ECBM_PWM16_OUT_GROUPB_PIN_SEL;       //设置PWM输出引脚位置。
    PWMB_ETRPS=ECBM_PWM16_OUT_GROUPB_EXT_PIN_SEL;   //设置外部触发引脚。
    PWMB_ENO  =ECBM_PWM16_OUT_GROUPB_PIN_EN;        //设置PWM输出引脚使能。
    PWMB_IOAUX=ECBM_PWM16_OUT_GROUPB_IOAUX;         //设置刹车功能覆盖的引脚。
    PWMB_PSCR =ECBM_PWM16_OUT_GROUPB_FREQ;          //设置预分频。
    PWMB_ARR  =ECBM_PWM16_OUT_GROUPB_ARR;           //设置计数值，和预分频共同决定了频率。
    PWMB_CCR5 =ECBM_PWM16_OUT_GROUPB_CH5_DUTY;      //设置通道5比较值。
    PWMB_CCR6 =ECBM_PWM16_OUT_GROUPB_CH6_DUTY;      //设置通道6比较值。
    PWMB_CCR7 =ECBM_PWM16_OUT_GROUPB_CH7_DUTY;      //设置通道7比较值。
    PWMB_CCR8 =ECBM_PWM16_OUT_GROUPB_CH8_DUTY;      //设置通道8比较值。
    PWMB_DTR  =ECBM_PWM16_OUT_GROUPB_DTR;           //设置死区时间。
    PWMB_OISR =ECBM_PWM16_OUT_GROUPB_PIN_OIS;       //设置空闲状态的输出电平。
    PWMB_CCER1=ECBM_PWM16_OUT_GROUPB_PIN56_POL;     //设置通道5和通道6的极性。
    PWMB_CCER2=ECBM_PWM16_OUT_GROUPB_PIN78_POL;     //设置通道7和通道8的极性。
    PWMB_BKR  =ECBM_PWM16_OUT_GROUPB_BKR;           //使能主输出且设置刹车。
    PWMB_CR1  =ECBM_PWM16_OUT_GROUPB_CR1;           //设置运行模式。
}
/*-------------------------------------------------------
高级16位PWMA组和B组的启动函数。
-------------------------------------------------------*/
void pwm16_out_groupa_start(void){
    PWMA_BKR|=0x80;//打开PWM模块的输出使能
    PWMA_CR1|=0x01;//启动计时器
}
void pwm16_out_groupb_start(void){
    PWMB_BKR|=0x80;//打开PWM模块的输出使能
    PWMB_CR1|=0x01;//启动计时器
}
/*-------------------------------------------------------
高级16位PWMA组和B组的停止函数。
-------------------------------------------------------*/
void pwm16_out_groupa_stop(void){
    PWMA_CR1&=~0x01;//停止计时器
    PWMA_BKR&=~0x80;//关闭PWM模块的输出使能
}
void pwm16_out_groupb_stop(void){
    PWMB_CR1&=~0x01;//停止计时器
    PWMB_BKR&=~0x80;//关闭PWM模块的输出使能
}
/*-------------------------------------------------------
高级16位PWM的频率设置函数。
-------------------------------------------------------*/
void pwm16_out_set_freq(u8 ch,u32 freq){
    u32 temp,temp2,temp3;
    if(freq){//频率必须在1Hz以上，否则就不能改寄存器。
        temp=(ECBM_SYSCLK_SETTING/freq);    //初步计算频率之比，
        if(temp>=65535UL){                  //如果频率太大，则分频。
            temp2=temp/65535UL;             //以ARR为最大值来计算，得到一个最小的预分频值。
            temp3=temp/(temp2+1);           //求出预分频之后的ARR值，但要注意寄存器里的值和实际的分频效果差1，所以要加回来。
        }else{                              //如果频率太小，则不分频。
            temp2=0;                        //设置预分频为0，就是1分频，或不分频的意思。
            temp3=temp;                     //不分频的话，上面求到值直接就可以给到ARR寄存器。
        }
        if(temp3){                          //上面说了，ARR也和预分频寄存器一样，实际效果和寄存器值差1。
            temp3--;                        //但是为了防止偶发的情况，一定得大于0才能减一。
        }                                   //否则0-1就得到一个极大值(无符号数的极大值=有符号数的负一)。
        if(ch<=4){                          //如果通道号小于等于4，则修改A组的预分频值。
            PWMA_PSCR=(u16)(temp2);         //设置A组预分频。
            PWMA_ARR =(u16)(temp3);         //设置A组ARR值。
        }else if(ch<=8){                    //如果通道号大于4小于等于8，则修改B组的预分频值。
            PWMB_PSCR=(u16)(temp2);         //设置B组预分频。
            PWMB_ARR =(u16)(temp3);         //设置B组ARR值。
        }
    }
}
/*-------------------------------------------------------
高级16位PWM的频率设置函数。
-------------------------------------------------------*/
void pwm16_out_set_duty(u8 ch,u16 ch_duty){
    u16 arr_temp,ccmr_temp;
    if(ch_duty==0){             //如果占空比是0%的话，
        ccmr_temp=0x40;         //设置强制输出低电平。
        arr_temp=0;             //清零寄存器，防止意外动作。
    }else if(ch_duty>=10000){   //如果占空比是100%的话，
        ccmr_temp=0x50;         //设置强制输出高电平。
        arr_temp=0;             //清零寄存器，防止意外动作。
    }else{                      //除了0%和100%以外的占空比，
        ccmr_temp=0x60;         //设置为PWM模式1，
        if(ch<=4){              //如果通道号小于等于4，
            arr_temp=(u16)((u32)(PWMA_ARR)*(u32)(ch_duty)/10000UL);//用A组的ARR计算出该占空比对应的值。
        }else if(ch<=8){        //如果通道号大于4小于等于8，
            arr_temp=(u16)((u32)(PWMB_ARR)*(u32)(ch_duty)/10000UL);//用B组的ARR计算出该占空比对应的值。
        }
    }
    switch(ch){//根据通道将值写入对应的寄存器。
        case 1:{PWMA_CCMR1=ccmr_temp;PWMA_CCR1=arr_temp;}break;
        case 2:{PWMA_CCMR2=ccmr_temp;PWMA_CCR2=arr_temp;}break;
        case 3:{PWMA_CCMR3=ccmr_temp;PWMA_CCR3=arr_temp;}break;
        case 4:{PWMA_CCMR4=ccmr_temp;PWMA_CCR4=arr_temp;}break;
        case 5:{PWMB_CCMR1=ccmr_temp;PWMB_CCR5=arr_temp;}break;
        case 6:{PWMB_CCMR2=ccmr_temp;PWMB_CCR6=arr_temp;}break;
        case 7:{PWMB_CCMR3=ccmr_temp;PWMB_CCR7=arr_temp;}break;
        case 8:{PWMB_CCMR4=ccmr_temp;PWMB_CCR8=arr_temp;}break;
    }
}
/*-------------------------------------------------------
高级16位PWM的启动函数（以可数脉冲的模式启动）。
-------------------------------------------------------*/
void pwm16_out_pulse_start(u8 ch,u8 ch_count){
    if(ch_count){//如果发出的脉冲数是0，则不启动。
        switch(ch){//设置对应的通道的工作模式和占空比，占空比恒定为50%。
            case 1:{PWMA_CCMR1=0x60;PWMA_CCR1=PWMA_ARR>>1;}break;
            case 2:{PWMA_CCMR2=0x60;PWMA_CCR2=PWMA_ARR>>1;}break;
            case 3:{PWMA_CCMR3=0x60;PWMA_CCR3=PWMA_ARR>>1;}break;
            case 4:{PWMA_CCMR4=0x60;PWMA_CCR4=PWMA_ARR>>1;}break;
            case 5:{PWMB_CCMR1=0x60;PWMB_CCR5=PWMB_ARR>>1;}break;
            case 6:{PWMB_CCMR2=0x60;PWMB_CCR6=PWMB_ARR>>1;}break;
            case 7:{PWMB_CCMR3=0x60;PWMB_CCR7=PWMB_ARR>>1;}break;
            case 8:{PWMB_CCMR4=0x60;PWMB_CCR8=PWMB_ARR>>1;}break;
        }
        if(ch<=4){                      //如果通道号小于等于4，
            PWMA_CR1|=0x08;             //确保单脉冲模式已经开启。
            PWMA_RCR=ch_count-1;        //装填脉冲数。
            pwm16_out_groupa_start();   //启动PWM。
        }else if(ch<=8){                //如果通道号大于4小于等于8，
            PWMB_CR1|=0x08;             //确保单脉冲模式已经开启。
            PWMB_RCR=ch_count-1;        //装填脉冲数。
            pwm16_out_groupb_start();   //启动PWM。
        }
    }
}
/*-------------------------------------------------------
高级16位PWMA组的启动函数（以波形输出的模式启动）。
-------------------------------------------------------*/
void pwm16_out_wave_start(u8 ch,u16 ch_duty){
    pwm16_out_set_duty(ch,ch_duty); //设置占空比。
    if(ch<=4){                      //如果通道号小于等于4，
        PWMA_CR1&=~0x08;            //确保单脉冲模式已经开启。
        pwm16_out_groupa_start();   //启动PWM。
    }else if(ch<=8){                //如果通道号大于4小于等于8，
        PWMB_CR1&=~0x08;            //确保单脉冲模式已经开启。
        pwm16_out_groupb_start();   //启动PWM。
    }
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。