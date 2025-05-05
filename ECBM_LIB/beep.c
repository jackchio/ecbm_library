#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_BEEP_EN)      //检查本库有没有被使能
/*------------------------------------资源冲突警告---------------------------------*/
/*---------------------------------------宏定义------------------------------------*/
#define ECBM_BEEP_OFF       (0)//蜂鸣器关闭。
#define ECBM_BEEP_IDLE      (1)//蜂鸣器闲置（此时用户可以自由控制）。
#define ECBM_BEEP_AUTO_ON   (2)//蜂鸣器自动模式下的响状态。
#define ECBM_BEEP_AUTO_OFF  (3)//蜂鸣器自动模式下的关闭状态。
/*-------------------------------------引脚定义------------------------------------*/
sbit BEEP_IO=(ECBM_BEEP_IO_PORT+ECBM_BEEP_IO_PIN);
/*--------------------------------------变量定义-----------------------------------*/
u8 beep_on_time_gu8; //蜂鸣器响的时间变量。
u8 beep_off_time_gu8;//蜂鸣器不响的时间变量。
u8 beep_count_gu8;   //蜂鸣器响的次数变量。
u8 beep_time_gu8;    //蜂鸣器的计时变量。
u8 beep_state_gu8;   //蜂鸣器的状态变量。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
蜂鸣器初始化函数。
-------------------------------------------------------*/
void beep_init(void){
    BEEP_IO=!ECBM_BEEP_IO_WORK;//关闭蜂鸣器。
    #if   (ECBM_BEEP_IO_PORT==0x80)
        gpio_mode(D00+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0x90)
        gpio_mode(D10+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xA0)
        gpio_mode(D20+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xB0)
        gpio_mode(D30+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xC0)
        gpio_mode(D40+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xC8)
        gpio_mode(D50+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xE8)
        gpio_mode(D60+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #elif (ECBM_BEEP_IO_PORT==0xF8)
        gpio_mode(D70+ECBM_BEEP_IO_PIN,GPIO_OUT);
    #endif
    beep_on_time_gu8=ECBM_BEEP_ON_TIME_MAX;
    beep_off_time_gu8=ECBM_BEEP_OFF_TIME_MAX;
    beep_count_gu8=0;
    beep_time_gu8=0;
    beep_state_gu8=ECBM_BEEP_OFF;
}
/*-------------------------------------------------------
蜂鸣器运行函数。
-------------------------------------------------------*/
void beep_run(void){
    switch(beep_state_gu8){
        case ECBM_BEEP_OFF:{//关闭状态，
            BEEP_IO=!ECBM_BEEP_IO_WORK;//关闭蜂鸣器。
            if(beep_count_gu8){//如果此时蜂鸣次数不为0，则进入自动响状态。
                beep_time_gu8=0;//重置计时变量。
                beep_state_gu8=ECBM_BEEP_AUTO_ON;//进入自动响状态。
            }
        }break;
        case ECBM_BEEP_IDLE:{//闲置状态，
            //什么都不处理，交给用户。
        }break;
        case ECBM_BEEP_AUTO_ON:{//自动响状态，
            BEEP_IO=ECBM_BEEP_IO_WORK;//开启蜂鸣器。
            beep_time_gu8++;//计时开始。
            if(beep_time_gu8>=beep_on_time_gu8){//如果计时达到了预定时间，
                beep_time_gu8=0;//重置计时变量。
                beep_count_gu8--;//蜂鸣器次数减1。
                beep_state_gu8=ECBM_BEEP_AUTO_OFF;//进入自动关闭状态。
            }
        }break;
        case ECBM_BEEP_AUTO_OFF:{//自动关闭状态，
            BEEP_IO=!ECBM_BEEP_IO_WORK;//关闭蜂鸣器。
            beep_time_gu8++;//计时开始。
            if(beep_time_gu8>=beep_off_time_gu8){//如果计时达到了预定时间，
                beep_time_gu8=0;//重置计时变量。
                if(beep_count_gu8){//如果蜂鸣次数不为0，
                    beep_state_gu8=ECBM_BEEP_AUTO_ON;//则进入自动响状态。
                }else{//如果蜂鸣次数为0，
                    beep_state_gu8=ECBM_BEEP_OFF;//进入关闭状态。
                }
            }
        }
    }
}
/*-------------------------------------------------------
蜂鸣器修改样式函数。
-------------------------------------------------------*/
void beep_set_class(u8 on_time,u8 off_time){
    beep_on_time_gu8=on_time;
    beep_off_time_gu8=off_time;
}
/*-------------------------------------------------------
蜂鸣器响函数。
-------------------------------------------------------*/
void beep_start(u8 count){
    beep_count_gu8=count;//设置蜂鸣次数。
    if(beep_state_gu8==ECBM_BEEP_IDLE){//如果当前状态为闲置状态，
        beep_state_gu8=ECBM_BEEP_OFF;//进入关闭状态，然后靠蜂鸣次数启动蜂鸣器。
    }
}
/*-------------------------------------------------------
蜂鸣器空闲函数。
-------------------------------------------------------*/
void beep_idle(void){
    beep_state_gu8=ECBM_BEEP_IDLE;
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。