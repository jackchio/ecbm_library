#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_TIMER_LIB_EN) //��鱾����û�б�ʹ��
/*------------------------------------��Դ��ͻ����---------------------------------*/
//------------------------------------���ڳ�ͻ����---------------------------------//
#if (ECBM_UART_LIB_EN)//�жϴ��ڿ��Ƿ���á�
#   if ((ECBM_UART1_EN)&&((ECBM_UART1_AUXR_CONFIG&0x01)==0)&&(ECBM_TIMER1_EN))
#       error ����1�Ͷ�ʱ��1��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART1_EN)&&((ECBM_UART1_AUXR_CONFIG&0x01))&&(ECBM_TIMER2_EN))
#       error ����1�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART2_EN)&&(ECBM_TIMER2_EN))
#       error ����2�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART3_EN)&&((ECBM_UART3_S3CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN))
#       error ����3�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART3_EN)&&(ECBM_UART3_S3CON_CONFIG&0x40)&&(ECBM_TIMER3_EN))
#       error ����3�Ͷ�ʱ��3��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART4_EN)&&((ECBM_UART4_S4CON_CONFIG&0x40)==0)&&(ECBM_TIMER2_EN))
#       error ����4�Ͷ�ʱ��2��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#   if ((ECBM_UART4_EN)&&(ECBM_UART4_S4CON_CONFIG&0x40)&&(ECBM_TIMER4_EN))
#       error ����4�Ͷ�ʱ��4��ͻ���뻻һ����ʱ��ʹ�ã�
#   endif
#endif
//----------------------------------��ʱ����������---------------------------------//
#if (((ECBM_MCU&0x000F00)<0x000300)&&(ECBM_TIMER2_EN))
#   error ���ͺ�û�ж�ʱ��2���뻻һ����ʱ��ʹ�ã�
#endif
#if (((ECBM_MCU&0x000F00)<0x000400)&&(ECBM_TIMER3_EN))
#   error ���ͺ�û�ж�ʱ��3���뻻һ����ʱ��ʹ�ã�
#endif
#if (((ECBM_MCU&0x000F00)<0x000500)&&(ECBM_TIMER4_EN))
#   error ���ͺ�û�ж�ʱ��4���뻻һ����ʱ��ʹ�ã�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��ʱ����ʼ������
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
��ʱ��ֹͣ������
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
��ʱ��������ƺ�����
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
��ʱ����ʼ��������
-------------------------------------------------------*/
void timer_init(void){
    #if (ECBM_TIMER0_EN)     //�ж϶�ʱ��0��û��ʹ�ܡ�
        TIMER0_SET_REG_AUXR    (ECBM_TIMER0_AUXR);//д���趨�����ݡ�
        TIMER0_SET_REG_TMOD    (ECBM_TIMER0_TMOD);//д���趨�����ݡ�
        TIMER0_SET_REG_HL    (65536-ECBM_TIMER0_COUNT);//д���ֵ��
        #if (ECBM_TIMER0_IT_EN)    //����������жϡ�
            TIMER0_IT_ENABLE;
        #endif
    #endif
    
    #if (ECBM_TIMER1_EN)     //�ж϶�ʱ��1��û��ʹ�ܡ�
        TIMER1_SET_REG_AUXR(ECBM_TIMER1_AUXR);//д���趨�����ݡ�
        TIMER1_SET_REG_TMOD(ECBM_TIMER1_TMOD);//д���趨�����ݡ�
        TIMER1_SET_REG_HL(65536-ECBM_TIMER1_COUNT);//д���ֵ��
        #if (ECBM_TIMER1_IT_EN)  //����������жϡ�
            TIMER1_IT_ENABLE;
        #endif
    #endif
    
    #if (ECBM_TIMER2_EN)     //�ж϶�ʱ��2��û��ʹ�ܡ�
        TIMER2_SET_REG_AUXR    (ECBM_TIMER2_AUXR);//д���趨�����ݡ�
        TIMER2_SET_REG_HL    (65536-ECBM_TIMER2_COUNT);//д���ֵ��
        #if (ECBM_TIMER2_IT_EN)   //����������жϡ�
            TIMER2_IT_ENABLE;
        #endif
    #endif
        
    #if (ECBM_TIMER3_EN)     //�ж϶�ʱ��3��û��ʹ�ܡ�
        TIMER3_SET_REG_T4T3M(ECBM_TIMER3_T4T3M);//д���趨�����ݡ�
        TIMER3_SET_REG_HL    (65536-ECBM_TIMER3_COUNT);//д���ֵ��
        #if (ECBM_TIMER3_IT_EN)    //����������жϡ�
            TIMER3_IT_ENABLE;
        #endif
    #endif

    #if (ECBM_TIMER4_EN)     //�ж϶�ʱ��4��û��ʹ�ܡ�
        TIMER4_SET_REG_T4T3M(ECBM_TIMER4_T4T3M);//д���趨�����ݡ�
        TIMER4_SET_REG_HL    (65536-ECBM_TIMER4_COUNT);//д���ֵ��
        #if (ECBM_TIMER4_IT_EN)    //����������жϡ�
            TIMER4_IT_ENABLE;
        #endif
    #endif
}
/*-------------------------------------------------------
��ʱ���趨��ʱģʽ������
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
��ʱ���趨��ֵ������
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
��ʱ������ֵ��ȡ������
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
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��