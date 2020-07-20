#include "ds18b20.h"//ͳһ���غ���ͷ�ļ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
DS18B20�ĳ�ʼ��������
-------------------------------------------------------*/
void ds18b20_init(ds18b20_def * dev,u8 pin){
	dev->port=io2port(pin);
	dev->pin =io2pin (pin);
	gpio_mode(pin,GPIO_IN);
}
/*-------------------------------------------------------
DS18B20��д������
-------------------------------------------------------*/
void ds18b20_write(ds18b20_def * dev,u8 dat){
	u8 i;
	u16 _10us,_70us;
	_10us=delay_set_us(10);
	_70us=delay_set_us(70);
	for(i=0;i<8;i++){
		if(dat&0x01){
			gpio_out_fast(dev->port,dev->pin,0);//�������ߣ���ʼͨ�š�
			delay_us(_10us);       //��15us��18B20��С�ɼ�ʱ�䣩
			gpio_out_fast(dev->port,dev->pin,1);//ǰ�������ߡ�
			delay_us(_70us);       //��ʱ70us����ǰ���10us��80usʱ�䣨����18B20���ɼ�ʱ�䣩
		}
		else{
			gpio_out_fast(dev->port,dev->pin,0);//�������ߣ���ʼͨ�š�
			delay_us(_70us);       //��ʱ70us������18B20�����ɼ�ʱ�䣩
			gpio_out_fast(dev->port,dev->pin,1);//�������ߡ�
			delay_us(_10us);       //������ʱ��ʹ��д1д0��ʱ��һ�¡�		
		}
		dat>>=1;
	}
}
/*-------------------------------------------------------
DS18B20�Ķ�������
-------------------------------------------------------*/
u8 ds18b20_read(ds18b20_def * dev){
	u8 i,dat=0;
	u16 _10us,_50us;
	_10us=delay_set_us(10);
	_50us=delay_set_us(50);
	for(i=0;i<8;i++){
		gpio_out_fast(dev->port,dev->pin,0); //�������ߣ���ʼͨ�š�
		dat>>=1;              //�ƶ����λ�����������ռ䡣
		gpio_out_fast(dev->port,dev->pin,1); //IO��һ��Ϊ�˶�ȡIO״̬��	
		delay_us(_10us);        //�ٷ��Ƽ����������ߺ�15us�ڶ�ȡ�����ǿ⺯��ִ��ҲҪʱ�䣬����ʱ10us��
		if(gpio_in_fast(dev->port,dev->pin)){//��ȡIO״̬��
			dat|=0x80;		  //�Ǹߵ�ƽ���ڸ�λ����1���ǵ͵�ƽ��������ָ���Զ���0��
		}
		delay_us(_50us);        //��ȡ��ʱ��Ҫ��60us��������ʱ50us�������20us��70us��
	}
	return dat;
}
/*-------------------------------------------------------
DS18B20�ļ�⺯����
-------------------------------------------------------*/
u8 ds18b20_check(ds18b20_def * dev){
	u16 _60us,_500us;
	_60us=delay_set_us(60);
	_500us=delay_set_us(500);
	gpio_out_fast(dev->port,dev->pin,0);  //�������ߣ���ʼͨ�š�
	delay_us(_500us);        //����500us(��λʱ��480us~960us)��
	gpio_out_fast(dev->port,dev->pin,1);		
	delay_us(_60us);         //�ȴ�DS18B20��Ӧ����Ҫ�ȴ�15us~60us����
	if(gpio_in_fast(dev->port,dev->pin)==0){
		return 1;          //���߱�DS18B20����˵���������ڡ�
	}
	return 0;              //0��ʾ���������ڡ�
}
/*-------------------------------------------------------
DS18B20�����к�����
-------------------------------------------------------*/
u8 ds18b20_run(ds18b20_def * dev){
	u8 h,l;
	u16 temp;
	u16 _100us;
	_100us=delay_set_us(100);
	if(ds18b20_check(dev)){
		delay_us(_100us);
		ds18b20_write(dev,0xcc);
		ds18b20_write(dev,0x44);
	}else return 1;
	if(ds18b20_check(dev)){
		delay_us(_100us);
		ds18b20_write(dev,0xcc);
		ds18b20_write(dev,0xbe);
		l=ds18b20_read(dev);
		h=ds18b20_read(dev);
		ds18b20_check(dev);
		temp=(h<<8)|l;
		if(temp&0x8000){
			temp=(~temp)+1;
			dev->temp=-((float)temp*0.0625f);
		}else{
			dev->temp=((float)temp*0.0625f);
		}
		return 0; 
	}else return 1;
}
