#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_LCM_LIB_EN)      //检查本库有没有被使能
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_MCU!=0x2815C4)
#   error 请使用带LCM外设的单片机型号！
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
LCM接口初始化函数
-------------------------------------------------------*/
void lcm_init(void){
    LCMIFCFG =ECBM_LCM_CFG1;//把图形化配置写入LCM配置寄存器1。
    LCMIFCFG2=ECBM_LCM_CFG2;//把图形化配置写入LCM配置寄存器2。
    #if   ((ECBM_LCM_CFG1&0x0E)==0x00)//根据配置来初始化相应的IO口。
        P2M1=0x00;//数据总线配置成弱上拉，准双向口。下同。
        P2M0=0x00;
    #elif ((ECBM_LCM_CFG1&0x0E)==0x04)
        P6M1=0x00;
        P6M0=0x00;
    #elif ((ECBM_LCM_CFG1&0x0E)==0x02)
        P2M1=0x00;
        P2M0=0x00;
        P0M1=0x00;
        P0M0=0x00;
    #elif ((ECBM_LCM_CFG1&0x0E)==0x06)
        P2M1=0x00;
        P2M0=0x00;
        P6M1=0x00;
        P6M0=0x00;
    #elif ((ECBM_LCM_CFG1&0x0E)==0x0A)
        P2M1=0x00;
        P2M0=0x00;
        P7M1=0x00;
        P7M0=0x00;
    #elif ((ECBM_LCM_CFG1&0x0E)==0x0E)
        P6M1=0x00;
        P6M0=0x00;
        P7M1=0x00;
        P7M0=0x00;
    #endif
    #if   ((ECBM_LCM_CFG2&0x60)==0x00)
        gpio_mode(D41,GPIO_OUT);//控制总线配置成推挽，下同。
        gpio_mode(D44,GPIO_OUT);
        gpio_mode(D43,GPIO_OUT);
    #elif ((ECBM_LCM_CFG2&0x60)==0x20)
        gpio_mode(D41,GPIO_OUT);
        gpio_mode(D37,GPIO_OUT);
        gpio_mode(D36,GPIO_OUT);
    #elif ((ECBM_LCM_CFG2&0x60)==0x40)
        gpio_mode(D41,GPIO_OUT);
        gpio_mode(D42,GPIO_OUT);
        gpio_mode(D40,GPIO_OUT);
    #elif ((ECBM_LCM_CFG2&0x60)==0x60)
        gpio_mode(D40,GPIO_OUT);
        gpio_mode(D37,GPIO_OUT);
        gpio_mode(D36,GPIO_OUT);
    #endif
}
/*-------------------------------------------------------
LCM发送8位指令函数
-------------------------------------------------------*/
void lcm_write_8cmd(u8 cmd){
    u16 timeout_u16=4800;//2ms@24MHz的超时时间。
    LCMIFDATL=cmd;          //写入要发送的指令。
    LCM_WRITE_CMD;          //触发“发送指令”动作。
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //等待发送完毕。
    LCM_CLS_FLAG;           //清空标志位。
}
/*-------------------------------------------------------
LCM发送8位数据函数
-------------------------------------------------------*/
void lcm_write_8data(u8 dat){
    u16 timeout_u16=4800;//2ms@24MHz的超时时间。
    LCMIFDATL=dat;          //写入要发送的数据。
    LCM_WRITE_DATA;         //触发“发送数据”动作。
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //等待发送完毕。
    LCM_CLS_FLAG;           //清空标志位。
}
/*-------------------------------------------------------
LCM发送16位指令函数
-------------------------------------------------------*/
void lcm_write_16cmd(u16 cmd){
    u16 timeout_u16=4800;//2ms@24MHz的超时时间。
    LCMIFDATH=(u8)(cmd>>8); //写入要发送的指令的高8位。
    LCMIFDATL=(u8)(cmd);    //写入要发送的指令的低8位。
    LCM_WRITE_CMD;          //触发“发送指令”动作。
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //等待发送完毕。
    LCM_CLS_FLAG;           //清空标志位。
}
/*-------------------------------------------------------
LCM发送16位数据函数
-------------------------------------------------------*/
void lcm_write_16data(u16 dat){
    u16 timeout_u16=4800;//2ms@24MHz的超时时间。
    LCMIFDATH=(u8)(dat>>8); //写入要发送的数据的高8位。
    LCMIFDATL=(u8)(dat);    //写入要发送的数据的低8位。
    LCM_WRITE_DATA;         //触发“发送数据”动作。
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //等待发送完毕。
    LCM_CLS_FLAG;           //清空标志位。
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。