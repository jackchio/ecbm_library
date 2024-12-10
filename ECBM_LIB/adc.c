#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_ADC_LIB_EN)   //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
float xdata adc_ch15_gxf;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
ADC初始化函数。
-------------------------------------------------------*/
void adc_init(void){
    ADC_SET_REG_CFG(ECBM_ADC_CFG);          //设置ADC的配置
    adc_ch15_gxf=(float)(REG_BGV)/1000.0f;  //将内部电压基准取出来，防止之后idata覆盖。
    #if (ECBM_ADC_IT_EN)                    //如果在界面里使能了ADC的中断。
        ADC_IT_ENABLE;                      //就打开ADC的中断。
    #endif
    #if (ECBM_ADC_PWM_EN)                   //如果在界面里使能了ADC和PWM联动，
        ADC_PWM_ENABLE;                     //那么就打开ADC-PWM使能。
    #endif
    #if (ECBM_MCU==0x2815C4)                //如果是STC8A8KxxD4_ALL
        ADC_SET_REG_EXCFG(ECBM_ADC_EXCFG);  //就再配置ADC的额外寄存器。
    #endif
    #if (ECBM_ADC_CH0_EN)                   //如果ADC通道0的使能打开，
        gpio_mode(A00,GPIO_HZ);             //就把对应的引脚设置为高阻态。
    #endif                                  //下面的通道1~通道14也是这个动作。
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
    ADC_POWER_ON;//根据手册，ADC电源打开后需要一定时间给内部电路充电。所以在初始化里打开电源。
}
/*-------------------------------------------------------
查询法读取AD值函数。
-------------------------------------------------------*/
u16 adc_read(u8 ch){
    u16 timeout_u16=4800;   //ADC转换时间还受分频的影响，所以这里以一个较大值即2ms@24MHz的超时时间来算。
    ADC_SET_CHANNELS(ch);   //设置要读取的通道。
    ADC_MEASURE_ON;         //开始测量。
    _nop_();                //加几个空指令防止流水线对下面判断的影响。
    _nop_();
    while((!(ADC_GET_IT_FLAG))&&(timeout_u16))timeout_u16--;//等待转换完成。
    ADC_CLS_IT_FLAG;
    #if (ECBM_ADC_8BIT)     //使能8位数据模式的话，编译8位读取函数。
        return (u16)(ADC_GET_REG_RES_H8);//返回结果寄存器的值。
    #else                   //否则编译12位读取函数。
        return (u16)(ADC_GET_REG_RES_HL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
    #endif
}
/*-------------------------------------------------------
ADC转换开始函数（中断法）。
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_read_start(u8 ch){
        ADC_SET_CHANNELS(ch);   //设置要读取的通道。
        ADC_MEASURE_ON;         //开始测量。
        _nop_();                //加几个空指令防止流水线对下面判断的影响。
        _nop_();                //剩下就是等待ADC中断了。
    }
#endif
/*-------------------------------------------------------
中断法读取AD值函数。
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    u16 adc_read_it(void){
        #if (ECBM_ADC_8BIT) //使能8位数据模式的话，编译8位读取函数。
            return (u16)(ADC_GET_REG_RES_H8);//返回结果寄存器的值。
        #else               //否则编译12位读取函数。
            return (u16)(ADC_GET_REG_RES_HL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
        #endif
    }
#endif
/*-------------------------------------------------------
读取电压函数。
-------------------------------------------------------*/
float adc_voltage(u8 ch,float vref){
    u16 jg_u16;
    jg_u16=adc_read(ch);    //先读取AD值。
    #if (ECBM_ADC_8BIT)     //根据设置，把AD值换算成电压值。
        return (((float)(jg_u16)*vref)/256.0f);//8位数据。
    #else
        return (((float)(jg_u16)*vref)/(ECBM_MCU_ADC_MAX));//10位或12位数据。
    #endif
}
/*-------------------------------------------------------
开启ADC中断函数。
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_it_start(void){
        ADC_IT_ENABLE;//打开ADC中断。
    }
#endif
/*-------------------------------------------------------
关闭ADC中断函数。
-------------------------------------------------------*/
#if (ECBM_ADC_IT_EN)
    void adc_it_stop(void){
        ADC_IT_DISABLE;//关闭ADC中断。
    }
#endif
/*-------------------------------------------------------
ADC读取Vref函数。
-------------------------------------------------------*/
float adc_read_vref(void){
    u16 jg_u16;
    jg_u16=adc_read(15);        //先读取AD值。  
    if(jg_u16==0)return 0.0f;   //防止出现NaN
    #if (ECBM_ADC_8BIT)         //根据设置，把AD值换算成电压值。
        return (adc_ch15_gxf*256.0f)/((float)jg_u16);//8位数据。
    #else
        return (adc_ch15_gxf)*(ECBM_MCU_ADC_MAX)/((float)jg_u16);//10位或12位数据。
    #endif
}
#endif  //和最上面的#if配合成一个程序段。
        //以一个空行为结尾。