#include "ds1302.h"//ͳһ���غ���ͷ�ļ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
DS1302��д������
-------------------------------------------------------*/
void ds1302_write(ds1302_def * dev,u8 addr,u8 dat){
	u8 i;
	gpio_out(dev->rst,1);//����DS1302����					
	//д��Ŀ���ַ��addr
	addr = addr & 0xFE; //���λ���㣬�Ĵ���0λΪ0ʱд��Ϊ1ʱ����
	for(i=0;i<8;i++){	//д8λ���ݡ�
		if(addr&0x01){	//�����λ����
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//����ʱ�ӣ�
		gpio_out(dev->sck,0);//ͨ�����ú�����ʱ������Ϊ��ʱ��
		addr=addr>>1;	//ȡ��һλ���ݡ�
	}	
	//д�����ݣ�dat
	for(i=0;i<8;i++){	//д8λ���ݡ�
		if(dat&0x01){	//�����λ����
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//����ʱ��
		gpio_out(dev->sck,0);//ͨ�����ú�����ʱ������Ϊ��ʱ��
		dat=dat>>1;		//ȡ��һλ���ݡ�
	}
	gpio_out(dev->rst,0);//ֹͣDS1302����
}
/*-------------------------------------------------------
DS1302�Ķ�������
-------------------------------------------------------*/
u8 ds1302_read(ds1302_def * dev,u8 addr) {
	unsigned char i,temp;	
	gpio_out(dev->rst,1);//����DS1302����
	//д��Ŀ���ַ��addr
	addr=addr|0x01;		//���λ�øߣ��Ĵ���0λΪ0ʱд��Ϊ1ʱ����
	for(i=0;i<8;i++){	//д8λ���ݡ�	
		if(addr&0x01){	//�ӵ�λ��ʼ����
			gpio_out(dev->io,1);
		}else{
			gpio_out(dev->io,0);
		}
		gpio_out(dev->sck,1);//����ʱ��
		gpio_out(dev->sck,0);//ͨ�����ú�����ʱ������Ϊ��ʱ��
		addr=addr>>1;		//ȡ��һλ���ݡ�
	}	
	//������ݣ�temp
	for(i=0;i<8;i++){	//��8λ���ݡ�
		temp=temp>>1;	//�ڳ����λ��
		if(gpio_in(dev->io)){//�����λ��ʼ����
			temp|=0x80;
		}else{
			temp&=0x7F;
		}
		gpio_out(dev->sck,1);//����ʱ��
		gpio_out(dev->sck,0);//ͨ�����ú�����ʱ������Ϊ��ʱ��
	}	
	gpio_out(dev->rst,0);//ֹͣDS1302����
	return temp;		//���ض�ȡ��������
}
/*-------------------------------------------------------
DS1302�Ĵ��溯����
-------------------------------------------------------*/
void ds1302_save(ds1302_def * dev){
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x00);		//�ر�д����
	ds1302_write(dev,DS1302_SECOND_ADDR,  0x80);		//��ͣʱ�� 
	ds1302_write(dev,DS1302_CHARGER_ADDR, dev->charger);//�������
	ds1302_write(dev,DS1302_YEAR_ADDR,    dev->year);	//�� 
	ds1302_write(dev,DS1302_MONTH_ADDR,   dev->month);	//�� 
	ds1302_write(dev,DS1302_DATE_ADDR,    dev->date);	//�� 
	ds1302_write(dev,DS1302_DAY_ADDR,     dev->day);    //�� 
	ds1302_write(dev,DS1302_HOUR_ADDR,    dev->hour);	//ʱ 
	ds1302_write(dev,DS1302_MINUTE_ADDR,  dev->minute); //��
	ds1302_write(dev,DS1302_SECOND_ADDR,  dev->second); //��
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x80);        //��д����
}
/*-------------------------------------------------------
DS1302�ļ��غ�����
-------------------------------------------------------*/
void ds1302_load(ds1302_def * dev){
	dev->year  =ds1302_read(dev,DS1302_YEAR_ADDR);	//�� 
	dev->month =ds1302_read(dev,DS1302_MONTH_ADDR);	//�� 
	dev->date  =ds1302_read(dev,DS1302_DATE_ADDR);	//�� 
	dev->hour  =ds1302_read(dev,DS1302_HOUR_ADDR);	//ʱ 
	dev->minute=ds1302_read(dev,DS1302_MINUTE_ADDR);//�� 
	dev->second=ds1302_read(dev,DS1302_SECOND_ADDR);//��
	dev->day   =ds1302_read(dev,DS1302_DAY_ADDR);	//�� 	
}
/*-------------------------------------------------------
DS1302�ĳ�ʼ��������
-------------------------------------------------------*/
void ds1302_init(ds1302_def * dev,u8 rst,u8 io,u8 sck){
	dev->rst=rst;//�����������á�
	dev->io =io;
	dev->sck=sck;
	gpio_mode(dev->rst,GPIO_OUT);//��������״̬��
	gpio_mode(dev->io, GPIO_OUT);
	gpio_mode(dev->sck,GPIO_OUT);
	gpio_out(dev->rst,0);//���ó�ʼ��ƽ��
	gpio_out(dev->sck,0);
	gpio_out(dev->io, 1);
	#if DS1302_INIT_DATA_EN  //����ʹ���˳�ʼ��д��ʱ�书�ܣ�
	dev->year   =DS1302_YEAR;//�Ͱ�ͼ�ν������õ�ʱ��д�롣
	dev->month  =DS1302_MONTH;
	dev->date   =DS1302_DATE;
	dev->day    =DS1302_DAY;
	dev->hour   =DS1302_HOUR;
	dev->minute =DS1302_MINUTE;
	dev->second =DS1302_SECOND;
	dev->charger=DS1302_CHARGER;
	ds1302_save(dev);		//Ȼ�󱣴浽ds1302�
	#endif	
}