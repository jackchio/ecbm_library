#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_ADC_LIB_EN)   //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
float xdata adc_ch15_gxf;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ADC��ʼ��������
-------------------------------------------------------*/
void adc_init(void){
    ADC_SET_REG_CFG(ECBM_ADC_CFG);          //����ADC������
    adc_ch15_gxf=(float)(REG_BGV)/1000.0f;  //���ڲ���ѹ��׼ȡ��������ֹ֮��idata���ǡ�
    #if (ECBM_ADC_IT_EN)                    //����ڽ�����ʹ����ADC���жϡ�
        ADC_IT_ENABLE;                      //�ʹ�ADC���жϡ�
    #endif
    #if (ECBM_ADC_PWM_EN)                   //����ڽ�����ʹ����ADC��PWM������
        ADC_PWM_ENABLE;                     //��ô�ʹ�ADC-PWMʹ�ܡ�
    #endif
    #if (ECBM_MCU==0x2815C4)                //�����STC8A8KxxD4_ALL
        ADC_SET_REG_EXCFG(ECBM_ADC_EXCFG);  //��������ADC�Ķ���Ĵ�����
    #endif
    #if (ECBM_ADC_CH0_EN)                   //���ADCͨ��0��ʹ�ܴ򿪣�
        gpio_mode(A00,GPIO_HZ);             //�ͰѶ�Ӧ����������Ϊ����̬��
    #endif                                  //�����ͨ��1~ͨ��14Ҳ�����������
    #if (ECBM_ADC_CH1_EN)
        gpio_mode(A01,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH2_EN)
        gpio_mode(A02,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH3_EN)
        gpio_mode(A03,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH4_EN)
        gpio_mode(A04,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH5_EN)
        gpio_mode(A05,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH6_EN)
        gpio_mode(A06,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH7_EN)
        gpio_mode(A07,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH8_EN)
        gpio_mode(A08,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH9_EN)
        gpio_mode(A09,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH10_EN)
        gpio_mode(A10,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH11_EN)
        gpio_mode(A11,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH12_EN)
        gpio_mode(A12,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH13_EN)
        gpio_mode(A13,GPIO_HZ);
    #endif
    #if (ECBM_ADC_CH14_EN)
        gpio_mode(A14,GPIO_HZ);
    #endif
    ADC_POWER_ON;//�����ֲᣬADC��Դ�򿪺���Ҫһ��ʱ����ڲ���·��硣�����ڳ�ʼ����򿪵�Դ��
}
/*-------------------------------------------------------
��ѯ����ȡADֵ������
-------------------------------------------------------*/
u16 adc_read(u8 ch){
    u16 timeout_u16=4800;   //ADCת��ʱ�仹�ܷ�Ƶ��Ӱ�죬����������һ���ϴ�ֵ��2ms@24MHz�ĳ�ʱʱ�����㡣
    ADC_SET_CHANNELS(ch);   //����Ҫ��ȡ��ͨ����
    ADC_MEASURE_ON;         //��ʼ������
    _nop_();                //�Ӽ�����ָ���ֹ��ˮ�߶������жϵ�Ӱ�졣
    _nop_();
    while((!(ADC_GET_IT_FLAG))&&(timeout_u16))timeout_u16--;//�ȴ�ת����ɡ�
    ADC_CLS_IT_FLAG;
    #if (ECBM_ADC_8BIT)     //ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
        return (u16)(ADC_GET_REG_RES_H8);//���ؽ���Ĵ�����ֵ��
    #else                   //�������12λ��ȡ������
        return (u16)(ADC_GET_REG_RES_HL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
    #endif
}
/*-------------------------------------------------------
ADCת����ʼ�������жϷ�����
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_read_start(u8 ch){
        ADC_SET_CHANNELS(ch);   //����Ҫ��ȡ��ͨ����
        ADC_MEASURE_ON;         //��ʼ������
        _nop_();                //�Ӽ�����ָ���ֹ��ˮ�߶������жϵ�Ӱ�졣
        _nop_();                //ʣ�¾��ǵȴ�ADC�ж��ˡ�
    }
#endif
/*-------------------------------------------------------
�жϷ���ȡADֵ������
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    u16 adc_read_it(void){
        #if (ECBM_ADC_8BIT) //ʹ��8λ����ģʽ�Ļ�������8λ��ȡ������
            return (u16)(ADC_GET_REG_RES_H8);//���ؽ���Ĵ�����ֵ��
        #else               //�������12λ��ȡ������
            return (u16)(ADC_GET_REG_RES_HL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
        #endif
    }
#endif
/*-------------------------------------------------------
��ȡ��ѹ������
-------------------------------------------------------*/
float adc_voltage(u8 ch,float vref){
    u16 jg_u16;
    jg_u16=adc_read(ch);    //�ȶ�ȡADֵ��
    #if (ECBM_ADC_8BIT)     //�������ã���ADֵ����ɵ�ѹֵ��
        return (((float)(jg_u16)*vref)/256.0f);//8λ���ݡ�
    #else
        return (((float)(jg_u16)*vref)/(ECBM_MCU_ADC_MAX));//10λ��12λ���ݡ�
    #endif
}
/*-------------------------------------------------------
����ADC�жϺ�����
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_it_start(void){
        ADC_IT_ENABLE;//��ADC�жϡ�
    }
#endif
/*-------------------------------------------------------
�ر�ADC�жϺ�����
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_it_stop(void){
        ADC_IT_DISABLE;//�ر�ADC�жϡ�
    }
#endif
/*-------------------------------------------------------
ADC��ȡVref������
-------------------------------------------------------*/
float adc_read_vref(void){
    u16 jg_u16;
    jg_u16=adc_read(15);        //�ȶ�ȡADֵ��  
    if(jg_u16==0)return 0.0f;   //��ֹ����NaN
    #if (ECBM_ADC_8BIT)         //�������ã���ADֵ����ɵ�ѹֵ��
        return (adc_ch15_gxf*256.0f)/((float)jg_u16);//8λ���ݡ�
    #else
        return (adc_ch15_gxf)*(ECBM_MCU_ADC_MAX)/((float)jg_u16);//10λ��12λ���ݡ�
    #endif
}
#endif  //���������#if��ϳ�һ������Ρ�
        //��һ������Ϊ��β��