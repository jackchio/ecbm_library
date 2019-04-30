#ifndef _DHT11_H_
#define _DHT11_H_
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
//<i>��ѡ��򹴣���ζ��DHT11���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣����֧�ֶ������µĴ��븴�á�
//<i>��ѡ��򹴣���ζ��DHT11���ܵ���ʹ�ã���������������ECBM�⺯������Ҫ��ֲ�����Ĺ��캯��������ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
#define ECBM_DHT11_LINK_EN 1 //��ECBM�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��DHT11���裬����Ϊ0��
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_DHT11_LINK_EN
/*----------------------------------------
���������õ����ⲿ����ʱ������ͨ��IO���ƺ�����
���Ҫ��֤����ͷ�ļ��������ܼ��ء�
-----------------------------------------*/
#include "ecbm.h"
/*----------------------------------------
DHT11����Ϣ�ṹ�嶨�塣������غ����ɸ��ã���
��ÿ����һ��DHT11�������Ͷඨ��һ����Ϣ�ṹ�塣
ʹ�÷�����
	�������һ�������һ������������dev1��
Ȼ�� dht11_def dev1;
	�����������ʱ������������һ����������
dht11_def dev1,dev2;
-----------------------------------------*/
typedef struct{
	u8 port;        //DHT11Ӳ�����ӵ�P��
	u8 pin;         //P���ϵı��
	u8 temp;		//DHT11��������¶�ֵ
	u8 humi;		//DHT11�������ʪ��ֵ
}dht11_def;
/*----------------------------------------
DHT11��ʼ�����������ڳ�ʼ��IO�����úͳ�ʼ����
Ϣ�ṹ�塣�ú����ɸ��ã�����ÿ����һ��DHT11��
�����Ͷ����һ�θú�����
ʹ�÷�����
	��֮ǰ�����DHT11��Ϣ�ṹ���DHT11Ӳ������
��IO�����Ϊ�������롣���磬������dht11_def dev1;
Ӳ����������ΪD17��IO���ϡ�����
        dht11_init(&dev1,D17);
����Ҫ�޸Ľṹ���ڵı���������&�Ų����٣�
���������д����
        dht11_init(&dev1,D17);//��ʼ������1
        dht11_init(&dev2,D16);//��ʼ������2
Ҫע�⣬�Ͻ���������������ͬһ��IO�ڣ�
-----------------------------------------*/
void dht11_init(dht11_def * dev,u8 pin){
	dev->port=pin>>4;
	dev->pin=0x01<<(pin&0x0f);
	dev->temp=0;
	dev->humi=0;
	gpio_mode(pin,GPIO_IN);
	gpio_out(pin,1);
}
/*----------------------------------------
DHT11��ȡ���������ڶ�ȡDHT11����������ʪ��ֵ��
�ú����ɸ��á��ɸ�����Ҫȥ���ã���Ҫע��DHT11
�Ƽ��Ĳ�������1��/�Ρ�������ε���֮ǰҪһ����
ʱ�����������ö�ʱ����1���ӣ�ÿ�����һ�Ρ�
ʹ�÷�����
	��֮ǰ�����DHT11��Ϣ�ṹ����Ϊ�������롣
���磬������dht11_def dev1;
        dht11_run(&dev1);
���������д����
        dht11_run(&dev1);//��ȡ����1������
        dht11_run(&dev2);//��ȡ����2������
����Ҫ�޸Ľṹ���ڵı���������&�Ų����٣�
�����������֮�󣬽ṹ������ھ�������ʪ��ֵ�ˡ�
��ʱ dev1.temp ���������1���¶ȣ�
dev1.humi ���������1��ʪ�ȡ�
ͬ��  dev2.temp ���������2���¶ȣ�
dev2.humi ���������2��ʪ�ȡ�
-----------------------------------------*/
unsigned char dht11_run(dht11_def * dev){//����0-������1-���ߴ���2-���ʳ�ʱ
	u8 timeout,i,t,j;
	u8 temp[5];
	gpio_out_fast(dev->port,dev->pin,0);//��ʼ�ź�			
	delay_ms(19);			//����18ms����
	gpio_out_fast(dev->port,dev->pin,1);//��������
	delay_us(_30us);		//�ȴ�DHT11��Ӧ
	if(gpio_in_fast(dev->port,dev->pin)==0){			//�ж�DHT11�Ƿ���Ӧ�����û�е͵�ƽ˵��û��Ӧ
		timeout=2;
		while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_10us);//�ȴ��͵�ƽ��Ӧ����
		if(timeout==1)return 2;//��ʱ���أ�ʱ��Ϊ10us*255=2.5ms
		timeout=2;
		while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_10us);//�ȴ��ߵ�ƽ��Ӧ����
		if(timeout==1)return 2;//��ʱ����
		for(j=0;j<5;j++){//һ������5λ����
			t=0;						//������ʱ����
			for(i=0;i<8;i++){
				timeout=2;
				while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_5us);//�ȴ����ݿ�ʼ�źţ��͵�ƽ������
				if(timeout==1)return 2;//��ʱ����,ʱ��Ϊ1us*255=255us
				delay_us(_30us);//�͵�ƽ֮��ӵĸߵ�ƽ�ĳ���ʱ����26us~28us��ʾ0.��ô����ʱ29us�����ŵ�ƽ
				t<<=1;
				if(gpio_in_fast(dev->port,dev->pin)==1){//��ʱ���Ǹߵ�ƽ�Ļ���˵�������ݡ�1��
					t|=1;				
				}//����������ݡ�0������ɶ�����ø�
				timeout=2;
				while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_5us);//ȷ���ߵ�ƽ����
				if(timeout==1)return 2;//��ʱ
			}
			temp[j]=t;//����ʱ������ֵװ��������
		}
		t=temp[0]+temp[1]+temp[2]+temp[3];//����У���
		if(t==temp[4]){//У�����ȷ�ͷ���0����ʾһ������
			dev->temp=temp[2];
			dev->humi=temp[0];
			return 0;//����
		}
	}
	return 1;//���ݴ������
}
/*-------------------------------------------
                   DEMO����
#include "device/dht11.h"//���ر�ͷ�ļ�
...//���...�Ǵ�Ҫ�������˼������Ͳ�������ֹ����
...
...
void main(){
	...
	dht11_def dev1;			//����һ���������������⣬���ظ����ɡ�
	dht11_init(&dev1,D17);	//��ʼ��������
	...
	...
	while(1){
		...
		dht11_run(&dev1);//��ȡ��ʪ��ֵ
		if(dev1.temp>38){//����ʪ����ĳЩ����
			...			//������������ж��¶ȴ���38��ʱ��ĳ�¡�
		}
		...
	}
}
--------------------------------------------*/
#else
#include "stc.h"
sbit dht_io=P3^5;
void dht11_init(){
	dht_io=1;
}
void dht11_delay_19ms(){
	unsigned char i, j, k;
	i = 3;
	j = 81;
	k = 48;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void delay_us(unsigned int us){
	unsigned int i;
	i = us;
	while (i--);
}
#define _5us 12
#define _10us 24
#define _30us 72
unsigned char dht11_run(unsigned char * temp_val,unsigned char * humi_val){//����0-������1-���ߴ���2-���ʳ�ʱ
	unsigned char timeout,i,t,j;
	unsigned char temp[5];
	dht_io=0;//��ʼ�ź�			
	dht11_delay_19ms();		//����18ms����
	dht_io=1;//��������
	delay_us(_30us);		//�ȴ�DHT11��Ӧ
	if(dht_io==0){			//�ж�DHT11�Ƿ���Ӧ�����û�е͵�ƽ˵��û��Ӧ
		timeout=2;
		while((dht_io==0)&&(timeout++))delay_us(_10us);//�ȴ��͵�ƽ��Ӧ����
		if(timeout==1)return 2;//��ʱ���أ�ʱ��Ϊ10us*255=2.5ms
		timeout=2;
		while((dht_io==1)&&(timeout++))delay_us(_10us);//�ȴ��ߵ�ƽ��Ӧ����
		if(timeout==1)return 2;//��ʱ����
		for(j=0;j<5;j++){//һ������5λ����
			t=0;						//������ʱ����
			for(i=0;i<8;i++){
				timeout=2;
				while((dht_io==0)&&(timeout++))delay_us(_5us);//�ȴ����ݿ�ʼ�źţ��͵�ƽ������
				if(timeout==1)return 2;//��ʱ����,ʱ��Ϊ1us*255=255us
				delay_us(_30us);//�͵�ƽ֮��ӵĸߵ�ƽ�ĳ���ʱ����26us~28us��ʾ0.��ô����ʱ29us�����ŵ�ƽ
				t<<=1;
				if(dht_io==1){//��ʱ���Ǹߵ�ƽ�Ļ���˵�������ݡ�1��
					t|=1;				
				}//����������ݡ�0������ɶ�����ø�
				timeout=2;
				while((dht_io==1)&&(timeout++))delay_us(_5us);//ȷ���ߵ�ƽ����
				if(timeout==1)return 2;//��ʱ
			}
			temp[j]=t;//����ʱ������ֵװ��������
		}
		t=temp[0]+temp[1]+temp[2]+temp[3];//����У���
		if(t==temp[4]){//У�����ȷ�ͷ���0����ʾһ������
			*temp_val=temp[2];
			*humi_val=temp[0];
			return 0;//����
		}
	}
	return 1;//���ݴ������
}



#endif
#endif