#ifndef _ECBM_DS18B20_H_
#define _ECBM_DS18B20_H_
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
//<i>��ѡ��򹴣���ζ��DS18B20���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣����֧�ֶ������µĴ��븴�á�
//<i>��ѡ��򹴣���ζ��DS18B20���ܵ���ʹ�ã���������������ECBM�⺯������Ҫ��ֲ�����Ĺ��캯��������ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
#define ECBM_DS18B20_LINK_EN 0 //��ECBM�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��DS18B20���裬����Ϊ0��
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_DS18B20_LINK_EN
#include "ecbm.h"
typedef struct{//�ṹ��ֻ�����ڶ��������ã��ڵ�����������£�ʡ�����ܽ�Լ����6�ֽڵĿռ�
	u8 port;
	u8 pin;
	float temp;
}ds18b20_def;
void ds18b20_init(ds18b20_def * dev,u8 pin){
	dev->port=pin>>4;
	dev->pin=0x01<<(pin&0x0f);
	gpio_mode(pin,GPIO_PP);
}
void ds18b20_write(ds18b20_def * dev,u8 dat){
	u8 i;
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
u8 ds18b20_read(ds18b20_def * dev){
	u8 i,dat=0;
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
u8 ds18b20_check(ds18b20_def * dev){
	gpio_out_fast(dev->port,dev->pin,0);  //�������ߣ���ʼͨ�š�
	delay_us(_500us);        //����500us(��λʱ��480us~960us)��
	gpio_out_fast(dev->port,dev->pin,1);		
	delay_us(_60us);         //�ȴ�DS18B20��Ӧ����Ҫ�ȴ�15us~60us����
	if(gpio_in_fast(dev->port,dev->pin)==0){
		return 1;          //���߱�DS18B20����˵���������ڡ�
	}
	return 0;              //0��ʾ���������ڡ�
}
u8 ds18b20_run(ds18b20_def * dev){
	u8 h,l;
	u16 temp;
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
#else
/*����ݹ�ʽ���ù�ʽֻ������STC8������������ʱֵ��
              ��ʱֵ=��ʱʱ��*��ʱ��/10����
����1��
    ����stc8��Ƭ��������24MHzƵ���ϣ���ô��ʱ10us��
��ʱֵ=10*��24/10��=24������������Ķ���������24����
#define _10us 24  
����2��
    ����stc8��Ƭ��������11.0592MHzƵ���ϣ���ô��ʱ10us��
��ʱֵ=10*��11.0592/10��=11��������������������������
����������11����#define _10us 11  
�Դ����ơ�
*/
#include "stc.h"     //��ֲ���ṩ��Ӧ��ͷ�ļ�
#define _10us  13    //��ֲ���޸���ʱֵ
#define _15us  20 
#define _50us  67
#define _60us  81
#define _70us  95
#define _100us 134
#define _500us 670
sbit    DS18B20=P3^3;   //��ֲ���޸�����,���޸���������ã�����Ӧ��������Ϊ����ģʽ��
#define GPIO_MODE_PP P3M1 &= 0xf7; P3M0 |= 0x08; //P3(00001000B,00001000B)

#define u8 unsigned char
#define u16 unsigned int
void delay_us(unsigned int us){
	unsigned int i;
	i = us;
	while (i--);
}
void ds18b20_init(){
	DS18B20=1;
	GPIO_MODE_PP;
}
void ds18b20_write(unsigned char dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat&0x01){
			DS18B20=0;//�������ߣ���ʼͨ�š�
			delay_us(_10us);       //��15us��18B20��С�ɼ�ʱ�䣩
			DS18B20=1;;//ǰ�������ߡ�
			delay_us(_70us);       //��ʱ70us����ǰ���10us��80usʱ�䣨����18B20���ɼ�ʱ�䣩
		}
		else{
			DS18B20=0;//�������ߣ���ʼͨ�š�
			delay_us(_70us);       //��ʱ70us������18B20�����ɼ�ʱ�䣩
			DS18B20=1;//�������ߡ�
			delay_us(_10us);       //������ʱ��ʹ��д1д0��ʱ��һ�¡�		
		}
		dat>>=1;
	}
}
u8 ds18b20_read(){
	unsigned char i,dat=0;
	for(i=0;i<8;i++){
		DS18B20=0;//�������ߣ���ʼͨ�š�
		dat>>=1;              //�ƶ����λ�����������ռ䡣
		DS18B20=1;//IO��һ��Ϊ�˶�ȡIO״̬��	
		delay_us(_15us);        //�ٷ��Ƽ����������ߺ�15us�ڶ�ȡ��
		if(DS18B20){//��ȡIO״̬��
			dat|=0x80;		  //�Ǹߵ�ƽ���ڸ�λ����1���ǵ͵�ƽ��������ָ���Զ���0��
		}
		delay_us(_50us);        //��ȡ��ʱ��Ҫ��60us��������ʱ50us�������20us��70us��
	}
	return dat;
}
unsigned char ds18b20_check(){
	DS18B20=0;//�������ߣ���ʼͨ�š�
	delay_us(_500us);        //����500us(��λʱ��480us~960us)��
	DS18B20=1;	
	delay_us(_60us);         //�ȴ�DS18B20��Ӧ����Ҫ�ȴ�15us~60us����
	if(DS18B20==0){
		return 1;          //���߱�DS18B20����˵���������ڡ�
	}
	return 0;              //0��ʾ���������ڡ�
}
float ds18b20_run(){
	unsigned char h,l;
	unsigned int temp;
	if(ds18b20_check()){
		delay_us(_100us);
		ds18b20_write(0xcc);
		ds18b20_write(0x44);
	}else return -999.0f;
	if(ds18b20_check()){
		delay_us(_100us);
		ds18b20_write(0xcc);
		ds18b20_write(0xbe);
		
		l=ds18b20_read();
		h=ds18b20_read();
		ds18b20_check();
		temp=(h<<8)|l;
		return ((float)temp*0.0625f); 
	}else return -999.0f;
}
#endif
#endif
