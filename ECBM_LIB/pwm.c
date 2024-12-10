#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_PWM_LIB_EN)   //��鱾����û�б�ʹ��
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
PWM��ʼ��������
-------------------------------------------------------*/
void pwm_init(void){
    #if ((ECBM_MCU&0xF00000)==0x200000)   //STC8A
        PWM15_POWER_ON;                             //�����ֲᣬ������Դ�ſ�д�����á�
        PWM15_SET_REG_CLK(ECBM_PWM_GROUP0_CLK);     //д��PWMʱ�����ò�����
        PWM15_SET_REG_COUNT(ECBM_PWM_GROUP0_COUNT); //д��PWM��ʱ���ֵ��
        #if (ECBM_PWM_GROUP0_CH0_EN)    //���ʹ����PWM��ͨ��0��
            PWM15_SET_REG_CH0_T1(ECBM_PWM_GROUP0_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH0_T2(ECBM_PWM_GROUP0_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH0_CR(ECBM_PWM_GROUP0_CH0_CR);//д��ͨ��0�����á�
            #if   ((ECBM_PWM_GROUP0_CH0_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D20,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH0_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D10,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH0_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D60,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH1_EN)    //���ʹ����PWM��ͨ��1��
            PWM15_SET_REG_CH1_T1(ECBM_PWM_GROUP0_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH1_T2(ECBM_PWM_GROUP0_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH1_CR(ECBM_PWM_GROUP0_CH1_CR);//д��ͨ��1�����á�
            #if   ((ECBM_PWM_GROUP0_CH1_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D21,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH1_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D11,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH1_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D61,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH2_EN)    //���ʹ����PWM��ͨ��2��
            PWM15_SET_REG_CH2_T1(ECBM_PWM_GROUP0_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH2_T2(ECBM_PWM_GROUP0_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH2_CR(ECBM_PWM_GROUP0_CH2_CR);//д��ͨ��2�����á�
            #if   ((ECBM_PWM_GROUP0_CH2_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D22,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH2_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D12,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH2_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D62,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH3_EN)    //���ʹ����PWM��ͨ��3��
            PWM15_SET_REG_CH3_T1(ECBM_PWM_GROUP0_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH3_T2(ECBM_PWM_GROUP0_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH3_CR(ECBM_PWM_GROUP0_CH3_CR);//д��ͨ��3�����á�
            #if   ((ECBM_PWM_GROUP0_CH3_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D23,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH3_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D13,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH3_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D63,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH4_EN)    //���ʹ����PWM��ͨ��4��
            PWM15_SET_REG_CH4_T1(ECBM_PWM_GROUP0_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH4_T2(ECBM_PWM_GROUP0_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH4_CR(ECBM_PWM_GROUP0_CH4_CR);//д��ͨ��4�����á�
            #if   ((ECBM_PWM_GROUP0_CH4_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D24,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH4_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D14,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH4_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D64,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH5_EN)    //���ʹ����PWM��ͨ��5��
            PWM15_SET_REG_CH5_T1(ECBM_PWM_GROUP0_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH5_T2(ECBM_PWM_GROUP0_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH5_CR(ECBM_PWM_GROUP0_CH5_CR);//д��ͨ��5�����á�
            #if   ((ECBM_PWM_GROUP0_CH5_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D25,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH5_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D15,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH5_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D65,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH6_EN)    //���ʹ����PWM��ͨ��6��
            PWM15_SET_REG_CH6_T1(ECBM_PWM_GROUP0_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH6_T2(ECBM_PWM_GROUP0_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH6_CR(ECBM_PWM_GROUP0_CH6_CR);//д��ͨ��6�����á�
            #if   ((ECBM_PWM_GROUP0_CH6_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D26,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH6_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D16,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH6_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D66,GPIO_OUT);
            #endif
        #endif
        #if (ECBM_PWM_GROUP0_CH7_EN)    //���ʹ����PWM��ͨ��7��
            PWM15_SET_REG_CH7_T1(ECBM_PWM_GROUP0_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
            PWM15_SET_REG_CH7_T2(ECBM_PWM_GROUP0_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
            PWM15_SET_REG_CH7_CR(ECBM_PWM_GROUP0_CH7_CR);//д��ͨ��7�����á�
            #if   ((ECBM_PWM_GROUP0_CH7_CR&0x18)==PWM_8A_IO_P2x)
                gpio_mode(D27,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH7_CR&0x18)==PWM_8A_IO_P1x)
                gpio_mode(D17,GPIO_OUT);
            #elif ((ECBM_PWM_GROUP0_CH7_CR&0x18)==PWM_8A_IO_P6x)
                gpio_mode(D67,GPIO_OUT);
            #endif
        #endif
        PWM15_START;
    #elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
        #if (ECBM_PWM_GROUP0_EN)
            PWM15_G0_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G0_CLK(ECBM_PWM_GROUP0_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G0_COUNT(ECBM_PWM_GROUP0_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP0_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G0_CH0_T1(ECBM_PWM_GROUP0_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH0_T2(ECBM_PWM_GROUP0_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH0_CR(ECBM_PWM_GROUP0_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D00,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G0_CH1_T1(ECBM_PWM_GROUP0_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH1_T2(ECBM_PWM_GROUP0_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH1_CR(ECBM_PWM_GROUP0_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D01,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G0_CH2_T1(ECBM_PWM_GROUP0_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH2_T2(ECBM_PWM_GROUP0_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH2_CR(ECBM_PWM_GROUP0_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D02,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G0_CH3_T1(ECBM_PWM_GROUP0_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH3_T2(ECBM_PWM_GROUP0_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH3_CR(ECBM_PWM_GROUP0_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D03,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G0_CH4_T1(ECBM_PWM_GROUP0_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH4_T2(ECBM_PWM_GROUP0_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH4_CR(ECBM_PWM_GROUP0_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D04,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G0_CH5_T1(ECBM_PWM_GROUP0_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH5_T2(ECBM_PWM_GROUP0_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH5_CR(ECBM_PWM_GROUP0_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D05,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G0_CH6_T1(ECBM_PWM_GROUP0_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH6_T2(ECBM_PWM_GROUP0_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH6_CR(ECBM_PWM_GROUP0_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D06,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP0_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G0_CH7_T1(ECBM_PWM_GROUP0_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH7_T2(ECBM_PWM_GROUP0_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G0_CH7_CR(ECBM_PWM_GROUP0_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D07,GPIO_OUT);
            #endif
            PWM15_G0_START;
        #endif
        #if (ECBM_PWM_GROUP1_EN)
            PWM15_G1_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G1_CLK(ECBM_PWM_GROUP1_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G1_COUNT(ECBM_PWM_GROUP1_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP1_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G1_CH0_T1(ECBM_PWM_GROUP1_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH0_T2(ECBM_PWM_GROUP1_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH0_CR(ECBM_PWM_GROUP1_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D10,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G1_CH1_T1(ECBM_PWM_GROUP1_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH1_T2(ECBM_PWM_GROUP1_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH1_CR(ECBM_PWM_GROUP1_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D11,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G1_CH2_T1(ECBM_PWM_GROUP1_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH2_T2(ECBM_PWM_GROUP1_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH2_CR(ECBM_PWM_GROUP1_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D12,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G1_CH3_T1(ECBM_PWM_GROUP1_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH3_T2(ECBM_PWM_GROUP1_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH3_CR(ECBM_PWM_GROUP1_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D13,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G1_CH4_T1(ECBM_PWM_GROUP1_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH4_T2(ECBM_PWM_GROUP1_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH4_CR(ECBM_PWM_GROUP1_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D14,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G1_CH5_T1(ECBM_PWM_GROUP1_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH5_T2(ECBM_PWM_GROUP1_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH5_CR(ECBM_PWM_GROUP1_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D15,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G1_CH6_T1(ECBM_PWM_GROUP1_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH6_T2(ECBM_PWM_GROUP1_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH6_CR(ECBM_PWM_GROUP1_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D16,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP1_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G1_CH7_T1(ECBM_PWM_GROUP1_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH7_T2(ECBM_PWM_GROUP1_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G1_CH7_CR(ECBM_PWM_GROUP1_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D17,GPIO_OUT);
            #endif
            PWM15_G1_START;
        #endif
        #if (ECBM_PWM_GROUP2_EN)
            PWM15_G2_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G2_CLK(ECBM_PWM_GROUP2_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G2_COUNT(ECBM_PWM_GROUP2_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP2_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G2_CH0_T1(ECBM_PWM_GROUP2_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH0_T2(ECBM_PWM_GROUP2_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH0_CR(ECBM_PWM_GROUP2_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D20,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G2_CH1_T1(ECBM_PWM_GROUP2_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH1_T2(ECBM_PWM_GROUP2_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH1_CR(ECBM_PWM_GROUP2_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D21,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G2_CH2_T1(ECBM_PWM_GROUP2_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH2_T2(ECBM_PWM_GROUP2_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH2_CR(ECBM_PWM_GROUP2_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D22,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G2_CH3_T1(ECBM_PWM_GROUP2_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH3_T2(ECBM_PWM_GROUP2_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH3_CR(ECBM_PWM_GROUP2_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D23,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G2_CH4_T1(ECBM_PWM_GROUP2_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH4_T2(ECBM_PWM_GROUP2_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH4_CR(ECBM_PWM_GROUP2_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D24,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G2_CH5_T1(ECBM_PWM_GROUP2_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH5_T2(ECBM_PWM_GROUP2_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH5_CR(ECBM_PWM_GROUP2_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D25,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G2_CH6_T1(ECBM_PWM_GROUP2_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH6_T2(ECBM_PWM_GROUP2_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH6_CR(ECBM_PWM_GROUP2_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D26,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP2_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G2_CH7_T1(ECBM_PWM_GROUP2_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH7_T2(ECBM_PWM_GROUP2_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G2_CH7_CR(ECBM_PWM_GROUP2_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D27,GPIO_OUT);
            #endif
            PWM15_G2_START;
        #endif
        #if (ECBM_PWM_GROUP3_EN)
            PWM15_G3_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G3_CLK(ECBM_PWM_GROUP3_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G3_COUNT(ECBM_PWM_GROUP3_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP3_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G3_CH0_T1(ECBM_PWM_GROUP3_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH0_T2(ECBM_PWM_GROUP3_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH0_CR(ECBM_PWM_GROUP3_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D30,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G3_CH1_T1(ECBM_PWM_GROUP3_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH1_T2(ECBM_PWM_GROUP3_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH1_CR(ECBM_PWM_GROUP3_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D31,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G3_CH2_T1(ECBM_PWM_GROUP3_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH2_T2(ECBM_PWM_GROUP3_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH2_CR(ECBM_PWM_GROUP3_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D32,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G3_CH3_T1(ECBM_PWM_GROUP3_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH3_T2(ECBM_PWM_GROUP3_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH3_CR(ECBM_PWM_GROUP3_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D33,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G3_CH4_T1(ECBM_PWM_GROUP3_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH4_T2(ECBM_PWM_GROUP3_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH4_CR(ECBM_PWM_GROUP3_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D34,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G3_CH5_T1(ECBM_PWM_GROUP3_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH5_T2(ECBM_PWM_GROUP3_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH5_CR(ECBM_PWM_GROUP3_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D35,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G3_CH6_T1(ECBM_PWM_GROUP3_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH6_T2(ECBM_PWM_GROUP3_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH6_CR(ECBM_PWM_GROUP3_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D36,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP3_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G3_CH7_T1(ECBM_PWM_GROUP3_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH7_T2(ECBM_PWM_GROUP3_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G3_CH7_CR(ECBM_PWM_GROUP3_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D37,GPIO_OUT);
            #endif
            PWM15_G3_START;
        #endif
        #if (ECBM_PWM_GROUP4_EN)
            PWM15_G4_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G4_CLK(ECBM_PWM_GROUP4_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G4_COUNT(ECBM_PWM_GROUP4_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP4_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G4_CH0_T1(ECBM_PWM_GROUP4_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH0_T2(ECBM_PWM_GROUP4_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH0_CR(ECBM_PWM_GROUP4_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D40,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G4_CH1_T1(ECBM_PWM_GROUP4_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH1_T2(ECBM_PWM_GROUP4_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH1_CR(ECBM_PWM_GROUP4_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D41,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G4_CH2_T1(ECBM_PWM_GROUP4_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH2_T2(ECBM_PWM_GROUP4_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH2_CR(ECBM_PWM_GROUP4_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D42,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G4_CH3_T1(ECBM_PWM_GROUP4_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH3_T2(ECBM_PWM_GROUP4_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH3_CR(ECBM_PWM_GROUP4_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D43,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G4_CH4_T1(ECBM_PWM_GROUP4_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH4_T2(ECBM_PWM_GROUP4_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH4_CR(ECBM_PWM_GROUP4_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D44,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G4_CH5_T1(ECBM_PWM_GROUP4_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH5_T2(ECBM_PWM_GROUP4_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH5_CR(ECBM_PWM_GROUP4_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D45,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G4_CH6_T1(ECBM_PWM_GROUP4_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH6_T2(ECBM_PWM_GROUP4_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH6_CR(ECBM_PWM_GROUP4_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D46,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP4_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G4_CH7_T1(ECBM_PWM_GROUP4_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH7_T2(ECBM_PWM_GROUP4_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G4_CH7_CR(ECBM_PWM_GROUP4_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D47,GPIO_OUT);
            #endif
            PWM15_G4_START;
        #endif
        #if (ECBM_PWM_GROUP5_EN)
            PWM15_G5_POWER_ON;                                  //�����ֲᣬ������Դ�ſ�д�����á�
            PWM15_SET_REG_G5_CLK(ECBM_PWM_GROUP5_CLK);          //д��PWMʱ�����ò�����
            PWM15_SET_REG_G5_COUNT(ECBM_PWM_GROUP5_COUNT);      //д��PWM��ʱ���ֵ��
            #if (ECBM_PWM_GROUP5_CH0_EN)                        //���ʹ����PWM��ͨ��0��
                PWM15_SET_REG_G5_CH0_T1(ECBM_PWM_GROUP5_CH0_T1);//д��ͨ��0�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH0_T2(ECBM_PWM_GROUP5_CH0_T2);//д��ͨ��0�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH0_CR(ECBM_PWM_GROUP5_CH0_CR);//д��ͨ��0�����á�
                gpio_mode(D50,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH1_EN)                        //���ʹ����PWM��ͨ��1��
                PWM15_SET_REG_G5_CH1_T1(ECBM_PWM_GROUP5_CH1_T1);//д��ͨ��1�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH1_T2(ECBM_PWM_GROUP5_CH1_T2);//д��ͨ��1�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH1_CR(ECBM_PWM_GROUP5_CH1_CR);//д��ͨ��1�����á�
                gpio_mode(D51,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH2_EN)                        //���ʹ����PWM��ͨ��2��
                PWM15_SET_REG_G5_CH2_T1(ECBM_PWM_GROUP5_CH2_T1);//д��ͨ��2�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH2_T2(ECBM_PWM_GROUP5_CH2_T2);//д��ͨ��2�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH2_CR(ECBM_PWM_GROUP5_CH2_CR);//д��ͨ��2�����á�
                gpio_mode(D52,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH3_EN)                        //���ʹ����PWM��ͨ��3��
                PWM15_SET_REG_G5_CH3_T1(ECBM_PWM_GROUP5_CH3_T1);//д��ͨ��3�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH3_T2(ECBM_PWM_GROUP5_CH3_T2);//д��ͨ��3�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH3_CR(ECBM_PWM_GROUP5_CH3_CR);//д��ͨ��3�����á�
                gpio_mode(D53,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH4_EN)                        //���ʹ����PWM��ͨ��4��
                PWM15_SET_REG_G5_CH4_T1(ECBM_PWM_GROUP5_CH4_T1);//д��ͨ��4�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH4_T2(ECBM_PWM_GROUP5_CH4_T2);//д��ͨ��4�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH4_CR(ECBM_PWM_GROUP5_CH4_CR);//д��ͨ��4�����á�
                gpio_mode(D54,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH5_EN)                        //���ʹ����PWM��ͨ��5��
                PWM15_SET_REG_G5_CH5_T1(ECBM_PWM_GROUP5_CH5_T1);//д��ͨ��5�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH5_T2(ECBM_PWM_GROUP5_CH5_T2);//д��ͨ��5�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH5_CR(ECBM_PWM_GROUP5_CH5_CR);//д��ͨ��5�����á�
                gpio_mode(D55,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH6_EN)                        //���ʹ����PWM��ͨ��6��
                PWM15_SET_REG_G5_CH6_T1(ECBM_PWM_GROUP5_CH6_T1);//д��ͨ��6�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH6_T2(ECBM_PWM_GROUP5_CH6_T2);//д��ͨ��6�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH6_CR(ECBM_PWM_GROUP5_CH6_CR);//д��ͨ��6�����á�
                gpio_mode(D56,GPIO_OUT);
            #endif
            #if (ECBM_PWM_GROUP5_CH7_EN)                        //���ʹ����PWM��ͨ��7��
                PWM15_SET_REG_G5_CH7_T1(ECBM_PWM_GROUP5_CH7_T1);//д��ͨ��7�ĵ͵�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH7_T2(ECBM_PWM_GROUP5_CH7_T2);//д��ͨ��7�ĸߵ�ƽ��ת�㡣
                PWM15_SET_REG_G5_CH7_CR(ECBM_PWM_GROUP5_CH7_CR);//д��ͨ��7�����á�
                gpio_mode(D57,GPIO_OUT);
            #endif
            PWM15_G5_START;
        #endif
    #endif
}
/*-------------------------------------------------------
PWM����Ƶ�ʺ�����
-------------------------------------------------------*/
void pwm_set_freq(u8 group,u32 freq){
    u8 i;
    u32 temp;
    for(i=1;i<16;i++){if((ECBM_SYSCLK_SETTING/i/32767)<freq)break;}
    temp=(ECBM_SYSCLK_SETTING/i/freq);
    if(temp>32767){return;}
    switch(group){
        default:break;
        #if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8A
            case 0:{
                PWM15_STOP;
                PWM15_SET_REG_CLK(i-1);
                PWM15_SET_REG_COUNT(temp);
                PWM15_START;
            }break;
        #elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
            #if ECBM_PWM_GROUP0_EN
                case 0:{
                    PWM15_G0_STOP;
                    PWM15_SET_REG_G0_CLK(i-1);
                    PWM15_SET_REG_G0_COUNT(temp);
                    PWM15_G0_START;
                }break;
            #endif
            #if ECBM_PWM_GROUP1_EN
                case 1:{
                    PWM15_G1_STOP;
                    PWM15_SET_REG_G1_CLK(i-1);
                    PWM15_SET_REG_G1_COUNT(temp);
                    PWM15_G1_START;
                }break;
            #endif
            #if ECBM_PWM_GROUP2_EN
                case 2:{
                    PWM15_G2_STOP;
                    PWM15_SET_REG_G2_CLK(i-1);
                    PWM15_SET_REG_G2_COUNT(temp);
                    PWM15_G2_START;
                }break;
            #endif
            #if ECBM_PWM_GROUP3_EN
                case 3:{
                    PWM15_G3_STOP;
                    PWM15_SET_REG_G3_CLK(i-1);
                    PWM15_SET_REG_G3_COUNT(temp);
                    PWM15_G3_START;
                }break;
            #endif
            #if ECBM_PWM_GROUP4_EN
                case 4:{
                    PWM15_G4_STOP;
                    PWM15_SET_REG_G4_CLK(i-1);
                    PWM15_SET_REG_G4_COUNT(temp);
                    PWM15_G4_START;
                }break;
            #endif
            #if ECBM_PWM_GROUP5_EN
                case 5:{
                    PWM15_G5_STOP;
                    PWM15_SET_REG_G5_CLK(i-1);
                    PWM15_SET_REG_G5_COUNT(temp);
                    PWM15_G5_START;
                }break;
            #endif
        #endif
    }
}
/*-------------------------------------------------------
PWM����ռ�ձȺ�����
-------------------------------------------------------*/
void pwm_set_duty(u8 group,u8 ch,u16 duty){
	ch=ch;
	duty=duty;
    switch(group){
        default:break;
        #if   ((ECBM_MCU&0xF00000)==0x200000)   //STC8A
            case 0:{
                switch(ch){
                    #if ECBM_PWM_GROUP0_CH0_EN
                        case 0:{
                            if(duty>=1000){
                                PWM15_SET_CH0_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH0_HOLD_L;
                            }else{
                                PWM15_SET_CH0_HOLD_OFF;
                                PWM15_SET_REG_CH0_T2(0x0000);
                                PWM15_SET_REG_CH0_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH1_EN
                        case 1:{
                            if(duty>=1000){
                                PWM15_SET_CH1_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH1_HOLD_L;
                            }else{
                                PWM15_SET_CH1_HOLD_OFF;
                                PWM15_SET_REG_CH1_T2(0x0000);
                                PWM15_SET_REG_CH1_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH2_EN
                        case 2:{
                            if(duty>=1000){
                                PWM15_SET_CH2_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH2_HOLD_L;
                            }else{
                                PWM15_SET_CH2_HOLD_OFF;
                                PWM15_SET_REG_CH2_T2(0x0000);
                                PWM15_SET_REG_CH2_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH3_EN
                        case 3:{
                            if(duty>=1000){
                                PWM15_SET_CH3_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH3_HOLD_L;
                            }else{
                                PWM15_SET_CH3_HOLD_OFF;
                                PWM15_SET_REG_CH3_T2(0x0000);
                            PWM15_SET_REG_CH3_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH4_EN
                        case 4:{
                            if(duty>=1000){
                                PWM15_SET_CH4_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH4_HOLD_L;
                            }else{
                                PWM15_SET_CH4_HOLD_OFF;
                                PWM15_SET_REG_CH4_T2(0x0000);
                                PWM15_SET_REG_CH4_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH5_EN
                        case 5:{
                            if(duty>=1000){
                                PWM15_SET_CH5_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH5_HOLD_L;
                            }else{
                                PWM15_SET_CH5_HOLD_OFF;
                                PWM15_SET_REG_CH5_T2(0x0000);
                                PWM15_SET_REG_CH5_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH6_EN
                        case 6:{
                            if(duty>=1000){
                                PWM15_SET_CH6_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH6_HOLD_L;
                            }else{
                                PWM15_SET_CH6_HOLD_OFF;
                                PWM15_SET_REG_CH6_T2(0x0000);
                                PWM15_SET_REG_CH6_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    #if ECBM_PWM_GROUP0_CH7_EN
                        case 7:{
                            if(duty>=1000){
                                PWM15_SET_CH7_HOLD_H;
                            }else if(duty==0){
                                PWM15_SET_CH7_HOLD_L;
                            }else{
                                PWM15_SET_CH7_HOLD_OFF;
                                PWM15_SET_REG_CH7_T2(0x0000);
                                PWM15_SET_REG_CH7_T1((u32)PWM15_GET_REG_COUNT*duty/1000);
                            }
                        }break;
                    #endif
                    default:break;
                }
            }break;
        #elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2Kϵ��
            #if ECBM_PWM_GROUP0_EN
                case 0:{
                    switch(ch){
                        #if ECBM_PWM_GROUP0_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH0_T2(0x0000);
                                    PWM15_SET_REG_G0_CH0_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH1_T2(0x0000);
                                    PWM15_SET_REG_G0_CH1_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH2_T2(0x0000);
                                    PWM15_SET_REG_G0_CH2_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH3_T2(0x0000);
                                    PWM15_SET_REG_G0_CH3_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH4_T2(0x0000);
                                    PWM15_SET_REG_G0_CH4_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH5_T2(0x0000);
                                    PWM15_SET_REG_G0_CH5_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH6_T2(0x0000);
                                    PWM15_SET_REG_G0_CH6_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP0_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G0_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G0_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G0_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G0_CH7_T2(0x0000);
                                    PWM15_SET_REG_G0_CH7_T1((u32)PWM15_GET_REG_G0_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
            #if ECBM_PWM_GROUP1_EN
                case 1:{
                    switch(ch){
                        #if ECBM_PWM_GROUP1_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH0_T2(0x0000);
                                    PWM15_SET_REG_G1_CH0_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH1_T2(0x0000);
                                    PWM15_SET_REG_G1_CH1_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH2_T2(0x0000);
                                    PWM15_SET_REG_G1_CH2_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH3_T2(0x0000);
                                    PWM15_SET_REG_G1_CH3_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH4_T2(0x0000);
                                    PWM15_SET_REG_G1_CH4_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH5_T2(0x0000);
                                    PWM15_SET_REG_G1_CH5_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH6_T2(0x0000);
                                    PWM15_SET_REG_G1_CH6_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP1_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G1_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G1_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G1_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G1_CH7_T2(0x0000);
                                    PWM15_SET_REG_G1_CH7_T1((u32)PWM15_GET_REG_G1_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
            #if ECBM_PWM_GROUP2_EN
                case 2:{
                    switch(ch){
                        #if ECBM_PWM_GROUP2_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH0_T2(0x0000);
                                    PWM15_SET_REG_G2_CH0_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH1_T2(0x0000);
                                    PWM15_SET_REG_G2_CH1_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH2_T2(0x0000);
                                    PWM15_SET_REG_G2_CH2_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH3_T2(0x0000);
                                    PWM15_SET_REG_G2_CH3_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH4_T2(0x0000);
                                    PWM15_SET_REG_G2_CH4_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH5_T2(0x0000);
                                    PWM15_SET_REG_G2_CH5_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH6_T2(0x0000);
                                    PWM15_SET_REG_G2_CH6_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP2_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G2_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G2_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G2_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G2_CH7_T2(0x0000);
                                    PWM15_SET_REG_G2_CH7_T1((u32)PWM15_GET_REG_G2_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
            #if ECBM_PWM_GROUP3_EN
                case 3:{
                    switch(ch){
                        #if ECBM_PWM_GROUP3_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH0_T2(0x0000);
                                    PWM15_SET_REG_G3_CH0_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH1_T2(0x0000);
                                    PWM15_SET_REG_G3_CH1_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH2_T2(0x0000);
                                    PWM15_SET_REG_G3_CH2_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH3_T2(0x0000);
                                    PWM15_SET_REG_G3_CH3_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH4_T2(0x0000);
                                    PWM15_SET_REG_G3_CH4_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH5_T2(0x0000);
                                    PWM15_SET_REG_G3_CH5_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH6_T2(0x0000);
                                    PWM15_SET_REG_G3_CH6_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP3_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G3_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G3_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G3_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G3_CH7_T2(0x0000);
                                    PWM15_SET_REG_G3_CH7_T1((u32)PWM15_GET_REG_G3_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
            #if ECBM_PWM_GROUP4_EN
                case 4:{
                    switch(ch){
                        #if ECBM_PWM_GROUP4_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH0_T2(0x0000);
                                    PWM15_SET_REG_G4_CH0_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH1_T2(0x0000);
                                    PWM15_SET_REG_G4_CH1_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH2_T2(0x0000);
                                    PWM15_SET_REG_G4_CH2_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH3_T2(0x0000);
                                    PWM15_SET_REG_G4_CH3_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH4_T2(0x0000);
                                    PWM15_SET_REG_G4_CH4_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH5_T2(0x0000);
                                    PWM15_SET_REG_G4_CH5_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH6_T2(0x0000);
                                    PWM15_SET_REG_G4_CH6_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP4_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G4_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G4_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G4_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G4_CH7_T2(0x0000);
                                    PWM15_SET_REG_G4_CH7_T1((u32)PWM15_GET_REG_G4_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
            #if ECBM_PWM_GROUP5_EN
                case 5:{
                    switch(ch){
                        #if ECBM_PWM_GROUP5_CH0_EN
                            case 0:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH0_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH0_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH0_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH0_T2(0x0000);
                                    PWM15_SET_REG_G5_CH0_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH1_EN
                            case 1:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH1_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH1_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH1_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH1_T2(0x0000);
                                    PWM15_SET_REG_G5_CH1_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH2_EN
                            case 2:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH2_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH2_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH2_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH2_T2(0x0000);
                                    PWM15_SET_REG_G5_CH2_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH3_EN
                            case 3:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH3_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH3_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH3_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH3_T2(0x0000);
                                    PWM15_SET_REG_G5_CH3_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH4_EN
                            case 4:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH4_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH4_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH4_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH4_T2(0x0000);
                                    PWM15_SET_REG_G5_CH4_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH5_EN
                            case 5:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH5_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH5_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH5_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH5_T2(0x0000);
                                    PWM15_SET_REG_G5_CH5_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH6_EN
                            case 6:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH6_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH6_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH6_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH6_T2(0x0000);
                                    PWM15_SET_REG_G5_CH6_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        #if ECBM_PWM_GROUP5_CH7_EN
                            case 7:{
                                if(duty>=1000){
                                    PWM15_SET_G5_CH7_HOLD_H;
                                }else if(duty==0){
                                    PWM15_SET_G5_CH7_HOLD_L;
                                }else{
                                    PWM15_SET_G5_CH7_HOLD_OFF;
                                    PWM15_SET_REG_G5_CH7_T2(0x0000);
                                    PWM15_SET_REG_G5_CH7_T1((u32)PWM15_GET_REG_G5_COUNT*duty/1000);
                                }
                            }break;
                        #endif
                        default:break;
                    }
                }break;
            #endif
        #endif
    }
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��