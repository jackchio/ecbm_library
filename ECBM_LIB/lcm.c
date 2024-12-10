#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_LCM_LIB_EN)      //��鱾����û�б�ʹ��
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_MCU!=0x2815C4)
#   error ��ʹ�ô�LCM����ĵ�Ƭ���ͺţ�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
LCM�ӿڳ�ʼ������
-------------------------------------------------------*/
void lcm_init(void){
    LCMIFCFG =ECBM_LCM_CFG1;//��ͼ�λ�����д��LCM���üĴ���1��
    LCMIFCFG2=ECBM_LCM_CFG2;//��ͼ�λ�����д��LCM���üĴ���2��
    #if   ((ECBM_LCM_CFG1&0x0E)==0x00)//������������ʼ����Ӧ��IO�ڡ�
        P2M1=0x00;//�����������ó���������׼˫��ڡ���ͬ��
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
        gpio_mode(D41,GPIO_OUT);//�����������ó����죬��ͬ��
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
LCM����8λָ���
-------------------------------------------------------*/
void lcm_write_8cmd(u8 cmd){
    u16 timeout_u16=4800;//2ms@24MHz�ĳ�ʱʱ�䡣
    LCMIFDATL=cmd;          //д��Ҫ���͵�ָ�
    LCM_WRITE_CMD;          //����������ָ�������
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //�ȴ�������ϡ�
    LCM_CLS_FLAG;           //��ձ�־λ��
}
/*-------------------------------------------------------
LCM����8λ���ݺ���
-------------------------------------------------------*/
void lcm_write_8data(u8 dat){
    u16 timeout_u16=4800;//2ms@24MHz�ĳ�ʱʱ�䡣
    LCMIFDATL=dat;          //д��Ҫ���͵����ݡ�
    LCM_WRITE_DATA;         //�������������ݡ�������
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //�ȴ�������ϡ�
    LCM_CLS_FLAG;           //��ձ�־λ��
}
/*-------------------------------------------------------
LCM����16λָ���
-------------------------------------------------------*/
void lcm_write_16cmd(u16 cmd){
    u16 timeout_u16=4800;//2ms@24MHz�ĳ�ʱʱ�䡣
    LCMIFDATH=(u8)(cmd>>8); //д��Ҫ���͵�ָ��ĸ�8λ��
    LCMIFDATL=(u8)(cmd);    //д��Ҫ���͵�ָ��ĵ�8λ��
    LCM_WRITE_CMD;          //����������ָ�������
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //�ȴ�������ϡ�
    LCM_CLS_FLAG;           //��ձ�־λ��
}
/*-------------------------------------------------------
LCM����16λ���ݺ���
-------------------------------------------------------*/
void lcm_write_16data(u16 dat){
    u16 timeout_u16=4800;//2ms@24MHz�ĳ�ʱʱ�䡣
    LCMIFDATH=(u8)(dat>>8); //д��Ҫ���͵����ݵĸ�8λ��
    LCMIFDATL=(u8)(dat);    //д��Ҫ���͵����ݵĵ�8λ��
    LCM_WRITE_DATA;         //�������������ݡ�������
    while((LCM_GET_FLAG==0)&&(timeout_u16))timeout_u16--; //�ȴ�������ϡ�
    LCM_CLS_FLAG;           //��ձ�־λ��
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��