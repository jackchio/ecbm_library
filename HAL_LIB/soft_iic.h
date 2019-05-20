#ifndef _ECBM_SOFT_IIC_H_
#define _ECBM_SOFT_IIC_H_
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
//<i>��ѡ��򹴣���ζ��SOFT_IIC���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣
//<i>��ѡ��򹴣���ζ��SOFT_IIC���ܵ���ʹ�ã���������������ECBM�⺯����ֻ��Ҫ�߱�������stc8ͷ�ļ����ɡ�����ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
//<i>����ʹ��SOFT_IIC��Ļ�����Ҫ�ֶ��Ѷ�Ӧ��IO������Ϊ��©ģʽ��������Ӳ���Ͻ���4.7K���ҵ��������衣������ܻ���ͨ���ϵ����⡣
//<i>stc8ͷ�ļ��ɴ�STC-ISP���ߵ������ɡ���STC-ISP��������ͷ�ļ�ʱ��������Ϊstc.h����iic.h����ͬһ���ļ��С�
#define ECBM_SOFT_IIC_LINK_EN 1 //��ecbm�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��SOFT_IIC���裬����Ϊ0��
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_SOFT_IIC_LINK_EN
typedef struct{
	u8 scl_port;
	u8 scl_pin;
	u8 sda_port;
	u8 sda_pin;
//	u16 iic_delay;
}soft_iic_def;
void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda){
	dev->scl_port=scl>>4;
	dev->scl_pin=0x01<<(scl&0x0f);
	dev->sda_port=sda>>4;
	dev->sda_pin=0x01<<(sda&0x0f);
	gpio_mode(scl,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
	gpio_mode(sda,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
	gpio_uppull(scl,1);    //IIC��Ҫһ����������
	gpio_uppull(sda,1);    //IIC��Ҫһ����������
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	dev->iic_delay=delay_set_us(1);
}
//IIC��������
u8	soft_iic_start(soft_iic_def * dev){
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==0)return -1;/* SDA��Ϊ�͵�ƽ������æ,�˳� */
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
//	delay_us(dev->iic_delay);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1)return -1;/* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	return 0;
}
//IICֹͣ����
void soft_iic_stop(soft_iic_def * dev){
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
}
//��������һ��ACK
void soft_iic_write_ack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,0);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
}
//��������һ����ACk
void soft_iic_write_nack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
}
//�ȴ��ӻ�����һ��ACK
unsigned char soft_iic_read_ack(soft_iic_def * dev){
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	gpio_out_fast(dev->scl_port,dev->scl_pin,1);
	if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1){
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
		return -1;
	}
	gpio_out_fast(dev->scl_port,dev->scl_pin,0);
	return 0;
}
//��IIC�����Ϸ���һ���ֽڵ�����
void soft_iic_write(soft_iic_def * dev,u8 dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x80){
			gpio_out_fast(dev->sda_port,dev->sda_pin,1);
		}
		else{
			gpio_out_fast(dev->sda_port,dev->sda_pin,0);
		}
		gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//		delay_us(dev->iic_delay);
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
		dat<<=1;
//		delay_us(dev->iic_delay);
	}
}
//��IIC�����϶�ȡһ���ֽڵ�����
unsigned char soft_iic_read(soft_iic_def * dev){
	unsigned char i,dat;
	dat=0;
//	delay_us(dev->iic_delay);
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);
	for(i=0;i<8;i++){
		dat<<=1;
		gpio_out_fast(dev->scl_port,dev->scl_pin,1);
//		delay_us(dev->iic_delay);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)==1){
			dat|=0x01;
		}
//		else{
//			dat&=0xfe;
//		}
		gpio_out_fast(dev->scl_port,dev->scl_pin,0);
//		delay_us(dev->iic_delay);
	}
	return dat;
}
#else
sbit soft_iic_scl=P1^0;
sbit soft_iic_sda=P1^1;
void soft_iic_init(){
	soft_iic_sda=1;
	soft_iic_scl=1;
}
//IIC��������
u8	soft_iic_start(){
	soft_iic_sda=1;
	soft_iic_scl=1;
	if(soft_iic_sda==0)return -1;/* SDA��Ϊ�͵�ƽ������æ,�˳� */
	soft_iic_sda=0;
	if(soft_iic_sda==1)return -1;/* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
	soft_iic_sda=0;
	soft_iic_scl=0;
	return 0;
}
//IICֹͣ����
void soft_iic_stop(){
	soft_iic_sda=0;
	soft_iic_scl=0;
	soft_iic_scl=1;
	soft_iic_sda=1;
}
//��������һ��ACK
void soft_iic_write_ack(){
	soft_iic_scl=0;
	soft_iic_sda=0;
	soft_iic_scl=1;
	soft_iic_scl=0;
}
//��������һ����ACk
void soft_iic_write_nack(){
	soft_iic_scl=0;
	soft_iic_sda=1;
	soft_iic_scl=1;
	soft_iic_scl=0;
}
//�ȴ��ӻ�����һ��ACK
unsigned char soft_iic_read_ack(){
	soft_iic_scl=0;
	soft_iic_sda=1;
	soft_iic_scl=1;
	if(soft_iic_sda==1){
		soft_iic_scl=0;
		return -1;
	}
	soft_iic_scl=0;
	return 0;
}
//��IIC�����Ϸ���һ���ֽڵ�����
void soft_iic_write(u8 dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x80){
			soft_iic_sda=1;
		}
		else{
			soft_iic_sda=0;
		}
		soft_iic_scl=1;
		soft_iic_scl=0;
		dat<<=1;
	}
}
//��IIC�����϶�ȡһ���ֽڵ�����
unsigned char soft_iic_read(){
	unsigned char i,dat;
	dat=0;
	soft_iic_sda=1;
	for(i=0;i<8;i++){
		dat<<=1;
		soft_iic_scl=1;
		if(soft_iic_sda==1){
			dat|=0x01;
		}
		soft_iic_scl=0;
	}
	return dat;
}
#endif
#endif
