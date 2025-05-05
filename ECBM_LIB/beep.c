#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_BEEP_EN)      //��鱾����û�б�ʹ��
/*------------------------------------��Դ��ͻ����---------------------------------*/
/*---------------------------------------�궨��------------------------------------*/
#define ECBM_BEEP_OFF       (0)//�������رա�
#define ECBM_BEEP_IDLE      (1)//���������ã���ʱ�û��������ɿ��ƣ���
#define ECBM_BEEP_AUTO_ON   (2)//�������Զ�ģʽ�µ���״̬��
#define ECBM_BEEP_AUTO_OFF  (3)//�������Զ�ģʽ�µĹر�״̬��
/*-------------------------------------���Ŷ���------------------------------------*/
sbit BEEP_IO=(ECBM_BEEP_IO_PORT+ECBM_BEEP_IO_PIN);
/*--------------------------------------��������-----------------------------------*/
u8 beep_on_time_gu8; //���������ʱ�������
u8 beep_off_time_gu8;//�����������ʱ�������
u8 beep_count_gu8;   //��������Ĵ���������
u8 beep_time_gu8;    //�������ļ�ʱ������
u8 beep_state_gu8;   //��������״̬������
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������ʼ��������
-------------------------------------------------------*/
void beep_init(void){
    BEEP_IO=!ECBM_BEEP_IO_WORK;//�رշ�������
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
���������к�����
-------------------------------------------------------*/
void beep_run(void){
    switch(beep_state_gu8){
        case ECBM_BEEP_OFF:{//�ر�״̬��
            BEEP_IO=!ECBM_BEEP_IO_WORK;//�رշ�������
            if(beep_count_gu8){//�����ʱ����������Ϊ0��������Զ���״̬��
                beep_time_gu8=0;//���ü�ʱ������
                beep_state_gu8=ECBM_BEEP_AUTO_ON;//�����Զ���״̬��
            }
        }break;
        case ECBM_BEEP_IDLE:{//����״̬��
            //ʲô�������������û���
        }break;
        case ECBM_BEEP_AUTO_ON:{//�Զ���״̬��
            BEEP_IO=ECBM_BEEP_IO_WORK;//������������
            beep_time_gu8++;//��ʱ��ʼ��
            if(beep_time_gu8>=beep_on_time_gu8){//�����ʱ�ﵽ��Ԥ��ʱ�䣬
                beep_time_gu8=0;//���ü�ʱ������
                beep_count_gu8--;//������������1��
                beep_state_gu8=ECBM_BEEP_AUTO_OFF;//�����Զ��ر�״̬��
            }
        }break;
        case ECBM_BEEP_AUTO_OFF:{//�Զ��ر�״̬��
            BEEP_IO=!ECBM_BEEP_IO_WORK;//�رշ�������
            beep_time_gu8++;//��ʱ��ʼ��
            if(beep_time_gu8>=beep_off_time_gu8){//�����ʱ�ﵽ��Ԥ��ʱ�䣬
                beep_time_gu8=0;//���ü�ʱ������
                if(beep_count_gu8){//�������������Ϊ0��
                    beep_state_gu8=ECBM_BEEP_AUTO_ON;//������Զ���״̬��
                }else{//�����������Ϊ0��
                    beep_state_gu8=ECBM_BEEP_OFF;//����ر�״̬��
                }
            }
        }
    }
}
/*-------------------------------------------------------
�������޸���ʽ������
-------------------------------------------------------*/
void beep_set_class(u8 on_time,u8 off_time){
    beep_on_time_gu8=on_time;
    beep_off_time_gu8=off_time;
}
/*-------------------------------------------------------
�������캯����
-------------------------------------------------------*/
void beep_start(u8 count){
    beep_count_gu8=count;//���÷���������
    if(beep_state_gu8==ECBM_BEEP_IDLE){//�����ǰ״̬Ϊ����״̬��
        beep_state_gu8=ECBM_BEEP_OFF;//����ر�״̬��Ȼ�󿿷�������������������
    }
}
/*-------------------------------------------------------
���������к�����
-------------------------------------------------------*/
void beep_idle(void){
    beep_state_gu8=ECBM_BEEP_IDLE;
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��