#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_TIMER_LIB_EN) //检查本库有没有被使能
/*------------------------------------资源冲突警告---------------------------------*/
//------------------------------------串口冲突警告---------------------------------//
#if (ECBM_UART_LIB_EN)//判断串口库是否调用。
#   if ((ECBM_UART1_EN)&&((ECBM_UART1_AUXR_CONFIG&0x01)==0)&&(ECBM_TIMER1_EN))
#       error 串口1和定时器1冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART1_EN)&&((ECBM_UART1_AUXR_CONFIG&0x01))&&(ECBM_TIMER2_EN))
#       error 串口1和定时器2冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART2_EN)&&(ECBM_TIMER2_EN))
#       error 串口2和定时器2冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART3_EN)&&((ECBM_UART3_S3CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN))
#       error 串口3和定时器2冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART3_EN)&&(ECBM_UART3_S3CON_CONFIG&0x40)&&(ECBM_TIMER3_EN))
#       error 串口3和定时器3冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART4_EN)&&((ECBM_UART4_S4CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN))
#       error 串口4和定时器2冲突，请换一个定时器使用！
#   endif
#   if ((ECBM_UART4_EN)&&(ECBM_UART4_S4CON_CONFIG&0x40)&&(ECBM_TIMER4_EN))
#       error 串口4和定时器4冲突，请换一个定时器使用！
#   endif
#endif
//----------------------------------定时器数量警告---------------------------------//
#if (((ECBM_MCU&0x000F00)<0x000300)&&(ECBM_TIMER2_EN))
#   error 该型号没有定时器2，请换一个定时器使用！
#endif
#if (((ECBM_MCU&0x000F00)<0x000400)&&(ECBM_TIMER3_EN))
#   error 该型号没有定时器3，请换一个定时器使用！
#endif
#if (((ECBM_MCU&0x000F00)<0x000500)&&(ECBM_TIMER4_EN))
#   error 该型号没有定时器4，请换一个定时器使用！
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
定时器开始函数。
-------------------------------------------------------*/
void timer_start(u8 id){
    switch(id){
        #if (ECBM_TIMER0_EN)
            case 0:{TIMER0_POWER_ON;}break;        
        #endif
        #if (ECBM_TIMER1_EN)
            case 1:{TIMER1_POWER_ON;}break;    
        #endif
        #if (ECBM_TIMER2_EN)
            case 2:{TIMER2_POWER_ON;}break;        
        #endif
        #if (ECBM_TIMER3_EN)
            case 3:{TIMER3_POWER_ON;}break;    
        #endif
        #if (ECBM_TIMER4_EN)
            case 4:{TIMER4_POWER_ON;}break;    
        #endif    
        default:break;
    }    
}
/*-------------------------------------------------------
定时器停止函数。
-------------------------------------------------------*/
void timer_stop(u8 id){
    switch(id){
        #if (ECBM_TIMER0_EN)
            case 0:{TIMER0_POWER_OFF;}break;        
        #endif
        #if (ECBM_TIMER1_EN)
            case 1:{TIMER1_POWER_OFF;}break;    
        #endif
        #if (ECBM_TIMER2_EN)
            case 2:{TIMER2_POWER_OFF;}break;        
        #endif
        #if (ECBM_TIMER3_EN)
            case 3:{TIMER3_POWER_OFF;}break;    
        #endif
        #if (ECBM_TIMER4_EN)
            case 4:{TIMER4_POWER_OFF;}break;    
        #endif    
        default:break;
    }    
}
/*-------------------------------------------------------
定时器输出控制函数。
-------------------------------------------------------*/
void timer_out(u8 id,u8 en){
    if(en){
        switch(id){
            #if (ECBM_TIMER0_EN)
                case 0:{TIMER0_OUT_ON;gpio_mode(D35,GPIO_OUT);}break;        
            #endif
            #if (ECBM_TIMER1_EN)
                case 1:{TIMER1_OUT_ON;gpio_mode(D34,GPIO_OUT);}break;    
            #endif
            #if (ECBM_TIMER2_EN)
                case 2:{TIMER2_OUT_ON;gpio_mode(D13,GPIO_OUT);}break;        
            #endif
            #if (ECBM_TIMER3_EN)
                case 3:{TIMER3_OUT_ON;gpio_mode(D05,GPIO_OUT);}break;    
            #endif
            #if (ECBM_TIMER4_EN)
                case 4:{TIMER4_OUT_ON;gpio_mode(D07,GPIO_OUT);}break;    
            #endif   
            default:break;
        }    
    }else{
        switch(id){
            #if (ECBM_TIMER0_EN)
                case 0:{TIMER0_OUT_OFF;gpio_mode(D35,GPIO_IN);}break;        
            #endif
            #if (ECBM_TIMER1_EN)
                case 1:{TIMER1_OUT_OFF;gpio_mode(D34,GPIO_IN);}break;    
            #endif
            #if (ECBM_TIMER2_EN)
                case 2:{TIMER2_OUT_OFF;gpio_mode(D13,GPIO_IN);}break;        
            #endif
            #if (ECBM_TIMER3_EN)
                case 3:{TIMER3_OUT_OFF;gpio_mode(D05,GPIO_IN);}break;    
            #endif
            #if (ECBM_TIMER4_EN)
                case 4:{TIMER4_OUT_OFF;gpio_mode(D07,GPIO_IN);}break;    
            #endif 
            default:break;
        }    
    }
}
/*-------------------------------------------------------
定时器初始化函数。
-------------------------------------------------------*/
void timer_init(void){
    #if (ECBM_TIMER0_EN)     //判断定时器0有没有使能。
        TIMER0_SET_REG_AUXR    (ECBM_TIMER0_AUXR);//写上设定的数据。
        TIMER0_SET_REG_TMOD    (ECBM_TIMER0_TMOD);//写上设定的数据。
        TIMER0_SET_REG_HL    (65536-ECBM_TIMER0_COUNT);//写入初值。
        #if (ECBM_TIMER0_IT_EN)    //如果开启了中断。
            TIMER0_IT_ENABLE;
        #endif
    #endif
    
    #if (ECBM_TIMER1_EN)     //判断定时器1有没有使能。
        TIMER1_SET_REG_AUXR(ECBM_TIMER1_AUXR);//写上设定的数据。
        TIMER1_SET_REG_TMOD(ECBM_TIMER1_TMOD);//写上设定的数据。
        TIMER1_SET_REG_HL(65536-ECBM_TIMER1_COUNT);//写入初值。
        #if (ECBM_TIMER1_IT_EN)  //如果开启了中断。
            TIMER1_IT_ENABLE;
        #endif
    #endif
    
    #if (ECBM_TIMER2_EN)     //判断定时器2有没有使能。
        TIMER2_SET_REG_AUXR    (ECBM_TIMER2_AUXR);//写上设定的数据。
        TIMER2_SET_REG_HL    (65536-ECBM_TIMER2_COUNT);//写入初值。
        #if (ECBM_TIMER2_IT_EN)   //如果开启了中断。
            TIMER2_IT_ENABLE;
        #endif
    #endif
        
    #if (ECBM_TIMER3_EN)     //判断定时器3有没有使能。
        TIMER3_SET_REG_T4T3M(ECBM_TIMER3_T4T3M);//写上设定的数据。
        TIMER3_SET_REG_HL    (65536-ECBM_TIMER3_COUNT);//写入初值。
        #if (ECBM_TIMER3_IT_EN)    //如果开启了中断。
            TIMER3_IT_ENABLE;
        #endif
    #endif

    #if (ECBM_TIMER4_EN)     //判断定时器4有没有使能。
        TIMER4_SET_REG_T4T3M(ECBM_TIMER4_T4T3M);//写上设定的数据。
        TIMER4_SET_REG_HL    (65536-ECBM_TIMER4_COUNT);//写入初值。
        #if (ECBM_TIMER4_IT_EN)    //如果开启了中断。
            TIMER4_IT_ENABLE;
        #endif
    #endif
}
/*-------------------------------------------------------
定时器设定定时模式函数。
-------------------------------------------------------*/
void timer_set_timer_mode(u8 id,u16 us){
    u16 n_u16,max_1T_u16,max_12T_u16,value_u16;
    if(us==0)return;
    max_1T_u16=(u16)(65535.0/((float)(ECBM_SYSCLK_SETTING)/1000000.0));
    #if (ECBM_SYSCLK_SETTING<=12000000UL)
        max_12T_u16=65535;
    #else
        max_12T_u16=(u16)(65535.0/((float)(ECBM_SYSCLK_SETTING)/12000000.0));
    #endif
    if(us<=max_1T_u16){
        n_u16=1;
        value_u16=65536-(u16)((float)us*((float)(ECBM_SYSCLK_SETTING)/1000000.0));
    }else if(us<=max_12T_u16){
        n_u16=12;
        value_u16=65536-(u16)((float)us*((float)(ECBM_SYSCLK_SETTING)/12.0/1000000.0));
    }
    switch(id){
        default:break;
        #if (ECBM_TIMER0_EN)
            case 0:{
                if(n_u16==1){
                    TIMER0_SET_MODE_1T;
                }else{
                    TIMER0_SET_MODE_12T;
                }
                TIMER0_SET_REG_HL(value_u16);
                TIMER0_SET_MODE_TIMER;
            }break;        
        #endif
        #if (ECBM_TIMER1_EN)
            case 1:{
                if(n_u16==1){
                    TIMER1_SET_MODE_1T;
                }else{
                    TIMER1_SET_MODE_12T;
                }
                TIMER1_SET_REG_HL(value_u16);
                TIMER1_SET_MODE_TIMER;
            }break;    
        #endif
        #if (ECBM_TIMER2_EN)
            case 2:{
                if(n_u16==1){
                    TIMER2_SET_MODE_1T;
                }else{
                    TIMER2_SET_MODE_12T;
                }
                TIMER2_SET_REG_HL(value_u16);
                TIMER2_SET_MODE_TIMER;
            }break;        
        #endif
        #if (ECBM_TIMER3_EN)
            case 3:{
                if(n_u16==1){
                    TIMER3_SET_MODE_1T;
                }else{
                    TIMER3_SET_MODE_12T;
                }
                TIMER3_SET_REG_HL(value_u16);
                TIMER3_SET_MODE_TIMER;
            }break;    
        #endif
        #if (ECBM_TIMER4_EN)
            case 4:{
                if(n_u16==1){
                    TIMER4_SET_MODE_1T;
                }else{
                    TIMER4_SET_MODE_12T;
                }
                TIMER4_SET_REG_HL(value_u16);
                TIMER4_SET_MODE_TIMER;
            }break;
        #endif  
    }
}
/*-------------------------------------------------------
定时器设定初值函数。
-------------------------------------------------------*/
void timer_set_value(u8 id,u16 value){
    value=value;
    switch(id){
        #if (ECBM_TIMER0_EN)
            case 0:{TIMER0_SET_REG_HL(value);}break;        
        #endif
        #if (ECBM_TIMER1_EN)
            case 1:{TIMER1_SET_REG_HL(value);}break;    
        #endif
        #if (ECBM_TIMER2_EN)
            case 2:{TIMER2_SET_REG_HL(value);}break;        
        #endif
        #if (ECBM_TIMER3_EN)
            case 3:{TIMER3_SET_REG_HL(value);}break;    
        #endif
        #if (ECBM_TIMER4_EN)
            case 4:{TIMER4_SET_REG_HL(value);}break;
        #endif   
        default:break;
    }
}
/*-------------------------------------------------------
定时器计数值获取函数。
-------------------------------------------------------*/
u16 timer_get_value(u8 id){
    u16 value_u16=0;
    switch(id){
        #if (ECBM_TIMER0_EN)
            case 0:{value_u16=TIMER0_GET_REG_HL;}break;        
        #endif
        #if (ECBM_TIMER1_EN) 
            case 1:{value_u16=TIMER1_GET_REG_HL;}break;    
        #endif
        #if (ECBM_TIMER2_EN)
            case 2:{value_u16=TIMER2_GET_REG_HL;}break;        
        #endif
        #if (ECBM_TIMER3_EN)
            case 3:{value_u16=TIMER3_GET_REG_HL;}break;    
        #endif
        #if (ECBM_TIMER4_EN)
            case 4:{value_u16=TIMER4_GET_REG_HL;}break;
        #endif   
        default:break;   
    }
    return value_u16;
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。