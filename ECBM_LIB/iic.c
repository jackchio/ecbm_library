#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_IIC_EN
/*--------------------------------------��������-----------------------------------*/
bit iic_busy;
u8 xdata iic_index;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
IIC���������ú�����
-------------------------------------------------------*/
void iic_set_pin(u8 group){
	switch(group){
		case IIC_PIN_P1:{//�л���D14��D15
			P1M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P1M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P1PU|=0x30;//0011 0000 IIC��Ҫһ����������       
		}break;
		case IIC_PIN_P2:{//�л���D24��D25
			P2M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P2M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P2PU|=0x30;//0011 0000 IIC��Ҫһ����������
		}break;
		case IIC_PIN_P7:{//�л���D76��D77
			P7M1|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
			P7M0|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
			P7PU|=0xC0;//1100 0000 IIC��Ҫһ����������
		}break;
		case IIC_PIN_P3:{//�л���D32��D33
			P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
			P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
			P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������
		}break;
		#if SYS_ERROR_EN
		default:error_printf("iic_set_pin(<%d>);�����ڸ���\r\n",(u16)group);break;
		#else
		default:while(1);break;
		#endif
	}
	P_SW2&=0xCF;
	P_SW2|=group;
}
/*-------------------------------------------------------
IIC���������ú����������棩��
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group){
	if(iic_index!=group){
		iic_index=group;
		I2CCFG&=0x7F;
		P_SW2&=0xCF;
		P_SW2|=group;
		I2CCFG|=0x80;
	}
}
/*-------------------------------------------------------
IIC�����Ż�ԭ������
-------------------------------------------------------*/
void iic_reset_pin(u8 group){
	switch(group){
		case IIC_PIN_P1:{
			P1M1&=0xCF;//1100 1111 �ָ�������ģʽ
			P1M0&=0xCF;//1100 1111 �ָ�������ģʽ
			P1PU&=0xCF;//1100 1111 �Ͽ���������
		}break;
		case IIC_PIN_P2:{
			P2M1&=0xCF;//1100 1111 �ָ�������ģʽ
			P2M0&=0xCF;//1100 1111 �ָ�������ģʽ
			P2PU&=0xCF;//1100 1111 �Ͽ���������
		}break;
		case IIC_PIN_P7:{
			P7M1&=0x3F;//0011 1111 �ָ�������ģʽ
			P7M0&=0x3F;//0011 1111 �ָ�������ģʽ
			P7PU&=0x3F;//0011 1111 �Ͽ���������       
		}break;
		case IIC_PIN_P3:{
			P3M1&=0xF3;//1111 0011 �ָ�������ģʽ
			P3M0&=0xF3;//1111 0011 �ָ�������ģʽ
			P3PU&=0xF3;//1111 0011 �Ͽ���������
		}break;
		#if SYS_ERROR_EN
		default:error_printf("iic_reset_pin(<%d>);�����ڸ���\r\n",(u16)group);break;
		#else
		default:while(1);break;
		#endif
	}
}
/*-------------------------------------------------------
IIC������ʼ��������
-------------------------------------------------------*/
void iic_master_init(void){
	I2CCFG=0x80|0x40|ECBM_IIC_WAIT; //����IIC|����|�ȴ�ʱ��
	I2CMSST=0x00;                   //������б�־λ
	iic_set_pin(ECBM_IIC_IO);       //Ĭ��ʹ��0�飬��P14��P15
	iic_index=ECBM_IIC_IO;
}
/*-------------------------------------------------------
IIC�ӻ���ʼ��������
-------------------------------------------------------*/
void iic_slave_init(void){
	I2CCFG=0x80|0x00|ECBM_IIC_WAIT; //����IIC|�ӻ�|�ȴ�ʱ��
	I2CMSST=0x00;                   //������б�־λ
	iic_set_pin(ECBM_IIC_IO);
	iic_index=ECBM_IIC_IO;
}
/*-------------------------------------------------------
��������iic_isr
��  ����IIC�жϺ���������IIC��Ҫ�����жϣ����Ծ�д�ڿ��У������������������ж����������¡�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣��ޣ�������á�
�������ڣ�2019-8-23
�޸ļ�¼��
-------------------------------------------------------*/
void iic_isr() interrupt 24
{
    if (I2CMSST&0x40){
        I2CMSST&=0xBF;//~0x40;//���жϱ�־
        iic_busy=0;
    }
}
/*-------------------------------------------------------
IIC�ĸ��ֲ��������������������Э�����Ų���
iic_start     :��ʼ��������ӦIIC��ʼ֡��
iic_stop      :ֹͣ��������ӦIICֹͣ֡��
iic_write     :д���ݺ�������������д1�ֽ����ݡ�
iic_write_ack :дACK��������������дһ��ACK��
iic_write_nack:дNO ACK��������������дһ��NO ACK��
iic_read      :�����ݺ�������ȡ������һ���ֽڵ����ݡ�
iic_read_ack  :��ACK��������ȡ�������Ƿ���ACK��
-------------------------------------------------------*/
void iic_start(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x81;   //����START����
    while(iic_busy&&(timeout--));
}
void iic_stop(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy = 1;
    I2CMSCR=0x86;  //����STOP����
    while(iic_busy&&(timeout--));//while(iic_busy);
}
void iic_write(u8 dat){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CTXD=dat;    //д���ݵ����ݻ�����
    iic_busy=1;
    I2CMSCR=0x82;  //����SEND����
    while(iic_busy&&(timeout--));//while(iic_busy);
}
void iic_write_ack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CMSST=0x00; // ����ACK�ź�
    iic_busy=1;
    I2CMSCR=0x85; //����ACK����
    while(iic_busy&&(timeout--));//while(iic_busy);  
}
void iic_write_nack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    I2CMSST=0x01; //����NAK�ź�
    iic_busy=1;
    I2CMSCR=0x85; //����ACK����
    while(iic_busy&&(timeout--));//while(iic_busy);
}
u8 iic_read(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x84;  //����RECV����
    while(iic_busy&&(timeout--));//while(iic_busy);
    return I2CRXD;
}
bit iic_read_ack(){
	u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    I2CMSCR=0x83; //���Ͷ�ACK����
    while(iic_busy&&(timeout--));//while(iic_busy);
	return (I2CMSST&0x02)>>1;
}
#endif
