#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_PWM16_OUT_LIB_EN)      //��鱾����û�б�ʹ��
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_MCU!=0x4805C4)
#error "����ֻ������STC8H8K64U,�����ͺŵ�PWMԭ��ͼĴ�����ͬ����ʹ��!"
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
�߼�16λPWM�ĳ�ʼ��������
-------------------------------------------------------*/
void pwm16_out_init(void){
    PWMA_PS   =ECBM_PWM16_OUT_GROUPA_PIN_SEL;       //����PWM�������λ�á�
    PWMA_ETRPS=ECBM_PWM16_OUT_GROUPA_EXT_PIN_SEL;   //�����ⲿ�������š�
    PWMA_ENO  =ECBM_PWM16_OUT_GROUPA_PIN_EN;        //����PWM�������ʹ�ܡ�
    PWMA_IOAUX=ECBM_PWM16_OUT_GROUPA_IOAUX;         //����ɲ�����ܸ��ǵ����š�
    PWMA_PSCR =ECBM_PWM16_OUT_GROUPA_FREQ;          //����Ԥ��Ƶ��
    PWMA_ARR  =ECBM_PWM16_OUT_GROUPA_ARR;           //���ü���ֵ����Ԥ��Ƶ��ͬ������Ƶ�ʡ�
    PWMA_CCR1 =ECBM_PWM16_OUT_GROUPA_CH1_DUTY;      //����ͨ��1�Ƚ�ֵ��
    PWMA_CCR2 =ECBM_PWM16_OUT_GROUPA_CH2_DUTY;      //����ͨ��2�Ƚ�ֵ��
    PWMA_CCR3 =ECBM_PWM16_OUT_GROUPA_CH3_DUTY;      //����ͨ��3�Ƚ�ֵ��
    PWMA_CCR4 =ECBM_PWM16_OUT_GROUPA_CH4_DUTY;      //����ͨ��4�Ƚ�ֵ��
    PWMA_DTR  =ECBM_PWM16_OUT_GROUPA_DTR;           //��������ʱ�䡣
    PWMA_OISR =ECBM_PWM16_OUT_GROUPA_PIN_OIS;       //���ÿ���״̬�������ƽ��
    PWMA_CCER1=ECBM_PWM16_OUT_GROUPA_PIN12_POL;     //����ͨ��1��ͨ��2�ļ��ԡ�
    PWMA_CCER2=ECBM_PWM16_OUT_GROUPA_PIN34_POL;     //����ͨ��3��ͨ��4�ļ��ԡ�
    PWMA_BKR  =ECBM_PWM16_OUT_GROUPA_BKR;           //ʹ�������������ɲ����
    PWMA_CR1  =ECBM_PWM16_OUT_GROUPA_CR1;           //��������ģʽ��

    PWMB_PS   =ECBM_PWM16_OUT_GROUPB_PIN_SEL;       //����PWM�������λ�á�
    PWMB_ETRPS=ECBM_PWM16_OUT_GROUPB_EXT_PIN_SEL;   //�����ⲿ�������š�
    PWMB_ENO  =ECBM_PWM16_OUT_GROUPB_PIN_EN;        //����PWM�������ʹ�ܡ�
    PWMB_IOAUX=ECBM_PWM16_OUT_GROUPB_IOAUX;         //����ɲ�����ܸ��ǵ����š�
    PWMB_PSCR =ECBM_PWM16_OUT_GROUPB_FREQ;          //����Ԥ��Ƶ��
    PWMB_ARR  =ECBM_PWM16_OUT_GROUPB_ARR;           //���ü���ֵ����Ԥ��Ƶ��ͬ������Ƶ�ʡ�
    PWMB_CCR5 =ECBM_PWM16_OUT_GROUPB_CH5_DUTY;      //����ͨ��5�Ƚ�ֵ��
    PWMB_CCR6 =ECBM_PWM16_OUT_GROUPB_CH6_DUTY;      //����ͨ��6�Ƚ�ֵ��
    PWMB_CCR7 =ECBM_PWM16_OUT_GROUPB_CH7_DUTY;      //����ͨ��7�Ƚ�ֵ��
    PWMB_CCR8 =ECBM_PWM16_OUT_GROUPB_CH8_DUTY;      //����ͨ��8�Ƚ�ֵ��
    PWMB_DTR  =ECBM_PWM16_OUT_GROUPB_DTR;           //��������ʱ�䡣
    PWMB_OISR =ECBM_PWM16_OUT_GROUPB_PIN_OIS;       //���ÿ���״̬�������ƽ��
    PWMB_CCER1=ECBM_PWM16_OUT_GROUPB_PIN56_POL;     //����ͨ��5��ͨ��6�ļ��ԡ�
    PWMB_CCER2=ECBM_PWM16_OUT_GROUPB_PIN78_POL;     //����ͨ��7��ͨ��8�ļ��ԡ�
    PWMB_BKR  =ECBM_PWM16_OUT_GROUPB_BKR;           //ʹ�������������ɲ����
    PWMB_CR1  =ECBM_PWM16_OUT_GROUPB_CR1;           //��������ģʽ��
}
/*-------------------------------------------------------
�߼�16λPWMA���B�������������
-------------------------------------------------------*/
void pwm16_out_groupa_start(void){
    PWMA_BKR|=0x80;//��PWMģ������ʹ��
    PWMA_CR1|=0x01;//������ʱ��
}
void pwm16_out_groupb_start(void){
    PWMB_BKR|=0x80;//��PWMģ������ʹ��
    PWMB_CR1|=0x01;//������ʱ��
}
/*-------------------------------------------------------
�߼�16λPWMA���B���ֹͣ������
-------------------------------------------------------*/
void pwm16_out_groupa_stop(void){
    PWMA_CR1&=~0x01;//ֹͣ��ʱ��
    PWMA_BKR&=~0x80;//�ر�PWMģ������ʹ��
}
void pwm16_out_groupb_stop(void){
    PWMB_CR1&=~0x01;//ֹͣ��ʱ��
    PWMB_BKR&=~0x80;//�ر�PWMģ������ʹ��
}
/*-------------------------------------------------------
�߼�16λPWM��Ƶ�����ú�����
-------------------------------------------------------*/
void pwm16_out_set_freq(u8 ch,u32 freq){
    u32 temp,temp2,temp3;
    if(freq){//Ƶ�ʱ�����1Hz���ϣ�����Ͳ��ܸļĴ�����
        temp=(ECBM_SYSCLK_SETTING/freq);    //��������Ƶ��֮�ȣ�
        if(temp>=65535UL){                  //���Ƶ��̫�����Ƶ��
            temp2=temp/65535UL;             //��ARRΪ���ֵ�����㣬�õ�һ����С��Ԥ��Ƶֵ��
            temp3=temp/(temp2+1);           //���Ԥ��Ƶ֮���ARRֵ����Ҫע��Ĵ������ֵ��ʵ�ʵķ�ƵЧ����1������Ҫ�ӻ�����
        }else{                              //���Ƶ��̫С���򲻷�Ƶ��
            temp2=0;                        //����Ԥ��ƵΪ0������1��Ƶ���򲻷�Ƶ����˼��
            temp3=temp;                     //����Ƶ�Ļ���������ֱֵ�ӾͿ��Ը���ARR�Ĵ�����
        }
        if(temp3){                          //����˵�ˣ�ARRҲ��Ԥ��Ƶ�Ĵ���һ����ʵ��Ч���ͼĴ���ֵ��1��
            temp3--;                        //����Ϊ�˷�ֹż���������һ���ô���0���ܼ�һ��
        }                                   //����0-1�͵õ�һ������ֵ(�޷������ļ���ֵ=�з������ĸ�һ)��
        if(ch<=4){                          //���ͨ����С�ڵ���4�����޸�A���Ԥ��Ƶֵ��
            PWMA_PSCR=(u16)(temp2);         //����A��Ԥ��Ƶ��
            PWMA_ARR =(u16)(temp3);         //����A��ARRֵ��
        }else if(ch<=8){                    //���ͨ���Ŵ���4С�ڵ���8�����޸�B���Ԥ��Ƶֵ��
            PWMB_PSCR=(u16)(temp2);         //����B��Ԥ��Ƶ��
            PWMB_ARR =(u16)(temp3);         //����B��ARRֵ��
        }
    }
}
/*-------------------------------------------------------
�߼�16λPWM��Ƶ�����ú�����
-------------------------------------------------------*/
void pwm16_out_set_duty(u8 ch,u16 ch_duty){
    u16 arr_temp,ccmr_temp;
    if(ch_duty==0){             //���ռ�ձ���0%�Ļ���
        ccmr_temp=0x40;         //����ǿ������͵�ƽ��
        arr_temp=0;             //����Ĵ�������ֹ���⶯����
    }else if(ch_duty>=10000){   //���ռ�ձ���100%�Ļ���
        ccmr_temp=0x50;         //����ǿ������ߵ�ƽ��
        arr_temp=0;             //����Ĵ�������ֹ���⶯����
    }else{                      //����0%��100%�����ռ�ձȣ�
        ccmr_temp=0x60;         //����ΪPWMģʽ1��
        if(ch<=4){              //���ͨ����С�ڵ���4��
            arr_temp=(u16)((u32)(PWMA_ARR)*(u32)(ch_duty)/10000UL);//��A���ARR�������ռ�ձȶ�Ӧ��ֵ��
        }else if(ch<=8){        //���ͨ���Ŵ���4С�ڵ���8��
            arr_temp=(u16)((u32)(PWMB_ARR)*(u32)(ch_duty)/10000UL);//��B���ARR�������ռ�ձȶ�Ӧ��ֵ��
        }
    }
    switch(ch){//����ͨ����ֵд���Ӧ�ļĴ�����
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
�߼�16λPWM�������������Կ��������ģʽ��������
-------------------------------------------------------*/
void pwm16_out_pulse_start(u8 ch,u8 ch_count){
    if(ch_count){//�����������������0����������
        switch(ch){//���ö�Ӧ��ͨ���Ĺ���ģʽ��ռ�ձȣ�ռ�ձȺ㶨Ϊ50%��
            case 1:{PWMA_CCMR1=0x60;PWMA_CCR1=PWMA_ARR>>1;}break;
            case 2:{PWMA_CCMR2=0x60;PWMA_CCR2=PWMA_ARR>>1;}break;
            case 3:{PWMA_CCMR3=0x60;PWMA_CCR3=PWMA_ARR>>1;}break;
            case 4:{PWMA_CCMR4=0x60;PWMA_CCR4=PWMA_ARR>>1;}break;
            case 5:{PWMB_CCMR1=0x60;PWMB_CCR5=PWMB_ARR>>1;}break;
            case 6:{PWMB_CCMR2=0x60;PWMB_CCR6=PWMB_ARR>>1;}break;
            case 7:{PWMB_CCMR3=0x60;PWMB_CCR7=PWMB_ARR>>1;}break;
            case 8:{PWMB_CCMR4=0x60;PWMB_CCR8=PWMB_ARR>>1;}break;
        }
        if(ch<=4){                      //���ͨ����С�ڵ���4��
            PWMA_CR1|=0x08;             //ȷ��������ģʽ�Ѿ�������
            PWMA_RCR=ch_count-1;        //װ����������
            pwm16_out_groupa_start();   //����PWM��
        }else if(ch<=8){                //���ͨ���Ŵ���4С�ڵ���8��
            PWMB_CR1|=0x08;             //ȷ��������ģʽ�Ѿ�������
            PWMB_RCR=ch_count-1;        //װ����������
            pwm16_out_groupb_start();   //����PWM��
        }
    }
}
/*-------------------------------------------------------
�߼�16λPWMA��������������Բ��������ģʽ��������
-------------------------------------------------------*/
void pwm16_out_wave_start(u8 ch,u16 ch_duty){
    pwm16_out_set_duty(ch,ch_duty); //����ռ�ձȡ�
    if(ch<=4){                      //���ͨ����С�ڵ���4��
        PWMA_CR1&=~0x08;            //ȷ��������ģʽ�Ѿ�������
        pwm16_out_groupa_start();   //����PWM��
    }else if(ch<=8){                //���ͨ���Ŵ���4С�ڵ���8��
        PWMB_CR1&=~0x08;            //ȷ��������ģʽ�Ѿ�������
        pwm16_out_groupb_start();   //����PWM��
    }
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��