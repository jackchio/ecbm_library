#ifndef _ECBM_AT24CXX_H_
#define _ECBM_AT24CXX_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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
//<i>��ѡ��򹴣���ζ��AT24CXX���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣����֧�ֶ������µĴ��븴�á�
//<i>��ѡ��򹴣���ζ��AT24CXX���ܵ���ʹ�ã���������������ECBM�⺯������Ҫ��ֲ�����Ĺ��캯��������ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
#define ECBM_AT24CXX_LINK_EN 1 //��ECBM�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��AT24CXX���裬����Ϊ0��
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
#if ECBM_AT24CXX_LINK_EN     //�����Ҫ��������
#include "ecbm.h"            //����ecbmͷ�ļ�
typedef struct{
	u8 mode;
	soft_iic_def io;	
}at24_def;
void at24_init_hard(at24_def * dev,u8 scl,u8 sda){
	if((scl==D15)&&(sda==D14))dev->mode=0;
	else if((scl==D25)&&(sda==D24))dev->mode=1;
	else if((scl==D77)&&(sda==D76))dev->mode=2;
	else if((scl==D32)&&(sda==D33))dev->mode=3;
	else {
		LED=0;
		while(1);
	}
	iic_master_init();
	iic_set_pin(dev->mode);
}
void at24_init_soft(at24_def * dev,u8 scl,u8 sda){
	dev->mode=0x10;
	soft_iic_init(&((*dev).io),scl,sda);
}
void at24_write(at24_def * dev,u8 addr,u8 dat[],u8 num){
	u8 i;
	if(dev->mode==0x10){
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa0);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_write    (&((*dev).io),addr);
		soft_iic_write_ack(&((*dev).io));
		for(i=0;i<num;i++){
			soft_iic_write(&((*dev).io),dat[i]);
			soft_iic_write_ack(&((*dev).io));
		}	
		soft_iic_stop     (&((*dev).io));
	}else{
		iic_start();
		iic_write(0xa0);
		iic_write_ack();
		iic_write(addr);
		iic_write_ack();
		for(i=0;i<num;i++){
			iic_write(dat[i]);
			iic_write_ack();
		}	
		iic_stop();
	}
}
void at24_read(at24_def * dev,u8 addr,u8 dat[],u8 num){
    u8 i;
    /*��д����*/
	if(dev->mode==0x10){
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa0);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_write    (&((*dev).io),addr);
		soft_iic_write_ack(&((*dev).io));
		soft_iic_start    (&((*dev).io));
		soft_iic_write    (&((*dev).io),0xa1);
		for(i=0;i<num;i++){
			soft_iic_write_ack(&((*dev).io));
			dat[i]=soft_iic_read (&((*dev).io));
		}
		soft_iic_write_nack(&((*dev).io));
		soft_iic_stop     (&((*dev).io));
	}else{
		iic_start();
		iic_write(0xa0);
		iic_write_ack();
		iic_write(addr);
		iic_write_ack();
		iic_start();
		iic_write(0xa1);
		for(i=0;i<num;i++){
			iic_write_ack();
			dat[i]=iic_read();
		}
		iic_write_nack();
		iic_stop();
	}
}
#endif
#endif
