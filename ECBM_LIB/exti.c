#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_EXTI_LIB_EN)  //��鱾����û�б�ʹ��
/*--------------------------------------������-----------------------------------*/
/*------------------------------------------------------
�ⲿ�жϳ�ʼ��������
-------------------------------------------------------*/
void exti_init(void){
    #if (ECBM_EXTI0_EN)         //�ⲿ�ж�0����P32�ڡ���ѡ�񴥷���ʽ��
        gpio_mode(D32,GPIO_IN); //����P32Ϊ����״̬��
        EXTI0_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��       
        #if (ECBM_EXTI0_MODE==0)//ͨ��������Ϣ�жϡ�    
            EXTI0_SET_MODE_UP_DOWN; //����������/�½����жϡ�
        #else
            EXTI0_SET_MODE_DOWN;//�����½����жϡ�
        #endif
        #if (ECBM_EXTI0_INIT)
            EXTI0_ENABLE;       //���ⲿ�ж�0��
        #endif
    #endif
    
    #if (ECBM_EXTI1_EN)         //�ⲿ�ж�1����P33�ڡ���ѡ�񴥷���ʽ��  
        gpio_mode(D33,GPIO_IN); //����P33Ϊ����״̬��
        EXTI1_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��   
        #if (ECBM_EXTI1_MODE==0)//ͨ��������Ϣ�жϡ�    
            EXTI1_SET_MODE_UP_DOWN; //����������/�½����жϡ�
        #else
            EXTI1_SET_MODE_DOWN;//�����½����жϡ�
        #endif
        #if (ECBM_EXTI1_INIT)
            EXTI1_ENABLE;       //���ⲿ�ж�1��
        #endif
    #endif
    
    #if (ECBM_EXTI2_EN)         //�ⲿ�ж�2����P36�ڡ�   
        gpio_mode(D36,GPIO_IN); //����P36Ϊ����״̬��
        EXTI2_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
        #if (ECBM_EXTI2_INIT)
            EXTI2_ENABLE;       //���ⲿ�ж�2��
        #endif
    #endif
    
    #if (ECBM_EXTI3_EN)         //�ⲿ�ж�3����P37�ڡ�  
        gpio_mode(D37,GPIO_IN); //����P37Ϊ����״̬��
        EXTI3_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
        #if (ECBM_EXTI3_INIT)
            EXTI3_ENABLE;       //���ⲿ�ж�3��
        #endif
    #endif
    
    #if (ECBM_EXTI4_EN)         //�ⲿ�ж�4����P30�ڡ�
        gpio_mode(D30,GPIO_IN); //����P30Ϊ����״̬��
        EXTI4_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
        #if (ECBM_EXTI4_INIT)
            EXTI4_ENABLE;       //���ⲿ�ж�4
        #endif
    #endif
}
/*------------------------------------------------------
���жϺ�����
-------------------------------------------------------*/
void exti_start(u8 id){
    switch(id){//����ID������Ӧ��֧��
        #if (ECBM_EXTI0_EN)
            case 0:{EXTI0_ENABLE;}break;
        #endif
        #if (ECBM_EXTI1_EN)
            case 1:{EXTI1_ENABLE;}break;
        #endif
        #if (ECBM_EXTI2_EN)
            case 2:{EXTI2_ENABLE;}break;
        #endif
        #if (ECBM_EXTI3_EN)
            case 3:{EXTI3_ENABLE;}break;
        #endif
        #if (ECBM_EXTI4_EN)
            case 4:{EXTI4_ENABLE;}break;
        #endif
        default:break;
    }    
}
/*------------------------------------------------------
�ر��жϺ�����
-------------------------------------------------------*/
void exti_stop(u8 id){
    switch(id){//����ID������Ӧ��֧��
        #if (ECBM_EXTI0_EN)
            case 0:{EXTI0_DISABLE;}break;
        #endif
        #if (ECBM_EXTI1_EN)
            case 1:{EXTI1_DISABLE;}break;
        #endif
        #if (ECBM_EXTI2_EN)
            case 2:{EXTI2_DISABLE;}break;
        #endif
        #if (ECBM_EXTI3_EN)
            case 3:{EXTI3_DISABLE;}break;
        #endif
        #if (ECBM_EXTI4_EN)
            case 4:{EXTI4_DISABLE;}break;
        #endif
        default:break;
    }    
}
/*------------------------------------------------------
�ж�ģʽ���ú�����
-------------------------------------------------------*/
void exti_set_mode(u8 id,u8 mode){
    mode=mode;
    switch(id){//����ID������Ӧ��֧��
        default:break;
        #if (ECBM_EXTI0_EN)
            case 0:{
                if(mode){
                    EXTI0_SET_MODE_DOWN;
                }else{
                    EXTI0_SET_MODE_UP_DOWN;
                }
            }break;
        #endif
        #if (ECBM_EXTI1_EN)
            case 1:{
                if(mode){
                    EXTI1_SET_MODE_DOWN;
                }else{
                    EXTI1_SET_MODE_UP_DOWN;
                }
            }break;
        #endif
    }    
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��