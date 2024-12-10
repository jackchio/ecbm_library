#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_LED_LIB_EN)   //检查本库有没有被使能
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
LED外设初始化函数。
-------------------------------------------------------*/
void led_init(void){
    LED_SET_REG_COMEN(ECBM_LED_COM_EN);
    LED_SET_REG_SEGENL(ECBM_LED_SEGL_EN);
    LED_SET_REG_SEGENH(ECBM_LED_SEGH_EN);
    LED_SET_REG_CTRL(ECBM_LED_CTRL);
    LED_SET_REG_CKS(ECBM_LED_CLK_DIV);
}
/*-------------------------------------------------------
LED开始工作函数。
-------------------------------------------------------*/
void led_start(void){
    LED_POWER_ON;
}
/*-------------------------------------------------------
LED停止工作函数。
-------------------------------------------------------*/
void led_stop(void){
    LED_POWER_OFF;
}
/*-------------------------------------------------------
LED工作设置函数。
-------------------------------------------------------*/
void led_set_mode(u8 mode){
    switch(mode){
        case LED_MODE_DC :{LED_SET_MODE_DC; }break;
        case LED_MODE_DA :{LED_SET_MODE_DA; }break;
        case LED_MODE_DCA:{LED_SET_MODE_DCA;}break;
    }
}
/*-------------------------------------------------------
LED亮度设置函数。
-------------------------------------------------------*/
void led_set_duty(u8 duty){
    LED_SET_DUTY(duty);
}
/*-------------------------------------------------------
LED驱动频率函数。
-------------------------------------------------------*/
void led_set_freq(u8 freq){
    //正在施工，等待芯片过来测试。
    freq=freq;
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。