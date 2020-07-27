#include "hx7xx.h"//ͳһ���غ���ͷ�ļ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
hx7xxϵ�еĳ�ʼ��������
-------------------------------------------------------*/
void hx7xx_init(hx7xx_def * dev,u8 sck,u8 sda){
	dev->sck_port=io2port(sck);//����IO��Ϣ�����档
	dev->sck_pin =io2pin (sck);
	dev->sda_port=io2port(sda);
	dev->sda_pin =io2pin (sda);
	dev->dat=0;					//���������ڳ�ʼ����ʱ�����㡣
	gpio_mode(sda,GPIO_IN);		//IO������Ϊ�����͡�
	gpio_mode(sck,GPIO_IN);
	gpio_out(sda,1);			//���е�ƽΪ�ߡ�
	gpio_out(sck,1);			//���е�ƽΪ�ߡ�
}
/*-------------------------------------------------------
hx7xxϵ�е����к�����
-------------------------------------------------------*/
void hx7xx_run(hx7xx_def * dev,u8 next){
	signed long temp;
	u8 i;
	u16 time=5000,_10us;
	_10us=delay_set_us(10);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);//ʱ�����ͣ�ʹ��AD��
	temp=0;
	gpio_out_fast(dev->sda_port,dev->sda_pin,1);//��֤���ݽ�Ϊ�ߡ���Ϊ����������ʱ��оƬ���������ݽš�
	while((gpio_in_fast(dev->sda_port,dev->sda_pin))&&(time--))delay_ms(1);//����û����˵��ADת��δ��������ȴ�������ʼ��ȡ��
	for (i=0;i<24;i++){//��ȡ24λ���ݡ�
		gpio_out_fast(dev->sck_port,dev->sck_pin,1); //ʱ�ӽ��øߣ��������壩
		delay_us(_10us);
		temp=temp<<1; //�½�����ʱ����temp����һλ���Ҳಹ��
		gpio_out_fast(dev->sck_port,dev->sck_pin,0); //ʱ�ӽ��õ�
		delay_us(_10us);
		if(gpio_in_fast(dev->sda_port,dev->sda_pin)){//���ݽŸߵ�ƽʱ��
			temp++;									 //��ʱ���������1���������ƻᲹ0���������ݽŵ͵�ƽ��������ÿ��ǡ�
		}
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��25�������½�����ʱ��ת������
	delay_us(_10us);
	gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	if(next>0){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��26�������½�����ʱ��ת������
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(next==2){
		gpio_out_fast(dev->sck_port,dev->sck_pin,1);//��27�������½�����ʱ��ת������
		delay_us(_10us);
		gpio_out_fast(dev->sck_port,dev->sck_pin,0);
	}
	if(time==0){//����������ȴ���ʱ��ʱ�ˣ�
		dev->dat=0;//������Ϊ0��
	}else{//����Ͱ��������ݴ���
		if(temp&(0x800000))temp|=0xFF000000;
		dev->dat=temp;
	}
	gpio_out_fast(dev->sck_port,dev->sck_pin,1);//����ʱ�ӽţ�����ͨ�š�
}
