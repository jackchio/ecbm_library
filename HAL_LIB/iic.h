#ifndef _ECBM_IIC_H_
#define _ECBM_IIC_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 ����

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

����˵����
	���������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ�������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽������ϵ��ʽ����Ⱥ778916610
------------------------------------------------------------------------------------*/

//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM��������ʹ��
//<i>��ѡ��򹴣���ζ��IIC���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣
//<i>��ѡ��򹴣���ζ��IIC���ܵ���ʹ�ã���������������ECBM�⺯����ֻ��Ҫ�߱�������stc8ͷ�ļ����ɡ�����ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����iic.h����ͬһ���ļ��С�
#define ECBM_IIC_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��IIC���裬����Ϊ0��
//<h>IIC���ڲ�����
//<o>IIC�ȴ�ʱ������
//<0-63:1>
//<i>������0~63��������ԽС�����ȴ�ʱ��Խ�٣�IIC���ٶ�Խ�졣���Ŀ���������ٶȸ����ϣ�������Ϊ0�Ի�ȡ����IICͨ���ٶȡ�
//<i>���Ŀ���������ٶȸ����ϣ�һ��ͨ�ų��������ֱ��ͨ��ʧ�ܣ������Դ�63��ʼһ��һ�������Ի��������ܡ����鷳Ҳ��ֱ����Ϊ63��
#define ECBM_IIC_WAIT 1
//<o>IICĬ�Ϲܽ�
//<i>������ֻ��Ķ���ʼ���Ĺܽţ���ʵ��Ӧ������ʱ����ʹ��iic_set_pin�����޸�IIC�ܽţ��ﵽ��ʱ���õ�Ч����
//<0=>SCL-P15|SDA-P14 <1=>SCL-P25|SDA-P24 <2=>SCL-P77|SDA-P76 <3=>SCL-P32|SDA-P33
#define ECBM_IIC_IO 3
//</h>
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------

/*---------------------------------------------����ͷ�ļ���Ԥ����---------------------------------------------*/
#if ECBM_IIC_LINK_EN      //�����ӵ�ecbm�����ʱ����Ҫ���������ļ���
#include "ecbm.h"         //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
#else                     //���Ҫ�����������У�ҲӦ���ṩSTC8��ͷ�ļ���ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ�
#include "stc.h"          //��STC-ISP��������ʱ������ΪSTC.h��
#include "intrins.h"      //ʹ��nopָ�������ͷ�ļ�
#define u8  unsigned char //����ʹ��IIC��ʱ���������ļ�д���ϡ�
#define u16 unsigned int
#define u32 unsigned long
#define s8    signed char
#define s16   signed int
#define s32   signed long
#endif
/*-----------------------------------------------------------------------------------------------------------*/
bit iic_busy;
void iic_isr() interrupt 24
{
    if (I2CMSST&0x40){
        I2CMSST&=~0x40;//���жϱ�־
        iic_busy=0;
    }
}
void iic_start(){
    iic_busy=1;
    I2CMSCR=0x81;   //����START����
    while(iic_busy);
}
void iic_stop(){
    iic_busy = 1;
    I2CMSCR=0x86;  //����STOP����
    while(iic_busy);
}
void iic_write(char dat){
    I2CTXD=dat;    //д���ݵ����ݻ�����
    iic_busy=1;
    I2CMSCR=0x82;  //����SEND����
    while(iic_busy);
}
void iic_write_ack(){
    I2CMSST=0x00; // ����ACK�ź�
    iic_busy=1;
    I2CMSCR=0x85; //����ACK����
    while(iic_busy);  
}
void iic_write_nack(){
    I2CMSST=0x01; //����NAK�ź�
    iic_busy=1;
    I2CMSCR=0x85; //����ACK����
    while(iic_busy);
}
char iic_read(){
    iic_busy=1;
    I2CMSCR=0x84;  //����RECV����
    while(iic_busy);
    return I2CRXD;
}
bit iic_read_ack(){
    iic_busy=1;
    I2CMSCR=0x83; //���Ͷ�ACK����
    while(iic_busy);
	return (I2CMSST&0x02)>>1;
}
#if ECBM_IIC_LINK_EN
void iic_set_pin(u8 group){
	switch(group){
		case 0:{
			gpio_mode(D14,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_mode(D15,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_uppull(D14,1);    //IIC��Ҫһ����������
			gpio_uppull(D15,1);    //IIC��Ҫһ����������
			P_SW2&=0xCF;           //�л���D14��D15
		}break;
		case 1:{
			gpio_mode(D24,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_mode(D25,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_uppull(D24,1);    //IIC��Ҫһ����������
			gpio_uppull(D25,1);    //IIC��Ҫһ����������
			P_SW2&=0xDF;           //�л���D24��D25
			P_SW2|=0x10;
		}break;
		case 2:{
			gpio_mode(D76,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_mode(D77,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_uppull(D76,1);    //IIC��Ҫһ����������
			gpio_uppull(D77,1);    //IIC��Ҫһ����������
			P_SW2|=0x20;           //�л���D76��D77
			P_SW2&=0xEF;
		}break;
		case 3:{
			gpio_mode(D32,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_mode(D33,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
			gpio_uppull(D32,1);    //IIC��Ҫһ����������
			gpio_uppull(D33,1);    //IIC��Ҫһ����������
			P_SW2|=0x30;           //�л���D32��D33
		}break;
	}
}
void iic_reset_pin(u8 group){
	switch(group){
		case 0:{
			gpio_mode(D14,GPIO_IN);//�ָ�������ģʽ
			gpio_mode(D15,GPIO_IN);//�ָ�������ģʽ
			gpio_uppull(D14,0);    //�Ͽ���������
			gpio_uppull(D15,0);    //�Ͽ���������
		}break;
		case 1:{
			gpio_mode(D24,GPIO_IN);//�ָ�������ģʽ
			gpio_mode(D25,GPIO_IN);//�ָ�������ģʽ
			gpio_uppull(D24,0);    //�Ͽ���������
			gpio_uppull(D25,0);    //�Ͽ���������
		}break;
		case 2:{
			gpio_mode(D76,GPIO_IN);//�ָ�������ģʽ
			gpio_mode(D77,GPIO_IN);//�ָ�������ģʽ
			gpio_uppull(D76,0);    //�Ͽ���������
			gpio_uppull(D77,0);    //�Ͽ���������         
		}break;
		case 3:{
			gpio_mode(D32,GPIO_IN);//�ָ�������ģʽ
			gpio_mode(D33,GPIO_IN);//�ָ�������ģʽ
			gpio_uppull(D32,0);    //�Ͽ���������
			gpio_uppull(D33,0);    //�Ͽ���������   
		}break;
	}
}
#else
void iic_set_pin(u8 group){
	switch(group){
		case 0:{
			P1M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P1M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P1PU|=0x30;//0011 0000 IIC��Ҫһ����������
			P_SW2&=0xCF;           //�л���D14��D15
		}break;
		case 1:{
			P2M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P2M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
			P2PU|=0x30;//0011 0000 IIC��Ҫһ����������
			P_SW2&=0xDF;           //�л���D24��D25
			P_SW2|=0x10;
		}break;
		case 2:{
			P7M1|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
			P7M0|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
			P7PU|=0xC0;//1100 0000 IIC��Ҫһ����������
			P_SW2|=0x20;           //�л���D76��D77
			P_SW2&=0xEF;
		}break;
		case 3:{
			P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
			P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
			P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������
			P_SW2|=0x30;           //�л���D32��D33
		}break;
	}
}
void iic_reset_pin(u8 group){
	switch(group){
		case 0:{
			P1M1&=0xCF;//1100 1111 �ָ�������ģʽ
			P1M0&=0xCF;//1100 1111 �ָ�������ģʽ
			P1PU&=0xCF;//1100 1111 �Ͽ���������
		}break;
		case 1:{
			P2M1&=0xCF;//1100 1111 �ָ�������ģʽ
			P2M0&=0xCF;//1100 1111 �ָ�������ģʽ
			P2PU&=0xCF;//1100 1111 �Ͽ���������
		}break;
		case 2:{
			P7M1&=0x3F;//0011 1111 �ָ�������ģʽ
			P7M0&=0x3F;//0011 1111 �ָ�������ģʽ
			P7PU&=0x3F;//0011 1111 �Ͽ���������       
		}break;
		case 3:{
			P3M1&=0xF3;//1111 0011 �ָ�������ģʽ
			P3M0&=0xF3;//1111 0011 �ָ�������ģʽ
			P3PU&=0xF3;//1111 0011 �Ͽ���������
		}break;
	}
}
#endif
void iic_master_init(){
	#if ECBM_IIC_LINK_EN == 0       //����Ƕ���ʹ�ã�����Ҫ�������Ĵ�����ʹ��
	P_SW2|=0x80;
	_nop_();EA=1;_nop_();
	#endif
	I2CCFG=0x80|0x40|ECBM_IIC_WAIT; //����IIC|����|�ȴ�ʱ��
	I2CMSST=0x00;                   //������б�־λ
	iic_set_pin(ECBM_IIC_IO);                 //Ĭ��ʹ��0�飬��P14��P15
}
void iic_slave_init(){
	#if ECBM_IIC_LINK_EN == 0       //����Ƕ���ʹ�ã�����Ҫ�������Ĵ�����ʹ��
	P_SW2|=0x80;
	_nop_();EA=1;_nop_();
	#endif
	I2CCFG=0x80|0x00|ECBM_IIC_WAIT; //����IIC|�ӻ�|�ȴ�ʱ��
	I2CMSST=0x00;                   //������б�־λ
	iic_set_pin(ECBM_IIC_IO);
}

#endif
